/* rygel-media-player.c generated by valac, the Vala compiler
 * generated from rygel-media-player.vala, do not modify */

/*
 * Copyright (C) 2008 OpenedHand Ltd.
 * Copyright (C) 2009,2010 Nokia Corporation.
 *
 * Author: Jorn Baayen <jorn@openedhand.com>
 *         Zeeshan Ali (Khattak) <zeeshanak@gnome.org>
 *                               <zeeshan.ali@nokia.com>
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
#include <float.h>
#include <math.h>


#define RYGEL_TYPE_MEDIA_PLAYER (rygel_media_player_get_type ())
#define RYGEL_MEDIA_PLAYER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_PLAYER, RygelMediaPlayer))
#define RYGEL_IS_MEDIA_PLAYER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_PLAYER))
#define RYGEL_MEDIA_PLAYER_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), RYGEL_TYPE_MEDIA_PLAYER, RygelMediaPlayerIface))

typedef struct _RygelMediaPlayer RygelMediaPlayer;
typedef struct _RygelMediaPlayerIface RygelMediaPlayerIface;

struct _RygelMediaPlayerIface {
	GTypeInterface parent_iface;
	gboolean (*seek) (RygelMediaPlayer* self, const char* time);
	char** (*get_protocols) (RygelMediaPlayer* self, int* result_length1);
	char** (*get_mime_types) (RygelMediaPlayer* self, int* result_length1);
	const char* (*get_playback_state) (RygelMediaPlayer* self);
	void (*set_playback_state) (RygelMediaPlayer* self, const char* value);
	const char* (*get_uri) (RygelMediaPlayer* self);
	void (*set_uri) (RygelMediaPlayer* self, const char* value);
	double (*get_volume) (RygelMediaPlayer* self);
	void (*set_volume) (RygelMediaPlayer* self, double value);
	char* (*get_duration) (RygelMediaPlayer* self);
	char* (*get_position) (RygelMediaPlayer* self);
};



GType rygel_media_player_get_type (void) G_GNUC_CONST;
gboolean rygel_media_player_seek (RygelMediaPlayer* self, const char* time);
char** rygel_media_player_get_protocols (RygelMediaPlayer* self, int* result_length1);
char** rygel_media_player_get_mime_types (RygelMediaPlayer* self, int* result_length1);
const char* rygel_media_player_get_playback_state (RygelMediaPlayer* self);
void rygel_media_player_set_playback_state (RygelMediaPlayer* self, const char* value);
const char* rygel_media_player_get_uri (RygelMediaPlayer* self);
void rygel_media_player_set_uri (RygelMediaPlayer* self, const char* value);
double rygel_media_player_get_volume (RygelMediaPlayer* self);
void rygel_media_player_set_volume (RygelMediaPlayer* self, double value);
char* rygel_media_player_get_duration (RygelMediaPlayer* self);
char* rygel_media_player_get_position (RygelMediaPlayer* self);



#line 31 "rygel-media-player.vala"
gboolean rygel_media_player_seek (RygelMediaPlayer* self, const char* time) {
#line 31 "rygel-media-player.vala"
	return RYGEL_MEDIA_PLAYER_GET_INTERFACE (self)->seek (self, time);
#line 80 "rygel-media-player.c"
}


#line 32 "rygel-media-player.vala"
char** rygel_media_player_get_protocols (RygelMediaPlayer* self, int* result_length1) {
#line 32 "rygel-media-player.vala"
	return RYGEL_MEDIA_PLAYER_GET_INTERFACE (self)->get_protocols (self, result_length1);
#line 88 "rygel-media-player.c"
}


#line 33 "rygel-media-player.vala"
char** rygel_media_player_get_mime_types (RygelMediaPlayer* self, int* result_length1) {
#line 33 "rygel-media-player.vala"
	return RYGEL_MEDIA_PLAYER_GET_INTERFACE (self)->get_mime_types (self, result_length1);
#line 96 "rygel-media-player.c"
}


const char* rygel_media_player_get_playback_state (RygelMediaPlayer* self) {
	return RYGEL_MEDIA_PLAYER_GET_INTERFACE (self)->get_playback_state (self);
}


void rygel_media_player_set_playback_state (RygelMediaPlayer* self, const char* value) {
	RYGEL_MEDIA_PLAYER_GET_INTERFACE (self)->set_playback_state (self, value);
}


const char* rygel_media_player_get_uri (RygelMediaPlayer* self) {
	return RYGEL_MEDIA_PLAYER_GET_INTERFACE (self)->get_uri (self);
}


void rygel_media_player_set_uri (RygelMediaPlayer* self, const char* value) {
	RYGEL_MEDIA_PLAYER_GET_INTERFACE (self)->set_uri (self, value);
}


double rygel_media_player_get_volume (RygelMediaPlayer* self) {
	return RYGEL_MEDIA_PLAYER_GET_INTERFACE (self)->get_volume (self);
}


void rygel_media_player_set_volume (RygelMediaPlayer* self, double value) {
	RYGEL_MEDIA_PLAYER_GET_INTERFACE (self)->set_volume (self, value);
}


char* rygel_media_player_get_duration (RygelMediaPlayer* self) {
	return RYGEL_MEDIA_PLAYER_GET_INTERFACE (self)->get_duration (self);
}


char* rygel_media_player_get_position (RygelMediaPlayer* self) {
	return RYGEL_MEDIA_PLAYER_GET_INTERFACE (self)->get_position (self);
}


static void rygel_media_player_base_init (RygelMediaPlayerIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
		g_object_interface_install_property (iface, g_param_spec_string ("playback-state", "playback-state", "playback-state", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
		g_object_interface_install_property (iface, g_param_spec_string ("uri", "uri", "uri", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
		g_object_interface_install_property (iface, g_param_spec_double ("volume", "volume", "volume", -G_MAXDOUBLE, G_MAXDOUBLE, 0.0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
		g_object_interface_install_property (iface, g_param_spec_string ("duration", "duration", "duration", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
		g_object_interface_install_property (iface, g_param_spec_string ("position", "position", "position", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	}
}


GType rygel_media_player_get_type (void) {
	static volatile gsize rygel_media_player_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_media_player_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediaPlayerIface), (GBaseInitFunc) rygel_media_player_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType rygel_media_player_type_id;
		rygel_media_player_type_id = g_type_register_static (G_TYPE_INTERFACE, "RygelMediaPlayer", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (rygel_media_player_type_id, G_TYPE_OBJECT);
		g_once_init_leave (&rygel_media_player_type_id__volatile, rygel_media_player_type_id);
	}
	return rygel_media_player_type_id__volatile;
}




