/* rygel-resource-info.c generated by valac, the Vala compiler
 * generated from rygel-resource-info.vala, do not modify */

/*
 * Copyright (C) 2008 Nokia Corporation.
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
#include <gobject/gvaluecollector.h>


#define RYGEL_TYPE_RESOURCE_INFO (rygel_resource_info_get_type ())
#define RYGEL_RESOURCE_INFO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_RESOURCE_INFO, RygelResourceInfo))
#define RYGEL_RESOURCE_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_RESOURCE_INFO, RygelResourceInfoClass))
#define RYGEL_IS_RESOURCE_INFO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_RESOURCE_INFO))
#define RYGEL_IS_RESOURCE_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_RESOURCE_INFO))
#define RYGEL_RESOURCE_INFO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_RESOURCE_INFO, RygelResourceInfoClass))

typedef struct _RygelResourceInfo RygelResourceInfo;
typedef struct _RygelResourceInfoClass RygelResourceInfoClass;
typedef struct _RygelResourceInfoPrivate RygelResourceInfoPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _RygelParamSpecResourceInfo RygelParamSpecResourceInfo;

struct _RygelResourceInfo {
	GTypeInstance parent_instance;
	volatile int ref_count;
	RygelResourceInfoPrivate * priv;
	char* upnp_type;
	char* upnp_id;
	char* description_path;
	GType type;
};

struct _RygelResourceInfoClass {
	GTypeClass parent_class;
	void (*finalize) (RygelResourceInfo *self);
};

struct _RygelParamSpecResourceInfo {
	GParamSpec parent_instance;
};


static gpointer rygel_resource_info_parent_class = NULL;

gpointer rygel_resource_info_ref (gpointer instance);
void rygel_resource_info_unref (gpointer instance);
GParamSpec* rygel_param_spec_resource_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_resource_info (GValue* value, gpointer v_object);
void rygel_value_take_resource_info (GValue* value, gpointer v_object);
gpointer rygel_value_get_resource_info (const GValue* value);
GType rygel_resource_info_get_type (void) G_GNUC_CONST;
enum  {
	RYGEL_RESOURCE_INFO_DUMMY_PROPERTY
};
RygelResourceInfo* rygel_resource_info_new (const char* upnp_id, const char* upnp_type, const char* description_path, GType type);
RygelResourceInfo* rygel_resource_info_construct (GType object_type, const char* upnp_id, const char* upnp_type, const char* description_path, GType type);
static void rygel_resource_info_finalize (RygelResourceInfo* obj);



#line 39 "rygel-resource-info.vala"
RygelResourceInfo* rygel_resource_info_construct (GType object_type, const char* upnp_id, const char* upnp_type, const char* description_path, GType type) {
#line 88 "rygel-resource-info.c"
	RygelResourceInfo* self;
	char* _tmp0_;
	char* _tmp1_;
	char* _tmp2_;
#line 39 "rygel-resource-info.vala"
	g_return_val_if_fail (upnp_id != NULL, NULL);
#line 39 "rygel-resource-info.vala"
	g_return_val_if_fail (upnp_type != NULL, NULL);
#line 39 "rygel-resource-info.vala"
	g_return_val_if_fail (description_path != NULL, NULL);
#line 99 "rygel-resource-info.c"
	self = (RygelResourceInfo*) g_type_create_instance (object_type);
#line 43 "rygel-resource-info.vala"
	self->upnp_type = (_tmp0_ = g_strdup (upnp_type), _g_free0 (self->upnp_type), _tmp0_);
#line 44 "rygel-resource-info.vala"
	self->upnp_id = (_tmp1_ = g_strdup (upnp_id), _g_free0 (self->upnp_id), _tmp1_);
#line 45 "rygel-resource-info.vala"
	self->description_path = (_tmp2_ = g_strdup (description_path), _g_free0 (self->description_path), _tmp2_);
#line 46 "rygel-resource-info.vala"
	self->type = type;
#line 109 "rygel-resource-info.c"
	return self;
}


#line 39 "rygel-resource-info.vala"
RygelResourceInfo* rygel_resource_info_new (const char* upnp_id, const char* upnp_type, const char* description_path, GType type) {
#line 39 "rygel-resource-info.vala"
	return rygel_resource_info_construct (RYGEL_TYPE_RESOURCE_INFO, upnp_id, upnp_type, description_path, type);
#line 118 "rygel-resource-info.c"
}


static void rygel_value_resource_info_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void rygel_value_resource_info_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		rygel_resource_info_unref (value->data[0].v_pointer);
	}
}


static void rygel_value_resource_info_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = rygel_resource_info_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer rygel_value_resource_info_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* rygel_value_resource_info_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		RygelResourceInfo* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = rygel_resource_info_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* rygel_value_resource_info_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	RygelResourceInfo** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags && G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = rygel_resource_info_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* rygel_param_spec_resource_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	RygelParamSpecResourceInfo* spec;
	g_return_val_if_fail (g_type_is_a (object_type, RYGEL_TYPE_RESOURCE_INFO), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer rygel_value_get_resource_info (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_TYPE_RESOURCE_INFO), NULL);
	return value->data[0].v_pointer;
}


void rygel_value_set_resource_info (GValue* value, gpointer v_object) {
	RygelResourceInfo* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_TYPE_RESOURCE_INFO));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, RYGEL_TYPE_RESOURCE_INFO));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		rygel_resource_info_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		rygel_resource_info_unref (old);
	}
}


void rygel_value_take_resource_info (GValue* value, gpointer v_object) {
	RygelResourceInfo* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_TYPE_RESOURCE_INFO));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, RYGEL_TYPE_RESOURCE_INFO));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		rygel_resource_info_unref (old);
	}
}


static void rygel_resource_info_class_init (RygelResourceInfoClass * klass) {
	rygel_resource_info_parent_class = g_type_class_peek_parent (klass);
	RYGEL_RESOURCE_INFO_CLASS (klass)->finalize = rygel_resource_info_finalize;
}


static void rygel_resource_info_instance_init (RygelResourceInfo * self) {
	self->ref_count = 1;
}


static void rygel_resource_info_finalize (RygelResourceInfo* obj) {
	RygelResourceInfo * self;
	self = RYGEL_RESOURCE_INFO (obj);
	_g_free0 (self->upnp_type);
	_g_free0 (self->upnp_id);
	_g_free0 (self->description_path);
}


GType rygel_resource_info_get_type (void) {
	static volatile gsize rygel_resource_info_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_resource_info_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { rygel_value_resource_info_init, rygel_value_resource_info_free_value, rygel_value_resource_info_copy_value, rygel_value_resource_info_peek_pointer, "p", rygel_value_resource_info_collect_value, "p", rygel_value_resource_info_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (RygelResourceInfoClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_resource_info_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelResourceInfo), 0, (GInstanceInitFunc) rygel_resource_info_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType rygel_resource_info_type_id;
		rygel_resource_info_type_id = g_type_register_fundamental (g_type_fundamental_next (), "RygelResourceInfo", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&rygel_resource_info_type_id__volatile, rygel_resource_info_type_id);
	}
	return rygel_resource_info_type_id__volatile;
}


gpointer rygel_resource_info_ref (gpointer instance) {
	RygelResourceInfo* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void rygel_resource_info_unref (gpointer instance) {
	RygelResourceInfo* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		RYGEL_RESOURCE_INFO_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}




