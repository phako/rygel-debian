/*
 * Copyright (C) 2008 Zeeshan Ali <zeenix@gmail.com>.
 * Copyright (C) 2008 Nokia Corporation.
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
#include <rygel.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>
#include <gst/gst.h>


#define RYGEL_TYPE_MEDIA_EXPORT_ITEM (rygel_media_export_item_get_type ())
#define RYGEL_MEDIA_EXPORT_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_EXPORT_ITEM, RygelMediaExportItem))
#define RYGEL_MEDIA_EXPORT_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_EXPORT_ITEM, RygelMediaExportItemClass))
#define RYGEL_IS_MEDIA_EXPORT_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_EXPORT_ITEM))
#define RYGEL_IS_MEDIA_EXPORT_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_EXPORT_ITEM))
#define RYGEL_MEDIA_EXPORT_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_EXPORT_ITEM, RygelMediaExportItemClass))

typedef struct _RygelMediaExportItem RygelMediaExportItem;
typedef struct _RygelMediaExportItemClass RygelMediaExportItemClass;
typedef struct _RygelMediaExportItemPrivate RygelMediaExportItemPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))

struct _RygelMediaExportItem {
	RygelMediaItem parent_instance;
	RygelMediaExportItemPrivate * priv;
};

struct _RygelMediaExportItemClass {
	RygelMediaItemClass parent_class;
};


static gpointer rygel_media_export_item_parent_class = NULL;

GType rygel_media_export_item_get_type (void);
enum  {
	RYGEL_MEDIA_EXPORT_ITEM_DUMMY_PROPERTY
};
RygelMediaExportItem* rygel_media_export_item_new (RygelMediaContainer* parent, GFile* file, GFileInfo* info);
RygelMediaExportItem* rygel_media_export_item_construct (GType object_type, RygelMediaContainer* parent, GFile* file, GFileInfo* info);
static void rygel_media_export_item_fill_from_tags_as_image (RygelMediaExportItem* self, GstTagList* tag_list);
static void rygel_media_export_item_fill_from_tags_as_audio (RygelMediaExportItem* self, GstTagList* tag_list);
static void rygel_media_export_item_fill_from_tags_as_video (RygelMediaExportItem* self, GstTagList* tag_list);
static RygelMediaExportItem* rygel_media_export_item_new_from_taglist (RygelMediaContainer* parent, const char* id, GFile* file, GstTagList* tag_list, const char* upnp_class);
static RygelMediaExportItem* rygel_media_export_item_construct_from_taglist (GType object_type, RygelMediaContainer* parent, const char* id, GFile* file, GstTagList* tag_list, const char* upnp_class);
RygelMediaItem* rygel_media_export_item_create_from_taglist (RygelMediaContainer* parent, GFile* file, GstTagList* tag_list);
static int _vala_strcmp0 (const char * str1, const char * str2);



RygelMediaExportItem* rygel_media_export_item_construct (GType object_type, RygelMediaContainer* parent, GFile* file, GFileInfo* info) {
	RygelMediaExportItem * self;
	char* content_type;
	char* item_class;
	char* id;
	char* _tmp5_;
	char* _tmp6_;
	g_return_val_if_fail (parent != NULL, NULL);
	g_return_val_if_fail (file != NULL, NULL);
	g_return_val_if_fail (info != NULL, NULL);
	content_type = g_strdup (g_file_info_get_content_type (info));
	item_class = NULL;
	id = g_compute_checksum_for_string (G_CHECKSUM_MD5, g_file_info_get_name (info), -1);
	if (g_str_has_prefix (content_type, "video/")) {
		char* _tmp0_;
		item_class = (_tmp0_ = g_strdup (RYGEL_MEDIA_ITEM_VIDEO_CLASS), _g_free0 (item_class), _tmp0_);
	} else {
		if (g_str_has_prefix (content_type, "audio/")) {
			char* _tmp1_;
			item_class = (_tmp1_ = g_strdup (RYGEL_MEDIA_ITEM_AUDIO_CLASS), _g_free0 (item_class), _tmp1_);
		} else {
			if (g_str_has_prefix (content_type, "image/")) {
				char* _tmp2_;
				item_class = (_tmp2_ = g_strdup (RYGEL_MEDIA_ITEM_IMAGE_CLASS), _g_free0 (item_class), _tmp2_);
			}
		}
	}
	if (item_class == NULL) {
		char* _tmp3_;
		char* _tmp4_;
		item_class = (_tmp3_ = g_strdup (RYGEL_MEDIA_ITEM_AUDIO_CLASS), _g_free0 (item_class), _tmp3_);
		g_warning ("rygel-media-export-item.vala:52: Failed to detect UPnP class for '%s', assuming it's '%s'", _tmp4_ = g_file_get_uri (file), item_class);
		_g_free0 (_tmp4_);
	}
	self = (RygelMediaExportItem*) rygel_media_item_construct (object_type, id, parent, g_file_info_get_name (info), item_class);
	((RygelMediaItem*) self)->mime_type = (_tmp5_ = g_strdup (content_type), _g_free0 (((RygelMediaItem*) self)->mime_type), _tmp5_);
	rygel_media_item_add_uri ((RygelMediaItem*) self, _tmp6_ = g_file_get_uri (file), NULL);
	_g_free0 (_tmp6_);
	_g_free0 (content_type);
	_g_free0 (item_class);
	_g_free0 (id);
	return self;
}


RygelMediaExportItem* rygel_media_export_item_new (RygelMediaContainer* parent, GFile* file, GFileInfo* info) {
	return rygel_media_export_item_construct (RYGEL_TYPE_MEDIA_EXPORT_ITEM, parent, file, info);
}


static void rygel_media_export_item_fill_from_tags_as_image (RygelMediaExportItem* self, GstTagList* tag_list) {
	char* _tmp2_;
	gboolean _tmp1_;
	char* _tmp0_;
	gint64 size;
	g_return_if_fail (self != NULL);
	g_return_if_fail (tag_list != NULL);
	_tmp0_ = NULL;
	_tmp1_ = gst_tag_list_get_string (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_MIME, &_tmp0_);
	((RygelMediaItem*) self)->mime_type = (_tmp2_ = _tmp0_, _g_free0 (((RygelMediaItem*) self)->mime_type), _tmp2_);
	_tmp1_;
	size = 0LL;
	gst_tag_list_get_int64 (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_SIZE, &size);
	((RygelMediaItem*) self)->size = (glong) size;
	gst_tag_list_get_int (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_WIDTH, &((RygelMediaItem*) self)->width);
	gst_tag_list_get_int (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_HEIGHT, &((RygelMediaItem*) self)->height);
	gst_tag_list_get_int (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_DEPTH, &((RygelMediaItem*) self)->color_depth);
}


static void rygel_media_export_item_fill_from_tags_as_audio (RygelMediaExportItem* self, GstTagList* tag_list) {
	gint64 duration;
	char* _tmp2_;
	gboolean _tmp1_;
	char* _tmp0_;
	gint64 size;
	char* _tmp5_;
	gboolean _tmp4_;
	char* _tmp3_;
	char* _tmp8_;
	gboolean _tmp7_;
	char* _tmp6_;
	guint tmp;
	GDate* date;
	GDate* _tmp11_;
	gboolean _tmp10_;
	GDate* _tmp9_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (tag_list != NULL);
	duration = 0LL;
	gst_tag_list_get_int64 (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_DURATION, &duration);
	((RygelMediaItem*) self)->duration = (glong) (duration / 1000000000);
	gst_tag_list_get_int (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_CHANNELS, &((RygelMediaItem*) self)->n_audio_channels);
	_tmp0_ = NULL;
	_tmp1_ = gst_tag_list_get_string (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_MIME, &_tmp0_);
	((RygelMediaItem*) self)->mime_type = (_tmp2_ = _tmp0_, _g_free0 (((RygelMediaItem*) self)->mime_type), _tmp2_);
	_tmp1_;
	size = 0LL;
	gst_tag_list_get_int64 (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_SIZE, &size);
	((RygelMediaItem*) self)->size = (glong) size;
	_tmp3_ = NULL;
	_tmp4_ = gst_tag_list_get_string (tag_list, GST_TAG_ARTIST, &_tmp3_);
	((RygelMediaItem*) self)->author = (_tmp5_ = _tmp3_, _g_free0 (((RygelMediaItem*) self)->author), _tmp5_);
	_tmp4_;
	_tmp6_ = NULL;
	_tmp7_ = gst_tag_list_get_string (tag_list, GST_TAG_ALBUM, &_tmp6_);
	((RygelMediaItem*) self)->album = (_tmp8_ = _tmp6_, _g_free0 (((RygelMediaItem*) self)->album), _tmp8_);
	_tmp7_;
	tmp = 0U;
	gst_tag_list_get_uint (tag_list, GST_TAG_TRACK_NUMBER, &tmp);
	((RygelMediaItem*) self)->track_number = (gint) tmp;
	gst_tag_list_get_uint (tag_list, GST_TAG_BITRATE, &tmp);
	((RygelMediaItem*) self)->bitrate = ((gint) tmp) / 8;
	gst_tag_list_get_int (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_RATE, &((RygelMediaItem*) self)->sample_freq);
	date = NULL;
	_tmp9_ = NULL;
	if ((_tmp10_ = gst_tag_list_get_date (tag_list, GST_TAG_DATE, &_tmp9_), date = (_tmp11_ = _tmp9_, _g_free0 (date), _tmp11_), _tmp10_)) {
		gchar* _tmp12_;
		gint datestr_size;
		gint datestr_length1;
		gchar* datestr;
		char* _tmp13_;
		datestr = (_tmp12_ = g_new0 (gchar, 30), datestr_length1 = 30, datestr_size = datestr_length1, _tmp12_);
		g_date_strftime (datestr, datestr_length1, "%F", date);
		((RygelMediaItem*) self)->date = (_tmp13_ = g_strdup ((const char*) datestr), _g_free0 (((RygelMediaItem*) self)->date), _tmp13_);
		datestr = (g_free (datestr), NULL);
	}
	_g_free0 (date);
}


static void rygel_media_export_item_fill_from_tags_as_video (RygelMediaExportItem* self, GstTagList* tag_list) {
	char* _tmp2_;
	gboolean _tmp1_;
	char* _tmp0_;
	gint64 size;
	g_return_if_fail (self != NULL);
	g_return_if_fail (tag_list != NULL);
	_tmp0_ = NULL;
	_tmp1_ = gst_tag_list_get_string (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_MIME, &_tmp0_);
	((RygelMediaItem*) self)->mime_type = (_tmp2_ = _tmp0_, _g_free0 (((RygelMediaItem*) self)->mime_type), _tmp2_);
	_tmp1_;
	size = 0LL;
	gst_tag_list_get_int64 (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_SIZE, &size);
	((RygelMediaItem*) self)->size = (glong) size;
	gst_tag_list_get_int (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_WIDTH, &((RygelMediaItem*) self)->width);
	gst_tag_list_get_int (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_HEIGHT, &((RygelMediaItem*) self)->height);
	gst_tag_list_get_int (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_DEPTH, &((RygelMediaItem*) self)->color_depth);
	gst_tag_list_get_int (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_CHANNELS, &((RygelMediaItem*) self)->n_audio_channels);
	gst_tag_list_get_int (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_RATE, &((RygelMediaItem*) self)->sample_freq);
}


RygelMediaItem* rygel_media_export_item_create_from_taglist (RygelMediaContainer* parent, GFile* file, GstTagList* tag_list) {
	RygelMediaItem* result;
	char* _tmp0_;
	char* _tmp1_;
	char* id;
	gint width;
	gint height;
	char* class_guessed;
	g_return_val_if_fail (parent != NULL, NULL);
	g_return_val_if_fail (file != NULL, NULL);
	g_return_val_if_fail (tag_list != NULL, NULL);
	id = (_tmp1_ = g_compute_checksum_for_string (G_CHECKSUM_MD5, _tmp0_ = g_file_get_uri (file), -1), _g_free0 (_tmp0_), _tmp1_);
	width = -1;
	height = -1;
	class_guessed = NULL;
	if (tag_list != NULL) {
		char* codec;
		char* _tmp4_;
		gboolean _tmp3_;
		char* _tmp2_;
		codec = NULL;
		_tmp2_ = NULL;
		if (!(_tmp3_ = gst_tag_list_get_string (tag_list, GST_TAG_VIDEO_CODEC, &_tmp2_), codec = (_tmp4_ = _tmp2_, _g_free0 (codec), _tmp4_), _tmp3_)) {
			char* _tmp7_;
			gboolean _tmp6_;
			char* _tmp5_;
			_tmp5_ = NULL;
			if (!(_tmp6_ = gst_tag_list_get_string (tag_list, GST_TAG_AUDIO_CODEC, &_tmp5_), codec = (_tmp7_ = _tmp5_, _g_free0 (codec), _tmp7_), _tmp6_)) {
				gboolean _tmp8_;
				_tmp8_ = FALSE;
				if (gst_tag_list_get_int (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_WIDTH, &width)) {
					_tmp8_ = TRUE;
				} else {
					_tmp8_ = gst_tag_list_get_int (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_HEIGHT, &height);
				}
				if (_tmp8_) {
					char* _tmp9_;
					class_guessed = (_tmp9_ = g_strdup (RYGEL_MEDIA_ITEM_IMAGE_CLASS), _g_free0 (class_guessed), _tmp9_);
				} else {
					char* _tmp10_;
					g_warning ("There's no codec inside and file is no image: " "%s", _tmp10_ = g_file_get_uri (file));
					_g_free0 (_tmp10_);
					result = NULL;
					_g_free0 (codec);
					_g_free0 (id);
					_g_free0 (class_guessed);
					return result;
				}
			} else {
				char* _tmp11_;
				class_guessed = (_tmp11_ = g_strdup (RYGEL_MEDIA_ITEM_AUDIO_CLASS), _g_free0 (class_guessed), _tmp11_);
			}
		} else {
			char* _tmp12_;
			class_guessed = (_tmp12_ = g_strdup (RYGEL_MEDIA_ITEM_VIDEO_CLASS), _g_free0 (class_guessed), _tmp12_);
		}
		_g_free0 (codec);
	} else {
		char* _tmp13_;
		g_warning ("rygel-media-export-item.vala:152: Got empty taglist for file %s", _tmp13_ = g_file_get_uri (file));
		_g_free0 (_tmp13_);
		result = NULL;
		_g_free0 (id);
		_g_free0 (class_guessed);
		return result;
	}
	result = (RygelMediaItem*) rygel_media_export_item_new_from_taglist (parent, id, file, tag_list, class_guessed);
	_g_free0 (id);
	_g_free0 (class_guessed);
	return result;
}


static RygelMediaExportItem* rygel_media_export_item_construct_from_taglist (GType object_type, RygelMediaContainer* parent, const char* id, GFile* file, GstTagList* tag_list, const char* upnp_class) {
	RygelMediaExportItem * self;
	char* title;
	gboolean _tmp0_;
	GQuark _tmp7_;
	const char* _tmp6_;
	guint64 mtime;
	char* _tmp8_;
	g_return_val_if_fail (parent != NULL, NULL);
	g_return_val_if_fail (id != NULL, NULL);
	g_return_val_if_fail (file != NULL, NULL);
	g_return_val_if_fail (tag_list != NULL, NULL);
	g_return_val_if_fail (upnp_class != NULL, NULL);
	title = NULL;
	_tmp0_ = FALSE;
	if (_vala_strcmp0 (upnp_class, RYGEL_MEDIA_ITEM_AUDIO_CLASS) == 0) {
		_tmp0_ = TRUE;
	} else {
		_tmp0_ = _vala_strcmp0 (upnp_class, RYGEL_MEDIA_ITEM_MUSIC_CLASS) == 0;
	}
	if (_tmp0_) {
		char* _tmp3_;
		gboolean _tmp2_;
		char* _tmp1_;
		_tmp1_ = NULL;
		if (!(_tmp2_ = gst_tag_list_get_string (tag_list, GST_TAG_TITLE, &_tmp1_), title = (_tmp3_ = _tmp1_, _g_free0 (title), _tmp3_), _tmp2_)) {
			char* _tmp4_;
			title = (_tmp4_ = g_file_get_basename (file), _g_free0 (title), _tmp4_);
		}
	} else {
		char* _tmp5_;
		title = (_tmp5_ = g_file_get_basename (file), _g_free0 (title), _tmp5_);
	}
	self = (RygelMediaExportItem*) rygel_media_item_construct (object_type, id, parent, title, upnp_class);
	_tmp6_ = upnp_class;
	_tmp7_ = (NULL == _tmp6_) ? 0 : g_quark_from_string (_tmp6_);
	if ((_tmp7_ == g_quark_from_string (RYGEL_MEDIA_ITEM_AUDIO_CLASS)) || (_tmp7_ == g_quark_from_string (RYGEL_MEDIA_ITEM_MUSIC_CLASS)))
	do {
		rygel_media_export_item_fill_from_tags_as_audio (self, tag_list);
		break;
	} while (0); else if (_tmp7_ == g_quark_from_string (RYGEL_MEDIA_ITEM_VIDEO_CLASS))
	do {
		rygel_media_export_item_fill_from_tags_as_video (self, tag_list);
		break;
	} while (0); else if (_tmp7_ == g_quark_from_string (RYGEL_MEDIA_ITEM_IMAGE_CLASS))
	do {
		rygel_media_export_item_fill_from_tags_as_image (self, tag_list);
		break;
	} while (0); else
	do {
		break;
	} while (0);
	mtime = 0ULL;
	gst_tag_list_get_uint64 (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_MTIME, &mtime);
	((RygelMediaObject*) self)->modified = (guint64) ((gint64) mtime);
	rygel_media_item_add_uri ((RygelMediaItem*) self, _tmp8_ = g_file_get_uri (file), NULL);
	_g_free0 (_tmp8_);
	_g_free0 (title);
	return self;
}


static RygelMediaExportItem* rygel_media_export_item_new_from_taglist (RygelMediaContainer* parent, const char* id, GFile* file, GstTagList* tag_list, const char* upnp_class) {
	return rygel_media_export_item_construct_from_taglist (RYGEL_TYPE_MEDIA_EXPORT_ITEM, parent, id, file, tag_list, upnp_class);
}


static void rygel_media_export_item_class_init (RygelMediaExportItemClass * klass) {
	rygel_media_export_item_parent_class = g_type_class_peek_parent (klass);
}


static void rygel_media_export_item_instance_init (RygelMediaExportItem * self) {
}


GType rygel_media_export_item_get_type (void) {
	static GType rygel_media_export_item_type_id = 0;
	if (rygel_media_export_item_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediaExportItemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_media_export_item_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediaExportItem), 0, (GInstanceInitFunc) rygel_media_export_item_instance_init, NULL };
		rygel_media_export_item_type_id = g_type_register_static (RYGEL_TYPE_MEDIA_ITEM, "RygelMediaExportItem", &g_define_type_info, 0);
	}
	return rygel_media_export_item_type_id;
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




