/* rygel-wmv-transcoder-bin.c generated by valac, the Vala compiler
 * generated from rygel-wmv-transcoder-bin.vala, do not modify */

/*
 * Copyright (C) 2009 Jens Georg <mail@jensge.org>.
 *
 * Author: Jens Georg <mail@jensge.org>
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
#include <glib/gi18n-lib.h>


#define RYGEL_TYPE_WMV_TRANSCODER_BIN (rygel_wmv_transcoder_bin_get_type ())
#define RYGEL_WMV_TRANSCODER_BIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_WMV_TRANSCODER_BIN, RygelWMVTranscoderBin))
#define RYGEL_WMV_TRANSCODER_BIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_WMV_TRANSCODER_BIN, RygelWMVTranscoderBinClass))
#define RYGEL_IS_WMV_TRANSCODER_BIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_WMV_TRANSCODER_BIN))
#define RYGEL_IS_WMV_TRANSCODER_BIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_WMV_TRANSCODER_BIN))
#define RYGEL_WMV_TRANSCODER_BIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_WMV_TRANSCODER_BIN, RygelWMVTranscoderBinClass))

typedef struct _RygelWMVTranscoderBin RygelWMVTranscoderBin;
typedef struct _RygelWMVTranscoderBinClass RygelWMVTranscoderBinClass;
typedef struct _RygelWMVTranscoderBinPrivate RygelWMVTranscoderBinPrivate;
#define _gst_object_unref0(var) ((var == NULL) ? NULL : (var = (gst_object_unref (var), NULL)))

#define RYGEL_TYPE_TRANSCODER (rygel_transcoder_get_type ())
#define RYGEL_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRANSCODER, RygelTranscoder))
#define RYGEL_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRANSCODER, RygelTranscoderClass))
#define RYGEL_IS_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRANSCODER))
#define RYGEL_IS_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRANSCODER))
#define RYGEL_TRANSCODER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRANSCODER, RygelTranscoderClass))

typedef struct _RygelTranscoder RygelTranscoder;
typedef struct _RygelTranscoderClass RygelTranscoderClass;

#define RYGEL_TYPE_WMA_TRANSCODER (rygel_wma_transcoder_get_type ())
#define RYGEL_WMA_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_WMA_TRANSCODER, RygelWMATranscoder))
#define RYGEL_WMA_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_WMA_TRANSCODER, RygelWMATranscoderClass))
#define RYGEL_IS_WMA_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_WMA_TRANSCODER))
#define RYGEL_IS_WMA_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_WMA_TRANSCODER))
#define RYGEL_WMA_TRANSCODER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_WMA_TRANSCODER, RygelWMATranscoderClass))

typedef struct _RygelWMATranscoder RygelWMATranscoder;
typedef struct _RygelWMATranscoderClass RygelWMATranscoderClass;

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

#define RYGEL_TYPE_WMV_TRANSCODER (rygel_wmv_transcoder_get_type ())
#define RYGEL_WMV_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_WMV_TRANSCODER, RygelWMVTranscoder))
#define RYGEL_WMV_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_WMV_TRANSCODER, RygelWMVTranscoderClass))
#define RYGEL_IS_WMV_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_WMV_TRANSCODER))
#define RYGEL_IS_WMV_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_WMV_TRANSCODER))
#define RYGEL_WMV_TRANSCODER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_WMV_TRANSCODER, RygelWMVTranscoderClass))

typedef struct _RygelWMVTranscoder RygelWMVTranscoder;
typedef struct _RygelWMVTranscoderClass RygelWMVTranscoderClass;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _RygelWMVTranscoderBin {
	GstBin parent_instance;
	RygelWMVTranscoderBinPrivate * priv;
};

struct _RygelWMVTranscoderBinClass {
	GstBinClass parent_class;
};

struct _RygelWMVTranscoderBinPrivate {
	GstElement* audio_enc;
	GstElement* video_enc;
	GstElement* muxer;
};

typedef enum  {
	RYGEL_GST_ERROR_MISSING_PLUGIN,
	RYGEL_GST_ERROR_LINK
} RygelGstError;
#define RYGEL_GST_ERROR rygel_gst_error_quark ()

static gpointer rygel_wmv_transcoder_bin_parent_class = NULL;

GType rygel_wmv_transcoder_bin_get_type (void);
#define RYGEL_WMV_TRANSCODER_BIN_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_WMV_TRANSCODER_BIN, RygelWMVTranscoderBinPrivate))
enum  {
	RYGEL_WMV_TRANSCODER_BIN_DUMMY_PROPERTY
};
#define RYGEL_WMV_TRANSCODER_BIN_DECODEBIN "decodebin2"
#define RYGEL_WMV_TRANSCODER_BIN_MUXER "ffmux_asf"
#define RYGEL_WMV_TRANSCODER_BIN_AUDIO_ENC_SINK "audio-enc-sink-pad"
#define RYGEL_WMV_TRANSCODER_BIN_VIDEO_ENC_SINK "sink"
GstElement* rygel_gst_utils_create_element (const char* factoryname, const char* name, GError** error);
RygelWMATranscoder* rygel_wma_transcoder_new (void);
RygelWMATranscoder* rygel_wma_transcoder_construct (GType object_type);
GType rygel_transcoder_get_type (void);
GType rygel_wma_transcoder_get_type (void);
GType rygel_media_object_get_type (void);
GType rygel_media_item_get_type (void);
GstElement* rygel_wma_transcoder_create_encoder (RygelWMATranscoder* self, RygelMediaItem* item, const char* src_pad_name, const char* sink_pad_name, GError** error);
GType rygel_wmv_transcoder_get_type (void);
GstElement* rygel_wmv_transcoder_create_encoder (RygelWMVTranscoder* self, RygelMediaItem* item, const char* src_pad_name, const char* sink_pad_name, GError** error);
static void rygel_wmv_transcoder_bin_decodebin_pad_added (RygelWMVTranscoderBin* self, GstElement* decodebin, GstPad* new_pad);
static void _rygel_wmv_transcoder_bin_decodebin_pad_added_gst_element_pad_added (GstElement* _sender, GstPad* pad, gpointer self);
static gboolean rygel_wmv_transcoder_bin_autoplug_continue (GstElement* decodebin, GstPad* new_pad, GstCaps* caps, RygelWMVTranscoderBin* self);
RygelWMVTranscoderBin* rygel_wmv_transcoder_bin_new (RygelMediaItem* item, GstElement* src, RygelWMVTranscoder* transcoder, GError** error);
RygelWMVTranscoderBin* rygel_wmv_transcoder_bin_construct (GType object_type, RygelMediaItem* item, GstElement* src, RygelWMVTranscoder* transcoder, GError** error);
GQuark rygel_gst_error_quark (void);
void rygel_gst_utils_post_error (GstElement* dest, GError* _error_);
static void rygel_wmv_transcoder_bin_finalize (GObject* obj);



static gpointer _gst_object_ref0 (gpointer self) {
	return self ? gst_object_ref (self) : NULL;
}


#line 86 "rygel-wmv-transcoder-bin.vala"
static void _rygel_wmv_transcoder_bin_decodebin_pad_added_gst_element_pad_added (GstElement* _sender, GstPad* pad, gpointer self) {
#line 159 "rygel-wmv-transcoder-bin.c"
	rygel_wmv_transcoder_bin_decodebin_pad_added (self, _sender, pad);
}


#line 39 "rygel-wmv-transcoder-bin.vala"
RygelWMVTranscoderBin* rygel_wmv_transcoder_bin_construct (GType object_type, RygelMediaItem* item, GstElement* src, RygelWMVTranscoder* transcoder, GError** error) {
#line 166 "rygel-wmv-transcoder-bin.c"
	GError * _inner_error_;
	RygelWMVTranscoderBin * self;
	GstElement* decodebin;
	RygelWMATranscoder* wma_transcoder;
	GstElement* _tmp0_;
	GstElement* _tmp1_;
	GstElement* _tmp2_;
	GstElement* _tmp3_;
	GstElement* _tmp4_;
	GstElement* _tmp5_;
	GstPad* src_pad;
	GstGhostPad* ghost;
#line 39 "rygel-wmv-transcoder-bin.vala"
	g_return_val_if_fail (item != NULL, NULL);
#line 39 "rygel-wmv-transcoder-bin.vala"
	g_return_val_if_fail (src != NULL, NULL);
#line 39 "rygel-wmv-transcoder-bin.vala"
	g_return_val_if_fail (transcoder != NULL, NULL);
#line 185 "rygel-wmv-transcoder-bin.c"
	_inner_error_ = NULL;
	self = g_object_newv (object_type, 0, NULL);
#line 43 "rygel-wmv-transcoder-bin.vala"
	decodebin = rygel_gst_utils_create_element (RYGEL_WMV_TRANSCODER_BIN_DECODEBIN, RYGEL_WMV_TRANSCODER_BIN_DECODEBIN, &_inner_error_);
#line 190 "rygel-wmv-transcoder-bin.c"
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		gst_object_unref (self);
		return NULL;
	}
#line 45 "rygel-wmv-transcoder-bin.vala"
	wma_transcoder = rygel_wma_transcoder_new ();
#line 46 "rygel-wmv-transcoder-bin.vala"
	_tmp0_ = rygel_wma_transcoder_create_encoder (wma_transcoder, item, NULL, RYGEL_WMV_TRANSCODER_BIN_AUDIO_ENC_SINK, &_inner_error_);
#line 200 "rygel-wmv-transcoder-bin.c"
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_gst_object_unref0 (decodebin);
		_g_object_unref0 (wma_transcoder);
		gst_object_unref (self);
		return NULL;
	}
#line 46 "rygel-wmv-transcoder-bin.vala"
	self->priv->audio_enc = (_tmp1_ = _tmp0_, _gst_object_unref0 (self->priv->audio_enc), _tmp1_);
#line 49 "rygel-wmv-transcoder-bin.vala"
	_tmp2_ = rygel_wmv_transcoder_create_encoder (transcoder, item, NULL, RYGEL_WMV_TRANSCODER_BIN_VIDEO_ENC_SINK, &_inner_error_);
#line 212 "rygel-wmv-transcoder-bin.c"
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_gst_object_unref0 (decodebin);
		_g_object_unref0 (wma_transcoder);
		gst_object_unref (self);
		return NULL;
	}
#line 49 "rygel-wmv-transcoder-bin.vala"
	self->priv->video_enc = (_tmp3_ = _tmp2_, _gst_object_unref0 (self->priv->video_enc), _tmp3_);
#line 50 "rygel-wmv-transcoder-bin.vala"
	_tmp4_ = rygel_gst_utils_create_element (RYGEL_WMV_TRANSCODER_BIN_MUXER, RYGEL_WMV_TRANSCODER_BIN_MUXER, &_inner_error_);
#line 224 "rygel-wmv-transcoder-bin.c"
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_gst_object_unref0 (decodebin);
		_g_object_unref0 (wma_transcoder);
		gst_object_unref (self);
		return NULL;
	}
#line 50 "rygel-wmv-transcoder-bin.vala"
	self->priv->muxer = (_tmp5_ = _tmp4_, _gst_object_unref0 (self->priv->muxer), _tmp5_);
#line 52 "rygel-wmv-transcoder-bin.vala"
	gst_bin_add_many ((GstBin*) self, _gst_object_ref0 (src), _gst_object_ref0 (decodebin), _gst_object_ref0 (self->priv->audio_enc), _gst_object_ref0 (self->priv->video_enc), _gst_object_ref0 (self->priv->muxer), NULL);
#line 57 "rygel-wmv-transcoder-bin.vala"
	gst_element_link (src, decodebin);
#line 59 "rygel-wmv-transcoder-bin.vala"
	src_pad = gst_element_get_static_pad (self->priv->muxer, "src");
#line 60 "rygel-wmv-transcoder-bin.vala"
	ghost = (GstGhostPad*) gst_ghost_pad_new (NULL, src_pad);
#line 61 "rygel-wmv-transcoder-bin.vala"
	gst_element_add_pad ((GstElement*) self, _gst_object_ref0 ((GstPad*) ghost));
#line 63 "rygel-wmv-transcoder-bin.vala"
	g_signal_connect_object (decodebin, "pad-added", (GCallback) _rygel_wmv_transcoder_bin_decodebin_pad_added_gst_element_pad_added, self, 0);
#line 66 "rygel-wmv-transcoder-bin.vala"
	g_signal_connect_object (decodebin, "autoplug-continue", (GCallback) rygel_wmv_transcoder_bin_autoplug_continue, (GObject*) self, G_CONNECT_AFTER);
#line 248 "rygel-wmv-transcoder-bin.c"
	_gst_object_unref0 (decodebin);
	_g_object_unref0 (wma_transcoder);
	_gst_object_unref0 (src_pad);
	_gst_object_unref0 (ghost);
	return self;
}


#line 39 "rygel-wmv-transcoder-bin.vala"
RygelWMVTranscoderBin* rygel_wmv_transcoder_bin_new (RygelMediaItem* item, GstElement* src, RygelWMVTranscoder* transcoder, GError** error) {
#line 39 "rygel-wmv-transcoder-bin.vala"
	return rygel_wmv_transcoder_bin_construct (RYGEL_TYPE_WMV_TRANSCODER_BIN, item, src, transcoder, error);
#line 261 "rygel-wmv-transcoder-bin.c"
}


#line 74 "rygel-wmv-transcoder-bin.vala"
static gboolean rygel_wmv_transcoder_bin_autoplug_continue (GstElement* decodebin, GstPad* new_pad, GstCaps* caps, RygelWMVTranscoderBin* self) {
#line 267 "rygel-wmv-transcoder-bin.c"
	gboolean result = FALSE;
	GstPad* muxer_pad;
#line 74 "rygel-wmv-transcoder-bin.vala"
	g_return_val_if_fail (self != NULL, FALSE);
#line 74 "rygel-wmv-transcoder-bin.vala"
	g_return_val_if_fail (decodebin != NULL, FALSE);
#line 74 "rygel-wmv-transcoder-bin.vala"
	g_return_val_if_fail (new_pad != NULL, FALSE);
#line 74 "rygel-wmv-transcoder-bin.vala"
	g_return_val_if_fail (caps != NULL, FALSE);
#line 77 "rygel-wmv-transcoder-bin.vala"
	muxer_pad = gst_element_get_compatible_pad (self->priv->muxer, new_pad, NULL);
#line 79 "rygel-wmv-transcoder-bin.vala"
	if (muxer_pad == NULL) {
#line 282 "rygel-wmv-transcoder-bin.c"
		result = TRUE;
		_gst_object_unref0 (muxer_pad);
#line 80 "rygel-wmv-transcoder-bin.vala"
		return result;
#line 287 "rygel-wmv-transcoder-bin.c"
	} else {
		result = gst_pad_link (new_pad, muxer_pad) != GST_PAD_LINK_OK;
		_gst_object_unref0 (muxer_pad);
#line 82 "rygel-wmv-transcoder-bin.vala"
		return result;
#line 293 "rygel-wmv-transcoder-bin.c"
	}
	_gst_object_unref0 (muxer_pad);
}


#line 86 "rygel-wmv-transcoder-bin.vala"
static void rygel_wmv_transcoder_bin_decodebin_pad_added (RygelWMVTranscoderBin* self, GstElement* decodebin, GstPad* new_pad) {
#line 301 "rygel-wmv-transcoder-bin.c"
	GstElement* encoder;
	GstPad* enc_pad;
	GstPad* audio_enc_pad;
	GstPad* video_enc_pad;
#line 86 "rygel-wmv-transcoder-bin.vala"
	g_return_if_fail (self != NULL);
#line 86 "rygel-wmv-transcoder-bin.vala"
	g_return_if_fail (decodebin != NULL);
#line 86 "rygel-wmv-transcoder-bin.vala"
	g_return_if_fail (new_pad != NULL);
#line 312 "rygel-wmv-transcoder-bin.c"
	encoder = NULL;
	enc_pad = NULL;
#line 90 "rygel-wmv-transcoder-bin.vala"
	audio_enc_pad = gst_element_get_pad (self->priv->audio_enc, RYGEL_WMV_TRANSCODER_BIN_AUDIO_ENC_SINK);
#line 91 "rygel-wmv-transcoder-bin.vala"
	video_enc_pad = gst_element_get_pad (self->priv->video_enc, RYGEL_WMV_TRANSCODER_BIN_VIDEO_ENC_SINK);
#line 94 "rygel-wmv-transcoder-bin.vala"
	if (gst_pad_can_link (new_pad, audio_enc_pad)) {
#line 321 "rygel-wmv-transcoder-bin.c"
		GstElement* _tmp0_;
		GstPad* _tmp1_;
#line 95 "rygel-wmv-transcoder-bin.vala"
		encoder = (_tmp0_ = _gst_object_ref0 (self->priv->audio_enc), _gst_object_unref0 (encoder), _tmp0_);
#line 96 "rygel-wmv-transcoder-bin.vala"
		enc_pad = (_tmp1_ = _gst_object_ref0 (audio_enc_pad), _gst_object_unref0 (enc_pad), _tmp1_);
#line 328 "rygel-wmv-transcoder-bin.c"
	} else {
#line 97 "rygel-wmv-transcoder-bin.vala"
		if (gst_pad_can_link (new_pad, video_enc_pad)) {
#line 332 "rygel-wmv-transcoder-bin.c"
			GstElement* _tmp2_;
			GstPad* _tmp3_;
#line 98 "rygel-wmv-transcoder-bin.vala"
			encoder = (_tmp2_ = _gst_object_ref0 (self->priv->video_enc), _gst_object_unref0 (encoder), _tmp2_);
#line 99 "rygel-wmv-transcoder-bin.vala"
			enc_pad = (_tmp3_ = _gst_object_ref0 (video_enc_pad), _gst_object_unref0 (enc_pad), _tmp3_);
#line 339 "rygel-wmv-transcoder-bin.c"
		} else {
			_gst_object_unref0 (encoder);
			_gst_object_unref0 (enc_pad);
			_gst_object_unref0 (audio_enc_pad);
			_gst_object_unref0 (video_enc_pad);
#line 101 "rygel-wmv-transcoder-bin.vala"
			return;
#line 347 "rygel-wmv-transcoder-bin.c"
		}
	}
#line 104 "rygel-wmv-transcoder-bin.vala"
	gst_element_link (encoder, self->priv->muxer);
#line 106 "rygel-wmv-transcoder-bin.vala"
	if (gst_pad_link (new_pad, enc_pad) != GST_PAD_LINK_OK) {
#line 354 "rygel-wmv-transcoder-bin.c"
		GError* _error_;
#line 107 "rygel-wmv-transcoder-bin.vala"
		_error_ = g_error_new (RYGEL_GST_ERROR, RYGEL_GST_ERROR_LINK, _ ("Failed to link pad %s to %s"), gst_object_get_name ((GstObject*) new_pad), gst_object_get_name ((GstObject*) enc_pad));
#line 110 "rygel-wmv-transcoder-bin.vala"
		rygel_gst_utils_post_error ((GstElement*) self, _error_);
#line 360 "rygel-wmv-transcoder-bin.c"
		_g_error_free0 (_error_);
	}
	_gst_object_unref0 (encoder);
	_gst_object_unref0 (enc_pad);
	_gst_object_unref0 (audio_enc_pad);
	_gst_object_unref0 (video_enc_pad);
}


static void rygel_wmv_transcoder_bin_class_init (RygelWMVTranscoderBinClass * klass) {
	rygel_wmv_transcoder_bin_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelWMVTranscoderBinPrivate));
	G_OBJECT_CLASS (klass)->finalize = rygel_wmv_transcoder_bin_finalize;
}


static void rygel_wmv_transcoder_bin_instance_init (RygelWMVTranscoderBin * self) {
	self->priv = RYGEL_WMV_TRANSCODER_BIN_GET_PRIVATE (self);
}


static void rygel_wmv_transcoder_bin_finalize (GObject* obj) {
	RygelWMVTranscoderBin * self;
	self = RYGEL_WMV_TRANSCODER_BIN (obj);
	_gst_object_unref0 (self->priv->audio_enc);
	_gst_object_unref0 (self->priv->video_enc);
	_gst_object_unref0 (self->priv->muxer);
	G_OBJECT_CLASS (rygel_wmv_transcoder_bin_parent_class)->finalize (obj);
}


GType rygel_wmv_transcoder_bin_get_type (void) {
	static volatile gsize rygel_wmv_transcoder_bin_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_wmv_transcoder_bin_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelWMVTranscoderBinClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_wmv_transcoder_bin_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelWMVTranscoderBin), 0, (GInstanceInitFunc) rygel_wmv_transcoder_bin_instance_init, NULL };
		GType rygel_wmv_transcoder_bin_type_id;
		rygel_wmv_transcoder_bin_type_id = g_type_register_static (GST_TYPE_BIN, "RygelWMVTranscoderBin", &g_define_type_info, 0);
		g_once_init_leave (&rygel_wmv_transcoder_bin_type_id__volatile, rygel_wmv_transcoder_bin_type_id);
	}
	return rygel_wmv_transcoder_bin_type_id__volatile;
}




