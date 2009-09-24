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
#include <libsoup/soup.h>
#include <libgupnp-av/gupnp-av.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>
#include <gst/gst.h>


#define RYGEL_TYPE_HTTP_REQUEST_HANDLER (rygel_http_request_handler_get_type ())
#define RYGEL_HTTP_REQUEST_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_REQUEST_HANDLER, RygelHTTPRequestHandler))
#define RYGEL_HTTP_REQUEST_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_REQUEST_HANDLER, RygelHTTPRequestHandlerClass))
#define RYGEL_IS_HTTP_REQUEST_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_REQUEST_HANDLER))
#define RYGEL_IS_HTTP_REQUEST_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_REQUEST_HANDLER))
#define RYGEL_HTTP_REQUEST_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_REQUEST_HANDLER, RygelHTTPRequestHandlerClass))

typedef struct _RygelHTTPRequestHandler RygelHTTPRequestHandler;
typedef struct _RygelHTTPRequestHandlerClass RygelHTTPRequestHandlerClass;
typedef struct _RygelHTTPRequestHandlerPrivate RygelHTTPRequestHandlerPrivate;

#define RYGEL_TYPE_HTTP_REQUEST (rygel_http_request_get_type ())
#define RYGEL_HTTP_REQUEST(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_REQUEST, RygelHTTPRequest))
#define RYGEL_HTTP_REQUEST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_REQUEST, RygelHTTPRequestClass))
#define RYGEL_IS_HTTP_REQUEST(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_REQUEST))
#define RYGEL_IS_HTTP_REQUEST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_REQUEST))
#define RYGEL_HTTP_REQUEST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_REQUEST, RygelHTTPRequestClass))

typedef struct _RygelHTTPRequest RygelHTTPRequest;
typedef struct _RygelHTTPRequestClass RygelHTTPRequestClass;

#define RYGEL_TYPE_HTTP_RESPONSE (rygel_http_response_get_type ())
#define RYGEL_HTTP_RESPONSE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_RESPONSE, RygelHTTPResponse))
#define RYGEL_HTTP_RESPONSE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_RESPONSE, RygelHTTPResponseClass))
#define RYGEL_IS_HTTP_RESPONSE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_RESPONSE))
#define RYGEL_IS_HTTP_RESPONSE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_RESPONSE))
#define RYGEL_HTTP_RESPONSE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_RESPONSE, RygelHTTPResponseClass))

typedef struct _RygelHTTPResponse RygelHTTPResponse;
typedef struct _RygelHTTPResponseClass RygelHTTPResponseClass;

#define RYGEL_TYPE_HTTP_TRANSCODE_HANDLER (rygel_http_transcode_handler_get_type ())
#define RYGEL_HTTP_TRANSCODE_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_TRANSCODE_HANDLER, RygelHTTPTranscodeHandler))
#define RYGEL_HTTP_TRANSCODE_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_TRANSCODE_HANDLER, RygelHTTPTranscodeHandlerClass))
#define RYGEL_IS_HTTP_TRANSCODE_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_TRANSCODE_HANDLER))
#define RYGEL_IS_HTTP_TRANSCODE_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_TRANSCODE_HANDLER))
#define RYGEL_HTTP_TRANSCODE_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_TRANSCODE_HANDLER, RygelHTTPTranscodeHandlerClass))

typedef struct _RygelHTTPTranscodeHandler RygelHTTPTranscodeHandler;
typedef struct _RygelHTTPTranscodeHandlerClass RygelHTTPTranscodeHandlerClass;
typedef struct _RygelHTTPTranscodeHandlerPrivate RygelHTTPTranscodeHandlerPrivate;

#define RYGEL_TYPE_TRANSCODER (rygel_transcoder_get_type ())
#define RYGEL_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRANSCODER, RygelTranscoder))
#define RYGEL_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRANSCODER, RygelTranscoderClass))
#define RYGEL_IS_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRANSCODER))
#define RYGEL_IS_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRANSCODER))
#define RYGEL_TRANSCODER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRANSCODER, RygelTranscoderClass))

typedef struct _RygelTranscoder RygelTranscoder;
typedef struct _RygelTranscoderClass RygelTranscoderClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define RYGEL_TYPE_STATE_MACHINE (rygel_state_machine_get_type ())
#define RYGEL_STATE_MACHINE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_STATE_MACHINE, RygelStateMachine))
#define RYGEL_IS_STATE_MACHINE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_STATE_MACHINE))
#define RYGEL_STATE_MACHINE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), RYGEL_TYPE_STATE_MACHINE, RygelStateMachineIface))

typedef struct _RygelStateMachine RygelStateMachine;
typedef struct _RygelStateMachineIface RygelStateMachineIface;
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

#define RYGEL_TYPE_HTTP_SEEK (rygel_http_seek_get_type ())
#define RYGEL_HTTP_SEEK(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_SEEK, RygelHTTPSeek))
#define RYGEL_HTTP_SEEK_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_SEEK, RygelHTTPSeekClass))
#define RYGEL_IS_HTTP_SEEK(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_SEEK))
#define RYGEL_IS_HTTP_SEEK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_SEEK))
#define RYGEL_HTTP_SEEK_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_SEEK, RygelHTTPSeekClass))

typedef struct _RygelHTTPSeek RygelHTTPSeek;
typedef struct _RygelHTTPSeekClass RygelHTTPSeekClass;
#define _gst_object_unref0(var) ((var == NULL) ? NULL : (var = (gst_object_unref (var), NULL)))

#define RYGEL_TYPE_LIVE_RESPONSE (rygel_live_response_get_type ())
#define RYGEL_LIVE_RESPONSE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_LIVE_RESPONSE, RygelLiveResponse))
#define RYGEL_LIVE_RESPONSE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_LIVE_RESPONSE, RygelLiveResponseClass))
#define RYGEL_IS_LIVE_RESPONSE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_LIVE_RESPONSE))
#define RYGEL_IS_LIVE_RESPONSE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_LIVE_RESPONSE))
#define RYGEL_LIVE_RESPONSE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_LIVE_RESPONSE, RygelLiveResponseClass))

typedef struct _RygelLiveResponse RygelLiveResponse;
typedef struct _RygelLiveResponseClass RygelLiveResponseClass;

typedef enum  {
	RYGEL_HTTP_REQUEST_ERROR_UNACCEPTABLE = SOUP_STATUS_NOT_ACCEPTABLE,
	RYGEL_HTTP_REQUEST_ERROR_BAD_REQUEST = SOUP_STATUS_BAD_REQUEST,
	RYGEL_HTTP_REQUEST_ERROR_NOT_FOUND = SOUP_STATUS_NOT_FOUND
} RygelHTTPRequestError;
#define RYGEL_HTTP_REQUEST_ERROR rygel_http_request_error_quark ()
struct _RygelHTTPRequestHandler {
	GObject parent_instance;
	RygelHTTPRequestHandlerPrivate * priv;
};

struct _RygelHTTPRequestHandlerClass {
	GObjectClass parent_class;
	void (*add_response_headers) (RygelHTTPRequestHandler* self, RygelHTTPRequest* request, GError** error);
	RygelHTTPResponse* (*render_body) (RygelHTTPRequestHandler* self, RygelHTTPRequest* request, GError** error);
	GUPnPDIDLLiteResource* (*add_resource) (RygelHTTPRequestHandler* self, GUPnPDIDLLiteItem* didl_item, RygelHTTPRequest* request, GError** error);
};

struct _RygelHTTPTranscodeHandler {
	RygelHTTPRequestHandler parent_instance;
	RygelHTTPTranscodeHandlerPrivate * priv;
};

struct _RygelHTTPTranscodeHandlerClass {
	RygelHTTPRequestHandlerClass parent_class;
};

struct _RygelHTTPTranscodeHandlerPrivate {
	RygelTranscoder* transcoder;
};

struct _RygelStateMachineIface {
	GTypeInterface parent_iface;
	void (*run) (RygelStateMachine* self);
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
	RygelHTTPSeek* byte_range;
	RygelHTTPSeek* time_range;
};

struct _RygelHTTPRequestClass {
	GObjectClass parent_class;
};


static gpointer rygel_http_transcode_handler_parent_class = NULL;

GType rygel_http_request_handler_get_type (void);
GType rygel_http_request_get_type (void);
GQuark rygel_http_request_error_quark (void);
GType rygel_http_response_get_type (void);
GType rygel_http_transcode_handler_get_type (void);
GType rygel_transcoder_get_type (void);
#define RYGEL_HTTP_TRANSCODE_HANDLER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_HTTP_TRANSCODE_HANDLER, RygelHTTPTranscodeHandlerPrivate))
enum  {
	RYGEL_HTTP_TRANSCODE_HANDLER_DUMMY_PROPERTY
};
RygelHTTPRequestHandler* rygel_http_request_handler_construct (GType object_type);
void rygel_http_request_handler_set_cancellable (RygelHTTPRequestHandler* self, GCancellable* value);
RygelHTTPTranscodeHandler* rygel_http_transcode_handler_new (RygelTranscoder* transcoder, GCancellable* cancellable);
RygelHTTPTranscodeHandler* rygel_http_transcode_handler_construct (GType object_type, RygelTranscoder* transcoder, GCancellable* cancellable);
GType rygel_state_machine_get_type (void);
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
GType rygel_http_seek_get_type (void);
const char* rygel_transcoder_get_mime_type (RygelTranscoder* self);
void rygel_http_seek_add_response_header (RygelHTTPSeek* self, SoupMessage* msg, gint64 length);
void rygel_http_request_handler_add_response_headers (RygelHTTPRequestHandler* self, RygelHTTPRequest* request, GError** error);
static void rygel_http_transcode_handler_real_add_response_headers (RygelHTTPRequestHandler* base, RygelHTTPRequest* request, GError** error);
GstElement* rygel_media_item_create_stream_source (RygelMediaItem* self);
GstElement* rygel_transcoder_create_source (RygelTranscoder* self, RygelMediaItem* item, GstElement* src, GError** error);
GCancellable* rygel_http_request_handler_get_cancellable (RygelHTTPRequestHandler* self);
RygelLiveResponse* rygel_live_response_new (SoupServer* server, SoupMessage* msg, const char* name, GstElement* src, RygelHTTPSeek* time_range, GCancellable* cancellable, GError** error);
RygelLiveResponse* rygel_live_response_construct (GType object_type, SoupServer* server, SoupMessage* msg, const char* name, GstElement* src, RygelHTTPSeek* time_range, GCancellable* cancellable, GError** error);
GType rygel_live_response_get_type (void);
static RygelHTTPResponse* rygel_http_transcode_handler_real_render_body (RygelHTTPRequestHandler* base, RygelHTTPRequest* request, GError** error);
GUPnPDIDLLiteResource* rygel_transcoder_add_resource (RygelTranscoder* self, GUPnPDIDLLiteItem* didl_item, RygelMediaItem* item, RygelTranscodeManager* manager, GError** error);
static GUPnPDIDLLiteResource* rygel_http_transcode_handler_real_add_resource (RygelHTTPRequestHandler* base, GUPnPDIDLLiteItem* didl_item, RygelHTTPRequest* request, GError** error);
static void rygel_http_transcode_handler_finalize (GObject* obj);



static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


RygelHTTPTranscodeHandler* rygel_http_transcode_handler_construct (GType object_type, RygelTranscoder* transcoder, GCancellable* cancellable) {
	RygelHTTPTranscodeHandler * self;
	RygelTranscoder* _tmp0_;
	g_return_val_if_fail (transcoder != NULL, NULL);
	self = (RygelHTTPTranscodeHandler*) rygel_http_request_handler_construct (object_type);
	self->priv->transcoder = (_tmp0_ = _g_object_ref0 (transcoder), _g_object_unref0 (self->priv->transcoder), _tmp0_);
	rygel_http_request_handler_set_cancellable ((RygelHTTPRequestHandler*) self, cancellable);
	return self;
}


RygelHTTPTranscodeHandler* rygel_http_transcode_handler_new (RygelTranscoder* transcoder, GCancellable* cancellable) {
	return rygel_http_transcode_handler_construct (RYGEL_TYPE_HTTP_TRANSCODE_HANDLER, transcoder, cancellable);
}


static void rygel_http_transcode_handler_real_add_response_headers (RygelHTTPRequestHandler* base, RygelHTTPRequest* request, GError** error) {
	RygelHTTPTranscodeHandler * self;
	GError * _inner_error_;
	self = (RygelHTTPTranscodeHandler*) base;
	g_return_if_fail (request != NULL);
	_inner_error_ = NULL;
	soup_message_headers_append (request->msg->response_headers, "Content-Type", rygel_transcoder_get_mime_type (self->priv->transcoder));
	if (request->time_range != NULL) {
		rygel_http_seek_add_response_header (request->time_range, request->msg, -1);
	}
	RYGEL_HTTP_REQUEST_HANDLER_CLASS (rygel_http_transcode_handler_parent_class)->add_response_headers (RYGEL_HTTP_REQUEST_HANDLER (self), request, &_inner_error_);
	if (_inner_error_ != NULL) {
		if (_inner_error_->domain == RYGEL_HTTP_REQUEST_ERROR) {
			g_propagate_error (error, _inner_error_);
			return;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
			g_clear_error (&_inner_error_);
			return;
		}
	}
}


static RygelHTTPResponse* rygel_http_transcode_handler_real_render_body (RygelHTTPRequestHandler* base, RygelHTTPRequest* request, GError** error) {
	RygelHTTPTranscodeHandler * self;
	RygelHTTPResponse* result;
	GError * _inner_error_;
	RygelMediaItem* item;
	GstElement* src;
	GstElement* _tmp0_;
	GstElement* _tmp1_;
	RygelLiveResponse* _tmp2_;
	self = (RygelHTTPTranscodeHandler*) base;
	g_return_val_if_fail (request != NULL, NULL);
	_inner_error_ = NULL;
	item = _g_object_ref0 (request->item);
	src = rygel_media_item_create_stream_source (item);
	if (src == NULL) {
		_inner_error_ = g_error_new_literal (RYGEL_HTTP_REQUEST_ERROR, RYGEL_HTTP_REQUEST_ERROR_NOT_FOUND, "Not found");
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == RYGEL_HTTP_REQUEST_ERROR) {
				g_propagate_error (error, _inner_error_);
				_g_object_unref0 (item);
				_gst_object_unref0 (src);
				return NULL;
			} else {
				_g_object_unref0 (item);
				_gst_object_unref0 (src);
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return NULL;
			}
		}
	}
	_tmp0_ = rygel_transcoder_create_source (self->priv->transcoder, item, src, &_inner_error_);
	if (_inner_error_ != NULL) {
		if (_inner_error_->domain == RYGEL_HTTP_REQUEST_ERROR) {
			g_propagate_error (error, _inner_error_);
			_g_object_unref0 (item);
			_gst_object_unref0 (src);
			return NULL;
		} else {
			_g_object_unref0 (item);
			_gst_object_unref0 (src);
			g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
	src = (_tmp1_ = _tmp0_, _gst_object_unref0 (src), _tmp1_);
	_tmp2_ = rygel_live_response_new (request->server, request->msg, "RygelLiveResponse", src, request->time_range, rygel_http_request_handler_get_cancellable ((RygelHTTPRequestHandler*) self), &_inner_error_);
	if (_inner_error_ != NULL) {
		if (_inner_error_->domain == RYGEL_HTTP_REQUEST_ERROR) {
			g_propagate_error (error, _inner_error_);
			_g_object_unref0 (item);
			_gst_object_unref0 (src);
			return NULL;
		} else {
			_g_object_unref0 (item);
			_gst_object_unref0 (src);
			g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
	result = (RygelHTTPResponse*) _tmp2_;
	_g_object_unref0 (item);
	_gst_object_unref0 (src);
	return result;
}


static GUPnPDIDLLiteResource* rygel_http_transcode_handler_real_add_resource (RygelHTTPRequestHandler* base, GUPnPDIDLLiteItem* didl_item, RygelHTTPRequest* request, GError** error) {
	RygelHTTPTranscodeHandler * self;
	GUPnPDIDLLiteResource* result;
	GError * _inner_error_;
	GUPnPDIDLLiteResource* _tmp0_;
	self = (RygelHTTPTranscodeHandler*) base;
	g_return_val_if_fail (didl_item != NULL, NULL);
	g_return_val_if_fail (request != NULL, NULL);
	_inner_error_ = NULL;
	_tmp0_ = rygel_transcoder_add_resource (self->priv->transcoder, didl_item, request->item, (RygelTranscodeManager*) request->http_server, &_inner_error_);
	if (_inner_error_ != NULL) {
		if (_inner_error_->domain == RYGEL_HTTP_REQUEST_ERROR) {
			g_propagate_error (error, _inner_error_);
			return NULL;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
	result = _tmp0_;
	return result;
}


static void rygel_http_transcode_handler_class_init (RygelHTTPTranscodeHandlerClass * klass) {
	rygel_http_transcode_handler_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelHTTPTranscodeHandlerPrivate));
	RYGEL_HTTP_REQUEST_HANDLER_CLASS (klass)->add_response_headers = rygel_http_transcode_handler_real_add_response_headers;
	RYGEL_HTTP_REQUEST_HANDLER_CLASS (klass)->render_body = rygel_http_transcode_handler_real_render_body;
	RYGEL_HTTP_REQUEST_HANDLER_CLASS (klass)->add_resource = rygel_http_transcode_handler_real_add_resource;
	G_OBJECT_CLASS (klass)->finalize = rygel_http_transcode_handler_finalize;
}


static void rygel_http_transcode_handler_instance_init (RygelHTTPTranscodeHandler * self) {
	self->priv = RYGEL_HTTP_TRANSCODE_HANDLER_GET_PRIVATE (self);
}


static void rygel_http_transcode_handler_finalize (GObject* obj) {
	RygelHTTPTranscodeHandler * self;
	self = RYGEL_HTTP_TRANSCODE_HANDLER (obj);
	_g_object_unref0 (self->priv->transcoder);
	G_OBJECT_CLASS (rygel_http_transcode_handler_parent_class)->finalize (obj);
}


GType rygel_http_transcode_handler_get_type (void) {
	static GType rygel_http_transcode_handler_type_id = 0;
	if (rygel_http_transcode_handler_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelHTTPTranscodeHandlerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_http_transcode_handler_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelHTTPTranscodeHandler), 0, (GInstanceInitFunc) rygel_http_transcode_handler_instance_init, NULL };
		rygel_http_transcode_handler_type_id = g_type_register_static (RYGEL_TYPE_HTTP_REQUEST_HANDLER, "RygelHTTPTranscodeHandler", &g_define_type_info, 0);
	}
	return rygel_http_transcode_handler_type_id;
}



