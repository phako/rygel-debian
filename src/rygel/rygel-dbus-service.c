/* rygel-dbus-service.c generated by valac, the Vala compiler
 * generated from rygel-dbus-service.vala, do not modify */

/*
 * Copyright (C) 2008 Nokia Corporation.
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
#include <stdlib.h>
#include <string.h>
#include <dbus/dbus-glib-lowlevel.h>
#include <dbus/dbus-glib.h>
#include <dbus/dbus.h>


#define RYGEL_TYPE_DBUS_SERVICE (rygel_dbus_service_get_type ())
#define RYGEL_DBUS_SERVICE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_DBUS_SERVICE, RygelDBusService))
#define RYGEL_DBUS_SERVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_DBUS_SERVICE, RygelDBusServiceClass))
#define RYGEL_IS_DBUS_SERVICE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_DBUS_SERVICE))
#define RYGEL_IS_DBUS_SERVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_DBUS_SERVICE))
#define RYGEL_DBUS_SERVICE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_DBUS_SERVICE, RygelDBusServiceClass))

typedef struct _RygelDBusService RygelDBusService;
typedef struct _RygelDBusServiceClass RygelDBusServiceClass;
typedef struct _RygelDBusServicePrivate RygelDBusServicePrivate;

#define RYGEL_TYPE_MAIN (rygel_main_get_type ())
#define RYGEL_MAIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MAIN, RygelMain))
#define RYGEL_MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MAIN, RygelMainClass))
#define RYGEL_IS_MAIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MAIN))
#define RYGEL_IS_MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MAIN))
#define RYGEL_MAIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MAIN, RygelMainClass))

typedef struct _RygelMain RygelMain;
typedef struct _RygelMainClass RygelMainClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _dbus_g_connection_unref0(var) ((var == NULL) ? NULL : (var = (dbus_g_connection_unref (var), NULL)))
typedef struct _DBusObjectVTable _DBusObjectVTable;

struct _RygelDBusService {
	GObject parent_instance;
	RygelDBusServicePrivate * priv;
};

struct _RygelDBusServiceClass {
	GObjectClass parent_class;
};

struct _RygelDBusServicePrivate {
	RygelMain* main;
};

struct _DBusObjectVTable {
	void (*register_object) (DBusConnection*, const char*, void*);
};


static char* rygel_dbus_service_RYGEL_SERVICE;
static char* rygel_dbus_service_RYGEL_SERVICE = NULL;
static char* rygel_dbus_service_RYGEL_PATH;
static char* rygel_dbus_service_RYGEL_PATH = NULL;
static gpointer rygel_dbus_service_parent_class = NULL;

GType rygel_dbus_service_get_type (void);
GType rygel_main_get_type (void);
#define RYGEL_DBUS_SERVICE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_DBUS_SERVICE, RygelDBusServicePrivate))
enum  {
	RYGEL_DBUS_SERVICE_DUMMY_PROPERTY
};
guint _dynamic_request_name2 (DBusGProxy* self, const char* param1, guint param2, GError** error);
RygelDBusService* rygel_dbus_service_new (RygelMain* main, GError** error);
RygelDBusService* rygel_dbus_service_construct (GType object_type, RygelMain* main, GError** error);
void rygel_main_exit (RygelMain* self, gint exit_code);
void rygel_dbus_service_Shutdown (RygelDBusService* self);
void rygel_dbus_service_dbus_register_object (DBusConnection* connection, const char* path, void* object);
void _rygel_dbus_service_dbus_unregister (DBusConnection* connection, void* _user_data_);
DBusHandlerResult rygel_dbus_service_dbus_message (DBusConnection* connection, DBusMessage* message, void* object);
static DBusHandlerResult _dbus_rygel_dbus_service_introspect (RygelDBusService* self, DBusConnection* connection, DBusMessage* message);
static DBusHandlerResult _dbus_rygel_dbus_service_property_get_all (RygelDBusService* self, DBusConnection* connection, DBusMessage* message);
static DBusHandlerResult _dbus_rygel_dbus_service_Shutdown (RygelDBusService* self, DBusConnection* connection, DBusMessage* message);
static void rygel_dbus_service_finalize (GObject* obj);
static void _vala_dbus_register_object (DBusConnection* connection, const char* path, void* object);
static void _vala_dbus_unregister_object (gpointer connection, GObject* object);

static const DBusObjectPathVTable _rygel_dbus_service_dbus_path_vtable = {_rygel_dbus_service_dbus_unregister, rygel_dbus_service_dbus_message};
static const _DBusObjectVTable _rygel_dbus_service_dbus_vtable = {rygel_dbus_service_dbus_register_object};


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


guint _dynamic_request_name2 (DBusGProxy* self, const char* param1, guint param2, GError** error) {
	guint result;
	dbus_g_proxy_call (self, "RequestName", error, G_TYPE_STRING, param1, G_TYPE_UINT, param2, G_TYPE_INVALID, G_TYPE_UINT, &result, G_TYPE_INVALID);
	if (*error) {
		return 0U;
	}
	return result;
}


RygelDBusService* rygel_dbus_service_construct (GType object_type, RygelMain* main, GError** error) {
	GError * _inner_error_;
	RygelDBusService * self;
	RygelMain* _tmp0_;
	DBusGConnection* conn;
	DBusGProxy* bus;
	guint request_name_result;
	g_return_val_if_fail (main != NULL, NULL);
	_inner_error_ = NULL;
	self = (RygelDBusService*) g_object_new (object_type, NULL);
	self->priv->main = (_tmp0_ = _g_object_ref0 (main), _g_object_unref0 (self->priv->main), _tmp0_);
	conn = dbus_g_bus_get (DBUS_BUS_SESSION, &_inner_error_);
	if (_inner_error_ != NULL) {
		if (_inner_error_->domain == DBUS_GERROR) {
			g_propagate_error (error, _inner_error_);
			return;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
	bus = dbus_g_proxy_new_for_name (conn, "org.freedesktop.DBus", "/org/freedesktop/DBus", "org.freedesktop.DBus");
	request_name_result = _dynamic_request_name2 (bus, rygel_dbus_service_RYGEL_SERVICE, (guint) 0, &_inner_error_);
	if (_inner_error_ != NULL) {
		if (_inner_error_->domain == DBUS_GERROR) {
			g_propagate_error (error, _inner_error_);
			_dbus_g_connection_unref0 (conn);
			_g_object_unref0 (bus);
			return;
		} else {
			_dbus_g_connection_unref0 (conn);
			_g_object_unref0 (bus);
			g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
	if (request_name_result != DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER) {
		g_warning ("rygel-dbus-service.vala:45: Failed to start D-Bus service, name '%s' already taken", rygel_dbus_service_RYGEL_SERVICE);
	} else {
		_vala_dbus_register_object (dbus_g_connection_get_connection (conn), rygel_dbus_service_RYGEL_PATH, (GObject*) self);
	}
	_dbus_g_connection_unref0 (conn);
	_g_object_unref0 (bus);
	return self;
}


RygelDBusService* rygel_dbus_service_new (RygelMain* main, GError** error) {
	return rygel_dbus_service_construct (RYGEL_TYPE_DBUS_SERVICE, main, error);
}


void rygel_dbus_service_Shutdown (RygelDBusService* self) {
	g_return_if_fail (self != NULL);
	rygel_main_exit (self->priv->main, 0);
}


void _rygel_dbus_service_dbus_unregister (DBusConnection* connection, void* _user_data_) {
}


static DBusHandlerResult _dbus_rygel_dbus_service_introspect (RygelDBusService* self, DBusConnection* connection, DBusMessage* message) {
	DBusMessage* reply;
	DBusMessageIter iter;
	GString* xml_data;
	char** children;
	int i;
	reply = dbus_message_new_method_return (message);
	dbus_message_iter_init_append (reply, &iter);
	xml_data = g_string_new ("<!DOCTYPE node PUBLIC \"-//freedesktop//DTD D-BUS Object Introspection 1.0//EN\" \"http://www.freedesktop.org/standards/dbus/1.0/introspect.dtd\">\n");
	g_string_append (xml_data, "<node>\n<interface name=\"org.freedesktop.DBus.Introspectable\">\n  <method name=\"Introspect\">\n    <arg name=\"data\" direction=\"out\" type=\"s\"/>\n  </method>\n</interface>\n<interface name=\"org.freedesktop.DBus.Properties\">\n  <method name=\"Get\">\n    <arg name=\"interface\" direction=\"in\" type=\"s\"/>\n    <arg name=\"propname\" direction=\"in\" type=\"s\"/>\n    <arg name=\"value\" direction=\"out\" type=\"v\"/>\n  </method>\n  <method name=\"Set\">\n    <arg name=\"interface\" direction=\"in\" type=\"s\"/>\n    <arg name=\"propname\" direction=\"in\" type=\"s\"/>\n    <arg name=\"value\" direction=\"in\" type=\"v\"/>\n  </method>\n  <method name=\"GetAll\">\n    <arg name=\"interface\" direction=\"in\" type=\"s\"/>\n    <arg name=\"props\" direction=\"out\" type=\"a{sv}\"/>\n  </method>\n</interface>\n<interface name=\"org.gnome.Rygel1\">\n  <method name=\"Shutdown\">\n  </method>\n</interface>\n");
	dbus_connection_list_registered (connection, g_object_get_data ((GObject *) self, "dbus_object_path"), &children);
	for (i = 0; children[i]; i++) {
		g_string_append_printf (xml_data, "<node name=\"%s\"/>\n", children[i]);
	}
	dbus_free_string_array (children);
	g_string_append (xml_data, "</node>\n");
	dbus_message_iter_append_basic (&iter, DBUS_TYPE_STRING, &xml_data->str);
	g_string_free (xml_data, TRUE);
	if (reply) {
		dbus_connection_send (connection, reply, NULL);
		dbus_message_unref (reply);
		return DBUS_HANDLER_RESULT_HANDLED;
	} else {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
}


static DBusHandlerResult _dbus_rygel_dbus_service_property_get_all (RygelDBusService* self, DBusConnection* connection, DBusMessage* message) {
	DBusMessage* reply;
	DBusMessageIter iter, reply_iter, subiter;
	char* interface_name;
	const char* _tmp0_;
	if (strcmp (dbus_message_get_signature (message), "s")) {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
	dbus_message_iter_init (message, &iter);
	reply = dbus_message_new_method_return (message);
	dbus_message_iter_init_append (reply, &reply_iter);
	dbus_message_iter_get_basic (&iter, &_tmp0_);
	dbus_message_iter_next (&iter);
	interface_name = g_strdup (_tmp0_);
	if (strcmp (interface_name, "org.gnome.Rygel1") == 0) {
		dbus_message_iter_open_container (&reply_iter, DBUS_TYPE_ARRAY, "{sv}", &subiter);
		dbus_message_iter_close_container (&reply_iter, &subiter);
	} else {
		dbus_message_unref (reply);
		reply = NULL;
	}
	g_free (interface_name);
	if (reply) {
		dbus_connection_send (connection, reply, NULL);
		dbus_message_unref (reply);
		return DBUS_HANDLER_RESULT_HANDLED;
	} else {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
}


static DBusHandlerResult _dbus_rygel_dbus_service_Shutdown (RygelDBusService* self, DBusConnection* connection, DBusMessage* message) {
	DBusMessageIter iter;
	GError* error;
	DBusMessage* reply;
	error = NULL;
	if (strcmp (dbus_message_get_signature (message), "")) {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
	dbus_message_iter_init (message, &iter);
	rygel_dbus_service_Shutdown (self);
	reply = dbus_message_new_method_return (message);
	dbus_message_iter_init_append (reply, &iter);
	if (reply) {
		dbus_connection_send (connection, reply, NULL);
		dbus_message_unref (reply);
		return DBUS_HANDLER_RESULT_HANDLED;
	} else {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
}


DBusHandlerResult rygel_dbus_service_dbus_message (DBusConnection* connection, DBusMessage* message, void* object) {
	DBusHandlerResult result;
	result = DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	if (dbus_message_is_method_call (message, "org.freedesktop.DBus.Introspectable", "Introspect")) {
		result = _dbus_rygel_dbus_service_introspect (object, connection, message);
	} else if (dbus_message_is_method_call (message, "org.freedesktop.DBus.Properties", "GetAll")) {
		result = _dbus_rygel_dbus_service_property_get_all (object, connection, message);
	} else if (dbus_message_is_method_call (message, "org.gnome.Rygel1", "Shutdown")) {
		result = _dbus_rygel_dbus_service_Shutdown (object, connection, message);
	}
	if (result == DBUS_HANDLER_RESULT_HANDLED) {
		return result;
	} else {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
}


void rygel_dbus_service_dbus_register_object (DBusConnection* connection, const char* path, void* object) {
	if (!g_object_get_data (object, "dbus_object_path")) {
		g_object_set_data (object, "dbus_object_path", g_strdup (path));
		dbus_connection_register_object_path (connection, path, &_rygel_dbus_service_dbus_path_vtable, object);
		g_object_weak_ref (object, _vala_dbus_unregister_object, connection);
	}
}


static void rygel_dbus_service_class_init (RygelDBusServiceClass * klass) {
	rygel_dbus_service_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelDBusServicePrivate));
	G_OBJECT_CLASS (klass)->finalize = rygel_dbus_service_finalize;
	g_type_set_qdata (RYGEL_TYPE_DBUS_SERVICE, g_quark_from_static_string ("DBusObjectVTable"), (void*) (&_rygel_dbus_service_dbus_vtable));
	rygel_dbus_service_RYGEL_SERVICE = g_strdup ("org.gnome.Rygel1");
	rygel_dbus_service_RYGEL_PATH = g_strdup ("/org/gnome/Rygel1");
}


static void rygel_dbus_service_instance_init (RygelDBusService * self) {
	self->priv = RYGEL_DBUS_SERVICE_GET_PRIVATE (self);
}


static void rygel_dbus_service_finalize (GObject* obj) {
	RygelDBusService * self;
	self = RYGEL_DBUS_SERVICE (obj);
	_g_object_unref0 (self->priv->main);
	G_OBJECT_CLASS (rygel_dbus_service_parent_class)->finalize (obj);
}


GType rygel_dbus_service_get_type (void) {
	static GType rygel_dbus_service_type_id = 0;
	if (rygel_dbus_service_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelDBusServiceClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_dbus_service_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelDBusService), 0, (GInstanceInitFunc) rygel_dbus_service_instance_init, NULL };
		rygel_dbus_service_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelDBusService", &g_define_type_info, 0);
	}
	return rygel_dbus_service_type_id;
}


static void _vala_dbus_register_object (DBusConnection* connection, const char* path, void* object) {
	const _DBusObjectVTable * vtable;
	vtable = g_type_get_qdata (G_TYPE_FROM_INSTANCE (object), g_quark_from_static_string ("DBusObjectVTable"));
	if (vtable) {
		vtable->register_object (connection, path, object);
	} else {
		g_warning ("Object does not implement any D-Bus interface");
	}
}


static void _vala_dbus_unregister_object (gpointer connection, GObject* object) {
	char* path;
	path = g_object_steal_data ((GObject*) object, "dbus_object_path");
	dbus_connection_unregister_object_path (connection, path);
	g_free (path);
}




