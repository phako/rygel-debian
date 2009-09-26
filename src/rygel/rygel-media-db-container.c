/*
 * Copyright (C) 2009 Jens Georg <mail@jensge.org>.
 *
 * Author: Jens Georg <mail@jensge.org>
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

#define RYGEL_TYPE_MEDIA_DB_CONTAINER (rygel_media_db_container_get_type ())
#define RYGEL_MEDIA_DB_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_DB_CONTAINER, RygelMediaDBContainer))
#define RYGEL_MEDIA_DB_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_DB_CONTAINER, RygelMediaDBContainerClass))
#define RYGEL_IS_MEDIA_DB_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_DB_CONTAINER))
#define RYGEL_IS_MEDIA_DB_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_DB_CONTAINER))
#define RYGEL_MEDIA_DB_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_DB_CONTAINER, RygelMediaDBContainerClass))

typedef struct _RygelMediaDBContainer RygelMediaDBContainer;
typedef struct _RygelMediaDBContainerClass RygelMediaDBContainerClass;
typedef struct _RygelMediaDBContainerPrivate RygelMediaDBContainerPrivate;

#define RYGEL_TYPE_MEDIA_DB (rygel_media_db_get_type ())
#define RYGEL_MEDIA_DB(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_DB, RygelMediaDB))
#define RYGEL_MEDIA_DB_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_DB, RygelMediaDBClass))
#define RYGEL_IS_MEDIA_DB(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_DB))
#define RYGEL_IS_MEDIA_DB_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_DB))
#define RYGEL_MEDIA_DB_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_DB, RygelMediaDBClass))

typedef struct _RygelMediaDB RygelMediaDB;
typedef struct _RygelMediaDBClass RygelMediaDBClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

#define RYGEL_TYPE_SIMPLE_ASYNC_RESULT (rygel_simple_async_result_get_type ())
#define RYGEL_SIMPLE_ASYNC_RESULT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_SIMPLE_ASYNC_RESULT, RygelSimpleAsyncResult))
#define RYGEL_SIMPLE_ASYNC_RESULT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_SIMPLE_ASYNC_RESULT, RygelSimpleAsyncResultClass))
#define RYGEL_IS_SIMPLE_ASYNC_RESULT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_SIMPLE_ASYNC_RESULT))
#define RYGEL_IS_SIMPLE_ASYNC_RESULT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_SIMPLE_ASYNC_RESULT))
#define RYGEL_SIMPLE_ASYNC_RESULT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_SIMPLE_ASYNC_RESULT, RygelSimpleAsyncResultClass))

typedef struct _RygelSimpleAsyncResult RygelSimpleAsyncResult;
typedef struct _RygelSimpleAsyncResultClass RygelSimpleAsyncResultClass;
typedef struct _RygelSimpleAsyncResultPrivate RygelSimpleAsyncResultPrivate;

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

struct _RygelMediaDBContainer {
	RygelMediaContainer parent_instance;
	RygelMediaDBContainerPrivate * priv;
	RygelMediaDB* media_db;
};

struct _RygelMediaDBContainerClass {
	RygelMediaContainerClass parent_class;
};

typedef enum  {
	RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR,
	RYGEL_MEDIA_DB_ERROR_GENERAL_ERROR,
	RYGEL_MEDIA_DB_ERROR_INVALID_TYPE
} RygelMediaDBError;
#define RYGEL_MEDIA_DB_ERROR rygel_media_db_error_quark ()
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


static gpointer rygel_media_db_container_parent_class = NULL;

GType rygel_media_object_get_type (void);
GType rygel_media_container_get_type (void);
GType rygel_media_db_container_get_type (void);
GType rygel_media_db_get_type (void);
enum  {
	RYGEL_MEDIA_DB_CONTAINER_DUMMY_PROPERTY
};
GQuark rygel_media_db_error_quark (void);
gint rygel_media_db_get_child_count (RygelMediaDB* self, const char* container_id, GError** error);
RygelMediaContainer* rygel_media_container_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title, guint child_count);
static void rygel_media_db_container_on_db_container_updated (RygelMediaDBContainer* self, RygelMediaContainer* container, RygelMediaContainer* container_updated);
static void _rygel_media_db_container_on_db_container_updated_rygel_media_container_container_updated (RygelMediaContainer* _sender, RygelMediaContainer* container, gpointer self);
RygelMediaDBContainer* rygel_media_db_container_new (RygelMediaDB* media_db, const char* id, const char* title);
RygelMediaDBContainer* rygel_media_db_container_construct (GType object_type, RygelMediaDB* media_db, const char* id, const char* title);
RygelSimpleAsyncResult* rygel_simple_async_result_new (GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, GObject* source_object, GAsyncReadyCallback callback, void* callback_target);
RygelSimpleAsyncResult* rygel_simple_async_result_construct (GType object_type, GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, GObject* source_object, GAsyncReadyCallback callback, void* callback_target);
GType rygel_simple_async_result_get_type (void);
GeeArrayList* rygel_media_db_get_children (RygelMediaDB* self, const char* container_id, glong offset, glong max_count);
void rygel_simple_async_result_complete_in_idle (RygelSimpleAsyncResult* self);
static void rygel_media_db_container_real_get_children (RygelMediaContainer* base, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target);
static GeeList* rygel_media_db_container_real_get_children_finish (RygelMediaContainer* base, GAsyncResult* res, GError** error);
RygelMediaObject* rygel_media_db_get_object (RygelMediaDB* self, const char* object_id, GError** error);
static void rygel_media_db_container_real_find_object (RygelMediaContainer* base, const char* id, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target);
static RygelMediaObject* rygel_media_db_container_real_find_object_finish (RygelMediaContainer* base, GAsyncResult* res, GError** error);
static void rygel_media_db_container_finalize (GObject* obj);



static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _rygel_media_db_container_on_db_container_updated_rygel_media_container_container_updated (RygelMediaContainer* _sender, RygelMediaContainer* container, gpointer self) {
	rygel_media_db_container_on_db_container_updated (self, _sender, container);
}


RygelMediaDBContainer* rygel_media_db_container_construct (GType object_type, RygelMediaDB* media_db, const char* id, const char* title) {
	GError * _inner_error_;
	RygelMediaDBContainer * self;
	gint count;
	RygelMediaDB* _tmp1_;
	g_return_val_if_fail (media_db != NULL, NULL);
	g_return_val_if_fail (id != NULL, NULL);
	g_return_val_if_fail (title != NULL, NULL);
	_inner_error_ = NULL;
	count = 0;
	{
		gint _tmp0_;
		_tmp0_ = rygel_media_db_get_child_count (media_db, id, &_inner_error_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
				goto __catch43_rygel_media_db_error;
			}
			goto __finally43;
		}
		count = _tmp0_;
	}
	goto __finally43;
	__catch43_rygel_media_db_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			g_debug ("rygel-media-db-container.vala:31: Could not get child count from database: %s", e->message);
			count = 0;
			_g_error_free0 (e);
		}
	}
	__finally43:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	self = (RygelMediaDBContainer*) rygel_media_container_construct (object_type, id, NULL, title, (guint) count);
	self->media_db = (_tmp1_ = _g_object_ref0 (media_db), _g_object_unref0 (self->media_db), _tmp1_);
	g_signal_connect_object ((RygelMediaContainer*) self, "container-updated", (GCallback) _rygel_media_db_container_on_db_container_updated_rygel_media_container_container_updated, self, 0);
	return self;
}


RygelMediaDBContainer* rygel_media_db_container_new (RygelMediaDB* media_db, const char* id, const char* title) {
	return rygel_media_db_container_construct (RYGEL_TYPE_MEDIA_DB_CONTAINER, media_db, id, title);
}


static void rygel_media_db_container_on_db_container_updated (RygelMediaDBContainer* self, RygelMediaContainer* container, RygelMediaContainer* container_updated) {
	GError * _inner_error_;
	gint _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (container != NULL);
	g_return_if_fail (container_updated != NULL);
	_inner_error_ = NULL;
	_tmp0_ = rygel_media_db_get_child_count (self->media_db, ((RygelMediaObject*) self)->id, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return;
	}
	((RygelMediaContainer*) self)->child_count = (guint) _tmp0_;
}


static void rygel_media_db_container_real_get_children (RygelMediaContainer* base, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target) {
	RygelMediaDBContainer * self;
	RygelSimpleAsyncResult* res;
	GeeArrayList* _tmp0_;
	self = (RygelMediaDBContainer*) base;
	res = rygel_simple_async_result_new (GEE_TYPE_ARRAY_LIST, (GBoxedCopyFunc) g_object_ref, g_object_unref, (GObject*) self, callback, callback_target);
	res->data = (_tmp0_ = rygel_media_db_get_children (self->media_db, ((RygelMediaObject*) self)->id, (glong) offset, (glong) max_count), _g_object_unref0 (res->data), _tmp0_);
	rygel_simple_async_result_complete_in_idle (res);
	_g_object_unref0 (res);
}


static GeeList* rygel_media_db_container_real_get_children_finish (RygelMediaContainer* base, GAsyncResult* res, GError** error) {
	RygelMediaDBContainer * self;
	GeeList* result;
	RygelSimpleAsyncResult* _result_;
	self = (RygelMediaDBContainer*) base;
	g_return_val_if_fail (res != NULL, NULL);
	_result_ = _g_object_ref0 (RYGEL_SIMPLE_ASYNC_RESULT (res));
	{
		GeeIterator* _obj_it;
		_obj_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) ((GeeArrayList*) _result_->data));
		while (TRUE) {
			RygelMediaObject* obj;
			if (!gee_iterator_next (_obj_it)) {
				break;
			}
			obj = (RygelMediaObject*) gee_iterator_get (_obj_it);
			obj->parent = (RygelMediaContainer*) self;
			_g_object_unref0 (obj);
		}
		_g_object_unref0 (_obj_it);
	}
	result = _g_object_ref0 ((GeeList*) ((GeeArrayList*) _result_->data));
	_g_object_unref0 (_result_);
	return result;
}


static void rygel_media_db_container_real_find_object (RygelMediaContainer* base, const char* id, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target) {
	RygelMediaDBContainer * self;
	GError * _inner_error_;
	RygelSimpleAsyncResult* res;
	RygelMediaObject* _tmp0_;
	RygelMediaObject* _tmp1_;
	self = (RygelMediaDBContainer*) base;
	g_return_if_fail (id != NULL);
	_inner_error_ = NULL;
	res = rygel_simple_async_result_new (RYGEL_TYPE_MEDIA_OBJECT, (GBoxedCopyFunc) g_object_ref, g_object_unref, (GObject*) self, callback, callback_target);
	_tmp0_ = rygel_media_db_get_object (self->media_db, id, &_inner_error_);
	if (_inner_error_ != NULL) {
		_g_object_unref0 (res);
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return;
	}
	res->data = (_tmp1_ = _tmp0_, _g_object_unref0 (res->data), _tmp1_);
	rygel_simple_async_result_complete_in_idle (res);
	_g_object_unref0 (res);
}


static RygelMediaObject* rygel_media_db_container_real_find_object_finish (RygelMediaContainer* base, GAsyncResult* res, GError** error) {
	RygelMediaDBContainer * self;
	RygelMediaObject* result;
	self = (RygelMediaDBContainer*) base;
	g_return_val_if_fail (res != NULL, NULL);
	result = _g_object_ref0 ((RygelMediaObject*) RYGEL_SIMPLE_ASYNC_RESULT (res)->data);
	return result;
}


static void rygel_media_db_container_class_init (RygelMediaDBContainerClass * klass) {
	rygel_media_db_container_parent_class = g_type_class_peek_parent (klass);
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->get_children = rygel_media_db_container_real_get_children;
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->get_children_finish = rygel_media_db_container_real_get_children_finish;
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->find_object = rygel_media_db_container_real_find_object;
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->find_object_finish = rygel_media_db_container_real_find_object_finish;
	G_OBJECT_CLASS (klass)->finalize = rygel_media_db_container_finalize;
}


static void rygel_media_db_container_instance_init (RygelMediaDBContainer * self) {
}


static void rygel_media_db_container_finalize (GObject* obj) {
	RygelMediaDBContainer * self;
	self = RYGEL_MEDIA_DB_CONTAINER (obj);
	_g_object_unref0 (self->media_db);
	G_OBJECT_CLASS (rygel_media_db_container_parent_class)->finalize (obj);
}


GType rygel_media_db_container_get_type (void) {
	static GType rygel_media_db_container_type_id = 0;
	if (rygel_media_db_container_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediaDBContainerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_media_db_container_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediaDBContainer), 0, (GInstanceInitFunc) rygel_media_db_container_instance_init, NULL };
		rygel_media_db_container_type_id = g_type_register_static (RYGEL_TYPE_MEDIA_CONTAINER, "RygelMediaDBContainer", &g_define_type_info, 0);
	}
	return rygel_media_db_container_type_id;
}




