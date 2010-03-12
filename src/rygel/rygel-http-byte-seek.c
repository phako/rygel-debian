/* rygel-http-byte-seek.c generated by valac, the Vala compiler
 * generated from rygel-http-byte-seek.vala, do not modify */

/*
 * Copyright (C) 2009 Nokia Corporation.
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
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>
#include <libsoup/soup.h>
#include <gee.h>
#include <gst/gst.h>
#include <float.h>
#include <math.h>


#define RYGEL_TYPE_HTTP_SEEK (rygel_http_seek_get_type ())
#define RYGEL_HTTP_SEEK(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_SEEK, RygelHTTPSeek))
#define RYGEL_HTTP_SEEK_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_SEEK, RygelHTTPSeekClass))
#define RYGEL_IS_HTTP_SEEK(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_SEEK))
#define RYGEL_IS_HTTP_SEEK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_SEEK))
#define RYGEL_HTTP_SEEK_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_SEEK, RygelHTTPSeekClass))

typedef struct _RygelHTTPSeek RygelHTTPSeek;
typedef struct _RygelHTTPSeekClass RygelHTTPSeekClass;
typedef struct _RygelHTTPSeekPrivate RygelHTTPSeekPrivate;

#define RYGEL_TYPE_HTTP_BYTE_SEEK (rygel_http_byte_seek_get_type ())
#define RYGEL_HTTP_BYTE_SEEK(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_BYTE_SEEK, RygelHTTPByteSeek))
#define RYGEL_HTTP_BYTE_SEEK_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_BYTE_SEEK, RygelHTTPByteSeekClass))
#define RYGEL_IS_HTTP_BYTE_SEEK(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_BYTE_SEEK))
#define RYGEL_IS_HTTP_BYTE_SEEK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_BYTE_SEEK))
#define RYGEL_HTTP_BYTE_SEEK_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_BYTE_SEEK, RygelHTTPByteSeekClass))

typedef struct _RygelHTTPByteSeek RygelHTTPByteSeek;
typedef struct _RygelHTTPByteSeekClass RygelHTTPByteSeekClass;
typedef struct _RygelHTTPByteSeekPrivate RygelHTTPByteSeekPrivate;

#define RYGEL_TYPE_STATE_MACHINE (rygel_state_machine_get_type ())
#define RYGEL_STATE_MACHINE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_STATE_MACHINE, RygelStateMachine))
#define RYGEL_IS_STATE_MACHINE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_STATE_MACHINE))
#define RYGEL_STATE_MACHINE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), RYGEL_TYPE_STATE_MACHINE, RygelStateMachineIface))

typedef struct _RygelStateMachine RygelStateMachine;
typedef struct _RygelStateMachineIface RygelStateMachineIface;

#define RYGEL_TYPE_HTTP_REQUEST (rygel_http_request_get_type ())
#define RYGEL_HTTP_REQUEST(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_REQUEST, RygelHTTPRequest))
#define RYGEL_HTTP_REQUEST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_REQUEST, RygelHTTPRequestClass))
#define RYGEL_IS_HTTP_REQUEST(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_REQUEST))
#define RYGEL_IS_HTTP_REQUEST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_REQUEST))
#define RYGEL_HTTP_REQUEST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_REQUEST, RygelHTTPRequestClass))

typedef struct _RygelHTTPRequest RygelHTTPRequest;
typedef struct _RygelHTTPRequestClass RygelHTTPRequestClass;
typedef struct _RygelHTTPRequestPrivate RygelHTTPRequestPrivate;

#define RYGEL_TYPE_TRANSCODE_MANAGER (rygel_transcode_manager_get_type ())
#define RYGEL_TRANSCODE_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRANSCODE_MANAGER, RygelTranscodeManager))
#define RYGEL_TRANSCODE_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRANSCODE_MANAGER, RygelTranscodeManagerClass))
#define RYGEL_IS_TRANSCODE_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRANSCODE_MANAGER))
#define RYGEL_IS_TRANSCODE_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRANSCODE_MANAGER))
#define RYGEL_TRANSCODE_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRANSCODE_MANAGER, RygelTranscodeManagerClass))

typedef struct _RygelTranscodeManager RygelTranscodeManager;
typedef struct _RygelTranscodeManagerClass RygelTranscodeManagerClass;

#define RYGEL_TYPE_HTTP_SERVER (rygel_http_server_get_type ())
#define RYGEL_HTTP_SERVER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_SERVER, RygelHTTPServer))
#define RYGEL_HTTP_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_SERVER, RygelHTTPServerClass))
#define RYGEL_IS_HTTP_SERVER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_SERVER))
#define RYGEL_IS_HTTP_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_SERVER))
#define RYGEL_HTTP_SERVER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_SERVER, RygelHTTPServerClass))

typedef struct _RygelHTTPServer RygelHTTPServer;
typedef struct _RygelHTTPServerClass RygelHTTPServerClass;

#define RYGEL_TYPE_MEDIA_OBJECT (rygel_media_object_get_type ())
#define RYGEL_MEDIA_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObject))
#define RYGEL_MEDIA_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObjectClass))
#define RYGEL_IS_MEDIA_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_OBJECT))
#define RYGEL_IS_MEDIA_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_OBJECT))
#define RYGEL_MEDIA_OBJECT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObjectClass))

typedef struct _RygelMediaObject RygelMediaObject;
typedef struct _RygelMediaObjectClass RygelMediaObjectClass;

#define RYGEL_TYPE_MEDIA_ITEM (rygel_media_item_get_type ())
#define RYGEL_MEDIA_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_ITEM, RygelMediaItem))
#define RYGEL_MEDIA_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_ITEM, RygelMediaItemClass))
#define RYGEL_IS_MEDIA_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_ITEM))
#define RYGEL_IS_MEDIA_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_ITEM))
#define RYGEL_MEDIA_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_ITEM, RygelMediaItemClass))

typedef struct _RygelMediaItem RygelMediaItem;
typedef struct _RygelMediaItemClass RygelMediaItemClass;

#define RYGEL_TYPE_ICON_INFO (rygel_icon_info_get_type ())
#define RYGEL_ICON_INFO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_ICON_INFO, RygelIconInfo))
#define RYGEL_ICON_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_ICON_INFO, RygelIconInfoClass))
#define RYGEL_IS_ICON_INFO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_ICON_INFO))
#define RYGEL_IS_ICON_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_ICON_INFO))
#define RYGEL_ICON_INFO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_ICON_INFO, RygelIconInfoClass))

typedef struct _RygelIconInfo RygelIconInfo;
typedef struct _RygelIconInfoClass RygelIconInfoClass;

#define RYGEL_TYPE_THUMBNAIL (rygel_thumbnail_get_type ())
#define RYGEL_THUMBNAIL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_THUMBNAIL, RygelThumbnail))
#define RYGEL_THUMBNAIL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_THUMBNAIL, RygelThumbnailClass))
#define RYGEL_IS_THUMBNAIL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_THUMBNAIL))
#define RYGEL_IS_THUMBNAIL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_THUMBNAIL))
#define RYGEL_THUMBNAIL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_THUMBNAIL, RygelThumbnailClass))

typedef struct _RygelThumbnail RygelThumbnail;
typedef struct _RygelThumbnailClass RygelThumbnailClass;

#define RYGEL_TYPE_HTTP_REQUEST_HANDLER (rygel_http_request_handler_get_type ())
#define RYGEL_HTTP_REQUEST_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_REQUEST_HANDLER, RygelHTTPRequestHandler))
#define RYGEL_HTTP_REQUEST_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_REQUEST_HANDLER, RygelHTTPRequestHandlerClass))
#define RYGEL_IS_HTTP_REQUEST_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_REQUEST_HANDLER))
#define RYGEL_IS_HTTP_REQUEST_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_REQUEST_HANDLER))
#define RYGEL_HTTP_REQUEST_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_REQUEST_HANDLER, RygelHTTPRequestHandlerClass))

typedef struct _RygelHTTPRequestHandler RygelHTTPRequestHandler;
typedef struct _RygelHTTPRequestHandlerClass RygelHTTPRequestHandlerClass;
typedef struct _RygelIconInfoPrivate RygelIconInfoPrivate;
typedef struct _RygelMediaObjectPrivate RygelMediaObjectPrivate;

#define RYGEL_TYPE_MEDIA_CONTAINER (rygel_media_container_get_type ())
#define RYGEL_MEDIA_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainer))
#define RYGEL_MEDIA_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainerClass))
#define RYGEL_IS_MEDIA_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_CONTAINER))
#define RYGEL_IS_MEDIA_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_CONTAINER))
#define RYGEL_MEDIA_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainerClass))

typedef struct _RygelMediaContainer RygelMediaContainer;
typedef struct _RygelMediaContainerClass RygelMediaContainerClass;
typedef struct _RygelMediaItemPrivate RygelMediaItemPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))

#define RYGEL_TYPE_HTTP_IDENTITY_HANDLER (rygel_http_identity_handler_get_type ())
#define RYGEL_HTTP_IDENTITY_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_IDENTITY_HANDLER, RygelHTTPIdentityHandler))
#define RYGEL_HTTP_IDENTITY_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_IDENTITY_HANDLER, RygelHTTPIdentityHandlerClass))
#define RYGEL_IS_HTTP_IDENTITY_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_IDENTITY_HANDLER))
#define RYGEL_IS_HTTP_IDENTITY_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_IDENTITY_HANDLER))
#define RYGEL_HTTP_IDENTITY_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_IDENTITY_HANDLER, RygelHTTPIdentityHandlerClass))

typedef struct _RygelHTTPIdentityHandler RygelHTTPIdentityHandler;
typedef struct _RygelHTTPIdentityHandlerClass RygelHTTPIdentityHandlerClass;

struct _RygelHTTPSeek {
	GObject parent_instance;
	RygelHTTPSeekPrivate * priv;
};

struct _RygelHTTPSeekClass {
	GObjectClass parent_class;
	void (*add_response_headers) (RygelHTTPSeek* self);
};

struct _RygelHTTPByteSeek {
	RygelHTTPSeek parent_instance;
	RygelHTTPByteSeekPrivate * priv;
};

struct _RygelHTTPByteSeekClass {
	RygelHTTPSeekClass parent_class;
};

struct _RygelStateMachineIface {
	GTypeInterface parent_iface;
	void (*run) (RygelStateMachine* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
	void (*run_finish) (RygelStateMachine* self, GAsyncResult* _res_);
	GCancellable* (*get_cancellable) (RygelStateMachine* self);
	void (*set_cancellable) (RygelStateMachine* self, GCancellable* value);
};

struct _RygelHTTPRequest {
	GObject parent_instance;
	RygelHTTPRequestPrivate * priv;
	RygelHTTPServer* http_server;
	SoupServer* server;
	SoupMessage* msg;
	RygelMediaItem* item;
	RygelThumbnail* thumbnail;
	RygelHTTPSeek* seek;
	RygelHTTPRequestHandler* handler;
};

struct _RygelHTTPRequestClass {
	GObjectClass parent_class;
};

struct _RygelIconInfo {
	GTypeInstance parent_instance;
	volatile int ref_count;
	RygelIconInfoPrivate * priv;
	char* mime_type;
	char* uri;
	glong size;
	gint width;
	gint height;
	gint depth;
};

struct _RygelIconInfoClass {
	GTypeClass parent_class;
	void (*finalize) (RygelIconInfo *self);
};

struct _RygelMediaObject {
	GObject parent_instance;
	RygelMediaObjectPrivate * priv;
	char* id;
	char* upnp_class;
	guint64 modified;
	GeeArrayList* uris;
	RygelMediaContainer* parent;
	RygelMediaContainer* parent_ref;
};

struct _RygelMediaObjectClass {
	GObjectClass parent_class;
};

struct _RygelMediaItem {
	RygelMediaObject parent_instance;
	RygelMediaItemPrivate * priv;
	char* author;
	char* album;
	char* date;
	char* mime_type;
	char* dlna_profile;
	glong size;
	glong duration;
	gint bitrate;
	gint sample_freq;
	gint bits_per_sample;
	gint n_audio_channels;
	gint track_number;
	gint width;
	gint height;
	gint pixel_width;
	gint pixel_height;
	gint color_depth;
	GeeArrayList* thumbnails;
};

struct _RygelMediaItemClass {
	RygelMediaObjectClass parent_class;
	GstElement* (*create_stream_source) (RygelMediaItem* self);
	gboolean (*should_stream) (RygelMediaItem* self);
};

typedef enum  {
	RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE = SOUP_STATUS_BAD_REQUEST,
	RYGEL_HTTP_SEEK_ERROR_OUT_OF_RANGE = SOUP_STATUS_REQUESTED_RANGE_NOT_SATISFIABLE
} RygelHTTPSeekError;
#define RYGEL_HTTP_SEEK_ERROR rygel_http_seek_error_quark ()

static gpointer rygel_http_byte_seek_parent_class = NULL;

GType rygel_http_seek_get_type (void);
GType rygel_http_byte_seek_get_type (void);
enum  {
	RYGEL_HTTP_BYTE_SEEK_DUMMY_PROPERTY
};
GType rygel_state_machine_get_type (void);
GType rygel_http_request_get_type (void);
GType rygel_transcode_manager_get_type (void);
GType rygel_http_server_get_type (void);
GType rygel_media_object_get_type (void);
GType rygel_media_item_get_type (void);
gpointer rygel_icon_info_ref (gpointer instance);
void rygel_icon_info_unref (gpointer instance);
GParamSpec* rygel_param_spec_icon_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_icon_info (GValue* value, gpointer v_object);
gpointer rygel_value_get_icon_info (const GValue* value);
GType rygel_icon_info_get_type (void);
GType rygel_thumbnail_get_type (void);
GType rygel_http_request_handler_get_type (void);
GType rygel_media_container_get_type (void);
GQuark rygel_http_seek_error_quark (void);
RygelHTTPSeek* rygel_http_seek_construct (GType object_type, SoupMessage* msg, gint64 start, gint64 stop, gint64 length);
RygelHTTPByteSeek* rygel_http_byte_seek_new (RygelHTTPRequest* request, GError** error);
RygelHTTPByteSeek* rygel_http_byte_seek_construct (GType object_type, RygelHTTPRequest* request, GError** error);
GType rygel_http_identity_handler_get_type (void);
gboolean rygel_http_byte_seek_needed (RygelHTTPRequest* request);
gint64 rygel_http_seek_get_start (RygelHTTPSeek* self);
gint64 rygel_http_seek_get_stop (RygelHTTPSeek* self);
SoupMessage* rygel_http_seek_get_msg (RygelHTTPSeek* self);
gint64 rygel_http_seek_get_length (RygelHTTPSeek* self);
static void rygel_http_byte_seek_real_add_response_headers (RygelHTTPSeek* base);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);
static int _vala_strcmp0 (const char * str1, const char * str2);



#line 25 "rygel-http-byte-seek.vala"
RygelHTTPByteSeek* rygel_http_byte_seek_construct (GType object_type, RygelHTTPRequest* request, GError** error) {
#line 327 "rygel-http-byte-seek.c"
	GError * _inner_error_;
	RygelHTTPByteSeek * self;
	char* range;
	char* pos;
	gint range_tokens_size;
	gint range_tokens_length1;
	char** range_tokens;
	gint64 start;
	gint64 total_length = 0LL;
	gint64 stop;
	char* _tmp0_;
#line 25 "rygel-http-byte-seek.vala"
	g_return_val_if_fail (request != NULL, NULL);
#line 341 "rygel-http-byte-seek.c"
	_inner_error_ = NULL;
	range = NULL;
	pos = NULL;
	range_tokens = (range_tokens_length1 = 0, NULL);
#line 28 "rygel-http-byte-seek.vala"
	start = (gint64) 0;
#line 30 "rygel-http-byte-seek.vala"
	if (request->thumbnail != NULL) {
#line 31 "rygel-http-byte-seek.vala"
		total_length = (gint64) ((RygelIconInfo*) request->thumbnail)->size;
#line 352 "rygel-http-byte-seek.c"
	} else {
#line 33 "rygel-http-byte-seek.vala"
		total_length = (gint64) request->item->size;
#line 356 "rygel-http-byte-seek.c"
	}
#line 35 "rygel-http-byte-seek.vala"
	stop = total_length - 1;
#line 37 "rygel-http-byte-seek.vala"
	range = (_tmp0_ = g_strdup (soup_message_headers_get (request->msg->request_headers, "Range")), _g_free0 (range), _tmp0_);
#line 38 "rygel-http-byte-seek.vala"
	if (range != NULL) {
#line 364 "rygel-http-byte-seek.c"
		char** _tmp2_;
		char** _tmp1_;
		gboolean _tmp3_ = FALSE;
		char* _tmp4_;
		char* _tmp5_;
#line 40 "rygel-http-byte-seek.vala"
		if (!g_str_has_prefix (range, "bytes=")) {
#line 372 "rygel-http-byte-seek.c"
			_inner_error_ = g_error_new (RYGEL_HTTP_SEEK_ERROR, RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE, "Invalid Range '%s'", range);
			{
				if (_inner_error_->domain == RYGEL_HTTP_SEEK_ERROR) {
					g_propagate_error (error, _inner_error_);
					_g_free0 (range);
					_g_free0 (pos);
					range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
					g_object_unref (self);
					return NULL;
				} else {
					_g_free0 (range);
					_g_free0 (pos);
					range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
					g_clear_error (&_inner_error_);
					return NULL;
				}
			}
		}
#line 45 "rygel-http-byte-seek.vala"
		range_tokens = (_tmp2_ = _tmp1_ = g_strsplit (g_utf8_offset_to_pointer (range, (glong) 6), "-", 2), range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL), range_tokens_length1 = _vala_array_length (_tmp1_), range_tokens_size = range_tokens_length1, _tmp2_);
#line 46 "rygel-http-byte-seek.vala"
		if (range_tokens[0] == NULL) {
#line 46 "rygel-http-byte-seek.vala"
			_tmp3_ = TRUE;
#line 398 "rygel-http-byte-seek.c"
		} else {
#line 46 "rygel-http-byte-seek.vala"
			_tmp3_ = range_tokens[1] == NULL;
#line 402 "rygel-http-byte-seek.c"
		}
#line 46 "rygel-http-byte-seek.vala"
		if (_tmp3_) {
#line 406 "rygel-http-byte-seek.c"
			_inner_error_ = g_error_new (RYGEL_HTTP_SEEK_ERROR, RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE, "Invalid Range '%s'", range);
			{
				if (_inner_error_->domain == RYGEL_HTTP_SEEK_ERROR) {
					g_propagate_error (error, _inner_error_);
					_g_free0 (range);
					_g_free0 (pos);
					range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
					g_object_unref (self);
					return NULL;
				} else {
					_g_free0 (range);
					_g_free0 (pos);
					range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
					g_clear_error (&_inner_error_);
					return NULL;
				}
			}
		}
#line 52 "rygel-http-byte-seek.vala"
		pos = (_tmp4_ = g_strdup (range_tokens[0]), _g_free0 (pos), _tmp4_);
#line 53 "rygel-http-byte-seek.vala"
		if (g_unichar_isdigit (g_utf8_get_char (g_utf8_offset_to_pointer (pos, 0)))) {
#line 54 "rygel-http-byte-seek.vala"
			start = g_ascii_strtoll (pos, NULL, 0);
#line 432 "rygel-http-byte-seek.c"
		} else {
#line 55 "rygel-http-byte-seek.vala"
			if (_vala_strcmp0 (pos, "") != 0) {
#line 436 "rygel-http-byte-seek.c"
				_inner_error_ = g_error_new (RYGEL_HTTP_SEEK_ERROR, RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE, "Invalid Range '%s'", range);
				{
					if (_inner_error_->domain == RYGEL_HTTP_SEEK_ERROR) {
						g_propagate_error (error, _inner_error_);
						_g_free0 (range);
						_g_free0 (pos);
						range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
						g_object_unref (self);
						return NULL;
					} else {
						_g_free0 (range);
						_g_free0 (pos);
						range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
						g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
						g_clear_error (&_inner_error_);
						return NULL;
					}
				}
			}
		}
#line 61 "rygel-http-byte-seek.vala"
		pos = (_tmp5_ = g_strdup (range_tokens[1]), _g_free0 (pos), _tmp5_);
#line 62 "rygel-http-byte-seek.vala"
		if (g_unichar_isdigit (g_utf8_get_char (g_utf8_offset_to_pointer (pos, 0)))) {
#line 63 "rygel-http-byte-seek.vala"
			stop = g_ascii_strtoll (pos, NULL, 0);
#line 64 "rygel-http-byte-seek.vala"
			if (stop < start) {
#line 465 "rygel-http-byte-seek.c"
				_inner_error_ = g_error_new (RYGEL_HTTP_SEEK_ERROR, RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE, "Invalid Range '%s'", range);
				{
					if (_inner_error_->domain == RYGEL_HTTP_SEEK_ERROR) {
						g_propagate_error (error, _inner_error_);
						_g_free0 (range);
						_g_free0 (pos);
						range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
						g_object_unref (self);
						return NULL;
					} else {
						_g_free0 (range);
						_g_free0 (pos);
						range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
						g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
						g_clear_error (&_inner_error_);
						return NULL;
					}
				}
			}
		} else {
#line 68 "rygel-http-byte-seek.vala"
			if (_vala_strcmp0 (pos, "") != 0) {
#line 488 "rygel-http-byte-seek.c"
				_inner_error_ = g_error_new (RYGEL_HTTP_SEEK_ERROR, RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE, "Invalid Range '%s'", range);
				{
					if (_inner_error_->domain == RYGEL_HTTP_SEEK_ERROR) {
						g_propagate_error (error, _inner_error_);
						_g_free0 (range);
						_g_free0 (pos);
						range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
						g_object_unref (self);
						return NULL;
					} else {
						_g_free0 (range);
						_g_free0 (pos);
						range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
						g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
						g_clear_error (&_inner_error_);
						return NULL;
					}
				}
			}
		}
	}
#line 74 "rygel-http-byte-seek.vala"
	self = (RygelHTTPByteSeek*) rygel_http_seek_construct (object_type, request->msg, start, stop, total_length);
#line 512 "rygel-http-byte-seek.c"
	_g_free0 (range);
	_g_free0 (pos);
	range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
	return self;
}


#line 25 "rygel-http-byte-seek.vala"
RygelHTTPByteSeek* rygel_http_byte_seek_new (RygelHTTPRequest* request, GError** error) {
#line 25 "rygel-http-byte-seek.vala"
	return rygel_http_byte_seek_construct (RYGEL_TYPE_HTTP_BYTE_SEEK, request, error);
#line 524 "rygel-http-byte-seek.c"
}


#line 80 "rygel-http-byte-seek.vala"
gboolean rygel_http_byte_seek_needed (RygelHTTPRequest* request) {
#line 530 "rygel-http-byte-seek.c"
	gboolean result;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
#line 80 "rygel-http-byte-seek.vala"
	g_return_val_if_fail (request != NULL, FALSE);
#line 81 "rygel-http-byte-seek.vala"
	if (request->item->size > 0) {
#line 82 "rygel-http-byte-seek.vala"
		_tmp1_ = RYGEL_IS_HTTP_IDENTITY_HANDLER (request->handler);
#line 540 "rygel-http-byte-seek.c"
	} else {
#line 81 "rygel-http-byte-seek.vala"
		_tmp1_ = FALSE;
#line 544 "rygel-http-byte-seek.c"
	}
#line 81 "rygel-http-byte-seek.vala"
	if (_tmp1_) {
#line 81 "rygel-http-byte-seek.vala"
		_tmp0_ = TRUE;
#line 550 "rygel-http-byte-seek.c"
	} else {
		gboolean _tmp2_ = FALSE;
#line 83 "rygel-http-byte-seek.vala"
		if (request->thumbnail != NULL) {
#line 83 "rygel-http-byte-seek.vala"
			_tmp2_ = ((RygelIconInfo*) request->thumbnail)->size > 0;
#line 557 "rygel-http-byte-seek.c"
		} else {
#line 83 "rygel-http-byte-seek.vala"
			_tmp2_ = FALSE;
#line 561 "rygel-http-byte-seek.c"
		}
#line 83 "rygel-http-byte-seek.vala"
		_tmp0_ = _tmp2_;
#line 565 "rygel-http-byte-seek.c"
	}
	result = _tmp0_;
#line 81 "rygel-http-byte-seek.vala"
	return result;
#line 570 "rygel-http-byte-seek.c"
}


#line 670 "glib-2.0.vapi"
static char* double_to_string (double self) {
#line 576 "rygel-http-byte-seek.c"
	char* result;
	gint _tmp0__length1;
	gchar* _tmp0_;
	char* _tmp1_;
	result = (_tmp1_ = g_strdup (g_ascii_dtostr ((_tmp0_ = g_new0 (gchar, G_ASCII_DTOSTR_BUF_SIZE), _tmp0__length1 = G_ASCII_DTOSTR_BUF_SIZE, _tmp0_), G_ASCII_DTOSTR_BUF_SIZE, self)), _tmp0_ = (g_free (_tmp0_), NULL), _tmp1_);
#line 671 "glib-2.0.vapi"
	return result;
#line 584 "rygel-http-byte-seek.c"
}


#line 86 "rygel-http-byte-seek.vala"
static void rygel_http_byte_seek_real_add_response_headers (RygelHTTPSeek* base) {
#line 590 "rygel-http-byte-seek.c"
	RygelHTTPByteSeek * self;
	char* range;
	double start;
	double stop;
	char* _tmp7_;
	char* _tmp6_;
	char* _tmp5_;
	char* _tmp4_;
	char* _tmp3_;
	char* _tmp2_;
	char* _tmp1_;
	char* _tmp0_;
	self = (RygelHTTPByteSeek*) base;
#line 88 "rygel-http-byte-seek.vala"
	range = g_strdup ("bytes ");
#line 89 "rygel-http-byte-seek.vala"
	start = (double) rygel_http_seek_get_start ((RygelHTTPSeek*) self);
#line 90 "rygel-http-byte-seek.vala"
	stop = (double) rygel_http_seek_get_stop ((RygelHTTPSeek*) self);
#line 92 "rygel-http-byte-seek.vala"
	soup_message_headers_append (rygel_http_seek_get_msg ((RygelHTTPSeek*) self)->response_headers, "Accept-Ranges", "bytes");
#line 94 "rygel-http-byte-seek.vala"
	range = (_tmp7_ = g_strconcat (range, _tmp6_ = g_strconcat (_tmp4_ = g_strconcat (_tmp3_ = g_strconcat (_tmp1_ = g_strconcat (_tmp0_ = double_to_string (start), "-", NULL), _tmp2_ = double_to_string (stop), NULL), "/", NULL), _tmp5_ = g_strdup_printf ("%lli", rygel_http_seek_get_length ((RygelHTTPSeek*) self)), NULL), NULL), _g_free0 (range), _tmp7_);
#line 614 "rygel-http-byte-seek.c"
	_g_free0 (_tmp6_);
	_g_free0 (_tmp5_);
	_g_free0 (_tmp4_);
	_g_free0 (_tmp3_);
	_g_free0 (_tmp2_);
	_g_free0 (_tmp1_);
	_g_free0 (_tmp0_);
#line 97 "rygel-http-byte-seek.vala"
	soup_message_headers_append (rygel_http_seek_get_msg ((RygelHTTPSeek*) self)->response_headers, "Content-Range", range);
#line 99 "rygel-http-byte-seek.vala"
	soup_message_headers_set_content_length (rygel_http_seek_get_msg ((RygelHTTPSeek*) self)->response_headers, rygel_http_seek_get_length ((RygelHTTPSeek*) self));
#line 626 "rygel-http-byte-seek.c"
	_g_free0 (range);
}


static void rygel_http_byte_seek_class_init (RygelHTTPByteSeekClass * klass) {
	rygel_http_byte_seek_parent_class = g_type_class_peek_parent (klass);
	RYGEL_HTTP_SEEK_CLASS (klass)->add_response_headers = rygel_http_byte_seek_real_add_response_headers;
}


static void rygel_http_byte_seek_instance_init (RygelHTTPByteSeek * self) {
}


GType rygel_http_byte_seek_get_type (void) {
	static GType rygel_http_byte_seek_type_id = 0;
	if (rygel_http_byte_seek_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelHTTPByteSeekClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_http_byte_seek_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelHTTPByteSeek), 0, (GInstanceInitFunc) rygel_http_byte_seek_instance_init, NULL };
		rygel_http_byte_seek_type_id = g_type_register_static (RYGEL_TYPE_HTTP_SEEK, "RygelHTTPByteSeek", &g_define_type_info, 0);
	}
	return rygel_http_byte_seek_type_id;
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




