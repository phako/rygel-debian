/* rygel-tracker-tags.c generated by valac, the Vala compiler
 * generated from rygel-tracker-tags.vala, do not modify */

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


#define RYGEL_TRACKER_TYPE_METADATA_VALUES (rygel_tracker_metadata_values_get_type ())
#define RYGEL_TRACKER_METADATA_VALUES(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TRACKER_TYPE_METADATA_VALUES, RygelTrackerMetadataValues))
#define RYGEL_TRACKER_METADATA_VALUES_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TRACKER_TYPE_METADATA_VALUES, RygelTrackerMetadataValuesClass))
#define RYGEL_TRACKER_IS_METADATA_VALUES(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TRACKER_TYPE_METADATA_VALUES))
#define RYGEL_TRACKER_IS_METADATA_VALUES_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TRACKER_TYPE_METADATA_VALUES))
#define RYGEL_TRACKER_METADATA_VALUES_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TRACKER_TYPE_METADATA_VALUES, RygelTrackerMetadataValuesClass))

typedef struct _RygelTrackerMetadataValues RygelTrackerMetadataValues;
typedef struct _RygelTrackerMetadataValuesClass RygelTrackerMetadataValuesClass;
typedef struct _RygelTrackerMetadataValuesPrivate RygelTrackerMetadataValuesPrivate;

#define RYGEL_TRACKER_TYPE_TAGS (rygel_tracker_tags_get_type ())
#define RYGEL_TRACKER_TAGS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TRACKER_TYPE_TAGS, RygelTrackerTags))
#define RYGEL_TRACKER_TAGS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TRACKER_TYPE_TAGS, RygelTrackerTagsClass))
#define RYGEL_TRACKER_IS_TAGS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TRACKER_TYPE_TAGS))
#define RYGEL_TRACKER_IS_TAGS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TRACKER_TYPE_TAGS))
#define RYGEL_TRACKER_TAGS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TRACKER_TYPE_TAGS, RygelTrackerTagsClass))

typedef struct _RygelTrackerTags RygelTrackerTags;
typedef struct _RygelTrackerTagsClass RygelTrackerTagsClass;
typedef struct _RygelTrackerTagsPrivate RygelTrackerTagsPrivate;

#define RYGEL_TRACKER_TYPE_ITEM_FACTORY (rygel_tracker_item_factory_get_type ())
#define RYGEL_TRACKER_ITEM_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TRACKER_TYPE_ITEM_FACTORY, RygelTrackerItemFactory))
#define RYGEL_TRACKER_ITEM_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TRACKER_TYPE_ITEM_FACTORY, RygelTrackerItemFactoryClass))
#define RYGEL_TRACKER_IS_ITEM_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TRACKER_TYPE_ITEM_FACTORY))
#define RYGEL_TRACKER_IS_ITEM_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TRACKER_TYPE_ITEM_FACTORY))
#define RYGEL_TRACKER_ITEM_FACTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TRACKER_TYPE_ITEM_FACTORY, RygelTrackerItemFactoryClass))

typedef struct _RygelTrackerItemFactory RygelTrackerItemFactory;
typedef struct _RygelTrackerItemFactoryClass RygelTrackerItemFactoryClass;
#define _g_free0(var) (var = (g_free (var), NULL))

typedef char* (*RygelTrackerMetadataValuesIDFunc) (const char* value, void* user_data);
typedef char* (*RygelTrackerMetadataValuesFilterFunc) (const char* variable, const char* value, void* user_data);
struct _RygelTrackerMetadataValues {
	RygelSimpleContainer parent_instance;
	RygelTrackerMetadataValuesPrivate * priv;
	char** key_chain;
	gint key_chain_length1;
	RygelTrackerMetadataValuesIDFunc id_func;
	gpointer id_func_target;
	GDestroyNotify id_func_target_destroy_notify;
	RygelTrackerMetadataValuesIDFunc title_func;
	gpointer title_func_target;
	GDestroyNotify title_func_target_destroy_notify;
	RygelTrackerMetadataValuesFilterFunc filter_func;
	gpointer filter_func_target;
	GDestroyNotify filter_func_target_destroy_notify;
};

struct _RygelTrackerMetadataValuesClass {
	RygelSimpleContainerClass parent_class;
};

struct _RygelTrackerTags {
	RygelTrackerMetadataValues parent_instance;
	RygelTrackerTagsPrivate * priv;
};

struct _RygelTrackerTagsClass {
	RygelTrackerMetadataValuesClass parent_class;
};


static gpointer rygel_tracker_tags_parent_class = NULL;

GType rygel_tracker_metadata_values_get_type (void) G_GNUC_CONST;
GType rygel_tracker_tags_get_type (void) G_GNUC_CONST;
enum  {
	RYGEL_TRACKER_TAGS_DUMMY_PROPERTY
};
#define RYGEL_TRACKER_TAGS_TITLE "Tags"
char* rygel_tracker_metadata_values_default_id_func (const char* value);
char* rygel_tracker_metadata_values_default_filter_func (const char* variable, const char* value);
gpointer rygel_tracker_item_factory_ref (gpointer instance);
void rygel_tracker_item_factory_unref (gpointer instance);
GParamSpec* rygel_tracker_param_spec_item_factory (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_tracker_value_set_item_factory (GValue* value, gpointer v_object);
void rygel_tracker_value_take_item_factory (GValue* value, gpointer v_object);
gpointer rygel_tracker_value_get_item_factory (const GValue* value);
GType rygel_tracker_item_factory_get_type (void) G_GNUC_CONST;
RygelTrackerMetadataValues* rygel_tracker_metadata_values_new (const char* id, RygelMediaContainer* parent, const char* title, RygelTrackerItemFactory* item_factory, char** key_chain, int key_chain_length1, RygelTrackerMetadataValuesIDFunc id_func, void* id_func_target, RygelTrackerMetadataValuesIDFunc title_func, void* title_func_target, RygelTrackerMetadataValuesFilterFunc filter_func, void* filter_func_target);
RygelTrackerMetadataValues* rygel_tracker_metadata_values_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title, RygelTrackerItemFactory* item_factory, char** key_chain, int key_chain_length1, RygelTrackerMetadataValuesIDFunc id_func, void* id_func_target, RygelTrackerMetadataValuesIDFunc title_func, void* title_func_target, RygelTrackerMetadataValuesFilterFunc filter_func, void* filter_func_target);
RygelTrackerTags* rygel_tracker_tags_new (RygelMediaContainer* parent, RygelTrackerItemFactory* item_factory);
RygelTrackerTags* rygel_tracker_tags_construct (GType object_type, RygelMediaContainer* parent, RygelTrackerItemFactory* item_factory);

static const char* RYGEL_TRACKER_TAGS_KEY_CHAIN[3] = {"nao:hasTag", "nao:prefLabel", NULL};


#line 36 "rygel-tracker-tags.vala"
RygelTrackerTags* rygel_tracker_tags_construct (GType object_type, RygelMediaContainer* parent, RygelTrackerItemFactory* item_factory) {
#line 127 "rygel-tracker-tags.c"
	RygelTrackerTags * self;
	char* _tmp0_;
#line 36 "rygel-tracker-tags.vala"
	g_return_val_if_fail (parent != NULL, NULL);
#line 36 "rygel-tracker-tags.vala"
	g_return_val_if_fail (item_factory != NULL, NULL);
#line 37 "rygel-tracker-tags.vala"
	self = (RygelTrackerTags*) rygel_tracker_metadata_values_construct (object_type, _tmp0_ = g_strconcat (((RygelMediaObject*) parent)->id, RYGEL_TRACKER_TAGS_TITLE, NULL), parent, RYGEL_TRACKER_TAGS_TITLE, item_factory, RYGEL_TRACKER_TAGS_KEY_CHAIN, G_N_ELEMENTS (RYGEL_TRACKER_TAGS_KEY_CHAIN), rygel_tracker_metadata_values_default_id_func, NULL, rygel_tracker_metadata_values_default_id_func, NULL, rygel_tracker_metadata_values_default_filter_func, NULL);
#line 136 "rygel-tracker-tags.c"
	_g_free0 (_tmp0_);
	return self;
}


#line 36 "rygel-tracker-tags.vala"
RygelTrackerTags* rygel_tracker_tags_new (RygelMediaContainer* parent, RygelTrackerItemFactory* item_factory) {
#line 36 "rygel-tracker-tags.vala"
	return rygel_tracker_tags_construct (RYGEL_TRACKER_TYPE_TAGS, parent, item_factory);
#line 146 "rygel-tracker-tags.c"
}


static void rygel_tracker_tags_class_init (RygelTrackerTagsClass * klass) {
	rygel_tracker_tags_parent_class = g_type_class_peek_parent (klass);
}


static void rygel_tracker_tags_instance_init (RygelTrackerTags * self) {
}


GType rygel_tracker_tags_get_type (void) {
	static volatile gsize rygel_tracker_tags_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_tracker_tags_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelTrackerTagsClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_tracker_tags_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelTrackerTags), 0, (GInstanceInitFunc) rygel_tracker_tags_instance_init, NULL };
		GType rygel_tracker_tags_type_id;
		rygel_tracker_tags_type_id = g_type_register_static (RYGEL_TRACKER_TYPE_METADATA_VALUES, "RygelTrackerTags", &g_define_type_info, 0);
		g_once_init_leave (&rygel_tracker_tags_type_id__volatile, rygel_tracker_tags_type_id);
	}
	return rygel_tracker_tags_type_id__volatile;
}




