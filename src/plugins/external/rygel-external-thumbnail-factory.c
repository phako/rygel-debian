/* rygel-external-thumbnail-factory.c generated by valac, the Vala compiler
 * generated from rygel-external-thumbnail-factory.vala, do not modify */

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
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>
#include <rygel.h>
#include <dbus/dbus-glib-lowlevel.h>
#include <dbus/dbus-glib.h>
#include <gobject/gvaluecollector.h>


#define RYGEL_EXTERNAL_TYPE_THUMBNAIL_FACTORY (rygel_external_thumbnail_factory_get_type ())
#define RYGEL_EXTERNAL_THUMBNAIL_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_EXTERNAL_TYPE_THUMBNAIL_FACTORY, RygelExternalThumbnailFactory))
#define RYGEL_EXTERNAL_THUMBNAIL_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_EXTERNAL_TYPE_THUMBNAIL_FACTORY, RygelExternalThumbnailFactoryClass))
#define RYGEL_EXTERNAL_IS_THUMBNAIL_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_EXTERNAL_TYPE_THUMBNAIL_FACTORY))
#define RYGEL_EXTERNAL_IS_THUMBNAIL_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_EXTERNAL_TYPE_THUMBNAIL_FACTORY))
#define RYGEL_EXTERNAL_THUMBNAIL_FACTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_EXTERNAL_TYPE_THUMBNAIL_FACTORY, RygelExternalThumbnailFactoryClass))

typedef struct _RygelExternalThumbnailFactory RygelExternalThumbnailFactory;
typedef struct _RygelExternalThumbnailFactoryClass RygelExternalThumbnailFactoryClass;
typedef struct _RygelExternalThumbnailFactoryPrivate RygelExternalThumbnailFactoryPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _rygel_icon_info_unref0(var) ((var == NULL) ? NULL : (var = (rygel_icon_info_unref (var), NULL)))

#define FREE_DESKTOP_TYPE_PROPERTIES (free_desktop_properties_get_type ())
#define FREE_DESKTOP_PROPERTIES(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FREE_DESKTOP_TYPE_PROPERTIES, FreeDesktopProperties))
#define FREE_DESKTOP_IS_PROPERTIES(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FREE_DESKTOP_TYPE_PROPERTIES))
#define FREE_DESKTOP_PROPERTIES_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), FREE_DESKTOP_TYPE_PROPERTIES, FreeDesktopPropertiesIface))

typedef struct _FreeDesktopProperties FreeDesktopProperties;
typedef struct _FreeDesktopPropertiesIface FreeDesktopPropertiesIface;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _dbus_g_connection_unref0(var) ((var == NULL) ? NULL : (var = (dbus_g_connection_unref (var), NULL)))
#define _g_regex_unref0(var) ((var == NULL) ? NULL : (var = (g_regex_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_hash_table_unref0(var) ((var == NULL) ? NULL : (var = (g_hash_table_unref (var), NULL)))
typedef struct _RygelExternalThumbnailFactoryCreateData RygelExternalThumbnailFactoryCreateData;
typedef struct _RygelExternalParamSpecThumbnailFactory RygelExternalParamSpecThumbnailFactory;

struct _RygelExternalThumbnailFactory {
	GTypeInstance parent_instance;
	volatile int ref_count;
	RygelExternalThumbnailFactoryPrivate * priv;
};

struct _RygelExternalThumbnailFactoryClass {
	GTypeClass parent_class;
	void (*finalize) (RygelExternalThumbnailFactory *self);
};

struct _FreeDesktopPropertiesIface {
	GTypeInterface parent_iface;
	void (*get_all) (FreeDesktopProperties* self, const char* iface, GAsyncReadyCallback _callback_, gpointer _user_data_);
	GHashTable* (*get_all_finish) (FreeDesktopProperties* self, GAsyncResult* _res_, GError** error);
};

struct _RygelExternalThumbnailFactoryCreateData {
	int _state_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	RygelExternalThumbnailFactory* self;
	char* service_name;
	char* object_path;
	char* host_ip;
	RygelThumbnail* result;
	DBusGConnection* connection;
	FreeDesktopProperties* props;
	GHashTable* item_props;
	RygelThumbnail* thumbnail;
	GValue* value;
	char* _tmp0_;
	GValue* _tmp1_;
	char** uris;
	char** _tmp2_;
	gint _uris_size_;
	gint uris_length1;
	gboolean _tmp3_;
	char* _tmp4_;
	GValue* _tmp5_;
	char* _tmp6_;
	GValue* _tmp7_;
	GValue* _tmp8_;
	GValue* _tmp9_;
	GValue* _tmp10_;
	GError * _inner_error_;
};

struct _RygelExternalParamSpecThumbnailFactory {
	GParamSpec parent_instance;
};


static gpointer rygel_external_thumbnail_factory_parent_class = NULL;

gpointer rygel_external_thumbnail_factory_ref (gpointer instance);
void rygel_external_thumbnail_factory_unref (gpointer instance);
GParamSpec* rygel_external_param_spec_thumbnail_factory (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_external_value_set_thumbnail_factory (GValue* value, gpointer v_object);
void rygel_external_value_take_thumbnail_factory (GValue* value, gpointer v_object);
gpointer rygel_external_value_get_thumbnail_factory (const GValue* value);
GType rygel_external_thumbnail_factory_get_type (void) G_GNUC_CONST;
enum  {
	RYGEL_EXTERNAL_THUMBNAIL_FACTORY_DUMMY_PROPERTY
};
static void rygel_external_thumbnail_factory_create_data_free (gpointer _data);
static void rygel_external_thumbnail_factory_create_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
FreeDesktopProperties* free_desktop_properties_dbus_proxy_new (DBusGConnection* connection, const char* name, const char* path);
GType free_desktop_properties_get_type (void) G_GNUC_CONST;
void free_desktop_properties_get_all (FreeDesktopProperties* self, const char* iface, GAsyncReadyCallback _callback_, gpointer _user_data_);
GHashTable* free_desktop_properties_get_all_finish (FreeDesktopProperties* self, GAsyncResult* _res_, GError** error);
#define RYGEL_EXTERNAL_MEDIA_ITEM_PROXY_IFACE "org.gnome.UPnP.MediaItem2"
static GValue* _g_value_dup (GValue* self);
void rygel_external_thumbnail_factory_create (RygelExternalThumbnailFactory* self, const char* service_name, const char* object_path, const char* host_ip, GAsyncReadyCallback _callback_, gpointer _user_data_);
RygelThumbnail* rygel_external_thumbnail_factory_create_finish (RygelExternalThumbnailFactory* self, GAsyncResult* _res_, GError** error);
static gboolean rygel_external_thumbnail_factory_create_co (RygelExternalThumbnailFactoryCreateData* data);
RygelExternalThumbnailFactory* rygel_external_thumbnail_factory_new (void);
RygelExternalThumbnailFactory* rygel_external_thumbnail_factory_construct (GType object_type);
static void rygel_external_thumbnail_factory_finalize (RygelExternalThumbnailFactory* obj);



static void rygel_external_thumbnail_factory_create_data_free (gpointer _data) {
	RygelExternalThumbnailFactoryCreateData* data;
	data = _data;
	_g_free0 (data->service_name);
	_g_free0 (data->object_path);
	_g_free0 (data->host_ip);
	_rygel_icon_info_unref0 (data->result);
	rygel_external_thumbnail_factory_unref (data->self);
	g_slice_free (RygelExternalThumbnailFactoryCreateData, data);
}


void rygel_external_thumbnail_factory_create (RygelExternalThumbnailFactory* self, const char* service_name, const char* object_path, const char* host_ip, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	RygelExternalThumbnailFactoryCreateData* _data_;
	_data_ = g_slice_new0 (RygelExternalThumbnailFactoryCreateData);
	_data_->_async_result = g_simple_async_result_new (g_object_newv (G_TYPE_OBJECT, 0, NULL), _callback_, _user_data_, rygel_external_thumbnail_factory_create);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, rygel_external_thumbnail_factory_create_data_free);
	_data_->self = rygel_external_thumbnail_factory_ref (self);
	_data_->service_name = g_strdup (service_name);
	_data_->object_path = g_strdup (object_path);
	_data_->host_ip = g_strdup (host_ip);
	rygel_external_thumbnail_factory_create_co (_data_);
}


RygelThumbnail* rygel_external_thumbnail_factory_create_finish (RygelExternalThumbnailFactory* self, GAsyncResult* _res_, GError** error) {
	RygelThumbnail* result;
	RygelExternalThumbnailFactoryCreateData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return NULL;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	_data_->result = NULL;
	return result;
}


static void rygel_external_thumbnail_factory_create_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	RygelExternalThumbnailFactoryCreateData* data;
	data = _user_data_;
	data->_res_ = _res_;
	rygel_external_thumbnail_factory_create_co (data);
}


static GValue* _g_value_dup (GValue* self) {
	return g_boxed_copy (G_TYPE_VALUE, self);
}


static gpointer __g_value_dup0 (gpointer self) {
	return self ? _g_value_dup (self) : NULL;
}


#line 1156 "glib-2.0.vapi"
static char* string_replace (const char* self, const char* old, const char* replacement) {
#line 208 "rygel-external-thumbnail-factory.c"
	char* result = NULL;
	GError * _inner_error_;
#line 1156 "glib-2.0.vapi"
	g_return_val_if_fail (self != NULL, NULL);
#line 1156 "glib-2.0.vapi"
	g_return_val_if_fail (old != NULL, NULL);
#line 1156 "glib-2.0.vapi"
	g_return_val_if_fail (replacement != NULL, NULL);
#line 217 "rygel-external-thumbnail-factory.c"
	_inner_error_ = NULL;
	{
		char* _tmp0_;
		GRegex* _tmp1_;
		GRegex* regex;
		char* _tmp2_;
#line 1158 "glib-2.0.vapi"
		regex = (_tmp1_ = g_regex_new (_tmp0_ = g_regex_escape_string (old, -1), 0, 0, &_inner_error_), _g_free0 (_tmp0_), _tmp1_);
#line 226 "rygel-external-thumbnail-factory.c"
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch3_g_regex_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
#line 1159 "glib-2.0.vapi"
		_tmp2_ = g_regex_replace_literal (regex, self, (gssize) (-1), 0, replacement, 0, &_inner_error_);
#line 237 "rygel-external-thumbnail-factory.c"
		if (_inner_error_ != NULL) {
			_g_regex_unref0 (regex);
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch3_g_regex_error;
			}
			_g_regex_unref0 (regex);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		result = _tmp2_;
		_g_regex_unref0 (regex);
#line 1159 "glib-2.0.vapi"
		return result;
#line 252 "rygel-external-thumbnail-factory.c"
	}
	goto __finally3;
	__catch3_g_regex_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
#line 1161 "glib-2.0.vapi"
			g_assert_not_reached ();
#line 263 "rygel-external-thumbnail-factory.c"
			_g_error_free0 (e);
		}
	}
	__finally3:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
}


static gboolean rygel_external_thumbnail_factory_create_co (RygelExternalThumbnailFactoryCreateData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		case 13:
		goto _state_13;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	{
		data->connection = dbus_g_bus_get (DBUS_BUS_SESSION, &data->_inner_error_);
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
		data->props = free_desktop_properties_dbus_proxy_new (data->connection, data->service_name, data->object_path);
		data->_state_ = 13;
		free_desktop_properties_get_all (data->props, RYGEL_EXTERNAL_MEDIA_ITEM_PROXY_IFACE, rygel_external_thumbnail_factory_create_ready, data);
		return FALSE;
		_state_13:
		data->item_props = free_desktop_properties_get_all_finish (data->props, data->_res_, &data->_inner_error_);
		if (data->_inner_error_ != NULL) {
			g_simple_async_result_set_from_error (data->_async_result, data->_inner_error_);
			g_error_free (data->_inner_error_);
			_g_object_unref0 (data->props);
			_dbus_g_connection_unref0 (data->connection);
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
		data->thumbnail = rygel_thumbnail_new ("image/jpeg", "JPEG_TN");
		data->value = __g_value_dup0 ((GValue*) g_hash_table_lookup (data->item_props, "MIMEType"));
#line 47 "rygel-external-thumbnail-factory.vala"
		((RygelIconInfo*) data->thumbnail)->mime_type = (data->_tmp0_ = g_strdup (g_value_get_string (data->value)), _g_free0 (((RygelIconInfo*) data->thumbnail)->mime_type), data->_tmp0_);
#line 49 "rygel-external-thumbnail-factory.vala"
		data->value = (data->_tmp1_ = __g_value_dup0 ((GValue*) g_hash_table_lookup (data->item_props, "URLs")), _g_free0 (data->value), data->_tmp1_);
#line 328 "rygel-external-thumbnail-factory.c"
		data->uris = (data->_tmp2_ = (char**) g_value_get_boxed (data->value), data->uris_length1 = -1, data->_uris_size_ = data->uris_length1, data->_tmp2_);
#line 51 "rygel-external-thumbnail-factory.vala"
		if (data->uris != NULL) {
#line 51 "rygel-external-thumbnail-factory.vala"
			data->_tmp3_ = data->uris[0] != NULL;
#line 334 "rygel-external-thumbnail-factory.c"
		} else {
#line 51 "rygel-external-thumbnail-factory.vala"
			data->_tmp3_ = FALSE;
#line 338 "rygel-external-thumbnail-factory.c"
		}
#line 51 "rygel-external-thumbnail-factory.vala"
		if (data->_tmp3_) {
#line 52 "rygel-external-thumbnail-factory.vala"
			((RygelIconInfo*) data->thumbnail)->uri = (data->_tmp4_ = string_replace (data->uris[0], "@ADDRESS@", data->host_ip), _g_free0 (((RygelIconInfo*) data->thumbnail)->uri), data->_tmp4_);
#line 344 "rygel-external-thumbnail-factory.c"
		}
#line 55 "rygel-external-thumbnail-factory.vala"
		data->value = (data->_tmp5_ = __g_value_dup0 ((GValue*) g_hash_table_lookup (data->item_props, "DLNAProfile")), _g_free0 (data->value), data->_tmp5_);
#line 56 "rygel-external-thumbnail-factory.vala"
		if (data->value != NULL) {
#line 57 "rygel-external-thumbnail-factory.vala"
			data->thumbnail->dlna_profile = (data->_tmp6_ = g_strdup (g_value_get_string (data->value)), _g_free0 (data->thumbnail->dlna_profile), data->_tmp6_);
#line 352 "rygel-external-thumbnail-factory.c"
		}
#line 60 "rygel-external-thumbnail-factory.vala"
		data->value = (data->_tmp7_ = __g_value_dup0 ((GValue*) g_hash_table_lookup (data->item_props, "Size")), _g_free0 (data->value), data->_tmp7_);
#line 61 "rygel-external-thumbnail-factory.vala"
		if (data->value != NULL) {
#line 62 "rygel-external-thumbnail-factory.vala"
			((RygelIconInfo*) data->thumbnail)->size = (glong) g_value_get_int (data->value);
#line 360 "rygel-external-thumbnail-factory.c"
		}
#line 65 "rygel-external-thumbnail-factory.vala"
		data->value = (data->_tmp8_ = __g_value_dup0 ((GValue*) g_hash_table_lookup (data->item_props, "Width")), _g_free0 (data->value), data->_tmp8_);
#line 66 "rygel-external-thumbnail-factory.vala"
		if (data->value != NULL) {
#line 67 "rygel-external-thumbnail-factory.vala"
			((RygelIconInfo*) data->thumbnail)->width = g_value_get_int (data->value);
#line 368 "rygel-external-thumbnail-factory.c"
		}
#line 70 "rygel-external-thumbnail-factory.vala"
		data->value = (data->_tmp9_ = __g_value_dup0 ((GValue*) g_hash_table_lookup (data->item_props, "Height")), _g_free0 (data->value), data->_tmp9_);
#line 71 "rygel-external-thumbnail-factory.vala"
		if (data->value != NULL) {
#line 72 "rygel-external-thumbnail-factory.vala"
			((RygelIconInfo*) data->thumbnail)->height = g_value_get_int (data->value);
#line 376 "rygel-external-thumbnail-factory.c"
		}
#line 75 "rygel-external-thumbnail-factory.vala"
		data->value = (data->_tmp10_ = __g_value_dup0 ((GValue*) g_hash_table_lookup (data->item_props, "ColorDepth")), _g_free0 (data->value), data->_tmp10_);
#line 76 "rygel-external-thumbnail-factory.vala"
		if (data->value != NULL) {
#line 77 "rygel-external-thumbnail-factory.vala"
			((RygelIconInfo*) data->thumbnail)->depth = g_value_get_int (data->value);
#line 384 "rygel-external-thumbnail-factory.c"
		}
		data->result = data->thumbnail;
		_g_free0 (data->value);
		_g_hash_table_unref0 (data->item_props);
		_g_object_unref0 (data->props);
		_dbus_g_connection_unref0 (data->connection);
		{
			if (data->_state_ == 0) {
				g_simple_async_result_complete_in_idle (data->_async_result);
			} else {
				g_simple_async_result_complete (data->_async_result);
			}
			g_object_unref (data->_async_result);
			return FALSE;
		}
		_g_free0 (data->value);
		_rygel_icon_info_unref0 (data->thumbnail);
		_g_hash_table_unref0 (data->item_props);
		_g_object_unref0 (data->props);
		_dbus_g_connection_unref0 (data->connection);
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


#line 31 "rygel-external-thumbnail-factory.vala"
RygelExternalThumbnailFactory* rygel_external_thumbnail_factory_construct (GType object_type) {
#line 420 "rygel-external-thumbnail-factory.c"
	RygelExternalThumbnailFactory* self;
	self = (RygelExternalThumbnailFactory*) g_type_create_instance (object_type);
	return self;
}


#line 31 "rygel-external-thumbnail-factory.vala"
RygelExternalThumbnailFactory* rygel_external_thumbnail_factory_new (void) {
#line 31 "rygel-external-thumbnail-factory.vala"
	return rygel_external_thumbnail_factory_construct (RYGEL_EXTERNAL_TYPE_THUMBNAIL_FACTORY);
#line 431 "rygel-external-thumbnail-factory.c"
}


static void rygel_external_value_thumbnail_factory_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void rygel_external_value_thumbnail_factory_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		rygel_external_thumbnail_factory_unref (value->data[0].v_pointer);
	}
}


static void rygel_external_value_thumbnail_factory_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = rygel_external_thumbnail_factory_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer rygel_external_value_thumbnail_factory_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* rygel_external_value_thumbnail_factory_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		RygelExternalThumbnailFactory* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = rygel_external_thumbnail_factory_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* rygel_external_value_thumbnail_factory_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	RygelExternalThumbnailFactory** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags && G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = rygel_external_thumbnail_factory_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* rygel_external_param_spec_thumbnail_factory (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	RygelExternalParamSpecThumbnailFactory* spec;
	g_return_val_if_fail (g_type_is_a (object_type, RYGEL_EXTERNAL_TYPE_THUMBNAIL_FACTORY), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer rygel_external_value_get_thumbnail_factory (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_EXTERNAL_TYPE_THUMBNAIL_FACTORY), NULL);
	return value->data[0].v_pointer;
}


void rygel_external_value_set_thumbnail_factory (GValue* value, gpointer v_object) {
	RygelExternalThumbnailFactory* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_EXTERNAL_TYPE_THUMBNAIL_FACTORY));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, RYGEL_EXTERNAL_TYPE_THUMBNAIL_FACTORY));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		rygel_external_thumbnail_factory_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		rygel_external_thumbnail_factory_unref (old);
	}
}


void rygel_external_value_take_thumbnail_factory (GValue* value, gpointer v_object) {
	RygelExternalThumbnailFactory* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_EXTERNAL_TYPE_THUMBNAIL_FACTORY));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, RYGEL_EXTERNAL_TYPE_THUMBNAIL_FACTORY));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		rygel_external_thumbnail_factory_unref (old);
	}
}


static void rygel_external_thumbnail_factory_class_init (RygelExternalThumbnailFactoryClass * klass) {
	rygel_external_thumbnail_factory_parent_class = g_type_class_peek_parent (klass);
	RYGEL_EXTERNAL_THUMBNAIL_FACTORY_CLASS (klass)->finalize = rygel_external_thumbnail_factory_finalize;
}


static void rygel_external_thumbnail_factory_instance_init (RygelExternalThumbnailFactory * self) {
	self->ref_count = 1;
}


static void rygel_external_thumbnail_factory_finalize (RygelExternalThumbnailFactory* obj) {
	RygelExternalThumbnailFactory * self;
	self = RYGEL_EXTERNAL_THUMBNAIL_FACTORY (obj);
}


GType rygel_external_thumbnail_factory_get_type (void) {
	static volatile gsize rygel_external_thumbnail_factory_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_external_thumbnail_factory_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { rygel_external_value_thumbnail_factory_init, rygel_external_value_thumbnail_factory_free_value, rygel_external_value_thumbnail_factory_copy_value, rygel_external_value_thumbnail_factory_peek_pointer, "p", rygel_external_value_thumbnail_factory_collect_value, "p", rygel_external_value_thumbnail_factory_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (RygelExternalThumbnailFactoryClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_external_thumbnail_factory_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelExternalThumbnailFactory), 0, (GInstanceInitFunc) rygel_external_thumbnail_factory_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType rygel_external_thumbnail_factory_type_id;
		rygel_external_thumbnail_factory_type_id = g_type_register_fundamental (g_type_fundamental_next (), "RygelExternalThumbnailFactory", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&rygel_external_thumbnail_factory_type_id__volatile, rygel_external_thumbnail_factory_type_id);
	}
	return rygel_external_thumbnail_factory_type_id__volatile;
}


gpointer rygel_external_thumbnail_factory_ref (gpointer instance) {
	RygelExternalThumbnailFactory* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void rygel_external_thumbnail_factory_unref (gpointer instance) {
	RygelExternalThumbnailFactory* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		RYGEL_EXTERNAL_THUMBNAIL_FACTORY_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}




