/* rygel-configuration.c generated by valac, the Vala compiler
 * generated from rygel-configuration.vala, do not modify */

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


#define RYGEL_TYPE_CONFIGURATION (rygel_configuration_get_type ())
#define RYGEL_CONFIGURATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_CONFIGURATION, RygelConfiguration))
#define RYGEL_IS_CONFIGURATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_CONFIGURATION))
#define RYGEL_CONFIGURATION_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), RYGEL_TYPE_CONFIGURATION, RygelConfigurationIface))

typedef struct _RygelConfiguration RygelConfiguration;
typedef struct _RygelConfigurationIface RygelConfigurationIface;

#define RYGEL_TYPE_LOG_LEVEL (rygel_log_level_get_type ())

typedef enum  {
	RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET,
	RYGEL_CONFIGURATION_ERROR_VALUE_OUT_OF_RANGE
} RygelConfigurationError;
#define RYGEL_CONFIGURATION_ERROR rygel_configuration_error_quark ()
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
	gboolean (*get_wmv_transcoder) (RygelConfiguration* self, GError** error);
	RygelLogLevel (*get_log_level) (RygelConfiguration* self, GError** error);
	char* (*get_plugin_path) (RygelConfiguration* self, GError** error);
	gboolean (*get_enabled) (RygelConfiguration* self, const char* section, GError** error);
	char* (*get_title) (RygelConfiguration* self, const char* section, GError** error);
	char* (*get_string) (RygelConfiguration* self, const char* section, const char* key, GError** error);
	GeeArrayList* (*get_string_list) (RygelConfiguration* self, const char* section, const char* key, GError** error);
	gint (*get_int) (RygelConfiguration* self, const char* section, const char* key, gint min, gint max, GError** error);
	GeeArrayList* (*get_int_list) (RygelConfiguration* self, const char* section, const char* key, GError** error);
	gboolean (*get_bool) (RygelConfiguration* self, const char* section, const char* key, GError** error);
};



GQuark rygel_configuration_error_quark (void);
GType rygel_log_level_get_type (void) G_GNUC_CONST;
GType rygel_configuration_get_type (void) G_GNUC_CONST;
gboolean rygel_configuration_get_upnp_enabled (RygelConfiguration* self, GError** error);
char* rygel_configuration_get_interface (RygelConfiguration* self, GError** error);
gint rygel_configuration_get_port (RygelConfiguration* self, GError** error);
gboolean rygel_configuration_get_transcoding (RygelConfiguration* self, GError** error);
gboolean rygel_configuration_get_mp3_transcoder (RygelConfiguration* self, GError** error);
gboolean rygel_configuration_get_mp2ts_transcoder (RygelConfiguration* self, GError** error);
gboolean rygel_configuration_get_lpcm_transcoder (RygelConfiguration* self, GError** error);
gboolean rygel_configuration_get_wmv_transcoder (RygelConfiguration* self, GError** error);
RygelLogLevel rygel_configuration_get_log_level (RygelConfiguration* self, GError** error);
char* rygel_configuration_get_plugin_path (RygelConfiguration* self, GError** error);
gboolean rygel_configuration_get_enabled (RygelConfiguration* self, const char* section, GError** error);
char* rygel_configuration_get_title (RygelConfiguration* self, const char* section, GError** error);
char* rygel_configuration_get_string (RygelConfiguration* self, const char* section, const char* key, GError** error);
GeeArrayList* rygel_configuration_get_string_list (RygelConfiguration* self, const char* section, const char* key, GError** error);
gint rygel_configuration_get_int (RygelConfiguration* self, const char* section, const char* key, gint min, gint max, GError** error);
GeeArrayList* rygel_configuration_get_int_list (RygelConfiguration* self, const char* section, const char* key, GError** error);
gboolean rygel_configuration_get_bool (RygelConfiguration* self, const char* section, const char* key, GError** error);



GQuark rygel_configuration_error_quark (void) {
	return g_quark_from_static_string ("rygel_configuration_error-quark");
}


#line 34 "rygel-configuration.vala"
gboolean rygel_configuration_get_upnp_enabled (RygelConfiguration* self, GError** error) {
#line 34 "rygel-configuration.vala"
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_upnp_enabled (self, error);
#line 116 "rygel-configuration.c"
}


#line 36 "rygel-configuration.vala"
char* rygel_configuration_get_interface (RygelConfiguration* self, GError** error) {
#line 36 "rygel-configuration.vala"
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_interface (self, error);
#line 124 "rygel-configuration.c"
}


#line 38 "rygel-configuration.vala"
gint rygel_configuration_get_port (RygelConfiguration* self, GError** error) {
#line 38 "rygel-configuration.vala"
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_port (self, error);
#line 132 "rygel-configuration.c"
}


#line 40 "rygel-configuration.vala"
gboolean rygel_configuration_get_transcoding (RygelConfiguration* self, GError** error) {
#line 40 "rygel-configuration.vala"
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_transcoding (self, error);
#line 140 "rygel-configuration.c"
}


#line 42 "rygel-configuration.vala"
gboolean rygel_configuration_get_mp3_transcoder (RygelConfiguration* self, GError** error) {
#line 42 "rygel-configuration.vala"
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_mp3_transcoder (self, error);
#line 148 "rygel-configuration.c"
}


#line 44 "rygel-configuration.vala"
gboolean rygel_configuration_get_mp2ts_transcoder (RygelConfiguration* self, GError** error) {
#line 44 "rygel-configuration.vala"
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_mp2ts_transcoder (self, error);
#line 156 "rygel-configuration.c"
}


#line 46 "rygel-configuration.vala"
gboolean rygel_configuration_get_lpcm_transcoder (RygelConfiguration* self, GError** error) {
#line 46 "rygel-configuration.vala"
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_lpcm_transcoder (self, error);
#line 164 "rygel-configuration.c"
}


#line 48 "rygel-configuration.vala"
gboolean rygel_configuration_get_wmv_transcoder (RygelConfiguration* self, GError** error) {
#line 48 "rygel-configuration.vala"
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_wmv_transcoder (self, error);
#line 172 "rygel-configuration.c"
}


#line 50 "rygel-configuration.vala"
RygelLogLevel rygel_configuration_get_log_level (RygelConfiguration* self, GError** error) {
#line 50 "rygel-configuration.vala"
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_log_level (self, error);
#line 180 "rygel-configuration.c"
}


#line 52 "rygel-configuration.vala"
char* rygel_configuration_get_plugin_path (RygelConfiguration* self, GError** error) {
#line 52 "rygel-configuration.vala"
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_plugin_path (self, error);
#line 188 "rygel-configuration.c"
}


#line 54 "rygel-configuration.vala"
gboolean rygel_configuration_get_enabled (RygelConfiguration* self, const char* section, GError** error) {
#line 54 "rygel-configuration.vala"
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_enabled (self, section, error);
#line 196 "rygel-configuration.c"
}


#line 56 "rygel-configuration.vala"
char* rygel_configuration_get_title (RygelConfiguration* self, const char* section, GError** error) {
#line 56 "rygel-configuration.vala"
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_title (self, section, error);
#line 204 "rygel-configuration.c"
}


#line 58 "rygel-configuration.vala"
char* rygel_configuration_get_string (RygelConfiguration* self, const char* section, const char* key, GError** error) {
#line 58 "rygel-configuration.vala"
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_string (self, section, key, error);
#line 212 "rygel-configuration.c"
}


#line 61 "rygel-configuration.vala"
GeeArrayList* rygel_configuration_get_string_list (RygelConfiguration* self, const char* section, const char* key, GError** error) {
#line 61 "rygel-configuration.vala"
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_string_list (self, section, key, error);
#line 220 "rygel-configuration.c"
}


#line 66 "rygel-configuration.vala"
gint rygel_configuration_get_int (RygelConfiguration* self, const char* section, const char* key, gint min, gint max, GError** error) {
#line 66 "rygel-configuration.vala"
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_int (self, section, key, min, max, error);
#line 228 "rygel-configuration.c"
}


#line 72 "rygel-configuration.vala"
GeeArrayList* rygel_configuration_get_int_list (RygelConfiguration* self, const char* section, const char* key, GError** error) {
#line 72 "rygel-configuration.vala"
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_int_list (self, section, key, error);
#line 236 "rygel-configuration.c"
}


#line 76 "rygel-configuration.vala"
gboolean rygel_configuration_get_bool (RygelConfiguration* self, const char* section, const char* key, GError** error) {
#line 76 "rygel-configuration.vala"
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_bool (self, section, key, error);
#line 244 "rygel-configuration.c"
}


static void rygel_configuration_base_init (RygelConfigurationIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
	}
}


GType rygel_configuration_get_type (void) {
	static volatile gsize rygel_configuration_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_configuration_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelConfigurationIface), (GBaseInitFunc) rygel_configuration_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType rygel_configuration_type_id;
		rygel_configuration_type_id = g_type_register_static (G_TYPE_INTERFACE, "RygelConfiguration", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (rygel_configuration_type_id, G_TYPE_OBJECT);
		g_once_init_leave (&rygel_configuration_type_id__volatile, rygel_configuration_type_id);
	}
	return rygel_configuration_type_id__volatile;
}




