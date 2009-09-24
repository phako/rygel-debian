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
#include <dbus/dbus-glib-lowlevel.h>
#include <dbus/dbus-glib.h>


#define RYGEL_TYPE_EXTERNAL_PLUGIN (rygel_external_plugin_get_type ())
#define RYGEL_EXTERNAL_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_EXTERNAL_PLUGIN, RygelExternalPlugin))
#define RYGEL_EXTERNAL_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_EXTERNAL_PLUGIN, RygelExternalPluginClass))
#define RYGEL_IS_EXTERNAL_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_EXTERNAL_PLUGIN))
#define RYGEL_IS_EXTERNAL_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_EXTERNAL_PLUGIN))
#define RYGEL_EXTERNAL_PLUGIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_EXTERNAL_PLUGIN, RygelExternalPluginClass))

typedef struct _RygelExternalPlugin RygelExternalPlugin;
typedef struct _RygelExternalPluginClass RygelExternalPluginClass;
typedef struct _RygelExternalPluginPrivate RygelExternalPluginPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_regex_unref0(var) ((var == NULL) ? NULL : (var = (g_regex_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define RYGEL_TYPE_EXTERNAL_CONTENT_DIR (rygel_external_content_dir_get_type ())
#define RYGEL_EXTERNAL_CONTENT_DIR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_EXTERNAL_CONTENT_DIR, RygelExternalContentDir))
#define RYGEL_EXTERNAL_CONTENT_DIR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_EXTERNAL_CONTENT_DIR, RygelExternalContentDirClass))
#define RYGEL_IS_EXTERNAL_CONTENT_DIR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_EXTERNAL_CONTENT_DIR))
#define RYGEL_IS_EXTERNAL_CONTENT_DIR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_EXTERNAL_CONTENT_DIR))
#define RYGEL_EXTERNAL_CONTENT_DIR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_EXTERNAL_CONTENT_DIR, RygelExternalContentDirClass))

typedef struct _RygelExternalContentDir RygelExternalContentDir;
typedef struct _RygelExternalContentDirClass RygelExternalContentDirClass;
#define _rygel_resource_info_unref0(var) ((var == NULL) ? NULL : (var = (rygel_resource_info_unref (var), NULL)))

struct _RygelExternalPlugin {
	RygelPlugin parent_instance;
	RygelExternalPluginPrivate * priv;
	char* service_name;
	char* root_object;
};

struct _RygelExternalPluginClass {
	RygelPluginClass parent_class;
};


static gpointer rygel_external_plugin_parent_class = NULL;

GType rygel_external_plugin_get_type (void);
enum  {
	RYGEL_EXTERNAL_PLUGIN_DUMMY_PROPERTY
};
#define RYGEL_EXTERNAL_PLUGIN_PROPS_IFACE "org.freedesktop.DBus.Properties"
#define RYGEL_EXTERNAL_PLUGIN_OBJECT_IFACE "org.gnome.UPnP.MediaObject1"
void _dynamic_Get6 (DBusGProxy* self, const char* param1, const char* param2, GValue* param3, GError** error);
GType rygel_external_content_dir_get_type (void);
RygelExternalPlugin* rygel_external_plugin_new (DBusGConnection* connection, const char* service_name);
RygelExternalPlugin* rygel_external_plugin_construct (GType object_type, DBusGConnection* connection, const char* service_name);
static void rygel_external_plugin_finalize (GObject* obj);



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
				goto __catch6_g_regex_error;
			}
			goto __finally6;
		}
		_tmp2_ = g_regex_replace_literal (regex, self, (glong) (-1), 0, replacement, 0, &_inner_error_);
		if (_inner_error_ != NULL) {
			_g_regex_unref0 (regex);
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch6_g_regex_error;
			}
			goto __finally6;
		}
		result = _tmp2_;
		_g_regex_unref0 (regex);
		return result;
	}
	goto __finally6;
	__catch6_g_regex_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			g_assert_not_reached ();
			_g_error_free0 (e);
		}
	}
	__finally6:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
}


void _dynamic_Get6 (DBusGProxy* self, const char* param1, const char* param2, GValue* param3, GError** error) {
	dbus_g_proxy_call (self, "Get", error, G_TYPE_STRING, param1, G_TYPE_STRING, param2, G_TYPE_INVALID, G_TYPE_VALUE, param3, G_TYPE_INVALID);
	if (*error) {
		return;
	}
}


RygelExternalPlugin* rygel_external_plugin_construct (GType object_type, DBusGConnection* connection, const char* service_name) {
	GError * _inner_error_;
	RygelExternalPlugin * self;
	char* _tmp0_;
	char* _tmp1_;
	char* root_object;
	DBusGProxy* props;
	GValue value = {0};
	GValue _tmp3_;
	GValue _tmp2_ = {0};
	char* title;
	char* _tmp4_;
	char* _tmp5_;
	RygelResourceInfo* resource_info;
	g_return_val_if_fail (connection != NULL, NULL);
	g_return_val_if_fail (service_name != NULL, NULL);
	_inner_error_ = NULL;
	root_object = (_tmp1_ = g_strconcat ("/", _tmp0_ = string_replace (service_name, ".", "/"), NULL), _g_free0 (_tmp0_), _tmp1_);
	props = dbus_g_proxy_new_for_name (connection, service_name, root_object, RYGEL_EXTERNAL_PLUGIN_PROPS_IFACE);
	_dynamic_Get6 (props, RYGEL_EXTERNAL_PLUGIN_OBJECT_IFACE, "DisplayName", &_tmp2_, &_inner_error_);
	value = (_tmp3_ = _tmp2_, G_IS_VALUE (&value) ? (g_value_unset (&value), NULL) : NULL, _tmp3_);
	if (_inner_error_ != NULL) {
		_g_free0 (root_object);
		_g_object_unref0 (props);
		G_IS_VALUE (&value) ? (g_value_unset (&value), NULL) : NULL;
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	title = g_strdup (g_value_get_string (&value));
	self = (RygelExternalPlugin*) rygel_plugin_construct_MediaServer (object_type, service_name, title);
	self->service_name = (_tmp4_ = g_strdup (service_name), _g_free0 (self->service_name), _tmp4_);
	self->root_object = (_tmp5_ = g_strdup (root_object), _g_free0 (self->root_object), _tmp5_);
	resource_info = rygel_resource_info_new (RYGEL_CONTENT_DIRECTORY_UPNP_ID, RYGEL_CONTENT_DIRECTORY_UPNP_TYPE, RYGEL_CONTENT_DIRECTORY_DESCRIPTION_PATH, RYGEL_TYPE_EXTERNAL_CONTENT_DIR);
	rygel_plugin_add_resource ((RygelPlugin*) self, resource_info);
	_g_free0 (root_object);
	_g_object_unref0 (props);
	G_IS_VALUE (&value) ? (g_value_unset (&value), NULL) : NULL;
	_g_free0 (title);
	_rygel_resource_info_unref0 (resource_info);
	return self;
}


RygelExternalPlugin* rygel_external_plugin_new (DBusGConnection* connection, const char* service_name) {
	return rygel_external_plugin_construct (RYGEL_TYPE_EXTERNAL_PLUGIN, connection, service_name);
}


static void rygel_external_plugin_class_init (RygelExternalPluginClass * klass) {
	rygel_external_plugin_parent_class = g_type_class_peek_parent (klass);
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
	static GType rygel_external_plugin_type_id = 0;
	if (rygel_external_plugin_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelExternalPluginClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_external_plugin_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelExternalPlugin), 0, (GInstanceInitFunc) rygel_external_plugin_instance_init, NULL };
		rygel_external_plugin_type_id = g_type_register_static (RYGEL_TYPE_PLUGIN, "RygelExternalPlugin", &g_define_type_info, 0);
	}
	return rygel_external_plugin_type_id;
}




