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
#include <stdlib.h>
#include <string.h>
#include <dbus/dbus-glib-lowlevel.h>
#include <dbus/dbus-glib.h>


#define RYGEL_TYPE_EXTERNAL_ITEM (rygel_external_item_get_type ())
#define RYGEL_EXTERNAL_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_EXTERNAL_ITEM, RygelExternalItem))
#define RYGEL_EXTERNAL_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_EXTERNAL_ITEM, RygelExternalItemClass))
#define RYGEL_IS_EXTERNAL_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_EXTERNAL_ITEM))
#define RYGEL_IS_EXTERNAL_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_EXTERNAL_ITEM))
#define RYGEL_EXTERNAL_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_EXTERNAL_ITEM, RygelExternalItemClass))

typedef struct _RygelExternalItem RygelExternalItem;
typedef struct _RygelExternalItemClass RygelExternalItemClass;
typedef struct _RygelExternalItemPrivate RygelExternalItemPrivate;

#define RYGEL_TYPE_EXTERNAL_CONTAINER (rygel_external_container_get_type ())
#define RYGEL_EXTERNAL_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_EXTERNAL_CONTAINER, RygelExternalContainer))
#define RYGEL_EXTERNAL_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_EXTERNAL_CONTAINER, RygelExternalContainerClass))
#define RYGEL_IS_EXTERNAL_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_EXTERNAL_CONTAINER))
#define RYGEL_IS_EXTERNAL_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_EXTERNAL_CONTAINER))
#define RYGEL_EXTERNAL_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_EXTERNAL_CONTAINER, RygelExternalContainerClass))

typedef struct _RygelExternalContainer RygelExternalContainer;
typedef struct _RygelExternalContainerClass RygelExternalContainerClass;
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _RygelExternalContainerPrivate RygelExternalContainerPrivate;
#define _dbus_g_connection_unref0(var) ((var == NULL) ? NULL : (var = (dbus_g_connection_unref (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_hash_table_unref0(var) ((var == NULL) ? NULL : (var = (g_hash_table_unref (var), NULL)))
#define _g_regex_unref0(var) ((var == NULL) ? NULL : (var = (g_regex_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _RygelExternalItem {
	RygelMediaItem parent_instance;
	RygelExternalItemPrivate * priv;
};

struct _RygelExternalItemClass {
	RygelMediaItemClass parent_class;
};

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


static char* rygel_external_item_PROPS_IFACE;
static char* rygel_external_item_PROPS_IFACE = NULL;
static char* rygel_external_item_OBJECT_IFACE;
static char* rygel_external_item_OBJECT_IFACE = NULL;
static char* rygel_external_item_ITEM_IFACE;
static char* rygel_external_item_ITEM_IFACE = NULL;
static gpointer rygel_external_item_parent_class = NULL;

GType rygel_external_item_get_type (void);
enum  {
	RYGEL_EXTERNAL_ITEM_DUMMY_PROPERTY
};
GType rygel_external_container_get_type (void);
static RygelExternalItem* rygel_external_item_new (const char* id, const char* object_path, RygelExternalContainer* parent, GError** error);
static RygelExternalItem* rygel_external_item_construct (GType object_type, const char* id, const char* object_path, RygelExternalContainer* parent, GError** error);
RygelExternalItem* rygel_external_item_new_for_path (const char* object_path, RygelExternalContainer* parent, GError** error);
RygelExternalItem* rygel_external_item_construct_for_path (GType object_type, const char* object_path, RygelExternalContainer* parent, GError** error);
RygelExternalItem* rygel_external_item_new_for_id (const char* id, RygelExternalContainer* parent, GError** error);
RygelExternalItem* rygel_external_item_construct_for_id (GType object_type, const char* id, RygelExternalContainer* parent, GError** error);
GHashTable* _dynamic_GetAll4 (DBusGProxy* self, const char* param1, GError** error);
static GValue* _g_value_dup (GValue* self);
char* rygel_external_container_substitute_keywords (RygelExternalContainer* self, const char* title);
void _dynamic_GetAll5 (DBusGProxy* self, const char* param1, GHashTable** param2, GError** error);
gboolean rygel_external_item_id_valid (const char* id);
static void rygel_external_item_finalize (GObject* obj);
static int _vala_strcmp0 (const char * str1, const char * str2);



RygelExternalItem* rygel_external_item_construct_for_path (GType object_type, const char* object_path, RygelExternalContainer* parent, GError** error) {
	RygelExternalItem * self;
	char* _tmp0_;
	g_return_val_if_fail (object_path != NULL, NULL);
	g_return_val_if_fail (parent != NULL, NULL);
	self = (RygelExternalItem*) rygel_external_item_construct (object_type, _tmp0_ = g_strconcat ("item:", object_path, NULL), object_path, parent, error);
	_g_free0 (_tmp0_);
	return self;
}


RygelExternalItem* rygel_external_item_new_for_path (const char* object_path, RygelExternalContainer* parent, GError** error) {
	return rygel_external_item_construct_for_path (RYGEL_TYPE_EXTERNAL_ITEM, object_path, parent, error);
}


RygelExternalItem* rygel_external_item_construct_for_id (GType object_type, const char* id, RygelExternalContainer* parent, GError** error) {
	RygelExternalItem * self;
	char* object_path;
	g_return_val_if_fail (id != NULL, NULL);
	g_return_val_if_fail (parent != NULL, NULL);
	object_path = g_strdup (strstr (id, "/"));
	g_assert (object_path != NULL);
	self = (RygelExternalItem*) rygel_external_item_construct (object_type, id, object_path, parent, error);
	_g_free0 (object_path);
	return self;
}


RygelExternalItem* rygel_external_item_new_for_id (const char* id, RygelExternalContainer* parent, GError** error) {
	return rygel_external_item_construct_for_id (RYGEL_TYPE_EXTERNAL_ITEM, id, parent, error);
}


GHashTable* _dynamic_GetAll4 (DBusGProxy* self, const char* param1, GError** error) {
	GHashTable* result;
	dbus_g_proxy_call (self, "GetAll", error, G_TYPE_STRING, param1, G_TYPE_INVALID, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), &result, G_TYPE_INVALID);
	if (*error) {
		return NULL;
	}
	return result;
}


static GValue* _g_value_dup (GValue* self) {
	return g_boxed_copy (G_TYPE_VALUE, self);
}


static gpointer __g_value_dup0 (gpointer self) {
	return self ? _g_value_dup (self) : NULL;
}


void _dynamic_GetAll5 (DBusGProxy* self, const char* param1, GHashTable** param2, GError** error) {
	dbus_g_proxy_call (self, "GetAll", error, G_TYPE_STRING, param1, G_TYPE_INVALID, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), param2, G_TYPE_INVALID);
	if (*error) {
		return;
	}
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
				goto __catch5_g_regex_error;
			}
			goto __finally5;
		}
		_tmp2_ = g_regex_replace_literal (regex, self, (glong) (-1), 0, replacement, 0, &_inner_error_);
		if (_inner_error_ != NULL) {
			_g_regex_unref0 (regex);
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch5_g_regex_error;
			}
			goto __finally5;
		}
		result = _tmp2_;
		_g_regex_unref0 (regex);
		return result;
	}
	goto __finally5;
	__catch5_g_regex_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			g_assert_not_reached ();
			_g_error_free0 (e);
		}
	}
	__finally5:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
}


static RygelExternalItem* rygel_external_item_construct (GType object_type, const char* id, const char* object_path, RygelExternalContainer* parent, GError** error) {
	GError * _inner_error_;
	RygelExternalItem * self;
	DBusGConnection* connection;
	DBusGProxy* props;
	GHashTable* object_props;
	GValue* value;
	char* _tmp0_;
	GHashTable* item_props;
	GHashTable* _tmp2_;
	GHashTable* _tmp1_;
	GValue* _tmp3_;
	char* type;
	GValue* _tmp8_;
	char* _tmp9_;
	GValue* _tmp10_;
	char** _tmp11_;
	gint uris_size;
	gint uris_length1;
	char** uris;
	GValue* _tmp13_;
	GValue* _tmp15_;
	GValue* _tmp16_;
	GValue* _tmp18_;
	GValue* _tmp20_;
	GValue* _tmp22_;
	GValue* _tmp23_;
	GValue* _tmp24_;
	GValue* _tmp25_;
	GValue* _tmp26_;
	GValue* _tmp27_;
	GValue* _tmp28_;
	g_return_val_if_fail (id != NULL, NULL);
	g_return_val_if_fail (object_path != NULL, NULL);
	g_return_val_if_fail (parent != NULL, NULL);
	_inner_error_ = NULL;
	self = (RygelExternalItem*) rygel_media_item_construct (object_type, id, (RygelMediaContainer*) parent, "Unknown", "Unknown");
	connection = dbus_g_bus_get (DBUS_BUS_SESSION, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return;
	}
	props = dbus_g_proxy_new_for_name (connection, parent->service_name, object_path, rygel_external_item_PROPS_IFACE);
	object_props = _dynamic_GetAll4 (props, rygel_external_item_OBJECT_IFACE, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_dbus_g_connection_unref0 (connection);
		_g_object_unref0 (props);
		return;
	}
	value = __g_value_dup0 ((GValue*) g_hash_table_lookup (object_props, "DisplayName"));
	((RygelMediaObject*) self)->title = (_tmp0_ = rygel_external_container_substitute_keywords (parent, g_value_get_string (value)), _g_free0 (((RygelMediaObject*) self)->title), _tmp0_);
	item_props = NULL;
	_tmp1_ = NULL;
	_dynamic_GetAll5 (props, rygel_external_item_ITEM_IFACE, &_tmp1_, &_inner_error_);
	item_props = (_tmp2_ = _tmp1_, _g_hash_table_unref0 (item_props), _tmp2_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_dbus_g_connection_unref0 (connection);
		_g_object_unref0 (props);
		_g_hash_table_unref0 (object_props);
		_g_free0 (value);
		_g_hash_table_unref0 (item_props);
		return;
	}
	value = (_tmp3_ = __g_value_dup0 ((GValue*) g_hash_table_lookup (item_props, "Type")), _g_free0 (value), _tmp3_);
	type = g_strdup (g_value_get_string (value));
	if (_vala_strcmp0 (type, "audio") == 0) {
		char* _tmp4_;
		((RygelMediaItem*) self)->upnp_class = (_tmp4_ = g_strdup (RYGEL_MEDIA_ITEM_AUDIO_CLASS), _g_free0 (((RygelMediaItem*) self)->upnp_class), _tmp4_);
	} else {
		if (_vala_strcmp0 (type, "music") == 0) {
			char* _tmp5_;
			((RygelMediaItem*) self)->upnp_class = (_tmp5_ = g_strdup (RYGEL_MEDIA_ITEM_MUSIC_CLASS), _g_free0 (((RygelMediaItem*) self)->upnp_class), _tmp5_);
		} else {
			if (_vala_strcmp0 (type, "video") == 0) {
				char* _tmp6_;
				((RygelMediaItem*) self)->upnp_class = (_tmp6_ = g_strdup (RYGEL_MEDIA_ITEM_VIDEO_CLASS), _g_free0 (((RygelMediaItem*) self)->upnp_class), _tmp6_);
			} else {
				char* _tmp7_;
				((RygelMediaItem*) self)->upnp_class = (_tmp7_ = g_strdup (RYGEL_MEDIA_ITEM_IMAGE_CLASS), _g_free0 (((RygelMediaItem*) self)->upnp_class), _tmp7_);
			}
		}
	}
	value = (_tmp8_ = __g_value_dup0 ((GValue*) g_hash_table_lookup (item_props, "MIMEType")), _g_free0 (value), _tmp8_);
	((RygelMediaItem*) self)->mime_type = (_tmp9_ = g_strdup (g_value_get_string (value)), _g_free0 (((RygelMediaItem*) self)->mime_type), _tmp9_);
	value = (_tmp10_ = __g_value_dup0 ((GValue*) g_hash_table_lookup (item_props, "URLs")), _g_free0 (value), _tmp10_);
	uris = (_tmp11_ = (char**) g_value_get_boxed (value), uris_length1 = -1, uris_size = uris_length1, _tmp11_);
	{
		gint i;
		i = 0;
		{
			gboolean _tmp12_;
			_tmp12_ = TRUE;
			while (TRUE) {
				char* tmp;
				if (!_tmp12_) {
					i++;
				}
				_tmp12_ = FALSE;
				if (!(uris[i] != NULL)) {
					break;
				}
				tmp = string_replace (uris[i], "@ADDRESS@", parent->host_ip);
				rygel_media_item_add_uri ((RygelMediaItem*) self, tmp, NULL);
				_g_free0 (tmp);
			}
		}
	}
	value = (_tmp13_ = __g_value_dup0 ((GValue*) g_hash_table_lookup (item_props, "DLNAProfile")), _g_free0 (value), _tmp13_);
	if (value != NULL) {
		char* _tmp14_;
		((RygelMediaItem*) self)->dlna_profile = (_tmp14_ = g_strdup (g_value_get_string (value)), _g_free0 (((RygelMediaItem*) self)->dlna_profile), _tmp14_);
	}
	value = (_tmp15_ = __g_value_dup0 ((GValue*) g_hash_table_lookup (item_props, "Size")), _g_free0 (value), _tmp15_);
	if (value != NULL) {
		((RygelMediaItem*) self)->size = (glong) g_value_get_int (value);
	}
	value = (_tmp16_ = __g_value_dup0 ((GValue*) g_hash_table_lookup (item_props, "Artist")), _g_free0 (value), _tmp16_);
	if (value != NULL) {
		char* _tmp17_;
		((RygelMediaItem*) self)->author = (_tmp17_ = g_strdup (g_value_get_string (value)), _g_free0 (((RygelMediaItem*) self)->author), _tmp17_);
	}
	value = (_tmp18_ = __g_value_dup0 ((GValue*) g_hash_table_lookup (item_props, "Album")), _g_free0 (value), _tmp18_);
	if (value != NULL) {
		char* _tmp19_;
		((RygelMediaItem*) self)->album = (_tmp19_ = g_strdup (g_value_get_string (value)), _g_free0 (((RygelMediaItem*) self)->album), _tmp19_);
	}
	value = (_tmp20_ = __g_value_dup0 ((GValue*) g_hash_table_lookup (item_props, "Date")), _g_free0 (value), _tmp20_);
	if (value != NULL) {
		char* _tmp21_;
		((RygelMediaItem*) self)->date = (_tmp21_ = g_strdup (g_value_get_string (value)), _g_free0 (((RygelMediaItem*) self)->date), _tmp21_);
	}
	value = (_tmp22_ = __g_value_dup0 ((GValue*) g_hash_table_lookup (item_props, "Duration")), _g_free0 (value), _tmp22_);
	if (value != NULL) {
		((RygelMediaItem*) self)->duration = (glong) g_value_get_int (value);
	}
	value = (_tmp23_ = __g_value_dup0 ((GValue*) g_hash_table_lookup (item_props, "Bitrate")), _g_free0 (value), _tmp23_);
	if (value != NULL) {
		((RygelMediaItem*) self)->bitrate = g_value_get_int (value);
	}
	value = (_tmp24_ = __g_value_dup0 ((GValue*) g_hash_table_lookup (item_props, "SampleRate")), _g_free0 (value), _tmp24_);
	if (value != NULL) {
		((RygelMediaItem*) self)->sample_freq = g_value_get_int (value);
	}
	value = (_tmp25_ = __g_value_dup0 ((GValue*) g_hash_table_lookup (item_props, "BitsPerSample")), _g_free0 (value), _tmp25_);
	if (value != NULL) {
		((RygelMediaItem*) self)->bits_per_sample = g_value_get_int (value);
	}
	value = (_tmp26_ = __g_value_dup0 ((GValue*) g_hash_table_lookup (item_props, "Width")), _g_free0 (value), _tmp26_);
	if (value != NULL) {
		((RygelMediaItem*) self)->width = g_value_get_int (value);
	}
	value = (_tmp27_ = __g_value_dup0 ((GValue*) g_hash_table_lookup (item_props, "Height")), _g_free0 (value), _tmp27_);
	if (value != NULL) {
		((RygelMediaItem*) self)->height = g_value_get_int (value);
	}
	value = (_tmp28_ = __g_value_dup0 ((GValue*) g_hash_table_lookup (item_props, "ColorDepth")), _g_free0 (value), _tmp28_);
	if (value != NULL) {
		((RygelMediaItem*) self)->color_depth = g_value_get_int (value);
	}
	_dbus_g_connection_unref0 (connection);
	_g_object_unref0 (props);
	_g_hash_table_unref0 (object_props);
	_g_free0 (value);
	_g_hash_table_unref0 (item_props);
	_g_free0 (type);
	return self;
}


static RygelExternalItem* rygel_external_item_new (const char* id, const char* object_path, RygelExternalContainer* parent, GError** error) {
	return rygel_external_item_construct (RYGEL_TYPE_EXTERNAL_ITEM, id, object_path, parent, error);
}


gboolean rygel_external_item_id_valid (const char* id) {
	gboolean result;
	g_return_val_if_fail (id != NULL, FALSE);
	result = g_str_has_prefix (id, "item:/");
	return result;
}


static void rygel_external_item_class_init (RygelExternalItemClass * klass) {
	rygel_external_item_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = rygel_external_item_finalize;
	rygel_external_item_PROPS_IFACE = g_strdup ("org.freedesktop.DBus.Properties");
	rygel_external_item_OBJECT_IFACE = g_strdup ("org.gnome.UPnP.MediaObject1");
	rygel_external_item_ITEM_IFACE = g_strdup ("org.gnome.UPnP.MediaItem1");
}


static void rygel_external_item_instance_init (RygelExternalItem * self) {
}


static void rygel_external_item_finalize (GObject* obj) {
	RygelExternalItem * self;
	self = RYGEL_EXTERNAL_ITEM (obj);
	G_OBJECT_CLASS (rygel_external_item_parent_class)->finalize (obj);
}


GType rygel_external_item_get_type (void) {
	static GType rygel_external_item_type_id = 0;
	if (rygel_external_item_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelExternalItemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_external_item_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelExternalItem), 0, (GInstanceInitFunc) rygel_external_item_instance_init, NULL };
		rygel_external_item_type_id = g_type_register_static (RYGEL_TYPE_MEDIA_ITEM, "RygelExternalItem", &g_define_type_info, 0);
	}
	return rygel_external_item_type_id;
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




