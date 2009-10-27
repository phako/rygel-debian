/* rygel-user-config.c generated by valac, the Vala compiler
 * generated from rygel-user-config.vala, do not modify */

/*
 * Copyright (C) 2008,2009 Nokia Corporation.
 * Copyright (C) 2008,2009 Zeeshan Ali (Khattak) <zeeshanak@gnome.org>.
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
#include <stdlib.h>
#include <string.h>
#include <gee.h>
#include <dbus/dbus-glib-lowlevel.h>
#include <dbus/dbus-glib.h>
#include <glib/gstdio.h>
#include <gio/gio.h>


#define RYGEL_TYPE_CONFIGURATION (rygel_configuration_get_type ())
#define RYGEL_CONFIGURATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_CONFIGURATION, RygelConfiguration))
#define RYGEL_IS_CONFIGURATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_CONFIGURATION))
#define RYGEL_CONFIGURATION_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), RYGEL_TYPE_CONFIGURATION, RygelConfigurationIface))

typedef struct _RygelConfiguration RygelConfiguration;
typedef struct _RygelConfigurationIface RygelConfigurationIface;

#define RYGEL_TYPE_LOG_LEVEL (rygel_log_level_get_type ())

#define RYGEL_TYPE_USER_CONFIG (rygel_user_config_get_type ())
#define RYGEL_USER_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_USER_CONFIG, RygelUserConfig))
#define RYGEL_USER_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_USER_CONFIG, RygelUserConfigClass))
#define RYGEL_IS_USER_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_USER_CONFIG))
#define RYGEL_IS_USER_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_USER_CONFIG))
#define RYGEL_USER_CONFIG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_USER_CONFIG, RygelUserConfigClass))

typedef struct _RygelUserConfig RygelUserConfig;
typedef struct _RygelUserConfigClass RygelUserConfigClass;
typedef struct _RygelUserConfigPrivate RygelUserConfigPrivate;
#define _g_key_file_free0(var) ((var == NULL) ? NULL : (var = (g_key_file_free (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _dbus_g_connection_unref0(var) ((var == NULL) ? NULL : (var = (dbus_g_connection_unref (var), NULL)))

typedef enum  {
	RYGEL_LOG_LEVEL_INVALID = 0,
	RYGEL_LOG_LEVEL_CRITICAL = 1,
	RYGEL_LOG_LEVEL_ERROR = 2,
	RYGEL_LOG_LEVEL_WARNING = 3,
	RYGEL_LOG_LEVEL_INFO = 4,
	RYGEL_LOG_LEVEL_DEFAULT = 4,
	RYGEL_LOG_LEVEL_DEBUG = 5
} RygelLogLevel;

struct _RygelConfigurationIface {
	GTypeInterface parent_iface;
	gboolean (*get_upnp_enabled) (RygelConfiguration* self, GError** error);
	char* (*get_interface) (RygelConfiguration* self, GError** error);
	gint (*get_port) (RygelConfiguration* self, GError** error);
	gboolean (*get_transcoding) (RygelConfiguration* self, GError** error);
	gboolean (*get_mp3_transcoder) (RygelConfiguration* self, GError** error);
	gboolean (*get_mp2ts_transcoder) (RygelConfiguration* self, GError** error);
	gboolean (*get_lpcm_transcoder) (RygelConfiguration* self, GError** error);
	RygelLogLevel (*get_log_level) (RygelConfiguration* self, GError** error);
	gboolean (*get_enabled) (RygelConfiguration* self, const char* section, GError** error);
	char* (*get_title) (RygelConfiguration* self, const char* section, GError** error);
	char* (*get_string) (RygelConfiguration* self, const char* section, const char* key, GError** error);
	GeeArrayList* (*get_string_list) (RygelConfiguration* self, const char* section, const char* key, GError** error);
	gint (*get_int) (RygelConfiguration* self, const char* section, const char* key, gint min, gint max, GError** error);
	GeeArrayList* (*get_int_list) (RygelConfiguration* self, const char* section, const char* key, GError** error);
	gboolean (*get_bool) (RygelConfiguration* self, const char* section, const char* key, GError** error);
};

struct _RygelUserConfig {
	GObject parent_instance;
	RygelUserConfigPrivate * priv;
	GKeyFile* key_file;
};

struct _RygelUserConfigClass {
	GObjectClass parent_class;
};

struct _RygelUserConfigPrivate {
	gboolean read_only;
	DBusGProxy* dbus_obj;
	DBusGProxy* rygel_obj;
};

typedef enum  {
	RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET,
	RYGEL_CONFIGURATION_ERROR_VALUE_OUT_OF_RANGE
} RygelConfigurationError;
#define RYGEL_CONFIGURATION_ERROR rygel_configuration_error_quark ()

static RygelUserConfig* rygel_user_config_config;
static RygelUserConfig* rygel_user_config_config = NULL;
static gpointer rygel_user_config_parent_class = NULL;
static RygelConfigurationIface* rygel_user_config_rygel_configuration_parent_iface = NULL;

GType rygel_log_level_get_type (void);
GType rygel_configuration_get_type (void);
GType rygel_user_config_get_type (void);
#define RYGEL_USER_CONFIG_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_USER_CONFIG, RygelUserConfigPrivate))
enum  {
	RYGEL_USER_CONFIG_DUMMY_PROPERTY
};
#define RYGEL_USER_CONFIG_CONFIG_FILE "rygel.conf"
#define RYGEL_USER_CONFIG_IFACE_KEY "interface"
#define RYGEL_USER_CONFIG_PORT_KEY "port"
#define RYGEL_USER_CONFIG_ENABLED_KEY "enabled"
#define RYGEL_USER_CONFIG_TITLE_KEY "title"
#define RYGEL_USER_CONFIG_TRANSCODING_KEY "enable-transcoding"
#define RYGEL_USER_CONFIG_MP3_TRANSCODER_KEY "enable-mp3-transcoder"
#define RYGEL_USER_CONFIG_MP2TS_TRANSCODER_KEY "enable-mp2ts-transcoder"
#define RYGEL_USER_CONFIG_LPCM_TRANSCODER_KEY "enable-lpcm-transcoder"
#define RYGEL_USER_CONFIG_LOG_LEVEL_KEY "log-level"
#define RYGEL_USER_CONFIG_DBUS_SERVICE "org.freedesktop.DBus"
#define RYGEL_USER_CONFIG_DBUS_PATH "/org/freedesktop/DBus"
#define RYGEL_USER_CONFIG_DBUS_INTERFACE "org.freedesktop.DBus"
#define RYGEL_USER_CONFIG_RYGEL_SERVICE "org.gnome.Rygel1"
#define RYGEL_USER_CONFIG_RYGEL_PATH "/org/gnome/Rygel1"
#define RYGEL_USER_CONFIG_RYGEL_INTERFACE "org.gnome.Rygel1"
gboolean rygel_configuration_get_bool (RygelConfiguration* self, const char* section, const char* key, GError** error);
static gboolean rygel_user_config_real_get_upnp_enabled (RygelConfiguration* base, GError** error);
gboolean rygel_configuration_get_upnp_enabled (RygelConfiguration* self, GError** error);
static void rygel_user_config_enable_upnp (RygelUserConfig* self, gboolean enable);
void rygel_user_config_set_upnp_enabled (RygelUserConfig* self, gboolean value);
char* rygel_configuration_get_string (RygelConfiguration* self, const char* section, const char* key, GError** error);
static char* rygel_user_config_real_get_interface (RygelConfiguration* base, GError** error);
void rygel_user_config_set_string (RygelUserConfig* self, const char* section, const char* key, const char* value);
void rygel_user_config_set_interface (RygelUserConfig* self, const char* value);
gint rygel_configuration_get_int (RygelConfiguration* self, const char* section, const char* key, gint min, gint max, GError** error);
static gint rygel_user_config_real_get_port (RygelConfiguration* base, GError** error);
void rygel_user_config_set_int (RygelUserConfig* self, const char* section, const char* key, gint value);
void rygel_user_config_set_port (RygelUserConfig* self, gint value);
static gboolean rygel_user_config_real_get_transcoding (RygelConfiguration* base, GError** error);
void rygel_user_config_set_bool (RygelUserConfig* self, const char* section, const char* key, gboolean value);
void rygel_user_config_set_transcoding (RygelUserConfig* self, gboolean value);
static gboolean rygel_user_config_real_get_mp3_transcoder (RygelConfiguration* base, GError** error);
void rygel_user_config_set_mp3_transcoder (RygelUserConfig* self, gboolean value);
static gboolean rygel_user_config_real_get_mp2ts_transcoder (RygelConfiguration* base, GError** error);
void rygel_user_config_set_mp2ts_transcoder (RygelUserConfig* self, gboolean value);
static gboolean rygel_user_config_real_get_lpcm_transcoder (RygelConfiguration* base, GError** error);
void rygel_user_config_set_lpcm_transcoder (RygelUserConfig* self, gboolean value);
static RygelLogLevel rygel_user_config_real_get_log_level (RygelConfiguration* base, GError** error);
RygelUserConfig* rygel_user_config_new (gboolean read_only, GError** error);
RygelUserConfig* rygel_user_config_construct (GType object_type, gboolean read_only, GError** error);
RygelUserConfig* rygel_user_config_get_default (GError** error);
void rygel_user_config_save (RygelUserConfig* self);
static gboolean rygel_user_config_real_get_enabled (RygelConfiguration* base, const char* section, GError** error);
static char* rygel_user_config_real_get_title (RygelConfiguration* base, const char* section, GError** error);
GQuark rygel_configuration_error_quark (void);
static char* rygel_user_config_real_get_string (RygelConfiguration* base, const char* section, const char* key, GError** error);
static GeeArrayList* rygel_user_config_real_get_string_list (RygelConfiguration* base, const char* section, const char* key, GError** error);
static gint rygel_user_config_real_get_int (RygelConfiguration* base, const char* section, const char* key, gint min, gint max, GError** error);
static GeeArrayList* rygel_user_config_real_get_int_list (RygelConfiguration* base, const char* section, const char* key, GError** error);
static gboolean rygel_user_config_real_get_bool (RygelConfiguration* base, const char* section, const char* key, GError** error);
void rygel_user_config_set_string_list (RygelUserConfig* self, const char* section, const char* key, GeeArrayList* str_list);
static void _dynamic_StartServiceByName0 (DBusGProxy* self, const char* param1, guint32 param2, guint32* param3, GError** error);
static void _dynamic_Shutdown1 (DBusGProxy* self, GError** error);
static void rygel_user_config_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static int _vala_strcmp0 (const char * str1, const char * str2);



static gboolean rygel_user_config_real_get_upnp_enabled (RygelConfiguration* base, GError** error) {
	RygelUserConfig * self;
	gboolean result;
	GError * _inner_error_;
	gboolean _tmp0_;
	self = (RygelUserConfig*) base;
	_inner_error_ = NULL;
	_tmp0_ = rygel_configuration_get_bool ((RygelConfiguration*) self, "general", RYGEL_USER_CONFIG_ENABLED_KEY, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return FALSE;
	}
	result = _tmp0_;
	return result;
}


void rygel_user_config_set_upnp_enabled (RygelUserConfig* self, gboolean value) {
	GError * _inner_error_;
	gboolean enabled;
	g_return_if_fail (self != NULL);
	_inner_error_ = NULL;
	enabled = FALSE;
	{
		gboolean _tmp0_;
		_tmp0_ = rygel_configuration_get_upnp_enabled ((RygelConfiguration*) self, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch0_g_error;
			goto __finally0;
		}
		enabled = _tmp0_;
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			_g_error_free0 (err);
		}
	}
	__finally0:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return;
	}
	if (value != enabled) {
		rygel_user_config_enable_upnp (self, value);
	}
}


static char* rygel_user_config_real_get_interface (RygelConfiguration* base, GError** error) {
	RygelUserConfig * self;
	char* result;
	GError * _inner_error_;
	char* _tmp0_;
	self = (RygelUserConfig*) base;
	_inner_error_ = NULL;
	_tmp0_ = rygel_configuration_get_string ((RygelConfiguration*) self, "general", RYGEL_USER_CONFIG_IFACE_KEY, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return NULL;
	}
	result = _tmp0_;
	return result;
}


void rygel_user_config_set_interface (RygelUserConfig* self, const char* value) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (value != NULL);
	rygel_user_config_set_string (self, "general", RYGEL_USER_CONFIG_IFACE_KEY, value);
}


static gint rygel_user_config_real_get_port (RygelConfiguration* base, GError** error) {
	RygelUserConfig * self;
	gint result;
	GError * _inner_error_;
	gint _tmp0_;
	self = (RygelUserConfig*) base;
	_inner_error_ = NULL;
	_tmp0_ = rygel_configuration_get_int ((RygelConfiguration*) self, "general", RYGEL_USER_CONFIG_PORT_KEY, (gint) 0U, (gint) G_MAXUINT16, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return 0;
	}
	result = _tmp0_;
	return result;
}


void rygel_user_config_set_port (RygelUserConfig* self, gint value) {
	g_return_if_fail (self != NULL);
	rygel_user_config_set_int (self, "general", RYGEL_USER_CONFIG_PORT_KEY, value);
}


static gboolean rygel_user_config_real_get_transcoding (RygelConfiguration* base, GError** error) {
	RygelUserConfig * self;
	gboolean result;
	GError * _inner_error_;
	gboolean _tmp0_;
	self = (RygelUserConfig*) base;
	_inner_error_ = NULL;
	_tmp0_ = rygel_configuration_get_bool ((RygelConfiguration*) self, "general", RYGEL_USER_CONFIG_TRANSCODING_KEY, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return FALSE;
	}
	result = _tmp0_;
	return result;
}


void rygel_user_config_set_transcoding (RygelUserConfig* self, gboolean value) {
	g_return_if_fail (self != NULL);
	rygel_user_config_set_bool (self, "general", RYGEL_USER_CONFIG_TRANSCODING_KEY, value);
}


static gboolean rygel_user_config_real_get_mp3_transcoder (RygelConfiguration* base, GError** error) {
	RygelUserConfig * self;
	gboolean result;
	GError * _inner_error_;
	gboolean _tmp0_;
	self = (RygelUserConfig*) base;
	_inner_error_ = NULL;
	_tmp0_ = rygel_configuration_get_bool ((RygelConfiguration*) self, "general", RYGEL_USER_CONFIG_MP3_TRANSCODER_KEY, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return FALSE;
	}
	result = _tmp0_;
	return result;
}


void rygel_user_config_set_mp3_transcoder (RygelUserConfig* self, gboolean value) {
	g_return_if_fail (self != NULL);
	rygel_user_config_set_bool (self, "general", RYGEL_USER_CONFIG_MP3_TRANSCODER_KEY, value);
}


static gboolean rygel_user_config_real_get_mp2ts_transcoder (RygelConfiguration* base, GError** error) {
	RygelUserConfig * self;
	gboolean result;
	GError * _inner_error_;
	gboolean _tmp0_;
	self = (RygelUserConfig*) base;
	_inner_error_ = NULL;
	_tmp0_ = rygel_configuration_get_bool ((RygelConfiguration*) self, "general", RYGEL_USER_CONFIG_MP2TS_TRANSCODER_KEY, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return FALSE;
	}
	result = _tmp0_;
	return result;
}


void rygel_user_config_set_mp2ts_transcoder (RygelUserConfig* self, gboolean value) {
	g_return_if_fail (self != NULL);
	rygel_user_config_set_bool (self, "general", RYGEL_USER_CONFIG_MP2TS_TRANSCODER_KEY, value);
}


static gboolean rygel_user_config_real_get_lpcm_transcoder (RygelConfiguration* base, GError** error) {
	RygelUserConfig * self;
	gboolean result;
	GError * _inner_error_;
	gboolean _tmp0_;
	self = (RygelUserConfig*) base;
	_inner_error_ = NULL;
	_tmp0_ = rygel_configuration_get_bool ((RygelConfiguration*) self, "general", RYGEL_USER_CONFIG_LPCM_TRANSCODER_KEY, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return FALSE;
	}
	result = _tmp0_;
	return result;
}


void rygel_user_config_set_lpcm_transcoder (RygelUserConfig* self, gboolean value) {
	g_return_if_fail (self != NULL);
	rygel_user_config_set_bool (self, "general", RYGEL_USER_CONFIG_LPCM_TRANSCODER_KEY, value);
}


static RygelLogLevel rygel_user_config_real_get_log_level (RygelConfiguration* base, GError** error) {
	RygelUserConfig * self;
	RygelLogLevel result;
	GError * _inner_error_;
	gint _tmp0_;
	self = (RygelUserConfig*) base;
	_inner_error_ = NULL;
	_tmp0_ = rygel_configuration_get_int ((RygelConfiguration*) self, "general", RYGEL_USER_CONFIG_LOG_LEVEL_KEY, (gint) RYGEL_LOG_LEVEL_INVALID, (gint) RYGEL_LOG_LEVEL_DEBUG, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return 0;
	}
	result = (RygelLogLevel) _tmp0_;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


RygelUserConfig* rygel_user_config_get_default (GError** error) {
	RygelUserConfig* result;
	GError * _inner_error_;
	_inner_error_ = NULL;
	if (rygel_user_config_config == NULL) {
		RygelUserConfig* _tmp0_;
		RygelUserConfig* _tmp1_;
		_tmp0_ = rygel_user_config_new (TRUE, &_inner_error_);
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			return NULL;
		}
		rygel_user_config_config = (_tmp1_ = _tmp0_, _g_object_unref0 (rygel_user_config_config), _tmp1_);
	}
	result = _g_object_ref0 (rygel_user_config_config);
	return result;
}


RygelUserConfig* rygel_user_config_construct (GType object_type, gboolean read_only, GError** error) {
	GError * _inner_error_;
	RygelUserConfig * self;
	GKeyFile* _tmp0_;
	char** _tmp1_;
	gint dirs_size;
	gint dirs_length1;
	char** dirs;
	char* _tmp2_;
	char* _tmp3_;
	char* path;
	char* _tmp6_;
	gboolean _tmp5_;
	char* _tmp4_ = NULL;
	_inner_error_ = NULL;
	self = (RygelUserConfig*) g_object_new (object_type, NULL);
	self->priv->read_only = read_only;
	self->key_file = (_tmp0_ = g_key_file_new (), _g_key_file_free0 (self->key_file), _tmp0_);
	dirs = (_tmp1_ = g_new0 (char*, 2 + 1), dirs_length1 = 2, dirs_size = dirs_length1, _tmp1_);
	dirs[0] = (_tmp2_ = g_strdup (g_get_user_config_dir ()), _g_free0 (dirs[0]), _tmp2_);
	dirs[1] = (_tmp3_ = g_strdup (SYS_CONFIG_DIR), _g_free0 (dirs[1]), _tmp3_);
	path = NULL;
	_tmp5_ = g_key_file_load_from_dirs (self->key_file, RYGEL_USER_CONFIG_CONFIG_FILE, dirs, &_tmp4_, G_KEY_FILE_KEEP_COMMENTS | G_KEY_FILE_KEEP_TRANSLATIONS, &_inner_error_);
	path = (_tmp6_ = _tmp4_, _g_free0 (path), _tmp6_);
	_tmp5_;
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		dirs = (_vala_array_free (dirs, dirs_length1, (GDestroyNotify) g_free), NULL);
		_g_free0 (path);
		return NULL;
	}
	g_debug ("rygel-user-config.vala:154: Loaded user configuration from file '%s'", path);
	{
		DBusGConnection* connection;
		DBusGProxy* _tmp7_;
		DBusGProxy* _tmp8_;
		connection = dbus_g_bus_get (DBUS_BUS_SESSION, &_inner_error_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == DBUS_GERROR) {
				goto __catch1_dbus_gerror;
			}
			goto __finally1;
		}
		self->priv->rygel_obj = (_tmp7_ = dbus_g_proxy_new_for_name (connection, RYGEL_USER_CONFIG_RYGEL_SERVICE, RYGEL_USER_CONFIG_RYGEL_PATH, RYGEL_USER_CONFIG_RYGEL_INTERFACE), _g_object_unref0 (self->priv->rygel_obj), _tmp7_);
		self->priv->dbus_obj = (_tmp8_ = dbus_g_proxy_new_for_name (connection, RYGEL_USER_CONFIG_DBUS_SERVICE, RYGEL_USER_CONFIG_DBUS_PATH, RYGEL_USER_CONFIG_DBUS_INTERFACE), _g_object_unref0 (self->priv->dbus_obj), _tmp8_);
		_dbus_g_connection_unref0 (connection);
	}
	goto __finally1;
	__catch1_dbus_gerror:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			g_debug ("rygel-user-config.vala:168: Failed to connect to session bus: %s", err->message);
			_g_error_free0 (err);
		}
	}
	__finally1:
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		dirs = (_vala_array_free (dirs, dirs_length1, (GDestroyNotify) g_free), NULL);
		_g_free0 (path);
		return NULL;
	}
	dirs = (_vala_array_free (dirs, dirs_length1, (GDestroyNotify) g_free), NULL);
	_g_free0 (path);
	return self;
}


RygelUserConfig* rygel_user_config_new (gboolean read_only, GError** error) {
	return rygel_user_config_construct (RYGEL_TYPE_USER_CONFIG, read_only, error);
}


void rygel_user_config_save (RygelUserConfig* self) {
	GError * _inner_error_;
	char* path;
	gsize length = 0UL;
	char* data;
	g_return_if_fail (self != NULL);
	_inner_error_ = NULL;
	g_return_if_fail (!self->priv->read_only);
	path = g_build_filename (g_get_user_config_dir (), RYGEL_USER_CONFIG_CONFIG_FILE, NULL);
	data = g_key_file_to_data (self->key_file, &length, NULL);
	{
		g_file_set_contents (path, data, (glong) length, &_inner_error_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_FILE_ERROR) {
				goto __catch2_g_file_error;
			}
			goto __finally2;
		}
	}
	goto __finally2;
	__catch2_g_file_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			g_critical ("rygel-user-config.vala:185: Failed to save configuration data to file '%s': %s", path, err->message);
			_g_error_free0 (err);
		}
	}
	__finally2:
	if (_inner_error_ != NULL) {
		_g_free0 (path);
		_g_free0 (data);
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return;
	}
	_g_free0 (path);
	_g_free0 (data);
}


static gboolean rygel_user_config_real_get_enabled (RygelConfiguration* base, const char* section, GError** error) {
	RygelUserConfig * self;
	gboolean result;
	GError * _inner_error_;
	gboolean _tmp0_;
	self = (RygelUserConfig*) base;
	g_return_val_if_fail (section != NULL, FALSE);
	_inner_error_ = NULL;
	_tmp0_ = rygel_configuration_get_bool ((RygelConfiguration*) self, section, RYGEL_USER_CONFIG_ENABLED_KEY, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return FALSE;
	}
	result = _tmp0_;
	return result;
}


static char* rygel_user_config_real_get_title (RygelConfiguration* base, const char* section, GError** error) {
	RygelUserConfig * self;
	char* result;
	GError * _inner_error_;
	char* _tmp0_;
	self = (RygelUserConfig*) base;
	g_return_val_if_fail (section != NULL, NULL);
	_inner_error_ = NULL;
	_tmp0_ = rygel_configuration_get_string ((RygelConfiguration*) self, section, RYGEL_USER_CONFIG_TITLE_KEY, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return NULL;
	}
	result = _tmp0_;
	return result;
}


static char* rygel_user_config_real_get_string (RygelConfiguration* base, const char* section, const char* key, GError** error) {
	RygelUserConfig * self;
	char* result;
	GError * _inner_error_;
	char* val;
	gboolean _tmp0_ = FALSE;
	self = (RygelUserConfig*) base;
	g_return_val_if_fail (section != NULL, NULL);
	g_return_val_if_fail (key != NULL, NULL);
	_inner_error_ = NULL;
	val = g_key_file_get_string (self->key_file, section, key, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return NULL;
	}
	if (val == NULL) {
		_tmp0_ = TRUE;
	} else {
		_tmp0_ = _vala_strcmp0 (val, "") == 0;
	}
	if (_tmp0_) {
		_inner_error_ = g_error_new (RYGEL_CONFIGURATION_ERROR, RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET, "No value available for '%s'", key);
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_g_free0 (val);
			return NULL;
		}
	}
	result = val;
	return result;
}


static GeeArrayList* rygel_user_config_real_get_string_list (RygelConfiguration* base, const char* section, const char* key, GError** error) {
	RygelUserConfig * self;
	GeeArrayList* result;
	GError * _inner_error_;
	GeeArrayList* str_list;
	char** _tmp1_;
	gint strings_size;
	gint strings_length1;
	gsize _tmp0_;
	char** strings;
	self = (RygelUserConfig*) base;
	g_return_val_if_fail (section != NULL, NULL);
	g_return_val_if_fail (key != NULL, NULL);
	_inner_error_ = NULL;
	str_list = gee_array_list_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, NULL);
	strings = (_tmp1_ = g_key_file_get_string_list (self->key_file, section, key, &_tmp0_, &_inner_error_), strings_length1 = _tmp0_, strings_size = strings_length1, _tmp1_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_g_object_unref0 (str_list);
		return NULL;
	}
	{
		char** str_collection;
		int str_collection_length1;
		int str_it;
		str_collection = strings;
		str_collection_length1 = strings_length1;
		for (str_it = 0; str_it < strings_length1; str_it = str_it + 1) {
			char* str;
			str = g_strdup (str_collection[str_it]);
			{
				gee_abstract_collection_add ((GeeAbstractCollection*) str_list, str);
				_g_free0 (str);
			}
		}
	}
	result = str_list;
	strings = (_vala_array_free (strings, strings_length1, (GDestroyNotify) g_free), NULL);
	return result;
}


static gint rygel_user_config_real_get_int (RygelConfiguration* base, const char* section, const char* key, gint min, gint max, GError** error) {
	RygelUserConfig * self;
	gint result;
	GError * _inner_error_;
	gint val;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	self = (RygelUserConfig*) base;
	g_return_val_if_fail (section != NULL, 0);
	g_return_val_if_fail (key != NULL, 0);
	_inner_error_ = NULL;
	val = g_key_file_get_integer (self->key_file, section, key, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return 0;
	}
	if (val == 0) {
		_tmp1_ = TRUE;
	} else {
		_tmp1_ = val < min;
	}
	if (_tmp1_) {
		_tmp0_ = TRUE;
	} else {
		_tmp0_ = val > max;
	}
	if (_tmp0_) {
		_inner_error_ = g_error_new (RYGEL_CONFIGURATION_ERROR, RYGEL_CONFIGURATION_ERROR_VALUE_OUT_OF_RANGE, "Value of '%s' out of range", key);
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			return 0;
		}
	}
	result = val;
	return result;
}


static GeeArrayList* rygel_user_config_real_get_int_list (RygelConfiguration* base, const char* section, const char* key, GError** error) {
	RygelUserConfig * self;
	GeeArrayList* result;
	GError * _inner_error_;
	GeeArrayList* int_list;
	gint* _tmp1_;
	gint ints_size;
	gint ints_length1;
	gsize _tmp0_;
	gint* ints;
	self = (RygelUserConfig*) base;
	g_return_val_if_fail (section != NULL, NULL);
	g_return_val_if_fail (key != NULL, NULL);
	_inner_error_ = NULL;
	int_list = gee_array_list_new (G_TYPE_INT, NULL, NULL, NULL);
	ints = (_tmp1_ = g_key_file_get_integer_list (self->key_file, section, key, &_tmp0_, &_inner_error_), ints_length1 = _tmp0_, ints_size = ints_length1, _tmp1_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_g_object_unref0 (int_list);
		return NULL;
	}
	{
		gint* num_collection;
		int num_collection_length1;
		int num_it;
		num_collection = ints;
		num_collection_length1 = ints_length1;
		for (num_it = 0; num_it < ints_length1; num_it = num_it + 1) {
			gint num;
			num = num_collection[num_it];
			{
				gee_abstract_collection_add ((GeeAbstractCollection*) int_list, GINT_TO_POINTER (num));
			}
		}
	}
	result = int_list;
	ints = (g_free (ints), NULL);
	return result;
}


static gboolean rygel_user_config_real_get_bool (RygelConfiguration* base, const char* section, const char* key, GError** error) {
	RygelUserConfig * self;
	gboolean result;
	GError * _inner_error_;
	gboolean _tmp0_;
	self = (RygelUserConfig*) base;
	g_return_val_if_fail (section != NULL, FALSE);
	g_return_val_if_fail (key != NULL, FALSE);
	_inner_error_ = NULL;
	_tmp0_ = g_key_file_get_boolean (self->key_file, section, key, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return FALSE;
	}
	result = _tmp0_;
	return result;
}


void rygel_user_config_set_string (RygelUserConfig* self, const char* section, const char* key, const char* value) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (section != NULL);
	g_return_if_fail (key != NULL);
	g_return_if_fail (value != NULL);
	g_key_file_set_string (self->key_file, section, key, value);
}


void rygel_user_config_set_string_list (RygelUserConfig* self, const char* section, const char* key, GeeArrayList* str_list) {
	char** _tmp1_;
	gint strings_size;
	gint strings_length1;
	gint _tmp0_;
	char** strings;
	gint i;
	g_return_if_fail (self != NULL);
	g_return_if_fail (section != NULL);
	g_return_if_fail (key != NULL);
	g_return_if_fail (str_list != NULL);
	strings = (_tmp1_ = g_new0 (char*, (_tmp0_ = gee_collection_get_size ((GeeCollection*) str_list)) + 1), strings_length1 = _tmp0_, strings_size = strings_length1, _tmp1_);
	i = 0;
	{
		GeeIterator* _str_it;
		_str_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) str_list);
		while (TRUE) {
			char* str;
			if (!gee_iterator_next (_str_it)) {
				break;
			}
			str = (char*) gee_iterator_get (_str_it);
			if (_vala_strcmp0 (str, "") != 0) {
				char* _tmp3_;
				char* *_tmp2_;
				_tmp2_ = &strings[i++];
				(*_tmp2_) = (_tmp3_ = g_strdup (str), _g_free0 ((*_tmp2_)), _tmp3_);
			}
			_g_free0 (str);
		}
		_g_object_unref0 (_str_it);
	}
	g_key_file_set_string_list (self->key_file, section, key, strings, strings_length1);
	strings = (_vala_array_free (strings, strings_length1, (GDestroyNotify) g_free), NULL);
}


void rygel_user_config_set_int (RygelUserConfig* self, const char* section, const char* key, gint value) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (section != NULL);
	g_return_if_fail (key != NULL);
	g_key_file_set_integer (self->key_file, section, key, value);
}


void rygel_user_config_set_bool (RygelUserConfig* self, const char* section, const char* key, gboolean value) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (section != NULL);
	g_return_if_fail (key != NULL);
	g_key_file_set_boolean (self->key_file, section, key, value);
}


static void _dynamic_StartServiceByName0 (DBusGProxy* self, const char* param1, guint32 param2, guint32* param3, GError** error) {
	dbus_g_proxy_call (self, "StartServiceByName", error, G_TYPE_STRING, param1, G_TYPE_UINT, param2, G_TYPE_INVALID, G_TYPE_UINT, param3, G_TYPE_INVALID);
	if (*error) {
		return;
	}
}


static void _dynamic_Shutdown1 (DBusGProxy* self, GError** error) {
	dbus_g_proxy_call (self, "Shutdown", error, G_TYPE_INVALID, G_TYPE_INVALID);
	if (*error) {
		return;
	}
}


static void rygel_user_config_enable_upnp (RygelUserConfig* self, gboolean enable) {
	GError * _inner_error_;
	char* dest_path;
	GFile* dest;
	g_return_if_fail (self != NULL);
	_inner_error_ = NULL;
	dest_path = g_build_filename (g_get_user_config_dir (), "autostart", "rygel.desktop", NULL);
	dest = g_file_new_for_path (dest_path);
	{
		if (enable) {
			guint32 res = 0U;
			char* source_path;
			if (self->priv->dbus_obj != NULL) {
				_dynamic_StartServiceByName0 (self->priv->dbus_obj, RYGEL_USER_CONFIG_RYGEL_SERVICE, (guint32) 0, &res, &_inner_error_);
				if (_inner_error_ != NULL) {
					goto __catch3_g_error;
					goto __finally3;
				}
			}
			source_path = g_build_filename (DESKTOP_DIR, "rygel.desktop", NULL);
			{
				g_file_make_symbolic_link (dest, source_path, NULL, &_inner_error_);
				if (_inner_error_ != NULL) {
					if (g_error_matches (_inner_error_, G_IO_ERROR, G_IO_ERROR_EXISTS)) {
						goto __catch4_g_io_error_exists;
					}
					goto __finally4;
				}
			}
			goto __finally4;
			__catch4_g_io_error_exists:
			{
				GError * err;
				err = _inner_error_;
				_inner_error_ = NULL;
				{
					_g_error_free0 (err);
				}
			}
			__finally4:
			if (_inner_error_ != NULL) {
				_g_free0 (source_path);
				goto __catch3_g_error;
				goto __finally3;
			}
			rygel_user_config_set_bool (self, "general", RYGEL_USER_CONFIG_ENABLED_KEY, TRUE);
			_g_free0 (source_path);
		} else {
			if (self->priv->rygel_obj != NULL) {
				_dynamic_Shutdown1 (self->priv->rygel_obj, &_inner_error_);
				if (_inner_error_ != NULL) {
					goto __catch3_g_error;
					goto __finally3;
				}
			}
			{
				g_file_delete (dest, NULL, &_inner_error_);
				if (_inner_error_ != NULL) {
					if (g_error_matches (_inner_error_, G_IO_ERROR, G_IO_ERROR_NOT_FOUND)) {
						goto __catch5_g_io_error_not_found;
					}
					goto __finally5;
				}
			}
			goto __finally5;
			__catch5_g_io_error_not_found:
			{
				GError * err;
				err = _inner_error_;
				_inner_error_ = NULL;
				{
					_g_error_free0 (err);
				}
			}
			__finally5:
			if (_inner_error_ != NULL) {
				goto __catch3_g_error;
				goto __finally3;
			}
			rygel_user_config_set_bool (self, "general", RYGEL_USER_CONFIG_ENABLED_KEY, FALSE);
		}
	}
	goto __finally3;
	__catch3_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			const char* _tmp0_;
			_tmp0_ = NULL;
			if (enable) {
				_tmp0_ = "start";
			} else {
				_tmp0_ = "stop";
			}
			g_warning ("rygel-user-config.vala:331: Failed to %s Rygel service: %s\n", _tmp0_, err->message);
			_g_error_free0 (err);
		}
	}
	__finally3:
	if (_inner_error_ != NULL) {
		_g_free0 (dest_path);
		_g_object_unref0 (dest);
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return;
	}
	_g_free0 (dest_path);
	_g_object_unref0 (dest);
}


static void rygel_user_config_class_init (RygelUserConfigClass * klass) {
	rygel_user_config_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelUserConfigPrivate));
	G_OBJECT_CLASS (klass)->finalize = rygel_user_config_finalize;
}


static void rygel_user_config_rygel_configuration_interface_init (RygelConfigurationIface * iface) {
	rygel_user_config_rygel_configuration_parent_iface = g_type_interface_peek_parent (iface);
	iface->get_upnp_enabled = rygel_user_config_real_get_upnp_enabled;
	iface->get_interface = rygel_user_config_real_get_interface;
	iface->get_port = rygel_user_config_real_get_port;
	iface->get_transcoding = rygel_user_config_real_get_transcoding;
	iface->get_mp3_transcoder = rygel_user_config_real_get_mp3_transcoder;
	iface->get_mp2ts_transcoder = rygel_user_config_real_get_mp2ts_transcoder;
	iface->get_lpcm_transcoder = rygel_user_config_real_get_lpcm_transcoder;
	iface->get_log_level = rygel_user_config_real_get_log_level;
	iface->get_enabled = rygel_user_config_real_get_enabled;
	iface->get_title = rygel_user_config_real_get_title;
	iface->get_string = rygel_user_config_real_get_string;
	iface->get_string_list = rygel_user_config_real_get_string_list;
	iface->get_int = rygel_user_config_real_get_int;
	iface->get_int_list = rygel_user_config_real_get_int_list;
	iface->get_bool = rygel_user_config_real_get_bool;
}


static void rygel_user_config_instance_init (RygelUserConfig * self) {
	self->priv = RYGEL_USER_CONFIG_GET_PRIVATE (self);
}


static void rygel_user_config_finalize (GObject* obj) {
	RygelUserConfig * self;
	self = RYGEL_USER_CONFIG (obj);
	_g_key_file_free0 (self->key_file);
	_g_object_unref0 (self->priv->dbus_obj);
	_g_object_unref0 (self->priv->rygel_obj);
	G_OBJECT_CLASS (rygel_user_config_parent_class)->finalize (obj);
}


GType rygel_user_config_get_type (void) {
	static GType rygel_user_config_type_id = 0;
	if (rygel_user_config_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelUserConfigClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_user_config_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelUserConfig), 0, (GInstanceInitFunc) rygel_user_config_instance_init, NULL };
		static const GInterfaceInfo rygel_configuration_info = { (GInterfaceInitFunc) rygel_user_config_rygel_configuration_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		rygel_user_config_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelUserConfig", &g_define_type_info, 0);
		g_type_add_interface_static (rygel_user_config_type_id, RYGEL_TYPE_CONFIGURATION, &rygel_configuration_info);
	}
	return rygel_user_config_type_id;
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




