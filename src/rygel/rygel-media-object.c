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
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

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


static gpointer rygel_media_object_parent_class = NULL;

GType rygel_media_object_get_type (void);
GType rygel_media_container_get_type (void);
enum  {
	RYGEL_MEDIA_OBJECT_DUMMY_PROPERTY
};
RygelMediaObject* rygel_media_object_construct (GType object_type);
static GObject * rygel_media_object_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void rygel_media_object_finalize (GObject* obj);



RygelMediaObject* rygel_media_object_construct (GType object_type) {
	RygelMediaObject * self;
	self = g_object_newv (object_type, 0, NULL);
	return self;
}


static GObject * rygel_media_object_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	RygelMediaObject * self;
	parent_class = G_OBJECT_CLASS (rygel_media_object_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = RYGEL_MEDIA_OBJECT (obj);
	{
		GeeArrayList* _tmp0_;
		self->uris = (_tmp0_ = gee_array_list_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, g_direct_equal), _g_object_unref0 (self->uris), _tmp0_);
	}
	return obj;
}


static void rygel_media_object_class_init (RygelMediaObjectClass * klass) {
	rygel_media_object_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->constructor = rygel_media_object_constructor;
	G_OBJECT_CLASS (klass)->finalize = rygel_media_object_finalize;
}


static void rygel_media_object_instance_init (RygelMediaObject * self) {
}


static void rygel_media_object_finalize (GObject* obj) {
	RygelMediaObject * self;
	self = RYGEL_MEDIA_OBJECT (obj);
	_g_free0 (self->id);
	_g_free0 (self->title);
	_g_object_unref0 (self->uris);
	_g_object_unref0 (self->parent_ref);
	G_OBJECT_CLASS (rygel_media_object_parent_class)->finalize (obj);
}


GType rygel_media_object_get_type (void) {
	static GType rygel_media_object_type_id = 0;
	if (rygel_media_object_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediaObjectClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_media_object_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediaObject), 0, (GInstanceInitFunc) rygel_media_object_instance_init, NULL };
		rygel_media_object_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelMediaObject", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
	}
	return rygel_media_object_type_id;
}




