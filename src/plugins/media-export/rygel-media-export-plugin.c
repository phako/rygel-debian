/*
 * Copyright (C) 2008-2009 Jens Georg <mail@jensge.org>.
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


#define RYGEL_TYPE_MEDIA_EXPORT_CONTENT_DIR (rygel_media_export_content_dir_get_type ())
#define RYGEL_MEDIA_EXPORT_CONTENT_DIR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_EXPORT_CONTENT_DIR, RygelMediaExportContentDir))
#define RYGEL_MEDIA_EXPORT_CONTENT_DIR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_EXPORT_CONTENT_DIR, RygelMediaExportContentDirClass))
#define RYGEL_IS_MEDIA_EXPORT_CONTENT_DIR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_EXPORT_CONTENT_DIR))
#define RYGEL_IS_MEDIA_EXPORT_CONTENT_DIR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_EXPORT_CONTENT_DIR))
#define RYGEL_MEDIA_EXPORT_CONTENT_DIR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_EXPORT_CONTENT_DIR, RygelMediaExportContentDirClass))

typedef struct _RygelMediaExportContentDir RygelMediaExportContentDir;
typedef struct _RygelMediaExportContentDirClass RygelMediaExportContentDirClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _rygel_resource_info_unref0(var) ((var == NULL) ? NULL : (var = (rygel_resource_info_unref (var), NULL)))
typedef struct _RygelMediaExportContentDirPrivate RygelMediaExportContentDirPrivate;

struct _RygelMediaExportContentDir {
	RygelContentDirectory parent_instance;
	RygelMediaExportContentDirPrivate * priv;
};

struct _RygelMediaExportContentDirClass {
	RygelContentDirectoryClass parent_class;
};


static gpointer rygel_media_export_content_dir_parent_class = NULL;

GType rygel_media_export_content_dir_get_type (void);
void module_init (RygelPluginLoader* loader);
enum  {
	RYGEL_MEDIA_EXPORT_CONTENT_DIR_DUMMY_PROPERTY
};
RygelMediaContainer* rygel_media_export_root_container_get_instance (void);
static RygelMediaContainer* rygel_media_export_content_dir_real_create_root_container (RygelContentDirectory* base);
RygelMediaExportContentDir* rygel_media_export_content_dir_new (void);
RygelMediaExportContentDir* rygel_media_export_content_dir_construct (GType object_type);



void module_init (RygelPluginLoader* loader) {
	RygelPlugin* plugin;
	RygelResourceInfo* resource_info;
	g_return_if_fail (loader != NULL);
	plugin = rygel_plugin_new_MediaServer ("MediaExport", "@REALNAME@'s media");
	resource_info = rygel_resource_info_new (RYGEL_CONTENT_DIRECTORY_UPNP_ID, RYGEL_CONTENT_DIRECTORY_UPNP_TYPE, RYGEL_CONTENT_DIRECTORY_DESCRIPTION_PATH, RYGEL_TYPE_MEDIA_EXPORT_CONTENT_DIR);
	rygel_plugin_add_resource (plugin, resource_info);
	rygel_plugin_loader_add_plugin (loader, plugin);
	_g_object_unref0 (plugin);
	_rygel_resource_info_unref0 (resource_info);
}


static RygelMediaContainer* rygel_media_export_content_dir_real_create_root_container (RygelContentDirectory* base) {
	RygelMediaExportContentDir * self;
	RygelMediaContainer* result;
	self = (RygelMediaExportContentDir*) base;
	result = rygel_media_export_root_container_get_instance ();
	return result;
}


RygelMediaExportContentDir* rygel_media_export_content_dir_construct (GType object_type) {
	RygelMediaExportContentDir * self;
	self = (RygelMediaExportContentDir*) rygel_content_directory_construct (object_type);
	return self;
}


RygelMediaExportContentDir* rygel_media_export_content_dir_new (void) {
	return rygel_media_export_content_dir_construct (RYGEL_TYPE_MEDIA_EXPORT_CONTENT_DIR);
}


static void rygel_media_export_content_dir_class_init (RygelMediaExportContentDirClass * klass) {
	rygel_media_export_content_dir_parent_class = g_type_class_peek_parent (klass);
	RYGEL_CONTENT_DIRECTORY_CLASS (klass)->create_root_container = rygel_media_export_content_dir_real_create_root_container;
}


static void rygel_media_export_content_dir_instance_init (RygelMediaExportContentDir * self) {
}


GType rygel_media_export_content_dir_get_type (void) {
	static GType rygel_media_export_content_dir_type_id = 0;
	if (rygel_media_export_content_dir_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediaExportContentDirClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_media_export_content_dir_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediaExportContentDir), 0, (GInstanceInitFunc) rygel_media_export_content_dir_instance_init, NULL };
		rygel_media_export_content_dir_type_id = g_type_register_static (RYGEL_TYPE_CONTENT_DIRECTORY, "RygelMediaExportContentDir", &g_define_type_info, 0);
	}
	return rygel_media_export_content_dir_type_id;
}




