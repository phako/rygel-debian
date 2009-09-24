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
#include <libgupnp/gupnp.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>
#include <gee.h>


#define RYGEL_TYPE_CONTENT_DIRECTORY (rygel_content_directory_get_type ())
#define RYGEL_CONTENT_DIRECTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_CONTENT_DIRECTORY, RygelContentDirectory))
#define RYGEL_CONTENT_DIRECTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_CONTENT_DIRECTORY, RygelContentDirectoryClass))
#define RYGEL_IS_CONTENT_DIRECTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_CONTENT_DIRECTORY))
#define RYGEL_IS_CONTENT_DIRECTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_CONTENT_DIRECTORY))
#define RYGEL_CONTENT_DIRECTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_CONTENT_DIRECTORY, RygelContentDirectoryClass))

typedef struct _RygelContentDirectory RygelContentDirectory;
typedef struct _RygelContentDirectoryClass RygelContentDirectoryClass;
typedef struct _RygelContentDirectoryPrivate RygelContentDirectoryPrivate;

#define RYGEL_TYPE_MEDIA_OBJECT (rygel_media_object_get_type ())
#define RYGEL_MEDIA_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObject))
#define RYGEL_MEDIA_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObjectClass))
#define RYGEL_IS_MEDIA_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_OBJECT))
#define RYGEL_IS_MEDIA_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_OBJECT))
#define RYGEL_MEDIA_OBJECT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObjectClass))

typedef struct _RygelMediaObject RygelMediaObject;
typedef struct _RygelMediaObjectClass RygelMediaObjectClass;

#define RYGEL_TYPE_MEDIA_CONTAINER (rygel_media_container_get_type ())
#define RYGEL_MEDIA_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainer))
#define RYGEL_MEDIA_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainerClass))
#define RYGEL_IS_MEDIA_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_CONTAINER))
#define RYGEL_IS_MEDIA_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_CONTAINER))
#define RYGEL_MEDIA_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainerClass))

typedef struct _RygelMediaContainer RygelMediaContainer;
typedef struct _RygelMediaContainerClass RygelMediaContainerClass;

#define RYGEL_TYPE_TRANSCODE_MANAGER (rygel_transcode_manager_get_type ())
#define RYGEL_TRANSCODE_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRANSCODE_MANAGER, RygelTranscodeManager))
#define RYGEL_TRANSCODE_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRANSCODE_MANAGER, RygelTranscodeManagerClass))
#define RYGEL_IS_TRANSCODE_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRANSCODE_MANAGER))
#define RYGEL_IS_TRANSCODE_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRANSCODE_MANAGER))
#define RYGEL_TRANSCODE_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRANSCODE_MANAGER, RygelTranscodeManagerClass))

typedef struct _RygelTranscodeManager RygelTranscodeManager;
typedef struct _RygelTranscodeManagerClass RygelTranscodeManagerClass;

#define RYGEL_TYPE_HTTP_SERVER (rygel_http_server_get_type ())
#define RYGEL_HTTP_SERVER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_SERVER, RygelHTTPServer))
#define RYGEL_HTTP_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_SERVER, RygelHTTPServerClass))
#define RYGEL_IS_HTTP_SERVER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_SERVER))
#define RYGEL_IS_HTTP_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_SERVER))
#define RYGEL_HTTP_SERVER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_SERVER, RygelHTTPServerClass))

typedef struct _RygelHTTPServer RygelHTTPServer;
typedef struct _RygelHTTPServerClass RygelHTTPServerClass;

#define RYGEL_TYPE_BROWSE (rygel_browse_get_type ())
#define RYGEL_BROWSE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_BROWSE, RygelBrowse))
#define RYGEL_BROWSE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_BROWSE, RygelBrowseClass))
#define RYGEL_IS_BROWSE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_BROWSE))
#define RYGEL_IS_BROWSE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_BROWSE))
#define RYGEL_BROWSE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_BROWSE, RygelBrowseClass))

typedef struct _RygelBrowse RygelBrowse;
typedef struct _RygelBrowseClass RygelBrowseClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

#define RYGEL_TYPE_STATE_MACHINE (rygel_state_machine_get_type ())
#define RYGEL_STATE_MACHINE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_STATE_MACHINE, RygelStateMachine))
#define RYGEL_IS_STATE_MACHINE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_STATE_MACHINE))
#define RYGEL_STATE_MACHINE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), RYGEL_TYPE_STATE_MACHINE, RygelStateMachineIface))

typedef struct _RygelStateMachine RygelStateMachine;
typedef struct _RygelStateMachineIface RygelStateMachineIface;
typedef struct _RygelMediaObjectPrivate RygelMediaObjectPrivate;
typedef struct _RygelMediaContainerPrivate RygelMediaContainerPrivate;

typedef enum  {
	RYGEL_CONTENT_DIRECTORY_ERROR_NO_SUCH_OBJECT = 701,
	RYGEL_CONTENT_DIRECTORY_ERROR_INVALID_ARGS = 402
} RygelContentDirectoryError;
#define RYGEL_CONTENT_DIRECTORY_ERROR rygel_content_directory_error_quark ()
struct _RygelContentDirectory {
	GUPnPService parent_instance;
	RygelContentDirectoryPrivate * priv;
	char* feature_list;
	char* search_caps;
	char* sort_caps;
	RygelHTTPServer* http_server;
	RygelMediaContainer* root_container;
	GCancellable* cancellable;
	guint32 system_update_id;
};

struct _RygelContentDirectoryClass {
	GUPnPServiceClass parent_class;
	RygelMediaContainer* (*create_root_container) (RygelContentDirectory* self);
	void (*browse_cb) (RygelContentDirectory* self, RygelContentDirectory* content_dir, GUPnPServiceAction* action);
};

struct _RygelContentDirectoryPrivate {
	GeeArrayList* updated_containers;
	gboolean clear_updated_containers;
	guint update_notify_id;
	GeeArrayList* browses;
};

struct _RygelStateMachineIface {
	GTypeInterface parent_iface;
	void (*run) (RygelStateMachine* self);
	GCancellable* (*get_cancellable) (RygelStateMachine* self);
	void (*set_cancellable) (RygelStateMachine* self, GCancellable* value);
};

struct _RygelMediaObject {
	GObject parent_instance;
	RygelMediaObjectPrivate * priv;
	char* id;
	char* title;
	guint64 modified;
	GeeArrayList* uris;
	RygelMediaContainer* parent;
	RygelMediaContainer* parent_ref;
};

struct _RygelMediaObjectClass {
	GObjectClass parent_class;
};

struct _RygelMediaContainer {
	RygelMediaObject parent_instance;
	RygelMediaContainerPrivate * priv;
	guint child_count;
	guint32 update_id;
};

struct _RygelMediaContainerClass {
	RygelMediaObjectClass parent_class;
	void (*get_children) (RygelMediaContainer* self, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target);
	GeeList* (*get_children_finish) (RygelMediaContainer* self, GAsyncResult* res, GError** error);
	void (*find_object) (RygelMediaContainer* self, const char* id, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target);
	RygelMediaObject* (*find_object_finish) (RygelMediaContainer* self, GAsyncResult* res, GError** error);
};


static gpointer rygel_content_directory_parent_class = NULL;

GQuark rygel_content_directory_error_quark (void);
GType rygel_content_directory_get_type (void);
GType rygel_media_object_get_type (void);
GType rygel_media_container_get_type (void);
GType rygel_transcode_manager_get_type (void);
GType rygel_http_server_get_type (void);
GType rygel_browse_get_type (void);
#define RYGEL_CONTENT_DIRECTORY_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_CONTENT_DIRECTORY, RygelContentDirectoryPrivate))
enum  {
	RYGEL_CONTENT_DIRECTORY_DUMMY_PROPERTY
};
#define RYGEL_CONTENT_DIRECTORY_UPNP_ID "urn:upnp-org:serviceId:ContentDirectory"
#define RYGEL_CONTENT_DIRECTORY_UPNP_TYPE "urn:schemas-upnp-org:service:ContentDirectory:2"
#define RYGEL_CONTENT_DIRECTORY_DESCRIPTION_PATH "xml/ContentDirectory.xml"
RygelMediaContainer* rygel_content_directory_create_root_container (RygelContentDirectory* self);
static RygelMediaContainer* rygel_content_directory_real_create_root_container (RygelContentDirectory* self);
RygelHTTPServer* rygel_http_server_new (RygelContentDirectory* content_dir, const char* name, GError** error);
RygelHTTPServer* rygel_http_server_construct (GType object_type, RygelContentDirectory* content_dir, const char* name, GError** error);
static void rygel_content_directory_on_container_updated (RygelContentDirectory* self, RygelMediaContainer* root_container, RygelMediaContainer* updated_container);
static void _rygel_content_directory_on_container_updated_rygel_media_container_container_updated (RygelMediaContainer* _sender, RygelMediaContainer* container, gpointer self);
static void rygel_content_directory_browse_cb (RygelContentDirectory* self, RygelContentDirectory* content_dir, GUPnPServiceAction* action);
static void _rygel_content_directory_browse_cb_gupnp_service_action_invoked (RygelContentDirectory* _sender, GUPnPServiceAction* action, gpointer self);
static void rygel_content_directory_get_system_update_id_cb (RygelContentDirectory* self, RygelContentDirectory* content_dir, GUPnPServiceAction* action);
static void _rygel_content_directory_get_system_update_id_cb_gupnp_service_action_invoked (RygelContentDirectory* _sender, GUPnPServiceAction* action, gpointer self);
static void rygel_content_directory_query_system_update_id (RygelContentDirectory* self, RygelContentDirectory* content_dir, const char* variable, GValue* value);
static void _rygel_content_directory_query_system_update_id_gupnp_service_query_variable (RygelContentDirectory* _sender, const char* variable, GValue* value, gpointer self);
static void rygel_content_directory_query_container_update_ids (RygelContentDirectory* self, RygelContentDirectory* content_dir, const char* variable, GValue* value);
static void _rygel_content_directory_query_container_update_ids_gupnp_service_query_variable (RygelContentDirectory* _sender, const char* variable, GValue* value, gpointer self);
static void rygel_content_directory_get_search_capabilities_cb (RygelContentDirectory* self, RygelContentDirectory* content_dir, GUPnPServiceAction* action);
static void _rygel_content_directory_get_search_capabilities_cb_gupnp_service_action_invoked (RygelContentDirectory* _sender, GUPnPServiceAction* action, gpointer self);
static void rygel_content_directory_query_search_capabilities (RygelContentDirectory* self, RygelContentDirectory* content_dir, const char* variable, GValue* value);
static void _rygel_content_directory_query_search_capabilities_gupnp_service_query_variable (RygelContentDirectory* _sender, const char* variable, GValue* value, gpointer self);
static void rygel_content_directory_get_sort_capabilities_cb (RygelContentDirectory* self, RygelContentDirectory* content_dir, GUPnPServiceAction* action);
static void _rygel_content_directory_get_sort_capabilities_cb_gupnp_service_action_invoked (RygelContentDirectory* _sender, GUPnPServiceAction* action, gpointer self);
static void rygel_content_directory_query_sort_capabilities (RygelContentDirectory* self, RygelContentDirectory* content_dir, const char* variable, GValue* value);
static void _rygel_content_directory_query_sort_capabilities_gupnp_service_query_variable (RygelContentDirectory* _sender, const char* variable, GValue* value, gpointer self);
static void rygel_content_directory_get_feature_list_cb (RygelContentDirectory* self, RygelContentDirectory* content_dir, GUPnPServiceAction* action);
static void _rygel_content_directory_get_feature_list_cb_gupnp_service_action_invoked (RygelContentDirectory* _sender, GUPnPServiceAction* action, gpointer self);
static void rygel_content_directory_query_feature_list (RygelContentDirectory* self, RygelContentDirectory* content_dir, const char* variable, GValue* value);
static void _rygel_content_directory_query_feature_list_gupnp_service_query_variable (RygelContentDirectory* _sender, const char* variable, GValue* value, gpointer self);
GType rygel_state_machine_get_type (void);
void rygel_state_machine_run (RygelStateMachine* self);
static void rygel_content_directory_real_constructed (GObject* base);
RygelBrowse* rygel_browse_new (RygelContentDirectory* content_dir, GUPnPServiceAction* action);
RygelBrowse* rygel_browse_construct (GType object_type, RygelContentDirectory* content_dir, GUPnPServiceAction* action);
static void rygel_content_directory_on_browse_completed (RygelContentDirectory* self, RygelBrowse* browse);
static void _rygel_content_directory_on_browse_completed_rygel_state_machine_completed (RygelBrowse* _sender, gpointer self);
static void rygel_content_directory_real_browse_cb (RygelContentDirectory* self, RygelContentDirectory* content_dir, GUPnPServiceAction* action);
static char* rygel_content_directory_create_container_update_ids (RygelContentDirectory* self);
static gboolean rygel_content_directory_update_notify (RygelContentDirectory* self);
static gboolean _rygel_content_directory_update_notify_gsource_func (gpointer self);
RygelContentDirectory* rygel_content_directory_new (void);
RygelContentDirectory* rygel_content_directory_construct (GType object_type);
static void rygel_content_directory_finalize (GObject* obj);
static int _vala_strcmp0 (const char * str1, const char * str2);



GQuark rygel_content_directory_error_quark (void) {
	return g_quark_from_static_string ("rygel_content_directory_error-quark");
}


static RygelMediaContainer* rygel_content_directory_real_create_root_container (RygelContentDirectory* self) {
	RygelMediaContainer* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = NULL;
	return result;
}


RygelMediaContainer* rygel_content_directory_create_root_container (RygelContentDirectory* self) {
	return RYGEL_CONTENT_DIRECTORY_GET_CLASS (self)->create_root_container (self);
}


static void _rygel_content_directory_on_container_updated_rygel_media_container_container_updated (RygelMediaContainer* _sender, RygelMediaContainer* container, gpointer self) {
	rygel_content_directory_on_container_updated (self, _sender, container);
}


static void _rygel_content_directory_browse_cb_gupnp_service_action_invoked (RygelContentDirectory* _sender, GUPnPServiceAction* action, gpointer self) {
	rygel_content_directory_browse_cb (self, _sender, action);
}


static void _rygel_content_directory_get_system_update_id_cb_gupnp_service_action_invoked (RygelContentDirectory* _sender, GUPnPServiceAction* action, gpointer self) {
	rygel_content_directory_get_system_update_id_cb (self, _sender, action);
}


static void _rygel_content_directory_query_system_update_id_gupnp_service_query_variable (RygelContentDirectory* _sender, const char* variable, GValue* value, gpointer self) {
	rygel_content_directory_query_system_update_id (self, _sender, variable, value);
}


static void _rygel_content_directory_query_container_update_ids_gupnp_service_query_variable (RygelContentDirectory* _sender, const char* variable, GValue* value, gpointer self) {
	rygel_content_directory_query_container_update_ids (self, _sender, variable, value);
}


static void _rygel_content_directory_get_search_capabilities_cb_gupnp_service_action_invoked (RygelContentDirectory* _sender, GUPnPServiceAction* action, gpointer self) {
	rygel_content_directory_get_search_capabilities_cb (self, _sender, action);
}


static void _rygel_content_directory_query_search_capabilities_gupnp_service_query_variable (RygelContentDirectory* _sender, const char* variable, GValue* value, gpointer self) {
	rygel_content_directory_query_search_capabilities (self, _sender, variable, value);
}


static void _rygel_content_directory_get_sort_capabilities_cb_gupnp_service_action_invoked (RygelContentDirectory* _sender, GUPnPServiceAction* action, gpointer self) {
	rygel_content_directory_get_sort_capabilities_cb (self, _sender, action);
}


static void _rygel_content_directory_query_sort_capabilities_gupnp_service_query_variable (RygelContentDirectory* _sender, const char* variable, GValue* value, gpointer self) {
	rygel_content_directory_query_sort_capabilities (self, _sender, variable, value);
}


static void _rygel_content_directory_get_feature_list_cb_gupnp_service_action_invoked (RygelContentDirectory* _sender, GUPnPServiceAction* action, gpointer self) {
	rygel_content_directory_get_feature_list_cb (self, _sender, action);
}


static void _rygel_content_directory_query_feature_list_gupnp_service_query_variable (RygelContentDirectory* _sender, const char* variable, GValue* value, gpointer self) {
	rygel_content_directory_query_feature_list (self, _sender, variable, value);
}


static void rygel_content_directory_real_constructed (GObject* base) {
	RygelContentDirectory * self;
	GError * _inner_error_;
	GCancellable* _tmp0_;
	RygelMediaContainer* _tmp1_;
	GeeArrayList* _tmp4_;
	GeeArrayList* _tmp5_;
	char* _tmp6_;
	char* _tmp7_;
	char* _tmp8_;
	self = (RygelContentDirectory*) base;
	_inner_error_ = NULL;
	self->cancellable = (_tmp0_ = g_cancellable_new (), _g_object_unref0 (self->cancellable), _tmp0_);
	self->root_container = (_tmp1_ = rygel_content_directory_create_root_container (self), _g_object_unref0 (self->root_container), _tmp1_);
	{
		RygelHTTPServer* _tmp2_;
		RygelHTTPServer* _tmp3_;
		_tmp2_ = rygel_http_server_new (self, g_type_name (G_TYPE_FROM_INSTANCE ((GObject*) self)), &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch17_g_error;
			goto __finally17;
		}
		self->http_server = (_tmp3_ = _tmp2_, _g_object_unref0 (self->http_server), _tmp3_);
	}
	goto __finally17;
	__catch17_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			g_critical ("rygel-content-directory.vala:77: Failed to create HTTP server for %s: %s", g_type_name (G_TYPE_FROM_INSTANCE ((GObject*) self)), err->message);
			_g_error_free0 (err);
			return;
		}
	}
	__finally17:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return;
	}
	self->priv->browses = (_tmp4_ = gee_array_list_new (RYGEL_TYPE_BROWSE, (GBoxedCopyFunc) g_object_ref, g_object_unref, g_direct_equal), _g_object_unref0 (self->priv->browses), _tmp4_);
	self->priv->updated_containers = (_tmp5_ = gee_array_list_new (RYGEL_TYPE_MEDIA_CONTAINER, (GBoxedCopyFunc) g_object_ref, g_object_unref, g_direct_equal), _g_object_unref0 (self->priv->updated_containers), _tmp5_);
	g_signal_connect_object (self->root_container, "container-updated", (GCallback) _rygel_content_directory_on_container_updated_rygel_media_container_container_updated, self, 0);
	self->feature_list = (_tmp6_ = g_strdup ("<?xml version=\"1.0\" encoding=\"UTF-8\"?>" "<Features xmlns=\"urn:schemas-upnp-org:av:avs\" " "xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" " "xsi:schemaLocation=\"urn:schemas-upnp-org:av:avs" "http://www.upnp.org/schemas/av/avs-v1-20060531.xsd\">" "</Features>"), _g_free0 (self->feature_list), _tmp6_);
	self->search_caps = (_tmp7_ = g_strdup (""), _g_free0 (self->search_caps), _tmp7_);
	self->sort_caps = (_tmp8_ = g_strdup (""), _g_free0 (self->sort_caps), _tmp8_);
	g_signal_connect_object ((GUPnPService*) self, "action-invoked::Browse", (GCallback) _rygel_content_directory_browse_cb_gupnp_service_action_invoked, self, 0);
	g_signal_connect_object ((GUPnPService*) self, "action-invoked::GetSystemUpdateID", (GCallback) _rygel_content_directory_get_system_update_id_cb_gupnp_service_action_invoked, self, 0);
	g_signal_connect_object ((GUPnPService*) self, "query-variable::SystemUpdateID", (GCallback) _rygel_content_directory_query_system_update_id_gupnp_service_query_variable, self, 0);
	g_signal_connect_object ((GUPnPService*) self, "query-variable::ContainerUpdateIDs", (GCallback) _rygel_content_directory_query_container_update_ids_gupnp_service_query_variable, self, 0);
	g_signal_connect_object ((GUPnPService*) self, "action-invoked::GetSearchCapabilities", (GCallback) _rygel_content_directory_get_search_capabilities_cb_gupnp_service_action_invoked, self, 0);
	g_signal_connect_object ((GUPnPService*) self, "query-variable::SearchCapabilities", (GCallback) _rygel_content_directory_query_search_capabilities_gupnp_service_query_variable, self, 0);
	g_signal_connect_object ((GUPnPService*) self, "action-invoked::GetSortCapabilities", (GCallback) _rygel_content_directory_get_sort_capabilities_cb_gupnp_service_action_invoked, self, 0);
	g_signal_connect_object ((GUPnPService*) self, "query-variable::SortCapabilities", (GCallback) _rygel_content_directory_query_sort_capabilities_gupnp_service_query_variable, self, 0);
	g_signal_connect_object ((GUPnPService*) self, "action-invoked::GetFeatureList", (GCallback) _rygel_content_directory_get_feature_list_cb_gupnp_service_action_invoked, self, 0);
	g_signal_connect_object ((GUPnPService*) self, "query-variable::FeatureList", (GCallback) _rygel_content_directory_query_feature_list_gupnp_service_query_variable, self, 0);
	rygel_state_machine_run ((RygelStateMachine*) self->http_server);
}


static void _rygel_content_directory_on_browse_completed_rygel_state_machine_completed (RygelBrowse* _sender, gpointer self) {
	rygel_content_directory_on_browse_completed (self, _sender);
}


static void rygel_content_directory_real_browse_cb (RygelContentDirectory* self, RygelContentDirectory* content_dir, GUPnPServiceAction* action) {
	RygelBrowse* browse;
	g_return_if_fail (self != NULL);
	g_return_if_fail (content_dir != NULL);
	g_return_if_fail (action != NULL);
	browse = rygel_browse_new (self, action);
	gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->browses, browse);
	g_signal_connect_object ((RygelStateMachine*) browse, "completed", (GCallback) _rygel_content_directory_on_browse_completed_rygel_state_machine_completed, self, 0);
	rygel_state_machine_run ((RygelStateMachine*) browse);
	_g_object_unref0 (browse);
}


void rygel_content_directory_browse_cb (RygelContentDirectory* self, RygelContentDirectory* content_dir, GUPnPServiceAction* action) {
	RYGEL_CONTENT_DIRECTORY_GET_CLASS (self)->browse_cb (self, content_dir, action);
}


static void rygel_content_directory_get_system_update_id_cb (RygelContentDirectory* self, RygelContentDirectory* content_dir, GUPnPServiceAction* action) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (content_dir != NULL);
	g_return_if_fail (action != NULL);
	gupnp_service_action_set (action, "Id", G_TYPE_UINT, self->system_update_id, NULL);
	gupnp_service_action_return (action);
}


static void rygel_content_directory_query_system_update_id (RygelContentDirectory* self, RygelContentDirectory* content_dir, const char* variable, GValue* value) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (content_dir != NULL);
	g_return_if_fail (variable != NULL);
	g_value_init (&(*value), G_TYPE_UINT);
	g_value_set_uint (&(*value), (guint) self->system_update_id);
}


static void rygel_content_directory_query_container_update_ids (RygelContentDirectory* self, RygelContentDirectory* content_dir, const char* variable, GValue* value) {
	char* update_ids;
	g_return_if_fail (self != NULL);
	g_return_if_fail (content_dir != NULL);
	g_return_if_fail (variable != NULL);
	update_ids = rygel_content_directory_create_container_update_ids (self);
	g_value_init (&(*value), G_TYPE_STRING);
	g_value_set_string (&(*value), update_ids);
	_g_free0 (update_ids);
}


static void rygel_content_directory_get_search_capabilities_cb (RygelContentDirectory* self, RygelContentDirectory* content_dir, GUPnPServiceAction* action) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (content_dir != NULL);
	g_return_if_fail (action != NULL);
	gupnp_service_action_set (action, "SearchCaps", G_TYPE_STRING, self->search_caps, NULL);
	gupnp_service_action_return (action);
}


static void rygel_content_directory_query_search_capabilities (RygelContentDirectory* self, RygelContentDirectory* content_dir, const char* variable, GValue* value) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (content_dir != NULL);
	g_return_if_fail (variable != NULL);
	g_value_init (&(*value), G_TYPE_STRING);
	g_value_set_string (&(*value), self->search_caps);
}


static void rygel_content_directory_get_sort_capabilities_cb (RygelContentDirectory* self, RygelContentDirectory* content_dir, GUPnPServiceAction* action) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (content_dir != NULL);
	g_return_if_fail (action != NULL);
	gupnp_service_action_set (action, "SortCaps", G_TYPE_STRING, self->sort_caps, NULL);
	gupnp_service_action_return (action);
}


static void rygel_content_directory_query_sort_capabilities (RygelContentDirectory* self, RygelContentDirectory* content_dir, const char* variable, GValue* value) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (content_dir != NULL);
	g_return_if_fail (variable != NULL);
	g_value_init (&(*value), G_TYPE_STRING);
	g_value_set_string (&(*value), self->sort_caps);
}


static void rygel_content_directory_get_feature_list_cb (RygelContentDirectory* self, RygelContentDirectory* content_dir, GUPnPServiceAction* action) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (content_dir != NULL);
	g_return_if_fail (action != NULL);
	gupnp_service_action_set (action, "FeatureList", G_TYPE_STRING, self->feature_list, NULL);
	gupnp_service_action_return (action);
}


static void rygel_content_directory_query_feature_list (RygelContentDirectory* self, RygelContentDirectory* content_dir, const char* variable, GValue* value) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (content_dir != NULL);
	g_return_if_fail (variable != NULL);
	g_value_init (&(*value), G_TYPE_STRING);
	g_value_set_string (&(*value), self->feature_list);
}


static void rygel_content_directory_on_browse_completed (RygelContentDirectory* self, RygelBrowse* browse) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (browse != NULL);
	gee_abstract_collection_remove ((GeeAbstractCollection*) self->priv->browses, browse);
}


static char* rygel_content_directory_create_container_update_ids (RygelContentDirectory* self) {
	char* result;
	char* update_ids;
	g_return_val_if_fail (self != NULL, NULL);
	update_ids = g_strdup ("");
	{
		GeeIterator* _container_it;
		_container_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->updated_containers);
		while (TRUE) {
			RygelMediaContainer* container;
			char* _tmp4_;
			char* _tmp3_;
			char* _tmp2_;
			char* _tmp1_;
			if (!gee_iterator_next (_container_it)) {
				break;
			}
			container = (RygelMediaContainer*) gee_iterator_get (_container_it);
			if (_vala_strcmp0 (update_ids, "") != 0) {
				char* _tmp0_;
				update_ids = (_tmp0_ = g_strconcat (update_ids, ",", NULL), _g_free0 (update_ids), _tmp0_);
			}
			update_ids = (_tmp4_ = g_strconcat (update_ids, _tmp3_ = g_strconcat (_tmp1_ = g_strconcat (((RygelMediaObject*) container)->id, ",", NULL), _tmp2_ = g_strdup_printf ("%u", container->update_id), NULL), NULL), _g_free0 (update_ids), _tmp4_);
			_g_free0 (_tmp3_);
			_g_free0 (_tmp2_);
			_g_free0 (_tmp1_);
			_g_object_unref0 (container);
		}
		_g_object_unref0 (_container_it);
	}
	result = update_ids;
	return result;
}


static gboolean _rygel_content_directory_update_notify_gsource_func (gpointer self) {
	return rygel_content_directory_update_notify (self);
}


static void rygel_content_directory_on_container_updated (RygelContentDirectory* self, RygelMediaContainer* root_container, RygelMediaContainer* updated_container) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (root_container != NULL);
	g_return_if_fail (updated_container != NULL);
	self->system_update_id++;
	if (self->priv->clear_updated_containers) {
		gee_abstract_collection_clear ((GeeAbstractCollection*) self->priv->updated_containers);
		self->priv->clear_updated_containers = FALSE;
	}
	gee_abstract_collection_remove ((GeeAbstractCollection*) self->priv->updated_containers, updated_container);
	gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->updated_containers, updated_container);
	if (self->priv->update_notify_id == 0) {
		self->priv->update_notify_id = g_timeout_add_full (G_PRIORITY_DEFAULT, (guint) 200, _rygel_content_directory_update_notify_gsource_func, g_object_ref (self), g_object_unref);
	}
}


static gboolean rygel_content_directory_update_notify (RygelContentDirectory* self) {
	gboolean result;
	char* update_ids;
	g_return_val_if_fail (self != NULL, FALSE);
	update_ids = rygel_content_directory_create_container_update_ids (self);
	gupnp_service_notify ((GUPnPService*) self, "ContainerUpdateIDs", G_TYPE_STRING, update_ids, NULL);
	gupnp_service_notify ((GUPnPService*) self, "SystemUpdateID", G_TYPE_UINT, self->system_update_id, NULL);
	self->priv->clear_updated_containers = TRUE;
	self->priv->update_notify_id = (guint) 0;
	result = FALSE;
	_g_free0 (update_ids);
	return result;
}


RygelContentDirectory* rygel_content_directory_construct (GType object_type) {
	RygelContentDirectory * self;
	self = g_object_newv (object_type, 0, NULL);
	return self;
}


RygelContentDirectory* rygel_content_directory_new (void) {
	return rygel_content_directory_construct (RYGEL_TYPE_CONTENT_DIRECTORY);
}


static void rygel_content_directory_class_init (RygelContentDirectoryClass * klass) {
	rygel_content_directory_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelContentDirectoryPrivate));
	RYGEL_CONTENT_DIRECTORY_CLASS (klass)->create_root_container = rygel_content_directory_real_create_root_container;
	G_OBJECT_CLASS (klass)->constructed = rygel_content_directory_real_constructed;
	RYGEL_CONTENT_DIRECTORY_CLASS (klass)->browse_cb = rygel_content_directory_real_browse_cb;
	G_OBJECT_CLASS (klass)->finalize = rygel_content_directory_finalize;
}


static void rygel_content_directory_instance_init (RygelContentDirectory * self) {
	self->priv = RYGEL_CONTENT_DIRECTORY_GET_PRIVATE (self);
}


static void rygel_content_directory_finalize (GObject* obj) {
	RygelContentDirectory * self;
	self = RYGEL_CONTENT_DIRECTORY (obj);
	{
		g_cancellable_cancel (self->cancellable);
	}
	_g_free0 (self->feature_list);
	_g_free0 (self->search_caps);
	_g_free0 (self->sort_caps);
	_g_object_unref0 (self->http_server);
	_g_object_unref0 (self->root_container);
	_g_object_unref0 (self->priv->updated_containers);
	_g_object_unref0 (self->priv->browses);
	_g_object_unref0 (self->cancellable);
	G_OBJECT_CLASS (rygel_content_directory_parent_class)->finalize (obj);
}


GType rygel_content_directory_get_type (void) {
	static GType rygel_content_directory_type_id = 0;
	if (rygel_content_directory_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelContentDirectoryClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_content_directory_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelContentDirectory), 0, (GInstanceInitFunc) rygel_content_directory_instance_init, NULL };
		rygel_content_directory_type_id = g_type_register_static (GUPNP_TYPE_SERVICE, "RygelContentDirectory", &g_define_type_info, 0);
	}
	return rygel_content_directory_type_id;
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




