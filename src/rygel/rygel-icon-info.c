/*
 * Copyright (C) 2008 Nokia Corporation, all rights reserved.
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


#define RYGEL_TYPE_ICON_INFO (rygel_icon_info_get_type ())
#define RYGEL_ICON_INFO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_ICON_INFO, RygelIconInfo))
#define RYGEL_ICON_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_ICON_INFO, RygelIconInfoClass))
#define RYGEL_IS_ICON_INFO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_ICON_INFO))
#define RYGEL_IS_ICON_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_ICON_INFO))
#define RYGEL_ICON_INFO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_ICON_INFO, RygelIconInfoClass))

typedef struct _RygelIconInfo RygelIconInfo;
typedef struct _RygelIconInfoClass RygelIconInfoClass;
typedef struct _RygelIconInfoPrivate RygelIconInfoPrivate;
typedef struct _RygelParamSpecIconInfo RygelParamSpecIconInfo;

/**
 * Holds information about an icon.
 */
struct _RygelIconInfo {
	GTypeInstance parent_instance;
	volatile int ref_count;
	RygelIconInfoPrivate * priv;
	char* mimetype;
	guint width;
	guint height;
	guint depth;
	char* path;
};

struct _RygelIconInfoClass {
	GTypeClass parent_class;
	void (*finalize) (RygelIconInfo *self);
};

struct _RygelParamSpecIconInfo {
	GParamSpec parent_instance;
};



gpointer rygel_icon_info_ref (gpointer instance);
void rygel_icon_info_unref (gpointer instance);
GParamSpec* rygel_param_spec_icon_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_icon_info (GValue* value, gpointer v_object);
gpointer rygel_value_get_icon_info (const GValue* value);
GType rygel_icon_info_get_type (void);
enum  {
	RYGEL_ICON_INFO_DUMMY_PROPERTY
};
RygelIconInfo* rygel_icon_info_new (const char* mimetype, guint width, guint height, guint depth, const char* path);
RygelIconInfo* rygel_icon_info_construct (GType object_type, const char* mimetype, guint width, guint height, guint depth, const char* path);
RygelIconInfo* rygel_icon_info_new (const char* mimetype, guint width, guint height, guint depth, const char* path);
static gpointer rygel_icon_info_parent_class = NULL;
static void rygel_icon_info_finalize (RygelIconInfo* obj);



RygelIconInfo* rygel_icon_info_construct (GType object_type, const char* mimetype, guint width, guint height, guint depth, const char* path) {
	RygelIconInfo* self;
	char* _tmp1_;
	const char* _tmp0_;
	char* _tmp3_;
	const char* _tmp2_;
	g_return_val_if_fail (mimetype != NULL, NULL);
	g_return_val_if_fail (path != NULL, NULL);
	self = (RygelIconInfo*) g_type_create_instance (object_type);
	_tmp1_ = NULL;
	_tmp0_ = NULL;
	self->mimetype = (_tmp1_ = (_tmp0_ = mimetype, (_tmp0_ == NULL) ? NULL : g_strdup (_tmp0_)), self->mimetype = (g_free (self->mimetype), NULL), _tmp1_);
	self->width = width;
	self->height = height;
	self->depth = depth;
	_tmp3_ = NULL;
	_tmp2_ = NULL;
	self->path = (_tmp3_ = (_tmp2_ = path, (_tmp2_ == NULL) ? NULL : g_strdup (_tmp2_)), self->path = (g_free (self->path), NULL), _tmp3_);
	return self;
}


RygelIconInfo* rygel_icon_info_new (const char* mimetype, guint width, guint height, guint depth, const char* path) {
	return rygel_icon_info_construct (RYGEL_TYPE_ICON_INFO, mimetype, width, height, depth, path);
}


static void rygel_value_icon_info_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void rygel_value_icon_info_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		rygel_icon_info_unref (value->data[0].v_pointer);
	}
}


static void rygel_value_icon_info_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = rygel_icon_info_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer rygel_value_icon_info_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* rygel_value_icon_info_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		RygelIconInfo* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = rygel_icon_info_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* rygel_value_icon_info_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	RygelIconInfo** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags && G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = rygel_icon_info_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* rygel_param_spec_icon_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	RygelParamSpecIconInfo* spec;
	g_return_val_if_fail (g_type_is_a (object_type, RYGEL_TYPE_ICON_INFO), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer rygel_value_get_icon_info (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_TYPE_ICON_INFO), NULL);
	return value->data[0].v_pointer;
}


void rygel_value_set_icon_info (GValue* value, gpointer v_object) {
	RygelIconInfo* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_TYPE_ICON_INFO));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, RYGEL_TYPE_ICON_INFO));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		rygel_icon_info_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		rygel_icon_info_unref (old);
	}
}


static void rygel_icon_info_class_init (RygelIconInfoClass * klass) {
	rygel_icon_info_parent_class = g_type_class_peek_parent (klass);
	RYGEL_ICON_INFO_CLASS (klass)->finalize = rygel_icon_info_finalize;
}


static void rygel_icon_info_instance_init (RygelIconInfo * self) {
	self->ref_count = 1;
}


static void rygel_icon_info_finalize (RygelIconInfo* obj) {
	RygelIconInfo * self;
	self = RYGEL_ICON_INFO (obj);
	self->mimetype = (g_free (self->mimetype), NULL);
	self->path = (g_free (self->path), NULL);
}


GType rygel_icon_info_get_type (void) {
	static GType rygel_icon_info_type_id = 0;
	if (rygel_icon_info_type_id == 0) {
		static const GTypeValueTable g_define_type_value_table = { rygel_value_icon_info_init, rygel_value_icon_info_free_value, rygel_value_icon_info_copy_value, rygel_value_icon_info_peek_pointer, "p", rygel_value_icon_info_collect_value, "p", rygel_value_icon_info_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (RygelIconInfoClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_icon_info_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelIconInfo), 0, (GInstanceInitFunc) rygel_icon_info_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		rygel_icon_info_type_id = g_type_register_fundamental (g_type_fundamental_next (), "RygelIconInfo", &g_define_type_info, &g_define_type_fundamental_info, 0);
	}
	return rygel_icon_info_type_id;
}


gpointer rygel_icon_info_ref (gpointer instance) {
	RygelIconInfo* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void rygel_icon_info_unref (gpointer instance) {
	RygelIconInfo* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		RYGEL_ICON_INFO_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}




