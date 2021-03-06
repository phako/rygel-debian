/* rygel-mediathek-plugin.c generated by valac, the Vala compiler
 * generated from rygel-mediathek-plugin.vala, do not modify */

/*
 * Copyright (C) 2009 Jens Georg
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
#include <rygel.h>


#define RYGEL_MEDIATHEK_TYPE_PLUGIN (rygel_mediathek_plugin_get_type ())
#define RYGEL_MEDIATHEK_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_MEDIATHEK_TYPE_PLUGIN, RygelMediathekPlugin))
#define RYGEL_MEDIATHEK_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_MEDIATHEK_TYPE_PLUGIN, RygelMediathekPluginClass))
#define RYGEL_MEDIATHEK_IS_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_MEDIATHEK_TYPE_PLUGIN))
#define RYGEL_MEDIATHEK_IS_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_MEDIATHEK_TYPE_PLUGIN))
#define RYGEL_MEDIATHEK_PLUGIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_MEDIATHEK_TYPE_PLUGIN, RygelMediathekPluginClass))

typedef struct _RygelMediathekPlugin RygelMediathekPlugin;
typedef struct _RygelMediathekPluginClass RygelMediathekPluginClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _RygelMediathekPluginPrivate RygelMediathekPluginPrivate;

#define RYGEL_MEDIATHEK_TYPE_ROOT_CONTAINER (rygel_mediathek_root_container_get_type ())
#define RYGEL_MEDIATHEK_ROOT_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_MEDIATHEK_TYPE_ROOT_CONTAINER, RygelMediathekRootContainer))
#define RYGEL_MEDIATHEK_ROOT_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_MEDIATHEK_TYPE_ROOT_CONTAINER, RygelMediathekRootContainerClass))
#define RYGEL_MEDIATHEK_IS_ROOT_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_MEDIATHEK_TYPE_ROOT_CONTAINER))
#define RYGEL_MEDIATHEK_IS_ROOT_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_MEDIATHEK_TYPE_ROOT_CONTAINER))
#define RYGEL_MEDIATHEK_ROOT_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_MEDIATHEK_TYPE_ROOT_CONTAINER, RygelMediathekRootContainerClass))

typedef struct _RygelMediathekRootContainer RygelMediathekRootContainer;
typedef struct _RygelMediathekRootContainerClass RygelMediathekRootContainerClass;

struct _RygelMediathekPlugin {
	RygelMediaServerPlugin parent_instance;
	RygelMediathekPluginPrivate * priv;
};

struct _RygelMediathekPluginClass {
	RygelMediaServerPluginClass parent_class;
};


static gpointer rygel_mediathek_plugin_parent_class = NULL;

RygelMediathekPlugin* rygel_mediathek_plugin_new (void);
RygelMediathekPlugin* rygel_mediathek_plugin_construct (GType object_type);
GType rygel_mediathek_plugin_get_type (void) G_GNUC_CONST;
void module_init (RygelPluginLoader* loader);
enum  {
	RYGEL_MEDIATHEK_PLUGIN_DUMMY_PROPERTY
};
GType rygel_mediathek_root_container_get_type (void) G_GNUC_CONST;
RygelMediathekRootContainer* rygel_mediathek_root_container_get_instance (void);
static RygelMediaContainer* rygel_mediathek_plugin_real_get_root_container (RygelMediaServerPlugin* base, RygelContentDirectory* content_dir);



#line 26 "rygel-mediathek-plugin.vala"
void module_init (RygelPluginLoader* loader) {
#line 81 "rygel-mediathek-plugin.c"
	RygelMediathekPlugin* plugin;
#line 26 "rygel-mediathek-plugin.vala"
	g_return_if_fail (loader != NULL);
#line 27 "rygel-mediathek-plugin.vala"
	plugin = rygel_mediathek_plugin_new ();
#line 29 "rygel-mediathek-plugin.vala"
	rygel_plugin_loader_add_plugin (loader, (RygelPlugin*) plugin);
#line 89 "rygel-mediathek-plugin.c"
	_g_object_unref0 (plugin);
}


#line 33 "rygel-mediathek-plugin.vala"
RygelMediathekPlugin* rygel_mediathek_plugin_construct (GType object_type) {
#line 96 "rygel-mediathek-plugin.c"
	RygelMediathekPlugin * self;
#line 34 "rygel-mediathek-plugin.vala"
	self = (RygelMediathekPlugin*) rygel_media_server_plugin_construct (object_type, "ZDFMediathek", "ZDF Mediathek", NULL);
#line 100 "rygel-mediathek-plugin.c"
	return self;
}


#line 33 "rygel-mediathek-plugin.vala"
RygelMediathekPlugin* rygel_mediathek_plugin_new (void) {
#line 33 "rygel-mediathek-plugin.vala"
	return rygel_mediathek_plugin_construct (RYGEL_MEDIATHEK_TYPE_PLUGIN);
#line 109 "rygel-mediathek-plugin.c"
}


#line 37 "rygel-mediathek-plugin.vala"
static RygelMediaContainer* rygel_mediathek_plugin_real_get_root_container (RygelMediaServerPlugin* base, RygelContentDirectory* content_dir) {
#line 115 "rygel-mediathek-plugin.c"
	RygelMediathekPlugin * self;
	RygelMediaContainer* result = NULL;
	self = (RygelMediathekPlugin*) base;
#line 37 "rygel-mediathek-plugin.vala"
	g_return_val_if_fail (content_dir != NULL, NULL);
#line 121 "rygel-mediathek-plugin.c"
	result = (RygelMediaContainer*) rygel_mediathek_root_container_get_instance ();
#line 39 "rygel-mediathek-plugin.vala"
	return result;
#line 125 "rygel-mediathek-plugin.c"
}


static void rygel_mediathek_plugin_class_init (RygelMediathekPluginClass * klass) {
	rygel_mediathek_plugin_parent_class = g_type_class_peek_parent (klass);
	RYGEL_MEDIA_SERVER_PLUGIN_CLASS (klass)->get_root_container = rygel_mediathek_plugin_real_get_root_container;
}


static void rygel_mediathek_plugin_instance_init (RygelMediathekPlugin * self) {
}


GType rygel_mediathek_plugin_get_type (void) {
	static volatile gsize rygel_mediathek_plugin_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_mediathek_plugin_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediathekPluginClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_mediathek_plugin_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediathekPlugin), 0, (GInstanceInitFunc) rygel_mediathek_plugin_instance_init, NULL };
		GType rygel_mediathek_plugin_type_id;
		rygel_mediathek_plugin_type_id = g_type_register_static (RYGEL_TYPE_MEDIA_SERVER_PLUGIN, "RygelMediathekPlugin", &g_define_type_info, 0);
		g_once_init_leave (&rygel_mediathek_plugin_type_id__volatile, rygel_mediathek_plugin_type_id);
	}
	return rygel_mediathek_plugin_type_id__volatile;
}




