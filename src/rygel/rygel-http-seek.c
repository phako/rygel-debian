/*
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
#include <libsoup/soup.h>
#include <gst/gst.h>
#include <stdlib.h>
#include <string.h>


#define RYGEL_TYPE_HTTP_SEEK (rygel_http_seek_get_type ())
#define RYGEL_HTTP_SEEK(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_SEEK, RygelHTTPSeek))
#define RYGEL_HTTP_SEEK_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_SEEK, RygelHTTPSeekClass))
#define RYGEL_IS_HTTP_SEEK(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_SEEK))
#define RYGEL_IS_HTTP_SEEK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_SEEK))
#define RYGEL_HTTP_SEEK_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_SEEK, RygelHTTPSeekClass))

typedef struct _RygelHTTPSeek RygelHTTPSeek;
typedef struct _RygelHTTPSeekClass RygelHTTPSeekClass;
typedef struct _RygelHTTPSeekPrivate RygelHTTPSeekPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))

typedef enum  {
	RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE = SOUP_STATUS_BAD_REQUEST,
	RYGEL_HTTP_SEEK_ERROR_OUT_OF_RANGE = SOUP_STATUS_REQUESTED_RANGE_NOT_SATISFIABLE
} RygelHTTPSeekError;
#define RYGEL_HTTP_SEEK_ERROR rygel_http_seek_error_quark ()
struct _RygelHTTPSeek {
	GObject parent_instance;
	RygelHTTPSeekPrivate * priv;
};

struct _RygelHTTPSeekClass {
	GObjectClass parent_class;
};

struct _RygelHTTPSeekPrivate {
	GstFormat _format;
	gint64 _start;
	gint64 _stop;
};


static gpointer rygel_http_seek_parent_class = NULL;

GQuark rygel_http_seek_error_quark (void);
GType rygel_http_seek_get_type (void);
#define RYGEL_HTTP_SEEK_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_HTTP_SEEK, RygelHTTPSeekPrivate))
enum  {
	RYGEL_HTTP_SEEK_DUMMY_PROPERTY,
	RYGEL_HTTP_SEEK_FORMAT,
	RYGEL_HTTP_SEEK_START,
	RYGEL_HTTP_SEEK_STOP,
	RYGEL_HTTP_SEEK_LENGTH
};
static void rygel_http_seek_set_format (RygelHTTPSeek* self, GstFormat value);
static void rygel_http_seek_set_start (RygelHTTPSeek* self, gint64 value);
static void rygel_http_seek_set_stop (RygelHTTPSeek* self, gint64 value);
RygelHTTPSeek* rygel_http_seek_new (GstFormat format, gint64 start, gint64 stop);
RygelHTTPSeek* rygel_http_seek_construct (GType object_type, GstFormat format, gint64 start, gint64 stop);
RygelHTTPSeek* rygel_http_seek_from_byte_range (SoupMessage* msg, GError** error);
RygelHTTPSeek* rygel_http_seek_from_time_range (SoupMessage* msg, GError** error);
GstFormat rygel_http_seek_get_format (RygelHTTPSeek* self);
gint64 rygel_http_seek_get_start (RygelHTTPSeek* self);
gint64 rygel_http_seek_get_stop (RygelHTTPSeek* self);
void rygel_http_seek_add_response_header (RygelHTTPSeek* self, SoupMessage* msg, gint64 length);
gint64 rygel_http_seek_get_length (RygelHTTPSeek* self);
static void rygel_http_seek_finalize (GObject* obj);
static void rygel_http_seek_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void rygel_http_seek_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);
static int _vala_strcmp0 (const char * str1, const char * str2);



GQuark rygel_http_seek_error_quark (void) {
	return g_quark_from_static_string ("rygel_http_seek_error-quark");
}


RygelHTTPSeek* rygel_http_seek_construct (GType object_type, GstFormat format, gint64 start, gint64 stop) {
	RygelHTTPSeek * self;
	self = (RygelHTTPSeek*) g_object_new (object_type, NULL);
	rygel_http_seek_set_format (self, format);
	rygel_http_seek_set_start (self, start);
	rygel_http_seek_set_stop (self, stop);
	return self;
}


RygelHTTPSeek* rygel_http_seek_new (GstFormat format, gint64 start, gint64 stop) {
	return rygel_http_seek_construct (RYGEL_TYPE_HTTP_SEEK, format, start, stop);
}


RygelHTTPSeek* rygel_http_seek_from_byte_range (SoupMessage* msg, GError** error) {
	RygelHTTPSeek* result;
	GError * _inner_error_;
	char* range;
	char* pos;
	gint range_tokens_size;
	gint range_tokens_length1;
	char** range_tokens;
	gint64 start;
	gint64 stop;
	char* _tmp0_;
	char** _tmp2_;
	char** _tmp1_;
	gboolean _tmp3_;
	char* _tmp4_;
	char* _tmp5_;
	g_return_val_if_fail (msg != NULL, NULL);
	_inner_error_ = NULL;
	range = NULL;
	pos = NULL;
	range_tokens = (range_tokens_length1 = 0, NULL);
	start = (gint64) 0;
	stop = (gint64) (-1);
	range = (_tmp0_ = g_strdup (soup_message_headers_get (msg->request_headers, "Range")), _g_free0 (range), _tmp0_);
	if (range == NULL) {
		result = NULL;
		_g_free0 (range);
		_g_free0 (pos);
		range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
		return result;
	}
	if (!g_str_has_prefix (range, "bytes=")) {
		_inner_error_ = g_error_new (RYGEL_HTTP_SEEK_ERROR, RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE, "Invalid Range '%s'", range);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == RYGEL_HTTP_SEEK_ERROR) {
				g_propagate_error (error, _inner_error_);
				_g_free0 (range);
				_g_free0 (pos);
				range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
				return NULL;
			} else {
				_g_free0 (range);
				_g_free0 (pos);
				range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return NULL;
			}
		}
	}
	range_tokens = (_tmp2_ = _tmp1_ = g_strsplit (g_utf8_offset_to_pointer (range, (glong) 6), "-", 2), range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL), range_tokens_length1 = _vala_array_length (_tmp1_), range_tokens_size = range_tokens_length1, _tmp2_);
	_tmp3_ = FALSE;
	if (range_tokens[0] == NULL) {
		_tmp3_ = TRUE;
	} else {
		_tmp3_ = range_tokens[1] == NULL;
	}
	if (_tmp3_) {
		_inner_error_ = g_error_new (RYGEL_HTTP_SEEK_ERROR, RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE, "Invalid Range '%s'", range);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == RYGEL_HTTP_SEEK_ERROR) {
				g_propagate_error (error, _inner_error_);
				_g_free0 (range);
				_g_free0 (pos);
				range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
				return NULL;
			} else {
				_g_free0 (range);
				_g_free0 (pos);
				range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return NULL;
			}
		}
	}
	pos = (_tmp4_ = g_strdup (range_tokens[0]), _g_free0 (pos), _tmp4_);
	if (g_unichar_isdigit (g_utf8_get_char (g_utf8_offset_to_pointer (pos, 0)))) {
		start = g_ascii_strtoll (pos, NULL, 0);
	} else {
		if (_vala_strcmp0 (pos, "") != 0) {
			_inner_error_ = g_error_new (RYGEL_HTTP_SEEK_ERROR, RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE, "Invalid Range '%s'", range);
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == RYGEL_HTTP_SEEK_ERROR) {
					g_propagate_error (error, _inner_error_);
					_g_free0 (range);
					_g_free0 (pos);
					range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
					return NULL;
				} else {
					_g_free0 (range);
					_g_free0 (pos);
					range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
					g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
					g_clear_error (&_inner_error_);
					return NULL;
				}
			}
		}
	}
	pos = (_tmp5_ = g_strdup (range_tokens[1]), _g_free0 (pos), _tmp5_);
	if (g_unichar_isdigit (g_utf8_get_char (g_utf8_offset_to_pointer (pos, 0)))) {
		stop = g_ascii_strtoll (pos, NULL, 0);
		if (stop < start) {
			_inner_error_ = g_error_new (RYGEL_HTTP_SEEK_ERROR, RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE, "Invalid Range '%s'", range);
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == RYGEL_HTTP_SEEK_ERROR) {
					g_propagate_error (error, _inner_error_);
					_g_free0 (range);
					_g_free0 (pos);
					range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
					return NULL;
				} else {
					_g_free0 (range);
					_g_free0 (pos);
					range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
					g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
					g_clear_error (&_inner_error_);
					return NULL;
				}
			}
		}
	} else {
		if (_vala_strcmp0 (pos, "") != 0) {
			_inner_error_ = g_error_new (RYGEL_HTTP_SEEK_ERROR, RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE, "Invalid Range '%s'", range);
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == RYGEL_HTTP_SEEK_ERROR) {
					g_propagate_error (error, _inner_error_);
					_g_free0 (range);
					_g_free0 (pos);
					range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
					return NULL;
				} else {
					_g_free0 (range);
					_g_free0 (pos);
					range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
					g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
					g_clear_error (&_inner_error_);
					return NULL;
				}
			}
		}
	}
	result = rygel_http_seek_new (GST_FORMAT_BYTES, start, stop);
	_g_free0 (range);
	_g_free0 (pos);
	range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
	return result;
}


RygelHTTPSeek* rygel_http_seek_from_time_range (SoupMessage* msg, GError** error) {
	RygelHTTPSeek* result;
	GError * _inner_error_;
	char* range;
	char* time;
	gint range_tokens_size;
	gint range_tokens_length1;
	char** range_tokens;
	gint64 start;
	gint64 stop;
	char* _tmp0_;
	char** _tmp2_;
	char** _tmp1_;
	gboolean _tmp3_;
	char* _tmp4_;
	char* _tmp5_;
	g_return_val_if_fail (msg != NULL, NULL);
	_inner_error_ = NULL;
	range = NULL;
	time = NULL;
	range_tokens = (range_tokens_length1 = 0, NULL);
	start = (gint64) 0;
	stop = (gint64) (-1);
	range = (_tmp0_ = g_strdup (soup_message_headers_get (msg->request_headers, "TimeSeekRange.dlna.org")), _g_free0 (range), _tmp0_);
	if (range == NULL) {
		result = NULL;
		_g_free0 (range);
		_g_free0 (time);
		range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
		return result;
	}
	if (!g_str_has_prefix (range, "npt=")) {
		_inner_error_ = g_error_new (RYGEL_HTTP_SEEK_ERROR, RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE, "Invalid Range '%s'", range);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == RYGEL_HTTP_SEEK_ERROR) {
				g_propagate_error (error, _inner_error_);
				_g_free0 (range);
				_g_free0 (time);
				range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
				return NULL;
			} else {
				_g_free0 (range);
				_g_free0 (time);
				range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return NULL;
			}
		}
	}
	range_tokens = (_tmp2_ = _tmp1_ = g_strsplit (g_utf8_offset_to_pointer (range, (glong) 4), "-", 2), range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL), range_tokens_length1 = _vala_array_length (_tmp1_), range_tokens_size = range_tokens_length1, _tmp2_);
	_tmp3_ = FALSE;
	if (range_tokens[0] == NULL) {
		_tmp3_ = TRUE;
	} else {
		_tmp3_ = range_tokens[1] == NULL;
	}
	if (_tmp3_) {
		_inner_error_ = g_error_new (RYGEL_HTTP_SEEK_ERROR, RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE, "Invalid Range '%s'", range);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == RYGEL_HTTP_SEEK_ERROR) {
				g_propagate_error (error, _inner_error_);
				_g_free0 (range);
				_g_free0 (time);
				range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
				return NULL;
			} else {
				_g_free0 (range);
				_g_free0 (time);
				range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return NULL;
			}
		}
	}
	time = (_tmp4_ = g_strdup (range_tokens[0]), _g_free0 (time), _tmp4_);
	if (g_unichar_isdigit (g_utf8_get_char (g_utf8_offset_to_pointer (time, 0)))) {
		start = (gint64) (g_ascii_strtod (time, NULL) * GST_SECOND);
	} else {
		if (_vala_strcmp0 (time, "") != 0) {
			_inner_error_ = g_error_new (RYGEL_HTTP_SEEK_ERROR, RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE, "Invalid Range '%s'", range);
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == RYGEL_HTTP_SEEK_ERROR) {
					g_propagate_error (error, _inner_error_);
					_g_free0 (range);
					_g_free0 (time);
					range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
					return NULL;
				} else {
					_g_free0 (range);
					_g_free0 (time);
					range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
					g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
					g_clear_error (&_inner_error_);
					return NULL;
				}
			}
		}
	}
	time = (_tmp5_ = g_strdup (range_tokens[1]), _g_free0 (time), _tmp5_);
	if (g_unichar_isdigit (g_utf8_get_char (g_utf8_offset_to_pointer (time, 0)))) {
		stop = (gint64) (g_ascii_strtod (time, NULL) * GST_SECOND);
		if (stop < start) {
			_inner_error_ = g_error_new (RYGEL_HTTP_SEEK_ERROR, RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE, "Invalid Range '%s'", range);
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == RYGEL_HTTP_SEEK_ERROR) {
					g_propagate_error (error, _inner_error_);
					_g_free0 (range);
					_g_free0 (time);
					range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
					return NULL;
				} else {
					_g_free0 (range);
					_g_free0 (time);
					range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
					g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
					g_clear_error (&_inner_error_);
					return NULL;
				}
			}
		}
	} else {
		if (_vala_strcmp0 (time, "") != 0) {
			_inner_error_ = g_error_new (RYGEL_HTTP_SEEK_ERROR, RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE, "Invalid Range '%s'", range);
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == RYGEL_HTTP_SEEK_ERROR) {
					g_propagate_error (error, _inner_error_);
					_g_free0 (range);
					_g_free0 (time);
					range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
					return NULL;
				} else {
					_g_free0 (range);
					_g_free0 (time);
					range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
					g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
					g_clear_error (&_inner_error_);
					return NULL;
				}
			}
		}
	}
	result = rygel_http_seek_new (GST_FORMAT_TIME, start, stop);
	_g_free0 (range);
	_g_free0 (time);
	range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
	return result;
}


void rygel_http_seek_add_response_header (RygelHTTPSeek* self, SoupMessage* msg, gint64 length) {
	char* value;
	g_return_if_fail (self != NULL);
	g_return_if_fail (msg != NULL);
	value = NULL;
	if (self->priv->_format == GST_FORMAT_TIME) {
		char* _tmp0_;
		value = (_tmp0_ = g_strdup_printf ("npt=%g-", ((double) self->priv->_start) / GST_SECOND), _g_free0 (value), _tmp0_);
		if (self->priv->_stop > 0) {
			char* _tmp2_;
			char* _tmp1_;
			value = (_tmp2_ = g_strconcat (value, _tmp1_ = g_strdup_printf ("%g", ((double) self->priv->_stop) / GST_SECOND), NULL), _g_free0 (value), _tmp2_);
			_g_free0 (_tmp1_);
		}
		soup_message_headers_append (msg->response_headers, "TimeSeekRange.dlna.org", value);
	} else {
		char* _tmp5_;
		char* _tmp4_;
		char* _tmp3_;
		gint64 end_point;
		value = (_tmp5_ = g_strconcat (_tmp4_ = g_strconcat ("bytes ", _tmp3_ = g_strdup_printf ("%lli", self->priv->_start), NULL), "-", NULL), _g_free0 (value), _tmp5_);
		_g_free0 (_tmp4_);
		_g_free0 (_tmp3_);
		end_point = self->priv->_stop;
		if (length > 0) {
			if (end_point >= 0) {
				end_point = MAX (end_point, length - 1);
			} else {
				end_point = length - 1;
			}
		}
		if (end_point >= 0) {
			char* _tmp7_;
			char* _tmp6_;
			value = (_tmp7_ = g_strconcat (value, _tmp6_ = g_strdup_printf ("%lli", end_point), NULL), _g_free0 (value), _tmp7_);
			_g_free0 (_tmp6_);
		}
	}
	if (length > 0) {
		char* _tmp10_;
		char* _tmp9_;
		char* _tmp8_;
		value = (_tmp10_ = g_strconcat (value, _tmp9_ = g_strconcat ("/", _tmp8_ = g_strdup_printf ("%lli", length), NULL), NULL), _g_free0 (value), _tmp10_);
		_g_free0 (_tmp9_);
		_g_free0 (_tmp8_);
	}
	soup_message_headers_append (msg->response_headers, "Content-Range", value);
	_g_free0 (value);
}


GstFormat rygel_http_seek_get_format (RygelHTTPSeek* self) {
	GstFormat result;
	g_return_val_if_fail (self != NULL, 0);
	result = self->priv->_format;
	return result;
}


static void rygel_http_seek_set_format (RygelHTTPSeek* self, GstFormat value) {
	g_return_if_fail (self != NULL);
	self->priv->_format = value;
	g_object_notify ((GObject *) self, "format");
}


gint64 rygel_http_seek_get_start (RygelHTTPSeek* self) {
	gint64 result;
	g_return_val_if_fail (self != NULL, 0LL);
	result = self->priv->_start;
	return result;
}


static void rygel_http_seek_set_start (RygelHTTPSeek* self, gint64 value) {
	g_return_if_fail (self != NULL);
	self->priv->_start = value;
	g_object_notify ((GObject *) self, "start");
}


gint64 rygel_http_seek_get_stop (RygelHTTPSeek* self) {
	gint64 result;
	g_return_val_if_fail (self != NULL, 0LL);
	result = self->priv->_stop;
	return result;
}


static void rygel_http_seek_set_stop (RygelHTTPSeek* self, gint64 value) {
	g_return_if_fail (self != NULL);
	self->priv->_stop = value;
	g_object_notify ((GObject *) self, "stop");
}


gint64 rygel_http_seek_get_length (RygelHTTPSeek* self) {
	gint64 result;
	g_return_val_if_fail (self != NULL, 0LL);
	result = (self->priv->_stop + 1) - self->priv->_start;
	return result;
}


static void rygel_http_seek_class_init (RygelHTTPSeekClass * klass) {
	rygel_http_seek_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelHTTPSeekPrivate));
	G_OBJECT_CLASS (klass)->get_property = rygel_http_seek_get_property;
	G_OBJECT_CLASS (klass)->set_property = rygel_http_seek_set_property;
	G_OBJECT_CLASS (klass)->finalize = rygel_http_seek_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), RYGEL_HTTP_SEEK_FORMAT, g_param_spec_enum ("format", "format", "format", GST_TYPE_FORMAT, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), RYGEL_HTTP_SEEK_START, g_param_spec_int64 ("start", "start", "start", G_MININT64, G_MAXINT64, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), RYGEL_HTTP_SEEK_STOP, g_param_spec_int64 ("stop", "stop", "stop", G_MININT64, G_MAXINT64, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), RYGEL_HTTP_SEEK_LENGTH, g_param_spec_int64 ("length", "length", "length", G_MININT64, G_MAXINT64, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
}


static void rygel_http_seek_instance_init (RygelHTTPSeek * self) {
	self->priv = RYGEL_HTTP_SEEK_GET_PRIVATE (self);
}


static void rygel_http_seek_finalize (GObject* obj) {
	RygelHTTPSeek * self;
	self = RYGEL_HTTP_SEEK (obj);
	G_OBJECT_CLASS (rygel_http_seek_parent_class)->finalize (obj);
}


GType rygel_http_seek_get_type (void) {
	static GType rygel_http_seek_type_id = 0;
	if (rygel_http_seek_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelHTTPSeekClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_http_seek_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelHTTPSeek), 0, (GInstanceInitFunc) rygel_http_seek_instance_init, NULL };
		rygel_http_seek_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelHTTPSeek", &g_define_type_info, 0);
	}
	return rygel_http_seek_type_id;
}


static void rygel_http_seek_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	RygelHTTPSeek * self;
	self = RYGEL_HTTP_SEEK (object);
	switch (property_id) {
		case RYGEL_HTTP_SEEK_FORMAT:
		g_value_set_enum (value, rygel_http_seek_get_format (self));
		break;
		case RYGEL_HTTP_SEEK_START:
		g_value_set_int64 (value, rygel_http_seek_get_start (self));
		break;
		case RYGEL_HTTP_SEEK_STOP:
		g_value_set_int64 (value, rygel_http_seek_get_stop (self));
		break;
		case RYGEL_HTTP_SEEK_LENGTH:
		g_value_set_int64 (value, rygel_http_seek_get_length (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void rygel_http_seek_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	RygelHTTPSeek * self;
	self = RYGEL_HTTP_SEEK (object);
	switch (property_id) {
		case RYGEL_HTTP_SEEK_FORMAT:
		rygel_http_seek_set_format (self, g_value_get_enum (value));
		break;
		case RYGEL_HTTP_SEEK_START:
		rygel_http_seek_set_start (self, g_value_get_int64 (value));
		break;
		case RYGEL_HTTP_SEEK_STOP:
		rygel_http_seek_set_stop (self, g_value_get_int64 (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
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



