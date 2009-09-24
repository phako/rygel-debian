/*
 * Copyright (C) 2009 Thijs Vermeir <thijsvermeir@gmail.com>
 *
 * Author: Thijs Vermeir <thijsvermeir@gmail.com>
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
#include <gee.h>
#include <stdlib.h>
#include <string.h>


#define RYGEL_TYPE_GST_LAUNCH_ROOT_CONTAINER (rygel_gst_launch_root_container_get_type ())
#define RYGEL_GST_LAUNCH_ROOT_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_GST_LAUNCH_ROOT_CONTAINER, RygelGstLaunchRootContainer))
#define RYGEL_GST_LAUNCH_ROOT_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_GST_LAUNCH_ROOT_CONTAINER, RygelGstLaunchRootContainerClass))
#define RYGEL_IS_GST_LAUNCH_ROOT_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_GST_LAUNCH_ROOT_CONTAINER))
#define RYGEL_IS_GST_LAUNCH_ROOT_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_GST_LAUNCH_ROOT_CONTAINER))
#define RYGEL_GST_LAUNCH_ROOT_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_GST_LAUNCH_ROOT_CONTAINER, RygelGstLaunchRootContainerClass))

typedef struct _RygelGstLaunchRootContainer RygelGstLaunchRootContainer;
typedef struct _RygelGstLaunchRootContainerClass RygelGstLaunchRootContainerClass;
typedef struct _RygelGstLaunchRootContainerPrivate RygelGstLaunchRootContainerPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

#define RYGEL_TYPE_GST_LAUNCH_ITEM (rygel_gst_launch_item_get_type ())
#define RYGEL_GST_LAUNCH_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_GST_LAUNCH_ITEM, RygelGstLaunchItem))
#define RYGEL_GST_LAUNCH_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_GST_LAUNCH_ITEM, RygelGstLaunchItemClass))
#define RYGEL_IS_GST_LAUNCH_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_GST_LAUNCH_ITEM))
#define RYGEL_IS_GST_LAUNCH_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_GST_LAUNCH_ITEM))
#define RYGEL_GST_LAUNCH_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_GST_LAUNCH_ITEM, RygelGstLaunchItemClass))

typedef struct _RygelGstLaunchItem RygelGstLaunchItem;
typedef struct _RygelGstLaunchItemClass RygelGstLaunchItemClass;

struct _RygelGstLaunchRootContainer {
	RygelSimpleContainer parent_instance;
	RygelGstLaunchRootContainerPrivate * priv;
};

struct _RygelGstLaunchRootContainerClass {
	RygelSimpleContainerClass parent_class;
};

struct _RygelGstLaunchRootContainerPrivate {
	RygelMetaConfig* config;
};


static gpointer rygel_gst_launch_root_container_parent_class = NULL;

GType rygel_gst_launch_root_container_get_type (void);
#define RYGEL_GST_LAUNCH_ROOT_CONTAINER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_GST_LAUNCH_ROOT_CONTAINER, RygelGstLaunchRootContainerPrivate))
enum  {
	RYGEL_GST_LAUNCH_ROOT_CONTAINER_DUMMY_PROPERTY
};
#define RYGEL_GST_LAUNCH_ROOT_CONTAINER_CONFIG_GROUP "GstLaunch"
#define RYGEL_GST_LAUNCH_ROOT_CONTAINER_ITEM_NAMES "launch_items"
static void rygel_gst_launch_root_container_add_launch_item (RygelGstLaunchRootContainer* self, const char* name);
RygelGstLaunchRootContainer* rygel_gst_launch_root_container_new (const char* title);
RygelGstLaunchRootContainer* rygel_gst_launch_root_container_construct (GType object_type, const char* title);
RygelGstLaunchItem* rygel_gst_launch_item_new (const char* id, RygelMediaContainer* parent, const char* title, const char* mime_type, const char* launch_line);
RygelGstLaunchItem* rygel_gst_launch_item_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title, const char* mime_type, const char* launch_line);
GType rygel_gst_launch_item_get_type (void);
static void rygel_gst_launch_root_container_finalize (GObject* obj);



RygelGstLaunchRootContainer* rygel_gst_launch_root_container_construct (GType object_type, const char* title) {
	GError * _inner_error_;
	RygelGstLaunchRootContainer * self;
	g_return_val_if_fail (title != NULL, NULL);
	_inner_error_ = NULL;
	self = (RygelGstLaunchRootContainer*) rygel_simple_container_construct_root (object_type, title);
	{
		RygelMetaConfig* _tmp0_;
		GeeArrayList* item_names;
		self->priv->config = (_tmp0_ = rygel_meta_config_get_default (), _g_object_unref0 (self->priv->config), _tmp0_);
		item_names = rygel_configuration_get_string_list ((RygelConfiguration*) self->priv->config, RYGEL_GST_LAUNCH_ROOT_CONTAINER_CONFIG_GROUP, RYGEL_GST_LAUNCH_ROOT_CONTAINER_ITEM_NAMES, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch0_g_error;
			goto __finally0;
		}
		{
			GeeIterator* _name_it;
			_name_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) item_names);
			while (TRUE) {
				char* name;
				if (!gee_iterator_next (_name_it)) {
					break;
				}
				name = (char*) gee_iterator_get (_name_it);
				rygel_gst_launch_root_container_add_launch_item (self, name);
				_g_free0 (name);
			}
			_g_object_unref0 (_name_it);
		}
		_g_object_unref0 (item_names);
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			g_debug ("rygel-gstlaunch-root-container.vala:49: GstLaunch init failed: %s", err->message);
			_g_error_free0 (err);
		}
	}
	__finally0:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	return self;
}


RygelGstLaunchRootContainer* rygel_gst_launch_root_container_new (const char* title) {
	return rygel_gst_launch_root_container_construct (RYGEL_TYPE_GST_LAUNCH_ROOT_CONTAINER, title);
}


static void rygel_gst_launch_root_container_add_launch_item (RygelGstLaunchRootContainer* self, const char* name) {
	GError * _inner_error_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (name != NULL);
	_inner_error_ = NULL;
	{
		char* _tmp0_;
		char* _tmp1_;
		char* title;
		char* _tmp2_;
		char* _tmp3_;
		char* mime_type;
		char* _tmp4_;
		char* _tmp5_;
		char* launch_line;
		RygelGstLaunchItem* _tmp6_;
		title = (_tmp1_ = rygel_configuration_get_string ((RygelConfiguration*) self->priv->config, RYGEL_GST_LAUNCH_ROOT_CONTAINER_CONFIG_GROUP, _tmp0_ = g_strdup_printf ("%s_title", name), &_inner_error_), _g_free0 (_tmp0_), _tmp1_);
		if (_inner_error_ != NULL) {
			goto __catch1_g_error;
			goto __finally1;
		}
		mime_type = (_tmp3_ = rygel_configuration_get_string ((RygelConfiguration*) self->priv->config, RYGEL_GST_LAUNCH_ROOT_CONTAINER_CONFIG_GROUP, _tmp2_ = g_strdup_printf ("%s_mime", name), &_inner_error_), _g_free0 (_tmp2_), _tmp3_);
		if (_inner_error_ != NULL) {
			_g_free0 (title);
			goto __catch1_g_error;
			goto __finally1;
		}
		launch_line = (_tmp5_ = rygel_configuration_get_string ((RygelConfiguration*) self->priv->config, RYGEL_GST_LAUNCH_ROOT_CONTAINER_CONFIG_GROUP, _tmp4_ = g_strdup_printf ("%s_launch", name), &_inner_error_), _g_free0 (_tmp4_), _tmp5_);
		if (_inner_error_ != NULL) {
			_g_free0 (title);
			_g_free0 (mime_type);
			goto __catch1_g_error;
			goto __finally1;
		}
		rygel_simple_container_add_child ((RygelSimpleContainer*) self, (RygelMediaObject*) (_tmp6_ = rygel_gst_launch_item_new (name, (RygelMediaContainer*) self, title, mime_type, launch_line)));
		_g_object_unref0 (_tmp6_);
		_g_free0 (title);
		_g_free0 (mime_type);
		_g_free0 (launch_line);
	}
	goto __finally1;
	__catch1_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			g_debug ("rygel-gstlaunch-root-container.vala:68: GstLaunch failed item '%s': %s", name, err->message);
			_g_error_free0 (err);
		}
	}
	__finally1:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return;
	}
}


static void rygel_gst_launch_root_container_class_init (RygelGstLaunchRootContainerClass * klass) {
	rygel_gst_launch_root_container_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelGstLaunchRootContainerPrivate));
	G_OBJECT_CLASS (klass)->finalize = rygel_gst_launch_root_container_finalize;
}


static void rygel_gst_launch_root_container_instance_init (RygelGstLaunchRootContainer * self) {
	self->priv = RYGEL_GST_LAUNCH_ROOT_CONTAINER_GET_PRIVATE (self);
}


static void rygel_gst_launch_root_container_finalize (GObject* obj) {
	RygelGstLaunchRootContainer * self;
	self = RYGEL_GST_LAUNCH_ROOT_CONTAINER (obj);
	_g_object_unref0 (self->priv->config);
	G_OBJECT_CLASS (rygel_gst_launch_root_container_parent_class)->finalize (obj);
}


GType rygel_gst_launch_root_container_get_type (void) {
	static GType rygel_gst_launch_root_container_type_id = 0;
	if (rygel_gst_launch_root_container_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelGstLaunchRootContainerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_gst_launch_root_container_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelGstLaunchRootContainer), 0, (GInstanceInitFunc) rygel_gst_launch_root_container_instance_init, NULL };
		rygel_gst_launch_root_container_type_id = g_type_register_static (RYGEL_TYPE_SIMPLE_CONTAINER, "RygelGstLaunchRootContainer", &g_define_type_info, 0);
	}
	return rygel_gst_launch_root_container_type_id;
}




