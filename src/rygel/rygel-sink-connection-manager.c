/* rygel-sink-connection-manager.c generated by valac, the Vala compiler
 * generated from rygel-sink-connection-manager.vala, do not modify */

/*
 * Copyright (C) 2008 OpenedHand Ltd.
 * Copyright (C) 2009 Nokia Corporation.
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
#include <libgupnp/gupnp.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>


#define RYGEL_TYPE_CONNECTION_MANAGER (rygel_connection_manager_get_type ())
#define RYGEL_CONNECTION_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_CONNECTION_MANAGER, RygelConnectionManager))
#define RYGEL_CONNECTION_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_CONNECTION_MANAGER, RygelConnectionManagerClass))
#define RYGEL_IS_CONNECTION_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_CONNECTION_MANAGER))
#define RYGEL_IS_CONNECTION_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_CONNECTION_MANAGER))
#define RYGEL_CONNECTION_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_CONNECTION_MANAGER, RygelConnectionManagerClass))

typedef struct _RygelConnectionManager RygelConnectionManager;
typedef struct _RygelConnectionManagerClass RygelConnectionManagerClass;
typedef struct _RygelConnectionManagerPrivate RygelConnectionManagerPrivate;

#define RYGEL_TYPE_SINK_CONNECTION_MANAGER (rygel_sink_connection_manager_get_type ())
#define RYGEL_SINK_CONNECTION_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_SINK_CONNECTION_MANAGER, RygelSinkConnectionManager))
#define RYGEL_SINK_CONNECTION_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_SINK_CONNECTION_MANAGER, RygelSinkConnectionManagerClass))
#define RYGEL_IS_SINK_CONNECTION_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_SINK_CONNECTION_MANAGER))
#define RYGEL_IS_SINK_CONNECTION_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_SINK_CONNECTION_MANAGER))
#define RYGEL_SINK_CONNECTION_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_SINK_CONNECTION_MANAGER, RygelSinkConnectionManagerClass))

typedef struct _RygelSinkConnectionManager RygelSinkConnectionManager;
typedef struct _RygelSinkConnectionManagerClass RygelSinkConnectionManagerClass;
typedef struct _RygelSinkConnectionManagerPrivate RygelSinkConnectionManagerPrivate;

#define RYGEL_TYPE_MEDIA_PLAYER (rygel_media_player_get_type ())
#define RYGEL_MEDIA_PLAYER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_PLAYER, RygelMediaPlayer))
#define RYGEL_IS_MEDIA_PLAYER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_PLAYER))
#define RYGEL_MEDIA_PLAYER_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), RYGEL_TYPE_MEDIA_PLAYER, RygelMediaPlayerIface))

typedef struct _RygelMediaPlayer RygelMediaPlayer;
typedef struct _RygelMediaPlayerIface RygelMediaPlayerIface;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define RYGEL_TYPE_PLUGIN (rygel_plugin_get_type ())
#define RYGEL_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_PLUGIN, RygelPlugin))
#define RYGEL_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_PLUGIN, RygelPluginClass))
#define RYGEL_IS_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_PLUGIN))
#define RYGEL_IS_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_PLUGIN))
#define RYGEL_PLUGIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_PLUGIN, RygelPluginClass))

typedef struct _RygelPlugin RygelPlugin;
typedef struct _RygelPluginClass RygelPluginClass;

#define RYGEL_TYPE_MEDIA_RENDERER_PLUGIN (rygel_media_renderer_plugin_get_type ())
#define RYGEL_MEDIA_RENDERER_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_RENDERER_PLUGIN, RygelMediaRendererPlugin))
#define RYGEL_MEDIA_RENDERER_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_RENDERER_PLUGIN, RygelMediaRendererPluginClass))
#define RYGEL_IS_MEDIA_RENDERER_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_RENDERER_PLUGIN))
#define RYGEL_IS_MEDIA_RENDERER_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_RENDERER_PLUGIN))
#define RYGEL_MEDIA_RENDERER_PLUGIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_RENDERER_PLUGIN, RygelMediaRendererPluginClass))

typedef struct _RygelMediaRendererPlugin RygelMediaRendererPlugin;
typedef struct _RygelMediaRendererPluginClass RygelMediaRendererPluginClass;
#define _g_free0(var) (var = (g_free (var), NULL))

struct _RygelConnectionManager {
	GUPnPService parent_instance;
	RygelConnectionManagerPrivate * priv;
	char* sink_protocol_info;
	char* connection_ids;
	char* source_protocol_info;
};

struct _RygelConnectionManagerClass {
	GUPnPServiceClass parent_class;
};

struct _RygelSinkConnectionManager {
	RygelConnectionManager parent_instance;
	RygelSinkConnectionManagerPrivate * priv;
};

struct _RygelSinkConnectionManagerClass {
	RygelConnectionManagerClass parent_class;
};

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

struct _RygelSinkConnectionManagerPrivate {
	RygelMediaPlayer* player;
};


static gpointer rygel_sink_connection_manager_parent_class = NULL;

GType rygel_connection_manager_get_type (void) G_GNUC_CONST;
GType rygel_sink_connection_manager_get_type (void) G_GNUC_CONST;
GType rygel_media_player_get_type (void) G_GNUC_CONST;
#define RYGEL_SINK_CONNECTION_MANAGER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_SINK_CONNECTION_MANAGER, RygelSinkConnectionManagerPrivate))
enum  {
	RYGEL_SINK_CONNECTION_MANAGER_DUMMY_PROPERTY
};
GType rygel_plugin_get_type (void) G_GNUC_CONST;
GType rygel_media_renderer_plugin_get_type (void) G_GNUC_CONST;
RygelMediaPlayer* rygel_media_renderer_plugin_get_player (RygelMediaRendererPlugin* self);
char** rygel_media_player_get_protocols (RygelMediaPlayer* self, int* result_length1);
char** rygel_media_player_get_mime_types (RygelMediaPlayer* self, int* result_length1);
static void rygel_sink_connection_manager_real_constructed (GObject* base);
RygelConnectionManager* rygel_connection_manager_new (void);
RygelConnectionManager* rygel_connection_manager_construct (GType object_type);
RygelSinkConnectionManager* rygel_sink_connection_manager_new (void);
RygelSinkConnectionManager* rygel_sink_connection_manager_construct (GType object_type);
static void rygel_sink_connection_manager_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static int _vala_strcmp0 (const char * str1, const char * str2);



static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


#line 29 "rygel-sink-connection-manager.vala"
static void rygel_sink_connection_manager_real_constructed (GObject* base) {
#line 163 "rygel-sink-connection-manager.c"
	RygelSinkConnectionManager * self;
	GUPnPRootDevice* _tmp1_;
	GUPnPRootDevice* _tmp0_ = NULL;
	GUPnPResourceFactory* _tmp2_;
	RygelMediaRendererPlugin* _tmp3_;
	RygelMediaRendererPlugin* plugin;
	RygelMediaPlayer* _tmp4_;
	self = (RygelSinkConnectionManager*) base;
#line 30 "rygel-sink-connection-manager.vala"
	G_OBJECT_CLASS (rygel_sink_connection_manager_parent_class)->constructed ((GObject*) RYGEL_CONNECTION_MANAGER (self));
#line 32 "rygel-sink-connection-manager.vala"
	plugin = (_tmp3_ = _g_object_ref0 ((_tmp2_ = gupnp_device_info_get_resource_factory ((GUPnPDeviceInfo*) (_tmp1_ = (g_object_get ((GUPnPService*) self, "root-device", &_tmp0_, NULL), _tmp0_))), RYGEL_IS_MEDIA_RENDERER_PLUGIN (_tmp2_) ? ((RygelMediaRendererPlugin*) _tmp2_) : NULL)), _g_object_unref0 (_tmp1_), _tmp3_);
#line 33 "rygel-sink-connection-manager.vala"
	self->priv->player = (_tmp4_ = rygel_media_renderer_plugin_get_player (plugin), _g_object_unref0 (self->priv->player), _tmp4_);
#line 178 "rygel-sink-connection-manager.c"
	{
		gint _tmp5_;
		char** protocol_collection;
		int protocol_collection_length1;
		int protocol_it;
#line 35 "rygel-sink-connection-manager.vala"
		protocol_collection = rygel_media_player_get_protocols (self->priv->player, &_tmp5_);
#line 186 "rygel-sink-connection-manager.c"
		protocol_collection_length1 = _tmp5_;
		for (protocol_it = 0; protocol_it < _tmp5_; protocol_it = protocol_it + 1) {
			char* protocol;
			protocol = g_strdup (protocol_collection[protocol_it]);
			{
				char** _tmp7_;
				gint _mime_types_size_;
				gint mime_types_length1;
				gint _tmp6_;
				char** mime_types;
				mime_types = (_tmp7_ = rygel_media_player_get_mime_types (self->priv->player, &_tmp6_), mime_types_length1 = _tmp6_, _mime_types_size_ = mime_types_length1, _tmp7_);
				{
					char** mime_type_collection;
					int mime_type_collection_length1;
					int mime_type_it;
#line 38 "rygel-sink-connection-manager.vala"
					mime_type_collection = mime_types;
#line 204 "rygel-sink-connection-manager.c"
					mime_type_collection_length1 = mime_types_length1;
					for (mime_type_it = 0; mime_type_it < mime_types_length1; mime_type_it = mime_type_it + 1) {
						char* mime_type;
						mime_type = g_strdup (mime_type_collection[mime_type_it]);
						{
							char* _tmp12_;
							char* _tmp11_;
							char* _tmp10_;
							char* _tmp9_;
#line 39 "rygel-sink-connection-manager.vala"
							if (_vala_strcmp0 (mime_types[0], mime_type) != 0) {
#line 216 "rygel-sink-connection-manager.c"
								char* _tmp8_;
#line 40 "rygel-sink-connection-manager.vala"
								((RygelConnectionManager*) self)->sink_protocol_info = (_tmp8_ = g_strconcat (((RygelConnectionManager*) self)->sink_protocol_info, ",", NULL), _g_free0 (((RygelConnectionManager*) self)->sink_protocol_info), _tmp8_);
#line 220 "rygel-sink-connection-manager.c"
							}
#line 43 "rygel-sink-connection-manager.vala"
							((RygelConnectionManager*) self)->sink_protocol_info = (_tmp12_ = g_strconcat (((RygelConnectionManager*) self)->sink_protocol_info, _tmp11_ = g_strconcat (_tmp10_ = g_strconcat (_tmp9_ = g_strconcat (protocol, ":*:", NULL), mime_type, NULL), ":*", NULL), NULL), _g_free0 (((RygelConnectionManager*) self)->sink_protocol_info), _tmp12_);
#line 224 "rygel-sink-connection-manager.c"
							_g_free0 (_tmp11_);
							_g_free0 (_tmp10_);
							_g_free0 (_tmp9_);
							_g_free0 (mime_type);
						}
					}
				}
				mime_types = (_vala_array_free (mime_types, mime_types_length1, (GDestroyNotify) g_free), NULL);
				_g_free0 (protocol);
			}
		}
#line 35 "rygel-sink-connection-manager.vala"
		protocol_collection = (_vala_array_free (protocol_collection, protocol_collection_length1, (GDestroyNotify) g_free), NULL);
#line 238 "rygel-sink-connection-manager.c"
	}
	_g_object_unref0 (plugin);
}


#line 26 "rygel-sink-connection-manager.vala"
RygelSinkConnectionManager* rygel_sink_connection_manager_construct (GType object_type) {
#line 246 "rygel-sink-connection-manager.c"
	RygelSinkConnectionManager * self;
#line 26 "rygel-sink-connection-manager.vala"
	self = (RygelSinkConnectionManager*) rygel_connection_manager_construct (object_type);
#line 250 "rygel-sink-connection-manager.c"
	return self;
}


#line 26 "rygel-sink-connection-manager.vala"
RygelSinkConnectionManager* rygel_sink_connection_manager_new (void) {
#line 26 "rygel-sink-connection-manager.vala"
	return rygel_sink_connection_manager_construct (RYGEL_TYPE_SINK_CONNECTION_MANAGER);
#line 259 "rygel-sink-connection-manager.c"
}


static void rygel_sink_connection_manager_class_init (RygelSinkConnectionManagerClass * klass) {
	rygel_sink_connection_manager_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelSinkConnectionManagerPrivate));
	G_OBJECT_CLASS (klass)->constructed = rygel_sink_connection_manager_real_constructed;
	G_OBJECT_CLASS (klass)->finalize = rygel_sink_connection_manager_finalize;
}


static void rygel_sink_connection_manager_instance_init (RygelSinkConnectionManager * self) {
	self->priv = RYGEL_SINK_CONNECTION_MANAGER_GET_PRIVATE (self);
}


static void rygel_sink_connection_manager_finalize (GObject* obj) {
	RygelSinkConnectionManager * self;
	self = RYGEL_SINK_CONNECTION_MANAGER (obj);
	_g_object_unref0 (self->priv->player);
	G_OBJECT_CLASS (rygel_sink_connection_manager_parent_class)->finalize (obj);
}


GType rygel_sink_connection_manager_get_type (void) {
	static volatile gsize rygel_sink_connection_manager_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_sink_connection_manager_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelSinkConnectionManagerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_sink_connection_manager_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelSinkConnectionManager), 0, (GInstanceInitFunc) rygel_sink_connection_manager_instance_init, NULL };
		GType rygel_sink_connection_manager_type_id;
		rygel_sink_connection_manager_type_id = g_type_register_static (RYGEL_TYPE_CONNECTION_MANAGER, "RygelSinkConnectionManager", &g_define_type_info, 0);
		g_once_init_leave (&rygel_sink_connection_manager_type_id__volatile, rygel_sink_connection_manager_type_id);
	}
	return rygel_sink_connection_manager_type_id__volatile;
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




