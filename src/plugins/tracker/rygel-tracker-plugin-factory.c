/* rygel-tracker-plugin-factory.c generated by valac, the Vala compiler
 * generated from rygel-tracker-plugin-factory.vala, do not modify */

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
#include <dbus/dbus-glib-lowlevel.h>
#include <dbus/dbus-glib.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>
#include <gobject/gvaluecollector.h>


#define TYPE_TRACKER_PLUGIN_FACTORY (tracker_plugin_factory_get_type ())
#define TRACKER_PLUGIN_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TRACKER_PLUGIN_FACTORY, TrackerPluginFactory))
#define TRACKER_PLUGIN_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TRACKER_PLUGIN_FACTORY, TrackerPluginFactoryClass))
#define IS_TRACKER_PLUGIN_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TRACKER_PLUGIN_FACTORY))
#define IS_TRACKER_PLUGIN_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TRACKER_PLUGIN_FACTORY))
#define TRACKER_PLUGIN_FACTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TRACKER_PLUGIN_FACTORY, TrackerPluginFactoryClass))

typedef struct _TrackerPluginFactory TrackerPluginFactory;
typedef struct _TrackerPluginFactoryClass TrackerPluginFactoryClass;
#define _tracker_plugin_factory_unref0(var) ((var == NULL) ? NULL : (var = (tracker_plugin_factory_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _TrackerPluginFactoryPrivate TrackerPluginFactoryPrivate;

#define RYGEL_TYPE_TRACKER_STATS_IFACE (rygel_tracker_stats_iface_get_type ())
#define RYGEL_TRACKER_STATS_IFACE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_STATS_IFACE, RygelTrackerStatsIface))
#define RYGEL_IS_TRACKER_STATS_IFACE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_STATS_IFACE))
#define RYGEL_TRACKER_STATS_IFACE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), RYGEL_TYPE_TRACKER_STATS_IFACE, RygelTrackerStatsIfaceIface))

typedef struct _RygelTrackerStatsIface RygelTrackerStatsIface;
typedef struct _RygelTrackerStatsIfaceIface RygelTrackerStatsIfaceIface;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define RYGEL_TYPE_TRACKER_PLUGIN (rygel_tracker_plugin_get_type ())
#define RYGEL_TRACKER_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_PLUGIN, RygelTrackerPlugin))
#define RYGEL_TRACKER_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_PLUGIN, RygelTrackerPluginClass))
#define RYGEL_IS_TRACKER_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_PLUGIN))
#define RYGEL_IS_TRACKER_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_PLUGIN))
#define RYGEL_TRACKER_PLUGIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_PLUGIN, RygelTrackerPluginClass))

typedef struct _RygelTrackerPlugin RygelTrackerPlugin;
typedef struct _RygelTrackerPluginClass RygelTrackerPluginClass;
#define _dbus_g_connection_unref0(var) ((var == NULL) ? NULL : (var = (dbus_g_connection_unref (var), NULL)))
typedef struct _ParamSpecTrackerPluginFactory ParamSpecTrackerPluginFactory;

struct _TrackerPluginFactory {
	GTypeInstance parent_instance;
	volatile int ref_count;
	TrackerPluginFactoryPrivate * priv;
};

struct _TrackerPluginFactoryClass {
	GTypeClass parent_class;
	void (*finalize) (TrackerPluginFactory *self);
};

struct _RygelTrackerStatsIfaceIface {
	GTypeInterface parent_iface;
	void (*get_statistics) (RygelTrackerStatsIface* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
	char** (*get_statistics_finish) (RygelTrackerStatsIface* self, GAsyncResult* _res_, int* result_length1, int* result_length2, GError** error);
};

struct _TrackerPluginFactoryPrivate {
	RygelTrackerStatsIface* stats;
	RygelPluginLoader* loader;
};

struct _ParamSpecTrackerPluginFactory {
	GParamSpec parent_instance;
};


extern TrackerPluginFactory* plugin_factory;
TrackerPluginFactory* plugin_factory = NULL;
static gpointer tracker_plugin_factory_parent_class = NULL;

gpointer tracker_plugin_factory_ref (gpointer instance);
void tracker_plugin_factory_unref (gpointer instance);
GParamSpec* param_spec_tracker_plugin_factory (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_tracker_plugin_factory (GValue* value, gpointer v_object);
void value_take_tracker_plugin_factory (GValue* value, gpointer v_object);
gpointer value_get_tracker_plugin_factory (const GValue* value);
GType tracker_plugin_factory_get_type (void);
TrackerPluginFactory* tracker_plugin_factory_new (RygelPluginLoader* loader, GError** error);
TrackerPluginFactory* tracker_plugin_factory_construct (GType object_type, RygelPluginLoader* loader, GError** error);
void module_init (RygelPluginLoader* loader);
GType rygel_tracker_stats_iface_get_type (void);
#define TRACKER_PLUGIN_FACTORY_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_TRACKER_PLUGIN_FACTORY, TrackerPluginFactoryPrivate))
enum  {
	TRACKER_PLUGIN_FACTORY_DUMMY_PROPERTY
};
#define TRACKER_PLUGIN_FACTORY_TRACKER_SERVICE "org.freedesktop.Tracker1"
#define TRACKER_PLUGIN_FACTORY_STATISTICS_OBJECT "/org/freedesktop/Tracker1/Statistics"
void rygel_tracker_stats_iface_get_statistics (RygelTrackerStatsIface* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
char** rygel_tracker_stats_iface_get_statistics_finish (RygelTrackerStatsIface* self, GAsyncResult* _res_, int* result_length1, int* result_length2, GError** error);
RygelTrackerPlugin* rygel_tracker_plugin_new (void);
RygelTrackerPlugin* rygel_tracker_plugin_construct (GType object_type);
GType rygel_tracker_plugin_get_type (void);
static void tracker_plugin_factory_finalize (TrackerPluginFactory* obj);



#line 32 "rygel-tracker-plugin-factory.vala"
void module_init (RygelPluginLoader* loader) {
#line 134 "rygel-tracker-plugin-factory.c"
	GError * _inner_error_;
#line 32 "rygel-tracker-plugin-factory.vala"
	g_return_if_fail (loader != NULL);
#line 138 "rygel-tracker-plugin-factory.c"
	_inner_error_ = NULL;
	{
		TrackerPluginFactory* _tmp0_;
		TrackerPluginFactory* _tmp1_;
#line 34 "rygel-tracker-plugin-factory.vala"
		_tmp0_ = tracker_plugin_factory_new (loader, &_inner_error_);
#line 145 "rygel-tracker-plugin-factory.c"
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == DBUS_GERROR) {
				goto __catch10_dbus_gerror;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
#line 34 "rygel-tracker-plugin-factory.vala"
		plugin_factory = (_tmp1_ = _tmp0_, _tracker_plugin_factory_unref0 (plugin_factory), _tmp1_);
#line 156 "rygel-tracker-plugin-factory.c"
	}
	goto __finally10;
	__catch10_dbus_gerror:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp3_;
			char* _tmp2_;
#line 36 "rygel-tracker-plugin-factory.vala"
			g_warning ("rygel-tracker-plugin-factory.vala:36: %s", _tmp3_ = g_strconcat (_tmp2_ = g_strconcat ("Failed to start Tracker service: ", err->message, NULL), ". Tracker plugin disabled.", NULL));
#line 169 "rygel-tracker-plugin-factory.c"
			_g_free0 (_tmp3_);
			_g_free0 (_tmp2_);
			_g_error_free0 (err);
		}
	}
	__finally10:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


#line 50 "rygel-tracker-plugin-factory.vala"
TrackerPluginFactory* tracker_plugin_factory_construct (GType object_type, RygelPluginLoader* loader, GError** error) {
#line 191 "rygel-tracker-plugin-factory.c"
	GError * _inner_error_;
	TrackerPluginFactory* self;
	DBusGConnection* connection;
	RygelTrackerStatsIface* _tmp0_;
	RygelPluginLoader* _tmp1_;
	RygelTrackerPlugin* _tmp2_;
#line 50 "rygel-tracker-plugin-factory.vala"
	g_return_val_if_fail (loader != NULL, NULL);
#line 200 "rygel-tracker-plugin-factory.c"
	_inner_error_ = NULL;
	self = (TrackerPluginFactory*) g_type_create_instance (object_type);
#line 51 "rygel-tracker-plugin-factory.vala"
	connection = dbus_g_bus_get (DBUS_BUS_SESSION, &_inner_error_);
#line 205 "rygel-tracker-plugin-factory.c"
	if (_inner_error_ != NULL) {
		if (_inner_error_->domain == DBUS_GERROR) {
			g_propagate_error (error, _inner_error_);
			tracker_plugin_factory_unref (self);
			return NULL;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
#line 53 "rygel-tracker-plugin-factory.vala"
	self->priv->stats = (_tmp0_ = rygel_tracker_stats_iface_dbus_proxy_new (connection, TRACKER_PLUGIN_FACTORY_TRACKER_SERVICE, TRACKER_PLUGIN_FACTORY_STATISTICS_OBJECT), _g_object_unref0 (self->priv->stats), _tmp0_);
#line 56 "rygel-tracker-plugin-factory.vala"
	self->priv->loader = (_tmp1_ = _g_object_ref0 (loader), _g_object_unref0 (self->priv->loader), _tmp1_);
#line 58 "rygel-tracker-plugin-factory.vala"
	rygel_tracker_stats_iface_get_statistics (self->priv->stats, NULL, NULL);
#line 60 "rygel-tracker-plugin-factory.vala"
	rygel_plugin_loader_add_plugin (self->priv->loader, (RygelPlugin*) (_tmp2_ = rygel_tracker_plugin_new ()));
#line 225 "rygel-tracker-plugin-factory.c"
	_g_object_unref0 (_tmp2_);
	_dbus_g_connection_unref0 (connection);
	return self;
}


#line 50 "rygel-tracker-plugin-factory.vala"
TrackerPluginFactory* tracker_plugin_factory_new (RygelPluginLoader* loader, GError** error) {
#line 50 "rygel-tracker-plugin-factory.vala"
	return tracker_plugin_factory_construct (TYPE_TRACKER_PLUGIN_FACTORY, loader, error);
#line 236 "rygel-tracker-plugin-factory.c"
}


static void value_tracker_plugin_factory_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void value_tracker_plugin_factory_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		tracker_plugin_factory_unref (value->data[0].v_pointer);
	}
}


static void value_tracker_plugin_factory_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = tracker_plugin_factory_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer value_tracker_plugin_factory_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* value_tracker_plugin_factory_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		TrackerPluginFactory* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = tracker_plugin_factory_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* value_tracker_plugin_factory_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	TrackerPluginFactory** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags && G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = tracker_plugin_factory_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* param_spec_tracker_plugin_factory (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	ParamSpecTrackerPluginFactory* spec;
	g_return_val_if_fail (g_type_is_a (object_type, TYPE_TRACKER_PLUGIN_FACTORY), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer value_get_tracker_plugin_factory (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_TRACKER_PLUGIN_FACTORY), NULL);
	return value->data[0].v_pointer;
}


void value_set_tracker_plugin_factory (GValue* value, gpointer v_object) {
	TrackerPluginFactory* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_TRACKER_PLUGIN_FACTORY));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_TRACKER_PLUGIN_FACTORY));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		tracker_plugin_factory_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		tracker_plugin_factory_unref (old);
	}
}


void value_take_tracker_plugin_factory (GValue* value, gpointer v_object) {
	TrackerPluginFactory* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_TRACKER_PLUGIN_FACTORY));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_TRACKER_PLUGIN_FACTORY));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		tracker_plugin_factory_unref (old);
	}
}


static void tracker_plugin_factory_class_init (TrackerPluginFactoryClass * klass) {
	tracker_plugin_factory_parent_class = g_type_class_peek_parent (klass);
	TRACKER_PLUGIN_FACTORY_CLASS (klass)->finalize = tracker_plugin_factory_finalize;
	g_type_class_add_private (klass, sizeof (TrackerPluginFactoryPrivate));
}


static void tracker_plugin_factory_instance_init (TrackerPluginFactory * self) {
	self->priv = TRACKER_PLUGIN_FACTORY_GET_PRIVATE (self);
	self->ref_count = 1;
}


static void tracker_plugin_factory_finalize (TrackerPluginFactory* obj) {
	TrackerPluginFactory * self;
	self = TRACKER_PLUGIN_FACTORY (obj);
	_g_object_unref0 (self->priv->stats);
	_g_object_unref0 (self->priv->loader);
}


GType tracker_plugin_factory_get_type (void) {
	static volatile gsize tracker_plugin_factory_type_id__volatile = 0;
	if (g_once_init_enter (&tracker_plugin_factory_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { value_tracker_plugin_factory_init, value_tracker_plugin_factory_free_value, value_tracker_plugin_factory_copy_value, value_tracker_plugin_factory_peek_pointer, "p", value_tracker_plugin_factory_collect_value, "p", value_tracker_plugin_factory_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (TrackerPluginFactoryClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) tracker_plugin_factory_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (TrackerPluginFactory), 0, (GInstanceInitFunc) tracker_plugin_factory_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType tracker_plugin_factory_type_id;
		tracker_plugin_factory_type_id = g_type_register_fundamental (g_type_fundamental_next (), "TrackerPluginFactory", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&tracker_plugin_factory_type_id__volatile, tracker_plugin_factory_type_id);
	}
	return tracker_plugin_factory_type_id__volatile;
}


gpointer tracker_plugin_factory_ref (gpointer instance) {
	TrackerPluginFactory* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void tracker_plugin_factory_unref (gpointer instance) {
	TrackerPluginFactory* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		TRACKER_PLUGIN_FACTORY_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}




