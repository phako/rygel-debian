/*
 * Copyright (C) 2008 Nokia Corporation.
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
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define RYGEL_TYPE_CONNECTION_MANAGER (rygel_connection_manager_get_type ())
#define RYGEL_CONNECTION_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_CONNECTION_MANAGER, RygelConnectionManager))
#define RYGEL_CONNECTION_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_CONNECTION_MANAGER, RygelConnectionManagerClass))
#define RYGEL_IS_CONNECTION_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_CONNECTION_MANAGER))
#define RYGEL_IS_CONNECTION_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_CONNECTION_MANAGER))
#define RYGEL_CONNECTION_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_CONNECTION_MANAGER, RygelConnectionManagerClass))

typedef struct _RygelConnectionManager RygelConnectionManager;
typedef struct _RygelConnectionManagerClass RygelConnectionManagerClass;
#define _rygel_resource_info_unref0(var) ((var == NULL) ? NULL : (var = (rygel_resource_info_unref (var), NULL)))
typedef struct _RygelResourceInfoPrivate RygelResourceInfoPrivate;

struct _RygelPlugin {
	GUPnPResourceFactory parent_instance;
	RygelPluginPrivate * priv;
	char* name;
	char* title;
	char* desc_path;
	GeeArrayList* resource_infos;
	GeeArrayList* icon_infos;
};

struct _RygelPluginClass {
	GUPnPResourceFactoryClass parent_class;
};

struct _RygelPluginPrivate {
	gboolean _available;
};

struct _RygelResourceInfo {
	GTypeInstance parent_instance;
	volatile int ref_count;
	RygelResourceInfoPrivate * priv;
	char* upnp_type;
	char* upnp_id;
	char* description_path;
	GType type;
};

struct _RygelResourceInfoClass {
	GTypeClass parent_class;
	void (*finalize) (RygelResourceInfo *self);
};


static gpointer rygel_plugin_parent_class = NULL;

GType rygel_plugin_get_type (void);
gpointer rygel_resource_info_ref (gpointer instance);
void rygel_resource_info_unref (gpointer instance);
GParamSpec* rygel_param_spec_resource_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_resource_info (GValue* value, gpointer v_object);
gpointer rygel_value_get_resource_info (const GValue* value);
GType rygel_resource_info_get_type (void);
gpointer rygel_icon_info_ref (gpointer instance);
void rygel_icon_info_unref (gpointer instance);
GParamSpec* rygel_param_spec_icon_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_icon_info (GValue* value, gpointer v_object);
gpointer rygel_value_get_icon_info (const GValue* value);
GType rygel_icon_info_get_type (void);
#define RYGEL_PLUGIN_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_PLUGIN, RygelPluginPrivate))
enum  {
	RYGEL_PLUGIN_DUMMY_PROPERTY,
	RYGEL_PLUGIN_AVAILABLE
};
#define RYGEL_PLUGIN_MEDIA_SERVER_DESC_PATH DATA_DIR "/xml/MediaServer2.xml"
void rygel_plugin_set_available (RygelPlugin* self, gboolean value);
RygelPlugin* rygel_plugin_new (const char* desc_path, const char* name, const char* title);
RygelPlugin* rygel_plugin_construct (GType object_type, const char* desc_path, const char* name, const char* title);
#define RYGEL_CONNECTION_MANAGER_UPNP_ID "urn:upnp-org:serviceId:ConnectionManager"
#define RYGEL_CONNECTION_MANAGER_UPNP_TYPE "urn:schemas-upnp-org:service:ConnectionManager:2"
#define RYGEL_CONNECTION_MANAGER_DESCRIPTION_PATH "xml/ConnectionManager.xml"
GType rygel_connection_manager_get_type (void);
RygelResourceInfo* rygel_resource_info_new (const char* upnp_id, const char* upnp_type, const char* description_path, GType type);
RygelResourceInfo* rygel_resource_info_construct (GType object_type, const char* upnp_id, const char* upnp_type, const char* description_path, GType type);
void rygel_plugin_add_resource (RygelPlugin* self, RygelResourceInfo* resource_info);
RygelPlugin* rygel_plugin_new_MediaServer (const char* name, const char* title);
RygelPlugin* rygel_plugin_construct_MediaServer (GType object_type, const char* name, const char* title);
void rygel_plugin_add_icon (RygelPlugin* self, RygelIconInfo* icon_info);
gboolean rygel_plugin_get_available (RygelPlugin* self);
static void rygel_plugin_finalize (GObject* obj);
static void rygel_plugin_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void rygel_plugin_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



RygelPlugin* rygel_plugin_construct (GType object_type, const char* desc_path, const char* name, const char* title) {
	RygelPlugin * self;
	char* _tmp0_;
	char* _tmp1_;
	char* _tmp2_;
	GeeArrayList* _tmp4_;
	GeeArrayList* _tmp5_;
	g_return_val_if_fail (desc_path != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	self = g_object_newv (object_type, 0, NULL);
	self->desc_path = (_tmp0_ = g_strdup (desc_path), _g_free0 (self->desc_path), _tmp0_);
	self->name = (_tmp1_ = g_strdup (name), _g_free0 (self->name), _tmp1_);
	self->title = (_tmp2_ = g_strdup (title), _g_free0 (self->title), _tmp2_);
	rygel_plugin_set_available (self, TRUE);
	if (title == NULL) {
		char* _tmp3_;
		self->title = (_tmp3_ = g_strdup (name), _g_free0 (self->title), _tmp3_);
	}
	self->resource_infos = (_tmp4_ = gee_array_list_new (RYGEL_TYPE_RESOURCE_INFO, (GBoxedCopyFunc) rygel_resource_info_ref, rygel_resource_info_unref, g_direct_equal), _g_object_unref0 (self->resource_infos), _tmp4_);
	self->icon_infos = (_tmp5_ = gee_array_list_new (RYGEL_TYPE_ICON_INFO, (GBoxedCopyFunc) rygel_icon_info_ref, rygel_icon_info_unref, g_direct_equal), _g_object_unref0 (self->icon_infos), _tmp5_);
	return self;
}


RygelPlugin* rygel_plugin_new (const char* desc_path, const char* name, const char* title) {
	return rygel_plugin_construct (RYGEL_TYPE_PLUGIN, desc_path, name, title);
}


RygelPlugin* rygel_plugin_construct_MediaServer (GType object_type, const char* name, const char* title) {
	RygelPlugin * self;
	RygelResourceInfo* resource_info;
	g_return_val_if_fail (name != NULL, NULL);
	self = (RygelPlugin*) rygel_plugin_construct (object_type, RYGEL_PLUGIN_MEDIA_SERVER_DESC_PATH, name, title);
	resource_info = rygel_resource_info_new (RYGEL_CONNECTION_MANAGER_UPNP_ID, RYGEL_CONNECTION_MANAGER_UPNP_TYPE, RYGEL_CONNECTION_MANAGER_DESCRIPTION_PATH, RYGEL_TYPE_CONNECTION_MANAGER);
	rygel_plugin_add_resource (self, resource_info);
	_rygel_resource_info_unref0 (resource_info);
	return self;
}


RygelPlugin* rygel_plugin_new_MediaServer (const char* name, const char* title) {
	return rygel_plugin_construct_MediaServer (RYGEL_TYPE_PLUGIN, name, title);
}


void rygel_plugin_add_resource (RygelPlugin* self, RygelResourceInfo* resource_info) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (resource_info != NULL);
	gee_abstract_collection_add ((GeeAbstractCollection*) self->resource_infos, resource_info);
	gupnp_resource_factory_register_resource_type ((GUPnPResourceFactory*) self, resource_info->upnp_type, resource_info->type);
}


void rygel_plugin_add_icon (RygelPlugin* self, RygelIconInfo* icon_info) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (icon_info != NULL);
	gee_abstract_collection_add ((GeeAbstractCollection*) self->icon_infos, icon_info);
}


gboolean rygel_plugin_get_available (RygelPlugin* self) {
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_available;
	return result;
}


void rygel_plugin_set_available (RygelPlugin* self, gboolean value) {
	g_return_if_fail (self != NULL);
	self->priv->_available = value;
	g_object_notify ((GObject *) self, "available");
}


static void rygel_plugin_class_init (RygelPluginClass * klass) {
	rygel_plugin_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelPluginPrivate));
	G_OBJECT_CLASS (klass)->get_property = rygel_plugin_get_property;
	G_OBJECT_CLASS (klass)->set_property = rygel_plugin_set_property;
	G_OBJECT_CLASS (klass)->finalize = rygel_plugin_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), RYGEL_PLUGIN_AVAILABLE, g_param_spec_boolean ("available", "available", "available", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void rygel_plugin_instance_init (RygelPlugin * self) {
	self->priv = RYGEL_PLUGIN_GET_PRIVATE (self);
}


static void rygel_plugin_finalize (GObject* obj) {
	RygelPlugin * self;
	self = RYGEL_PLUGIN (obj);
	_g_free0 (self->name);
	_g_free0 (self->title);
	_g_free0 (self->desc_path);
	_g_object_unref0 (self->resource_infos);
	_g_object_unref0 (self->icon_infos);
	G_OBJECT_CLASS (rygel_plugin_parent_class)->finalize (obj);
}


GType rygel_plugin_get_type (void) {
	static GType rygel_plugin_type_id = 0;
	if (rygel_plugin_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelPluginClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_plugin_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelPlugin), 0, (GInstanceInitFunc) rygel_plugin_instance_init, NULL };
		rygel_plugin_type_id = g_type_register_static (GUPNP_TYPE_RESOURCE_FACTORY, "RygelPlugin", &g_define_type_info, 0);
	}
	return rygel_plugin_type_id;
}


static void rygel_plugin_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	RygelPlugin * self;
	self = RYGEL_PLUGIN (object);
	switch (property_id) {
		case RYGEL_PLUGIN_AVAILABLE:
		g_value_set_boolean (value, rygel_plugin_get_available (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void rygel_plugin_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	RygelPlugin * self;
	self = RYGEL_PLUGIN (object);
	switch (property_id) {
		case RYGEL_PLUGIN_AVAILABLE:
		rygel_plugin_set_available (self, g_value_get_boolean (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




