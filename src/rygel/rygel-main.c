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
#include <glib/gi18n-lib.h>
#include <cstuff.h>
#include <libgssdp/gssdp.h>
#include <gst/gst.h>


#define RYGEL_TYPE_MAIN (rygel_main_get_type ())
#define RYGEL_MAIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MAIN, RygelMain))
#define RYGEL_MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MAIN, RygelMainClass))
#define RYGEL_IS_MAIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MAIN))
#define RYGEL_IS_MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MAIN))
#define RYGEL_MAIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MAIN, RygelMainClass))

typedef struct _RygelMain RygelMain;
typedef struct _RygelMainClass RygelMainClass;
typedef struct _RygelMainPrivate RygelMainPrivate;

#define RYGEL_TYPE_PLUGIN_LOADER (rygel_plugin_loader_get_type ())
#define RYGEL_PLUGIN_LOADER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_PLUGIN_LOADER, RygelPluginLoader))
#define RYGEL_PLUGIN_LOADER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_PLUGIN_LOADER, RygelPluginLoaderClass))
#define RYGEL_IS_PLUGIN_LOADER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_PLUGIN_LOADER))
#define RYGEL_IS_PLUGIN_LOADER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_PLUGIN_LOADER))
#define RYGEL_PLUGIN_LOADER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_PLUGIN_LOADER, RygelPluginLoaderClass))

typedef struct _RygelPluginLoader RygelPluginLoader;
typedef struct _RygelPluginLoaderClass RygelPluginLoaderClass;

#define RYGEL_TYPE_ROOT_DEVICE_FACTORY (rygel_root_device_factory_get_type ())
#define RYGEL_ROOT_DEVICE_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_ROOT_DEVICE_FACTORY, RygelRootDeviceFactory))
#define RYGEL_ROOT_DEVICE_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_ROOT_DEVICE_FACTORY, RygelRootDeviceFactoryClass))
#define RYGEL_IS_ROOT_DEVICE_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_ROOT_DEVICE_FACTORY))
#define RYGEL_IS_ROOT_DEVICE_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_ROOT_DEVICE_FACTORY))
#define RYGEL_ROOT_DEVICE_FACTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_ROOT_DEVICE_FACTORY, RygelRootDeviceFactoryClass))

typedef struct _RygelRootDeviceFactory RygelRootDeviceFactory;
typedef struct _RygelRootDeviceFactoryClass RygelRootDeviceFactoryClass;

#define RYGEL_TYPE_ROOT_DEVICE (rygel_root_device_get_type ())
#define RYGEL_ROOT_DEVICE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_ROOT_DEVICE, RygelRootDevice))
#define RYGEL_ROOT_DEVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_ROOT_DEVICE, RygelRootDeviceClass))
#define RYGEL_IS_ROOT_DEVICE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_ROOT_DEVICE))
#define RYGEL_IS_ROOT_DEVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_ROOT_DEVICE))
#define RYGEL_ROOT_DEVICE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_ROOT_DEVICE, RygelRootDeviceClass))

typedef struct _RygelRootDevice RygelRootDevice;
typedef struct _RygelRootDeviceClass RygelRootDeviceClass;

#define RYGEL_TYPE_CONFIGURATION (rygel_configuration_get_type ())
#define RYGEL_CONFIGURATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_CONFIGURATION, RygelConfiguration))
#define RYGEL_IS_CONFIGURATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_CONFIGURATION))
#define RYGEL_CONFIGURATION_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), RYGEL_TYPE_CONFIGURATION, RygelConfigurationIface))

typedef struct _RygelConfiguration RygelConfiguration;
typedef struct _RygelConfigurationIface RygelConfigurationIface;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_main_loop_unref0(var) ((var == NULL) ? NULL : (var = (g_main_loop_unref (var), NULL)))

#define RYGEL_TYPE_META_CONFIG (rygel_meta_config_get_type ())
#define RYGEL_META_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_META_CONFIG, RygelMetaConfig))
#define RYGEL_META_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_META_CONFIG, RygelMetaConfigClass))
#define RYGEL_IS_META_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_META_CONFIG))
#define RYGEL_IS_META_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_META_CONFIG))
#define RYGEL_META_CONFIG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_META_CONFIG, RygelMetaConfigClass))

typedef struct _RygelMetaConfig RygelMetaConfig;
typedef struct _RygelMetaConfigClass RygelMetaConfigClass;

#define RYGEL_TYPE_PLUGIN (rygel_plugin_get_type ())
#define RYGEL_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_PLUGIN, RygelPlugin))
#define RYGEL_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_PLUGIN, RygelPluginClass))
#define RYGEL_IS_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_PLUGIN))
#define RYGEL_IS_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_PLUGIN))
#define RYGEL_PLUGIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_PLUGIN, RygelPluginClass))

typedef struct _RygelPlugin RygelPlugin;
typedef struct _RygelPluginClass RygelPluginClass;
#define _rygel_root_device_factory_unref0(var) ((var == NULL) ? NULL : (var = (rygel_root_device_factory_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _RygelRootDeviceFactoryPrivate RygelRootDeviceFactoryPrivate;
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

#define RYGEL_TYPE_DBUS_SERVICE (rygel_dbus_service_get_type ())
#define RYGEL_DBUS_SERVICE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_DBUS_SERVICE, RygelDBusService))
#define RYGEL_DBUS_SERVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_DBUS_SERVICE, RygelDBusServiceClass))
#define RYGEL_IS_DBUS_SERVICE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_DBUS_SERVICE))
#define RYGEL_IS_DBUS_SERVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_DBUS_SERVICE))
#define RYGEL_DBUS_SERVICE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_DBUS_SERVICE, RygelDBusServiceClass))

typedef struct _RygelDBusService RygelDBusService;
typedef struct _RygelDBusServiceClass RygelDBusServiceClass;

struct _RygelMain {
	GObject parent_instance;
	RygelMainPrivate * priv;
};

struct _RygelMainClass {
	GObjectClass parent_class;
};

struct _RygelConfigurationIface {
	GTypeInterface parent_iface;
	gboolean (*get_upnp_enabled) (RygelConfiguration* self, GError** error);
	char* (*get_interface) (RygelConfiguration* self, GError** error);
	gint (*get_port) (RygelConfiguration* self, GError** error);
	gboolean (*get_transcoding) (RygelConfiguration* self, GError** error);
	gboolean (*get_mp3_transcoder) (RygelConfiguration* self, GError** error);
	gboolean (*get_mp2ts_transcoder) (RygelConfiguration* self, GError** error);
	gboolean (*get_lpcm_transcoder) (RygelConfiguration* self, GError** error);
	gboolean (*get_enabled) (RygelConfiguration* self, const char* section, GError** error);
	char* (*get_title) (RygelConfiguration* self, const char* section, GError** error);
	char* (*get_string) (RygelConfiguration* self, const char* section, const char* key, GError** error);
	GeeArrayList* (*get_string_list) (RygelConfiguration* self, const char* section, const char* key, GError** error);
	gint (*get_int) (RygelConfiguration* self, const char* section, const char* key, gint min, gint max, GError** error);
	GeeArrayList* (*get_int_list) (RygelConfiguration* self, const char* section, const char* key, GError** error);
	gboolean (*get_bool) (RygelConfiguration* self, const char* section, const char* key, GError** error);
};

struct _RygelMainPrivate {
	RygelPluginLoader* plugin_loader;
	GUPnPContextManager* context_manager;
	GeeArrayList* factories;
	GeeArrayList* root_devices;
	RygelConfiguration* config;
	GMainLoop* main_loop;
	gint exit_code;
};

struct _RygelRootDeviceFactory {
	GTypeInstance parent_instance;
	volatile int ref_count;
	RygelRootDeviceFactoryPrivate * priv;
	GUPnPContext* context;
};

struct _RygelRootDeviceFactoryClass {
	GTypeClass parent_class;
	void (*finalize) (RygelRootDeviceFactory *self);
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

typedef enum  {
	RYGEL_CMDLINE_CONFIG_ERROR_VERSION_ONLY
} RygelCmdlineConfigError;
#define RYGEL_CMDLINE_CONFIG_ERROR rygel_cmdline_config_error_quark ()

static gpointer rygel_main_parent_class = NULL;

GType rygel_main_get_type (void);
GType rygel_plugin_loader_get_type (void);
gpointer rygel_root_device_factory_ref (gpointer instance);
void rygel_root_device_factory_unref (gpointer instance);
GParamSpec* rygel_param_spec_root_device_factory (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_root_device_factory (GValue* value, gpointer v_object);
gpointer rygel_value_get_root_device_factory (const GValue* value);
GType rygel_root_device_factory_get_type (void);
GType rygel_root_device_get_type (void);
GType rygel_configuration_get_type (void);
#define RYGEL_MAIN_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_MAIN, RygelMainPrivate))
enum  {
	RYGEL_MAIN_DUMMY_PROPERTY
};
GType rygel_meta_config_get_type (void);
RygelMetaConfig* rygel_meta_config_get_default (void);
RygelPluginLoader* rygel_plugin_loader_new (void);
RygelPluginLoader* rygel_plugin_loader_construct (GType object_type);
static GUPnPContextManager* rygel_main_create_context_manager (RygelMain* self);
GType rygel_plugin_get_type (void);
static void rygel_main_on_plugin_loaded (RygelMain* self, RygelPluginLoader* plugin_loader, RygelPlugin* plugin);
static void _rygel_main_on_plugin_loaded_rygel_plugin_loader_plugin_available (RygelPluginLoader* _sender, RygelPlugin* plugin, gpointer self);
static void rygel_main_application_exit_cb (RygelMain* self);
static void _rygel_main_application_exit_cb_cstuff_utils_application_exit_cb (gpointer self);
static RygelMain* rygel_main_new (GError** error);
static RygelMain* rygel_main_construct (GType object_type, GError** error);
void rygel_main_exit (RygelMain* self, gint exit_code);
void rygel_plugin_loader_load_plugins (RygelPluginLoader* self);
static gint rygel_main_run (RygelMain* self);
static void rygel_main_create_device (RygelMain* self, RygelPlugin* plugin, RygelRootDeviceFactory* factory);
gint rygel_configuration_get_port (RygelConfiguration* self, GError** error);
static void rygel_main_on_context_available (RygelMain* self, GUPnPContextManager* manager, GUPnPContext* context);
static void _rygel_main_on_context_available_gupnp_context_manager_context_available (GUPnPContextManager* _sender, GUPnPContext* p0, gpointer self);
static void rygel_main_on_context_unavailable (RygelMain* self, GUPnPContextManager* manager, GUPnPContext* context);
static void _rygel_main_on_context_unavailable_gupnp_context_manager_context_unavailable (GUPnPContextManager* _sender, GUPnPContext* p0, gpointer self);
char* rygel_configuration_get_interface (RygelConfiguration* self, GError** error);
RygelRootDeviceFactory* rygel_root_device_factory_new (GUPnPContext* context, GError** error);
RygelRootDeviceFactory* rygel_root_device_factory_construct (GType object_type, GUPnPContext* context, GError** error);
GeeCollection* rygel_plugin_loader_list_plugins (RygelPluginLoader* self);
RygelRootDevice* rygel_root_device_factory_create (RygelRootDeviceFactory* self, RygelPlugin* plugin, GError** error);
gboolean rygel_plugin_get_available (RygelPlugin* self);
static void rygel_main_on_plugin_notify (RygelMain* self, RygelPlugin* plugin, GParamSpec* spec);
static void _rygel_main_on_plugin_notify_g_object_notify (RygelPlugin* _sender, GParamSpec* pspec, gpointer self);
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
GType rygel_dbus_service_get_type (void);
GQuark rygel_cmdline_config_error_quark (void);
void rygel_cmdline_config_parse_args (char*** args, int* args_length1, GError** error);
RygelDBusService* rygel_dbus_service_new (RygelMain* main, GError** error);
RygelDBusService* rygel_dbus_service_construct (GType object_type, RygelMain* main, GError** error);
static gint rygel_main_main (char** args, int args_length1);
static void rygel_main_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static int _vala_strcmp0 (const char * str1, const char * str2);



static void _rygel_main_on_plugin_loaded_rygel_plugin_loader_plugin_available (RygelPluginLoader* _sender, RygelPlugin* plugin, gpointer self) {
	rygel_main_on_plugin_loaded (self, _sender, plugin);
}


static void _rygel_main_application_exit_cb_cstuff_utils_application_exit_cb (gpointer self) {
	rygel_main_application_exit_cb (self);
}


static RygelMain* rygel_main_construct (GType object_type, GError** error) {
	RygelMain * self;
	RygelConfiguration* _tmp0_;
	RygelPluginLoader* _tmp1_;
	GeeArrayList* _tmp2_;
	GeeArrayList* _tmp3_;
	GUPnPContextManager* _tmp4_;
	GMainLoop* _tmp5_;
	self = (RygelMain*) g_object_new (object_type, NULL);
	g_set_application_name (_ (PACKAGE_NAME));
	self->priv->config = (_tmp0_ = (RygelConfiguration*) rygel_meta_config_get_default (), _g_object_unref0 (self->priv->config), _tmp0_);
	self->priv->plugin_loader = (_tmp1_ = rygel_plugin_loader_new (), _g_object_unref0 (self->priv->plugin_loader), _tmp1_);
	self->priv->root_devices = (_tmp2_ = gee_array_list_new (RYGEL_TYPE_ROOT_DEVICE, (GBoxedCopyFunc) g_object_ref, g_object_unref, g_direct_equal), _g_object_unref0 (self->priv->root_devices), _tmp2_);
	self->priv->factories = (_tmp3_ = gee_array_list_new (RYGEL_TYPE_ROOT_DEVICE_FACTORY, (GBoxedCopyFunc) rygel_root_device_factory_ref, rygel_root_device_factory_unref, g_direct_equal), _g_object_unref0 (self->priv->factories), _tmp3_);
	self->priv->context_manager = (_tmp4_ = rygel_main_create_context_manager (self), _g_object_unref0 (self->priv->context_manager), _tmp4_);
	self->priv->main_loop = (_tmp5_ = g_main_loop_new (NULL, FALSE), _g_main_loop_unref0 (self->priv->main_loop), _tmp5_);
	self->priv->exit_code = 0;
	g_signal_connect_object (self->priv->plugin_loader, "plugin-available", (GCallback) _rygel_main_on_plugin_loaded_rygel_plugin_loader_plugin_available, self, 0);
	on_application_exit (_rygel_main_application_exit_cb_cstuff_utils_application_exit_cb, self);
	return self;
}


static RygelMain* rygel_main_new (GError** error) {
	return rygel_main_construct (RYGEL_TYPE_MAIN, error);
}


void rygel_main_exit (RygelMain* self, gint exit_code) {
	g_return_if_fail (self != NULL);
	self->priv->exit_code = exit_code;
	g_main_loop_quit (self->priv->main_loop);
}


static gint rygel_main_run (RygelMain* self) {
	gint result;
	g_return_val_if_fail (self != NULL, 0);
	rygel_plugin_loader_load_plugins (self->priv->plugin_loader);
	g_main_loop_run (self->priv->main_loop);
	result = self->priv->exit_code;
	return result;
}


static void rygel_main_application_exit_cb (RygelMain* self) {
	g_return_if_fail (self != NULL);
	rygel_main_exit (self, 0);
}


static void rygel_main_on_plugin_loaded (RygelMain* self, RygelPluginLoader* plugin_loader, RygelPlugin* plugin) {
	GeeArrayList* factories;
	g_return_if_fail (self != NULL);
	g_return_if_fail (plugin_loader != NULL);
	g_return_if_fail (plugin != NULL);
	factories = gee_array_list_new (RYGEL_TYPE_ROOT_DEVICE_FACTORY, (GBoxedCopyFunc) rygel_root_device_factory_ref, rygel_root_device_factory_unref, g_direct_equal);
	{
		GeeIterator* _factory_it;
		_factory_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->factories);
		while (TRUE) {
			RygelRootDeviceFactory* factory;
			if (!gee_iterator_next (_factory_it)) {
				break;
			}
			factory = (RygelRootDeviceFactory*) gee_iterator_get (_factory_it);
			gee_abstract_collection_add ((GeeAbstractCollection*) factories, factory);
			_rygel_root_device_factory_unref0 (factory);
		}
		_g_object_unref0 (_factory_it);
	}
	{
		GeeIterator* _factory_it;
		_factory_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) factories);
		while (TRUE) {
			RygelRootDeviceFactory* factory;
			if (!gee_iterator_next (_factory_it)) {
				break;
			}
			factory = (RygelRootDeviceFactory*) gee_iterator_get (_factory_it);
			rygel_main_create_device (self, plugin, factory);
			_rygel_root_device_factory_unref0 (factory);
		}
		_g_object_unref0 (_factory_it);
	}
	_g_object_unref0 (factories);
}


static void _rygel_main_on_context_available_gupnp_context_manager_context_available (GUPnPContextManager* _sender, GUPnPContext* p0, gpointer self) {
	rygel_main_on_context_available (self, _sender, p0);
}


static void _rygel_main_on_context_unavailable_gupnp_context_manager_context_unavailable (GUPnPContextManager* _sender, GUPnPContext* p0, gpointer self) {
	rygel_main_on_context_unavailable (self, _sender, p0);
}


static GUPnPContextManager* rygel_main_create_context_manager (RygelMain* self) {
	GUPnPContextManager* result;
	GError * _inner_error_;
	gint port;
	GUPnPContextManager* manager;
	g_return_val_if_fail (self != NULL, NULL);
	_inner_error_ = NULL;
	port = 0;
	{
		gint _tmp0_;
		_tmp0_ = rygel_configuration_get_port (self->priv->config, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch47_g_error;
			goto __finally47;
		}
		port = _tmp0_;
	}
	goto __finally47;
	__catch47_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			_g_error_free0 (err);
		}
	}
	__finally47:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	manager = gupnp_context_manager_new (NULL, (guint) port);
	g_signal_connect_object (manager, "context-available", (GCallback) _rygel_main_on_context_available_gupnp_context_manager_context_available, self, 0);
	g_signal_connect_object (manager, "context-unavailable", (GCallback) _rygel_main_on_context_unavailable_gupnp_context_manager_context_unavailable, self, 0);
	result = manager;
	return result;
}


static void rygel_main_on_context_available (RygelMain* self, GUPnPContextManager* manager, GUPnPContext* context) {
	GError * _inner_error_;
	char* iface;
	gboolean _tmp2_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (manager != NULL);
	g_return_if_fail (context != NULL);
	_inner_error_ = NULL;
	iface = NULL;
	g_debug ("rygel-main.vala:108: new network context %s (%s) available.", gssdp_client_get_interface ((GSSDPClient*) context), gssdp_client_get_host_ip ((GSSDPClient*) context));
	{
		char* _tmp0_;
		char* _tmp1_;
		_tmp0_ = rygel_configuration_get_interface (self->priv->config, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch48_g_error;
			goto __finally48;
		}
		iface = (_tmp1_ = _tmp0_, _g_free0 (iface), _tmp1_);
	}
	goto __finally48;
	__catch48_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			_g_error_free0 (err);
		}
	}
	__finally48:
	if (_inner_error_ != NULL) {
		_g_free0 (iface);
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp2_ = FALSE;
	if (iface == NULL) {
		_tmp2_ = TRUE;
	} else {
		_tmp2_ = _vala_strcmp0 (iface, gssdp_client_get_interface ((GSSDPClient*) context)) == 0;
	}
	if (_tmp2_) {
		RygelRootDeviceFactory* factory;
		GeeArrayList* plugins;
		factory = rygel_root_device_factory_new (context, &_inner_error_);
		if (_inner_error_ != NULL) {
			_g_free0 (iface);
			g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
			g_clear_error (&_inner_error_);
			return;
		}
		gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->factories, factory);
		plugins = gee_array_list_new (RYGEL_TYPE_PLUGIN, (GBoxedCopyFunc) g_object_ref, g_object_unref, g_direct_equal);
		{
			GeeCollection* _tmp3_;
			GeeIterator* _tmp4_;
			GeeIterator* _plugin_it;
			_plugin_it = (_tmp4_ = gee_iterable_iterator ((GeeIterable*) (_tmp3_ = rygel_plugin_loader_list_plugins (self->priv->plugin_loader))), _g_object_unref0 (_tmp3_), _tmp4_);
			while (TRUE) {
				RygelPlugin* plugin;
				if (!gee_iterator_next (_plugin_it)) {
					break;
				}
				plugin = (RygelPlugin*) gee_iterator_get (_plugin_it);
				gee_abstract_collection_add ((GeeAbstractCollection*) plugins, plugin);
				_g_object_unref0 (plugin);
			}
			_g_object_unref0 (_plugin_it);
		}
		{
			GeeIterator* _plugin_it;
			_plugin_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) plugins);
			while (TRUE) {
				RygelPlugin* plugin;
				if (!gee_iterator_next (_plugin_it)) {
					break;
				}
				plugin = (RygelPlugin*) gee_iterator_get (_plugin_it);
				rygel_main_create_device (self, plugin, factory);
				_g_object_unref0 (plugin);
			}
			_g_object_unref0 (_plugin_it);
		}
		_rygel_root_device_factory_unref0 (factory);
		_g_object_unref0 (plugins);
	} else {
		g_debug ("rygel-main.vala:130: Ignoring network context %s (%s).", gssdp_client_get_interface ((GSSDPClient*) context), gssdp_client_get_host_ip ((GSSDPClient*) context));
	}
	_g_free0 (iface);
}


static void rygel_main_on_context_unavailable (RygelMain* self, GUPnPContextManager* manager, GUPnPContext* context) {
	GeeArrayList* factory_list;
	GeeArrayList* device_list;
	g_return_if_fail (self != NULL);
	g_return_if_fail (manager != NULL);
	g_return_if_fail (context != NULL);
	g_debug ("rygel-main.vala:138: Network context %s (%s) now unavailable.", gssdp_client_get_interface ((GSSDPClient*) context), gssdp_client_get_host_ip ((GSSDPClient*) context));
	factory_list = gee_array_list_new (RYGEL_TYPE_ROOT_DEVICE_FACTORY, (GBoxedCopyFunc) rygel_root_device_factory_ref, rygel_root_device_factory_unref, g_direct_equal);
	{
		GeeIterator* _factory_it;
		_factory_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->factories);
		while (TRUE) {
			RygelRootDeviceFactory* factory;
			if (!gee_iterator_next (_factory_it)) {
				break;
			}
			factory = (RygelRootDeviceFactory*) gee_iterator_get (_factory_it);
			if (context == factory->context) {
				gee_abstract_collection_add ((GeeAbstractCollection*) factory_list, factory);
			}
			_rygel_root_device_factory_unref0 (factory);
		}
		_g_object_unref0 (_factory_it);
	}
	{
		GeeIterator* _factory_it;
		_factory_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) factory_list);
		while (TRUE) {
			RygelRootDeviceFactory* factory;
			if (!gee_iterator_next (_factory_it)) {
				break;
			}
			factory = (RygelRootDeviceFactory*) gee_iterator_get (_factory_it);
			gee_abstract_collection_remove ((GeeAbstractCollection*) self->priv->factories, factory);
			_rygel_root_device_factory_unref0 (factory);
		}
		_g_object_unref0 (_factory_it);
	}
	device_list = gee_array_list_new (RYGEL_TYPE_ROOT_DEVICE, (GBoxedCopyFunc) g_object_ref, g_object_unref, g_direct_equal);
	{
		GeeIterator* _device_it;
		_device_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->root_devices);
		while (TRUE) {
			RygelRootDevice* device;
			if (!gee_iterator_next (_device_it)) {
				break;
			}
			device = (RygelRootDevice*) gee_iterator_get (_device_it);
			if (context == gupnp_device_info_get_context ((GUPnPDeviceInfo*) device)) {
				gee_abstract_collection_add ((GeeAbstractCollection*) device_list, device);
			}
			_g_object_unref0 (device);
		}
		_g_object_unref0 (_device_it);
	}
	{
		GeeIterator* _device_it;
		_device_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) device_list);
		while (TRUE) {
			RygelRootDevice* device;
			if (!gee_iterator_next (_device_it)) {
				break;
			}
			device = (RygelRootDevice*) gee_iterator_get (_device_it);
			gee_abstract_collection_remove ((GeeAbstractCollection*) self->priv->root_devices, device);
			_g_object_unref0 (device);
		}
		_g_object_unref0 (_device_it);
	}
	_g_object_unref0 (factory_list);
	_g_object_unref0 (device_list);
}


static void _rygel_main_on_plugin_notify_g_object_notify (RygelPlugin* _sender, GParamSpec* pspec, gpointer self) {
	rygel_main_on_plugin_notify (self, _sender, pspec);
}


static void rygel_main_create_device (RygelMain* self, RygelPlugin* plugin, RygelRootDeviceFactory* factory) {
	GError * _inner_error_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (plugin != NULL);
	g_return_if_fail (factory != NULL);
	_inner_error_ = NULL;
	{
		RygelRootDevice* device;
		device = rygel_root_device_factory_create (factory, plugin, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch49_g_error;
			goto __finally49;
		}
		gupnp_root_device_set_available ((GUPnPRootDevice*) device, rygel_plugin_get_available (plugin));
		gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->root_devices, device);
		g_signal_connect_object ((GObject*) plugin, "notify::available", (GCallback) _rygel_main_on_plugin_notify_g_object_notify, self, 0);
		_g_object_unref0 (device);
	}
	goto __finally49;
	__catch49_g_error:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
			g_warning ("rygel-main.vala:176: Failed to create RootDevice for %s. Reason: %s\n", plugin->name, _error_->message);
			_g_error_free0 (_error_);
		}
	}
	__finally49:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return;
	}
}


static void rygel_main_on_plugin_notify (RygelMain* self, RygelPlugin* plugin, GParamSpec* spec) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (plugin != NULL);
	g_return_if_fail (spec != NULL);
	{
		GeeIterator* _device_it;
		_device_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->root_devices);
		while (TRUE) {
			RygelRootDevice* device;
			if (!gee_iterator_next (_device_it)) {
				break;
			}
			device = (RygelRootDevice*) gee_iterator_get (_device_it);
			if (gupnp_device_info_get_resource_factory ((GUPnPDeviceInfo*) device) == GUPNP_RESOURCE_FACTORY (plugin)) {
				gupnp_root_device_set_available ((GUPnPRootDevice*) device, rygel_plugin_get_available (plugin));
			}
			_g_object_unref0 (device);
		}
		_g_object_unref0 (_device_it);
	}
}


static gint rygel_main_main (char** args, int args_length1) {
	gint result;
	GError * _inner_error_;
	RygelMain* main;
	RygelDBusService* service;
	gint exit_code;
	_inner_error_ = NULL;
	main = NULL;
	service = NULL;
	{
		char** _tmp0_;
		gint dummy_args_size;
		gint dummy_args_length1;
		char** dummy_args;
		RygelMain* _tmp1_;
		RygelMain* _tmp2_;
		RygelDBusService* _tmp3_;
		RygelDBusService* _tmp4_;
		rygel_cmdline_config_parse_args (&args, &args_length1, &_inner_error_);
		if (_inner_error_ != NULL) {
			if (g_error_matches (_inner_error_, RYGEL_CMDLINE_CONFIG_ERROR, RYGEL_CMDLINE_CONFIG_ERROR_VERSION_ONLY)) {
				goto __catch50_rygel_cmdline_config_error_version_only;
			}
			goto __catch50_g_error;
			goto __finally50;
		}
		dummy_args = (_tmp0_ = g_new0 (char*, 0 + 1), dummy_args_length1 = 0, dummy_args_size = dummy_args_length1, _tmp0_);
		gst_init (&dummy_args_length1, &dummy_args);
		_tmp1_ = rygel_main_new (&_inner_error_);
		if (_inner_error_ != NULL) {
			dummy_args = (_vala_array_free (dummy_args, dummy_args_length1, (GDestroyNotify) g_free), NULL);
			if (g_error_matches (_inner_error_, RYGEL_CMDLINE_CONFIG_ERROR, RYGEL_CMDLINE_CONFIG_ERROR_VERSION_ONLY)) {
				goto __catch50_rygel_cmdline_config_error_version_only;
			}
			goto __catch50_g_error;
			goto __finally50;
		}
		main = (_tmp2_ = _tmp1_, _g_object_unref0 (main), _tmp2_);
		_tmp3_ = rygel_dbus_service_new (main, &_inner_error_);
		if (_inner_error_ != NULL) {
			dummy_args = (_vala_array_free (dummy_args, dummy_args_length1, (GDestroyNotify) g_free), NULL);
			if (g_error_matches (_inner_error_, RYGEL_CMDLINE_CONFIG_ERROR, RYGEL_CMDLINE_CONFIG_ERROR_VERSION_ONLY)) {
				goto __catch50_rygel_cmdline_config_error_version_only;
			}
			goto __catch50_g_error;
			goto __finally50;
		}
		service = (_tmp4_ = _tmp3_, _g_object_unref0 (service), _tmp4_);
		dummy_args = (_vala_array_free (dummy_args, dummy_args_length1, (GDestroyNotify) g_free), NULL);
	}
	goto __finally50;
	__catch50_rygel_cmdline_config_error_version_only:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			result = 0;
			_g_error_free0 (err);
			_g_object_unref0 (main);
			_g_object_unref0 (service);
			return result;
		}
	}
	goto __finally50;
	__catch50_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			g_error ("rygel-main.vala:208: %s", err->message);
			result = -1;
			_g_error_free0 (err);
			_g_object_unref0 (main);
			_g_object_unref0 (service);
			return result;
		}
	}
	__finally50:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (main);
		_g_object_unref0 (service);
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return 0;
	}
	exit_code = rygel_main_run (main);
	result = exit_code;
	_g_object_unref0 (main);
	_g_object_unref0 (service);
	return result;
}


int main (int argc, char ** argv) {
	g_thread_init (NULL);
	g_type_init ();
	return rygel_main_main (argv, argc);
}


static void rygel_main_class_init (RygelMainClass * klass) {
	rygel_main_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelMainPrivate));
	G_OBJECT_CLASS (klass)->finalize = rygel_main_finalize;
}


static void rygel_main_instance_init (RygelMain * self) {
	self->priv = RYGEL_MAIN_GET_PRIVATE (self);
}


static void rygel_main_finalize (GObject* obj) {
	RygelMain * self;
	self = RYGEL_MAIN (obj);
	_g_object_unref0 (self->priv->plugin_loader);
	_g_object_unref0 (self->priv->context_manager);
	_g_object_unref0 (self->priv->factories);
	_g_object_unref0 (self->priv->root_devices);
	_g_object_unref0 (self->priv->config);
	_g_main_loop_unref0 (self->priv->main_loop);
	G_OBJECT_CLASS (rygel_main_parent_class)->finalize (obj);
}


GType rygel_main_get_type (void) {
	static GType rygel_main_type_id = 0;
	if (rygel_main_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMainClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_main_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMain), 0, (GInstanceInitFunc) rygel_main_instance_init, NULL };
		rygel_main_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelMain", &g_define_type_info, 0);
	}
	return rygel_main_type_id;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static int _vala_strcmp0 (const char * str1, const char * str2) {
	if (str1 == NULL) {
		return -(str1 != str2);
	}
	if (str2 == NULL) {
		return str1 != str2;
	}
	return strcmp (str1, str2);
}




