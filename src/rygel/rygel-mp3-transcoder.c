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

#define RYGEL_TYPE_MP3_TRANSCODER (rygel_mp3_transcoder_get_type ())
#define RYGEL_MP3_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MP3_TRANSCODER, RygelMP3Transcoder))
#define RYGEL_MP3_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MP3_TRANSCODER, RygelMP3TranscoderClass))
#define RYGEL_IS_MP3_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MP3_TRANSCODER))
#define RYGEL_IS_MP3_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MP3_TRANSCODER))
#define RYGEL_MP3_TRANSCODER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MP3_TRANSCODER, RygelMP3TranscoderClass))

typedef struct _RygelMP3Transcoder RygelMP3Transcoder;
typedef struct _RygelMP3TranscoderClass RygelMP3TranscoderClass;
typedef struct _RygelMP3TranscoderPrivate RygelMP3TranscoderPrivate;

#define RYGEL_TYPE_MP3_LAYER (rygel_mp3_layer_get_type ())

#define RYGEL_TYPE_MP3_TRANSCODER_BIN (rygel_mp3_transcoder_bin_get_type ())
#define RYGEL_MP3_TRANSCODER_BIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MP3_TRANSCODER_BIN, RygelMP3TranscoderBin))
#define RYGEL_MP3_TRANSCODER_BIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MP3_TRANSCODER_BIN, RygelMP3TranscoderBinClass))
#define RYGEL_IS_MP3_TRANSCODER_BIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MP3_TRANSCODER_BIN))
#define RYGEL_IS_MP3_TRANSCODER_BIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MP3_TRANSCODER_BIN))
#define RYGEL_MP3_TRANSCODER_BIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MP3_TRANSCODER_BIN, RygelMP3TranscoderBinClass))

typedef struct _RygelMP3TranscoderBin RygelMP3TranscoderBin;
typedef struct _RygelMP3TranscoderBinClass RygelMP3TranscoderBinClass;
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

#define TYPE_ENDIANNESS (endianness_get_type ())

#define RYGEL_TYPE_L16_TRANSCODER (rygel_l16_transcoder_get_type ())
#define RYGEL_L16_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_L16_TRANSCODER, RygelL16Transcoder))
#define RYGEL_L16_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_L16_TRANSCODER, RygelL16TranscoderClass))
#define RYGEL_IS_L16_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_L16_TRANSCODER))
#define RYGEL_IS_L16_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_L16_TRANSCODER))
#define RYGEL_L16_TRANSCODER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_L16_TRANSCODER, RygelL16TranscoderClass))

typedef struct _RygelL16Transcoder RygelL16Transcoder;
typedef struct _RygelL16TranscoderClass RygelL16TranscoderClass;
#define _gst_object_unref0(var) ((var == NULL) ? NULL : (var = (gst_object_unref (var), NULL)))

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

struct _RygelMP3Transcoder {
	RygelTranscoder parent_instance;
	RygelMP3TranscoderPrivate * priv;
};

struct _RygelMP3TranscoderClass {
	RygelTranscoderClass parent_class;
};

typedef enum  {
	RYGEL_MP3_LAYER_TWO = 1,
	RYGEL_MP3_LAYER_THREE = 2
} RygelMP3Layer;

struct _RygelMP3TranscoderPrivate {
	RygelMP3Layer layer;
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

typedef enum  {
	ENDIANNESS_LITTLE = G_LITTLE_ENDIAN,
	ENDIANNESS_BIG = G_BIG_ENDIAN
} Endianness;


static gpointer rygel_mp3_transcoder_parent_class = NULL;

GType rygel_transcoder_get_type (void);
GType rygel_media_object_get_type (void);
GType rygel_media_item_get_type (void);
GType rygel_transcode_manager_get_type (void);
GType rygel_mp3_transcoder_get_type (void);
GType rygel_mp3_layer_get_type (void);
#define RYGEL_MP3_TRANSCODER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_MP3_TRANSCODER, RygelMP3TranscoderPrivate))
enum  {
	RYGEL_MP3_TRANSCODER_DUMMY_PROPERTY
};
#define RYGEL_MP3_TRANSCODER_BITRATE 256
#define RYGEL_MP3_TRANSCODER_AUDIO_PARSER "mp3parse"
#define RYGEL_MP3_TRANSCODER_CONVERT_SINK_PAD "convert-sink-pad"
#define RYGEL_MEDIA_ITEM_AUDIO_CLASS "object.item.audioItem"
RygelTranscoder* rygel_transcoder_construct (GType object_type, const char* mime_type, const char* dlna_profile, const char* upnp_class);
RygelMP3Transcoder* rygel_mp3_transcoder_new (RygelMP3Layer layer);
RygelMP3Transcoder* rygel_mp3_transcoder_construct (GType object_type, RygelMP3Layer layer);
RygelMP3TranscoderBin* rygel_mp3_transcoder_bin_new (RygelMediaItem* item, GstElement* src, RygelMP3Transcoder* transcoder, GError** error);
RygelMP3TranscoderBin* rygel_mp3_transcoder_bin_construct (GType object_type, RygelMediaItem* item, GstElement* src, RygelMP3Transcoder* transcoder, GError** error);
GType rygel_mp3_transcoder_bin_get_type (void);
static GstElement* rygel_mp3_transcoder_real_create_source (RygelTranscoder* base, RygelMediaItem* item, GstElement* src, GError** error);
GUPnPDIDLLiteResource* rygel_transcoder_add_resource (RygelTranscoder* self, GUPnPDIDLLiteItem* didl_item, RygelMediaItem* item, RygelTranscodeManager* manager, GError** error);
static GUPnPDIDLLiteResource* rygel_mp3_transcoder_real_add_resource (RygelTranscoder* base, GUPnPDIDLLiteItem* didl_item, RygelMediaItem* item, RygelTranscodeManager* manager, GError** error);
GType rygel_media_container_get_type (void);
gpointer rygel_icon_info_ref (gpointer instance);
void rygel_icon_info_unref (gpointer instance);
GParamSpec* rygel_param_spec_icon_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_icon_info (GValue* value, gpointer v_object);
gpointer rygel_value_get_icon_info (const GValue* value);
GType rygel_icon_info_get_type (void);
GType rygel_thumbnail_get_type (void);
#define RYGEL_MEDIA_ITEM_IMAGE_CLASS "object.item.imageItem"
static guint rygel_mp3_transcoder_real_get_distance (RygelTranscoder* base, RygelMediaItem* item);
GType endianness_get_type (void);
RygelL16Transcoder* rygel_l16_transcoder_new (Endianness endianness);
RygelL16Transcoder* rygel_l16_transcoder_construct (GType object_type, Endianness endianness);
GType rygel_l16_transcoder_get_type (void);
GstElement* rygel_l16_transcoder_create_encoder (RygelL16Transcoder* self, RygelMediaItem* item, const char* src_pad_name, const char* sink_pad_name, GError** error);
GstElement* rygel_gst_utils_create_element (const char* factoryname, const char* name, GError** error);
static inline void _dynamic_set_quality3 (GstElement* obj, gint value);
static inline void _dynamic_set_bitrate4 (GstElement* obj, gint value);
GstElement* rygel_mp3_transcoder_create_encoder (RygelMP3Transcoder* self, RygelMediaItem* item, const char* src_pad_name, const char* sink_pad_name, GError** error);
static void rygel_mp3_transcoder_finalize (GObject* obj);

static const char* RYGEL_MP3_TRANSCODER_AUDIO_ENCODER[] = {NULL, "twolame", "lame"};


RygelMP3Transcoder* rygel_mp3_transcoder_construct (GType object_type, RygelMP3Layer layer) {
	RygelMP3Transcoder * self;
	self = (RygelMP3Transcoder*) rygel_transcoder_construct (object_type, "audio/mpeg", "MP3", RYGEL_MEDIA_ITEM_AUDIO_CLASS);
	self->priv->layer = layer;
	return self;
}


RygelMP3Transcoder* rygel_mp3_transcoder_new (RygelMP3Layer layer) {
	return rygel_mp3_transcoder_construct (RYGEL_TYPE_MP3_TRANSCODER, layer);
}


static GstElement* rygel_mp3_transcoder_real_create_source (RygelTranscoder* base, RygelMediaItem* item, GstElement* src, GError** error) {
	RygelMP3Transcoder * self;
	GstElement* result;
	GError * _inner_error_;
	RygelMP3TranscoderBin* _tmp0_;
	self = (RygelMP3Transcoder*) base;
	g_return_val_if_fail (item != NULL, NULL);
	g_return_val_if_fail (src != NULL, NULL);
	_inner_error_ = NULL;
	_tmp0_ = rygel_mp3_transcoder_bin_new (item, src, self, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return NULL;
	}
	result = (GstElement*) _tmp0_;
	return result;
}


static GUPnPDIDLLiteResource* rygel_mp3_transcoder_real_add_resource (RygelTranscoder* base, GUPnPDIDLLiteItem* didl_item, RygelMediaItem* item, RygelTranscodeManager* manager, GError** error) {
	RygelMP3Transcoder * self;
	GUPnPDIDLLiteResource* result;
	GError * _inner_error_;
	GUPnPDIDLLiteResource* resource;
	self = (RygelMP3Transcoder*) base;
	g_return_val_if_fail (didl_item != NULL, NULL);
	g_return_val_if_fail (item != NULL, NULL);
	g_return_val_if_fail (manager != NULL, NULL);
	_inner_error_ = NULL;
	resource = RYGEL_TRANSCODER_CLASS (rygel_mp3_transcoder_parent_class)->add_resource (RYGEL_TRANSCODER (self), didl_item, item, manager, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return NULL;
	}
	if (resource == NULL) {
		result = NULL;
		_g_object_unref0 (resource);
		return result;
	}
	gupnp_didl_lite_resource_set_bitrate (resource, (RYGEL_MP3_TRANSCODER_BITRATE * 1000) / 8);
	result = resource;
	return result;
}


static guint rygel_mp3_transcoder_real_get_distance (RygelTranscoder* base, RygelMediaItem* item) {
	RygelMP3Transcoder * self;
	guint result;
	guint distance;
	self = (RygelMP3Transcoder*) base;
	g_return_val_if_fail (item != NULL, 0U);
	if (g_str_has_prefix (item->upnp_class, RYGEL_MEDIA_ITEM_IMAGE_CLASS)) {
		result = G_MAXUINT;
		return result;
	}
	distance = 0U;
	if (g_str_has_prefix (item->upnp_class, RYGEL_MEDIA_ITEM_AUDIO_CLASS)) {
		distance = 0;
		if (item->bitrate > 0) {
			distance = distance + ((guint) abs (item->bitrate - RYGEL_MP3_TRANSCODER_BITRATE));
		}
	} else {
		distance = G_MAXUINT / 2;
	}
	result = distance;
	return result;
}


static inline void _dynamic_set_quality3 (GstElement* obj, gint value) {
	g_object_set (obj, "quality", value, NULL);
}


static inline void _dynamic_set_bitrate4 (GstElement* obj, gint value) {
	g_object_set (obj, "bitrate", value, NULL);
}


static gpointer _gst_object_ref0 (gpointer self) {
	return self ? gst_object_ref (self) : NULL;
}


GstElement* rygel_mp3_transcoder_create_encoder (RygelMP3Transcoder* self, RygelMediaItem* item, const char* src_pad_name, const char* sink_pad_name, GError** error) {
	GstElement* result;
	GError * _inner_error_;
	RygelL16Transcoder* l16_transcoder;
	GstElement* convert;
	GstElement* encoder;
	GstElement* parser;
	GstBin* bin;
	GstPad* pad;
	GstGhostPad* ghost;
	GstPad* _tmp0_;
	GstGhostPad* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (item != NULL, NULL);
	_inner_error_ = NULL;
	l16_transcoder = rygel_l16_transcoder_new (ENDIANNESS_LITTLE);
	convert = rygel_l16_transcoder_create_encoder (l16_transcoder, item, NULL, RYGEL_MP3_TRANSCODER_CONVERT_SINK_PAD, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_g_object_unref0 (l16_transcoder);
		return NULL;
	}
	encoder = rygel_gst_utils_create_element (RYGEL_MP3_TRANSCODER_AUDIO_ENCODER[self->priv->layer], RYGEL_MP3_TRANSCODER_AUDIO_ENCODER[self->priv->layer], &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_g_object_unref0 (l16_transcoder);
		_gst_object_unref0 (convert);
		return NULL;
	}
	parser = rygel_gst_utils_create_element (RYGEL_MP3_TRANSCODER_AUDIO_PARSER, RYGEL_MP3_TRANSCODER_AUDIO_PARSER, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_g_object_unref0 (l16_transcoder);
		_gst_object_unref0 (convert);
		_gst_object_unref0 (encoder);
		return NULL;
	}
	if (self->priv->layer == RYGEL_MP3_LAYER_THREE) {
		_dynamic_set_quality3 (encoder, 0);
	}
	_dynamic_set_bitrate4 (encoder, RYGEL_MP3_TRANSCODER_BITRATE);
	bin = (GstBin*) gst_bin_new ("mp3-encoder-bin");
	gst_bin_add_many (bin, _gst_object_ref0 (convert), _gst_object_ref0 (encoder), _gst_object_ref0 (parser), NULL);
	gst_element_link_many (convert, encoder, parser, NULL);
	pad = gst_element_get_static_pad (convert, RYGEL_MP3_TRANSCODER_CONVERT_SINK_PAD);
	ghost = (GstGhostPad*) gst_ghost_pad_new (sink_pad_name, pad);
	gst_element_add_pad ((GstElement*) bin, _gst_object_ref0 ((GstPad*) ghost));
	pad = (_tmp0_ = gst_element_get_static_pad (parser, "src"), _gst_object_unref0 (pad), _tmp0_);
	ghost = (_tmp1_ = (GstGhostPad*) gst_ghost_pad_new (src_pad_name, pad), _gst_object_unref0 (ghost), _tmp1_);
	gst_element_add_pad ((GstElement*) bin, _gst_object_ref0 ((GstPad*) ghost));
	result = (GstElement*) bin;
	_g_object_unref0 (l16_transcoder);
	_gst_object_unref0 (convert);
	_gst_object_unref0 (encoder);
	_gst_object_unref0 (parser);
	_gst_object_unref0 (pad);
	_gst_object_unref0 (ghost);
	return result;
}


static void rygel_mp3_transcoder_class_init (RygelMP3TranscoderClass * klass) {
	rygel_mp3_transcoder_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelMP3TranscoderPrivate));
	RYGEL_TRANSCODER_CLASS (klass)->create_source = rygel_mp3_transcoder_real_create_source;
	RYGEL_TRANSCODER_CLASS (klass)->add_resource = rygel_mp3_transcoder_real_add_resource;
	RYGEL_TRANSCODER_CLASS (klass)->get_distance = rygel_mp3_transcoder_real_get_distance;
	G_OBJECT_CLASS (klass)->finalize = rygel_mp3_transcoder_finalize;
}


static void rygel_mp3_transcoder_instance_init (RygelMP3Transcoder * self) {
	self->priv = RYGEL_MP3_TRANSCODER_GET_PRIVATE (self);
}


static void rygel_mp3_transcoder_finalize (GObject* obj) {
	RygelMP3Transcoder * self;
	self = RYGEL_MP3_TRANSCODER (obj);
	G_OBJECT_CLASS (rygel_mp3_transcoder_parent_class)->finalize (obj);
}


GType rygel_mp3_transcoder_get_type (void) {
	static GType rygel_mp3_transcoder_type_id = 0;
	if (rygel_mp3_transcoder_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMP3TranscoderClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_mp3_transcoder_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMP3Transcoder), 0, (GInstanceInitFunc) rygel_mp3_transcoder_instance_init, NULL };
		rygel_mp3_transcoder_type_id = g_type_register_static (RYGEL_TYPE_TRANSCODER, "RygelMP3Transcoder", &g_define_type_info, 0);
	}
	return rygel_mp3_transcoder_type_id;
}




