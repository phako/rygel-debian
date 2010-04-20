/* rygel-tracker-query-triplet.c generated by valac, the Vala compiler
 * generated from rygel-tracker-query-triplet.vala, do not modify */

/*
 * Copyright (C) 2008 Nokia Corporation.
 *
 * Author: Zeeshan Ali <zeenix@gmail.com>
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


#define RYGEL_TYPE_TRACKER_QUERY_TRIPLET (rygel_tracker_query_triplet_get_type ())
#define RYGEL_TRACKER_QUERY_TRIPLET(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_QUERY_TRIPLET, RygelTrackerQueryTriplet))
#define RYGEL_TRACKER_QUERY_TRIPLET_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_QUERY_TRIPLET, RygelTrackerQueryTripletClass))
#define RYGEL_IS_TRACKER_QUERY_TRIPLET(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_QUERY_TRIPLET))
#define RYGEL_IS_TRACKER_QUERY_TRIPLET_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_QUERY_TRIPLET))
#define RYGEL_TRACKER_QUERY_TRIPLET_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_QUERY_TRIPLET, RygelTrackerQueryTripletClass))

typedef struct _RygelTrackerQueryTriplet RygelTrackerQueryTriplet;
typedef struct _RygelTrackerQueryTripletClass RygelTrackerQueryTripletClass;
typedef struct _RygelTrackerQueryTripletPrivate RygelTrackerQueryTripletPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _rygel_tracker_query_triplet_unref0(var) ((var == NULL) ? NULL : (var = (rygel_tracker_query_triplet_unref (var), NULL)))
typedef struct _RygelParamSpecTrackerQueryTriplet RygelParamSpecTrackerQueryTriplet;

struct _RygelTrackerQueryTriplet {
	GTypeInstance parent_instance;
	volatile int ref_count;
	RygelTrackerQueryTripletPrivate * priv;
	char* subject;
	char* predicate;
	char* obj;
	gboolean optional;
	RygelTrackerQueryTriplet* next;
};

struct _RygelTrackerQueryTripletClass {
	GTypeClass parent_class;
	void (*finalize) (RygelTrackerQueryTriplet *self);
};

struct _RygelParamSpecTrackerQueryTriplet {
	GParamSpec parent_instance;
};


static gpointer rygel_tracker_query_triplet_parent_class = NULL;

gpointer rygel_tracker_query_triplet_ref (gpointer instance);
void rygel_tracker_query_triplet_unref (gpointer instance);
GParamSpec* rygel_param_spec_tracker_query_triplet (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_tracker_query_triplet (GValue* value, gpointer v_object);
void rygel_value_take_tracker_query_triplet (GValue* value, gpointer v_object);
gpointer rygel_value_get_tracker_query_triplet (const GValue* value);
GType rygel_tracker_query_triplet_get_type (void);
enum  {
	RYGEL_TRACKER_QUERY_TRIPLET_DUMMY_PROPERTY
};
RygelTrackerQueryTriplet* rygel_tracker_query_triplet_new (const char* subject, const char* predicate, const char* obj, gboolean optional);
RygelTrackerQueryTriplet* rygel_tracker_query_triplet_construct (GType object_type, const char* subject, const char* predicate, const char* obj, gboolean optional);
RygelTrackerQueryTriplet* rygel_tracker_query_triplet_new_chain (const char* subject, const char* predicate, RygelTrackerQueryTriplet* next, gboolean optional);
RygelTrackerQueryTriplet* rygel_tracker_query_triplet_construct_chain (GType object_type, const char* subject, const char* predicate, RygelTrackerQueryTriplet* next, gboolean optional);
RygelTrackerQueryTriplet* rygel_tracker_query_triplet_new_clone (RygelTrackerQueryTriplet* triplet);
RygelTrackerQueryTriplet* rygel_tracker_query_triplet_construct_clone (GType object_type, RygelTrackerQueryTriplet* triplet);
gboolean rygel_tracker_query_triplet_equal_func (RygelTrackerQueryTriplet* a, RygelTrackerQueryTriplet* b);
char* rygel_tracker_query_triplet_to_string (RygelTrackerQueryTriplet* self);
static void rygel_tracker_query_triplet_finalize (RygelTrackerQueryTriplet* obj);
static int _vala_strcmp0 (const char * str1, const char * str2);



#line 37 "rygel-tracker-query-triplet.vala"
RygelTrackerQueryTriplet* rygel_tracker_query_triplet_construct (GType object_type, const char* subject, const char* predicate, const char* obj, gboolean optional) {
#line 96 "rygel-tracker-query-triplet.c"
	RygelTrackerQueryTriplet* self;
	char* _tmp0_;
	char* _tmp1_;
	char* _tmp2_;
#line 37 "rygel-tracker-query-triplet.vala"
	g_return_val_if_fail (predicate != NULL, NULL);
#line 37 "rygel-tracker-query-triplet.vala"
	g_return_val_if_fail (obj != NULL, NULL);
#line 105 "rygel-tracker-query-triplet.c"
	self = (RygelTrackerQueryTriplet*) g_type_create_instance (object_type);
#line 41 "rygel-tracker-query-triplet.vala"
	self->subject = (_tmp0_ = g_strdup (subject), _g_free0 (self->subject), _tmp0_);
#line 42 "rygel-tracker-query-triplet.vala"
	self->predicate = (_tmp1_ = g_strdup (predicate), _g_free0 (self->predicate), _tmp1_);
#line 43 "rygel-tracker-query-triplet.vala"
	self->obj = (_tmp2_ = g_strdup (obj), _g_free0 (self->obj), _tmp2_);
#line 44 "rygel-tracker-query-triplet.vala"
	self->optional = optional;
#line 115 "rygel-tracker-query-triplet.c"
	return self;
}


#line 37 "rygel-tracker-query-triplet.vala"
RygelTrackerQueryTriplet* rygel_tracker_query_triplet_new (const char* subject, const char* predicate, const char* obj, gboolean optional) {
#line 37 "rygel-tracker-query-triplet.vala"
	return rygel_tracker_query_triplet_construct (RYGEL_TYPE_TRACKER_QUERY_TRIPLET, subject, predicate, obj, optional);
#line 124 "rygel-tracker-query-triplet.c"
}


static gpointer _rygel_tracker_query_triplet_ref0 (gpointer self) {
	return self ? rygel_tracker_query_triplet_ref (self) : NULL;
}


#line 47 "rygel-tracker-query-triplet.vala"
RygelTrackerQueryTriplet* rygel_tracker_query_triplet_construct_chain (GType object_type, const char* subject, const char* predicate, RygelTrackerQueryTriplet* next, gboolean optional) {
#line 135 "rygel-tracker-query-triplet.c"
	RygelTrackerQueryTriplet* self;
	char* _tmp0_;
	char* _tmp1_;
	RygelTrackerQueryTriplet* _tmp2_;
#line 47 "rygel-tracker-query-triplet.vala"
	g_return_val_if_fail (predicate != NULL, NULL);
#line 47 "rygel-tracker-query-triplet.vala"
	g_return_val_if_fail (next != NULL, NULL);
#line 144 "rygel-tracker-query-triplet.c"
	self = (RygelTrackerQueryTriplet*) g_type_create_instance (object_type);
#line 51 "rygel-tracker-query-triplet.vala"
	self->subject = (_tmp0_ = g_strdup (subject), _g_free0 (self->subject), _tmp0_);
#line 52 "rygel-tracker-query-triplet.vala"
	self->predicate = (_tmp1_ = g_strdup (predicate), _g_free0 (self->predicate), _tmp1_);
#line 53 "rygel-tracker-query-triplet.vala"
	self->next = (_tmp2_ = _rygel_tracker_query_triplet_ref0 (next), _rygel_tracker_query_triplet_unref0 (self->next), _tmp2_);
#line 54 "rygel-tracker-query-triplet.vala"
	self->optional = optional;
#line 154 "rygel-tracker-query-triplet.c"
	return self;
}


#line 47 "rygel-tracker-query-triplet.vala"
RygelTrackerQueryTriplet* rygel_tracker_query_triplet_new_chain (const char* subject, const char* predicate, RygelTrackerQueryTriplet* next, gboolean optional) {
#line 47 "rygel-tracker-query-triplet.vala"
	return rygel_tracker_query_triplet_construct_chain (RYGEL_TYPE_TRACKER_QUERY_TRIPLET, subject, predicate, next, optional);
#line 163 "rygel-tracker-query-triplet.c"
}


#line 57 "rygel-tracker-query-triplet.vala"
RygelTrackerQueryTriplet* rygel_tracker_query_triplet_construct_clone (GType object_type, RygelTrackerQueryTriplet* triplet) {
#line 169 "rygel-tracker-query-triplet.c"
	RygelTrackerQueryTriplet* self;
	char* _tmp0_;
	char* _tmp1_;
#line 57 "rygel-tracker-query-triplet.vala"
	g_return_val_if_fail (triplet != NULL, NULL);
#line 175 "rygel-tracker-query-triplet.c"
	self = (RygelTrackerQueryTriplet*) g_type_create_instance (object_type);
#line 58 "rygel-tracker-query-triplet.vala"
	self->subject = (_tmp0_ = g_strdup (triplet->subject), _g_free0 (self->subject), _tmp0_);
#line 59 "rygel-tracker-query-triplet.vala"
	self->predicate = (_tmp1_ = g_strdup (triplet->predicate), _g_free0 (self->predicate), _tmp1_);
#line 60 "rygel-tracker-query-triplet.vala"
	self->optional = triplet->optional;
#line 62 "rygel-tracker-query-triplet.vala"
	if (triplet->next != NULL) {
#line 185 "rygel-tracker-query-triplet.c"
		RygelTrackerQueryTriplet* _tmp2_;
#line 63 "rygel-tracker-query-triplet.vala"
		self->next = (_tmp2_ = _rygel_tracker_query_triplet_ref0 (triplet->next), _rygel_tracker_query_triplet_unref0 (self->next), _tmp2_);
#line 189 "rygel-tracker-query-triplet.c"
	} else {
		char* _tmp3_;
#line 65 "rygel-tracker-query-triplet.vala"
		self->obj = (_tmp3_ = g_strdup (triplet->obj), _g_free0 (self->obj), _tmp3_);
#line 194 "rygel-tracker-query-triplet.c"
	}
	return self;
}


#line 57 "rygel-tracker-query-triplet.vala"
RygelTrackerQueryTriplet* rygel_tracker_query_triplet_new_clone (RygelTrackerQueryTriplet* triplet) {
#line 57 "rygel-tracker-query-triplet.vala"
	return rygel_tracker_query_triplet_construct_clone (RYGEL_TYPE_TRACKER_QUERY_TRIPLET, triplet);
#line 204 "rygel-tracker-query-triplet.c"
}


#line 69 "rygel-tracker-query-triplet.vala"
gboolean rygel_tracker_query_triplet_equal_func (RygelTrackerQueryTriplet* a, RygelTrackerQueryTriplet* b) {
#line 210 "rygel-tracker-query-triplet.c"
	gboolean result = FALSE;
	gboolean chain_equal = FALSE;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_ = FALSE;
	gboolean _tmp3_ = FALSE;
	gboolean _tmp4_ = FALSE;
#line 69 "rygel-tracker-query-triplet.vala"
	g_return_val_if_fail (a != NULL, FALSE);
#line 69 "rygel-tracker-query-triplet.vala"
	g_return_val_if_fail (b != NULL, FALSE);
#line 73 "rygel-tracker-query-triplet.vala"
	if (a->next != NULL) {
#line 73 "rygel-tracker-query-triplet.vala"
		_tmp0_ = b->next != NULL;
#line 226 "rygel-tracker-query-triplet.c"
	} else {
#line 73 "rygel-tracker-query-triplet.vala"
		_tmp0_ = FALSE;
#line 230 "rygel-tracker-query-triplet.c"
	}
#line 73 "rygel-tracker-query-triplet.vala"
	if (_tmp0_) {
#line 74 "rygel-tracker-query-triplet.vala"
		chain_equal = rygel_tracker_query_triplet_equal_func (a->next, b->next);
#line 236 "rygel-tracker-query-triplet.c"
	} else {
#line 76 "rygel-tracker-query-triplet.vala"
		chain_equal = a->next == b->next;
#line 240 "rygel-tracker-query-triplet.c"
	}
#line 79 "rygel-tracker-query-triplet.vala"
	if (_vala_strcmp0 (a->subject, b->subject) == 0) {
#line 80 "rygel-tracker-query-triplet.vala"
		_tmp4_ = _vala_strcmp0 (a->obj, b->obj) == 0;
#line 246 "rygel-tracker-query-triplet.c"
	} else {
#line 79 "rygel-tracker-query-triplet.vala"
		_tmp4_ = FALSE;
#line 250 "rygel-tracker-query-triplet.c"
	}
#line 79 "rygel-tracker-query-triplet.vala"
	if (_tmp4_) {
#line 81 "rygel-tracker-query-triplet.vala"
		_tmp3_ = _vala_strcmp0 (a->predicate, b->predicate) == 0;
#line 256 "rygel-tracker-query-triplet.c"
	} else {
#line 79 "rygel-tracker-query-triplet.vala"
		_tmp3_ = FALSE;
#line 260 "rygel-tracker-query-triplet.c"
	}
#line 79 "rygel-tracker-query-triplet.vala"
	if (_tmp3_) {
#line 82 "rygel-tracker-query-triplet.vala"
		_tmp2_ = a->optional == b->optional;
#line 266 "rygel-tracker-query-triplet.c"
	} else {
#line 79 "rygel-tracker-query-triplet.vala"
		_tmp2_ = FALSE;
#line 270 "rygel-tracker-query-triplet.c"
	}
#line 79 "rygel-tracker-query-triplet.vala"
	if (_tmp2_) {
#line 83 "rygel-tracker-query-triplet.vala"
		_tmp1_ = chain_equal;
#line 276 "rygel-tracker-query-triplet.c"
	} else {
#line 79 "rygel-tracker-query-triplet.vala"
		_tmp1_ = FALSE;
#line 280 "rygel-tracker-query-triplet.c"
	}
	result = _tmp1_;
#line 79 "rygel-tracker-query-triplet.vala"
	return result;
#line 285 "rygel-tracker-query-triplet.c"
}


#line 86 "rygel-tracker-query-triplet.vala"
char* rygel_tracker_query_triplet_to_string (RygelTrackerQueryTriplet* self) {
#line 291 "rygel-tracker-query-triplet.c"
	char* result = NULL;
	char* str;
	char* _tmp4_;
	char* _tmp3_;
#line 86 "rygel-tracker-query-triplet.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 87 "rygel-tracker-query-triplet.vala"
	str = g_strdup ("");
#line 89 "rygel-tracker-query-triplet.vala"
	if (self->optional) {
#line 302 "rygel-tracker-query-triplet.c"
		char* _tmp0_;
#line 90 "rygel-tracker-query-triplet.vala"
		str = (_tmp0_ = g_strconcat (str, "OPTIONAL {", NULL), _g_free0 (str), _tmp0_);
#line 306 "rygel-tracker-query-triplet.c"
	}
#line 93 "rygel-tracker-query-triplet.vala"
	if (self->subject != NULL) {
#line 310 "rygel-tracker-query-triplet.c"
		char* _tmp2_;
		char* _tmp1_;
#line 94 "rygel-tracker-query-triplet.vala"
		str = (_tmp2_ = g_strconcat (str, _tmp1_ = g_strconcat (" ", self->subject, NULL), NULL), _g_free0 (str), _tmp2_);
#line 315 "rygel-tracker-query-triplet.c"
		_g_free0 (_tmp1_);
	}
#line 97 "rygel-tracker-query-triplet.vala"
	str = (_tmp4_ = g_strconcat (str, _tmp3_ = g_strconcat (" ", self->predicate, NULL), NULL), _g_free0 (str), _tmp4_);
#line 320 "rygel-tracker-query-triplet.c"
	_g_free0 (_tmp3_);
#line 99 "rygel-tracker-query-triplet.vala"
	if (self->next != NULL) {
#line 324 "rygel-tracker-query-triplet.c"
		char* _tmp8_;
		char* _tmp7_;
		char* _tmp6_;
		char* _tmp5_;
#line 100 "rygel-tracker-query-triplet.vala"
		str = (_tmp8_ = g_strconcat (str, _tmp7_ = g_strconcat (_tmp6_ = g_strconcat (" [ ", _tmp5_ = rygel_tracker_query_triplet_to_string (self->next), NULL), " ] ", NULL), NULL), _g_free0 (str), _tmp8_);
#line 331 "rygel-tracker-query-triplet.c"
		_g_free0 (_tmp7_);
		_g_free0 (_tmp6_);
		_g_free0 (_tmp5_);
	} else {
		char* _tmp10_;
		char* _tmp9_;
#line 102 "rygel-tracker-query-triplet.vala"
		str = (_tmp10_ = g_strconcat (str, _tmp9_ = g_strconcat (" ", self->obj, NULL), NULL), _g_free0 (str), _tmp10_);
#line 340 "rygel-tracker-query-triplet.c"
		_g_free0 (_tmp9_);
	}
#line 105 "rygel-tracker-query-triplet.vala"
	if (self->optional) {
#line 345 "rygel-tracker-query-triplet.c"
		char* _tmp11_;
#line 106 "rygel-tracker-query-triplet.vala"
		str = (_tmp11_ = g_strconcat (str, " }", NULL), _g_free0 (str), _tmp11_);
#line 349 "rygel-tracker-query-triplet.c"
	}
	result = str;
#line 109 "rygel-tracker-query-triplet.vala"
	return result;
#line 354 "rygel-tracker-query-triplet.c"
}


static void rygel_value_tracker_query_triplet_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void rygel_value_tracker_query_triplet_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		rygel_tracker_query_triplet_unref (value->data[0].v_pointer);
	}
}


static void rygel_value_tracker_query_triplet_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = rygel_tracker_query_triplet_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer rygel_value_tracker_query_triplet_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* rygel_value_tracker_query_triplet_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		RygelTrackerQueryTriplet* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = rygel_tracker_query_triplet_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* rygel_value_tracker_query_triplet_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	RygelTrackerQueryTriplet** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags && G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = rygel_tracker_query_triplet_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* rygel_param_spec_tracker_query_triplet (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	RygelParamSpecTrackerQueryTriplet* spec;
	g_return_val_if_fail (g_type_is_a (object_type, RYGEL_TYPE_TRACKER_QUERY_TRIPLET), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer rygel_value_get_tracker_query_triplet (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_TYPE_TRACKER_QUERY_TRIPLET), NULL);
	return value->data[0].v_pointer;
}


void rygel_value_set_tracker_query_triplet (GValue* value, gpointer v_object) {
	RygelTrackerQueryTriplet* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_TYPE_TRACKER_QUERY_TRIPLET));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, RYGEL_TYPE_TRACKER_QUERY_TRIPLET));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		rygel_tracker_query_triplet_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		rygel_tracker_query_triplet_unref (old);
	}
}


void rygel_value_take_tracker_query_triplet (GValue* value, gpointer v_object) {
	RygelTrackerQueryTriplet* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_TYPE_TRACKER_QUERY_TRIPLET));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, RYGEL_TYPE_TRACKER_QUERY_TRIPLET));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		rygel_tracker_query_triplet_unref (old);
	}
}


static void rygel_tracker_query_triplet_class_init (RygelTrackerQueryTripletClass * klass) {
	rygel_tracker_query_triplet_parent_class = g_type_class_peek_parent (klass);
	RYGEL_TRACKER_QUERY_TRIPLET_CLASS (klass)->finalize = rygel_tracker_query_triplet_finalize;
}


static void rygel_tracker_query_triplet_instance_init (RygelTrackerQueryTriplet * self) {
	self->ref_count = 1;
}


static void rygel_tracker_query_triplet_finalize (RygelTrackerQueryTriplet* obj) {
	RygelTrackerQueryTriplet * self;
	self = RYGEL_TRACKER_QUERY_TRIPLET (obj);
	_g_free0 (self->subject);
	_g_free0 (self->predicate);
	_g_free0 (self->obj);
	_rygel_tracker_query_triplet_unref0 (self->next);
}


GType rygel_tracker_query_triplet_get_type (void) {
	static volatile gsize rygel_tracker_query_triplet_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_tracker_query_triplet_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { rygel_value_tracker_query_triplet_init, rygel_value_tracker_query_triplet_free_value, rygel_value_tracker_query_triplet_copy_value, rygel_value_tracker_query_triplet_peek_pointer, "p", rygel_value_tracker_query_triplet_collect_value, "p", rygel_value_tracker_query_triplet_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (RygelTrackerQueryTripletClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_tracker_query_triplet_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelTrackerQueryTriplet), 0, (GInstanceInitFunc) rygel_tracker_query_triplet_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType rygel_tracker_query_triplet_type_id;
		rygel_tracker_query_triplet_type_id = g_type_register_fundamental (g_type_fundamental_next (), "RygelTrackerQueryTriplet", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&rygel_tracker_query_triplet_type_id__volatile, rygel_tracker_query_triplet_type_id);
	}
	return rygel_tracker_query_triplet_type_id__volatile;
}


gpointer rygel_tracker_query_triplet_ref (gpointer instance) {
	RygelTrackerQueryTriplet* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void rygel_tracker_query_triplet_unref (gpointer instance) {
	RygelTrackerQueryTriplet* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		RYGEL_TRACKER_QUERY_TRIPLET_GET_CLASS (self)->finalize (self);
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



