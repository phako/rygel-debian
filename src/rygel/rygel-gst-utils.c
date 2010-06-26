/* rygel-gst-utils.c generated by valac, the Vala compiler
 * generated from rygel-gst-utils.vala, do not modify */

/*
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
#include <gst/gst.h>
#include <glib/gi18n-lib.h>
#include <stdlib.h>
#include <string.h>
#include <gobject/gvaluecollector.h>


#define RYGEL_TYPE_GST_UTILS (rygel_gst_utils_get_type ())
#define RYGEL_GST_UTILS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_GST_UTILS, RygelGstUtils))
#define RYGEL_GST_UTILS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_GST_UTILS, RygelGstUtilsClass))
#define RYGEL_IS_GST_UTILS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_GST_UTILS))
#define RYGEL_IS_GST_UTILS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_GST_UTILS))
#define RYGEL_GST_UTILS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_GST_UTILS, RygelGstUtilsClass))

typedef struct _RygelGstUtils RygelGstUtils;
typedef struct _RygelGstUtilsClass RygelGstUtilsClass;
typedef struct _RygelGstUtilsPrivate RygelGstUtilsPrivate;
#define _gst_object_unref0(var) ((var == NULL) ? NULL : (var = (gst_object_unref (var), NULL)))
#define _gst_message_unref0(var) ((var == NULL) ? NULL : (var = (gst_message_unref (var), NULL)))
#define __g_list_free_gst_object_unref0(var) ((var == NULL) ? NULL : (var = (_g_list_free_gst_object_unref (var), NULL)))
#define _gst_structure_free0(var) ((var == NULL) ? NULL : (var = (gst_structure_free (var), NULL)))
typedef struct _RygelParamSpecGstUtils RygelParamSpecGstUtils;

typedef enum  {
	RYGEL_GST_ERROR_MISSING_PLUGIN,
	RYGEL_GST_ERROR_LINK
} RygelGstError;
#define RYGEL_GST_ERROR rygel_gst_error_quark ()
struct _RygelGstUtils {
	GTypeInstance parent_instance;
	volatile int ref_count;
	RygelGstUtilsPrivate * priv;
};

struct _RygelGstUtilsClass {
	GTypeClass parent_class;
	void (*finalize) (RygelGstUtils *self);
};

struct _RygelParamSpecGstUtils {
	GParamSpec parent_instance;
};


static gpointer rygel_gst_utils_parent_class = NULL;

GQuark rygel_gst_error_quark (void);
gpointer rygel_gst_utils_ref (gpointer instance);
void rygel_gst_utils_unref (gpointer instance);
GParamSpec* rygel_param_spec_gst_utils (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_gst_utils (GValue* value, gpointer v_object);
void rygel_value_take_gst_utils (GValue* value, gpointer v_object);
gpointer rygel_value_get_gst_utils (const GValue* value);
GType rygel_gst_utils_get_type (void);
enum  {
	RYGEL_GST_UTILS_DUMMY_PROPERTY
};
GstElement* rygel_gst_utils_create_element (const char* factoryname, const char* name, GError** error);
void rygel_gst_utils_post_error (GstElement* dest, GError* _error_);
static gboolean rygel_gst_utils_need_rtp_depayloader (GstCaps* caps);
static gboolean rygel_gst_utils_rtp_depay_filter (GstPluginFeature* feature);
static gboolean _rygel_gst_utils_rtp_depay_filter_gst_plugin_feature_filter (GstPluginFeature* feature, gpointer self);
static GstElement* rygel_gst_utils_get_best_depay (GList* features, GstCaps* caps);
static void _g_list_free_gst_object_unref (GList* self);
GstElement* rygel_gst_utils_get_rtp_depayloader (GstCaps* caps);
static gint rygel_gst_utils_compare_factories (void* a, void* b);
static gint _rygel_gst_utils_compare_factories_gcompare_func (void* a, void* b);
RygelGstUtils* rygel_gst_utils_construct (GType object_type);
static void rygel_gst_utils_finalize (RygelGstUtils* obj);
static int _vala_strcmp0 (const char * str1, const char * str2);



GQuark rygel_gst_error_quark (void) {
	return g_quark_from_static_string ("rygel_gst_error-quark");
}


#line 32 "rygel-gst-utils.vala"
GstElement* rygel_gst_utils_create_element (const char* factoryname, const char* name, GError** error) {
#line 110 "rygel-gst-utils.c"
	GstElement* result = NULL;
	GError * _inner_error_;
	GstElement* element;
#line 32 "rygel-gst-utils.vala"
	g_return_val_if_fail (factoryname != NULL, NULL);
#line 116 "rygel-gst-utils.c"
	_inner_error_ = NULL;
#line 35 "rygel-gst-utils.vala"
	element = gst_element_factory_make (factoryname, name);
#line 36 "rygel-gst-utils.vala"
	if (element == NULL) {
#line 122 "rygel-gst-utils.c"
		_inner_error_ = g_error_new (RYGEL_GST_ERROR, RYGEL_GST_ERROR_MISSING_PLUGIN, _ ("Required element %s missing"), factoryname);
		{
			g_propagate_error (error, _inner_error_);
			_gst_object_unref0 (element);
			return NULL;
		}
	}
	result = element;
#line 42 "rygel-gst-utils.vala"
	return result;
#line 133 "rygel-gst-utils.c"
}


static gpointer _gst_message_ref0 (gpointer self) {
	return self ? gst_message_ref (self) : NULL;
}


#line 45 "rygel-gst-utils.vala"
void rygel_gst_utils_post_error (GstElement* dest, GError* _error_) {
#line 144 "rygel-gst-utils.c"
	GstMessage* msg;
#line 45 "rygel-gst-utils.vala"
	g_return_if_fail (dest != NULL);
#line 46 "rygel-gst-utils.vala"
	msg = gst_message_new_error ((GstObject*) dest, _error_, _error_->message);
#line 47 "rygel-gst-utils.vala"
	gst_element_post_message (dest, _gst_message_ref0 (msg));
#line 152 "rygel-gst-utils.c"
	_gst_message_unref0 (msg);
}


#line 93 "rygel-gst-utils.vala"
static gboolean _rygel_gst_utils_rtp_depay_filter_gst_plugin_feature_filter (GstPluginFeature* feature, gpointer self) {
#line 159 "rygel-gst-utils.c"
	gboolean result;
	result = rygel_gst_utils_rtp_depay_filter (feature);
	return result;
}


static void _g_list_free_gst_object_unref (GList* self) {
	g_list_foreach (self, (GFunc) gst_object_unref, NULL);
	g_list_free (self);
}


#line 50 "rygel-gst-utils.vala"
GstElement* rygel_gst_utils_get_rtp_depayloader (GstCaps* caps) {
#line 174 "rygel-gst-utils.c"
	GstElement* result = NULL;
	GstRegistry* registry;
	GList* features;
#line 50 "rygel-gst-utils.vala"
	g_return_val_if_fail (caps != NULL, NULL);
#line 51 "rygel-gst-utils.vala"
	if (!rygel_gst_utils_need_rtp_depayloader (caps)) {
#line 182 "rygel-gst-utils.c"
		result = NULL;
#line 52 "rygel-gst-utils.vala"
		return result;
#line 186 "rygel-gst-utils.c"
	}
#line 55 "rygel-gst-utils.vala"
	registry = gst_registry_get_default ();
#line 56 "rygel-gst-utils.vala"
	features = gst_registry_feature_filter (registry, _rygel_gst_utils_rtp_depay_filter_gst_plugin_feature_filter, FALSE, NULL);
#line 192 "rygel-gst-utils.c"
	result = rygel_gst_utils_get_best_depay (features, caps);
	__g_list_free_gst_object_unref0 (features);
#line 58 "rygel-gst-utils.vala"
	return result;
#line 197 "rygel-gst-utils.c"
}


static gpointer _gst_structure_copy0 (gpointer self) {
	return self ? gst_structure_copy (self) : NULL;
}


#line 61 "rygel-gst-utils.vala"
static gboolean rygel_gst_utils_need_rtp_depayloader (GstCaps* caps) {
#line 208 "rygel-gst-utils.c"
	gboolean result = FALSE;
	GstStructure* structure;
#line 61 "rygel-gst-utils.vala"
	g_return_val_if_fail (caps != NULL, FALSE);
#line 62 "rygel-gst-utils.vala"
	structure = _gst_structure_copy0 (gst_caps_get_structure (caps, (guint) 0));
#line 215 "rygel-gst-utils.c"
	result = _vala_strcmp0 (gst_structure_get_name (structure), "application/x-rtp") == 0;
	_gst_structure_free0 (structure);
#line 63 "rygel-gst-utils.vala"
	return result;
#line 220 "rygel-gst-utils.c"
}


static gpointer _gst_object_ref0 (gpointer self) {
	return self ? gst_object_ref (self) : NULL;
}


#line 103 "rygel-gst-utils.vala"
static gint _rygel_gst_utils_compare_factories_gcompare_func (void* a, void* b) {
#line 231 "rygel-gst-utils.c"
	gint result;
	result = rygel_gst_utils_compare_factories (a, b);
	return result;
}


#line 66 "rygel-gst-utils.vala"
static GstElement* rygel_gst_utils_get_best_depay (GList* features, GstCaps* caps) {
#line 240 "rygel-gst-utils.c"
	GstElement* result = NULL;
	GList* relevant_factories;
	GstElementFactory* factory;
#line 66 "rygel-gst-utils.vala"
	g_return_val_if_fail (caps != NULL, NULL);
#line 69 "rygel-gst-utils.vala"
	relevant_factories = NULL;
#line 248 "rygel-gst-utils.c"
	{
		GList* feature_collection;
		GList* feature_it;
#line 72 "rygel-gst-utils.vala"
		feature_collection = features;
#line 254 "rygel-gst-utils.c"
		for (feature_it = feature_collection; feature_it != NULL; feature_it = feature_it->next) {
			GstPluginFeature* feature;
#line 72 "rygel-gst-utils.vala"
			feature = _gst_object_ref0 ((GstPluginFeature*) feature_it->data);
#line 259 "rygel-gst-utils.c"
			{
				GstElementFactory* factory;
#line 73 "rygel-gst-utils.vala"
				factory = _gst_object_ref0 (GST_ELEMENT_FACTORY (feature));
#line 74 "rygel-gst-utils.vala"
				if (gst_element_factory_can_sink_caps (factory, caps)) {
#line 75 "rygel-gst-utils.vala"
					relevant_factories = g_list_append (relevant_factories, _gst_object_ref0 (factory));
#line 268 "rygel-gst-utils.c"
				}
				_gst_object_unref0 (feature);
				_gst_object_unref0 (factory);
			}
		}
	}
#line 79 "rygel-gst-utils.vala"
	if (g_list_length (relevant_factories) == 0) {
#line 277 "rygel-gst-utils.c"
		result = NULL;
		__g_list_free_gst_object_unref0 (relevant_factories);
#line 81 "rygel-gst-utils.vala"
		return result;
#line 282 "rygel-gst-utils.c"
	}
#line 85 "rygel-gst-utils.vala"
	relevant_factories = g_list_sort (relevant_factories, _rygel_gst_utils_compare_factories_gcompare_func);
#line 88 "rygel-gst-utils.vala"
	factory = _gst_object_ref0 ((GstElementFactory*) relevant_factories->data);
#line 288 "rygel-gst-utils.c"
	result = gst_element_factory_make (gst_plugin_feature_get_name ((GstPluginFeature*) factory), NULL);
	__g_list_free_gst_object_unref0 (relevant_factories);
	_gst_object_unref0 (factory);
#line 90 "rygel-gst-utils.vala"
	return result;
#line 294 "rygel-gst-utils.c"
}


#line 1144 "glib-2.0.vapi"
static gboolean string_contains (const char* self, const char* needle) {
#line 300 "rygel-gst-utils.c"
	gboolean result = FALSE;
#line 1144 "glib-2.0.vapi"
	g_return_val_if_fail (self != NULL, FALSE);
#line 1144 "glib-2.0.vapi"
	g_return_val_if_fail (needle != NULL, FALSE);
#line 306 "rygel-gst-utils.c"
	result = strstr (self, needle) != NULL;
#line 1145 "glib-2.0.vapi"
	return result;
#line 310 "rygel-gst-utils.c"
}


#line 93 "rygel-gst-utils.vala"
static gboolean rygel_gst_utils_rtp_depay_filter (GstPluginFeature* feature) {
#line 316 "rygel-gst-utils.c"
	gboolean result = FALSE;
	GstElementFactory* factory;
#line 93 "rygel-gst-utils.vala"
	g_return_val_if_fail (feature != NULL, FALSE);
#line 94 "rygel-gst-utils.vala"
	if (!g_type_is_a (G_TYPE_FROM_INSTANCE ((GObject*) feature), GST_TYPE_ELEMENT_FACTORY)) {
#line 323 "rygel-gst-utils.c"
		result = FALSE;
#line 95 "rygel-gst-utils.vala"
		return result;
#line 327 "rygel-gst-utils.c"
	}
#line 98 "rygel-gst-utils.vala"
	factory = _gst_object_ref0 (GST_ELEMENT_FACTORY (feature));
#line 331 "rygel-gst-utils.c"
	result = string_contains (gst_element_factory_get_klass (factory), "Depayloader");
	_gst_object_unref0 (factory);
#line 100 "rygel-gst-utils.vala"
	return result;
#line 336 "rygel-gst-utils.c"
}


#line 103 "rygel-gst-utils.vala"
static gint rygel_gst_utils_compare_factories (void* a, void* b) {
#line 342 "rygel-gst-utils.c"
	gint result = 0;
	GstElementFactory* factory_a;
	GstElementFactory* factory_b;
#line 104 "rygel-gst-utils.vala"
	factory_a = _gst_object_ref0 (GST_ELEMENT_FACTORY (a));
#line 105 "rygel-gst-utils.vala"
	factory_b = _gst_object_ref0 (GST_ELEMENT_FACTORY (b));
#line 350 "rygel-gst-utils.c"
	result = (gint) (gst_plugin_feature_get_rank ((GstPluginFeature*) factory_b) - gst_plugin_feature_get_rank ((GstPluginFeature*) factory_a));
	_gst_object_unref0 (factory_a);
	_gst_object_unref0 (factory_b);
#line 107 "rygel-gst-utils.vala"
	return result;
#line 356 "rygel-gst-utils.c"
}


#line 31 "rygel-gst-utils.vala"
RygelGstUtils* rygel_gst_utils_construct (GType object_type) {
#line 362 "rygel-gst-utils.c"
	RygelGstUtils* self;
	self = (RygelGstUtils*) g_type_create_instance (object_type);
	return self;
}


static void rygel_value_gst_utils_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void rygel_value_gst_utils_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		rygel_gst_utils_unref (value->data[0].v_pointer);
	}
}


static void rygel_value_gst_utils_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = rygel_gst_utils_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer rygel_value_gst_utils_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* rygel_value_gst_utils_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		RygelGstUtils* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = rygel_gst_utils_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* rygel_value_gst_utils_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	RygelGstUtils** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags && G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = rygel_gst_utils_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* rygel_param_spec_gst_utils (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	RygelParamSpecGstUtils* spec;
	g_return_val_if_fail (g_type_is_a (object_type, RYGEL_TYPE_GST_UTILS), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer rygel_value_get_gst_utils (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_TYPE_GST_UTILS), NULL);
	return value->data[0].v_pointer;
}


void rygel_value_set_gst_utils (GValue* value, gpointer v_object) {
	RygelGstUtils* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_TYPE_GST_UTILS));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, RYGEL_TYPE_GST_UTILS));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		rygel_gst_utils_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		rygel_gst_utils_unref (old);
	}
}


void rygel_value_take_gst_utils (GValue* value, gpointer v_object) {
	RygelGstUtils* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_TYPE_GST_UTILS));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, RYGEL_TYPE_GST_UTILS));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		rygel_gst_utils_unref (old);
	}
}


static void rygel_gst_utils_class_init (RygelGstUtilsClass * klass) {
	rygel_gst_utils_parent_class = g_type_class_peek_parent (klass);
	RYGEL_GST_UTILS_CLASS (klass)->finalize = rygel_gst_utils_finalize;
}


static void rygel_gst_utils_instance_init (RygelGstUtils * self) {
	self->ref_count = 1;
}


static void rygel_gst_utils_finalize (RygelGstUtils* obj) {
	RygelGstUtils * self;
	self = RYGEL_GST_UTILS (obj);
}


GType rygel_gst_utils_get_type (void) {
	static volatile gsize rygel_gst_utils_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_gst_utils_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { rygel_value_gst_utils_init, rygel_value_gst_utils_free_value, rygel_value_gst_utils_copy_value, rygel_value_gst_utils_peek_pointer, "p", rygel_value_gst_utils_collect_value, "p", rygel_value_gst_utils_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (RygelGstUtilsClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_gst_utils_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelGstUtils), 0, (GInstanceInitFunc) rygel_gst_utils_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType rygel_gst_utils_type_id;
		rygel_gst_utils_type_id = g_type_register_fundamental (g_type_fundamental_next (), "RygelGstUtils", &g_define_type_info, &g_define_type_fundamental_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&rygel_gst_utils_type_id__volatile, rygel_gst_utils_type_id);
	}
	return rygel_gst_utils_type_id__volatile;
}


gpointer rygel_gst_utils_ref (gpointer instance) {
	RygelGstUtils* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void rygel_gst_utils_unref (gpointer instance) {
	RygelGstUtils* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		RYGEL_GST_UTILS_GET_CLASS (self)->finalize (self);
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




