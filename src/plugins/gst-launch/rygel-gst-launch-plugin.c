/* rygel-gst-launch-plugin.c generated by valac, the Vala compiler
 * generated from rygel-gst-launch-plugin.vala, do not modify */

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


#define RYGEL_TYPE_GST_LAUNCH_CONTENT_DIR (rygel_gst_launch_content_dir_get_type ())
#define RYGEL_GST_LAUNCH_CONTENT_DIR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_GST_LAUNCH_CONTENT_DIR, RygelGstLaunchContentDir))
#define RYGEL_GST_LAUNCH_CONTENT_DIR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_GST_LAUNCH_CONTENT_DIR, RygelGstLaunchContentDirClass))
#define RYGEL_IS_GST_LAUNCH_CONTENT_DIR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_GST_LAUNCH_CONTENT_DIR))
#define RYGEL_IS_GST_LAUNCH_CONTENT_DIR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_GST_LAUNCH_CONTENT_DIR))
#define RYGEL_GST_LAUNCH_CONTENT_DIR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_GST_LAUNCH_CONTENT_DIR, RygelGstLaunchContentDirClass))

typedef struct _RygelGstLaunchContentDir RygelGstLaunchContentDir;
typedef struct _RygelGstLaunchContentDirClass RygelGstLaunchContentDirClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))



GType rygel_gst_launch_content_dir_get_type (void);
void module_init (RygelPluginLoader* loader);



void module_init (RygelPluginLoader* loader) {
	RygelPlugin* plugin;
	g_return_if_fail (loader != NULL);
	plugin = rygel_plugin_new_MediaServer ("GstLaunch", "Gst Launch", RYGEL_TYPE_GST_LAUNCH_CONTENT_DIR);
	rygel_plugin_loader_add_plugin (loader, plugin);
	_g_object_unref0 (plugin);
}



