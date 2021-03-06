/* rygel-external-dummy-container.c generated by valac, the Vala compiler
 * generated from rygel-external-dummy-container.vala, do not modify */

/*
 * Copyright (C) 2009,2010 Jens Georg <mail@jensge.org>.
 * Copyright (C) 2010 Nokia Corporation.
 *
 * Author: Jens Georg <mail@jensge.org>
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
#include <gio/gio.h>


#define RYGEL_EXTERNAL_TYPE_DUMMY_CONTAINER (rygel_external_dummy_container_get_type ())
#define RYGEL_EXTERNAL_DUMMY_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_EXTERNAL_TYPE_DUMMY_CONTAINER, RygelExternalDummyContainer))
#define RYGEL_EXTERNAL_DUMMY_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_EXTERNAL_TYPE_DUMMY_CONTAINER, RygelExternalDummyContainerClass))
#define RYGEL_EXTERNAL_IS_DUMMY_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_EXTERNAL_TYPE_DUMMY_CONTAINER))
#define RYGEL_EXTERNAL_IS_DUMMY_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_EXTERNAL_TYPE_DUMMY_CONTAINER))
#define RYGEL_EXTERNAL_DUMMY_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_EXTERNAL_TYPE_DUMMY_CONTAINER, RygelExternalDummyContainerClass))

typedef struct _RygelExternalDummyContainer RygelExternalDummyContainer;
typedef struct _RygelExternalDummyContainerClass RygelExternalDummyContainerClass;
typedef struct _RygelExternalDummyContainerPrivate RygelExternalDummyContainerPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _RygelExternalDummyContainerGetChildrenData RygelExternalDummyContainerGetChildrenData;

struct _RygelExternalDummyContainer {
	RygelMediaContainer parent_instance;
	RygelExternalDummyContainerPrivate * priv;
};

struct _RygelExternalDummyContainerClass {
	RygelMediaContainerClass parent_class;
};

struct _RygelExternalDummyContainerGetChildrenData {
	int _state_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	RygelExternalDummyContainer* self;
	guint offset;
	guint max_count;
	GCancellable* cancellable;
	RygelMediaObjects* result;
};


static gpointer rygel_external_dummy_container_parent_class = NULL;

GType rygel_external_dummy_container_get_type (void) G_GNUC_CONST;
enum  {
	RYGEL_EXTERNAL_DUMMY_CONTAINER_DUMMY_PROPERTY
};
RygelExternalDummyContainer* rygel_external_dummy_container_new (const char* id, const char* title, guint child_coult, RygelMediaContainer* parent);
RygelExternalDummyContainer* rygel_external_dummy_container_construct (GType object_type, const char* id, const char* title, guint child_coult, RygelMediaContainer* parent);
static void rygel_external_dummy_container_real_get_children_data_free (gpointer _data);
static void rygel_external_dummy_container_real_get_children (RygelMediaContainer* base, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
static void rygel_external_dummy_container_get_children_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static gboolean rygel_external_dummy_container_real_get_children_co (RygelExternalDummyContainerGetChildrenData* data);



#line 34 "rygel-external-dummy-container.vala"
RygelExternalDummyContainer* rygel_external_dummy_container_construct (GType object_type, const char* id, const char* title, guint child_coult, RygelMediaContainer* parent) {
#line 89 "rygel-external-dummy-container.c"
	RygelExternalDummyContainer * self;
#line 34 "rygel-external-dummy-container.vala"
	g_return_val_if_fail (id != NULL, NULL);
#line 34 "rygel-external-dummy-container.vala"
	g_return_val_if_fail (title != NULL, NULL);
#line 38 "rygel-external-dummy-container.vala"
	self = (RygelExternalDummyContainer*) rygel_media_container_construct (object_type, id, parent, title, ((RygelMediaContainer*) self)->child_count);
#line 97 "rygel-external-dummy-container.c"
	return self;
}


#line 34 "rygel-external-dummy-container.vala"
RygelExternalDummyContainer* rygel_external_dummy_container_new (const char* id, const char* title, guint child_coult, RygelMediaContainer* parent) {
#line 34 "rygel-external-dummy-container.vala"
	return rygel_external_dummy_container_construct (RYGEL_EXTERNAL_TYPE_DUMMY_CONTAINER, id, title, child_coult, parent);
#line 106 "rygel-external-dummy-container.c"
}


static void rygel_external_dummy_container_real_get_children_data_free (gpointer _data) {
	RygelExternalDummyContainerGetChildrenData* data;
	data = _data;
	_g_object_unref0 (data->cancellable);
	_g_object_unref0 (data->result);
	g_object_unref (data->self);
	g_slice_free (RygelExternalDummyContainerGetChildrenData, data);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void rygel_external_dummy_container_real_get_children (RygelMediaContainer* base, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	RygelExternalDummyContainer * self;
	RygelExternalDummyContainerGetChildrenData* _data_;
	self = (RygelExternalDummyContainer*) base;
	_data_ = g_slice_new0 (RygelExternalDummyContainerGetChildrenData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, rygel_external_dummy_container_real_get_children);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, rygel_external_dummy_container_real_get_children_data_free);
	_data_->self = g_object_ref (self);
	_data_->offset = offset;
	_data_->max_count = max_count;
	_data_->cancellable = _g_object_ref0 (cancellable);
	rygel_external_dummy_container_real_get_children_co (_data_);
}


static RygelMediaObjects* rygel_external_dummy_container_real_get_children_finish (RygelMediaContainer* base, GAsyncResult* _res_, GError** error) {
	RygelMediaObjects* result;
	RygelExternalDummyContainerGetChildrenData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return NULL;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	_data_->result = NULL;
	return result;
}


static void rygel_external_dummy_container_get_children_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	RygelExternalDummyContainerGetChildrenData* data;
	data = _user_data_;
	data->_res_ = _res_;
	rygel_external_dummy_container_real_get_children_co (data);
}


static gboolean rygel_external_dummy_container_real_get_children_co (RygelExternalDummyContainerGetChildrenData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	{
		data->result = rygel_media_objects_new ();
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


static void rygel_external_dummy_container_class_init (RygelExternalDummyContainerClass * klass) {
	rygel_external_dummy_container_parent_class = g_type_class_peek_parent (klass);
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->get_children = rygel_external_dummy_container_real_get_children;
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->get_children_finish = rygel_external_dummy_container_real_get_children_finish;
}


static void rygel_external_dummy_container_instance_init (RygelExternalDummyContainer * self) {
}


GType rygel_external_dummy_container_get_type (void) {
	static volatile gsize rygel_external_dummy_container_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_external_dummy_container_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelExternalDummyContainerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_external_dummy_container_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelExternalDummyContainer), 0, (GInstanceInitFunc) rygel_external_dummy_container_instance_init, NULL };
		GType rygel_external_dummy_container_type_id;
		rygel_external_dummy_container_type_id = g_type_register_static (RYGEL_TYPE_MEDIA_CONTAINER, "RygelExternalDummyContainer", &g_define_type_info, 0);
		g_once_init_leave (&rygel_external_dummy_container_type_id__volatile, rygel_external_dummy_container_type_id);
	}
	return rygel_external_dummy_container_type_id__volatile;
}




