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
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>


#define RYGEL_TYPE_TRACKER_GET_METADATA_RESULT (rygel_tracker_get_metadata_result_get_type ())
#define RYGEL_TRACKER_GET_METADATA_RESULT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_GET_METADATA_RESULT, RygelTrackerGetMetadataResult))
#define RYGEL_TRACKER_GET_METADATA_RESULT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_GET_METADATA_RESULT, RygelTrackerGetMetadataResultClass))
#define RYGEL_IS_TRACKER_GET_METADATA_RESULT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_GET_METADATA_RESULT))
#define RYGEL_IS_TRACKER_GET_METADATA_RESULT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_GET_METADATA_RESULT))
#define RYGEL_TRACKER_GET_METADATA_RESULT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_GET_METADATA_RESULT, RygelTrackerGetMetadataResultClass))

typedef struct _RygelTrackerGetMetadataResult RygelTrackerGetMetadataResult;
typedef struct _RygelTrackerGetMetadataResultClass RygelTrackerGetMetadataResultClass;
typedef struct _RygelTrackerGetMetadataResultPrivate RygelTrackerGetMetadataResultPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))

#define RYGEL_TYPE_TRACKER_SEARCH_CONTAINER (rygel_tracker_search_container_get_type ())
#define RYGEL_TRACKER_SEARCH_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainer))
#define RYGEL_TRACKER_SEARCH_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainerClass))
#define RYGEL_IS_TRACKER_SEARCH_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER))
#define RYGEL_IS_TRACKER_SEARCH_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER))
#define RYGEL_TRACKER_SEARCH_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainerClass))

typedef struct _RygelTrackerSearchContainer RygelTrackerSearchContainer;
typedef struct _RygelTrackerSearchContainerClass RygelTrackerSearchContainerClass;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _RygelTrackerGetMetadataResult {
	RygelSimpleAsyncResult parent_instance;
	RygelTrackerGetMetadataResultPrivate * priv;
	char* item_id;
	char* item_path;
	char* item_service;
};

struct _RygelTrackerGetMetadataResultClass {
	RygelSimpleAsyncResultClass parent_class;
};


static gpointer rygel_tracker_get_metadata_result_parent_class = NULL;

GType rygel_tracker_get_metadata_result_get_type (void);
enum  {
	RYGEL_TRACKER_GET_METADATA_RESULT_DUMMY_PROPERTY
};
GType rygel_tracker_search_container_get_type (void);
RygelTrackerGetMetadataResult* rygel_tracker_get_metadata_result_new (RygelTrackerSearchContainer* search_container, GAsyncReadyCallback callback, void* callback_target, const char* item_id);
RygelTrackerGetMetadataResult* rygel_tracker_get_metadata_result_construct (GType object_type, RygelTrackerSearchContainer* search_container, GAsyncReadyCallback callback, void* callback_target, const char* item_id);
RygelMediaItem* rygel_tracker_search_container_create_item (RygelTrackerSearchContainer* self, const char* service, const char* path, char** metadata, int metadata_length1);
void rygel_tracker_get_metadata_result_ready (RygelTrackerGetMetadataResult* self, char** metadata, int metadata_length1, GError* _error_);
static void rygel_tracker_get_metadata_result_finalize (GObject* obj);



RygelTrackerGetMetadataResult* rygel_tracker_get_metadata_result_construct (GType object_type, RygelTrackerSearchContainer* search_container, GAsyncReadyCallback callback, void* callback_target, const char* item_id) {
	RygelTrackerGetMetadataResult * self;
	char* _tmp0_;
	g_return_val_if_fail (search_container != NULL, NULL);
	g_return_val_if_fail (item_id != NULL, NULL);
	self = (RygelTrackerGetMetadataResult*) rygel_simple_async_result_construct (object_type, RYGEL_TYPE_MEDIA_OBJECT, (GBoxedCopyFunc) g_object_ref, g_object_unref, (GObject*) search_container, callback, callback_target);
	self->item_id = (_tmp0_ = g_strdup (item_id), _g_free0 (self->item_id), _tmp0_);
	return self;
}


RygelTrackerGetMetadataResult* rygel_tracker_get_metadata_result_new (RygelTrackerSearchContainer* search_container, GAsyncReadyCallback callback, void* callback_target, const char* item_id) {
	return rygel_tracker_get_metadata_result_construct (RYGEL_TYPE_TRACKER_GET_METADATA_RESULT, search_container, callback, callback_target, item_id);
}


static gpointer _g_error_copy0 (gpointer self) {
	return self ? g_error_copy (self) : NULL;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void rygel_tracker_get_metadata_result_ready (RygelTrackerGetMetadataResult* self, char** metadata, int metadata_length1, GError* _error_) {
	RygelTrackerSearchContainer* search_container;
	RygelMediaObject* _tmp1_;
	g_return_if_fail (self != NULL);
	if (_error_ != NULL) {
		GError* _tmp0_;
		((RygelSimpleAsyncResult*) self)->error = (_tmp0_ = _g_error_copy0 (_error_), _g_error_free0 (((RygelSimpleAsyncResult*) self)->error), _tmp0_);
		rygel_simple_async_result_complete ((RygelSimpleAsyncResult*) self);
		return;
	}
	search_container = _g_object_ref0 (RYGEL_TRACKER_SEARCH_CONTAINER (((RygelSimpleAsyncResult*) self)->source_object));
	((RygelSimpleAsyncResult*) self)->data = (_tmp1_ = (RygelMediaObject*) rygel_tracker_search_container_create_item (search_container, self->item_service, self->item_path, metadata, metadata_length1), _g_object_unref0 (((RygelSimpleAsyncResult*) self)->data), _tmp1_);
	rygel_simple_async_result_complete ((RygelSimpleAsyncResult*) self);
	_g_object_unref0 (search_container);
}


static void rygel_tracker_get_metadata_result_class_init (RygelTrackerGetMetadataResultClass * klass) {
	rygel_tracker_get_metadata_result_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = rygel_tracker_get_metadata_result_finalize;
}


static void rygel_tracker_get_metadata_result_instance_init (RygelTrackerGetMetadataResult * self) {
}


static void rygel_tracker_get_metadata_result_finalize (GObject* obj) {
	RygelTrackerGetMetadataResult * self;
	self = RYGEL_TRACKER_GET_METADATA_RESULT (obj);
	_g_free0 (self->item_id);
	_g_free0 (self->item_path);
	_g_free0 (self->item_service);
	G_OBJECT_CLASS (rygel_tracker_get_metadata_result_parent_class)->finalize (obj);
}


GType rygel_tracker_get_metadata_result_get_type (void) {
	static GType rygel_tracker_get_metadata_result_type_id = 0;
	if (rygel_tracker_get_metadata_result_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelTrackerGetMetadataResultClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_tracker_get_metadata_result_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelTrackerGetMetadataResult), 0, (GInstanceInitFunc) rygel_tracker_get_metadata_result_instance_init, NULL };
		rygel_tracker_get_metadata_result_type_id = g_type_register_static (RYGEL_TYPE_SIMPLE_ASYNC_RESULT, "RygelTrackerGetMetadataResult", &g_define_type_info, 0);
	}
	return rygel_tracker_get_metadata_result_type_id;
}




