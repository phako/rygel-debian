/*
 * Copyright (C) 2009 Jens Georg <mail@jensge.org>.
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
#include <dbus/dbus.h>


#define RYGEL_TYPE_MEDIA_EXPORT_DBUS_SERVICE (rygel_media_export_dbus_service_get_type ())
#define RYGEL_MEDIA_EXPORT_DBUS_SERVICE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_EXPORT_DBUS_SERVICE, RygelMediaExportDBusService))
#define RYGEL_MEDIA_EXPORT_DBUS_SERVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_EXPORT_DBUS_SERVICE, RygelMediaExportDBusServiceClass))
#define RYGEL_IS_MEDIA_EXPORT_DBUS_SERVICE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_EXPORT_DBUS_SERVICE))
#define RYGEL_IS_MEDIA_EXPORT_DBUS_SERVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_EXPORT_DBUS_SERVICE))
#define RYGEL_MEDIA_EXPORT_DBUS_SERVICE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_EXPORT_DBUS_SERVICE, RygelMediaExportDBusServiceClass))

typedef struct _RygelMediaExportDBusService RygelMediaExportDBusService;
typedef struct _RygelMediaExportDBusServiceClass RygelMediaExportDBusServiceClass;
typedef struct _RygelMediaExportDBusServicePrivate RygelMediaExportDBusServicePrivate;

#define RYGEL_TYPE_MEDIA_EXPORT_ROOT_CONTAINER (rygel_media_export_root_container_get_type ())
#define RYGEL_MEDIA_EXPORT_ROOT_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_EXPORT_ROOT_CONTAINER, RygelMediaExportRootContainer))
#define RYGEL_MEDIA_EXPORT_ROOT_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_EXPORT_ROOT_CONTAINER, RygelMediaExportRootContainerClass))
#define RYGEL_IS_MEDIA_EXPORT_ROOT_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_EXPORT_ROOT_CONTAINER))
#define RYGEL_IS_MEDIA_EXPORT_ROOT_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_EXPORT_ROOT_CONTAINER))
#define RYGEL_MEDIA_EXPORT_ROOT_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_EXPORT_ROOT_CONTAINER, RygelMediaExportRootContainerClass))

typedef struct _RygelMediaExportRootContainer RygelMediaExportRootContainer;
typedef struct _RygelMediaExportRootContainerClass RygelMediaExportRootContainerClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _dbus_g_connection_unref0(var) ((var == NULL) ? NULL : (var = (dbus_g_connection_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _DBusObjectVTable _DBusObjectVTable;

struct _RygelMediaExportDBusService {
	GObject parent_instance;
	RygelMediaExportDBusServicePrivate * priv;
};

struct _RygelMediaExportDBusServiceClass {
	GObjectClass parent_class;
};

struct _RygelMediaExportDBusServicePrivate {
	RygelMediaExportRootContainer* root_container;
};

struct _DBusObjectVTable {
	void (*register_object) (DBusConnection*, const char*, void*);
};


static gpointer rygel_media_export_dbus_service_parent_class = NULL;

GType rygel_media_export_dbus_service_get_type (void);
GType rygel_media_export_root_container_get_type (void);
#define RYGEL_MEDIA_EXPORT_DBUS_SERVICE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_MEDIA_EXPORT_DBUS_SERVICE, RygelMediaExportDBusServicePrivate))
enum  {
	RYGEL_MEDIA_EXPORT_DBUS_SERVICE_DUMMY_PROPERTY
};
#define RYGEL_MEDIA_EXPORT_DBUS_SERVICE_RYGEL_MEDIA_EXPORT_PATH "/org/gnome/Rygel/MediaExport1"
RygelMediaExportDBusService* rygel_media_export_dbus_service_new (RygelMediaExportRootContainer* root_container, GError** error);
RygelMediaExportDBusService* rygel_media_export_dbus_service_construct (GType object_type, RygelMediaExportRootContainer* root_container, GError** error);
void rygel_media_export_root_container_add_uri (RygelMediaExportRootContainer* self, const char* uri);
void rygel_media_export_dbus_service_AddUri (RygelMediaExportDBusService* self, const char* uri);
void rygel_media_export_root_container_remove_uri (RygelMediaExportRootContainer* self, const char* uri);
void rygel_media_export_dbus_service_RemoveUri (RygelMediaExportDBusService* self, const char* uri);
char** rygel_media_export_root_container_get_dynamic_uris (RygelMediaExportRootContainer* self, int* result_length1);
char** rygel_media_export_dbus_service_GetUris (RygelMediaExportDBusService* self, int* result_length1);
void rygel_media_export_dbus_service_dbus_register_object (DBusConnection* connection, const char* path, void* object);
void _rygel_media_export_dbus_service_dbus_unregister (DBusConnection* connection, void* _user_data_);
DBusHandlerResult rygel_media_export_dbus_service_dbus_message (DBusConnection* connection, DBusMessage* message, void* object);
static DBusHandlerResult _dbus_rygel_media_export_dbus_service_introspect (RygelMediaExportDBusService* self, DBusConnection* connection, DBusMessage* message);
static DBusHandlerResult _dbus_rygel_media_export_dbus_service_property_get_all (RygelMediaExportDBusService* self, DBusConnection* connection, DBusMessage* message);
static DBusHandlerResult _dbus_rygel_media_export_dbus_service_AddUri (RygelMediaExportDBusService* self, DBusConnection* connection, DBusMessage* message);
static DBusHandlerResult _dbus_rygel_media_export_dbus_service_RemoveUri (RygelMediaExportDBusService* self, DBusConnection* connection, DBusMessage* message);
static DBusHandlerResult _dbus_rygel_media_export_dbus_service_GetUris (RygelMediaExportDBusService* self, DBusConnection* connection, DBusMessage* message);
static void rygel_media_export_dbus_service_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_dbus_register_object (DBusConnection* connection, const char* path, void* object);
static void _vala_dbus_unregister_object (gpointer connection, GObject* object);

static const DBusObjectPathVTable _rygel_media_export_dbus_service_dbus_path_vtable = {_rygel_media_export_dbus_service_dbus_unregister, rygel_media_export_dbus_service_dbus_message};
static const _DBusObjectVTable _rygel_media_export_dbus_service_dbus_vtable = {rygel_media_export_dbus_service_dbus_register_object};


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


RygelMediaExportDBusService* rygel_media_export_dbus_service_construct (GType object_type, RygelMediaExportRootContainer* root_container, GError** error) {
	GError * _inner_error_;
	RygelMediaExportDBusService * self;
	RygelMediaExportRootContainer* _tmp0_;
	DBusGConnection* conn;
	g_return_val_if_fail (root_container != NULL, NULL);
	_inner_error_ = NULL;
	self = (RygelMediaExportDBusService*) g_object_new (object_type, NULL);
	self->priv->root_container = (_tmp0_ = _g_object_ref0 (root_container), _g_object_unref0 (self->priv->root_container), _tmp0_);
	conn = dbus_g_bus_get (DBUS_BUS_SESSION, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return;
	}
	_vala_dbus_register_object (dbus_g_connection_get_connection (conn), RYGEL_MEDIA_EXPORT_DBUS_SERVICE_RYGEL_MEDIA_EXPORT_PATH, (GObject*) self);
	_dbus_g_connection_unref0 (conn);
	return self;
}


RygelMediaExportDBusService* rygel_media_export_dbus_service_new (RygelMediaExportRootContainer* root_container, GError** error) {
	return rygel_media_export_dbus_service_construct (RYGEL_TYPE_MEDIA_EXPORT_DBUS_SERVICE, root_container, error);
}


void rygel_media_export_dbus_service_AddUri (RygelMediaExportDBusService* self, const char* uri) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (uri != NULL);
	rygel_media_export_root_container_add_uri (self->priv->root_container, uri);
}


void rygel_media_export_dbus_service_RemoveUri (RygelMediaExportDBusService* self, const char* uri) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (uri != NULL);
	rygel_media_export_root_container_remove_uri (self->priv->root_container, uri);
}


char** rygel_media_export_dbus_service_GetUris (RygelMediaExportDBusService* self, int* result_length1) {
	char** result;
	gint _tmp0_;
	char** _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	result = (_tmp1_ = rygel_media_export_root_container_get_dynamic_uris (self->priv->root_container, &_tmp0_), *result_length1 = _tmp0_, _tmp1_);
	return result;
}


void _rygel_media_export_dbus_service_dbus_unregister (DBusConnection* connection, void* _user_data_) {
}


static DBusHandlerResult _dbus_rygel_media_export_dbus_service_introspect (RygelMediaExportDBusService* self, DBusConnection* connection, DBusMessage* message) {
	DBusMessage* reply;
	DBusMessageIter iter;
	GString* xml_data;
	char** children;
	int i;
	reply = dbus_message_new_method_return (message);
	dbus_message_iter_init_append (reply, &iter);
	xml_data = g_string_new ("<!DOCTYPE node PUBLIC \"-//freedesktop//DTD D-BUS Object Introspection 1.0//EN\" \"http://www.freedesktop.org/standards/dbus/1.0/introspect.dtd\">\n");
	g_string_append (xml_data, "<node>\n<interface name=\"org.freedesktop.DBus.Introspectable\">\n  <method name=\"Introspect\">\n    <arg name=\"data\" direction=\"out\" type=\"s\"/>\n  </method>\n</interface>\n<interface name=\"org.freedesktop.DBus.Properties\">\n  <method name=\"Get\">\n    <arg name=\"interface\" direction=\"in\" type=\"s\"/>\n    <arg name=\"propname\" direction=\"in\" type=\"s\"/>\n    <arg name=\"value\" direction=\"out\" type=\"v\"/>\n  </method>\n  <method name=\"Set\">\n    <arg name=\"interface\" direction=\"in\" type=\"s\"/>\n    <arg name=\"propname\" direction=\"in\" type=\"s\"/>\n    <arg name=\"value\" direction=\"in\" type=\"v\"/>\n  </method>\n  <method name=\"GetAll\">\n    <arg name=\"interface\" direction=\"in\" type=\"s\"/>\n    <arg name=\"props\" direction=\"out\" type=\"a{sv}\"/>\n  </method>\n</interface>\n<interface name=\"org.gnome.Rygel.MediaExport1\">\n  <method name=\"AddUri\">\n    <arg name=\"uri\" type=\"s\" direction=\"in\"/>\n  </method>\n  <method name=\"RemoveUri\">\n    <arg name=\"uri\" type=\"s\" direction=\"in\"/>\n  </method>\n  <method name=\"GetUris\">\n    <arg name=\"result\" type=\"as\" direction=\"out\"/>\n  </method>\n</interface>\n");
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


static DBusHandlerResult _dbus_rygel_media_export_dbus_service_property_get_all (RygelMediaExportDBusService* self, DBusConnection* connection, DBusMessage* message) {
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
	if (strcmp (interface_name, "org.gnome.Rygel.MediaExport1") == 0) {
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


static DBusHandlerResult _dbus_rygel_media_export_dbus_service_AddUri (RygelMediaExportDBusService* self, DBusConnection* connection, DBusMessage* message) {
	DBusMessageIter iter;
	GError* error;
	char* uri;
	const char* _tmp1_;
	DBusMessage* reply;
	error = NULL;
	if (strcmp (dbus_message_get_signature (message), "s")) {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
	dbus_message_iter_init (message, &iter);
	uri = NULL;
	dbus_message_iter_get_basic (&iter, &_tmp1_);
	dbus_message_iter_next (&iter);
	uri = g_strdup (_tmp1_);
	rygel_media_export_dbus_service_AddUri (self, uri);
	reply = dbus_message_new_method_return (message);
	dbus_message_iter_init_append (reply, &iter);
	_g_free0 (uri);
	if (reply) {
		dbus_connection_send (connection, reply, NULL);
		dbus_message_unref (reply);
		return DBUS_HANDLER_RESULT_HANDLED;
	} else {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
}


static DBusHandlerResult _dbus_rygel_media_export_dbus_service_RemoveUri (RygelMediaExportDBusService* self, DBusConnection* connection, DBusMessage* message) {
	DBusMessageIter iter;
	GError* error;
	char* uri;
	const char* _tmp2_;
	DBusMessage* reply;
	error = NULL;
	if (strcmp (dbus_message_get_signature (message), "s")) {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
	dbus_message_iter_init (message, &iter);
	uri = NULL;
	dbus_message_iter_get_basic (&iter, &_tmp2_);
	dbus_message_iter_next (&iter);
	uri = g_strdup (_tmp2_);
	rygel_media_export_dbus_service_RemoveUri (self, uri);
	reply = dbus_message_new_method_return (message);
	dbus_message_iter_init_append (reply, &iter);
	_g_free0 (uri);
	if (reply) {
		dbus_connection_send (connection, reply, NULL);
		dbus_message_unref (reply);
		return DBUS_HANDLER_RESULT_HANDLED;
	} else {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
}


static DBusHandlerResult _dbus_rygel_media_export_dbus_service_GetUris (RygelMediaExportDBusService* self, DBusConnection* connection, DBusMessage* message) {
	DBusMessageIter iter;
	GError* error;
	char** result;
	int result_length1;
	DBusMessage* reply;
	char** _tmp3_;
	DBusMessageIter _tmp4_;
	int _tmp5_;
	error = NULL;
	if (strcmp (dbus_message_get_signature (message), "")) {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
	dbus_message_iter_init (message, &iter);
	result_length1 = 0;
	result = rygel_media_export_dbus_service_GetUris (self, &result_length1);
	reply = dbus_message_new_method_return (message);
	dbus_message_iter_init_append (reply, &iter);
	_tmp3_ = result;
	dbus_message_iter_open_container (&iter, DBUS_TYPE_ARRAY, "s", &_tmp4_);
	for (_tmp5_ = 0; _tmp5_ < result_length1; _tmp5_++) {
		const char* _tmp6_;
		_tmp6_ = *_tmp3_;
		dbus_message_iter_append_basic (&_tmp4_, DBUS_TYPE_STRING, &_tmp6_);
		_tmp3_++;
	}
	dbus_message_iter_close_container (&iter, &_tmp4_);
	result = (_vala_array_free (result,  result_length1, (GDestroyNotify) g_free), NULL);
	if (reply) {
		dbus_connection_send (connection, reply, NULL);
		dbus_message_unref (reply);
		return DBUS_HANDLER_RESULT_HANDLED;
	} else {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
}


DBusHandlerResult rygel_media_export_dbus_service_dbus_message (DBusConnection* connection, DBusMessage* message, void* object) {
	DBusHandlerResult result;
	result = DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	if (dbus_message_is_method_call (message, "org.freedesktop.DBus.Introspectable", "Introspect")) {
		result = _dbus_rygel_media_export_dbus_service_introspect (object, connection, message);
	} else if (dbus_message_is_method_call (message, "org.freedesktop.DBus.Properties", "GetAll")) {
		result = _dbus_rygel_media_export_dbus_service_property_get_all (object, connection, message);
	} else if (dbus_message_is_method_call (message, "org.gnome.Rygel.MediaExport1", "AddUri")) {
		result = _dbus_rygel_media_export_dbus_service_AddUri (object, connection, message);
	} else if (dbus_message_is_method_call (message, "org.gnome.Rygel.MediaExport1", "RemoveUri")) {
		result = _dbus_rygel_media_export_dbus_service_RemoveUri (object, connection, message);
	} else if (dbus_message_is_method_call (message, "org.gnome.Rygel.MediaExport1", "GetUris")) {
		result = _dbus_rygel_media_export_dbus_service_GetUris (object, connection, message);
	}
	if (result == DBUS_HANDLER_RESULT_HANDLED) {
		return result;
	} else {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
}


void rygel_media_export_dbus_service_dbus_register_object (DBusConnection* connection, const char* path, void* object) {
	if (!g_object_get_data (object, "dbus_object_path")) {
		g_object_set_data (object, "dbus_object_path", g_strdup (path));
		dbus_connection_register_object_path (connection, path, &_rygel_media_export_dbus_service_dbus_path_vtable, object);
		g_object_weak_ref (object, _vala_dbus_unregister_object, connection);
	}
}


static void rygel_media_export_dbus_service_class_init (RygelMediaExportDBusServiceClass * klass) {
	rygel_media_export_dbus_service_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelMediaExportDBusServicePrivate));
	G_OBJECT_CLASS (klass)->finalize = rygel_media_export_dbus_service_finalize;
	g_type_set_qdata (RYGEL_TYPE_MEDIA_EXPORT_DBUS_SERVICE, g_quark_from_static_string ("DBusObjectVTable"), (void*) (&_rygel_media_export_dbus_service_dbus_vtable));
}


static void rygel_media_export_dbus_service_instance_init (RygelMediaExportDBusService * self) {
	self->priv = RYGEL_MEDIA_EXPORT_DBUS_SERVICE_GET_PRIVATE (self);
}


static void rygel_media_export_dbus_service_finalize (GObject* obj) {
	RygelMediaExportDBusService * self;
	self = RYGEL_MEDIA_EXPORT_DBUS_SERVICE (obj);
	_g_object_unref0 (self->priv->root_container);
	G_OBJECT_CLASS (rygel_media_export_dbus_service_parent_class)->finalize (obj);
}


GType rygel_media_export_dbus_service_get_type (void) {
	static GType rygel_media_export_dbus_service_type_id = 0;
	if (rygel_media_export_dbus_service_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediaExportDBusServiceClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_media_export_dbus_service_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediaExportDBusService), 0, (GInstanceInitFunc) rygel_media_export_dbus_service_instance_init, NULL };
		rygel_media_export_dbus_service_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelMediaExportDBusService", &g_define_type_info, 0);
	}
	return rygel_media_export_dbus_service_type_id;
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



