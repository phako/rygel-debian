/* rygel-playbin-plugin.c generated by valac, the Vala compiler
 * generated from rygel-playbin-plugin.vala, do not modify */

/*
 * Copyright (C) 2008 Zeeshan Ali (Khattak) <zeeshanak@gnome.org>.
 * Copyright (C) 2008 Nokia Corporation, all rights reserved.
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
#include <rygel.h>
#include <glib/gi18n-lib.h>


#define RYGEL_PLAYBIN_TYPE_PLUGIN (rygel_playbin_plugin_get_type ())
#define RYGEL_PLAYBIN_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_PLAYBIN_TYPE_PLUGIN, RygelPlaybinPlugin))
#define RYGEL_PLAYBIN_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_PLAYBIN_TYPE_PLUGIN, RygelPlaybinPluginClass))
#define RYGEL_PLAYBIN_IS_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_PLAYBIN_TYPE_PLUGIN))
#define RYGEL_PLAYBIN_IS_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_PLAYBIN_TYPE_PLUGIN))
#define RYGEL_PLAYBIN_PLUGIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_PLAYBIN_TYPE_PLUGIN, RygelPlaybinPluginClass))

typedef struct _RygelPlaybinPlugin RygelPlaybinPlugin;
typedef struct _RygelPlaybinPluginClass RygelPlaybinPluginClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _RygelPlaybinPluginPrivate RygelPlaybinPluginPrivate;

#define RYGEL_PLAYBIN_TYPE_PLAYER (rygel_playbin_player_get_type ())
#define RYGEL_PLAYBIN_PLAYER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_PLAYBIN_TYPE_PLAYER, RygelPlaybinPlayer))
#define RYGEL_PLAYBIN_PLAYER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_PLAYBIN_TYPE_PLAYER, RygelPlaybinPlayerClass))
#define RYGEL_PLAYBIN_IS_PLAYER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_PLAYBIN_TYPE_PLAYER))
#define RYGEL_PLAYBIN_IS_PLAYER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_PLAYBIN_TYPE_PLAYER))
#define RYGEL_PLAYBIN_PLAYER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_PLAYBIN_TYPE_PLAYER, RygelPlaybinPlayerClass))

typedef struct _RygelPlaybinPlayer RygelPlaybinPlayer;
typedef struct _RygelPlaybinPlayerClass RygelPlaybinPlayerClass;

struct _RygelPlaybinPlugin {
	RygelMediaRendererPlugin parent_instance;
	RygelPlaybinPluginPrivate * priv;
};

struct _RygelPlaybinPluginClass {
	RygelMediaRendererPluginClass parent_class;
};


static gpointer rygel_playbin_plugin_parent_class = NULL;

RygelPlaybinPlugin* rygel_playbin_plugin_new (void);
RygelPlaybinPlugin* rygel_playbin_plugin_construct (GType object_type);
GType rygel_playbin_plugin_get_type (void) G_GNUC_CONST;
void module_init (RygelPluginLoader* loader);
enum  {
	RYGEL_PLAYBIN_PLUGIN_DUMMY_PROPERTY
};
GType rygel_playbin_player_get_type (void) G_GNUC_CONST;
RygelPlaybinPlayer* rygel_playbin_player_get_default (void);
static RygelMediaPlayer* rygel_playbin_plugin_real_get_player (RygelMediaRendererPlugin* base);



#line 28 "rygel-playbin-plugin.vala"
void module_init (RygelPluginLoader* loader) {
#line 84 "rygel-playbin-plugin.c"
	RygelPlaybinPlugin* plugin;
#line 28 "rygel-playbin-plugin.vala"
	g_return_if_fail (loader != NULL);
#line 29 "rygel-playbin-plugin.vala"
	plugin = rygel_playbin_plugin_new ();
#line 31 "rygel-playbin-plugin.vala"
	rygel_plugin_loader_add_plugin (loader, (RygelPlugin*) plugin);
#line 92 "rygel-playbin-plugin.c"
	_g_object_unref0 (plugin);
}


#line 35 "rygel-playbin-plugin.vala"
RygelPlaybinPlugin* rygel_playbin_plugin_construct (GType object_type) {
#line 99 "rygel-playbin-plugin.c"
	RygelPlaybinPlugin * self;
#line 36 "rygel-playbin-plugin.vala"
	self = (RygelPlaybinPlugin*) rygel_media_renderer_plugin_construct (object_type, "Playbin", _ ("GStreamer Player"), NULL);
#line 103 "rygel-playbin-plugin.c"
	return self;
}


#line 35 "rygel-playbin-plugin.vala"
RygelPlaybinPlugin* rygel_playbin_plugin_new (void) {
#line 35 "rygel-playbin-plugin.vala"
	return rygel_playbin_plugin_construct (RYGEL_PLAYBIN_TYPE_PLUGIN);
#line 112 "rygel-playbin-plugin.c"
}


#line 39 "rygel-playbin-plugin.vala"
static RygelMediaPlayer* rygel_playbin_plugin_real_get_player (RygelMediaRendererPlugin* base) {
#line 118 "rygel-playbin-plugin.c"
	RygelPlaybinPlugin * self;
	RygelMediaPlayer* result = NULL;
	self = (RygelPlaybinPlugin*) base;
	result = (RygelMediaPlayer*) rygel_playbin_player_get_default ();
#line 40 "rygel-playbin-plugin.vala"
	return result;
#line 125 "rygel-playbin-plugin.c"
}


static void rygel_playbin_plugin_class_init (RygelPlaybinPluginClass * klass) {
	rygel_playbin_plugin_parent_class = g_type_class_peek_parent (klass);
	RYGEL_MEDIA_RENDERER_PLUGIN_CLASS (klass)->get_player = rygel_playbin_plugin_real_get_player;
}


static void rygel_playbin_plugin_instance_init (RygelPlaybinPlugin * self) {
}


GType rygel_playbin_plugin_get_type (void) {
	static volatile gsize rygel_playbin_plugin_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_playbin_plugin_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelPlaybinPluginClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_playbin_plugin_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelPlaybinPlugin), 0, (GInstanceInitFunc) rygel_playbin_plugin_instance_init, NULL };
		GType rygel_playbin_plugin_type_id;
		rygel_playbin_plugin_type_id = g_type_register_static (RYGEL_TYPE_MEDIA_RENDERER_PLUGIN, "RygelPlaybinPlugin", &g_define_type_info, 0);
		g_once_init_leave (&rygel_playbin_plugin_type_id__volatile, rygel_playbin_plugin_type_id);
	}
	return rygel_playbin_plugin_type_id__volatile;
}




