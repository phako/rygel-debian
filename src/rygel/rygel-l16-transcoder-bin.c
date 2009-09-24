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


#define RYGEL_TYPE_L16_TRANSCODER_BIN (rygel_l16_transcoder_bin_get_type ())
#define RYGEL_L16_TRANSCODER_BIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_L16_TRANSCODER_BIN, RygelL16TranscoderBin))
#define RYGEL_L16_TRANSCODER_BIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_L16_TRANSCODER_BIN, RygelL16TranscoderBinClass))
#define RYGEL_IS_L16_TRANSCODER_BIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_L16_TRANSCODER_BIN))
#define RYGEL_IS_L16_TRANSCODER_BIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_L16_TRANSCODER_BIN))
#define RYGEL_L16_TRANSCODER_BIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_L16_TRANSCODER_BIN, RygelL16TranscoderBinClass))

typedef struct _RygelL16TranscoderBin RygelL16TranscoderBin;
typedef struct _RygelL16TranscoderBinClass RygelL16TranscoderBinClass;
typedef struct _RygelL16TranscoderBinPrivate RygelL16TranscoderBinPrivate;
#define _gst_object_unref0(var) ((var == NULL) ? NULL : (var = (gst_object_unref (var), NULL)))

#define RYGEL_TYPE_TRANSCODER (rygel_transcoder_get_type ())
#define RYGEL_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRANSCODER, RygelTranscoder))
#define RYGEL_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRANSCODER, RygelTranscoderClass))
#define RYGEL_IS_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRANSCODER))
#define RYGEL_IS_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRANSCODER))
#define RYGEL_TRANSCODER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRANSCODER, RygelTranscoderClass))

typedef struct _RygelTranscoder RygelTranscoder;
typedef struct _RygelTranscoderClass RygelTranscoderClass;

#define RYGEL_TYPE_L16_TRANSCODER (rygel_l16_transcoder_get_type ())
#define RYGEL_L16_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_L16_TRANSCODER, RygelL16Transcoder))
#define RYGEL_L16_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_L16_TRANSCODER, RygelL16TranscoderClass))
#define RYGEL_IS_L16_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_L16_TRANSCODER))
#define RYGEL_IS_L16_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_L16_TRANSCODER))
#define RYGEL_L16_TRANSCODER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_L16_TRANSCODER, RygelL16TranscoderClass))

typedef struct _RygelL16Transcoder RygelL16Transcoder;
typedef struct _RygelL16TranscoderClass RygelL16TranscoderClass;

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
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _RygelL16TranscoderBin {
	GstBin parent_instance;
	RygelL16TranscoderBinPrivate * priv;
};

struct _RygelL16TranscoderBinClass {
	GstBinClass parent_class;
};

struct _RygelL16TranscoderBinPrivate {
	GstElement* audio_enc;
};

typedef enum  {
	RYGEL_LIVE_RESPONSE_ERROR_MISSING_PLUGIN,
	RYGEL_LIVE_RESPONSE_ERROR_LINK
} RygelLiveResponseError;
#define RYGEL_LIVE_RESPONSE_ERROR rygel_live_response_error_quark ()

static gpointer rygel_l16_transcoder_bin_parent_class = NULL;

GType rygel_l16_transcoder_bin_get_type (void);
#define RYGEL_L16_TRANSCODER_BIN_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_L16_TRANSCODER_BIN, RygelL16TranscoderBinPrivate))
enum  {
	RYGEL_L16_TRANSCODER_BIN_DUMMY_PROPERTY
};
#define RYGEL_L16_TRANSCODER_BIN_DECODEBIN "decodebin2"
#define RYGEL_L16_TRANSCODER_BIN_AUDIO_SRC_PAD "audio-src-pad"
#define RYGEL_L16_TRANSCODER_BIN_AUDIO_SINK_PAD "audio-sink-pad"
GstElement* rygel_gst_utils_create_element (const char* factoryname, const char* name, GError** error);
GType rygel_transcoder_get_type (void);
GType rygel_l16_transcoder_get_type (void);
GType rygel_media_object_get_type (void);
GType rygel_media_item_get_type (void);
GstElement* rygel_l16_transcoder_create_encoder (RygelL16Transcoder* self, RygelMediaItem* item, const char* src_pad_name, const char* sink_pad_name, GError** error);
static void rygel_l16_transcoder_bin_decodebin_pad_added (RygelL16TranscoderBin* self, GstElement* decodebin, GstPad* new_pad);
static void _rygel_l16_transcoder_bin_decodebin_pad_added_gst_element_pad_added (GstElement* _sender, GstPad* pad, gpointer self);
RygelL16TranscoderBin* rygel_l16_transcoder_bin_new (RygelMediaItem* item, GstElement* src, RygelL16Transcoder* transcoder, GError** error);
RygelL16TranscoderBin* rygel_l16_transcoder_bin_construct (GType object_type, RygelMediaItem* item, GstElement* src, RygelL16Transcoder* transcoder, GError** error);
void rygel_gst_utils_post_error (GstElement* dest, GError* _error_);
GQuark rygel_live_response_error_quark (void);
static void rygel_l16_transcoder_bin_finalize (GObject* obj);



static gpointer _gst_object_ref0 (gpointer self) {
	return self ? gst_object_ref (self) : NULL;
}


static void _rygel_l16_transcoder_bin_decodebin_pad_added_gst_element_pad_added (GstElement* _sender, GstPad* pad, gpointer self) {
	rygel_l16_transcoder_bin_decodebin_pad_added (self, _sender, pad);
}


RygelL16TranscoderBin* rygel_l16_transcoder_bin_construct (GType object_type, RygelMediaItem* item, GstElement* src, RygelL16Transcoder* transcoder, GError** error) {
	GError * _inner_error_;
	RygelL16TranscoderBin * self;
	GstElement* decodebin;
	GstElement* _tmp0_;
	GstElement* _tmp1_;
	GstPad* src_pad;
	GstGhostPad* ghost;
	g_return_val_if_fail (item != NULL, NULL);
	g_return_val_if_fail (src != NULL, NULL);
	g_return_val_if_fail (transcoder != NULL, NULL);
	_inner_error_ = NULL;
	self = g_object_newv (object_type, 0, NULL);
	decodebin = rygel_gst_utils_create_element (RYGEL_L16_TRANSCODER_BIN_DECODEBIN, RYGEL_L16_TRANSCODER_BIN_DECODEBIN, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return;
	}
	_tmp0_ = rygel_l16_transcoder_create_encoder (transcoder, item, RYGEL_L16_TRANSCODER_BIN_AUDIO_SRC_PAD, RYGEL_L16_TRANSCODER_BIN_AUDIO_SINK_PAD, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_gst_object_unref0 (decodebin);
		return;
	}
	self->priv->audio_enc = (_tmp1_ = _tmp0_, _gst_object_unref0 (self->priv->audio_enc), _tmp1_);
	gst_bin_add_many ((GstBin*) self, _gst_object_ref0 (src), _gst_object_ref0 (decodebin), _gst_object_ref0 (self->priv->audio_enc), NULL);
	gst_element_link (src, decodebin);
	src_pad = gst_element_get_static_pad (self->priv->audio_enc, RYGEL_L16_TRANSCODER_BIN_AUDIO_SRC_PAD);
	ghost = (GstGhostPad*) gst_ghost_pad_new (NULL, src_pad);
	gst_element_add_pad ((GstElement*) self, _gst_object_ref0 ((GstPad*) ghost));
	g_signal_connect_object (decodebin, "pad-added", (GCallback) _rygel_l16_transcoder_bin_decodebin_pad_added_gst_element_pad_added, self, 0);
	_gst_object_unref0 (decodebin);
	_gst_object_unref0 (src_pad);
	_gst_object_unref0 (ghost);
	return self;
}


RygelL16TranscoderBin* rygel_l16_transcoder_bin_new (RygelMediaItem* item, GstElement* src, RygelL16Transcoder* transcoder, GError** error) {
	return rygel_l16_transcoder_bin_construct (RYGEL_TYPE_L16_TRANSCODER_BIN, item, src, transcoder, error);
}


static void rygel_l16_transcoder_bin_decodebin_pad_added (RygelL16TranscoderBin* self, GstElement* decodebin, GstPad* new_pad) {
	GstPad* enc_pad;
	g_return_if_fail (self != NULL);
	g_return_if_fail (decodebin != NULL);
	g_return_if_fail (new_pad != NULL);
	enc_pad = _gst_object_ref0 (gst_element_get_pad (self->priv->audio_enc, RYGEL_L16_TRANSCODER_BIN_AUDIO_SINK_PAD));
	if (!gst_pad_can_link (new_pad, enc_pad)) {
		_gst_object_unref0 (enc_pad);
		return;
	}
	if (gst_pad_link (new_pad, enc_pad) != GST_PAD_LINK_OK) {
		GError* _tmp0_;
		rygel_gst_utils_post_error ((GstElement*) self, _tmp0_ = g_error_new (RYGEL_LIVE_RESPONSE_ERROR, RYGEL_LIVE_RESPONSE_ERROR_LINK, "Failed to link pad %s to %s", gst_object_get_name ((GstObject*) new_pad), gst_object_get_name ((GstObject*) enc_pad)));
		_g_error_free0 (_tmp0_);
		_gst_object_unref0 (enc_pad);
		return;
	}
	_gst_object_unref0 (enc_pad);
}


static void rygel_l16_transcoder_bin_class_init (RygelL16TranscoderBinClass * klass) {
	rygel_l16_transcoder_bin_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelL16TranscoderBinPrivate));
	G_OBJECT_CLASS (klass)->finalize = rygel_l16_transcoder_bin_finalize;
}


static void rygel_l16_transcoder_bin_instance_init (RygelL16TranscoderBin * self) {
	self->priv = RYGEL_L16_TRANSCODER_BIN_GET_PRIVATE (self);
}


static void rygel_l16_transcoder_bin_finalize (GObject* obj) {
	RygelL16TranscoderBin * self;
	self = RYGEL_L16_TRANSCODER_BIN (obj);
	_gst_object_unref0 (self->priv->audio_enc);
	G_OBJECT_CLASS (rygel_l16_transcoder_bin_parent_class)->finalize (obj);
}


GType rygel_l16_transcoder_bin_get_type (void) {
	static GType rygel_l16_transcoder_bin_type_id = 0;
	if (rygel_l16_transcoder_bin_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelL16TranscoderBinClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_l16_transcoder_bin_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelL16TranscoderBin), 0, (GInstanceInitFunc) rygel_l16_transcoder_bin_instance_init, NULL };
		rygel_l16_transcoder_bin_type_id = g_type_register_static (GST_TYPE_BIN, "RygelL16TranscoderBin", &g_define_type_info, 0);
	}
	return rygel_l16_transcoder_bin_type_id;
}




