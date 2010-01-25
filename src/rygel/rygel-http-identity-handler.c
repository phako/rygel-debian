/* rygel-http-identity-handler.c generated by valac, the Vala compiler
 * generated from rygel-http-identity-handler.vala, do not modify */

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
#include <gee.h>
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

#define RYGEL_TYPE_HTTP_IDENTITY_HANDLER (rygel_http_identity_handler_get_type ())
#define RYGEL_HTTP_IDENTITY_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_IDENTITY_HANDLER, RygelHTTPIdentityHandler))
#define RYGEL_HTTP_IDENTITY_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_IDENTITY_HANDLER, RygelHTTPIdentityHandlerClass))
#define RYGEL_IS_HTTP_IDENTITY_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_IDENTITY_HANDLER))
#define RYGEL_IS_HTTP_IDENTITY_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_IDENTITY_HANDLER))
#define RYGEL_HTTP_IDENTITY_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_IDENTITY_HANDLER, RygelHTTPIdentityHandlerClass))

typedef struct _RygelHTTPIdentityHandler RygelHTTPIdentityHandler;
typedef struct _RygelHTTPIdentityHandlerClass RygelHTTPIdentityHandlerClass;
typedef struct _RygelHTTPIdentityHandlerPrivate RygelHTTPIdentityHandlerPrivate;

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
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

#define RYGEL_TYPE_SEEKABLE_RESPONSE (rygel_seekable_response_get_type ())
#define RYGEL_SEEKABLE_RESPONSE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_SEEKABLE_RESPONSE, RygelSeekableResponse))
#define RYGEL_SEEKABLE_RESPONSE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_SEEKABLE_RESPONSE, RygelSeekableResponseClass))
#define RYGEL_IS_SEEKABLE_RESPONSE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_SEEKABLE_RESPONSE))
#define RYGEL_IS_SEEKABLE_RESPONSE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_SEEKABLE_RESPONSE))
#define RYGEL_SEEKABLE_RESPONSE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_SEEKABLE_RESPONSE, RygelSeekableResponseClass))

typedef struct _RygelSeekableResponse RygelSeekableResponse;
typedef struct _RygelSeekableResponseClass RygelSeekableResponseClass;
#define _gst_object_unref0(var) ((var == NULL) ? NULL : (var = (gst_object_unref (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

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

struct _RygelHTTPIdentityHandler {
	RygelHTTPRequestHandler parent_instance;
	RygelHTTPIdentityHandlerPrivate * priv;
};

struct _RygelHTTPIdentityHandlerClass {
	RygelHTTPRequestHandlerClass parent_class;
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


static gpointer rygel_http_identity_handler_parent_class = NULL;

GType rygel_http_request_handler_get_type (void);
GType rygel_http_request_get_type (void);
GQuark rygel_http_request_error_quark (void);
GType rygel_http_response_get_type (void);
GType rygel_http_identity_handler_get_type (void);
enum  {
	RYGEL_HTTP_IDENTITY_HANDLER_DUMMY_PROPERTY
};
RygelHTTPRequestHandler* rygel_http_request_handler_construct (GType object_type);
void rygel_http_request_handler_set_cancellable (RygelHTTPRequestHandler* self, GCancellable* value);
RygelHTTPIdentityHandler* rygel_http_identity_handler_new (GCancellable* cancellable);
RygelHTTPIdentityHandler* rygel_http_identity_handler_construct (GType object_type, GCancellable* cancellable);
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
GType rygel_media_container_get_type (void);
void rygel_http_seek_add_response_headers (RygelHTTPSeek* self);
void rygel_http_request_handler_add_response_headers (RygelHTTPRequestHandler* self, RygelHTTPRequest* request, GError** error);
static void rygel_http_identity_handler_real_add_response_headers (RygelHTTPRequestHandler* base, RygelHTTPRequest* request, GError** error);
static RygelHTTPResponse* rygel_http_identity_handler_render_body_real (RygelHTTPIdentityHandler* self, RygelHTTPRequest* request, GError** error);
static RygelHTTPResponse* rygel_http_identity_handler_real_render_body (RygelHTTPRequestHandler* base, RygelHTTPRequest* request, GError** error);
char* rygel_transcode_manager_get_protocol (RygelTranscodeManager* self);
GUPnPDIDLLiteResource* rygel_thumbnail_add_resource (RygelThumbnail* self, GUPnPDIDLLiteItem* didl_item, const char* protocol);
GUPnPDIDLLiteResource* rygel_media_item_add_resource (RygelMediaItem* self, GUPnPDIDLLiteItem* didl_item, const char* uri, const char* protocol, GError** error);
static GUPnPDIDLLiteResource* rygel_http_identity_handler_real_add_resource (RygelHTTPRequestHandler* base, GUPnPDIDLLiteItem* didl_item, RygelHTTPRequest* request, GError** error);
GCancellable* rygel_http_request_handler_get_cancellable (RygelHTTPRequestHandler* self);
RygelSeekableResponse* rygel_seekable_response_new (SoupServer* server, SoupMessage* msg, const char* uri, RygelHTTPSeek* seek, gsize file_length, GCancellable* cancellable);
RygelSeekableResponse* rygel_seekable_response_construct (GType object_type, SoupServer* server, SoupMessage* msg, const char* uri, RygelHTTPSeek* seek, gsize file_length, GCancellable* cancellable);
GType rygel_seekable_response_get_type (void);
gboolean rygel_media_item_should_stream (RygelMediaItem* self);
GstElement* rygel_media_item_create_stream_source (RygelMediaItem* self);
RygelLiveResponse* rygel_live_response_new (SoupServer* server, SoupMessage* msg, const char* name, GstElement* src, RygelHTTPSeek* time_range, GCancellable* cancellable, GError** error);
RygelLiveResponse* rygel_live_response_construct (GType object_type, SoupServer* server, SoupMessage* msg, const char* name, GstElement* src, RygelHTTPSeek* time_range, GCancellable* cancellable, GError** error);
GType rygel_live_response_get_type (void);



#line 29 "rygel-http-identity-handler.vala"
RygelHTTPIdentityHandler* rygel_http_identity_handler_construct (GType object_type, GCancellable* cancellable) {
#line 361 "rygel-http-identity-handler.c"
	RygelHTTPIdentityHandler * self;
#line 29 "rygel-http-identity-handler.vala"
	self = (RygelHTTPIdentityHandler*) rygel_http_request_handler_construct (object_type);
#line 30 "rygel-http-identity-handler.vala"
	rygel_http_request_handler_set_cancellable ((RygelHTTPRequestHandler*) self, cancellable);
#line 367 "rygel-http-identity-handler.c"
	return self;
}


#line 29 "rygel-http-identity-handler.vala"
RygelHTTPIdentityHandler* rygel_http_identity_handler_new (GCancellable* cancellable) {
#line 29 "rygel-http-identity-handler.vala"
	return rygel_http_identity_handler_construct (RYGEL_TYPE_HTTP_IDENTITY_HANDLER, cancellable);
#line 376 "rygel-http-identity-handler.c"
}


#line 33 "rygel-http-identity-handler.vala"
static void rygel_http_identity_handler_real_add_response_headers (RygelHTTPRequestHandler* base, RygelHTTPRequest* request, GError** error) {
#line 382 "rygel-http-identity-handler.c"
	RygelHTTPIdentityHandler * self;
	GError * _inner_error_;
	self = (RygelHTTPIdentityHandler*) base;
#line 33 "rygel-http-identity-handler.vala"
	g_return_if_fail (request != NULL);
#line 388 "rygel-http-identity-handler.c"
	_inner_error_ = NULL;
#line 35 "rygel-http-identity-handler.vala"
	if (request->thumbnail != NULL) {
#line 36 "rygel-http-identity-handler.vala"
		soup_message_headers_append (request->msg->response_headers, "Content-Type", ((RygelIconInfo*) request->thumbnail)->mime_type);
#line 394 "rygel-http-identity-handler.c"
	} else {
#line 39 "rygel-http-identity-handler.vala"
		soup_message_headers_append (request->msg->response_headers, "Content-Type", request->item->mime_type);
#line 398 "rygel-http-identity-handler.c"
	}
#line 43 "rygel-http-identity-handler.vala"
	if (request->seek != NULL) {
#line 44 "rygel-http-identity-handler.vala"
		rygel_http_seek_add_response_headers (request->seek);
#line 404 "rygel-http-identity-handler.c"
	}
#line 48 "rygel-http-identity-handler.vala"
	RYGEL_HTTP_REQUEST_HANDLER_CLASS (rygel_http_identity_handler_parent_class)->add_response_headers (RYGEL_HTTP_REQUEST_HANDLER (self), request, &_inner_error_);
#line 408 "rygel-http-identity-handler.c"
	if (_inner_error_ != NULL) {
		if (_inner_error_->domain == RYGEL_HTTP_REQUEST_ERROR) {
			g_propagate_error (error, _inner_error_);
			return;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
}


#line 51 "rygel-http-identity-handler.vala"
static RygelHTTPResponse* rygel_http_identity_handler_real_render_body (RygelHTTPRequestHandler* base, RygelHTTPRequest* request, GError** error) {
#line 424 "rygel-http-identity-handler.c"
	RygelHTTPIdentityHandler * self;
	RygelHTTPResponse* result;
	GError * _inner_error_;
	self = (RygelHTTPIdentityHandler*) base;
#line 51 "rygel-http-identity-handler.vala"
	g_return_val_if_fail (request != NULL, NULL);
#line 431 "rygel-http-identity-handler.c"
	_inner_error_ = NULL;
	{
		RygelHTTPResponse* _tmp0_;
#line 54 "rygel-http-identity-handler.vala"
		_tmp0_ = rygel_http_identity_handler_render_body_real (self, request, &_inner_error_);
#line 437 "rygel-http-identity-handler.c"
		if (_inner_error_ != NULL) {
			goto __catch28_g_error;
			goto __finally28;
		}
		result = _tmp0_;
#line 54 "rygel-http-identity-handler.vala"
		return result;
#line 445 "rygel-http-identity-handler.c"
	}
	goto __finally28;
	__catch28_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			_inner_error_ = g_error_new_literal (RYGEL_HTTP_REQUEST_ERROR, RYGEL_HTTP_REQUEST_ERROR_NOT_FOUND, err->message);
			if (_inner_error_ != NULL) {
				_g_error_free0 (err);
				goto __finally28;
			}
			_g_error_free0 (err);
		}
	}
	__finally28:
	if (_inner_error_ != NULL) {
		if (_inner_error_->domain == RYGEL_HTTP_REQUEST_ERROR) {
			g_propagate_error (error, _inner_error_);
			return NULL;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
}


#line 60 "rygel-http-identity-handler.vala"
static GUPnPDIDLLiteResource* rygel_http_identity_handler_real_add_resource (RygelHTTPRequestHandler* base, GUPnPDIDLLiteItem* didl_item, RygelHTTPRequest* request, GError** error) {
#line 478 "rygel-http-identity-handler.c"
	RygelHTTPIdentityHandler * self;
	GUPnPDIDLLiteResource* result;
	GError * _inner_error_;
	char* protocol;
	self = (RygelHTTPIdentityHandler*) base;
#line 60 "rygel-http-identity-handler.vala"
	g_return_val_if_fail (didl_item != NULL, NULL);
#line 60 "rygel-http-identity-handler.vala"
	g_return_val_if_fail (request != NULL, NULL);
#line 488 "rygel-http-identity-handler.c"
	_inner_error_ = NULL;
#line 63 "rygel-http-identity-handler.vala"
	protocol = rygel_transcode_manager_get_protocol ((RygelTranscodeManager*) request->http_server);
#line 65 "rygel-http-identity-handler.vala"
	if (request->thumbnail != NULL) {
#line 494 "rygel-http-identity-handler.c"
		result = rygel_thumbnail_add_resource (request->thumbnail, didl_item, protocol);
		_g_free0 (protocol);
#line 66 "rygel-http-identity-handler.vala"
		return result;
#line 499 "rygel-http-identity-handler.c"
	} else {
		GUPnPDIDLLiteResource* _tmp0_;
#line 68 "rygel-http-identity-handler.vala"
		_tmp0_ = rygel_media_item_add_resource (request->item, didl_item, NULL, protocol, &_inner_error_);
#line 504 "rygel-http-identity-handler.c"
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_g_free0 (protocol);
			return NULL;
		}
		result = _tmp0_;
		_g_free0 (protocol);
#line 68 "rygel-http-identity-handler.vala"
		return result;
#line 514 "rygel-http-identity-handler.c"
	}
	_g_free0 (protocol);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


#line 72 "rygel-http-identity-handler.vala"
static RygelHTTPResponse* rygel_http_identity_handler_render_body_real (RygelHTTPIdentityHandler* self, RygelHTTPRequest* request, GError** error) {
#line 527 "rygel-http-identity-handler.c"
	RygelHTTPResponse* result;
	GError * _inner_error_;
	RygelMediaItem* item;
#line 72 "rygel-http-identity-handler.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 72 "rygel-http-identity-handler.vala"
	g_return_val_if_fail (request != NULL, NULL);
#line 535 "rygel-http-identity-handler.c"
	_inner_error_ = NULL;
#line 73 "rygel-http-identity-handler.vala"
	if (request->thumbnail != NULL) {
#line 539 "rygel-http-identity-handler.c"
		result = (RygelHTTPResponse*) rygel_seekable_response_new (request->server, request->msg, ((RygelIconInfo*) request->thumbnail)->uri, request->seek, (gsize) ((RygelIconInfo*) request->thumbnail)->size, rygel_http_request_handler_get_cancellable ((RygelHTTPRequestHandler*) self));
#line 74 "rygel-http-identity-handler.vala"
		return result;
#line 543 "rygel-http-identity-handler.c"
	}
#line 82 "rygel-http-identity-handler.vala"
	item = _g_object_ref0 (request->item);
#line 84 "rygel-http-identity-handler.vala"
	if (rygel_media_item_should_stream (item)) {
#line 549 "rygel-http-identity-handler.c"
		GstElement* src;
		RygelLiveResponse* _tmp0_;
#line 85 "rygel-http-identity-handler.vala"
		src = rygel_media_item_create_stream_source (item);
#line 86 "rygel-http-identity-handler.vala"
		if (src == NULL) {
#line 556 "rygel-http-identity-handler.c"
			_inner_error_ = g_error_new_literal (RYGEL_HTTP_REQUEST_ERROR, RYGEL_HTTP_REQUEST_ERROR_NOT_FOUND, "Not found");
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_gst_object_unref0 (src);
				_g_object_unref0 (item);
				return NULL;
			}
		}
#line 90 "rygel-http-identity-handler.vala"
		_tmp0_ = rygel_live_response_new (request->server, request->msg, "RygelLiveResponse", src, request->seek, rygel_http_request_handler_get_cancellable ((RygelHTTPRequestHandler*) self), &_inner_error_);
#line 567 "rygel-http-identity-handler.c"
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_gst_object_unref0 (src);
			_g_object_unref0 (item);
			return NULL;
		}
		result = (RygelHTTPResponse*) _tmp0_;
		_gst_object_unref0 (src);
		_g_object_unref0 (item);
#line 90 "rygel-http-identity-handler.vala"
		return result;
#line 579 "rygel-http-identity-handler.c"
	} else {
		char* _tmp1_;
		RygelHTTPResponse* _tmp2_;
#line 97 "rygel-http-identity-handler.vala"
		if (gee_collection_get_size ((GeeCollection*) ((RygelMediaObject*) item)->uris) == 0) {
#line 585 "rygel-http-identity-handler.c"
			_inner_error_ = g_error_new (RYGEL_HTTP_REQUEST_ERROR, RYGEL_HTTP_REQUEST_ERROR_NOT_FOUND, "Requested item '%s' didn't provide a URI\n", ((RygelMediaObject*) item)->id);
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_g_object_unref0 (item);
				return NULL;
			}
		}
		result = (_tmp2_ = (RygelHTTPResponse*) rygel_seekable_response_new (request->server, request->msg, _tmp1_ = (char*) gee_abstract_list_get ((GeeAbstractList*) ((RygelMediaObject*) item)->uris, 0), request->seek, (gsize) item->size, rygel_http_request_handler_get_cancellable ((RygelHTTPRequestHandler*) self)), _g_free0 (_tmp1_), _tmp2_);
		_g_object_unref0 (item);
#line 103 "rygel-http-identity-handler.vala"
		return result;
#line 597 "rygel-http-identity-handler.c"
	}
	_g_object_unref0 (item);
}


static void rygel_http_identity_handler_class_init (RygelHTTPIdentityHandlerClass * klass) {
	rygel_http_identity_handler_parent_class = g_type_class_peek_parent (klass);
	RYGEL_HTTP_REQUEST_HANDLER_CLASS (klass)->add_response_headers = rygel_http_identity_handler_real_add_response_headers;
	RYGEL_HTTP_REQUEST_HANDLER_CLASS (klass)->render_body = rygel_http_identity_handler_real_render_body;
	RYGEL_HTTP_REQUEST_HANDLER_CLASS (klass)->add_resource = rygel_http_identity_handler_real_add_resource;
}


static void rygel_http_identity_handler_instance_init (RygelHTTPIdentityHandler * self) {
}


GType rygel_http_identity_handler_get_type (void) {
	static GType rygel_http_identity_handler_type_id = 0;
	if (rygel_http_identity_handler_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelHTTPIdentityHandlerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_http_identity_handler_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelHTTPIdentityHandler), 0, (GInstanceInitFunc) rygel_http_identity_handler_instance_init, NULL };
		rygel_http_identity_handler_type_id = g_type_register_static (RYGEL_TYPE_HTTP_REQUEST_HANDLER, "RygelHTTPIdentityHandler", &g_define_type_info, 0);
	}
	return rygel_http_identity_handler_type_id;
}




