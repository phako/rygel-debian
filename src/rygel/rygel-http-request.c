/*
 * Copyright (C) 2008, 2009 Nokia Corporation.
 * Copyright (C) 2006, 2007, 2008 OpenedHand Ltd.
 *
 * Author: Zeeshan Ali (Khattak) <zeeshanak@gnome.org>
 *                               <zeeshan.ali@nokia.com>
 *         Jorn Baayen <jorn.baayen@gmail.com>
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
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>
#include <libgupnp-av/gupnp-av.h>
#include <libgupnp/gupnp.h>
#include <gee.h>
#include <gst/gst.h>


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

#define RYGEL_TYPE_HTTP_SEEK (rygel_http_seek_get_type ())
#define RYGEL_HTTP_SEEK(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_SEEK, RygelHTTPSeek))
#define RYGEL_HTTP_SEEK_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_SEEK, RygelHTTPSeekClass))
#define RYGEL_IS_HTTP_SEEK(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_SEEK))
#define RYGEL_IS_HTTP_SEEK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_SEEK))
#define RYGEL_HTTP_SEEK_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_SEEK, RygelHTTPSeekClass))

typedef struct _RygelHTTPSeek RygelHTTPSeek;
typedef struct _RygelHTTPSeekClass RygelHTTPSeekClass;

#define RYGEL_TYPE_MEDIA_CONTAINER (rygel_media_container_get_type ())
#define RYGEL_MEDIA_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainer))
#define RYGEL_MEDIA_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainerClass))
#define RYGEL_IS_MEDIA_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_CONTAINER))
#define RYGEL_IS_MEDIA_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_CONTAINER))
#define RYGEL_MEDIA_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainerClass))

typedef struct _RygelMediaContainer RygelMediaContainer;
typedef struct _RygelMediaContainerClass RygelMediaContainerClass;

#define RYGEL_TYPE_HTTP_RESPONSE (rygel_http_response_get_type ())
#define RYGEL_HTTP_RESPONSE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_RESPONSE, RygelHTTPResponse))
#define RYGEL_HTTP_RESPONSE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_RESPONSE, RygelHTTPResponseClass))
#define RYGEL_IS_HTTP_RESPONSE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_RESPONSE))
#define RYGEL_IS_HTTP_RESPONSE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_RESPONSE))
#define RYGEL_HTTP_RESPONSE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_RESPONSE, RygelHTTPResponseClass))

typedef struct _RygelHTTPResponse RygelHTTPResponse;
typedef struct _RygelHTTPResponseClass RygelHTTPResponseClass;

#define RYGEL_TYPE_HTTP_REQUEST_HANDLER (rygel_http_request_handler_get_type ())
#define RYGEL_HTTP_REQUEST_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_REQUEST_HANDLER, RygelHTTPRequestHandler))
#define RYGEL_HTTP_REQUEST_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_REQUEST_HANDLER, RygelHTTPRequestHandlerClass))
#define RYGEL_IS_HTTP_REQUEST_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_REQUEST_HANDLER))
#define RYGEL_IS_HTTP_REQUEST_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_REQUEST_HANDLER))
#define RYGEL_HTTP_REQUEST_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_REQUEST_HANDLER, RygelHTTPRequestHandlerClass))

typedef struct _RygelHTTPRequestHandler RygelHTTPRequestHandler;
typedef struct _RygelHTTPRequestHandlerClass RygelHTTPRequestHandlerClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_hash_table_unref0(var) ((var == NULL) ? NULL : (var = (g_hash_table_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _rygel_icon_info_unref0(var) ((var == NULL) ? NULL : (var = (rygel_icon_info_unref (var), NULL)))
typedef struct _RygelTranscodeManagerPrivate RygelTranscodeManagerPrivate;
typedef struct _RygelHTTPServerPrivate RygelHTTPServerPrivate;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

#define RYGEL_TYPE_TRANSCODER (rygel_transcoder_get_type ())
#define RYGEL_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRANSCODER, RygelTranscoder))
#define RYGEL_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRANSCODER, RygelTranscoderClass))
#define RYGEL_IS_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRANSCODER))
#define RYGEL_IS_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRANSCODER))
#define RYGEL_TRANSCODER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRANSCODER, RygelTranscoderClass))

typedef struct _RygelTranscoder RygelTranscoder;
typedef struct _RygelTranscoderClass RygelTranscoderClass;

#define RYGEL_TYPE_HTTP_TRANSCODE_HANDLER (rygel_http_transcode_handler_get_type ())
#define RYGEL_HTTP_TRANSCODE_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_TRANSCODE_HANDLER, RygelHTTPTranscodeHandler))
#define RYGEL_HTTP_TRANSCODE_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_TRANSCODE_HANDLER, RygelHTTPTranscodeHandlerClass))
#define RYGEL_IS_HTTP_TRANSCODE_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_TRANSCODE_HANDLER))
#define RYGEL_IS_HTTP_TRANSCODE_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_TRANSCODE_HANDLER))
#define RYGEL_HTTP_TRANSCODE_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_TRANSCODE_HANDLER, RygelHTTPTranscodeHandlerClass))

typedef struct _RygelHTTPTranscodeHandler RygelHTTPTranscodeHandler;
typedef struct _RygelHTTPTranscodeHandlerClass RygelHTTPTranscodeHandlerClass;

#define RYGEL_TYPE_HTTP_IDENTITY_HANDLER (rygel_http_identity_handler_get_type ())
#define RYGEL_HTTP_IDENTITY_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_IDENTITY_HANDLER, RygelHTTPIdentityHandler))
#define RYGEL_HTTP_IDENTITY_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_IDENTITY_HANDLER, RygelHTTPIdentityHandlerClass))
#define RYGEL_IS_HTTP_IDENTITY_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_IDENTITY_HANDLER))
#define RYGEL_IS_HTTP_IDENTITY_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_IDENTITY_HANDLER))
#define RYGEL_HTTP_IDENTITY_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_IDENTITY_HANDLER, RygelHTTPIdentityHandlerClass))

typedef struct _RygelHTTPIdentityHandler RygelHTTPIdentityHandler;
typedef struct _RygelHTTPIdentityHandlerClass RygelHTTPIdentityHandlerClass;
typedef struct _RygelMediaObjectPrivate RygelMediaObjectPrivate;
typedef struct _RygelMediaItemPrivate RygelMediaItemPrivate;

typedef enum  {
	RYGEL_HTTP_REQUEST_ERROR_UNACCEPTABLE = SOUP_STATUS_NOT_ACCEPTABLE,
	RYGEL_HTTP_REQUEST_ERROR_BAD_REQUEST = SOUP_STATUS_BAD_REQUEST,
	RYGEL_HTTP_REQUEST_ERROR_NOT_FOUND = SOUP_STATUS_NOT_FOUND
} RygelHTTPRequestError;
#define RYGEL_HTTP_REQUEST_ERROR rygel_http_request_error_quark ()
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

struct _RygelHTTPRequestPrivate {
	RygelMediaContainer* root_container;
	GHashTable* query;
	GCancellable* _cancellable;
	RygelHTTPResponse* response;
	char* item_id;
	gint thumbnail_index;
	RygelHTTPRequestHandler* request_handler;
};

struct _RygelTranscodeManager {
	GObject parent_instance;
	RygelTranscodeManagerPrivate * priv;
};

struct _RygelTranscodeManagerClass {
	GObjectClass parent_class;
	char* (*create_uri_for_item) (RygelTranscodeManager* self, RygelMediaItem* item, gint thumbnail_index, const char* transcode_target, char** protocol);
	void (*add_resources) (RygelTranscodeManager* self, GUPnPDIDLLiteItem* didl_item, RygelMediaItem* item, GError** error);
	char* (*get_protocol) (RygelTranscodeManager* self);
	char* (*get_protocol_info) (RygelTranscodeManager* self);
};

struct _RygelHTTPServer {
	RygelTranscodeManager parent_instance;
	RygelHTTPServerPrivate * priv;
	RygelMediaContainer* root_container;
	GUPnPContext* context;
};

struct _RygelHTTPServerClass {
	RygelTranscodeManagerClass parent_class;
};

typedef enum  {
	RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE = SOUP_STATUS_BAD_REQUEST,
	RYGEL_HTTP_SEEK_ERROR_OUT_OF_RANGE = SOUP_STATUS_REQUESTED_RANGE_NOT_SATISFIABLE
} RygelHTTPSeekError;
#define RYGEL_HTTP_SEEK_ERROR rygel_http_seek_error_quark ()
struct _RygelMediaObject {
	GObject parent_instance;
	RygelMediaObjectPrivate * priv;
	char* id;
	char* title;
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
	char* upnp_class;
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


static gpointer rygel_http_request_parent_class = NULL;
static RygelStateMachineIface* rygel_http_request_rygel_state_machine_parent_iface = NULL;

GQuark rygel_http_request_error_quark (void);
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
GType rygel_http_seek_get_type (void);
GType rygel_media_container_get_type (void);
GType rygel_http_response_get_type (void);
GType rygel_http_request_handler_get_type (void);
#define RYGEL_HTTP_REQUEST_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_HTTP_REQUEST, RygelHTTPRequestPrivate))
enum  {
	RYGEL_HTTP_REQUEST_DUMMY_PROPERTY,
	RYGEL_HTTP_REQUEST_CANCELLABLE
};
GCancellable* rygel_state_machine_get_cancellable (RygelStateMachine* self);
void rygel_state_machine_set_cancellable (RygelStateMachine* self, GCancellable* value);
RygelHTTPRequest* rygel_http_request_new (RygelHTTPServer* http_server, SoupServer* server, SoupMessage* msg, GHashTable* query);
RygelHTTPRequest* rygel_http_request_construct (GType object_type, RygelHTTPServer* http_server, SoupServer* server, SoupMessage* msg, GHashTable* query);
static void rygel_http_request_handle_error (RygelHTTPRequest* self, GError* _error_);
GType rygel_transcoder_get_type (void);
RygelTranscoder* rygel_transcode_manager_get_transcoder (RygelTranscodeManager* self, const char* target, GError** error);
RygelHTTPTranscodeHandler* rygel_http_transcode_handler_new (RygelTranscoder* transcoder, GCancellable* cancellable);
RygelHTTPTranscodeHandler* rygel_http_transcode_handler_construct (GType object_type, RygelTranscoder* transcoder, GCancellable* cancellable);
GType rygel_http_transcode_handler_get_type (void);
RygelHTTPIdentityHandler* rygel_http_identity_handler_new (GCancellable* cancellable);
RygelHTTPIdentityHandler* rygel_http_identity_handler_construct (GType object_type, GCancellable* cancellable);
GType rygel_http_identity_handler_get_type (void);
void rygel_media_container_find_object (RygelMediaContainer* self, const char* id, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target);
static void rygel_http_request_on_item_found (RygelHTTPRequest* self, GObject* source_object, GAsyncResult* res);
static void _rygel_http_request_on_item_found_gasync_ready_callback (GObject* source_object, GAsyncResult* res, gpointer self);
static void rygel_http_request_real_run (RygelStateMachine* base);
void rygel_http_request_end (RygelHTTPRequest* self, guint status);
static void rygel_http_request_on_response_completed (RygelHTTPRequest* self, RygelHTTPResponse* response);
GQuark rygel_http_seek_error_quark (void);
RygelHTTPSeek* rygel_http_seek_from_byte_range (SoupMessage* msg, GError** error);
RygelHTTPSeek* rygel_http_seek_from_time_range (SoupMessage* msg, GError** error);
void rygel_http_request_handler_add_response_headers (RygelHTTPRequestHandler* self, RygelHTTPRequest* request, GError** error);
RygelHTTPResponse* rygel_http_request_handler_render_body (RygelHTTPRequestHandler* self, RygelHTTPRequest* request, GError** error);
static void _rygel_http_request_on_response_completed_rygel_state_machine_completed (RygelHTTPResponse* _sender, gpointer self);
void rygel_http_response_run (RygelHTTPResponse* self);
static void rygel_http_request_handle_item_request (RygelHTTPRequest* self);
RygelMediaObject* rygel_media_container_find_object_finish (RygelMediaContainer* self, GAsyncResult* res, GError** error);
static void rygel_http_request_finalize (GObject* obj);
static void rygel_http_request_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void rygel_http_request_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static int _vala_strcmp0 (const char * str1, const char * str2);



GQuark rygel_http_request_error_quark (void) {
	return g_quark_from_static_string ("rygel_http_request_error-quark");
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static gpointer _g_hash_table_ref0 (gpointer self) {
	return self ? g_hash_table_ref (self) : NULL;
}


RygelHTTPRequest* rygel_http_request_construct (GType object_type, RygelHTTPServer* http_server, SoupServer* server, SoupMessage* msg, GHashTable* query) {
	RygelHTTPRequest * self;
	RygelMediaContainer* _tmp0_;
	SoupServer* _tmp1_;
	SoupMessage* _tmp2_;
	GHashTable* _tmp3_;
	g_return_val_if_fail (http_server != NULL, NULL);
	g_return_val_if_fail (server != NULL, NULL);
	g_return_val_if_fail (msg != NULL, NULL);
	self = (RygelHTTPRequest*) g_object_new (object_type, NULL);
	self->http_server = http_server;
	rygel_state_machine_set_cancellable ((RygelStateMachine*) self, rygel_state_machine_get_cancellable ((RygelStateMachine*) http_server));
	self->priv->root_container = (_tmp0_ = _g_object_ref0 (http_server->root_container), _g_object_unref0 (self->priv->root_container), _tmp0_);
	self->server = (_tmp1_ = _g_object_ref0 (server), _g_object_unref0 (self->server), _tmp1_);
	self->msg = (_tmp2_ = _g_object_ref0 (msg), _g_object_unref0 (self->msg), _tmp2_);
	self->priv->query = (_tmp3_ = _g_hash_table_ref0 (query), _g_hash_table_unref0 (self->priv->query), _tmp3_);
	self->priv->thumbnail_index = -1;
	return self;
}


RygelHTTPRequest* rygel_http_request_new (RygelHTTPServer* http_server, SoupServer* server, SoupMessage* msg, GHashTable* query) {
	return rygel_http_request_construct (RYGEL_TYPE_HTTP_REQUEST, http_server, server, msg, query);
}


static void _rygel_http_request_on_item_found_gasync_ready_callback (GObject* source_object, GAsyncResult* res, gpointer self) {
	rygel_http_request_on_item_found (self, source_object, res);
}


static void rygel_http_request_real_run (RygelStateMachine* base) {
	RygelHTTPRequest * self;
	GError * _inner_error_;
	char* header;
	gboolean _tmp0_;
	gboolean _tmp1_;
	char* _tmp3_;
	char* _tmp2_;
	gboolean _tmp4_;
	self = (RygelHTTPRequest*) base;
	_inner_error_ = NULL;
	soup_server_pause_message (self->server, self->msg);
	header = g_strdup (soup_message_headers_get (self->msg->request_headers, "getcontentFeatures.dlna.org"));
	_tmp0_ = FALSE;
	_tmp1_ = FALSE;
	_tmp2_ = NULL;
	if ((_tmp4_ = _vala_strcmp0 (_tmp3_ = (g_object_get (self->msg, "method", &_tmp2_, NULL), _tmp2_), "HEAD") != 0, _g_free0 (_tmp3_), _tmp4_)) {
		char* _tmp6_;
		char* _tmp5_;
		_tmp5_ = NULL;
		_tmp1_ = _vala_strcmp0 (_tmp6_ = (g_object_get (self->msg, "method", &_tmp5_, NULL), _tmp5_), "GET") != 0;
		_g_free0 (_tmp6_);
	} else {
		_tmp1_ = FALSE;
	}
	if (_tmp1_) {
		_tmp0_ = TRUE;
	} else {
		gboolean _tmp7_;
		_tmp7_ = FALSE;
		if (header != NULL) {
			_tmp7_ = _vala_strcmp0 (header, "1") != 0;
		} else {
			_tmp7_ = FALSE;
		}
		_tmp0_ = _tmp7_;
	}
	if (_tmp0_) {
		GError* _tmp8_;
		rygel_http_request_handle_error (self, _tmp8_ = g_error_new_literal (RYGEL_HTTP_REQUEST_ERROR, RYGEL_HTTP_REQUEST_ERROR_BAD_REQUEST, "Invalid Request"));
		_g_error_free0 (_tmp8_);
		_g_free0 (header);
		return;
	}
	if (self->priv->query != NULL) {
		char* _tmp9_;
		char* target;
		char* index;
		self->priv->item_id = (_tmp9_ = g_strdup ((const char*) g_hash_table_lookup (self->priv->query, "itemid")), _g_free0 (self->priv->item_id), _tmp9_);
		target = g_strdup ((const char*) g_hash_table_lookup (self->priv->query, "transcode"));
		if (target != NULL) {
			RygelTranscoder* transcoder;
			RygelHTTPRequestHandler* _tmp10_;
			transcoder = rygel_transcode_manager_get_transcoder ((RygelTranscodeManager*) self->http_server, target, &_inner_error_);
			if (_inner_error_ != NULL) {
				_g_free0 (target);
				_g_free0 (header);
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return;
			}
			self->priv->request_handler = (_tmp10_ = (RygelHTTPRequestHandler*) rygel_http_transcode_handler_new (transcoder, rygel_state_machine_get_cancellable ((RygelStateMachine*) self)), _g_object_unref0 (self->priv->request_handler), _tmp10_);
			_g_object_unref0 (transcoder);
		}
		index = g_strdup ((const char*) g_hash_table_lookup (self->priv->query, "thumbnail"));
		if (index != NULL) {
			self->priv->thumbnail_index = atoi (index);
		}
		_g_free0 (target);
		_g_free0 (index);
	}
	if (self->priv->item_id == NULL) {
		GError* _tmp11_;
		rygel_http_request_handle_error (self, _tmp11_ = g_error_new_literal (RYGEL_HTTP_REQUEST_ERROR, RYGEL_HTTP_REQUEST_ERROR_NOT_FOUND, "Not Found"));
		_g_error_free0 (_tmp11_);
		_g_free0 (header);
		return;
	}
	if (self->priv->request_handler == NULL) {
		RygelHTTPRequestHandler* _tmp12_;
		self->priv->request_handler = (_tmp12_ = (RygelHTTPRequestHandler*) rygel_http_identity_handler_new (rygel_state_machine_get_cancellable ((RygelStateMachine*) self)), _g_object_unref0 (self->priv->request_handler), _tmp12_);
	}
	rygel_media_container_find_object (self->priv->root_container, self->priv->item_id, NULL, _rygel_http_request_on_item_found_gasync_ready_callback, self);
	_g_free0 (header);
}


static void rygel_http_request_on_response_completed (RygelHTTPRequest* self, RygelHTTPResponse* response) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (response != NULL);
	rygel_http_request_end (self, (guint) SOUP_STATUS_NONE);
}


static void _rygel_http_request_on_response_completed_rygel_state_machine_completed (RygelHTTPResponse* _sender, gpointer self) {
	rygel_http_request_on_response_completed (self, _sender);
}


static void rygel_http_request_handle_item_request (RygelHTTPRequest* self) {
	GError * _inner_error_;
	g_return_if_fail (self != NULL);
	_inner_error_ = NULL;
	{
		RygelHTTPSeek* _tmp0_;
		RygelHTTPSeek* _tmp1_;
		RygelHTTPSeek* _tmp2_;
		RygelHTTPSeek* _tmp3_;
		char* _tmp5_;
		char* _tmp4_;
		gboolean _tmp6_;
		RygelHTTPResponse* _tmp7_;
		RygelHTTPResponse* _tmp8_;
		_tmp0_ = rygel_http_seek_from_byte_range (self->msg, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch20_g_error;
			goto __finally20;
		}
		self->byte_range = (_tmp1_ = _tmp0_, _g_object_unref0 (self->byte_range), _tmp1_);
		_tmp2_ = rygel_http_seek_from_time_range (self->msg, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch20_g_error;
			goto __finally20;
		}
		self->time_range = (_tmp3_ = _tmp2_, _g_object_unref0 (self->time_range), _tmp3_);
		rygel_http_request_handler_add_response_headers (self->priv->request_handler, self, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch20_g_error;
			goto __finally20;
		}
		_tmp4_ = NULL;
		if ((_tmp6_ = _vala_strcmp0 (_tmp5_ = (g_object_get (self->msg, "method", &_tmp4_, NULL), _tmp4_), "HEAD") == 0, _g_free0 (_tmp5_), _tmp6_)) {
			soup_server_unpause_message (self->server, self->msg);
			rygel_http_request_end (self, (guint) SOUP_STATUS_OK);
			return;
		}
		_tmp7_ = rygel_http_request_handler_render_body (self->priv->request_handler, self, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch20_g_error;
			goto __finally20;
		}
		self->priv->response = (_tmp8_ = _tmp7_, _g_object_unref0 (self->priv->response), _tmp8_);
		g_signal_connect_object ((RygelStateMachine*) self->priv->response, "completed", (GCallback) _rygel_http_request_on_response_completed_rygel_state_machine_completed, self, 0);
		rygel_http_response_run (self->priv->response);
	}
	goto __finally20;
	__catch20_g_error:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
			rygel_http_request_handle_error (self, _error_);
			_g_error_free0 (_error_);
		}
	}
	__finally20:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return;
	}
}


static void rygel_http_request_on_item_found (RygelHTTPRequest* self, GObject* source_object, GAsyncResult* res) {
	GError * _inner_error_;
	RygelMediaContainer* container;
	RygelMediaObject* media_object;
	gboolean _tmp2_;
	RygelMediaItem* _tmp4_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (res != NULL);
	_inner_error_ = NULL;
	container = _g_object_ref0 (RYGEL_MEDIA_CONTAINER (source_object));
	media_object = NULL;
	{
		RygelMediaObject* _tmp0_;
		RygelMediaObject* _tmp1_;
		_tmp0_ = rygel_media_container_find_object_finish (container, res, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch21_g_error;
			goto __finally21;
		}
		media_object = (_tmp1_ = _tmp0_, _g_object_unref0 (media_object), _tmp1_);
	}
	goto __finally21;
	__catch21_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			rygel_http_request_handle_error (self, err);
			_g_error_free0 (err);
			_g_object_unref0 (container);
			_g_object_unref0 (media_object);
			return;
		}
	}
	__finally21:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (container);
		_g_object_unref0 (media_object);
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp2_ = FALSE;
	if (media_object == NULL) {
		_tmp2_ = TRUE;
	} else {
		_tmp2_ = !RYGEL_IS_MEDIA_ITEM (media_object);
	}
	if (_tmp2_) {
		GError* _tmp3_;
		rygel_http_request_handle_error (self, _tmp3_ = g_error_new (RYGEL_HTTP_REQUEST_ERROR, RYGEL_HTTP_REQUEST_ERROR_NOT_FOUND, "requested item '%s' not found", self->priv->item_id));
		_g_error_free0 (_tmp3_);
		_g_object_unref0 (container);
		_g_object_unref0 (media_object);
		return;
	}
	self->item = (_tmp4_ = _g_object_ref0 (RYGEL_MEDIA_ITEM (media_object)), _g_object_unref0 (self->item), _tmp4_);
	if (self->priv->thumbnail_index >= 0) {
		RygelThumbnail* _tmp5_;
		self->thumbnail = (_tmp5_ = (RygelThumbnail*) gee_abstract_list_get ((GeeAbstractList*) self->item->thumbnails, self->priv->thumbnail_index), _rygel_icon_info_unref0 (self->thumbnail), _tmp5_);
	}
	rygel_http_request_handle_item_request (self);
	_g_object_unref0 (container);
	_g_object_unref0 (media_object);
}


static void rygel_http_request_handle_error (RygelHTTPRequest* self, GError* _error_) {
	guint status;
	g_return_if_fail (self != NULL);
	g_warning ("rygel-http-request.vala:171: %s", _error_->message);
	status = 0U;
	if (_error_->domain == RYGEL_HTTP_REQUEST_ERROR) {
		status = (guint) _error_->code;
	} else {
		status = (guint) SOUP_STATUS_NOT_FOUND;
	}
	soup_server_unpause_message (self->server, self->msg);
	rygel_http_request_end (self, status);
}


void rygel_http_request_end (RygelHTTPRequest* self, guint status) {
	g_return_if_fail (self != NULL);
	if (status != SOUP_STATUS_NONE) {
		soup_message_set_status (self->msg, status);
	}
	g_signal_emit_by_name ((RygelStateMachine*) self, "completed");
}


static GCancellable* rygel_http_request_real_get_cancellable (RygelStateMachine* base) {
	GCancellable* result;
	RygelHTTPRequest* self;
	self = (RygelHTTPRequest*) base;
	result = self->priv->_cancellable;
	return result;
}


static void rygel_http_request_real_set_cancellable (RygelStateMachine* base, GCancellable* value) {
	RygelHTTPRequest* self;
	GCancellable* _tmp0_;
	self = (RygelHTTPRequest*) base;
	self->priv->_cancellable = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_cancellable), _tmp0_);
	g_object_notify ((GObject *) self, "cancellable");
}


static void rygel_http_request_class_init (RygelHTTPRequestClass * klass) {
	rygel_http_request_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelHTTPRequestPrivate));
	G_OBJECT_CLASS (klass)->get_property = rygel_http_request_get_property;
	G_OBJECT_CLASS (klass)->set_property = rygel_http_request_set_property;
	G_OBJECT_CLASS (klass)->finalize = rygel_http_request_finalize;
	g_object_class_override_property (G_OBJECT_CLASS (klass), RYGEL_HTTP_REQUEST_CANCELLABLE, "cancellable");
}


static void rygel_http_request_rygel_state_machine_interface_init (RygelStateMachineIface * iface) {
	rygel_http_request_rygel_state_machine_parent_iface = g_type_interface_peek_parent (iface);
	iface->run = rygel_http_request_real_run;
	iface->get_cancellable = rygel_http_request_real_get_cancellable;
	iface->set_cancellable = rygel_http_request_real_set_cancellable;
}


static void rygel_http_request_instance_init (RygelHTTPRequest * self) {
	self->priv = RYGEL_HTTP_REQUEST_GET_PRIVATE (self);
}


static void rygel_http_request_finalize (GObject* obj) {
	RygelHTTPRequest * self;
	self = RYGEL_HTTP_REQUEST (obj);
	_g_object_unref0 (self->priv->root_container);
	_g_object_unref0 (self->server);
	_g_object_unref0 (self->msg);
	_g_hash_table_unref0 (self->priv->query);
	_g_object_unref0 (self->priv->_cancellable);
	_g_object_unref0 (self->priv->response);
	_g_free0 (self->priv->item_id);
	_g_object_unref0 (self->item);
	_rygel_icon_info_unref0 (self->thumbnail);
	_g_object_unref0 (self->byte_range);
	_g_object_unref0 (self->time_range);
	_g_object_unref0 (self->priv->request_handler);
	G_OBJECT_CLASS (rygel_http_request_parent_class)->finalize (obj);
}


GType rygel_http_request_get_type (void) {
	static GType rygel_http_request_type_id = 0;
	if (rygel_http_request_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelHTTPRequestClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_http_request_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelHTTPRequest), 0, (GInstanceInitFunc) rygel_http_request_instance_init, NULL };
		static const GInterfaceInfo rygel_state_machine_info = { (GInterfaceInitFunc) rygel_http_request_rygel_state_machine_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		rygel_http_request_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelHTTPRequest", &g_define_type_info, 0);
		g_type_add_interface_static (rygel_http_request_type_id, RYGEL_TYPE_STATE_MACHINE, &rygel_state_machine_info);
	}
	return rygel_http_request_type_id;
}


static void rygel_http_request_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	RygelHTTPRequest * self;
	self = RYGEL_HTTP_REQUEST (object);
	switch (property_id) {
		case RYGEL_HTTP_REQUEST_CANCELLABLE:
		g_value_set_object (value, rygel_state_machine_get_cancellable ((RygelStateMachine*) self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void rygel_http_request_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	RygelHTTPRequest * self;
	self = RYGEL_HTTP_REQUEST (object);
	switch (property_id) {
		case RYGEL_HTTP_REQUEST_CANCELLABLE:
		rygel_state_machine_set_cancellable ((RygelStateMachine*) self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
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




