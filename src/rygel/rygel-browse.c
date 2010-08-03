/* rygel-browse.c generated by valac, the Vala compiler
 * generated from rygel-browse.vala, do not modify */

/*
 * Copyright (C) 2008 Zeeshan Ali <zeenix@gmail.com>.
 * Copyright (C) 2007 OpenedHand Ltd.
 *
 * Author: Zeeshan Ali <zeenix@gmail.com>
 *         Jorn Baayen <jorn@openedhand.com>
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
#include <gee.h>
#include <stdlib.h>
#include <string.h>
#include <libgupnp/gupnp.h>
#include <libgupnp-av/gupnp-av.h>
#include <glib/gi18n-lib.h>


#define RYGEL_TYPE_STATE_MACHINE (rygel_state_machine_get_type ())
#define RYGEL_STATE_MACHINE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_STATE_MACHINE, RygelStateMachine))
#define RYGEL_IS_STATE_MACHINE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_STATE_MACHINE))
#define RYGEL_STATE_MACHINE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), RYGEL_TYPE_STATE_MACHINE, RygelStateMachineIface))

typedef struct _RygelStateMachine RygelStateMachine;
typedef struct _RygelStateMachineIface RygelStateMachineIface;

#define RYGEL_TYPE_MEDIA_QUERY_ACTION (rygel_media_query_action_get_type ())
#define RYGEL_MEDIA_QUERY_ACTION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_QUERY_ACTION, RygelMediaQueryAction))
#define RYGEL_MEDIA_QUERY_ACTION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_QUERY_ACTION, RygelMediaQueryActionClass))
#define RYGEL_IS_MEDIA_QUERY_ACTION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_QUERY_ACTION))
#define RYGEL_IS_MEDIA_QUERY_ACTION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_QUERY_ACTION))
#define RYGEL_MEDIA_QUERY_ACTION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_QUERY_ACTION, RygelMediaQueryActionClass))

typedef struct _RygelMediaQueryAction RygelMediaQueryAction;
typedef struct _RygelMediaQueryActionClass RygelMediaQueryActionClass;
typedef struct _RygelMediaQueryActionPrivate RygelMediaQueryActionPrivate;

#define RYGEL_TYPE_MEDIA_OBJECT (rygel_media_object_get_type ())
#define RYGEL_MEDIA_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObject))
#define RYGEL_MEDIA_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObjectClass))
#define RYGEL_IS_MEDIA_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_OBJECT))
#define RYGEL_IS_MEDIA_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_OBJECT))
#define RYGEL_MEDIA_OBJECT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObjectClass))

typedef struct _RygelMediaObject RygelMediaObject;
typedef struct _RygelMediaObjectClass RygelMediaObjectClass;

#define RYGEL_TYPE_MEDIA_OBJECTS (rygel_media_objects_get_type ())
#define RYGEL_MEDIA_OBJECTS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_OBJECTS, RygelMediaObjects))
#define RYGEL_MEDIA_OBJECTS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_OBJECTS, RygelMediaObjectsClass))
#define RYGEL_IS_MEDIA_OBJECTS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_OBJECTS))
#define RYGEL_IS_MEDIA_OBJECTS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_OBJECTS))
#define RYGEL_MEDIA_OBJECTS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_OBJECTS, RygelMediaObjectsClass))

typedef struct _RygelMediaObjects RygelMediaObjects;
typedef struct _RygelMediaObjectsClass RygelMediaObjectsClass;

#define RYGEL_TYPE_MEDIA_CONTAINER (rygel_media_container_get_type ())
#define RYGEL_MEDIA_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainer))
#define RYGEL_MEDIA_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainerClass))
#define RYGEL_IS_MEDIA_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_CONTAINER))
#define RYGEL_IS_MEDIA_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_CONTAINER))
#define RYGEL_MEDIA_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainerClass))

typedef struct _RygelMediaContainer RygelMediaContainer;
typedef struct _RygelMediaContainerClass RygelMediaContainerClass;

#define RYGEL_TYPE_DIDL_LITE_WRITER (rygel_didl_lite_writer_get_type ())
#define RYGEL_DIDL_LITE_WRITER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_DIDL_LITE_WRITER, RygelDIDLLiteWriter))
#define RYGEL_DIDL_LITE_WRITER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_DIDL_LITE_WRITER, RygelDIDLLiteWriterClass))
#define RYGEL_IS_DIDL_LITE_WRITER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_DIDL_LITE_WRITER))
#define RYGEL_IS_DIDL_LITE_WRITER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_DIDL_LITE_WRITER))
#define RYGEL_DIDL_LITE_WRITER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_DIDL_LITE_WRITER, RygelDIDLLiteWriterClass))

typedef struct _RygelDIDLLiteWriter RygelDIDLLiteWriter;
typedef struct _RygelDIDLLiteWriterClass RygelDIDLLiteWriterClass;

#define RYGEL_TYPE_XBOX_HACKS (rygel_xbox_hacks_get_type ())
#define RYGEL_XBOX_HACKS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_XBOX_HACKS, RygelXBoxHacks))
#define RYGEL_XBOX_HACKS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_XBOX_HACKS, RygelXBoxHacksClass))
#define RYGEL_IS_XBOX_HACKS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_XBOX_HACKS))
#define RYGEL_IS_XBOX_HACKS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_XBOX_HACKS))
#define RYGEL_XBOX_HACKS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_XBOX_HACKS, RygelXBoxHacksClass))

typedef struct _RygelXBoxHacks RygelXBoxHacks;
typedef struct _RygelXBoxHacksClass RygelXBoxHacksClass;

#define RYGEL_TYPE_BROWSE (rygel_browse_get_type ())
#define RYGEL_BROWSE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_BROWSE, RygelBrowse))
#define RYGEL_BROWSE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_BROWSE, RygelBrowseClass))
#define RYGEL_IS_BROWSE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_BROWSE))
#define RYGEL_IS_BROWSE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_BROWSE))
#define RYGEL_BROWSE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_BROWSE, RygelBrowseClass))

typedef struct _RygelBrowse RygelBrowse;
typedef struct _RygelBrowseClass RygelBrowseClass;
typedef struct _RygelBrowsePrivate RygelBrowsePrivate;

#define RYGEL_TYPE_CONTENT_DIRECTORY (rygel_content_directory_get_type ())
#define RYGEL_CONTENT_DIRECTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_CONTENT_DIRECTORY, RygelContentDirectory))
#define RYGEL_CONTENT_DIRECTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_CONTENT_DIRECTORY, RygelContentDirectoryClass))
#define RYGEL_IS_CONTENT_DIRECTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_CONTENT_DIRECTORY))
#define RYGEL_IS_CONTENT_DIRECTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_CONTENT_DIRECTORY))
#define RYGEL_CONTENT_DIRECTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_CONTENT_DIRECTORY, RygelContentDirectoryClass))

typedef struct _RygelContentDirectory RygelContentDirectory;
typedef struct _RygelContentDirectoryClass RygelContentDirectoryClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _RygelBrowseFetchResultsData RygelBrowseFetchResultsData;
typedef struct _RygelMediaObjectPrivate RygelMediaObjectPrivate;
typedef struct _RygelMediaContainerPrivate RygelMediaContainerPrivate;

#define RYGEL_TYPE_SEARCH_EXPRESSION (rygel_search_expression_get_type ())
#define RYGEL_SEARCH_EXPRESSION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_SEARCH_EXPRESSION, RygelSearchExpression))
#define RYGEL_SEARCH_EXPRESSION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_SEARCH_EXPRESSION, RygelSearchExpressionClass))
#define RYGEL_IS_SEARCH_EXPRESSION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_SEARCH_EXPRESSION))
#define RYGEL_IS_SEARCH_EXPRESSION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_SEARCH_EXPRESSION))
#define RYGEL_SEARCH_EXPRESSION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_SEARCH_EXPRESSION, RygelSearchExpressionClass))

typedef struct _RygelSearchExpression RygelSearchExpression;
typedef struct _RygelSearchExpressionClass RygelSearchExpressionClass;

#define RYGEL_TYPE_MEDIA_ITEM (rygel_media_item_get_type ())
#define RYGEL_MEDIA_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_ITEM, RygelMediaItem))
#define RYGEL_MEDIA_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_ITEM, RygelMediaItemClass))
#define RYGEL_IS_MEDIA_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_ITEM))
#define RYGEL_IS_MEDIA_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_ITEM))
#define RYGEL_MEDIA_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_ITEM, RygelMediaItemClass))

typedef struct _RygelMediaItem RygelMediaItem;
typedef struct _RygelMediaItemClass RygelMediaItemClass;
typedef struct _RygelBrowseHandleChildrenRequestData RygelBrowseHandleChildrenRequestData;

struct _RygelStateMachineIface {
	GTypeInterface parent_iface;
	void (*run) (RygelStateMachine* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
	void (*run_finish) (RygelStateMachine* self, GAsyncResult* _res_);
	GCancellable* (*get_cancellable) (RygelStateMachine* self);
	void (*set_cancellable) (RygelStateMachine* self, GCancellable* value);
};

struct _RygelMediaQueryAction {
	GObject parent_instance;
	RygelMediaQueryActionPrivate * priv;
	char* object_id;
	char* browse_flag;
	char* filter;
	guint index;
	guint requested_count;
	char* sort_criteria;
	guint number_returned;
	guint total_matches;
	guint update_id;
	RygelMediaContainer* root_container;
	guint32 system_update_id;
	GUPnPServiceAction* action;
	RygelDIDLLiteWriter* didl_writer;
	RygelXBoxHacks* xbox_hacks;
	char* object_id_arg;
};

struct _RygelMediaQueryActionClass {
	GObjectClass parent_class;
	void (*parse_args) (RygelMediaQueryAction* self, GError** error);
	void (*fetch_results) (RygelMediaQueryAction* self, RygelMediaObject* media_object, GAsyncReadyCallback _callback_, gpointer _user_data_);
	RygelMediaObjects* (*fetch_results_finish) (RygelMediaQueryAction* self, GAsyncResult* _res_, GError** error);
	void (*handle_error) (RygelMediaQueryAction* self, GError* _error_);
};

struct _RygelBrowse {
	RygelMediaQueryAction parent_instance;
	RygelBrowsePrivate * priv;
};

struct _RygelBrowseClass {
	RygelMediaQueryActionClass parent_class;
};

struct _RygelBrowsePrivate {
	gboolean fetch_metadata;
};

typedef enum  {
	RYGEL_CONTENT_DIRECTORY_ERROR_NO_SUCH_OBJECT = 701,
	RYGEL_CONTENT_DIRECTORY_ERROR_BAD_METADATA = 712,
	RYGEL_CONTENT_DIRECTORY_ERROR_RESTRICTED_PARENT = 713,
	RYGEL_CONTENT_DIRECTORY_ERROR_CANT_PROCESS = 720,
	RYGEL_CONTENT_DIRECTORY_ERROR_INVALID_ARGS = 402
} RygelContentDirectoryError;
#define RYGEL_CONTENT_DIRECTORY_ERROR rygel_content_directory_error_quark ()
struct _RygelBrowseFetchResultsData {
	int _state_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	RygelBrowse* self;
	RygelMediaObject* media_object;
	RygelMediaObjects* result;
	RygelMediaObjects* _tmp0_;
	RygelMediaObjects* _tmp1_;
	GError * _inner_error_;
};

struct _RygelMediaObject {
	GObject parent_instance;
	RygelMediaObjectPrivate * priv;
	char* id;
	char* upnp_class;
	guint64 modified;
	GeeArrayList* uris;
	RygelMediaContainer* parent;
};

struct _RygelMediaObjectClass {
	GObjectClass parent_class;
	gint (*compare_by_property) (RygelMediaObject* self, RygelMediaObject* media_object, const char* property);
};

struct _RygelMediaContainer {
	RygelMediaObject parent_instance;
	RygelMediaContainerPrivate * priv;
	gint child_count;
	guint32 update_id;
	GeeArrayList* create_classes;
};

struct _RygelMediaContainerClass {
	RygelMediaObjectClass parent_class;
	void (*get_children) (RygelMediaContainer* self, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
	RygelMediaObjects* (*get_children_finish) (RygelMediaContainer* self, GAsyncResult* _res_, GError** error);
	void (*search) (RygelMediaContainer* self, RygelSearchExpression* expression, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
	RygelMediaObjects* (*search_finish) (RygelMediaContainer* self, GAsyncResult* _res_, guint* total_matches, GError** error);
	void (*find_object) (RygelMediaContainer* self, const char* id, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
	RygelMediaObject* (*find_object_finish) (RygelMediaContainer* self, GAsyncResult* _res_, GError** error);
	void (*add_item) (RygelMediaContainer* self, RygelMediaItem* item, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
	void (*add_item_finish) (RygelMediaContainer* self, GAsyncResult* _res_, GError** error);
};

struct _RygelBrowseHandleChildrenRequestData {
	int _state_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	RygelBrowse* self;
	RygelMediaObject* media_object;
	RygelMediaObjects* result;
	RygelMediaContainer* container;
	RygelMediaObjects* children;
	GError * _inner_error_;
};


static gpointer rygel_browse_parent_class = NULL;

GType rygel_state_machine_get_type (void) G_GNUC_CONST;
GType rygel_media_query_action_get_type (void) G_GNUC_CONST;
GType rygel_media_object_get_type (void) G_GNUC_CONST;
GType rygel_media_objects_get_type (void) G_GNUC_CONST;
GType rygel_media_container_get_type (void) G_GNUC_CONST;
GType rygel_didl_lite_writer_get_type (void) G_GNUC_CONST;
GType rygel_xbox_hacks_get_type (void) G_GNUC_CONST;
GType rygel_browse_get_type (void) G_GNUC_CONST;
#define RYGEL_BROWSE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_BROWSE, RygelBrowsePrivate))
enum  {
	RYGEL_BROWSE_DUMMY_PROPERTY
};
GType rygel_content_directory_get_type (void) G_GNUC_CONST;
RygelMediaQueryAction* rygel_media_query_action_construct (GType object_type, RygelContentDirectory* content_dir, GUPnPServiceAction* action);
RygelBrowse* rygel_browse_new (RygelContentDirectory* content_dir, GUPnPServiceAction* action);
RygelBrowse* rygel_browse_construct (GType object_type, RygelContentDirectory* content_dir, GUPnPServiceAction* action);
void rygel_media_query_action_parse_args (RygelMediaQueryAction* self, GError** error);
GQuark rygel_content_directory_error_quark (void);
static void rygel_browse_real_parse_args (RygelMediaQueryAction* base, GError** error);
static void rygel_browse_real_fetch_results_data_free (gpointer _data);
static void rygel_browse_real_fetch_results (RygelMediaQueryAction* base, RygelMediaObject* media_object, GAsyncReadyCallback _callback_, gpointer _user_data_);
static void rygel_browse_fetch_results_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static RygelMediaObjects* rygel_browse_handle_metadata_request (RygelBrowse* self, RygelMediaObject* media_object, GError** error);
static void rygel_browse_handle_children_request (RygelBrowse* self, RygelMediaObject* media_object, GAsyncReadyCallback _callback_, gpointer _user_data_);
static RygelMediaObjects* rygel_browse_handle_children_request_finish (RygelBrowse* self, GAsyncResult* _res_, GError** error);
static gboolean rygel_browse_real_fetch_results_co (RygelBrowseFetchResultsData* data);
RygelMediaObjects* rygel_media_objects_new (void);
RygelMediaObjects* rygel_media_objects_construct (GType object_type);
static void rygel_browse_handle_children_request_data_free (gpointer _data);
static void rygel_browse_handle_children_request_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
gpointer rygel_search_expression_ref (gpointer instance);
void rygel_search_expression_unref (gpointer instance);
GParamSpec* rygel_param_spec_search_expression (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_search_expression (GValue* value, gpointer v_object);
void rygel_value_take_search_expression (GValue* value, gpointer v_object);
gpointer rygel_value_get_search_expression (const GValue* value);
GType rygel_search_expression_get_type (void) G_GNUC_CONST;
GType rygel_media_item_get_type (void) G_GNUC_CONST;
void rygel_media_container_get_children (RygelMediaContainer* self, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
RygelMediaObjects* rygel_media_container_get_children_finish (RygelMediaContainer* self, GAsyncResult* _res_, GError** error);
GCancellable* rygel_state_machine_get_cancellable (RygelStateMachine* self);
static gboolean rygel_browse_handle_children_request_co (RygelBrowseHandleChildrenRequestData* data);
void rygel_media_query_action_handle_error (RygelMediaQueryAction* self, GError* _error_);
static void rygel_browse_real_handle_error (RygelMediaQueryAction* base, GError* _error_);
static void rygel_browse_finalize (GObject* obj);
static int _vala_strcmp0 (const char * str1, const char * str2);



#line 38 "rygel-browse.vala"
RygelBrowse* rygel_browse_construct (GType object_type, RygelContentDirectory* content_dir, GUPnPServiceAction* action) {
#line 326 "rygel-browse.c"
	RygelBrowse * self;
#line 38 "rygel-browse.vala"
	g_return_val_if_fail (content_dir != NULL, NULL);
#line 38 "rygel-browse.vala"
	g_return_val_if_fail (action != NULL, NULL);
#line 40 "rygel-browse.vala"
	self = (RygelBrowse*) rygel_media_query_action_construct (object_type, content_dir, action);
#line 42 "rygel-browse.vala"
	if (((RygelMediaQueryAction*) self)->xbox_hacks != NULL) {
#line 336 "rygel-browse.c"
		char* _tmp0_;
#line 43 "rygel-browse.vala"
		((RygelMediaQueryAction*) self)->object_id_arg = (_tmp0_ = g_strdup ("ContainerID"), _g_free0 (((RygelMediaQueryAction*) self)->object_id_arg), _tmp0_);
#line 340 "rygel-browse.c"
	} else {
		char* _tmp1_;
#line 45 "rygel-browse.vala"
		((RygelMediaQueryAction*) self)->object_id_arg = (_tmp1_ = g_strdup ("ObjectID"), _g_free0 (((RygelMediaQueryAction*) self)->object_id_arg), _tmp1_);
#line 345 "rygel-browse.c"
	}
	return self;
}


#line 38 "rygel-browse.vala"
RygelBrowse* rygel_browse_new (RygelContentDirectory* content_dir, GUPnPServiceAction* action) {
#line 38 "rygel-browse.vala"
	return rygel_browse_construct (RYGEL_TYPE_BROWSE, content_dir, action);
#line 355 "rygel-browse.c"
}


#line 49 "rygel-browse.vala"
static void rygel_browse_real_parse_args (RygelMediaQueryAction* base, GError** error) {
#line 361 "rygel-browse.c"
	RygelBrowse * self;
	GError * _inner_error_;
	gboolean _tmp0_ = FALSE;
	self = (RygelBrowse*) base;
	_inner_error_ = NULL;
#line 50 "rygel-browse.vala"
	RYGEL_MEDIA_QUERY_ACTION_CLASS (rygel_browse_parent_class)->parse_args (RYGEL_MEDIA_QUERY_ACTION (self), &_inner_error_);
#line 369 "rygel-browse.c"
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return;
	}
#line 52 "rygel-browse.vala"
	gupnp_service_action_get (((RygelMediaQueryAction*) self)->action, "BrowseFlag", G_TYPE_STRING, &((RygelMediaQueryAction*) self)->browse_flag, NULL);
#line 55 "rygel-browse.vala"
	if (((RygelMediaQueryAction*) self)->browse_flag != NULL) {
#line 56 "rygel-browse.vala"
		_tmp0_ = _vala_strcmp0 (((RygelMediaQueryAction*) self)->browse_flag, "BrowseDirectChildren") == 0;
#line 380 "rygel-browse.c"
	} else {
#line 55 "rygel-browse.vala"
		_tmp0_ = FALSE;
#line 384 "rygel-browse.c"
	}
#line 55 "rygel-browse.vala"
	if (_tmp0_) {
#line 57 "rygel-browse.vala"
		self->priv->fetch_metadata = FALSE;
#line 390 "rygel-browse.c"
	} else {
		gboolean _tmp1_ = FALSE;
#line 58 "rygel-browse.vala"
		if (((RygelMediaQueryAction*) self)->browse_flag != NULL) {
#line 59 "rygel-browse.vala"
			_tmp1_ = _vala_strcmp0 (((RygelMediaQueryAction*) self)->browse_flag, "BrowseMetadata") == 0;
#line 397 "rygel-browse.c"
		} else {
#line 58 "rygel-browse.vala"
			_tmp1_ = FALSE;
#line 401 "rygel-browse.c"
		}
#line 58 "rygel-browse.vala"
		if (_tmp1_) {
#line 60 "rygel-browse.vala"
			self->priv->fetch_metadata = TRUE;
#line 407 "rygel-browse.c"
		} else {
			_inner_error_ = g_error_new_literal (RYGEL_CONTENT_DIRECTORY_ERROR, RYGEL_CONTENT_DIRECTORY_ERROR_INVALID_ARGS, _ ("Invalid Arguments"));
			{
				g_propagate_error (error, _inner_error_);
				return;
			}
		}
	}
}


static void rygel_browse_real_fetch_results_data_free (gpointer _data) {
	RygelBrowseFetchResultsData* data;
	data = _data;
	_g_object_unref0 (data->media_object);
	_g_object_unref0 (data->result);
	g_object_unref (data->self);
	g_slice_free (RygelBrowseFetchResultsData, data);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void rygel_browse_real_fetch_results (RygelMediaQueryAction* base, RygelMediaObject* media_object, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	RygelBrowse * self;
	RygelBrowseFetchResultsData* _data_;
	self = (RygelBrowse*) base;
	_data_ = g_slice_new0 (RygelBrowseFetchResultsData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, rygel_browse_real_fetch_results);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, rygel_browse_real_fetch_results_data_free);
	_data_->self = g_object_ref (self);
	_data_->media_object = _g_object_ref0 (media_object);
	rygel_browse_real_fetch_results_co (_data_);
}


static RygelMediaObjects* rygel_browse_real_fetch_results_finish (RygelMediaQueryAction* base, GAsyncResult* _res_, GError** error) {
	RygelMediaObjects* result;
	RygelBrowseFetchResultsData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return NULL;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	_data_->result = NULL;
	return result;
}


static void rygel_browse_fetch_results_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	RygelBrowseFetchResultsData* data;
	data = _user_data_;
	data->_res_ = _res_;
	rygel_browse_real_fetch_results_co (data);
}


static gboolean rygel_browse_real_fetch_results_co (RygelBrowseFetchResultsData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		case 34:
		goto _state_34;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	{
#line 69 "rygel-browse.vala"
		if (data->self->priv->fetch_metadata) {
#line 481 "rygel-browse.c"
			data->_tmp0_ = rygel_browse_handle_metadata_request (data->self, data->media_object, &data->_inner_error_);
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
		} else {
			data->_state_ = 34;
			rygel_browse_handle_children_request (data->self, data->media_object, rygel_browse_fetch_results_ready, data);
			return FALSE;
			_state_34:
			data->_tmp1_ = rygel_browse_handle_children_request_finish (data->self, data->_res_, &data->_inner_error_);
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
			data->result = data->_tmp1_;
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


#line 78 "rygel-browse.vala"
static RygelMediaObjects* rygel_browse_handle_metadata_request (RygelBrowse* self, RygelMediaObject* media_object, GError** error) {
#line 551 "rygel-browse.c"
	RygelMediaObjects* result = NULL;
	RygelMediaObjects* results;
#line 78 "rygel-browse.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 78 "rygel-browse.vala"
	g_return_val_if_fail (media_object != NULL, NULL);
#line 80 "rygel-browse.vala"
	((RygelMediaQueryAction*) self)->total_matches = (guint) 1;
#line 82 "rygel-browse.vala"
	results = rygel_media_objects_new ();
#line 83 "rygel-browse.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) results, media_object);
#line 564 "rygel-browse.c"
	result = results;
#line 85 "rygel-browse.vala"
	return result;
#line 568 "rygel-browse.c"
}


static void rygel_browse_handle_children_request_data_free (gpointer _data) {
	RygelBrowseHandleChildrenRequestData* data;
	data = _data;
	_g_object_unref0 (data->media_object);
	_g_object_unref0 (data->result);
	g_object_unref (data->self);
	g_slice_free (RygelBrowseHandleChildrenRequestData, data);
}


static void rygel_browse_handle_children_request (RygelBrowse* self, RygelMediaObject* media_object, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	RygelBrowseHandleChildrenRequestData* _data_;
	_data_ = g_slice_new0 (RygelBrowseHandleChildrenRequestData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, rygel_browse_handle_children_request);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, rygel_browse_handle_children_request_data_free);
	_data_->self = g_object_ref (self);
	_data_->media_object = _g_object_ref0 (media_object);
	rygel_browse_handle_children_request_co (_data_);
}


static RygelMediaObjects* rygel_browse_handle_children_request_finish (RygelBrowse* self, GAsyncResult* _res_, GError** error) {
	RygelMediaObjects* result;
	RygelBrowseHandleChildrenRequestData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return NULL;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	_data_->result = NULL;
	return result;
}


static void rygel_browse_handle_children_request_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	RygelBrowseHandleChildrenRequestData* data;
	data = _user_data_;
	data->_res_ = _res_;
	rygel_browse_handle_children_request_co (data);
}


static gboolean rygel_browse_handle_children_request_co (RygelBrowseHandleChildrenRequestData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		case 35:
		goto _state_35;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	{
#line 91 "rygel-browse.vala"
		if (!RYGEL_IS_MEDIA_CONTAINER (data->media_object)) {
#line 627 "rygel-browse.c"
			data->_inner_error_ = g_error_new_literal (RYGEL_CONTENT_DIRECTORY_ERROR, RYGEL_CONTENT_DIRECTORY_ERROR_NO_SUCH_OBJECT, _ ("No such object"));
			{
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
		}
		data->container = _g_object_ref0 (RYGEL_MEDIA_CONTAINER (data->media_object));
#line 97 "rygel-browse.vala"
		((RygelMediaQueryAction*) data->self)->total_matches = (guint) data->container->child_count;
#line 99 "rygel-browse.vala"
		if (((RygelMediaQueryAction*) data->self)->requested_count == 0) {
#line 101 "rygel-browse.vala"
			((RygelMediaQueryAction*) data->self)->requested_count = ((RygelMediaQueryAction*) data->self)->total_matches;
#line 650 "rygel-browse.c"
		}
#line 104 "rygel-browse.vala"
		g_debug ("rygel-browse.vala:104: Fetching %u children of container '%s' from ind" \
"ex %u..", ((RygelMediaQueryAction*) data->self)->requested_count, ((RygelMediaQueryAction*) data->self)->object_id, ((RygelMediaQueryAction*) data->self)->index);
#line 654 "rygel-browse.c"
		data->_state_ = 35;
		rygel_media_container_get_children (data->container, ((RygelMediaQueryAction*) data->self)->index, ((RygelMediaQueryAction*) data->self)->requested_count, rygel_state_machine_get_cancellable ((RygelStateMachine*) data->self), rygel_browse_handle_children_request_ready, data);
		return FALSE;
		_state_35:
		data->children = rygel_media_container_get_children_finish (data->container, data->_res_, &data->_inner_error_);
		if (data->_inner_error_ != NULL) {
			g_simple_async_result_set_from_error (data->_async_result, data->_inner_error_);
			g_error_free (data->_inner_error_);
			_g_object_unref0 (data->container);
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
#line 111 "rygel-browse.vala"
		g_debug ("rygel-browse.vala:111: Fetched %u children of container '%s' from inde" \
"x %u.", ((RygelMediaQueryAction*) data->self)->requested_count, ((RygelMediaQueryAction*) data->self)->object_id, ((RygelMediaQueryAction*) data->self)->index);
#line 676 "rygel-browse.c"
		data->result = data->children;
		_g_object_unref0 (data->container);
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
		_g_object_unref0 (data->container);
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


#line 119 "rygel-browse.vala"
static void rygel_browse_real_handle_error (RygelMediaQueryAction* base, GError* _error_) {
#line 705 "rygel-browse.c"
	RygelBrowse * self;
	self = (RygelBrowse*) base;
#line 120 "rygel-browse.vala"
	g_warning (_ ("Failed to browse '%s': %s\n"), ((RygelMediaQueryAction*) self)->object_id, _error_->message);
#line 124 "rygel-browse.vala"
	RYGEL_MEDIA_QUERY_ACTION_CLASS (rygel_browse_parent_class)->handle_error (RYGEL_MEDIA_QUERY_ACTION (self), _error_);
#line 712 "rygel-browse.c"
}


static void rygel_browse_class_init (RygelBrowseClass * klass) {
	rygel_browse_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelBrowsePrivate));
	RYGEL_MEDIA_QUERY_ACTION_CLASS (klass)->parse_args = rygel_browse_real_parse_args;
	RYGEL_MEDIA_QUERY_ACTION_CLASS (klass)->fetch_results = rygel_browse_real_fetch_results;
	RYGEL_MEDIA_QUERY_ACTION_CLASS (klass)->fetch_results_finish = rygel_browse_real_fetch_results_finish;
	RYGEL_MEDIA_QUERY_ACTION_CLASS (klass)->handle_error = rygel_browse_real_handle_error;
	G_OBJECT_CLASS (klass)->finalize = rygel_browse_finalize;
}


static void rygel_browse_instance_init (RygelBrowse * self) {
	self->priv = RYGEL_BROWSE_GET_PRIVATE (self);
}


static void rygel_browse_finalize (GObject* obj) {
	RygelBrowse * self;
	self = RYGEL_BROWSE (obj);
	G_OBJECT_CLASS (rygel_browse_parent_class)->finalize (obj);
}


GType rygel_browse_get_type (void) {
	static volatile gsize rygel_browse_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_browse_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelBrowseClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_browse_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelBrowse), 0, (GInstanceInitFunc) rygel_browse_instance_init, NULL };
		GType rygel_browse_type_id;
		rygel_browse_type_id = g_type_register_static (RYGEL_TYPE_MEDIA_QUERY_ACTION, "RygelBrowse", &g_define_type_info, 0);
		g_once_init_leave (&rygel_browse_type_id__volatile, rygel_browse_type_id);
	}
	return rygel_browse_type_id__volatile;
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




