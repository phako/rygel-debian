/*
 * Copyright (C) 2008 Zeeshan Ali (Khattak) <zeeshanak@gnome.org>.
 * Copyright (C) 2008 Nokia Corporation.
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
#include <rygel.h>
#include <stdlib.h>
#include <string.h>


#define RYGEL_TYPE_TRACKER_ROOT_CONTAINER (rygel_tracker_root_container_get_type ())
#define RYGEL_TRACKER_ROOT_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_ROOT_CONTAINER, RygelTrackerRootContainer))
#define RYGEL_TRACKER_ROOT_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_ROOT_CONTAINER, RygelTrackerRootContainerClass))
#define RYGEL_IS_TRACKER_ROOT_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_ROOT_CONTAINER))
#define RYGEL_IS_TRACKER_ROOT_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_ROOT_CONTAINER))
#define RYGEL_TRACKER_ROOT_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_ROOT_CONTAINER, RygelTrackerRootContainerClass))

typedef struct _RygelTrackerRootContainer RygelTrackerRootContainer;
typedef struct _RygelTrackerRootContainerClass RygelTrackerRootContainerClass;
typedef struct _RygelTrackerRootContainerPrivate RygelTrackerRootContainerPrivate;

#define RYGEL_TYPE_TRACKER_SEARCH_CONTAINER (rygel_tracker_search_container_get_type ())
#define RYGEL_TRACKER_SEARCH_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainer))
#define RYGEL_TRACKER_SEARCH_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainerClass))
#define RYGEL_IS_TRACKER_SEARCH_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER))
#define RYGEL_IS_TRACKER_SEARCH_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER))
#define RYGEL_TRACKER_SEARCH_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainerClass))

typedef struct _RygelTrackerSearchContainer RygelTrackerSearchContainer;
typedef struct _RygelTrackerSearchContainerClass RygelTrackerSearchContainerClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define RYGEL_TYPE_TRACKER_METADATA_VALUES (rygel_tracker_metadata_values_get_type ())
#define RYGEL_TRACKER_METADATA_VALUES(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_METADATA_VALUES, RygelTrackerMetadataValues))
#define RYGEL_TRACKER_METADATA_VALUES_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_METADATA_VALUES, RygelTrackerMetadataValuesClass))
#define RYGEL_IS_TRACKER_METADATA_VALUES(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_METADATA_VALUES))
#define RYGEL_IS_TRACKER_METADATA_VALUES_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_METADATA_VALUES))
#define RYGEL_TRACKER_METADATA_VALUES_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_METADATA_VALUES, RygelTrackerMetadataValuesClass))

typedef struct _RygelTrackerMetadataValues RygelTrackerMetadataValues;
typedef struct _RygelTrackerMetadataValuesClass RygelTrackerMetadataValuesClass;

#define RYGEL_TYPE_TRACKER_KEYWORDS (rygel_tracker_keywords_get_type ())
#define RYGEL_TRACKER_KEYWORDS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_KEYWORDS, RygelTrackerKeywords))
#define RYGEL_TRACKER_KEYWORDS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_KEYWORDS, RygelTrackerKeywordsClass))
#define RYGEL_IS_TRACKER_KEYWORDS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_KEYWORDS))
#define RYGEL_IS_TRACKER_KEYWORDS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_KEYWORDS))
#define RYGEL_TRACKER_KEYWORDS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_KEYWORDS, RygelTrackerKeywordsClass))

typedef struct _RygelTrackerKeywords RygelTrackerKeywords;
typedef struct _RygelTrackerKeywordsClass RygelTrackerKeywordsClass;

struct _RygelTrackerRootContainer {
	RygelSimpleContainer parent_instance;
	RygelTrackerRootContainerPrivate * priv;
};

struct _RygelTrackerRootContainerClass {
	RygelSimpleContainerClass parent_class;
};


static gpointer rygel_tracker_root_container_parent_class = NULL;

GType rygel_tracker_root_container_get_type (void);
enum  {
	RYGEL_TRACKER_ROOT_CONTAINER_DUMMY_PROPERTY
};
#define RYGEL_TRACKER_IMAGE_ITEM_SERVICE "Images"
RygelTrackerSearchContainer* rygel_tracker_search_container_new (const char* id, RygelMediaContainer* parent, const char* title, const char* service, const char* query_condition, char** keywords, int keywords_length1);
RygelTrackerSearchContainer* rygel_tracker_search_container_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title, const char* service, const char* query_condition, char** keywords, int keywords_length1);
GType rygel_tracker_search_container_get_type (void);
#define RYGEL_TRACKER_MUSIC_ITEM_SERVICE "Music"
#define RYGEL_TRACKER_VIDEO_ITEM_SERVICE "Videos"
RygelTrackerMetadataValues* rygel_tracker_metadata_values_new (const char* key, const char* id, RygelMediaContainer* parent, const char* title);
RygelTrackerMetadataValues* rygel_tracker_metadata_values_construct (GType object_type, const char* key, const char* id, RygelMediaContainer* parent, const char* title);
GType rygel_tracker_metadata_values_get_type (void);
RygelTrackerKeywords* rygel_tracker_keywords_new (const char* id, RygelMediaContainer* parent);
RygelTrackerKeywords* rygel_tracker_keywords_construct (GType object_type, const char* id, RygelMediaContainer* parent);
GType rygel_tracker_keywords_get_type (void);
RygelTrackerRootContainer* rygel_tracker_root_container_new (const char* title);
RygelTrackerRootContainer* rygel_tracker_root_container_construct (GType object_type, const char* title);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);



RygelTrackerRootContainer* rygel_tracker_root_container_construct (GType object_type, const char* title) {
	RygelTrackerRootContainer * self;
	RygelTrackerSearchContainer* _tmp1_;
	gint _tmp0__length1;
	char** _tmp0_;
	RygelTrackerSearchContainer* _tmp3_;
	gint _tmp2__length1;
	char** _tmp2_;
	RygelTrackerSearchContainer* _tmp5_;
	gint _tmp4__length1;
	char** _tmp4_;
	RygelTrackerMetadataValues* _tmp6_;
	RygelTrackerMetadataValues* _tmp7_;
	RygelTrackerKeywords* _tmp8_;
	g_return_val_if_fail (title != NULL, NULL);
	self = (RygelTrackerRootContainer*) rygel_simple_container_construct_root (object_type, title);
	rygel_simple_container_add_child ((RygelSimpleContainer*) self, (RygelMediaObject*) (_tmp1_ = rygel_tracker_search_container_new ("16", (RygelMediaContainer*) self, "Pictures", RYGEL_TRACKER_IMAGE_ITEM_SERVICE, "", (_tmp0_ = g_new0 (char*, 0 + 1), _tmp0__length1 = 0, _tmp0_), 0)));
	_g_object_unref0 (_tmp1_);
	_tmp0_ = (_vala_array_free (_tmp0_, _tmp0__length1, (GDestroyNotify) g_free), NULL);
	rygel_simple_container_add_child ((RygelSimpleContainer*) self, (RygelMediaObject*) (_tmp3_ = rygel_tracker_search_container_new ("14", (RygelMediaContainer*) self, "Music", RYGEL_TRACKER_MUSIC_ITEM_SERVICE, "", (_tmp2_ = g_new0 (char*, 0 + 1), _tmp2__length1 = 0, _tmp2_), 0)));
	_g_object_unref0 (_tmp3_);
	_tmp2_ = (_vala_array_free (_tmp2_, _tmp2__length1, (GDestroyNotify) g_free), NULL);
	rygel_simple_container_add_child ((RygelSimpleContainer*) self, (RygelMediaObject*) (_tmp5_ = rygel_tracker_search_container_new ("15", (RygelMediaContainer*) self, "Videos", RYGEL_TRACKER_VIDEO_ITEM_SERVICE, "", (_tmp4_ = g_new0 (char*, 0 + 1), _tmp4__length1 = 0, _tmp4_), 0)));
	_g_object_unref0 (_tmp5_);
	_tmp4_ = (_vala_array_free (_tmp4_, _tmp4__length1, (GDestroyNotify) g_free), NULL);
	rygel_simple_container_add_child ((RygelSimpleContainer*) self, (RygelMediaObject*) (_tmp6_ = rygel_tracker_metadata_values_new ("Audio:Artist", "17", (RygelMediaContainer*) self, "Artists")));
	_g_object_unref0 (_tmp6_);
	rygel_simple_container_add_child ((RygelSimpleContainer*) self, (RygelMediaObject*) (_tmp7_ = rygel_tracker_metadata_values_new ("Audio:Album", "18", (RygelMediaContainer*) self, "Albums")));
	_g_object_unref0 (_tmp7_);
	rygel_simple_container_add_child ((RygelSimpleContainer*) self, (RygelMediaObject*) (_tmp8_ = rygel_tracker_keywords_new ("19", (RygelMediaContainer*) self)));
	_g_object_unref0 (_tmp8_);
	return self;
}


RygelTrackerRootContainer* rygel_tracker_root_container_new (const char* title) {
	return rygel_tracker_root_container_construct (RYGEL_TYPE_TRACKER_ROOT_CONTAINER, title);
}


static void rygel_tracker_root_container_class_init (RygelTrackerRootContainerClass * klass) {
	rygel_tracker_root_container_parent_class = g_type_class_peek_parent (klass);
}


static void rygel_tracker_root_container_instance_init (RygelTrackerRootContainer * self) {
}


GType rygel_tracker_root_container_get_type (void) {
	static GType rygel_tracker_root_container_type_id = 0;
	if (rygel_tracker_root_container_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelTrackerRootContainerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_tracker_root_container_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelTrackerRootContainer), 0, (GInstanceInitFunc) rygel_tracker_root_container_instance_init, NULL };
		rygel_tracker_root_container_type_id = g_type_register_static (RYGEL_TYPE_SIMPLE_CONTAINER, "RygelTrackerRootContainer", &g_define_type_info, 0);
	}
	return rygel_tracker_root_container_type_id;
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




