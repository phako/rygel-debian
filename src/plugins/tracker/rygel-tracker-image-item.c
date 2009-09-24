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

#define RYGEL_TYPE_TRACKER_IMAGE_ITEM (rygel_tracker_image_item_get_type ())
#define RYGEL_TRACKER_IMAGE_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_IMAGE_ITEM, RygelTrackerImageItem))
#define RYGEL_TRACKER_IMAGE_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_IMAGE_ITEM, RygelTrackerImageItemClass))
#define RYGEL_IS_TRACKER_IMAGE_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_IMAGE_ITEM))
#define RYGEL_IS_TRACKER_IMAGE_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_IMAGE_ITEM))
#define RYGEL_TRACKER_IMAGE_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_IMAGE_ITEM, RygelTrackerImageItemClass))

typedef struct _RygelTrackerImageItem RygelTrackerImageItem;
typedef struct _RygelTrackerImageItemClass RygelTrackerImageItemClass;
typedef struct _RygelTrackerImageItemPrivate RygelTrackerImageItemPrivate;

#define RYGEL_TYPE_TRACKER_SEARCH_CONTAINER (rygel_tracker_search_container_get_type ())
#define RYGEL_TRACKER_SEARCH_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainer))
#define RYGEL_TRACKER_SEARCH_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainerClass))
#define RYGEL_IS_TRACKER_SEARCH_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER))
#define RYGEL_IS_TRACKER_SEARCH_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER))
#define RYGEL_TRACKER_SEARCH_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainerClass))

typedef struct _RygelTrackerSearchContainer RygelTrackerSearchContainer;
typedef struct _RygelTrackerSearchContainerClass RygelTrackerSearchContainerClass;

#define RYGEL_TRACKER_ITEM_TYPE_METADATA (rygel_tracker_item_metadata_get_type ())
#define _g_free0(var) (var = (g_free (var), NULL))

struct _RygelTrackerItem {
	RygelMediaItem parent_instance;
	RygelTrackerItemPrivate * priv;
	char* path;
};

struct _RygelTrackerItemClass {
	RygelMediaItemClass parent_class;
};

struct _RygelTrackerImageItem {
	RygelTrackerItem parent_instance;
	RygelTrackerImageItemPrivate * priv;
};

struct _RygelTrackerImageItemClass {
	RygelTrackerItemClass parent_class;
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


static gpointer rygel_tracker_image_item_parent_class = NULL;

GType rygel_tracker_item_get_type (void);
GType rygel_tracker_image_item_get_type (void);
enum  {
	RYGEL_TRACKER_IMAGE_ITEM_DUMMY_PROPERTY
};
#define RYGEL_TRACKER_IMAGE_ITEM_SERVICE "Images"
GType rygel_tracker_search_container_get_type (void);
RygelTrackerItem* rygel_tracker_item_construct (GType object_type, const char* id, const char* path, RygelTrackerSearchContainer* parent, const char* upnp_class, char** metadata, int metadata_length1);
GType rygel_tracker_item_metadata_get_type (void);
char* rygel_tracker_item_seconds_to_iso8601 (RygelTrackerItem* self, const char* seconds);
RygelTrackerImageItem* rygel_tracker_image_item_new (const char* id, const char* path, RygelTrackerSearchContainer* parent, char** metadata, int metadata_length1);
RygelTrackerImageItem* rygel_tracker_image_item_construct (GType object_type, const char* id, const char* path, RygelTrackerSearchContainer* parent, char** metadata, int metadata_length1);
static int _vala_strcmp0 (const char * str1, const char * str2);



RygelTrackerImageItem* rygel_tracker_image_item_construct (GType object_type, const char* id, const char* path, RygelTrackerSearchContainer* parent, char** metadata, int metadata_length1) {
	RygelTrackerImageItem * self;
	char* _tmp3_;
	char* _tmp4_;
	g_return_val_if_fail (id != NULL, NULL);
	g_return_val_if_fail (path != NULL, NULL);
	g_return_val_if_fail (parent != NULL, NULL);
	self = (RygelTrackerImageItem*) rygel_tracker_item_construct (object_type, id, path, parent, RYGEL_MEDIA_ITEM_IMAGE_CLASS, metadata, metadata_length1);
	if (_vala_strcmp0 (metadata[RYGEL_TRACKER_ITEM_METADATA_IMAGE_TITLE], "") != 0) {
		char* _tmp0_;
		((RygelMediaObject*) self)->title = (_tmp0_ = g_strdup (metadata[RYGEL_TRACKER_ITEM_METADATA_IMAGE_TITLE]), _g_free0 (((RygelMediaObject*) self)->title), _tmp0_);
	} else {
		char* _tmp1_;
		((RygelMediaObject*) self)->title = (_tmp1_ = g_strdup (metadata[RYGEL_TRACKER_ITEM_METADATA_FILE_NAME]), _g_free0 (((RygelMediaObject*) self)->title), _tmp1_);
	}
	if (_vala_strcmp0 (metadata[RYGEL_TRACKER_ITEM_METADATA_IMAGE_WIDTH], "") != 0) {
		((RygelMediaItem*) self)->width = atoi (metadata[RYGEL_TRACKER_ITEM_METADATA_IMAGE_WIDTH]);
	}
	if (_vala_strcmp0 (metadata[RYGEL_TRACKER_ITEM_METADATA_IMAGE_HEIGHT], "") != 0) {
		((RygelMediaItem*) self)->height = atoi (metadata[RYGEL_TRACKER_ITEM_METADATA_IMAGE_HEIGHT]);
	}
	if (_vala_strcmp0 (metadata[RYGEL_TRACKER_ITEM_METADATA_IMAGE_DATE], "") != 0) {
		char* _tmp2_;
		((RygelMediaItem*) self)->date = (_tmp2_ = rygel_tracker_item_seconds_to_iso8601 ((RygelTrackerItem*) self, metadata[RYGEL_TRACKER_ITEM_METADATA_IMAGE_DATE]), _g_free0 (((RygelMediaItem*) self)->date), _tmp2_);
	}
	((RygelMediaItem*) self)->author = (_tmp3_ = g_strdup (metadata[RYGEL_TRACKER_ITEM_METADATA_CREATOR]), _g_free0 (((RygelMediaItem*) self)->author), _tmp3_);
	((RygelMediaItem*) self)->album = (_tmp4_ = g_strdup (metadata[RYGEL_TRACKER_ITEM_METADATA_IMAGE_ALBUM]), _g_free0 (((RygelMediaItem*) self)->album), _tmp4_);
	return self;
}


RygelTrackerImageItem* rygel_tracker_image_item_new (const char* id, const char* path, RygelTrackerSearchContainer* parent, char** metadata, int metadata_length1) {
	return rygel_tracker_image_item_construct (RYGEL_TYPE_TRACKER_IMAGE_ITEM, id, path, parent, metadata, metadata_length1);
}


static void rygel_tracker_image_item_class_init (RygelTrackerImageItemClass * klass) {
	rygel_tracker_image_item_parent_class = g_type_class_peek_parent (klass);
}


static void rygel_tracker_image_item_instance_init (RygelTrackerImageItem * self) {
}


GType rygel_tracker_image_item_get_type (void) {
	static GType rygel_tracker_image_item_type_id = 0;
	if (rygel_tracker_image_item_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelTrackerImageItemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_tracker_image_item_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelTrackerImageItem), 0, (GInstanceInitFunc) rygel_tracker_image_item_instance_init, NULL };
		rygel_tracker_image_item_type_id = g_type_register_static (RYGEL_TYPE_TRACKER_ITEM, "RygelTrackerImageItem", &g_define_type_info, 0);
	}
	return rygel_tracker_image_item_type_id;
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




