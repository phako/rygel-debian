/*
 * Copyright (C) 2009 Zeeshan Ali (Khattak) <zeeshanak@gnome.org>.
 * Copyright (C) 2009 Nokia Corporation.
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

#define RYGEL_TYPE_SIMPLE_CONTAINER (rygel_simple_container_get_type ())
#define RYGEL_SIMPLE_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_SIMPLE_CONTAINER, RygelSimpleContainer))
#define RYGEL_SIMPLE_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_SIMPLE_CONTAINER, RygelSimpleContainerClass))
#define RYGEL_IS_SIMPLE_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_SIMPLE_CONTAINER))
#define RYGEL_IS_SIMPLE_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_SIMPLE_CONTAINER))
#define RYGEL_SIMPLE_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_SIMPLE_CONTAINER, RygelSimpleContainerClass))

typedef struct _RygelSimpleContainer RygelSimpleContainer;
typedef struct _RygelSimpleContainerClass RygelSimpleContainerClass;
typedef struct _RygelSimpleContainerPrivate RygelSimpleContainerPrivate;

#define RYGEL_TYPE_MEDIA_OBJECT_SEARCH (rygel_media_object_search_get_type ())
#define RYGEL_MEDIA_OBJECT_SEARCH(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_OBJECT_SEARCH, RygelMediaObjectSearch))
#define RYGEL_MEDIA_OBJECT_SEARCH_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_OBJECT_SEARCH, RygelMediaObjectSearchClass))
#define RYGEL_IS_MEDIA_OBJECT_SEARCH(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_OBJECT_SEARCH))
#define RYGEL_IS_MEDIA_OBJECT_SEARCH_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_OBJECT_SEARCH))
#define RYGEL_MEDIA_OBJECT_SEARCH_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_OBJECT_SEARCH, RygelMediaObjectSearchClass))

typedef struct _RygelMediaObjectSearch RygelMediaObjectSearch;
typedef struct _RygelMediaObjectSearchClass RygelMediaObjectSearchClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define RYGEL_TYPE_SIMPLE_ASYNC_RESULT (rygel_simple_async_result_get_type ())
#define RYGEL_SIMPLE_ASYNC_RESULT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_SIMPLE_ASYNC_RESULT, RygelSimpleAsyncResult))
#define RYGEL_SIMPLE_ASYNC_RESULT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_SIMPLE_ASYNC_RESULT, RygelSimpleAsyncResultClass))
#define RYGEL_IS_SIMPLE_ASYNC_RESULT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_SIMPLE_ASYNC_RESULT))
#define RYGEL_IS_SIMPLE_ASYNC_RESULT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_SIMPLE_ASYNC_RESULT))
#define RYGEL_SIMPLE_ASYNC_RESULT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_SIMPLE_ASYNC_RESULT, RygelSimpleAsyncResultClass))

typedef struct _RygelSimpleAsyncResult RygelSimpleAsyncResult;
typedef struct _RygelSimpleAsyncResultClass RygelSimpleAsyncResultClass;
typedef struct _RygelSimpleAsyncResultPrivate RygelSimpleAsyncResultPrivate;

#define RYGEL_TYPE_STATE_MACHINE (rygel_state_machine_get_type ())
#define RYGEL_STATE_MACHINE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_STATE_MACHINE, RygelStateMachine))
#define RYGEL_IS_STATE_MACHINE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_STATE_MACHINE))
#define RYGEL_STATE_MACHINE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), RYGEL_TYPE_STATE_MACHINE, RygelStateMachineIface))

typedef struct _RygelStateMachine RygelStateMachine;
typedef struct _RygelStateMachineIface RygelStateMachineIface;
typedef struct _RygelMediaObjectSearchPrivate RygelMediaObjectSearchPrivate;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

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

struct _RygelSimpleContainer {
	RygelMediaContainer parent_instance;
	RygelSimpleContainerPrivate * priv;
	GeeArrayList* children;
};

struct _RygelSimpleContainerClass {
	RygelMediaContainerClass parent_class;
};

struct _RygelSimpleContainerPrivate {
	GeeArrayList* searches;
};

struct _RygelSimpleAsyncResult {
	GObject parent_instance;
	RygelSimpleAsyncResultPrivate * priv;
	GObject* source_object;
	GAsyncReadyCallback callback;
	gpointer callback_target;
	GDestroyNotify callback_target_destroy_notify;
	gpointer data;
	GError* error;
};

struct _RygelSimpleAsyncResultClass {
	GObjectClass parent_class;
};

struct _RygelStateMachineIface {
	GTypeInterface parent_iface;
	void (*run) (RygelStateMachine* self);
	GCancellable* (*get_cancellable) (RygelStateMachine* self);
	void (*set_cancellable) (RygelStateMachine* self, GCancellable* value);
};

struct _RygelMediaObjectSearch {
	GObject parent_instance;
	RygelMediaObjectSearchPrivate * priv;
	char* id;
	gpointer data;
	RygelMediaObject* media_object;
	GError* error;
};

struct _RygelMediaObjectSearchClass {
	GObjectClass parent_class;
};


static gpointer rygel_simple_container_parent_class = NULL;

GType rygel_media_object_get_type (void);
GType rygel_media_container_get_type (void);
GType rygel_simple_container_get_type (void);
GType rygel_media_object_search_get_type (void);
#define RYGEL_SIMPLE_CONTAINER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_SIMPLE_CONTAINER, RygelSimpleContainerPrivate))
enum  {
	RYGEL_SIMPLE_CONTAINER_DUMMY_PROPERTY
};
RygelMediaContainer* rygel_media_container_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title, guint child_count);
RygelSimpleContainer* rygel_simple_container_new (const char* id, RygelMediaContainer* parent, const char* title);
RygelSimpleContainer* rygel_simple_container_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title);
RygelSimpleContainer* rygel_simple_container_new_root (const char* title);
RygelSimpleContainer* rygel_simple_container_construct_root (GType object_type, const char* title);
void rygel_simple_container_add_child (RygelSimpleContainer* self, RygelMediaObject* child);
void rygel_simple_container_remove_child (RygelSimpleContainer* self, RygelMediaObject* child);
RygelSimpleAsyncResult* rygel_simple_async_result_new (GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, GObject* source_object, GAsyncReadyCallback callback, void* callback_target);
RygelSimpleAsyncResult* rygel_simple_async_result_construct (GType object_type, GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, GObject* source_object, GAsyncReadyCallback callback, void* callback_target);
GType rygel_simple_async_result_get_type (void);
void rygel_simple_async_result_complete_in_idle (RygelSimpleAsyncResult* self);
static void rygel_simple_container_real_get_children (RygelMediaContainer* base, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target);
static GeeList* rygel_simple_container_real_get_children_finish (RygelMediaContainer* base, GAsyncResult* res, GError** error);
RygelMediaObjectSearch* rygel_media_object_search_new (GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, const char* id, GeeArrayList* containers, gconstpointer data, GCancellable* cancellable);
RygelMediaObjectSearch* rygel_media_object_search_construct (GType object_type, GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, const char* id, GeeArrayList* containers, gconstpointer data, GCancellable* cancellable);
GType rygel_state_machine_get_type (void);
static void rygel_simple_container_on_object_search_completed (RygelSimpleContainer* self, RygelStateMachine* state_machine);
static void _rygel_simple_container_on_object_search_completed_rygel_state_machine_completed (RygelStateMachine* _sender, gpointer self);
void rygel_state_machine_run (RygelStateMachine* self);
static void rygel_simple_container_real_find_object (RygelMediaContainer* base, const char* id, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target);
static RygelMediaObject* rygel_simple_container_real_find_object_finish (RygelMediaContainer* base, GAsyncResult* res, GError** error);
void rygel_simple_async_result_complete (RygelSimpleAsyncResult* self);
static void rygel_simple_container_finalize (GObject* obj);
static int _vala_strcmp0 (const char * str1, const char * str2);



RygelSimpleContainer* rygel_simple_container_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title) {
	RygelSimpleContainer * self;
	GeeArrayList* _tmp0_;
	GeeArrayList* _tmp1_;
	g_return_val_if_fail (id != NULL, NULL);
	g_return_val_if_fail (title != NULL, NULL);
	self = (RygelSimpleContainer*) rygel_media_container_construct (object_type, id, parent, title, (guint) 0);
	self->children = (_tmp0_ = gee_array_list_new (RYGEL_TYPE_MEDIA_OBJECT, (GBoxedCopyFunc) g_object_ref, g_object_unref, g_direct_equal), _g_object_unref0 (self->children), _tmp0_);
	self->priv->searches = (_tmp1_ = gee_array_list_new (RYGEL_TYPE_MEDIA_OBJECT_SEARCH, (GBoxedCopyFunc) g_object_ref, g_object_unref, g_direct_equal), _g_object_unref0 (self->priv->searches), _tmp1_);
	return self;
}


RygelSimpleContainer* rygel_simple_container_new (const char* id, RygelMediaContainer* parent, const char* title) {
	return rygel_simple_container_construct (RYGEL_TYPE_SIMPLE_CONTAINER, id, parent, title);
}


RygelSimpleContainer* rygel_simple_container_construct_root (GType object_type, const char* title) {
	RygelSimpleContainer * self;
	g_return_val_if_fail (title != NULL, NULL);
	self = (RygelSimpleContainer*) rygel_simple_container_construct (object_type, "0", NULL, title);
	return self;
}


RygelSimpleContainer* rygel_simple_container_new_root (const char* title) {
	return rygel_simple_container_construct_root (RYGEL_TYPE_SIMPLE_CONTAINER, title);
}


void rygel_simple_container_add_child (RygelSimpleContainer* self, RygelMediaObject* child) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (child != NULL);
	gee_abstract_collection_add ((GeeAbstractCollection*) self->children, child);
	((RygelMediaContainer*) self)->child_count++;
}


void rygel_simple_container_remove_child (RygelSimpleContainer* self, RygelMediaObject* child) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (child != NULL);
	gee_abstract_collection_remove ((GeeAbstractCollection*) self->children, child);
	((RygelMediaContainer*) self)->child_count--;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void rygel_simple_container_real_get_children (RygelMediaContainer* base, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target) {
	RygelSimpleContainer * self;
	guint stop;
	GeeList* media_objects;
	RygelSimpleAsyncResult* res;
	GeeList* _tmp0_;
	self = (RygelSimpleContainer*) base;
	stop = offset + max_count;
	stop = CLAMP (stop, (guint) 0, ((RygelMediaContainer*) self)->child_count);
	media_objects = gee_abstract_list_slice ((GeeAbstractList*) self->children, (gint) offset, (gint) stop);
	res = rygel_simple_async_result_new (GEE_TYPE_LIST, (GBoxedCopyFunc) g_object_ref, g_object_unref, (GObject*) self, callback, callback_target);
	res->data = (_tmp0_ = _g_object_ref0 (media_objects), _g_object_unref0 (res->data), _tmp0_);
	rygel_simple_async_result_complete_in_idle (res);
	_g_object_unref0 (media_objects);
	_g_object_unref0 (res);
}


static GeeList* rygel_simple_container_real_get_children_finish (RygelMediaContainer* base, GAsyncResult* res, GError** error) {
	RygelSimpleContainer * self;
	GeeList* result;
	RygelSimpleAsyncResult* simple_res;
	self = (RygelSimpleContainer*) base;
	g_return_val_if_fail (res != NULL, NULL);
	simple_res = _g_object_ref0 (RYGEL_SIMPLE_ASYNC_RESULT (res));
	result = _g_object_ref0 ((GeeList*) simple_res->data);
	_g_object_unref0 (simple_res);
	return result;
}


static void _rygel_simple_container_on_object_search_completed_rygel_state_machine_completed (RygelStateMachine* _sender, gpointer self) {
	rygel_simple_container_on_object_search_completed (self, _sender);
}


static void rygel_simple_container_real_find_object (RygelMediaContainer* base, const char* id, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target) {
	RygelSimpleContainer * self;
	RygelSimpleAsyncResult* res;
	RygelMediaObject* child;
	self = (RygelSimpleContainer*) base;
	g_return_if_fail (id != NULL);
	res = rygel_simple_async_result_new (RYGEL_TYPE_MEDIA_OBJECT, (GBoxedCopyFunc) g_object_ref, g_object_unref, (GObject*) self, callback, callback_target);
	child = NULL;
	{
		GeeIterator* _tmp_it;
		_tmp_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->children);
		while (TRUE) {
			RygelMediaObject* tmp;
			if (!gee_iterator_next (_tmp_it)) {
				break;
			}
			tmp = (RygelMediaObject*) gee_iterator_get (_tmp_it);
			if (_vala_strcmp0 (id, tmp->id) == 0) {
				RygelMediaObject* _tmp0_;
				child = (_tmp0_ = _g_object_ref0 (tmp), _g_object_unref0 (child), _tmp0_);
				_g_object_unref0 (tmp);
				break;
			}
			_g_object_unref0 (tmp);
		}
		_g_object_unref0 (_tmp_it);
	}
	if (child != NULL) {
		RygelMediaObject* _tmp1_;
		res->data = (_tmp1_ = _g_object_ref0 (child), _g_object_unref0 (res->data), _tmp1_);
		rygel_simple_async_result_complete_in_idle (res);
	} else {
		GeeArrayList* containers;
		RygelMediaObjectSearch* search;
		containers = gee_array_list_new (RYGEL_TYPE_MEDIA_CONTAINER, (GBoxedCopyFunc) g_object_ref, g_object_unref, g_direct_equal);
		{
			GeeIterator* _tmp_it;
			_tmp_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->children);
			while (TRUE) {
				RygelMediaObject* tmp;
				if (!gee_iterator_next (_tmp_it)) {
					break;
				}
				tmp = (RygelMediaObject*) gee_iterator_get (_tmp_it);
				if (RYGEL_IS_MEDIA_CONTAINER (tmp)) {
					RygelMediaObject* _tmp2_;
					gee_abstract_collection_add ((GeeAbstractCollection*) containers, (_tmp2_ = tmp, RYGEL_IS_MEDIA_CONTAINER (_tmp2_) ? ((RygelMediaContainer*) _tmp2_) : NULL));
				}
				_g_object_unref0 (tmp);
			}
			_g_object_unref0 (_tmp_it);
		}
		search = rygel_media_object_search_new (RYGEL_TYPE_SIMPLE_ASYNC_RESULT, (GBoxedCopyFunc) g_object_ref, g_object_unref, id, containers, res, cancellable);
		g_signal_connect_object ((RygelStateMachine*) search, "completed", (GCallback) _rygel_simple_container_on_object_search_completed_rygel_state_machine_completed, self, 0);
		gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->searches, search);
		rygel_state_machine_run ((RygelStateMachine*) search);
		_g_object_unref0 (containers);
		_g_object_unref0 (search);
	}
	_g_object_unref0 (res);
	_g_object_unref0 (child);
}


static gpointer _g_error_copy0 (gpointer self) {
	return self ? g_error_copy (self) : NULL;
}


static RygelMediaObject* rygel_simple_container_real_find_object_finish (RygelMediaContainer* base, GAsyncResult* res, GError** error) {
	RygelSimpleContainer * self;
	RygelMediaObject* result;
	GError * _inner_error_;
	RygelSimpleAsyncResult* simple_res;
	self = (RygelSimpleContainer*) base;
	g_return_val_if_fail (res != NULL, NULL);
	_inner_error_ = NULL;
	simple_res = _g_object_ref0 (RYGEL_SIMPLE_ASYNC_RESULT (res));
	if (simple_res->error != NULL) {
		_inner_error_ = _g_error_copy0 (simple_res->error);
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_g_object_unref0 (simple_res);
			return NULL;
		}
	} else {
		result = _g_object_ref0 ((RygelMediaObject*) simple_res->data);
		_g_object_unref0 (simple_res);
		return result;
	}
	_g_object_unref0 (simple_res);
}


static void rygel_simple_container_on_object_search_completed (RygelSimpleContainer* self, RygelStateMachine* state_machine) {
	RygelStateMachine* _tmp0_;
	RygelMediaObjectSearch* search;
	RygelMediaObject* _tmp1_;
	GError* _tmp2_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (state_machine != NULL);
	search = _g_object_ref0 ((_tmp0_ = state_machine, RYGEL_IS_MEDIA_OBJECT_SEARCH (_tmp0_) ? ((RygelMediaObjectSearch*) _tmp0_) : NULL));
	((RygelSimpleAsyncResult*) search->data)->data = (_tmp1_ = _g_object_ref0 (search->media_object), _g_object_unref0 (((RygelSimpleAsyncResult*) search->data)->data), _tmp1_);
	((RygelSimpleAsyncResult*) search->data)->error = (_tmp2_ = _g_error_copy0 (search->error), _g_error_free0 (((RygelSimpleAsyncResult*) search->data)->error), _tmp2_);
	rygel_simple_async_result_complete ((RygelSimpleAsyncResult*) search->data);
	gee_abstract_collection_remove ((GeeAbstractCollection*) self->priv->searches, search);
	_g_object_unref0 (search);
}


static void rygel_simple_container_class_init (RygelSimpleContainerClass * klass) {
	rygel_simple_container_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelSimpleContainerPrivate));
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->get_children = rygel_simple_container_real_get_children;
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->get_children_finish = rygel_simple_container_real_get_children_finish;
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->find_object = rygel_simple_container_real_find_object;
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->find_object_finish = rygel_simple_container_real_find_object_finish;
	G_OBJECT_CLASS (klass)->finalize = rygel_simple_container_finalize;
}


static void rygel_simple_container_instance_init (RygelSimpleContainer * self) {
	self->priv = RYGEL_SIMPLE_CONTAINER_GET_PRIVATE (self);
}


static void rygel_simple_container_finalize (GObject* obj) {
	RygelSimpleContainer * self;
	self = RYGEL_SIMPLE_CONTAINER (obj);
	_g_object_unref0 (self->children);
	_g_object_unref0 (self->priv->searches);
	G_OBJECT_CLASS (rygel_simple_container_parent_class)->finalize (obj);
}


GType rygel_simple_container_get_type (void) {
	static GType rygel_simple_container_type_id = 0;
	if (rygel_simple_container_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelSimpleContainerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_simple_container_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelSimpleContainer), 0, (GInstanceInitFunc) rygel_simple_container_instance_init, NULL };
		rygel_simple_container_type_id = g_type_register_static (RYGEL_TYPE_MEDIA_CONTAINER, "RygelSimpleContainer", &g_define_type_info, 0);
	}
	return rygel_simple_container_type_id;
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




