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
#include <gst/gst.h>
#include <libgupnp-av/gupnp-av.h>
#include <stdlib.h>
#include <string.h>
#include <gee.h>
#include <gio/gio.h>


#define RYGEL_TYPE_TRANSCODER (rygel_transcoder_get_type ())
#define RYGEL_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRANSCODER, RygelTranscoder))
#define RYGEL_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRANSCODER, RygelTranscoderClass))
#define RYGEL_IS_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRANSCODER))
#define RYGEL_IS_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRANSCODER))
#define RYGEL_TRANSCODER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRANSCODER, RygelTranscoderClass))

typedef struct _RygelTranscoder RygelTranscoder;
typedef struct _RygelTranscoderClass RygelTranscoderClass;
typedef struct _RygelTranscoderPrivate RygelTranscoderPrivate;

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

#define RYGEL_TYPE_TRANSCODE_MANAGER (rygel_transcode_manager_get_type ())
#define RYGEL_TRANSCODE_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRANSCODE_MANAGER, RygelTranscodeManager))
#define RYGEL_TRANSCODE_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRANSCODE_MANAGER, RygelTranscodeManagerClass))
#define RYGEL_IS_TRANSCODE_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRANSCODE_MANAGER))
#define RYGEL_IS_TRANSCODE_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRANSCODE_MANAGER))
#define RYGEL_TRANSCODE_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRANSCODE_MANAGER, RygelTranscodeManagerClass))

typedef struct _RygelTranscodeManager RygelTranscodeManager;
typedef struct _RygelTranscodeManagerClass RygelTranscodeManagerClass;
#define _g_free0(var) (var = (g_free (var), NULL))
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
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _RygelTranscoder {
	GObject parent_instance;
	RygelTranscoderPrivate * priv;
};

struct _RygelTranscoderClass {
	GObjectClass parent_class;
	GstElement* (*create_source) (RygelTranscoder* self, RygelMediaItem* item, GstElement* src, GError** error);
	GUPnPDIDLLiteResource* (*add_resource) (RygelTranscoder* self, GUPnPDIDLLiteItem* didl_item, RygelMediaItem* item, RygelTranscodeManager* manager, GError** error);
	guint (*get_distance) (RygelTranscoder* self, RygelMediaItem* item);
};

struct _RygelTranscoderPrivate {
	char* _mime_type;
	char* _dlna_profile;
	char* _upnp_class;
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


static gpointer rygel_transcoder_parent_class = NULL;

GType rygel_transcoder_get_type (void);
GType rygel_media_object_get_type (void);
GType rygel_media_item_get_type (void);
GType rygel_transcode_manager_get_type (void);
#define RYGEL_TRANSCODER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_TRANSCODER, RygelTranscoderPrivate))
enum  {
	RYGEL_TRANSCODER_DUMMY_PROPERTY,
	RYGEL_TRANSCODER_MIME_TYPE,
	RYGEL_TRANSCODER_DLNA_PROFILE,
	RYGEL_TRANSCODER_UPNP_CLASS
};
void rygel_transcoder_set_mime_type (RygelTranscoder* self, const char* value);
void rygel_transcoder_set_dlna_profile (RygelTranscoder* self, const char* value);
void rygel_transcoder_set_upnp_class (RygelTranscoder* self, const char* value);
RygelTranscoder* rygel_transcoder_construct (GType object_type, const char* mime_type, const char* dlna_profile, const char* upnp_class);
GstElement* rygel_transcoder_create_source (RygelTranscoder* self, RygelMediaItem* item, GstElement* src, GError** error);
static GstElement* rygel_transcoder_real_create_source (RygelTranscoder* self, RygelMediaItem* item, GstElement* src, GError** error);
gboolean rygel_transcoder_mime_type_is_a (RygelTranscoder* self, const char* mime_type1, const char* mime_type2);
GType rygel_media_container_get_type (void);
gpointer rygel_icon_info_ref (gpointer instance);
void rygel_icon_info_unref (gpointer instance);
GParamSpec* rygel_param_spec_icon_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_icon_info (GValue* value, gpointer v_object);
gpointer rygel_value_get_icon_info (const GValue* value);
GType rygel_icon_info_get_type (void);
GType rygel_thumbnail_get_type (void);
const char* rygel_transcoder_get_mime_type (RygelTranscoder* self);
char* rygel_transcode_manager_create_uri_for_item (RygelTranscodeManager* self, RygelMediaItem* item, gint thumbnail_index, const char* transcode_target, char** protocol);
const char* rygel_transcoder_get_dlna_profile (RygelTranscoder* self);
GUPnPDIDLLiteResource* rygel_media_item_add_resource (RygelMediaItem* self, GUPnPDIDLLiteItem* didl_item, const char* uri, const char* protocol, GError** error);
GUPnPDIDLLiteResource* rygel_transcoder_add_resource (RygelTranscoder* self, GUPnPDIDLLiteItem* didl_item, RygelMediaItem* item, RygelTranscodeManager* manager, GError** error);
static GUPnPDIDLLiteResource* rygel_transcoder_real_add_resource (RygelTranscoder* self, GUPnPDIDLLiteItem* didl_item, RygelMediaItem* item, RygelTranscodeManager* manager, GError** error);
gboolean rygel_transcoder_can_handle (RygelTranscoder* self, const char* target);
guint rygel_transcoder_get_distance (RygelTranscoder* self, RygelMediaItem* item);
static guint rygel_transcoder_real_get_distance (RygelTranscoder* self, RygelMediaItem* item);
const char* rygel_transcoder_get_upnp_class (RygelTranscoder* self);
static void rygel_transcoder_finalize (GObject* obj);
static void rygel_transcoder_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void rygel_transcoder_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static int _vala_strcmp0 (const char * str1, const char * str2);



RygelTranscoder* rygel_transcoder_construct (GType object_type, const char* mime_type, const char* dlna_profile, const char* upnp_class) {
	RygelTranscoder * self;
	g_return_val_if_fail (mime_type != NULL, NULL);
	g_return_val_if_fail (dlna_profile != NULL, NULL);
	g_return_val_if_fail (upnp_class != NULL, NULL);
	self = (RygelTranscoder*) g_object_new (object_type, NULL);
	rygel_transcoder_set_mime_type (self, mime_type);
	rygel_transcoder_set_dlna_profile (self, dlna_profile);
	rygel_transcoder_set_upnp_class (self, upnp_class);
	return self;
}


static GstElement* rygel_transcoder_real_create_source (RygelTranscoder* self, RygelMediaItem* item, GstElement* src, GError** error) {
	g_return_val_if_fail (self != NULL, NULL);
	g_critical ("Type `%s' does not implement abstract method `rygel_transcoder_create_source'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}


GstElement* rygel_transcoder_create_source (RygelTranscoder* self, RygelMediaItem* item, GstElement* src, GError** error) {
	return RYGEL_TRANSCODER_GET_CLASS (self)->create_source (self, item, src, error);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static GUPnPDIDLLiteResource* rygel_transcoder_real_add_resource (RygelTranscoder* self, GUPnPDIDLLiteItem* didl_item, RygelMediaItem* item, RygelTranscodeManager* manager, GError** error) {
	GUPnPDIDLLiteResource* result;
	GError * _inner_error_;
	char* protocol;
	char* _tmp2_;
	char* _tmp1_;
	char* _tmp0_;
	char* uri;
	GUPnPDIDLLiteResource* res;
	GUPnPProtocolInfo* protocol_info;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (didl_item != NULL, NULL);
	g_return_val_if_fail (item != NULL, NULL);
	g_return_val_if_fail (manager != NULL, NULL);
	_inner_error_ = NULL;
	if (rygel_transcoder_mime_type_is_a (self, item->mime_type, self->priv->_mime_type)) {
		result = NULL;
		return result;
	}
	protocol = NULL;
	_tmp0_ = NULL;
	uri = (_tmp1_ = rygel_transcode_manager_create_uri_for_item (manager, item, -1, self->priv->_dlna_profile, &_tmp0_), protocol = (_tmp2_ = _tmp0_, _g_free0 (protocol), _tmp2_), _tmp1_);
	res = rygel_media_item_add_resource (item, didl_item, uri, protocol, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_g_free0 (protocol);
		_g_free0 (uri);
		return NULL;
	}
	gupnp_didl_lite_resource_set_size (res, (glong) (-1));
	protocol_info = _g_object_ref0 (gupnp_didl_lite_resource_get_protocol_info (res));
	gupnp_protocol_info_set_mime_type (protocol_info, self->priv->_mime_type);
	gupnp_protocol_info_set_dlna_profile (protocol_info, self->priv->_dlna_profile);
	gupnp_protocol_info_set_dlna_conversion (protocol_info, GUPNP_DLNA_CONVERSION_TRANSCODED);
	gupnp_protocol_info_set_dlna_flags (protocol_info, GUPNP_DLNA_FLAGS_STREAMING_TRANSFER_MODE);
	gupnp_protocol_info_set_dlna_operation (protocol_info, GUPNP_DLNA_OPERATION_TIMESEEK);
	result = res;
	_g_free0 (protocol);
	_g_free0 (uri);
	_g_object_unref0 (protocol_info);
	return result;
}


GUPnPDIDLLiteResource* rygel_transcoder_add_resource (RygelTranscoder* self, GUPnPDIDLLiteItem* didl_item, RygelMediaItem* item, RygelTranscodeManager* manager, GError** error) {
	return RYGEL_TRANSCODER_GET_CLASS (self)->add_resource (self, didl_item, item, manager, error);
}


gboolean rygel_transcoder_can_handle (RygelTranscoder* self, const char* target) {
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (target != NULL, FALSE);
	result = _vala_strcmp0 (target, self->priv->_dlna_profile) == 0;
	return result;
}


static guint rygel_transcoder_real_get_distance (RygelTranscoder* self, RygelMediaItem* item) {
	g_return_val_if_fail (self != NULL, 0U);
	g_critical ("Type `%s' does not implement abstract method `rygel_transcoder_get_distance'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return 0U;
}


guint rygel_transcoder_get_distance (RygelTranscoder* self, RygelMediaItem* item) {
	return RYGEL_TRANSCODER_GET_CLASS (self)->get_distance (self, item);
}


gboolean rygel_transcoder_mime_type_is_a (RygelTranscoder* self, const char* mime_type1, const char* mime_type2) {
	gboolean result;
	char* content_type1;
	char* content_type2;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (mime_type1 != NULL, FALSE);
	g_return_val_if_fail (mime_type2 != NULL, FALSE);
	content_type1 = g_strdup (g_content_type_from_mime_type (mime_type1));
	content_type2 = g_strdup (g_content_type_from_mime_type (mime_type2));
	result = g_content_type_is_a (content_type1, content_type2);
	_g_free0 (content_type1);
	_g_free0 (content_type2);
	return result;
}


const char* rygel_transcoder_get_mime_type (RygelTranscoder* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_mime_type;
	return result;
}


void rygel_transcoder_set_mime_type (RygelTranscoder* self, const char* value) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_mime_type = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_mime_type), _tmp0_);
	g_object_notify ((GObject *) self, "mime-type");
}


const char* rygel_transcoder_get_dlna_profile (RygelTranscoder* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_dlna_profile;
	return result;
}


void rygel_transcoder_set_dlna_profile (RygelTranscoder* self, const char* value) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_dlna_profile = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_dlna_profile), _tmp0_);
	g_object_notify ((GObject *) self, "dlna-profile");
}


const char* rygel_transcoder_get_upnp_class (RygelTranscoder* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_upnp_class;
	return result;
}


void rygel_transcoder_set_upnp_class (RygelTranscoder* self, const char* value) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_upnp_class = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_upnp_class), _tmp0_);
	g_object_notify ((GObject *) self, "upnp-class");
}


static void rygel_transcoder_class_init (RygelTranscoderClass * klass) {
	rygel_transcoder_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelTranscoderPrivate));
	RYGEL_TRANSCODER_CLASS (klass)->create_source = rygel_transcoder_real_create_source;
	RYGEL_TRANSCODER_CLASS (klass)->add_resource = rygel_transcoder_real_add_resource;
	RYGEL_TRANSCODER_CLASS (klass)->get_distance = rygel_transcoder_real_get_distance;
	G_OBJECT_CLASS (klass)->get_property = rygel_transcoder_get_property;
	G_OBJECT_CLASS (klass)->set_property = rygel_transcoder_set_property;
	G_OBJECT_CLASS (klass)->finalize = rygel_transcoder_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), RYGEL_TRANSCODER_MIME_TYPE, g_param_spec_string ("mime-type", "mime-type", "mime-type", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), RYGEL_TRANSCODER_DLNA_PROFILE, g_param_spec_string ("dlna-profile", "dlna-profile", "dlna-profile", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), RYGEL_TRANSCODER_UPNP_CLASS, g_param_spec_string ("upnp-class", "upnp-class", "upnp-class", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void rygel_transcoder_instance_init (RygelTranscoder * self) {
	self->priv = RYGEL_TRANSCODER_GET_PRIVATE (self);
}


static void rygel_transcoder_finalize (GObject* obj) {
	RygelTranscoder * self;
	self = RYGEL_TRANSCODER (obj);
	_g_free0 (self->priv->_mime_type);
	_g_free0 (self->priv->_dlna_profile);
	_g_free0 (self->priv->_upnp_class);
	G_OBJECT_CLASS (rygel_transcoder_parent_class)->finalize (obj);
}


GType rygel_transcoder_get_type (void) {
	static GType rygel_transcoder_type_id = 0;
	if (rygel_transcoder_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelTranscoderClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_transcoder_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelTranscoder), 0, (GInstanceInitFunc) rygel_transcoder_instance_init, NULL };
		rygel_transcoder_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelTranscoder", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
	}
	return rygel_transcoder_type_id;
}


static void rygel_transcoder_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	RygelTranscoder * self;
	self = RYGEL_TRANSCODER (object);
	switch (property_id) {
		case RYGEL_TRANSCODER_MIME_TYPE:
		g_value_set_string (value, rygel_transcoder_get_mime_type (self));
		break;
		case RYGEL_TRANSCODER_DLNA_PROFILE:
		g_value_set_string (value, rygel_transcoder_get_dlna_profile (self));
		break;
		case RYGEL_TRANSCODER_UPNP_CLASS:
		g_value_set_string (value, rygel_transcoder_get_upnp_class (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void rygel_transcoder_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	RygelTranscoder * self;
	self = RYGEL_TRANSCODER (object);
	switch (property_id) {
		case RYGEL_TRANSCODER_MIME_TYPE:
		rygel_transcoder_set_mime_type (self, g_value_get_string (value));
		break;
		case RYGEL_TRANSCODER_DLNA_PROFILE:
		rygel_transcoder_set_dlna_profile (self, g_value_get_string (value));
		break;
		case RYGEL_TRANSCODER_UPNP_CLASS:
		rygel_transcoder_set_upnp_class (self, g_value_get_string (value));
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




