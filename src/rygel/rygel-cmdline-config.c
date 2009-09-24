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
#include <gst/gst.h>
#include <stdio.h>


#define RYGEL_TYPE_CONFIGURATION (rygel_configuration_get_type ())
#define RYGEL_CONFIGURATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_CONFIGURATION, RygelConfiguration))
#define RYGEL_IS_CONFIGURATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_CONFIGURATION))
#define RYGEL_CONFIGURATION_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), RYGEL_TYPE_CONFIGURATION, RygelConfigurationIface))

typedef struct _RygelConfiguration RygelConfiguration;
typedef struct _RygelConfigurationIface RygelConfigurationIface;

#define RYGEL_TYPE_CMDLINE_CONFIG (rygel_cmdline_config_get_type ())
#define RYGEL_CMDLINE_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_CMDLINE_CONFIG, RygelCmdlineConfig))
#define RYGEL_CMDLINE_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_CMDLINE_CONFIG, RygelCmdlineConfigClass))
#define RYGEL_IS_CMDLINE_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_CMDLINE_CONFIG))
#define RYGEL_IS_CMDLINE_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_CMDLINE_CONFIG))
#define RYGEL_CMDLINE_CONFIG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_CMDLINE_CONFIG, RygelCmdlineConfigClass))

typedef struct _RygelCmdlineConfig RygelCmdlineConfig;
typedef struct _RygelCmdlineConfigClass RygelCmdlineConfigClass;
typedef struct _RygelCmdlineConfigPrivate RygelCmdlineConfigPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_option_context_free0(var) ((var == NULL) ? NULL : (var = (g_option_context_free (var), NULL)))

typedef enum  {
	RYGEL_CMDLINE_CONFIG_ERROR_VERSION_ONLY
} RygelCmdlineConfigError;
#define RYGEL_CMDLINE_CONFIG_ERROR rygel_cmdline_config_error_quark ()
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

struct _RygelCmdlineConfig {
	GObject parent_instance;
	RygelCmdlineConfigPrivate * priv;
};

struct _RygelCmdlineConfigClass {
	GObjectClass parent_class;
};

typedef enum  {
	RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET,
	RYGEL_CONFIGURATION_ERROR_VALUE_OUT_OF_RANGE
} RygelConfigurationError;
#define RYGEL_CONFIGURATION_ERROR rygel_configuration_error_quark ()

static char* rygel_cmdline_config_iface;
static char* rygel_cmdline_config_iface = NULL;
static gint rygel_cmdline_config_port;
static gint rygel_cmdline_config_port = 0;
static gboolean rygel_cmdline_config_no_transcoding;
static gboolean rygel_cmdline_config_no_transcoding = FALSE;
static gboolean rygel_cmdline_config_no_mp3_trans;
static gboolean rygel_cmdline_config_no_mp3_trans = FALSE;
static gboolean rygel_cmdline_config_no_mp2ts_trans;
static gboolean rygel_cmdline_config_no_mp2ts_trans = FALSE;
static gboolean rygel_cmdline_config_no_lpcm_trans;
static gboolean rygel_cmdline_config_no_lpcm_trans = FALSE;
static gboolean rygel_cmdline_config_version;
static gboolean rygel_cmdline_config_version = FALSE;
static char** rygel_cmdline_config_disabled_plugins;
static char** rygel_cmdline_config_disabled_plugins = NULL;
static char** rygel_cmdline_config_plugin_titles;
static char** rygel_cmdline_config_plugin_titles = NULL;
static char** rygel_cmdline_config_plugin_options;
static char** rygel_cmdline_config_plugin_options = NULL;
static RygelCmdlineConfig* rygel_cmdline_config_config;
static RygelCmdlineConfig* rygel_cmdline_config_config = NULL;
static gpointer rygel_cmdline_config_parent_class = NULL;
static RygelConfigurationIface* rygel_cmdline_config_rygel_configuration_parent_iface = NULL;

GQuark rygel_cmdline_config_error_quark (void);
GType rygel_configuration_get_type (void);
GType rygel_cmdline_config_get_type (void);
enum  {
	RYGEL_CMDLINE_CONFIG_DUMMY_PROPERTY
};
RygelCmdlineConfig* rygel_cmdline_config_new (void);
RygelCmdlineConfig* rygel_cmdline_config_construct (GType object_type);
RygelCmdlineConfig* rygel_cmdline_config_get_default (void);
void rygel_cmdline_config_parse_args (char*** args, int* args_length1, GError** error);
GQuark rygel_configuration_error_quark (void);
static gboolean rygel_cmdline_config_real_get_upnp_enabled (RygelConfiguration* base, GError** error);
static char* rygel_cmdline_config_real_get_interface (RygelConfiguration* base, GError** error);
static gint rygel_cmdline_config_real_get_port (RygelConfiguration* base, GError** error);
static gboolean rygel_cmdline_config_real_get_transcoding (RygelConfiguration* base, GError** error);
static gboolean rygel_cmdline_config_real_get_mp3_transcoder (RygelConfiguration* base, GError** error);
static gboolean rygel_cmdline_config_real_get_mp2ts_transcoder (RygelConfiguration* base, GError** error);
static gboolean rygel_cmdline_config_real_get_lpcm_transcoder (RygelConfiguration* base, GError** error);
static gboolean rygel_cmdline_config_real_get_enabled (RygelConfiguration* base, const char* section, GError** error);
static char* rygel_cmdline_config_real_get_title (RygelConfiguration* base, const char* section, GError** error);
static char* rygel_cmdline_config_real_get_string (RygelConfiguration* base, const char* section, const char* key, GError** error);
static GeeArrayList* rygel_cmdline_config_real_get_string_list (RygelConfiguration* base, const char* section, const char* key, GError** error);
static gint rygel_cmdline_config_real_get_int (RygelConfiguration* base, const char* section, const char* key, gint min, gint max, GError** error);
static GeeArrayList* rygel_cmdline_config_real_get_int_list (RygelConfiguration* base, const char* section, const char* key, GError** error);
static gboolean rygel_cmdline_config_real_get_bool (RygelConfiguration* base, const char* section, const char* key, GError** error);
static void rygel_cmdline_config_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);
static int _vala_strcmp0 (const char * str1, const char * str2);

static const GOptionEntry RYGEL_CMDLINE_CONFIG_options[] = {{"version", (gchar) 0, 0, G_OPTION_ARG_NONE, &rygel_cmdline_config_version, "Display version number", NULL}, {"network-interface", 'n', 0, G_OPTION_ARG_STRING, &rygel_cmdline_config_iface, "Network Interface", "INTERFACE"}, {"port", 'p', 0, G_OPTION_ARG_INT, &rygel_cmdline_config_port, "Port", "PORT"}, {"disable-transcoding", 't', 0, G_OPTION_ARG_NONE, &rygel_cmdline_config_no_transcoding, "Disable transcoding", NULL}, {"disable-mp3-transcoder", 'm', 0, G_OPTION_ARG_NONE, &rygel_cmdline_config_no_mp3_trans, "Disable MP3 transcoder", NULL}, {"disable-mp2ts-transcoder", 's', 0, G_OPTION_ARG_NONE, &rygel_cmdline_config_no_mp2ts_trans, "Disable mpeg2 transport stream transcoder", NULL}, {"disable-lpcm-transcoder", 'l', 0, G_OPTION_ARG_NONE, &rygel_cmdline_config_no_lpcm_trans, "Disable Linear PCM transcoder", NULL}, {"disable-plugin", 'd', 0, G_OPTION_ARG_STRING_ARRAY, &rygel_cmdline_config_disabled_plugins, "Disable plugin", "PluginName"}, {"title", 'i', 0, G_OPTION_ARG_STRING_ARRAY, &rygel_cmdline_config_plugin_titles, "Set plugin titles", "PluginName:TITLE"}, {"plugin-option", 'o', 0, G_OPTION_ARG_STRING_ARRAY, &rygel_cmdline_config_plugin_options, "Set plugin options", "PluginName:OPTION:VALUE1[,VALUE2,..]"}, {NULL}};


GQuark rygel_cmdline_config_error_quark (void) {
	return g_quark_from_static_string ("rygel_cmdline_config_error-quark");
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


RygelCmdlineConfig* rygel_cmdline_config_get_default (void) {
	RygelCmdlineConfig* result;
	if (rygel_cmdline_config_config == NULL) {
		RygelCmdlineConfig* _tmp0_;
		rygel_cmdline_config_config = (_tmp0_ = rygel_cmdline_config_new (), _g_object_unref0 (rygel_cmdline_config_config), _tmp0_);
	}
	result = _g_object_ref0 (rygel_cmdline_config_config);
	return result;
}


void rygel_cmdline_config_parse_args (char*** args, int* args_length1, GError** error) {
	GError * _inner_error_;
	char* parameter_string;
	GOptionContext* opt_context;
	_inner_error_ = NULL;
	parameter_string = g_strdup ("- " PACKAGE_NAME);
	opt_context = g_option_context_new (parameter_string);
	g_option_context_set_help_enabled (opt_context, TRUE);
	g_option_context_add_main_entries (opt_context, RYGEL_CMDLINE_CONFIG_options, NULL);
	g_option_context_add_group (opt_context, gst_init_get_option_group ());
	g_option_context_parse (opt_context, &(*args_length1), &(*args), &_inner_error_);
	if (_inner_error_ != NULL) {
		if ((_inner_error_->domain == RYGEL_CMDLINE_CONFIG_ERROR) || (_inner_error_->domain == G_OPTION_ERROR)) {
			g_propagate_error (error, _inner_error_);
			_g_free0 (parameter_string);
			_g_option_context_free0 (opt_context);
			return;
		} else {
			_g_free0 (parameter_string);
			_g_option_context_free0 (opt_context);
			g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	if (rygel_cmdline_config_version) {
		fprintf (stdout, "%s\n", PACKAGE_STRING);
		_inner_error_ = g_error_new_literal (RYGEL_CMDLINE_CONFIG_ERROR, RYGEL_CMDLINE_CONFIG_ERROR_VERSION_ONLY, "");
		if (_inner_error_ != NULL) {
			if ((_inner_error_->domain == RYGEL_CMDLINE_CONFIG_ERROR) || (_inner_error_->domain == G_OPTION_ERROR)) {
				g_propagate_error (error, _inner_error_);
				_g_free0 (parameter_string);
				_g_option_context_free0 (opt_context);
				return;
			} else {
				_g_free0 (parameter_string);
				_g_option_context_free0 (opt_context);
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return;
			}
		}
	}
	_g_free0 (parameter_string);
	_g_option_context_free0 (opt_context);
}


static gboolean rygel_cmdline_config_real_get_upnp_enabled (RygelConfiguration* base, GError** error) {
	RygelCmdlineConfig * self;
	gboolean result;
	GError * _inner_error_;
	self = (RygelCmdlineConfig*) base;
	_inner_error_ = NULL;
	_inner_error_ = g_error_new_literal (RYGEL_CONFIGURATION_ERROR, RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET, "No value available");
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return FALSE;
	}
}


static char* rygel_cmdline_config_real_get_interface (RygelConfiguration* base, GError** error) {
	RygelCmdlineConfig * self;
	char* result;
	GError * _inner_error_;
	self = (RygelCmdlineConfig*) base;
	_inner_error_ = NULL;
	if (rygel_cmdline_config_iface == NULL) {
		_inner_error_ = g_error_new_literal (RYGEL_CONFIGURATION_ERROR, RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET, "No value available");
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			return NULL;
		}
	}
	result = g_strdup (rygel_cmdline_config_iface);
	return result;
}


static gint rygel_cmdline_config_real_get_port (RygelConfiguration* base, GError** error) {
	RygelCmdlineConfig * self;
	gint result;
	GError * _inner_error_;
	self = (RygelCmdlineConfig*) base;
	_inner_error_ = NULL;
	if (rygel_cmdline_config_port == (-1)) {
		_inner_error_ = g_error_new_literal (RYGEL_CONFIGURATION_ERROR, RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET, "No value available");
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			return 0;
		}
	}
	result = rygel_cmdline_config_port;
	return result;
}


static gboolean rygel_cmdline_config_real_get_transcoding (RygelConfiguration* base, GError** error) {
	RygelCmdlineConfig * self;
	gboolean result;
	self = (RygelCmdlineConfig*) base;
	result = !rygel_cmdline_config_no_transcoding;
	return result;
}


static gboolean rygel_cmdline_config_real_get_mp3_transcoder (RygelConfiguration* base, GError** error) {
	RygelCmdlineConfig * self;
	gboolean result;
	self = (RygelCmdlineConfig*) base;
	result = !rygel_cmdline_config_no_mp3_trans;
	return result;
}


static gboolean rygel_cmdline_config_real_get_mp2ts_transcoder (RygelConfiguration* base, GError** error) {
	RygelCmdlineConfig * self;
	gboolean result;
	self = (RygelCmdlineConfig*) base;
	result = !rygel_cmdline_config_no_mp2ts_trans;
	return result;
}


static gboolean rygel_cmdline_config_real_get_lpcm_transcoder (RygelConfiguration* base, GError** error) {
	RygelCmdlineConfig * self;
	gboolean result;
	self = (RygelCmdlineConfig*) base;
	result = !rygel_cmdline_config_no_lpcm_trans;
	return result;
}


static gboolean rygel_cmdline_config_real_get_enabled (RygelConfiguration* base, const char* section, GError** error) {
	RygelCmdlineConfig * self;
	gboolean result;
	GError * _inner_error_;
	gboolean disabled;
	self = (RygelCmdlineConfig*) base;
	g_return_val_if_fail (section != NULL, FALSE);
	_inner_error_ = NULL;
	disabled = FALSE;
	{
		char** plugin_collection;
		int plugin_collection_length1;
		int plugin_it;
		plugin_collection = rygel_cmdline_config_disabled_plugins;
		plugin_collection_length1 = _vala_array_length (rygel_cmdline_config_disabled_plugins);
		for (plugin_it = 0; plugin_it < _vala_array_length (rygel_cmdline_config_disabled_plugins); plugin_it = plugin_it + 1) {
			char* plugin;
			plugin = g_strdup (plugin_collection[plugin_it]);
			{
				if (_vala_strcmp0 (plugin, section) == 0) {
					disabled = TRUE;
					_g_free0 (plugin);
					break;
				}
				_g_free0 (plugin);
			}
		}
	}
	if (disabled) {
		result = FALSE;
		return result;
	} else {
		_inner_error_ = g_error_new_literal (RYGEL_CONFIGURATION_ERROR, RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET, "No value available");
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			return FALSE;
		}
	}
}


static char* rygel_cmdline_config_real_get_title (RygelConfiguration* base, const char* section, GError** error) {
	RygelCmdlineConfig * self;
	char* result;
	GError * _inner_error_;
	char* title;
	self = (RygelCmdlineConfig*) base;
	g_return_val_if_fail (section != NULL, NULL);
	_inner_error_ = NULL;
	title = NULL;
	{
		char** plugin_title_collection;
		int plugin_title_collection_length1;
		int plugin_title_it;
		plugin_title_collection = rygel_cmdline_config_plugin_titles;
		plugin_title_collection_length1 = _vala_array_length (rygel_cmdline_config_plugin_titles);
		for (plugin_title_it = 0; plugin_title_it < _vala_array_length (rygel_cmdline_config_plugin_titles); plugin_title_it = plugin_title_it + 1) {
			char* plugin_title;
			plugin_title = g_strdup (plugin_title_collection[plugin_title_it]);
			{
				char** _tmp1_;
				gint tokens_size;
				gint tokens_length1;
				char** _tmp0_;
				char** tokens;
				gboolean _tmp2_;
				gboolean _tmp3_;
				tokens = (_tmp1_ = _tmp0_ = g_strsplit (plugin_title, ":", 2), tokens_length1 = _vala_array_length (_tmp0_), tokens_size = tokens_length1, _tmp1_);
				_tmp2_ = FALSE;
				_tmp3_ = FALSE;
				if (tokens[0] != NULL) {
					_tmp3_ = tokens[1] != NULL;
				} else {
					_tmp3_ = FALSE;
				}
				if (_tmp3_) {
					_tmp2_ = _vala_strcmp0 (tokens[0], section) == 0;
				} else {
					_tmp2_ = FALSE;
				}
				if (_tmp2_) {
					char* _tmp4_;
					title = (_tmp4_ = g_strdup (tokens[1]), _g_free0 (title), _tmp4_);
					_g_free0 (plugin_title);
					tokens = (_vala_array_free (tokens, tokens_length1, (GDestroyNotify) g_free), NULL);
					break;
				}
				_g_free0 (plugin_title);
				tokens = (_vala_array_free (tokens, tokens_length1, (GDestroyNotify) g_free), NULL);
			}
		}
	}
	if (title != NULL) {
		result = title;
		return result;
	} else {
		_inner_error_ = g_error_new_literal (RYGEL_CONFIGURATION_ERROR, RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET, "No value available");
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_g_free0 (title);
			return NULL;
		}
	}
	_g_free0 (title);
}


static char* rygel_cmdline_config_real_get_string (RygelConfiguration* base, const char* section, const char* key, GError** error) {
	RygelCmdlineConfig * self;
	char* result;
	GError * _inner_error_;
	char* value;
	self = (RygelCmdlineConfig*) base;
	g_return_val_if_fail (section != NULL, NULL);
	g_return_val_if_fail (key != NULL, NULL);
	_inner_error_ = NULL;
	value = NULL;
	{
		char** option_collection;
		int option_collection_length1;
		int option_it;
		option_collection = rygel_cmdline_config_plugin_options;
		option_collection_length1 = _vala_array_length (rygel_cmdline_config_plugin_options);
		for (option_it = 0; option_it < _vala_array_length (rygel_cmdline_config_plugin_options); option_it = option_it + 1) {
			char* option;
			option = g_strdup (option_collection[option_it]);
			{
				char** _tmp1_;
				gint tokens_size;
				gint tokens_length1;
				char** _tmp0_;
				char** tokens;
				gboolean _tmp2_;
				gboolean _tmp3_;
				gboolean _tmp4_;
				gboolean _tmp5_;
				tokens = (_tmp1_ = _tmp0_ = g_strsplit (option, ":", 3), tokens_length1 = _vala_array_length (_tmp0_), tokens_size = tokens_length1, _tmp1_);
				_tmp2_ = FALSE;
				_tmp3_ = FALSE;
				_tmp4_ = FALSE;
				_tmp5_ = FALSE;
				if (tokens[0] != NULL) {
					_tmp5_ = tokens[1] != NULL;
				} else {
					_tmp5_ = FALSE;
				}
				if (_tmp5_) {
					_tmp4_ = tokens[2] != NULL;
				} else {
					_tmp4_ = FALSE;
				}
				if (_tmp4_) {
					_tmp3_ = _vala_strcmp0 (tokens[0], section) == 0;
				} else {
					_tmp3_ = FALSE;
				}
				if (_tmp3_) {
					_tmp2_ = _vala_strcmp0 (tokens[1], key) == 0;
				} else {
					_tmp2_ = FALSE;
				}
				if (_tmp2_) {
					char* _tmp6_;
					value = (_tmp6_ = g_strdup (tokens[2]), _g_free0 (value), _tmp6_);
					_g_free0 (option);
					tokens = (_vala_array_free (tokens, tokens_length1, (GDestroyNotify) g_free), NULL);
					break;
				}
				_g_free0 (option);
				tokens = (_vala_array_free (tokens, tokens_length1, (GDestroyNotify) g_free), NULL);
			}
		}
	}
	if (value != NULL) {
		result = value;
		return result;
	} else {
		_inner_error_ = g_error_new_literal (RYGEL_CONFIGURATION_ERROR, RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET, "No value available");
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_g_free0 (value);
			return NULL;
		}
	}
	_g_free0 (value);
}


static GeeArrayList* rygel_cmdline_config_real_get_string_list (RygelConfiguration* base, const char* section, const char* key, GError** error) {
	RygelCmdlineConfig * self;
	GeeArrayList* result;
	GError * _inner_error_;
	GeeArrayList* value;
	self = (RygelCmdlineConfig*) base;
	g_return_val_if_fail (section != NULL, NULL);
	g_return_val_if_fail (key != NULL, NULL);
	_inner_error_ = NULL;
	value = NULL;
	{
		char** option_collection;
		int option_collection_length1;
		int option_it;
		option_collection = rygel_cmdline_config_plugin_options;
		option_collection_length1 = _vala_array_length (rygel_cmdline_config_plugin_options);
		for (option_it = 0; option_it < _vala_array_length (rygel_cmdline_config_plugin_options); option_it = option_it + 1) {
			char* option;
			option = g_strdup (option_collection[option_it]);
			{
				char** _tmp1_;
				gint tokens_size;
				gint tokens_length1;
				char** _tmp0_;
				char** tokens;
				gboolean _tmp2_;
				gboolean _tmp3_;
				gboolean _tmp4_;
				gboolean _tmp5_;
				tokens = (_tmp1_ = _tmp0_ = g_strsplit (option, ":", 3), tokens_length1 = _vala_array_length (_tmp0_), tokens_size = tokens_length1, _tmp1_);
				_tmp2_ = FALSE;
				_tmp3_ = FALSE;
				_tmp4_ = FALSE;
				_tmp5_ = FALSE;
				if (tokens[0] != NULL) {
					_tmp5_ = tokens[1] != NULL;
				} else {
					_tmp5_ = FALSE;
				}
				if (_tmp5_) {
					_tmp4_ = tokens[2] != NULL;
				} else {
					_tmp4_ = FALSE;
				}
				if (_tmp4_) {
					_tmp3_ = _vala_strcmp0 (tokens[0], section) == 0;
				} else {
					_tmp3_ = FALSE;
				}
				if (_tmp3_) {
					_tmp2_ = _vala_strcmp0 (tokens[1], key) == 0;
				} else {
					_tmp2_ = FALSE;
				}
				if (_tmp2_) {
					GeeArrayList* _tmp6_;
					value = (_tmp6_ = gee_array_list_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, g_direct_equal), _g_object_unref0 (value), _tmp6_);
					{
						char** _tmp7_;
						char** val_token_collection;
						int val_token_collection_length1;
						int val_token_it;
						val_token_collection = _tmp7_ = g_strsplit (tokens[2], ",", -1);
						val_token_collection_length1 = _vala_array_length (_tmp7_);
						for (val_token_it = 0; val_token_it < _vala_array_length (_tmp7_); val_token_it = val_token_it + 1) {
							char* val_token;
							val_token = g_strdup (val_token_collection[val_token_it]);
							{
								gee_abstract_collection_add ((GeeAbstractCollection*) value, val_token);
								_g_free0 (val_token);
							}
						}
						val_token_collection = (_vala_array_free (val_token_collection, val_token_collection_length1, (GDestroyNotify) g_free), NULL);
					}
					_g_free0 (option);
					tokens = (_vala_array_free (tokens, tokens_length1, (GDestroyNotify) g_free), NULL);
					break;
				}
				_g_free0 (option);
				tokens = (_vala_array_free (tokens, tokens_length1, (GDestroyNotify) g_free), NULL);
			}
		}
	}
	if (value != NULL) {
		result = value;
		return result;
	} else {
		_inner_error_ = g_error_new_literal (RYGEL_CONFIGURATION_ERROR, RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET, "No value available");
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_g_object_unref0 (value);
			return NULL;
		}
	}
	_g_object_unref0 (value);
}


static gint rygel_cmdline_config_real_get_int (RygelConfiguration* base, const char* section, const char* key, gint min, gint max, GError** error) {
	RygelCmdlineConfig * self;
	gint result;
	GError * _inner_error_;
	gint value;
	gboolean value_set;
	self = (RygelCmdlineConfig*) base;
	g_return_val_if_fail (section != NULL, 0);
	g_return_val_if_fail (key != NULL, 0);
	_inner_error_ = NULL;
	value = 0;
	value_set = FALSE;
	{
		char** option_collection;
		int option_collection_length1;
		int option_it;
		option_collection = rygel_cmdline_config_plugin_options;
		option_collection_length1 = _vala_array_length (rygel_cmdline_config_plugin_options);
		for (option_it = 0; option_it < _vala_array_length (rygel_cmdline_config_plugin_options); option_it = option_it + 1) {
			char* option;
			option = g_strdup (option_collection[option_it]);
			{
				char** _tmp1_;
				gint tokens_size;
				gint tokens_length1;
				char** _tmp0_;
				char** tokens;
				gboolean _tmp2_;
				gboolean _tmp3_;
				gboolean _tmp4_;
				gboolean _tmp5_;
				tokens = (_tmp1_ = _tmp0_ = g_strsplit (option, ":", 3), tokens_length1 = _vala_array_length (_tmp0_), tokens_size = tokens_length1, _tmp1_);
				_tmp2_ = FALSE;
				_tmp3_ = FALSE;
				_tmp4_ = FALSE;
				_tmp5_ = FALSE;
				if (tokens[0] != NULL) {
					_tmp5_ = tokens[1] != NULL;
				} else {
					_tmp5_ = FALSE;
				}
				if (_tmp5_) {
					_tmp4_ = tokens[2] != NULL;
				} else {
					_tmp4_ = FALSE;
				}
				if (_tmp4_) {
					_tmp3_ = _vala_strcmp0 (tokens[0], section) == 0;
				} else {
					_tmp3_ = FALSE;
				}
				if (_tmp3_) {
					_tmp2_ = _vala_strcmp0 (tokens[1], key) == 0;
				} else {
					_tmp2_ = FALSE;
				}
				if (_tmp2_) {
					gboolean _tmp6_;
					value = atoi (tokens[2]);
					_tmp6_ = FALSE;
					if (value >= min) {
						_tmp6_ = value <= max;
					} else {
						_tmp6_ = FALSE;
					}
					if (_tmp6_) {
						value_set = TRUE;
					}
					_g_free0 (option);
					tokens = (_vala_array_free (tokens, tokens_length1, (GDestroyNotify) g_free), NULL);
					break;
				}
				_g_free0 (option);
				tokens = (_vala_array_free (tokens, tokens_length1, (GDestroyNotify) g_free), NULL);
			}
		}
	}
	if (value_set) {
		result = value;
		return result;
	} else {
		_inner_error_ = g_error_new_literal (RYGEL_CONFIGURATION_ERROR, RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET, "No value available");
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			return 0;
		}
	}
}


static GeeArrayList* rygel_cmdline_config_real_get_int_list (RygelConfiguration* base, const char* section, const char* key, GError** error) {
	RygelCmdlineConfig * self;
	GeeArrayList* result;
	GError * _inner_error_;
	GeeArrayList* value;
	self = (RygelCmdlineConfig*) base;
	g_return_val_if_fail (section != NULL, NULL);
	g_return_val_if_fail (key != NULL, NULL);
	_inner_error_ = NULL;
	value = NULL;
	{
		char** option_collection;
		int option_collection_length1;
		int option_it;
		option_collection = rygel_cmdline_config_plugin_options;
		option_collection_length1 = _vala_array_length (rygel_cmdline_config_plugin_options);
		for (option_it = 0; option_it < _vala_array_length (rygel_cmdline_config_plugin_options); option_it = option_it + 1) {
			char* option;
			option = g_strdup (option_collection[option_it]);
			{
				char** _tmp1_;
				gint tokens_size;
				gint tokens_length1;
				char** _tmp0_;
				char** tokens;
				gboolean _tmp2_;
				gboolean _tmp3_;
				gboolean _tmp4_;
				gboolean _tmp5_;
				tokens = (_tmp1_ = _tmp0_ = g_strsplit (option, ":", 3), tokens_length1 = _vala_array_length (_tmp0_), tokens_size = tokens_length1, _tmp1_);
				_tmp2_ = FALSE;
				_tmp3_ = FALSE;
				_tmp4_ = FALSE;
				_tmp5_ = FALSE;
				if (tokens[0] != NULL) {
					_tmp5_ = tokens[1] != NULL;
				} else {
					_tmp5_ = FALSE;
				}
				if (_tmp5_) {
					_tmp4_ = tokens[2] != NULL;
				} else {
					_tmp4_ = FALSE;
				}
				if (_tmp4_) {
					_tmp3_ = _vala_strcmp0 (tokens[0], section) == 0;
				} else {
					_tmp3_ = FALSE;
				}
				if (_tmp3_) {
					_tmp2_ = _vala_strcmp0 (tokens[1], key) == 0;
				} else {
					_tmp2_ = FALSE;
				}
				if (_tmp2_) {
					GeeArrayList* _tmp6_;
					value = (_tmp6_ = gee_array_list_new (G_TYPE_INT, NULL, NULL, g_direct_equal), _g_object_unref0 (value), _tmp6_);
					{
						char** _tmp7_;
						char** val_token_collection;
						int val_token_collection_length1;
						int val_token_it;
						val_token_collection = _tmp7_ = g_strsplit (tokens[2], ",", -1);
						val_token_collection_length1 = _vala_array_length (_tmp7_);
						for (val_token_it = 0; val_token_it < _vala_array_length (_tmp7_); val_token_it = val_token_it + 1) {
							char* val_token;
							val_token = g_strdup (val_token_collection[val_token_it]);
							{
								gee_abstract_collection_add ((GeeAbstractCollection*) value, GINT_TO_POINTER (atoi (val_token)));
								_g_free0 (val_token);
							}
						}
						val_token_collection = (_vala_array_free (val_token_collection, val_token_collection_length1, (GDestroyNotify) g_free), NULL);
					}
					_g_free0 (option);
					tokens = (_vala_array_free (tokens, tokens_length1, (GDestroyNotify) g_free), NULL);
					break;
				}
				_g_free0 (option);
				tokens = (_vala_array_free (tokens, tokens_length1, (GDestroyNotify) g_free), NULL);
			}
		}
	}
	if (value != NULL) {
		result = value;
		return result;
	} else {
		_inner_error_ = g_error_new_literal (RYGEL_CONFIGURATION_ERROR, RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET, "No value available");
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_g_object_unref0 (value);
			return NULL;
		}
	}
	_g_object_unref0 (value);
}


static gboolean string_to_bool (const char* self) {
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	if (_vala_strcmp0 (self, "true") == 0) {
		result = TRUE;
		return result;
	} else {
		result = FALSE;
		return result;
	}
}


static gboolean rygel_cmdline_config_real_get_bool (RygelConfiguration* base, const char* section, const char* key, GError** error) {
	RygelCmdlineConfig * self;
	gboolean result;
	GError * _inner_error_;
	gboolean value;
	gboolean value_set;
	self = (RygelCmdlineConfig*) base;
	g_return_val_if_fail (section != NULL, FALSE);
	g_return_val_if_fail (key != NULL, FALSE);
	_inner_error_ = NULL;
	value = FALSE;
	value_set = FALSE;
	{
		char** option_collection;
		int option_collection_length1;
		int option_it;
		option_collection = rygel_cmdline_config_plugin_options;
		option_collection_length1 = _vala_array_length (rygel_cmdline_config_plugin_options);
		for (option_it = 0; option_it < _vala_array_length (rygel_cmdline_config_plugin_options); option_it = option_it + 1) {
			char* option;
			option = g_strdup (option_collection[option_it]);
			{
				char** _tmp1_;
				gint tokens_size;
				gint tokens_length1;
				char** _tmp0_;
				char** tokens;
				gboolean _tmp2_;
				gboolean _tmp3_;
				gboolean _tmp4_;
				gboolean _tmp5_;
				tokens = (_tmp1_ = _tmp0_ = g_strsplit (option, ":", 3), tokens_length1 = _vala_array_length (_tmp0_), tokens_size = tokens_length1, _tmp1_);
				_tmp2_ = FALSE;
				_tmp3_ = FALSE;
				_tmp4_ = FALSE;
				_tmp5_ = FALSE;
				if (tokens[0] != NULL) {
					_tmp5_ = tokens[1] != NULL;
				} else {
					_tmp5_ = FALSE;
				}
				if (_tmp5_) {
					_tmp4_ = tokens[2] != NULL;
				} else {
					_tmp4_ = FALSE;
				}
				if (_tmp4_) {
					_tmp3_ = _vala_strcmp0 (tokens[0], section) == 0;
				} else {
					_tmp3_ = FALSE;
				}
				if (_tmp3_) {
					_tmp2_ = _vala_strcmp0 (tokens[1], key) == 0;
				} else {
					_tmp2_ = FALSE;
				}
				if (_tmp2_) {
					value = string_to_bool (tokens[2]);
					value_set = TRUE;
					_g_free0 (option);
					tokens = (_vala_array_free (tokens, tokens_length1, (GDestroyNotify) g_free), NULL);
					break;
				}
				_g_free0 (option);
				tokens = (_vala_array_free (tokens, tokens_length1, (GDestroyNotify) g_free), NULL);
			}
		}
	}
	if (value_set) {
		result = value;
		return result;
	} else {
		_inner_error_ = g_error_new_literal (RYGEL_CONFIGURATION_ERROR, RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET, "No value available");
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			return FALSE;
		}
	}
}


RygelCmdlineConfig* rygel_cmdline_config_construct (GType object_type) {
	RygelCmdlineConfig * self;
	self = (RygelCmdlineConfig*) g_object_new (object_type, NULL);
	return self;
}


RygelCmdlineConfig* rygel_cmdline_config_new (void) {
	return rygel_cmdline_config_construct (RYGEL_TYPE_CMDLINE_CONFIG);
}


static void rygel_cmdline_config_class_init (RygelCmdlineConfigClass * klass) {
	rygel_cmdline_config_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = rygel_cmdline_config_finalize;
	rygel_cmdline_config_port = -1;
}


static void rygel_cmdline_config_rygel_configuration_interface_init (RygelConfigurationIface * iface) {
	rygel_cmdline_config_rygel_configuration_parent_iface = g_type_interface_peek_parent (iface);
	iface->get_upnp_enabled = rygel_cmdline_config_real_get_upnp_enabled;
	iface->get_interface = rygel_cmdline_config_real_get_interface;
	iface->get_port = rygel_cmdline_config_real_get_port;
	iface->get_transcoding = rygel_cmdline_config_real_get_transcoding;
	iface->get_mp3_transcoder = rygel_cmdline_config_real_get_mp3_transcoder;
	iface->get_mp2ts_transcoder = rygel_cmdline_config_real_get_mp2ts_transcoder;
	iface->get_lpcm_transcoder = rygel_cmdline_config_real_get_lpcm_transcoder;
	iface->get_enabled = rygel_cmdline_config_real_get_enabled;
	iface->get_title = rygel_cmdline_config_real_get_title;
	iface->get_string = rygel_cmdline_config_real_get_string;
	iface->get_string_list = rygel_cmdline_config_real_get_string_list;
	iface->get_int = rygel_cmdline_config_real_get_int;
	iface->get_int_list = rygel_cmdline_config_real_get_int_list;
	iface->get_bool = rygel_cmdline_config_real_get_bool;
}


static void rygel_cmdline_config_instance_init (RygelCmdlineConfig * self) {
}


static void rygel_cmdline_config_finalize (GObject* obj) {
	RygelCmdlineConfig * self;
	self = RYGEL_CMDLINE_CONFIG (obj);
	G_OBJECT_CLASS (rygel_cmdline_config_parent_class)->finalize (obj);
}


GType rygel_cmdline_config_get_type (void) {
	static GType rygel_cmdline_config_type_id = 0;
	if (rygel_cmdline_config_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelCmdlineConfigClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_cmdline_config_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelCmdlineConfig), 0, (GInstanceInitFunc) rygel_cmdline_config_instance_init, NULL };
		static const GInterfaceInfo rygel_configuration_info = { (GInterfaceInitFunc) rygel_cmdline_config_rygel_configuration_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		rygel_cmdline_config_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelCmdlineConfig", &g_define_type_info, 0);
		g_type_add_interface_static (rygel_cmdline_config_type_id, RYGEL_TYPE_CONFIGURATION, &rygel_configuration_info);
	}
	return rygel_cmdline_config_type_id;
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


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
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




