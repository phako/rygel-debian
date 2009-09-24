/*
 * Copyright (C) 2009 Jens Georg <mail@jensge.org>.
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
#include <gee.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>


#define RYGEL_TYPE_MEDIA_EXPORT_DYNAMIC_CONTAINER (rygel_media_export_dynamic_container_get_type ())
#define RYGEL_MEDIA_EXPORT_DYNAMIC_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_EXPORT_DYNAMIC_CONTAINER, RygelMediaExportDynamicContainer))
#define RYGEL_MEDIA_EXPORT_DYNAMIC_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_EXPORT_DYNAMIC_CONTAINER, RygelMediaExportDynamicContainerClass))
#define RYGEL_IS_MEDIA_EXPORT_DYNAMIC_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_EXPORT_DYNAMIC_CONTAINER))
#define RYGEL_IS_MEDIA_EXPORT_DYNAMIC_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_EXPORT_DYNAMIC_CONTAINER))
#define RYGEL_MEDIA_EXPORT_DYNAMIC_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_EXPORT_DYNAMIC_CONTAINER, RygelMediaExportDynamicContainerClass))

typedef struct _RygelMediaExportDynamicContainer RygelMediaExportDynamicContainer;
typedef struct _RygelMediaExportDynamicContainerClass RygelMediaExportDynamicContainerClass;
typedef struct _RygelMediaExportDynamicContainerPrivate RygelMediaExportDynamicContainerPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define RYGEL_TYPE_MEDIA_EXPORT_ROOT_CONTAINER (rygel_media_export_root_container_get_type ())
#define RYGEL_MEDIA_EXPORT_ROOT_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_EXPORT_ROOT_CONTAINER, RygelMediaExportRootContainer))
#define RYGEL_MEDIA_EXPORT_ROOT_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_EXPORT_ROOT_CONTAINER, RygelMediaExportRootContainerClass))
#define RYGEL_IS_MEDIA_EXPORT_ROOT_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_EXPORT_ROOT_CONTAINER))
#define RYGEL_IS_MEDIA_EXPORT_ROOT_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_EXPORT_ROOT_CONTAINER))
#define RYGEL_MEDIA_EXPORT_ROOT_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_EXPORT_ROOT_CONTAINER, RygelMediaExportRootContainerClass))

typedef struct _RygelMediaExportRootContainer RygelMediaExportRootContainer;
typedef struct _RygelMediaExportRootContainerClass RygelMediaExportRootContainerClass;
typedef struct _RygelMediaExportRootContainerPrivate RygelMediaExportRootContainerPrivate;

#define RYGEL_TYPE_MEDIA_EXPORT_HARVESTER (rygel_media_export_harvester_get_type ())
#define RYGEL_MEDIA_EXPORT_HARVESTER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_EXPORT_HARVESTER, RygelMediaExportHarvester))
#define RYGEL_MEDIA_EXPORT_HARVESTER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_EXPORT_HARVESTER, RygelMediaExportHarvesterClass))
#define RYGEL_IS_MEDIA_EXPORT_HARVESTER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_EXPORT_HARVESTER))
#define RYGEL_IS_MEDIA_EXPORT_HARVESTER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_EXPORT_HARVESTER))
#define RYGEL_MEDIA_EXPORT_HARVESTER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_EXPORT_HARVESTER, RygelMediaExportHarvesterClass))

typedef struct _RygelMediaExportHarvester RygelMediaExportHarvester;
typedef struct _RygelMediaExportHarvesterClass RygelMediaExportHarvesterClass;

#define RYGEL_TYPE_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR (rygel_media_export_recursive_file_monitor_get_type ())
#define RYGEL_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR, RygelMediaExportRecursiveFileMonitor))
#define RYGEL_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR, RygelMediaExportRecursiveFileMonitorClass))
#define RYGEL_IS_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR))
#define RYGEL_IS_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR))
#define RYGEL_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR, RygelMediaExportRecursiveFileMonitorClass))

typedef struct _RygelMediaExportRecursiveFileMonitor RygelMediaExportRecursiveFileMonitor;
typedef struct _RygelMediaExportRecursiveFileMonitorClass RygelMediaExportRecursiveFileMonitorClass;

#define RYGEL_TYPE_MEDIA_EXPORT_DBUS_SERVICE (rygel_media_export_dbus_service_get_type ())
#define RYGEL_MEDIA_EXPORT_DBUS_SERVICE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_EXPORT_DBUS_SERVICE, RygelMediaExportDBusService))
#define RYGEL_MEDIA_EXPORT_DBUS_SERVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_EXPORT_DBUS_SERVICE, RygelMediaExportDBusServiceClass))
#define RYGEL_IS_MEDIA_EXPORT_DBUS_SERVICE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_EXPORT_DBUS_SERVICE))
#define RYGEL_IS_MEDIA_EXPORT_DBUS_SERVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_EXPORT_DBUS_SERVICE))
#define RYGEL_MEDIA_EXPORT_DBUS_SERVICE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_EXPORT_DBUS_SERVICE, RygelMediaExportDBusServiceClass))

typedef struct _RygelMediaExportDBusService RygelMediaExportDBusService;
typedef struct _RygelMediaExportDBusServiceClass RygelMediaExportDBusServiceClass;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

#define RYGEL_TYPE_NULL_CONTAINER (rygel_null_container_get_type ())
#define RYGEL_NULL_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_NULL_CONTAINER, RygelNullContainer))
#define RYGEL_NULL_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_NULL_CONTAINER, RygelNullContainerClass))
#define RYGEL_IS_NULL_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_NULL_CONTAINER))
#define RYGEL_IS_NULL_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_NULL_CONTAINER))
#define RYGEL_NULL_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_NULL_CONTAINER, RygelNullContainerClass))

typedef struct _RygelNullContainer RygelNullContainer;
typedef struct _RygelNullContainerClass RygelNullContainerClass;

struct _RygelMediaExportDynamicContainer {
	RygelMediaDBContainer parent_instance;
	RygelMediaExportDynamicContainerPrivate * priv;
};

struct _RygelMediaExportDynamicContainerClass {
	RygelMediaDBContainerClass parent_class;
};

struct _RygelMediaExportRootContainer {
	RygelMediaDBContainer parent_instance;
	RygelMediaExportRootContainerPrivate * priv;
};

struct _RygelMediaExportRootContainerClass {
	RygelMediaDBContainerClass parent_class;
};

struct _RygelMediaExportRootContainerPrivate {
	RygelMetadataExtractor* extractor;
	GeeHashMap* harvester;
	RygelMediaExportRecursiveFileMonitor* monitor;
	RygelMediaExportDBusService* service;
	RygelMediaExportDynamicContainer* dynamic_elements;
};


static gpointer rygel_media_export_dynamic_container_parent_class = NULL;
static RygelMediaContainer* rygel_media_export_root_container_instance;
static RygelMediaContainer* rygel_media_export_root_container_instance = NULL;
static gpointer rygel_media_export_root_container_parent_class = NULL;

GType rygel_media_export_dynamic_container_get_type (void);
enum  {
	RYGEL_MEDIA_EXPORT_DYNAMIC_CONTAINER_DUMMY_PROPERTY
};
#define RYGEL_MEDIA_EXPORT_DYNAMIC_CONTAINER_ID "DynamicContainerId"
RygelMediaExportDynamicContainer* rygel_media_export_dynamic_container_new (RygelMediaDB* media_db, RygelMediaContainer* parent);
RygelMediaExportDynamicContainer* rygel_media_export_dynamic_container_construct (GType object_type, RygelMediaDB* media_db, RygelMediaContainer* parent);
GeeList* rygel_media_export_dynamic_container_get_uris (RygelMediaExportDynamicContainer* self);
GType rygel_media_export_root_container_get_type (void);
GType rygel_media_export_harvester_get_type (void);
GType rygel_media_export_recursive_file_monitor_get_type (void);
GType rygel_media_export_dbus_service_get_type (void);
#define RYGEL_MEDIA_EXPORT_ROOT_CONTAINER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_MEDIA_EXPORT_ROOT_CONTAINER, RygelMediaExportRootContainerPrivate))
enum  {
	RYGEL_MEDIA_EXPORT_ROOT_CONTAINER_DUMMY_PROPERTY
};
static GeeArrayList* rygel_media_export_root_container_get_uris (RygelMediaExportRootContainer* self);
static RygelMediaExportRootContainer* rygel_media_export_root_container_new (RygelMediaDB* db);
static RygelMediaExportRootContainer* rygel_media_export_root_container_construct (GType object_type, RygelMediaDB* db);
RygelNullContainer* rygel_null_container_new (void);
RygelNullContainer* rygel_null_container_construct (GType object_type);
GType rygel_null_container_get_type (void);
RygelMediaContainer* rygel_media_export_root_container_get_instance (void);
static void rygel_media_export_root_container_harvest (RygelMediaExportRootContainer* self, GFile* file, RygelMediaContainer* parent);
void rygel_media_export_root_container_add_uri (RygelMediaExportRootContainer* self, const char* uri);
void rygel_media_export_root_container_remove_uri (RygelMediaExportRootContainer* self, const char* uri);
static void _vala_array_add1 (char*** array, int* length, int* size, char* value);
char** rygel_media_export_root_container_get_dynamic_uris (RygelMediaExportRootContainer* self, int* result_length1);
RygelMediaExportRecursiveFileMonitor* rygel_media_export_recursive_file_monitor_new (GCancellable* cancellable);
RygelMediaExportRecursiveFileMonitor* rygel_media_export_recursive_file_monitor_construct (GType object_type, GCancellable* cancellable);
static void rygel_media_export_root_container_on_file_changed (RygelMediaExportRootContainer* self, GFile* file, GFile* other, GFileMonitorEvent event);
static void _rygel_media_export_root_container_on_file_changed_rygel_media_export_recursive_file_monitor_changed (RygelMediaExportRecursiveFileMonitor* _sender, GFile* file, GFile* other_file, GFileMonitorEvent event_type, gpointer self);
RygelMediaExportDBusService* rygel_media_export_dbus_service_new (RygelMediaExportRootContainer* root_container, GError** error);
RygelMediaExportDBusService* rygel_media_export_dbus_service_construct (GType object_type, RygelMediaExportRootContainer* root_container, GError** error);
static void rygel_media_export_root_container_on_file_harvested (RygelMediaExportRootContainer* self, GFile* file);
RygelMediaExportHarvester* rygel_media_export_harvester_new (RygelMediaContainer* parent, RygelMediaDB* media_db, RygelMetadataExtractor* extractor, RygelMediaExportRecursiveFileMonitor* monitor);
RygelMediaExportHarvester* rygel_media_export_harvester_construct (GType object_type, RygelMediaContainer* parent, RygelMediaDB* media_db, RygelMetadataExtractor* extractor, RygelMediaExportRecursiveFileMonitor* monitor);
static void _rygel_media_export_root_container_on_file_harvested_rygel_media_export_harvester_harvested (RygelMediaExportHarvester* _sender, GFile* file, gpointer self);
void rygel_media_export_harvester_harvest (RygelMediaExportHarvester* self, GFile* file);
static void rygel_media_export_root_container_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static int _vala_strcmp0 (const char * str1, const char * str2);



RygelMediaExportDynamicContainer* rygel_media_export_dynamic_container_construct (GType object_type, RygelMediaDB* media_db, RygelMediaContainer* parent) {
	RygelMediaExportDynamicContainer * self;
	g_return_val_if_fail (media_db != NULL, NULL);
	g_return_val_if_fail (parent != NULL, NULL);
	self = (RygelMediaExportDynamicContainer*) rygel_media_db_container_construct (object_type, media_db, RYGEL_MEDIA_EXPORT_DYNAMIC_CONTAINER_ID, "Dynamic");
	((RygelMediaObject*) self)->parent = parent;
	return self;
}


RygelMediaExportDynamicContainer* rygel_media_export_dynamic_container_new (RygelMediaDB* media_db, RygelMediaContainer* parent) {
	return rygel_media_export_dynamic_container_construct (RYGEL_TYPE_MEDIA_EXPORT_DYNAMIC_CONTAINER, media_db, parent);
}


GeeList* rygel_media_export_dynamic_container_get_uris (RygelMediaExportDynamicContainer* self) {
	GeeList* result;
	GeeArrayList* _result_;
	GeeArrayList* children;
	g_return_val_if_fail (self != NULL, NULL);
	_result_ = gee_array_list_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, g_direct_equal);
	children = rygel_media_db_get_children (((RygelMediaDBContainer*) self)->media_db, ((RygelMediaObject*) self)->id, (glong) (-1), (glong) (-1));
	if (children != NULL) {
		{
			GeeIterator* _child_it;
			_child_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) children);
			while (TRUE) {
				RygelMediaObject* child;
				if (!gee_iterator_next (_child_it)) {
					break;
				}
				child = (RygelMediaObject*) gee_iterator_get (_child_it);
				gee_abstract_collection_add_all ((GeeAbstractCollection*) _result_, (GeeCollection*) child->uris);
				_g_object_unref0 (child);
			}
			_g_object_unref0 (_child_it);
		}
	}
	result = (GeeList*) _result_;
	_g_object_unref0 (children);
	return result;
}


static void rygel_media_export_dynamic_container_class_init (RygelMediaExportDynamicContainerClass * klass) {
	rygel_media_export_dynamic_container_parent_class = g_type_class_peek_parent (klass);
}


static void rygel_media_export_dynamic_container_instance_init (RygelMediaExportDynamicContainer * self) {
}


GType rygel_media_export_dynamic_container_get_type (void) {
	static GType rygel_media_export_dynamic_container_type_id = 0;
	if (rygel_media_export_dynamic_container_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediaExportDynamicContainerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_media_export_dynamic_container_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediaExportDynamicContainer), 0, (GInstanceInitFunc) rygel_media_export_dynamic_container_instance_init, NULL };
		rygel_media_export_dynamic_container_type_id = g_type_register_static (RYGEL_TYPE_MEDIA_DB_CONTAINER, "RygelMediaExportDynamicContainer", &g_define_type_info, 0);
	}
	return rygel_media_export_dynamic_container_type_id;
}


static GeeArrayList* rygel_media_export_root_container_get_uris (RygelMediaExportRootContainer* self) {
	GeeArrayList* result;
	GError * _inner_error_;
	GeeArrayList* uris;
	RygelMetaConfig* config;
	GeeList* dbus_uris;
	g_return_val_if_fail (self != NULL, NULL);
	_inner_error_ = NULL;
	uris = NULL;
	config = rygel_meta_config_get_default ();
	{
		GeeArrayList* _tmp0_;
		GeeArrayList* _tmp1_;
		_tmp0_ = rygel_configuration_get_string_list ((RygelConfiguration*) config, "MediaExport", "uris", &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch0_g_error;
			goto __finally0;
		}
		uris = (_tmp1_ = _tmp0_, _g_object_unref0 (uris), _tmp1_);
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
			GeeArrayList* _tmp2_;
			uris = (_tmp2_ = gee_array_list_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, g_direct_equal), _g_object_unref0 (uris), _tmp2_);
			_g_error_free0 (_error_);
		}
	}
	__finally0:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (uris);
		_g_object_unref0 (config);
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	if (gee_collection_get_size ((GeeCollection*) uris) == 0) {
		char* uri;
		char* _tmp3_;
		char* _tmp4_;
		g_debug ("rygel-media-export-root-container.vala:71: Nothing configured, using XDG special directories");
		uri = g_strdup (g_get_user_special_dir (G_USER_DIRECTORY_MUSIC));
		if (uri != NULL) {
			gee_abstract_collection_add ((GeeAbstractCollection*) uris, uri);
		}
		uri = (_tmp3_ = g_strdup (g_get_user_special_dir (G_USER_DIRECTORY_PICTURES)), _g_free0 (uri), _tmp3_);
		if (uri != NULL) {
			gee_abstract_collection_add ((GeeAbstractCollection*) uris, uri);
		}
		uri = (_tmp4_ = g_strdup (g_get_user_special_dir (G_USER_DIRECTORY_VIDEOS)), _g_free0 (uri), _tmp4_);
		if (uri != NULL) {
			gee_abstract_collection_add ((GeeAbstractCollection*) uris, uri);
		}
		_g_free0 (uri);
	}
	dbus_uris = rygel_media_export_dynamic_container_get_uris (self->priv->dynamic_elements);
	if (dbus_uris != NULL) {
		gee_abstract_collection_add_all ((GeeAbstractCollection*) uris, (GeeCollection*) dbus_uris);
	}
	result = uris;
	_g_object_unref0 (config);
	_g_object_unref0 (dbus_uris);
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


RygelMediaContainer* rygel_media_export_root_container_get_instance (void) {
	RygelMediaContainer* result;
	GError * _inner_error_;
	_inner_error_ = NULL;
	if (rygel_media_export_root_container_instance == NULL) {
		{
			RygelMediaDB* db;
			RygelMediaContainer* _tmp0_;
			db = rygel_media_db_create ("media-export", &_inner_error_);
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
					goto __catch1_rygel_media_db_error;
				}
				goto __finally1;
			}
			rygel_media_export_root_container_instance = (_tmp0_ = (RygelMediaContainer*) rygel_media_export_root_container_new (db), _g_object_unref0 (rygel_media_export_root_container_instance), _tmp0_);
			_g_object_unref0 (db);
		}
		goto __finally1;
		__catch1_rygel_media_db_error:
		{
			GError * err;
			err = _inner_error_;
			_inner_error_ = NULL;
			{
				RygelMediaContainer* _tmp1_;
				g_warning ("rygel-media-export-root-container.vala:100: Failed to create instance of database");
				rygel_media_export_root_container_instance = (_tmp1_ = (RygelMediaContainer*) rygel_null_container_new (), _g_object_unref0 (rygel_media_export_root_container_instance), _tmp1_);
				_g_error_free0 (err);
			}
		}
		__finally1:
		if (_inner_error_ != NULL) {
			g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
	result = _g_object_ref0 (rygel_media_export_root_container_instance);
	return result;
}


void rygel_media_export_root_container_add_uri (RygelMediaExportRootContainer* self, const char* uri) {
	GFile* file;
	g_return_if_fail (self != NULL);
	g_return_if_fail (uri != NULL);
	file = g_file_new_for_commandline_arg (uri);
	rygel_media_export_root_container_harvest (self, file, (RygelMediaContainer*) self->priv->dynamic_elements);
	_g_object_unref0 (file);
}


void rygel_media_export_root_container_remove_uri (RygelMediaExportRootContainer* self, const char* uri) {
	GError * _inner_error_;
	GFile* file;
	char* _tmp0_;
	char* _tmp1_;
	char* id;
	g_return_if_fail (self != NULL);
	g_return_if_fail (uri != NULL);
	_inner_error_ = NULL;
	file = g_file_new_for_commandline_arg (uri);
	id = (_tmp1_ = g_compute_checksum_for_string (G_CHECKSUM_MD5, _tmp0_ = g_file_get_uri (file), -1), _g_free0 (_tmp0_), _tmp1_);
	{
		rygel_media_db_remove_by_id (((RygelMediaDBContainer*) self)->media_db, id, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch2_g_error;
			goto __finally2;
		}
	}
	goto __finally2;
	__catch2_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			g_warning ("rygel-media-export-root-container.vala:121: Failed to remove uri: %s", e->message);
			_g_error_free0 (e);
		}
	}
	__finally2:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (file);
		_g_free0 (id);
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return;
	}
	_g_object_unref0 (file);
	_g_free0 (id);
}


static void _vala_array_add1 (char*** array, int* length, int* size, char* value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (char*, *array, (*size) + 1);
	}
	(*array)[(*length)++] = value;
	(*array)[*length] = NULL;
}


char** rygel_media_export_root_container_get_dynamic_uris (RygelMediaExportRootContainer* self, int* result_length1) {
	char** result;
	char** _tmp0_;
	gint _result__size;
	gint _result__length1;
	char** _result_;
	GeeList* dynamic_uris;
	char** _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	_result_ = (_tmp0_ = g_new0 (char*, 0 + 1), _result__length1 = 0, _result__size = _result__length1, _tmp0_);
	dynamic_uris = rygel_media_export_dynamic_container_get_uris (self->priv->dynamic_elements);
	{
		GeeIterator* _uri_it;
		_uri_it = gee_iterable_iterator ((GeeIterable*) dynamic_uris);
		while (TRUE) {
			char* uri;
			if (!gee_iterator_next (_uri_it)) {
				break;
			}
			uri = (char*) gee_iterator_get (_uri_it);
			_vala_array_add1 (&_result_, &_result__length1, &_result__size, g_strdup (uri));
			_g_free0 (uri);
		}
		_g_object_unref0 (_uri_it);
	}
	result = (_tmp1_ = _result_, *result_length1 = _result__length1, _tmp1_);
	_g_object_unref0 (dynamic_uris);
	return result;
	_result_ = (_vala_array_free (_result_, _result__length1, (GDestroyNotify) g_free), NULL);
	_g_object_unref0 (dynamic_uris);
}


static void _rygel_media_export_root_container_on_file_changed_rygel_media_export_recursive_file_monitor_changed (RygelMediaExportRecursiveFileMonitor* _sender, GFile* file, GFile* other_file, GFileMonitorEvent event_type, gpointer self) {
	rygel_media_export_root_container_on_file_changed (self, file, other_file, event_type);
}


static RygelMediaExportRootContainer* rygel_media_export_root_container_construct (GType object_type, RygelMediaDB* db) {
	GError * _inner_error_;
	RygelMediaExportRootContainer * self;
	RygelMetadataExtractor* _tmp0_;
	GeeHashMap* _tmp1_;
	RygelMediaExportRecursiveFileMonitor* _tmp2_;
	RygelMediaExportDBusService* _tmp3_;
	RygelMediaExportDBusService* _tmp4_;
	RygelMediaExportDynamicContainer* _tmp5_;
	gint64 timestamp;
	gboolean _tmp6_;
	gboolean _tmp7_;
	GeeArrayList* ids;
	GeeArrayList* uris;
	g_return_val_if_fail (db != NULL, NULL);
	_inner_error_ = NULL;
	self = (RygelMediaExportRootContainer*) rygel_media_db_container_construct (object_type, db, "0", "MediaExportRoot");
	self->priv->extractor = (_tmp0_ = rygel_metadata_extractor_new (), _g_object_unref0 (self->priv->extractor), _tmp0_);
	self->priv->harvester = (_tmp1_ = gee_hash_map_new (G_TYPE_FILE, (GBoxedCopyFunc) g_object_ref, g_object_unref, RYGEL_TYPE_MEDIA_EXPORT_HARVESTER, (GBoxedCopyFunc) g_object_ref, g_object_unref, g_file_hash, g_file_equal, g_direct_equal), _g_object_unref0 (self->priv->harvester), _tmp1_);
	self->priv->monitor = (_tmp2_ = rygel_media_export_recursive_file_monitor_new (NULL), _g_object_unref0 (self->priv->monitor), _tmp2_);
	g_signal_connect_object (self->priv->monitor, "changed", (GCallback) _rygel_media_export_root_container_on_file_changed_rygel_media_export_recursive_file_monitor_changed, self, 0);
	_tmp3_ = rygel_media_export_dbus_service_new (self, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	self->priv->service = (_tmp4_ = _tmp3_, _g_object_unref0 (self->priv->service), _tmp4_);
	self->priv->dynamic_elements = (_tmp5_ = rygel_media_export_dynamic_container_new (db, (RygelMediaContainer*) self), _g_object_unref0 (self->priv->dynamic_elements), _tmp5_);
	timestamp = 0LL;
	_tmp6_ = rygel_media_db_exists (((RygelMediaDBContainer*) self)->media_db, "0", &timestamp, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	if (!_tmp6_) {
		{
			rygel_media_db_save_object (((RygelMediaDBContainer*) self)->media_db, (RygelMediaObject*) self, &_inner_error_);
			if (_inner_error_ != NULL) {
				goto __catch3_g_error;
				goto __finally3;
			}
		}
		goto __finally3;
		__catch3_g_error:
		{
			GError * _error_;
			_error_ = _inner_error_;
			_inner_error_ = NULL;
			{
				_g_error_free0 (_error_);
			}
		}
		__finally3:
		if (_inner_error_ != NULL) {
			g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
	_tmp7_ = rygel_media_db_exists (((RygelMediaDBContainer*) self)->media_db, "DynamicContainerId", &timestamp, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	if (!_tmp7_) {
		{
			rygel_media_db_save_object (((RygelMediaDBContainer*) self)->media_db, (RygelMediaObject*) self->priv->dynamic_elements, &_inner_error_);
			if (_inner_error_ != NULL) {
				goto __catch4_g_error;
				goto __finally4;
			}
		}
		goto __finally4;
		__catch4_g_error:
		{
			GError * _error_;
			_error_ = _inner_error_;
			_inner_error_ = NULL;
			{
				_g_error_free0 (_error_);
			}
		}
		__finally4:
		if (_inner_error_ != NULL) {
			g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
	ids = NULL;
	{
		GeeArrayList* _tmp8_;
		GeeArrayList* _tmp9_;
		_tmp8_ = rygel_media_db_get_child_ids (((RygelMediaDBContainer*) self)->media_db, "0", &_inner_error_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
				goto __catch5_rygel_media_db_error;
			}
			goto __finally5;
		}
		ids = (_tmp9_ = _tmp8_, _g_object_unref0 (ids), _tmp9_);
	}
	goto __finally5;
	__catch5_rygel_media_db_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			GeeArrayList* _tmp10_;
			ids = (_tmp10_ = gee_array_list_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, g_direct_equal), _g_object_unref0 (ids), _tmp10_);
			_g_error_free0 (e);
		}
	}
	__finally5:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (ids);
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	uris = rygel_media_export_root_container_get_uris (self);
	{
		GeeIterator* _uri_it;
		_uri_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) uris);
		while (TRUE) {
			char* uri;
			GFile* file;
			if (!gee_iterator_next (_uri_it)) {
				break;
			}
			uri = (char*) gee_iterator_get (_uri_it);
			file = g_file_new_for_commandline_arg (uri);
			if (g_file_query_exists (file, NULL)) {
				char* _tmp11_;
				char* _tmp12_;
				char* id;
				id = (_tmp12_ = g_compute_checksum_for_string (G_CHECKSUM_MD5, _tmp11_ = g_file_get_uri (file), -1), _g_free0 (_tmp11_), _tmp12_);
				gee_abstract_collection_remove ((GeeAbstractCollection*) ids, id);
				rygel_media_export_root_container_harvest (self, file, self);
				_g_free0 (id);
			}
			_g_free0 (uri);
			_g_object_unref0 (file);
		}
		_g_object_unref0 (_uri_it);
	}
	{
		GeeIterator* _id_it;
		_id_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) ids);
		while (TRUE) {
			char* id;
			if (!gee_iterator_next (_id_it)) {
				break;
			}
			id = (char*) gee_iterator_get (_id_it);
			if (_vala_strcmp0 (id, RYGEL_MEDIA_EXPORT_DYNAMIC_CONTAINER_ID) == 0) {
				_g_free0 (id);
				continue;
			}
			g_debug ("rygel-media-export-root-container.vala:194: Id %s no longer in config, deleting...", id);
			{
				rygel_media_db_remove_by_id (((RygelMediaDBContainer*) self)->media_db, id, &_inner_error_);
				if (_inner_error_ != NULL) {
					if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
						goto __catch6_rygel_media_db_error;
					}
					goto __finally6;
				}
			}
			goto __finally6;
			__catch6_rygel_media_db_error:
			{
				GError * e;
				e = _inner_error_;
				_inner_error_ = NULL;
				{
					g_warning ("rygel-media-export-root-container.vala:199: Failed to remove entry: %s", e->message);
					_g_error_free0 (e);
				}
			}
			__finally6:
			if (_inner_error_ != NULL) {
				_g_free0 (id);
				_g_object_unref0 (_id_it);
				_g_object_unref0 (ids);
				_g_object_unref0 (uris);
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return NULL;
			}
			_g_free0 (id);
		}
		_g_object_unref0 (_id_it);
	}
	rygel_media_container_updated ((RygelMediaContainer*) self);
	_g_object_unref0 (ids);
	_g_object_unref0 (uris);
	return self;
}


static RygelMediaExportRootContainer* rygel_media_export_root_container_new (RygelMediaDB* db) {
	return rygel_media_export_root_container_construct (RYGEL_TYPE_MEDIA_EXPORT_ROOT_CONTAINER, db);
}


static void rygel_media_export_root_container_on_file_harvested (RygelMediaExportRootContainer* self, GFile* file) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (file != NULL);
	gee_abstract_map_remove ((GeeAbstractMap*) self->priv->harvester, file, NULL);
}


static void _rygel_media_export_root_container_on_file_harvested_rygel_media_export_harvester_harvested (RygelMediaExportHarvester* _sender, GFile* file, gpointer self) {
	rygel_media_export_root_container_on_file_harvested (self, file);
}


static void rygel_media_export_root_container_harvest (RygelMediaExportRootContainer* self, GFile* file, RygelMediaContainer* parent) {
	RygelMediaExportHarvester* harvester;
	g_return_if_fail (self != NULL);
	g_return_if_fail (file != NULL);
	g_return_if_fail (parent != NULL);
	harvester = rygel_media_export_harvester_new (parent, ((RygelMediaDBContainer*) self)->media_db, self->priv->extractor, self->priv->monitor);
	g_signal_connect_object (harvester, "harvested", (GCallback) _rygel_media_export_root_container_on_file_harvested_rygel_media_export_harvester_harvested, self, 0);
	gee_abstract_map_set ((GeeAbstractMap*) self->priv->harvester, file, harvester);
	rygel_media_export_harvester_harvest (harvester, file);
	_g_object_unref0 (harvester);
}


static void rygel_media_export_root_container_on_file_changed (RygelMediaExportRootContainer* self, GFile* file, GFile* other, GFileMonitorEvent event) {
	GError * _inner_error_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (file != NULL);
	_inner_error_ = NULL;
	switch (event) {
		case G_FILE_MONITOR_EVENT_CREATED:
		{
			GFile* parent;
			char* _tmp0_;
			char* _tmp1_;
			char* id;
			RygelMediaObject* parent_container;
			parent = g_file_get_parent (file);
			id = (_tmp1_ = g_compute_checksum_for_string (G_CHECKSUM_MD5, _tmp0_ = g_file_get_uri (parent), -1), _g_free0 (_tmp0_), _tmp1_);
			parent_container = rygel_media_db_get_object (((RygelMediaDBContainer*) self)->media_db, id, &_inner_error_);
			if (_inner_error_ != NULL) {
				_g_object_unref0 (parent);
				_g_free0 (id);
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return;
			}
			if (parent_container != NULL) {
				rygel_media_export_root_container_harvest (self, file, RYGEL_MEDIA_CONTAINER (parent_container));
			} else {
				g_assert_not_reached ();
			}
			_g_object_unref0 (parent);
			_g_free0 (id);
			_g_object_unref0 (parent_container);
			break;
		}
		case G_FILE_MONITOR_EVENT_CHANGES_DONE_HINT:
		{
			break;
		}
		case G_FILE_MONITOR_EVENT_DELETED:
		{
			char* _tmp2_;
			char* _tmp3_;
			char* id;
			RygelMediaObject* obj;
			id = (_tmp3_ = g_compute_checksum_for_string (G_CHECKSUM_MD5, _tmp2_ = g_file_get_uri (file), -1), _g_free0 (_tmp2_), _tmp3_);
			obj = rygel_media_db_get_object (((RygelMediaDBContainer*) self)->media_db, id, &_inner_error_);
			if (_inner_error_ != NULL) {
				_g_free0 (id);
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return;
			}
			if (obj != NULL) {
				rygel_media_db_remove_object (((RygelMediaDBContainer*) self)->media_db, obj, &_inner_error_);
				if (_inner_error_ != NULL) {
					_g_free0 (id);
					_g_object_unref0 (obj);
					g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
					g_clear_error (&_inner_error_);
					return;
				}
				if (obj->parent != NULL) {
					rygel_media_container_updated (obj->parent);
				}
			}
			_g_free0 (id);
			_g_object_unref0 (obj);
			break;
		}
		default:
		{
			break;
		}
	}
}


static void rygel_media_export_root_container_class_init (RygelMediaExportRootContainerClass * klass) {
	rygel_media_export_root_container_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelMediaExportRootContainerPrivate));
	G_OBJECT_CLASS (klass)->finalize = rygel_media_export_root_container_finalize;
}


static void rygel_media_export_root_container_instance_init (RygelMediaExportRootContainer * self) {
	self->priv = RYGEL_MEDIA_EXPORT_ROOT_CONTAINER_GET_PRIVATE (self);
}


static void rygel_media_export_root_container_finalize (GObject* obj) {
	RygelMediaExportRootContainer * self;
	self = RYGEL_MEDIA_EXPORT_ROOT_CONTAINER (obj);
	_g_object_unref0 (self->priv->extractor);
	_g_object_unref0 (self->priv->harvester);
	_g_object_unref0 (self->priv->monitor);
	_g_object_unref0 (self->priv->service);
	_g_object_unref0 (self->priv->dynamic_elements);
	G_OBJECT_CLASS (rygel_media_export_root_container_parent_class)->finalize (obj);
}


GType rygel_media_export_root_container_get_type (void) {
	static GType rygel_media_export_root_container_type_id = 0;
	if (rygel_media_export_root_container_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediaExportRootContainerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_media_export_root_container_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediaExportRootContainer), 0, (GInstanceInitFunc) rygel_media_export_root_container_instance_init, NULL };
		rygel_media_export_root_container_type_id = g_type_register_static (RYGEL_TYPE_MEDIA_DB_CONTAINER, "RygelMediaExportRootContainer", &g_define_type_info, 0);
	}
	return rygel_media_export_root_container_type_id;
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



