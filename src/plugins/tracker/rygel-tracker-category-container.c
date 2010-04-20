/* rygel-tracker-category-container.c generated by valac, the Vala compiler
 * generated from rygel-tracker-category-container.vala, do not modify */

/*
 * Copyright (C) 2010 Nokia Corporation.
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


#define RYGEL_TYPE_TRACKER_CATEGORY_CONTAINER (rygel_tracker_category_container_get_type ())
#define RYGEL_TRACKER_CATEGORY_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_CATEGORY_CONTAINER, RygelTrackerCategoryContainer))
#define RYGEL_TRACKER_CATEGORY_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_CATEGORY_CONTAINER, RygelTrackerCategoryContainerClass))
#define RYGEL_IS_TRACKER_CATEGORY_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_CATEGORY_CONTAINER))
#define RYGEL_IS_TRACKER_CATEGORY_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_CATEGORY_CONTAINER))
#define RYGEL_TRACKER_CATEGORY_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_CATEGORY_CONTAINER, RygelTrackerCategoryContainerClass))

typedef struct _RygelTrackerCategoryContainer RygelTrackerCategoryContainer;
typedef struct _RygelTrackerCategoryContainerClass RygelTrackerCategoryContainerClass;
typedef struct _RygelTrackerCategoryContainerPrivate RygelTrackerCategoryContainerPrivate;

#define RYGEL_TYPE_TRACKER_ITEM_FACTORY (rygel_tracker_item_factory_get_type ())
#define RYGEL_TRACKER_ITEM_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_ITEM_FACTORY, RygelTrackerItemFactory))
#define RYGEL_TRACKER_ITEM_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_ITEM_FACTORY, RygelTrackerItemFactoryClass))
#define RYGEL_IS_TRACKER_ITEM_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_ITEM_FACTORY))
#define RYGEL_IS_TRACKER_ITEM_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_ITEM_FACTORY))
#define RYGEL_TRACKER_ITEM_FACTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_ITEM_FACTORY, RygelTrackerItemFactoryClass))

typedef struct _RygelTrackerItemFactory RygelTrackerItemFactory;
typedef struct _RygelTrackerItemFactoryClass RygelTrackerItemFactoryClass;
#define _rygel_tracker_item_factory_unref0(var) ((var == NULL) ? NULL : (var = (rygel_tracker_item_factory_unref (var), NULL)))

#define RYGEL_TYPE_TRACKER_SEARCH_CONTAINER (rygel_tracker_search_container_get_type ())
#define RYGEL_TRACKER_SEARCH_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainer))
#define RYGEL_TRACKER_SEARCH_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainerClass))
#define RYGEL_IS_TRACKER_SEARCH_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER))
#define RYGEL_IS_TRACKER_SEARCH_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER))
#define RYGEL_TRACKER_SEARCH_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainerClass))

typedef struct _RygelTrackerSearchContainer RygelTrackerSearchContainer;
typedef struct _RygelTrackerSearchContainerClass RygelTrackerSearchContainerClass;

#define RYGEL_TYPE_TRACKER_CATEGORY_ALL_CONTAINER (rygel_tracker_category_all_container_get_type ())
#define RYGEL_TRACKER_CATEGORY_ALL_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_CATEGORY_ALL_CONTAINER, RygelTrackerCategoryAllContainer))
#define RYGEL_TRACKER_CATEGORY_ALL_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_CATEGORY_ALL_CONTAINER, RygelTrackerCategoryAllContainerClass))
#define RYGEL_IS_TRACKER_CATEGORY_ALL_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_CATEGORY_ALL_CONTAINER))
#define RYGEL_IS_TRACKER_CATEGORY_ALL_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_CATEGORY_ALL_CONTAINER))
#define RYGEL_TRACKER_CATEGORY_ALL_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_CATEGORY_ALL_CONTAINER, RygelTrackerCategoryAllContainerClass))

typedef struct _RygelTrackerCategoryAllContainer RygelTrackerCategoryAllContainer;
typedef struct _RygelTrackerCategoryAllContainerClass RygelTrackerCategoryAllContainerClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _RygelTrackerCategoryContainer {
	RygelSimpleContainer parent_instance;
	RygelTrackerCategoryContainerPrivate * priv;
	RygelTrackerItemFactory* item_factory;
};

struct _RygelTrackerCategoryContainerClass {
	RygelSimpleContainerClass parent_class;
};


static gpointer rygel_tracker_category_container_parent_class = NULL;

GType rygel_tracker_category_container_get_type (void);
gpointer rygel_tracker_item_factory_ref (gpointer instance);
void rygel_tracker_item_factory_unref (gpointer instance);
GParamSpec* rygel_param_spec_tracker_item_factory (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_tracker_item_factory (GValue* value, gpointer v_object);
void rygel_value_take_tracker_item_factory (GValue* value, gpointer v_object);
gpointer rygel_value_get_tracker_item_factory (const GValue* value);
GType rygel_tracker_item_factory_get_type (void);
enum  {
	RYGEL_TRACKER_CATEGORY_CONTAINER_DUMMY_PROPERTY
};
RygelTrackerCategoryAllContainer* rygel_tracker_category_all_container_new (RygelTrackerCategoryContainer* parent);
RygelTrackerCategoryAllContainer* rygel_tracker_category_all_container_construct (GType object_type, RygelTrackerCategoryContainer* parent);
GType rygel_tracker_search_container_get_type (void);
GType rygel_tracker_category_all_container_get_type (void);
RygelTrackerCategoryContainer* rygel_tracker_category_container_new (const char* id, RygelMediaContainer* parent, const char* title, RygelTrackerItemFactory* item_factory);
RygelTrackerCategoryContainer* rygel_tracker_category_container_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title, RygelTrackerItemFactory* item_factory);
static void rygel_tracker_category_container_finalize (GObject* obj);



static gpointer _rygel_tracker_item_factory_ref0 (gpointer self) {
	return self ? rygel_tracker_item_factory_ref (self) : NULL;
}


#line 32 "rygel-tracker-category-container.vala"
RygelTrackerCategoryContainer* rygel_tracker_category_container_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title, RygelTrackerItemFactory* item_factory) {
#line 119 "rygel-tracker-category-container.c"
	RygelTrackerCategoryContainer * self;
	RygelTrackerItemFactory* _tmp0_;
	RygelTrackerCategoryAllContainer* _tmp1_;
#line 32 "rygel-tracker-category-container.vala"
	g_return_val_if_fail (id != NULL, NULL);
#line 32 "rygel-tracker-category-container.vala"
	g_return_val_if_fail (parent != NULL, NULL);
#line 32 "rygel-tracker-category-container.vala"
	g_return_val_if_fail (title != NULL, NULL);
#line 32 "rygel-tracker-category-container.vala"
	g_return_val_if_fail (item_factory != NULL, NULL);
#line 36 "rygel-tracker-category-container.vala"
	self = (RygelTrackerCategoryContainer*) rygel_simple_container_construct (object_type, id, parent, title);
#line 38 "rygel-tracker-category-container.vala"
	self->item_factory = (_tmp0_ = _rygel_tracker_item_factory_ref0 (item_factory), _rygel_tracker_item_factory_unref0 (self->item_factory), _tmp0_);
#line 40 "rygel-tracker-category-container.vala"
	rygel_simple_container_add_child ((RygelSimpleContainer*) self, (RygelMediaObject*) (_tmp1_ = rygel_tracker_category_all_container_new (self)));
#line 137 "rygel-tracker-category-container.c"
	_g_object_unref0 (_tmp1_);
	return self;
}


#line 32 "rygel-tracker-category-container.vala"
RygelTrackerCategoryContainer* rygel_tracker_category_container_new (const char* id, RygelMediaContainer* parent, const char* title, RygelTrackerItemFactory* item_factory) {
#line 32 "rygel-tracker-category-container.vala"
	return rygel_tracker_category_container_construct (RYGEL_TYPE_TRACKER_CATEGORY_CONTAINER, id, parent, title, item_factory);
#line 147 "rygel-tracker-category-container.c"
}


static void rygel_tracker_category_container_class_init (RygelTrackerCategoryContainerClass * klass) {
	rygel_tracker_category_container_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = rygel_tracker_category_container_finalize;
}


static void rygel_tracker_category_container_instance_init (RygelTrackerCategoryContainer * self) {
}


static void rygel_tracker_category_container_finalize (GObject* obj) {
	RygelTrackerCategoryContainer * self;
	self = RYGEL_TRACKER_CATEGORY_CONTAINER (obj);
	_rygel_tracker_item_factory_unref0 (self->item_factory);
	G_OBJECT_CLASS (rygel_tracker_category_container_parent_class)->finalize (obj);
}


GType rygel_tracker_category_container_get_type (void) {
	static volatile gsize rygel_tracker_category_container_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_tracker_category_container_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelTrackerCategoryContainerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_tracker_category_container_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelTrackerCategoryContainer), 0, (GInstanceInitFunc) rygel_tracker_category_container_instance_init, NULL };
		GType rygel_tracker_category_container_type_id;
		rygel_tracker_category_container_type_id = g_type_register_static (RYGEL_TYPE_SIMPLE_CONTAINER, "RygelTrackerCategoryContainer", &g_define_type_info, 0);
		g_once_init_leave (&rygel_tracker_category_container_type_id__volatile, rygel_tracker_category_container_type_id);
	}
	return rygel_tracker_category_container_type_id__volatile;
}



