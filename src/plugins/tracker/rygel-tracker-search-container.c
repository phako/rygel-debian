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
#include <gee.h>
#include <gio/gio.h>


#define RYGEL_TYPE_TRACKER_SEARCH_CONTAINER (rygel_tracker_search_container_get_type ())
#define RYGEL_TRACKER_SEARCH_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainer))
#define RYGEL_TRACKER_SEARCH_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainerClass))
#define RYGEL_IS_TRACKER_SEARCH_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER))
#define RYGEL_IS_TRACKER_SEARCH_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER))
#define RYGEL_TRACKER_SEARCH_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainerClass))

typedef struct _RygelTrackerSearchContainer RygelTrackerSearchContainer;
typedef struct _RygelTrackerSearchContainerClass RygelTrackerSearchContainerClass;
typedef struct _RygelTrackerSearchContainerPrivate RygelTrackerSearchContainerPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

#define RYGEL_TYPE_TRACKER_SEARCH_RESULT (rygel_tracker_search_result_get_type ())
#define RYGEL_TRACKER_SEARCH_RESULT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_SEARCH_RESULT, RygelTrackerSearchResult))
#define RYGEL_TRACKER_SEARCH_RESULT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_SEARCH_RESULT, RygelTrackerSearchResultClass))
#define RYGEL_IS_TRACKER_SEARCH_RESULT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_SEARCH_RESULT))
#define RYGEL_IS_TRACKER_SEARCH_RESULT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_SEARCH_RESULT))
#define RYGEL_TRACKER_SEARCH_RESULT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_SEARCH_RESULT, RygelTrackerSearchResultClass))

typedef struct _RygelTrackerSearchResult RygelTrackerSearchResult;
typedef struct _RygelTrackerSearchResultClass RygelTrackerSearchResultClass;

#define RYGEL_TYPE_TRACKER_GET_METADATA_RESULT (rygel_tracker_get_metadata_result_get_type ())
#define RYGEL_TRACKER_GET_METADATA_RESULT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_GET_METADATA_RESULT, RygelTrackerGetMetadataResult))
#define RYGEL_TRACKER_GET_METADATA_RESULT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_GET_METADATA_RESULT, RygelTrackerGetMetadataResultClass))
#define RYGEL_IS_TRACKER_GET_METADATA_RESULT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_GET_METADATA_RESULT))
#define RYGEL_IS_TRACKER_GET_METADATA_RESULT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_GET_METADATA_RESULT))
#define RYGEL_TRACKER_GET_METADATA_RESULT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_GET_METADATA_RESULT, RygelTrackerGetMetadataResultClass))

typedef struct _RygelTrackerGetMetadataResult RygelTrackerGetMetadataResult;
typedef struct _RygelTrackerGetMetadataResultClass RygelTrackerGetMetadataResultClass;
typedef struct _RygelTrackerGetMetadataResultPrivate RygelTrackerGetMetadataResultPrivate;

#define RYGEL_TYPE_TRACKER_ITEM (rygel_tracker_item_get_type ())
#define RYGEL_TRACKER_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_ITEM, RygelTrackerItem))
#define RYGEL_TRACKER_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_ITEM, RygelTrackerItemClass))
#define RYGEL_IS_TRACKER_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_ITEM))
#define RYGEL_IS_TRACKER_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_ITEM))
#define RYGEL_TRACKER_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_ITEM, RygelTrackerItemClass))

typedef struct _RygelTrackerItem RygelTrackerItem;
typedef struct _RygelTrackerItemClass RygelTrackerItemClass;

#define RYGEL_TYPE_TRACKER_VIDEO_ITEM (rygel_tracker_video_item_get_type ())
#define RYGEL_TRACKER_VIDEO_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_VIDEO_ITEM, RygelTrackerVideoItem))
#define RYGEL_TRACKER_VIDEO_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_VIDEO_ITEM, RygelTrackerVideoItemClass))
#define RYGEL_IS_TRACKER_VIDEO_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_VIDEO_ITEM))
#define RYGEL_IS_TRACKER_VIDEO_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_VIDEO_ITEM))
#define RYGEL_TRACKER_VIDEO_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_VIDEO_ITEM, RygelTrackerVideoItemClass))

typedef struct _RygelTrackerVideoItem RygelTrackerVideoItem;
typedef struct _RygelTrackerVideoItemClass RygelTrackerVideoItemClass;

#define RYGEL_TYPE_TRACKER_IMAGE_ITEM (rygel_tracker_image_item_get_type ())
#define RYGEL_TRACKER_IMAGE_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_IMAGE_ITEM, RygelTrackerImageItem))
#define RYGEL_TRACKER_IMAGE_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_IMAGE_ITEM, RygelTrackerImageItemClass))
#define RYGEL_IS_TRACKER_IMAGE_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_IMAGE_ITEM))
#define RYGEL_IS_TRACKER_IMAGE_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_IMAGE_ITEM))
#define RYGEL_TRACKER_IMAGE_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_IMAGE_ITEM, RygelTrackerImageItemClass))

typedef struct _RygelTrackerImageItem RygelTrackerImageItem;
typedef struct _RygelTrackerImageItemClass RygelTrackerImageItemClass;

#define RYGEL_TYPE_TRACKER_MUSIC_ITEM (rygel_tracker_music_item_get_type ())
#define RYGEL_TRACKER_MUSIC_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_MUSIC_ITEM, RygelTrackerMusicItem))
#define RYGEL_TRACKER_MUSIC_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_MUSIC_ITEM, RygelTrackerMusicItemClass))
#define RYGEL_IS_TRACKER_MUSIC_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_MUSIC_ITEM))
#define RYGEL_IS_TRACKER_MUSIC_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_MUSIC_ITEM))
#define RYGEL_TRACKER_MUSIC_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_MUSIC_ITEM, RygelTrackerMusicItemClass))

typedef struct _RygelTrackerMusicItem RygelTrackerMusicItem;
typedef struct _RygelTrackerMusicItemClass RygelTrackerMusicItemClass;
#define _dbus_g_connection_unref0(var) ((var == NULL) ? NULL : (var = (dbus_g_connection_unref (var), NULL)))

struct _RygelTrackerSearchContainer {
	RygelMediaContainer parent_instance;
	RygelTrackerSearchContainerPrivate * priv;
	DBusGProxy* metadata;
	DBusGProxy* search;
	DBusGProxy* tracker;
	char* service;
	char* query_condition;
	char** keywords;
	gint keywords_length1;
};

struct _RygelTrackerSearchContainerClass {
	RygelMediaContainerClass parent_class;
};

struct _RygelTrackerSearchContainerPrivate {
	GeeList* results;
};

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


static gpointer rygel_tracker_search_container_parent_class = NULL;

GType rygel_tracker_search_container_get_type (void);
#define RYGEL_TRACKER_SEARCH_CONTAINER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainerPrivate))
enum  {
	RYGEL_TRACKER_SEARCH_CONTAINER_DUMMY_PROPERTY
};
#define RYGEL_TRACKER_SEARCH_CONTAINER_TRACKER_SERVICE "org.freedesktop.Tracker"
#define RYGEL_TRACKER_SEARCH_CONTAINER_TRACKER_PATH "/org/freedesktop/Tracker"
#define RYGEL_TRACKER_SEARCH_CONTAINER_TRACKER_IFACE "org.freedesktop.Tracker"
#define RYGEL_TRACKER_SEARCH_CONTAINER_SEARCH_PATH "/org/freedesktop/Tracker/Search"
#define RYGEL_TRACKER_SEARCH_CONTAINER_SEARCH_IFACE "org.freedesktop.Tracker.Search"
#define RYGEL_TRACKER_SEARCH_CONTAINER_METADATA_PATH "/org/freedesktop/Tracker/Metadata"
#define RYGEL_TRACKER_SEARCH_CONTAINER_METADATA_IFACE "org.freedesktop.Tracker.Metadata"
static char** _vala_array_dup1 (char** self, int length);
static void rygel_tracker_search_container_create_proxies (RygelTrackerSearchContainer* self, GError** error);
static void rygel_tracker_search_container_get_children_count (RygelTrackerSearchContainer* self);
RygelTrackerSearchContainer* rygel_tracker_search_container_new (const char* id, RygelMediaContainer* parent, const char* title, const char* service, const char* query_condition, char** keywords, int keywords_length1);
RygelTrackerSearchContainer* rygel_tracker_search_container_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title, const char* service, const char* query_condition, char** keywords, int keywords_length1);
static void rygel_tracker_search_container_on_search_query_cb (RygelTrackerSearchContainer* self, char*** search_result, int search_result_length1, GError* _error_);
void _dynamic_Query2 (DBusGProxy* self, gint param1, const char* param2, char** param3, int param3_length1, const char* param4, char** param5, int param5_length1, const char* param6, gboolean param7, char** param8, int param8_length1, gboolean param9, gint param10, gint param11, gpointer param12, void* param12_target, GError** error);
RygelTrackerSearchResult* rygel_tracker_search_result_new (RygelTrackerSearchContainer* search_container, GAsyncReadyCallback callback, void* callback_target);
RygelTrackerSearchResult* rygel_tracker_search_result_construct (GType object_type, RygelTrackerSearchContainer* search_container, GAsyncReadyCallback callback, void* callback_target);
GType rygel_tracker_search_result_get_type (void);
char** rygel_tracker_item_get_metadata_keys (int* result_length1);
void rygel_tracker_search_result_ready (RygelTrackerSearchResult* self, char*** search_result, int search_result_length1, GError* _error_);
void _dynamic_Query3 (DBusGProxy* self, gint param1, const char* param2, char** param3, int param3_length1, const char* param4, char** param5, int param5_length1, const char* param6, gboolean param7, char** param8, int param8_length1, gboolean param9, gint param10, gint param11, gpointer param12, void* param12_target, GError** error);
static void rygel_tracker_search_container_real_get_children (RygelMediaContainer* base, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target);
static GeeList* rygel_tracker_search_container_real_get_children_finish (RygelMediaContainer* base, GAsyncResult* res, GError** error);
RygelTrackerGetMetadataResult* rygel_tracker_get_metadata_result_new (RygelTrackerSearchContainer* search_container, GAsyncReadyCallback callback, void* callback_target, const char* item_id);
RygelTrackerGetMetadataResult* rygel_tracker_get_metadata_result_construct (GType object_type, RygelTrackerSearchContainer* search_container, GAsyncReadyCallback callback, void* callback_target, const char* item_id);
GType rygel_tracker_get_metadata_result_get_type (void);
char* rygel_tracker_search_container_get_item_info (RygelTrackerSearchContainer* self, const char* item_id, char** parent_id, char** service);
void rygel_tracker_get_metadata_result_ready (RygelTrackerGetMetadataResult* self, char** metadata, int metadata_length1, GError* _error_);
void _dynamic_Get4 (DBusGProxy* self, const char* param1, const char* param2, char** param3, int param3_length1, gpointer param4, void* param4_target, GError** error);
static void rygel_tracker_search_container_real_find_object (RygelMediaContainer* base, const char* id, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target);
static RygelMediaObject* rygel_tracker_search_container_real_find_object_finish (RygelMediaContainer* base, GAsyncResult* res, GError** error);
gboolean rygel_tracker_search_container_is_thy_child (RygelTrackerSearchContainer* self, const char* item_id);
#define RYGEL_TRACKER_VIDEO_ITEM_SERVICE "Videos"
RygelTrackerVideoItem* rygel_tracker_video_item_new (const char* id, const char* path, RygelTrackerSearchContainer* parent, char** metadata, int metadata_length1);
RygelTrackerVideoItem* rygel_tracker_video_item_construct (GType object_type, const char* id, const char* path, RygelTrackerSearchContainer* parent, char** metadata, int metadata_length1);
GType rygel_tracker_item_get_type (void);
GType rygel_tracker_video_item_get_type (void);
#define RYGEL_TRACKER_IMAGE_ITEM_SERVICE "Images"
RygelTrackerImageItem* rygel_tracker_image_item_new (const char* id, const char* path, RygelTrackerSearchContainer* parent, char** metadata, int metadata_length1);
RygelTrackerImageItem* rygel_tracker_image_item_construct (GType object_type, const char* id, const char* path, RygelTrackerSearchContainer* parent, char** metadata, int metadata_length1);
GType rygel_tracker_image_item_get_type (void);
#define RYGEL_TRACKER_MUSIC_ITEM_SERVICE "Music"
RygelTrackerMusicItem* rygel_tracker_music_item_new (const char* id, const char* path, RygelTrackerSearchContainer* parent, char** metadata, int metadata_length1);
RygelTrackerMusicItem* rygel_tracker_music_item_construct (GType object_type, const char* id, const char* path, RygelTrackerSearchContainer* parent, char** metadata, int metadata_length1);
GType rygel_tracker_music_item_get_type (void);
RygelMediaItem* rygel_tracker_search_container_create_item (RygelTrackerSearchContainer* self, const char* service, const char* path, char** metadata, int metadata_length1);
static void rygel_tracker_search_container_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);
static int _vala_strcmp0 (const char * str1, const char * str2);



static char** _vala_array_dup1 (char** self, int length) {
	char** result;
	int i;
	result = g_new0 (char*, length);
	for (i = 0; i < length; i++) {
		result[i] = g_strdup (self[i]);
	}
	return result;
}


RygelTrackerSearchContainer* rygel_tracker_search_container_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title, const char* service, const char* query_condition, char** keywords, int keywords_length1) {
	GError * _inner_error_;
	RygelTrackerSearchContainer * self;
	gint _tmp0__length1;
	char** _tmp0_;
	char* _tmp1_;
	char** _tmp3_;
	char** _tmp2_;
	char* _tmp4_;
	g_return_val_if_fail (id != NULL, NULL);
	g_return_val_if_fail (parent != NULL, NULL);
	g_return_val_if_fail (title != NULL, NULL);
	g_return_val_if_fail (service != NULL, NULL);
	g_return_val_if_fail (query_condition != NULL, NULL);
	_inner_error_ = NULL;
	self = (RygelTrackerSearchContainer*) rygel_media_container_construct (object_type, id, parent, title, (guint) 0);
	_tmp0_ = (_vala_array_free (_tmp0_, _tmp0__length1, (GDestroyNotify) g_free), NULL);
	self->service = (_tmp1_ = g_strdup (service), _g_free0 (self->service), _tmp1_);
	self->keywords = (_tmp3_ = (_tmp2_ = keywords, (_tmp2_ == NULL) ? ((gpointer) _tmp2_) : _vala_array_dup1 (_tmp2_, keywords_length1)), self->keywords = (_vala_array_free (self->keywords, self->keywords_length1, (GDestroyNotify) g_free), NULL), self->keywords_length1 = keywords_length1, _tmp3_);
	self->query_condition = (_tmp4_ = g_strdup (query_condition), _g_free0 (self->query_condition), _tmp4_);
	{
		GeeList* _tmp5_;
		rygel_tracker_search_container_create_proxies (self, &_inner_error_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == DBUS_GERROR) {
				goto __catch2_dbus_gerror;
			}
			goto __finally2;
		}
		rygel_tracker_search_container_get_children_count (self);
		self->priv->results = (_tmp5_ = (GeeList*) gee_array_list_new (G_TYPE_ASYNC_RESULT, (GBoxedCopyFunc) g_object_ref, g_object_unref, g_direct_equal), _g_object_unref0 (self->priv->results), _tmp5_);
	}
	goto __finally2;
	__catch2_dbus_gerror:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
			g_critical ("rygel-tracker-search-container.vala:75: Failed to connect to session bus: %s\n", _error_->message);
			_g_error_free0 (_error_);
		}
	}
	__finally2:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	return self;
}


RygelTrackerSearchContainer* rygel_tracker_search_container_new (const char* id, RygelMediaContainer* parent, const char* title, const char* service, const char* query_condition, char** keywords, int keywords_length1) {
	return rygel_tracker_search_container_construct (RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, id, parent, title, service, query_condition, keywords, keywords_length1);
}


static void _rygel_tracker_search_container_on_search_query_cb_cb (DBusGProxy* proxy, DBusGProxyCall* call, void* user_data) {
	GError* error;
	GPtrArray* search_result;
	error = NULL;
	dbus_g_proxy_end_call (proxy, call, &error, dbus_g_type_get_collection ("GPtrArray", G_TYPE_STRV), &search_result, G_TYPE_INVALID);
	rygel_tracker_search_container_on_search_query_cb (user_data, search_result->pdata, search_result->len, error);
}


void _dynamic_Query2 (DBusGProxy* self, gint param1, const char* param2, char** param3, int param3_length1, const char* param4, char** param5, int param5_length1, const char* param6, gboolean param7, char** param8, int param8_length1, gboolean param9, gint param10, gint param11, gpointer param12, void* param12_target, GError** error) {
	dbus_g_proxy_begin_call (self, "Query", _rygel_tracker_search_container_on_search_query_cb_cb, param12_target, NULL, G_TYPE_INT, param1, G_TYPE_STRING, param2, G_TYPE_STRV, param3, G_TYPE_STRING, param4, G_TYPE_STRV, param5, G_TYPE_STRING, param6, G_TYPE_BOOLEAN, param7, G_TYPE_STRV, param8, G_TYPE_BOOLEAN, param9, G_TYPE_INT, param10, G_TYPE_INT, param11, G_TYPE_INVALID, G_TYPE_INVALID);
	if (*error) {
		return;
	}
}


static void rygel_tracker_search_container_get_children_count (RygelTrackerSearchContainer* self) {
	GError * _inner_error_;
	g_return_if_fail (self != NULL);
	_inner_error_ = NULL;
	{
		gint _tmp1__length1;
		char** _tmp1_;
		gint _tmp0__length1;
		char** _tmp0_;
		_dynamic_Query2 (self->search, 0, self->service, (_tmp0_ = g_new0 (char*, 0 + 1), _tmp0__length1 = 0, _tmp0_), 0, "", self->keywords, self->keywords_length1, self->query_condition, FALSE, (_tmp1_ = g_new0 (char*, 0 + 1), _tmp1__length1 = 0, _tmp1_), 0, FALSE, 0, -1, rygel_tracker_search_container_on_search_query_cb, self, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch3_g_error;
			goto __finally3;
		}
		_tmp1_ = (_vala_array_free (_tmp1_, _tmp1__length1, (GDestroyNotify) g_free), NULL);
		_tmp0_ = (_vala_array_free (_tmp0_, _tmp0__length1, (GDestroyNotify) g_free), NULL);
	}
	goto __finally3;
	__catch3_g_error:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
			g_critical ("rygel-tracker-search-container.vala:97: error getting items under service '%s': %s", self->service, _error_->message);
			_g_error_free0 (_error_);
			return;
		}
	}
	__finally3:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return;
	}
}


static void rygel_tracker_search_container_on_search_query_cb (RygelTrackerSearchContainer* self, char*** search_result, int search_result_length1, GError* _error_) {
	g_return_if_fail (self != NULL);
	if (_error_ != NULL) {
		g_critical ("rygel-tracker-search-container.vala:108: error getting items under service '%s': %s", self->service, _error_->message);
		return;
	}
	((RygelMediaContainer*) self)->child_count = (guint) search_result_length1;
	rygel_media_container_updated ((RygelMediaContainer*) self);
}


static void _rygel_tracker_search_result_ready_cb (DBusGProxy* proxy, DBusGProxyCall* call, void* user_data) {
	GError* error;
	GPtrArray* search_result;
	error = NULL;
	dbus_g_proxy_end_call (proxy, call, &error, dbus_g_type_get_collection ("GPtrArray", G_TYPE_STRV), &search_result, G_TYPE_INVALID);
	rygel_tracker_search_result_ready (user_data, search_result->pdata, search_result->len, error);
}


void _dynamic_Query3 (DBusGProxy* self, gint param1, const char* param2, char** param3, int param3_length1, const char* param4, char** param5, int param5_length1, const char* param6, gboolean param7, char** param8, int param8_length1, gboolean param9, gint param10, gint param11, gpointer param12, void* param12_target, GError** error) {
	dbus_g_proxy_begin_call (self, "Query", _rygel_tracker_search_result_ready_cb, param12_target, NULL, G_TYPE_INT, param1, G_TYPE_STRING, param2, G_TYPE_STRV, param3, G_TYPE_STRING, param4, G_TYPE_STRV, param5, G_TYPE_STRING, param6, G_TYPE_BOOLEAN, param7, G_TYPE_STRV, param8, G_TYPE_BOOLEAN, param9, G_TYPE_INT, param10, G_TYPE_INT, param11, G_TYPE_INVALID, G_TYPE_INVALID);
	if (*error) {
		return;
	}
}


static gpointer _g_error_copy0 (gpointer self) {
	return self ? g_error_copy (self) : NULL;
}


static void rygel_tracker_search_container_real_get_children (RygelMediaContainer* base, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target) {
	RygelTrackerSearchContainer * self;
	GError * _inner_error_;
	RygelTrackerSearchResult* res;
	self = (RygelTrackerSearchContainer*) base;
	_inner_error_ = NULL;
	res = rygel_tracker_search_result_new (self, callback, callback_target);
	gee_collection_add ((GeeCollection*) self->priv->results, (GAsyncResult*) res);
	{
		char** _tmp3_;
		gint _tmp2__length1;
		char** _tmp2_;
		gint _tmp1__length1;
		char** _tmp1_;
		gint _tmp0_;
		_tmp3_ = (_tmp1_ = rygel_tracker_item_get_metadata_keys (&_tmp0_), _tmp1__length1 = _tmp0_, _tmp1_);
		_dynamic_Query3 (self->search, 0, self->service, _tmp3_, _tmp0_, "", self->keywords, self->keywords_length1, self->query_condition, FALSE, (_tmp2_ = g_new0 (char*, 0 + 1), _tmp2__length1 = 0, _tmp2_), 0, FALSE, (gint) offset, (gint) max_count, rygel_tracker_search_result_ready, res, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch4_g_error;
			goto __finally4;
		}
		_tmp2_ = (_vala_array_free (_tmp2_, _tmp2__length1, (GDestroyNotify) g_free), NULL);
		_tmp1_ = (_vala_array_free (_tmp1_, _tmp1__length1, (GDestroyNotify) g_free), NULL);
	}
	goto __finally4;
	__catch4_g_error:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
			GError* _tmp4_;
			((RygelSimpleAsyncResult*) res)->error = (_tmp4_ = _g_error_copy0 (_error_), _g_error_free0 (((RygelSimpleAsyncResult*) res)->error), _tmp4_);
			rygel_simple_async_result_complete_in_idle ((RygelSimpleAsyncResult*) res);
			_g_error_free0 (_error_);
		}
	}
	__finally4:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (res);
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return;
	}
	_g_object_unref0 (res);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static GeeList* rygel_tracker_search_container_real_get_children_finish (RygelMediaContainer* base, GAsyncResult* res, GError** error) {
	RygelTrackerSearchContainer * self;
	GeeList* result;
	GError * _inner_error_;
	RygelTrackerSearchResult* search_res;
	self = (RygelTrackerSearchContainer*) base;
	g_return_val_if_fail (res != NULL, NULL);
	_inner_error_ = NULL;
	search_res = _g_object_ref0 (RYGEL_TRACKER_SEARCH_RESULT (res));
	gee_collection_remove ((GeeCollection*) self->priv->results, (GAsyncResult*) search_res);
	if (((RygelSimpleAsyncResult*) search_res)->error != NULL) {
		_inner_error_ = _g_error_copy0 (((RygelSimpleAsyncResult*) search_res)->error);
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_g_object_unref0 (search_res);
			return NULL;
		}
	} else {
		result = _g_object_ref0 ((GeeList*) ((RygelSimpleAsyncResult*) search_res)->data);
		_g_object_unref0 (search_res);
		return result;
	}
	_g_object_unref0 (search_res);
}


static void _rygel_tracker_get_metadata_result_ready_cb (DBusGProxy* proxy, DBusGProxyCall* call, void* user_data) {
	GError* error;
	char** metadata;
	error = NULL;
	dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_STRV, &metadata, G_TYPE_INVALID);
	rygel_tracker_get_metadata_result_ready (user_data, metadata, g_strv_length (metadata), error);
}


void _dynamic_Get4 (DBusGProxy* self, const char* param1, const char* param2, char** param3, int param3_length1, gpointer param4, void* param4_target, GError** error) {
	dbus_g_proxy_begin_call (self, "Get", _rygel_tracker_get_metadata_result_ready_cb, param4_target, NULL, G_TYPE_STRING, param1, G_TYPE_STRING, param2, G_TYPE_STRV, param3, G_TYPE_INVALID, G_TYPE_INVALID);
	if (*error) {
		return;
	}
}


static void rygel_tracker_search_container_real_find_object (RygelMediaContainer* base, const char* id, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target) {
	RygelTrackerSearchContainer * self;
	GError * _inner_error_;
	RygelTrackerGetMetadataResult* res;
	self = (RygelTrackerSearchContainer*) base;
	g_return_if_fail (id != NULL);
	_inner_error_ = NULL;
	res = rygel_tracker_get_metadata_result_new (self, callback, callback_target, id);
	gee_collection_add ((GeeCollection*) self->priv->results, (GAsyncResult*) res);
	{
		char* parent_id;
		char* _tmp6_;
		char* _tmp5_;
		char* _tmp4_;
		char* _tmp3_;
		char* _tmp2_;
		char* _tmp1_;
		char* _tmp0_;
		char** _tmp8_;
		gint keys_size;
		gint keys_length1;
		gint _tmp7_;
		char** keys;
		parent_id = NULL;
		_tmp3_ = NULL;
		_tmp0_ = NULL;
		res->item_path = (_tmp6_ = (_tmp4_ = (_tmp1_ = rygel_tracker_search_container_get_item_info (self, id, &_tmp0_, &_tmp3_), parent_id = (_tmp2_ = _tmp0_, _g_free0 (parent_id), _tmp2_), _tmp1_), res->item_service = (_tmp5_ = _tmp3_, _g_free0 (res->item_service), _tmp5_), _tmp4_), _g_free0 (res->item_path), _tmp6_);
		if (res->item_path == NULL) {
			rygel_simple_async_result_complete_in_idle ((RygelSimpleAsyncResult*) res);
			_g_free0 (parent_id);
			_g_object_unref0 (res);
			return;
		}
		keys = (_tmp8_ = rygel_tracker_item_get_metadata_keys (&_tmp7_), keys_length1 = _tmp7_, keys_size = keys_length1, _tmp8_);
		_dynamic_Get4 (self->metadata, res->item_service, res->item_path, keys, keys_length1, rygel_tracker_get_metadata_result_ready, res, &_inner_error_);
		if (_inner_error_ != NULL) {
			_g_free0 (parent_id);
			keys = (_vala_array_free (keys, keys_length1, (GDestroyNotify) g_free), NULL);
			goto __catch5_g_error;
			goto __finally5;
		}
		_g_free0 (parent_id);
		keys = (_vala_array_free (keys, keys_length1, (GDestroyNotify) g_free), NULL);
	}
	goto __finally5;
	__catch5_g_error:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
			GError* _tmp9_;
			((RygelSimpleAsyncResult*) res)->error = (_tmp9_ = _g_error_copy0 (_error_), _g_error_free0 (((RygelSimpleAsyncResult*) res)->error), _tmp9_);
			rygel_simple_async_result_complete_in_idle ((RygelSimpleAsyncResult*) res);
			_g_error_free0 (_error_);
		}
	}
	__finally5:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (res);
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return;
	}
	_g_object_unref0 (res);
}


static RygelMediaObject* rygel_tracker_search_container_real_find_object_finish (RygelMediaContainer* base, GAsyncResult* res, GError** error) {
	RygelTrackerSearchContainer * self;
	RygelMediaObject* result;
	GError * _inner_error_;
	RygelTrackerGetMetadataResult* metadata_res;
	self = (RygelTrackerSearchContainer*) base;
	g_return_val_if_fail (res != NULL, NULL);
	_inner_error_ = NULL;
	metadata_res = _g_object_ref0 (RYGEL_TRACKER_GET_METADATA_RESULT (res));
	if (((RygelSimpleAsyncResult*) metadata_res)->error != NULL) {
		_inner_error_ = _g_error_copy0 (((RygelSimpleAsyncResult*) metadata_res)->error);
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_g_object_unref0 (metadata_res);
			return NULL;
		}
	} else {
		result = _g_object_ref0 ((RygelMediaObject*) ((RygelSimpleAsyncResult*) metadata_res)->data);
		_g_object_unref0 (metadata_res);
		return result;
	}
	_g_object_unref0 (metadata_res);
}


gboolean rygel_tracker_search_container_is_thy_child (RygelTrackerSearchContainer* self, const char* item_id) {
	gboolean result;
	char* parent_id;
	char* _tmp6_;
	char* _tmp5_;
	char* _tmp4_;
	char* _tmp3_;
	char* _tmp2_;
	char* _tmp1_;
	char* _tmp0_;
	gboolean _tmp7_;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (item_id != NULL, FALSE);
	parent_id = NULL;
	_tmp3_ = NULL;
	_tmp0_ = NULL;
	_tmp6_ = (_tmp4_ = (_tmp1_ = rygel_tracker_search_container_get_item_info (self, ((RygelMediaObject*) self)->id, &_tmp0_, &_tmp3_), parent_id = (_tmp2_ = _tmp0_, _g_free0 (parent_id), _tmp2_), _tmp1_), self->service = (_tmp5_ = _tmp3_, _g_free0 (self->service), _tmp5_), _tmp4_);
	_g_free0 (_tmp6_);
	_tmp7_ = FALSE;
	if (parent_id != NULL) {
		_tmp7_ = _vala_strcmp0 (parent_id, ((RygelMediaObject*) self)->id) == 0;
	} else {
		_tmp7_ = FALSE;
	}
	if (_tmp7_) {
		result = TRUE;
		_g_free0 (parent_id);
		return result;
	} else {
		result = FALSE;
		_g_free0 (parent_id);
		return result;
	}
	_g_free0 (parent_id);
}


RygelMediaItem* rygel_tracker_search_container_create_item (RygelTrackerSearchContainer* self, const char* service, const char* path, char** metadata, int metadata_length1) {
	RygelMediaItem* result;
	char* _tmp2_;
	char* _tmp1_;
	char* _tmp0_;
	char* _tmp3_;
	char* id;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (service != NULL, NULL);
	g_return_val_if_fail (path != NULL, NULL);
	id = (_tmp3_ = g_strconcat (_tmp2_ = g_strconcat (_tmp1_ = g_strconcat (_tmp0_ = g_strconcat (service, ":", NULL), ((RygelMediaObject*) self)->id, NULL), ":", NULL), path, NULL), _g_free0 (_tmp2_), _g_free0 (_tmp1_), _g_free0 (_tmp0_), _tmp3_);
	if (_vala_strcmp0 (service, RYGEL_TRACKER_VIDEO_ITEM_SERVICE) == 0) {
		result = (RygelMediaItem*) rygel_tracker_video_item_new (id, path, self, metadata, metadata_length1);
		_g_free0 (id);
		return result;
	} else {
		if (_vala_strcmp0 (service, RYGEL_TRACKER_IMAGE_ITEM_SERVICE) == 0) {
			result = (RygelMediaItem*) rygel_tracker_image_item_new (id, path, self, metadata, metadata_length1);
			_g_free0 (id);
			return result;
		} else {
			if (_vala_strcmp0 (service, RYGEL_TRACKER_MUSIC_ITEM_SERVICE) == 0) {
				result = (RygelMediaItem*) rygel_tracker_music_item_new (id, path, self, metadata, metadata_length1);
				_g_free0 (id);
				return result;
			} else {
				result = NULL;
				_g_free0 (id);
				return result;
			}
		}
	}
	_g_free0 (id);
}


char* rygel_tracker_search_container_get_item_info (RygelTrackerSearchContainer* self, const char* item_id, char** parent_id, char** service) {
	char* result;
	char** _tmp1_;
	gint tokens_size;
	gint tokens_length1;
	char** _tmp0_;
	char** tokens;
	gboolean _tmp2_;
	gboolean _tmp3_;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (item_id != NULL, NULL);
	if (parent_id != NULL) {
		*parent_id = NULL;
	}
	if (service != NULL) {
		*service = NULL;
	}
	tokens = (_tmp1_ = _tmp0_ = g_strsplit (item_id, ":", 3), tokens_length1 = _vala_array_length (_tmp0_), tokens_size = tokens_length1, _tmp1_);
	_tmp2_ = FALSE;
	_tmp3_ = FALSE;
	if (tokens[0] != NULL) {
		_tmp3_ = tokens[1] != NULL;
	} else {
		_tmp3_ = FALSE;
	}
	if (_tmp3_) {
		_tmp2_ = tokens[2] != NULL;
	} else {
		_tmp2_ = FALSE;
	}
	if (_tmp2_) {
		char* _tmp4_;
		char* _tmp5_;
		(*service) = (_tmp4_ = g_strdup (tokens[0]), _g_free0 ((*service)), _tmp4_);
		(*parent_id) = (_tmp5_ = g_strdup (tokens[1]), _g_free0 ((*parent_id)), _tmp5_);
		result = g_strdup (tokens[2]);
		tokens = (_vala_array_free (tokens, tokens_length1, (GDestroyNotify) g_free), NULL);
		return result;
	} else {
		result = NULL;
		tokens = (_vala_array_free (tokens, tokens_length1, (GDestroyNotify) g_free), NULL);
		return result;
	}
	tokens = (_vala_array_free (tokens, tokens_length1, (GDestroyNotify) g_free), NULL);
}


static void rygel_tracker_search_container_create_proxies (RygelTrackerSearchContainer* self, GError** error) {
	GError * _inner_error_;
	DBusGConnection* connection;
	DBusGProxy* _tmp0_;
	DBusGProxy* _tmp1_;
	DBusGProxy* _tmp2_;
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
	self->metadata = (_tmp0_ = dbus_g_proxy_new_for_name (connection, RYGEL_TRACKER_SEARCH_CONTAINER_TRACKER_SERVICE, RYGEL_TRACKER_SEARCH_CONTAINER_METADATA_PATH, RYGEL_TRACKER_SEARCH_CONTAINER_METADATA_IFACE), _g_object_unref0 (self->metadata), _tmp0_);
	self->search = (_tmp1_ = dbus_g_proxy_new_for_name (connection, RYGEL_TRACKER_SEARCH_CONTAINER_TRACKER_SERVICE, RYGEL_TRACKER_SEARCH_CONTAINER_SEARCH_PATH, RYGEL_TRACKER_SEARCH_CONTAINER_SEARCH_IFACE), _g_object_unref0 (self->search), _tmp1_);
	self->tracker = (_tmp2_ = dbus_g_proxy_new_for_name (connection, RYGEL_TRACKER_SEARCH_CONTAINER_TRACKER_SERVICE, RYGEL_TRACKER_SEARCH_CONTAINER_TRACKER_PATH, RYGEL_TRACKER_SEARCH_CONTAINER_TRACKER_IFACE), _g_object_unref0 (self->tracker), _tmp2_);
	_dbus_g_connection_unref0 (connection);
}


static void rygel_tracker_search_container_class_init (RygelTrackerSearchContainerClass * klass) {
	rygel_tracker_search_container_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelTrackerSearchContainerPrivate));
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->get_children = rygel_tracker_search_container_real_get_children;
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->get_children_finish = rygel_tracker_search_container_real_get_children_finish;
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->find_object = rygel_tracker_search_container_real_find_object;
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->find_object_finish = rygel_tracker_search_container_real_find_object_finish;
	G_OBJECT_CLASS (klass)->finalize = rygel_tracker_search_container_finalize;
}


static void rygel_tracker_search_container_instance_init (RygelTrackerSearchContainer * self) {
	self->priv = RYGEL_TRACKER_SEARCH_CONTAINER_GET_PRIVATE (self);
}


static void rygel_tracker_search_container_finalize (GObject* obj) {
	RygelTrackerSearchContainer * self;
	self = RYGEL_TRACKER_SEARCH_CONTAINER (obj);
	_g_object_unref0 (self->metadata);
	_g_object_unref0 (self->search);
	_g_object_unref0 (self->tracker);
	_g_free0 (self->service);
	_g_free0 (self->query_condition);
	self->keywords = (_vala_array_free (self->keywords, self->keywords_length1, (GDestroyNotify) g_free), NULL);
	_g_object_unref0 (self->priv->results);
	G_OBJECT_CLASS (rygel_tracker_search_container_parent_class)->finalize (obj);
}


GType rygel_tracker_search_container_get_type (void) {
	static GType rygel_tracker_search_container_type_id = 0;
	if (rygel_tracker_search_container_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelTrackerSearchContainerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_tracker_search_container_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelTrackerSearchContainer), 0, (GInstanceInitFunc) rygel_tracker_search_container_instance_init, NULL };
		rygel_tracker_search_container_type_id = g_type_register_static (RYGEL_TYPE_MEDIA_CONTAINER, "RygelTrackerSearchContainer", &g_define_type_info, 0);
	}
	return rygel_tracker_search_container_type_id;
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


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
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




