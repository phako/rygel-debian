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


#define TYPE_ENDIANNESS (endianness_get_type ())

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

#define RYGEL_TYPE_L16_TRANSCODER (rygel_l16_transcoder_get_type ())
#define RYGEL_L16_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_L16_TRANSCODER, RygelL16Transcoder))
#define RYGEL_L16_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_L16_TRANSCODER, RygelL16TranscoderClass))
#define RYGEL_IS_L16_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_L16_TRANSCODER))
#define RYGEL_IS_L16_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_L16_TRANSCODER))
#define RYGEL_L16_TRANSCODER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_L16_TRANSCODER, RygelL16TranscoderClass))

typedef struct _RygelL16Transcoder RygelL16Transcoder;
typedef struct _RygelL16TranscoderClass RygelL16TranscoderClass;
typedef struct _RygelL16TranscoderPrivate RygelL16TranscoderPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))

#define RYGEL_TYPE_L16_TRANSCODER_BIN (rygel_l16_transcoder_bin_get_type ())
#define RYGEL_L16_TRANSCODER_BIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_L16_TRANSCODER_BIN, RygelL16TranscoderBin))
#define RYGEL_L16_TRANSCODER_BIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_L16_TRANSCODER_BIN, RygelL16TranscoderBinClass))
#define RYGEL_IS_L16_TRANSCODER_BIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_L16_TRANSCODER_BIN))
#define RYGEL_IS_L16_TRANSCODER_BIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_L16_TRANSCODER_BIN))
#define RYGEL_L16_TRANSCODER_BIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_L16_TRANSCODER_BIN, RygelL16TranscoderBinClass))

typedef struct _RygelL16TranscoderBin RygelL16TranscoderBin;
typedef struct _RygelL16TranscoderBinClass RygelL16TranscoderBinClass;
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
	ENDIANNESS_LITTLE = G_LITTLE_ENDIAN,
	ENDIANNESS_BIG = G_BIG_ENDIAN
} Endianness;

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

struct _RygelL16Transcoder {
	RygelTranscoder parent_instance;
	RygelL16TranscoderPrivate * priv;
};

struct _RygelL16TranscoderClass {
	RygelTranscoderClass parent_class;
};

struct _RygelL16TranscoderPrivate {
	Endianness endianness;
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


static gpointer rygel_l16_transcoder_parent_class = NULL;

GType endianness_get_type (void);
GType rygel_transcoder_get_type (void);
GType rygel_media_object_get_type (void);
GType rygel_media_item_get_type (void);
GType rygel_transcode_manager_get_type (void);
GType rygel_l16_transcoder_get_type (void);
#define RYGEL_L16_TRANSCODER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_L16_TRANSCODER, RygelL16TranscoderPrivate))
enum  {
	RYGEL_L16_TRANSCODER_DUMMY_PROPERTY
};
#define RYGEL_L16_TRANSCODER_CHANNELS 2
#define RYGEL_L16_TRANSCODER_FREQUENCY 44100
#define RYGEL_L16_TRANSCODER_WIDTH 16
#define RYGEL_L16_TRANSCODER_DEPTH 16
#define RYGEL_L16_TRANSCODER_SIGNED TRUE
#define RYGEL_L16_TRANSCODER_AUDIO_CONVERT "audioconvert"
#define RYGEL_L16_TRANSCODER_AUDIO_RESAMPLE "audioresample"
#define RYGEL_L16_TRANSCODER_AUDIO_RATE "audiorate"
#define RYGEL_L16_TRANSCODER_CAPS_FILTER "capsfilter"
#define RYGEL_MEDIA_ITEM_AUDIO_CLASS "object.item.audioItem"
RygelTranscoder* rygel_transcoder_construct (GType object_type, const char* mime_type, const char* dlna_profile, const char* upnp_class);
RygelL16Transcoder* rygel_l16_transcoder_new (Endianness endianness);
RygelL16Transcoder* rygel_l16_transcoder_construct (GType object_type, Endianness endianness);
RygelL16TranscoderBin* rygel_l16_transcoder_bin_new (RygelMediaItem* item, GstElement* src, RygelL16Transcoder* transcoder, GError** error);
RygelL16TranscoderBin* rygel_l16_transcoder_bin_construct (GType object_type, RygelMediaItem* item, GstElement* src, RygelL16Transcoder* transcoder, GError** error);
GType rygel_l16_transcoder_bin_get_type (void);
static GstElement* rygel_l16_transcoder_real_create_source (RygelTranscoder* base, RygelMediaItem* item, GstElement* src, GError** error);
GUPnPDIDLLiteResource* rygel_transcoder_add_resource (RygelTranscoder* self, GUPnPDIDLLiteItem* didl_item, RygelMediaItem* item, RygelTranscodeManager* manager, GError** error);
static GUPnPDIDLLiteResource* rygel_l16_transcoder_real_add_resource (RygelTranscoder* base, GUPnPDIDLLiteItem* didl_item, RygelMediaItem* item, RygelTranscodeManager* manager, GError** error);
GType rygel_media_container_get_type (void);
gpointer rygel_icon_info_ref (gpointer instance);
void rygel_icon_info_unref (gpointer instance);
GParamSpec* rygel_param_spec_icon_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_icon_info (GValue* value, gpointer v_object);
gpointer rygel_value_get_icon_info (const GValue* value);
GType rygel_icon_info_get_type (void);
GType rygel_thumbnail_get_type (void);
#define RYGEL_MEDIA_ITEM_IMAGE_CLASS "object.item.imageItem"
static guint rygel_l16_transcoder_real_get_distance (RygelTranscoder* base, RygelMediaItem* item);
GstElement* rygel_gst_utils_create_element (const char* factoryname, const char* name, GError** error);
static inline void _dynamic_set_caps5 (GstElement* obj, GstCaps* value);
GstElement* rygel_l16_transcoder_create_encoder (RygelL16Transcoder* self, RygelMediaItem* item, const char* src_pad_name, const char* sink_pad_name, GError** error);
static void rygel_l16_transcoder_finalize (GObject* obj);




GType endianness_get_type (void) {
	static GType endianness_type_id = 0;
	if (G_UNLIKELY (endianness_type_id == 0)) {
		static const GEnumValue values[] = {{ENDIANNESS_LITTLE, "ENDIANNESS_LITTLE", "little"}, {ENDIANNESS_BIG, "ENDIANNESS_BIG", "big"}, {0, NULL, NULL}};
		endianness_type_id = g_enum_register_static ("Endianness", values);
	}
	return endianness_type_id;
}


RygelL16Transcoder* rygel_l16_transcoder_construct (GType object_type, Endianness endianness) {
	RygelL16Transcoder * self;
	char* _tmp6_;
	char* _tmp5_;
	char* _tmp4_;
	char* _tmp3_;
	char* _tmp2_;
	char* _tmp1_;
	char* _tmp0_;
	char* _tmp7_;
	char* mime_type;
	mime_type = (_tmp7_ = g_strconcat (_tmp5_ = g_strconcat (_tmp4_ = g_strconcat (_tmp2_ = g_strconcat (_tmp1_ = g_strconcat ("audio/L", _tmp0_ = g_strdup_printf ("%i", RYGEL_L16_TRANSCODER_WIDTH), NULL), ";rate=", NULL), _tmp3_ = g_strdup_printf ("%i", RYGEL_L16_TRANSCODER_FREQUENCY), NULL), ";channels=", NULL), _tmp6_ = g_strdup_printf ("%i", RYGEL_L16_TRANSCODER_CHANNELS), NULL), _g_free0 (_tmp6_), _g_free0 (_tmp5_), _g_free0 (_tmp4_), _g_free0 (_tmp3_), _g_free0 (_tmp2_), _g_free0 (_tmp1_), _g_free0 (_tmp0_), _tmp7_);
	self = (RygelL16Transcoder*) rygel_transcoder_construct (object_type, mime_type, "LPCM", RYGEL_MEDIA_ITEM_AUDIO_CLASS);
	self->priv->endianness = endianness;
	_g_free0 (mime_type);
	return self;
}


RygelL16Transcoder* rygel_l16_transcoder_new (Endianness endianness) {
	return rygel_l16_transcoder_construct (RYGEL_TYPE_L16_TRANSCODER, endianness);
}


static GstElement* rygel_l16_transcoder_real_create_source (RygelTranscoder* base, RygelMediaItem* item, GstElement* src, GError** error) {
	RygelL16Transcoder * self;
	GstElement* result;
	GError * _inner_error_;
	RygelL16TranscoderBin* _tmp0_;
	self = (RygelL16Transcoder*) base;
	g_return_val_if_fail (item != NULL, NULL);
	g_return_val_if_fail (src != NULL, NULL);
	_inner_error_ = NULL;
	_tmp0_ = rygel_l16_transcoder_bin_new (item, src, self, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return NULL;
	}
	result = (GstElement*) _tmp0_;
	return result;
}


static GUPnPDIDLLiteResource* rygel_l16_transcoder_real_add_resource (RygelTranscoder* base, GUPnPDIDLLiteItem* didl_item, RygelMediaItem* item, RygelTranscodeManager* manager, GError** error) {
	RygelL16Transcoder * self;
	GUPnPDIDLLiteResource* result;
	GError * _inner_error_;
	GUPnPDIDLLiteResource* resource;
	self = (RygelL16Transcoder*) base;
	g_return_val_if_fail (didl_item != NULL, NULL);
	g_return_val_if_fail (item != NULL, NULL);
	g_return_val_if_fail (manager != NULL, NULL);
	_inner_error_ = NULL;
	resource = RYGEL_TRANSCODER_CLASS (rygel_l16_transcoder_parent_class)->add_resource (RYGEL_TRANSCODER (self), didl_item, item, manager, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return NULL;
	}
	if (resource == NULL) {
		result = NULL;
		_g_object_unref0 (resource);
		return result;
	}
	gupnp_didl_lite_resource_set_sample_freq (resource, RYGEL_L16_TRANSCODER_FREQUENCY);
	gupnp_didl_lite_resource_set_audio_channels (resource, RYGEL_L16_TRANSCODER_CHANNELS);
	gupnp_didl_lite_resource_set_bits_per_sample (resource, RYGEL_L16_TRANSCODER_WIDTH);
	gupnp_didl_lite_resource_set_bitrate (resource, ((RYGEL_L16_TRANSCODER_FREQUENCY * RYGEL_L16_TRANSCODER_CHANNELS) * RYGEL_L16_TRANSCODER_WIDTH) / 8);
	result = resource;
	return result;
}


static guint rygel_l16_transcoder_real_get_distance (RygelTranscoder* base, RygelMediaItem* item) {
	RygelL16Transcoder * self;
	guint result;
	guint distance;
	self = (RygelL16Transcoder*) base;
	g_return_val_if_fail (item != NULL, 0U);
	if (g_str_has_prefix (item->upnp_class, RYGEL_MEDIA_ITEM_IMAGE_CLASS)) {
		result = G_MAXUINT;
		return result;
	}
	distance = 0U;
	if (g_str_has_prefix (item->upnp_class, RYGEL_MEDIA_ITEM_AUDIO_CLASS)) {
		distance = 0;
		if (item->sample_freq > 0) {
			distance = distance + ((guint) abs (item->sample_freq - RYGEL_L16_TRANSCODER_FREQUENCY));
		}
		if (item->n_audio_channels > 0) {
			distance = distance + ((guint) abs (item->n_audio_channels - RYGEL_L16_TRANSCODER_CHANNELS));
		}
		if (item->bits_per_sample > 0) {
			distance = distance + ((guint) abs (item->bits_per_sample - RYGEL_L16_TRANSCODER_WIDTH));
		}
	} else {
		distance = G_MAXUINT / 2;
	}
	result = distance;
	return result;
}


static gpointer _gst_object_ref0 (gpointer self) {
	return self ? gst_object_ref (self) : NULL;
}


static inline void _dynamic_set_caps5 (GstElement* obj, GstCaps* value) {
	g_object_set (obj, "caps", value, NULL);
}


GstElement* rygel_l16_transcoder_create_encoder (RygelL16Transcoder* self, RygelMediaItem* item, const char* src_pad_name, const char* sink_pad_name, GError** error) {
	GstElement* result;
	GError * _inner_error_;
	GstElement* convert1;
	GstElement* resample;
	GstElement* audiorate;
	GstElement* convert2;
	GstElement* capsfilter;
	GstBin* bin;
	GstCaps* _tmp0_;
	GstPad* pad;
	GstGhostPad* ghost;
	GstPad* _tmp1_;
	GstGhostPad* _tmp2_;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (item != NULL, NULL);
	_inner_error_ = NULL;
	convert1 = rygel_gst_utils_create_element (RYGEL_L16_TRANSCODER_AUDIO_CONVERT, NULL, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return NULL;
	}
	resample = rygel_gst_utils_create_element (RYGEL_L16_TRANSCODER_AUDIO_RESAMPLE, RYGEL_L16_TRANSCODER_AUDIO_RESAMPLE, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_gst_object_unref0 (convert1);
		return NULL;
	}
	audiorate = rygel_gst_utils_create_element (RYGEL_L16_TRANSCODER_AUDIO_RATE, NULL, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_gst_object_unref0 (convert1);
		_gst_object_unref0 (resample);
		return NULL;
	}
	convert2 = rygel_gst_utils_create_element (RYGEL_L16_TRANSCODER_AUDIO_CONVERT, NULL, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_gst_object_unref0 (convert1);
		_gst_object_unref0 (resample);
		_gst_object_unref0 (audiorate);
		return NULL;
	}
	capsfilter = rygel_gst_utils_create_element (RYGEL_L16_TRANSCODER_CAPS_FILTER, RYGEL_L16_TRANSCODER_CAPS_FILTER, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_gst_object_unref0 (convert1);
		_gst_object_unref0 (resample);
		_gst_object_unref0 (audiorate);
		_gst_object_unref0 (convert2);
		return NULL;
	}
	bin = (GstBin*) gst_bin_new ("l16-encoder-bin");
	gst_bin_add_many (bin, _gst_object_ref0 (convert1), _gst_object_ref0 (resample), _gst_object_ref0 (audiorate), _gst_object_ref0 (convert2), _gst_object_ref0 (capsfilter), NULL);
	_dynamic_set_caps5 (capsfilter, _tmp0_ = gst_caps_new_simple ("audio/x-raw-int", "channels", G_TYPE_INT, RYGEL_L16_TRANSCODER_CHANNELS, "rate", G_TYPE_INT, RYGEL_L16_TRANSCODER_FREQUENCY, "width", G_TYPE_INT, RYGEL_L16_TRANSCODER_WIDTH, "depth", G_TYPE_INT, RYGEL_L16_TRANSCODER_DEPTH, "signed", G_TYPE_BOOLEAN, RYGEL_L16_TRANSCODER_SIGNED, "endianness", G_TYPE_INT, self->priv->endianness, NULL));
	_gst_caps_unref0 (_tmp0_);
	gst_element_link_many (convert1, resample, audiorate, convert2, capsfilter, NULL);
	pad = gst_element_get_static_pad (convert1, "sink");
	ghost = (GstGhostPad*) gst_ghost_pad_new (sink_pad_name, pad);
	gst_element_add_pad ((GstElement*) bin, _gst_object_ref0 ((GstPad*) ghost));
	pad = (_tmp1_ = gst_element_get_static_pad (capsfilter, "src"), _gst_object_unref0 (pad), _tmp1_);
	ghost = (_tmp2_ = (GstGhostPad*) gst_ghost_pad_new (src_pad_name, pad), _gst_object_unref0 (ghost), _tmp2_);
	gst_element_add_pad ((GstElement*) bin, _gst_object_ref0 ((GstPad*) ghost));
	result = (GstElement*) bin;
	_gst_object_unref0 (convert1);
	_gst_object_unref0 (resample);
	_gst_object_unref0 (audiorate);
	_gst_object_unref0 (convert2);
	_gst_object_unref0 (capsfilter);
	_gst_object_unref0 (pad);
	_gst_object_unref0 (ghost);
	return result;
}


static void rygel_l16_transcoder_class_init (RygelL16TranscoderClass * klass) {
	rygel_l16_transcoder_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelL16TranscoderPrivate));
	RYGEL_TRANSCODER_CLASS (klass)->create_source = rygel_l16_transcoder_real_create_source;
	RYGEL_TRANSCODER_CLASS (klass)->add_resource = rygel_l16_transcoder_real_add_resource;
	RYGEL_TRANSCODER_CLASS (klass)->get_distance = rygel_l16_transcoder_real_get_distance;
	G_OBJECT_CLASS (klass)->finalize = rygel_l16_transcoder_finalize;
}


static void rygel_l16_transcoder_instance_init (RygelL16Transcoder * self) {
	self->priv = RYGEL_L16_TRANSCODER_GET_PRIVATE (self);
}


static void rygel_l16_transcoder_finalize (GObject* obj) {
	RygelL16Transcoder * self;
	self = RYGEL_L16_TRANSCODER (obj);
	G_OBJECT_CLASS (rygel_l16_transcoder_parent_class)->finalize (obj);
}


GType rygel_l16_transcoder_get_type (void) {
	static GType rygel_l16_transcoder_type_id = 0;
	if (rygel_l16_transcoder_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelL16TranscoderClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_l16_transcoder_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelL16Transcoder), 0, (GInstanceInitFunc) rygel_l16_transcoder_instance_init, NULL };
		rygel_l16_transcoder_type_id = g_type_register_static (RYGEL_TYPE_TRANSCODER, "RygelL16Transcoder", &g_define_type_info, 0);
	}
	return rygel_l16_transcoder_type_id;
}




