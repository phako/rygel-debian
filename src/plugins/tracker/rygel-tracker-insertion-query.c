/* rygel-tracker-insertion-query.c generated by valac, the Vala compiler
 * generated from rygel-tracker-insertion-query.vala, do not modify */

/*
 * Copyright (C) 20010 Nokia Corporation.
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
#include <gio/gio.h>
#include <dbus/dbus-glib-lowlevel.h>
#include <dbus/dbus-glib.h>
#include <stdlib.h>
#include <string.h>
#include <gee.h>
#include <rygel.h>


#define RYGEL_TYPE_TRACKER_QUERY (rygel_tracker_query_get_type ())
#define RYGEL_TRACKER_QUERY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_QUERY, RygelTrackerQuery))
#define RYGEL_TRACKER_QUERY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_QUERY, RygelTrackerQueryClass))
#define RYGEL_IS_TRACKER_QUERY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_QUERY))
#define RYGEL_IS_TRACKER_QUERY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_QUERY))
#define RYGEL_TRACKER_QUERY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_QUERY, RygelTrackerQueryClass))

typedef struct _RygelTrackerQuery RygelTrackerQuery;
typedef struct _RygelTrackerQueryClass RygelTrackerQueryClass;
typedef struct _RygelTrackerQueryPrivate RygelTrackerQueryPrivate;

#define RYGEL_TYPE_TRACKER_RESOURCES_IFACE (rygel_tracker_resources_iface_get_type ())
#define RYGEL_TRACKER_RESOURCES_IFACE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_RESOURCES_IFACE, RygelTrackerResourcesIface))
#define RYGEL_IS_TRACKER_RESOURCES_IFACE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_RESOURCES_IFACE))
#define RYGEL_TRACKER_RESOURCES_IFACE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), RYGEL_TYPE_TRACKER_RESOURCES_IFACE, RygelTrackerResourcesIfaceIface))

typedef struct _RygelTrackerResourcesIface RygelTrackerResourcesIface;
typedef struct _RygelTrackerResourcesIfaceIface RygelTrackerResourcesIfaceIface;

#define RYGEL_TYPE_TRACKER_QUERY_TRIPLETS (rygel_tracker_query_triplets_get_type ())
#define RYGEL_TRACKER_QUERY_TRIPLETS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_QUERY_TRIPLETS, RygelTrackerQueryTriplets))
#define RYGEL_TRACKER_QUERY_TRIPLETS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_QUERY_TRIPLETS, RygelTrackerQueryTripletsClass))
#define RYGEL_IS_TRACKER_QUERY_TRIPLETS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_QUERY_TRIPLETS))
#define RYGEL_IS_TRACKER_QUERY_TRIPLETS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_QUERY_TRIPLETS))
#define RYGEL_TRACKER_QUERY_TRIPLETS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_QUERY_TRIPLETS, RygelTrackerQueryTripletsClass))

typedef struct _RygelTrackerQueryTriplets RygelTrackerQueryTriplets;
typedef struct _RygelTrackerQueryTripletsClass RygelTrackerQueryTripletsClass;

#define RYGEL_TYPE_TRACKER_INSERTION_QUERY (rygel_tracker_insertion_query_get_type ())
#define RYGEL_TRACKER_INSERTION_QUERY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_INSERTION_QUERY, RygelTrackerInsertionQuery))
#define RYGEL_TRACKER_INSERTION_QUERY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_INSERTION_QUERY, RygelTrackerInsertionQueryClass))
#define RYGEL_IS_TRACKER_INSERTION_QUERY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_INSERTION_QUERY))
#define RYGEL_IS_TRACKER_INSERTION_QUERY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_INSERTION_QUERY))
#define RYGEL_TRACKER_INSERTION_QUERY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_INSERTION_QUERY, RygelTrackerInsertionQueryClass))

typedef struct _RygelTrackerInsertionQuery RygelTrackerInsertionQuery;
typedef struct _RygelTrackerInsertionQueryClass RygelTrackerInsertionQueryClass;
typedef struct _RygelTrackerInsertionQueryPrivate RygelTrackerInsertionQueryPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))

#define RYGEL_TYPE_TRACKER_QUERY_TRIPLET (rygel_tracker_query_triplet_get_type ())
#define RYGEL_TRACKER_QUERY_TRIPLET(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_QUERY_TRIPLET, RygelTrackerQueryTriplet))
#define RYGEL_TRACKER_QUERY_TRIPLET_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_QUERY_TRIPLET, RygelTrackerQueryTripletClass))
#define RYGEL_IS_TRACKER_QUERY_TRIPLET(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_QUERY_TRIPLET))
#define RYGEL_IS_TRACKER_QUERY_TRIPLET_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_QUERY_TRIPLET))
#define RYGEL_TRACKER_QUERY_TRIPLET_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_QUERY_TRIPLET, RygelTrackerQueryTripletClass))

typedef struct _RygelTrackerQueryTriplet RygelTrackerQueryTriplet;
typedef struct _RygelTrackerQueryTripletClass RygelTrackerQueryTripletClass;
#define _rygel_tracker_query_triplet_unref0(var) ((var == NULL) ? NULL : (var = (rygel_tracker_query_triplet_unref (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _RygelTrackerInsertionQueryExecuteData RygelTrackerInsertionQueryExecuteData;

struct _RygelTrackerResourcesIfaceIface {
	GTypeInterface parent_iface;
	void (*sparql_query) (RygelTrackerResourcesIface* self, const char* query, GAsyncReadyCallback _callback_, gpointer _user_data_);
	char** (*sparql_query_finish) (RygelTrackerResourcesIface* self, GAsyncResult* _res_, int* result_length1, int* result_length2, GError** error);
	void (*sparql_update_blank) (RygelTrackerResourcesIface* self, const char* query, GAsyncReadyCallback _callback_, gpointer _user_data_);
	GHashTable** (*sparql_update_blank_finish) (RygelTrackerResourcesIface* self, GAsyncResult* _res_, int* result_length1, int* result_length2, GError** error);
};

struct _RygelTrackerQuery {
	GTypeInstance parent_instance;
	volatile int ref_count;
	RygelTrackerQueryPrivate * priv;
	RygelTrackerQueryTriplets* mandatory;
	RygelTrackerQueryTriplets* optional;
};

struct _RygelTrackerQueryClass {
	GTypeClass parent_class;
	void (*finalize) (RygelTrackerQuery *self);
	void (*execute) (RygelTrackerQuery* self, RygelTrackerResourcesIface* resources, GAsyncReadyCallback _callback_, gpointer _user_data_);
	void (*execute_finish) (RygelTrackerQuery* self, GAsyncResult* _res_, GError** error);
	char* (*to_string) (RygelTrackerQuery* self);
};

struct _RygelTrackerInsertionQuery {
	RygelTrackerQuery parent_instance;
	RygelTrackerInsertionQueryPrivate * priv;
	char* id;
};

struct _RygelTrackerInsertionQueryClass {
	RygelTrackerQueryClass parent_class;
};

struct _RygelTrackerInsertionQueryExecuteData {
	int _state_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	RygelTrackerInsertionQuery* self;
	RygelTrackerResourcesIface* resources;
	char* str;
	GHashTable** _result_;
	gint _tmp1_;
	gint _tmp0_;
	GHashTable** _tmp2_;
	gint _result__length2;
	gint _result__length1;
	char* _tmp3_;
	GError * _inner_error_;
};


static gpointer rygel_tracker_insertion_query_parent_class = NULL;

gpointer rygel_tracker_query_ref (gpointer instance);
void rygel_tracker_query_unref (gpointer instance);
GParamSpec* rygel_param_spec_tracker_query (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_tracker_query (GValue* value, gpointer v_object);
void rygel_value_take_tracker_query (GValue* value, gpointer v_object);
gpointer rygel_value_get_tracker_query (const GValue* value);
GType rygel_tracker_query_get_type (void);
GType rygel_tracker_resources_iface_get_type (void);
GType rygel_tracker_query_triplets_get_type (void);
GType rygel_tracker_insertion_query_get_type (void);
enum  {
	RYGEL_TRACKER_INSERTION_QUERY_DUMMY_PROPERTY
};
#define RYGEL_TRACKER_INSERTION_QUERY_TEMP_ID "x"
#define RYGEL_TRACKER_INSERTION_QUERY_QUERY_ID "_:" RYGEL_TRACKER_INSERTION_QUERY_TEMP_ID
RygelTrackerQueryTriplets* rygel_tracker_query_triplets_new (void);
RygelTrackerQueryTriplets* rygel_tracker_query_triplets_construct (GType object_type);
RygelTrackerQueryTriplet* rygel_tracker_query_triplet_new (const char* subject, const char* predicate, const char* obj, gboolean optional);
RygelTrackerQueryTriplet* rygel_tracker_query_triplet_construct (GType object_type, const char* subject, const char* predicate, const char* obj, gboolean optional);
gpointer rygel_tracker_query_triplet_ref (gpointer instance);
void rygel_tracker_query_triplet_unref (gpointer instance);
GParamSpec* rygel_param_spec_tracker_query_triplet (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_tracker_query_triplet (GValue* value, gpointer v_object);
void rygel_value_take_tracker_query_triplet (GValue* value, gpointer v_object);
gpointer rygel_value_get_tracker_query_triplet (const GValue* value);
GType rygel_tracker_query_triplet_get_type (void);
RygelTrackerQuery* rygel_tracker_query_construct (GType object_type, RygelTrackerQueryTriplets* mandatory, RygelTrackerQueryTriplets* optional);
RygelTrackerInsertionQuery* rygel_tracker_insertion_query_new (RygelMediaItem* item, const char* category);
RygelTrackerInsertionQuery* rygel_tracker_insertion_query_construct (GType object_type, RygelMediaItem* item, const char* category);
static void rygel_tracker_insertion_query_real_execute_data_free (gpointer _data);
static void rygel_tracker_insertion_query_real_execute (RygelTrackerQuery* base, RygelTrackerResourcesIface* resources, GAsyncReadyCallback _callback_, gpointer _user_data_);
static void rygel_tracker_insertion_query_execute_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
char* rygel_tracker_query_to_string (RygelTrackerQuery* self);
void rygel_tracker_resources_iface_sparql_update_blank (RygelTrackerResourcesIface* self, const char* query, GAsyncReadyCallback _callback_, gpointer _user_data_);
GHashTable** rygel_tracker_resources_iface_sparql_update_blank_finish (RygelTrackerResourcesIface* self, GAsyncResult* _res_, int* result_length1, int* result_length2, GError** error);
static gboolean rygel_tracker_insertion_query_real_execute_co (RygelTrackerInsertionQueryExecuteData* data);
static char* rygel_tracker_insertion_query_real_to_string (RygelTrackerQuery* base);
static void rygel_tracker_insertion_query_finalize (RygelTrackerQuery* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);



#line 34 "rygel-tracker-insertion-query.vala"
RygelTrackerInsertionQuery* rygel_tracker_insertion_query_construct (GType object_type, RygelMediaItem* item, const char* category) {
#line 191 "rygel-tracker-insertion-query.c"
	RygelTrackerInsertionQuery* self;
	RygelTrackerQueryTriplets* triplets;
	RygelTrackerQueryTriplet* _tmp0_;
	RygelTrackerQueryTriplet* _tmp1_;
	RygelTrackerQueryTriplet* _tmp2_;
	RygelTrackerQueryTriplet* _tmp5_;
	char* _tmp4_;
	char* _tmp3_;
	RygelTrackerQueryTriplet* _tmp9_;
	char* _tmp8_;
	char* _tmp7_;
	char* _tmp6_;
	GTimeVal now = {0};
	RygelTrackerQueryTriplet* _tmp13_;
	char* _tmp12_;
	char* _tmp11_;
	char* _tmp10_;
#line 34 "rygel-tracker-insertion-query.vala"
	g_return_val_if_fail (item != NULL, NULL);
#line 34 "rygel-tracker-insertion-query.vala"
	g_return_val_if_fail (category != NULL, NULL);
#line 35 "rygel-tracker-insertion-query.vala"
	triplets = rygel_tracker_query_triplets_new ();
#line 36 "rygel-tracker-insertion-query.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) triplets, _tmp0_ = rygel_tracker_query_triplet_new (RYGEL_TRACKER_INSERTION_QUERY_QUERY_ID, "a", category, FALSE));
#line 217 "rygel-tracker-insertion-query.c"
	_rygel_tracker_query_triplet_unref0 (_tmp0_);
#line 40 "rygel-tracker-insertion-query.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) triplets, _tmp1_ = rygel_tracker_query_triplet_new (RYGEL_TRACKER_INSERTION_QUERY_QUERY_ID, "a", "nie:DataObject", FALSE));
#line 221 "rygel-tracker-insertion-query.c"
	_rygel_tracker_query_triplet_unref0 (_tmp1_);
#line 44 "rygel-tracker-insertion-query.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) triplets, _tmp2_ = rygel_tracker_query_triplet_new (RYGEL_TRACKER_INSERTION_QUERY_QUERY_ID, "a", "nfo:FileDataObject", FALSE));
#line 225 "rygel-tracker-insertion-query.c"
	_rygel_tracker_query_triplet_unref0 (_tmp2_);
#line 48 "rygel-tracker-insertion-query.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) triplets, _tmp5_ = rygel_tracker_query_triplet_new (RYGEL_TRACKER_INSERTION_QUERY_QUERY_ID, "nie:mimeType", _tmp4_ = g_strconcat (_tmp3_ = g_strconcat ("\"", item->mime_type, NULL), "\"", NULL), FALSE));
#line 229 "rygel-tracker-insertion-query.c"
	_rygel_tracker_query_triplet_unref0 (_tmp5_);
	_g_free0 (_tmp4_);
	_g_free0 (_tmp3_);
#line 52 "rygel-tracker-insertion-query.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) triplets, _tmp9_ = rygel_tracker_query_triplet_new (RYGEL_TRACKER_INSERTION_QUERY_QUERY_ID, "nie:url", _tmp8_ = g_strconcat (_tmp7_ = g_strconcat ("\"", _tmp6_ = (char*) gee_abstract_list_get ((GeeAbstractList*) ((RygelMediaObject*) item)->uris, 0), NULL), "\"", NULL), FALSE));
#line 235 "rygel-tracker-insertion-query.c"
	_rygel_tracker_query_triplet_unref0 (_tmp9_);
	_g_free0 (_tmp8_);
	_g_free0 (_tmp7_);
	_g_free0 (_tmp6_);
	g_get_current_time (&now);
#line 58 "rygel-tracker-insertion-query.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) triplets, _tmp13_ = rygel_tracker_query_triplet_new (RYGEL_TRACKER_INSERTION_QUERY_QUERY_ID, "nfo:fileLastModified", _tmp12_ = g_strconcat (_tmp11_ = g_strconcat ("\"", _tmp10_ = g_time_val_to_iso8601 (&now), NULL), "\"", NULL), FALSE));
#line 243 "rygel-tracker-insertion-query.c"
	_rygel_tracker_query_triplet_unref0 (_tmp13_);
	_g_free0 (_tmp12_);
	_g_free0 (_tmp11_);
	_g_free0 (_tmp10_);
#line 63 "rygel-tracker-insertion-query.vala"
	self = (RygelTrackerInsertionQuery*) rygel_tracker_query_construct (object_type, triplets, NULL);
#line 250 "rygel-tracker-insertion-query.c"
	_g_object_unref0 (triplets);
	return self;
}


#line 34 "rygel-tracker-insertion-query.vala"
RygelTrackerInsertionQuery* rygel_tracker_insertion_query_new (RygelMediaItem* item, const char* category) {
#line 34 "rygel-tracker-insertion-query.vala"
	return rygel_tracker_insertion_query_construct (RYGEL_TYPE_TRACKER_INSERTION_QUERY, item, category);
#line 260 "rygel-tracker-insertion-query.c"
}


static void rygel_tracker_insertion_query_real_execute_data_free (gpointer _data) {
	RygelTrackerInsertionQueryExecuteData* data;
	data = _data;
	_g_object_unref0 (data->resources);
	rygel_tracker_query_unref (data->self);
	g_slice_free (RygelTrackerInsertionQueryExecuteData, data);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void rygel_tracker_insertion_query_real_execute (RygelTrackerQuery* base, RygelTrackerResourcesIface* resources, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	RygelTrackerInsertionQuery * self;
	RygelTrackerInsertionQueryExecuteData* _data_;
	self = (RygelTrackerInsertionQuery*) base;
	_data_ = g_slice_new0 (RygelTrackerInsertionQueryExecuteData);
	_data_->_async_result = g_simple_async_result_new (g_object_newv (G_TYPE_OBJECT, 0, NULL), _callback_, _user_data_, rygel_tracker_insertion_query_real_execute);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, rygel_tracker_insertion_query_real_execute_data_free);
	_data_->self = rygel_tracker_query_ref (self);
	_data_->resources = _g_object_ref0 (resources);
	rygel_tracker_insertion_query_real_execute_co (_data_);
}


static void rygel_tracker_insertion_query_real_execute_finish (RygelTrackerQuery* base, GAsyncResult* _res_, GError** error) {
	RygelTrackerInsertionQueryExecuteData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void rygel_tracker_insertion_query_execute_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	RygelTrackerInsertionQueryExecuteData* data;
	data = _user_data_;
	data->_res_ = _res_;
	rygel_tracker_insertion_query_real_execute_co (data);
}


static gboolean rygel_tracker_insertion_query_real_execute_co (RygelTrackerInsertionQueryExecuteData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		case 8:
		goto _state_8;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	{
		data->str = rygel_tracker_query_to_string ((RygelTrackerQuery*) data->self);
#line 70 "rygel-tracker-insertion-query.vala"
		g_debug ("rygel-tracker-insertion-query.vala:70: Executing SPARQL query: %s", data->str);
#line 322 "rygel-tracker-insertion-query.c"
		data->_state_ = 8;
		rygel_tracker_resources_iface_sparql_update_blank (data->resources, data->str, rygel_tracker_insertion_query_execute_ready, data);
		return FALSE;
		_state_8:
		data->_result_ = (data->_tmp2_ = rygel_tracker_resources_iface_sparql_update_blank_finish (data->resources, data->_res_, &data->_tmp0_, &data->_tmp1_, &data->_inner_error_), data->_result__length1 = data->_tmp0_, data->_result__length2 = data->_tmp1_, data->_tmp2_);
		if (data->_inner_error_ != NULL) {
			if (data->_inner_error_->domain == DBUS_GERROR) {
				g_simple_async_result_set_from_error (data->_async_result, data->_inner_error_);
				g_error_free (data->_inner_error_);
				_g_free0 (data->str);
				{
					if (data->_state_ == 0) {
						g_simple_async_result_complete_in_idle (data->_async_result);
					} else {
						g_simple_async_result_complete (data->_async_result);
					}
					g_object_unref (data->_async_result);
					return FALSE;
				}
			} else {
				_g_free0 (data->str);
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, data->_inner_error_->message, g_quark_to_string (data->_inner_error_->domain), data->_inner_error_->code);
				g_clear_error (&data->_inner_error_);
				return FALSE;
			}
		}
#line 74 "rygel-tracker-insertion-query.vala"
		data->self->id = (data->_tmp3_ = g_strdup ((const char*) g_hash_table_lookup (data->_result_[(0 * data->_result__length2) + 0], RYGEL_TRACKER_INSERTION_QUERY_TEMP_ID)), _g_free0 (data->self->id), data->_tmp3_);
#line 351 "rygel-tracker-insertion-query.c"
		_g_free0 (data->str);
		data->_result_ = (_vala_array_free (data->_result_, data->_result__length1 * data->_result__length2, (GDestroyNotify) g_hash_table_unref), NULL);
	}
	{
		if (data->_state_ == 0) {
			g_simple_async_result_complete_in_idle (data->_async_result);
		} else {
			g_simple_async_result_complete (data->_async_result);
		}
		g_object_unref (data->_async_result);
		return FALSE;
	}
}


#line 77 "rygel-tracker-insertion-query.vala"
static char* rygel_tracker_insertion_query_real_to_string (RygelTrackerQuery* base) {
#line 369 "rygel-tracker-insertion-query.c"
	RygelTrackerInsertionQuery * self;
	char* result = NULL;
	char* _tmp1_;
	char* _tmp0_;
	char* _tmp2_;
	self = (RygelTrackerInsertionQuery*) base;
	result = (_tmp2_ = g_strconcat (_tmp1_ = g_strconcat ("INSERT { ", _tmp0_ = RYGEL_TRACKER_QUERY_CLASS (rygel_tracker_insertion_query_parent_class)->to_string (RYGEL_TRACKER_QUERY (self)), NULL), " }", NULL), _g_free0 (_tmp1_), _g_free0 (_tmp0_), _tmp2_);
#line 78 "rygel-tracker-insertion-query.vala"
	return result;
#line 379 "rygel-tracker-insertion-query.c"
}


static void rygel_tracker_insertion_query_class_init (RygelTrackerInsertionQueryClass * klass) {
	rygel_tracker_insertion_query_parent_class = g_type_class_peek_parent (klass);
	RYGEL_TRACKER_QUERY_CLASS (klass)->finalize = rygel_tracker_insertion_query_finalize;
	RYGEL_TRACKER_QUERY_CLASS (klass)->execute = rygel_tracker_insertion_query_real_execute;
	RYGEL_TRACKER_QUERY_CLASS (klass)->execute_finish = rygel_tracker_insertion_query_real_execute_finish;
	RYGEL_TRACKER_QUERY_CLASS (klass)->to_string = rygel_tracker_insertion_query_real_to_string;
}


static void rygel_tracker_insertion_query_instance_init (RygelTrackerInsertionQuery * self) {
}


static void rygel_tracker_insertion_query_finalize (RygelTrackerQuery* obj) {
	RygelTrackerInsertionQuery * self;
	self = RYGEL_TRACKER_INSERTION_QUERY (obj);
	_g_free0 (self->id);
	RYGEL_TRACKER_QUERY_CLASS (rygel_tracker_insertion_query_parent_class)->finalize (obj);
}


GType rygel_tracker_insertion_query_get_type (void) {
	static volatile gsize rygel_tracker_insertion_query_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_tracker_insertion_query_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelTrackerInsertionQueryClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_tracker_insertion_query_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelTrackerInsertionQuery), 0, (GInstanceInitFunc) rygel_tracker_insertion_query_instance_init, NULL };
		GType rygel_tracker_insertion_query_type_id;
		rygel_tracker_insertion_query_type_id = g_type_register_static (RYGEL_TYPE_TRACKER_QUERY, "RygelTrackerInsertionQuery", &g_define_type_info, 0);
		g_once_init_leave (&rygel_tracker_insertion_query_type_id__volatile, rygel_tracker_insertion_query_type_id);
	}
	return rygel_tracker_insertion_query_type_id__volatile;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}



