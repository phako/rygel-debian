/*
 * Copyright (C) 2009 Zeeshan Ali (Khattak) <zeeshanak@gnome.org>.
 * Copyright (C) 2009 Nokia Corporation.
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
#include <dbus/dbus-glib-lowlevel.h>
#include <dbus/dbus-glib.h>
#include <stdlib.h>
#include <string.h>
#include <gee.h>
#include <gio/gio.h>


#define RYGEL_TYPE_EXTERNAL_CONTAINER (rygel_external_container_get_type ())
#define RYGEL_EXTERNAL_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_EXTERNAL_CONTAINER, RygelExternalContainer))
#define RYGEL_EXTERNAL_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_EXTERNAL_CONTAINER, RygelExternalContainerClass))
#define RYGEL_IS_EXTERNAL_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_EXTERNAL_CONTAINER))
#define RYGEL_IS_EXTERNAL_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_EXTERNAL_CONTAINER))
#define RYGEL_EXTERNAL_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_EXTERNAL_CONTAINER, RygelExternalContainerClass))

typedef struct _RygelExternalContainer RygelExternalContainer;
typedef struct _RygelExternalContainerClass RygelExternalContainerClass;
typedef struct _RygelExternalContainerPrivate RygelExternalContainerPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _dbus_g_connection_unref0(var) ((var == NULL) ? NULL : (var = (dbus_g_connection_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

#define RYGEL_TYPE_EXTERNAL_ITEM (rygel_external_item_get_type ())
#define RYGEL_EXTERNAL_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_EXTERNAL_ITEM, RygelExternalItem))
#define RYGEL_EXTERNAL_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_EXTERNAL_ITEM, RygelExternalItemClass))
#define RYGEL_IS_EXTERNAL_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_EXTERNAL_ITEM))
#define RYGEL_IS_EXTERNAL_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_EXTERNAL_ITEM))
#define RYGEL_EXTERNAL_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_EXTERNAL_ITEM, RygelExternalItemClass))

typedef struct _RygelExternalItem RygelExternalItem;
typedef struct _RygelExternalItemClass RygelExternalItemClass;
#define _g_regex_unref0(var) ((var == NULL) ? NULL : (var = (g_regex_unref (var), NULL)))

struct _RygelExternalContainer {
	RygelMediaContainer parent_instance;
	RygelExternalContainerPrivate * priv;
	DBusGProxy* actual_container;
	DBusGProxy* props;
	char* host_ip;
	char* service_name;
};

struct _RygelExternalContainerClass {
	RygelMediaContainerClass parent_class;
};

struct _RygelExternalContainerPrivate {
	char* object_path;
	GeeArrayList* containers;
};


static char* rygel_external_container_PROPS_IFACE;
static char* rygel_external_container_PROPS_IFACE = NULL;
static gpointer rygel_external_container_parent_class = NULL;

GType rygel_external_container_get_type (void);
#define RYGEL_EXTERNAL_CONTAINER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_EXTERNAL_CONTAINER, RygelExternalContainerPrivate))
enum  {
	RYGEL_EXTERNAL_CONTAINER_DUMMY_PROPERTY
};
#define RYGEL_EXTERNAL_CONTAINER_OBJECT_IFACE "org.gnome.UPnP.MediaObject1"
#define RYGEL_EXTERNAL_CONTAINER_CONTAINER_IFACE "org.gnome.UPnP.MediaContainer1"
#define RYGEL_EXTERNAL_CONTAINER_ITEM_IFACE "org.gnome.UPnP.MediaItem1"
void _dynamic_Get0 (DBusGProxy* self, const char* param1, const char* param2, GValue* param3, GError** error);
char* rygel_external_container_substitute_keywords (RygelExternalContainer* self, const char* title);
static void rygel_external_container_update_container (RygelExternalContainer* self, GError** error);
static void rygel_external_container_on_container_updated (RygelExternalContainer* self, DBusGProxy* actual_container);
static void _rygel_external_container_on_container_updated_dynamic_Updated0_ (DBusGProxy* _sender, gpointer self);
void _dynamic_Updated1_connect (gpointer obj, const char * signal_name, GCallback handler, gpointer data);
RygelExternalContainer* rygel_external_container_new (const char* id, const char* service_name, const char* object_path, const char* host_ip, RygelExternalContainer* parent);
RygelExternalContainer* rygel_external_container_construct (GType object_type, const char* id, const char* service_name, const char* object_path, const char* host_ip, RygelExternalContainer* parent);
void _dynamic_Get1 (DBusGProxy* self, const char* param1, const char* param2, GValue* param3, GError** error);
RygelExternalItem* rygel_external_item_new_for_path (const char* object_path, RygelExternalContainer* parent, GError** error);
RygelExternalItem* rygel_external_item_construct_for_path (GType object_type, const char* object_path, RygelExternalContainer* parent, GError** error);
GType rygel_external_item_get_type (void);
static void rygel_external_container_real_get_children (RygelMediaContainer* base, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target);
static GeeList* rygel_external_container_real_get_children_finish (RygelMediaContainer* base, GAsyncResult* res, GError** error);
static RygelMediaContainer* rygel_external_container_find_container (RygelExternalContainer* self, const char* id);
gboolean rygel_external_item_id_valid (const char* id);
RygelExternalItem* rygel_external_item_new_for_id (const char* id, RygelExternalContainer* parent, GError** error);
RygelExternalItem* rygel_external_item_construct_for_id (GType object_type, const char* id, RygelExternalContainer* parent, GError** error);
static void rygel_external_container_real_find_object (RygelMediaContainer* base, const char* id, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target);
static RygelMediaObject* rygel_external_container_real_find_object_finish (RygelMediaContainer* base, GAsyncResult* res, GError** error);
void _dynamic_Get2 (DBusGProxy* self, const char* param1, const char* param2, GValue* param3, GError** error);
void _dynamic_Get3 (DBusGProxy* self, const char* param1, const char* param2, GValue* param3, GError** error);
static void rygel_external_container_finalize (GObject* obj);
static int _vala_strcmp0 (const char * str1, const char * str2);



void _dynamic_Get0 (DBusGProxy* self, const char* param1, const char* param2, GValue* param3, GError** error) {
	dbus_g_proxy_call (self, "Get", error, G_TYPE_STRING, param1, G_TYPE_STRING, param2, G_TYPE_INVALID, G_TYPE_VALUE, param3, G_TYPE_INVALID);
	if (*error) {
		return;
	}
}


static void _rygel_external_container_on_container_updated_dynamic_Updated0_ (DBusGProxy* _sender, gpointer self) {
	rygel_external_container_on_container_updated (self, _sender);
}


void _dynamic_Updated1_connect (gpointer obj, const char * signal_name, GCallback handler, gpointer data) {
	dbus_g_object_register_marshaller (g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, G_TYPE_INVALID);
	dbus_g_proxy_add_signal (obj, "Updated", G_TYPE_INVALID);
	dbus_g_proxy_connect_signal (obj, signal_name, handler, data, NULL);
}


RygelExternalContainer* rygel_external_container_construct (GType object_type, const char* id, const char* service_name, const char* object_path, const char* host_ip, RygelExternalContainer* parent) {
	GError * _inner_error_;
	RygelExternalContainer * self;
	char* _tmp0_;
	char* _tmp1_;
	char* _tmp2_;
	GeeArrayList* _tmp3_;
	g_return_val_if_fail (id != NULL, NULL);
	g_return_val_if_fail (service_name != NULL, NULL);
	g_return_val_if_fail (object_path != NULL, NULL);
	g_return_val_if_fail (host_ip != NULL, NULL);
	_inner_error_ = NULL;
	self = (RygelExternalContainer*) rygel_media_container_construct (object_type, id, (RygelMediaContainer*) parent, "Uknown", (guint) 0);
	self->service_name = (_tmp0_ = g_strdup (service_name), _g_free0 (self->service_name), _tmp0_);
	self->priv->object_path = (_tmp1_ = g_strdup (object_path), _g_free0 (self->priv->object_path), _tmp1_);
	self->host_ip = (_tmp2_ = g_strdup (host_ip), _g_free0 (self->host_ip), _tmp2_);
	self->priv->containers = (_tmp3_ = gee_array_list_new (RYGEL_TYPE_EXTERNAL_CONTAINER, (GBoxedCopyFunc) g_object_ref, g_object_unref, g_direct_equal), _g_object_unref0 (self->priv->containers), _tmp3_);
	{
		DBusGConnection* connection;
		DBusGProxy* _tmp4_;
		GValue value = {0};
		GValue _tmp6_;
		GValue _tmp5_ = {0};
		char* _tmp7_;
		DBusGProxy* _tmp8_;
		connection = dbus_g_bus_get (DBUS_BUS_SESSION, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch0_g_error;
			goto __finally0;
		}
		self->props = (_tmp4_ = dbus_g_proxy_new_for_name (connection, service_name, object_path, rygel_external_container_PROPS_IFACE), _g_object_unref0 (self->props), _tmp4_);
		_dynamic_Get0 (self->props, RYGEL_EXTERNAL_CONTAINER_OBJECT_IFACE, "DisplayName", &_tmp5_, &_inner_error_);
		value = (_tmp6_ = _tmp5_, G_IS_VALUE (&value) ? (g_value_unset (&value), NULL) : NULL, _tmp6_);
		if (_inner_error_ != NULL) {
			_dbus_g_connection_unref0 (connection);
			G_IS_VALUE (&value) ? (g_value_unset (&value), NULL) : NULL;
			goto __catch0_g_error;
			goto __finally0;
		}
		((RygelMediaObject*) self)->title = (_tmp7_ = rygel_external_container_substitute_keywords (self, g_value_get_string (&value)), _g_free0 (((RygelMediaObject*) self)->title), _tmp7_);
		self->actual_container = (_tmp8_ = dbus_g_proxy_new_for_name (connection, service_name, object_path, RYGEL_EXTERNAL_CONTAINER_CONTAINER_IFACE), _g_object_unref0 (self->actual_container), _tmp8_);
		rygel_external_container_update_container (self, &_inner_error_);
		if (_inner_error_ != NULL) {
			_dbus_g_connection_unref0 (connection);
			G_IS_VALUE (&value) ? (g_value_unset (&value), NULL) : NULL;
			goto __catch0_g_error;
			goto __finally0;
		}
		_dynamic_Updated1_connect (self->actual_container, "Updated", (GCallback) _rygel_external_container_on_container_updated_dynamic_Updated0_, self);
		_dbus_g_connection_unref0 (connection);
		G_IS_VALUE (&value) ? (g_value_unset (&value), NULL) : NULL;
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			g_critical ("rygel-external-container.vala:82: Failed to fetch information about container '%s': %s\n", ((RygelMediaObject*) self)->id, err->message);
			_g_error_free0 (err);
		}
	}
	__finally0:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	return self;
}


RygelExternalContainer* rygel_external_container_new (const char* id, const char* service_name, const char* object_path, const char* host_ip, RygelExternalContainer* parent) {
	return rygel_external_container_construct (RYGEL_TYPE_EXTERNAL_CONTAINER, id, service_name, object_path, host_ip, parent);
}


void _dynamic_Get1 (DBusGProxy* self, const char* param1, const char* param2, GValue* param3, GError** error) {
	dbus_g_proxy_call (self, "Get", error, G_TYPE_STRING, param1, G_TYPE_STRING, param2, G_TYPE_INVALID, G_TYPE_VALUE, param3, G_TYPE_INVALID);
	if (*error) {
		return;
	}
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void rygel_external_container_real_get_children (RygelMediaContainer* base, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target) {
	RygelExternalContainer * self;
	GError * _inner_error_;
	GeeArrayList* media_objects;
	GValue value = {0};
	GValue _tmp1_;
	GValue _tmp0_ = {0};
	GPtrArray* obj_paths;
	guint stop;
	GeeList* children;
	RygelSimpleAsyncResult* res;
	GeeList* _tmp3_;
	self = (RygelExternalContainer*) base;
	_inner_error_ = NULL;
	media_objects = gee_array_list_new (RYGEL_TYPE_MEDIA_OBJECT, (GBoxedCopyFunc) g_object_ref, g_object_unref, g_direct_equal);
	gee_abstract_collection_add_all ((GeeAbstractCollection*) media_objects, (GeeCollection*) self->priv->containers);
	_dynamic_Get1 (self->props, RYGEL_EXTERNAL_CONTAINER_CONTAINER_IFACE, "Items", &_tmp0_, &_inner_error_);
	value = (_tmp1_ = _tmp0_, G_IS_VALUE (&value) ? (g_value_unset (&value), NULL) : NULL, _tmp1_);
	if (_inner_error_ != NULL) {
		_g_object_unref0 (media_objects);
		G_IS_VALUE (&value) ? (g_value_unset (&value), NULL) : NULL;
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return;
	}
	obj_paths = (GPtrArray*) g_value_get_boxed (&value);
	if (obj_paths->len > 0) {
		{
			gint i;
			i = 0;
			{
				gboolean _tmp2_;
				_tmp2_ = TRUE;
				while (TRUE) {
					char* obj_path;
					if (!_tmp2_) {
						i++;
					}
					_tmp2_ = FALSE;
					if (!(i < obj_paths->len)) {
						break;
					}
					obj_path = g_strdup ((const char*) obj_paths->pdata[i]);
					{
						RygelExternalItem* item;
						item = rygel_external_item_new_for_path (obj_path, self, &_inner_error_);
						if (_inner_error_ != NULL) {
							goto __catch1_g_error;
							goto __finally1;
						}
						gee_abstract_collection_add ((GeeAbstractCollection*) media_objects, (RygelMediaObject*) item);
						_g_object_unref0 (item);
					}
					goto __finally1;
					__catch1_g_error:
					{
						GError * err;
						err = _inner_error_;
						_inner_error_ = NULL;
						{
							g_warning ("rygel-external-container.vala:111: Error initializable item at '%s': %s. Ignoring..", obj_path, err->message);
							_g_error_free0 (err);
						}
					}
					__finally1:
					if (_inner_error_ != NULL) {
						_g_free0 (obj_path);
						_g_object_unref0 (media_objects);
						G_IS_VALUE (&value) ? (g_value_unset (&value), NULL) : NULL;
						g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
						g_clear_error (&_inner_error_);
						return;
					}
					_g_free0 (obj_path);
				}
			}
		}
	}
	stop = offset + max_count;
	stop = CLAMP (stop, (guint) 0, ((RygelMediaContainer*) self)->child_count);
	children = gee_abstract_list_slice ((GeeAbstractList*) media_objects, (gint) offset, (gint) stop);
	res = rygel_simple_async_result_new (GEE_TYPE_LIST, (GBoxedCopyFunc) g_object_ref, g_object_unref, (GObject*) self, callback, callback_target);
	res->data = (_tmp3_ = _g_object_ref0 (children), _g_object_unref0 (res->data), _tmp3_);
	rygel_simple_async_result_complete_in_idle (res);
	_g_object_unref0 (media_objects);
	G_IS_VALUE (&value) ? (g_value_unset (&value), NULL) : NULL;
	_g_object_unref0 (children);
	_g_object_unref0 (res);
}


static GeeList* rygel_external_container_real_get_children_finish (RygelMediaContainer* base, GAsyncResult* res, GError** error) {
	RygelExternalContainer * self;
	GeeList* result;
	RygelSimpleAsyncResult* simple_res;
	self = (RygelExternalContainer*) base;
	g_return_val_if_fail (res != NULL, NULL);
	simple_res = _g_object_ref0 (RYGEL_SIMPLE_ASYNC_RESULT (res));
	result = _g_object_ref0 ((GeeList*) simple_res->data);
	_g_object_unref0 (simple_res);
	return result;
}


static gpointer _g_error_copy0 (gpointer self) {
	return self ? g_error_copy (self) : NULL;
}


static void rygel_external_container_real_find_object (RygelMediaContainer* base, const char* id, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target) {
	RygelExternalContainer * self;
	GError * _inner_error_;
	RygelSimpleAsyncResult* res;
	RygelMediaObject* media_object;
	gboolean _tmp0_;
	RygelMediaObject* _tmp4_;
	self = (RygelExternalContainer*) base;
	g_return_if_fail (id != NULL);
	_inner_error_ = NULL;
	res = rygel_simple_async_result_new (RYGEL_TYPE_MEDIA_OBJECT, (GBoxedCopyFunc) g_object_ref, g_object_unref, (GObject*) self, callback, callback_target);
	media_object = (RygelMediaObject*) rygel_external_container_find_container (self, id);
	_tmp0_ = FALSE;
	if (media_object == NULL) {
		_tmp0_ = rygel_external_item_id_valid (id);
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		{
			RygelExternalItem* _tmp1_;
			RygelMediaObject* _tmp2_;
			_tmp1_ = rygel_external_item_new_for_id (id, self, &_inner_error_);
			if (_inner_error_ != NULL) {
				goto __catch2_g_error;
				goto __finally2;
			}
			media_object = (_tmp2_ = (RygelMediaObject*) _tmp1_, _g_object_unref0 (media_object), _tmp2_);
		}
		goto __finally2;
		__catch2_g_error:
		{
			GError * err;
			err = _inner_error_;
			_inner_error_ = NULL;
			{
				GError* _tmp3_;
				res->error = (_tmp3_ = _g_error_copy0 (err), _g_error_free0 (res->error), _tmp3_);
				_g_error_free0 (err);
			}
		}
		__finally2:
		if (_inner_error_ != NULL) {
			_g_object_unref0 (res);
			_g_object_unref0 (media_object);
			g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	res->data = (_tmp4_ = _g_object_ref0 (media_object), _g_object_unref0 (res->data), _tmp4_);
	rygel_simple_async_result_complete_in_idle (res);
	_g_object_unref0 (res);
	_g_object_unref0 (media_object);
}


static RygelMediaObject* rygel_external_container_real_find_object_finish (RygelMediaContainer* base, GAsyncResult* res, GError** error) {
	RygelExternalContainer * self;
	RygelMediaObject* result;
	GError * _inner_error_;
	RygelSimpleAsyncResult* simple_res;
	self = (RygelExternalContainer*) base;
	g_return_val_if_fail (res != NULL, NULL);
	_inner_error_ = NULL;
	simple_res = _g_object_ref0 (RYGEL_SIMPLE_ASYNC_RESULT (res));
	if (simple_res->error != NULL) {
		_inner_error_ = _g_error_copy0 (simple_res->error);
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_g_object_unref0 (simple_res);
			return NULL;
		}
	} else {
		result = _g_object_ref0 ((RygelMediaObject*) simple_res->data);
		_g_object_unref0 (simple_res);
		return result;
	}
	_g_object_unref0 (simple_res);
}


static char* string_replace (const char* self, const char* old, const char* replacement) {
	char* result;
	GError * _inner_error_;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (old != NULL, NULL);
	g_return_val_if_fail (replacement != NULL, NULL);
	_inner_error_ = NULL;
	{
		char* _tmp0_;
		GRegex* _tmp1_;
		GRegex* regex;
		char* _tmp2_;
		regex = (_tmp1_ = g_regex_new (_tmp0_ = g_regex_escape_string (old, -1), 0, 0, &_inner_error_), _g_free0 (_tmp0_), _tmp1_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch3_g_regex_error;
			}
			goto __finally3;
		}
		_tmp2_ = g_regex_replace_literal (regex, self, (glong) (-1), 0, replacement, 0, &_inner_error_);
		if (_inner_error_ != NULL) {
			_g_regex_unref0 (regex);
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch3_g_regex_error;
			}
			goto __finally3;
		}
		result = _tmp2_;
		_g_regex_unref0 (regex);
		return result;
	}
	goto __finally3;
	__catch3_g_regex_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			g_assert_not_reached ();
			_g_error_free0 (e);
		}
	}
	__finally3:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
}


char* rygel_external_container_substitute_keywords (RygelExternalContainer* self, const char* title) {
	char* result;
	char* new_title;
	char* _tmp0_;
	char* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (title != NULL, NULL);
	new_title = string_replace (title, "@REALNAME@", g_get_real_name ());
	new_title = (_tmp0_ = string_replace (new_title, "@USERNAME@", g_get_user_name ()), _g_free0 (new_title), _tmp0_);
	new_title = (_tmp1_ = string_replace (new_title, "@HOSTNAME@", g_get_host_name ()), _g_free0 (new_title), _tmp1_);
	result = new_title;
	return result;
}


static RygelMediaContainer* rygel_external_container_find_container (RygelExternalContainer* self, const char* id) {
	RygelMediaContainer* result;
	RygelMediaContainer* container;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (id != NULL, NULL);
	container = NULL;
	{
		GeeIterator* _tmp_it;
		_tmp_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->containers);
		while (TRUE) {
			RygelExternalContainer* tmp;
			if (!gee_iterator_next (_tmp_it)) {
				break;
			}
			tmp = (RygelExternalContainer*) gee_iterator_get (_tmp_it);
			if (_vala_strcmp0 (id, ((RygelMediaObject*) tmp)->id) == 0) {
				RygelMediaContainer* _tmp0_;
				container = (_tmp0_ = _g_object_ref0 ((RygelMediaContainer*) tmp), _g_object_unref0 (container), _tmp0_);
			} else {
				RygelMediaContainer* _tmp1_;
				container = (_tmp1_ = rygel_external_container_find_container (tmp, id), _g_object_unref0 (container), _tmp1_);
			}
			if (container != NULL) {
				_g_object_unref0 (tmp);
				break;
			}
			_g_object_unref0 (tmp);
		}
		_g_object_unref0 (_tmp_it);
	}
	result = container;
	return result;
}


void _dynamic_Get2 (DBusGProxy* self, const char* param1, const char* param2, GValue* param3, GError** error) {
	dbus_g_proxy_call (self, "Get", error, G_TYPE_STRING, param1, G_TYPE_STRING, param2, G_TYPE_INVALID, G_TYPE_VALUE, param3, G_TYPE_INVALID);
	if (*error) {
		return;
	}
}


void _dynamic_Get3 (DBusGProxy* self, const char* param1, const char* param2, GValue* param3, GError** error) {
	dbus_g_proxy_call (self, "Get", error, G_TYPE_STRING, param1, G_TYPE_STRING, param2, G_TYPE_INVALID, G_TYPE_VALUE, param3, G_TYPE_INVALID);
	if (*error) {
		return;
	}
}


static void rygel_external_container_update_container (RygelExternalContainer* self, GError** error) {
	GError * _inner_error_;
	GValue value = {0};
	GValue _tmp1_;
	GValue _tmp0_ = {0};
	GPtrArray* obj_paths;
	GValue _tmp6_;
	GValue _tmp5_ = {0};
	g_return_if_fail (self != NULL);
	_inner_error_ = NULL;
	gee_abstract_collection_clear ((GeeAbstractCollection*) self->priv->containers);
	_dynamic_Get2 (self->props, RYGEL_EXTERNAL_CONTAINER_CONTAINER_IFACE, "Containers", &_tmp0_, &_inner_error_);
	value = (_tmp1_ = _tmp0_, G_IS_VALUE (&value) ? (g_value_unset (&value), NULL) : NULL, _tmp1_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		G_IS_VALUE (&value) ? (g_value_unset (&value), NULL) : NULL;
		return;
	}
	obj_paths = (GPtrArray*) g_value_get_boxed (&value);
	if (obj_paths->len > 0) {
		{
			gint i;
			i = 0;
			{
				gboolean _tmp2_;
				_tmp2_ = TRUE;
				while (TRUE) {
					char* obj_path;
					char* _tmp3_;
					RygelExternalContainer* _tmp4_;
					RygelExternalContainer* container;
					if (!_tmp2_) {
						i++;
					}
					_tmp2_ = FALSE;
					if (!(i < obj_paths->len)) {
						break;
					}
					obj_path = g_strdup ((const char*) obj_paths->pdata[i]);
					container = (_tmp4_ = rygel_external_container_new (_tmp3_ = g_strconcat ("container:", (const char*) obj_path, NULL), self->service_name, obj_path, self->host_ip, self), _g_free0 (_tmp3_), _tmp4_);
					gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->containers, container);
					_g_free0 (obj_path);
					_g_object_unref0 (container);
				}
			}
		}
	}
	((RygelMediaContainer*) self)->child_count = (guint) gee_collection_get_size ((GeeCollection*) self->priv->containers);
	_dynamic_Get3 (self->props, RYGEL_EXTERNAL_CONTAINER_CONTAINER_IFACE, "ItemCount", &_tmp5_, &_inner_error_);
	value = (_tmp6_ = _tmp5_, G_IS_VALUE (&value) ? (g_value_unset (&value), NULL) : NULL, _tmp6_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		G_IS_VALUE (&value) ? (g_value_unset (&value), NULL) : NULL;
		return;
	}
	((RygelMediaContainer*) self)->child_count = ((RygelMediaContainer*) self)->child_count + g_value_get_uint (&value);
	G_IS_VALUE (&value) ? (g_value_unset (&value), NULL) : NULL;
}


static void rygel_external_container_on_container_updated (RygelExternalContainer* self, DBusGProxy* actual_container) {
	GError * _inner_error_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (actual_container != NULL);
	_inner_error_ = NULL;
	{
		rygel_external_container_update_container (self, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch4_g_error;
			goto __finally4;
		}
	}
	goto __finally4;
	__catch4_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			g_warning ("rygel-external-container.vala:226: Failed to update information about container '%s': %s\n", ((RygelMediaObject*) self)->id, err->message);
			_g_error_free0 (err);
		}
	}
	__finally4:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return;
	}
	rygel_media_container_updated ((RygelMediaContainer*) self);
}


static void rygel_external_container_class_init (RygelExternalContainerClass * klass) {
	rygel_external_container_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelExternalContainerPrivate));
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->get_children = rygel_external_container_real_get_children;
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->get_children_finish = rygel_external_container_real_get_children_finish;
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->find_object = rygel_external_container_real_find_object;
	RYGEL_MEDIA_CONTAINER_CLASS (klass)->find_object_finish = rygel_external_container_real_find_object_finish;
	G_OBJECT_CLASS (klass)->finalize = rygel_external_container_finalize;
	rygel_external_container_PROPS_IFACE = g_strdup ("org.freedesktop.DBus.Properties");
}


static void rygel_external_container_instance_init (RygelExternalContainer * self) {
	self->priv = RYGEL_EXTERNAL_CONTAINER_GET_PRIVATE (self);
}


static void rygel_external_container_finalize (GObject* obj) {
	RygelExternalContainer * self;
	self = RYGEL_EXTERNAL_CONTAINER (obj);
	_g_object_unref0 (self->actual_container);
	_g_object_unref0 (self->props);
	_g_free0 (self->host_ip);
	_g_free0 (self->service_name);
	_g_free0 (self->priv->object_path);
	_g_object_unref0 (self->priv->containers);
	G_OBJECT_CLASS (rygel_external_container_parent_class)->finalize (obj);
}


GType rygel_external_container_get_type (void) {
	static GType rygel_external_container_type_id = 0;
	if (rygel_external_container_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelExternalContainerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_external_container_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelExternalContainer), 0, (GInstanceInitFunc) rygel_external_container_instance_init, NULL };
		rygel_external_container_type_id = g_type_register_static (RYGEL_TYPE_MEDIA_CONTAINER, "RygelExternalContainer", &g_define_type_info, 0);
	}
	return rygel_external_container_type_id;
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




