/* rygel-http-time-seek.c generated by valac, the Vala compiler
 * generated from rygel-http-time-seek.vala, do not modify */

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

#define RYGEL_TYPE_HTTP_TIME_SEEK (rygel_http_time_seek_get_type ())
#define RYGEL_HTTP_TIME_SEEK(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_TIME_SEEK, RygelHTTPTimeSeek))
#define RYGEL_HTTP_TIME_SEEK_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_TIME_SEEK, RygelHTTPTimeSeekClass))
#define RYGEL_IS_HTTP_TIME_SEEK(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_TIME_SEEK))
#define RYGEL_IS_HTTP_TIME_SEEK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_TIME_SEEK))
#define RYGEL_HTTP_TIME_SEEK_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_TIME_SEEK, RygelHTTPTimeSeekClass))

typedef struct _RygelHTTPTimeSeek RygelHTTPTimeSeek;
typedef struct _RygelHTTPTimeSeekClass RygelHTTPTimeSeekClass;
typedef struct _RygelHTTPTimeSeekPrivate RygelHTTPTimeSeekPrivate;

#define RYGEL_TYPE_HTTP_REQUEST (rygel_http_request_get_type ())
#define RYGEL_HTTP_REQUEST(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_REQUEST, RygelHTTPRequest))
#define RYGEL_HTTP_REQUEST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_REQUEST, RygelHTTPRequestClass))
#define RYGEL_IS_HTTP_REQUEST(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_REQUEST))
#define RYGEL_IS_HTTP_REQUEST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_REQUEST))
#define RYGEL_HTTP_REQUEST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_REQUEST, RygelHTTPRequestClass))

typedef struct _RygelHTTPRequest RygelHTTPRequest;
typedef struct _RygelHTTPRequestClass RygelHTTPRequestClass;

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
#define _g_free0(var) (var = (g_free (var), NULL))

#define RYGEL_TYPE_HTTP_GET (rygel_http_get_get_type ())
#define RYGEL_HTTP_GET(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_GET, RygelHTTPGet))
#define RYGEL_HTTP_GET_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_GET, RygelHTTPGetClass))
#define RYGEL_IS_HTTP_GET(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_GET))
#define RYGEL_IS_HTTP_GET_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_GET))
#define RYGEL_HTTP_GET_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_GET, RygelHTTPGetClass))

typedef struct _RygelHTTPGet RygelHTTPGet;
typedef struct _RygelHTTPGetClass RygelHTTPGetClass;
typedef struct _RygelHTTPGetPrivate RygelHTTPGetPrivate;

#define RYGEL_TYPE_HTTP_GET_HANDLER (rygel_http_get_handler_get_type ())
#define RYGEL_HTTP_GET_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_GET_HANDLER, RygelHTTPGetHandler))
#define RYGEL_HTTP_GET_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_GET_HANDLER, RygelHTTPGetHandlerClass))
#define RYGEL_IS_HTTP_GET_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_GET_HANDLER))
#define RYGEL_IS_HTTP_GET_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_GET_HANDLER))
#define RYGEL_HTTP_GET_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_GET_HANDLER, RygelHTTPGetHandlerClass))

typedef struct _RygelHTTPGetHandler RygelHTTPGetHandler;
typedef struct _RygelHTTPGetHandlerClass RygelHTTPGetHandlerClass;

#define RYGEL_TYPE_HTTP_TRANSCODE_HANDLER (rygel_http_transcode_handler_get_type ())
#define RYGEL_HTTP_TRANSCODE_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_TRANSCODE_HANDLER, RygelHTTPTranscodeHandler))
#define RYGEL_HTTP_TRANSCODE_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_TRANSCODE_HANDLER, RygelHTTPTranscodeHandlerClass))
#define RYGEL_IS_HTTP_TRANSCODE_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_TRANSCODE_HANDLER))
#define RYGEL_IS_HTTP_TRANSCODE_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_TRANSCODE_HANDLER))
#define RYGEL_HTTP_TRANSCODE_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_TRANSCODE_HANDLER, RygelHTTPTranscodeHandlerClass))

typedef struct _RygelHTTPTranscodeHandler RygelHTTPTranscodeHandler;
typedef struct _RygelHTTPTranscodeHandlerClass RygelHTTPTranscodeHandlerClass;

struct _RygelHTTPSeek {
	GObject parent_instance;
	RygelHTTPSeekPrivate * priv;
};

struct _RygelHTTPSeekClass {
	GObjectClass parent_class;
	void (*add_response_headers) (RygelHTTPSeek* self);
};

struct _RygelHTTPTimeSeek {
	RygelHTTPSeek parent_instance;
	RygelHTTPTimeSeekPrivate * priv;
};

struct _RygelHTTPTimeSeekClass {
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

typedef enum  {
	RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE = SOUP_STATUS_BAD_REQUEST,
	RYGEL_HTTP_SEEK_ERROR_OUT_OF_RANGE = SOUP_STATUS_REQUESTED_RANGE_NOT_SATISFIABLE
} RygelHTTPSeekError;
#define RYGEL_HTTP_SEEK_ERROR rygel_http_seek_error_quark ()
struct _RygelHTTPGet {
	RygelHTTPRequest parent_instance;
	RygelHTTPGetPrivate * priv;
	RygelThumbnail* thumbnail;
	RygelSubtitle* subtitle;
	RygelHTTPSeek* seek;
	RygelHTTPGetHandler* handler;
};

struct _RygelHTTPGetClass {
	RygelHTTPRequestClass parent_class;
};


static gpointer rygel_http_time_seek_parent_class = NULL;

GType rygel_http_seek_get_type (void);
GType rygel_http_time_seek_get_type (void);
enum  {
	RYGEL_HTTP_TIME_SEEK_DUMMY_PROPERTY
};
GType rygel_http_request_get_type (void);
GType rygel_state_machine_get_type (void);
GType rygel_transcode_manager_get_type (void);
GType rygel_http_server_get_type (void);
GType rygel_http_item_uri_get_type (void);
GType rygel_media_object_get_type (void);
GType rygel_media_item_get_type (void);
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
GQuark rygel_http_seek_error_quark (void);
RygelHTTPSeek* rygel_http_seek_construct (GType object_type, SoupMessage* msg, gint64 start, gint64 stop, gint64 length);
GType rygel_http_get_get_type (void);
RygelHTTPTimeSeek* rygel_http_time_seek_new (RygelHTTPGet* request, GError** error);
RygelHTTPTimeSeek* rygel_http_time_seek_construct (GType object_type, RygelHTTPGet* request, GError** error);
GType rygel_http_get_handler_get_type (void);
GType rygel_http_transcode_handler_get_type (void);
gboolean rygel_media_item_should_stream (RygelMediaItem* self);
gboolean rygel_http_time_seek_needed (RygelHTTPGet* request);
gint64 rygel_http_seek_get_start (RygelHTTPSeek* self);
gint64 rygel_http_seek_get_stop (RygelHTTPSeek* self);
gint64 rygel_http_seek_get_length (RygelHTTPSeek* self);
SoupMessage* rygel_http_seek_get_msg (RygelHTTPSeek* self);
static void rygel_http_time_seek_real_add_response_headers (RygelHTTPSeek* base);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);
static int _vala_strcmp0 (const char * str1, const char * str2);



#line 34 "rygel-http-time-seek.vala"
RygelHTTPTimeSeek* rygel_http_time_seek_construct (GType object_type, RygelHTTPGet* request, GError** error) {
#line 368 "rygel-http-time-seek.c"
	GError * _inner_error_;
	RygelHTTPTimeSeek * self;
	char* range;
	char* time;
	gint _range_tokens_size_;
	gint range_tokens_length1;
	char** range_tokens;
	gint64 start;
	gint64 duration;
	gint64 stop;
	char* _tmp0_;
#line 34 "rygel-http-time-seek.vala"
	g_return_val_if_fail (request != NULL, NULL);
#line 382 "rygel-http-time-seek.c"
	_inner_error_ = NULL;
	range = NULL;
	time = NULL;
	range_tokens = (range_tokens_length1 = 0, NULL);
#line 37 "rygel-http-time-seek.vala"
	start = (gint64) 0;
#line 38 "rygel-http-time-seek.vala"
	duration = (gint64) (((RygelHTTPRequest*) request)->item->duration * GST_SECOND);
#line 39 "rygel-http-time-seek.vala"
	stop = duration - (10 * GST_MSECOND);
#line 41 "rygel-http-time-seek.vala"
	range = (_tmp0_ = g_strdup (soup_message_headers_get (((RygelHTTPRequest*) request)->msg->request_headers, "TimeSeekRange.dlna.org")), _g_free0 (range), _tmp0_);
#line 42 "rygel-http-time-seek.vala"
	if (range != NULL) {
#line 397 "rygel-http-time-seek.c"
		char** _tmp2_;
		char** _tmp1_;
		gboolean _tmp3_ = FALSE;
		char* _tmp4_;
		char* _tmp5_;
#line 43 "rygel-http-time-seek.vala"
		if (!g_str_has_prefix (range, "npt=")) {
#line 405 "rygel-http-time-seek.c"
			_inner_error_ = g_error_new (RYGEL_HTTP_SEEK_ERROR, RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE, "Invalid Range '%s'", range);
			{
				if (_inner_error_->domain == RYGEL_HTTP_SEEK_ERROR) {
					g_propagate_error (error, _inner_error_);
					_g_free0 (range);
					_g_free0 (time);
					range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
					g_object_unref (self);
					return NULL;
				} else {
					_g_free0 (range);
					_g_free0 (time);
					range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
					g_clear_error (&_inner_error_);
					return NULL;
				}
			}
		}
#line 48 "rygel-http-time-seek.vala"
		range_tokens = (_tmp2_ = _tmp1_ = g_strsplit (g_utf8_offset_to_pointer (range, (glong) 4), "-", 2), range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL), range_tokens_length1 = _vala_array_length (_tmp1_), _range_tokens_size_ = range_tokens_length1, _tmp2_);
#line 49 "rygel-http-time-seek.vala"
		if (range_tokens[0] == NULL) {
#line 49 "rygel-http-time-seek.vala"
			_tmp3_ = TRUE;
#line 431 "rygel-http-time-seek.c"
		} else {
#line 49 "rygel-http-time-seek.vala"
			_tmp3_ = range_tokens[1] == NULL;
#line 435 "rygel-http-time-seek.c"
		}
#line 49 "rygel-http-time-seek.vala"
		if (_tmp3_) {
#line 439 "rygel-http-time-seek.c"
			_inner_error_ = g_error_new (RYGEL_HTTP_SEEK_ERROR, RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE, "Invalid Range '%s'", range);
			{
				if (_inner_error_->domain == RYGEL_HTTP_SEEK_ERROR) {
					g_propagate_error (error, _inner_error_);
					_g_free0 (range);
					_g_free0 (time);
					range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
					g_object_unref (self);
					return NULL;
				} else {
					_g_free0 (range);
					_g_free0 (time);
					range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
					g_clear_error (&_inner_error_);
					return NULL;
				}
			}
		}
#line 55 "rygel-http-time-seek.vala"
		time = (_tmp4_ = g_strdup (range_tokens[0]), _g_free0 (time), _tmp4_);
#line 56 "rygel-http-time-seek.vala"
		if (g_unichar_isdigit (g_utf8_get_char (g_utf8_offset_to_pointer (time, 0)))) {
#line 57 "rygel-http-time-seek.vala"
			start = (gint64) (g_ascii_strtod (time, NULL) * GST_SECOND);
#line 465 "rygel-http-time-seek.c"
		} else {
#line 58 "rygel-http-time-seek.vala"
			if (_vala_strcmp0 (time, "") != 0) {
#line 469 "rygel-http-time-seek.c"
				_inner_error_ = g_error_new (RYGEL_HTTP_SEEK_ERROR, RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE, "Invalid Range '%s'", range);
				{
					if (_inner_error_->domain == RYGEL_HTTP_SEEK_ERROR) {
						g_propagate_error (error, _inner_error_);
						_g_free0 (range);
						_g_free0 (time);
						range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
						g_object_unref (self);
						return NULL;
					} else {
						_g_free0 (range);
						_g_free0 (time);
						range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
						g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
						g_clear_error (&_inner_error_);
						return NULL;
					}
				}
			}
		}
#line 64 "rygel-http-time-seek.vala"
		time = (_tmp5_ = g_strdup (range_tokens[1]), _g_free0 (time), _tmp5_);
#line 65 "rygel-http-time-seek.vala"
		if (g_unichar_isdigit (g_utf8_get_char (g_utf8_offset_to_pointer (time, 0)))) {
#line 66 "rygel-http-time-seek.vala"
			stop = (gint64) (g_ascii_strtod (time, NULL) * GST_SECOND);
#line 67 "rygel-http-time-seek.vala"
			if (stop < start) {
#line 498 "rygel-http-time-seek.c"
				_inner_error_ = g_error_new (RYGEL_HTTP_SEEK_ERROR, RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE, "Invalid Range '%s'", range);
				{
					if (_inner_error_->domain == RYGEL_HTTP_SEEK_ERROR) {
						g_propagate_error (error, _inner_error_);
						_g_free0 (range);
						_g_free0 (time);
						range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
						g_object_unref (self);
						return NULL;
					} else {
						_g_free0 (range);
						_g_free0 (time);
						range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
						g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
						g_clear_error (&_inner_error_);
						return NULL;
					}
				}
			}
		} else {
#line 71 "rygel-http-time-seek.vala"
			if (_vala_strcmp0 (time, "") != 0) {
#line 521 "rygel-http-time-seek.c"
				_inner_error_ = g_error_new (RYGEL_HTTP_SEEK_ERROR, RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE, "Invalid Range '%s'", range);
				{
					if (_inner_error_->domain == RYGEL_HTTP_SEEK_ERROR) {
						g_propagate_error (error, _inner_error_);
						_g_free0 (range);
						_g_free0 (time);
						range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
						g_object_unref (self);
						return NULL;
					} else {
						_g_free0 (range);
						_g_free0 (time);
						range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
						g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
						g_clear_error (&_inner_error_);
						return NULL;
					}
				}
			}
		}
	}
#line 77 "rygel-http-time-seek.vala"
	self = (RygelHTTPTimeSeek*) rygel_http_seek_construct (object_type, ((RygelHTTPRequest*) request)->msg, start, stop, duration);
#line 545 "rygel-http-time-seek.c"
	_g_free0 (range);
	_g_free0 (time);
	range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
	return self;
}


#line 34 "rygel-http-time-seek.vala"
RygelHTTPTimeSeek* rygel_http_time_seek_new (RygelHTTPGet* request, GError** error) {
#line 34 "rygel-http-time-seek.vala"
	return rygel_http_time_seek_construct (RYGEL_TYPE_HTTP_TIME_SEEK, request, error);
#line 557 "rygel-http-time-seek.c"
}


#line 83 "rygel-http-time-seek.vala"
gboolean rygel_http_time_seek_needed (RygelHTTPGet* request) {
#line 563 "rygel-http-time-seek.c"
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
#line 83 "rygel-http-time-seek.vala"
	g_return_val_if_fail (request != NULL, FALSE);
#line 84 "rygel-http-time-seek.vala"
	if (((RygelHTTPRequest*) request)->item->duration > 0) {
#line 570 "rygel-http-time-seek.c"
		gboolean _tmp1_ = FALSE;
#line 85 "rygel-http-time-seek.vala"
		if (RYGEL_IS_HTTP_TRANSCODE_HANDLER (request->handler)) {
#line 85 "rygel-http-time-seek.vala"
			_tmp1_ = TRUE;
#line 576 "rygel-http-time-seek.c"
		} else {
			gboolean _tmp2_ = FALSE;
#line 86 "rygel-http-time-seek.vala"
			if (request->thumbnail == NULL) {
#line 87 "rygel-http-time-seek.vala"
				_tmp2_ = rygel_media_item_should_stream (((RygelHTTPRequest*) request)->item);
#line 583 "rygel-http-time-seek.c"
			} else {
#line 86 "rygel-http-time-seek.vala"
				_tmp2_ = FALSE;
#line 587 "rygel-http-time-seek.c"
			}
#line 86 "rygel-http-time-seek.vala"
			_tmp1_ = _tmp2_;
#line 591 "rygel-http-time-seek.c"
		}
#line 85 "rygel-http-time-seek.vala"
		_tmp0_ = _tmp1_;
#line 595 "rygel-http-time-seek.c"
	} else {
#line 84 "rygel-http-time-seek.vala"
		_tmp0_ = FALSE;
#line 599 "rygel-http-time-seek.c"
	}
	result = _tmp0_;
#line 84 "rygel-http-time-seek.vala"
	return result;
#line 604 "rygel-http-time-seek.c"
}


#line 90 "rygel-http-time-seek.vala"
static void rygel_http_time_seek_real_add_response_headers (RygelHTTPSeek* base) {
#line 610 "rygel-http-time-seek.c"
	RygelHTTPTimeSeek * self;
	double start;
	double stop;
	double length;
	char* range;
	self = (RygelHTTPTimeSeek*) base;
#line 92 "rygel-http-time-seek.vala"
	start = ((double) rygel_http_seek_get_start ((RygelHTTPSeek*) self)) / GST_SECOND;
#line 93 "rygel-http-time-seek.vala"
	stop = ((double) rygel_http_seek_get_stop ((RygelHTTPSeek*) self)) / GST_SECOND;
#line 94 "rygel-http-time-seek.vala"
	length = ((double) rygel_http_seek_get_length ((RygelHTTPSeek*) self)) / GST_SECOND;
#line 96 "rygel-http-time-seek.vala"
	range = g_strdup_printf ("npt=%.2f-%.2f/%.2f", start, stop, length);
#line 98 "rygel-http-time-seek.vala"
	soup_message_headers_append (rygel_http_seek_get_msg ((RygelHTTPSeek*) self)->response_headers, "TimeSeekRange.dlna.org", range);
#line 627 "rygel-http-time-seek.c"
	_g_free0 (range);
}


static void rygel_http_time_seek_class_init (RygelHTTPTimeSeekClass * klass) {
	rygel_http_time_seek_parent_class = g_type_class_peek_parent (klass);
	RYGEL_HTTP_SEEK_CLASS (klass)->add_response_headers = rygel_http_time_seek_real_add_response_headers;
}


static void rygel_http_time_seek_instance_init (RygelHTTPTimeSeek * self) {
}


GType rygel_http_time_seek_get_type (void) {
	static volatile gsize rygel_http_time_seek_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_http_time_seek_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelHTTPTimeSeekClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_http_time_seek_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelHTTPTimeSeek), 0, (GInstanceInitFunc) rygel_http_time_seek_instance_init, NULL };
		GType rygel_http_time_seek_type_id;
		rygel_http_time_seek_type_id = g_type_register_static (RYGEL_TYPE_HTTP_SEEK, "RygelHTTPTimeSeek", &g_define_type_info, 0);
		g_once_init_leave (&rygel_http_time_seek_type_id__volatile, rygel_http_time_seek_type_id);
	}
	return rygel_http_time_seek_type_id__volatile;
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




