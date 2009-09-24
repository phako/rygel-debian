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
#include <libgupnp/gupnp.h>
#include <stdlib.h>
#include <string.h>


#define RYGEL_TYPE_GST_LAUNCH_CONTENT_DIR (rygel_gst_launch_content_dir_get_type ())
#define RYGEL_GST_LAUNCH_CONTENT_DIR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_GST_LAUNCH_CONTENT_DIR, RygelGstLaunchContentDir))
#define RYGEL_GST_LAUNCH_CONTENT_DIR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_GST_LAUNCH_CONTENT_DIR, RygelGstLaunchContentDirClass))
#define RYGEL_IS_GST_LAUNCH_CONTENT_DIR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_GST_LAUNCH_CONTENT_DIR))
#define RYGEL_IS_GST_LAUNCH_CONTENT_DIR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_GST_LAUNCH_CONTENT_DIR))
#define RYGEL_GST_LAUNCH_CONTENT_DIR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_GST_LAUNCH_CONTENT_DIR, RygelGstLaunchContentDirClass))

typedef struct _RygelGstLaunchContentDir RygelGstLaunchContentDir;
typedef struct _RygelGstLaunchContentDirClass RygelGstLaunchContentDirClass;
typedef struct _RygelGstLaunchContentDirPrivate RygelGstLaunchContentDirPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define RYGEL_TYPE_GST_LAUNCH_ROOT_CONTAINER (rygel_gst_launch_root_container_get_type ())
#define RYGEL_GST_LAUNCH_ROOT_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_GST_LAUNCH_ROOT_CONTAINER, RygelGstLaunchRootContainer))
#define RYGEL_GST_LAUNCH_ROOT_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_GST_LAUNCH_ROOT_CONTAINER, RygelGstLaunchRootContainerClass))
#define RYGEL_IS_GST_LAUNCH_ROOT_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_GST_LAUNCH_ROOT_CONTAINER))
#define RYGEL_IS_GST_LAUNCH_ROOT_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_GST_LAUNCH_ROOT_CONTAINER))
#define RYGEL_GST_LAUNCH_ROOT_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_GST_LAUNCH_ROOT_CONTAINER, RygelGstLaunchRootContainerClass))

typedef struct _RygelGstLaunchRootContainer RygelGstLaunchRootContainer;
typedef struct _RygelGstLaunchRootContainerClass RygelGstLaunchRootContainerClass;
#define _g_free0(var) (var = (g_free (var), NULL))

struct _RygelGstLaunchContentDir {
	RygelContentDirectory parent_instance;
	RygelGstLaunchContentDirPrivate * priv;
};

struct _RygelGstLaunchContentDirClass {
	RygelContentDirectoryClass parent_class;
};


static gpointer rygel_gst_launch_content_dir_parent_class = NULL;

GType rygel_gst_launch_content_dir_get_type (void);
enum  {
	RYGEL_GST_LAUNCH_CONTENT_DIR_DUMMY_PROPERTY
};
RygelGstLaunchRootContainer* rygel_gst_launch_root_container_new (const char* title);
RygelGstLaunchRootContainer* rygel_gst_launch_root_container_construct (GType object_type, const char* title);
GType rygel_gst_launch_root_container_get_type (void);
static RygelMediaContainer* rygel_gst_launch_content_dir_real_create_root_container (RygelContentDirectory* base);
RygelGstLaunchContentDir* rygel_gst_launch_content_dir_new (void);
RygelGstLaunchContentDir* rygel_gst_launch_content_dir_construct (GType object_type);



static RygelMediaContainer* rygel_gst_launch_content_dir_real_create_root_container (RygelContentDirectory* base) {
	RygelGstLaunchContentDir * self;
	RygelMediaContainer* result;
	GUPnPRootDevice* _tmp1_;
	GUPnPRootDevice* _tmp0_;
	char* _tmp2_;
	char* friendly_name;
	self = (RygelGstLaunchContentDir*) base;
	_tmp0_ = NULL;
	friendly_name = (_tmp2_ = gupnp_device_info_get_friendly_name ((GUPnPDeviceInfo*) (_tmp1_ = (g_object_get ((GUPnPService*) self, "root-device", &_tmp0_, NULL), _tmp0_))), _g_object_unref0 (_tmp1_), _tmp2_);
	result = (RygelMediaContainer*) rygel_gst_launch_root_container_new (friendly_name);
	_g_free0 (friendly_name);
	return result;
}


RygelGstLaunchContentDir* rygel_gst_launch_content_dir_construct (GType object_type) {
	RygelGstLaunchContentDir * self;
	self = (RygelGstLaunchContentDir*) rygel_content_directory_construct (object_type);
	return self;
}


RygelGstLaunchContentDir* rygel_gst_launch_content_dir_new (void) {
	return rygel_gst_launch_content_dir_construct (RYGEL_TYPE_GST_LAUNCH_CONTENT_DIR);
}


static void rygel_gst_launch_content_dir_class_init (RygelGstLaunchContentDirClass * klass) {
	rygel_gst_launch_content_dir_parent_class = g_type_class_peek_parent (klass);
	RYGEL_CONTENT_DIRECTORY_CLASS (klass)->create_root_container = rygel_gst_launch_content_dir_real_create_root_container;
}


static void rygel_gst_launch_content_dir_instance_init (RygelGstLaunchContentDir * self) {
}


GType rygel_gst_launch_content_dir_get_type (void) {
	static GType rygel_gst_launch_content_dir_type_id = 0;
	if (rygel_gst_launch_content_dir_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelGstLaunchContentDirClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_gst_launch_content_dir_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelGstLaunchContentDir), 0, (GInstanceInitFunc) rygel_gst_launch_content_dir_instance_init, NULL };
		rygel_gst_launch_content_dir_type_id = g_type_register_static (RYGEL_TYPE_CONTENT_DIRECTORY, "RygelGstLaunchContentDir", &g_define_type_info, 0);
	}
	return rygel_gst_launch_content_dir_type_id;
}



