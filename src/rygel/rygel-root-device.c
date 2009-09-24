/*
 * Copyright (C) 2008 Nokia Corporation.
 * Copyright (C) 2008 Zeeshan Ali (Khattak) <zeeshanak@gnome.org>.
 *
 * Author: Zeeshan Ali (Khattak) <zeeshanak@gnome.org>
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
#include <gee.h>
#include <stdlib.h>
#include <string.h>


#define RYGEL_TYPE_ROOT_DEVICE (rygel_root_device_get_type ())
#define RYGEL_ROOT_DEVICE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_ROOT_DEVICE, RygelRootDevice))
#define RYGEL_ROOT_DEVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_ROOT_DEVICE, RygelRootDeviceClass))
#define RYGEL_IS_ROOT_DEVICE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_ROOT_DEVICE))
#define RYGEL_IS_ROOT_DEVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_ROOT_DEVICE))
#define RYGEL_ROOT_DEVICE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_ROOT_DEVICE, RygelRootDeviceClass))

typedef struct _RygelRootDevice RygelRootDevice;
typedef struct _RygelRootDeviceClass RygelRootDeviceClass;
typedef struct _RygelRootDevicePrivate RygelRootDevicePrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

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
typedef struct _RygelResourceInfoPrivate RygelResourceInfoPrivate;
#define _rygel_resource_info_unref0(var) ((var == NULL) ? NULL : (var = (rygel_resource_info_unref (var), NULL)))

struct _RygelRootDevice {
	GUPnPRootDevice parent_instance;
	RygelRootDevicePrivate * priv;
	GeeArrayList* services;
};

struct _RygelRootDeviceClass {
	GUPnPRootDeviceClass parent_class;
};

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


static gpointer rygel_root_device_parent_class = NULL;

GType rygel_root_device_get_type (void);
enum  {
	RYGEL_ROOT_DEVICE_DUMMY_PROPERTY
};
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
RygelRootDevice* rygel_root_device_new (GUPnPContext* context, RygelPlugin* plugin, GUPnPXMLDoc* description_doc, const char* description_path, const char* description_dir);
RygelRootDevice* rygel_root_device_construct (GType object_type, GUPnPContext* context, RygelPlugin* plugin, GUPnPXMLDoc* description_doc, const char* description_path, const char* description_dir);
static void rygel_root_device_finalize (GObject* obj);



RygelRootDevice* rygel_root_device_construct (GType object_type, GUPnPContext* context, RygelPlugin* plugin, GUPnPXMLDoc* description_doc, const char* description_path, const char* description_dir) {
	GParameter * __params;
	GParameter * __params_it;
	RygelRootDevice * self;
	GeeArrayList* _tmp0_;
	g_return_val_if_fail (context != NULL, NULL);
	g_return_val_if_fail (plugin != NULL, NULL);
	g_return_val_if_fail (description_doc != NULL, NULL);
	g_return_val_if_fail (description_path != NULL, NULL);
	g_return_val_if_fail (description_dir != NULL, NULL);
	__params = g_new0 (GParameter, 6);
	__params_it = __params;
	__params_it->name = "resource-factory";
	g_value_init (&__params_it->value, GUPNP_TYPE_RESOURCE_FACTORY);
	g_value_set_object (&__params_it->value, (GUPnPResourceFactory*) plugin);
	__params_it++;
	__params_it->name = "root-device";
	g_value_init (&__params_it->value, GUPNP_TYPE_ROOT_DEVICE);
	g_value_set_object (&__params_it->value, NULL);
	__params_it++;
	__params_it->name = "context";
	g_value_init (&__params_it->value, GUPNP_TYPE_CONTEXT);
	g_value_set_object (&__params_it->value, context);
	__params_it++;
	__params_it->name = "description-doc";
	g_value_init (&__params_it->value, GUPNP_TYPE_XML_DOC);
	g_value_set_object (&__params_it->value, description_doc);
	__params_it++;
	__params_it->name = "description-path";
	g_value_init (&__params_it->value, G_TYPE_STRING);
	g_value_set_string (&__params_it->value, description_path);
	__params_it++;
	__params_it->name = "description-dir";
	g_value_init (&__params_it->value, G_TYPE_STRING);
	g_value_set_string (&__params_it->value, description_dir);
	__params_it++;
	self = g_object_newv (object_type, __params_it - __params, __params);
	self->services = (_tmp0_ = gee_array_list_new (GUPNP_TYPE_SERVICE_INFO, (GBoxedCopyFunc) g_object_ref, g_object_unref, g_direct_equal), _g_object_unref0 (self->services), _tmp0_);
	{
		GeeIterator* _info_it;
		_info_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) plugin->resource_infos);
		while (TRUE) {
			RygelResourceInfo* info;
			if (!gee_iterator_next (_info_it)) {
				break;
			}
			info = (RygelResourceInfo*) gee_iterator_get (_info_it);
			if (g_type_is_a (info->type, GUPNP_TYPE_SERVICE)) {
				GUPnPServiceInfo* service;
				service = gupnp_device_info_get_service ((GUPnPDeviceInfo*) self, info->upnp_type);
				gee_abstract_collection_add ((GeeAbstractCollection*) self->services, service);
				_g_object_unref0 (service);
			}
			_rygel_resource_info_unref0 (info);
		}
		_g_object_unref0 (_info_it);
	}
	while (__params_it > __params) {
		--__params_it;
		g_value_unset (&__params_it->value);
	}
	g_free (__params);
	return self;
}


RygelRootDevice* rygel_root_device_new (GUPnPContext* context, RygelPlugin* plugin, GUPnPXMLDoc* description_doc, const char* description_path, const char* description_dir) {
	return rygel_root_device_construct (RYGEL_TYPE_ROOT_DEVICE, context, plugin, description_doc, description_path, description_dir);
}


static void rygel_root_device_class_init (RygelRootDeviceClass * klass) {
	rygel_root_device_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = rygel_root_device_finalize;
}


static void rygel_root_device_instance_init (RygelRootDevice * self) {
}


static void rygel_root_device_finalize (GObject* obj) {
	RygelRootDevice * self;
	self = RYGEL_ROOT_DEVICE (obj);
	_g_object_unref0 (self->services);
	G_OBJECT_CLASS (rygel_root_device_parent_class)->finalize (obj);
}


GType rygel_root_device_get_type (void) {
	static GType rygel_root_device_type_id = 0;
	if (rygel_root_device_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelRootDeviceClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_root_device_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelRootDevice), 0, (GInstanceInitFunc) rygel_root_device_instance_init, NULL };
		rygel_root_device_type_id = g_type_register_static (GUPNP_TYPE_ROOT_DEVICE, "RygelRootDevice", &g_define_type_info, 0);
	}
	return rygel_root_device_type_id;
}



