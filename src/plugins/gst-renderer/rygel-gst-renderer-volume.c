/* rygel-gst-renderer-volume.c generated by valac, the Vala compiler
 * generated from rygel-gst-renderer-volume.vala, do not modify */

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
/* Helper class for converting between double and percentage representations*/
/* of volume.*/

#include <glib.h>
#include <glib-object.h>
#include <float.h>
#include <math.h>
#include <gobject/gvaluecollector.h>


#define RYGEL_GST_RENDERER_TYPE_VOLUME (rygel_gst_renderer_volume_get_type ())
#define RYGEL_GST_RENDERER_VOLUME(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_GST_RENDERER_TYPE_VOLUME, RygelGstRendererVolume))
#define RYGEL_GST_RENDERER_VOLUME_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_GST_RENDERER_TYPE_VOLUME, RygelGstRendererVolumeClass))
#define RYGEL_GST_RENDERER_IS_VOLUME(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_GST_RENDERER_TYPE_VOLUME))
#define RYGEL_GST_RENDERER_IS_VOLUME_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_GST_RENDERER_TYPE_VOLUME))
#define RYGEL_GST_RENDERER_VOLUME_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_GST_RENDERER_TYPE_VOLUME, RygelGstRendererVolumeClass))

typedef struct _RygelGstRendererVolume RygelGstRendererVolume;
typedef struct _RygelGstRendererVolumeClass RygelGstRendererVolumeClass;
typedef struct _RygelGstRendererVolumePrivate RygelGstRendererVolumePrivate;
typedef struct _RygelGstRendererParamSpecVolume RygelGstRendererParamSpecVolume;

struct _RygelGstRendererVolume {
	GTypeInstance parent_instance;
	volatile int ref_count;
	RygelGstRendererVolumePrivate * priv;
};

struct _RygelGstRendererVolumeClass {
	GTypeClass parent_class;
	void (*finalize) (RygelGstRendererVolume *self);
};

struct _RygelGstRendererParamSpecVolume {
	GParamSpec parent_instance;
};


static gpointer rygel_gst_renderer_volume_parent_class = NULL;

gpointer rygel_gst_renderer_volume_ref (gpointer instance);
void rygel_gst_renderer_volume_unref (gpointer instance);
GParamSpec* rygel_gst_renderer_param_spec_volume (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_gst_renderer_value_set_volume (GValue* value, gpointer v_object);
void rygel_gst_renderer_value_take_volume (GValue* value, gpointer v_object);
gpointer rygel_gst_renderer_value_get_volume (const GValue* value);
GType rygel_gst_renderer_volume_get_type (void);
enum  {
	RYGEL_GST_RENDERER_VOLUME_DUMMY_PROPERTY
};
double rygel_gst_renderer_volume_from_percentage (guint percentage);
guint rygel_gst_renderer_volume_to_percentage (double volume);
RygelGstRendererVolume* rygel_gst_renderer_volume_new (void);
RygelGstRendererVolume* rygel_gst_renderer_volume_construct (GType object_type);
static void rygel_gst_renderer_volume_finalize (RygelGstRendererVolume* obj);



#line 27 "rygel-gst-renderer-volume.vala"
double rygel_gst_renderer_volume_from_percentage (guint percentage) {
#line 87 "rygel-gst-renderer-volume.c"
	double result = 0.0;
	result = ((double) percentage) / 100.0;
#line 28 "rygel-gst-renderer-volume.vala"
	return result;
#line 92 "rygel-gst-renderer-volume.c"
}


#line 31 "rygel-gst-renderer-volume.vala"
guint rygel_gst_renderer_volume_to_percentage (double volume) {
#line 98 "rygel-gst-renderer-volume.c"
	guint result = 0U;
	result = (guint) (volume * 100.0);
#line 32 "rygel-gst-renderer-volume.vala"
	return result;
#line 103 "rygel-gst-renderer-volume.c"
}


#line 26 "rygel-gst-renderer-volume.vala"
RygelGstRendererVolume* rygel_gst_renderer_volume_construct (GType object_type) {
#line 109 "rygel-gst-renderer-volume.c"
	RygelGstRendererVolume* self;
	self = (RygelGstRendererVolume*) g_type_create_instance (object_type);
	return self;
}


#line 26 "rygel-gst-renderer-volume.vala"
RygelGstRendererVolume* rygel_gst_renderer_volume_new (void) {
#line 26 "rygel-gst-renderer-volume.vala"
	return rygel_gst_renderer_volume_construct (RYGEL_GST_RENDERER_TYPE_VOLUME);
#line 120 "rygel-gst-renderer-volume.c"
}


static void rygel_gst_renderer_value_volume_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void rygel_gst_renderer_value_volume_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		rygel_gst_renderer_volume_unref (value->data[0].v_pointer);
	}
}


static void rygel_gst_renderer_value_volume_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = rygel_gst_renderer_volume_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer rygel_gst_renderer_value_volume_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* rygel_gst_renderer_value_volume_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		RygelGstRendererVolume* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = rygel_gst_renderer_volume_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* rygel_gst_renderer_value_volume_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	RygelGstRendererVolume** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags && G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = rygel_gst_renderer_volume_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* rygel_gst_renderer_param_spec_volume (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	RygelGstRendererParamSpecVolume* spec;
	g_return_val_if_fail (g_type_is_a (object_type, RYGEL_GST_RENDERER_TYPE_VOLUME), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer rygel_gst_renderer_value_get_volume (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_GST_RENDERER_TYPE_VOLUME), NULL);
	return value->data[0].v_pointer;
}


void rygel_gst_renderer_value_set_volume (GValue* value, gpointer v_object) {
	RygelGstRendererVolume* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_GST_RENDERER_TYPE_VOLUME));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, RYGEL_GST_RENDERER_TYPE_VOLUME));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		rygel_gst_renderer_volume_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		rygel_gst_renderer_volume_unref (old);
	}
}


void rygel_gst_renderer_value_take_volume (GValue* value, gpointer v_object) {
	RygelGstRendererVolume* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_GST_RENDERER_TYPE_VOLUME));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, RYGEL_GST_RENDERER_TYPE_VOLUME));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		rygel_gst_renderer_volume_unref (old);
	}
}


static void rygel_gst_renderer_volume_class_init (RygelGstRendererVolumeClass * klass) {
	rygel_gst_renderer_volume_parent_class = g_type_class_peek_parent (klass);
	RYGEL_GST_RENDERER_VOLUME_CLASS (klass)->finalize = rygel_gst_renderer_volume_finalize;
}


static void rygel_gst_renderer_volume_instance_init (RygelGstRendererVolume * self) {
	self->ref_count = 1;
}


static void rygel_gst_renderer_volume_finalize (RygelGstRendererVolume* obj) {
	RygelGstRendererVolume * self;
	self = RYGEL_GST_RENDERER_VOLUME (obj);
}


GType rygel_gst_renderer_volume_get_type (void) {
	static volatile gsize rygel_gst_renderer_volume_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_gst_renderer_volume_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { rygel_gst_renderer_value_volume_init, rygel_gst_renderer_value_volume_free_value, rygel_gst_renderer_value_volume_copy_value, rygel_gst_renderer_value_volume_peek_pointer, "p", rygel_gst_renderer_value_volume_collect_value, "p", rygel_gst_renderer_value_volume_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (RygelGstRendererVolumeClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_gst_renderer_volume_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelGstRendererVolume), 0, (GInstanceInitFunc) rygel_gst_renderer_volume_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType rygel_gst_renderer_volume_type_id;
		rygel_gst_renderer_volume_type_id = g_type_register_fundamental (g_type_fundamental_next (), "RygelGstRendererVolume", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&rygel_gst_renderer_volume_type_id__volatile, rygel_gst_renderer_volume_type_id);
	}
	return rygel_gst_renderer_volume_type_id__volatile;
}


gpointer rygel_gst_renderer_volume_ref (gpointer instance) {
	RygelGstRendererVolume* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void rygel_gst_renderer_volume_unref (gpointer instance) {
	RygelGstRendererVolume* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		RYGEL_GST_RENDERER_VOLUME_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}



