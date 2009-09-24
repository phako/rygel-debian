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
#include <stdlib.h>
#include <string.h>


#define RYGEL_TYPE_TRACKER_ITEM (rygel_tracker_item_get_type ())
#define RYGEL_TRACKER_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_ITEM, RygelTrackerItem))
#define RYGEL_TRACKER_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_ITEM, RygelTrackerItemClass))
#define RYGEL_IS_TRACKER_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_ITEM))
#define RYGEL_IS_TRACKER_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_ITEM))
#define RYGEL_TRACKER_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_ITEM, RygelTrackerItemClass))

typedef struct _RygelTrackerItem RygelTrackerItem;
typedef struct _RygelTrackerItemClass RygelTrackerItemClass;
typedef struct _RygelTrackerItemPrivate RygelTrackerItemPrivate;

#define RYGEL_TRACKER_ITEM_TYPE_METADATA (rygel_tracker_item_metadata_get_type ())
#define _g_free0(var) (var = (g_free (var), NULL))

#define RYGEL_TYPE_TRACKER_SEARCH_CONTAINER (rygel_tracker_search_container_get_type ())
#define RYGEL_TRACKER_SEARCH_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainer))
#define RYGEL_TRACKER_SEARCH_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainerClass))
#define RYGEL_IS_TRACKER_SEARCH_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER))
#define RYGEL_IS_TRACKER_SEARCH_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER))
#define RYGEL_TRACKER_SEARCH_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainerClass))

typedef struct _RygelTrackerSearchContainer RygelTrackerSearchContainer;
typedef struct _RygelTrackerSearchContainerClass RygelTrackerSearchContainerClass;

struct _RygelTrackerItem {
	RygelMediaItem parent_instance;
	RygelTrackerItemPrivate * priv;
	char* path;
};

struct _RygelTrackerItemClass {
	RygelMediaItemClass parent_class;
};

typedef enum  {
	RYGEL_TRACKER_ITEM_METADATA_FILE_NAME,
	RYGEL_TRACKER_ITEM_METADATA_MIME,
	RYGEL_TRACKER_ITEM_METADATA_SIZE,
	RYGEL_TRACKER_ITEM_METADATA_DATE,
	RYGEL_TRACKER_ITEM_METADATA_IMAGE_TITLE,
	RYGEL_TRACKER_ITEM_METADATA_IMAGE_WIDTH,
	RYGEL_TRACKER_ITEM_METADATA_IMAGE_HEIGHT,
	RYGEL_TRACKER_ITEM_METADATA_IMAGE_ALBUM,
	RYGEL_TRACKER_ITEM_METADATA_IMAGE_DATE,
	RYGEL_TRACKER_ITEM_METADATA_CREATOR,
	RYGEL_TRACKER_ITEM_METADATA_AUDIO_TITLE,
	RYGEL_TRACKER_ITEM_METADATA_AUDIO_DURATION,
	RYGEL_TRACKER_ITEM_METADATA_AUDIO_ALBUM,
	RYGEL_TRACKER_ITEM_METADATA_ARTIST,
	RYGEL_TRACKER_ITEM_METADATA_TRACK_NUM,
	RYGEL_TRACKER_ITEM_METADATA_RELEASE,
	RYGEL_TRACKER_ITEM_METADATA_DATE_ADDED,
	RYGEL_TRACKER_ITEM_METADATA_VIDEO_TITLE,
	RYGEL_TRACKER_ITEM_METADATA_VIDEO_WIDTH,
	RYGEL_TRACKER_ITEM_METADATA_VIDEO_HEIGHT,
	RYGEL_TRACKER_ITEM_METADATA_VIDEO_DURATION,
	RYGEL_TRACKER_ITEM_METADATA_AUTHOR,
	RYGEL_TRACKER_ITEM_METADATA_LAST_KEY
} RygelTrackerItemMetadata;


static gpointer rygel_tracker_item_parent_class = NULL;

GType rygel_tracker_item_get_type (void);
enum  {
	RYGEL_TRACKER_ITEM_DUMMY_PROPERTY
};
GType rygel_tracker_item_metadata_get_type (void);
char* rygel_tracker_item_seconds_to_iso8601 (RygelTrackerItem* self, const char* seconds);
GType rygel_tracker_search_container_get_type (void);
RygelTrackerItem* rygel_tracker_item_construct (GType object_type, const char* id, const char* path, RygelTrackerSearchContainer* parent, const char* upnp_class, char** metadata, int metadata_length1);
char** rygel_tracker_item_get_metadata_keys (int* result_length1);
static void rygel_tracker_item_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static int _vala_strcmp0 (const char * str1, const char * str2);




GType rygel_tracker_item_metadata_get_type (void) {
	static GType rygel_tracker_item_metadata_type_id = 0;
	if (G_UNLIKELY (rygel_tracker_item_metadata_type_id == 0)) {
		static const GEnumValue values[] = {{RYGEL_TRACKER_ITEM_METADATA_FILE_NAME, "RYGEL_TRACKER_ITEM_METADATA_FILE_NAME", "file-name"}, {RYGEL_TRACKER_ITEM_METADATA_MIME, "RYGEL_TRACKER_ITEM_METADATA_MIME", "mime"}, {RYGEL_TRACKER_ITEM_METADATA_SIZE, "RYGEL_TRACKER_ITEM_METADATA_SIZE", "size"}, {RYGEL_TRACKER_ITEM_METADATA_DATE, "RYGEL_TRACKER_ITEM_METADATA_DATE", "date"}, {RYGEL_TRACKER_ITEM_METADATA_IMAGE_TITLE, "RYGEL_TRACKER_ITEM_METADATA_IMAGE_TITLE", "image-title"}, {RYGEL_TRACKER_ITEM_METADATA_IMAGE_WIDTH, "RYGEL_TRACKER_ITEM_METADATA_IMAGE_WIDTH", "image-width"}, {RYGEL_TRACKER_ITEM_METADATA_IMAGE_HEIGHT, "RYGEL_TRACKER_ITEM_METADATA_IMAGE_HEIGHT", "image-height"}, {RYGEL_TRACKER_ITEM_METADATA_IMAGE_ALBUM, "RYGEL_TRACKER_ITEM_METADATA_IMAGE_ALBUM", "image-album"}, {RYGEL_TRACKER_ITEM_METADATA_IMAGE_DATE, "RYGEL_TRACKER_ITEM_METADATA_IMAGE_DATE", "image-date"}, {RYGEL_TRACKER_ITEM_METADATA_CREATOR, "RYGEL_TRACKER_ITEM_METADATA_CREATOR", "creator"}, {RYGEL_TRACKER_ITEM_METADATA_AUDIO_TITLE, "RYGEL_TRACKER_ITEM_METADATA_AUDIO_TITLE", "audio-title"}, {RYGEL_TRACKER_ITEM_METADATA_AUDIO_DURATION, "RYGEL_TRACKER_ITEM_METADATA_AUDIO_DURATION", "audio-duration"}, {RYGEL_TRACKER_ITEM_METADATA_AUDIO_ALBUM, "RYGEL_TRACKER_ITEM_METADATA_AUDIO_ALBUM", "audio-album"}, {RYGEL_TRACKER_ITEM_METADATA_ARTIST, "RYGEL_TRACKER_ITEM_METADATA_ARTIST", "artist"}, {RYGEL_TRACKER_ITEM_METADATA_TRACK_NUM, "RYGEL_TRACKER_ITEM_METADATA_TRACK_NUM", "track-num"}, {RYGEL_TRACKER_ITEM_METADATA_RELEASE, "RYGEL_TRACKER_ITEM_METADATA_RELEASE", "release"}, {RYGEL_TRACKER_ITEM_METADATA_DATE_ADDED, "RYGEL_TRACKER_ITEM_METADATA_DATE_ADDED", "date-added"}, {RYGEL_TRACKER_ITEM_METADATA_VIDEO_TITLE, "RYGEL_TRACKER_ITEM_METADATA_VIDEO_TITLE", "video-title"}, {RYGEL_TRACKER_ITEM_METADATA_VIDEO_WIDTH, "RYGEL_TRACKER_ITEM_METADATA_VIDEO_WIDTH", "video-width"}, {RYGEL_TRACKER_ITEM_METADATA_VIDEO_HEIGHT, "RYGEL_TRACKER_ITEM_METADATA_VIDEO_HEIGHT", "video-height"}, {RYGEL_TRACKER_ITEM_METADATA_VIDEO_DURATION, "RYGEL_TRACKER_ITEM_METADATA_VIDEO_DURATION", "video-duration"}, {RYGEL_TRACKER_ITEM_METADATA_AUTHOR, "RYGEL_TRACKER_ITEM_METADATA_AUTHOR", "author"}, {RYGEL_TRACKER_ITEM_METADATA_LAST_KEY, "RYGEL_TRACKER_ITEM_METADATA_LAST_KEY", "last-key"}, {0, NULL, NULL}};
		rygel_tracker_item_metadata_type_id = g_enum_register_static ("RygelTrackerItemMetadata", values);
	}
	return rygel_tracker_item_metadata_type_id;
}


RygelTrackerItem* rygel_tracker_item_construct (GType object_type, const char* id, const char* path, RygelTrackerSearchContainer* parent, const char* upnp_class, char** metadata, int metadata_length1) {
	GError * _inner_error_;
	RygelTrackerItem * self;
	char* _tmp0_;
	char* _tmp2_;
	char* _tmp3_;
	char* _tmp4_;
	g_return_val_if_fail (id != NULL, NULL);
	g_return_val_if_fail (path != NULL, NULL);
	g_return_val_if_fail (parent != NULL, NULL);
	g_return_val_if_fail (upnp_class != NULL, NULL);
	_inner_error_ = NULL;
	self = (RygelTrackerItem*) rygel_media_item_construct (object_type, id, (RygelMediaContainer*) parent, "", upnp_class);
	self->path = (_tmp0_ = g_strdup (path), _g_free0 (self->path), _tmp0_);
	if (_vala_strcmp0 (metadata[RYGEL_TRACKER_ITEM_METADATA_SIZE], "") != 0) {
		((RygelMediaItem*) self)->size = (glong) atoi (metadata[RYGEL_TRACKER_ITEM_METADATA_SIZE]);
	}
	if (_vala_strcmp0 (metadata[RYGEL_TRACKER_ITEM_METADATA_DATE], "") != 0) {
		char* _tmp1_;
		((RygelMediaItem*) self)->date = (_tmp1_ = rygel_tracker_item_seconds_to_iso8601 (self, metadata[RYGEL_TRACKER_ITEM_METADATA_DATE]), _g_free0 (((RygelMediaItem*) self)->date), _tmp1_);
	}
	((RygelMediaItem*) self)->mime_type = (_tmp2_ = g_strdup (metadata[RYGEL_TRACKER_ITEM_METADATA_MIME]), _g_free0 (((RygelMediaItem*) self)->mime_type), _tmp2_);
	_tmp3_ = g_filename_to_uri (path, NULL, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	rygel_media_item_add_uri ((RygelMediaItem*) self, _tmp4_ = _tmp3_, NULL);
	_g_free0 (_tmp4_);
	return self;
}


char** rygel_tracker_item_get_metadata_keys (int* result_length1) {
	char** result;
	char** _tmp0_;
	gint keys_size;
	gint keys_length1;
	char** keys;
	char* _tmp1_;
	char* _tmp2_;
	char* _tmp3_;
	char* _tmp4_;
	char* _tmp5_;
	char* _tmp6_;
	char* _tmp7_;
	char* _tmp8_;
	char* _tmp9_;
	char* _tmp10_;
	char* _tmp11_;
	char* _tmp12_;
	char* _tmp13_;
	char* _tmp14_;
	char* _tmp15_;
	char* _tmp16_;
	char* _tmp17_;
	char* _tmp18_;
	char* _tmp19_;
	char* _tmp20_;
	char* _tmp21_;
	char* _tmp22_;
	char** _tmp23_;
	keys = (_tmp0_ = g_new0 (char*, RYGEL_TRACKER_ITEM_METADATA_LAST_KEY + 1), keys_length1 = RYGEL_TRACKER_ITEM_METADATA_LAST_KEY, keys_size = keys_length1, _tmp0_);
	keys[RYGEL_TRACKER_ITEM_METADATA_FILE_NAME] = (_tmp1_ = g_strdup ("File:Name"), _g_free0 (keys[RYGEL_TRACKER_ITEM_METADATA_FILE_NAME]), _tmp1_);
	keys[RYGEL_TRACKER_ITEM_METADATA_MIME] = (_tmp2_ = g_strdup ("File:Mime"), _g_free0 (keys[RYGEL_TRACKER_ITEM_METADATA_MIME]), _tmp2_);
	keys[RYGEL_TRACKER_ITEM_METADATA_SIZE] = (_tmp3_ = g_strdup ("File:Size"), _g_free0 (keys[RYGEL_TRACKER_ITEM_METADATA_SIZE]), _tmp3_);
	keys[RYGEL_TRACKER_ITEM_METADATA_DATE] = (_tmp4_ = g_strdup ("DC:Date"), _g_free0 (keys[RYGEL_TRACKER_ITEM_METADATA_DATE]), _tmp4_);
	keys[RYGEL_TRACKER_ITEM_METADATA_IMAGE_TITLE] = (_tmp5_ = g_strdup ("Image:Title"), _g_free0 (keys[RYGEL_TRACKER_ITEM_METADATA_IMAGE_TITLE]), _tmp5_);
	keys[RYGEL_TRACKER_ITEM_METADATA_CREATOR] = (_tmp6_ = g_strdup ("Image:Creator"), _g_free0 (keys[RYGEL_TRACKER_ITEM_METADATA_CREATOR]), _tmp6_);
	keys[RYGEL_TRACKER_ITEM_METADATA_IMAGE_WIDTH] = (_tmp7_ = g_strdup ("Image:Width"), _g_free0 (keys[RYGEL_TRACKER_ITEM_METADATA_IMAGE_WIDTH]), _tmp7_);
	keys[RYGEL_TRACKER_ITEM_METADATA_IMAGE_HEIGHT] = (_tmp8_ = g_strdup ("Image:Height"), _g_free0 (keys[RYGEL_TRACKER_ITEM_METADATA_IMAGE_HEIGHT]), _tmp8_);
	keys[RYGEL_TRACKER_ITEM_METADATA_IMAGE_ALBUM] = (_tmp9_ = g_strdup ("Image:Album"), _g_free0 (keys[RYGEL_TRACKER_ITEM_METADATA_IMAGE_ALBUM]), _tmp9_);
	keys[RYGEL_TRACKER_ITEM_METADATA_IMAGE_DATE] = (_tmp10_ = g_strdup ("Image:Date"), _g_free0 (keys[RYGEL_TRACKER_ITEM_METADATA_IMAGE_DATE]), _tmp10_);
	keys[RYGEL_TRACKER_ITEM_METADATA_AUDIO_TITLE] = (_tmp11_ = g_strdup ("Audio:Title"), _g_free0 (keys[RYGEL_TRACKER_ITEM_METADATA_AUDIO_TITLE]), _tmp11_);
	keys[RYGEL_TRACKER_ITEM_METADATA_AUDIO_DURATION] = (_tmp12_ = g_strdup ("Audio:Duration"), _g_free0 (keys[RYGEL_TRACKER_ITEM_METADATA_AUDIO_DURATION]), _tmp12_);
	keys[RYGEL_TRACKER_ITEM_METADATA_ARTIST] = (_tmp13_ = g_strdup ("Audio:Artist"), _g_free0 (keys[RYGEL_TRACKER_ITEM_METADATA_ARTIST]), _tmp13_);
	keys[RYGEL_TRACKER_ITEM_METADATA_AUDIO_ALBUM] = (_tmp14_ = g_strdup ("Audio:Album"), _g_free0 (keys[RYGEL_TRACKER_ITEM_METADATA_AUDIO_ALBUM]), _tmp14_);
	keys[RYGEL_TRACKER_ITEM_METADATA_TRACK_NUM] = (_tmp15_ = g_strdup ("Audio:TrackNo"), _g_free0 (keys[RYGEL_TRACKER_ITEM_METADATA_TRACK_NUM]), _tmp15_);
	keys[RYGEL_TRACKER_ITEM_METADATA_RELEASE] = (_tmp16_ = g_strdup ("Audio:ReleaseDate"), _g_free0 (keys[RYGEL_TRACKER_ITEM_METADATA_RELEASE]), _tmp16_);
	keys[RYGEL_TRACKER_ITEM_METADATA_DATE_ADDED] = (_tmp17_ = g_strdup ("Audio:DateAdded"), _g_free0 (keys[RYGEL_TRACKER_ITEM_METADATA_DATE_ADDED]), _tmp17_);
	keys[RYGEL_TRACKER_ITEM_METADATA_VIDEO_DURATION] = (_tmp18_ = g_strdup ("Video:Duration"), _g_free0 (keys[RYGEL_TRACKER_ITEM_METADATA_VIDEO_DURATION]), _tmp18_);
	keys[RYGEL_TRACKER_ITEM_METADATA_VIDEO_TITLE] = (_tmp19_ = g_strdup ("Video:Title"), _g_free0 (keys[RYGEL_TRACKER_ITEM_METADATA_VIDEO_TITLE]), _tmp19_);
	keys[RYGEL_TRACKER_ITEM_METADATA_AUTHOR] = (_tmp20_ = g_strdup ("Video:Author"), _g_free0 (keys[RYGEL_TRACKER_ITEM_METADATA_AUTHOR]), _tmp20_);
	keys[RYGEL_TRACKER_ITEM_METADATA_VIDEO_WIDTH] = (_tmp21_ = g_strdup ("Video:Width"), _g_free0 (keys[RYGEL_TRACKER_ITEM_METADATA_VIDEO_WIDTH]), _tmp21_);
	keys[RYGEL_TRACKER_ITEM_METADATA_VIDEO_HEIGHT] = (_tmp22_ = g_strdup ("Video:Height"), _g_free0 (keys[RYGEL_TRACKER_ITEM_METADATA_VIDEO_HEIGHT]), _tmp22_);
	result = (_tmp23_ = keys, *result_length1 = keys_length1, _tmp23_);
	return result;
	keys = (_vala_array_free (keys, keys_length1, (GDestroyNotify) g_free), NULL);
}


char* rygel_tracker_item_seconds_to_iso8601 (RygelTrackerItem* self, const char* seconds) {
	char* result;
	char* date;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (seconds != NULL, NULL);
	date = NULL;
	if (_vala_strcmp0 (seconds, "") != 0) {
		GTimeVal _tmp0_ = {0};
		GTimeVal tv;
		char* _tmp1_;
		tv = (g_get_current_time (&_tmp0_), _tmp0_);
		tv.tv_sec = (glong) atoi (seconds);
		tv.tv_usec = (glong) 0;
		date = (_tmp1_ = g_time_val_to_iso8601 (&tv), _g_free0 (date), _tmp1_);
	} else {
		char* _tmp2_;
		date = (_tmp2_ = g_strdup (""), _g_free0 (date), _tmp2_);
	}
	result = date;
	return result;
}


static void rygel_tracker_item_class_init (RygelTrackerItemClass * klass) {
	rygel_tracker_item_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = rygel_tracker_item_finalize;
}


static void rygel_tracker_item_instance_init (RygelTrackerItem * self) {
}


static void rygel_tracker_item_finalize (GObject* obj) {
	RygelTrackerItem * self;
	self = RYGEL_TRACKER_ITEM (obj);
	_g_free0 (self->path);
	G_OBJECT_CLASS (rygel_tracker_item_parent_class)->finalize (obj);
}


GType rygel_tracker_item_get_type (void) {
	static GType rygel_tracker_item_type_id = 0;
	if (rygel_tracker_item_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelTrackerItemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_tracker_item_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelTrackerItem), 0, (GInstanceInitFunc) rygel_tracker_item_instance_init, NULL };
		rygel_tracker_item_type_id = g_type_register_static (RYGEL_TYPE_MEDIA_ITEM, "RygelTrackerItem", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
	}
	return rygel_tracker_item_type_id;
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


static int _vala_strcmp0 (const char * str1, const char * str2) {
	if (str1 == NULL) {
		return -(str1 != str2);
	}
	if (str2 == NULL) {
		return str1 != str2;
	}
	return strcmp (str1, str2);
}




