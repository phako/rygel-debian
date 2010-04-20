/* rygel-simple-container.c generated by valac, the Vala compiler
 * generated from rygel-simple-container.vala, do not modify */

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

#define RYGEL_TYPE_SEARCH_EXPRESSION (rygel_search_expression_get_type ())
#define RYGEL_SEARCH_EXPRESSION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_SEARCH_EXPRESSION, RygelSearchExpression))
#define RYGEL_SEARCH_EXPRESSION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_SEARCH_EXPRESSION, RygelSearchExpressionClass))
#define RYGEL_IS_SEARCH_EXPRESSION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_SEARCH_EXPRESSION))
#define RYGEL_IS_SEARCH_EXPRESSION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_SEARCH_EXPRESSION))
#define RYGEL_SEARCH_EXPRESSION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_SEARCH_EXPRESSION, RygelSearchExpressionClass))

typedef struct _RygelSearchExpression RygelSearchExpression;
typedef struct _RygelSearchExpressionClass RygelSearchExpressionClass;

#define RYGEL_TYPE_MEDIA_ITEM (rygel_media_item_get_type ())
#define RYGEL_MEDIA_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_ITEM, RygelMediaItem))
#define RYGEL_MEDIA_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_ITEM, RygelMediaItemClass))
#define RYGEL_IS_MEDIA_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_ITEM))
#define RYGEL_IS_MEDIA_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_ITEM))
#define RYGEL_MEDIA_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_ITEM, RygelMediaItemClass))

typedef struct _RygelMediaItem RygelMediaItem;
typedef struct _RygelMediaItemClass RygelMediaItemClass;

#define RYGEL_TYPE_SIMPLE_CONTAINER (rygel_simple_container_get_type ())
#define RYGEL_SIMPLE_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_SIMPLE_CONTAINER, RygelSimpleContainer))
#define RYGEL_SIMPLE_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_SIMPLE_CONTAINER, RygelSimpleContainerClass))
#define RYGEL_IS_SIMPLE_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_SIMPLE_CONTAINER))
#define RYGEL_IS_SIMPLE_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_SIMPLE_CONTAINER))
#define RYGEL_SIMPLE_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_SIMPLE_CONTAINER, RygelSimpleContainerClass))

typedef struct _RygelSimpleContainer RygelSimpleContainer;
typedef struct _RygelSimpleContainerClass RygelSimpleContainerClass;
typedef struct _RygelSimpleContainerPrivate RygelSimpleContainerPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _RygelSimpleContainerGetChildrenData RygelSimpleContainerGetChildrenData;

struct _RygelMediaObject {
	GObject parent_instance;
	RygelMediaObjectPrivate * priv;
	char* id;
	char* upnp_class;
	guint64 modified;
	GeeArrayList* uris;
	RygelMediaContainer* parent;
};

struct _RygelMediaObjectClass {
	GObjectClass parent_class;
};

struct _RygelMediaContainer {
	RygelMediaObject parent_instance;
	RygelMediaContainerPrivate * priv;
	gint child_count;
	guint32 update_id;
};

struct _RygelMediaContainerClass {
	RygelMediaObjectClass parent_class;
	void (*get_children) (RygelMediaContainer* self, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
	GeeList* (*get_children_finish) (RygelMediaContainer* self, GAsyncResult* _res_, GError** error);
	void (*search) (RygelMediaContainer* self, RygelSearchExpression* expression, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
	GeeList* (*search_finish) (RygelMediaContainer* self, GAsyncResult* _res_, guint* total_matches, GError** error);
	void (*add_item) (RygelMediaContainer* self, RygelMediaItem* item, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
	void (*add_item_finish) (RygelMediaContainer* self, GAsyncResult* _res_, GError** error);
};

struct _RygelSimpleContainer {
	RygelMediaContainer parent_instance;
	RygelSimpleContainerPrivate * priv;
	GeeArrayList* children;
};

struct _RygelSimpleContainerClass {
	RygelMediaContainerClass parent_class;
};

struct _RygelSimpleContainerGetChildrenData {
	int _state_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	RygelSimpleContainer* self;
	guint offset;
	guint max_count;
	GCancellable* cancellable;
	GeeList* result;
	guint stop;
};


static gpointer rygel_simple_container_parent_class = NULL;

GType rygel_media_object_get_type (void);
GType rygel_media_container_get_type (void);
gpointer rygel_search_expression_ref (gpointer instance);
void rygel_search_expression_unref (gpointer instance);
GParamSpec* rygel_param_spec_search_expression (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_search_expression (GValue* value, gpointer v_object);
void rygel_value_take_search_expression (GValue* value, gpointer v_object);
gpointer rygel_value_get_search_expression (const GValue* value);
GType rygel_search_expression_get_type (void);
GType rygel_media_item_get_type (void);
GType rygel_simple_container_get_type (void);
enum  {
	RYGEL_SIMPLE_CONTAINER_DUMMY_PROPERTY
};
RygelMediaContainer* rygel_media_container_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title, gint child_count);
RygelSimpleContainer* rygel_simple_container_new (const char* id, RygelMediaContainer* parent, const char* title);
RygelSimpleContainer* rygel_simple_container_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title);
RygelSimpleContainer* rygel_simple_container_new_root (const char* title);
RygelSimpleContainer* rygel_simple_container_construct_root (GType object_type, const char* title);
void rygel_simple_container_add_child (RygelSimpleContainer* self, RygelMediaObject* child);
void rygel_simple_container_remove_child (RygelSimpleContainer* self, RygelMediaObject* child);
void rygel_simple_container_clear (RygelSimpleContainer* self);
static void rygel_simple_container_real_get_children_data_free (gpointer _data);
static void rygel_simple_container_real_get_children (RygelMediaContainer* base, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
static void rygel_simple_container_get_children_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static gboolean rygel_simple_container_real_get_children_co (RygelSimpleContainerGetChildrenData* data);
static void rygel_simple_container_finalize (GObject* obj);



#line 35 "rygel-simple-container.vala"
RygelSimpleContainer* rygel_simple_container_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title) {
#line 180 "rygel-simple-container.c"
	RygelSimpleContainer * self;
	GeeArrayList* _tmp0_;
#line 35 "rygel-simple-container.vala"
	g_return_val_if_fail (id != NULL, NULL);
#line 35 "rygel-simple-container.vala"
	g_return_val_if_fail (title != NULL, NULL);
#line 38 "rygel-simple-container.vala"
	self = (RygelSimpleContainer*) rygel_media_container_construct (object_type, id, parent, title, 0);
#line 40 "rygel-simple-container.vala"
	self->children = (_tmp0_ = gee_array_list_new (RYGEL_TYPE_MEDIA_OBJECT, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL), _g_object_unref0 (self->children), _tmp0_);
#line 191 "rygel-simple-container.c"
	return self;
}


#line 35 "rygel-simple-container.vala"
RygelSimpleContainer* rygel_simple_container_new (const char* id, RygelMediaContainer* parent, const char* title) {
#line 35 "rygel-simple-container.vala"
	return rygel_simple_container_construct (RYGEL_TYPE_SIMPLE_CONTAINER, id, parent, title);
#line 200 "rygel-simple-container.c"
}


#line 43 "rygel-simple-container.vala"
RygelSimpleContainer* rygel_simple_container_construct_root (GType object_type, const char* title) {
#line 206 "rygel-simple-container.c"
	RygelSimpleContainer * self;
#line 43 "rygel-simple-container.vala"
	g_return_val_if_fail (title != NULL, NULL);
#line 44 "rygel-simple-container.vala"
	self = (RygelSimpleContainer*) rygel_simple_container_construct (object_type, "0", NULL, title);
#line 212 "rygel-simple-container.c"
	return self;
}


#line 43 "rygel-simple-container.vala"
RygelSimpleContainer* rygel_simple_container_new_root (const char* title) {
#line 43 "rygel-simple-container.vala"
	return rygel_simple_container_construct_root (RYGEL_TYPE_SIMPLE_CONTAINER, title);
#line 221 "rygel-simple-container.c"
}


#line 47 "rygel-simple-container.vala"
void rygel_simple_container_add_child (RygelSimpleContainer* self, RygelMediaObject* child) {
#line 47 "rygel-simple-container.vala"
	g_return_if_fail (self != NULL);
#line 47 "rygel-simple-container.vala"
	g_return_if_fail (child != NULL);
#line 48 "rygel-simple-container.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) self->children, child);
#line 50 "rygel-simple-container.vala"
	((RygelMediaContainer*) self)->child_count++;
#line 235 "rygel-simple-container.c"
}


#line 53 "rygel-simple-container.vala"
void rygel_simple_container_remove_child (RygelSimpleContainer* self, RygelMediaObject* child) {
#line 53 "rygel-simple-container.vala"
	g_return_if_fail (self != NULL);
#line 53 "rygel-simple-container.vala"
	g_return_if_fail (child != NULL);
#line 54 "rygel-simple-container.vala"
	gee_abstract_collection_remove ((GeeAbstractCollection*) self->children, child);
#line 56 "rygel-simple-container.vala"
	((RygelMediaContainer*) self)->child_count--;
#line 249 "rygel-simple-container.c"
}


#line 59 "rygel-simple-container.vala"
void rygel_simple_container_clear (RygelSimpleContainer* self) {
#line 59 "rygel-simple-container.vala"
	g_return_if_fail (self != NULL);
#line 60 "rygel-simple-container.vala"
	gee_abstract_collection_clear ((GeeAbstractCollection*) self->children);
#line 62 "rygel-simple-container.vala"
	((RygelMediaContainer*) self)->child_count = 0;
#line 261 "rygel-simple-container.c"
}


static void rygel_simple_container_real_get_children_data_free (gpointer _data) {
	RygelSimpleContainerGetChildrenData* data;
	data = _data;
	_g_object_unref0 (data->cancellable);
	_g_object_unref0 (data->result);
	g_object_unref (data->self);
	g_slice_free (RygelSimpleContainerGetChildrenData, data);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void rygel_simple_container_real_get_children (RygelMediaContainer* base, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	RygelSimpleContainer * self;
	RygelSimpleContainerGetChildrenData* _data_;
	self = (RygelSimpleContainer*) base;
	_data_ = g_slice_new0 (RygelSimpleContainerGetChildrenData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, rygel_simple_container_real_get_children);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, rygel_simple_container_real_get_children_data_free);
	_data_->self = g_object_ref (self);
	_data_->offset = offset;
	_data_->max_count = max_count;
	_data_->cancellable = _g_object_ref0 (cancellable);
	rygel_simple_container_real_get_children_co (_data_);
}


static GeeList* rygel_simple_container_real_get_children_finish (RygelMediaContainer* base, GAsyncResult* _res_, GError** error) {
	GeeList* result;
	RygelSimpleContainerGetChildrenData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return NULL;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	_data_->result = NULL;
	return result;
}


static void rygel_simple_container_get_children_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	RygelSimpleContainerGetChildrenData* data;
	data = _user_data_;
	data->_res_ = _res_;
	rygel_simple_container_real_get_children_co (data);
}


static gboolean rygel_simple_container_real_get_children_co (RygelSimpleContainerGetChildrenData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	{
		data->stop = data->offset + data->max_count;
#line 71 "rygel-simple-container.vala"
		data->stop = CLAMP (data->stop, (guint) 0, (guint) ((RygelMediaContainer*) data->self)->child_count);
#line 328 "rygel-simple-container.c"
		data->result = gee_abstract_list_slice ((GeeAbstractList*) data->self->children, (gint) data->offset, (gint) data->stop);
		{
			if (data->_state_ == 0) {
				g_simple_async_result_complete_in_idle (data->_async_result);
			} else {
				g_simple_async_result_complete (data->_async_result);
			}
			g_object_unref (data->_async_result);
			return FALSE;
		}
	}
	{
		if (data->_state_ == 0) {
			g_simple_async_result_complete_in_idle (data->_async_result);
		} else {
			g_simple_async_result_complete (data->_async_result);
		}
		g_object_unref (data->_async_result);
		return FALSE;
	}
}


static void rygel_simple_container_class_init (RygelSimpleContainerClass * klass) {
	rygel_simple_container_parent_class = g_type_class_peek_parent (klass);
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->get_children = rygel_simple_container_real_get_children;
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->get_children_finish = rygel_simple_container_real_get_children_finish;
	G_OBJECT_CLASS (klass)->finalize = rygel_simple_container_finalize;
}


static void rygel_simple_container_instance_init (RygelSimpleContainer * self) {
}


static void rygel_simple_container_finalize (GObject* obj) {
	RygelSimpleContainer * self;
	self = RYGEL_SIMPLE_CONTAINER (obj);
	_g_object_unref0 (self->children);
	G_OBJECT_CLASS (rygel_simple_container_parent_class)->finalize (obj);
}


GType rygel_simple_container_get_type (void) {
	static volatile gsize rygel_simple_container_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_simple_container_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelSimpleContainerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_simple_container_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelSimpleContainer), 0, (GInstanceInitFunc) rygel_simple_container_instance_init, NULL };
		GType rygel_simple_container_type_id;
		rygel_simple_container_type_id = g_type_register_static (RYGEL_TYPE_MEDIA_CONTAINER, "RygelSimpleContainer", &g_define_type_info, 0);
		g_once_init_leave (&rygel_simple_container_type_id__volatile, rygel_simple_container_type_id);
	}
	return rygel_simple_container_type_id__volatile;
}




