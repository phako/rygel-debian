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
#include <rygel.h>
#include <gio/gio.h>
#include <gee.h>
#include <stdlib.h>
#include <string.h>


#define RYGEL_TYPE_TRACKER_SEARCH_RESULT (rygel_tracker_search_result_get_type ())
#define RYGEL_TRACKER_SEARCH_RESULT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_SEARCH_RESULT, RygelTrackerSearchResult))
#define RYGEL_TRACKER_SEARCH_RESULT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_SEARCH_RESULT, RygelTrackerSearchResultClass))
#define RYGEL_IS_TRACKER_SEARCH_RESULT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_SEARCH_RESULT))
#define RYGEL_IS_TRACKER_SEARCH_RESULT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_SEARCH_RESULT))
#define RYGEL_TRACKER_SEARCH_RESULT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_SEARCH_RESULT, RygelTrackerSearchResultClass))

typedef struct _RygelTrackerSearchResult RygelTrackerSearchResult;
typedef struct _RygelTrackerSearchResultClass RygelTrackerSearchResultClass;
typedef struct _RygelTrackerSearchResultPrivate RygelTrackerSearchResultPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define RYGEL_TYPE_TRACKER_SEARCH_CONTAINER (rygel_tracker_search_container_get_type ())
#define RYGEL_TRACKER_SEARCH_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainer))
#define RYGEL_TRACKER_SEARCH_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainerClass))
#define RYGEL_IS_TRACKER_SEARCH_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER))
#define RYGEL_IS_TRACKER_SEARCH_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER))
#define RYGEL_TRACKER_SEARCH_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainerClass))

typedef struct _RygelTrackerSearchContainer RygelTrackerSearchContainer;
typedef struct _RygelTrackerSearchContainerClass RygelTrackerSearchContainerClass;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _RygelTrackerSearchResult {
	RygelSimpleAsyncResult parent_instance;
	RygelTrackerSearchResultPrivate * priv;
};

struct _RygelTrackerSearchResultClass {
	RygelSimpleAsyncResultClass parent_class;
};


static gpointer rygel_tracker_search_result_parent_class = NULL;

GType rygel_tracker_search_result_get_type (void);
enum  {
	RYGEL_TRACKER_SEARCH_RESULT_DUMMY_PROPERTY
};
GType rygel_tracker_search_container_get_type (void);
RygelTrackerSearchResult* rygel_tracker_search_result_new (RygelTrackerSearchContainer* search_container, GAsyncReadyCallback callback, void* callback_target);
RygelTrackerSearchResult* rygel_tracker_search_result_construct (GType object_type, RygelTrackerSearchContainer* search_container, GAsyncReadyCallback callback, void* callback_target);
static char** rygel_tracker_search_result_slice_strv_tail (RygelTrackerSearchResult* self, char** strv, int strv_length1, gint index, int* result_length1);
RygelMediaItem* rygel_tracker_search_container_create_item (RygelTrackerSearchContainer* self, const char* service, const char* path, char** metadata, int metadata_length1);
void rygel_tracker_search_result_ready (RygelTrackerSearchResult* self, char*** search_result, int search_result_length1, GError* _error_);
static gint rygel_tracker_search_result_get_strv_length (RygelTrackerSearchResult* self, char** strv, int strv_length1);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);



RygelTrackerSearchResult* rygel_tracker_search_result_construct (GType object_type, RygelTrackerSearchContainer* search_container, GAsyncReadyCallback callback, void* callback_target) {
	RygelTrackerSearchResult * self;
	GeeList* _tmp0_;
	g_return_val_if_fail (search_container != NULL, NULL);
	self = (RygelTrackerSearchResult*) rygel_simple_async_result_construct (object_type, GEE_TYPE_LIST, (GBoxedCopyFunc) g_object_ref, g_object_unref, (GObject*) search_container, callback, callback_target);
	((RygelSimpleAsyncResult*) self)->data = (_tmp0_ = (GeeList*) gee_array_list_new (RYGEL_TYPE_MEDIA_OBJECT, (GBoxedCopyFunc) g_object_ref, g_object_unref, g_direct_equal), _g_object_unref0 (((RygelSimpleAsyncResult*) self)->data), _tmp0_);
	return self;
}


RygelTrackerSearchResult* rygel_tracker_search_result_new (RygelTrackerSearchContainer* search_container, GAsyncReadyCallback callback, void* callback_target) {
	return rygel_tracker_search_result_construct (RYGEL_TYPE_TRACKER_SEARCH_RESULT, search_container, callback, callback_target);
}


static gpointer _g_error_copy0 (gpointer self) {
	return self ? g_error_copy (self) : NULL;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void rygel_tracker_search_result_ready (RygelTrackerSearchResult* self, char*** search_result, int search_result_length1, GError* _error_) {
	RygelTrackerSearchContainer* search_container;
	g_return_if_fail (self != NULL);
	if (_error_ != NULL) {
		GError* _tmp0_;
		((RygelSimpleAsyncResult*) self)->error = (_tmp0_ = _g_error_copy0 (_error_), _g_error_free0 (((RygelSimpleAsyncResult*) self)->error), _tmp0_);
		rygel_simple_async_result_complete ((RygelSimpleAsyncResult*) self);
		return;
	}
	search_container = _g_object_ref0 (RYGEL_TRACKER_SEARCH_CONTAINER (((RygelSimpleAsyncResult*) self)->source_object));
	{
		guint i;
		i = (guint) 0;
		{
			gboolean _tmp1_;
			_tmp1_ = TRUE;
			while (TRUE) {
				char* child_path;
				char* service;
				char** _tmp3_;
				gint metadata_size;
				gint metadata_length1;
				gint _tmp2_;
				char** metadata;
				RygelMediaItem* item;
				if (!_tmp1_) {
					i++;
				}
				_tmp1_ = FALSE;
				if (!(i < search_result_length1)) {
					break;
				}
				child_path = g_strdup (search_result[i][0]);
				service = g_strdup (search_result[i][1]);
				metadata = (_tmp3_ = rygel_tracker_search_result_slice_strv_tail (self, search_result[i], -1, 2, &_tmp2_), metadata_length1 = _tmp2_, metadata_size = metadata_length1, _tmp3_);
				item = rygel_tracker_search_container_create_item (search_container, service, child_path, metadata, metadata_length1);
				gee_collection_add ((GeeCollection*) ((GeeList*) ((RygelSimpleAsyncResult*) self)->data), (RygelMediaObject*) item);
				_g_free0 (child_path);
				_g_free0 (service);
				metadata = (_vala_array_free (metadata, metadata_length1, (GDestroyNotify) g_free), NULL);
				_g_object_unref0 (item);
			}
		}
	}
	rygel_simple_async_result_complete ((RygelSimpleAsyncResult*) self);
	_g_object_unref0 (search_container);
}


static char** rygel_tracker_search_result_slice_strv_tail (RygelTrackerSearchResult* self, char** strv, int strv_length1, gint index, int* result_length1) {
	char** result;
	gint strv_length;
	char** _tmp1_;
	gint slice_size;
	gint slice_length1;
	gint _tmp0_;
	char** slice;
	char** _tmp4_;
	g_return_val_if_fail (self != NULL, NULL);
	strv_length = rygel_tracker_search_result_get_strv_length (self, strv, strv_length1);
	slice = (_tmp1_ = g_new0 (char*, (_tmp0_ = strv_length - index) + 1), slice_length1 = _tmp0_, slice_size = slice_length1, _tmp1_);
	{
		gint i;
		i = 0;
		{
			gboolean _tmp2_;
			_tmp2_ = TRUE;
			while (TRUE) {
				char* _tmp3_;
				if (!_tmp2_) {
					i++;
				}
				_tmp2_ = FALSE;
				if (!(i < slice_length1)) {
					break;
				}
				slice[i] = (_tmp3_ = g_strdup (strv[i + index]), _g_free0 (slice[i]), _tmp3_);
			}
		}
	}
	result = (_tmp4_ = slice, *result_length1 = slice_length1, _tmp4_);
	return result;
	slice = (_vala_array_free (slice, slice_length1, (GDestroyNotify) g_free), NULL);
}


static gint rygel_tracker_search_result_get_strv_length (RygelTrackerSearchResult* self, char** strv, int strv_length1) {
	gint result;
	gint i;
	g_return_val_if_fail (self != NULL, 0);
	i = 0;
	{
		gboolean _tmp0_;
		i = 0;
		_tmp0_ = TRUE;
		while (TRUE) {
			if (!_tmp0_) {
				i++;
			}
			_tmp0_ = FALSE;
			if (!(strv[i] != NULL)) {
				break;
			}
			;
		}
	}
	result = i + 1;
	return result;
}


static void rygel_tracker_search_result_class_init (RygelTrackerSearchResultClass * klass) {
	rygel_tracker_search_result_parent_class = g_type_class_peek_parent (klass);
}


static void rygel_tracker_search_result_instance_init (RygelTrackerSearchResult * self) {
}


GType rygel_tracker_search_result_get_type (void) {
	static GType rygel_tracker_search_result_type_id = 0;
	if (rygel_tracker_search_result_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelTrackerSearchResultClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_tracker_search_result_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelTrackerSearchResult), 0, (GInstanceInitFunc) rygel_tracker_search_result_instance_init, NULL };
		rygel_tracker_search_result_type_id = g_type_register_static (RYGEL_TYPE_SIMPLE_ASYNC_RESULT, "RygelTrackerSearchResult", &g_define_type_info, 0);
	}
	return rygel_tracker_search_result_type_id;
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




