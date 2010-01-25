/* rygel-logical-expression.c generated by valac, the Vala compiler
 * generated from rygel-logical-expression.vala, do not modify */

/*
 * Copyright (C) 2009 Nokia Corporation.
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
#include <stdlib.h>
#include <string.h>


#define RYGEL_TYPE_LOGICAL_OPERATOR (rygel_logical_operator_get_type ())

#define RYGEL_TYPE_SEARCH_EXPRESSION (rygel_search_expression_get_type ())
#define RYGEL_SEARCH_EXPRESSION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_SEARCH_EXPRESSION, RygelSearchExpression))
#define RYGEL_SEARCH_EXPRESSION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_SEARCH_EXPRESSION, RygelSearchExpressionClass))
#define RYGEL_IS_SEARCH_EXPRESSION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_SEARCH_EXPRESSION))
#define RYGEL_IS_SEARCH_EXPRESSION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_SEARCH_EXPRESSION))
#define RYGEL_SEARCH_EXPRESSION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_SEARCH_EXPRESSION, RygelSearchExpressionClass))

typedef struct _RygelSearchExpression RygelSearchExpression;
typedef struct _RygelSearchExpressionClass RygelSearchExpressionClass;
typedef struct _RygelSearchExpressionPrivate RygelSearchExpressionPrivate;

#define RYGEL_TYPE_MEDIA_OBJECT (rygel_media_object_get_type ())
#define RYGEL_MEDIA_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObject))
#define RYGEL_MEDIA_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObjectClass))
#define RYGEL_IS_MEDIA_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_OBJECT))
#define RYGEL_IS_MEDIA_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_OBJECT))
#define RYGEL_MEDIA_OBJECT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObjectClass))

typedef struct _RygelMediaObject RygelMediaObject;
typedef struct _RygelMediaObjectClass RygelMediaObjectClass;

#define RYGEL_TYPE_LOGICAL_EXPRESSION (rygel_logical_expression_get_type ())
#define RYGEL_LOGICAL_EXPRESSION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_LOGICAL_EXPRESSION, RygelLogicalExpression))
#define RYGEL_LOGICAL_EXPRESSION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_LOGICAL_EXPRESSION, RygelLogicalExpressionClass))
#define RYGEL_IS_LOGICAL_EXPRESSION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_LOGICAL_EXPRESSION))
#define RYGEL_IS_LOGICAL_EXPRESSION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_LOGICAL_EXPRESSION))
#define RYGEL_LOGICAL_EXPRESSION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_LOGICAL_EXPRESSION, RygelLogicalExpressionClass))

typedef struct _RygelLogicalExpression RygelLogicalExpression;
typedef struct _RygelLogicalExpressionClass RygelLogicalExpressionClass;
typedef struct _RygelLogicalExpressionPrivate RygelLogicalExpressionPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))

typedef enum  {
	RYGEL_LOGICAL_OPERATOR_AND,
	RYGEL_LOGICAL_OPERATOR_OR
} RygelLogicalOperator;

struct _RygelSearchExpression {
	GTypeInstance parent_instance;
	volatile int ref_count;
	RygelSearchExpressionPrivate * priv;
	gpointer op;
	gpointer operand1;
	gpointer operand2;
};

struct _RygelSearchExpressionClass {
	GTypeClass parent_class;
	void (*finalize) (RygelSearchExpression *self);
	gboolean (*satisfied_by) (RygelSearchExpression* self, RygelMediaObject* media_object);
	char* (*to_string) (RygelSearchExpression* self);
};

struct _RygelLogicalExpression {
	RygelSearchExpression parent_instance;
	RygelLogicalExpressionPrivate * priv;
};

struct _RygelLogicalExpressionClass {
	RygelSearchExpressionClass parent_class;
};


static gpointer rygel_logical_expression_parent_class = NULL;

GType rygel_logical_operator_get_type (void);
gpointer rygel_search_expression_ref (gpointer instance);
void rygel_search_expression_unref (gpointer instance);
GParamSpec* rygel_param_spec_search_expression (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_search_expression (GValue* value, gpointer v_object);
gpointer rygel_value_get_search_expression (const GValue* value);
GType rygel_search_expression_get_type (void);
GType rygel_media_object_get_type (void);
GType rygel_logical_expression_get_type (void);
enum  {
	RYGEL_LOGICAL_EXPRESSION_DUMMY_PROPERTY
};
gboolean rygel_search_expression_satisfied_by (RygelSearchExpression* self, RygelMediaObject* media_object);
static gboolean rygel_logical_expression_real_satisfied_by (RygelSearchExpression* base, RygelMediaObject* media_object);
char* rygel_search_expression_to_string (RygelSearchExpression* self);
static char* rygel_logical_expression_real_to_string (RygelSearchExpression* base);
RygelSearchExpression* rygel_search_expression_construct (GType object_type, GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, GType h_type, GBoxedCopyFunc h_dup_func, GDestroyNotify h_destroy_func, GType i_type, GBoxedCopyFunc i_dup_func, GDestroyNotify i_destroy_func);
RygelLogicalExpression* rygel_logical_expression_new (void);
RygelLogicalExpression* rygel_logical_expression_construct (GType object_type);




GType rygel_logical_operator_get_type (void) {
	static GType rygel_logical_operator_type_id = 0;
	if (G_UNLIKELY (rygel_logical_operator_type_id == 0)) {
		static const GEnumValue values[] = {{RYGEL_LOGICAL_OPERATOR_AND, "RYGEL_LOGICAL_OPERATOR_AND", "and"}, {RYGEL_LOGICAL_OPERATOR_OR, "RYGEL_LOGICAL_OPERATOR_OR", "or"}, {0, NULL, NULL}};
		rygel_logical_operator_type_id = g_enum_register_static ("RygelLogicalOperator", values);
	}
	return rygel_logical_operator_type_id;
}


#line 34 "rygel-logical-expression.vala"
static gboolean rygel_logical_expression_real_satisfied_by (RygelSearchExpression* base, RygelMediaObject* media_object) {
#line 136 "rygel-logical-expression.c"
	RygelLogicalExpression * self;
	gboolean result;
	self = (RygelLogicalExpression*) base;
#line 34 "rygel-logical-expression.vala"
	g_return_val_if_fail (media_object != NULL, FALSE);
#line 35 "rygel-logical-expression.vala"
	switch (GPOINTER_TO_INT (((RygelSearchExpression*) self)->op)) {
#line 144 "rygel-logical-expression.c"
		case RYGEL_LOGICAL_OPERATOR_AND:
		{
			gboolean _tmp0_ = FALSE;
#line 37 "rygel-logical-expression.vala"
			if (rygel_search_expression_satisfied_by ((RygelSearchExpression*) ((RygelSearchExpression*) self)->operand1, media_object)) {
#line 38 "rygel-logical-expression.vala"
				_tmp0_ = rygel_search_expression_satisfied_by ((RygelSearchExpression*) ((RygelSearchExpression*) self)->operand2, media_object);
#line 152 "rygel-logical-expression.c"
			} else {
#line 37 "rygel-logical-expression.vala"
				_tmp0_ = FALSE;
#line 156 "rygel-logical-expression.c"
			}
			result = _tmp0_;
#line 37 "rygel-logical-expression.vala"
			return result;
#line 161 "rygel-logical-expression.c"
		}
		case RYGEL_LOGICAL_OPERATOR_OR:
		{
			gboolean _tmp1_ = FALSE;
#line 40 "rygel-logical-expression.vala"
			if (rygel_search_expression_satisfied_by ((RygelSearchExpression*) ((RygelSearchExpression*) self)->operand1, media_object)) {
#line 40 "rygel-logical-expression.vala"
				_tmp1_ = TRUE;
#line 170 "rygel-logical-expression.c"
			} else {
#line 41 "rygel-logical-expression.vala"
				_tmp1_ = rygel_search_expression_satisfied_by ((RygelSearchExpression*) ((RygelSearchExpression*) self)->operand2, media_object);
#line 174 "rygel-logical-expression.c"
			}
			result = _tmp1_;
#line 40 "rygel-logical-expression.vala"
			return result;
#line 179 "rygel-logical-expression.c"
		}
		default:
		{
			result = FALSE;
#line 43 "rygel-logical-expression.vala"
			return result;
#line 186 "rygel-logical-expression.c"
		}
	}
}


#line 47 "rygel-logical-expression.vala"
static char* rygel_logical_expression_real_to_string (RygelSearchExpression* base) {
#line 194 "rygel-logical-expression.c"
	RygelLogicalExpression * self;
	char* result;
	char* _tmp0_;
	char* operand1;
	char* _tmp3_;
	char* operand2;
	self = (RygelLogicalExpression*) base;
	_tmp0_ = NULL;
#line 48 "rygel-logical-expression.vala"
	if (((RygelSearchExpression*) ((RygelSearchExpression*) self)->operand1) != NULL) {
#line 205 "rygel-logical-expression.c"
		char* _tmp1_;
#line 49 "rygel-logical-expression.vala"
		_tmp0_ = (_tmp1_ = rygel_search_expression_to_string ((RygelSearchExpression*) ((RygelSearchExpression*) self)->operand1), _g_free0 (_tmp0_), _tmp1_);
#line 209 "rygel-logical-expression.c"
	} else {
		char* _tmp2_;
#line 50 "rygel-logical-expression.vala"
		_tmp0_ = (_tmp2_ = g_strdup ("none"), _g_free0 (_tmp0_), _tmp2_);
#line 214 "rygel-logical-expression.c"
	}
#line 48 "rygel-logical-expression.vala"
	operand1 = g_strdup (_tmp0_);
#line 218 "rygel-logical-expression.c"
	_tmp3_ = NULL;
#line 51 "rygel-logical-expression.vala"
	if (((RygelSearchExpression*) ((RygelSearchExpression*) self)->operand2) != NULL) {
#line 222 "rygel-logical-expression.c"
		char* _tmp4_;
#line 52 "rygel-logical-expression.vala"
		_tmp3_ = (_tmp4_ = rygel_search_expression_to_string ((RygelSearchExpression*) ((RygelSearchExpression*) self)->operand2), _g_free0 (_tmp3_), _tmp4_);
#line 226 "rygel-logical-expression.c"
	} else {
		char* _tmp5_;
#line 53 "rygel-logical-expression.vala"
		_tmp3_ = (_tmp5_ = g_strdup ("none"), _g_free0 (_tmp3_), _tmp5_);
#line 231 "rygel-logical-expression.c"
	}
#line 51 "rygel-logical-expression.vala"
	operand2 = g_strdup (_tmp3_);
#line 235 "rygel-logical-expression.c"
	result = g_strdup_printf ("(%s %d %s)", operand1, (gint) GPOINTER_TO_INT (((RygelSearchExpression*) self)->op), operand2);
	_g_free0 (_tmp0_);
	_g_free0 (operand1);
	_g_free0 (_tmp3_);
	_g_free0 (operand2);
#line 54 "rygel-logical-expression.vala"
	return result;
#line 243 "rygel-logical-expression.c"
}


#line 30 "rygel-logical-expression.vala"
RygelLogicalExpression* rygel_logical_expression_construct (GType object_type) {
#line 249 "rygel-logical-expression.c"
	RygelLogicalExpression* self;
#line 30 "rygel-logical-expression.vala"
	self = (RygelLogicalExpression*) rygel_search_expression_construct (object_type, RYGEL_TYPE_LOGICAL_OPERATOR, NULL, NULL, RYGEL_TYPE_SEARCH_EXPRESSION, (GBoxedCopyFunc) rygel_search_expression_ref, rygel_search_expression_unref, RYGEL_TYPE_SEARCH_EXPRESSION, (GBoxedCopyFunc) rygel_search_expression_ref, rygel_search_expression_unref);
#line 253 "rygel-logical-expression.c"
	return self;
}


#line 30 "rygel-logical-expression.vala"
RygelLogicalExpression* rygel_logical_expression_new (void) {
#line 30 "rygel-logical-expression.vala"
	return rygel_logical_expression_construct (RYGEL_TYPE_LOGICAL_EXPRESSION);
#line 262 "rygel-logical-expression.c"
}


static void rygel_logical_expression_class_init (RygelLogicalExpressionClass * klass) {
	rygel_logical_expression_parent_class = g_type_class_peek_parent (klass);
	RYGEL_SEARCH_EXPRESSION_CLASS (klass)->satisfied_by = rygel_logical_expression_real_satisfied_by;
	RYGEL_SEARCH_EXPRESSION_CLASS (klass)->to_string = rygel_logical_expression_real_to_string;
}


static void rygel_logical_expression_instance_init (RygelLogicalExpression * self) {
}


GType rygel_logical_expression_get_type (void) {
	static GType rygel_logical_expression_type_id = 0;
	if (rygel_logical_expression_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelLogicalExpressionClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_logical_expression_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelLogicalExpression), 0, (GInstanceInitFunc) rygel_logical_expression_instance_init, NULL };
		rygel_logical_expression_type_id = g_type_register_static (RYGEL_TYPE_SEARCH_EXPRESSION, "RygelLogicalExpression", &g_define_type_info, 0);
	}
	return rygel_logical_expression_type_id;
}




