/* rygel-xml-utils.c generated by valac, the Vala compiler
 * generated from rygel-xml-utils.vala, do not modify */

/*
 * Copyright (C) 2008,2010 Nokia Corporation.
 * Copyright (C) 2008 Zeeshan Ali (Khattak) <zeeshanak@gnome.org>.
 *
 * Author: Zeeshan Ali (Khattak) <zeeshanak@gnome.org>
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
#include <libxml/tree.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <gobject/gvaluecollector.h>


#define RYGEL_TYPE_XML_UTILS (rygel_xml_utils_get_type ())
#define RYGEL_XML_UTILS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_XML_UTILS, RygelXMLUtils))
#define RYGEL_XML_UTILS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_XML_UTILS, RygelXMLUtilsClass))
#define RYGEL_IS_XML_UTILS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_XML_UTILS))
#define RYGEL_IS_XML_UTILS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_XML_UTILS))
#define RYGEL_XML_UTILS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_XML_UTILS, RygelXMLUtilsClass))

typedef struct _RygelXMLUtils RygelXMLUtils;
typedef struct _RygelXMLUtilsClass RygelXMLUtilsClass;
typedef struct _RygelXMLUtilsPrivate RygelXMLUtilsPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _RygelParamSpecXMLUtils RygelParamSpecXMLUtils;

struct _RygelXMLUtils {
	GTypeInstance parent_instance;
	volatile int ref_count;
	RygelXMLUtilsPrivate * priv;
};

struct _RygelXMLUtilsClass {
	GTypeClass parent_class;
	void (*finalize) (RygelXMLUtils *self);
};

struct _RygelParamSpecXMLUtils {
	GParamSpec parent_instance;
};


static gpointer rygel_xml_utils_parent_class = NULL;

gpointer rygel_xml_utils_ref (gpointer instance);
void rygel_xml_utils_unref (gpointer instance);
GParamSpec* rygel_param_spec_xml_utils (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_xml_utils (GValue* value, gpointer v_object);
void rygel_value_take_xml_utils (GValue* value, gpointer v_object);
gpointer rygel_value_get_xml_utils (const GValue* value);
GType rygel_xml_utils_get_type (void) G_GNUC_CONST;
enum  {
	RYGEL_XML_UTILS_DUMMY_PROPERTY
};
xmlNode* rygel_xml_utils_get_element (xmlNode* node, ...);
RygelXMLUtils* rygel_xml_utils_new (void);
RygelXMLUtils* rygel_xml_utils_construct (GType object_type);
static void rygel_xml_utils_finalize (RygelXMLUtils* obj);
static int _vala_strcmp0 (const char * str1, const char * str2);



#line 31 "rygel-xml-utils.vala"
xmlNode* rygel_xml_utils_get_element (xmlNode* node, ...) {
#line 88 "rygel-xml-utils.c"
	xmlNode* result = NULL;
	xmlNode* ret;
	va_list list;
#line 32 "rygel-xml-utils.vala"
	ret = node;
#line 94 "rygel-xml-utils.c"
	va_start (list, node);
#line 36 "rygel-xml-utils.vala"
	while (TRUE) {
#line 98 "rygel-xml-utils.c"
		char* arg;
#line 37 "rygel-xml-utils.vala"
		arg = g_strdup (va_arg (list, char*));
#line 38 "rygel-xml-utils.vala"
		if (arg == NULL) {
#line 104 "rygel-xml-utils.c"
			_g_free0 (arg);
#line 39 "rygel-xml-utils.vala"
			break;
#line 108 "rygel-xml-utils.c"
		}
		{
			gboolean _tmp0_;
#line 41 "rygel-xml-utils.vala"
			ret = ret->children;
#line 41 "rygel-xml-utils.vala"
			_tmp0_ = TRUE;
#line 41 "rygel-xml-utils.vala"
			while (TRUE) {
#line 41 "rygel-xml-utils.vala"
				if (!_tmp0_) {
#line 41 "rygel-xml-utils.vala"
					ret = ret->next;
#line 122 "rygel-xml-utils.c"
				}
#line 41 "rygel-xml-utils.vala"
				_tmp0_ = FALSE;
#line 41 "rygel-xml-utils.vala"
				if (!(ret != NULL)) {
#line 41 "rygel-xml-utils.vala"
					break;
#line 130 "rygel-xml-utils.c"
				}
#line 42 "rygel-xml-utils.vala"
				if (_vala_strcmp0 (arg, ret->name) == 0) {
#line 43 "rygel-xml-utils.vala"
					break;
#line 136 "rygel-xml-utils.c"
				}
			}
		}
#line 45 "rygel-xml-utils.vala"
		if (ret == NULL) {
#line 142 "rygel-xml-utils.c"
			_g_free0 (arg);
#line 46 "rygel-xml-utils.vala"
			break;
#line 146 "rygel-xml-utils.c"
		}
		_g_free0 (arg);
	}
	result = ret;
	va_end (list);
#line 49 "rygel-xml-utils.vala"
	return result;
#line 154 "rygel-xml-utils.c"
}


#line 29 "rygel-xml-utils.vala"
RygelXMLUtils* rygel_xml_utils_construct (GType object_type) {
#line 160 "rygel-xml-utils.c"
	RygelXMLUtils* self;
	self = (RygelXMLUtils*) g_type_create_instance (object_type);
	return self;
}


#line 29 "rygel-xml-utils.vala"
RygelXMLUtils* rygel_xml_utils_new (void) {
#line 29 "rygel-xml-utils.vala"
	return rygel_xml_utils_construct (RYGEL_TYPE_XML_UTILS);
#line 171 "rygel-xml-utils.c"
}


static void rygel_value_xml_utils_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void rygel_value_xml_utils_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		rygel_xml_utils_unref (value->data[0].v_pointer);
	}
}


static void rygel_value_xml_utils_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = rygel_xml_utils_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer rygel_value_xml_utils_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* rygel_value_xml_utils_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		RygelXMLUtils* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = rygel_xml_utils_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* rygel_value_xml_utils_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	RygelXMLUtils** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags && G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = rygel_xml_utils_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* rygel_param_spec_xml_utils (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	RygelParamSpecXMLUtils* spec;
	g_return_val_if_fail (g_type_is_a (object_type, RYGEL_TYPE_XML_UTILS), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer rygel_value_get_xml_utils (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_TYPE_XML_UTILS), NULL);
	return value->data[0].v_pointer;
}


void rygel_value_set_xml_utils (GValue* value, gpointer v_object) {
	RygelXMLUtils* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_TYPE_XML_UTILS));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, RYGEL_TYPE_XML_UTILS));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		rygel_xml_utils_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		rygel_xml_utils_unref (old);
	}
}


void rygel_value_take_xml_utils (GValue* value, gpointer v_object) {
	RygelXMLUtils* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_TYPE_XML_UTILS));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, RYGEL_TYPE_XML_UTILS));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		rygel_xml_utils_unref (old);
	}
}


static void rygel_xml_utils_class_init (RygelXMLUtilsClass * klass) {
	rygel_xml_utils_parent_class = g_type_class_peek_parent (klass);
	RYGEL_XML_UTILS_CLASS (klass)->finalize = rygel_xml_utils_finalize;
}


static void rygel_xml_utils_instance_init (RygelXMLUtils * self) {
	self->ref_count = 1;
}


static void rygel_xml_utils_finalize (RygelXMLUtils* obj) {
	RygelXMLUtils * self;
	self = RYGEL_XML_UTILS (obj);
}


GType rygel_xml_utils_get_type (void) {
	static volatile gsize rygel_xml_utils_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_xml_utils_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { rygel_value_xml_utils_init, rygel_value_xml_utils_free_value, rygel_value_xml_utils_copy_value, rygel_value_xml_utils_peek_pointer, "p", rygel_value_xml_utils_collect_value, "p", rygel_value_xml_utils_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (RygelXMLUtilsClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_xml_utils_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelXMLUtils), 0, (GInstanceInitFunc) rygel_xml_utils_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType rygel_xml_utils_type_id;
		rygel_xml_utils_type_id = g_type_register_fundamental (g_type_fundamental_next (), "RygelXMLUtils", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&rygel_xml_utils_type_id__volatile, rygel_xml_utils_type_id);
	}
	return rygel_xml_utils_type_id__volatile;
}


gpointer rygel_xml_utils_ref (gpointer instance) {
	RygelXMLUtils* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void rygel_xml_utils_unref (gpointer instance) {
	RygelXMLUtils* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		RYGEL_XML_UTILS_GET_CLASS (self)->finalize (self);
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




