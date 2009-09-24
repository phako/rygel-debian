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

typedef enum  {
	RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET,
	RYGEL_CONFIGURATION_ERROR_VALUE_OUT_OF_RANGE
} RygelConfigurationError;
#define RYGEL_CONFIGURATION_ERROR rygel_configuration_error_quark ()
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



GQuark rygel_configuration_error_quark (void);
GType rygel_configuration_get_type (void);
gboolean rygel_configuration_get_upnp_enabled (RygelConfiguration* self, GError** error);
char* rygel_configuration_get_interface (RygelConfiguration* self, GError** error);
gint rygel_configuration_get_port (RygelConfiguration* self, GError** error);
gboolean rygel_configuration_get_transcoding (RygelConfiguration* self, GError** error);
gboolean rygel_configuration_get_mp3_transcoder (RygelConfiguration* self, GError** error);
gboolean rygel_configuration_get_mp2ts_transcoder (RygelConfiguration* self, GError** error);
gboolean rygel_configuration_get_lpcm_transcoder (RygelConfiguration* self, GError** error);
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


gboolean rygel_configuration_get_upnp_enabled (RygelConfiguration* self, GError** error) {
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_upnp_enabled (self, error);
}


char* rygel_configuration_get_interface (RygelConfiguration* self, GError** error) {
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_interface (self, error);
}


gint rygel_configuration_get_port (RygelConfiguration* self, GError** error) {
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_port (self, error);
}


gboolean rygel_configuration_get_transcoding (RygelConfiguration* self, GError** error) {
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_transcoding (self, error);
}


gboolean rygel_configuration_get_mp3_transcoder (RygelConfiguration* self, GError** error) {
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_mp3_transcoder (self, error);
}


gboolean rygel_configuration_get_mp2ts_transcoder (RygelConfiguration* self, GError** error) {
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_mp2ts_transcoder (self, error);
}


gboolean rygel_configuration_get_lpcm_transcoder (RygelConfiguration* self, GError** error) {
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_lpcm_transcoder (self, error);
}


gboolean rygel_configuration_get_enabled (RygelConfiguration* self, const char* section, GError** error) {
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_enabled (self, section, error);
}


char* rygel_configuration_get_title (RygelConfiguration* self, const char* section, GError** error) {
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_title (self, section, error);
}


char* rygel_configuration_get_string (RygelConfiguration* self, const char* section, const char* key, GError** error) {
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_string (self, section, key, error);
}


GeeArrayList* rygel_configuration_get_string_list (RygelConfiguration* self, const char* section, const char* key, GError** error) {
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_string_list (self, section, key, error);
}


gint rygel_configuration_get_int (RygelConfiguration* self, const char* section, const char* key, gint min, gint max, GError** error) {
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_int (self, section, key, min, max, error);
}


GeeArrayList* rygel_configuration_get_int_list (RygelConfiguration* self, const char* section, const char* key, GError** error) {
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_int_list (self, section, key, error);
}


gboolean rygel_configuration_get_bool (RygelConfiguration* self, const char* section, const char* key, GError** error) {
	return RYGEL_CONFIGURATION_GET_INTERFACE (self)->get_bool (self, section, key, error);
}


static void rygel_configuration_base_init (RygelConfigurationIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
	}
}


GType rygel_configuration_get_type (void) {
	static GType rygel_configuration_type_id = 0;
	if (rygel_configuration_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelConfigurationIface), (GBaseInitFunc) rygel_configuration_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		rygel_configuration_type_id = g_type_register_static (G_TYPE_INTERFACE, "RygelConfiguration", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (rygel_configuration_type_id, G_TYPE_OBJECT);
	}
	return rygel_configuration_type_id;
}




