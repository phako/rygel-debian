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
#include <gio/gio.h>


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
typedef struct _RygelMediaContainerPrivate RygelMediaContainerPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))

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

struct _RygelMediaContainer {
	RygelMediaObject parent_instance;
	RygelMediaContainerPrivate * priv;
	guint child_count;
	guint32 update_id;
};

struct _RygelMediaContainerClass {
	RygelMediaObjectClass parent_class;
	void (*get_children) (RygelMediaContainer* self, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target);
	GeeList* (*get_children_finish) (RygelMediaContainer* self, GAsyncResult* res, GError** error);
	void (*find_object) (RygelMediaContainer* self, const char* id, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target);
	RygelMediaObject* (*find_object_finish) (RygelMediaContainer* self, GAsyncResult* res, GError** error);
};


static gpointer rygel_media_container_parent_class = NULL;

GType rygel_media_object_get_type (void);
GType rygel_media_container_get_type (void);
enum  {
	RYGEL_MEDIA_CONTAINER_DUMMY_PROPERTY
};
RygelMediaObject* rygel_media_object_construct (GType object_type);
static void rygel_media_container_on_container_updated (RygelMediaContainer* self, RygelMediaContainer* container, RygelMediaContainer* updated_container);
static void _rygel_media_container_on_container_updated_rygel_media_container_container_updated (RygelMediaContainer* _sender, RygelMediaContainer* container, gpointer self);
RygelMediaContainer* rygel_media_container_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title, guint child_count);
RygelMediaContainer* rygel_media_container_construct_root (GType object_type, const char* title, guint child_count);
void rygel_media_container_get_children (RygelMediaContainer* self, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target);
static void rygel_media_container_real_get_children (RygelMediaContainer* self, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target);
GeeList* rygel_media_container_get_children_finish (RygelMediaContainer* self, GAsyncResult* res, GError** error);
static GeeList* rygel_media_container_real_get_children_finish (RygelMediaContainer* self, GAsyncResult* res, GError** error);
void rygel_media_container_find_object (RygelMediaContainer* self, const char* id, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target);
static void rygel_media_container_real_find_object (RygelMediaContainer* self, const char* id, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target);
RygelMediaObject* rygel_media_container_find_object_finish (RygelMediaContainer* self, GAsyncResult* res, GError** error);
static RygelMediaObject* rygel_media_container_real_find_object_finish (RygelMediaContainer* self, GAsyncResult* res, GError** error);
void rygel_media_container_updated (RygelMediaContainer* self);
static void rygel_media_container_finalize (GObject* obj);



static void _rygel_media_container_on_container_updated_rygel_media_container_container_updated (RygelMediaContainer* _sender, RygelMediaContainer* container, gpointer self) {
	rygel_media_container_on_container_updated (self, _sender, container);
}


RygelMediaContainer* rygel_media_container_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title, guint child_count) {
	RygelMediaContainer * self;
	char* _tmp0_;
	char* _tmp1_;
	g_return_val_if_fail (id != NULL, NULL);
	g_return_val_if_fail (title != NULL, NULL);
	self = (RygelMediaContainer*) rygel_media_object_construct (object_type);
	((RygelMediaObject*) self)->id = (_tmp0_ = g_strdup (id), _g_free0 (((RygelMediaObject*) self)->id), _tmp0_);
	((RygelMediaObject*) self)->parent = parent;
	((RygelMediaObject*) self)->title = (_tmp1_ = g_strdup (title), _g_free0 (((RygelMediaObject*) self)->title), _tmp1_);
	self->child_count = child_count;
	self->update_id = (guint32) 0;
	g_signal_connect_object (self, "container-updated", (GCallback) _rygel_media_container_on_container_updated_rygel_media_container_container_updated, self, 0);
	return self;
}


RygelMediaContainer* rygel_media_container_construct_root (GType object_type, const char* title, guint child_count) {
	RygelMediaContainer * self;
	g_return_val_if_fail (title != NULL, NULL);
	self = (RygelMediaContainer*) rygel_media_container_construct (object_type, "0", NULL, title, child_count);
	return self;
}


static void rygel_media_container_real_get_children (RygelMediaContainer* self, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target) {
	g_return_if_fail (self != NULL);
	g_critical ("Type `%s' does not implement abstract method `rygel_media_container_get_children'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return;
}


void rygel_media_container_get_children (RygelMediaContainer* self, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target) {
	RYGEL_MEDIA_CONTAINER_GET_CLASS (self)->get_children (self, offset, max_count, cancellable, callback, callback_target);
}


static GeeList* rygel_media_container_real_get_children_finish (RygelMediaContainer* self, GAsyncResult* res, GError** error) {
	g_return_val_if_fail (self != NULL, NULL);
	g_critical ("Type `%s' does not implement abstract method `rygel_media_container_get_children_finish'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}


GeeList* rygel_media_container_get_children_finish (RygelMediaContainer* self, GAsyncResult* res, GError** error) {
	return RYGEL_MEDIA_CONTAINER_GET_CLASS (self)->get_children_finish (self, res, error);
}


static void rygel_media_container_real_find_object (RygelMediaContainer* self, const char* id, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target) {
	g_return_if_fail (self != NULL);
	g_critical ("Type `%s' does not implement abstract method `rygel_media_container_find_object'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return;
}


void rygel_media_container_find_object (RygelMediaContainer* self, const char* id, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target) {
	RYGEL_MEDIA_CONTAINER_GET_CLASS (self)->find_object (self, id, cancellable, callback, callback_target);
}


static RygelMediaObject* rygel_media_container_real_find_object_finish (RygelMediaContainer* self, GAsyncResult* res, GError** error) {
	g_return_val_if_fail (self != NULL, NULL);
	g_critical ("Type `%s' does not implement abstract method `rygel_media_container_find_object_finish'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}


RygelMediaObject* rygel_media_container_find_object_finish (RygelMediaContainer* self, GAsyncResult* res, GError** error) {
	return RYGEL_MEDIA_CONTAINER_GET_CLASS (self)->find_object_finish (self, res, error);
}


void rygel_media_container_updated (RygelMediaContainer* self) {
	g_return_if_fail (self != NULL);
	self->update_id++;
	g_signal_emit_by_name (self, "container-updated", self);
}


static void rygel_media_container_on_container_updated (RygelMediaContainer* self, RygelMediaContainer* container, RygelMediaContainer* updated_container) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (container != NULL);
	g_return_if_fail (updated_container != NULL);
	if (((RygelMediaObject*) self)->parent != NULL) {
		g_signal_emit_by_name (((RygelMediaObject*) self)->parent, "container-updated", updated_container);
	}
}


static void rygel_media_container_class_init (RygelMediaContainerClass * klass) {
	rygel_media_container_parent_class = g_type_class_peek_parent (klass);
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->get_children = rygel_media_container_real_get_children;
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->get_children_finish = rygel_media_container_real_get_children_finish;
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->find_object = rygel_media_container_real_find_object;
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->find_object_finish = rygel_media_container_real_find_object_finish;
	G_OBJECT_CLASS (klass)->finalize = rygel_media_container_finalize;
	g_signal_new ("container_updated", RYGEL_TYPE_MEDIA_CONTAINER, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__OBJECT, G_TYPE_NONE, 1, RYGEL_TYPE_MEDIA_CONTAINER);
}


static void rygel_media_container_instance_init (RygelMediaContainer * self) {
}


static void rygel_media_container_finalize (GObject* obj) {
	RygelMediaContainer * self;
	self = RYGEL_MEDIA_CONTAINER (obj);
	G_OBJECT_CLASS (rygel_media_container_parent_class)->finalize (obj);
}


GType rygel_media_container_get_type (void) {
	static GType rygel_media_container_type_id = 0;
	if (rygel_media_container_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediaContainerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_media_container_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediaContainer), 0, (GInstanceInitFunc) rygel_media_container_instance_init, NULL };
		rygel_media_container_type_id = g_type_register_static (RYGEL_TYPE_MEDIA_OBJECT, "RygelMediaContainer", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
	}
	return rygel_media_container_type_id;
}




