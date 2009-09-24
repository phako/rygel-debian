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


#define RYGEL_TYPE_TRACKER_KEYWORDS (rygel_tracker_keywords_get_type ())
#define RYGEL_TRACKER_KEYWORDS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_KEYWORDS, RygelTrackerKeywords))
#define RYGEL_TRACKER_KEYWORDS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_KEYWORDS, RygelTrackerKeywordsClass))
#define RYGEL_IS_TRACKER_KEYWORDS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_KEYWORDS))
#define RYGEL_IS_TRACKER_KEYWORDS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_KEYWORDS))
#define RYGEL_TRACKER_KEYWORDS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_KEYWORDS, RygelTrackerKeywordsClass))

typedef struct _RygelTrackerKeywords RygelTrackerKeywords;
typedef struct _RygelTrackerKeywordsClass RygelTrackerKeywordsClass;
typedef struct _RygelTrackerKeywordsPrivate RygelTrackerKeywordsPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

#define RYGEL_TYPE_TRACKER_SEARCH_CONTAINER (rygel_tracker_search_container_get_type ())
#define RYGEL_TRACKER_SEARCH_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainer))
#define RYGEL_TRACKER_SEARCH_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainerClass))
#define RYGEL_IS_TRACKER_SEARCH_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER))
#define RYGEL_IS_TRACKER_SEARCH_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER))
#define RYGEL_TRACKER_SEARCH_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainerClass))

typedef struct _RygelTrackerSearchContainer RygelTrackerSearchContainer;
typedef struct _RygelTrackerSearchContainerClass RygelTrackerSearchContainerClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _dbus_g_connection_unref0(var) ((var == NULL) ? NULL : (var = (dbus_g_connection_unref (var), NULL)))

struct _RygelTrackerKeywords {
	RygelSimpleContainer parent_instance;
	RygelTrackerKeywordsPrivate * priv;
	DBusGProxy* keywords;
};

struct _RygelTrackerKeywordsClass {
	RygelSimpleContainerClass parent_class;
};


static gpointer rygel_tracker_keywords_parent_class = NULL;

GType rygel_tracker_keywords_get_type (void);
enum  {
	RYGEL_TRACKER_KEYWORDS_DUMMY_PROPERTY
};
#define RYGEL_TRACKER_KEYWORDS_TRACKER_SERVICE "org.freedesktop.Tracker"
#define RYGEL_TRACKER_KEYWORDS_KEYWORDS_PATH "/org/freedesktop/Tracker/Keywords"
#define RYGEL_TRACKER_KEYWORDS_KEYWORDS_IFACE "org.freedesktop.Tracker.Keywords"
#define RYGEL_TRACKER_KEYWORDS_SERVICE "Files"
#define RYGEL_TRACKER_KEYWORDS_TITLE "Tags"
static void rygel_tracker_keywords_create_proxies (RygelTrackerKeywords* self, GError** error);
static void rygel_tracker_keywords_on_get_keywords_cb (RygelTrackerKeywords* self, char*** keywords_list, int keywords_list_length1, GError* _error_);
void _dynamic_GetList1 (DBusGProxy* self, const char* param1, gpointer param2, void* param2_target, GError** error);
RygelTrackerKeywords* rygel_tracker_keywords_new (const char* id, RygelMediaContainer* parent);
RygelTrackerKeywords* rygel_tracker_keywords_construct (GType object_type, const char* id, RygelMediaContainer* parent);
RygelTrackerSearchContainer* rygel_tracker_search_container_new (const char* id, RygelMediaContainer* parent, const char* title, const char* service, const char* query_condition, char** keywords, int keywords_length1);
RygelTrackerSearchContainer* rygel_tracker_search_container_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title, const char* service, const char* query_condition, char** keywords, int keywords_length1);
GType rygel_tracker_search_container_get_type (void);
static void rygel_tracker_keywords_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);



static void _rygel_tracker_keywords_on_get_keywords_cb_cb (DBusGProxy* proxy, DBusGProxyCall* call, void* user_data) {
	GError* error;
	GPtrArray* keywords_list;
	error = NULL;
	dbus_g_proxy_end_call (proxy, call, &error, dbus_g_type_get_collection ("GPtrArray", G_TYPE_STRV), &keywords_list, G_TYPE_INVALID);
	rygel_tracker_keywords_on_get_keywords_cb (user_data, keywords_list->pdata, keywords_list->len, error);
}


void _dynamic_GetList1 (DBusGProxy* self, const char* param1, gpointer param2, void* param2_target, GError** error) {
	dbus_g_proxy_begin_call (self, "GetList", _rygel_tracker_keywords_on_get_keywords_cb_cb, param2_target, NULL, G_TYPE_STRING, param1, G_TYPE_INVALID, G_TYPE_INVALID);
	if (*error) {
		return;
	}
}


RygelTrackerKeywords* rygel_tracker_keywords_construct (GType object_type, const char* id, RygelMediaContainer* parent) {
	GError * _inner_error_;
	RygelTrackerKeywords * self;
	g_return_val_if_fail (id != NULL, NULL);
	g_return_val_if_fail (parent != NULL, NULL);
	_inner_error_ = NULL;
	self = (RygelTrackerKeywords*) rygel_simple_container_construct (object_type, id, parent, RYGEL_TRACKER_KEYWORDS_TITLE);
	{
		rygel_tracker_keywords_create_proxies (self, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch1_g_error;
			goto __finally1;
		}
		_dynamic_GetList1 (self->keywords, RYGEL_TRACKER_KEYWORDS_SERVICE, rygel_tracker_keywords_on_get_keywords_cb, self, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch1_g_error;
			goto __finally1;
		}
	}
	goto __finally1;
	__catch1_g_error:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
			g_critical ("rygel-tracker-keywords.vala:54: Failed to create to Session bus: %s\n", _error_->message);
			_g_error_free0 (_error_);
		}
	}
	__finally1:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	return self;
}


RygelTrackerKeywords* rygel_tracker_keywords_new (const char* id, RygelMediaContainer* parent) {
	return rygel_tracker_keywords_construct (RYGEL_TYPE_TRACKER_KEYWORDS, id, parent);
}


static void rygel_tracker_keywords_on_get_keywords_cb (RygelTrackerKeywords* self, char*** keywords_list, int keywords_list_length1, GError* _error_) {
	g_return_if_fail (self != NULL);
	if (_error_ != NULL) {
		g_critical ("rygel-tracker-keywords.vala:62: error getting all keywords: %s", _error_->message);
		return;
	}
	{
		guint i;
		i = (guint) 0;
		{
			gboolean _tmp0_;
			_tmp0_ = TRUE;
			while (TRUE) {
				char* keyword;
				char** _tmp2_;
				gint keywords_size;
				gint keywords_length1;
				char** _tmp1_;
				char** keywords;
				RygelTrackerSearchContainer* container;
				if (!_tmp0_) {
					i++;
				}
				_tmp0_ = FALSE;
				if (!(i < keywords_list_length1)) {
					break;
				}
				keyword = g_strdup (keywords_list[i][0]);
				_tmp1_ = NULL;
				keywords = (_tmp2_ = (_tmp1_ = g_new0 (char*, 1 + 1), _tmp1_[0] = g_strdup (keyword), _tmp1_), keywords_length1 = 1, keywords_size = keywords_length1, _tmp2_);
				container = rygel_tracker_search_container_new (keyword, (RygelMediaContainer*) self, keyword, RYGEL_TRACKER_KEYWORDS_SERVICE, "", keywords, keywords_length1);
				rygel_simple_container_add_child ((RygelSimpleContainer*) self, (RygelMediaObject*) container);
				_g_free0 (keyword);
				keywords = (_vala_array_free (keywords, keywords_length1, (GDestroyNotify) g_free), NULL);
				_g_object_unref0 (container);
			}
		}
	}
	rygel_media_container_updated ((RygelMediaContainer*) self);
}


static void rygel_tracker_keywords_create_proxies (RygelTrackerKeywords* self, GError** error) {
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
	self->keywords = (_tmp0_ = dbus_g_proxy_new_for_name (connection, RYGEL_TRACKER_KEYWORDS_TRACKER_SERVICE, RYGEL_TRACKER_KEYWORDS_KEYWORDS_PATH, RYGEL_TRACKER_KEYWORDS_KEYWORDS_IFACE), _g_object_unref0 (self->keywords), _tmp0_);
	_dbus_g_connection_unref0 (connection);
}


static void rygel_tracker_keywords_class_init (RygelTrackerKeywordsClass * klass) {
	rygel_tracker_keywords_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = rygel_tracker_keywords_finalize;
}


static void rygel_tracker_keywords_instance_init (RygelTrackerKeywords * self) {
}


static void rygel_tracker_keywords_finalize (GObject* obj) {
	RygelTrackerKeywords * self;
	self = RYGEL_TRACKER_KEYWORDS (obj);
	_g_object_unref0 (self->keywords);
	G_OBJECT_CLASS (rygel_tracker_keywords_parent_class)->finalize (obj);
}


GType rygel_tracker_keywords_get_type (void) {
	static GType rygel_tracker_keywords_type_id = 0;
	if (rygel_tracker_keywords_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelTrackerKeywordsClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_tracker_keywords_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelTrackerKeywords), 0, (GInstanceInitFunc) rygel_tracker_keywords_instance_init, NULL };
		rygel_tracker_keywords_type_id = g_type_register_static (RYGEL_TYPE_SIMPLE_CONTAINER, "RygelTrackerKeywords", &g_define_type_info, 0);
	}
	return rygel_tracker_keywords_type_id;
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




