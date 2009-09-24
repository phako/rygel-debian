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
#include <stdlib.h>
#include <string.h>
#include <libgupnp-av/gupnp-av.h>
#include <gee.h>
#include <libsoup/soup.h>


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

#define RYGEL_TYPE_TRANSCODER (rygel_transcoder_get_type ())
#define RYGEL_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRANSCODER, RygelTranscoder))
#define RYGEL_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRANSCODER, RygelTranscoderClass))
#define RYGEL_IS_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRANSCODER))
#define RYGEL_IS_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRANSCODER))
#define RYGEL_TRANSCODER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRANSCODER, RygelTranscoderClass))

typedef struct _RygelTranscoder RygelTranscoder;
typedef struct _RygelTranscoderClass RygelTranscoderClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define RYGEL_TYPE_META_CONFIG (rygel_meta_config_get_type ())
#define RYGEL_META_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_META_CONFIG, RygelMetaConfig))
#define RYGEL_META_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_META_CONFIG, RygelMetaConfigClass))
#define RYGEL_IS_META_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_META_CONFIG))
#define RYGEL_IS_META_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_META_CONFIG))
#define RYGEL_META_CONFIG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_META_CONFIG, RygelMetaConfigClass))

typedef struct _RygelMetaConfig RygelMetaConfig;
typedef struct _RygelMetaConfigClass RygelMetaConfigClass;

#define RYGEL_TYPE_CONFIGURATION (rygel_configuration_get_type ())
#define RYGEL_CONFIGURATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_CONFIGURATION, RygelConfiguration))
#define RYGEL_IS_CONFIGURATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_CONFIGURATION))
#define RYGEL_CONFIGURATION_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), RYGEL_TYPE_CONFIGURATION, RygelConfigurationIface))

typedef struct _RygelConfiguration RygelConfiguration;
typedef struct _RygelConfigurationIface RygelConfigurationIface;

#define TYPE_ENDIANNESS (endianness_get_type ())

#define RYGEL_TYPE_L16_TRANSCODER (rygel_l16_transcoder_get_type ())
#define RYGEL_L16_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_L16_TRANSCODER, RygelL16Transcoder))
#define RYGEL_L16_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_L16_TRANSCODER, RygelL16TranscoderClass))
#define RYGEL_IS_L16_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_L16_TRANSCODER))
#define RYGEL_IS_L16_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_L16_TRANSCODER))
#define RYGEL_L16_TRANSCODER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_L16_TRANSCODER, RygelL16TranscoderClass))

typedef struct _RygelL16Transcoder RygelL16Transcoder;
typedef struct _RygelL16TranscoderClass RygelL16TranscoderClass;

#define RYGEL_TYPE_MP3_LAYER (rygel_mp3_layer_get_type ())

#define RYGEL_TYPE_MP3_TRANSCODER (rygel_mp3_transcoder_get_type ())
#define RYGEL_MP3_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MP3_TRANSCODER, RygelMP3Transcoder))
#define RYGEL_MP3_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MP3_TRANSCODER, RygelMP3TranscoderClass))
#define RYGEL_IS_MP3_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MP3_TRANSCODER))
#define RYGEL_IS_MP3_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MP3_TRANSCODER))
#define RYGEL_MP3_TRANSCODER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MP3_TRANSCODER, RygelMP3TranscoderClass))

typedef struct _RygelMP3Transcoder RygelMP3Transcoder;
typedef struct _RygelMP3TranscoderClass RygelMP3TranscoderClass;

#define RYGEL_TYPE_MP2_TS_PROFILE (rygel_mp2_ts_profile_get_type ())

#define RYGEL_TYPE_MP2_TS_TRANSCODER (rygel_mp2_ts_transcoder_get_type ())
#define RYGEL_MP2_TS_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MP2_TS_TRANSCODER, RygelMP2TSTranscoder))
#define RYGEL_MP2_TS_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MP2_TS_TRANSCODER, RygelMP2TSTranscoderClass))
#define RYGEL_IS_MP2_TS_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MP2_TS_TRANSCODER))
#define RYGEL_IS_MP2_TS_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MP2_TS_TRANSCODER))
#define RYGEL_MP2_TS_TRANSCODER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MP2_TS_TRANSCODER, RygelMP2TSTranscoderClass))

typedef struct _RygelMP2TSTranscoder RygelMP2TSTranscoder;
typedef struct _RygelMP2TSTranscoderClass RygelMP2TSTranscoderClass;
#define __g_list_free_g_object_unref0(var) ((var == NULL) ? NULL : (var = (_g_list_free_g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

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

struct _RygelTranscodeManagerPrivate {
	GeeArrayList* transcoders;
};

struct _RygelConfigurationIface {
	GTypeInterface parent_iface;
	gboolean (*get_upnp_enabled) (RygelConfiguration* self, GError** error);
	char* (*get_interface) (RygelConfiguration* self, GError** error);
	gint (*get_port) (RygelConfiguration* self, GError** error);
	gboolean (*get_transcoding) (RygelConfiguration* self, GError** error);
	gboolean (*get_mp3_transcoder) (RygelConfiguration* self, GError** error);
	gboolean (*get_mp2ts_transcoder) (RygelConfiguration* self, GError** error);
	gboolean (*get_lpcm_transcoder) (RygelConfiguration* self, GError** error);
	gboolean (*get_enabled) (RygelConfiguration* self, const char* section, GError** error);
	char* (*get_title) (RygelConfiguration* self, const char* section, GError** error);
	char* (*get_string) (RygelConfiguration* self, const char* section, const char* key, GError** error);
	GeeArrayList* (*get_string_list) (RygelConfiguration* self, const char* section, const char* key, GError** error);
	gint (*get_int) (RygelConfiguration* self, const char* section, const char* key, gint min, gint max, GError** error);
	GeeArrayList* (*get_int_list) (RygelConfiguration* self, const char* section, const char* key, GError** error);
	gboolean (*get_bool) (RygelConfiguration* self, const char* section, const char* key, GError** error);
};

typedef enum  {
	ENDIANNESS_LITTLE = G_LITTLE_ENDIAN,
	ENDIANNESS_BIG = G_BIG_ENDIAN
} Endianness;

typedef enum  {
	RYGEL_MP3_LAYER_TWO = 1,
	RYGEL_MP3_LAYER_THREE = 2
} RygelMP3Layer;

typedef enum  {
	RYGEL_MP2_TS_PROFILE_SD = 0,
	RYGEL_MP2_TS_PROFILE_HD
} RygelMP2TSProfile;

typedef enum  {
	RYGEL_HTTP_REQUEST_ERROR_UNACCEPTABLE = SOUP_STATUS_NOT_ACCEPTABLE,
	RYGEL_HTTP_REQUEST_ERROR_BAD_REQUEST = SOUP_STATUS_BAD_REQUEST,
	RYGEL_HTTP_REQUEST_ERROR_NOT_FOUND = SOUP_STATUS_NOT_FOUND
} RygelHTTPRequestError;
#define RYGEL_HTTP_REQUEST_ERROR rygel_http_request_error_quark ()

static gpointer rygel_transcode_manager_parent_class = NULL;

GType rygel_transcode_manager_get_type (void);
GType rygel_media_object_get_type (void);
GType rygel_media_item_get_type (void);
GType rygel_transcoder_get_type (void);
#define RYGEL_TRANSCODE_MANAGER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_TRANSCODE_MANAGER, RygelTranscodeManagerPrivate))
enum  {
	RYGEL_TRANSCODE_MANAGER_DUMMY_PROPERTY
};
GType rygel_meta_config_get_type (void);
RygelMetaConfig* rygel_meta_config_get_default (void);
GType rygel_configuration_get_type (void);
gboolean rygel_configuration_get_transcoding (RygelConfiguration* self, GError** error);
gboolean rygel_configuration_get_lpcm_transcoder (RygelConfiguration* self, GError** error);
GType endianness_get_type (void);
RygelL16Transcoder* rygel_l16_transcoder_new (Endianness endianness);
RygelL16Transcoder* rygel_l16_transcoder_construct (GType object_type, Endianness endianness);
GType rygel_l16_transcoder_get_type (void);
gboolean rygel_configuration_get_mp3_transcoder (RygelConfiguration* self, GError** error);
GType rygel_mp3_layer_get_type (void);
RygelMP3Transcoder* rygel_mp3_transcoder_new (RygelMP3Layer layer);
RygelMP3Transcoder* rygel_mp3_transcoder_construct (GType object_type, RygelMP3Layer layer);
GType rygel_mp3_transcoder_get_type (void);
gboolean rygel_configuration_get_mp2ts_transcoder (RygelConfiguration* self, GError** error);
GType rygel_mp2_ts_profile_get_type (void);
RygelMP2TSTranscoder* rygel_mp2_ts_transcoder_new (RygelMP2TSProfile profile);
RygelMP2TSTranscoder* rygel_mp2_ts_transcoder_construct (GType object_type, RygelMP2TSProfile profile);
GType rygel_mp2_ts_transcoder_get_type (void);
RygelTranscodeManager* rygel_transcode_manager_construct (GType object_type, GError** error);
char* rygel_transcode_manager_create_uri_for_item (RygelTranscodeManager* self, RygelMediaItem* item, gint thumbnail_index, const char* transcode_target, char** protocol);
static char* rygel_transcode_manager_real_create_uri_for_item (RygelTranscodeManager* self, RygelMediaItem* item, gint thumbnail_index, const char* transcode_target, char** protocol);
guint rygel_transcoder_get_distance (RygelTranscoder* self, RygelMediaItem* item);
gint rygel_media_item_compare_transcoders (RygelMediaItem* self, void* a, void* b);
static gint _rygel_media_item_compare_transcoders_gcompare_data_func (void* a, void* b, gpointer self);
GUPnPDIDLLiteResource* rygel_transcoder_add_resource (RygelTranscoder* self, GUPnPDIDLLiteItem* didl_item, RygelMediaItem* item, RygelTranscodeManager* manager, GError** error);
static void _g_list_free_g_object_unref (GList* self);
void rygel_transcode_manager_add_resources (RygelTranscodeManager* self, GUPnPDIDLLiteItem* didl_item, RygelMediaItem* item, GError** error);
static void rygel_transcode_manager_real_add_resources (RygelTranscodeManager* self, GUPnPDIDLLiteItem* didl_item, RygelMediaItem* item, GError** error);
gboolean rygel_transcoder_can_handle (RygelTranscoder* self, const char* target);
GQuark rygel_http_request_error_quark (void);
RygelTranscoder* rygel_transcode_manager_get_transcoder (RygelTranscodeManager* self, const char* target, GError** error);
char* rygel_transcode_manager_get_protocol (RygelTranscodeManager* self);
static char* rygel_transcode_manager_real_get_protocol (RygelTranscodeManager* self);
const char* rygel_transcoder_get_mime_type (RygelTranscoder* self);
const char* rygel_transcoder_get_dlna_profile (RygelTranscoder* self);
char* rygel_transcode_manager_get_protocol_info (RygelTranscodeManager* self);
static char* rygel_transcode_manager_real_get_protocol_info (RygelTranscodeManager* self);
static void rygel_transcode_manager_finalize (GObject* obj);
static int _vala_strcmp0 (const char * str1, const char * str2);



RygelTranscodeManager* rygel_transcode_manager_construct (GType object_type, GError** error) {
	GError * _inner_error_;
	RygelTranscodeManager * self;
	GeeArrayList* _tmp0_;
	RygelMetaConfig* config;
	gboolean _tmp1_;
	_inner_error_ = NULL;
	self = (RygelTranscodeManager*) g_object_new (object_type, NULL);
	self->priv->transcoders = (_tmp0_ = gee_array_list_new (RYGEL_TYPE_TRANSCODER, (GBoxedCopyFunc) g_object_ref, g_object_unref, g_direct_equal), _g_object_unref0 (self->priv->transcoders), _tmp0_);
	config = rygel_meta_config_get_default ();
	_tmp1_ = rygel_configuration_get_transcoding ((RygelConfiguration*) config, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_g_object_unref0 (config);
		return;
	}
	if (_tmp1_) {
		gboolean _tmp2_;
		gboolean _tmp4_;
		gboolean _tmp6_;
		_tmp2_ = rygel_configuration_get_lpcm_transcoder ((RygelConfiguration*) config, &_inner_error_);
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_g_object_unref0 (config);
			return;
		}
		if (_tmp2_) {
			RygelL16Transcoder* _tmp3_;
			gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->transcoders, (RygelTranscoder*) (_tmp3_ = rygel_l16_transcoder_new (ENDIANNESS_BIG)));
			_g_object_unref0 (_tmp3_);
		}
		_tmp4_ = rygel_configuration_get_mp3_transcoder ((RygelConfiguration*) config, &_inner_error_);
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_g_object_unref0 (config);
			return;
		}
		if (_tmp4_) {
			RygelMP3Transcoder* _tmp5_;
			gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->transcoders, (RygelTranscoder*) (_tmp5_ = rygel_mp3_transcoder_new (RYGEL_MP3_LAYER_THREE)));
			_g_object_unref0 (_tmp5_);
		}
		_tmp6_ = rygel_configuration_get_mp2ts_transcoder ((RygelConfiguration*) config, &_inner_error_);
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_g_object_unref0 (config);
			return;
		}
		if (_tmp6_) {
			RygelMP2TSTranscoder* _tmp7_;
			RygelMP2TSTranscoder* _tmp8_;
			gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->transcoders, (RygelTranscoder*) (_tmp7_ = rygel_mp2_ts_transcoder_new (RYGEL_MP2_TS_PROFILE_SD)));
			_g_object_unref0 (_tmp7_);
			gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->transcoders, (RygelTranscoder*) (_tmp8_ = rygel_mp2_ts_transcoder_new (RYGEL_MP2_TS_PROFILE_HD)));
			_g_object_unref0 (_tmp8_);
		}
	}
	_g_object_unref0 (config);
	return self;
}


static char* rygel_transcode_manager_real_create_uri_for_item (RygelTranscodeManager* self, RygelMediaItem* item, gint thumbnail_index, const char* transcode_target, char** protocol) {
	g_return_val_if_fail (self != NULL, NULL);
	g_critical ("Type `%s' does not implement abstract method `rygel_transcode_manager_create_uri_for_item'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}


char* rygel_transcode_manager_create_uri_for_item (RygelTranscodeManager* self, RygelMediaItem* item, gint thumbnail_index, const char* transcode_target, char** protocol) {
	return RYGEL_TRANSCODE_MANAGER_GET_CLASS (self)->create_uri_for_item (self, item, thumbnail_index, transcode_target, protocol);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static gint _rygel_media_item_compare_transcoders_gcompare_data_func (void* a, void* b, gpointer self) {
	return rygel_media_item_compare_transcoders (self, a, b);
}


static void _g_list_free_g_object_unref (GList* self) {
	g_list_foreach (self, (GFunc) g_object_unref, NULL);
	g_list_free (self);
}


static void rygel_transcode_manager_real_add_resources (RygelTranscodeManager* self, GUPnPDIDLLiteItem* didl_item, RygelMediaItem* item, GError** error) {
	GError * _inner_error_;
	GList* list;
	g_return_if_fail (self != NULL);
	g_return_if_fail (didl_item != NULL);
	g_return_if_fail (item != NULL);
	_inner_error_ = NULL;
	list = NULL;
	{
		GeeIterator* _transcoder_it;
		_transcoder_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->transcoders);
		while (TRUE) {
			RygelTranscoder* transcoder;
			if (!gee_iterator_next (_transcoder_it)) {
				break;
			}
			transcoder = (RygelTranscoder*) gee_iterator_get (_transcoder_it);
			if (rygel_transcoder_get_distance (transcoder, item) != G_MAXUINT) {
				list = g_list_append (list, _g_object_ref0 (transcoder));
			}
			_g_object_unref0 (transcoder);
		}
		_g_object_unref0 (_transcoder_it);
	}
	list = g_list_sort_with_data (list, _rygel_media_item_compare_transcoders_gcompare_data_func, item);
	{
		GList* transcoder_collection;
		GList* transcoder_it;
		transcoder_collection = list;
		for (transcoder_it = transcoder_collection; transcoder_it != NULL; transcoder_it = transcoder_it->next) {
			RygelTranscoder* transcoder;
			transcoder = _g_object_ref0 ((RygelTranscoder*) transcoder_it->data);
			{
				GUPnPDIDLLiteResource* _tmp0_;
				_tmp0_ = rygel_transcoder_add_resource (transcoder, didl_item, item, self, &_inner_error_);
				if (_inner_error_ != NULL) {
					g_propagate_error (error, _inner_error_);
					_g_object_unref0 (transcoder);
					__g_list_free_g_object_unref0 (list);
					return;
				}
				_g_object_unref0 (_tmp0_);
				_g_object_unref0 (transcoder);
			}
		}
	}
	__g_list_free_g_object_unref0 (list);
}


void rygel_transcode_manager_add_resources (RygelTranscodeManager* self, GUPnPDIDLLiteItem* didl_item, RygelMediaItem* item, GError** error) {
	RYGEL_TRANSCODE_MANAGER_GET_CLASS (self)->add_resources (self, didl_item, item, error);
}


RygelTranscoder* rygel_transcode_manager_get_transcoder (RygelTranscodeManager* self, const char* target, GError** error) {
	RygelTranscoder* result;
	GError * _inner_error_;
	RygelTranscoder* transcoder;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (target != NULL, NULL);
	_inner_error_ = NULL;
	transcoder = NULL;
	{
		GeeIterator* _iter_it;
		_iter_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->transcoders);
		while (TRUE) {
			RygelTranscoder* iter;
			if (!gee_iterator_next (_iter_it)) {
				break;
			}
			iter = (RygelTranscoder*) gee_iterator_get (_iter_it);
			if (rygel_transcoder_can_handle (iter, target)) {
				RygelTranscoder* _tmp0_;
				transcoder = (_tmp0_ = _g_object_ref0 (iter), _g_object_unref0 (transcoder), _tmp0_);
			}
			_g_object_unref0 (iter);
		}
		_g_object_unref0 (_iter_it);
	}
	if (transcoder == NULL) {
		_inner_error_ = g_error_new (RYGEL_HTTP_REQUEST_ERROR, RYGEL_HTTP_REQUEST_ERROR_NOT_FOUND, "No transcoder available for target format '%s'", target);
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_g_object_unref0 (transcoder);
			return NULL;
		}
	}
	result = transcoder;
	return result;
}


static char* rygel_transcode_manager_real_get_protocol (RygelTranscodeManager* self) {
	g_return_val_if_fail (self != NULL, NULL);
	g_critical ("Type `%s' does not implement abstract method `rygel_transcode_manager_get_protocol'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}


char* rygel_transcode_manager_get_protocol (RygelTranscodeManager* self) {
	return RYGEL_TRANSCODE_MANAGER_GET_CLASS (self)->get_protocol (self);
}


static char* rygel_transcode_manager_real_get_protocol_info (RygelTranscodeManager* self) {
	char* result;
	char* protocol_info;
	g_return_val_if_fail (self != NULL, NULL);
	protocol_info = g_strdup ("");
	{
		GeeIterator* _transcoder_it;
		_transcoder_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->transcoders);
		while (TRUE) {
			RygelTranscoder* transcoder;
			char* _tmp6_;
			char* _tmp5_;
			char* _tmp4_;
			char* _tmp3_;
			char* _tmp2_;
			char* _tmp1_;
			if (!gee_iterator_next (_transcoder_it)) {
				break;
			}
			transcoder = (RygelTranscoder*) gee_iterator_get (_transcoder_it);
			if (_vala_strcmp0 (protocol_info, "") != 0) {
				char* _tmp0_;
				protocol_info = (_tmp0_ = g_strconcat (protocol_info, ",", NULL), _g_free0 (protocol_info), _tmp0_);
			}
			protocol_info = (_tmp6_ = g_strconcat (protocol_info, _tmp5_ = g_strconcat (_tmp4_ = g_strconcat (_tmp3_ = g_strconcat (_tmp2_ = g_strconcat (_tmp1_ = rygel_transcode_manager_get_protocol (self), ":*:", NULL), rygel_transcoder_get_mime_type (transcoder), NULL), ":DLNA.ORG_PN=", NULL), rygel_transcoder_get_dlna_profile (transcoder), NULL), NULL), _g_free0 (protocol_info), _tmp6_);
			_g_free0 (_tmp5_);
			_g_free0 (_tmp4_);
			_g_free0 (_tmp3_);
			_g_free0 (_tmp2_);
			_g_free0 (_tmp1_);
			_g_object_unref0 (transcoder);
		}
		_g_object_unref0 (_transcoder_it);
	}
	result = protocol_info;
	return result;
}


char* rygel_transcode_manager_get_protocol_info (RygelTranscodeManager* self) {
	return RYGEL_TRANSCODE_MANAGER_GET_CLASS (self)->get_protocol_info (self);
}


static void rygel_transcode_manager_class_init (RygelTranscodeManagerClass * klass) {
	rygel_transcode_manager_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelTranscodeManagerPrivate));
	RYGEL_TRANSCODE_MANAGER_CLASS (klass)->create_uri_for_item = rygel_transcode_manager_real_create_uri_for_item;
	RYGEL_TRANSCODE_MANAGER_CLASS (klass)->add_resources = rygel_transcode_manager_real_add_resources;
	RYGEL_TRANSCODE_MANAGER_CLASS (klass)->get_protocol = rygel_transcode_manager_real_get_protocol;
	RYGEL_TRANSCODE_MANAGER_CLASS (klass)->get_protocol_info = rygel_transcode_manager_real_get_protocol_info;
	G_OBJECT_CLASS (klass)->finalize = rygel_transcode_manager_finalize;
}


static void rygel_transcode_manager_instance_init (RygelTranscodeManager * self) {
	self->priv = RYGEL_TRANSCODE_MANAGER_GET_PRIVATE (self);
}


static void rygel_transcode_manager_finalize (GObject* obj) {
	RygelTranscodeManager * self;
	self = RYGEL_TRANSCODE_MANAGER (obj);
	_g_object_unref0 (self->priv->transcoders);
	G_OBJECT_CLASS (rygel_transcode_manager_parent_class)->finalize (obj);
}


GType rygel_transcode_manager_get_type (void) {
	static GType rygel_transcode_manager_type_id = 0;
	if (rygel_transcode_manager_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelTranscodeManagerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_transcode_manager_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelTranscodeManager), 0, (GInstanceInitFunc) rygel_transcode_manager_instance_init, NULL };
		rygel_transcode_manager_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelTranscodeManager", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
	}
	return rygel_transcode_manager_type_id;
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




