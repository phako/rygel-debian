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
#include <libgupnp-av/gupnp-av.h>
#include <stdlib.h>
#include <string.h>
#include <gee.h>
#include <gst/gst.h>
#include <gio/gio.h>
#include <libgupnp/gupnp.h>
#include <libgssdp/gssdp.h>


#define RYGEL_TYPE_DIDL_LITE_WRITER (rygel_didl_lite_writer_get_type ())
#define RYGEL_DIDL_LITE_WRITER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_DIDL_LITE_WRITER, RygelDIDLLiteWriter))
#define RYGEL_DIDL_LITE_WRITER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_DIDL_LITE_WRITER, RygelDIDLLiteWriterClass))
#define RYGEL_IS_DIDL_LITE_WRITER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_DIDL_LITE_WRITER))
#define RYGEL_IS_DIDL_LITE_WRITER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_DIDL_LITE_WRITER))
#define RYGEL_DIDL_LITE_WRITER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_DIDL_LITE_WRITER, RygelDIDLLiteWriterClass))

typedef struct _RygelDIDLLiteWriter RygelDIDLLiteWriter;
typedef struct _RygelDIDLLiteWriterClass RygelDIDLLiteWriterClass;
typedef struct _RygelDIDLLiteWriterPrivate RygelDIDLLiteWriterPrivate;

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
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

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

#define RYGEL_TYPE_MEDIA_CONTAINER (rygel_media_container_get_type ())
#define RYGEL_MEDIA_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainer))
#define RYGEL_MEDIA_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainerClass))
#define RYGEL_IS_MEDIA_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_CONTAINER))
#define RYGEL_IS_MEDIA_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_CONTAINER))
#define RYGEL_MEDIA_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainerClass))

typedef struct _RygelMediaContainer RygelMediaContainer;
typedef struct _RygelMediaContainerClass RygelMediaContainerClass;
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
typedef struct _RygelTranscodeManagerPrivate RygelTranscodeManagerPrivate;

#define RYGEL_TYPE_STATE_MACHINE (rygel_state_machine_get_type ())
#define RYGEL_STATE_MACHINE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_STATE_MACHINE, RygelStateMachine))
#define RYGEL_IS_STATE_MACHINE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_STATE_MACHINE))
#define RYGEL_STATE_MACHINE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), RYGEL_TYPE_STATE_MACHINE, RygelStateMachineIface))

typedef struct _RygelStateMachine RygelStateMachine;
typedef struct _RygelStateMachineIface RygelStateMachineIface;
typedef struct _RygelHTTPServerPrivate RygelHTTPServerPrivate;
typedef struct _RygelMediaContainerPrivate RygelMediaContainerPrivate;

typedef enum  {
	RYGEL_DIDL_LITE_WRITER_ERROR_UNSUPPORTED_OBJECT
} RygelDIDLLiteWriterError;
#define RYGEL_DIDL_LITE_WRITER_ERROR rygel_didl_lite_writer_error_quark ()
struct _RygelDIDLLiteWriter {
	GUPnPDIDLLiteWriter parent_instance;
	RygelDIDLLiteWriterPrivate * priv;
};

struct _RygelDIDLLiteWriterClass {
	GUPnPDIDLLiteWriterClass parent_class;
};

struct _RygelDIDLLiteWriterPrivate {
	RygelHTTPServer* http_server;
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

struct _RygelMediaContainer {
	RygelMediaObject parent_instance;
	RygelMediaContainerPrivate * priv;
	guint child_count;
	guint32 update_id;
};

struct _RygelMediaContainerClass {
	RygelMediaObjectClass parent_class;
	void (*get_children) (RygelMediaContainer* self, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target);
	GeeList* (*get_children_finish) (RygelMediaContainer* self, GAsyncResult* res, GError** error);
	void (*find_object) (RygelMediaContainer* self, const char* id, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target);
	RygelMediaObject* (*find_object_finish) (RygelMediaContainer* self, GAsyncResult* res, GError** error);
};


static gpointer rygel_didl_lite_writer_parent_class = NULL;

GQuark rygel_didl_lite_writer_error_quark (void);
GType rygel_didl_lite_writer_get_type (void);
GType rygel_transcode_manager_get_type (void);
GType rygel_http_server_get_type (void);
#define RYGEL_DIDL_LITE_WRITER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_DIDL_LITE_WRITER, RygelDIDLLiteWriterPrivate))
enum  {
	RYGEL_DIDL_LITE_WRITER_DUMMY_PROPERTY
};
RygelDIDLLiteWriter* rygel_didl_lite_writer_new (RygelHTTPServer* http_server);
RygelDIDLLiteWriter* rygel_didl_lite_writer_construct (GType object_type, RygelHTTPServer* http_server);
GType rygel_media_object_get_type (void);
GType rygel_media_item_get_type (void);
static void rygel_didl_lite_writer_serialize_item (RygelDIDLLiteWriter* self, RygelMediaItem* item, GError** error);
GType rygel_media_container_get_type (void);
static void rygel_didl_lite_writer_serialize_container (RygelDIDLLiteWriter* self, RygelMediaContainer* container, GError** error);
void rygel_didl_lite_writer_serialize (RygelDIDLLiteWriter* self, RygelMediaObject* media_object, GError** error);
gpointer rygel_icon_info_ref (gpointer instance);
void rygel_icon_info_unref (gpointer instance);
GParamSpec* rygel_param_spec_icon_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_icon_info (GValue* value, gpointer v_object);
gpointer rygel_value_get_icon_info (const GValue* value);
GType rygel_icon_info_get_type (void);
GType rygel_thumbnail_get_type (void);
#define RYGEL_MEDIA_ITEM_VIDEO_CLASS "object.item.videoItem"
#define RYGEL_MEDIA_ITEM_MUSIC_CLASS "object.item.audioItem.musicTrack"
void rygel_transcode_manager_add_resources (RygelTranscodeManager* self, GUPnPDIDLLiteItem* didl_item, RygelMediaItem* item, GError** error);
GType rygel_state_machine_get_type (void);
void rygel_media_item_add_resources (RygelMediaItem* self, GUPnPDIDLLiteItem* didl_item, gboolean allow_internal, GError** error);
static void rygel_didl_lite_writer_finalize (GObject* obj);
static int _vala_strcmp0 (const char * str1, const char * str2);



GQuark rygel_didl_lite_writer_error_quark (void) {
	return g_quark_from_static_string ("rygel_didl_lite_writer_error-quark");
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


RygelDIDLLiteWriter* rygel_didl_lite_writer_construct (GType object_type, RygelHTTPServer* http_server) {
	RygelDIDLLiteWriter * self;
	RygelHTTPServer* _tmp0_;
	g_return_val_if_fail (http_server != NULL, NULL);
	self = g_object_newv (object_type, 0, NULL);
	self->priv->http_server = (_tmp0_ = _g_object_ref0 (http_server), _g_object_unref0 (self->priv->http_server), _tmp0_);
	return self;
}


RygelDIDLLiteWriter* rygel_didl_lite_writer_new (RygelHTTPServer* http_server) {
	return rygel_didl_lite_writer_construct (RYGEL_TYPE_DIDL_LITE_WRITER, http_server);
}


void rygel_didl_lite_writer_serialize (RygelDIDLLiteWriter* self, RygelMediaObject* media_object, GError** error) {
	GError * _inner_error_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (media_object != NULL);
	_inner_error_ = NULL;
	if (RYGEL_IS_MEDIA_ITEM (media_object)) {
		rygel_didl_lite_writer_serialize_item (self, RYGEL_MEDIA_ITEM (media_object), &_inner_error_);
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			return;
		}
	} else {
		if (RYGEL_IS_MEDIA_CONTAINER (media_object)) {
			rygel_didl_lite_writer_serialize_container (self, RYGEL_MEDIA_CONTAINER (media_object), &_inner_error_);
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				return;
			}
		} else {
			_inner_error_ = g_error_new_literal (RYGEL_DIDL_LITE_WRITER_ERROR, RYGEL_DIDL_LITE_WRITER_ERROR_UNSUPPORTED_OBJECT, "Unable to serialize unsupported object");
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				return;
			}
		}
	}
}


static void rygel_didl_lite_writer_serialize_item (RygelDIDLLiteWriter* self, RygelMediaItem* item, GError** error) {
	GError * _inner_error_;
	GUPnPDIDLLiteItem* didl_item;
	gboolean _tmp0_;
	gboolean _tmp1_;
	gboolean _tmp2_;
	gboolean _tmp3_;
	gboolean internal_allowed;
	g_return_if_fail (self != NULL);
	g_return_if_fail (item != NULL);
	_inner_error_ = NULL;
	didl_item = gupnp_didl_lite_writer_add_item ((GUPnPDIDLLiteWriter*) self);
	gupnp_didl_lite_object_set_id ((GUPnPDIDLLiteObject*) didl_item, ((RygelMediaObject*) item)->id);
	if (((RygelMediaObject*) item)->parent != NULL) {
		gupnp_didl_lite_object_set_parent_id ((GUPnPDIDLLiteObject*) didl_item, ((RygelMediaObject*) ((RygelMediaObject*) item)->parent)->id);
	} else {
		gupnp_didl_lite_object_set_parent_id ((GUPnPDIDLLiteObject*) didl_item, "0");
	}
	gupnp_didl_lite_object_set_restricted ((GUPnPDIDLLiteObject*) didl_item, FALSE);
	gupnp_didl_lite_object_set_title ((GUPnPDIDLLiteObject*) didl_item, ((RygelMediaObject*) item)->title);
	gupnp_didl_lite_object_set_upnp_class ((GUPnPDIDLLiteObject*) didl_item, item->upnp_class);
	_tmp0_ = FALSE;
	if (item->author != NULL) {
		_tmp0_ = _vala_strcmp0 (item->author, "") != 0;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		gupnp_didl_lite_object_set_creator ((GUPnPDIDLLiteObject*) didl_item, item->author);
		if (g_str_has_prefix (item->upnp_class, RYGEL_MEDIA_ITEM_VIDEO_CLASS)) {
			gupnp_didl_lite_object_set_author ((GUPnPDIDLLiteObject*) didl_item, item->author);
		} else {
			if (g_str_has_prefix (item->upnp_class, RYGEL_MEDIA_ITEM_MUSIC_CLASS)) {
				gupnp_didl_lite_object_set_artist ((GUPnPDIDLLiteObject*) didl_item, item->author);
			}
		}
	}
	if (item->track_number >= 0) {
		gupnp_didl_lite_object_set_track_number ((GUPnPDIDLLiteObject*) didl_item, item->track_number);
	}
	_tmp1_ = FALSE;
	if (item->album != NULL) {
		_tmp1_ = _vala_strcmp0 (item->album, "") != 0;
	} else {
		_tmp1_ = FALSE;
	}
	if (_tmp1_) {
		gupnp_didl_lite_object_set_album ((GUPnPDIDLLiteObject*) didl_item, item->album);
	}
	_tmp2_ = FALSE;
	if (item->date != NULL) {
		_tmp2_ = _vala_strcmp0 (item->date, "") != 0;
	} else {
		_tmp2_ = FALSE;
	}
	if (_tmp2_) {
		gupnp_didl_lite_object_set_date ((GUPnPDIDLLiteObject*) didl_item, item->date);
	}
	rygel_transcode_manager_add_resources ((RygelTranscodeManager*) self->priv->http_server, didl_item, item, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_g_object_unref0 (didl_item);
		return;
	}
	_tmp3_ = FALSE;
	if (_vala_strcmp0 (gssdp_client_get_interface ((GSSDPClient*) self->priv->http_server->context), "lo") == 0) {
		_tmp3_ = TRUE;
	} else {
		_tmp3_ = _vala_strcmp0 (gssdp_client_get_host_ip ((GSSDPClient*) self->priv->http_server->context), "127.0.0.1") == 0;
	}
	internal_allowed = _tmp3_;
	rygel_media_item_add_resources (item, didl_item, internal_allowed, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_g_object_unref0 (didl_item);
		return;
	}
	_g_object_unref0 (didl_item);
}


static void rygel_didl_lite_writer_serialize_container (RygelDIDLLiteWriter* self, RygelMediaContainer* container, GError** error) {
	GUPnPDIDLLiteContainer* didl_container;
	g_return_if_fail (self != NULL);
	g_return_if_fail (container != NULL);
	didl_container = gupnp_didl_lite_writer_add_container ((GUPnPDIDLLiteWriter*) self);
	if (((RygelMediaObject*) container)->parent != NULL) {
		gupnp_didl_lite_object_set_parent_id ((GUPnPDIDLLiteObject*) didl_container, ((RygelMediaObject*) ((RygelMediaObject*) container)->parent)->id);
	} else {
		gupnp_didl_lite_object_set_parent_id ((GUPnPDIDLLiteObject*) didl_container, "-1");
	}
	gupnp_didl_lite_object_set_id ((GUPnPDIDLLiteObject*) didl_container, ((RygelMediaObject*) container)->id);
	gupnp_didl_lite_object_set_title ((GUPnPDIDLLiteObject*) didl_container, ((RygelMediaObject*) container)->title);
	gupnp_didl_lite_container_set_child_count (didl_container, container->child_count);
	gupnp_didl_lite_object_set_restricted ((GUPnPDIDLLiteObject*) didl_container, FALSE);
	gupnp_didl_lite_container_set_searchable (didl_container, FALSE);
	gupnp_didl_lite_object_set_upnp_class ((GUPnPDIDLLiteObject*) didl_container, "object.container.storageFolder");
	_g_object_unref0 (didl_container);
}


static void rygel_didl_lite_writer_class_init (RygelDIDLLiteWriterClass * klass) {
	rygel_didl_lite_writer_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelDIDLLiteWriterPrivate));
	G_OBJECT_CLASS (klass)->finalize = rygel_didl_lite_writer_finalize;
}


static void rygel_didl_lite_writer_instance_init (RygelDIDLLiteWriter * self) {
	self->priv = RYGEL_DIDL_LITE_WRITER_GET_PRIVATE (self);
}


static void rygel_didl_lite_writer_finalize (GObject* obj) {
	RygelDIDLLiteWriter * self;
	self = RYGEL_DIDL_LITE_WRITER (obj);
	_g_object_unref0 (self->priv->http_server);
	G_OBJECT_CLASS (rygel_didl_lite_writer_parent_class)->finalize (obj);
}


GType rygel_didl_lite_writer_get_type (void) {
	static GType rygel_didl_lite_writer_type_id = 0;
	if (rygel_didl_lite_writer_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelDIDLLiteWriterClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_didl_lite_writer_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelDIDLLiteWriter), 0, (GInstanceInitFunc) rygel_didl_lite_writer_instance_init, NULL };
		rygel_didl_lite_writer_type_id = g_type_register_static (GUPNP_TYPE_DIDL_LITE_WRITER, "RygelDIDLLiteWriter", &g_define_type_info, 0);
	}
	return rygel_didl_lite_writer_type_id;
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




