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
#include <stdlib.h>
#include <string.h>


#define RYGEL_TYPE_MP2_TS_TRANSCODER_BIN (rygel_mp2_ts_transcoder_bin_get_type ())
#define RYGEL_MP2_TS_TRANSCODER_BIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MP2_TS_TRANSCODER_BIN, RygelMP2TSTranscoderBin))
#define RYGEL_MP2_TS_TRANSCODER_BIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MP2_TS_TRANSCODER_BIN, RygelMP2TSTranscoderBinClass))
#define RYGEL_IS_MP2_TS_TRANSCODER_BIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MP2_TS_TRANSCODER_BIN))
#define RYGEL_IS_MP2_TS_TRANSCODER_BIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MP2_TS_TRANSCODER_BIN))
#define RYGEL_MP2_TS_TRANSCODER_BIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MP2_TS_TRANSCODER_BIN, RygelMP2TSTranscoderBinClass))

typedef struct _RygelMP2TSTranscoderBin RygelMP2TSTranscoderBin;
typedef struct _RygelMP2TSTranscoderBinClass RygelMP2TSTranscoderBinClass;
typedef struct _RygelMP2TSTranscoderBinPrivate RygelMP2TSTranscoderBinPrivate;
#define _gst_object_unref0(var) ((var == NULL) ? NULL : (var = (gst_object_unref (var), NULL)))

#define RYGEL_TYPE_MP3_LAYER (rygel_mp3_layer_get_type ())

#define RYGEL_TYPE_TRANSCODER (rygel_transcoder_get_type ())
#define RYGEL_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRANSCODER, RygelTranscoder))
#define RYGEL_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRANSCODER, RygelTranscoderClass))
#define RYGEL_IS_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRANSCODER))
#define RYGEL_IS_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRANSCODER))
#define RYGEL_TRANSCODER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRANSCODER, RygelTranscoderClass))

typedef struct _RygelTranscoder RygelTranscoder;
typedef struct _RygelTranscoderClass RygelTranscoderClass;

#define RYGEL_TYPE_MP3_TRANSCODER (rygel_mp3_transcoder_get_type ())
#define RYGEL_MP3_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MP3_TRANSCODER, RygelMP3Transcoder))
#define RYGEL_MP3_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MP3_TRANSCODER, RygelMP3TranscoderClass))
#define RYGEL_IS_MP3_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MP3_TRANSCODER))
#define RYGEL_IS_MP3_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MP3_TRANSCODER))
#define RYGEL_MP3_TRANSCODER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MP3_TRANSCODER, RygelMP3TranscoderClass))

typedef struct _RygelMP3Transcoder RygelMP3Transcoder;
typedef struct _RygelMP3TranscoderClass RygelMP3TranscoderClass;

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
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define RYGEL_TYPE_MP2_TS_TRANSCODER (rygel_mp2_ts_transcoder_get_type ())
#define RYGEL_MP2_TS_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MP2_TS_TRANSCODER, RygelMP2TSTranscoder))
#define RYGEL_MP2_TS_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MP2_TS_TRANSCODER, RygelMP2TSTranscoderClass))
#define RYGEL_IS_MP2_TS_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MP2_TS_TRANSCODER))
#define RYGEL_IS_MP2_TS_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MP2_TS_TRANSCODER))
#define RYGEL_MP2_TS_TRANSCODER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MP2_TS_TRANSCODER, RygelMP2TSTranscoderClass))

typedef struct _RygelMP2TSTranscoder RygelMP2TSTranscoder;
typedef struct _RygelMP2TSTranscoderClass RygelMP2TSTranscoderClass;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _RygelMP2TSTranscoderBin {
	GstBin parent_instance;
	RygelMP2TSTranscoderBinPrivate * priv;
};

struct _RygelMP2TSTranscoderBinClass {
	GstBinClass parent_class;
};

struct _RygelMP2TSTranscoderBinPrivate {
	GstElement* audio_enc;
	GstElement* video_enc;
	GstElement* muxer;
};

typedef enum  {
	RYGEL_MP3_LAYER_TWO = 1,
	RYGEL_MP3_LAYER_THREE = 2
} RygelMP3Layer;

typedef enum  {
	RYGEL_LIVE_RESPONSE_ERROR_MISSING_PLUGIN,
	RYGEL_LIVE_RESPONSE_ERROR_LINK
} RygelLiveResponseError;
#define RYGEL_LIVE_RESPONSE_ERROR rygel_live_response_error_quark ()

static gpointer rygel_mp2_ts_transcoder_bin_parent_class = NULL;

GType rygel_mp2_ts_transcoder_bin_get_type (void);
#define RYGEL_MP2_TS_TRANSCODER_BIN_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_MP2_TS_TRANSCODER_BIN, RygelMP2TSTranscoderBinPrivate))
enum  {
	RYGEL_MP2_TS_TRANSCODER_BIN_DUMMY_PROPERTY
};
#define RYGEL_MP2_TS_TRANSCODER_BIN_DECODEBIN "decodebin2"
#define RYGEL_MP2_TS_TRANSCODER_BIN_MUXER "mpegtsmux"
#define RYGEL_MP2_TS_TRANSCODER_BIN_AUDIO_ENC_SINK "audio-enc-sink-pad"
#define RYGEL_MP2_TS_TRANSCODER_BIN_VIDEO_ENC_SINK "sink"
GstElement* rygel_gst_utils_create_element (const char* factoryname, const char* name, GError** error);
GType rygel_mp3_layer_get_type (void);
RygelMP3Transcoder* rygel_mp3_transcoder_new (RygelMP3Layer layer);
RygelMP3Transcoder* rygel_mp3_transcoder_construct (GType object_type, RygelMP3Layer layer);
GType rygel_transcoder_get_type (void);
GType rygel_mp3_transcoder_get_type (void);
GType rygel_media_object_get_type (void);
GType rygel_media_item_get_type (void);
GstElement* rygel_mp3_transcoder_create_encoder (RygelMP3Transcoder* self, RygelMediaItem* item, const char* src_pad_name, const char* sink_pad_name, GError** error);
GType rygel_mp2_ts_transcoder_get_type (void);
GstElement* rygel_mp2_ts_transcoder_create_encoder (RygelMP2TSTranscoder* self, RygelMediaItem* item, const char* src_pad_name, const char* sink_pad_name, GError** error);
static void rygel_mp2_ts_transcoder_bin_decodebin_pad_added (RygelMP2TSTranscoderBin* self, GstElement* decodebin, GstPad* new_pad);
static void _rygel_mp2_ts_transcoder_bin_decodebin_pad_added_gst_element_pad_added (GstElement* _sender, GstPad* pad, gpointer self);
RygelMP2TSTranscoderBin* rygel_mp2_ts_transcoder_bin_new (RygelMediaItem* item, GstElement* src, RygelMP2TSTranscoder* transcoder, GError** error);
RygelMP2TSTranscoderBin* rygel_mp2_ts_transcoder_bin_construct (GType object_type, RygelMediaItem* item, GstElement* src, RygelMP2TSTranscoder* transcoder, GError** error);
void rygel_gst_utils_post_error (GstElement* dest, GError* _error_);
GQuark rygel_live_response_error_quark (void);
static void rygel_mp2_ts_transcoder_bin_finalize (GObject* obj);



static gpointer _gst_object_ref0 (gpointer self) {
	return self ? gst_object_ref (self) : NULL;
}


static void _rygel_mp2_ts_transcoder_bin_decodebin_pad_added_gst_element_pad_added (GstElement* _sender, GstPad* pad, gpointer self) {
	rygel_mp2_ts_transcoder_bin_decodebin_pad_added (self, _sender, pad);
}


RygelMP2TSTranscoderBin* rygel_mp2_ts_transcoder_bin_construct (GType object_type, RygelMediaItem* item, GstElement* src, RygelMP2TSTranscoder* transcoder, GError** error) {
	GError * _inner_error_;
	RygelMP2TSTranscoderBin * self;
	GstElement* decodebin;
	RygelMP3Transcoder* mp3_transcoder;
	GstElement* _tmp0_;
	GstElement* _tmp1_;
	GstElement* _tmp2_;
	GstElement* _tmp3_;
	GstElement* _tmp4_;
	GstElement* _tmp5_;
	GstPad* src_pad;
	GstGhostPad* ghost;
	g_return_val_if_fail (item != NULL, NULL);
	g_return_val_if_fail (src != NULL, NULL);
	g_return_val_if_fail (transcoder != NULL, NULL);
	_inner_error_ = NULL;
	self = g_object_newv (object_type, 0, NULL);
	decodebin = rygel_gst_utils_create_element (RYGEL_MP2_TS_TRANSCODER_BIN_DECODEBIN, RYGEL_MP2_TS_TRANSCODER_BIN_DECODEBIN, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return;
	}
	mp3_transcoder = rygel_mp3_transcoder_new (RYGEL_MP3_LAYER_TWO);
	_tmp0_ = rygel_mp3_transcoder_create_encoder (mp3_transcoder, item, NULL, RYGEL_MP2_TS_TRANSCODER_BIN_AUDIO_ENC_SINK, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_gst_object_unref0 (decodebin);
		_g_object_unref0 (mp3_transcoder);
		return;
	}
	self->priv->audio_enc = (_tmp1_ = _tmp0_, _gst_object_unref0 (self->priv->audio_enc), _tmp1_);
	_tmp2_ = rygel_mp2_ts_transcoder_create_encoder (transcoder, item, NULL, RYGEL_MP2_TS_TRANSCODER_BIN_VIDEO_ENC_SINK, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_gst_object_unref0 (decodebin);
		_g_object_unref0 (mp3_transcoder);
		return;
	}
	self->priv->video_enc = (_tmp3_ = _tmp2_, _gst_object_unref0 (self->priv->video_enc), _tmp3_);
	_tmp4_ = rygel_gst_utils_create_element (RYGEL_MP2_TS_TRANSCODER_BIN_MUXER, RYGEL_MP2_TS_TRANSCODER_BIN_MUXER, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_gst_object_unref0 (decodebin);
		_g_object_unref0 (mp3_transcoder);
		return;
	}
	self->priv->muxer = (_tmp5_ = _tmp4_, _gst_object_unref0 (self->priv->muxer), _tmp5_);
	gst_bin_add_many ((GstBin*) self, _gst_object_ref0 (src), _gst_object_ref0 (decodebin), _gst_object_ref0 (self->priv->audio_enc), _gst_object_ref0 (self->priv->video_enc), _gst_object_ref0 (self->priv->muxer), NULL);
	gst_element_link (src, decodebin);
	src_pad = gst_element_get_static_pad (self->priv->muxer, "src");
	ghost = (GstGhostPad*) gst_ghost_pad_new (NULL, src_pad);
	gst_element_add_pad ((GstElement*) self, _gst_object_ref0 ((GstPad*) ghost));
	g_signal_connect_object (decodebin, "pad-added", (GCallback) _rygel_mp2_ts_transcoder_bin_decodebin_pad_added_gst_element_pad_added, self, 0);
	_gst_object_unref0 (decodebin);
	_g_object_unref0 (mp3_transcoder);
	_gst_object_unref0 (src_pad);
	_gst_object_unref0 (ghost);
	return self;
}


RygelMP2TSTranscoderBin* rygel_mp2_ts_transcoder_bin_new (RygelMediaItem* item, GstElement* src, RygelMP2TSTranscoder* transcoder, GError** error) {
	return rygel_mp2_ts_transcoder_bin_construct (RYGEL_TYPE_MP2_TS_TRANSCODER_BIN, item, src, transcoder, error);
}


static void rygel_mp2_ts_transcoder_bin_decodebin_pad_added (RygelMP2TSTranscoderBin* self, GstElement* decodebin, GstPad* new_pad) {
	GstElement* encoder;
	GstPad* enc_pad;
	GstPad* audio_enc_pad;
	GstPad* video_enc_pad;
	g_return_if_fail (self != NULL);
	g_return_if_fail (decodebin != NULL);
	g_return_if_fail (new_pad != NULL);
	encoder = NULL;
	enc_pad = NULL;
	audio_enc_pad = _gst_object_ref0 (gst_element_get_pad (self->priv->audio_enc, RYGEL_MP2_TS_TRANSCODER_BIN_AUDIO_ENC_SINK));
	video_enc_pad = _gst_object_ref0 (gst_element_get_pad (self->priv->video_enc, RYGEL_MP2_TS_TRANSCODER_BIN_VIDEO_ENC_SINK));
	if (gst_pad_can_link (new_pad, audio_enc_pad)) {
		GstElement* _tmp0_;
		GstPad* _tmp1_;
		encoder = (_tmp0_ = _gst_object_ref0 (self->priv->audio_enc), _gst_object_unref0 (encoder), _tmp0_);
		enc_pad = (_tmp1_ = _gst_object_ref0 (audio_enc_pad), _gst_object_unref0 (enc_pad), _tmp1_);
	} else {
		if (gst_pad_can_link (new_pad, video_enc_pad)) {
			GstElement* _tmp2_;
			GstPad* _tmp3_;
			encoder = (_tmp2_ = _gst_object_ref0 (self->priv->video_enc), _gst_object_unref0 (encoder), _tmp2_);
			enc_pad = (_tmp3_ = _gst_object_ref0 (video_enc_pad), _gst_object_unref0 (enc_pad), _tmp3_);
		} else {
			_gst_object_unref0 (encoder);
			_gst_object_unref0 (enc_pad);
			_gst_object_unref0 (audio_enc_pad);
			_gst_object_unref0 (video_enc_pad);
			return;
		}
	}
	gst_element_link (encoder, self->priv->muxer);
	if (gst_pad_link (new_pad, enc_pad) != GST_PAD_LINK_OK) {
		GError* _tmp4_;
		rygel_gst_utils_post_error ((GstElement*) self, _tmp4_ = g_error_new (RYGEL_LIVE_RESPONSE_ERROR, RYGEL_LIVE_RESPONSE_ERROR_LINK, "Failed to link pad %s to %s", gst_object_get_name ((GstObject*) new_pad), gst_object_get_name ((GstObject*) enc_pad)));
		_g_error_free0 (_tmp4_);
		_gst_object_unref0 (encoder);
		_gst_object_unref0 (enc_pad);
		_gst_object_unref0 (audio_enc_pad);
		_gst_object_unref0 (video_enc_pad);
		return;
	}
	_gst_object_unref0 (encoder);
	_gst_object_unref0 (enc_pad);
	_gst_object_unref0 (audio_enc_pad);
	_gst_object_unref0 (video_enc_pad);
}


static void rygel_mp2_ts_transcoder_bin_class_init (RygelMP2TSTranscoderBinClass * klass) {
	rygel_mp2_ts_transcoder_bin_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelMP2TSTranscoderBinPrivate));
	G_OBJECT_CLASS (klass)->finalize = rygel_mp2_ts_transcoder_bin_finalize;
}


static void rygel_mp2_ts_transcoder_bin_instance_init (RygelMP2TSTranscoderBin * self) {
	self->priv = RYGEL_MP2_TS_TRANSCODER_BIN_GET_PRIVATE (self);
}


static void rygel_mp2_ts_transcoder_bin_finalize (GObject* obj) {
	RygelMP2TSTranscoderBin * self;
	self = RYGEL_MP2_TS_TRANSCODER_BIN (obj);
	_gst_object_unref0 (self->priv->audio_enc);
	_gst_object_unref0 (self->priv->video_enc);
	_gst_object_unref0 (self->priv->muxer);
	G_OBJECT_CLASS (rygel_mp2_ts_transcoder_bin_parent_class)->finalize (obj);
}


GType rygel_mp2_ts_transcoder_bin_get_type (void) {
	static GType rygel_mp2_ts_transcoder_bin_type_id = 0;
	if (rygel_mp2_ts_transcoder_bin_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMP2TSTranscoderBinClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_mp2_ts_transcoder_bin_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMP2TSTranscoderBin), 0, (GInstanceInitFunc) rygel_mp2_ts_transcoder_bin_instance_init, NULL };
		rygel_mp2_ts_transcoder_bin_type_id = g_type_register_static (GST_TYPE_BIN, "RygelMP2TSTranscoderBin", &g_define_type_info, 0);
	}
	return rygel_mp2_ts_transcoder_bin_type_id;
}




