/* rygel-tracker-category-all-container.c generated by valac, the Vala compiler
 * generated from rygel-tracker-category-all-container.vala, do not modify */

/*
 * Copyright (C) 2008 Zeeshan Ali <zeenix@gmail.com>.
 * Copyright (C) 2008-2010 Nokia Corporation.
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
#include <gee.h>
#include <glib/gi18n-lib.h>
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

#define RYGEL_TYPE_TRACKER_QUERY (rygel_tracker_query_get_type ())
#define RYGEL_TRACKER_QUERY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_QUERY, RygelTrackerQuery))
#define RYGEL_TRACKER_QUERY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_QUERY, RygelTrackerQueryClass))
#define RYGEL_IS_TRACKER_QUERY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_QUERY))
#define RYGEL_IS_TRACKER_QUERY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_QUERY))
#define RYGEL_TRACKER_QUERY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_QUERY, RygelTrackerQueryClass))

typedef struct _RygelTrackerQuery RygelTrackerQuery;
typedef struct _RygelTrackerQueryClass RygelTrackerQueryClass;

#define RYGEL_TYPE_TRACKER_SELECTION_QUERY (rygel_tracker_selection_query_get_type ())
#define RYGEL_TRACKER_SELECTION_QUERY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_SELECTION_QUERY, RygelTrackerSelectionQuery))
#define RYGEL_TRACKER_SELECTION_QUERY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_SELECTION_QUERY, RygelTrackerSelectionQueryClass))
#define RYGEL_IS_TRACKER_SELECTION_QUERY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_SELECTION_QUERY))
#define RYGEL_IS_TRACKER_SELECTION_QUERY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_SELECTION_QUERY))
#define RYGEL_TRACKER_SELECTION_QUERY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_SELECTION_QUERY, RygelTrackerSelectionQueryClass))

typedef struct _RygelTrackerSelectionQuery RygelTrackerSelectionQuery;
typedef struct _RygelTrackerSelectionQueryClass RygelTrackerSelectionQueryClass;

#define RYGEL_TYPE_TRACKER_ITEM_FACTORY (rygel_tracker_item_factory_get_type ())
#define RYGEL_TRACKER_ITEM_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_ITEM_FACTORY, RygelTrackerItemFactory))
#define RYGEL_TRACKER_ITEM_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_ITEM_FACTORY, RygelTrackerItemFactoryClass))
#define RYGEL_IS_TRACKER_ITEM_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_ITEM_FACTORY))
#define RYGEL_IS_TRACKER_ITEM_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_ITEM_FACTORY))
#define RYGEL_TRACKER_ITEM_FACTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_ITEM_FACTORY, RygelTrackerItemFactoryClass))

typedef struct _RygelTrackerItemFactory RygelTrackerItemFactory;
typedef struct _RygelTrackerItemFactoryClass RygelTrackerItemFactoryClass;

#define RYGEL_TYPE_TRACKER_CATEGORY_ALL_CONTAINER (rygel_tracker_category_all_container_get_type ())
#define RYGEL_TRACKER_CATEGORY_ALL_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_CATEGORY_ALL_CONTAINER, RygelTrackerCategoryAllContainer))
#define RYGEL_TRACKER_CATEGORY_ALL_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_CATEGORY_ALL_CONTAINER, RygelTrackerCategoryAllContainerClass))
#define RYGEL_IS_TRACKER_CATEGORY_ALL_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_CATEGORY_ALL_CONTAINER))
#define RYGEL_IS_TRACKER_CATEGORY_ALL_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_CATEGORY_ALL_CONTAINER))
#define RYGEL_TRACKER_CATEGORY_ALL_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_CATEGORY_ALL_CONTAINER, RygelTrackerCategoryAllContainerClass))

typedef struct _RygelTrackerCategoryAllContainer RygelTrackerCategoryAllContainer;
typedef struct _RygelTrackerCategoryAllContainerClass RygelTrackerCategoryAllContainerClass;
typedef struct _RygelTrackerCategoryAllContainerPrivate RygelTrackerCategoryAllContainerPrivate;

#define RYGEL_TYPE_TRACKER_CATEGORY_CONTAINER (rygel_tracker_category_container_get_type ())
#define RYGEL_TRACKER_CATEGORY_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_CATEGORY_CONTAINER, RygelTrackerCategoryContainer))
#define RYGEL_TRACKER_CATEGORY_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_CATEGORY_CONTAINER, RygelTrackerCategoryContainerClass))
#define RYGEL_IS_TRACKER_CATEGORY_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_CATEGORY_CONTAINER))
#define RYGEL_IS_TRACKER_CATEGORY_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_CATEGORY_CONTAINER))
#define RYGEL_TRACKER_CATEGORY_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_CATEGORY_CONTAINER, RygelTrackerCategoryContainerClass))

typedef struct _RygelTrackerCategoryContainer RygelTrackerCategoryContainer;
typedef struct _RygelTrackerCategoryContainerClass RygelTrackerCategoryContainerClass;
typedef struct _RygelTrackerCategoryContainerPrivate RygelTrackerCategoryContainerPrivate;

#define RYGEL_TYPE_TRACKER_QUERY_TRIPLETS (rygel_tracker_query_triplets_get_type ())
#define RYGEL_TRACKER_QUERY_TRIPLETS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_QUERY_TRIPLETS, RygelTrackerQueryTriplets))
#define RYGEL_TRACKER_QUERY_TRIPLETS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_QUERY_TRIPLETS, RygelTrackerQueryTripletsClass))
#define RYGEL_IS_TRACKER_QUERY_TRIPLETS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_QUERY_TRIPLETS))
#define RYGEL_IS_TRACKER_QUERY_TRIPLETS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_QUERY_TRIPLETS))
#define RYGEL_TRACKER_QUERY_TRIPLETS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_QUERY_TRIPLETS, RygelTrackerQueryTripletsClass))

typedef struct _RygelTrackerQueryTriplets RygelTrackerQueryTriplets;
typedef struct _RygelTrackerQueryTripletsClass RygelTrackerQueryTripletsClass;
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _RygelTrackerItemFactoryPrivate RygelTrackerItemFactoryPrivate;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define RYGEL_TYPE_TRACKER_ITEM_CREATION (rygel_tracker_item_creation_get_type ())
#define RYGEL_TRACKER_ITEM_CREATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_ITEM_CREATION, RygelTrackerItemCreation))
#define RYGEL_TRACKER_ITEM_CREATION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_ITEM_CREATION, RygelTrackerItemCreationClass))
#define RYGEL_IS_TRACKER_ITEM_CREATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_ITEM_CREATION))
#define RYGEL_IS_TRACKER_ITEM_CREATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_ITEM_CREATION))
#define RYGEL_TRACKER_ITEM_CREATION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_ITEM_CREATION, RygelTrackerItemCreationClass))

typedef struct _RygelTrackerItemCreation RygelTrackerItemCreation;
typedef struct _RygelTrackerItemCreationClass RygelTrackerItemCreationClass;
typedef struct _RygelTrackerCategoryAllContainerAddItemData RygelTrackerCategoryAllContainerAddItemData;

struct _RygelTrackerSearchContainer {
	RygelMediaContainer parent_instance;
	RygelTrackerSearchContainerPrivate * priv;
	RygelTrackerSelectionQuery* query;
	RygelTrackerItemFactory* item_factory;
};

struct _RygelTrackerSearchContainerClass {
	RygelMediaContainerClass parent_class;
};

struct _RygelTrackerCategoryAllContainer {
	RygelTrackerSearchContainer parent_instance;
	RygelTrackerCategoryAllContainerPrivate * priv;
};

struct _RygelTrackerCategoryAllContainerClass {
	RygelTrackerSearchContainerClass parent_class;
};

struct _RygelTrackerCategoryContainer {
	RygelSimpleContainer parent_instance;
	RygelTrackerCategoryContainerPrivate * priv;
	RygelTrackerItemFactory* item_factory;
};

struct _RygelTrackerCategoryContainerClass {
	RygelSimpleContainerClass parent_class;
};

struct _RygelTrackerItemFactory {
	GTypeInstance parent_instance;
	volatile int ref_count;
	RygelTrackerItemFactoryPrivate * priv;
	char* category;
	char* upnp_class;
	char* resources_class_path;
	char* upload_dir;
	GeeArrayList* key_chains;
};

struct _RygelTrackerItemFactoryClass {
	GTypeClass parent_class;
	void (*finalize) (RygelTrackerItemFactory *self);
	RygelMediaItem* (*create) (RygelTrackerItemFactory* self, const char* id, const char* uri, RygelTrackerSearchContainer* parent, char** metadata, int metadata_length1, GError** error);
};

struct _RygelTrackerCategoryAllContainerAddItemData {
	int _state_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	RygelTrackerCategoryAllContainer* self;
	RygelMediaItem* item;
	GCancellable* cancellable;
	RygelTrackerItemCreation* creation;
	GError * _inner_error_;
};


static gpointer rygel_tracker_category_all_container_parent_class = NULL;

GType rygel_tracker_search_container_get_type (void);
gpointer rygel_tracker_query_ref (gpointer instance);
void rygel_tracker_query_unref (gpointer instance);
GParamSpec* rygel_param_spec_tracker_query (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_tracker_query (GValue* value, gpointer v_object);
void rygel_value_take_tracker_query (GValue* value, gpointer v_object);
gpointer rygel_value_get_tracker_query (const GValue* value);
GType rygel_tracker_query_get_type (void);
GType rygel_tracker_selection_query_get_type (void);
gpointer rygel_tracker_item_factory_ref (gpointer instance);
void rygel_tracker_item_factory_unref (gpointer instance);
GParamSpec* rygel_param_spec_tracker_item_factory (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_tracker_item_factory (GValue* value, gpointer v_object);
void rygel_value_take_tracker_item_factory (GValue* value, gpointer v_object);
gpointer rygel_value_get_tracker_item_factory (const GValue* value);
GType rygel_tracker_item_factory_get_type (void);
GType rygel_tracker_category_all_container_get_type (void);
enum  {
	RYGEL_TRACKER_CATEGORY_ALL_CONTAINER_DUMMY_PROPERTY
};
GType rygel_tracker_category_container_get_type (void);
GType rygel_tracker_query_triplets_get_type (void);
RygelTrackerSearchContainer* rygel_tracker_search_container_new (const char* id, RygelMediaContainer* parent, const char* title, RygelTrackerItemFactory* item_factory, RygelTrackerQueryTriplets* mandatory, GeeArrayList* filters);
RygelTrackerSearchContainer* rygel_tracker_search_container_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title, RygelTrackerItemFactory* item_factory, RygelTrackerQueryTriplets* mandatory, GeeArrayList* filters);
RygelTrackerCategoryAllContainer* rygel_tracker_category_all_container_new (RygelTrackerCategoryContainer* parent);
RygelTrackerCategoryAllContainer* rygel_tracker_category_all_container_construct (GType object_type, RygelTrackerCategoryContainer* parent);
static void rygel_tracker_category_all_container_real_add_item_data_free (gpointer _data);
static void rygel_tracker_category_all_container_real_add_item (RygelMediaContainer* base, RygelMediaItem* item, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
static void rygel_tracker_category_all_container_add_item_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
RygelTrackerItemCreation* rygel_tracker_item_creation_new (RygelMediaItem* item, RygelTrackerCategoryAllContainer* container, GCancellable* cancellable, GError** error);
RygelTrackerItemCreation* rygel_tracker_item_creation_construct (GType object_type, RygelMediaItem* item, RygelTrackerCategoryAllContainer* container, GCancellable* cancellable, GError** error);
GType rygel_tracker_item_creation_get_type (void);
GError* rygel_tracker_item_creation_get_error (RygelTrackerItemCreation* self);
static gboolean rygel_tracker_category_all_container_real_add_item_co (RygelTrackerCategoryAllContainerAddItemData* data);



#line 31 "rygel-tracker-category-all-container.vala"
RygelTrackerCategoryAllContainer* rygel_tracker_category_all_container_construct (GType object_type, RygelTrackerCategoryContainer* parent) {
#line 227 "rygel-tracker-category-all-container.c"
	GError * _inner_error_;
	RygelTrackerCategoryAllContainer * self;
	char* _tmp0_;
#line 31 "rygel-tracker-category-all-container.vala"
	g_return_val_if_fail (parent != NULL, NULL);
#line 233 "rygel-tracker-category-all-container.c"
	_inner_error_ = NULL;
#line 32 "rygel-tracker-category-all-container.vala"
	self = (RygelTrackerCategoryAllContainer*) rygel_tracker_search_container_construct (object_type, _tmp0_ = g_strconcat ("All", ((RygelMediaObject*) parent)->id, NULL), (RygelMediaContainer*) parent, "All", parent->item_factory, NULL, NULL);
#line 237 "rygel-tracker-category-all-container.c"
	_g_free0 (_tmp0_);
	{
		char* uri;
#line 35 "rygel-tracker-category-all-container.vala"
		uri = g_filename_to_uri (((RygelTrackerSearchContainer*) self)->item_factory->upload_dir, NULL, &_inner_error_);
#line 243 "rygel-tracker-category-all-container.c"
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_CONVERT_ERROR) {
				goto __catch7_g_convert_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
#line 36 "rygel-tracker-category-all-container.vala"
		gee_abstract_collection_add ((GeeAbstractCollection*) ((RygelMediaObject*) self)->uris, uri);
#line 254 "rygel-tracker-category-all-container.c"
		_g_free0 (uri);
	}
	goto __finally7;
	__catch7_g_convert_error:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
#line 38 "rygel-tracker-category-all-container.vala"
			g_warning (_ ("Failed to construct URI for folder '%s': %s"), ((RygelTrackerSearchContainer*) self)->item_factory->upload_dir, _error_->message);
#line 266 "rygel-tracker-category-all-container.c"
			_g_error_free0 (_error_);
		}
	}
	__finally7:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	return self;
}


#line 31 "rygel-tracker-category-all-container.vala"
RygelTrackerCategoryAllContainer* rygel_tracker_category_all_container_new (RygelTrackerCategoryContainer* parent) {
#line 31 "rygel-tracker-category-all-container.vala"
	return rygel_tracker_category_all_container_construct (RYGEL_TYPE_TRACKER_CATEGORY_ALL_CONTAINER, parent);
#line 284 "rygel-tracker-category-all-container.c"
}


static void rygel_tracker_category_all_container_real_add_item_data_free (gpointer _data) {
	RygelTrackerCategoryAllContainerAddItemData* data;
	data = _data;
	_g_object_unref0 (data->item);
	_g_object_unref0 (data->cancellable);
	g_object_unref (data->self);
	g_slice_free (RygelTrackerCategoryAllContainerAddItemData, data);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void rygel_tracker_category_all_container_real_add_item (RygelMediaContainer* base, RygelMediaItem* item, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	RygelTrackerCategoryAllContainer * self;
	RygelTrackerCategoryAllContainerAddItemData* _data_;
	self = (RygelTrackerCategoryAllContainer*) base;
	_data_ = g_slice_new0 (RygelTrackerCategoryAllContainerAddItemData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, rygel_tracker_category_all_container_real_add_item);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, rygel_tracker_category_all_container_real_add_item_data_free);
	_data_->self = g_object_ref (self);
	_data_->item = _g_object_ref0 (item);
	_data_->cancellable = _g_object_ref0 (cancellable);
	rygel_tracker_category_all_container_real_add_item_co (_data_);
}


static void rygel_tracker_category_all_container_real_add_item_finish (RygelMediaContainer* base, GAsyncResult* _res_, GError** error) {
	RygelTrackerCategoryAllContainerAddItemData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void rygel_tracker_category_all_container_add_item_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	RygelTrackerCategoryAllContainerAddItemData* data;
	data = _user_data_;
	data->_res_ = _res_;
	rygel_tracker_category_all_container_real_add_item_co (data);
}


static gpointer _g_error_copy0 (gpointer self) {
	return self ? g_error_copy (self) : NULL;
}


static gboolean rygel_tracker_category_all_container_real_add_item_co (RygelTrackerCategoryAllContainerAddItemData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		case 6:
		goto _state_6;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	{
#line 47 "rygel-tracker-category-all-container.vala"
		g_assert (gee_collection_get_size ((GeeCollection*) ((RygelMediaObject*) data->self)->uris) > 0);
#line 352 "rygel-tracker-category-all-container.c"
		data->creation = rygel_tracker_item_creation_new (data->item, data->self, data->cancellable, &data->_inner_error_);
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
		data->_state_ = 6;
		rygel_state_machine_run ((RygelStateMachine*) data->creation, rygel_tracker_category_all_container_add_item_ready, data);
		return FALSE;
		_state_6:
#line 50 "rygel-tracker-category-all-container.vala"
		rygel_state_machine_run_finish ((RygelStateMachine*) data->creation, data->_res_);
#line 51 "rygel-tracker-category-all-container.vala"
		if (rygel_tracker_item_creation_get_error (data->creation) != NULL) {
#line 375 "rygel-tracker-category-all-container.c"
			data->_inner_error_ = _g_error_copy0 (rygel_tracker_item_creation_get_error (data->creation));
			{
				g_simple_async_result_set_from_error (data->_async_result, data->_inner_error_);
				g_error_free (data->_inner_error_);
				_g_object_unref0 (data->creation);
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
		}
		_g_object_unref0 (data->creation);
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


static void rygel_tracker_category_all_container_class_init (RygelTrackerCategoryAllContainerClass * klass) {
	rygel_tracker_category_all_container_parent_class = g_type_class_peek_parent (klass);
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->add_item = rygel_tracker_category_all_container_real_add_item;
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->add_item_finish = rygel_tracker_category_all_container_real_add_item_finish;
}


static void rygel_tracker_category_all_container_instance_init (RygelTrackerCategoryAllContainer * self) {
}


GType rygel_tracker_category_all_container_get_type (void) {
	static volatile gsize rygel_tracker_category_all_container_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_tracker_category_all_container_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelTrackerCategoryAllContainerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_tracker_category_all_container_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelTrackerCategoryAllContainer), 0, (GInstanceInitFunc) rygel_tracker_category_all_container_instance_init, NULL };
		GType rygel_tracker_category_all_container_type_id;
		rygel_tracker_category_all_container_type_id = g_type_register_static (RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, "RygelTrackerCategoryAllContainer", &g_define_type_info, 0);
		g_once_init_leave (&rygel_tracker_category_all_container_type_id__volatile, rygel_tracker_category_all_container_type_id);
	}
	return rygel_tracker_category_all_container_type_id__volatile;
}




