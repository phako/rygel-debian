/* rygel-plugin.c generated by valac, the Vala compiler
 * generated from rygel-plugin.vala, do not modify */

/*
 * Copyright (C) 2008 Nokia Corporation.
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
#include <libgupnp/gupnp.h>
#include <stdlib.h>
#include <string.h>
#include <gee.h>
#include <config.h>


#define RYGEL_TYPE_PLUGIN (rygel_plugin_get_type ())
#define RYGEL_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_PLUGIN, RygelPlugin))
#define RYGEL_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_PLUGIN, RygelPluginClass))
#define RYGEL_IS_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_PLUGIN))
#define RYGEL_IS_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_PLUGIN))
#define RYGEL_PLUGIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_PLUGIN, RygelPluginClass))

typedef struct _RygelPlugin RygelPlugin;
typedef struct _RygelPluginClass RygelPluginClass;
typedef struct _RygelPluginPrivate RygelPluginPrivate;

#define RYGEL_TYPE_RESOURCE_INFO (rygel_resource_info_get_type ())
#define RYGEL_RESOURCE_INFO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_RESOURCE_INFO, RygelResourceInfo))
#define RYGEL_RESOURCE_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_RESOURCE_INFO, RygelResourceInfoClass))
#define RYGEL_IS_RESOURCE_INFO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_RESOURCE_INFO))
#define RYGEL_IS_RESOURCE_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_RESOURCE_INFO))
#define RYGEL_RESOURCE_INFO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_RESOURCE_INFO, RygelResourceInfoClass))

typedef struct _RygelResourceInfo RygelResourceInfo;
typedef struct _RygelResourceInfoClass RygelResourceInfoClass;

#define RYGEL_TYPE_ICON_INFO (rygel_icon_info_get_type ())
#define RYGEL_ICON_INFO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_ICON_INFO, RygelIconInfo))
#define RYGEL_ICON_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_ICON_INFO, RygelIconInfoClass))
#define RYGEL_IS_ICON_INFO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_ICON_INFO))
#define RYGEL_IS_ICON_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_ICON_INFO))
#define RYGEL_ICON_INFO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_ICON_INFO, RygelIconInfoClass))

typedef struct _RygelIconInfo RygelIconInfo;
typedef struct _RygelIconInfoClass RygelIconInfoClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _RygelIconInfoPrivate RygelIconInfoPrivate;
#define _rygel_icon_info_unref0(var) ((var == NULL) ? NULL : (var = (rygel_icon_info_unref (var), NULL)))
typedef struct _RygelResourceInfoPrivate RygelResourceInfoPrivate;

struct _RygelPlugin {
	GUPnPResourceFactory parent_instance;
	RygelPluginPrivate * priv;
	char* name;
	char* title;
	char* description;
	char* desc_path;
	GeeArrayList* resource_infos;
	GeeArrayList* icon_infos;
	GeeArrayList* default_icons;
};

struct _RygelPluginClass {
	GUPnPResourceFactoryClass parent_class;
};

struct _RygelPluginPrivate {
	gboolean _available;
};

struct _RygelIconInfo {
	GTypeInstance parent_instance;
	volatile int ref_count;
	RygelIconInfoPrivate * priv;
	char* mime_type;
	char* uri;
	glong size;
	gint width;
	gint height;
	gint depth;
};

struct _RygelIconInfoClass {
	GTypeClass parent_class;
	void (*finalize) (RygelIconInfo *self);
};

struct _RygelResourceInfo {
	GTypeInstance parent_instance;
	volatile int ref_count;
	RygelResourceInfoPrivate * priv;
	char* upnp_type;
	char* upnp_id;
	char* description_path;
	GType type;
};

struct _RygelResourceInfoClass {
	GTypeClass parent_class;
	void (*finalize) (RygelResourceInfo *self);
};


static gpointer rygel_plugin_parent_class = NULL;

GType rygel_plugin_get_type (void) G_GNUC_CONST;
gpointer rygel_resource_info_ref (gpointer instance);
void rygel_resource_info_unref (gpointer instance);
GParamSpec* rygel_param_spec_resource_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_resource_info (GValue* value, gpointer v_object);
void rygel_value_take_resource_info (GValue* value, gpointer v_object);
gpointer rygel_value_get_resource_info (const GValue* value);
GType rygel_resource_info_get_type (void) G_GNUC_CONST;
gpointer rygel_icon_info_ref (gpointer instance);
void rygel_icon_info_unref (gpointer instance);
GParamSpec* rygel_param_spec_icon_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_icon_info (GValue* value, gpointer v_object);
void rygel_value_take_icon_info (GValue* value, gpointer v_object);
gpointer rygel_value_get_icon_info (const GValue* value);
GType rygel_icon_info_get_type (void) G_GNUC_CONST;
#define RYGEL_PLUGIN_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_PLUGIN, RygelPluginPrivate))
enum  {
	RYGEL_PLUGIN_DUMMY_PROPERTY,
	RYGEL_PLUGIN_AVAILABLE
};
#define RYGEL_PLUGIN_ICON_BIG "file://" BIG_ICON_DIR "/rygel.png"
#define RYGEL_PLUGIN_ICON_SMALL "file://" SMALL_ICON_DIR "/rygel.png"
#define RYGEL_PLUGIN_ICON_MIME "image/png"
#define RYGEL_PLUGIN_ICON_DEPTH 32
#define RYGEL_PLUGIN_ICON_BIG_WIDTH 256
#define RYGEL_PLUGIN_ICON_BIG_HEIGHT 256
#define RYGEL_PLUGIN_ICON_SMALL_WIDTH 32
#define RYGEL_PLUGIN_ICON_SMALL_HEIGHT 32
void rygel_plugin_set_available (RygelPlugin* self, gboolean value);
RygelIconInfo* rygel_icon_info_new (const char* mime_type);
RygelIconInfo* rygel_icon_info_construct (GType object_type, const char* mime_type);
RygelPlugin* rygel_plugin_new (const char* desc_path, const char* name, const char* title, const char* description);
RygelPlugin* rygel_plugin_construct (GType object_type, const char* desc_path, const char* name, const char* title, const char* description);
void rygel_plugin_add_resource (RygelPlugin* self, RygelResourceInfo* resource_info);
void rygel_plugin_add_icon (RygelPlugin* self, RygelIconInfo* icon_info);
gboolean rygel_plugin_get_available (RygelPlugin* self);
static void rygel_plugin_finalize (GObject* obj);
static void rygel_plugin_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void rygel_plugin_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



#line 59 "rygel-plugin.vala"
RygelPlugin* rygel_plugin_construct (GType object_type, const char* desc_path, const char* name, const char* title, const char* description) {
#line 172 "rygel-plugin.c"
	RygelPlugin * self;
	char* _tmp0_;
	char* _tmp1_;
	char* _tmp2_;
	char* _tmp3_;
	GeeArrayList* _tmp5_;
	GeeArrayList* _tmp6_;
	GeeArrayList* _tmp7_;
	RygelIconInfo* icon;
	char* _tmp8_;
	RygelIconInfo* _tmp9_;
	char* _tmp10_;
#line 59 "rygel-plugin.vala"
	g_return_val_if_fail (desc_path != NULL, NULL);
#line 59 "rygel-plugin.vala"
	g_return_val_if_fail (name != NULL, NULL);
#line 189 "rygel-plugin.c"
	self = g_object_newv (object_type, 0, NULL);
#line 63 "rygel-plugin.vala"
	self->desc_path = (_tmp0_ = g_strdup (desc_path), _g_free0 (self->desc_path), _tmp0_);
#line 64 "rygel-plugin.vala"
	self->name = (_tmp1_ = g_strdup (name), _g_free0 (self->name), _tmp1_);
#line 65 "rygel-plugin.vala"
	self->title = (_tmp2_ = g_strdup (title), _g_free0 (self->title), _tmp2_);
#line 66 "rygel-plugin.vala"
	self->description = (_tmp3_ = g_strdup (description), _g_free0 (self->description), _tmp3_);
#line 68 "rygel-plugin.vala"
	rygel_plugin_set_available (self, TRUE);
#line 70 "rygel-plugin.vala"
	if (title == NULL) {
#line 203 "rygel-plugin.c"
		char* _tmp4_;
#line 71 "rygel-plugin.vala"
		self->title = (_tmp4_ = g_strdup (name), _g_free0 (self->title), _tmp4_);
#line 207 "rygel-plugin.c"
	}
#line 74 "rygel-plugin.vala"
	self->resource_infos = (_tmp5_ = gee_array_list_new (RYGEL_TYPE_RESOURCE_INFO, (GBoxedCopyFunc) rygel_resource_info_ref, rygel_resource_info_unref, NULL), _g_object_unref0 (self->resource_infos), _tmp5_);
#line 75 "rygel-plugin.vala"
	self->icon_infos = (_tmp6_ = gee_array_list_new (RYGEL_TYPE_ICON_INFO, (GBoxedCopyFunc) rygel_icon_info_ref, rygel_icon_info_unref, NULL), _g_object_unref0 (self->icon_infos), _tmp6_);
#line 76 "rygel-plugin.vala"
	self->default_icons = (_tmp7_ = gee_array_list_new (RYGEL_TYPE_ICON_INFO, (GBoxedCopyFunc) rygel_icon_info_ref, rygel_icon_info_unref, NULL), _g_object_unref0 (self->default_icons), _tmp7_);
#line 78 "rygel-plugin.vala"
	icon = rygel_icon_info_new (RYGEL_PLUGIN_ICON_MIME);
#line 79 "rygel-plugin.vala"
	icon->uri = (_tmp8_ = g_strdup (RYGEL_PLUGIN_ICON_BIG), _g_free0 (icon->uri), _tmp8_);
#line 80 "rygel-plugin.vala"
	icon->width = RYGEL_PLUGIN_ICON_BIG_WIDTH;
#line 81 "rygel-plugin.vala"
	icon->height = RYGEL_PLUGIN_ICON_BIG_HEIGHT;
#line 82 "rygel-plugin.vala"
	icon->depth = RYGEL_PLUGIN_ICON_DEPTH;
#line 83 "rygel-plugin.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) self->default_icons, icon);
#line 85 "rygel-plugin.vala"
	icon = (_tmp9_ = rygel_icon_info_new (RYGEL_PLUGIN_ICON_MIME), _rygel_icon_info_unref0 (icon), _tmp9_);
#line 86 "rygel-plugin.vala"
	icon->uri = (_tmp10_ = g_strdup (RYGEL_PLUGIN_ICON_SMALL), _g_free0 (icon->uri), _tmp10_);
#line 87 "rygel-plugin.vala"
	icon->width = RYGEL_PLUGIN_ICON_SMALL_WIDTH;
#line 88 "rygel-plugin.vala"
	icon->height = RYGEL_PLUGIN_ICON_SMALL_HEIGHT;
#line 89 "rygel-plugin.vala"
	icon->depth = RYGEL_PLUGIN_ICON_DEPTH;
#line 90 "rygel-plugin.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) self->default_icons, icon);
#line 239 "rygel-plugin.c"
	_rygel_icon_info_unref0 (icon);
	return self;
}


#line 59 "rygel-plugin.vala"
RygelPlugin* rygel_plugin_new (const char* desc_path, const char* name, const char* title, const char* description) {
#line 59 "rygel-plugin.vala"
	return rygel_plugin_construct (RYGEL_TYPE_PLUGIN, desc_path, name, title, description);
#line 249 "rygel-plugin.c"
}


#line 93 "rygel-plugin.vala"
void rygel_plugin_add_resource (RygelPlugin* self, RygelResourceInfo* resource_info) {
#line 93 "rygel-plugin.vala"
	g_return_if_fail (self != NULL);
#line 93 "rygel-plugin.vala"
	g_return_if_fail (resource_info != NULL);
#line 94 "rygel-plugin.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) self->resource_infos, resource_info);
#line 95 "rygel-plugin.vala"
	gupnp_resource_factory_register_resource_type ((GUPnPResourceFactory*) self, resource_info->upnp_type, resource_info->type);
#line 263 "rygel-plugin.c"
}


#line 99 "rygel-plugin.vala"
void rygel_plugin_add_icon (RygelPlugin* self, RygelIconInfo* icon_info) {
#line 99 "rygel-plugin.vala"
	g_return_if_fail (self != NULL);
#line 99 "rygel-plugin.vala"
	g_return_if_fail (icon_info != NULL);
#line 100 "rygel-plugin.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) self->icon_infos, icon_info);
#line 275 "rygel-plugin.c"
}


gboolean rygel_plugin_get_available (RygelPlugin* self) {
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_available;
#line 52 "rygel-plugin.vala"
	return result;
#line 285 "rygel-plugin.c"
}


void rygel_plugin_set_available (RygelPlugin* self, gboolean value) {
	g_return_if_fail (self != NULL);
	self->priv->_available = value;
	g_object_notify ((GObject *) self, "available");
}


static void rygel_plugin_class_init (RygelPluginClass * klass) {
	rygel_plugin_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelPluginPrivate));
	G_OBJECT_CLASS (klass)->get_property = rygel_plugin_get_property;
	G_OBJECT_CLASS (klass)->set_property = rygel_plugin_set_property;
	G_OBJECT_CLASS (klass)->finalize = rygel_plugin_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), RYGEL_PLUGIN_AVAILABLE, g_param_spec_boolean ("available", "available", "available", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void rygel_plugin_instance_init (RygelPlugin * self) {
	self->priv = RYGEL_PLUGIN_GET_PRIVATE (self);
}


static void rygel_plugin_finalize (GObject* obj) {
	RygelPlugin * self;
	self = RYGEL_PLUGIN (obj);
	_g_free0 (self->name);
	_g_free0 (self->title);
	_g_free0 (self->description);
	_g_free0 (self->desc_path);
	_g_object_unref0 (self->resource_infos);
	_g_object_unref0 (self->icon_infos);
	_g_object_unref0 (self->default_icons);
	G_OBJECT_CLASS (rygel_plugin_parent_class)->finalize (obj);
}


GType rygel_plugin_get_type (void) {
	static volatile gsize rygel_plugin_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_plugin_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelPluginClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_plugin_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelPlugin), 0, (GInstanceInitFunc) rygel_plugin_instance_init, NULL };
		GType rygel_plugin_type_id;
		rygel_plugin_type_id = g_type_register_static (GUPNP_TYPE_RESOURCE_FACTORY, "RygelPlugin", &g_define_type_info, 0);
		g_once_init_leave (&rygel_plugin_type_id__volatile, rygel_plugin_type_id);
	}
	return rygel_plugin_type_id__volatile;
}


static void rygel_plugin_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	RygelPlugin * self;
	self = RYGEL_PLUGIN (object);
	switch (property_id) {
		case RYGEL_PLUGIN_AVAILABLE:
		g_value_set_boolean (value, rygel_plugin_get_available (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void rygel_plugin_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	RygelPlugin * self;
	self = RYGEL_PLUGIN (object);
	switch (property_id) {
		case RYGEL_PLUGIN_AVAILABLE:
		rygel_plugin_set_available (self, g_value_get_boolean (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




