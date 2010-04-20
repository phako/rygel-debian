/* rygel-tracker-years.c generated by valac, the Vala compiler
 * generated from rygel-tracker-years.vala, do not modify */

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
#include <rygel.h>
#include <stdlib.h>
#include <string.h>


#define RYGEL_TYPE_TRACKER_METADATA_VALUES (rygel_tracker_metadata_values_get_type ())
#define RYGEL_TRACKER_METADATA_VALUES(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_METADATA_VALUES, RygelTrackerMetadataValues))
#define RYGEL_TRACKER_METADATA_VALUES_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_METADATA_VALUES, RygelTrackerMetadataValuesClass))
#define RYGEL_IS_TRACKER_METADATA_VALUES(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_METADATA_VALUES))
#define RYGEL_IS_TRACKER_METADATA_VALUES_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_METADATA_VALUES))
#define RYGEL_TRACKER_METADATA_VALUES_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_METADATA_VALUES, RygelTrackerMetadataValuesClass))

typedef struct _RygelTrackerMetadataValues RygelTrackerMetadataValues;
typedef struct _RygelTrackerMetadataValuesClass RygelTrackerMetadataValuesClass;
typedef struct _RygelTrackerMetadataValuesPrivate RygelTrackerMetadataValuesPrivate;

#define RYGEL_TYPE_TRACKER_YEARS (rygel_tracker_years_get_type ())
#define RYGEL_TRACKER_YEARS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_YEARS, RygelTrackerYears))
#define RYGEL_TRACKER_YEARS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_YEARS, RygelTrackerYearsClass))
#define RYGEL_IS_TRACKER_YEARS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_YEARS))
#define RYGEL_IS_TRACKER_YEARS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_YEARS))
#define RYGEL_TRACKER_YEARS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_YEARS, RygelTrackerYearsClass))

typedef struct _RygelTrackerYears RygelTrackerYears;
typedef struct _RygelTrackerYearsClass RygelTrackerYearsClass;
typedef struct _RygelTrackerYearsPrivate RygelTrackerYearsPrivate;

#define RYGEL_TYPE_TRACKER_ITEM_FACTORY (rygel_tracker_item_factory_get_type ())
#define RYGEL_TRACKER_ITEM_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_ITEM_FACTORY, RygelTrackerItemFactory))
#define RYGEL_TRACKER_ITEM_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_ITEM_FACTORY, RygelTrackerItemFactoryClass))
#define RYGEL_IS_TRACKER_ITEM_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_ITEM_FACTORY))
#define RYGEL_IS_TRACKER_ITEM_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_ITEM_FACTORY))
#define RYGEL_TRACKER_ITEM_FACTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_ITEM_FACTORY, RygelTrackerItemFactoryClass))

typedef struct _RygelTrackerItemFactory RygelTrackerItemFactory;
typedef struct _RygelTrackerItemFactoryClass RygelTrackerItemFactoryClass;
#define _g_free0(var) (var = (g_free (var), NULL))

typedef char* (*RygelTrackerMetadataValuesIDFunc) (const char* value, void* user_data);
typedef char* (*RygelTrackerMetadataValuesFilterFunc) (const char* variable, const char* value, void* user_data);
struct _RygelTrackerMetadataValues {
	RygelSimpleContainer parent_instance;
	RygelTrackerMetadataValuesPrivate * priv;
	char** key_chain;
	gint key_chain_length1;
	RygelTrackerMetadataValuesIDFunc id_func;
	gpointer id_func_target;
	GDestroyNotify id_func_target_destroy_notify;
	RygelTrackerMetadataValuesIDFunc title_func;
	gpointer title_func_target;
	GDestroyNotify title_func_target_destroy_notify;
	RygelTrackerMetadataValuesFilterFunc filter_func;
	gpointer filter_func_target;
	GDestroyNotify filter_func_target_destroy_notify;
};

struct _RygelTrackerMetadataValuesClass {
	RygelSimpleContainerClass parent_class;
};

struct _RygelTrackerYears {
	RygelTrackerMetadataValues parent_instance;
	RygelTrackerYearsPrivate * priv;
};

struct _RygelTrackerYearsClass {
	RygelTrackerMetadataValuesClass parent_class;
};


static gpointer rygel_tracker_years_parent_class = NULL;

GType rygel_tracker_metadata_values_get_type (void);
GType rygel_tracker_years_get_type (void);
enum  {
	RYGEL_TRACKER_YEARS_DUMMY_PROPERTY
};
static char* rygel_tracker_years_year_id_func (const char* value);
static char* _rygel_tracker_years_year_id_func_rygel_tracker_metadata_values_id_func (const char* value, gpointer self);
static char* rygel_tracker_years_year_filter_func (const char* variable, const char* value);
static char* _rygel_tracker_years_year_filter_func_rygel_tracker_metadata_values_filter_func (const char* variable, const char* value, gpointer self);
gpointer rygel_tracker_item_factory_ref (gpointer instance);
void rygel_tracker_item_factory_unref (gpointer instance);
GParamSpec* rygel_param_spec_tracker_item_factory (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_tracker_item_factory (GValue* value, gpointer v_object);
void rygel_value_take_tracker_item_factory (GValue* value, gpointer v_object);
gpointer rygel_value_get_tracker_item_factory (const GValue* value);
GType rygel_tracker_item_factory_get_type (void);
RygelTrackerMetadataValues* rygel_tracker_metadata_values_new (const char* id, RygelMediaContainer* parent, const char* title, RygelTrackerItemFactory* item_factory, char** key_chain, int key_chain_length1, RygelTrackerMetadataValuesIDFunc id_func, void* id_func_target, RygelTrackerMetadataValuesIDFunc title_func, void* title_func_target, RygelTrackerMetadataValuesFilterFunc filter_func, void* filter_func_target);
RygelTrackerMetadataValues* rygel_tracker_metadata_values_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title, RygelTrackerItemFactory* item_factory, char** key_chain, int key_chain_length1, RygelTrackerMetadataValuesIDFunc id_func, void* id_func_target, RygelTrackerMetadataValuesIDFunc title_func, void* title_func_target, RygelTrackerMetadataValuesFilterFunc filter_func, void* filter_func_target);
RygelTrackerYears* rygel_tracker_years_new (RygelMediaContainer* parent, RygelTrackerItemFactory* item_factory);
RygelTrackerYears* rygel_tracker_years_construct (GType object_type, RygelMediaContainer* parent, RygelTrackerItemFactory* item_factory);

static const char* RYGEL_TRACKER_YEARS_KEY_CHAIN[2] = {"nie:contentCreated", NULL};


#line 44 "rygel-tracker-years.vala"
static char* _rygel_tracker_years_year_id_func_rygel_tracker_metadata_values_id_func (const char* value, gpointer self) {
#line 128 "rygel-tracker-years.c"
	return rygel_tracker_years_year_id_func (value);
}


#line 48 "rygel-tracker-years.vala"
static char* _rygel_tracker_years_year_filter_func_rygel_tracker_metadata_values_filter_func (const char* variable, const char* value, gpointer self) {
#line 135 "rygel-tracker-years.c"
	return rygel_tracker_years_year_filter_func (variable, value);
}


#line 32 "rygel-tracker-years.vala"
RygelTrackerYears* rygel_tracker_years_construct (GType object_type, RygelMediaContainer* parent, RygelTrackerItemFactory* item_factory) {
#line 142 "rygel-tracker-years.c"
	RygelTrackerYears * self;
	char* _tmp0_;
#line 32 "rygel-tracker-years.vala"
	g_return_val_if_fail (parent != NULL, NULL);
#line 32 "rygel-tracker-years.vala"
	g_return_val_if_fail (item_factory != NULL, NULL);
#line 34 "rygel-tracker-years.vala"
	self = (RygelTrackerYears*) rygel_tracker_metadata_values_construct (object_type, _tmp0_ = g_strconcat (((RygelMediaObject*) parent)->id, "Year", NULL), parent, "Year", item_factory, RYGEL_TRACKER_YEARS_KEY_CHAIN, G_N_ELEMENTS (RYGEL_TRACKER_YEARS_KEY_CHAIN), _rygel_tracker_years_year_id_func_rygel_tracker_metadata_values_id_func, NULL, _rygel_tracker_years_year_id_func_rygel_tracker_metadata_values_id_func, NULL, _rygel_tracker_years_year_filter_func_rygel_tracker_metadata_values_filter_func, NULL);
#line 151 "rygel-tracker-years.c"
	_g_free0 (_tmp0_);
	return self;
}


#line 32 "rygel-tracker-years.vala"
RygelTrackerYears* rygel_tracker_years_new (RygelMediaContainer* parent, RygelTrackerItemFactory* item_factory) {
#line 32 "rygel-tracker-years.vala"
	return rygel_tracker_years_construct (RYGEL_TYPE_TRACKER_YEARS, parent, item_factory);
#line 161 "rygel-tracker-years.c"
}


#line 44 "rygel-tracker-years.vala"
static char* rygel_tracker_years_year_id_func (const char* value) {
#line 167 "rygel-tracker-years.c"
	char* result = NULL;
#line 44 "rygel-tracker-years.vala"
	g_return_val_if_fail (value != NULL, NULL);
#line 171 "rygel-tracker-years.c"
	result = g_strndup (value, (gsize) 4);
#line 45 "rygel-tracker-years.vala"
	return result;
#line 175 "rygel-tracker-years.c"
}


#line 48 "rygel-tracker-years.vala"
static char* rygel_tracker_years_year_filter_func (const char* variable, const char* value) {
#line 181 "rygel-tracker-years.c"
	char* result = NULL;
	char* year;
	char* next_year;
	char* _tmp0_;
	char* _tmp1_;
	char* _tmp7_;
	char* _tmp6_;
	char* _tmp5_;
	char* _tmp4_;
	char* _tmp3_;
	char* _tmp2_;
	char* _tmp8_;
#line 48 "rygel-tracker-years.vala"
	g_return_val_if_fail (variable != NULL, NULL);
#line 48 "rygel-tracker-years.vala"
	g_return_val_if_fail (value != NULL, NULL);
#line 49 "rygel-tracker-years.vala"
	year = rygel_tracker_years_year_id_func (value);
#line 50 "rygel-tracker-years.vala"
	next_year = g_strdup_printf ("%i", atoi (year) + 1);
#line 52 "rygel-tracker-years.vala"
	year = (_tmp0_ = g_strconcat (year, "-01-01T00:00:00Z", NULL), _g_free0 (year), _tmp0_);
#line 53 "rygel-tracker-years.vala"
	next_year = (_tmp1_ = g_strconcat (next_year, "-01-01T00:00:00Z", NULL), _g_free0 (next_year), _tmp1_);
#line 206 "rygel-tracker-years.c"
	result = (_tmp8_ = g_strconcat (_tmp7_ = g_strconcat (_tmp6_ = g_strconcat (_tmp5_ = g_strconcat (_tmp4_ = g_strconcat (_tmp3_ = g_strconcat (_tmp2_ = g_strconcat (variable, " > \"", NULL), year, NULL), "\" && ", NULL), variable, NULL), " < \"", NULL), next_year, NULL), "\"", NULL), _g_free0 (_tmp7_), _g_free0 (_tmp6_), _g_free0 (_tmp5_), _g_free0 (_tmp4_), _g_free0 (_tmp3_), _g_free0 (_tmp2_), _tmp8_);
	_g_free0 (year);
	_g_free0 (next_year);
#line 55 "rygel-tracker-years.vala"
	return result;
#line 212 "rygel-tracker-years.c"
	_g_free0 (year);
	_g_free0 (next_year);
}


static void rygel_tracker_years_class_init (RygelTrackerYearsClass * klass) {
	rygel_tracker_years_parent_class = g_type_class_peek_parent (klass);
}


static void rygel_tracker_years_instance_init (RygelTrackerYears * self) {
}


GType rygel_tracker_years_get_type (void) {
	static volatile gsize rygel_tracker_years_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_tracker_years_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelTrackerYearsClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_tracker_years_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelTrackerYears), 0, (GInstanceInitFunc) rygel_tracker_years_instance_init, NULL };
		GType rygel_tracker_years_type_id;
		rygel_tracker_years_type_id = g_type_register_static (RYGEL_TYPE_TRACKER_METADATA_VALUES, "RygelTrackerYears", &g_define_type_info, 0);
		g_once_init_leave (&rygel_tracker_years_type_id__volatile, rygel_tracker_years_type_id);
	}
	return rygel_tracker_years_type_id__volatile;
}




