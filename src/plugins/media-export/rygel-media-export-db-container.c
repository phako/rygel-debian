/* rygel-media-export-db-container.c generated by valac, the Vala compiler
 * generated from rygel-media-export-db-container.vala, do not modify */

/*
 * Copyright (C) 2009 Jens Georg <mail@jensge.org>.
 *
 * Author: Jens Georg <mail@jensge.org>
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
#include <gio/gio.h>
#include <gee.h>


#define RYGEL_MEDIA_EXPORT_TYPE_DB_CONTAINER (rygel_media_export_db_container_get_type ())
#define RYGEL_MEDIA_EXPORT_DB_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_MEDIA_EXPORT_TYPE_DB_CONTAINER, RygelMediaExportDBContainer))
#define RYGEL_MEDIA_EXPORT_DB_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_MEDIA_EXPORT_TYPE_DB_CONTAINER, RygelMediaExportDBContainerClass))
#define RYGEL_MEDIA_EXPORT_IS_DB_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_MEDIA_EXPORT_TYPE_DB_CONTAINER))
#define RYGEL_MEDIA_EXPORT_IS_DB_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_MEDIA_EXPORT_TYPE_DB_CONTAINER))
#define RYGEL_MEDIA_EXPORT_DB_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_MEDIA_EXPORT_TYPE_DB_CONTAINER, RygelMediaExportDBContainerClass))

typedef struct _RygelMediaExportDBContainer RygelMediaExportDBContainer;
typedef struct _RygelMediaExportDBContainerClass RygelMediaExportDBContainerClass;
typedef struct _RygelMediaExportDBContainerPrivate RygelMediaExportDBContainerPrivate;

#define RYGEL_MEDIA_EXPORT_TYPE_MEDIA_CACHE (rygel_media_export_media_cache_get_type ())
#define RYGEL_MEDIA_EXPORT_MEDIA_CACHE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_MEDIA_EXPORT_TYPE_MEDIA_CACHE, RygelMediaExportMediaCache))
#define RYGEL_MEDIA_EXPORT_MEDIA_CACHE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_MEDIA_EXPORT_TYPE_MEDIA_CACHE, RygelMediaExportMediaCacheClass))
#define RYGEL_MEDIA_EXPORT_IS_MEDIA_CACHE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_MEDIA_EXPORT_TYPE_MEDIA_CACHE))
#define RYGEL_MEDIA_EXPORT_IS_MEDIA_CACHE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_MEDIA_EXPORT_TYPE_MEDIA_CACHE))
#define RYGEL_MEDIA_EXPORT_MEDIA_CACHE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_MEDIA_EXPORT_TYPE_MEDIA_CACHE, RygelMediaExportMediaCacheClass))

typedef struct _RygelMediaExportMediaCache RygelMediaExportMediaCache;
typedef struct _RygelMediaExportMediaCacheClass RygelMediaExportMediaCacheClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _RygelMediaExportDbContainerGetChildrenData RygelMediaExportDbContainerGetChildrenData;
#define _rygel_search_expression_unref0(var) ((var == NULL) ? NULL : (var = (rygel_search_expression_unref (var), NULL)))
typedef struct _RygelMediaExportDbContainerSearchData RygelMediaExportDbContainerSearchData;
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _RygelMediaExportDbContainerFindObjectData RygelMediaExportDbContainerFindObjectData;

struct _RygelMediaExportDBContainer {
	RygelMediaContainer parent_instance;
	RygelMediaExportDBContainerPrivate * priv;
	RygelMediaExportMediaCache* media_db;
};

struct _RygelMediaExportDBContainerClass {
	RygelMediaContainerClass parent_class;
};

typedef enum  {
	RYGEL_MEDIA_EXPORT_DATABASE_ERROR_IO_ERROR,
	RYGEL_MEDIA_EXPORT_DATABASE_ERROR_SQLITE_ERROR
} RygelMediaExportDatabaseError;
#define RYGEL_MEDIA_EXPORT_DATABASE_ERROR rygel_media_export_database_error_quark ()
struct _RygelMediaExportDbContainerGetChildrenData {
	int _state_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	RygelMediaExportDBContainer* self;
	guint offset;
	guint max_count;
	GCancellable* cancellable;
	RygelMediaObjects* result;
	RygelMediaObjects* children;
	GeeIterator* _child_it;
	RygelMediaObject* child;
	GError * _inner_error_;
};

typedef enum  {
	RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR,
	RYGEL_MEDIA_DB_ERROR_GENERAL_ERROR,
	RYGEL_MEDIA_DB_ERROR_INVALID_TYPE,
	RYGEL_MEDIA_DB_ERROR_UNSUPPORTED_SEARCH
} RygelMediaDBError;
#define RYGEL_MEDIA_DB_ERROR rygel_media_db_error_quark ()
struct _RygelMediaExportDbContainerSearchData {
	int _state_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	RygelMediaExportDBContainer* self;
	RygelSearchExpression* expression;
	guint offset;
	guint max_count;
	guint total_matches;
	GCancellable* cancellable;
	RygelMediaObjects* result;
	RygelMediaObjects* children;
	guint max_objects;
	RygelMediaObjects* _tmp0_;
	RygelMediaObjects* _tmp1_;
	RygelMediaObjects* _tmp2_;
	RygelMediaObjects* _tmp3_;
	GError * _error_;
	GError * _inner_error_;
};

struct _RygelMediaExportDbContainerFindObjectData {
	int _state_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	RygelMediaExportDBContainer* self;
	char* id;
	GCancellable* cancellable;
	RygelMediaObject* result;
	RygelMediaObject* _tmp0_;
	GError * _inner_error_;
};


static gpointer rygel_media_export_db_container_parent_class = NULL;

GType rygel_media_export_db_container_get_type (void) G_GNUC_CONST;
GType rygel_media_export_media_cache_get_type (void) G_GNUC_CONST;
enum  {
	RYGEL_MEDIA_EXPORT_DB_CONTAINER_DUMMY_PROPERTY
};
GQuark rygel_media_export_database_error_quark (void);
gint rygel_media_export_media_cache_get_child_count (RygelMediaExportMediaCache* self, const char* container_id, GError** error);
static void rygel_media_export_db_container_on_db_container_updated (RygelMediaExportDBContainer* self, RygelMediaContainer* container, RygelMediaContainer* container_updated);
static void _rygel_media_export_db_container_on_db_container_updated_rygel_media_container_container_updated (RygelMediaContainer* _sender, RygelMediaContainer* container, gpointer self);
RygelMediaExportDBContainer* rygel_media_export_db_container_new (RygelMediaExportMediaCache* media_db, const char* id, const char* title);
RygelMediaExportDBContainer* rygel_media_export_db_container_construct (GType object_type, RygelMediaExportMediaCache* media_db, const char* id, const char* title);
static void rygel_media_export_db_container_real_get_children_data_free (gpointer _data);
static void rygel_media_export_db_container_real_get_children (RygelMediaContainer* base, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
static void rygel_media_export_db_container_get_children_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
RygelMediaObjects* rygel_media_export_media_cache_get_children (RygelMediaExportMediaCache* self, const char* container_id, glong offset, glong max_count, GError** error);
static gboolean rygel_media_export_db_container_real_get_children_co (RygelMediaExportDbContainerGetChildrenData* data);
static void rygel_media_export_db_container_real_search_data_free (gpointer _data);
static void rygel_media_export_db_container_real_search (RygelMediaContainer* base, RygelSearchExpression* expression, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
static void rygel_media_export_db_container_search_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
RygelMediaObjects* rygel_media_export_media_cache_get_objects_by_search_expression (RygelMediaExportMediaCache* self, RygelSearchExpression* expression, const char* container_id, guint offset, guint max_count, guint* total_matches, GError** error);
GQuark rygel_media_db_error_quark (void);
static gboolean rygel_media_export_db_container_real_search_co (RygelMediaExportDbContainerSearchData* data);
static void rygel_media_export_db_container_real_find_object_data_free (gpointer _data);
static void rygel_media_export_db_container_real_find_object (RygelMediaContainer* base, const char* id, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
static void rygel_media_export_db_container_find_object_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
RygelMediaObject* rygel_media_export_media_cache_get_object (RygelMediaExportMediaCache* self, const char* object_id, GError** error);
static gboolean rygel_media_export_db_container_real_find_object_co (RygelMediaExportDbContainerFindObjectData* data);
static void rygel_media_export_db_container_finalize (GObject* obj);



static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


#line 42 "rygel-media-export-db-container.vala"
static void _rygel_media_export_db_container_on_db_container_updated_rygel_media_container_container_updated (RygelMediaContainer* _sender, RygelMediaContainer* container, gpointer self) {
#line 175 "rygel-media-export-db-container.c"
	rygel_media_export_db_container_on_db_container_updated (self, _sender, container);
}


#line 27 "rygel-media-export-db-container.vala"
RygelMediaExportDBContainer* rygel_media_export_db_container_construct (GType object_type, RygelMediaExportMediaCache* media_db, const char* id, const char* title) {
#line 182 "rygel-media-export-db-container.c"
	GError * _inner_error_;
	RygelMediaExportDBContainer * self;
	gint count = 0;
	RygelMediaExportMediaCache* _tmp1_;
#line 27 "rygel-media-export-db-container.vala"
	g_return_val_if_fail (media_db != NULL, NULL);
#line 27 "rygel-media-export-db-container.vala"
	g_return_val_if_fail (id != NULL, NULL);
#line 27 "rygel-media-export-db-container.vala"
	g_return_val_if_fail (title != NULL, NULL);
#line 193 "rygel-media-export-db-container.c"
	_inner_error_ = NULL;
	{
		gint _tmp0_;
#line 30 "rygel-media-export-db-container.vala"
		_tmp0_ = rygel_media_export_media_cache_get_child_count (media_db, id, &_inner_error_);
#line 199 "rygel-media-export-db-container.c"
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == RYGEL_MEDIA_EXPORT_DATABASE_ERROR) {
				goto __catch0_rygel_media_export_database_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
#line 30 "rygel-media-export-db-container.vala"
		count = _tmp0_;
#line 210 "rygel-media-export-db-container.c"
	}
	goto __finally0;
	__catch0_rygel_media_export_database_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
#line 32 "rygel-media-export-db-container.vala"
			g_debug ("rygel-media-export-db-container.vala:32: Could not get child count fro" \
"m database: %s", e->message);
#line 34 "rygel-media-export-db-container.vala"
			count = 0;
#line 223 "rygel-media-export-db-container.c"
			_g_error_free0 (e);
		}
	}
	__finally0:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
#line 36 "rygel-media-export-db-container.vala"
	self = (RygelMediaExportDBContainer*) rygel_media_container_construct (object_type, id, NULL, title, count);
#line 38 "rygel-media-export-db-container.vala"
	self->media_db = (_tmp1_ = _g_object_ref0 (media_db), _g_object_unref0 (self->media_db), _tmp1_);
#line 39 "rygel-media-export-db-container.vala"
	g_signal_connect_object ((RygelMediaContainer*) self, "container-updated", (GCallback) _rygel_media_export_db_container_on_db_container_updated_rygel_media_container_container_updated, self, 0);
#line 239 "rygel-media-export-db-container.c"
	return self;
}


#line 27 "rygel-media-export-db-container.vala"
RygelMediaExportDBContainer* rygel_media_export_db_container_new (RygelMediaExportMediaCache* media_db, const char* id, const char* title) {
#line 27 "rygel-media-export-db-container.vala"
	return rygel_media_export_db_container_construct (RYGEL_MEDIA_EXPORT_TYPE_DB_CONTAINER, media_db, id, title);
#line 248 "rygel-media-export-db-container.c"
}


#line 42 "rygel-media-export-db-container.vala"
static void rygel_media_export_db_container_on_db_container_updated (RygelMediaExportDBContainer* self, RygelMediaContainer* container, RygelMediaContainer* container_updated) {
#line 254 "rygel-media-export-db-container.c"
	GError * _inner_error_;
#line 42 "rygel-media-export-db-container.vala"
	g_return_if_fail (self != NULL);
#line 42 "rygel-media-export-db-container.vala"
	g_return_if_fail (container != NULL);
#line 42 "rygel-media-export-db-container.vala"
	g_return_if_fail (container_updated != NULL);
#line 262 "rygel-media-export-db-container.c"
	_inner_error_ = NULL;
	{
		gint _tmp0_;
#line 45 "rygel-media-export-db-container.vala"
		_tmp0_ = rygel_media_export_media_cache_get_child_count (self->media_db, ((RygelMediaObject*) self)->id, &_inner_error_);
#line 268 "rygel-media-export-db-container.c"
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == RYGEL_MEDIA_EXPORT_DATABASE_ERROR) {
				goto __catch1_rygel_media_export_database_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
#line 45 "rygel-media-export-db-container.vala"
		((RygelMediaContainer*) self)->child_count = _tmp0_;
#line 279 "rygel-media-export-db-container.c"
	}
	goto __finally1;
	__catch1_rygel_media_export_database_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
#line 47 "rygel-media-export-db-container.vala"
			g_debug ("rygel-media-export-db-container.vala:47: Could not get child count fro" \
"m database: %s", e->message);
#line 49 "rygel-media-export-db-container.vala"
			((RygelMediaContainer*) self)->child_count = 0;
#line 292 "rygel-media-export-db-container.c"
			_g_error_free0 (e);
		}
	}
	__finally1:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


static void rygel_media_export_db_container_real_get_children_data_free (gpointer _data) {
	RygelMediaExportDbContainerGetChildrenData* data;
	data = _data;
	_g_object_unref0 (data->cancellable);
	_g_object_unref0 (data->result);
	g_object_unref (data->self);
	g_slice_free (RygelMediaExportDbContainerGetChildrenData, data);
}


static void rygel_media_export_db_container_real_get_children (RygelMediaContainer* base, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	RygelMediaExportDBContainer * self;
	RygelMediaExportDbContainerGetChildrenData* _data_;
	self = (RygelMediaExportDBContainer*) base;
	_data_ = g_slice_new0 (RygelMediaExportDbContainerGetChildrenData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, rygel_media_export_db_container_real_get_children);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, rygel_media_export_db_container_real_get_children_data_free);
	_data_->self = g_object_ref (self);
	_data_->offset = offset;
	_data_->max_count = max_count;
	_data_->cancellable = _g_object_ref0 (cancellable);
	rygel_media_export_db_container_real_get_children_co (_data_);
}


static RygelMediaObjects* rygel_media_export_db_container_real_get_children_finish (RygelMediaContainer* base, GAsyncResult* _res_, GError** error) {
	RygelMediaObjects* result;
	RygelMediaExportDbContainerGetChildrenData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return NULL;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	_data_->result = NULL;
	return result;
}


static void rygel_media_export_db_container_get_children_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	RygelMediaExportDbContainerGetChildrenData* data;
	data = _user_data_;
	data->_res_ = _res_;
	rygel_media_export_db_container_real_get_children_co (data);
}


static gboolean rygel_media_export_db_container_real_get_children_co (RygelMediaExportDbContainerGetChildrenData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	{
		data->children = rygel_media_export_media_cache_get_children (data->self->media_db, ((RygelMediaObject*) data->self)->id, (glong) data->offset, (glong) data->max_count, &data->_inner_error_);
		if (data->_inner_error_ != NULL) {
			g_simple_async_result_set_from_error (data->_async_result, data->_inner_error_);
			g_error_free (data->_inner_error_);
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
		{
			data->_child_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) data->children);
#line 60 "rygel-media-export-db-container.vala"
			while (TRUE) {
#line 60 "rygel-media-export-db-container.vala"
				if (!gee_iterator_next (data->_child_it)) {
#line 60 "rygel-media-export-db-container.vala"
					break;
#line 382 "rygel-media-export-db-container.c"
				}
				data->child = (RygelMediaObject*) gee_iterator_get (data->_child_it);
#line 61 "rygel-media-export-db-container.vala"
				data->child->parent = (RygelMediaContainer*) data->self;
#line 387 "rygel-media-export-db-container.c"
				_g_object_unref0 (data->child);
			}
			_g_object_unref0 (data->_child_it);
		}
		data->result = data->children;
		{
			if (data->_state_ == 0) {
				g_simple_async_result_complete_in_idle (data->_async_result);
			} else {
				g_simple_async_result_complete (data->_async_result);
			}
			g_object_unref (data->_async_result);
			return FALSE;
		}
		_g_object_unref0 (data->children);
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


static void rygel_media_export_db_container_real_search_data_free (gpointer _data) {
	RygelMediaExportDbContainerSearchData* data;
	data = _data;
	_rygel_search_expression_unref0 (data->expression);
	_g_object_unref0 (data->cancellable);
	_g_object_unref0 (data->result);
	g_object_unref (data->self);
	g_slice_free (RygelMediaExportDbContainerSearchData, data);
}


static gpointer _rygel_search_expression_ref0 (gpointer self) {
	return self ? rygel_search_expression_ref (self) : NULL;
}


static void rygel_media_export_db_container_real_search (RygelMediaContainer* base, RygelSearchExpression* expression, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	RygelMediaExportDBContainer * self;
	RygelMediaExportDbContainerSearchData* _data_;
	self = (RygelMediaExportDBContainer*) base;
	_data_ = g_slice_new0 (RygelMediaExportDbContainerSearchData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, rygel_media_export_db_container_real_search);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, rygel_media_export_db_container_real_search_data_free);
	_data_->self = g_object_ref (self);
	_data_->expression = _rygel_search_expression_ref0 (expression);
	_data_->offset = offset;
	_data_->max_count = max_count;
	_data_->cancellable = _g_object_ref0 (cancellable);
	rygel_media_export_db_container_real_search_co (_data_);
}


static RygelMediaObjects* rygel_media_export_db_container_real_search_finish (RygelMediaContainer* base, GAsyncResult* _res_, guint* total_matches, GError** error) {
	RygelMediaObjects* result;
	RygelMediaExportDbContainerSearchData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return NULL;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	*total_matches = _data_->total_matches;
	result = _data_->result;
	_data_->result = NULL;
	return result;
}


static void rygel_media_export_db_container_search_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	RygelMediaExportDbContainerSearchData* data;
	data = _user_data_;
	data->_res_ = _res_;
	rygel_media_export_db_container_real_search_co (data);
}


static gpointer _g_error_copy0 (gpointer self) {
	return self ? g_error_copy (self) : NULL;
}


static gboolean rygel_media_export_db_container_real_search_co (RygelMediaExportDbContainerSearchData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	{
		data->children = NULL;
		data->max_objects = data->max_count;
#line 76 "rygel-media-export-db-container.vala"
		if (data->max_objects == 0) {
#line 77 "rygel-media-export-db-container.vala"
			data->max_objects = (guint) (-1);
#line 492 "rygel-media-export-db-container.c"
		}
		{
			data->_tmp0_ = rygel_media_export_media_cache_get_objects_by_search_expression (data->self->media_db, data->expression, ((RygelMediaObject*) data->self)->id, data->offset, data->max_objects, &data->total_matches, &data->_inner_error_);
			if (data->_inner_error_ != NULL) {
				if (data->_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
					goto __catch2_rygel_media_db_error;
				}
				goto __finally2;
			}
#line 81 "rygel-media-export-db-container.vala"
			data->children = (data->_tmp1_ = data->_tmp0_, _g_object_unref0 (data->children), data->_tmp1_);
#line 504 "rygel-media-export-db-container.c"
		}
		goto __finally2;
		__catch2_rygel_media_db_error:
		{
			data->_error_ = data->_inner_error_;
			data->_inner_error_ = NULL;
			{
#line 88 "rygel-media-export-db-container.vala"
				if (g_error_matches (data->_error_, RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_UNSUPPORTED_SEARCH)) {
#line 514 "rygel-media-export-db-container.c"
					data->_state_ = 1;
					RYGEL_MEDIA_CONTAINER_CLASS (rygel_media_export_db_container_parent_class)->search (RYGEL_MEDIA_CONTAINER (data->self), data->expression, data->offset, data->max_count, data->cancellable, rygel_media_export_db_container_search_ready, data);
					return FALSE;
					_state_1:
					data->_tmp2_ = RYGEL_MEDIA_CONTAINER_CLASS (rygel_media_export_db_container_parent_class)->search_finish (RYGEL_MEDIA_CONTAINER (data->self), data->_res_, &data->total_matches, &data->_inner_error_);
					if (data->_inner_error_ != NULL) {
						_g_error_free0 (data->_error_);
						_g_object_unref0 (data->children);
						goto __finally2;
					}
#line 89 "rygel-media-export-db-container.vala"
					data->children = (data->_tmp3_ = data->_tmp2_, _g_object_unref0 (data->children), data->_tmp3_);
#line 527 "rygel-media-export-db-container.c"
				} else {
					data->_inner_error_ = _g_error_copy0 (data->_error_);
					{
						_g_error_free0 (data->_error_);
						_g_object_unref0 (data->children);
						goto __finally2;
					}
				}
				_g_error_free0 (data->_error_);
			}
		}
		__finally2:
		if (data->_inner_error_ != NULL) {
			g_simple_async_result_set_from_error (data->_async_result, data->_inner_error_);
			g_error_free (data->_inner_error_);
			_g_object_unref0 (data->children);
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
		data->result = data->children;
		{
			if (data->_state_ == 0) {
				g_simple_async_result_complete_in_idle (data->_async_result);
			} else {
				g_simple_async_result_complete (data->_async_result);
			}
			g_object_unref (data->_async_result);
			return FALSE;
		}
		_g_object_unref0 (data->children);
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


static void rygel_media_export_db_container_real_find_object_data_free (gpointer _data) {
	RygelMediaExportDbContainerFindObjectData* data;
	data = _data;
	_g_free0 (data->id);
	_g_object_unref0 (data->cancellable);
	_g_object_unref0 (data->result);
	g_object_unref (data->self);
	g_slice_free (RygelMediaExportDbContainerFindObjectData, data);
}


static void rygel_media_export_db_container_real_find_object (RygelMediaContainer* base, const char* id, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	RygelMediaExportDBContainer * self;
	RygelMediaExportDbContainerFindObjectData* _data_;
	self = (RygelMediaExportDBContainer*) base;
	_data_ = g_slice_new0 (RygelMediaExportDbContainerFindObjectData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, rygel_media_export_db_container_real_find_object);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, rygel_media_export_db_container_real_find_object_data_free);
	_data_->self = g_object_ref (self);
	_data_->id = g_strdup (id);
	_data_->cancellable = _g_object_ref0 (cancellable);
	rygel_media_export_db_container_real_find_object_co (_data_);
}


static RygelMediaObject* rygel_media_export_db_container_real_find_object_finish (RygelMediaContainer* base, GAsyncResult* _res_, GError** error) {
	RygelMediaObject* result;
	RygelMediaExportDbContainerFindObjectData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return NULL;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	_data_->result = NULL;
	return result;
}


static void rygel_media_export_db_container_find_object_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	RygelMediaExportDbContainerFindObjectData* data;
	data = _user_data_;
	data->_res_ = _res_;
	rygel_media_export_db_container_real_find_object_co (data);
}


static gboolean rygel_media_export_db_container_real_find_object_co (RygelMediaExportDbContainerFindObjectData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	{
		data->_tmp0_ = rygel_media_export_media_cache_get_object (data->self->media_db, data->id, &data->_inner_error_);
		if (data->_inner_error_ != NULL) {
			g_simple_async_result_set_from_error (data->_async_result, data->_inner_error_);
			g_error_free (data->_inner_error_);
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
		data->result = data->_tmp0_;
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


static void rygel_media_export_db_container_class_init (RygelMediaExportDBContainerClass * klass) {
	rygel_media_export_db_container_parent_class = g_type_class_peek_parent (klass);
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->get_children = rygel_media_export_db_container_real_get_children;
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->get_children_finish = rygel_media_export_db_container_real_get_children_finish;
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->search = rygel_media_export_db_container_real_search;
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->search_finish = rygel_media_export_db_container_real_search_finish;
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->find_object = rygel_media_export_db_container_real_find_object;
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->find_object_finish = rygel_media_export_db_container_real_find_object_finish;
	G_OBJECT_CLASS (klass)->finalize = rygel_media_export_db_container_finalize;
}


static void rygel_media_export_db_container_instance_init (RygelMediaExportDBContainer * self) {
}


static void rygel_media_export_db_container_finalize (GObject* obj) {
	RygelMediaExportDBContainer * self;
	self = RYGEL_MEDIA_EXPORT_DB_CONTAINER (obj);
	_g_object_unref0 (self->media_db);
	G_OBJECT_CLASS (rygel_media_export_db_container_parent_class)->finalize (obj);
}


GType rygel_media_export_db_container_get_type (void) {
	static volatile gsize rygel_media_export_db_container_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_media_export_db_container_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediaExportDBContainerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_media_export_db_container_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediaExportDBContainer), 0, (GInstanceInitFunc) rygel_media_export_db_container_instance_init, NULL };
		GType rygel_media_export_db_container_type_id;
		rygel_media_export_db_container_type_id = g_type_register_static (RYGEL_TYPE_MEDIA_CONTAINER, "RygelMediaExportDBContainer", &g_define_type_info, 0);
		g_once_init_leave (&rygel_media_export_db_container_type_id__volatile, rygel_media_export_db_container_type_id);
	}
	return rygel_media_export_db_container_type_id__volatile;
}




