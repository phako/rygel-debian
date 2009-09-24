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
#include <stdlib.h>
#include <string.h>
#include <libgupnp-av/gupnp-av.h>
#include <gio/gio.h>
#include <libgupnp/gupnp.h>
#include <gee.h>
#include <libsoup/soup.h>
#include <gst/gst.h>
#include <libgssdp/gssdp.h>


#define RYGEL_TYPE_TRANSCODE_MANAGER (rygel_transcode_manager_get_type ())
#define RYGEL_TRANSCODE_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRANSCODE_MANAGER, RygelTranscodeManager))
#define RYGEL_TRANSCODE_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRANSCODE_MANAGER, RygelTranscodeManagerClass))
#define RYGEL_IS_TRANSCODE_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRANSCODE_MANAGER))
#define RYGEL_IS_TRANSCODE_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRANSCODE_MANAGER))
#define RYGEL_TRANSCODE_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRANSCODE_MANAGER, RygelTranscodeManagerClass))

typedef struct _RygelTranscodeManager RygelTranscodeManager;
typedef struct _RygelTranscodeManagerClass RygelTranscodeManagerClass;
typedef struct _RygelTranscodeManagerPrivate RygelTranscodeManagerPrivate;

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

#define RYGEL_TYPE_STATE_MACHINE (rygel_state_machine_get_type ())
#define RYGEL_STATE_MACHINE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_STATE_MACHINE, RygelStateMachine))
#define RYGEL_IS_STATE_MACHINE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_STATE_MACHINE))
#define RYGEL_STATE_MACHINE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), RYGEL_TYPE_STATE_MACHINE, RygelStateMachineIface))

typedef struct _RygelStateMachine RygelStateMachine;
typedef struct _RygelStateMachineIface RygelStateMachineIface;

#define RYGEL_TYPE_HTTP_SERVER (rygel_http_server_get_type ())
#define RYGEL_HTTP_SERVER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_SERVER, RygelHTTPServer))
#define RYGEL_HTTP_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_SERVER, RygelHTTPServerClass))
#define RYGEL_IS_HTTP_SERVER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_SERVER))
#define RYGEL_IS_HTTP_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_SERVER))
#define RYGEL_HTTP_SERVER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_SERVER, RygelHTTPServerClass))

typedef struct _RygelHTTPServer RygelHTTPServer;
typedef struct _RygelHTTPServerClass RygelHTTPServerClass;
typedef struct _RygelHTTPServerPrivate RygelHTTPServerPrivate;

#define RYGEL_TYPE_MEDIA_CONTAINER (rygel_media_container_get_type ())
#define RYGEL_MEDIA_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainer))
#define RYGEL_MEDIA_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainerClass))
#define RYGEL_IS_MEDIA_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_CONTAINER))
#define RYGEL_IS_MEDIA_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_CONTAINER))
#define RYGEL_MEDIA_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainerClass))

typedef struct _RygelMediaContainer RygelMediaContainer;
typedef struct _RygelMediaContainerClass RygelMediaContainerClass;

#define RYGEL_TYPE_HTTP_REQUEST (rygel_http_request_get_type ())
#define RYGEL_HTTP_REQUEST(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_REQUEST, RygelHTTPRequest))
#define RYGEL_HTTP_REQUEST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_REQUEST, RygelHTTPRequestClass))
#define RYGEL_IS_HTTP_REQUEST(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_REQUEST))
#define RYGEL_IS_HTTP_REQUEST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_REQUEST))
#define RYGEL_HTTP_REQUEST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_REQUEST, RygelHTTPRequestClass))

typedef struct _RygelHTTPRequest RygelHTTPRequest;
typedef struct _RygelHTTPRequestClass RygelHTTPRequestClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define RYGEL_TYPE_CONTENT_DIRECTORY (rygel_content_directory_get_type ())
#define RYGEL_CONTENT_DIRECTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_CONTENT_DIRECTORY, RygelContentDirectory))
#define RYGEL_CONTENT_DIRECTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_CONTENT_DIRECTORY, RygelContentDirectoryClass))
#define RYGEL_IS_CONTENT_DIRECTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_CONTENT_DIRECTORY))
#define RYGEL_IS_CONTENT_DIRECTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_CONTENT_DIRECTORY))
#define RYGEL_CONTENT_DIRECTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_CONTENT_DIRECTORY, RygelContentDirectoryClass))

typedef struct _RygelContentDirectory RygelContentDirectory;
typedef struct _RygelContentDirectoryClass RygelContentDirectoryClass;
typedef struct _RygelContentDirectoryPrivate RygelContentDirectoryPrivate;
typedef struct _RygelMediaObjectPrivate RygelMediaObjectPrivate;
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
typedef struct _RygelIconInfoPrivate RygelIconInfoPrivate;
typedef struct _RygelThumbnailPrivate RygelThumbnailPrivate;
#define _rygel_icon_info_unref0(var) ((var == NULL) ? NULL : (var = (rygel_icon_info_unref (var), NULL)))

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

struct _RygelStateMachineIface {
	GTypeInterface parent_iface;
	void (*run) (RygelStateMachine* self);
	GCancellable* (*get_cancellable) (RygelStateMachine* self);
	void (*set_cancellable) (RygelStateMachine* self, GCancellable* value);
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

struct _RygelHTTPServerPrivate {
	char* path_root;
	GeeArrayList* requests;
	GCancellable* _cancellable;
};

struct _RygelContentDirectory {
	GUPnPService parent_instance;
	RygelContentDirectoryPrivate * priv;
	char* feature_list;
	char* search_caps;
	char* sort_caps;
	RygelHTTPServer* http_server;
	RygelMediaContainer* root_container;
	GCancellable* cancellable;
	guint32 system_update_id;
};

struct _RygelContentDirectoryClass {
	GUPnPServiceClass parent_class;
	RygelMediaContainer* (*create_root_container) (RygelContentDirectory* self);
	void (*browse_cb) (RygelContentDirectory* self, RygelContentDirectory* content_dir, GUPnPServiceAction* action);
};

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

struct _RygelIconInfo {
	GTypeInstance parent_instance;
	volatile int ref_count;
	RygelIconInfoPrivate * priv;
	char* mime_type;
	char* path;
	glong size;
	gint width;
	gint height;
	gint depth;
};

struct _RygelIconInfoClass {
	GTypeClass parent_class;
	void (*finalize) (RygelIconInfo *self);
};

struct _RygelThumbnail {
	RygelIconInfo parent_instance;
	RygelThumbnailPrivate * priv;
	char* uri;
	char* dlna_profile;
};

struct _RygelThumbnailClass {
	RygelIconInfoClass parent_class;
};


static gpointer rygel_http_server_parent_class = NULL;
static RygelStateMachineIface* rygel_http_server_rygel_state_machine_parent_iface = NULL;

GType rygel_transcode_manager_get_type (void);
GType rygel_media_object_get_type (void);
GType rygel_media_item_get_type (void);
GType rygel_state_machine_get_type (void);
GType rygel_http_server_get_type (void);
GType rygel_media_container_get_type (void);
GType rygel_http_request_get_type (void);
#define RYGEL_HTTP_SERVER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_HTTP_SERVER, RygelHTTPServerPrivate))
enum  {
	RYGEL_HTTP_SERVER_DUMMY_PROPERTY,
	RYGEL_HTTP_SERVER_CANCELLABLE
};
#define RYGEL_HTTP_SERVER_SERVER_PATH_PREFIX "/RygelHTTPServer"
RygelTranscodeManager* rygel_transcode_manager_construct (GType object_type, GError** error);
GType rygel_content_directory_get_type (void);
void rygel_state_machine_set_cancellable (RygelStateMachine* self, GCancellable* value);
RygelHTTPServer* rygel_http_server_new (RygelContentDirectory* content_dir, const char* name, GError** error);
RygelHTTPServer* rygel_http_server_construct (GType object_type, RygelContentDirectory* content_dir, const char* name, GError** error);
static void rygel_http_server_server_handler (RygelHTTPServer* self, SoupServer* server, SoupMessage* msg, const char* server_path, GHashTable* query, SoupClientContext* soup_client);
static void _rygel_http_server_server_handler_soup_server_callback (SoupServer* server, SoupMessage* msg, const char* path, GHashTable* query, SoupClientContext* client, gpointer self);
GCancellable* rygel_state_machine_get_cancellable (RygelStateMachine* self);
static void rygel_http_server_on_cancelled (RygelHTTPServer* self, GCancellable* cancellable);
static void _rygel_http_server_on_cancelled_g_cancellable_cancelled (GCancellable* _sender, gpointer self);
static void rygel_http_server_real_run (RygelStateMachine* base);
static gboolean rygel_http_server_http_uri_present (RygelHTTPServer* self, RygelMediaItem* item);
char* rygel_transcode_manager_create_uri_for_item (RygelTranscodeManager* self, RygelMediaItem* item, gint thumbnail_index, const char* transcode_target, char** protocol);
GUPnPDIDLLiteResource* rygel_media_item_add_resource (RygelMediaItem* self, GUPnPDIDLLiteItem* didl_item, const char* uri, const char* protocol, GError** error);
void rygel_transcode_manager_add_resources (RygelTranscodeManager* self, GUPnPDIDLLiteItem* didl_item, RygelMediaItem* item, GError** error);
gpointer rygel_icon_info_ref (gpointer instance);
void rygel_icon_info_unref (gpointer instance);
GParamSpec* rygel_param_spec_icon_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_icon_info (GValue* value, gpointer v_object);
gpointer rygel_value_get_icon_info (const GValue* value);
GType rygel_icon_info_get_type (void);
GType rygel_thumbnail_get_type (void);
static gboolean rygel_http_server_is_http_uri (RygelHTTPServer* self, const char* uri);
GUPnPDIDLLiteResource* rygel_thumbnail_add_resource (RygelThumbnail* self, GUPnPDIDLLiteItem* didl_item, const char* protocol);
static void rygel_http_server_real_add_resources (RygelTranscodeManager* base, GUPnPDIDLLiteItem* didl_item, RygelMediaItem* item, GError** error);
static char* rygel_http_server_create_uri_for_path (RygelHTTPServer* self, const char* path);
static char* rygel_http_server_real_create_uri_for_item (RygelTranscodeManager* base, RygelMediaItem* item, gint thumbnail_index, const char* transcode_target, char** protocol);
static char* rygel_http_server_real_get_protocol (RygelTranscodeManager* base);
char* rygel_transcode_manager_get_protocol (RygelTranscodeManager* self);
char* rygel_transcode_manager_get_protocol_info (RygelTranscodeManager* self);
static char* rygel_http_server_real_get_protocol_info (RygelTranscodeManager* base);
static void rygel_http_server_on_request_completed (RygelHTTPServer* self, RygelHTTPRequest* request);
RygelHTTPRequest* rygel_http_request_new (RygelHTTPServer* http_server, SoupServer* server, SoupMessage* msg, GHashTable* query);
RygelHTTPRequest* rygel_http_request_construct (GType object_type, RygelHTTPServer* http_server, SoupServer* server, SoupMessage* msg, GHashTable* query);
static void _rygel_http_server_on_request_completed_rygel_state_machine_completed (RygelHTTPRequest* _sender, gpointer self);
void rygel_state_machine_run (RygelStateMachine* self);
static void rygel_http_server_finalize (GObject* obj);
static void rygel_http_server_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void rygel_http_server_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static int _vala_strcmp0 (const char * str1, const char * str2);



static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


RygelHTTPServer* rygel_http_server_construct (GType object_type, RygelContentDirectory* content_dir, const char* name, GError** error) {
	RygelHTTPServer * self;
	RygelMediaContainer* _tmp0_;
	GUPnPContext* _tmp1_;
	GeeArrayList* _tmp2_;
	char* _tmp3_;
	g_return_val_if_fail (content_dir != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	self = (RygelHTTPServer*) rygel_transcode_manager_construct (object_type, error);
	self->root_container = (_tmp0_ = _g_object_ref0 (content_dir->root_container), _g_object_unref0 (self->root_container), _tmp0_);
	self->context = (_tmp1_ = _g_object_ref0 (gupnp_service_info_get_context ((GUPnPServiceInfo*) content_dir)), _g_object_unref0 (self->context), _tmp1_);
	rygel_state_machine_set_cancellable ((RygelStateMachine*) self, content_dir->cancellable);
	self->priv->requests = (_tmp2_ = gee_array_list_new (RYGEL_TYPE_HTTP_REQUEST, (GBoxedCopyFunc) g_object_ref, g_object_unref, g_direct_equal), _g_object_unref0 (self->priv->requests), _tmp2_);
	self->priv->path_root = (_tmp3_ = g_strconcat (RYGEL_HTTP_SERVER_SERVER_PATH_PREFIX "/", name, NULL), _g_free0 (self->priv->path_root), _tmp3_);
	return self;
}


RygelHTTPServer* rygel_http_server_new (RygelContentDirectory* content_dir, const char* name, GError** error) {
	return rygel_http_server_construct (RYGEL_TYPE_HTTP_SERVER, content_dir, name, error);
}


static void _rygel_http_server_server_handler_soup_server_callback (SoupServer* server, SoupMessage* msg, const char* path, GHashTable* query, SoupClientContext* client, gpointer self) {
	rygel_http_server_server_handler (self, server, msg, path, query, client);
}


static void _rygel_http_server_on_cancelled_g_cancellable_cancelled (GCancellable* _sender, gpointer self) {
	rygel_http_server_on_cancelled (self, _sender);
}


static void rygel_http_server_real_run (RygelStateMachine* base) {
	RygelHTTPServer * self;
	self = (RygelHTTPServer*) base;
	soup_server_add_handler (gupnp_context_get_server (self->context), self->priv->path_root, _rygel_http_server_server_handler_soup_server_callback, g_object_ref (self), g_object_unref);
	if (rygel_state_machine_get_cancellable ((RygelStateMachine*) self) != NULL) {
		g_signal_connect_object (rygel_state_machine_get_cancellable ((RygelStateMachine*) self), "cancelled", (GCallback) _rygel_http_server_on_cancelled_g_cancellable_cancelled, self, 0);
	}
}


static void rygel_http_server_real_add_resources (RygelTranscodeManager* base, GUPnPDIDLLiteItem* didl_item, RygelMediaItem* item, GError** error) {
	RygelHTTPServer * self;
	GError * _inner_error_;
	self = (RygelHTTPServer*) base;
	g_return_if_fail (didl_item != NULL);
	g_return_if_fail (item != NULL);
	_inner_error_ = NULL;
	if (!rygel_http_server_http_uri_present (self, item)) {
		char* protocol;
		char* _tmp2_;
		char* _tmp1_;
		char* _tmp0_;
		char* uri;
		GUPnPDIDLLiteResource* _tmp3_;
		protocol = NULL;
		_tmp0_ = NULL;
		uri = (_tmp1_ = rygel_transcode_manager_create_uri_for_item ((RygelTranscodeManager*) self, item, -1, NULL, &_tmp0_), protocol = (_tmp2_ = _tmp0_, _g_free0 (protocol), _tmp2_), _tmp1_);
		_tmp3_ = rygel_media_item_add_resource (item, didl_item, uri, protocol, &_inner_error_);
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_g_free0 (protocol);
			_g_free0 (uri);
			return;
		}
		_g_object_unref0 (_tmp3_);
		_g_free0 (protocol);
		_g_free0 (uri);
	}
	RYGEL_TRANSCODE_MANAGER_CLASS (rygel_http_server_parent_class)->add_resources (RYGEL_TRANSCODE_MANAGER (self), didl_item, item, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return;
	}
	{
		GeeIterator* _thumbnail_it;
		_thumbnail_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) item->thumbnails);
		while (TRUE) {
			RygelThumbnail* thumbnail;
			if (!gee_iterator_next (_thumbnail_it)) {
				break;
			}
			thumbnail = (RygelThumbnail*) gee_iterator_get (_thumbnail_it);
			if (!rygel_http_server_is_http_uri (self, thumbnail->uri)) {
				char* uri;
				gint index;
				char* protocol;
				char* _tmp7_;
				char* _tmp6_;
				char* _tmp5_;
				char* _tmp4_;
				GUPnPDIDLLiteResource* _tmp8_;
				char* _tmp9_;
				uri = g_strdup (thumbnail->uri);
				index = gee_abstract_list_index_of ((GeeAbstractList*) item->thumbnails, thumbnail);
				protocol = NULL;
				_tmp4_ = NULL;
				thumbnail->uri = (_tmp7_ = (_tmp5_ = rygel_transcode_manager_create_uri_for_item ((RygelTranscodeManager*) self, item, index, NULL, &_tmp4_), protocol = (_tmp6_ = _tmp4_, _g_free0 (protocol), _tmp6_), _tmp5_), _g_free0 (thumbnail->uri), _tmp7_);
				_tmp8_ = rygel_thumbnail_add_resource (thumbnail, didl_item, protocol);
				_g_object_unref0 (_tmp8_);
				thumbnail->uri = (_tmp9_ = g_strdup (uri), _g_free0 (thumbnail->uri), _tmp9_);
				_g_free0 (uri);
				_g_free0 (protocol);
			}
			_rygel_icon_info_unref0 (thumbnail);
		}
		_g_object_unref0 (_thumbnail_it);
	}
}


static gboolean rygel_http_server_http_uri_present (RygelHTTPServer* self, RygelMediaItem* item) {
	gboolean result;
	gboolean present;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (item != NULL, FALSE);
	present = FALSE;
	{
		GeeIterator* _uri_it;
		_uri_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) ((RygelMediaObject*) item)->uris);
		while (TRUE) {
			char* uri;
			if (!gee_iterator_next (_uri_it)) {
				break;
			}
			uri = (char*) gee_iterator_get (_uri_it);
			if (rygel_http_server_is_http_uri (self, uri)) {
				present = TRUE;
				_g_free0 (uri);
				break;
			}
			_g_free0 (uri);
		}
		_g_object_unref0 (_uri_it);
	}
	result = present;
	return result;
}


static gboolean rygel_http_server_is_http_uri (RygelHTTPServer* self, const char* uri) {
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (uri != NULL, FALSE);
	result = g_str_has_prefix (uri, "http:");
	return result;
}


static void rygel_http_server_on_cancelled (RygelHTTPServer* self, GCancellable* cancellable) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (cancellable != NULL);
	g_cancellable_cancel (rygel_state_machine_get_cancellable ((RygelStateMachine*) self));
	soup_server_remove_handler (gupnp_context_get_server (self->context), self->priv->path_root);
	g_signal_emit_by_name ((RygelStateMachine*) self, "completed");
}


static char* rygel_http_server_create_uri_for_path (RygelHTTPServer* self, const char* path) {
	char* result;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (path != NULL, NULL);
	result = g_strdup_printf ("http://%s:%u%s%s", gssdp_client_get_host_ip ((GSSDPClient*) self->context), gupnp_context_get_port (self->context), self->priv->path_root, path);
	return result;
}


static char* rygel_http_server_real_create_uri_for_item (RygelTranscodeManager* base, RygelMediaItem* item, gint thumbnail_index, const char* transcode_target, char** protocol) {
	RygelHTTPServer * self;
	char* result;
	char* escaped;
	char* query;
	char* _tmp6_;
	self = (RygelHTTPServer*) base;
	g_return_val_if_fail (item != NULL, NULL);
	if (protocol != NULL) {
		*protocol = NULL;
	}
	escaped = g_uri_escape_string (((RygelMediaObject*) item)->id, "", TRUE);
	query = g_strconcat ("?itemid=", escaped, NULL);
	if (thumbnail_index >= 0) {
		char* _tmp2_;
		char* _tmp1_;
		char* _tmp0_;
		query = (_tmp2_ = g_strconcat (query, _tmp1_ = g_strconcat ("&thumbnail=", _tmp0_ = g_strdup_printf ("%i", thumbnail_index), NULL), NULL), _g_free0 (query), _tmp2_);
		_g_free0 (_tmp1_);
		_g_free0 (_tmp0_);
	}
	if (transcode_target != NULL) {
		char* _tmp3_;
		char* _tmp5_;
		char* _tmp4_;
		escaped = (_tmp3_ = g_uri_escape_string (transcode_target, "", TRUE), _g_free0 (escaped), _tmp3_);
		query = (_tmp5_ = g_strconcat (query, _tmp4_ = g_strconcat ("&transcode=", escaped, NULL), NULL), _g_free0 (query), _tmp5_);
		_g_free0 (_tmp4_);
	}
	(*protocol) = (_tmp6_ = g_strdup ("http-get"), _g_free0 ((*protocol)), _tmp6_);
	result = rygel_http_server_create_uri_for_path (self, query);
	_g_free0 (escaped);
	_g_free0 (query);
	return result;
}


static char* rygel_http_server_real_get_protocol (RygelTranscodeManager* base) {
	RygelHTTPServer * self;
	char* result;
	self = (RygelHTTPServer*) base;
	result = g_strdup ("http-get");
	return result;
}


static char* rygel_http_server_real_get_protocol_info (RygelTranscodeManager* base) {
	RygelHTTPServer * self;
	char* result;
	char* _tmp0_;
	char* _tmp1_;
	char* protocol_info;
	char* base_info;
	self = (RygelHTTPServer*) base;
	protocol_info = (_tmp1_ = g_strconcat (_tmp0_ = rygel_transcode_manager_get_protocol ((RygelTranscodeManager*) self), ":*:*:*", NULL), _g_free0 (_tmp0_), _tmp1_);
	base_info = RYGEL_TRANSCODE_MANAGER_CLASS (rygel_http_server_parent_class)->get_protocol_info (RYGEL_TRANSCODE_MANAGER (self));
	if (_vala_strcmp0 (base_info, "") != 0) {
		char* _tmp3_;
		char* _tmp2_;
		protocol_info = (_tmp3_ = g_strconcat (protocol_info, _tmp2_ = g_strconcat (",", base_info, NULL), NULL), _g_free0 (protocol_info), _tmp3_);
		_g_free0 (_tmp2_);
	}
	result = protocol_info;
	_g_free0 (base_info);
	return result;
}


static void rygel_http_server_on_request_completed (RygelHTTPServer* self, RygelHTTPRequest* request) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (request != NULL);
	gee_abstract_collection_remove ((GeeAbstractCollection*) self->priv->requests, request);
}


static void _rygel_http_server_on_request_completed_rygel_state_machine_completed (RygelHTTPRequest* _sender, gpointer self) {
	rygel_http_server_on_request_completed (self, _sender);
}


static void rygel_http_server_server_handler (RygelHTTPServer* self, SoupServer* server, SoupMessage* msg, const char* server_path, GHashTable* query, SoupClientContext* soup_client) {
	char* _tmp2_;
	char* _tmp1_;
	char* _tmp0_;
	RygelHTTPRequest* request;
	g_return_if_fail (self != NULL);
	g_return_if_fail (server != NULL);
	g_return_if_fail (msg != NULL);
	g_return_if_fail (server_path != NULL);
	g_return_if_fail (soup_client != NULL);
	_tmp0_ = NULL;
	g_debug ("rygel-http-server.vala:173: HTTP %s request for URI: %s", _tmp1_ = (g_object_get (msg, "method", &_tmp0_, NULL), _tmp0_), _tmp2_ = soup_uri_to_string (soup_message_get_uri (msg), FALSE));
	_g_free0 (_tmp2_);
	_g_free0 (_tmp1_);
	request = rygel_http_request_new (self, server, msg, query);
	g_signal_connect_object ((RygelStateMachine*) request, "completed", (GCallback) _rygel_http_server_on_request_completed_rygel_state_machine_completed, self, 0);
	gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->requests, request);
	rygel_state_machine_run ((RygelStateMachine*) request);
	_g_object_unref0 (request);
}


static GCancellable* rygel_http_server_real_get_cancellable (RygelStateMachine* base) {
	GCancellable* result;
	RygelHTTPServer* self;
	self = (RygelHTTPServer*) base;
	result = self->priv->_cancellable;
	return result;
}


static void rygel_http_server_real_set_cancellable (RygelStateMachine* base, GCancellable* value) {
	RygelHTTPServer* self;
	GCancellable* _tmp0_;
	self = (RygelHTTPServer*) base;
	self->priv->_cancellable = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_cancellable), _tmp0_);
	g_object_notify ((GObject *) self, "cancellable");
}


static void rygel_http_server_class_init (RygelHTTPServerClass * klass) {
	rygel_http_server_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelHTTPServerPrivate));
	RYGEL_TRANSCODE_MANAGER_CLASS (klass)->add_resources = rygel_http_server_real_add_resources;
	RYGEL_TRANSCODE_MANAGER_CLASS (klass)->create_uri_for_item = rygel_http_server_real_create_uri_for_item;
	RYGEL_TRANSCODE_MANAGER_CLASS (klass)->get_protocol = rygel_http_server_real_get_protocol;
	RYGEL_TRANSCODE_MANAGER_CLASS (klass)->get_protocol_info = rygel_http_server_real_get_protocol_info;
	G_OBJECT_CLASS (klass)->get_property = rygel_http_server_get_property;
	G_OBJECT_CLASS (klass)->set_property = rygel_http_server_set_property;
	G_OBJECT_CLASS (klass)->finalize = rygel_http_server_finalize;
	g_object_class_override_property (G_OBJECT_CLASS (klass), RYGEL_HTTP_SERVER_CANCELLABLE, "cancellable");
}


static void rygel_http_server_rygel_state_machine_interface_init (RygelStateMachineIface * iface) {
	rygel_http_server_rygel_state_machine_parent_iface = g_type_interface_peek_parent (iface);
	iface->run = rygel_http_server_real_run;
	iface->get_cancellable = rygel_http_server_real_get_cancellable;
	iface->set_cancellable = rygel_http_server_real_set_cancellable;
}


static void rygel_http_server_instance_init (RygelHTTPServer * self) {
	self->priv = RYGEL_HTTP_SERVER_GET_PRIVATE (self);
}


static void rygel_http_server_finalize (GObject* obj) {
	RygelHTTPServer * self;
	self = RYGEL_HTTP_SERVER (obj);
	_g_free0 (self->priv->path_root);
	_g_object_unref0 (self->root_container);
	_g_object_unref0 (self->context);
	_g_object_unref0 (self->priv->requests);
	_g_object_unref0 (self->priv->_cancellable);
	G_OBJECT_CLASS (rygel_http_server_parent_class)->finalize (obj);
}


GType rygel_http_server_get_type (void) {
	static GType rygel_http_server_type_id = 0;
	if (rygel_http_server_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelHTTPServerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_http_server_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelHTTPServer), 0, (GInstanceInitFunc) rygel_http_server_instance_init, NULL };
		static const GInterfaceInfo rygel_state_machine_info = { (GInterfaceInitFunc) rygel_http_server_rygel_state_machine_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		rygel_http_server_type_id = g_type_register_static (RYGEL_TYPE_TRANSCODE_MANAGER, "RygelHTTPServer", &g_define_type_info, 0);
		g_type_add_interface_static (rygel_http_server_type_id, RYGEL_TYPE_STATE_MACHINE, &rygel_state_machine_info);
	}
	return rygel_http_server_type_id;
}


static void rygel_http_server_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	RygelHTTPServer * self;
	self = RYGEL_HTTP_SERVER (object);
	switch (property_id) {
		case RYGEL_HTTP_SERVER_CANCELLABLE:
		g_value_set_object (value, rygel_state_machine_get_cancellable ((RygelStateMachine*) self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void rygel_http_server_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	RygelHTTPServer * self;
	self = RYGEL_HTTP_SERVER (object);
	switch (property_id) {
		case RYGEL_HTTP_SERVER_CANCELLABLE:
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




