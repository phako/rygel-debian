/*
 * Copyright (C) 2008 Zeeshan Ali <zeenix@gmail.com>.
 *
 * Author: Zeeshan Ali <zeenix@gmail.com>
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
#include <libgupnp-av/gupnp-av.h>


#define RYGEL_TYPE_ICON_INFO (rygel_icon_info_get_type ())
#define RYGEL_ICON_INFO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_ICON_INFO, RygelIconInfo))
#define RYGEL_ICON_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_ICON_INFO, RygelIconInfoClass))
#define RYGEL_IS_ICON_INFO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_ICON_INFO))
#define RYGEL_IS_ICON_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_ICON_INFO))
#define RYGEL_ICON_INFO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_ICON_INFO, RygelIconInfoClass))

typedef struct _RygelIconInfo RygelIconInfo;
typedef struct _RygelIconInfoClass RygelIconInfoClass;
typedef struct _RygelIconInfoPrivate RygelIconInfoPrivate;

#define RYGEL_TYPE_THUMBNAIL (rygel_thumbnail_get_type ())
#define RYGEL_THUMBNAIL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_THUMBNAIL, RygelThumbnail))
#define RYGEL_THUMBNAIL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_THUMBNAIL, RygelThumbnailClass))
#define RYGEL_IS_THUMBNAIL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_THUMBNAIL))
#define RYGEL_IS_THUMBNAIL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_THUMBNAIL))
#define RYGEL_THUMBNAIL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_THUMBNAIL, RygelThumbnailClass))

typedef struct _RygelThumbnail RygelThumbnail;
typedef struct _RygelThumbnailClass RygelThumbnailClass;
typedef struct _RygelThumbnailPrivate RygelThumbnailPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _RygelIconInfo {
	GTypeInstance parent_instance;
	volatile int ref_count;
	RygelIconInfoPrivate * priv;
	char* mime_type;
	char* path;
	glong size;
	gint width;
	gint height;
	gint depth;
};

struct _RygelIconInfoClass {
	GTypeClass parent_class;
	void (*finalize) (RygelIconInfo *self);
};

struct _RygelThumbnail {
	RygelIconInfo parent_instance;
	RygelThumbnailPrivate * priv;
	char* uri;
	char* dlna_profile;
};

struct _RygelThumbnailClass {
	RygelIconInfoClass parent_class;
};


static gpointer rygel_thumbnail_parent_class = NULL;

gpointer rygel_icon_info_ref (gpointer instance);
void rygel_icon_info_unref (gpointer instance);
GParamSpec* rygel_param_spec_icon_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_icon_info (GValue* value, gpointer v_object);
gpointer rygel_value_get_icon_info (const GValue* value);
GType rygel_icon_info_get_type (void);
GType rygel_thumbnail_get_type (void);
enum  {
	RYGEL_THUMBNAIL_DUMMY_PROPERTY
};
RygelIconInfo* rygel_icon_info_new (const char* mime_type);
RygelIconInfo* rygel_icon_info_construct (GType object_type, const char* mime_type);
RygelThumbnail* rygel_thumbnail_new (const char* mime_type, const char* dlna_profile);
RygelThumbnail* rygel_thumbnail_construct (GType object_type, const char* mime_type, const char* dlna_profile);
static GUPnPProtocolInfo* rygel_thumbnail_get_protocol_info (RygelThumbnail* self, const char* protocol);
GUPnPDIDLLiteResource* rygel_thumbnail_add_resource (RygelThumbnail* self, GUPnPDIDLLiteItem* didl_item, const char* protocol);
static void rygel_thumbnail_finalize (RygelIconInfo* obj);



RygelThumbnail* rygel_thumbnail_construct (GType object_type, const char* mime_type, const char* dlna_profile) {
	RygelThumbnail* self;
	char* _tmp0_;
	g_return_val_if_fail (mime_type != NULL, NULL);
	g_return_val_if_fail (dlna_profile != NULL, NULL);
	self = (RygelThumbnail*) rygel_icon_info_construct (object_type, mime_type);
	self->dlna_profile = (_tmp0_ = g_strdup (dlna_profile), _g_free0 (self->dlna_profile), _tmp0_);
	return self;
}


RygelThumbnail* rygel_thumbnail_new (const char* mime_type, const char* dlna_profile) {
	return rygel_thumbnail_construct (RYGEL_TYPE_THUMBNAIL, mime_type, dlna_profile);
}


GUPnPDIDLLiteResource* rygel_thumbnail_add_resource (RygelThumbnail* self, GUPnPDIDLLiteItem* didl_item, const char* protocol) {
	GUPnPDIDLLiteResource* result;
	GUPnPDIDLLiteResource* res;
	GUPnPProtocolInfo* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (didl_item != NULL, NULL);
	g_return_val_if_fail (protocol != NULL, NULL);
	res = gupnp_didl_lite_object_add_resource ((GUPnPDIDLLiteObject*) didl_item);
	gupnp_didl_lite_resource_set_uri (res, self->uri);
	gupnp_didl_lite_resource_set_size (res, ((RygelIconInfo*) self)->size);
	gupnp_didl_lite_resource_set_width (res, ((RygelIconInfo*) self)->width);
	gupnp_didl_lite_resource_set_height (res, ((RygelIconInfo*) self)->height);
	gupnp_didl_lite_resource_set_color_depth (res, ((RygelIconInfo*) self)->depth);
	gupnp_didl_lite_resource_set_protocol_info (res, _tmp0_ = rygel_thumbnail_get_protocol_info (self, protocol));
	_g_object_unref0 (_tmp0_);
	result = res;
	return result;
}


static GUPnPProtocolInfo* rygel_thumbnail_get_protocol_info (RygelThumbnail* self, const char* protocol) {
	GUPnPProtocolInfo* result;
	GUPnPProtocolInfo* protocol_info;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (protocol != NULL, NULL);
	protocol_info = gupnp_protocol_info_new ();
	gupnp_protocol_info_set_mime_type (protocol_info, ((RygelIconInfo*) self)->mime_type);
	gupnp_protocol_info_set_dlna_profile (protocol_info, self->dlna_profile);
	gupnp_protocol_info_set_protocol (protocol_info, protocol);
	gupnp_protocol_info_set_dlna_flags (protocol_info, gupnp_protocol_info_get_dlna_flags (protocol_info) | (GUPNP_DLNA_FLAGS_INTERACTIVE_TRANSFER_MODE | GUPNP_DLNA_FLAGS_BACKGROUND_TRANSFER_MODE));
	result = protocol_info;
	return result;
}


static void rygel_thumbnail_class_init (RygelThumbnailClass * klass) {
	rygel_thumbnail_parent_class = g_type_class_peek_parent (klass);
	RYGEL_ICON_INFO_CLASS (klass)->finalize = rygel_thumbnail_finalize;
}


static void rygel_thumbnail_instance_init (RygelThumbnail * self) {
}


static void rygel_thumbnail_finalize (RygelIconInfo* obj) {
	RygelThumbnail * self;
	self = RYGEL_THUMBNAIL (obj);
	_g_free0 (self->uri);
	_g_free0 (self->dlna_profile);
	RYGEL_ICON_INFO_CLASS (rygel_thumbnail_parent_class)->finalize (obj);
}


GType rygel_thumbnail_get_type (void) {
	static GType rygel_thumbnail_type_id = 0;
	if (rygel_thumbnail_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelThumbnailClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_thumbnail_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelThumbnail), 0, (GInstanceInitFunc) rygel_thumbnail_instance_init, NULL };
		rygel_thumbnail_type_id = g_type_register_static (RYGEL_TYPE_ICON_INFO, "RygelThumbnail", &g_define_type_info, 0);
	}
	return rygel_thumbnail_type_id;
}



