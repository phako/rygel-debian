/*
 * Copyright (C) 2009 Jens Georg <mail@jensge.org>.
 *
 * Author: Jens Georg <mail@jensge.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>


#define RYGEL_TYPE_MEDIA_DB_OBJECT_FACTORY (rygel_media_db_object_factory_get_type ())
#define RYGEL_MEDIA_DB_OBJECT_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_DB_OBJECT_FACTORY, RygelMediaDBObjectFactory))
#define RYGEL_MEDIA_DB_OBJECT_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_DB_OBJECT_FACTORY, RygelMediaDBObjectFactoryClass))
#define RYGEL_IS_MEDIA_DB_OBJECT_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_DB_OBJECT_FACTORY))
#define RYGEL_IS_MEDIA_DB_OBJECT_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_DB_OBJECT_FACTORY))
#define RYGEL_MEDIA_DB_OBJECT_FACTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_DB_OBJECT_FACTORY, RygelMediaDBObjectFactoryClass))

typedef struct _RygelMediaDBObjectFactory RygelMediaDBObjectFactory;
typedef struct _RygelMediaDBObjectFactoryClass RygelMediaDBObjectFactoryClass;
typedef struct _RygelMediaDBObjectFactoryPrivate RygelMediaDBObjectFactoryPrivate;

#define RYGEL_TYPE_MEDIA_DB (rygel_media_db_get_type ())
#define RYGEL_MEDIA_DB(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_DB, RygelMediaDB))
#define RYGEL_MEDIA_DB_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_DB, RygelMediaDBClass))
#define RYGEL_IS_MEDIA_DB(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_DB))
#define RYGEL_IS_MEDIA_DB_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_DB))
#define RYGEL_MEDIA_DB_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_DB, RygelMediaDBClass))

typedef struct _RygelMediaDB RygelMediaDB;
typedef struct _RygelMediaDBClass RygelMediaDBClass;

#define RYGEL_TYPE_MEDIA_OBJECT (rygel_media_object_get_type ())
#define RYGEL_MEDIA_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObject))
#define RYGEL_MEDIA_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObjectClass))
#define RYGEL_IS_MEDIA_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_OBJECT))
#define RYGEL_IS_MEDIA_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_OBJECT))
#define RYGEL_MEDIA_OBJECT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObjectClass))

typedef struct _RygelMediaObject RygelMediaObject;
typedef struct _RygelMediaObjectClass RygelMediaObjectClass;

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

#define RYGEL_TYPE_MEDIA_DB_CONTAINER (rygel_media_db_container_get_type ())
#define RYGEL_MEDIA_DB_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_DB_CONTAINER, RygelMediaDBContainer))
#define RYGEL_MEDIA_DB_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_DB_CONTAINER, RygelMediaDBContainerClass))
#define RYGEL_IS_MEDIA_DB_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_DB_CONTAINER))
#define RYGEL_IS_MEDIA_DB_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_DB_CONTAINER))
#define RYGEL_MEDIA_DB_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_DB_CONTAINER, RygelMediaDBContainerClass))

typedef struct _RygelMediaDBContainer RygelMediaDBContainer;
typedef struct _RygelMediaDBContainerClass RygelMediaDBContainerClass;

struct _RygelMediaDBObjectFactory {
	GObject parent_instance;
	RygelMediaDBObjectFactoryPrivate * priv;
};

struct _RygelMediaDBObjectFactoryClass {
	GObjectClass parent_class;
	RygelMediaContainer* (*get_container) (RygelMediaDBObjectFactory* self, RygelMediaDB* media_db, const char* id, const char* title, guint child_count);
	RygelMediaItem* (*get_item) (RygelMediaDBObjectFactory* self, RygelMediaDB* media_db, RygelMediaContainer* parent, const char* id, const char* title, const char* upnp_class);
};


static gpointer rygel_media_db_object_factory_parent_class = NULL;

GType rygel_media_db_object_factory_get_type (void);
GType rygel_media_db_get_type (void);
GType rygel_media_object_get_type (void);
GType rygel_media_container_get_type (void);
GType rygel_media_item_get_type (void);
enum  {
	RYGEL_MEDIA_DB_OBJECT_FACTORY_DUMMY_PROPERTY
};
RygelMediaDBContainer* rygel_media_db_container_new (RygelMediaDB* media_db, const char* id, const char* title);
RygelMediaDBContainer* rygel_media_db_container_construct (GType object_type, RygelMediaDB* media_db, const char* id, const char* title);
GType rygel_media_db_container_get_type (void);
RygelMediaContainer* rygel_media_db_object_factory_get_container (RygelMediaDBObjectFactory* self, RygelMediaDB* media_db, const char* id, const char* title, guint child_count);
static RygelMediaContainer* rygel_media_db_object_factory_real_get_container (RygelMediaDBObjectFactory* self, RygelMediaDB* media_db, const char* id, const char* title, guint child_count);
RygelMediaItem* rygel_media_item_new (const char* id, RygelMediaContainer* parent, const char* title, const char* upnp_class);
RygelMediaItem* rygel_media_item_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title, const char* upnp_class);
RygelMediaItem* rygel_media_db_object_factory_get_item (RygelMediaDBObjectFactory* self, RygelMediaDB* media_db, RygelMediaContainer* parent, const char* id, const char* title, const char* upnp_class);
static RygelMediaItem* rygel_media_db_object_factory_real_get_item (RygelMediaDBObjectFactory* self, RygelMediaDB* media_db, RygelMediaContainer* parent, const char* id, const char* title, const char* upnp_class);
RygelMediaDBObjectFactory* rygel_media_db_object_factory_new (void);
RygelMediaDBObjectFactory* rygel_media_db_object_factory_construct (GType object_type);



static RygelMediaContainer* rygel_media_db_object_factory_real_get_container (RygelMediaDBObjectFactory* self, RygelMediaDB* media_db, const char* id, const char* title, guint child_count) {
	RygelMediaContainer* result;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (media_db != NULL, NULL);
	g_return_val_if_fail (id != NULL, NULL);
	g_return_val_if_fail (title != NULL, NULL);
	result = (RygelMediaContainer*) rygel_media_db_container_new (media_db, id, title);
	return result;
}


RygelMediaContainer* rygel_media_db_object_factory_get_container (RygelMediaDBObjectFactory* self, RygelMediaDB* media_db, const char* id, const char* title, guint child_count) {
	return RYGEL_MEDIA_DB_OBJECT_FACTORY_GET_CLASS (self)->get_container (self, media_db, id, title, child_count);
}


static RygelMediaItem* rygel_media_db_object_factory_real_get_item (RygelMediaDBObjectFactory* self, RygelMediaDB* media_db, RygelMediaContainer* parent, const char* id, const char* title, const char* upnp_class) {
	RygelMediaItem* result;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (media_db != NULL, NULL);
	g_return_val_if_fail (parent != NULL, NULL);
	g_return_val_if_fail (id != NULL, NULL);
	g_return_val_if_fail (title != NULL, NULL);
	g_return_val_if_fail (upnp_class != NULL, NULL);
	result = rygel_media_item_new (id, parent, title, upnp_class);
	return result;
}


RygelMediaItem* rygel_media_db_object_factory_get_item (RygelMediaDBObjectFactory* self, RygelMediaDB* media_db, RygelMediaContainer* parent, const char* id, const char* title, const char* upnp_class) {
	return RYGEL_MEDIA_DB_OBJECT_FACTORY_GET_CLASS (self)->get_item (self, media_db, parent, id, title, upnp_class);
}


RygelMediaDBObjectFactory* rygel_media_db_object_factory_construct (GType object_type) {
	RygelMediaDBObjectFactory * self;
	self = (RygelMediaDBObjectFactory*) g_object_new (object_type, NULL);
	return self;
}


RygelMediaDBObjectFactory* rygel_media_db_object_factory_new (void) {
	return rygel_media_db_object_factory_construct (RYGEL_TYPE_MEDIA_DB_OBJECT_FACTORY);
}


static void rygel_media_db_object_factory_class_init (RygelMediaDBObjectFactoryClass * klass) {
	rygel_media_db_object_factory_parent_class = g_type_class_peek_parent (klass);
	RYGEL_MEDIA_DB_OBJECT_FACTORY_CLASS (klass)->get_container = rygel_media_db_object_factory_real_get_container;
	RYGEL_MEDIA_DB_OBJECT_FACTORY_CLASS (klass)->get_item = rygel_media_db_object_factory_real_get_item;
}


static void rygel_media_db_object_factory_instance_init (RygelMediaDBObjectFactory * self) {
}


GType rygel_media_db_object_factory_get_type (void) {
	static GType rygel_media_db_object_factory_type_id = 0;
	if (rygel_media_db_object_factory_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediaDBObjectFactoryClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_media_db_object_factory_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediaDBObjectFactory), 0, (GInstanceInitFunc) rygel_media_db_object_factory_instance_init, NULL };
		rygel_media_db_object_factory_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelMediaDBObjectFactory", &g_define_type_info, 0);
	}
	return rygel_media_db_object_factory_type_id;
}



