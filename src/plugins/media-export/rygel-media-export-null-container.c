/*
 * Copyright (C) 2009 Jens Georg <mail@jensge.org>.
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
#include <gee.h>
#include <stdlib.h>
#include <string.h>


#define RYGEL_TYPE_NULL_CONTAINER (rygel_null_container_get_type ())
#define RYGEL_NULL_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_NULL_CONTAINER, RygelNullContainer))
#define RYGEL_NULL_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_NULL_CONTAINER, RygelNullContainerClass))
#define RYGEL_IS_NULL_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_NULL_CONTAINER))
#define RYGEL_IS_NULL_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_NULL_CONTAINER))
#define RYGEL_NULL_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_NULL_CONTAINER, RygelNullContainerClass))

typedef struct _RygelNullContainer RygelNullContainer;
typedef struct _RygelNullContainerClass RygelNullContainerClass;
typedef struct _RygelNullContainerPrivate RygelNullContainerPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _RygelNullContainer {
	RygelMediaContainer parent_instance;
	RygelNullContainerPrivate * priv;
};

struct _RygelNullContainerClass {
	RygelMediaContainerClass parent_class;
};


static gpointer rygel_null_container_parent_class = NULL;

GType rygel_null_container_get_type (void);
enum  {
	RYGEL_NULL_CONTAINER_DUMMY_PROPERTY
};
RygelNullContainer* rygel_null_container_new (void);
RygelNullContainer* rygel_null_container_construct (GType object_type);
static void rygel_null_container_real_get_children (RygelMediaContainer* base, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target);
static GeeList* rygel_null_container_real_get_children_finish (RygelMediaContainer* base, GAsyncResult* res, GError** error);
static void rygel_null_container_real_find_object (RygelMediaContainer* base, const char* id, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target);
static RygelMediaObject* rygel_null_container_real_find_object_finish (RygelMediaContainer* base, GAsyncResult* res, GError** error);



RygelNullContainer* rygel_null_container_construct (GType object_type) {
	RygelNullContainer * self;
	self = (RygelNullContainer*) rygel_media_container_construct_root (object_type, "MediaExport", (guint) 0);
	return self;
}


RygelNullContainer* rygel_null_container_new (void) {
	return rygel_null_container_construct (RYGEL_TYPE_NULL_CONTAINER);
}


static void rygel_null_container_real_get_children (RygelMediaContainer* base, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target) {
	RygelNullContainer * self;
	RygelSimpleAsyncResult* res;
	self = (RygelNullContainer*) base;
	res = rygel_simple_async_result_new (G_TYPE_INT, NULL, NULL, (GObject*) self, callback, callback_target);
	rygel_simple_async_result_complete_in_idle (res);
	_g_object_unref0 (res);
}


static GeeList* rygel_null_container_real_get_children_finish (RygelMediaContainer* base, GAsyncResult* res, GError** error) {
	RygelNullContainer * self;
	GeeList* result;
	self = (RygelNullContainer*) base;
	g_return_val_if_fail (res != NULL, NULL);
	result = (GeeList*) gee_array_list_new (RYGEL_TYPE_MEDIA_OBJECT, (GBoxedCopyFunc) g_object_ref, g_object_unref, g_direct_equal);
	return result;
}


static void rygel_null_container_real_find_object (RygelMediaContainer* base, const char* id, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target) {
	RygelNullContainer * self;
	RygelSimpleAsyncResult* res;
	self = (RygelNullContainer*) base;
	g_return_if_fail (id != NULL);
	res = rygel_simple_async_result_new (G_TYPE_INT, NULL, NULL, (GObject*) self, callback, callback_target);
	rygel_simple_async_result_complete_in_idle (res);
	_g_object_unref0 (res);
}


static RygelMediaObject* rygel_null_container_real_find_object_finish (RygelMediaContainer* base, GAsyncResult* res, GError** error) {
	RygelNullContainer * self;
	RygelMediaObject* result;
	self = (RygelNullContainer*) base;
	g_return_val_if_fail (res != NULL, NULL);
	result = NULL;
	return result;
}


static void rygel_null_container_class_init (RygelNullContainerClass * klass) {
	rygel_null_container_parent_class = g_type_class_peek_parent (klass);
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->get_children = rygel_null_container_real_get_children;
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->get_children_finish = rygel_null_container_real_get_children_finish;
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->find_object = rygel_null_container_real_find_object;
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->find_object_finish = rygel_null_container_real_find_object_finish;
}


static void rygel_null_container_instance_init (RygelNullContainer * self) {
}


GType rygel_null_container_get_type (void) {
	static GType rygel_null_container_type_id = 0;
	if (rygel_null_container_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelNullContainerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_null_container_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelNullContainer), 0, (GInstanceInitFunc) rygel_null_container_instance_init, NULL };
		rygel_null_container_type_id = g_type_register_static (RYGEL_TYPE_MEDIA_CONTAINER, "RygelNullContainer", &g_define_type_info, 0);
	}
	return rygel_null_container_type_id;
}




