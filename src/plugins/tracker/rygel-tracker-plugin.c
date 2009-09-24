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
#include <rygel.h>


#define RYGEL_TYPE_TRACKER_PLUGIN (rygel_tracker_plugin_get_type ())
#define RYGEL_TRACKER_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_PLUGIN, RygelTrackerPlugin))
#define RYGEL_TRACKER_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_PLUGIN, RygelTrackerPluginClass))
#define RYGEL_IS_TRACKER_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_PLUGIN))
#define RYGEL_IS_TRACKER_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_PLUGIN))
#define RYGEL_TRACKER_PLUGIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_PLUGIN, RygelTrackerPluginClass))

typedef struct _RygelTrackerPlugin RygelTrackerPlugin;
typedef struct _RygelTrackerPluginClass RygelTrackerPluginClass;
typedef struct _RygelTrackerPluginPrivate RygelTrackerPluginPrivate;

#define RYGEL_TYPE_MEDIA_TRACKER (rygel_media_tracker_get_type ())
#define RYGEL_MEDIA_TRACKER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_TRACKER, RygelMediaTracker))
#define RYGEL_MEDIA_TRACKER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_TRACKER, RygelMediaTrackerClass))
#define RYGEL_IS_MEDIA_TRACKER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_TRACKER))
#define RYGEL_IS_MEDIA_TRACKER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_TRACKER))
#define RYGEL_MEDIA_TRACKER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_TRACKER, RygelMediaTrackerClass))

typedef struct _RygelMediaTracker RygelMediaTracker;
typedef struct _RygelMediaTrackerClass RygelMediaTrackerClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _rygel_resource_info_unref0(var) ((var == NULL) ? NULL : (var = (rygel_resource_info_unref (var), NULL)))
#define _rygel_icon_info_unref0(var) ((var == NULL) ? NULL : (var = (rygel_icon_info_unref (var), NULL)))

struct _RygelTrackerPlugin {
	RygelPlugin parent_instance;
	RygelTrackerPluginPrivate * priv;
};

struct _RygelTrackerPluginClass {
	RygelPluginClass parent_class;
};


static gpointer rygel_tracker_plugin_parent_class = NULL;

GType rygel_tracker_plugin_get_type (void);
enum  {
	RYGEL_TRACKER_PLUGIN_DUMMY_PROPERTY
};
#define RYGEL_TRACKER_PLUGIN_ICON DATA_DIR "/icons/hicolor/48x48/apps/tracker.png"
GType rygel_media_tracker_get_type (void);
RygelTrackerPlugin* rygel_tracker_plugin_new (void);
RygelTrackerPlugin* rygel_tracker_plugin_construct (GType object_type);



RygelTrackerPlugin* rygel_tracker_plugin_construct (GType object_type) {
	RygelTrackerPlugin * self;
	RygelResourceInfo* resource_info;
	RygelIconInfo* icon_info;
	char* _tmp0_;
	self = (RygelTrackerPlugin*) rygel_plugin_construct_MediaServer (object_type, "Tracker", "@REALNAME@'s media");
	resource_info = rygel_resource_info_new (RYGEL_CONTENT_DIRECTORY_UPNP_ID, RYGEL_CONTENT_DIRECTORY_UPNP_TYPE, RYGEL_CONTENT_DIRECTORY_DESCRIPTION_PATH, RYGEL_TYPE_MEDIA_TRACKER);
	rygel_plugin_add_resource ((RygelPlugin*) self, resource_info);
	icon_info = rygel_icon_info_new ("image/png");
	icon_info->path = (_tmp0_ = g_strdup (RYGEL_TRACKER_PLUGIN_ICON), _g_free0 (icon_info->path), _tmp0_);
	icon_info->width = 48;
	icon_info->height = 48;
	icon_info->depth = 24;
	rygel_plugin_add_icon ((RygelPlugin*) self, icon_info);
	_rygel_resource_info_unref0 (resource_info);
	_rygel_icon_info_unref0 (icon_info);
	return self;
}


RygelTrackerPlugin* rygel_tracker_plugin_new (void) {
	return rygel_tracker_plugin_construct (RYGEL_TYPE_TRACKER_PLUGIN);
}


static void rygel_tracker_plugin_class_init (RygelTrackerPluginClass * klass) {
	rygel_tracker_plugin_parent_class = g_type_class_peek_parent (klass);
}


static void rygel_tracker_plugin_instance_init (RygelTrackerPlugin * self) {
}


GType rygel_tracker_plugin_get_type (void) {
	static GType rygel_tracker_plugin_type_id = 0;
	if (rygel_tracker_plugin_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelTrackerPluginClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_tracker_plugin_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelTrackerPlugin), 0, (GInstanceInitFunc) rygel_tracker_plugin_instance_init, NULL };
		rygel_tracker_plugin_type_id = g_type_register_static (RYGEL_TYPE_PLUGIN, "RygelTrackerPlugin", &g_define_type_info, 0);
	}
	return rygel_tracker_plugin_type_id;
}




