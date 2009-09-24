/*
 * Copyright (C) 2008 Nokia Corporation.
 * Copyright (C) 2008 Zeeshan Ali (Khattak) <zeeshanak@gnome.org>.
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
#include <libxml/tree.h>
#include <cstuff.h>
#include <stdio.h>
#include <libxml/parser.h>
#include <gio/gio.h>
#include <gobject/gvaluecollector.h>


#define RYGEL_TYPE_ROOT_DEVICE_FACTORY (rygel_root_device_factory_get_type ())
#define RYGEL_ROOT_DEVICE_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_ROOT_DEVICE_FACTORY, RygelRootDeviceFactory))
#define RYGEL_ROOT_DEVICE_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_ROOT_DEVICE_FACTORY, RygelRootDeviceFactoryClass))
#define RYGEL_IS_ROOT_DEVICE_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_ROOT_DEVICE_FACTORY))
#define RYGEL_IS_ROOT_DEVICE_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_ROOT_DEVICE_FACTORY))
#define RYGEL_ROOT_DEVICE_FACTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_ROOT_DEVICE_FACTORY, RygelRootDeviceFactoryClass))

typedef struct _RygelRootDeviceFactory RygelRootDeviceFactory;
typedef struct _RygelRootDeviceFactoryClass RygelRootDeviceFactoryClass;
typedef struct _RygelRootDeviceFactoryPrivate RygelRootDeviceFactoryPrivate;

#define RYGEL_TYPE_CONFIGURATION (rygel_configuration_get_type ())
#define RYGEL_CONFIGURATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_CONFIGURATION, RygelConfiguration))
#define RYGEL_IS_CONFIGURATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_CONFIGURATION))
#define RYGEL_CONFIGURATION_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), RYGEL_TYPE_CONFIGURATION, RygelConfigurationIface))

typedef struct _RygelConfiguration RygelConfiguration;
typedef struct _RygelConfigurationIface RygelConfigurationIface;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

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
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

#define RYGEL_TYPE_ROOT_DEVICE (rygel_root_device_get_type ())
#define RYGEL_ROOT_DEVICE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_ROOT_DEVICE, RygelRootDevice))
#define RYGEL_ROOT_DEVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_ROOT_DEVICE, RygelRootDeviceClass))
#define RYGEL_IS_ROOT_DEVICE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_ROOT_DEVICE))
#define RYGEL_IS_ROOT_DEVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_ROOT_DEVICE))
#define RYGEL_ROOT_DEVICE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_ROOT_DEVICE, RygelRootDeviceClass))

typedef struct _RygelRootDevice RygelRootDevice;
typedef struct _RygelRootDeviceClass RygelRootDeviceClass;
#define _g_regex_unref0(var) ((var == NULL) ? NULL : (var = (g_regex_unref (var), NULL)))
typedef struct _RygelResourceInfoPrivate RygelResourceInfoPrivate;
#define _rygel_resource_info_unref0(var) ((var == NULL) ? NULL : (var = (rygel_resource_info_unref (var), NULL)))
#define _rygel_icon_info_unref0(var) ((var == NULL) ? NULL : (var = (rygel_icon_info_unref (var), NULL)))
typedef struct _RygelIconInfoPrivate RygelIconInfoPrivate;
#define _fclose0(var) ((var == NULL) ? NULL : (var = (fclose (var), NULL)))
typedef struct _RygelParamSpecRootDeviceFactory RygelParamSpecRootDeviceFactory;

typedef enum  {
	ROOT_DEVICE_FACTORY_ERROR_XML_PARSE,
	ROOT_DEVICE_FACTORY_ERROR_PLUGIN_DISABLED
} RootDeviceFactoryError;
#define ROOT_DEVICE_FACTORY_ERROR root_device_factory_error_quark ()
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

struct _RygelRootDeviceFactoryPrivate {
	RygelConfiguration* config;
	char* desc_dir;
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

struct _RygelIconInfo {
	GTypeInstance parent_instance;
	volatile int ref_count;
	RygelIconInfoPrivate * priv;
	char* mime_type;
	char* path;
	glong size;
	gint width;
	gint height;
	gint depth;
};

struct _RygelIconInfoClass {
	GTypeClass parent_class;
	void (*finalize) (RygelIconInfo *self);
};

struct _RygelParamSpecRootDeviceFactory {
	GParamSpec parent_instance;
};


static gpointer rygel_root_device_factory_parent_class = NULL;

GQuark root_device_factory_error_quark (void);
gpointer rygel_root_device_factory_ref (gpointer instance);
void rygel_root_device_factory_unref (gpointer instance);
GParamSpec* rygel_param_spec_root_device_factory (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_root_device_factory (GValue* value, gpointer v_object);
gpointer rygel_value_get_root_device_factory (const GValue* value);
GType rygel_root_device_factory_get_type (void);
GType rygel_configuration_get_type (void);
#define RYGEL_ROOT_DEVICE_FACTORY_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_ROOT_DEVICE_FACTORY, RygelRootDeviceFactoryPrivate))
enum  {
	RYGEL_ROOT_DEVICE_FACTORY_DUMMY_PROPERTY
};
GType rygel_meta_config_get_type (void);
RygelMetaConfig* rygel_meta_config_get_default (void);
static void rygel_root_device_factory_ensure_dir_exists (RygelRootDeviceFactory* self, const char* dir_path, GError** error);
RygelRootDeviceFactory* rygel_root_device_factory_new (GUPnPContext* context, GError** error);
RygelRootDeviceFactory* rygel_root_device_factory_construct (GType object_type, GUPnPContext* context, GError** error);
gboolean rygel_configuration_get_enabled (RygelConfiguration* self, const char* section, GError** error);
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
static GUPnPXMLDoc* rygel_root_device_factory_create_desc (RygelRootDeviceFactory* self, RygelPlugin* plugin, const char* desc_path, GError** error);
RygelRootDevice* rygel_root_device_new (GUPnPContext* context, RygelPlugin* plugin, GUPnPXMLDoc* description_doc, const char* description_path, const char* description_dir);
RygelRootDevice* rygel_root_device_construct (GType object_type, GUPnPContext* context, RygelPlugin* plugin, GUPnPXMLDoc* description_doc, const char* description_path, const char* description_dir);
GType rygel_root_device_get_type (void);
RygelRootDevice* rygel_root_device_factory_create (RygelRootDeviceFactory* self, RygelPlugin* plugin, GError** error);
static gboolean rygel_root_device_factory_check_path_exist (RygelRootDeviceFactory* self, const char* path);
static void rygel_root_device_factory_prepare_desc_for_plugin (RygelRootDeviceFactory* self, GUPnPXMLDoc* doc, RygelPlugin* plugin);
static void rygel_root_device_factory_save_modified_desc (RygelRootDeviceFactory* self, GUPnPXMLDoc* doc, const char* desc_path, GError** error);
static void rygel_root_device_factory_set_friendly_name_and_udn (RygelRootDeviceFactory* self, xmlNode* device_element, const char* plugin_name, const char* plugin_title);
static void rygel_root_device_factory_add_icons_to_desc (RygelRootDeviceFactory* self, xmlNode* device_element, RygelPlugin* plugin);
static void rygel_root_device_factory_add_services_to_desc (RygelRootDeviceFactory* self, xmlNode* device_element, RygelPlugin* plugin);
char* rygel_configuration_get_title (RygelConfiguration* self, const char* section, GError** error);
static void rygel_root_device_factory_add_service_to_desc (RygelRootDeviceFactory* self, xmlNode* service_list_node, const char* plugin_name, RygelResourceInfo* resource_info);
static void rygel_root_device_factory_add_icon_to_desc (RygelRootDeviceFactory* self, xmlNode* icon_list_node, RygelIconInfo* icon_info, RygelPlugin* plugin);
static void rygel_root_device_factory_finalize (RygelRootDeviceFactory* obj);
static int _vala_strcmp0 (const char * str1, const char * str2);



GQuark root_device_factory_error_quark (void) {
	return g_quark_from_static_string ("root_device_factory_error-quark");
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


RygelRootDeviceFactory* rygel_root_device_factory_construct (GType object_type, GUPnPContext* context, GError** error) {
	GError * _inner_error_;
	RygelRootDeviceFactory* self;
	RygelConfiguration* _tmp0_;
	GUPnPContext* _tmp1_;
	char* _tmp2_;
	g_return_val_if_fail (context != NULL, NULL);
	_inner_error_ = NULL;
	self = (RygelRootDeviceFactory*) g_type_create_instance (object_type);
	self->priv->config = (_tmp0_ = (RygelConfiguration*) rygel_meta_config_get_default (), _g_object_unref0 (self->priv->config), _tmp0_);
	self->context = (_tmp1_ = _g_object_ref0 (context), _g_object_unref0 (self->context), _tmp1_);
	self->priv->desc_dir = (_tmp2_ = g_build_filename (g_get_user_config_dir (), "Rygel", NULL), _g_free0 (self->priv->desc_dir), _tmp2_);
	rygel_root_device_factory_ensure_dir_exists (self, self->priv->desc_dir, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return;
	}
	return self;
}


RygelRootDeviceFactory* rygel_root_device_factory_new (GUPnPContext* context, GError** error) {
	return rygel_root_device_factory_construct (RYGEL_TYPE_ROOT_DEVICE_FACTORY, context, error);
}


RygelRootDevice* rygel_root_device_factory_create (RygelRootDeviceFactory* self, RygelPlugin* plugin, GError** error) {
	RygelRootDevice* result;
	GError * _inner_error_;
	gboolean enabled;
	char* modified_desc;
	char* desc_path;
	GUPnPXMLDoc* doc;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (plugin != NULL, NULL);
	_inner_error_ = NULL;
	enabled = TRUE;
	{
		gboolean _tmp0_;
		_tmp0_ = rygel_configuration_get_enabled (self->priv->config, plugin->name, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch42_g_error;
			goto __finally42;
		}
		enabled = _tmp0_;
	}
	goto __finally42;
	__catch42_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			_g_error_free0 (err);
		}
	}
	__finally42:
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return NULL;
	}
	if (!enabled) {
		_inner_error_ = g_error_new_literal (ROOT_DEVICE_FACTORY_ERROR, ROOT_DEVICE_FACTORY_ERROR_PLUGIN_DISABLED, "Plugin disabled in user configuration.");
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			return NULL;
		}
	}
	modified_desc = g_strconcat (plugin->name, ".xml", NULL);
	desc_path = g_build_filename (self->priv->desc_dir, modified_desc, NULL);
	doc = rygel_root_device_factory_create_desc (self, plugin, desc_path, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_g_free0 (modified_desc);
		_g_free0 (desc_path);
		return NULL;
	}
	result = rygel_root_device_new (self->context, plugin, doc, desc_path, DATA_DIR);
	_g_free0 (modified_desc);
	_g_free0 (desc_path);
	_g_object_unref0 (doc);
	return result;
}


static GUPnPXMLDoc* rygel_root_device_factory_create_desc (RygelRootDeviceFactory* self, RygelPlugin* plugin, const char* desc_path, GError** error) {
	GUPnPXMLDoc* result;
	GError * _inner_error_;
	char* path;
	GUPnPXMLDoc* doc;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (plugin != NULL, NULL);
	g_return_val_if_fail (desc_path != NULL, NULL);
	_inner_error_ = NULL;
	path = NULL;
	if (rygel_root_device_factory_check_path_exist (self, desc_path)) {
		char* _tmp0_;
		path = (_tmp0_ = g_strdup (desc_path), _g_free0 (path), _tmp0_);
	} else {
		char* _tmp1_;
		path = (_tmp1_ = g_strdup (plugin->desc_path), _g_free0 (path), _tmp1_);
	}
	doc = gupnp_xml_doc_new_from_path (path, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_g_free0 (path);
		return NULL;
	}
	rygel_root_device_factory_prepare_desc_for_plugin (self, doc, plugin);
	rygel_root_device_factory_save_modified_desc (self, doc, desc_path, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_g_free0 (path);
		_g_object_unref0 (doc);
		return NULL;
	}
	result = doc;
	_g_free0 (path);
	return result;
}


static void rygel_root_device_factory_prepare_desc_for_plugin (RygelRootDeviceFactory* self, GUPnPXMLDoc* doc, RygelPlugin* plugin) {
	xmlNode* device_element;
	g_return_if_fail (self != NULL);
	g_return_if_fail (doc != NULL);
	g_return_if_fail (plugin != NULL);
	device_element = NULL;
	device_element = get_xml_element ((xmlNode*) doc->doc, "root", "device", NULL, NULL);
	if (device_element == NULL) {
		g_warning ("rygel-root-device-factory.vala:108: Element /root/device not found.");
		return;
	}
	rygel_root_device_factory_set_friendly_name_and_udn (self, device_element, plugin->name, plugin->title);
	rygel_root_device_factory_add_icons_to_desc (self, device_element, plugin);
	rygel_root_device_factory_add_services_to_desc (self, device_element, plugin);
}


static char* string_replace (const char* self, const char* old, const char* replacement) {
	char* result;
	GError * _inner_error_;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (old != NULL, NULL);
	g_return_val_if_fail (replacement != NULL, NULL);
	_inner_error_ = NULL;
	{
		char* _tmp0_;
		GRegex* _tmp1_;
		GRegex* regex;
		char* _tmp2_;
		regex = (_tmp1_ = g_regex_new (_tmp0_ = g_regex_escape_string (old, -1), 0, 0, &_inner_error_), _g_free0 (_tmp0_), _tmp1_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch44_g_regex_error;
			}
			goto __finally44;
		}
		_tmp2_ = g_regex_replace_literal (regex, self, (glong) (-1), 0, replacement, 0, &_inner_error_);
		if (_inner_error_ != NULL) {
			_g_regex_unref0 (regex);
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch44_g_regex_error;
			}
			goto __finally44;
		}
		result = _tmp2_;
		_g_regex_unref0 (regex);
		return result;
	}
	goto __finally44;
	__catch44_g_regex_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			g_assert_not_reached ();
			_g_error_free0 (e);
		}
	}
	__finally44:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
}


static void rygel_root_device_factory_set_friendly_name_and_udn (RygelRootDeviceFactory* self, xmlNode* device_element, const char* plugin_name, const char* plugin_title) {
	GError * _inner_error_;
	xmlNode* element;
	char* title;
	char* _tmp3_;
	char* _tmp4_;
	char* _tmp5_;
	char* udn;
	gboolean _tmp6_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (plugin_name != NULL);
	g_return_if_fail (plugin_title != NULL);
	_inner_error_ = NULL;
	element = get_xml_element (device_element, "friendlyName", NULL, NULL);
	if (element == NULL) {
		g_warning ("rygel-root-device-factory.vala:137: Element /root/device/friendlyName not found.");
		return;
	}
	title = NULL;
	{
		char* _tmp0_;
		char* _tmp1_;
		_tmp0_ = rygel_configuration_get_title (self->priv->config, plugin_name, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch43_g_error;
			goto __finally43;
		}
		title = (_tmp1_ = _tmp0_, _g_free0 (title), _tmp1_);
	}
	goto __finally43;
	__catch43_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp2_;
			title = (_tmp2_ = g_strdup (plugin_title), _g_free0 (title), _tmp2_);
			_g_error_free0 (err);
		}
	}
	__finally43:
	if (_inner_error_ != NULL) {
		_g_free0 (title);
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return;
	}
	title = (_tmp3_ = string_replace (title, "@REALNAME@", g_get_real_name ()), _g_free0 (title), _tmp3_);
	title = (_tmp4_ = string_replace (title, "@USERNAME@", g_get_user_name ()), _g_free0 (title), _tmp4_);
	title = (_tmp5_ = string_replace (title, "@HOSTNAME@", g_get_host_name ()), _g_free0 (title), _tmp5_);
	xmlNodeSetContent (element, title);
	element = get_xml_element (device_element, "UDN", NULL);
	if (element == NULL) {
		g_warning ("rygel-root-device-factory.vala:158: Element /root/device/UDN not found.");
		_g_free0 (title);
		return;
	}
	udn = xmlNodeGetContent (element);
	_tmp6_ = FALSE;
	if (udn == NULL) {
		_tmp6_ = TRUE;
	} else {
		_tmp6_ = _vala_strcmp0 (udn, "") == 0;
	}
	if (_tmp6_) {
		char* _tmp7_;
		udn = (_tmp7_ = generate_random_udn (), _g_free0 (udn), _tmp7_);
		xmlNodeSetContent (element, udn);
	}
	_g_free0 (title);
	_g_free0 (udn);
}


static void rygel_root_device_factory_add_services_to_desc (RygelRootDeviceFactory* self, xmlNode* device_element, RygelPlugin* plugin) {
	xmlNode* service_list_node;
	g_return_if_fail (self != NULL);
	g_return_if_fail (plugin != NULL);
	service_list_node = get_xml_element (device_element, "serviceList", NULL, NULL);
	if (service_list_node == NULL) {
		g_warning ("rygel-root-device-factory.vala:177: Element /root/device/serviceList not found.");
		return;
	}
	xmlNodeSetContent (service_list_node, "");
	{
		GeeIterator* _resource_info_it;
		_resource_info_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) plugin->resource_infos);
		while (TRUE) {
			RygelResourceInfo* resource_info;
			if (!gee_iterator_next (_resource_info_it)) {
				break;
			}
			resource_info = (RygelResourceInfo*) gee_iterator_get (_resource_info_it);
			if (g_type_is_a (resource_info->type, GUPNP_TYPE_SERVICE)) {
				rygel_root_device_factory_add_service_to_desc (self, service_list_node, plugin->name, resource_info);
			}
			_rygel_resource_info_unref0 (resource_info);
		}
		_g_object_unref0 (_resource_info_it);
	}
}


static void rygel_root_device_factory_add_service_to_desc (RygelRootDeviceFactory* self, xmlNode* service_list_node, const char* plugin_name, RygelResourceInfo* resource_info) {
	xmlNode* service_node;
	char* url;
	char* _tmp2_;
	char* _tmp1_;
	char* _tmp0_;
	char* _tmp5_;
	char* _tmp4_;
	char* _tmp3_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (plugin_name != NULL);
	g_return_if_fail (resource_info != NULL);
	service_node = xmlNewChild (service_list_node, NULL, "service", NULL);
	xmlNewChild (service_node, NULL, "serviceType", resource_info->upnp_type);
	xmlNewChild (service_node, NULL, "serviceId", resource_info->upnp_id);
	url = g_strdup (resource_info->description_path);
	xmlNewChild (service_node, NULL, "SCPDURL", url);
	url = (_tmp2_ = g_strconcat (_tmp1_ = g_strconcat (_tmp0_ = g_strconcat (plugin_name, "/", NULL), g_type_name (resource_info->type), NULL), "/Event", NULL), _g_free0 (url), _tmp2_);
	_g_free0 (_tmp1_);
	_g_free0 (_tmp0_);
	xmlNewChild (service_node, NULL, "eventSubURL", url);
	url = (_tmp5_ = g_strconcat (_tmp4_ = g_strconcat (_tmp3_ = g_strconcat (plugin_name, "/", NULL), g_type_name (resource_info->type), NULL), "/Control", NULL), _g_free0 (url), _tmp5_);
	_g_free0 (_tmp4_);
	_g_free0 (_tmp3_);
	xmlNewChild (service_node, NULL, "controlURL", url);
	_g_free0 (url);
}


static void rygel_root_device_factory_add_icons_to_desc (RygelRootDeviceFactory* self, xmlNode* device_element, RygelPlugin* plugin) {
	gboolean _tmp0_;
	xmlNode* icon_list_node;
	g_return_if_fail (self != NULL);
	g_return_if_fail (plugin != NULL);
	_tmp0_ = FALSE;
	if (plugin->icon_infos == NULL) {
		_tmp0_ = TRUE;
	} else {
		_tmp0_ = gee_collection_get_size ((GeeCollection*) plugin->icon_infos) == 0;
	}
	if (_tmp0_) {
		g_debug ("rygel-root-device-factory.vala:218: No icon provided by %s.", plugin->name);
		return;
	}
	icon_list_node = get_xml_element (device_element, "iconList", NULL, NULL);
	if (icon_list_node == NULL) {
		icon_list_node = xmlNewChild (device_element, NULL, "iconList", NULL);
	} else {
		xmlNodeSetContent (icon_list_node, "");
	}
	{
		GeeIterator* _icon_info_it;
		_icon_info_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) plugin->icon_infos);
		while (TRUE) {
			RygelIconInfo* icon_info;
			if (!gee_iterator_next (_icon_info_it)) {
				break;
			}
			icon_info = (RygelIconInfo*) gee_iterator_get (_icon_info_it);
			rygel_root_device_factory_add_icon_to_desc (self, icon_list_node, icon_info, plugin);
			_rygel_icon_info_unref0 (icon_info);
		}
		_g_object_unref0 (_icon_info_it);
	}
}


static void rygel_root_device_factory_add_icon_to_desc (RygelRootDeviceFactory* self, xmlNode* icon_list_node, RygelIconInfo* icon_info, RygelPlugin* plugin) {
	xmlNode* icon_node;
	char* width;
	char* height;
	char* depth;
	char* _tmp5_;
	char* _tmp4_;
	char* _tmp3_;
	char* _tmp2_;
	char* _tmp1_;
	char* _tmp0_;
	char* _tmp6_;
	char* url;
	char* _tmp7_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (icon_info != NULL);
	g_return_if_fail (plugin != NULL);
	icon_node = xmlNewChild (icon_list_node, NULL, "icon", NULL);
	width = g_strdup_printf ("%i", icon_info->width);
	height = g_strdup_printf ("%i", icon_info->height);
	depth = g_strdup_printf ("%i", icon_info->depth);
	xmlNewChild (icon_node, NULL, "mimetype", icon_info->mime_type);
	xmlNewChild (icon_node, NULL, "width", width);
	xmlNewChild (icon_node, NULL, "height", height);
	xmlNewChild (icon_node, NULL, "depth", depth);
	url = (_tmp6_ = g_strconcat (_tmp5_ = g_strconcat (_tmp4_ = g_strconcat (_tmp3_ = g_strconcat (_tmp2_ = g_strconcat (_tmp1_ = g_strconcat (_tmp0_ = g_strconcat (plugin->name, "-", NULL), width, NULL), "x", NULL), height, NULL), "x", NULL), depth, NULL), ".png", NULL), _g_free0 (_tmp5_), _g_free0 (_tmp4_), _g_free0 (_tmp3_), _g_free0 (_tmp2_), _g_free0 (_tmp1_), _g_free0 (_tmp0_), _tmp6_);
	gupnp_context_host_path (self->context, icon_info->path, _tmp7_ = g_strconcat ("/", url, NULL));
	_g_free0 (_tmp7_);
	xmlNewChild (icon_node, NULL, "url", url);
	_g_free0 (width);
	_g_free0 (height);
	_g_free0 (depth);
	_g_free0 (url);
}


static void rygel_root_device_factory_save_modified_desc (RygelRootDeviceFactory* self, GUPnPXMLDoc* doc, const char* desc_path, GError** error) {
	GError * _inner_error_;
	FILE* f;
	gint res;
	gboolean _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (doc != NULL);
	g_return_if_fail (desc_path != NULL);
	_inner_error_ = NULL;
	f = fopen (desc_path, "w+");
	res = -1;
	if (f != NULL) {
		res = xmlDocDump (f, doc->doc);
	}
	_tmp0_ = FALSE;
	if (f == NULL) {
		_tmp0_ = TRUE;
	} else {
		_tmp0_ = res == (-1);
	}
	if (_tmp0_) {
		char* _tmp1_;
		char* _tmp2_;
		char* message;
		message = (_tmp2_ = g_strconcat ("Failed to write modified description", _tmp1_ = g_strdup_printf (" to %s.\n", desc_path), NULL), _g_free0 (_tmp1_), _tmp2_);
		_inner_error_ = g_error_new_literal (G_IO_ERROR, G_IO_ERROR_FAILED, message);
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_g_free0 (message);
			_fclose0 (f);
			return;
		}
		_g_free0 (message);
	}
	_fclose0 (f);
}


static gboolean rygel_root_device_factory_check_path_exist (RygelRootDeviceFactory* self, const char* path) {
	gboolean result;
	GFile* file;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (path != NULL, FALSE);
	file = g_file_new_for_path (path);
	result = g_file_query_exists (file, NULL);
	_g_object_unref0 (file);
	return result;
}


static void rygel_root_device_factory_ensure_dir_exists (RygelRootDeviceFactory* self, const char* dir_path, GError** error) {
	GError * _inner_error_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (dir_path != NULL);
	_inner_error_ = NULL;
	if (!rygel_root_device_factory_check_path_exist (self, dir_path)) {
		GFile* file;
		file = g_file_new_for_path (dir_path);
		g_file_make_directory (file, NULL, &_inner_error_);
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_g_object_unref0 (file);
			return;
		}
		_g_object_unref0 (file);
	}
}


static void rygel_value_root_device_factory_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void rygel_value_root_device_factory_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		rygel_root_device_factory_unref (value->data[0].v_pointer);
	}
}


static void rygel_value_root_device_factory_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = rygel_root_device_factory_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer rygel_value_root_device_factory_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* rygel_value_root_device_factory_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		RygelRootDeviceFactory* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = rygel_root_device_factory_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* rygel_value_root_device_factory_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	RygelRootDeviceFactory** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags && G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = rygel_root_device_factory_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* rygel_param_spec_root_device_factory (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	RygelParamSpecRootDeviceFactory* spec;
	g_return_val_if_fail (g_type_is_a (object_type, RYGEL_TYPE_ROOT_DEVICE_FACTORY), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer rygel_value_get_root_device_factory (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_TYPE_ROOT_DEVICE_FACTORY), NULL);
	return value->data[0].v_pointer;
}


void rygel_value_set_root_device_factory (GValue* value, gpointer v_object) {
	RygelRootDeviceFactory* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_TYPE_ROOT_DEVICE_FACTORY));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, RYGEL_TYPE_ROOT_DEVICE_FACTORY));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		rygel_root_device_factory_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		rygel_root_device_factory_unref (old);
	}
}


static void rygel_root_device_factory_class_init (RygelRootDeviceFactoryClass * klass) {
	rygel_root_device_factory_parent_class = g_type_class_peek_parent (klass);
	RYGEL_ROOT_DEVICE_FACTORY_CLASS (klass)->finalize = rygel_root_device_factory_finalize;
	g_type_class_add_private (klass, sizeof (RygelRootDeviceFactoryPrivate));
}


static void rygel_root_device_factory_instance_init (RygelRootDeviceFactory * self) {
	self->priv = RYGEL_ROOT_DEVICE_FACTORY_GET_PRIVATE (self);
	self->ref_count = 1;
}


static void rygel_root_device_factory_finalize (RygelRootDeviceFactory* obj) {
	RygelRootDeviceFactory * self;
	self = RYGEL_ROOT_DEVICE_FACTORY (obj);
	_g_object_unref0 (self->context);
	_g_object_unref0 (self->priv->config);
	_g_free0 (self->priv->desc_dir);
}


GType rygel_root_device_factory_get_type (void) {
	static GType rygel_root_device_factory_type_id = 0;
	if (rygel_root_device_factory_type_id == 0) {
		static const GTypeValueTable g_define_type_value_table = { rygel_value_root_device_factory_init, rygel_value_root_device_factory_free_value, rygel_value_root_device_factory_copy_value, rygel_value_root_device_factory_peek_pointer, "p", rygel_value_root_device_factory_collect_value, "p", rygel_value_root_device_factory_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (RygelRootDeviceFactoryClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_root_device_factory_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelRootDeviceFactory), 0, (GInstanceInitFunc) rygel_root_device_factory_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		rygel_root_device_factory_type_id = g_type_register_fundamental (g_type_fundamental_next (), "RygelRootDeviceFactory", &g_define_type_info, &g_define_type_fundamental_info, 0);
	}
	return rygel_root_device_factory_type_id;
}


gpointer rygel_root_device_factory_ref (gpointer instance) {
	RygelRootDeviceFactory* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void rygel_root_device_factory_unref (gpointer instance) {
	RygelRootDeviceFactory* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		RYGEL_ROOT_DEVICE_FACTORY_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
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




