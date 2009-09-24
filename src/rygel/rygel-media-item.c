/*
 * Copyright (C) 2008 Zeeshan Ali <zeenix@gmail.com>.
 *
 * Author: Zeeshan Ali <zeenix@gmail.com>
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
#include <gee.h>
#include <gst/gst.h>
#include <libgupnp-av/gupnp-av.h>


#define RYGEL_TYPE_MEDIA_OBJECT (rygel_media_object_get_type ())
#define RYGEL_MEDIA_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObject))
#define RYGEL_MEDIA_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObjectClass))
#define RYGEL_IS_MEDIA_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_OBJECT))
#define RYGEL_IS_MEDIA_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_OBJECT))
#define RYGEL_MEDIA_OBJECT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObjectClass))

typedef struct _RygelMediaObject RygelMediaObject;
typedef struct _RygelMediaObjectClass RygelMediaObjectClass;
typedef struct _RygelMediaObjectPrivate RygelMediaObjectPrivate;

#define RYGEL_TYPE_MEDIA_CONTAINER (rygel_media_container_get_type ())
#define RYGEL_MEDIA_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainer))
#define RYGEL_MEDIA_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainerClass))
#define RYGEL_IS_MEDIA_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_CONTAINER))
#define RYGEL_IS_MEDIA_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_CONTAINER))
#define RYGEL_MEDIA_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainerClass))

typedef struct _RygelMediaContainer RygelMediaContainer;
typedef struct _RygelMediaContainerClass RygelMediaContainerClass;

#define RYGEL_TYPE_MEDIA_ITEM (rygel_media_item_get_type ())
#define RYGEL_MEDIA_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_ITEM, RygelMediaItem))
#define RYGEL_MEDIA_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_ITEM, RygelMediaItemClass))
#define RYGEL_IS_MEDIA_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_ITEM))
#define RYGEL_IS_MEDIA_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_ITEM))
#define RYGEL_MEDIA_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_ITEM, RygelMediaItemClass))

typedef struct _RygelMediaItem RygelMediaItem;
typedef struct _RygelMediaItemClass RygelMediaItemClass;
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
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _gst_object_unref0(var) ((var == NULL) ? NULL : (var = (gst_object_unref (var), NULL)))

#define RYGEL_TYPE_THUMBNAILER (rygel_thumbnailer_get_type ())
#define RYGEL_THUMBNAILER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_THUMBNAILER, RygelThumbnailer))
#define RYGEL_THUMBNAILER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_THUMBNAILER, RygelThumbnailerClass))
#define RYGEL_IS_THUMBNAILER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_THUMBNAILER))
#define RYGEL_IS_THUMBNAILER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_THUMBNAILER))
#define RYGEL_THUMBNAILER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_THUMBNAILER, RygelThumbnailerClass))

typedef struct _RygelThumbnailer RygelThumbnailer;
typedef struct _RygelThumbnailerClass RygelThumbnailerClass;
#define _rygel_icon_info_unref0(var) ((var == NULL) ? NULL : (var = (rygel_icon_info_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

#define RYGEL_TYPE_TRANSCODER (rygel_transcoder_get_type ())
#define RYGEL_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRANSCODER, RygelTranscoder))
#define RYGEL_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRANSCODER, RygelTranscoderClass))
#define RYGEL_IS_TRANSCODER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRANSCODER))
#define RYGEL_IS_TRANSCODER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRANSCODER))
#define RYGEL_TRANSCODER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRANSCODER, RygelTranscoderClass))

typedef struct _RygelTranscoder RygelTranscoder;
typedef struct _RygelTranscoderClass RygelTranscoderClass;
typedef struct _RygelIconInfoPrivate RygelIconInfoPrivate;
typedef struct _RygelThumbnailPrivate RygelThumbnailPrivate;

typedef enum  {
	RYGEL_MEDIA_ITEM_ERROR_BAD_URI
} RygelMediaItemError;
#define RYGEL_MEDIA_ITEM_ERROR rygel_media_item_error_quark ()
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

struct _RygelIconInfo {
	GTypeInstance parent_instance;
	volatile int ref_count;
	RygelIconInfoPrivate * priv;
	char* mime_type;
	char* path;
	glong size;
	gint width;
	gint height;
	gint depth;
};

struct _RygelIconInfoClass {
	GTypeClass parent_class;
	void (*finalize) (RygelIconInfo *self);
};

struct _RygelThumbnail {
	RygelIconInfo parent_instance;
	RygelThumbnailPrivate * priv;
	char* uri;
	char* dlna_profile;
};

struct _RygelThumbnailClass {
	RygelIconInfoClass parent_class;
};


static gpointer rygel_media_item_parent_class = NULL;

GQuark rygel_media_item_error_quark (void);
GType rygel_media_object_get_type (void);
GType rygel_media_container_get_type (void);
GType rygel_media_item_get_type (void);
gpointer rygel_icon_info_ref (gpointer instance);
void rygel_icon_info_unref (gpointer instance);
GParamSpec* rygel_param_spec_icon_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_icon_info (GValue* value, gpointer v_object);
gpointer rygel_value_get_icon_info (const GValue* value);
GType rygel_icon_info_get_type (void);
GType rygel_thumbnail_get_type (void);
enum  {
	RYGEL_MEDIA_ITEM_DUMMY_PROPERTY
};
#define RYGEL_MEDIA_ITEM_IMAGE_CLASS "object.item.imageItem"
#define RYGEL_MEDIA_ITEM_VIDEO_CLASS "object.item.videoItem"
#define RYGEL_MEDIA_ITEM_AUDIO_CLASS "object.item.audioItem"
#define RYGEL_MEDIA_ITEM_MUSIC_CLASS "object.item.audioItem.musicTrack"
RygelMediaObject* rygel_media_object_construct (GType object_type);
RygelMediaItem* rygel_media_item_new (const char* id, RygelMediaContainer* parent, const char* title, const char* upnp_class);
RygelMediaItem* rygel_media_item_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title, const char* upnp_class);
static inline void _dynamic_set_tcp_timeout1 (GstElement* obj, gint64 value);
GstElement* rygel_media_item_create_stream_source (RygelMediaItem* self);
static GstElement* rygel_media_item_real_create_stream_source (RygelMediaItem* self);
gboolean rygel_media_item_should_stream (RygelMediaItem* self);
static gboolean rygel_media_item_real_should_stream (RygelMediaItem* self);
GType rygel_thumbnailer_get_type (void);
RygelThumbnailer* rygel_thumbnailer_get_default (void);
RygelThumbnail* rygel_thumbnailer_get_thumbnail (RygelThumbnailer* self, const char* uri, GError** error);
void rygel_media_item_add_uri (RygelMediaItem* self, const char* uri, RygelThumbnail* thumbnail);
GType rygel_transcoder_get_type (void);
guint rygel_transcoder_get_distance (RygelTranscoder* self, RygelMediaItem* item);
gint rygel_media_item_compare_transcoders (RygelMediaItem* self, void* a, void* b);
static char* rygel_media_item_get_protocol_for_uri (RygelMediaItem* self, const char* uri, GError** error);
GUPnPDIDLLiteResource* rygel_media_item_add_resource (RygelMediaItem* self, GUPnPDIDLLiteItem* didl_item, const char* uri, const char* protocol, GError** error);
GUPnPDIDLLiteResource* rygel_thumbnail_add_resource (RygelThumbnail* self, GUPnPDIDLLiteItem* didl_item, const char* protocol);
void rygel_media_item_add_resources (RygelMediaItem* self, GUPnPDIDLLiteItem* didl_item, gboolean allow_internal, GError** error);
static GUPnPProtocolInfo* rygel_media_item_get_protocol_info (RygelMediaItem* self, const char* uri, const char* protocol);
static void rygel_media_item_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);
static int _vala_strcmp0 (const char * str1, const char * str2);



GQuark rygel_media_item_error_quark (void) {
	return g_quark_from_static_string ("rygel_media_item_error-quark");
}


RygelMediaItem* rygel_media_item_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title, const char* upnp_class) {
	RygelMediaItem * self;
	char* _tmp0_;
	char* _tmp1_;
	char* _tmp2_;
	GeeArrayList* _tmp3_;
	g_return_val_if_fail (id != NULL, NULL);
	g_return_val_if_fail (parent != NULL, NULL);
	g_return_val_if_fail (title != NULL, NULL);
	g_return_val_if_fail (upnp_class != NULL, NULL);
	self = (RygelMediaItem*) rygel_media_object_construct (object_type);
	((RygelMediaObject*) self)->id = (_tmp0_ = g_strdup (id), _g_free0 (((RygelMediaObject*) self)->id), _tmp0_);
	((RygelMediaObject*) self)->parent = parent;
	((RygelMediaObject*) self)->title = (_tmp1_ = g_strdup (title), _g_free0 (((RygelMediaObject*) self)->title), _tmp1_);
	self->upnp_class = (_tmp2_ = g_strdup (upnp_class), _g_free0 (self->upnp_class), _tmp2_);
	self->thumbnails = (_tmp3_ = gee_array_list_new (RYGEL_TYPE_THUMBNAIL, (GBoxedCopyFunc) rygel_icon_info_ref, rygel_icon_info_unref, g_direct_equal), _g_object_unref0 (self->thumbnails), _tmp3_);
	return self;
}


RygelMediaItem* rygel_media_item_new (const char* id, RygelMediaContainer* parent, const char* title, const char* upnp_class) {
	return rygel_media_item_construct (RYGEL_TYPE_MEDIA_ITEM, id, parent, title, upnp_class);
}


static inline void _dynamic_set_tcp_timeout1 (GstElement* obj, gint64 value) {
	g_object_set (obj, "tcp-timeout", value, NULL);
}


static GstElement* rygel_media_item_real_create_stream_source (RygelMediaItem* self) {
	GstElement* result;
	GstElement* src;
	gboolean _tmp2_;
	g_return_val_if_fail (self != NULL, NULL);
	src = NULL;
	if (gee_collection_get_size ((GeeCollection*) ((RygelMediaObject*) self)->uris) != 0) {
		GstElement* _tmp1_;
		char* _tmp0_;
		src = (_tmp1_ = gst_element_make_from_uri (GST_URI_SRC, _tmp0_ = (char*) gee_abstract_list_get ((GeeAbstractList*) ((RygelMediaObject*) self)->uris, 0), NULL), _gst_object_unref0 (src), _tmp1_);
		_g_free0 (_tmp0_);
	}
	_tmp2_ = FALSE;
	if (src != NULL) {
		_tmp2_ = _vala_strcmp0 (g_type_name (G_TYPE_FROM_INSTANCE ((GObject*) src)), "GstRTSPSrc") == 0;
	} else {
		_tmp2_ = FALSE;
	}
	if (_tmp2_) {
		_dynamic_set_tcp_timeout1 (src, (gint64) 60000000);
	}
	result = src;
	return result;
}


GstElement* rygel_media_item_create_stream_source (RygelMediaItem* self) {
	return RYGEL_MEDIA_ITEM_GET_CLASS (self)->create_stream_source (self);
}


static gboolean rygel_media_item_real_should_stream (RygelMediaItem* self) {
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->size <= 0;
	return result;
}


gboolean rygel_media_item_should_stream (RygelMediaItem* self) {
	return RYGEL_MEDIA_ITEM_GET_CLASS (self)->should_stream (self);
}


void rygel_media_item_add_uri (RygelMediaItem* self, const char* uri, RygelThumbnail* thumbnail) {
	GError * _inner_error_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (uri != NULL);
	_inner_error_ = NULL;
	gee_abstract_collection_add ((GeeAbstractCollection*) ((RygelMediaObject*) self)->uris, uri);
	if (thumbnail != NULL) {
		gee_abstract_collection_add ((GeeAbstractCollection*) self->thumbnails, thumbnail);
	} else {
		gboolean _tmp0_;
		_tmp0_ = FALSE;
		if (g_str_has_prefix (self->upnp_class, RYGEL_MEDIA_ITEM_IMAGE_CLASS)) {
			_tmp0_ = TRUE;
		} else {
			_tmp0_ = g_str_has_prefix (self->upnp_class, RYGEL_MEDIA_ITEM_VIDEO_CLASS);
		}
		if (_tmp0_) {
			RygelThumbnailer* thumbnailer;
			thumbnailer = rygel_thumbnailer_get_default ();
			if (thumbnailer == NULL) {
				_g_object_unref0 (thumbnailer);
				return;
			}
			{
				RygelThumbnail* thumb;
				thumb = rygel_thumbnailer_get_thumbnail (thumbnailer, uri, &_inner_error_);
				if (_inner_error_ != NULL) {
					goto __catch28_g_error;
					goto __finally28;
				}
				gee_abstract_collection_add ((GeeAbstractCollection*) self->thumbnails, thumb);
				_rygel_icon_info_unref0 (thumb);
			}
			goto __finally28;
			__catch28_g_error:
			{
				GError * err;
				err = _inner_error_;
				_inner_error_ = NULL;
				{
					_g_error_free0 (err);
				}
			}
			__finally28:
			if (_inner_error_ != NULL) {
				_g_object_unref0 (thumbnailer);
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return;
			}
			_g_object_unref0 (thumbnailer);
		}
	}
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


gint rygel_media_item_compare_transcoders (RygelMediaItem* self, void* a, void* b) {
	gint result;
	RygelTranscoder* transcoder1;
	RygelTranscoder* transcoder2;
	g_return_val_if_fail (self != NULL, 0);
	transcoder1 = _g_object_ref0 (RYGEL_TRANSCODER (a));
	transcoder2 = _g_object_ref0 (RYGEL_TRANSCODER (b));
	result = ((gint) rygel_transcoder_get_distance (transcoder1, self)) - ((gint) rygel_transcoder_get_distance (transcoder2, self));
	_g_object_unref0 (transcoder1);
	_g_object_unref0 (transcoder2);
	return result;
}


void rygel_media_item_add_resources (RygelMediaItem* self, GUPnPDIDLLiteItem* didl_item, gboolean allow_internal, GError** error) {
	GError * _inner_error_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (didl_item != NULL);
	_inner_error_ = NULL;
	{
		GeeIterator* _uri_it;
		_uri_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) ((RygelMediaObject*) self)->uris);
		while (TRUE) {
			char* uri;
			char* protocol;
			gboolean _tmp0_;
			if (!gee_iterator_next (_uri_it)) {
				break;
			}
			uri = (char*) gee_iterator_get (_uri_it);
			protocol = rygel_media_item_get_protocol_for_uri (self, uri, &_inner_error_);
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_g_free0 (uri);
				_g_object_unref0 (_uri_it);
				return;
			}
			_tmp0_ = FALSE;
			if (allow_internal) {
				_tmp0_ = TRUE;
			} else {
				_tmp0_ = _vala_strcmp0 (protocol, "internal") != 0;
			}
			if (_tmp0_) {
				GUPnPDIDLLiteResource* _tmp1_;
				_tmp1_ = rygel_media_item_add_resource (self, didl_item, uri, protocol, &_inner_error_);
				if (_inner_error_ != NULL) {
					g_propagate_error (error, _inner_error_);
					_g_free0 (uri);
					_g_free0 (protocol);
					_g_object_unref0 (_uri_it);
					return;
				}
				_g_object_unref0 (_tmp1_);
			}
			_g_free0 (uri);
			_g_free0 (protocol);
		}
		_g_object_unref0 (_uri_it);
	}
	{
		GeeIterator* _thumbnail_it;
		_thumbnail_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->thumbnails);
		while (TRUE) {
			RygelThumbnail* thumbnail;
			char* protocol;
			gboolean _tmp2_;
			if (!gee_iterator_next (_thumbnail_it)) {
				break;
			}
			thumbnail = (RygelThumbnail*) gee_iterator_get (_thumbnail_it);
			protocol = rygel_media_item_get_protocol_for_uri (self, thumbnail->uri, &_inner_error_);
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_rygel_icon_info_unref0 (thumbnail);
				_g_object_unref0 (_thumbnail_it);
				return;
			}
			_tmp2_ = FALSE;
			if (allow_internal) {
				_tmp2_ = TRUE;
			} else {
				_tmp2_ = _vala_strcmp0 (protocol, "internal") != 0;
			}
			if (_tmp2_) {
				GUPnPDIDLLiteResource* _tmp3_;
				_tmp3_ = rygel_thumbnail_add_resource (thumbnail, didl_item, protocol);
				_g_object_unref0 (_tmp3_);
			}
			_rygel_icon_info_unref0 (thumbnail);
			_g_free0 (protocol);
		}
		_g_object_unref0 (_thumbnail_it);
	}
}


GUPnPDIDLLiteResource* rygel_media_item_add_resource (RygelMediaItem* self, GUPnPDIDLLiteItem* didl_item, const char* uri, const char* protocol, GError** error) {
	GUPnPDIDLLiteResource* result;
	GUPnPDIDLLiteResource* res;
	GUPnPProtocolInfo* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (didl_item != NULL, NULL);
	g_return_val_if_fail (protocol != NULL, NULL);
	res = gupnp_didl_lite_object_add_resource ((GUPnPDIDLLiteObject*) didl_item);
	if (uri != NULL) {
		gupnp_didl_lite_resource_set_uri (res, uri);
	}
	gupnp_didl_lite_resource_set_size (res, self->size);
	gupnp_didl_lite_resource_set_duration (res, self->duration);
	gupnp_didl_lite_resource_set_bitrate (res, self->bitrate);
	gupnp_didl_lite_resource_set_sample_freq (res, self->sample_freq);
	gupnp_didl_lite_resource_set_bits_per_sample (res, self->bits_per_sample);
	gupnp_didl_lite_resource_set_audio_channels (res, self->n_audio_channels);
	gupnp_didl_lite_resource_set_width (res, self->width);
	gupnp_didl_lite_resource_set_height (res, self->height);
	gupnp_didl_lite_resource_set_color_depth (res, self->color_depth);
	gupnp_didl_lite_resource_set_protocol_info (res, _tmp0_ = rygel_media_item_get_protocol_info (self, uri, protocol));
	_g_object_unref0 (_tmp0_);
	result = res;
	return result;
}


static GUPnPProtocolInfo* rygel_media_item_get_protocol_info (RygelMediaItem* self, const char* uri, const char* protocol) {
	GUPnPProtocolInfo* result;
	GUPnPProtocolInfo* protocol_info;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (protocol != NULL, NULL);
	protocol_info = gupnp_protocol_info_new ();
	gupnp_protocol_info_set_mime_type (protocol_info, self->mime_type);
	gupnp_protocol_info_set_dlna_profile (protocol_info, self->dlna_profile);
	gupnp_protocol_info_set_protocol (protocol_info, protocol);
	if (g_str_has_prefix (self->upnp_class, RYGEL_MEDIA_ITEM_IMAGE_CLASS)) {
		gupnp_protocol_info_set_dlna_flags (protocol_info, gupnp_protocol_info_get_dlna_flags (protocol_info) | GUPNP_DLNA_FLAGS_INTERACTIVE_TRANSFER_MODE);
	} else {
		gupnp_protocol_info_set_dlna_flags (protocol_info, gupnp_protocol_info_get_dlna_flags (protocol_info) | GUPNP_DLNA_FLAGS_STREAMING_TRANSFER_MODE);
	}
	if (!rygel_media_item_should_stream (self)) {
		gupnp_protocol_info_set_dlna_operation (protocol_info, GUPNP_DLNA_OPERATION_RANGE);
		gupnp_protocol_info_set_dlna_flags (protocol_info, gupnp_protocol_info_get_dlna_flags (protocol_info) | GUPNP_DLNA_FLAGS_BACKGROUND_TRANSFER_MODE);
	}
	result = protocol_info;
	return result;
}


static char* rygel_media_item_get_protocol_for_uri (RygelMediaItem* self, const char* uri, GError** error) {
	char* result;
	GError * _inner_error_;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (uri != NULL, NULL);
	_inner_error_ = NULL;
	if (g_str_has_prefix (uri, "http")) {
		result = g_strdup ("http-get");
		return result;
	} else {
		if (g_str_has_prefix (uri, "file")) {
			result = g_strdup ("internal");
			return result;
		} else {
			if (g_str_has_prefix (uri, "rtsp")) {
				result = g_strdup ("rtsp-rtp-udp");
				return result;
			} else {
				char** _tmp1_;
				gint tokens_size;
				gint tokens_length1;
				char** _tmp0_;
				char** tokens;
				tokens = (_tmp1_ = _tmp0_ = g_strsplit (uri, ":", 2), tokens_length1 = _vala_array_length (_tmp0_), tokens_size = tokens_length1, _tmp1_);
				if (tokens[0] == NULL) {
					_inner_error_ = g_error_new (RYGEL_MEDIA_ITEM_ERROR, RYGEL_MEDIA_ITEM_ERROR_BAD_URI, "Bad URI: %s", uri);
					if (_inner_error_ != NULL) {
						g_propagate_error (error, _inner_error_);
						tokens = (_vala_array_free (tokens, tokens_length1, (GDestroyNotify) g_free), NULL);
						return NULL;
					}
				}
				g_warning ("rygel-media-item.vala:223: Failed to probe protocol for URI %s. Assuming '%s'", uri, tokens[0]);
				result = g_strdup (tokens[0]);
				tokens = (_vala_array_free (tokens, tokens_length1, (GDestroyNotify) g_free), NULL);
				return result;
			}
		}
	}
}


static void rygel_media_item_class_init (RygelMediaItemClass * klass) {
	rygel_media_item_parent_class = g_type_class_peek_parent (klass);
	RYGEL_MEDIA_ITEM_CLASS (klass)->create_stream_source = rygel_media_item_real_create_stream_source;
	RYGEL_MEDIA_ITEM_CLASS (klass)->should_stream = rygel_media_item_real_should_stream;
	G_OBJECT_CLASS (klass)->finalize = rygel_media_item_finalize;
}


static void rygel_media_item_instance_init (RygelMediaItem * self) {
	self->size = (glong) (-1);
	self->duration = (glong) (-1);
	self->bitrate = -1;
	self->sample_freq = -1;
	self->bits_per_sample = -1;
	self->n_audio_channels = -1;
	self->track_number = -1;
	self->width = -1;
	self->height = -1;
	self->pixel_width = -1;
	self->pixel_height = -1;
	self->color_depth = -1;
}


static void rygel_media_item_finalize (GObject* obj) {
	RygelMediaItem * self;
	self = RYGEL_MEDIA_ITEM (obj);
	_g_free0 (self->author);
	_g_free0 (self->album);
	_g_free0 (self->date);
	_g_free0 (self->upnp_class);
	_g_free0 (self->mime_type);
	_g_free0 (self->dlna_profile);
	_g_object_unref0 (self->thumbnails);
	G_OBJECT_CLASS (rygel_media_item_parent_class)->finalize (obj);
}


GType rygel_media_item_get_type (void) {
	static GType rygel_media_item_type_id = 0;
	if (rygel_media_item_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediaItemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_media_item_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediaItem), 0, (GInstanceInitFunc) rygel_media_item_instance_init, NULL };
		rygel_media_item_type_id = g_type_register_static (RYGEL_TYPE_MEDIA_OBJECT, "RygelMediaItem", &g_define_type_info, 0);
	}
	return rygel_media_item_type_id;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
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




