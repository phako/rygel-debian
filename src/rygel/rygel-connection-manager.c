/*
 * Copyright (C) 2008 OpenedHand Ltd.
 * Copyright (C) 2008 Zeeshan Ali <zeenix@gmail.com>.
 *
 * Author: Jorn Baayen <jorn@openedhand.com>
 *         Zeeshan Ali <zeenix@gmail.com>
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
#include <gee.h>
#include <gio/gio.h>


#define RYGEL_TYPE_CONNECTION_MANAGER (rygel_connection_manager_get_type ())
#define RYGEL_CONNECTION_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_CONNECTION_MANAGER, RygelConnectionManager))
#define RYGEL_CONNECTION_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_CONNECTION_MANAGER, RygelConnectionManagerClass))
#define RYGEL_IS_CONNECTION_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_CONNECTION_MANAGER))
#define RYGEL_IS_CONNECTION_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_CONNECTION_MANAGER))
#define RYGEL_CONNECTION_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_CONNECTION_MANAGER, RygelConnectionManagerClass))

typedef struct _RygelConnectionManager RygelConnectionManager;
typedef struct _RygelConnectionManagerClass RygelConnectionManagerClass;
typedef struct _RygelConnectionManagerPrivate RygelConnectionManagerPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))

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

#define RYGEL_TYPE_ROOT_DEVICE (rygel_root_device_get_type ())
#define RYGEL_ROOT_DEVICE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_ROOT_DEVICE, RygelRootDevice))
#define RYGEL_ROOT_DEVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_ROOT_DEVICE, RygelRootDeviceClass))
#define RYGEL_IS_ROOT_DEVICE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_ROOT_DEVICE))
#define RYGEL_IS_ROOT_DEVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_ROOT_DEVICE))
#define RYGEL_ROOT_DEVICE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_ROOT_DEVICE, RygelRootDeviceClass))

typedef struct _RygelRootDevice RygelRootDevice;
typedef struct _RygelRootDeviceClass RygelRootDeviceClass;
typedef struct _RygelRootDevicePrivate RygelRootDevicePrivate;

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
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _RygelConnectionManager {
	GUPnPService parent_instance;
	RygelConnectionManagerPrivate * priv;
	char* sink_protocol_info;
	char* connection_ids;
};

struct _RygelConnectionManagerClass {
	GUPnPServiceClass parent_class;
};

struct _RygelRootDevice {
	GUPnPRootDevice parent_instance;
	RygelRootDevicePrivate * priv;
	GeeArrayList* services;
};

struct _RygelRootDeviceClass {
	GUPnPRootDeviceClass parent_class;
};

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


static gpointer rygel_connection_manager_parent_class = NULL;

GType rygel_connection_manager_get_type (void);
enum  {
	RYGEL_CONNECTION_MANAGER_DUMMY_PROPERTY,
	RYGEL_CONNECTION_MANAGER_SOURCE_PROTOCOL_INFO
};
#define RYGEL_CONNECTION_MANAGER_UPNP_ID "urn:upnp-org:serviceId:ConnectionManager"
#define RYGEL_CONNECTION_MANAGER_UPNP_TYPE "urn:schemas-upnp-org:service:ConnectionManager:2"
#define RYGEL_CONNECTION_MANAGER_DESCRIPTION_PATH "xml/ConnectionManager.xml"
static void rygel_connection_manager_query_source_protocol_info_cb (RygelConnectionManager* self, RygelConnectionManager* cm, const char* var, GValue* val);
static void _rygel_connection_manager_query_source_protocol_info_cb_gupnp_service_query_variable (RygelConnectionManager* _sender, const char* variable, GValue* value, gpointer self);
static void rygel_connection_manager_query_sink_protocol_info_cb (RygelConnectionManager* self, RygelConnectionManager* cm, const char* var, GValue* val);
static void _rygel_connection_manager_query_sink_protocol_info_cb_gupnp_service_query_variable (RygelConnectionManager* _sender, const char* variable, GValue* value, gpointer self);
static void rygel_connection_manager_query_current_connection_ids_cb (RygelConnectionManager* self, RygelConnectionManager* cm, const char* var, GValue* val);
static void _rygel_connection_manager_query_current_connection_ids_cb_gupnp_service_query_variable (RygelConnectionManager* _sender, const char* variable, GValue* value, gpointer self);
static void rygel_connection_manager_get_protocol_info_cb (RygelConnectionManager* self, RygelConnectionManager* cm, GUPnPServiceAction* action);
static void _rygel_connection_manager_get_protocol_info_cb_gupnp_service_action_invoked (RygelConnectionManager* _sender, GUPnPServiceAction* action, gpointer self);
static void rygel_connection_manager_get_current_connection_ids_cb (RygelConnectionManager* self, RygelConnectionManager* cm, GUPnPServiceAction* action);
static void _rygel_connection_manager_get_current_connection_ids_cb_gupnp_service_action_invoked (RygelConnectionManager* _sender, GUPnPServiceAction* action, gpointer self);
static void rygel_connection_manager_get_current_connection_info_cb (RygelConnectionManager* self, RygelConnectionManager* cm, GUPnPServiceAction* action);
static void _rygel_connection_manager_get_current_connection_info_cb_gupnp_service_action_invoked (RygelConnectionManager* _sender, GUPnPServiceAction* action, gpointer self);
static void rygel_connection_manager_real_constructed (GObject* base);
char* rygel_connection_manager_get_source_protocol_info (RygelConnectionManager* self);
GType rygel_transcode_manager_get_type (void);
GType rygel_http_server_get_type (void);
GType rygel_root_device_get_type (void);
GType rygel_content_directory_get_type (void);
GType rygel_media_object_get_type (void);
GType rygel_media_container_get_type (void);
static RygelHTTPServer* rygel_connection_manager_get_http_server (RygelConnectionManager* self);
RygelConnectionManager* rygel_connection_manager_new (void);
RygelConnectionManager* rygel_connection_manager_construct (GType object_type);
char* rygel_transcode_manager_get_protocol_info (RygelTranscodeManager* self);
static void rygel_connection_manager_finalize (GObject* obj);
static void rygel_connection_manager_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);



static void _rygel_connection_manager_query_source_protocol_info_cb_gupnp_service_query_variable (RygelConnectionManager* _sender, const char* variable, GValue* value, gpointer self) {
	rygel_connection_manager_query_source_protocol_info_cb (self, _sender, variable, value);
}


static void _rygel_connection_manager_query_sink_protocol_info_cb_gupnp_service_query_variable (RygelConnectionManager* _sender, const char* variable, GValue* value, gpointer self) {
	rygel_connection_manager_query_sink_protocol_info_cb (self, _sender, variable, value);
}


static void _rygel_connection_manager_query_current_connection_ids_cb_gupnp_service_query_variable (RygelConnectionManager* _sender, const char* variable, GValue* value, gpointer self) {
	rygel_connection_manager_query_current_connection_ids_cb (self, _sender, variable, value);
}


static void _rygel_connection_manager_get_protocol_info_cb_gupnp_service_action_invoked (RygelConnectionManager* _sender, GUPnPServiceAction* action, gpointer self) {
	rygel_connection_manager_get_protocol_info_cb (self, _sender, action);
}


static void _rygel_connection_manager_get_current_connection_ids_cb_gupnp_service_action_invoked (RygelConnectionManager* _sender, GUPnPServiceAction* action, gpointer self) {
	rygel_connection_manager_get_current_connection_ids_cb (self, _sender, action);
}


static void _rygel_connection_manager_get_current_connection_info_cb_gupnp_service_action_invoked (RygelConnectionManager* _sender, GUPnPServiceAction* action, gpointer self) {
	rygel_connection_manager_get_current_connection_info_cb (self, _sender, action);
}


static void rygel_connection_manager_real_constructed (GObject* base) {
	RygelConnectionManager * self;
	char* _tmp0_;
	char* _tmp1_;
	self = (RygelConnectionManager*) base;
	self->sink_protocol_info = (_tmp0_ = g_strdup (""), _g_free0 (self->sink_protocol_info), _tmp0_);
	self->connection_ids = (_tmp1_ = g_strdup ("0"), _g_free0 (self->connection_ids), _tmp1_);
	g_signal_connect_object ((GUPnPService*) self, "query-variable::SourceProtocolInfo", (GCallback) _rygel_connection_manager_query_source_protocol_info_cb_gupnp_service_query_variable, self, 0);
	g_signal_connect_object ((GUPnPService*) self, "query-variable::SinkProtocolInfo", (GCallback) _rygel_connection_manager_query_sink_protocol_info_cb_gupnp_service_query_variable, self, 0);
	g_signal_connect_object ((GUPnPService*) self, "query-variable::CurrentConnectionIDs", (GCallback) _rygel_connection_manager_query_current_connection_ids_cb_gupnp_service_query_variable, self, 0);
	g_signal_connect_object ((GUPnPService*) self, "action-invoked::GetProtocolInfo", (GCallback) _rygel_connection_manager_get_protocol_info_cb_gupnp_service_action_invoked, self, 0);
	g_signal_connect_object ((GUPnPService*) self, "action-invoked::GetCurrentConnectionIDs", (GCallback) _rygel_connection_manager_get_current_connection_ids_cb_gupnp_service_action_invoked, self, 0);
	g_signal_connect_object ((GUPnPService*) self, "action-invoked::GetCurrentConnectionInfo", (GCallback) _rygel_connection_manager_get_current_connection_info_cb_gupnp_service_action_invoked, self, 0);
}


static void rygel_connection_manager_query_source_protocol_info_cb (RygelConnectionManager* self, RygelConnectionManager* cm, const char* var, GValue* val) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (cm != NULL);
	g_return_if_fail (var != NULL);
	g_value_init (&(*val), G_TYPE_STRING);
	g_value_set_string (&(*val), _tmp0_ = rygel_connection_manager_get_source_protocol_info (self));
	_g_free0 (_tmp0_);
}


static void rygel_connection_manager_query_sink_protocol_info_cb (RygelConnectionManager* self, RygelConnectionManager* cm, const char* var, GValue* val) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (cm != NULL);
	g_return_if_fail (var != NULL);
	g_value_init (&(*val), G_TYPE_STRING);
	g_value_set_string (&(*val), self->sink_protocol_info);
}


static void rygel_connection_manager_query_current_connection_ids_cb (RygelConnectionManager* self, RygelConnectionManager* cm, const char* var, GValue* val) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (cm != NULL);
	g_return_if_fail (var != NULL);
	g_value_init (&(*val), G_TYPE_STRING);
	g_value_set_string (&(*val), self->connection_ids);
}


static void rygel_connection_manager_get_protocol_info_cb (RygelConnectionManager* self, RygelConnectionManager* cm, GUPnPServiceAction* action) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (cm != NULL);
	g_return_if_fail (action != NULL);
	gupnp_service_action_set (action, "Source", G_TYPE_STRING, _tmp0_ = rygel_connection_manager_get_source_protocol_info (self), "Sink", G_TYPE_STRING, self->sink_protocol_info, NULL);
	_g_free0 (_tmp0_);
	gupnp_service_action_return (action);
}


static void rygel_connection_manager_get_current_connection_ids_cb (RygelConnectionManager* self, RygelConnectionManager* cm, GUPnPServiceAction* action) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (cm != NULL);
	g_return_if_fail (action != NULL);
	gupnp_service_action_set (action, "ConnectionIDs", G_TYPE_STRING, self->connection_ids, NULL);
	gupnp_service_action_return (action);
}


static void rygel_connection_manager_get_current_connection_info_cb (RygelConnectionManager* self, RygelConnectionManager* cm, GUPnPServiceAction* action) {
	gint connection_id;
	g_return_if_fail (self != NULL);
	g_return_if_fail (cm != NULL);
	g_return_if_fail (action != NULL);
	connection_id = 0;
	gupnp_service_action_get (action, "ConnectionID", G_TYPE_INT, &connection_id, NULL);
	if (connection_id != 0) {
		gupnp_service_action_return_error (action, (guint) 706, "Invalid connection reference");
		return;
	}
	gupnp_service_action_set (action, "ResID", G_TYPE_INT, -1, "AVTransportID", G_TYPE_INT, -1, "ProtocolInfo", G_TYPE_STRING, "", "PeerConnectionManager", G_TYPE_STRING, "", "PeerConnectionID", G_TYPE_INT, -1, "Direction", G_TYPE_STRING, "Input", "Status", G_TYPE_STRING, "Unknown", NULL);
	gupnp_service_action_return (action);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static RygelHTTPServer* rygel_connection_manager_get_http_server (RygelConnectionManager* self) {
	RygelHTTPServer* result;
	RygelHTTPServer* server;
	GUPnPRootDevice* _tmp0_;
	RygelRootDevice* root_device;
	g_return_val_if_fail (self != NULL, NULL);
	server = NULL;
	_tmp0_ = NULL;
	root_device = RYGEL_ROOT_DEVICE ((g_object_get ((GUPnPService*) self, "root-device", &_tmp0_, NULL), _tmp0_));
	{
		GeeIterator* _service_it;
		_service_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) root_device->services);
		while (TRUE) {
			GUPnPServiceInfo* service;
			if (!gee_iterator_next (_service_it)) {
				break;
			}
			service = (GUPnPServiceInfo*) gee_iterator_get (_service_it);
			if (g_type_is_a (G_TYPE_FROM_INSTANCE ((GObject*) service), RYGEL_TYPE_CONTENT_DIRECTORY)) {
				RygelContentDirectory* content_directory;
				RygelHTTPServer* _tmp1_;
				content_directory = _g_object_ref0 (RYGEL_CONTENT_DIRECTORY (service));
				server = (_tmp1_ = _g_object_ref0 (content_directory->http_server), _g_object_unref0 (server), _tmp1_);
				_g_object_unref0 (content_directory);
			}
			_g_object_unref0 (service);
		}
		_g_object_unref0 (_service_it);
	}
	result = server;
	_g_object_unref0 (root_device);
	return result;
}


RygelConnectionManager* rygel_connection_manager_construct (GType object_type) {
	RygelConnectionManager * self;
	self = g_object_newv (object_type, 0, NULL);
	return self;
}


RygelConnectionManager* rygel_connection_manager_new (void) {
	return rygel_connection_manager_construct (RYGEL_TYPE_CONNECTION_MANAGER);
}


char* rygel_connection_manager_get_source_protocol_info (RygelConnectionManager* self) {
	char* result;
	RygelHTTPServer* _tmp0_;
	char* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	result = (_tmp1_ = rygel_transcode_manager_get_protocol_info ((RygelTranscodeManager*) (_tmp0_ = rygel_connection_manager_get_http_server (self))), _g_object_unref0 (_tmp0_), _tmp1_);
	return result;
}


static void rygel_connection_manager_class_init (RygelConnectionManagerClass * klass) {
	rygel_connection_manager_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->constructed = rygel_connection_manager_real_constructed;
	G_OBJECT_CLASS (klass)->get_property = rygel_connection_manager_get_property;
	G_OBJECT_CLASS (klass)->finalize = rygel_connection_manager_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), RYGEL_CONNECTION_MANAGER_SOURCE_PROTOCOL_INFO, g_param_spec_string ("source-protocol-info", "source-protocol-info", "source-protocol-info", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
}


static void rygel_connection_manager_instance_init (RygelConnectionManager * self) {
}


static void rygel_connection_manager_finalize (GObject* obj) {
	RygelConnectionManager * self;
	self = RYGEL_CONNECTION_MANAGER (obj);
	_g_free0 (self->sink_protocol_info);
	_g_free0 (self->connection_ids);
	G_OBJECT_CLASS (rygel_connection_manager_parent_class)->finalize (obj);
}


GType rygel_connection_manager_get_type (void) {
	static GType rygel_connection_manager_type_id = 0;
	if (rygel_connection_manager_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelConnectionManagerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_connection_manager_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelConnectionManager), 0, (GInstanceInitFunc) rygel_connection_manager_instance_init, NULL };
		rygel_connection_manager_type_id = g_type_register_static (GUPNP_TYPE_SERVICE, "RygelConnectionManager", &g_define_type_info, 0);
	}
	return rygel_connection_manager_type_id;
}


static void rygel_connection_manager_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	RygelConnectionManager * self;
	self = RYGEL_CONNECTION_MANAGER (object);
	switch (property_id) {
		case RYGEL_CONNECTION_MANAGER_SOURCE_PROTOCOL_INFO:
		g_value_set_string (value, rygel_connection_manager_get_source_protocol_info (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




