/* rygel-gst-player.c generated by valac, the Vala compiler
 * generated from rygel-gst-player.vala, do not modify */

/*
 * Copyright (C) 2008 OpenedHand Ltd.
 * Copyright (C) 2009 Nokia Corporation.
 *
 * Author: Jorn Baayen <jorn@openedhand.com>
 *         Zeeshan Ali (Khattak) <zeeshanak@gnome.org>
 *                               <zeeshan.ali@nokia.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 */

#include <glib.h>
#include <glib-object.h>
#include <gst/gst.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <gobject/gvaluecollector.h>


#define RYGEL_TYPE_GST_PLAYER (rygel_gst_player_get_type ())
#define RYGEL_GST_PLAYER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_GST_PLAYER, RygelGstPlayer))
#define RYGEL_GST_PLAYER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_GST_PLAYER, RygelGstPlayerClass))
#define RYGEL_IS_GST_PLAYER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_GST_PLAYER))
#define RYGEL_IS_GST_PLAYER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_GST_PLAYER))
#define RYGEL_GST_PLAYER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_GST_PLAYER, RygelGstPlayerClass))

typedef struct _RygelGstPlayer RygelGstPlayer;
typedef struct _RygelGstPlayerClass RygelGstPlayerClass;
typedef struct _RygelGstPlayerPrivate RygelGstPlayerPrivate;
#define _gst_object_unref0(var) ((var == NULL) ? NULL : (var = (gst_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define TYPE_TIME (time_get_type ())
#define TIME(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TIME, Time))
#define TIME_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TIME, TimeClass))
#define IS_TIME(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TIME))
#define IS_TIME_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TIME))
#define TIME_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TIME, TimeClass))

typedef struct _Time Time;
typedef struct _TimeClass TimeClass;
typedef struct _TimePrivate TimePrivate;
typedef struct _ParamSpecTime ParamSpecTime;

struct _RygelGstPlayer {
	GObject parent_instance;
	RygelGstPlayerPrivate * priv;
};

struct _RygelGstPlayerClass {
	GObjectClass parent_class;
};

struct _RygelGstPlayerPrivate {
	GstElement* playbin;
	char* _playback_state;
};

struct _Time {
	GTypeInstance parent_instance;
	volatile int ref_count;
	TimePrivate * priv;
};

struct _TimeClass {
	GTypeClass parent_class;
	void (*finalize) (Time *self);
};

struct _ParamSpecTime {
	GParamSpec parent_instance;
};


static RygelGstPlayer* rygel_gst_player_player;
static RygelGstPlayer* rygel_gst_player_player = NULL;
static gpointer rygel_gst_player_parent_class = NULL;
static gpointer time_parent_class = NULL;

GType rygel_gst_player_get_type (void);
#define RYGEL_GST_PLAYER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_GST_PLAYER, RygelGstPlayerPrivate))
enum  {
	RYGEL_GST_PLAYER_DUMMY_PROPERTY,
	RYGEL_GST_PLAYER_PLAYBACK_STATE,
	RYGEL_GST_PLAYER_URI,
	RYGEL_GST_PLAYER_VOLUME,
	RYGEL_GST_PLAYER_DURATION,
	RYGEL_GST_PLAYER_POSITION
};
static gboolean rygel_gst_player_bus_handler (RygelGstPlayer* self, GstBus* bus, GstMessage* message);
static gboolean _rygel_gst_player_bus_handler_gst_bus_func (GstBus* bus, GstMessage* message, gpointer self);
static RygelGstPlayer* rygel_gst_player_new (void);
static RygelGstPlayer* rygel_gst_player_construct (GType object_type);
RygelGstPlayer* rygel_gst_player_get_default (void);
GstClockTime time_from_string (const char* str);
gboolean rygel_gst_player_seek (RygelGstPlayer* self, const char* time);
void rygel_gst_player_set_playback_state (RygelGstPlayer* self, const char* value);
const char* rygel_gst_player_get_playback_state (RygelGstPlayer* self);
static inline const char* _dynamic_get_uri0 (GstElement* obj);
const char* rygel_gst_player_get_uri (RygelGstPlayer* self);
static inline void _dynamic_set_uri1 (GstElement* obj, const char* value);
void rygel_gst_player_set_uri (RygelGstPlayer* self, const char* value);
static inline double _dynamic_get_volume2 (GstElement* obj);
double rygel_gst_player_get_volume (RygelGstPlayer* self);
static inline void _dynamic_set_volume3 (GstElement* obj, double value);
void rygel_gst_player_set_volume (RygelGstPlayer* self, double value);
char* time_to_string (GstClockTime time);
char* rygel_gst_player_get_duration (RygelGstPlayer* self);
char* rygel_gst_player_get_position (RygelGstPlayer* self);
static void rygel_gst_player_finalize (GObject* obj);
static void rygel_gst_player_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void rygel_gst_player_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
gpointer time_ref (gpointer instance);
void time_unref (gpointer instance);
GParamSpec* param_spec_time (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_time (GValue* value, gpointer v_object);
gpointer value_get_time (const GValue* value);
GType time_get_type (void);
enum  {
	TIME_DUMMY_PROPERTY
};
Time* time_new (void);
Time* time_construct (GType object_type);
static void time_finalize (Time* obj);



static gboolean _rygel_gst_player_bus_handler_gst_bus_func (GstBus* bus, GstMessage* message, gpointer self) {
	return rygel_gst_player_bus_handler (self, bus, message);
}


static RygelGstPlayer* rygel_gst_player_construct (GType object_type) {
	RygelGstPlayer * self;
	GstElement* _tmp0_;
	GstBus* bus;
	self = (RygelGstPlayer*) g_object_new (object_type, NULL);
	self->priv->playbin = (_tmp0_ = gst_element_factory_make ("playbin2", NULL), _gst_object_unref0 (self->priv->playbin), _tmp0_);
	g_assert (self->priv->playbin != NULL);
	bus = gst_element_get_bus (self->priv->playbin);
	gst_bus_add_watch (bus, _rygel_gst_player_bus_handler_gst_bus_func, self);
	_gst_object_unref0 (bus);
	return self;
}


static RygelGstPlayer* rygel_gst_player_new (void) {
	return rygel_gst_player_construct (RYGEL_TYPE_GST_PLAYER);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


RygelGstPlayer* rygel_gst_player_get_default (void) {
	RygelGstPlayer* result;
	if (rygel_gst_player_player == NULL) {
		RygelGstPlayer* _tmp0_;
		rygel_gst_player_player = (_tmp0_ = rygel_gst_player_new (), _g_object_unref0 (rygel_gst_player_player), _tmp0_);
	}
	result = _g_object_ref0 (rygel_gst_player_player);
	return result;
}


gboolean rygel_gst_player_seek (RygelGstPlayer* self, const char* time) {
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (time != NULL, FALSE);
	g_debug ("rygel-gst-player.vala:127: Seeking to %s.", time);
	result = gst_element_seek (self->priv->playbin, 1.0, GST_FORMAT_TIME, GST_SEEK_FLAG_FLUSH, GST_SEEK_TYPE_SET, (gint64) time_from_string (time), GST_SEEK_TYPE_NONE, (gint64) (-1));
	return result;
}


static gboolean rygel_gst_player_bus_handler (RygelGstPlayer* self, GstBus* bus, GstMessage* message) {
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (bus != NULL, FALSE);
	g_return_val_if_fail (message != NULL, FALSE);
	if (message->type == GST_MESSAGE_EOS) {
		g_debug ("rygel-gst-player.vala:140: EOS");
		rygel_gst_player_set_playback_state (self, "STOPPED");
	}
	result = TRUE;
	return result;
}


const char* rygel_gst_player_get_playback_state (RygelGstPlayer* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_playback_state;
	return result;
}


void rygel_gst_player_set_playback_state (RygelGstPlayer* self, const char* value) {
	char* _tmp0_;
	GQuark _tmp2_;
	const char* _tmp1_;
	static GQuark _tmp2__label0 = 0;
	static GQuark _tmp2__label1 = 0;
	static GQuark _tmp2__label2 = 0;
	g_return_if_fail (self != NULL);
	g_debug ("rygel-gst-player.vala:42: Changing playback state to %s..", value);
	self->priv->_playback_state = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_playback_state), _tmp0_);
	_tmp1_ = self->priv->_playback_state;
	_tmp2_ = (NULL == _tmp1_) ? 0 : g_quark_from_string (_tmp1_);
	if (_tmp2_ == ((0 != _tmp2__label0) ? _tmp2__label0 : (_tmp2__label0 = g_quark_from_static_string ("STOPPED"))))
	do {
		gst_element_set_state (self->priv->playbin, GST_STATE_NULL);
		break;
	} while (0); else if (_tmp2_ == ((0 != _tmp2__label1) ? _tmp2__label1 : (_tmp2__label1 = g_quark_from_static_string ("PAUSED_PLAYBACK"))))
	do {
		gst_element_set_state (self->priv->playbin, GST_STATE_PAUSED);
		break;
	} while (0); else if (_tmp2_ == ((0 != _tmp2__label2) ? _tmp2__label2 : (_tmp2__label2 = g_quark_from_static_string ("PLAYING"))))
	do {
		gst_element_set_state (self->priv->playbin, GST_STATE_PLAYING);
		break;
	} while (0); else
	do {
		break;
	} while (0);
	g_object_notify ((GObject *) self, "playback-state");
}


static inline const char* _dynamic_get_uri0 (GstElement* obj) {
	const char* result;
	g_object_get (obj, "uri", &result, NULL);
	return result;
}


const char* rygel_gst_player_get_uri (RygelGstPlayer* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = _dynamic_get_uri0 (self->priv->playbin);
	return result;
}


static inline void _dynamic_set_uri1 (GstElement* obj, const char* value) {
	g_object_set (obj, "uri", value, NULL);
}


void rygel_gst_player_set_uri (RygelGstPlayer* self, const char* value) {
	g_return_if_fail (self != NULL);
	_dynamic_set_uri1 (self->priv->playbin, value);
	g_debug ("rygel-gst-player.vala:68: URI set to %s.", value);
	g_object_notify ((GObject *) self, "uri");
}


static inline double _dynamic_get_volume2 (GstElement* obj) {
	double result;
	g_object_get (obj, "volume", &result, NULL);
	return result;
}


double rygel_gst_player_get_volume (RygelGstPlayer* self) {
	double result;
	g_return_val_if_fail (self != NULL, 0.0);
	result = _dynamic_get_volume2 (self->priv->playbin);
	return result;
}


static inline void _dynamic_set_volume3 (GstElement* obj, double value) {
	g_object_set (obj, "volume", value, NULL);
}


void rygel_gst_player_set_volume (RygelGstPlayer* self, double value) {
	g_return_if_fail (self != NULL);
	_dynamic_set_volume3 (self->priv->playbin, value);
	g_debug ("rygel-gst-player.vala:79: volume set to %f.", value);
	g_object_notify ((GObject *) self, "volume");
}


char* rygel_gst_player_get_duration (RygelGstPlayer* self) {
	char* result;
	GstFormat format;
	gint64 dur = 0LL;
	g_return_val_if_fail (self != NULL, NULL);
	format = GST_FORMAT_TIME;
	if (gst_element_query_duration (self->priv->playbin, &format, &dur)) {
		result = time_to_string ((GstClockTime) dur);
		return result;
	} else {
		result = g_strdup ("00:00:00");
		return result;
	}
}


char* rygel_gst_player_get_position (RygelGstPlayer* self) {
	char* result;
	GstFormat format;
	gint64 pos = 0LL;
	g_return_val_if_fail (self != NULL, NULL);
	format = GST_FORMAT_TIME;
	if (gst_element_query_position (self->priv->playbin, &format, &pos)) {
		result = time_to_string ((GstClockTime) pos);
		return result;
	} else {
		result = g_strdup ("00:00:00");
		return result;
	}
}


static void rygel_gst_player_class_init (RygelGstPlayerClass * klass) {
	rygel_gst_player_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelGstPlayerPrivate));
	G_OBJECT_CLASS (klass)->get_property = rygel_gst_player_get_property;
	G_OBJECT_CLASS (klass)->set_property = rygel_gst_player_set_property;
	G_OBJECT_CLASS (klass)->finalize = rygel_gst_player_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), RYGEL_GST_PLAYER_PLAYBACK_STATE, g_param_spec_string ("playback-state", "playback-state", "playback-state", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), RYGEL_GST_PLAYER_URI, g_param_spec_string ("uri", "uri", "uri", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), RYGEL_GST_PLAYER_VOLUME, g_param_spec_double ("volume", "volume", "volume", -G_MAXDOUBLE, G_MAXDOUBLE, 0.0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), RYGEL_GST_PLAYER_DURATION, g_param_spec_string ("duration", "duration", "duration", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), RYGEL_GST_PLAYER_POSITION, g_param_spec_string ("position", "position", "position", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
}


static void rygel_gst_player_instance_init (RygelGstPlayer * self) {
	self->priv = RYGEL_GST_PLAYER_GET_PRIVATE (self);
	self->priv->_playback_state = g_strdup ("STOPPED");
}


static void rygel_gst_player_finalize (GObject* obj) {
	RygelGstPlayer * self;
	self = RYGEL_GST_PLAYER (obj);
	_gst_object_unref0 (self->priv->playbin);
	_g_free0 (self->priv->_playback_state);
	G_OBJECT_CLASS (rygel_gst_player_parent_class)->finalize (obj);
}


GType rygel_gst_player_get_type (void) {
	static GType rygel_gst_player_type_id = 0;
	if (rygel_gst_player_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelGstPlayerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_gst_player_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelGstPlayer), 0, (GInstanceInitFunc) rygel_gst_player_instance_init, NULL };
		rygel_gst_player_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelGstPlayer", &g_define_type_info, 0);
	}
	return rygel_gst_player_type_id;
}


static void rygel_gst_player_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	RygelGstPlayer * self;
	self = RYGEL_GST_PLAYER (object);
	switch (property_id) {
		case RYGEL_GST_PLAYER_PLAYBACK_STATE:
		g_value_set_string (value, rygel_gst_player_get_playback_state (self));
		break;
		case RYGEL_GST_PLAYER_URI:
		g_value_set_string (value, rygel_gst_player_get_uri (self));
		break;
		case RYGEL_GST_PLAYER_VOLUME:
		g_value_set_double (value, rygel_gst_player_get_volume (self));
		break;
		case RYGEL_GST_PLAYER_DURATION:
		g_value_set_string (value, rygel_gst_player_get_duration (self));
		break;
		case RYGEL_GST_PLAYER_POSITION:
		g_value_set_string (value, rygel_gst_player_get_position (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void rygel_gst_player_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	RygelGstPlayer * self;
	self = RYGEL_GST_PLAYER (object);
	switch (property_id) {
		case RYGEL_GST_PLAYER_PLAYBACK_STATE:
		rygel_gst_player_set_playback_state (self, g_value_get_string (value));
		break;
		case RYGEL_GST_PLAYER_URI:
		rygel_gst_player_set_uri (self, g_value_get_string (value));
		break;
		case RYGEL_GST_PLAYER_VOLUME:
		rygel_gst_player_set_volume (self, g_value_get_double (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


GstClockTime time_from_string (const char* str) {
	GstClockTime result;
	guint64 hours = 0ULL;
	guint64 minutes = 0ULL;
	guint64 seconds = 0ULL;
	g_return_val_if_fail (str != NULL, 0ULL);
	sscanf (str, "%llu:%2llu:%2llu%*s", &hours, &minutes, &seconds);
	result = (GstClockTime) ((((hours * 3600) + (minutes * 60)) + seconds) * GST_SECOND);
	return result;
}


char* time_to_string (GstClockTime time) {
	char* result;
	guint64 hours = 0ULL;
	guint64 minutes = 0ULL;
	guint64 seconds = 0ULL;
	hours = (guint64) ((time / GST_SECOND) / 3600);
	seconds = (guint64) ((time / GST_SECOND) % 3600);
	minutes = seconds / 60;
	seconds = seconds % 60;
	result = g_strdup_printf ("%llu:%.2llu:%.2llu", hours, minutes, seconds);
	return result;
}


Time* time_construct (GType object_type) {
	Time* self;
	self = (Time*) g_type_create_instance (object_type);
	return self;
}


Time* time_new (void) {
	return time_construct (TYPE_TIME);
}


static void value_time_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void value_time_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		time_unref (value->data[0].v_pointer);
	}
}


static void value_time_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = time_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer value_time_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* value_time_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		Time* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = time_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* value_time_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	Time** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags && G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = time_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* param_spec_time (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	ParamSpecTime* spec;
	g_return_val_if_fail (g_type_is_a (object_type, TYPE_TIME), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer value_get_time (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_TIME), NULL);
	return value->data[0].v_pointer;
}


void value_set_time (GValue* value, gpointer v_object) {
	Time* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_TIME));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_TIME));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		time_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		time_unref (old);
	}
}


static void time_class_init (TimeClass * klass) {
	time_parent_class = g_type_class_peek_parent (klass);
	TIME_CLASS (klass)->finalize = time_finalize;
}


static void time_instance_init (Time * self) {
	self->ref_count = 1;
}


static void time_finalize (Time* obj) {
	Time * self;
	self = TIME (obj);
}


GType time_get_type (void) {
	static GType time_type_id = 0;
	if (time_type_id == 0) {
		static const GTypeValueTable g_define_type_value_table = { value_time_init, value_time_free_value, value_time_copy_value, value_time_peek_pointer, "p", value_time_collect_value, "p", value_time_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (TimeClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) time_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Time), 0, (GInstanceInitFunc) time_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		time_type_id = g_type_register_fundamental (g_type_fundamental_next (), "Time", &g_define_type_info, &g_define_type_fundamental_info, 0);
	}
	return time_type_id;
}


gpointer time_ref (gpointer instance) {
	Time* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void time_unref (gpointer instance) {
	Time* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		TIME_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}



