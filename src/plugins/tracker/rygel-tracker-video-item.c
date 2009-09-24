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

#define RYGEL_TYPE_TRACKER_VIDEO_ITEM (rygel_tracker_video_item_get_type ())
#define RYGEL_TRACKER_VIDEO_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_VIDEO_ITEM, RygelTrackerVideoItem))
#define RYGEL_TRACKER_VIDEO_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_VIDEO_ITEM, RygelTrackerVideoItemClass))
#define RYGEL_IS_TRACKER_VIDEO_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_VIDEO_ITEM))
#define RYGEL_IS_TRACKER_VIDEO_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_VIDEO_ITEM))
#define RYGEL_TRACKER_VIDEO_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_VIDEO_ITEM, RygelTrackerVideoItemClass))

typedef struct _RygelTrackerVideoItem RygelTrackerVideoItem;
typedef struct _RygelTrackerVideoItemClass RygelTrackerVideoItemClass;
typedef struct _RygelTrackerVideoItemPrivate RygelTrackerVideoItemPrivate;

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

struct _RygelTrackerVideoItem {
	RygelTrackerItem parent_instance;
	RygelTrackerVideoItemPrivate * priv;
};

struct _RygelTrackerVideoItemClass {
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


static gpointer rygel_tracker_video_item_parent_class = NULL;

GType rygel_tracker_item_get_type (void);
GType rygel_tracker_video_item_get_type (void);
enum  {
	RYGEL_TRACKER_VIDEO_ITEM_DUMMY_PROPERTY
};
#define RYGEL_TRACKER_VIDEO_ITEM_SERVICE "Videos"
GType rygel_tracker_search_container_get_type (void);
RygelTrackerItem* rygel_tracker_item_construct (GType object_type, const char* id, const char* path, RygelTrackerSearchContainer* parent, const char* upnp_class, char** metadata, int metadata_length1);
GType rygel_tracker_item_metadata_get_type (void);
RygelTrackerVideoItem* rygel_tracker_video_item_new (const char* id, const char* path, RygelTrackerSearchContainer* parent, char** metadata, int metadata_length1);
RygelTrackerVideoItem* rygel_tracker_video_item_construct (GType object_type, const char* id, const char* path, RygelTrackerSearchContainer* parent, char** metadata, int metadata_length1);
static int _vala_strcmp0 (const char * str1, const char * str2);



RygelTrackerVideoItem* rygel_tracker_video_item_construct (GType object_type, const char* id, const char* path, RygelTrackerSearchContainer* parent, char** metadata, int metadata_length1) {
	RygelTrackerVideoItem * self;
	char* _tmp2_;
	g_return_val_if_fail (id != NULL, NULL);
	g_return_val_if_fail (path != NULL, NULL);
	g_return_val_if_fail (parent != NULL, NULL);
	self = (RygelTrackerVideoItem*) rygel_tracker_item_construct (object_type, id, path, parent, RYGEL_MEDIA_ITEM_VIDEO_CLASS, metadata, metadata_length1);
	if (_vala_strcmp0 (metadata[RYGEL_TRACKER_ITEM_METADATA_VIDEO_TITLE], "") != 0) {
		char* _tmp0_;
		((RygelMediaObject*) self)->title = (_tmp0_ = g_strdup (metadata[RYGEL_TRACKER_ITEM_METADATA_VIDEO_TITLE]), _g_free0 (((RygelMediaObject*) self)->title), _tmp0_);
	} else {
		char* _tmp1_;
		((RygelMediaObject*) self)->title = (_tmp1_ = g_strdup (metadata[RYGEL_TRACKER_ITEM_METADATA_FILE_NAME]), _g_free0 (((RygelMediaObject*) self)->title), _tmp1_);
	}
	if (_vala_strcmp0 (metadata[RYGEL_TRACKER_ITEM_METADATA_VIDEO_WIDTH], "") != 0) {
		((RygelMediaItem*) self)->width = atoi (metadata[RYGEL_TRACKER_ITEM_METADATA_VIDEO_WIDTH]);
	}
	if (_vala_strcmp0 (metadata[RYGEL_TRACKER_ITEM_METADATA_VIDEO_HEIGHT], "") != 0) {
		((RygelMediaItem*) self)->height = atoi (metadata[RYGEL_TRACKER_ITEM_METADATA_VIDEO_HEIGHT]);
	}
	if (_vala_strcmp0 (metadata[RYGEL_TRACKER_ITEM_METADATA_VIDEO_DURATION], "") != 0) {
		((RygelMediaItem*) self)->duration = (glong) atoi (metadata[RYGEL_TRACKER_ITEM_METADATA_VIDEO_DURATION]);
	}
	if (_vala_strcmp0 (metadata[RYGEL_TRACKER_ITEM_METADATA_VIDEO_DURATION], "") != 0) {
		((RygelMediaItem*) self)->duration = (glong) atoi (metadata[RYGEL_TRACKER_ITEM_METADATA_VIDEO_DURATION]);
	}
	((RygelMediaItem*) self)->author = (_tmp2_ = g_strdup (metadata[RYGEL_TRACKER_ITEM_METADATA_AUTHOR]), _g_free0 (((RygelMediaItem*) self)->author), _tmp2_);
	return self;
}


RygelTrackerVideoItem* rygel_tracker_video_item_new (const char* id, const char* path, RygelTrackerSearchContainer* parent, char** metadata, int metadata_length1) {
	return rygel_tracker_video_item_construct (RYGEL_TYPE_TRACKER_VIDEO_ITEM, id, path, parent, metadata, metadata_length1);
}


static void rygel_tracker_video_item_class_init (RygelTrackerVideoItemClass * klass) {
	rygel_tracker_video_item_parent_class = g_type_class_peek_parent (klass);
}


static void rygel_tracker_video_item_instance_init (RygelTrackerVideoItem * self) {
}


GType rygel_tracker_video_item_get_type (void) {
	static GType rygel_tracker_video_item_type_id = 0;
	if (rygel_tracker_video_item_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelTrackerVideoItemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_tracker_video_item_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelTrackerVideoItem), 0, (GInstanceInitFunc) rygel_tracker_video_item_instance_init, NULL };
		rygel_tracker_video_item_type_id = g_type_register_static (RYGEL_TYPE_TRACKER_ITEM, "RygelTrackerVideoItem", &g_define_type_info, 0);
	}
	return rygel_tracker_video_item_type_id;
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




