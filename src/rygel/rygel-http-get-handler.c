/* rygel-http-get-handler.c generated by valac, the Vala compiler
 * generated from rygel-http-get-handler.vala, do not modify */

/*
 * Copyright (C) 2008-2010 Nokia Corporation.
 * Copyright (C) 2010 Andreas Henriksson <andreas@fatal.se>
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


#define RYGEL_TYPE_HTTP_GET_HANDLER (rygel_http_get_handler_get_type ())
#define RYGEL_HTTP_GET_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_GET_HANDLER, RygelHTTPGetHandler))
#define RYGEL_HTTP_GET_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_GET_HANDLER, RygelHTTPGetHandlerClass))
#define RYGEL_IS_HTTP_GET_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_GET_HANDLER))
#define RYGEL_IS_HTTP_GET_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_GET_HANDLER))
#define RYGEL_HTTP_GET_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_GET_HANDLER, RygelHTTPGetHandlerClass))

typedef struct _RygelHTTPGetHandler RygelHTTPGetHandler;
typedef struct _RygelHTTPGetHandlerClass RygelHTTPGetHandlerClass;
typedef struct _RygelHTTPGetHandlerPrivate RygelHTTPGetHandlerPrivate;

#define RYGEL_TYPE_HTTP_REQUEST (rygel_http_request_get_type ())
#define RYGEL_HTTP_REQUEST(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_REQUEST, RygelHTTPRequest))
#define RYGEL_HTTP_REQUEST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_REQUEST, RygelHTTPRequestClass))
#define RYGEL_IS_HTTP_REQUEST(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_REQUEST))
#define RYGEL_IS_HTTP_REQUEST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_REQUEST))
#define RYGEL_HTTP_REQUEST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_REQUEST, RygelHTTPRequestClass))

typedef struct _RygelHTTPRequest RygelHTTPRequest;
typedef struct _RygelHTTPRequestClass RygelHTTPRequestClass;

#define RYGEL_TYPE_HTTP_GET (rygel_http_get_get_type ())
#define RYGEL_HTTP_GET(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_GET, RygelHTTPGet))
#define RYGEL_HTTP_GET_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_GET, RygelHTTPGetClass))
#define RYGEL_IS_HTTP_GET(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_GET))
#define RYGEL_IS_HTTP_GET_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_GET))
#define RYGEL_HTTP_GET_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_GET, RygelHTTPGetClass))

typedef struct _RygelHTTPGet RygelHTTPGet;
typedef struct _RygelHTTPGetClass RygelHTTPGetClass;

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

#define RYGEL_TYPE_HTTP_ITEM_URI (rygel_http_item_uri_get_type ())
#define RYGEL_HTTP_ITEM_URI(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_ITEM_URI, RygelHTTPItemURI))
#define RYGEL_HTTP_ITEM_URI_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_ITEM_URI, RygelHTTPItemURIClass))
#define RYGEL_IS_HTTP_ITEM_URI(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_ITEM_URI))
#define RYGEL_IS_HTTP_ITEM_URI_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_ITEM_URI))
#define RYGEL_HTTP_ITEM_URI_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_ITEM_URI, RygelHTTPItemURIClass))

typedef struct _RygelHTTPItemURI RygelHTTPItemURI;
typedef struct _RygelHTTPItemURIClass RygelHTTPItemURIClass;

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
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
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

#define RYGEL_TYPE_SUBTITLE (rygel_subtitle_get_type ())
#define RYGEL_SUBTITLE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_SUBTITLE, RygelSubtitle))
#define RYGEL_SUBTITLE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_SUBTITLE, RygelSubtitleClass))
#define RYGEL_IS_SUBTITLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_SUBTITLE))
#define RYGEL_IS_SUBTITLE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_SUBTITLE))
#define RYGEL_SUBTITLE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_SUBTITLE, RygelSubtitleClass))

typedef struct _RygelSubtitle RygelSubtitle;
typedef struct _RygelSubtitleClass RygelSubtitleClass;

typedef enum  {
	RYGEL_HTTP_REQUEST_ERROR_UNACCEPTABLE = SOUP_STATUS_NOT_ACCEPTABLE,
	RYGEL_HTTP_REQUEST_ERROR_BAD_REQUEST = SOUP_STATUS_BAD_REQUEST,
	RYGEL_HTTP_REQUEST_ERROR_NOT_FOUND = SOUP_STATUS_NOT_FOUND
} RygelHTTPRequestError;
#define RYGEL_HTTP_REQUEST_ERROR rygel_http_request_error_quark ()
struct _RygelHTTPGetHandler {
	GObject parent_instance;
	RygelHTTPGetHandlerPrivate * priv;
};

struct _RygelHTTPGetHandlerClass {
	GObjectClass parent_class;
	void (*add_response_headers) (RygelHTTPGetHandler* self, RygelHTTPGet* request, GError** error);
	RygelHTTPResponse* (*render_body) (RygelHTTPGetHandler* self, RygelHTTPGet* request, GError** error);
	GUPnPDIDLLiteResource* (*add_resource) (RygelHTTPGetHandler* self, GUPnPDIDLLiteItem* didl_item, RygelHTTPGet* request, GError** error);
};

struct _RygelHTTPGetHandlerPrivate {
	GCancellable* _cancellable;
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
	RygelHTTPItemURI* uri;
	RygelMediaItem* item;
};

struct _RygelHTTPRequestClass {
	GObjectClass parent_class;
	void (*handle) (RygelHTTPRequest* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
	void (*handle_finish) (RygelHTTPRequest* self, GAsyncResult* _res_);
	void (*find_item) (RygelHTTPRequest* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
	void (*find_item_finish) (RygelHTTPRequest* self, GAsyncResult* _res_);
	void (*handle_error) (RygelHTTPRequest* self, GError* _error_);
};

struct _RygelMediaObject {
	GObject parent_instance;
	RygelMediaObjectPrivate * priv;
	char* id;
	char* upnp_class;
	guint64 modified;
	GeeArrayList* uris;
	RygelMediaContainer* parent;
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
	GeeArrayList* subtitles;
	gboolean place_holder;
};

struct _RygelMediaItemClass {
	RygelMediaObjectClass parent_class;
	GstElement* (*create_stream_source) (RygelMediaItem* self);
	gboolean (*should_stream) (RygelMediaItem* self);
};


static gpointer rygel_http_get_handler_parent_class = NULL;

GType rygel_http_get_handler_get_type (void);
GType rygel_http_request_get_type (void);
GType rygel_http_get_get_type (void);
GQuark rygel_http_request_error_quark (void);
GType rygel_http_response_get_type (void);
#define RYGEL_HTTP_GET_HANDLER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_HTTP_GET_HANDLER, RygelHTTPGetHandlerPrivate))
enum  {
	RYGEL_HTTP_GET_HANDLER_DUMMY_PROPERTY,
	RYGEL_HTTP_GET_HANDLER_CANCELLABLE
};
GType rygel_state_machine_get_type (void);
GType rygel_transcode_manager_get_type (void);
GType rygel_http_server_get_type (void);
GType rygel_http_item_uri_get_type (void);
GType rygel_media_object_get_type (void);
GType rygel_media_item_get_type (void);
GUPnPDIDLLiteResource* rygel_http_get_handler_add_resource (RygelHTTPGetHandler* self, GUPnPDIDLLiteItem* didl_item, RygelHTTPGet* request, GError** error);
GType rygel_media_container_get_type (void);
gpointer rygel_icon_info_ref (gpointer instance);
void rygel_icon_info_unref (gpointer instance);
GParamSpec* rygel_param_spec_icon_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_icon_info (GValue* value, gpointer v_object);
void rygel_value_take_icon_info (GValue* value, gpointer v_object);
gpointer rygel_value_get_icon_info (const GValue* value);
GType rygel_icon_info_get_type (void);
GType rygel_thumbnail_get_type (void);
gpointer rygel_subtitle_ref (gpointer instance);
void rygel_subtitle_unref (gpointer instance);
GParamSpec* rygel_param_spec_subtitle (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_subtitle (GValue* value, gpointer v_object);
void rygel_value_take_subtitle (GValue* value, gpointer v_object);
gpointer rygel_value_get_subtitle (const GValue* value);
GType rygel_subtitle_get_type (void);
char* rygel_transcode_manager_create_uri_for_item (RygelTranscodeManager* self, RygelMediaItem* item, gint thumbnail_index, gint subtitle_index, const char* transcode_target);
void rygel_http_get_handler_add_response_headers (RygelHTTPGetHandler* self, RygelHTTPGet* request, GError** error);
static void rygel_http_get_handler_real_add_response_headers (RygelHTTPGetHandler* self, RygelHTTPGet* request, GError** error);
RygelHTTPResponse* rygel_http_get_handler_render_body (RygelHTTPGetHandler* self, RygelHTTPGet* request, GError** error);
static RygelHTTPResponse* rygel_http_get_handler_real_render_body (RygelHTTPGetHandler* self, RygelHTTPGet* request, GError** error);
static GUPnPDIDLLiteResource* rygel_http_get_handler_real_add_resource (RygelHTTPGetHandler* self, GUPnPDIDLLiteItem* didl_item, RygelHTTPGet* request, GError** error);
RygelHTTPGetHandler* rygel_http_get_handler_construct (GType object_type);
GCancellable* rygel_http_get_handler_get_cancellable (RygelHTTPGetHandler* self);
void rygel_http_get_handler_set_cancellable (RygelHTTPGetHandler* self, GCancellable* value);
static void rygel_http_get_handler_finalize (GObject* obj);
static void rygel_http_get_handler_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void rygel_http_get_handler_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);



#line 34 "rygel-http-get-handler.vala"
static void rygel_http_get_handler_real_add_response_headers (RygelHTTPGetHandler* self, RygelHTTPGet* request, GError** error) {
#line 335 "rygel-http-get-handler.c"
	GError * _inner_error_;
	char* mode;
	GUPnPDIDLLiteWriter* didl_writer;
	GUPnPDIDLLiteItem* didl_item;
	gboolean _tmp4_ = FALSE;
#line 34 "rygel-http-get-handler.vala"
	g_return_if_fail (self != NULL);
#line 34 "rygel-http-get-handler.vala"
	g_return_if_fail (request != NULL);
#line 345 "rygel-http-get-handler.c"
	_inner_error_ = NULL;
#line 36 "rygel-http-get-handler.vala"
	mode = g_strdup (soup_message_headers_get (((RygelHTTPRequest*) request)->msg->request_headers, "transferMode.dlna.org"));
#line 37 "rygel-http-get-handler.vala"
	if (mode != NULL) {
#line 41 "rygel-http-get-handler.vala"
		soup_message_headers_append (((RygelHTTPRequest*) request)->msg->response_headers, "transferMode.dlna.org", mode);
#line 353 "rygel-http-get-handler.c"
	}
#line 47 "rygel-http-get-handler.vala"
	didl_writer = gupnp_didl_lite_writer_new (NULL);
#line 48 "rygel-http-get-handler.vala"
	didl_item = gupnp_didl_lite_writer_add_item (didl_writer);
#line 359 "rygel-http-get-handler.c"
	{
		GUPnPDIDLLiteResource* resource;
		char** _tmp3_;
		gint _tokens_size_;
		gint tokens_length1;
		char** _tmp1_;
		char* _tmp0_;
		char** _tmp2_;
		char** tokens;
#line 50 "rygel-http-get-handler.vala"
		resource = rygel_http_get_handler_add_resource (self, didl_item, request, &_inner_error_);
#line 371 "rygel-http-get-handler.c"
		if (_inner_error_ != NULL) {
			goto __catch27_g_error;
		}
		tokens = (_tmp3_ = (_tmp2_ = _tmp1_ = g_strsplit (_tmp0_ = gupnp_protocol_info_to_string (gupnp_didl_lite_resource_get_protocol_info (resource)), ":", 4), _g_free0 (_tmp0_), _tmp2_), tokens_length1 = _vala_array_length (_tmp1_), _tokens_size_ = tokens_length1, _tmp3_);
#line 52 "rygel-http-get-handler.vala"
		g_assert (tokens_length1 == 4);
#line 54 "rygel-http-get-handler.vala"
		soup_message_headers_append (((RygelHTTPRequest*) request)->msg->response_headers, "contentFeatures.dlna.org", tokens[3]);
#line 380 "rygel-http-get-handler.c"
		_g_object_unref0 (resource);
		tokens = (_vala_array_free (tokens, tokens_length1, (GDestroyNotify) g_free), NULL);
	}
	goto __finally27;
	__catch27_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
#line 57 "rygel-http-get-handler.vala"
			g_warning ("rygel-http-get-handler.vala:57: %s", "Received request for 'contentFeatures.dlna.org' but " "failed to provide the value in response headers");
#line 393 "rygel-http-get-handler.c"
			_g_error_free0 (err);
		}
	}
	__finally27:
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
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
#line 62 "rygel-http-get-handler.vala"
	if (soup_message_headers_get (((RygelHTTPRequest*) request)->msg->request_headers, "getCaptionInfo.sec") != NULL) {
#line 63 "rygel-http-get-handler.vala"
		_tmp4_ = gee_collection_get_size ((GeeCollection*) ((RygelHTTPRequest*) request)->item->subtitles) > 0;
#line 418 "rygel-http-get-handler.c"
	} else {
#line 62 "rygel-http-get-handler.vala"
		_tmp4_ = FALSE;
#line 422 "rygel-http-get-handler.c"
	}
#line 62 "rygel-http-get-handler.vala"
	if (_tmp4_) {
#line 426 "rygel-http-get-handler.c"
		char* caption_uri;
#line 64 "rygel-http-get-handler.vala"
		caption_uri = rygel_transcode_manager_create_uri_for_item ((RygelTranscodeManager*) ((RygelHTTPRequest*) request)->http_server, ((RygelHTTPRequest*) request)->item, -1, 0, NULL);
#line 70 "rygel-http-get-handler.vala"
		soup_message_headers_append (((RygelHTTPRequest*) request)->msg->response_headers, "CaptionInfo.sec", caption_uri);
#line 432 "rygel-http-get-handler.c"
		_g_free0 (caption_uri);
	}
	_g_free0 (mode);
	_g_object_unref0 (didl_writer);
	_g_object_unref0 (didl_item);
}


#line 34 "rygel-http-get-handler.vala"
void rygel_http_get_handler_add_response_headers (RygelHTTPGetHandler* self, RygelHTTPGet* request, GError** error) {
#line 34 "rygel-http-get-handler.vala"
	RYGEL_HTTP_GET_HANDLER_GET_CLASS (self)->add_response_headers (self, request, error);
#line 445 "rygel-http-get-handler.c"
}


#line 76 "rygel-http-get-handler.vala"
static RygelHTTPResponse* rygel_http_get_handler_real_render_body (RygelHTTPGetHandler* self, RygelHTTPGet* request, GError** error) {
#line 451 "rygel-http-get-handler.c"
	g_return_val_if_fail (self != NULL, NULL);
	g_critical ("Type `%s' does not implement abstract method `rygel_http_get_handler_render_body'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}


#line 76 "rygel-http-get-handler.vala"
RygelHTTPResponse* rygel_http_get_handler_render_body (RygelHTTPGetHandler* self, RygelHTTPGet* request, GError** error) {
#line 76 "rygel-http-get-handler.vala"
	return RYGEL_HTTP_GET_HANDLER_GET_CLASS (self)->render_body (self, request, error);
#line 462 "rygel-http-get-handler.c"
}


#line 79 "rygel-http-get-handler.vala"
static GUPnPDIDLLiteResource* rygel_http_get_handler_real_add_resource (RygelHTTPGetHandler* self, GUPnPDIDLLiteItem* didl_item, RygelHTTPGet* request, GError** error) {
#line 468 "rygel-http-get-handler.c"
	g_return_val_if_fail (self != NULL, NULL);
	g_critical ("Type `%s' does not implement abstract method `rygel_http_get_handler_add_resource'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}


#line 79 "rygel-http-get-handler.vala"
GUPnPDIDLLiteResource* rygel_http_get_handler_add_resource (RygelHTTPGetHandler* self, GUPnPDIDLLiteItem* didl_item, RygelHTTPGet* request, GError** error) {
#line 79 "rygel-http-get-handler.vala"
	return RYGEL_HTTP_GET_HANDLER_GET_CLASS (self)->add_resource (self, didl_item, request, error);
#line 479 "rygel-http-get-handler.c"
}


#line 30 "rygel-http-get-handler.vala"
RygelHTTPGetHandler* rygel_http_get_handler_construct (GType object_type) {
#line 485 "rygel-http-get-handler.c"
	RygelHTTPGetHandler * self;
#line 30 "rygel-http-get-handler.vala"
	self = (RygelHTTPGetHandler*) g_object_new (object_type, NULL);
#line 489 "rygel-http-get-handler.c"
	return self;
}


GCancellable* rygel_http_get_handler_get_cancellable (RygelHTTPGetHandler* self) {
	GCancellable* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_cancellable;
#line 31 "rygel-http-get-handler.vala"
	return result;
#line 500 "rygel-http-get-handler.c"
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void rygel_http_get_handler_set_cancellable (RygelHTTPGetHandler* self, GCancellable* value) {
	GCancellable* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_cancellable = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_cancellable), _tmp0_);
	g_object_notify ((GObject *) self, "cancellable");
}


static void rygel_http_get_handler_class_init (RygelHTTPGetHandlerClass * klass) {
	rygel_http_get_handler_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelHTTPGetHandlerPrivate));
	RYGEL_HTTP_GET_HANDLER_CLASS (klass)->add_response_headers = rygel_http_get_handler_real_add_response_headers;
	RYGEL_HTTP_GET_HANDLER_CLASS (klass)->render_body = rygel_http_get_handler_real_render_body;
	RYGEL_HTTP_GET_HANDLER_CLASS (klass)->add_resource = rygel_http_get_handler_real_add_resource;
	G_OBJECT_CLASS (klass)->get_property = rygel_http_get_handler_get_property;
	G_OBJECT_CLASS (klass)->set_property = rygel_http_get_handler_set_property;
	G_OBJECT_CLASS (klass)->finalize = rygel_http_get_handler_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), RYGEL_HTTP_GET_HANDLER_CANCELLABLE, g_param_spec_object ("cancellable", "cancellable", "cancellable", G_TYPE_CANCELLABLE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void rygel_http_get_handler_instance_init (RygelHTTPGetHandler * self) {
	self->priv = RYGEL_HTTP_GET_HANDLER_GET_PRIVATE (self);
}


static void rygel_http_get_handler_finalize (GObject* obj) {
	RygelHTTPGetHandler * self;
	self = RYGEL_HTTP_GET_HANDLER (obj);
	_g_object_unref0 (self->priv->_cancellable);
	G_OBJECT_CLASS (rygel_http_get_handler_parent_class)->finalize (obj);
}


GType rygel_http_get_handler_get_type (void) {
	static volatile gsize rygel_http_get_handler_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_http_get_handler_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelHTTPGetHandlerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_http_get_handler_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelHTTPGetHandler), 0, (GInstanceInitFunc) rygel_http_get_handler_instance_init, NULL };
		GType rygel_http_get_handler_type_id;
		rygel_http_get_handler_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelHTTPGetHandler", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&rygel_http_get_handler_type_id__volatile, rygel_http_get_handler_type_id);
	}
	return rygel_http_get_handler_type_id__volatile;
}


static void rygel_http_get_handler_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	RygelHTTPGetHandler * self;
	self = RYGEL_HTTP_GET_HANDLER (object);
	switch (property_id) {
		case RYGEL_HTTP_GET_HANDLER_CANCELLABLE:
		g_value_set_object (value, rygel_http_get_handler_get_cancellable (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void rygel_http_get_handler_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	RygelHTTPGetHandler * self;
	self = RYGEL_HTTP_GET_HANDLER (object);
	switch (property_id) {
		case RYGEL_HTTP_GET_HANDLER_CANCELLABLE:
		rygel_http_get_handler_set_cancellable (self, g_value_get_object (value));
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




