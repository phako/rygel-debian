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


#define RYGEL_TYPE_MP2_TS_PROFILE (rygel_mp2_ts_profile_get_type ())

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

#define RYGEL_TYPE_MP2_TS_TRANSCODER (rygel_mp2_ts_transcoder_get_type ())
#define RYGEL_MP2_TS_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MP2_TS_TRANSCODER, RygelMP2TSTranscoder))
#define RYGEL_MP2_TS_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MP2_TS_TRANSCODER, RygelMP2TSTranscoderClass))
#define RYGEL_IS_MP2_TS_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MP2_TS_TRANSCODER))
#define RYGEL_IS_MP2_TS_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MP2_TS_TRANSCODER))
#define RYGEL_MP2_TS_TRANSCODER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MP2_TS_TRANSCODER, RygelMP2TSTranscoderClass))

typedef struct _RygelMP2TSTranscoder RygelMP2TSTranscoder;
typedef struct _RygelMP2TSTranscoderClass RygelMP2TSTranscoderClass;
typedef struct _RygelMP2TSTranscoderPrivate RygelMP2TSTranscoderPrivate;

#define RYGEL_TYPE_MP2_TS_TRANSCODER_BIN (rygel_mp2_ts_transcoder_bin_get_type ())
#define RYGEL_MP2_TS_TRANSCODER_BIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MP2_TS_TRANSCODER_BIN, RygelMP2TSTranscoderBin))
#define RYGEL_MP2_TS_TRANSCODER_BIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MP2_TS_TRANSCODER_BIN, RygelMP2TSTranscoderBinClass))
#define RYGEL_IS_MP2_TS_TRANSCODER_BIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MP2_TS_TRANSCODER_BIN))
#define RYGEL_IS_MP2_TS_TRANSCODER_BIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MP2_TS_TRANSCODER_BIN))
#define RYGEL_MP2_TS_TRANSCODER_BIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MP2_TS_TRANSCODER_BIN, RygelMP2TSTranscoderBinClass))

typedef struct _RygelMP2TSTranscoderBin RygelMP2TSTranscoderBin;
typedef struct _RygelMP2TSTranscoderBinClass RygelMP2TSTranscoderBinClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
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
#define _gst_object_unref0(var) ((var == NULL) ? NULL : (var = (gst_object_unref (var), NULL)))
#define _gst_caps_unref0(var) ((var == NULL) ? NULL : (var = (gst_caps_unref (var), NULL)))

typedef enum  {
	RYGEL_MP2_TS_PROFILE_SD = 0,
	RYGEL_MP2_TS_PROFILE_HD
} RygelMP2TSProfile;

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

struct _RygelMP2TSTranscoder {
	RygelTranscoder parent_instance;
	RygelMP2TSTranscoderPrivate * priv;
};

struct _RygelMP2TSTranscoderClass {
	RygelTranscoderClass parent_class;
};

struct _RygelMP2TSTranscoderPrivate {
	RygelMP2TSProfile profile;
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


static gpointer rygel_mp2_ts_transcoder_parent_class = NULL;

GType rygel_mp2_ts_profile_get_type (void);
GType rygel_transcoder_get_type (void);
GType rygel_media_object_get_type (void);
GType rygel_media_item_get_type (void);
GType rygel_transcode_manager_get_type (void);
GType rygel_mp2_ts_transcoder_get_type (void);
#define RYGEL_MP2_TS_TRANSCODER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_MP2_TS_TRANSCODER, RygelMP2TSTranscoderPrivate))
enum  {
	RYGEL_MP2_TS_TRANSCODER_DUMMY_PROPERTY
};
#define RYGEL_MP2_TS_TRANSCODER_VIDEO_BITRATE 3000
#define RYGEL_MP2_TS_TRANSCODER_BITRATE 3000000
#define RYGEL_MP2_TS_TRANSCODER_VIDEO_ENCODER "ffenc_mpeg2video"
#define RYGEL_MP2_TS_TRANSCODER_COLORSPACE_CONVERT "ffmpegcolorspace"
#define RYGEL_MP2_TS_TRANSCODER_VIDEO_RATE "videorate"
#define RYGEL_MP2_TS_TRANSCODER_VIDEO_SCALE "videoscale"
#define RYGEL_MEDIA_ITEM_VIDEO_CLASS "object.item.videoItem"
RygelTranscoder* rygel_transcoder_construct (GType object_type, const char* mime_type, const char* dlna_profile, const char* upnp_class);
RygelMP2TSTranscoder* rygel_mp2_ts_transcoder_new (RygelMP2TSProfile profile);
RygelMP2TSTranscoder* rygel_mp2_ts_transcoder_construct (GType object_type, RygelMP2TSProfile profile);
RygelMP2TSTranscoderBin* rygel_mp2_ts_transcoder_bin_new (RygelMediaItem* item, GstElement* src, RygelMP2TSTranscoder* transcoder, GError** error);
RygelMP2TSTranscoderBin* rygel_mp2_ts_transcoder_bin_construct (GType object_type, RygelMediaItem* item, GstElement* src, RygelMP2TSTranscoder* transcoder, GError** error);
GType rygel_mp2_ts_transcoder_bin_get_type (void);
static GstElement* rygel_mp2_ts_transcoder_real_create_source (RygelTranscoder* base, RygelMediaItem* item, GstElement* src, GError** error);
GUPnPDIDLLiteResource* rygel_transcoder_add_resource (RygelTranscoder* self, GUPnPDIDLLiteItem* didl_item, RygelMediaItem* item, RygelTranscodeManager* manager, GError** error);
#define RYGEL_MP3_TRANSCODER_BITRATE 256
static GUPnPDIDLLiteResource* rygel_mp2_ts_transcoder_real_add_resource (RygelTranscoder* base, GUPnPDIDLLiteItem* didl_item, RygelMediaItem* item, RygelTranscodeManager* manager, GError** error);
GType rygel_media_container_get_type (void);
gpointer rygel_icon_info_ref (gpointer instance);
void rygel_icon_info_unref (gpointer instance);
GParamSpec* rygel_param_spec_icon_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_icon_info (GValue* value, gpointer v_object);
gpointer rygel_value_get_icon_info (const GValue* value);
GType rygel_icon_info_get_type (void);
GType rygel_thumbnail_get_type (void);
#define RYGEL_MEDIA_ITEM_IMAGE_CLASS "object.item.imageItem"
static guint rygel_mp2_ts_transcoder_real_get_distance (RygelTranscoder* base, RygelMediaItem* item);
GstElement* rygel_gst_utils_create_element (const char* factoryname, const char* name, GError** error);
static inline void _dynamic_set_bitrate2 (GstElement* obj, gint value);
GstElement* rygel_mp2_ts_transcoder_create_encoder (RygelMP2TSTranscoder* self, RygelMediaItem* item, const char* src_pad_name, const char* sink_pad_name, GError** error);
static void rygel_mp2_ts_transcoder_finalize (GObject* obj);

static const gint RYGEL_MP2_TS_TRANSCODER_WIDTH[] = {640, 1280};
static const gint RYGEL_MP2_TS_TRANSCODER_HEIGHT[] = {480, 720};
static const char* RYGEL_MP2_TS_TRANSCODER_PROFILES[] = {"MPEG_TS_SD_US", "MPEG_TS_HD_US"};



GType rygel_mp2_ts_profile_get_type (void) {
	static GType rygel_mp2_ts_profile_type_id = 0;
	if (G_UNLIKELY (rygel_mp2_ts_profile_type_id == 0)) {
		static const GEnumValue values[] = {{RYGEL_MP2_TS_PROFILE_SD, "RYGEL_MP2_TS_PROFILE_SD", "sd"}, {RYGEL_MP2_TS_PROFILE_HD, "RYGEL_MP2_TS_PROFILE_HD", "hd"}, {0, NULL, NULL}};
		rygel_mp2_ts_profile_type_id = g_enum_register_static ("RygelMP2TSProfile", values);
	}
	return rygel_mp2_ts_profile_type_id;
}


RygelMP2TSTranscoder* rygel_mp2_ts_transcoder_construct (GType object_type, RygelMP2TSProfile profile) {
	RygelMP2TSTranscoder * self;
	self = (RygelMP2TSTranscoder*) rygel_transcoder_construct (object_type, "video/mpeg", RYGEL_MP2_TS_TRANSCODER_PROFILES[profile], RYGEL_MEDIA_ITEM_VIDEO_CLASS);
	self->priv->profile = profile;
	return self;
}


RygelMP2TSTranscoder* rygel_mp2_ts_transcoder_new (RygelMP2TSProfile profile) {
	return rygel_mp2_ts_transcoder_construct (RYGEL_TYPE_MP2_TS_TRANSCODER, profile);
}


static GstElement* rygel_mp2_ts_transcoder_real_create_source (RygelTranscoder* base, RygelMediaItem* item, GstElement* src, GError** error) {
	RygelMP2TSTranscoder * self;
	GstElement* result;
	GError * _inner_error_;
	RygelMP2TSTranscoderBin* _tmp0_;
	self = (RygelMP2TSTranscoder*) base;
	g_return_val_if_fail (item != NULL, NULL);
	g_return_val_if_fail (src != NULL, NULL);
	_inner_error_ = NULL;
	_tmp0_ = rygel_mp2_ts_transcoder_bin_new (item, src, self, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return NULL;
	}
	result = (GstElement*) _tmp0_;
	return result;
}


static GUPnPDIDLLiteResource* rygel_mp2_ts_transcoder_real_add_resource (RygelTranscoder* base, GUPnPDIDLLiteItem* didl_item, RygelMediaItem* item, RygelTranscodeManager* manager, GError** error) {
	RygelMP2TSTranscoder * self;
	GUPnPDIDLLiteResource* result;
	GError * _inner_error_;
	GUPnPDIDLLiteResource* resource;
	self = (RygelMP2TSTranscoder*) base;
	g_return_val_if_fail (didl_item != NULL, NULL);
	g_return_val_if_fail (item != NULL, NULL);
	g_return_val_if_fail (manager != NULL, NULL);
	_inner_error_ = NULL;
	resource = RYGEL_TRANSCODER_CLASS (rygel_mp2_ts_transcoder_parent_class)->add_resource (RYGEL_TRANSCODER (self), didl_item, item, manager, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return NULL;
	}
	if (resource == NULL) {
		result = NULL;
		_g_object_unref0 (resource);
		return result;
	}
	gupnp_didl_lite_resource_set_width (resource, RYGEL_MP2_TS_TRANSCODER_WIDTH[self->priv->profile]);
	gupnp_didl_lite_resource_set_height (resource, RYGEL_MP2_TS_TRANSCODER_HEIGHT[self->priv->profile]);
	gupnp_didl_lite_resource_set_bitrate (resource, ((RYGEL_MP2_TS_TRANSCODER_VIDEO_BITRATE + RYGEL_MP3_TRANSCODER_BITRATE) * 1000) / 8);
	result = resource;
	return result;
}


static guint rygel_mp2_ts_transcoder_real_get_distance (RygelTranscoder* base, RygelMediaItem* item) {
	RygelMP2TSTranscoder * self;
	guint result;
	guint distance;
	self = (RygelMP2TSTranscoder*) base;
	g_return_val_if_fail (item != NULL, 0U);
	if (g_str_has_prefix (item->upnp_class, RYGEL_MEDIA_ITEM_IMAGE_CLASS)) {
		result = G_MAXUINT;
		return result;
	}
	distance = 0U;
	if (g_str_has_prefix (item->upnp_class, RYGEL_MEDIA_ITEM_VIDEO_CLASS)) {
		distance = 0;
		if (item->bitrate > 0) {
			distance = distance + ((guint) abs (item->bitrate - RYGEL_MP2_TS_TRANSCODER_BITRATE));
		}
		if (item->width > 0) {
			distance = distance + ((guint) abs (item->width - RYGEL_MP2_TS_TRANSCODER_WIDTH[self->priv->profile]));
		}
		if (item->height > 0) {
			distance = distance + ((guint) abs (item->height - RYGEL_MP2_TS_TRANSCODER_HEIGHT[self->priv->profile]));
		}
	} else {
		distance = G_MAXUINT / 2;
	}
	result = distance;
	return result;
}


static inline void _dynamic_set_bitrate2 (GstElement* obj, gint value) {
	g_object_set (obj, "bitrate", value, NULL);
}


static gpointer _gst_object_ref0 (gpointer self) {
	return self ? gst_object_ref (self) : NULL;
}


GstElement* rygel_mp2_ts_transcoder_create_encoder (RygelMP2TSTranscoder* self, RygelMediaItem* item, const char* src_pad_name, const char* sink_pad_name, GError** error) {
	GstElement* result;
	GError * _inner_error_;
	GstElement* videorate;
	GstElement* videoscale;
	GstElement* convert;
	GstElement* encoder;
	GstBin* bin;
	gint pixel_w;
	gint pixel_h;
	gboolean _tmp0_;
	GstCaps* caps;
	GstPad* pad;
	GstGhostPad* ghost;
	GstPad* _tmp1_;
	GstGhostPad* _tmp2_;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (item != NULL, NULL);
	_inner_error_ = NULL;
	videorate = rygel_gst_utils_create_element (RYGEL_MP2_TS_TRANSCODER_VIDEO_RATE, RYGEL_MP2_TS_TRANSCODER_VIDEO_RATE, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return NULL;
	}
	videoscale = rygel_gst_utils_create_element (RYGEL_MP2_TS_TRANSCODER_VIDEO_SCALE, RYGEL_MP2_TS_TRANSCODER_VIDEO_SCALE, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_gst_object_unref0 (videorate);
		return NULL;
	}
	convert = rygel_gst_utils_create_element (RYGEL_MP2_TS_TRANSCODER_COLORSPACE_CONVERT, RYGEL_MP2_TS_TRANSCODER_COLORSPACE_CONVERT, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_gst_object_unref0 (videorate);
		_gst_object_unref0 (videoscale);
		return NULL;
	}
	encoder = rygel_gst_utils_create_element (RYGEL_MP2_TS_TRANSCODER_VIDEO_ENCODER, RYGEL_MP2_TS_TRANSCODER_VIDEO_ENCODER, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_gst_object_unref0 (videorate);
		_gst_object_unref0 (videoscale);
		_gst_object_unref0 (convert);
		return NULL;
	}
	_dynamic_set_bitrate2 (encoder, ((gint) RYGEL_MP2_TS_TRANSCODER_VIDEO_BITRATE) * 1000);
	bin = (GstBin*) gst_bin_new ("video-encoder-bin");
	gst_bin_add_many (bin, _gst_object_ref0 (videorate), _gst_object_ref0 (videoscale), _gst_object_ref0 (convert), _gst_object_ref0 (encoder), NULL);
	gst_element_link_many (convert, videoscale, videorate, NULL);
	pixel_w = 0;
	pixel_h = 0;
	_tmp0_ = FALSE;
	if (item->pixel_width > 0) {
		_tmp0_ = item->pixel_height > 0;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		pixel_w = (item->width * RYGEL_MP2_TS_TRANSCODER_HEIGHT[self->priv->profile]) * item->pixel_width;
		pixel_h = (item->height * RYGEL_MP2_TS_TRANSCODER_WIDTH[self->priv->profile]) * item->pixel_height;
	} else {
		pixel_w = 1;
		pixel_h = 1;
	}
	caps = gst_caps_new_simple ("video/x-raw-yuv", "width", G_TYPE_INT, RYGEL_MP2_TS_TRANSCODER_WIDTH[self->priv->profile], "height", G_TYPE_INT, RYGEL_MP2_TS_TRANSCODER_HEIGHT[self->priv->profile], "framerate", GST_TYPE_FRACTION, 30, 1, "pixel-aspect-ratio", GST_TYPE_FRACTION, pixel_w, pixel_h, NULL);
	gst_element_link_filtered (videorate, encoder, caps);
	pad = gst_element_get_static_pad (convert, "sink");
	ghost = (GstGhostPad*) gst_ghost_pad_new (sink_pad_name, pad);
	gst_element_add_pad ((GstElement*) bin, _gst_object_ref0 ((GstPad*) ghost));
	pad = (_tmp1_ = gst_element_get_static_pad (encoder, "src"), _gst_object_unref0 (pad), _tmp1_);
	ghost = (_tmp2_ = (GstGhostPad*) gst_ghost_pad_new (src_pad_name, pad), _gst_object_unref0 (ghost), _tmp2_);
	gst_element_add_pad ((GstElement*) bin, _gst_object_ref0 ((GstPad*) ghost));
	result = (GstElement*) bin;
	_gst_object_unref0 (videorate);
	_gst_object_unref0 (videoscale);
	_gst_object_unref0 (convert);
	_gst_object_unref0 (encoder);
	_gst_caps_unref0 (caps);
	_gst_object_unref0 (pad);
	_gst_object_unref0 (ghost);
	return result;
}


static void rygel_mp2_ts_transcoder_class_init (RygelMP2TSTranscoderClass * klass) {
	rygel_mp2_ts_transcoder_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelMP2TSTranscoderPrivate));
	RYGEL_TRANSCODER_CLASS (klass)->create_source = rygel_mp2_ts_transcoder_real_create_source;
	RYGEL_TRANSCODER_CLASS (klass)->add_resource = rygel_mp2_ts_transcoder_real_add_resource;
	RYGEL_TRANSCODER_CLASS (klass)->get_distance = rygel_mp2_ts_transcoder_real_get_distance;
	G_OBJECT_CLASS (klass)->finalize = rygel_mp2_ts_transcoder_finalize;
}


static void rygel_mp2_ts_transcoder_instance_init (RygelMP2TSTranscoder * self) {
	self->priv = RYGEL_MP2_TS_TRANSCODER_GET_PRIVATE (self);
}


static void rygel_mp2_ts_transcoder_finalize (GObject* obj) {
	RygelMP2TSTranscoder * self;
	self = RYGEL_MP2_TS_TRANSCODER (obj);
	G_OBJECT_CLASS (rygel_mp2_ts_transcoder_parent_class)->finalize (obj);
}


GType rygel_mp2_ts_transcoder_get_type (void) {
	static GType rygel_mp2_ts_transcoder_type_id = 0;
	if (rygel_mp2_ts_transcoder_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMP2TSTranscoderClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_mp2_ts_transcoder_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMP2TSTranscoder), 0, (GInstanceInitFunc) rygel_mp2_ts_transcoder_instance_init, NULL };
		rygel_mp2_ts_transcoder_type_id = g_type_register_static (RYGEL_TYPE_TRANSCODER, "RygelMP2TSTranscoder", &g_define_type_info, 0);
	}
	return rygel_mp2_ts_transcoder_type_id;
}




