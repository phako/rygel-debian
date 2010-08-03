/* rygel-source-connection-manager.c generated by valac, the Vala compiler
 * generated from rygel-source-connection-manager.vala, do not modify */

/*
 * Copyright (C) 2009 Nokia Corporation.
 * Copyright (C) 2008 Zeeshan Ali (Khattak) <zeeshanak@gnome.org>.
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

#define RYGEL_TYPE_SOURCE_CONNECTION_MANAGER (rygel_source_connection_manager_get_type ())
#define RYGEL_SOURCE_CONNECTION_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_SOURCE_CONNECTION_MANAGER, RygelSourceConnectionManager))
#define RYGEL_SOURCE_CONNECTION_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_SOURCE_CONNECTION_MANAGER, RygelSourceConnectionManagerClass))
#define RYGEL_IS_SOURCE_CONNECTION_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_SOURCE_CONNECTION_MANAGER))
#define RYGEL_IS_SOURCE_CONNECTION_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_SOURCE_CONNECTION_MANAGER))
#define RYGEL_SOURCE_CONNECTION_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_SOURCE_CONNECTION_MANAGER, RygelSourceConnectionManagerClass))

typedef struct _RygelSourceConnectionManager RygelSourceConnectionManager;
typedef struct _RygelSourceConnectionManagerClass RygelSourceConnectionManagerClass;
typedef struct _RygelSourceConnectionManagerPrivate RygelSourceConnectionManagerPrivate;

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
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

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

struct _RygelConnectionManager {
	GUPnPService parent_instance;
	RygelConnectionManagerPrivate * priv;
	char* sink_protocol_info;
	char* connection_ids;
	char* source_protocol_info;
};

struct _RygelConnectionManagerClass {
	GUPnPServiceClass parent_class;
};

struct _RygelSourceConnectionManager {
	RygelConnectionManager parent_instance;
	RygelSourceConnectionManagerPrivate * priv;
};

struct _RygelSourceConnectionManagerClass {
	RygelConnectionManagerClass parent_class;
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
	RygelHTTPServer* http_server;
	RygelMediaContainer* root_container;
	GCancellable* cancellable;
	guint32 system_update_id;
};

struct _RygelContentDirectoryClass {
	GUPnPServiceClass parent_class;
};


static gpointer rygel_source_connection_manager_parent_class = NULL;

GType rygel_connection_manager_get_type (void) G_GNUC_CONST;
GType rygel_source_connection_manager_get_type (void) G_GNUC_CONST;
enum  {
	RYGEL_SOURCE_CONNECTION_MANAGER_DUMMY_PROPERTY
};
GType rygel_transcode_manager_get_type (void) G_GNUC_CONST;
GType rygel_http_server_get_type (void) G_GNUC_CONST;
static RygelHTTPServer* rygel_source_connection_manager_get_http_server (RygelSourceConnectionManager* self);
char* rygel_transcode_manager_get_protocol_info (RygelTranscodeManager* self);
static void rygel_source_connection_manager_real_constructed (GObject* base);
GType rygel_root_device_get_type (void) G_GNUC_CONST;
GType rygel_content_directory_get_type (void) G_GNUC_CONST;
GType rygel_media_object_get_type (void) G_GNUC_CONST;
GType rygel_media_container_get_type (void) G_GNUC_CONST;
RygelConnectionManager* rygel_connection_manager_new (void);
RygelConnectionManager* rygel_connection_manager_construct (GType object_type);
RygelSourceConnectionManager* rygel_source_connection_manager_new (void);
RygelSourceConnectionManager* rygel_source_connection_manager_construct (GType object_type);



#line 30 "rygel-source-connection-manager.vala"
static void rygel_source_connection_manager_real_constructed (GObject* base) {
#line 194 "rygel-source-connection-manager.c"
	RygelSourceConnectionManager * self;
	RygelHTTPServer* server;
	char* _tmp0_;
	self = (RygelSourceConnectionManager*) base;
#line 31 "rygel-source-connection-manager.vala"
	G_OBJECT_CLASS (rygel_source_connection_manager_parent_class)->constructed ((GObject*) RYGEL_CONNECTION_MANAGER (self));
#line 33 "rygel-source-connection-manager.vala"
	server = rygel_source_connection_manager_get_http_server (self);
#line 34 "rygel-source-connection-manager.vala"
	((RygelConnectionManager*) self)->source_protocol_info = (_tmp0_ = rygel_transcode_manager_get_protocol_info ((RygelTranscodeManager*) server), _g_free0 (((RygelConnectionManager*) self)->source_protocol_info), _tmp0_);
#line 205 "rygel-source-connection-manager.c"
	_g_object_unref0 (server);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


#line 37 "rygel-source-connection-manager.vala"
static RygelHTTPServer* rygel_source_connection_manager_get_http_server (RygelSourceConnectionManager* self) {
#line 217 "rygel-source-connection-manager.c"
	RygelHTTPServer* result = NULL;
	RygelHTTPServer* server;
	GUPnPRootDevice* _tmp0_ = NULL;
	RygelRootDevice* root_device;
#line 37 "rygel-source-connection-manager.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 38 "rygel-source-connection-manager.vala"
	server = NULL;
#line 40 "rygel-source-connection-manager.vala"
	root_device = RYGEL_ROOT_DEVICE ((g_object_get ((GUPnPService*) self, "root-device", &_tmp0_, NULL), _tmp0_));
#line 228 "rygel-source-connection-manager.c"
	{
		GeeIterator* _service_it;
#line 43 "rygel-source-connection-manager.vala"
		_service_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) root_device->services);
#line 43 "rygel-source-connection-manager.vala"
		while (TRUE) {
#line 235 "rygel-source-connection-manager.c"
			GUPnPServiceInfo* service;
#line 43 "rygel-source-connection-manager.vala"
			if (!gee_iterator_next (_service_it)) {
#line 43 "rygel-source-connection-manager.vala"
				break;
#line 241 "rygel-source-connection-manager.c"
			}
#line 43 "rygel-source-connection-manager.vala"
			service = (GUPnPServiceInfo*) gee_iterator_get (_service_it);
#line 44 "rygel-source-connection-manager.vala"
			if (g_type_is_a (G_TYPE_FROM_INSTANCE ((GObject*) service), RYGEL_TYPE_CONTENT_DIRECTORY)) {
#line 247 "rygel-source-connection-manager.c"
				RygelContentDirectory* content_directory;
				RygelHTTPServer* _tmp1_;
#line 45 "rygel-source-connection-manager.vala"
				content_directory = _g_object_ref0 (RYGEL_CONTENT_DIRECTORY (service));
#line 46 "rygel-source-connection-manager.vala"
				server = (_tmp1_ = _g_object_ref0 (content_directory->http_server), _g_object_unref0 (server), _tmp1_);
#line 254 "rygel-source-connection-manager.c"
				_g_object_unref0 (content_directory);
			}
			_g_object_unref0 (service);
		}
		_g_object_unref0 (_service_it);
	}
	result = server;
	_g_object_unref0 (root_device);
#line 50 "rygel-source-connection-manager.vala"
	return result;
#line 265 "rygel-source-connection-manager.c"
}


#line 29 "rygel-source-connection-manager.vala"
RygelSourceConnectionManager* rygel_source_connection_manager_construct (GType object_type) {
#line 271 "rygel-source-connection-manager.c"
	RygelSourceConnectionManager * self;
#line 29 "rygel-source-connection-manager.vala"
	self = (RygelSourceConnectionManager*) rygel_connection_manager_construct (object_type);
#line 275 "rygel-source-connection-manager.c"
	return self;
}


#line 29 "rygel-source-connection-manager.vala"
RygelSourceConnectionManager* rygel_source_connection_manager_new (void) {
#line 29 "rygel-source-connection-manager.vala"
	return rygel_source_connection_manager_construct (RYGEL_TYPE_SOURCE_CONNECTION_MANAGER);
#line 284 "rygel-source-connection-manager.c"
}


static void rygel_source_connection_manager_class_init (RygelSourceConnectionManagerClass * klass) {
	rygel_source_connection_manager_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->constructed = rygel_source_connection_manager_real_constructed;
}


static void rygel_source_connection_manager_instance_init (RygelSourceConnectionManager * self) {
}


GType rygel_source_connection_manager_get_type (void) {
	static volatile gsize rygel_source_connection_manager_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_source_connection_manager_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelSourceConnectionManagerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_source_connection_manager_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelSourceConnectionManager), 0, (GInstanceInitFunc) rygel_source_connection_manager_instance_init, NULL };
		GType rygel_source_connection_manager_type_id;
		rygel_source_connection_manager_type_id = g_type_register_static (RYGEL_TYPE_CONNECTION_MANAGER, "RygelSourceConnectionManager", &g_define_type_info, 0);
		g_once_init_leave (&rygel_source_connection_manager_type_id__volatile, rygel_source_connection_manager_type_id);
	}
	return rygel_source_connection_manager_type_id__volatile;
}




