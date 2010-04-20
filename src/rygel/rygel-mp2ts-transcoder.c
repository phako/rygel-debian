/* rygel-mp2ts-transcoder.c generated by valac, the Vala compiler
 * generated from rygel-mp2ts-transcoder.vala, do not modify */

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

#define RYGEL_TYPE_SUBTITLE (rygel_subtitle_get_type ())
#define RYGEL_SUBTITLE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_SUBTITLE, RygelSubtitle))
#define RYGEL_SUBTITLE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_SUBTITLE, RygelSubtitleClass))
#define RYGEL_IS_SUBTITLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_SUBTITLE))
#define RYGEL_IS_SUBTITLE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_SUBTITLE))
#define RYGEL_SUBTITLE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_SUBTITLE, RygelSubtitleClass))

typedef struct _RygelSubtitle RygelSubtitle;
typedef struct _RygelSubtitleClass RygelSubtitleClass;
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
#define RYGEL_MEDIA_ITEM_IMAGE_CLASS "object.item.imageItem"
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
static guint rygel_mp2_ts_transcoder_real_get_distance (RygelTranscoder* base, RygelMediaItem* item);
GstElement* rygel_gst_utils_create_element (const char* factoryname, const char* name, GError** error);
static inline void _dynamic_set_bitrate2 (GstElement* obj, gint value);
GstElement* rygel_mp2_ts_transcoder_create_encoder (RygelMP2TSTranscoder* self, RygelMediaItem* item, const char* src_pad_name, const char* sink_pad_name, GError** error);
static void rygel_mp2_ts_transcoder_finalize (GObject* obj);

static const gint RYGEL_MP2_TS_TRANSCODER_WIDTH[2] = {640, 1280};
static const gint RYGEL_MP2_TS_TRANSCODER_HEIGHT[2] = {480, 720};
static const char* RYGEL_MP2_TS_TRANSCODER_PROFILES[2] = {"MPEG_TS_SD_US", "MPEG_TS_HD_US"};


GType rygel_mp2_ts_profile_get_type (void) {
	static volatile gsize rygel_mp2_ts_profile_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_mp2_ts_profile_type_id__volatile)) {
		static const GEnumValue values[] = {{RYGEL_MP2_TS_PROFILE_SD, "RYGEL_MP2_TS_PROFILE_SD", "sd"}, {RYGEL_MP2_TS_PROFILE_HD, "RYGEL_MP2_TS_PROFILE_HD", "hd"}, {0, NULL, NULL}};
		GType rygel_mp2_ts_profile_type_id;
		rygel_mp2_ts_profile_type_id = g_enum_register_static ("RygelMP2TSProfile", values);
		g_once_init_leave (&rygel_mp2_ts_profile_type_id__volatile, rygel_mp2_ts_profile_type_id);
	}
	return rygel_mp2_ts_profile_type_id__volatile;
}


#line 52 "rygel-mp2ts-transcoder.vala"
RygelMP2TSTranscoder* rygel_mp2_ts_transcoder_construct (GType object_type, RygelMP2TSProfile profile) {
#line 293 "rygel-mp2ts-transcoder.c"
	RygelMP2TSTranscoder * self;
#line 53 "rygel-mp2ts-transcoder.vala"
	self = (RygelMP2TSTranscoder*) rygel_transcoder_construct (object_type, "video/mpeg", RYGEL_MP2_TS_TRANSCODER_PROFILES[profile], RYGEL_MEDIA_ITEM_VIDEO_CLASS);
#line 55 "rygel-mp2ts-transcoder.vala"
	self->priv->profile = profile;
#line 299 "rygel-mp2ts-transcoder.c"
	return self;
}


#line 52 "rygel-mp2ts-transcoder.vala"
RygelMP2TSTranscoder* rygel_mp2_ts_transcoder_new (RygelMP2TSProfile profile) {
#line 52 "rygel-mp2ts-transcoder.vala"
	return rygel_mp2_ts_transcoder_construct (RYGEL_TYPE_MP2_TS_TRANSCODER, profile);
#line 308 "rygel-mp2ts-transcoder.c"
}


#line 58 "rygel-mp2ts-transcoder.vala"
static GstElement* rygel_mp2_ts_transcoder_real_create_source (RygelTranscoder* base, RygelMediaItem* item, GstElement* src, GError** error) {
#line 314 "rygel-mp2ts-transcoder.c"
	RygelMP2TSTranscoder * self;
	GstElement* result = NULL;
	GError * _inner_error_;
	RygelMP2TSTranscoderBin* _tmp0_;
	self = (RygelMP2TSTranscoder*) base;
#line 58 "rygel-mp2ts-transcoder.vala"
	g_return_val_if_fail (item != NULL, NULL);
#line 58 "rygel-mp2ts-transcoder.vala"
	g_return_val_if_fail (src != NULL, NULL);
#line 324 "rygel-mp2ts-transcoder.c"
	_inner_error_ = NULL;
#line 61 "rygel-mp2ts-transcoder.vala"
	_tmp0_ = rygel_mp2_ts_transcoder_bin_new (item, src, self, &_inner_error_);
#line 328 "rygel-mp2ts-transcoder.c"
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return NULL;
	}
	result = (GstElement*) _tmp0_;
#line 61 "rygel-mp2ts-transcoder.vala"
	return result;
#line 336 "rygel-mp2ts-transcoder.c"
}


#line 64 "rygel-mp2ts-transcoder.vala"
static GUPnPDIDLLiteResource* rygel_mp2_ts_transcoder_real_add_resource (RygelTranscoder* base, GUPnPDIDLLiteItem* didl_item, RygelMediaItem* item, RygelTranscodeManager* manager, GError** error) {
#line 342 "rygel-mp2ts-transcoder.c"
	RygelMP2TSTranscoder * self;
	GUPnPDIDLLiteResource* result = NULL;
	GError * _inner_error_;
	GUPnPDIDLLiteResource* resource;
	self = (RygelMP2TSTranscoder*) base;
#line 64 "rygel-mp2ts-transcoder.vala"
	g_return_val_if_fail (didl_item != NULL, NULL);
#line 64 "rygel-mp2ts-transcoder.vala"
	g_return_val_if_fail (item != NULL, NULL);
#line 64 "rygel-mp2ts-transcoder.vala"
	g_return_val_if_fail (manager != NULL, NULL);
#line 354 "rygel-mp2ts-transcoder.c"
	_inner_error_ = NULL;
#line 68 "rygel-mp2ts-transcoder.vala"
	resource = RYGEL_TRANSCODER_CLASS (rygel_mp2_ts_transcoder_parent_class)->add_resource (RYGEL_TRANSCODER (self), didl_item, item, manager, &_inner_error_);
#line 358 "rygel-mp2ts-transcoder.c"
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return NULL;
	}
#line 69 "rygel-mp2ts-transcoder.vala"
	if (resource == NULL) {
#line 365 "rygel-mp2ts-transcoder.c"
		result = NULL;
		_g_object_unref0 (resource);
#line 70 "rygel-mp2ts-transcoder.vala"
		return result;
#line 370 "rygel-mp2ts-transcoder.c"
	}
#line 72 "rygel-mp2ts-transcoder.vala"
	gupnp_didl_lite_resource_set_width (resource, RYGEL_MP2_TS_TRANSCODER_WIDTH[self->priv->profile]);
#line 73 "rygel-mp2ts-transcoder.vala"
	gupnp_didl_lite_resource_set_height (resource, RYGEL_MP2_TS_TRANSCODER_HEIGHT[self->priv->profile]);
#line 74 "rygel-mp2ts-transcoder.vala"
	gupnp_didl_lite_resource_set_bitrate (resource, ((RYGEL_MP2_TS_TRANSCODER_VIDEO_BITRATE + RYGEL_MP3_TRANSCODER_BITRATE) * 1000) / 8);
#line 378 "rygel-mp2ts-transcoder.c"
	result = resource;
#line 76 "rygel-mp2ts-transcoder.vala"
	return result;
#line 382 "rygel-mp2ts-transcoder.c"
}


#line 79 "rygel-mp2ts-transcoder.vala"
static guint rygel_mp2_ts_transcoder_real_get_distance (RygelTranscoder* base, RygelMediaItem* item) {
#line 388 "rygel-mp2ts-transcoder.c"
	RygelMP2TSTranscoder * self;
	guint result = 0U;
	guint distance = 0U;
	self = (RygelMP2TSTranscoder*) base;
#line 79 "rygel-mp2ts-transcoder.vala"
	g_return_val_if_fail (item != NULL, 0U);
#line 80 "rygel-mp2ts-transcoder.vala"
	if (g_str_has_prefix (((RygelMediaObject*) item)->upnp_class, RYGEL_MEDIA_ITEM_IMAGE_CLASS)) {
#line 397 "rygel-mp2ts-transcoder.c"
		result = G_MAXUINT;
#line 81 "rygel-mp2ts-transcoder.vala"
		return result;
#line 401 "rygel-mp2ts-transcoder.c"
	}
#line 86 "rygel-mp2ts-transcoder.vala"
	if (g_str_has_prefix (((RygelMediaObject*) item)->upnp_class, RYGEL_MEDIA_ITEM_VIDEO_CLASS)) {
#line 87 "rygel-mp2ts-transcoder.vala"
		distance = 0;
#line 89 "rygel-mp2ts-transcoder.vala"
		if (item->bitrate > 0) {
#line 90 "rygel-mp2ts-transcoder.vala"
			distance = distance + ((guint) abs (item->bitrate - RYGEL_MP2_TS_TRANSCODER_BITRATE));
#line 411 "rygel-mp2ts-transcoder.c"
		}
#line 93 "rygel-mp2ts-transcoder.vala"
		if (item->width > 0) {
#line 94 "rygel-mp2ts-transcoder.vala"
			distance = distance + ((guint) abs (item->width - RYGEL_MP2_TS_TRANSCODER_WIDTH[self->priv->profile]));
#line 417 "rygel-mp2ts-transcoder.c"
		}
#line 97 "rygel-mp2ts-transcoder.vala"
		if (item->height > 0) {
#line 98 "rygel-mp2ts-transcoder.vala"
			distance = distance + ((guint) abs (item->height - RYGEL_MP2_TS_TRANSCODER_HEIGHT[self->priv->profile]));
#line 423 "rygel-mp2ts-transcoder.c"
		}
	} else {
#line 101 "rygel-mp2ts-transcoder.vala"
		distance = G_MAXUINT / 2;
#line 428 "rygel-mp2ts-transcoder.c"
	}
	result = distance;
#line 104 "rygel-mp2ts-transcoder.vala"
	return result;
#line 433 "rygel-mp2ts-transcoder.c"
}


static inline void _dynamic_set_bitrate2 (GstElement* obj, gint value) {
	g_object_set (obj, "bitrate", value, NULL);
}


static gpointer _gst_object_ref0 (gpointer self) {
	return self ? gst_object_ref (self) : NULL;
}


#line 107 "rygel-mp2ts-transcoder.vala"
GstElement* rygel_mp2_ts_transcoder_create_encoder (RygelMP2TSTranscoder* self, RygelMediaItem* item, const char* src_pad_name, const char* sink_pad_name, GError** error) {
#line 449 "rygel-mp2ts-transcoder.c"
	GstElement* result = NULL;
	GError * _inner_error_;
	GstElement* videorate;
	GstElement* videoscale;
	GstElement* convert;
	GstElement* encoder;
	GstBin* bin;
	gint pixel_w = 0;
	gint pixel_h = 0;
	gboolean _tmp0_ = FALSE;
	GstCaps* caps;
	GstPad* pad;
	GstGhostPad* ghost;
	GstPad* _tmp1_;
	GstGhostPad* _tmp2_;
#line 107 "rygel-mp2ts-transcoder.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 107 "rygel-mp2ts-transcoder.vala"
	g_return_val_if_fail (item != NULL, NULL);
#line 469 "rygel-mp2ts-transcoder.c"
	_inner_error_ = NULL;
#line 111 "rygel-mp2ts-transcoder.vala"
	videorate = rygel_gst_utils_create_element (RYGEL_MP2_TS_TRANSCODER_VIDEO_RATE, RYGEL_MP2_TS_TRANSCODER_VIDEO_RATE, &_inner_error_);
#line 473 "rygel-mp2ts-transcoder.c"
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return NULL;
	}
#line 112 "rygel-mp2ts-transcoder.vala"
	videoscale = rygel_gst_utils_create_element (RYGEL_MP2_TS_TRANSCODER_VIDEO_SCALE, RYGEL_MP2_TS_TRANSCODER_VIDEO_SCALE, &_inner_error_);
#line 480 "rygel-mp2ts-transcoder.c"
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_gst_object_unref0 (videorate);
		return NULL;
	}
#line 113 "rygel-mp2ts-transcoder.vala"
	convert = rygel_gst_utils_create_element (RYGEL_MP2_TS_TRANSCODER_COLORSPACE_CONVERT, RYGEL_MP2_TS_TRANSCODER_COLORSPACE_CONVERT, &_inner_error_);
#line 488 "rygel-mp2ts-transcoder.c"
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_gst_object_unref0 (videorate);
		_gst_object_unref0 (videoscale);
		return NULL;
	}
#line 115 "rygel-mp2ts-transcoder.vala"
	encoder = rygel_gst_utils_create_element (RYGEL_MP2_TS_TRANSCODER_VIDEO_ENCODER, RYGEL_MP2_TS_TRANSCODER_VIDEO_ENCODER, &_inner_error_);
#line 497 "rygel-mp2ts-transcoder.c"
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_gst_object_unref0 (videorate);
		_gst_object_unref0 (videoscale);
		_gst_object_unref0 (convert);
		return NULL;
	}
#line 118 "rygel-mp2ts-transcoder.vala"
	_dynamic_set_bitrate2 (encoder, ((gint) RYGEL_MP2_TS_TRANSCODER_VIDEO_BITRATE) * 1000);
#line 120 "rygel-mp2ts-transcoder.vala"
	bin = (GstBin*) gst_bin_new ("video-encoder-bin");
#line 121 "rygel-mp2ts-transcoder.vala"
	gst_bin_add_many (bin, _gst_object_ref0 (videorate), _gst_object_ref0 (videoscale), _gst_object_ref0 (convert), _gst_object_ref0 (encoder), NULL);
#line 123 "rygel-mp2ts-transcoder.vala"
	gst_element_link_many (convert, videoscale, videorate, NULL);
#line 128 "rygel-mp2ts-transcoder.vala"
	if (item->pixel_width > 0) {
#line 128 "rygel-mp2ts-transcoder.vala"
		_tmp0_ = item->pixel_height > 0;
#line 517 "rygel-mp2ts-transcoder.c"
	} else {
#line 128 "rygel-mp2ts-transcoder.vala"
		_tmp0_ = FALSE;
#line 521 "rygel-mp2ts-transcoder.c"
	}
#line 128 "rygel-mp2ts-transcoder.vala"
	if (_tmp0_) {
#line 129 "rygel-mp2ts-transcoder.vala"
		pixel_w = (item->width * RYGEL_MP2_TS_TRANSCODER_HEIGHT[self->priv->profile]) * item->pixel_width;
#line 130 "rygel-mp2ts-transcoder.vala"
		pixel_h = (item->height * RYGEL_MP2_TS_TRANSCODER_WIDTH[self->priv->profile]) * item->pixel_height;
#line 529 "rygel-mp2ts-transcoder.c"
	} else {
#line 133 "rygel-mp2ts-transcoder.vala"
		pixel_w = 1;
#line 134 "rygel-mp2ts-transcoder.vala"
		pixel_h = 1;
#line 535 "rygel-mp2ts-transcoder.c"
	}
#line 137 "rygel-mp2ts-transcoder.vala"
	caps = gst_caps_new_simple ("video/x-raw-yuv", "width", G_TYPE_INT, RYGEL_MP2_TS_TRANSCODER_WIDTH[self->priv->profile], "height", G_TYPE_INT, RYGEL_MP2_TS_TRANSCODER_HEIGHT[self->priv->profile], "framerate", GST_TYPE_FRACTION, 30, 1, "pixel-aspect-ratio", GST_TYPE_FRACTION, pixel_w, pixel_h, NULL);
#line 152 "rygel-mp2ts-transcoder.vala"
	gst_element_link_filtered (videorate, encoder, caps);
#line 154 "rygel-mp2ts-transcoder.vala"
	pad = gst_element_get_static_pad (convert, "sink");
#line 155 "rygel-mp2ts-transcoder.vala"
	ghost = (GstGhostPad*) gst_ghost_pad_new (sink_pad_name, pad);
#line 156 "rygel-mp2ts-transcoder.vala"
	gst_element_add_pad ((GstElement*) bin, _gst_object_ref0 ((GstPad*) ghost));
#line 158 "rygel-mp2ts-transcoder.vala"
	pad = (_tmp1_ = gst_element_get_static_pad (encoder, "src"), _gst_object_unref0 (pad), _tmp1_);
#line 159 "rygel-mp2ts-transcoder.vala"
	ghost = (_tmp2_ = (GstGhostPad*) gst_ghost_pad_new (src_pad_name, pad), _gst_object_unref0 (ghost), _tmp2_);
#line 160 "rygel-mp2ts-transcoder.vala"
	gst_element_add_pad ((GstElement*) bin, _gst_object_ref0 ((GstPad*) ghost));
#line 553 "rygel-mp2ts-transcoder.c"
	result = (GstElement*) bin;
	_gst_object_unref0 (videorate);
	_gst_object_unref0 (videoscale);
	_gst_object_unref0 (convert);
	_gst_object_unref0 (encoder);
	_gst_caps_unref0 (caps);
	_gst_object_unref0 (pad);
	_gst_object_unref0 (ghost);
#line 162 "rygel-mp2ts-transcoder.vala"
	return result;
#line 564 "rygel-mp2ts-transcoder.c"
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
	static volatile gsize rygel_mp2_ts_transcoder_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_mp2_ts_transcoder_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMP2TSTranscoderClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_mp2_ts_transcoder_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMP2TSTranscoder), 0, (GInstanceInitFunc) rygel_mp2_ts_transcoder_instance_init, NULL };
		GType rygel_mp2_ts_transcoder_type_id;
		rygel_mp2_ts_transcoder_type_id = g_type_register_static (RYGEL_TYPE_TRANSCODER, "RygelMP2TSTranscoder", &g_define_type_info, 0);
		g_once_init_leave (&rygel_mp2_ts_transcoder_type_id__volatile, rygel_mp2_ts_transcoder_type_id);
	}
	return rygel_mp2_ts_transcoder_type_id__volatile;
}




