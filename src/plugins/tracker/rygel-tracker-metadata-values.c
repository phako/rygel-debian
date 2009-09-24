/*
 * Copyright (C) 2008 Zeeshan Ali <zeenix@gmail.com>.
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
#include <rygel.h>
#include <dbus/dbus-glib-lowlevel.h>
#include <dbus/dbus-glib.h>
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
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

#define RYGEL_TYPE_TRACKER_SEARCH_CONTAINER (rygel_tracker_search_container_get_type ())
#define RYGEL_TRACKER_SEARCH_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainer))
#define RYGEL_TRACKER_SEARCH_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainerClass))
#define RYGEL_IS_TRACKER_SEARCH_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER))
#define RYGEL_IS_TRACKER_SEARCH_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER))
#define RYGEL_TRACKER_SEARCH_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainerClass))

typedef struct _RygelTrackerSearchContainer RygelTrackerSearchContainer;
typedef struct _RygelTrackerSearchContainerClass RygelTrackerSearchContainerClass;
#define _dbus_g_connection_unref0(var) ((var == NULL) ? NULL : (var = (dbus_g_connection_unref (var), NULL)))

struct _RygelTrackerMetadataValues {
	RygelSimpleContainer parent_instance;
	RygelTrackerMetadataValuesPrivate * priv;
	DBusGProxy* metadata;
	char* key;
};

struct _RygelTrackerMetadataValuesClass {
	RygelSimpleContainerClass parent_class;
};


static gpointer rygel_tracker_metadata_values_parent_class = NULL;

GType rygel_tracker_metadata_values_get_type (void);
enum  {
	RYGEL_TRACKER_METADATA_VALUES_DUMMY_PROPERTY
};
#define RYGEL_TRACKER_METADATA_VALUES_TRACKER_SERVICE "org.freedesktop.Tracker"
#define RYGEL_TRACKER_METADATA_VALUES_METADATA_PATH "/org/freedesktop/Tracker/Metadata"
#define RYGEL_TRACKER_METADATA_VALUES_METADATA_IFACE "org.freedesktop.Tracker.Metadata"
#define RYGEL_TRACKER_METADATA_VALUES_SERVICE "Files"
#define RYGEL_TRACKER_METADATA_VALUES_QUERY_CONDITION "<rdfq:Condition>\n" "<rdfq:equals>\n" "<rdfq:Property name=\"%s\" />\n" "<rdf:String>%s</rdf:String>\n" "</rdfq:equals>\n" "</rdfq:Condition>"
static void rygel_tracker_metadata_values_create_proxies (RygelTrackerMetadataValues* self, GError** error);
static void rygel_tracker_metadata_values_on_get_unique_values_cb (RygelTrackerMetadataValues* self, char*** search_result, int search_result_length1, GError* _error_);
void _dynamic_GetUniqueValues0 (DBusGProxy* self, const char* param1, char** param2, int param2_length1, const char* param3, gboolean param4, gint param5, gint param6, gpointer param7, void* param7_target, GError** error);
RygelTrackerMetadataValues* rygel_tracker_metadata_values_new (const char* key, const char* id, RygelMediaContainer* parent, const char* title);
RygelTrackerMetadataValues* rygel_tracker_metadata_values_construct (GType object_type, const char* key, const char* id, RygelMediaContainer* parent, const char* title);
RygelTrackerSearchContainer* rygel_tracker_search_container_new (const char* id, RygelMediaContainer* parent, const char* title, const char* service, const char* query_condition, char** keywords, int keywords_length1);
RygelTrackerSearchContainer* rygel_tracker_search_container_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title, const char* service, const char* query_condition, char** keywords, int keywords_length1);
GType rygel_tracker_search_container_get_type (void);
static void rygel_tracker_metadata_values_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static int _vala_strcmp0 (const char * str1, const char * str2);



static void _rygel_tracker_metadata_values_on_get_unique_values_cb_cb (DBusGProxy* proxy, DBusGProxyCall* call, void* user_data) {
	GError* error;
	GPtrArray* search_result;
	error = NULL;
	dbus_g_proxy_end_call (proxy, call, &error, dbus_g_type_get_collection ("GPtrArray", G_TYPE_STRV), &search_result, G_TYPE_INVALID);
	rygel_tracker_metadata_values_on_get_unique_values_cb (user_data, search_result->pdata, search_result->len, error);
}


void _dynamic_GetUniqueValues0 (DBusGProxy* self, const char* param1, char** param2, int param2_length1, const char* param3, gboolean param4, gint param5, gint param6, gpointer param7, void* param7_target, GError** error) {
	dbus_g_proxy_begin_call (self, "GetUniqueValues", _rygel_tracker_metadata_values_on_get_unique_values_cb_cb, param7_target, NULL, G_TYPE_STRING, param1, G_TYPE_STRV, param2, G_TYPE_STRING, param3, G_TYPE_BOOLEAN, param4, G_TYPE_INT, param5, G_TYPE_INT, param6, G_TYPE_INVALID, G_TYPE_INVALID);
	if (*error) {
		return;
	}
}


RygelTrackerMetadataValues* rygel_tracker_metadata_values_construct (GType object_type, const char* key, const char* id, RygelMediaContainer* parent, const char* title) {
	GError * _inner_error_;
	RygelTrackerMetadataValues * self;
	char* _tmp0_;
	g_return_val_if_fail (key != NULL, NULL);
	g_return_val_if_fail (id != NULL, NULL);
	g_return_val_if_fail (parent != NULL, NULL);
	g_return_val_if_fail (title != NULL, NULL);
	_inner_error_ = NULL;
	self = (RygelTrackerMetadataValues*) rygel_simple_container_construct (object_type, id, parent, title);
	self->key = (_tmp0_ = g_strdup (key), _g_free0 (self->key), _tmp0_);
	{
		char** _tmp2_;
		gint keys_size;
		gint keys_length1;
		char** _tmp1_;
		char** keys;
		rygel_tracker_metadata_values_create_proxies (self, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch0_g_error;
			goto __finally0;
		}
		_tmp1_ = NULL;
		keys = (_tmp2_ = (_tmp1_ = g_new0 (char*, 1 + 1), _tmp1_[0] = g_strdup (self->key), _tmp1_), keys_length1 = 1, keys_size = keys_length1, _tmp2_);
		_dynamic_GetUniqueValues0 (self->metadata, RYGEL_TRACKER_METADATA_VALUES_SERVICE, keys, keys_length1, "", FALSE, 0, -1, rygel_tracker_metadata_values_on_get_unique_values_cb, self, &_inner_error_);
		if (_inner_error_ != NULL) {
			keys = (_vala_array_free (keys, keys_length1, (GDestroyNotify) g_free), NULL);
			goto __catch0_g_error;
			goto __finally0;
		}
		keys = (_vala_array_free (keys, keys_length1, (GDestroyNotify) g_free), NULL);
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
			g_critical ("rygel-tracker-metadata-values.vala:74: Failed to create to Session bus: %s\n", _error_->message);
			_g_error_free0 (_error_);
		}
	}
	__finally0:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	return self;
}


RygelTrackerMetadataValues* rygel_tracker_metadata_values_new (const char* key, const char* id, RygelMediaContainer* parent, const char* title) {
	return rygel_tracker_metadata_values_construct (RYGEL_TYPE_TRACKER_METADATA_VALUES, key, id, parent, title);
}


static void rygel_tracker_metadata_values_on_get_unique_values_cb (RygelTrackerMetadataValues* self, char*** search_result, int search_result_length1, GError* _error_) {
	g_return_if_fail (self != NULL);
	if (_error_ != NULL) {
		g_critical ("rygel-tracker-metadata-values.vala:82: error getting all values for '%s': %s", self->key, _error_->message);
		return;
	}
	{
		guint i;
		i = (guint) 0;
		{
			gboolean _tmp0_;
			_tmp0_ = TRUE;
			while (TRUE) {
				char* value;
				char* _tmp1_;
				char* _tmp2_;
				char* query_condition;
				gint _tmp3__length1;
				char** _tmp3_;
				RygelTrackerSearchContainer* _tmp4_;
				RygelTrackerSearchContainer* container;
				if (!_tmp0_) {
					i++;
				}
				_tmp0_ = FALSE;
				if (!(i < search_result_length1)) {
					break;
				}
				value = g_strdup (search_result[i][0]);
				if (_vala_strcmp0 (value, "") == 0) {
					_g_free0 (value);
					continue;
				}
				query_condition = (_tmp2_ = g_strdup_printf (RYGEL_TRACKER_METADATA_VALUES_QUERY_CONDITION, self->key, _tmp1_ = g_markup_escape_text (value, -1)), _g_free0 (_tmp1_), _tmp2_);
				container = (_tmp4_ = rygel_tracker_search_container_new (value, (RygelMediaContainer*) self, value, RYGEL_TRACKER_METADATA_VALUES_SERVICE, query_condition, (_tmp3_ = g_new0 (char*, 0 + 1), _tmp3__length1 = 0, _tmp3_), 0), _tmp3_ = (_vala_array_free (_tmp3_, _tmp3__length1, (GDestroyNotify) g_free), NULL), _tmp4_);
				rygel_simple_container_add_child ((RygelSimpleContainer*) self, (RygelMediaObject*) container);
				_g_free0 (value);
				_g_free0 (query_condition);
				_g_object_unref0 (container);
			}
		}
	}
	rygel_media_container_updated ((RygelMediaContainer*) self);
}


static void rygel_tracker_metadata_values_create_proxies (RygelTrackerMetadataValues* self, GError** error) {
	GError * _inner_error_;
	DBusGConnection* connection;
	DBusGProxy* _tmp0_;
	g_return_if_fail (self != NULL);
	_inner_error_ = NULL;
	connection = dbus_g_bus_get (DBUS_BUS_SESSION, &_inner_error_);
	if (_inner_error_ != NULL) {
		if (_inner_error_->domain == DBUS_GERROR) {
			g_propagate_error (error, _inner_error_);
			return;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	self->metadata = (_tmp0_ = dbus_g_proxy_new_for_name (connection, RYGEL_TRACKER_METADATA_VALUES_TRACKER_SERVICE, RYGEL_TRACKER_METADATA_VALUES_METADATA_PATH, RYGEL_TRACKER_METADATA_VALUES_METADATA_IFACE), _g_object_unref0 (self->metadata), _tmp0_);
	_dbus_g_connection_unref0 (connection);
}


static void rygel_tracker_metadata_values_class_init (RygelTrackerMetadataValuesClass * klass) {
	rygel_tracker_metadata_values_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = rygel_tracker_metadata_values_finalize;
}


static void rygel_tracker_metadata_values_instance_init (RygelTrackerMetadataValues * self) {
}


static void rygel_tracker_metadata_values_finalize (GObject* obj) {
	RygelTrackerMetadataValues * self;
	self = RYGEL_TRACKER_METADATA_VALUES (obj);
	_g_object_unref0 (self->metadata);
	_g_free0 (self->key);
	G_OBJECT_CLASS (rygel_tracker_metadata_values_parent_class)->finalize (obj);
}


GType rygel_tracker_metadata_values_get_type (void) {
	static GType rygel_tracker_metadata_values_type_id = 0;
	if (rygel_tracker_metadata_values_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelTrackerMetadataValuesClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_tracker_metadata_values_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelTrackerMetadataValues), 0, (GInstanceInitFunc) rygel_tracker_metadata_values_instance_init, NULL };
		rygel_tracker_metadata_values_type_id = g_type_register_static (RYGEL_TYPE_SIMPLE_CONTAINER, "RygelTrackerMetadataValues", &g_define_type_info, 0);
	}
	return rygel_tracker_metadata_values_type_id;
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


static int _vala_strcmp0 (const char * str1, const char * str2) {
	if (str1 == NULL) {
		return -(str1 != str2);
	}
	if (str2 == NULL) {
		return str1 != str2;
	}
	return strcmp (str1, str2);
}




