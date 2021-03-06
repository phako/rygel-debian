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


#define RYGEL_TRACKER_TYPE_QUERY_TRIPLET (rygel_tracker_query_triplet_get_type ())
#define RYGEL_TRACKER_QUERY_TRIPLET(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TRACKER_TYPE_QUERY_TRIPLET, RygelTrackerQueryTriplet))
#define RYGEL_TRACKER_QUERY_TRIPLET_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TRACKER_TYPE_QUERY_TRIPLET, RygelTrackerQueryTripletClass))
#define RYGEL_TRACKER_IS_QUERY_TRIPLET(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TRACKER_TYPE_QUERY_TRIPLET))
#define RYGEL_TRACKER_IS_QUERY_TRIPLET_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TRACKER_TYPE_QUERY_TRIPLET))
#define RYGEL_TRACKER_QUERY_TRIPLET_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TRACKER_TYPE_QUERY_TRIPLET, RygelTrackerQueryTripletClass))

typedef struct _RygelTrackerQueryTriplet RygelTrackerQueryTriplet;
typedef struct _RygelTrackerQueryTripletClass RygelTrackerQueryTripletClass;
typedef struct _RygelTrackerQueryTripletPrivate RygelTrackerQueryTripletPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _rygel_tracker_query_triplet_unref0(var) ((var == NULL) ? NULL : (var = (rygel_tracker_query_triplet_unref (var), NULL)))
typedef struct _RygelTrackerParamSpecQueryTriplet RygelTrackerParamSpecQueryTriplet;

struct _RygelTrackerQueryTriplet {
	GTypeInstance parent_instance;
	volatile int ref_count;
	RygelTrackerQueryTripletPrivate * priv;
	char* subject;
	char* predicate;
	char* obj;
	RygelTrackerQueryTriplet* next;
};

struct _RygelTrackerQueryTripletClass {
	GTypeClass parent_class;
	void (*finalize) (RygelTrackerQueryTriplet *self);
};

struct _RygelTrackerParamSpecQueryTriplet {
	GParamSpec parent_instance;
};


static gpointer rygel_tracker_query_triplet_parent_class = NULL;

gpointer rygel_tracker_query_triplet_ref (gpointer instance);
void rygel_tracker_query_triplet_unref (gpointer instance);
GParamSpec* rygel_tracker_param_spec_query_triplet (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_tracker_value_set_query_triplet (GValue* value, gpointer v_object);
void rygel_tracker_value_take_query_triplet (GValue* value, gpointer v_object);
gpointer rygel_tracker_value_get_query_triplet (const GValue* value);
GType rygel_tracker_query_triplet_get_type (void) G_GNUC_CONST;
enum  {
	RYGEL_TRACKER_QUERY_TRIPLET_DUMMY_PROPERTY
};
RygelTrackerQueryTriplet* rygel_tracker_query_triplet_new (const char* subject, const char* predicate, const char* obj);
RygelTrackerQueryTriplet* rygel_tracker_query_triplet_construct (GType object_type, const char* subject, const char* predicate, const char* obj);
RygelTrackerQueryTriplet* rygel_tracker_query_triplet_new_chain (const char* subject, const char* predicate, RygelTrackerQueryTriplet* next);
RygelTrackerQueryTriplet* rygel_tracker_query_triplet_construct_chain (GType object_type, const char* subject, const char* predicate, RygelTrackerQueryTriplet* next);
RygelTrackerQueryTriplet* rygel_tracker_query_triplet_new_clone (RygelTrackerQueryTriplet* triplet);
RygelTrackerQueryTriplet* rygel_tracker_query_triplet_construct_clone (GType object_type, RygelTrackerQueryTriplet* triplet);
gboolean rygel_tracker_query_triplet_equal_func (RygelTrackerQueryTriplet* a, RygelTrackerQueryTriplet* b);
char* rygel_tracker_query_triplet_to_string (RygelTrackerQueryTriplet* self, gboolean include_subject);
static void rygel_tracker_query_triplet_finalize (RygelTrackerQueryTriplet* obj);
static int _vala_strcmp0 (const char * str1, const char * str2);



#line 35 "rygel-tracker-query-triplet.vala"
RygelTrackerQueryTriplet* rygel_tracker_query_triplet_construct (GType object_type, const char* subject, const char* predicate, const char* obj) {
#line 95 "rygel-tracker-query-triplet.c"
	RygelTrackerQueryTriplet* self;
	char* _tmp0_;
	char* _tmp1_;
	char* _tmp2_;
#line 35 "rygel-tracker-query-triplet.vala"
	g_return_val_if_fail (subject != NULL, NULL);
#line 35 "rygel-tracker-query-triplet.vala"
	g_return_val_if_fail (predicate != NULL, NULL);
#line 35 "rygel-tracker-query-triplet.vala"
	g_return_val_if_fail (obj != NULL, NULL);
#line 106 "rygel-tracker-query-triplet.c"
	self = (RygelTrackerQueryTriplet*) g_type_create_instance (object_type);
#line 36 "rygel-tracker-query-triplet.vala"
	self->subject = (_tmp0_ = g_strdup (subject), _g_free0 (self->subject), _tmp0_);
#line 37 "rygel-tracker-query-triplet.vala"
	self->predicate = (_tmp1_ = g_strdup (predicate), _g_free0 (self->predicate), _tmp1_);
#line 38 "rygel-tracker-query-triplet.vala"
	self->obj = (_tmp2_ = g_strdup (obj), _g_free0 (self->obj), _tmp2_);
#line 114 "rygel-tracker-query-triplet.c"
	return self;
}


#line 35 "rygel-tracker-query-triplet.vala"
RygelTrackerQueryTriplet* rygel_tracker_query_triplet_new (const char* subject, const char* predicate, const char* obj) {
#line 35 "rygel-tracker-query-triplet.vala"
	return rygel_tracker_query_triplet_construct (RYGEL_TRACKER_TYPE_QUERY_TRIPLET, subject, predicate, obj);
#line 123 "rygel-tracker-query-triplet.c"
}


static gpointer _rygel_tracker_query_triplet_ref0 (gpointer self) {
	return self ? rygel_tracker_query_triplet_ref (self) : NULL;
}


#line 41 "rygel-tracker-query-triplet.vala"
RygelTrackerQueryTriplet* rygel_tracker_query_triplet_construct_chain (GType object_type, const char* subject, const char* predicate, RygelTrackerQueryTriplet* next) {
#line 134 "rygel-tracker-query-triplet.c"
	RygelTrackerQueryTriplet* self;
	char* _tmp0_;
	char* _tmp1_;
	RygelTrackerQueryTriplet* _tmp2_;
#line 41 "rygel-tracker-query-triplet.vala"
	g_return_val_if_fail (subject != NULL, NULL);
#line 41 "rygel-tracker-query-triplet.vala"
	g_return_val_if_fail (predicate != NULL, NULL);
#line 41 "rygel-tracker-query-triplet.vala"
	g_return_val_if_fail (next != NULL, NULL);
#line 145 "rygel-tracker-query-triplet.c"
	self = (RygelTrackerQueryTriplet*) g_type_create_instance (object_type);
#line 44 "rygel-tracker-query-triplet.vala"
	self->subject = (_tmp0_ = g_strdup (subject), _g_free0 (self->subject), _tmp0_);
#line 45 "rygel-tracker-query-triplet.vala"
	self->predicate = (_tmp1_ = g_strdup (predicate), _g_free0 (self->predicate), _tmp1_);
#line 46 "rygel-tracker-query-triplet.vala"
	self->next = (_tmp2_ = _rygel_tracker_query_triplet_ref0 (next), _rygel_tracker_query_triplet_unref0 (self->next), _tmp2_);
#line 153 "rygel-tracker-query-triplet.c"
	return self;
}


#line 41 "rygel-tracker-query-triplet.vala"
RygelTrackerQueryTriplet* rygel_tracker_query_triplet_new_chain (const char* subject, const char* predicate, RygelTrackerQueryTriplet* next) {
#line 41 "rygel-tracker-query-triplet.vala"
	return rygel_tracker_query_triplet_construct_chain (RYGEL_TRACKER_TYPE_QUERY_TRIPLET, subject, predicate, next);
#line 162 "rygel-tracker-query-triplet.c"
}


#line 49 "rygel-tracker-query-triplet.vala"
RygelTrackerQueryTriplet* rygel_tracker_query_triplet_construct_clone (GType object_type, RygelTrackerQueryTriplet* triplet) {
#line 168 "rygel-tracker-query-triplet.c"
	RygelTrackerQueryTriplet* self;
	char* _tmp0_;
	char* _tmp1_;
#line 49 "rygel-tracker-query-triplet.vala"
	g_return_val_if_fail (triplet != NULL, NULL);
#line 174 "rygel-tracker-query-triplet.c"
	self = (RygelTrackerQueryTriplet*) g_type_create_instance (object_type);
#line 50 "rygel-tracker-query-triplet.vala"
	self->subject = (_tmp0_ = g_strdup (triplet->subject), _g_free0 (self->subject), _tmp0_);
#line 51 "rygel-tracker-query-triplet.vala"
	self->predicate = (_tmp1_ = g_strdup (triplet->predicate), _g_free0 (self->predicate), _tmp1_);
#line 53 "rygel-tracker-query-triplet.vala"
	if (triplet->next != NULL) {
#line 182 "rygel-tracker-query-triplet.c"
		RygelTrackerQueryTriplet* _tmp2_;
#line 54 "rygel-tracker-query-triplet.vala"
		self->next = (_tmp2_ = _rygel_tracker_query_triplet_ref0 (triplet->next), _rygel_tracker_query_triplet_unref0 (self->next), _tmp2_);
#line 186 "rygel-tracker-query-triplet.c"
	} else {
		char* _tmp3_;
#line 56 "rygel-tracker-query-triplet.vala"
		self->obj = (_tmp3_ = g_strdup (triplet->obj), _g_free0 (self->obj), _tmp3_);
#line 191 "rygel-tracker-query-triplet.c"
	}
	return self;
}


#line 49 "rygel-tracker-query-triplet.vala"
RygelTrackerQueryTriplet* rygel_tracker_query_triplet_new_clone (RygelTrackerQueryTriplet* triplet) {
#line 49 "rygel-tracker-query-triplet.vala"
	return rygel_tracker_query_triplet_construct_clone (RYGEL_TRACKER_TYPE_QUERY_TRIPLET, triplet);
#line 201 "rygel-tracker-query-triplet.c"
}


#line 60 "rygel-tracker-query-triplet.vala"
gboolean rygel_tracker_query_triplet_equal_func (RygelTrackerQueryTriplet* a, RygelTrackerQueryTriplet* b) {
#line 207 "rygel-tracker-query-triplet.c"
	gboolean result = FALSE;
	gboolean chain_equal = FALSE;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_ = FALSE;
	gboolean _tmp3_ = FALSE;
#line 60 "rygel-tracker-query-triplet.vala"
	g_return_val_if_fail (a != NULL, FALSE);
#line 60 "rygel-tracker-query-triplet.vala"
	g_return_val_if_fail (b != NULL, FALSE);
#line 63 "rygel-tracker-query-triplet.vala"
	if (a->next != NULL) {
#line 63 "rygel-tracker-query-triplet.vala"
		_tmp0_ = b->next != NULL;
#line 222 "rygel-tracker-query-triplet.c"
	} else {
#line 63 "rygel-tracker-query-triplet.vala"
		_tmp0_ = FALSE;
#line 226 "rygel-tracker-query-triplet.c"
	}
#line 63 "rygel-tracker-query-triplet.vala"
	if (_tmp0_) {
#line 64 "rygel-tracker-query-triplet.vala"
		chain_equal = rygel_tracker_query_triplet_equal_func (a->next, b->next);
#line 232 "rygel-tracker-query-triplet.c"
	} else {
#line 66 "rygel-tracker-query-triplet.vala"
		chain_equal = a->next == b->next;
#line 236 "rygel-tracker-query-triplet.c"
	}
#line 69 "rygel-tracker-query-triplet.vala"
	if (_vala_strcmp0 (a->subject, b->subject) == 0) {
#line 70 "rygel-tracker-query-triplet.vala"
		_tmp3_ = _vala_strcmp0 (a->obj, b->obj) == 0;
#line 242 "rygel-tracker-query-triplet.c"
	} else {
#line 69 "rygel-tracker-query-triplet.vala"
		_tmp3_ = FALSE;
#line 246 "rygel-tracker-query-triplet.c"
	}
#line 69 "rygel-tracker-query-triplet.vala"
	if (_tmp3_) {
#line 71 "rygel-tracker-query-triplet.vala"
		_tmp2_ = _vala_strcmp0 (a->predicate, b->predicate) == 0;
#line 252 "rygel-tracker-query-triplet.c"
	} else {
#line 69 "rygel-tracker-query-triplet.vala"
		_tmp2_ = FALSE;
#line 256 "rygel-tracker-query-triplet.c"
	}
#line 69 "rygel-tracker-query-triplet.vala"
	if (_tmp2_) {
#line 72 "rygel-tracker-query-triplet.vala"
		_tmp1_ = chain_equal;
#line 262 "rygel-tracker-query-triplet.c"
	} else {
#line 69 "rygel-tracker-query-triplet.vala"
		_tmp1_ = FALSE;
#line 266 "rygel-tracker-query-triplet.c"
	}
	result = _tmp1_;
#line 69 "rygel-tracker-query-triplet.vala"
	return result;
#line 271 "rygel-tracker-query-triplet.c"
}


#line 75 "rygel-tracker-query-triplet.vala"
char* rygel_tracker_query_triplet_to_string (RygelTrackerQueryTriplet* self, gboolean include_subject) {
#line 277 "rygel-tracker-query-triplet.c"
	char* result = NULL;
	char* str;
	char* _tmp3_;
	char* _tmp2_;
#line 75 "rygel-tracker-query-triplet.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 76 "rygel-tracker-query-triplet.vala"
	str = g_strdup ("");
#line 78 "rygel-tracker-query-triplet.vala"
	if (include_subject) {
#line 288 "rygel-tracker-query-triplet.c"
		char* _tmp1_;
		char* _tmp0_;
#line 79 "rygel-tracker-query-triplet.vala"
		str = (_tmp1_ = g_strconcat (str, _tmp0_ = g_strconcat (" ", self->subject, NULL), NULL), _g_free0 (str), _tmp1_);
#line 293 "rygel-tracker-query-triplet.c"
		_g_free0 (_tmp0_);
	}
#line 82 "rygel-tracker-query-triplet.vala"
	str = (_tmp3_ = g_strconcat (str, _tmp2_ = g_strconcat (" ", self->predicate, NULL), NULL), _g_free0 (str), _tmp3_);
#line 298 "rygel-tracker-query-triplet.c"
	_g_free0 (_tmp2_);
#line 84 "rygel-tracker-query-triplet.vala"
	if (self->next != NULL) {
#line 302 "rygel-tracker-query-triplet.c"
		char* _tmp7_;
		char* _tmp6_;
		char* _tmp5_;
		char* _tmp4_;
#line 85 "rygel-tracker-query-triplet.vala"
		str = (_tmp7_ = g_strconcat (str, _tmp6_ = g_strconcat (_tmp5_ = g_strconcat (" [ ", _tmp4_ = rygel_tracker_query_triplet_to_string (self->next, TRUE), NULL), " ] ", NULL), NULL), _g_free0 (str), _tmp7_);
#line 309 "rygel-tracker-query-triplet.c"
		_g_free0 (_tmp6_);
		_g_free0 (_tmp5_);
		_g_free0 (_tmp4_);
	} else {
		char* _tmp9_;
		char* _tmp8_;
#line 87 "rygel-tracker-query-triplet.vala"
		str = (_tmp9_ = g_strconcat (str, _tmp8_ = g_strconcat (" ", self->obj, NULL), NULL), _g_free0 (str), _tmp9_);
#line 318 "rygel-tracker-query-triplet.c"
		_g_free0 (_tmp8_);
	}
	result = str;
#line 90 "rygel-tracker-query-triplet.vala"
	return result;
#line 324 "rygel-tracker-query-triplet.c"
}


static void rygel_tracker_value_query_triplet_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void rygel_tracker_value_query_triplet_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		rygel_tracker_query_triplet_unref (value->data[0].v_pointer);
	}
}


static void rygel_tracker_value_query_triplet_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = rygel_tracker_query_triplet_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer rygel_tracker_value_query_triplet_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* rygel_tracker_value_query_triplet_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
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


static gchar* rygel_tracker_value_query_triplet_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
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


GParamSpec* rygel_tracker_param_spec_query_triplet (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	RygelTrackerParamSpecQueryTriplet* spec;
	g_return_val_if_fail (g_type_is_a (object_type, RYGEL_TRACKER_TYPE_QUERY_TRIPLET), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer rygel_tracker_value_get_query_triplet (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_TRACKER_TYPE_QUERY_TRIPLET), NULL);
	return value->data[0].v_pointer;
}


void rygel_tracker_value_set_query_triplet (GValue* value, gpointer v_object) {
	RygelTrackerQueryTriplet* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_TRACKER_TYPE_QUERY_TRIPLET));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, RYGEL_TRACKER_TYPE_QUERY_TRIPLET));
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


void rygel_tracker_value_take_query_triplet (GValue* value, gpointer v_object) {
	RygelTrackerQueryTriplet* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_TRACKER_TYPE_QUERY_TRIPLET));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, RYGEL_TRACKER_TYPE_QUERY_TRIPLET));
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
		static const GTypeValueTable g_define_type_value_table = { rygel_tracker_value_query_triplet_init, rygel_tracker_value_query_triplet_free_value, rygel_tracker_value_query_triplet_copy_value, rygel_tracker_value_query_triplet_peek_pointer, "p", rygel_tracker_value_query_triplet_collect_value, "p", rygel_tracker_value_query_triplet_lcopy_value };
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




