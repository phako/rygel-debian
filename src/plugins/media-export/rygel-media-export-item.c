/* rygel-media-export-item.c generated by valac, the Vala compiler
 * generated from rygel-media-export-item.vala, do not modify */

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
static RygelMediaExportItem* rygel_media_export_item_new_from_taglist (RygelMediaContainer* parent, const char* id, GFile* file, GstTagList* tag_list, const char* upnp_class);
static RygelMediaExportItem* rygel_media_export_item_construct_from_taglist (GType object_type, RygelMediaContainer* parent, const char* id, GFile* file, GstTagList* tag_list, const char* upnp_class);
RygelMediaItem* rygel_media_export_item_create_from_taglist (RygelMediaContainer* parent, GFile* file, GstTagList* tag_list);
static int _vala_strcmp0 (const char * str1, const char * str2);



#line 31 "rygel-media-export-item.vala"
RygelMediaExportItem* rygel_media_export_item_construct (GType object_type, RygelMediaContainer* parent, GFile* file, GFileInfo* info) {
#line 76 "rygel-media-export-item.c"
	RygelMediaExportItem * self;
	char* content_type;
	char* item_class;
	char* id;
	char* _tmp5_;
	char* _tmp6_;
#line 31 "rygel-media-export-item.vala"
	g_return_val_if_fail (parent != NULL, NULL);
#line 31 "rygel-media-export-item.vala"
	g_return_val_if_fail (file != NULL, NULL);
#line 31 "rygel-media-export-item.vala"
	g_return_val_if_fail (info != NULL, NULL);
#line 34 "rygel-media-export-item.vala"
	content_type = g_strdup (g_file_info_get_content_type (info));
#line 35 "rygel-media-export-item.vala"
	item_class = NULL;
#line 36 "rygel-media-export-item.vala"
	id = g_compute_checksum_for_string (G_CHECKSUM_MD5, g_file_info_get_name (info), -1);
#line 42 "rygel-media-export-item.vala"
	if (g_str_has_prefix (content_type, "video/")) {
#line 97 "rygel-media-export-item.c"
		char* _tmp0_;
#line 43 "rygel-media-export-item.vala"
		item_class = (_tmp0_ = g_strdup (RYGEL_MEDIA_ITEM_VIDEO_CLASS), _g_free0 (item_class), _tmp0_);
#line 101 "rygel-media-export-item.c"
	} else {
#line 44 "rygel-media-export-item.vala"
		if (g_str_has_prefix (content_type, "audio/")) {
#line 105 "rygel-media-export-item.c"
			char* _tmp1_;
#line 45 "rygel-media-export-item.vala"
			item_class = (_tmp1_ = g_strdup (RYGEL_MEDIA_ITEM_AUDIO_CLASS), _g_free0 (item_class), _tmp1_);
#line 109 "rygel-media-export-item.c"
		} else {
#line 46 "rygel-media-export-item.vala"
			if (g_str_has_prefix (content_type, "image/")) {
#line 113 "rygel-media-export-item.c"
				char* _tmp2_;
#line 47 "rygel-media-export-item.vala"
				item_class = (_tmp2_ = g_strdup (RYGEL_MEDIA_ITEM_PHOTO_CLASS), _g_free0 (item_class), _tmp2_);
#line 117 "rygel-media-export-item.c"
			}
		}
	}
#line 50 "rygel-media-export-item.vala"
	if (item_class == NULL) {
#line 123 "rygel-media-export-item.c"
		char* _tmp3_;
		char* _tmp4_;
#line 51 "rygel-media-export-item.vala"
		item_class = (_tmp3_ = g_strdup (RYGEL_MEDIA_ITEM_AUDIO_CLASS), _g_free0 (item_class), _tmp3_);
#line 52 "rygel-media-export-item.vala"
		g_warning ("rygel-media-export-item.vala:52: Failed to detect UPnP class for '%s'," \
" assuming it's '%s'", _tmp4_ = g_file_get_uri (file), item_class);
#line 130 "rygel-media-export-item.c"
		_g_free0 (_tmp4_);
	}
#line 56 "rygel-media-export-item.vala"
	self = (RygelMediaExportItem*) rygel_media_item_construct (object_type, id, parent, g_file_info_get_name (info), item_class);
#line 58 "rygel-media-export-item.vala"
	((RygelMediaItem*) self)->mime_type = (_tmp5_ = g_strdup (content_type), _g_free0 (((RygelMediaItem*) self)->mime_type), _tmp5_);
#line 59 "rygel-media-export-item.vala"
	rygel_media_item_add_uri ((RygelMediaItem*) self, _tmp6_ = g_file_get_uri (file), NULL);
#line 139 "rygel-media-export-item.c"
	_g_free0 (_tmp6_);
	_g_free0 (content_type);
	_g_free0 (item_class);
	_g_free0 (id);
	return self;
}


#line 31 "rygel-media-export-item.vala"
RygelMediaExportItem* rygel_media_export_item_new (RygelMediaContainer* parent, GFile* file, GFileInfo* info) {
#line 31 "rygel-media-export-item.vala"
	return rygel_media_export_item_construct (RYGEL_TYPE_MEDIA_EXPORT_ITEM, parent, file, info);
#line 152 "rygel-media-export-item.c"
}


#line 62 "rygel-media-export-item.vala"
RygelMediaItem* rygel_media_export_item_create_from_taglist (RygelMediaContainer* parent, GFile* file, GstTagList* tag_list) {
#line 158 "rygel-media-export-item.c"
	RygelMediaItem* result = NULL;
	char* _tmp0_;
	char* _tmp1_;
	char* id;
	gint width;
	gint height;
	char* class_guessed;
#line 62 "rygel-media-export-item.vala"
	g_return_val_if_fail (parent != NULL, NULL);
#line 62 "rygel-media-export-item.vala"
	g_return_val_if_fail (file != NULL, NULL);
#line 62 "rygel-media-export-item.vala"
	g_return_val_if_fail (tag_list != NULL, NULL);
#line 65 "rygel-media-export-item.vala"
	id = (_tmp1_ = g_compute_checksum_for_string (G_CHECKSUM_MD5, _tmp0_ = g_file_get_uri (file), -1), _g_free0 (_tmp0_), _tmp1_);
#line 67 "rygel-media-export-item.vala"
	width = -1;
#line 68 "rygel-media-export-item.vala"
	height = -1;
#line 69 "rygel-media-export-item.vala"
	class_guessed = NULL;
#line 71 "rygel-media-export-item.vala"
	if (tag_list != NULL) {
#line 182 "rygel-media-export-item.c"
		char* codec;
		char* _tmp4_;
		gboolean _tmp3_;
		char* _tmp2_ = NULL;
		codec = NULL;
#line 74 "rygel-media-export-item.vala"
		if (!(_tmp3_ = gst_tag_list_get_string (tag_list, GST_TAG_VIDEO_CODEC, &_tmp2_), codec = (_tmp4_ = _tmp2_, _g_free0 (codec), _tmp4_), _tmp3_)) {
#line 190 "rygel-media-export-item.c"
			char* _tmp7_;
			gboolean _tmp6_;
			char* _tmp5_ = NULL;
#line 75 "rygel-media-export-item.vala"
			if (!(_tmp6_ = gst_tag_list_get_string (tag_list, GST_TAG_AUDIO_CODEC, &_tmp5_), codec = (_tmp7_ = _tmp5_, _g_free0 (codec), _tmp7_), _tmp6_)) {
#line 196 "rygel-media-export-item.c"
				gboolean _tmp8_ = FALSE;
#line 76 "rygel-media-export-item.vala"
				if (gst_tag_list_get_int (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_WIDTH, &width)) {
#line 76 "rygel-media-export-item.vala"
					_tmp8_ = TRUE;
#line 202 "rygel-media-export-item.c"
				} else {
#line 77 "rygel-media-export-item.vala"
					_tmp8_ = gst_tag_list_get_int (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_HEIGHT, &height);
#line 206 "rygel-media-export-item.c"
				}
#line 76 "rygel-media-export-item.vala"
				if (_tmp8_) {
#line 210 "rygel-media-export-item.c"
					char* _tmp9_;
#line 78 "rygel-media-export-item.vala"
					class_guessed = (_tmp9_ = g_strdup (RYGEL_MEDIA_ITEM_PHOTO_CLASS), _g_free0 (class_guessed), _tmp9_);
#line 214 "rygel-media-export-item.c"
				} else {
					gint64 duration = 0LL;
#line 84 "rygel-media-export-item.vala"
					if (gst_tag_list_get_int64 (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_DURATION, &duration)) {
#line 219 "rygel-media-export-item.c"
						char* _tmp10_;
#line 86 "rygel-media-export-item.vala"
						class_guessed = (_tmp10_ = g_strdup (RYGEL_MEDIA_ITEM_VIDEO_CLASS), _g_free0 (class_guessed), _tmp10_);
#line 223 "rygel-media-export-item.c"
					} else {
						char* _tmp11_;
#line 88 "rygel-media-export-item.vala"
						g_warning ("There's no codec inside and file is no image: " "%s", _tmp11_ = g_file_get_uri (file));
#line 228 "rygel-media-export-item.c"
						_g_free0 (_tmp11_);
						result = NULL;
						_g_free0 (codec);
						_g_free0 (id);
						_g_free0 (class_guessed);
#line 90 "rygel-media-export-item.vala"
						return result;
#line 236 "rygel-media-export-item.c"
					}
				}
			} else {
				gboolean _tmp12_ = FALSE;
#line 97 "rygel-media-export-item.vala"
				if (gst_tag_list_get_int (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_WIDTH, &width)) {
#line 97 "rygel-media-export-item.vala"
					_tmp12_ = TRUE;
#line 245 "rygel-media-export-item.c"
				} else {
#line 98 "rygel-media-export-item.vala"
					_tmp12_ = gst_tag_list_get_int (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_HEIGHT, &height);
#line 249 "rygel-media-export-item.c"
				}
#line 97 "rygel-media-export-item.vala"
				if (_tmp12_) {
#line 253 "rygel-media-export-item.c"
					char* _tmp13_;
#line 99 "rygel-media-export-item.vala"
					class_guessed = (_tmp13_ = g_strdup (RYGEL_MEDIA_ITEM_VIDEO_CLASS), _g_free0 (class_guessed), _tmp13_);
#line 257 "rygel-media-export-item.c"
				} else {
					char* _tmp14_;
#line 101 "rygel-media-export-item.vala"
					class_guessed = (_tmp14_ = g_strdup (RYGEL_MEDIA_ITEM_AUDIO_CLASS), _g_free0 (class_guessed), _tmp14_);
#line 262 "rygel-media-export-item.c"
				}
			}
		} else {
			char* _tmp15_;
#line 105 "rygel-media-export-item.vala"
			class_guessed = (_tmp15_ = g_strdup (RYGEL_MEDIA_ITEM_VIDEO_CLASS), _g_free0 (class_guessed), _tmp15_);
#line 269 "rygel-media-export-item.c"
		}
		_g_free0 (codec);
	} else {
		char* _tmp16_;
#line 109 "rygel-media-export-item.vala"
		g_warning ("rygel-media-export-item.vala:109: Got empty taglist for file %s", _tmp16_ = g_file_get_uri (file));
#line 276 "rygel-media-export-item.c"
		_g_free0 (_tmp16_);
		result = NULL;
		_g_free0 (id);
		_g_free0 (class_guessed);
#line 110 "rygel-media-export-item.vala"
		return result;
#line 283 "rygel-media-export-item.c"
	}
	result = (RygelMediaItem*) rygel_media_export_item_new_from_taglist (parent, id, file, tag_list, class_guessed);
	_g_free0 (id);
	_g_free0 (class_guessed);
#line 113 "rygel-media-export-item.vala"
	return result;
#line 290 "rygel-media-export-item.c"
}


#line 120 "rygel-media-export-item.vala"
static RygelMediaExportItem* rygel_media_export_item_construct_from_taglist (GType object_type, RygelMediaContainer* parent, const char* id, GFile* file, GstTagList* tag_list, const char* upnp_class) {
#line 296 "rygel-media-export-item.c"
	RygelMediaExportItem * self;
	char* title;
	gboolean _tmp0_ = FALSE;
	gint64 duration = 0LL;
	glong _tmp6_ = 0L;
	char* _tmp8_;
	char* _tmp7_ = NULL;
	char* _tmp10_;
	char* _tmp9_ = NULL;
	guint tmp = 0U;
	gint64 size = 0LL;
	guint64 mtime = 0ULL;
	GDate* date = NULL;
	GDate* _tmp13_;
	gboolean _tmp12_;
	GDate* _tmp11_ = NULL;
	char* _tmp19_;
	char* _tmp18_ = NULL;
	char* _tmp20_;
#line 120 "rygel-media-export-item.vala"
	g_return_val_if_fail (parent != NULL, NULL);
#line 120 "rygel-media-export-item.vala"
	g_return_val_if_fail (id != NULL, NULL);
#line 120 "rygel-media-export-item.vala"
	g_return_val_if_fail (file != NULL, NULL);
#line 120 "rygel-media-export-item.vala"
	g_return_val_if_fail (tag_list != NULL, NULL);
#line 120 "rygel-media-export-item.vala"
	g_return_val_if_fail (upnp_class != NULL, NULL);
#line 125 "rygel-media-export-item.vala"
	title = NULL;
#line 126 "rygel-media-export-item.vala"
	if (_vala_strcmp0 (upnp_class, RYGEL_MEDIA_ITEM_AUDIO_CLASS) == 0) {
#line 126 "rygel-media-export-item.vala"
		_tmp0_ = TRUE;
#line 332 "rygel-media-export-item.c"
	} else {
#line 127 "rygel-media-export-item.vala"
		_tmp0_ = _vala_strcmp0 (upnp_class, RYGEL_MEDIA_ITEM_MUSIC_CLASS) == 0;
#line 336 "rygel-media-export-item.c"
	}
#line 126 "rygel-media-export-item.vala"
	if (_tmp0_) {
#line 340 "rygel-media-export-item.c"
		char* _tmp3_;
		gboolean _tmp2_;
		char* _tmp1_ = NULL;
#line 129 "rygel-media-export-item.vala"
		if (!(_tmp2_ = gst_tag_list_get_string (tag_list, GST_TAG_TITLE, &_tmp1_), title = (_tmp3_ = _tmp1_, _g_free0 (title), _tmp3_), _tmp2_)) {
#line 346 "rygel-media-export-item.c"
			char* _tmp4_;
#line 130 "rygel-media-export-item.vala"
			title = (_tmp4_ = g_file_get_basename (file), _g_free0 (title), _tmp4_);
#line 350 "rygel-media-export-item.c"
		}
	} else {
		char* _tmp5_;
#line 134 "rygel-media-export-item.vala"
		title = (_tmp5_ = g_file_get_basename (file), _g_free0 (title), _tmp5_);
#line 356 "rygel-media-export-item.c"
	}
#line 136 "rygel-media-export-item.vala"
	self = (RygelMediaExportItem*) rygel_media_item_construct (object_type, id, parent, title, upnp_class);
#line 138 "rygel-media-export-item.vala"
	gst_tag_list_get_int (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_WIDTH, &((RygelMediaItem*) self)->width);
#line 139 "rygel-media-export-item.vala"
	gst_tag_list_get_int (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_HEIGHT, &((RygelMediaItem*) self)->height);
#line 140 "rygel-media-export-item.vala"
	gst_tag_list_get_int (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_DEPTH, &((RygelMediaItem*) self)->color_depth);
#line 143 "rygel-media-export-item.vala"
	gst_tag_list_get_int64 (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_DURATION, &duration);
#line 145 "rygel-media-export-item.vala"
	if (duration == (-1)) {
#line 145 "rygel-media-export-item.vala"
		_tmp6_ = (glong) (-1);
#line 372 "rygel-media-export-item.c"
	} else {
#line 145 "rygel-media-export-item.vala"
		_tmp6_ = (glong) (duration / 1000000000);
#line 376 "rygel-media-export-item.c"
	}
#line 145 "rygel-media-export-item.vala"
	((RygelMediaItem*) self)->duration = _tmp6_;
#line 147 "rygel-media-export-item.vala"
	gst_tag_list_get_int (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_CHANNELS, &((RygelMediaItem*) self)->n_audio_channels);
#line 149 "rygel-media-export-item.vala"
	gst_tag_list_get_string (tag_list, GST_TAG_ARTIST, &_tmp7_);
#line 149 "rygel-media-export-item.vala"
	((RygelMediaItem*) self)->author = (_tmp8_ = _tmp7_, _g_free0 (((RygelMediaItem*) self)->author), _tmp8_);
#line 150 "rygel-media-export-item.vala"
	gst_tag_list_get_string (tag_list, GST_TAG_ALBUM, &_tmp9_);
#line 150 "rygel-media-export-item.vala"
	((RygelMediaItem*) self)->album = (_tmp10_ = _tmp9_, _g_free0 (((RygelMediaItem*) self)->album), _tmp10_);
#line 153 "rygel-media-export-item.vala"
	gst_tag_list_get_uint (tag_list, GST_TAG_TRACK_NUMBER, &tmp);
#line 154 "rygel-media-export-item.vala"
	((RygelMediaItem*) self)->track_number = (gint) tmp;
#line 155 "rygel-media-export-item.vala"
	gst_tag_list_get_uint (tag_list, GST_TAG_BITRATE, &tmp);
#line 156 "rygel-media-export-item.vala"
	((RygelMediaItem*) self)->bitrate = ((gint) tmp) / 8;
#line 157 "rygel-media-export-item.vala"
	gst_tag_list_get_int (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_RATE, &((RygelMediaItem*) self)->sample_freq);
#line 161 "rygel-media-export-item.vala"
	gst_tag_list_get_int64 (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_SIZE, &size);
#line 162 "rygel-media-export-item.vala"
	((RygelMediaItem*) self)->size = (glong) size;
#line 165 "rygel-media-export-item.vala"
	gst_tag_list_get_uint64 (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_MTIME, &mtime);
#line 167 "rygel-media-export-item.vala"
	((RygelMediaObject*) self)->modified = (guint64) ((gint64) mtime);
#line 170 "rygel-media-export-item.vala"
	if ((_tmp12_ = gst_tag_list_get_date (tag_list, GST_TAG_DATE, &_tmp11_), date = (_tmp13_ = _tmp11_, _g_free0 (date), _tmp13_), _tmp12_)) {
#line 410 "rygel-media-export-item.c"
		gchar* _tmp14_;
		gint _datestr_size_;
		gint datestr_length1;
		gchar* datestr;
		char* _tmp15_;
		datestr = (_tmp14_ = g_new0 (gchar, 30), datestr_length1 = 30, _datestr_size_ = datestr_length1, _tmp14_);
#line 172 "rygel-media-export-item.vala"
		g_date_strftime (datestr, datestr_length1, "%F", date);
#line 173 "rygel-media-export-item.vala"
		((RygelMediaItem*) self)->date = (_tmp15_ = g_strdup ((const char*) datestr), _g_free0 (((RygelMediaItem*) self)->date), _tmp15_);
#line 421 "rygel-media-export-item.c"
		datestr = (g_free (datestr), NULL);
	} else {
		GTimeVal _tmp16_ = {0};
		GTimeVal tv;
		char* _tmp17_;
#line 175 "rygel-media-export-item.vala"
		tv = (_tmp16_.tv_sec = (glong) mtime, _tmp16_.tv_usec = (glong) 0, _tmp16_);
#line 176 "rygel-media-export-item.vala"
		((RygelMediaItem*) self)->date = (_tmp17_ = g_time_val_to_iso8601 (&tv), _g_free0 (((RygelMediaItem*) self)->date), _tmp17_);
#line 431 "rygel-media-export-item.c"
	}
#line 180 "rygel-media-export-item.vala"
	gst_tag_list_get_string (tag_list, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_MIME, &_tmp18_);
#line 180 "rygel-media-export-item.vala"
	((RygelMediaItem*) self)->mime_type = (_tmp19_ = _tmp18_, _g_free0 (((RygelMediaItem*) self)->mime_type), _tmp19_);
#line 183 "rygel-media-export-item.vala"
	rygel_media_item_add_uri ((RygelMediaItem*) self, _tmp20_ = g_file_get_uri (file), NULL);
#line 439 "rygel-media-export-item.c"
	_g_free0 (_tmp20_);
	_g_free0 (title);
	_g_free0 (date);
	return self;
}


#line 120 "rygel-media-export-item.vala"
static RygelMediaExportItem* rygel_media_export_item_new_from_taglist (RygelMediaContainer* parent, const char* id, GFile* file, GstTagList* tag_list, const char* upnp_class) {
#line 120 "rygel-media-export-item.vala"
	return rygel_media_export_item_construct_from_taglist (RYGEL_TYPE_MEDIA_EXPORT_ITEM, parent, id, file, tag_list, upnp_class);
#line 451 "rygel-media-export-item.c"
}


static void rygel_media_export_item_class_init (RygelMediaExportItemClass * klass) {
	rygel_media_export_item_parent_class = g_type_class_peek_parent (klass);
}


static void rygel_media_export_item_instance_init (RygelMediaExportItem * self) {
}


GType rygel_media_export_item_get_type (void) {
	static volatile gsize rygel_media_export_item_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_media_export_item_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediaExportItemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_media_export_item_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediaExportItem), 0, (GInstanceInitFunc) rygel_media_export_item_instance_init, NULL };
		GType rygel_media_export_item_type_id;
		rygel_media_export_item_type_id = g_type_register_static (RYGEL_TYPE_MEDIA_ITEM, "RygelMediaExportItem", &g_define_type_info, 0);
		g_once_init_leave (&rygel_media_export_item_type_id__volatile, rygel_media_export_item_type_id);
	}
	return rygel_media_export_item_type_id__volatile;
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




