/*
 * Copyright (C) 2008 Zeeshan Ali (Khattak) <zeeshanak@gnome.org>.
 * Copyright (C) 2008 Nokia Corporation.
 *
 * Author: Zeeshan Ali (Khattak) <zeeshanak@gnome.org>
 *                               <zeeshan.ali@nokia.com>
 *
 * This file is part of Rygel.
 *
 * Rygel is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Rygel is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include <glib.h>
#include <glib-object.h>
#include <gio/gio.h>
#include <libsoup/soup.h>
#include <stdlib.h>
#include <string.h>


#define RYGEL_TYPE_STATE_MACHINE (rygel_state_machine_get_type ())
#define RYGEL_STATE_MACHINE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_STATE_MACHINE, RygelStateMachine))
#define RYGEL_IS_STATE_MACHINE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_STATE_MACHINE))
#define RYGEL_STATE_MACHINE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), RYGEL_TYPE_STATE_MACHINE, RygelStateMachineIface))

typedef struct _RygelStateMachine RygelStateMachine;
typedef struct _RygelStateMachineIface RygelStateMachineIface;

#define RYGEL_TYPE_HTTP_RESPONSE (rygel_http_response_get_type ())
#define RYGEL_HTTP_RESPONSE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_RESPONSE, RygelHTTPResponse))
#define RYGEL_HTTP_RESPONSE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_RESPONSE, RygelHTTPResponseClass))
#define RYGEL_IS_HTTP_RESPONSE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_RESPONSE))
#define RYGEL_IS_HTTP_RESPONSE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_RESPONSE))
#define RYGEL_HTTP_RESPONSE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_RESPONSE, RygelHTTPResponseClass))

typedef struct _RygelHTTPResponse RygelHTTPResponse;
typedef struct _RygelHTTPResponseClass RygelHTTPResponseClass;
typedef struct _RygelHTTPResponsePrivate RygelHTTPResponsePrivate;

#define RYGEL_TYPE_SEEKABLE_RESPONSE (rygel_seekable_response_get_type ())
#define RYGEL_SEEKABLE_RESPONSE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_SEEKABLE_RESPONSE, RygelSeekableResponse))
#define RYGEL_SEEKABLE_RESPONSE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_SEEKABLE_RESPONSE, RygelSeekableResponseClass))
#define RYGEL_IS_SEEKABLE_RESPONSE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_SEEKABLE_RESPONSE))
#define RYGEL_IS_SEEKABLE_RESPONSE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_SEEKABLE_RESPONSE))
#define RYGEL_SEEKABLE_RESPONSE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_SEEKABLE_RESPONSE, RygelSeekableResponseClass))

typedef struct _RygelSeekableResponse RygelSeekableResponse;
typedef struct _RygelSeekableResponseClass RygelSeekableResponseClass;
typedef struct _RygelSeekableResponsePrivate RygelSeekableResponsePrivate;

#define RYGEL_TYPE_HTTP_SEEK (rygel_http_seek_get_type ())
#define RYGEL_HTTP_SEEK(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_SEEK, RygelHTTPSeek))
#define RYGEL_HTTP_SEEK_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_SEEK, RygelHTTPSeekClass))
#define RYGEL_IS_HTTP_SEEK(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_SEEK))
#define RYGEL_IS_HTTP_SEEK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_SEEK))
#define RYGEL_HTTP_SEEK_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_SEEK, RygelHTTPSeekClass))

typedef struct _RygelHTTPSeek RygelHTTPSeek;
typedef struct _RygelHTTPSeekClass RygelHTTPSeekClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _RygelStateMachineIface {
	GTypeInterface parent_iface;
	void (*run) (RygelStateMachine* self);
	GCancellable* (*get_cancellable) (RygelStateMachine* self);
	void (*set_cancellable) (RygelStateMachine* self, GCancellable* value);
};

struct _RygelHTTPResponse {
	GObject parent_instance;
	RygelHTTPResponsePrivate * priv;
	SoupMessage* msg;
};

struct _RygelHTTPResponseClass {
	GObjectClass parent_class;
	void (*run) (RygelHTTPResponse* self);
	void (*end) (RygelHTTPResponse* self, gboolean aborted, guint status);
};

struct _RygelSeekableResponse {
	RygelHTTPResponse parent_instance;
	RygelSeekableResponsePrivate * priv;
};

struct _RygelSeekableResponseClass {
	RygelHTTPResponseClass parent_class;
};

struct _RygelSeekableResponsePrivate {
	RygelHTTPSeek* seek;
	GFile* file;
	GFileInputStream* input_stream;
	gchar* buffer;
	gint buffer_length1;
	gint buffer_size;
	gsize total_length;
	gint priority;
};


static gpointer rygel_seekable_response_parent_class = NULL;

GType rygel_state_machine_get_type (void);
GType rygel_http_response_get_type (void);
GType rygel_seekable_response_get_type (void);
GType rygel_http_seek_get_type (void);
#define RYGEL_SEEKABLE_RESPONSE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_SEEKABLE_RESPONSE, RygelSeekableResponsePrivate))
enum  {
	RYGEL_SEEKABLE_RESPONSE_DUMMY_PROPERTY
};
#define RYGEL_SEEKABLE_RESPONSE_BUFFER_LENGTH ((gsize) 4096)
RygelHTTPResponse* rygel_http_response_construct (GType object_type, SoupServer* server, SoupMessage* msg, gboolean partial, GCancellable* cancellable);
static gint rygel_seekable_response_get_requested_priority (RygelSeekableResponse* self);
gint64 rygel_http_seek_get_length (RygelHTTPSeek* self);
static void rygel_seekable_response_on_wrote_chunk (RygelSeekableResponse* self, SoupMessage* msg);
static void _rygel_seekable_response_on_wrote_chunk_soup_message_wrote_chunk (SoupMessage* _sender, gpointer self);
RygelSeekableResponse* rygel_seekable_response_new (SoupServer* server, SoupMessage* msg, const char* uri, RygelHTTPSeek* seek, gsize file_length, GCancellable* cancellable);
RygelSeekableResponse* rygel_seekable_response_construct (GType object_type, SoupServer* server, SoupMessage* msg, const char* uri, RygelHTTPSeek* seek, gsize file_length, GCancellable* cancellable);
GCancellable* rygel_state_machine_get_cancellable (RygelStateMachine* self);
void rygel_state_machine_set_cancellable (RygelStateMachine* self, GCancellable* value);
static void rygel_seekable_response_on_file_read (RygelSeekableResponse* self, GObject* source_object, GAsyncResult* _result_);
static void _rygel_seekable_response_on_file_read_gasync_ready_callback (GObject* source_object, GAsyncResult* res, gpointer self);
static void rygel_seekable_response_real_run (RygelHTTPResponse* base);
void rygel_http_response_end (RygelHTTPResponse* self, gboolean aborted, guint status);
gint64 rygel_http_seek_get_start (RygelHTTPSeek* self);
gint64 rygel_http_seek_get_stop (RygelHTTPSeek* self);
static void rygel_seekable_response_on_contents_read (RygelSeekableResponse* self, GObject* source_object, GAsyncResult* _result_);
static void _rygel_seekable_response_on_contents_read_gasync_ready_callback (GObject* source_object, GAsyncResult* res, gpointer self);
void rygel_http_response_push_data (RygelHTTPResponse* self, void* data, gsize length);
static void rygel_seekable_response_on_input_stream_closed (RygelSeekableResponse* self, GObject* source_object, GAsyncResult* _result_);
static void _rygel_seekable_response_on_input_stream_closed_gasync_ready_callback (GObject* source_object, GAsyncResult* res, gpointer self);
static void rygel_seekable_response_finalize (GObject* obj);
static int _vala_strcmp0 (const char * str1, const char * str2);



static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _rygel_seekable_response_on_wrote_chunk_soup_message_wrote_chunk (SoupMessage* _sender, gpointer self) {
	rygel_seekable_response_on_wrote_chunk (self, _sender);
}


RygelSeekableResponse* rygel_seekable_response_construct (GType object_type, SoupServer* server, SoupMessage* msg, const char* uri, RygelHTTPSeek* seek, gsize file_length, GCancellable* cancellable) {
	RygelSeekableResponse * self;
	RygelHTTPSeek* _tmp0_;
	gchar* _tmp1_;
	GFile* _tmp2_;
	g_return_val_if_fail (server != NULL, NULL);
	g_return_val_if_fail (msg != NULL, NULL);
	g_return_val_if_fail (uri != NULL, NULL);
	self = (RygelSeekableResponse*) rygel_http_response_construct (object_type, server, msg, seek != NULL, cancellable);
	self->priv->seek = (_tmp0_ = _g_object_ref0 (seek), _g_object_unref0 (self->priv->seek), _tmp0_);
	self->priv->total_length = file_length;
	self->priv->priority = rygel_seekable_response_get_requested_priority (self);
	if (seek != NULL) {
		self->priv->total_length = (gsize) rygel_http_seek_get_length (seek);
	} else {
		self->priv->total_length = file_length;
	}
	g_signal_connect_object (msg, "wrote-chunk", (GCallback) _rygel_seekable_response_on_wrote_chunk_soup_message_wrote_chunk, self, 0);
	self->priv->buffer = (_tmp1_ = g_new0 (gchar, RYGEL_SEEKABLE_RESPONSE_BUFFER_LENGTH), self->priv->buffer = (g_free (self->priv->buffer), NULL), self->priv->buffer_length1 = RYGEL_SEEKABLE_RESPONSE_BUFFER_LENGTH, self->priv->buffer_size = self->priv->buffer_length1, _tmp1_);
	self->priv->file = (_tmp2_ = g_file_new_for_uri (uri), _g_object_unref0 (self->priv->file), _tmp2_);
	return self;
}


RygelSeekableResponse* rygel_seekable_response_new (SoupServer* server, SoupMessage* msg, const char* uri, RygelHTTPSeek* seek, gsize file_length, GCancellable* cancellable) {
	return rygel_seekable_response_construct (RYGEL_TYPE_SEEKABLE_RESPONSE, server, msg, uri, seek, file_length, cancellable);
}


static void _rygel_seekable_response_on_file_read_gasync_ready_callback (GObject* source_object, GAsyncResult* res, gpointer self) {
	rygel_seekable_response_on_file_read (self, source_object, res);
}


static void rygel_seekable_response_real_run (RygelHTTPResponse* base) {
	RygelSeekableResponse * self;
	self = (RygelSeekableResponse*) base;
	rygel_state_machine_set_cancellable ((RygelStateMachine*) self, rygel_state_machine_get_cancellable ((RygelStateMachine*) self));
	g_file_read_async (self->priv->file, self->priv->priority, rygel_state_machine_get_cancellable ((RygelStateMachine*) self), _rygel_seekable_response_on_file_read_gasync_ready_callback, self);
}


static void _rygel_seekable_response_on_contents_read_gasync_ready_callback (GObject* source_object, GAsyncResult* res, gpointer self) {
	rygel_seekable_response_on_contents_read (self, source_object, res);
}


static void rygel_seekable_response_on_file_read (RygelSeekableResponse* self, GObject* source_object, GAsyncResult* _result_) {
	GError * _inner_error_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (_result_ != NULL);
	_inner_error_ = NULL;
	{
		GFileInputStream* _tmp0_;
		GFileInputStream* _tmp1_;
		_tmp0_ = g_file_read_finish (self->priv->file, _result_, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch20_g_error;
			goto __finally20;
		}
		self->priv->input_stream = (_tmp1_ = _tmp0_, _g_object_unref0 (self->priv->input_stream), _tmp1_);
	}
	goto __finally20;
	__catch20_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp2_;
			g_warning ("rygel-seekable-response.vala:74: Failed to read from URI: %s: %s\n", _tmp2_ = g_file_get_uri (self->priv->file), err->message);
			_g_free0 (_tmp2_);
			rygel_http_response_end ((RygelHTTPResponse*) self, FALSE, (guint) SOUP_STATUS_NOT_FOUND);
			_g_error_free0 (err);
			return;
		}
	}
	__finally20:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return;
	}
	if (self->priv->seek != NULL) {
		{
			G_FILE_INPUT_STREAM_GET_CLASS (self->priv->input_stream)->seek (self->priv->input_stream, rygel_http_seek_get_start (self->priv->seek), G_SEEK_SET, rygel_state_machine_get_cancellable ((RygelStateMachine*) self), &_inner_error_);
			if (_inner_error_ != NULL) {
				goto __catch21_g_error;
				goto __finally21;
			}
		}
		goto __finally21;
		__catch21_g_error:
		{
			GError * err;
			err = _inner_error_;
			_inner_error_ = NULL;
			{
				char* _tmp5_;
				char* _tmp4_;
				char* _tmp3_;
				g_warning ("rygel-seekable-response.vala:87: Failed to seek to %s-%s on URI %s: %s\n", _tmp3_ = g_strdup_printf ("%lli", rygel_http_seek_get_start (self->priv->seek)), _tmp4_ = g_strdup_printf ("%lli", rygel_http_seek_get_stop (self->priv->seek)), _tmp5_ = g_file_get_uri (self->priv->file), err->message);
				_g_free0 (_tmp5_);
				_g_free0 (_tmp4_);
				_g_free0 (_tmp3_);
				rygel_http_response_end ((RygelHTTPResponse*) self, FALSE, (guint) SOUP_STATUS_REQUESTED_RANGE_NOT_SATISFIABLE);
				_g_error_free0 (err);
				return;
			}
		}
		__finally21:
		if (_inner_error_ != NULL) {
			g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	g_input_stream_read_async ((GInputStream*) self->priv->input_stream, self->priv->buffer, RYGEL_SEEKABLE_RESPONSE_BUFFER_LENGTH, self->priv->priority, rygel_state_machine_get_cancellable ((RygelStateMachine*) self), _rygel_seekable_response_on_contents_read_gasync_ready_callback, self);
}


static void _rygel_seekable_response_on_input_stream_closed_gasync_ready_callback (GObject* source_object, GAsyncResult* res, gpointer self) {
	rygel_seekable_response_on_input_stream_closed (self, source_object, res);
}


static void rygel_seekable_response_on_contents_read (RygelSeekableResponse* self, GObject* source_object, GAsyncResult* _result_) {
	GError * _inner_error_;
	GFileInputStream* input_stream;
	gssize bytes_read;
	g_return_if_fail (self != NULL);
	g_return_if_fail (_result_ != NULL);
	_inner_error_ = NULL;
	input_stream = _g_object_ref0 (G_FILE_INPUT_STREAM (source_object));
	bytes_read = 0L;
	{
		gssize _tmp0_;
		_tmp0_ = g_input_stream_read_finish ((GInputStream*) input_stream, _result_, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch22_g_error;
			goto __finally22;
		}
		bytes_read = _tmp0_;
	}
	goto __finally22;
	__catch22_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp1_;
			g_warning ("rygel-seekable-response.vala:113: Failed to read contents from URI: %s: %s\n", _tmp1_ = g_file_get_uri (self->priv->file), err->message);
			_g_free0 (_tmp1_);
			rygel_http_response_end ((RygelHTTPResponse*) self, FALSE, (guint) SOUP_STATUS_NOT_FOUND);
			_g_error_free0 (err);
			_g_object_unref0 (input_stream);
			return;
		}
	}
	__finally22:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (input_stream);
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return;
	}
	if (bytes_read > 0) {
		rygel_http_response_push_data ((RygelHTTPResponse*) self, self->priv->buffer, (gsize) bytes_read);
	} else {
		g_input_stream_close_async ((GInputStream*) input_stream, self->priv->priority, rygel_state_machine_get_cancellable ((RygelStateMachine*) self), _rygel_seekable_response_on_input_stream_closed_gasync_ready_callback, self);
	}
	_g_object_unref0 (input_stream);
}


static void rygel_seekable_response_on_input_stream_closed (RygelSeekableResponse* self, GObject* source_object, GAsyncResult* _result_) {
	GError * _inner_error_;
	GFileInputStream* input_stream;
	g_return_if_fail (self != NULL);
	g_return_if_fail (_result_ != NULL);
	_inner_error_ = NULL;
	input_stream = _g_object_ref0 (G_FILE_INPUT_STREAM (source_object));
	{
		g_input_stream_close_finish ((GInputStream*) input_stream, _result_, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch23_g_error;
			goto __finally23;
		}
	}
	goto __finally23;
	__catch23_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp0_;
			g_warning ("rygel-seekable-response.vala:136: Failed to close stream to URI %s: %s\n", _tmp0_ = g_file_get_uri (self->priv->file), err->message);
			_g_free0 (_tmp0_);
			_g_error_free0 (err);
		}
	}
	__finally23:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (input_stream);
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return;
	}
	rygel_http_response_end ((RygelHTTPResponse*) self, FALSE, (guint) SOUP_STATUS_NONE);
	_g_object_unref0 (input_stream);
}


static void rygel_seekable_response_on_wrote_chunk (RygelSeekableResponse* self, SoupMessage* msg) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (msg != NULL);
	g_input_stream_read_async ((GInputStream*) self->priv->input_stream, self->priv->buffer, RYGEL_SEEKABLE_RESPONSE_BUFFER_LENGTH, self->priv->priority, rygel_state_machine_get_cancellable ((RygelStateMachine*) self), _rygel_seekable_response_on_contents_read_gasync_ready_callback, self);
}


static gint rygel_seekable_response_get_requested_priority (RygelSeekableResponse* self) {
	gint result;
	char* mode;
	gboolean _tmp0_;
	g_return_val_if_fail (self != NULL, 0);
	mode = g_strdup (soup_message_headers_get (((RygelHTTPResponse*) self)->msg->request_headers, "transferMode.dlna.org"));
	_tmp0_ = FALSE;
	if (mode == NULL) {
		_tmp0_ = TRUE;
	} else {
		_tmp0_ = _vala_strcmp0 (mode, "Interactive") == 0;
	}
	if (_tmp0_) {
		result = G_PRIORITY_DEFAULT;
		_g_free0 (mode);
		return result;
	} else {
		if (_vala_strcmp0 (mode, "Streaming") == 0) {
			result = G_PRIORITY_HIGH;
			_g_free0 (mode);
			return result;
		} else {
			if (_vala_strcmp0 (mode, "Background") == 0) {
				result = G_PRIORITY_LOW;
				_g_free0 (mode);
				return result;
			} else {
				result = G_PRIORITY_DEFAULT;
				_g_free0 (mode);
				return result;
			}
		}
	}
	_g_free0 (mode);
}


static void rygel_seekable_response_class_init (RygelSeekableResponseClass * klass) {
	rygel_seekable_response_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelSeekableResponsePrivate));
	RYGEL_HTTP_RESPONSE_CLASS (klass)->run = rygel_seekable_response_real_run;
	G_OBJECT_CLASS (klass)->finalize = rygel_seekable_response_finalize;
}


static void rygel_seekable_response_instance_init (RygelSeekableResponse * self) {
	self->priv = RYGEL_SEEKABLE_RESPONSE_GET_PRIVATE (self);
}


static void rygel_seekable_response_finalize (GObject* obj) {
	RygelSeekableResponse * self;
	self = RYGEL_SEEKABLE_RESPONSE (obj);
	_g_object_unref0 (self->priv->seek);
	_g_object_unref0 (self->priv->file);
	_g_object_unref0 (self->priv->input_stream);
	self->priv->buffer = (g_free (self->priv->buffer), NULL);
	G_OBJECT_CLASS (rygel_seekable_response_parent_class)->finalize (obj);
}


GType rygel_seekable_response_get_type (void) {
	static GType rygel_seekable_response_type_id = 0;
	if (rygel_seekable_response_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelSeekableResponseClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_seekable_response_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelSeekableResponse), 0, (GInstanceInitFunc) rygel_seekable_response_instance_init, NULL };
		rygel_seekable_response_type_id = g_type_register_static (RYGEL_TYPE_HTTP_RESPONSE, "RygelSeekableResponse", &g_define_type_info, 0);
	}
	return rygel_seekable_response_type_id;
}


static int _vala_strcmp0 (const char * str1, const char * str2) {
	if (str1 == NULL) {
		return -(str1 != str2);
	}
	if (str2 == NULL) {
		return str1 != str2;
	}
	return strcmp (str1, str2);
}




