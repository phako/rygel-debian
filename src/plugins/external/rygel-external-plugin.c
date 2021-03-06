/* rygel-external-plugin.c generated by valac, the Vala compiler
 * generated from rygel-external-plugin.vala, do not modify */

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
#include <rygel.h>
#include <stdlib.h>
#include <string.h>
#include <libgupnp/gupnp.h>
#include <libgssdp/gssdp.h>


#define RYGEL_EXTERNAL_TYPE_PLUGIN (rygel_external_plugin_get_type ())
#define RYGEL_EXTERNAL_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_EXTERNAL_TYPE_PLUGIN, RygelExternalPlugin))
#define RYGEL_EXTERNAL_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_EXTERNAL_TYPE_PLUGIN, RygelExternalPluginClass))
#define RYGEL_EXTERNAL_IS_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_EXTERNAL_TYPE_PLUGIN))
#define RYGEL_EXTERNAL_IS_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_EXTERNAL_TYPE_PLUGIN))
#define RYGEL_EXTERNAL_PLUGIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_EXTERNAL_TYPE_PLUGIN, RygelExternalPluginClass))

typedef struct _RygelExternalPlugin RygelExternalPlugin;
typedef struct _RygelExternalPluginClass RygelExternalPluginClass;
typedef struct _RygelExternalPluginPrivate RygelExternalPluginPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))

#define RYGEL_EXTERNAL_TYPE_CONTAINER (rygel_external_container_get_type ())
#define RYGEL_EXTERNAL_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_EXTERNAL_TYPE_CONTAINER, RygelExternalContainer))
#define RYGEL_EXTERNAL_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_EXTERNAL_TYPE_CONTAINER, RygelExternalContainerClass))
#define RYGEL_EXTERNAL_IS_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_EXTERNAL_TYPE_CONTAINER))
#define RYGEL_EXTERNAL_IS_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_EXTERNAL_TYPE_CONTAINER))
#define RYGEL_EXTERNAL_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_EXTERNAL_TYPE_CONTAINER, RygelExternalContainerClass))

typedef struct _RygelExternalContainer RygelExternalContainer;
typedef struct _RygelExternalContainerClass RygelExternalContainerClass;

struct _RygelExternalPlugin {
	RygelMediaServerPlugin parent_instance;
	RygelExternalPluginPrivate * priv;
	char* service_name;
	char* root_object;
	guint child_count;
	gboolean searchable;
};

struct _RygelExternalPluginClass {
	RygelMediaServerPluginClass parent_class;
};


static gpointer rygel_external_plugin_parent_class = NULL;

GType rygel_external_plugin_get_type (void) G_GNUC_CONST;
enum  {
	RYGEL_EXTERNAL_PLUGIN_DUMMY_PROPERTY
};
RygelExternalPlugin* rygel_external_plugin_new (const char* service_name, const char* title, guint child_count, gboolean searchable, const char* root_object, RygelIconInfo* icon);
RygelExternalPlugin* rygel_external_plugin_construct (GType object_type, const char* service_name, const char* title, guint child_count, gboolean searchable, const char* root_object, RygelIconInfo* icon);
GType rygel_external_container_get_type (void) G_GNUC_CONST;
RygelExternalContainer* rygel_external_container_new (const char* id, const char* title, guint child_count, gboolean searchable, const char* service_name, const char* path, const char* host_ip, RygelExternalContainer* parent);
RygelExternalContainer* rygel_external_container_construct (GType object_type, const char* id, const char* title, guint child_count, gboolean searchable, const char* service_name, const char* path, const char* host_ip, RygelExternalContainer* parent);
static RygelMediaContainer* rygel_external_plugin_real_get_root_container (RygelMediaServerPlugin* base, RygelContentDirectory* content_dir);
static void rygel_external_plugin_finalize (GObject* obj);



#line 35 "rygel-external-plugin.vala"
RygelExternalPlugin* rygel_external_plugin_construct (GType object_type, const char* service_name, const char* title, guint child_count, gboolean searchable, const char* root_object, RygelIconInfo* icon) {
#line 92 "rygel-external-plugin.c"
	RygelExternalPlugin * self;
	char* _tmp0_;
	char* _tmp1_;
	char* _tmp2_;
#line 35 "rygel-external-plugin.vala"
	g_return_val_if_fail (service_name != NULL, NULL);
#line 35 "rygel-external-plugin.vala"
	g_return_val_if_fail (title != NULL, NULL);
#line 35 "rygel-external-plugin.vala"
	g_return_val_if_fail (root_object != NULL, NULL);
#line 41 "rygel-external-plugin.vala"
	self = (RygelExternalPlugin*) rygel_media_server_plugin_construct (object_type, service_name, title, _tmp0_ = g_strconcat ("Rygel External ", title, NULL));
#line 105 "rygel-external-plugin.c"
	_g_free0 (_tmp0_);
#line 45 "rygel-external-plugin.vala"
	self->service_name = (_tmp1_ = g_strdup (service_name), _g_free0 (self->service_name), _tmp1_);
#line 46 "rygel-external-plugin.vala"
	self->child_count = child_count;
#line 47 "rygel-external-plugin.vala"
	self->searchable = searchable;
#line 48 "rygel-external-plugin.vala"
	self->root_object = (_tmp2_ = g_strdup (root_object), _g_free0 (self->root_object), _tmp2_);
#line 49 "rygel-external-plugin.vala"
	if (icon != NULL) {
#line 50 "rygel-external-plugin.vala"
		rygel_plugin_add_icon ((RygelPlugin*) self, icon);
#line 119 "rygel-external-plugin.c"
	}
	return self;
}


#line 35 "rygel-external-plugin.vala"
RygelExternalPlugin* rygel_external_plugin_new (const char* service_name, const char* title, guint child_count, gboolean searchable, const char* root_object, RygelIconInfo* icon) {
#line 35 "rygel-external-plugin.vala"
	return rygel_external_plugin_construct (RYGEL_EXTERNAL_TYPE_PLUGIN, service_name, title, child_count, searchable, root_object, icon);
#line 129 "rygel-external-plugin.c"
}


#line 54 "rygel-external-plugin.vala"
static RygelMediaContainer* rygel_external_plugin_real_get_root_container (RygelMediaServerPlugin* base, RygelContentDirectory* content_dir) {
#line 135 "rygel-external-plugin.c"
	RygelExternalPlugin * self;
	RygelMediaContainer* result = NULL;
	self = (RygelExternalPlugin*) base;
#line 54 "rygel-external-plugin.vala"
	g_return_val_if_fail (content_dir != NULL, NULL);
#line 141 "rygel-external-plugin.c"
	result = (RygelMediaContainer*) rygel_external_container_new ("0", ((RygelPlugin*) self)->title, self->child_count, self->searchable, self->service_name, self->root_object, gssdp_client_get_host_ip ((GSSDPClient*) gupnp_service_info_get_context ((GUPnPServiceInfo*) content_dir)), NULL);
#line 56 "rygel-external-plugin.vala"
	return result;
#line 145 "rygel-external-plugin.c"
}


static void rygel_external_plugin_class_init (RygelExternalPluginClass * klass) {
	rygel_external_plugin_parent_class = g_type_class_peek_parent (klass);
	RYGEL_MEDIA_SERVER_PLUGIN_CLASS (klass)->get_root_container = rygel_external_plugin_real_get_root_container;
	G_OBJECT_CLASS (klass)->finalize = rygel_external_plugin_finalize;
}


static void rygel_external_plugin_instance_init (RygelExternalPlugin * self) {
}


static void rygel_external_plugin_finalize (GObject* obj) {
	RygelExternalPlugin * self;
	self = RYGEL_EXTERNAL_PLUGIN (obj);
	_g_free0 (self->service_name);
	_g_free0 (self->root_object);
	G_OBJECT_CLASS (rygel_external_plugin_parent_class)->finalize (obj);
}


GType rygel_external_plugin_get_type (void) {
	static volatile gsize rygel_external_plugin_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_external_plugin_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelExternalPluginClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_external_plugin_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelExternalPlugin), 0, (GInstanceInitFunc) rygel_external_plugin_instance_init, NULL };
		GType rygel_external_plugin_type_id;
		rygel_external_plugin_type_id = g_type_register_static (RYGEL_TYPE_MEDIA_SERVER_PLUGIN, "RygelExternalPlugin", &g_define_type_info, 0);
		g_once_init_leave (&rygel_external_plugin_type_id__volatile, rygel_external_plugin_type_id);
	}
	return rygel_external_plugin_type_id__volatile;
}




