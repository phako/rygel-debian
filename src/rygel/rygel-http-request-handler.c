/* rygel-http-request-handler.c generated by valac, the Vala compiler
 * generated from rygel-http-request-handler.vala, do not modify */

/*
 * Copyright (C) 2008, 2009 Nokia Corporation.
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
#define _g_free0(var) (var = (g_free (var), NULL))

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

struct _RygelHTTPRequestHandlerPrivate {
	GCancellable* _cancellable;
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


static gpointer rygel_http_request_handler_parent_class = NULL;

GType rygel_http_request_handler_get_type (void);
GType rygel_http_request_get_type (void);
GQuark rygel_http_request_error_quark (void);
GType rygel_http_response_get_type (void);
#define RYGEL_HTTP_REQUEST_HANDLER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_HTTP_REQUEST_HANDLER, RygelHTTPRequestHandlerPrivate))
enum  {
	RYGEL_HTTP_REQUEST_HANDLER_DUMMY_PROPERTY,
	RYGEL_HTTP_REQUEST_HANDLER_CANCELLABLE
};
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
GUPnPDIDLLiteResource* rygel_http_request_handler_add_resource (RygelHTTPRequestHandler* self, GUPnPDIDLLiteItem* didl_item, RygelHTTPRequest* request, GError** error);
void rygel_http_request_handler_add_response_headers (RygelHTTPRequestHandler* self, RygelHTTPRequest* request, GError** error);
static void rygel_http_request_handler_real_add_response_headers (RygelHTTPRequestHandler* self, RygelHTTPRequest* request, GError** error);
RygelHTTPResponse* rygel_http_request_handler_render_body (RygelHTTPRequestHandler* self, RygelHTTPRequest* request, GError** error);
static RygelHTTPResponse* rygel_http_request_handler_real_render_body (RygelHTTPRequestHandler* self, RygelHTTPRequest* request, GError** error);
static GUPnPDIDLLiteResource* rygel_http_request_handler_real_add_resource (RygelHTTPRequestHandler* self, GUPnPDIDLLiteItem* didl_item, RygelHTTPRequest* request, GError** error);
RygelHTTPRequestHandler* rygel_http_request_handler_construct (GType object_type);
GCancellable* rygel_http_request_handler_get_cancellable (RygelHTTPRequestHandler* self);
void rygel_http_request_handler_set_cancellable (RygelHTTPRequestHandler* self, GCancellable* value);
static void rygel_http_request_handler_finalize (GObject* obj);
static void rygel_http_request_handler_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void rygel_http_request_handler_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);



static void rygel_http_request_handler_real_add_response_headers (RygelHTTPRequestHandler* self, RygelHTTPRequest* request, GError** error) {
	GError * _inner_error_;
	char* mode;
	GUPnPDIDLLiteWriter* didl_writer;
	GUPnPDIDLLiteItem* didl_item;
	GUPnPDIDLLiteResource* resource;
	char** _tmp3_;
	gint tokens_size;
	gint tokens_length1;
	char** _tmp1_;
	char* _tmp0_;
	char** _tmp2_;
	char** tokens;
	g_return_if_fail (self != NULL);
	g_return_if_fail (request != NULL);
	_inner_error_ = NULL;
	mode = g_strdup (soup_message_headers_get (request->msg->request_headers, "transferMode.dlna.org"));
	if (mode != NULL) {
		soup_message_headers_append (request->msg->response_headers, "transferMode.dlna.org", mode);
	}
	didl_writer = gupnp_didl_lite_writer_new (NULL);
	didl_item = gupnp_didl_lite_writer_add_item (didl_writer);
	resource = rygel_http_request_handler_add_resource (self, didl_item, request, &_inner_error_);
	if (_inner_error_ != NULL) {
		if (_inner_error_->domain == RYGEL_HTTP_REQUEST_ERROR) {
			g_propagate_error (error, _inner_error_);
			_g_free0 (mode);
			_g_object_unref0 (didl_writer);
			_g_object_unref0 (didl_item);
			return;
		} else {
			_g_free0 (mode);
			_g_object_unref0 (didl_writer);
			_g_object_unref0 (didl_item);
			g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	tokens = (_tmp3_ = (_tmp2_ = _tmp1_ = g_strsplit (_tmp0_ = gupnp_protocol_info_to_string (gupnp_didl_lite_resource_get_protocol_info (resource)), ":", 4), _g_free0 (_tmp0_), _tmp2_), tokens_length1 = _vala_array_length (_tmp1_), tokens_size = tokens_length1, _tmp3_);
	g_assert (tokens_length1 == 4);
	soup_message_headers_append (request->msg->response_headers, "contentFeatures.dlna.org", tokens[3]);
	_g_free0 (mode);
	_g_object_unref0 (didl_writer);
	_g_object_unref0 (didl_item);
	_g_object_unref0 (resource);
	tokens = (_vala_array_free (tokens, tokens_length1, (GDestroyNotify) g_free), NULL);
}


void rygel_http_request_handler_add_response_headers (RygelHTTPRequestHandler* self, RygelHTTPRequest* request, GError** error) {
	RYGEL_HTTP_REQUEST_HANDLER_GET_CLASS (self)->add_response_headers (self, request, error);
}


static RygelHTTPResponse* rygel_http_request_handler_real_render_body (RygelHTTPRequestHandler* self, RygelHTTPRequest* request, GError** error) {
	g_return_val_if_fail (self != NULL, NULL);
	g_critical ("Type `%s' does not implement abstract method `rygel_http_request_handler_render_body'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}


RygelHTTPResponse* rygel_http_request_handler_render_body (RygelHTTPRequestHandler* self, RygelHTTPRequest* request, GError** error) {
	return RYGEL_HTTP_REQUEST_HANDLER_GET_CLASS (self)->render_body (self, request, error);
}


static GUPnPDIDLLiteResource* rygel_http_request_handler_real_add_resource (RygelHTTPRequestHandler* self, GUPnPDIDLLiteItem* didl_item, RygelHTTPRequest* request, GError** error) {
	g_return_val_if_fail (self != NULL, NULL);
	g_critical ("Type `%s' does not implement abstract method `rygel_http_request_handler_add_resource'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}


GUPnPDIDLLiteResource* rygel_http_request_handler_add_resource (RygelHTTPRequestHandler* self, GUPnPDIDLLiteItem* didl_item, RygelHTTPRequest* request, GError** error) {
	return RYGEL_HTTP_REQUEST_HANDLER_GET_CLASS (self)->add_resource (self, didl_item, request, error);
}


RygelHTTPRequestHandler* rygel_http_request_handler_construct (GType object_type) {
	RygelHTTPRequestHandler * self;
	self = (RygelHTTPRequestHandler*) g_object_new (object_type, NULL);
	return self;
}


GCancellable* rygel_http_request_handler_get_cancellable (RygelHTTPRequestHandler* self) {
	GCancellable* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_cancellable;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void rygel_http_request_handler_set_cancellable (RygelHTTPRequestHandler* self, GCancellable* value) {
	GCancellable* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_cancellable = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_cancellable), _tmp0_);
	g_object_notify ((GObject *) self, "cancellable");
}


static void rygel_http_request_handler_class_init (RygelHTTPRequestHandlerClass * klass) {
	rygel_http_request_handler_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelHTTPRequestHandlerPrivate));
	RYGEL_HTTP_REQUEST_HANDLER_CLASS (klass)->add_response_headers = rygel_http_request_handler_real_add_response_headers;
	RYGEL_HTTP_REQUEST_HANDLER_CLASS (klass)->render_body = rygel_http_request_handler_real_render_body;
	RYGEL_HTTP_REQUEST_HANDLER_CLASS (klass)->add_resource = rygel_http_request_handler_real_add_resource;
	G_OBJECT_CLASS (klass)->get_property = rygel_http_request_handler_get_property;
	G_OBJECT_CLASS (klass)->set_property = rygel_http_request_handler_set_property;
	G_OBJECT_CLASS (klass)->finalize = rygel_http_request_handler_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), RYGEL_HTTP_REQUEST_HANDLER_CANCELLABLE, g_param_spec_object ("cancellable", "cancellable", "cancellable", G_TYPE_CANCELLABLE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void rygel_http_request_handler_instance_init (RygelHTTPRequestHandler * self) {
	self->priv = RYGEL_HTTP_REQUEST_HANDLER_GET_PRIVATE (self);
}


static void rygel_http_request_handler_finalize (GObject* obj) {
	RygelHTTPRequestHandler * self;
	self = RYGEL_HTTP_REQUEST_HANDLER (obj);
	_g_object_unref0 (self->priv->_cancellable);
	G_OBJECT_CLASS (rygel_http_request_handler_parent_class)->finalize (obj);
}


GType rygel_http_request_handler_get_type (void) {
	static GType rygel_http_request_handler_type_id = 0;
	if (rygel_http_request_handler_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelHTTPRequestHandlerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_http_request_handler_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelHTTPRequestHandler), 0, (GInstanceInitFunc) rygel_http_request_handler_instance_init, NULL };
		rygel_http_request_handler_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelHTTPRequestHandler", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
	}
	return rygel_http_request_handler_type_id;
}


static void rygel_http_request_handler_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	RygelHTTPRequestHandler * self;
	self = RYGEL_HTTP_REQUEST_HANDLER (object);
	switch (property_id) {
		case RYGEL_HTTP_REQUEST_HANDLER_CANCELLABLE:
		g_value_set_object (value, rygel_http_request_handler_get_cancellable (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void rygel_http_request_handler_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	RygelHTTPRequestHandler * self;
	self = RYGEL_HTTP_REQUEST_HANDLER (object);
	switch (property_id) {
		case RYGEL_HTTP_REQUEST_HANDLER_CANCELLABLE:
		rygel_http_request_handler_set_cancellable (self, g_value_get_object (value));
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




