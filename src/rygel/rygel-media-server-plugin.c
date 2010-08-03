/* rygel-media-server-plugin.c generated by valac, the Vala compiler
 * generated from rygel-media-server-plugin.vala, do not modify */

/*
 * Copyright (C) 2008,2010 Nokia Corporation.
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
#include <libgupnp/gupnp.h>
#include <stdlib.h>
#include <string.h>
#include <gee.h>
#include <config.h>


#define RYGEL_TYPE_PLUGIN (rygel_plugin_get_type ())
#define RYGEL_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_PLUGIN, RygelPlugin))
#define RYGEL_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_PLUGIN, RygelPluginClass))
#define RYGEL_IS_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_PLUGIN))
#define RYGEL_IS_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_PLUGIN))
#define RYGEL_PLUGIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_PLUGIN, RygelPluginClass))

typedef struct _RygelPlugin RygelPlugin;
typedef struct _RygelPluginClass RygelPluginClass;
typedef struct _RygelPluginPrivate RygelPluginPrivate;

#define RYGEL_TYPE_RESOURCE_INFO (rygel_resource_info_get_type ())
#define RYGEL_RESOURCE_INFO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_RESOURCE_INFO, RygelResourceInfo))
#define RYGEL_RESOURCE_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_RESOURCE_INFO, RygelResourceInfoClass))
#define RYGEL_IS_RESOURCE_INFO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_RESOURCE_INFO))
#define RYGEL_IS_RESOURCE_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_RESOURCE_INFO))
#define RYGEL_RESOURCE_INFO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_RESOURCE_INFO, RygelResourceInfoClass))

typedef struct _RygelResourceInfo RygelResourceInfo;
typedef struct _RygelResourceInfoClass RygelResourceInfoClass;

#define RYGEL_TYPE_ICON_INFO (rygel_icon_info_get_type ())
#define RYGEL_ICON_INFO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_ICON_INFO, RygelIconInfo))
#define RYGEL_ICON_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_ICON_INFO, RygelIconInfoClass))
#define RYGEL_IS_ICON_INFO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_ICON_INFO))
#define RYGEL_IS_ICON_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_ICON_INFO))
#define RYGEL_ICON_INFO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_ICON_INFO, RygelIconInfoClass))

typedef struct _RygelIconInfo RygelIconInfo;
typedef struct _RygelIconInfoClass RygelIconInfoClass;

#define RYGEL_TYPE_MEDIA_SERVER_PLUGIN (rygel_media_server_plugin_get_type ())
#define RYGEL_MEDIA_SERVER_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_SERVER_PLUGIN, RygelMediaServerPlugin))
#define RYGEL_MEDIA_SERVER_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_SERVER_PLUGIN, RygelMediaServerPluginClass))
#define RYGEL_IS_MEDIA_SERVER_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_SERVER_PLUGIN))
#define RYGEL_IS_MEDIA_SERVER_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_SERVER_PLUGIN))
#define RYGEL_MEDIA_SERVER_PLUGIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_SERVER_PLUGIN, RygelMediaServerPluginClass))

typedef struct _RygelMediaServerPlugin RygelMediaServerPlugin;
typedef struct _RygelMediaServerPluginClass RygelMediaServerPluginClass;
typedef struct _RygelMediaServerPluginPrivate RygelMediaServerPluginPrivate;

#define RYGEL_TYPE_CONTENT_DIRECTORY (rygel_content_directory_get_type ())
#define RYGEL_CONTENT_DIRECTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_CONTENT_DIRECTORY, RygelContentDirectory))
#define RYGEL_CONTENT_DIRECTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_CONTENT_DIRECTORY, RygelContentDirectoryClass))
#define RYGEL_IS_CONTENT_DIRECTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_CONTENT_DIRECTORY))
#define RYGEL_IS_CONTENT_DIRECTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_CONTENT_DIRECTORY))
#define RYGEL_CONTENT_DIRECTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_CONTENT_DIRECTORY, RygelContentDirectoryClass))

typedef struct _RygelContentDirectory RygelContentDirectory;
typedef struct _RygelContentDirectoryClass RygelContentDirectoryClass;

#define RYGEL_TYPE_MEDIA_OBJECT (rygel_media_object_get_type ())
#define RYGEL_MEDIA_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObject))
#define RYGEL_MEDIA_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObjectClass))
#define RYGEL_IS_MEDIA_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_OBJECT))
#define RYGEL_IS_MEDIA_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_OBJECT))
#define RYGEL_MEDIA_OBJECT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObjectClass))

typedef struct _RygelMediaObject RygelMediaObject;
typedef struct _RygelMediaObjectClass RygelMediaObjectClass;

#define RYGEL_TYPE_MEDIA_CONTAINER (rygel_media_container_get_type ())
#define RYGEL_MEDIA_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainer))
#define RYGEL_MEDIA_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainerClass))
#define RYGEL_IS_MEDIA_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_CONTAINER))
#define RYGEL_IS_MEDIA_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_CONTAINER))
#define RYGEL_MEDIA_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainerClass))

typedef struct _RygelMediaContainer RygelMediaContainer;
typedef struct _RygelMediaContainerClass RygelMediaContainerClass;

#define RYGEL_TYPE_CONNECTION_MANAGER (rygel_connection_manager_get_type ())
#define RYGEL_CONNECTION_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_CONNECTION_MANAGER, RygelConnectionManager))
#define RYGEL_CONNECTION_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_CONNECTION_MANAGER, RygelConnectionManagerClass))
#define RYGEL_IS_CONNECTION_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_CONNECTION_MANAGER))
#define RYGEL_IS_CONNECTION_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_CONNECTION_MANAGER))
#define RYGEL_CONNECTION_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_CONNECTION_MANAGER, RygelConnectionManagerClass))

typedef struct _RygelConnectionManager RygelConnectionManager;
typedef struct _RygelConnectionManagerClass RygelConnectionManagerClass;

#define RYGEL_TYPE_SOURCE_CONNECTION_MANAGER (rygel_source_connection_manager_get_type ())
#define RYGEL_SOURCE_CONNECTION_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_SOURCE_CONNECTION_MANAGER, RygelSourceConnectionManager))
#define RYGEL_SOURCE_CONNECTION_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_SOURCE_CONNECTION_MANAGER, RygelSourceConnectionManagerClass))
#define RYGEL_IS_SOURCE_CONNECTION_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_SOURCE_CONNECTION_MANAGER))
#define RYGEL_IS_SOURCE_CONNECTION_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_SOURCE_CONNECTION_MANAGER))
#define RYGEL_SOURCE_CONNECTION_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_SOURCE_CONNECTION_MANAGER, RygelSourceConnectionManagerClass))

typedef struct _RygelSourceConnectionManager RygelSourceConnectionManager;
typedef struct _RygelSourceConnectionManagerClass RygelSourceConnectionManagerClass;
#define _rygel_resource_info_unref0(var) ((var == NULL) ? NULL : (var = (rygel_resource_info_unref (var), NULL)))

#define RYGEL_TYPE_MEDIA_RECEIVER_REGISTRAR (rygel_media_receiver_registrar_get_type ())
#define RYGEL_MEDIA_RECEIVER_REGISTRAR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_RECEIVER_REGISTRAR, RygelMediaReceiverRegistrar))
#define RYGEL_MEDIA_RECEIVER_REGISTRAR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_RECEIVER_REGISTRAR, RygelMediaReceiverRegistrarClass))
#define RYGEL_IS_MEDIA_RECEIVER_REGISTRAR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_RECEIVER_REGISTRAR))
#define RYGEL_IS_MEDIA_RECEIVER_REGISTRAR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_RECEIVER_REGISTRAR))
#define RYGEL_MEDIA_RECEIVER_REGISTRAR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_RECEIVER_REGISTRAR, RygelMediaReceiverRegistrarClass))

typedef struct _RygelMediaReceiverRegistrar RygelMediaReceiverRegistrar;
typedef struct _RygelMediaReceiverRegistrarClass RygelMediaReceiverRegistrarClass;

struct _RygelPlugin {
	GUPnPResourceFactory parent_instance;
	RygelPluginPrivate * priv;
	char* name;
	char* title;
	char* description;
	char* desc_path;
	GeeArrayList* resource_infos;
	GeeArrayList* icon_infos;
	GeeArrayList* default_icons;
};

struct _RygelPluginClass {
	GUPnPResourceFactoryClass parent_class;
};

struct _RygelMediaServerPlugin {
	RygelPlugin parent_instance;
	RygelMediaServerPluginPrivate * priv;
};

struct _RygelMediaServerPluginClass {
	RygelPluginClass parent_class;
	RygelMediaContainer* (*get_root_container) (RygelMediaServerPlugin* self, RygelContentDirectory* content_dir);
};


static gpointer rygel_media_server_plugin_parent_class = NULL;

GType rygel_plugin_get_type (void) G_GNUC_CONST;
gpointer rygel_resource_info_ref (gpointer instance);
void rygel_resource_info_unref (gpointer instance);
GParamSpec* rygel_param_spec_resource_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_resource_info (GValue* value, gpointer v_object);
void rygel_value_take_resource_info (GValue* value, gpointer v_object);
gpointer rygel_value_get_resource_info (const GValue* value);
GType rygel_resource_info_get_type (void) G_GNUC_CONST;
gpointer rygel_icon_info_ref (gpointer instance);
void rygel_icon_info_unref (gpointer instance);
GParamSpec* rygel_param_spec_icon_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_icon_info (GValue* value, gpointer v_object);
void rygel_value_take_icon_info (GValue* value, gpointer v_object);
gpointer rygel_value_get_icon_info (const GValue* value);
GType rygel_icon_info_get_type (void) G_GNUC_CONST;
GType rygel_media_server_plugin_get_type (void) G_GNUC_CONST;
GType rygel_content_directory_get_type (void) G_GNUC_CONST;
GType rygel_media_object_get_type (void) G_GNUC_CONST;
GType rygel_media_container_get_type (void) G_GNUC_CONST;
enum  {
	RYGEL_MEDIA_SERVER_PLUGIN_DUMMY_PROPERTY
};
#define RYGEL_MEDIA_SERVER_PLUGIN_MEDIA_SERVER_DESC_PATH DATA_DIR "/xml/MediaServer2.xml"
RygelPlugin* rygel_plugin_new (const char* desc_path, const char* name, const char* title, const char* description);
RygelPlugin* rygel_plugin_construct (GType object_type, const char* desc_path, const char* name, const char* title, const char* description);
#define RYGEL_CONTENT_DIRECTORY_UPNP_ID "urn:upnp-org:serviceId:ContentDirectory"
#define RYGEL_CONTENT_DIRECTORY_UPNP_TYPE "urn:schemas-upnp-org:service:ContentDirectory:2"
#define RYGEL_CONTENT_DIRECTORY_DESCRIPTION_PATH "xml/ContentDirectory.xml"
RygelResourceInfo* rygel_resource_info_new (const char* upnp_id, const char* upnp_type, const char* description_path, GType type);
RygelResourceInfo* rygel_resource_info_construct (GType object_type, const char* upnp_id, const char* upnp_type, const char* description_path, GType type);
void rygel_plugin_add_resource (RygelPlugin* self, RygelResourceInfo* resource_info);
#define RYGEL_CONNECTION_MANAGER_UPNP_ID "urn:upnp-org:serviceId:ConnectionManager"
#define RYGEL_CONNECTION_MANAGER_UPNP_TYPE "urn:schemas-upnp-org:service:ConnectionManager:2"
#define RYGEL_CONNECTION_MANAGER_DESCRIPTION_PATH "xml/ConnectionManager.xml"
GType rygel_connection_manager_get_type (void) G_GNUC_CONST;
GType rygel_source_connection_manager_get_type (void) G_GNUC_CONST;
#define RYGEL_MEDIA_RECEIVER_REGISTRAR_UPNP_ID "urn:microsoft.com:serviceId:X_MS_MediaReceiverRegistrar"
#define RYGEL_MEDIA_RECEIVER_REGISTRAR_UPNP_TYPE "urn:microsoft.com:service:X_MS_MediaReceiverRegistrar:1"
#define RYGEL_MEDIA_RECEIVER_REGISTRAR_DESCRIPTION_PATH "xml/X_MS_MediaReceiverRegistrar1.xml"
GType rygel_media_receiver_registrar_get_type (void) G_GNUC_CONST;
RygelMediaServerPlugin* rygel_media_server_plugin_new (const char* name, const char* title, const char* description);
RygelMediaServerPlugin* rygel_media_server_plugin_construct (GType object_type, const char* name, const char* title, const char* description);
RygelMediaContainer* rygel_media_server_plugin_get_root_container (RygelMediaServerPlugin* self, RygelContentDirectory* content_dir);
static RygelMediaContainer* rygel_media_server_plugin_real_get_root_container (RygelMediaServerPlugin* self, RygelContentDirectory* content_dir);



#line 28 "rygel-media-server-plugin.vala"
RygelMediaServerPlugin* rygel_media_server_plugin_construct (GType object_type, const char* name, const char* title, const char* description) {
#line 218 "rygel-media-server-plugin.c"
	RygelMediaServerPlugin * self;
	RygelResourceInfo* resource_info;
	RygelResourceInfo* _tmp0_;
	RygelResourceInfo* _tmp1_;
#line 28 "rygel-media-server-plugin.vala"
	g_return_val_if_fail (name != NULL, NULL);
#line 31 "rygel-media-server-plugin.vala"
	self = (RygelMediaServerPlugin*) rygel_plugin_construct (object_type, RYGEL_MEDIA_SERVER_PLUGIN_MEDIA_SERVER_DESC_PATH, name, title, description);
#line 34 "rygel-media-server-plugin.vala"
	resource_info = rygel_resource_info_new (RYGEL_CONTENT_DIRECTORY_UPNP_ID, RYGEL_CONTENT_DIRECTORY_UPNP_TYPE, RYGEL_CONTENT_DIRECTORY_DESCRIPTION_PATH, RYGEL_TYPE_CONTENT_DIRECTORY);
#line 38 "rygel-media-server-plugin.vala"
	rygel_plugin_add_resource ((RygelPlugin*) self, resource_info);
#line 41 "rygel-media-server-plugin.vala"
	resource_info = (_tmp0_ = rygel_resource_info_new (RYGEL_CONNECTION_MANAGER_UPNP_ID, RYGEL_CONNECTION_MANAGER_UPNP_TYPE, RYGEL_CONNECTION_MANAGER_DESCRIPTION_PATH, RYGEL_TYPE_SOURCE_CONNECTION_MANAGER), _rygel_resource_info_unref0 (resource_info), _tmp0_);
#line 46 "rygel-media-server-plugin.vala"
	rygel_plugin_add_resource ((RygelPlugin*) self, resource_info);
#line 47 "rygel-media-server-plugin.vala"
	resource_info = (_tmp1_ = rygel_resource_info_new (RYGEL_MEDIA_RECEIVER_REGISTRAR_UPNP_ID, RYGEL_MEDIA_RECEIVER_REGISTRAR_UPNP_TYPE, RYGEL_MEDIA_RECEIVER_REGISTRAR_DESCRIPTION_PATH, RYGEL_TYPE_MEDIA_RECEIVER_REGISTRAR), _rygel_resource_info_unref0 (resource_info), _tmp1_);
#line 52 "rygel-media-server-plugin.vala"
	rygel_plugin_add_resource ((RygelPlugin*) self, resource_info);
#line 239 "rygel-media-server-plugin.c"
	_rygel_resource_info_unref0 (resource_info);
	return self;
}


#line 28 "rygel-media-server-plugin.vala"
RygelMediaServerPlugin* rygel_media_server_plugin_new (const char* name, const char* title, const char* description) {
#line 28 "rygel-media-server-plugin.vala"
	return rygel_media_server_plugin_construct (RYGEL_TYPE_MEDIA_SERVER_PLUGIN, name, title, description);
#line 249 "rygel-media-server-plugin.c"
}


#line 55 "rygel-media-server-plugin.vala"
static RygelMediaContainer* rygel_media_server_plugin_real_get_root_container (RygelMediaServerPlugin* self, RygelContentDirectory* content_dir) {
#line 255 "rygel-media-server-plugin.c"
	RygelMediaContainer* result = NULL;
#line 55 "rygel-media-server-plugin.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 55 "rygel-media-server-plugin.vala"
	g_return_val_if_fail (content_dir != NULL, NULL);
#line 261 "rygel-media-server-plugin.c"
	result = NULL;
#line 57 "rygel-media-server-plugin.vala"
	return result;
#line 265 "rygel-media-server-plugin.c"
}


#line 55 "rygel-media-server-plugin.vala"
RygelMediaContainer* rygel_media_server_plugin_get_root_container (RygelMediaServerPlugin* self, RygelContentDirectory* content_dir) {
#line 55 "rygel-media-server-plugin.vala"
	return RYGEL_MEDIA_SERVER_PLUGIN_GET_CLASS (self)->get_root_container (self, content_dir);
#line 273 "rygel-media-server-plugin.c"
}


static void rygel_media_server_plugin_class_init (RygelMediaServerPluginClass * klass) {
	rygel_media_server_plugin_parent_class = g_type_class_peek_parent (klass);
	RYGEL_MEDIA_SERVER_PLUGIN_CLASS (klass)->get_root_container = rygel_media_server_plugin_real_get_root_container;
}


static void rygel_media_server_plugin_instance_init (RygelMediaServerPlugin * self) {
}


GType rygel_media_server_plugin_get_type (void) {
	static volatile gsize rygel_media_server_plugin_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_media_server_plugin_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediaServerPluginClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_media_server_plugin_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediaServerPlugin), 0, (GInstanceInitFunc) rygel_media_server_plugin_instance_init, NULL };
		GType rygel_media_server_plugin_type_id;
		rygel_media_server_plugin_type_id = g_type_register_static (RYGEL_TYPE_PLUGIN, "RygelMediaServerPlugin", &g_define_type_info, 0);
		g_once_init_leave (&rygel_media_server_plugin_type_id__volatile, rygel_media_server_plugin_type_id);
	}
	return rygel_media_server_plugin_type_id__volatile;
}



