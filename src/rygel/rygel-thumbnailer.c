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
#include <gio/gio.h>


#define RYGEL_TYPE_THUMBNAILER (rygel_thumbnailer_get_type ())
#define RYGEL_THUMBNAILER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_THUMBNAILER, RygelThumbnailer))
#define RYGEL_THUMBNAILER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_THUMBNAILER, RygelThumbnailerClass))
#define RYGEL_IS_THUMBNAILER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_THUMBNAILER))
#define RYGEL_IS_THUMBNAILER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_THUMBNAILER))
#define RYGEL_THUMBNAILER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_THUMBNAILER, RygelThumbnailerClass))

typedef struct _RygelThumbnailer RygelThumbnailer;
typedef struct _RygelThumbnailerClass RygelThumbnailerClass;
typedef struct _RygelThumbnailerPrivate RygelThumbnailerPrivate;

#define RYGEL_TYPE_ICON_INFO (rygel_icon_info_get_type ())
#define RYGEL_ICON_INFO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_ICON_INFO, RygelIconInfo))
#define RYGEL_ICON_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_ICON_INFO, RygelIconInfoClass))
#define RYGEL_IS_ICON_INFO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_ICON_INFO))
#define RYGEL_IS_ICON_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_ICON_INFO))
#define RYGEL_ICON_INFO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_ICON_INFO, RygelIconInfoClass))

typedef struct _RygelIconInfo RygelIconInfo;
typedef struct _RygelIconInfoClass RygelIconInfoClass;

#define RYGEL_TYPE_THUMBNAIL (rygel_thumbnail_get_type ())
#define RYGEL_THUMBNAIL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_THUMBNAIL, RygelThumbnail))
#define RYGEL_THUMBNAIL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_THUMBNAIL, RygelThumbnailClass))
#define RYGEL_IS_THUMBNAIL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_THUMBNAIL))
#define RYGEL_IS_THUMBNAIL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_THUMBNAIL))
#define RYGEL_THUMBNAIL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_THUMBNAIL, RygelThumbnailClass))

typedef struct _RygelThumbnail RygelThumbnail;
typedef struct _RygelThumbnailClass RygelThumbnailClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _rygel_icon_info_unref0(var) ((var == NULL) ? NULL : (var = (rygel_icon_info_unref (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _RygelIconInfoPrivate RygelIconInfoPrivate;
typedef struct _RygelThumbnailPrivate RygelThumbnailPrivate;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

typedef enum  {
	THUMBNAILER_ERROR_NO_DIR,
	THUMBNAILER_ERROR_NO_THUMBNAIL
} ThumbnailerError;
#define THUMBNAILER_ERROR thumbnailer_error_quark ()
struct _RygelThumbnailer {
	GObject parent_instance;
	RygelThumbnailerPrivate * priv;
	char* directory;
};

struct _RygelThumbnailerClass {
	GObjectClass parent_class;
};

struct _RygelThumbnailerPrivate {
	RygelThumbnail* template;
	char* extension;
};

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


static RygelThumbnailer* rygel_thumbnailer_thumbnailer;
static RygelThumbnailer* rygel_thumbnailer_thumbnailer = NULL;
static gboolean rygel_thumbnailer_first_time;
static gboolean rygel_thumbnailer_first_time = TRUE;
static gpointer rygel_thumbnailer_parent_class = NULL;

GQuark thumbnailer_error_quark (void);
GType rygel_thumbnailer_get_type (void);
gpointer rygel_icon_info_ref (gpointer instance);
void rygel_icon_info_unref (gpointer instance);
GParamSpec* rygel_param_spec_icon_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_icon_info (GValue* value, gpointer v_object);
gpointer rygel_value_get_icon_info (const GValue* value);
GType rygel_icon_info_get_type (void);
GType rygel_thumbnail_get_type (void);
#define RYGEL_THUMBNAILER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_THUMBNAILER, RygelThumbnailerPrivate))
enum  {
	RYGEL_THUMBNAILER_DUMMY_PROPERTY
};
RygelThumbnail* rygel_thumbnail_new (const char* mime_type, const char* dlna_profile);
RygelThumbnail* rygel_thumbnail_construct (GType object_type, const char* mime_type, const char* dlna_profile);
static RygelThumbnailer* rygel_thumbnailer_new (GError** error);
static RygelThumbnailer* rygel_thumbnailer_construct (GType object_type, GError** error);
RygelThumbnailer* rygel_thumbnailer_get_default (void);
RygelThumbnail* rygel_thumbnailer_get_thumbnail (RygelThumbnailer* self, const char* uri, GError** error);
static void rygel_thumbnailer_finalize (GObject* obj);



GQuark thumbnailer_error_quark (void) {
	return g_quark_from_static_string ("thumbnailer_error-quark");
}


static RygelThumbnailer* rygel_thumbnailer_construct (GType object_type, GError** error) {
	GError * _inner_error_;
	RygelThumbnailer * self;
	char* dir;
	GFile* file;
	RygelThumbnail* _tmp0_;
	char* _tmp7_;
	_inner_error_ = NULL;
	self = (RygelThumbnailer*) g_object_new (object_type, NULL);
	dir = g_build_filename (g_get_home_dir (), ".thumbnails", "cropped", NULL);
	file = g_file_new_for_path (dir);
	self->priv->template = (_tmp0_ = rygel_thumbnail_new ("image/jpeg", "JPEG_TN"), _rygel_icon_info_unref0 (self->priv->template), _tmp0_);
	if (!g_file_query_exists (file, NULL)) {
		char* _tmp1_;
		GFile* _tmp2_;
		dir = (_tmp1_ = g_build_filename (g_get_home_dir (), ".thumbnails", "normal", NULL), _g_free0 (dir), _tmp1_);
		file = (_tmp2_ = g_file_new_for_path (dir), _g_object_unref0 (file), _tmp2_);
		if (!g_file_query_exists (file, NULL)) {
			_inner_error_ = g_error_new_literal (THUMBNAILER_ERROR, THUMBNAILER_ERROR_NO_DIR, "Failed to find thumbnails directory");
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == THUMBNAILER_ERROR) {
					g_propagate_error (error, _inner_error_);
					_g_free0 (dir);
					_g_object_unref0 (file);
					return;
				} else {
					_g_free0 (dir);
					_g_object_unref0 (file);
					g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
					g_clear_error (&_inner_error_);
					return NULL;
				}
			}
		} else {
			char* _tmp3_;
			char* _tmp4_;
			char* _tmp5_;
			((RygelIconInfo*) self->priv->template)->mime_type = (_tmp3_ = g_strdup ("image/png"), _g_free0 (((RygelIconInfo*) self->priv->template)->mime_type), _tmp3_);
			self->priv->template->dlna_profile = (_tmp4_ = g_strdup ("PNG_TN"), _g_free0 (self->priv->template->dlna_profile), _tmp4_);
			((RygelIconInfo*) self->priv->template)->width = 128;
			((RygelIconInfo*) self->priv->template)->height = 128;
			((RygelIconInfo*) self->priv->template)->depth = 32;
			self->priv->extension = (_tmp5_ = g_strdup (".png"), _g_free0 (self->priv->extension), _tmp5_);
		}
	} else {
		char* _tmp6_;
		((RygelIconInfo*) self->priv->template)->width = 124;
		((RygelIconInfo*) self->priv->template)->height = 124;
		((RygelIconInfo*) self->priv->template)->depth = 24;
		self->priv->extension = (_tmp6_ = g_strdup (".jpeg"), _g_free0 (self->priv->extension), _tmp6_);
	}
	self->directory = (_tmp7_ = g_strdup (dir), _g_free0 (self->directory), _tmp7_);
	_g_free0 (dir);
	_g_object_unref0 (file);
	return self;
}


static RygelThumbnailer* rygel_thumbnailer_new (GError** error) {
	return rygel_thumbnailer_construct (RYGEL_TYPE_THUMBNAILER, error);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


RygelThumbnailer* rygel_thumbnailer_get_default (void) {
	RygelThumbnailer* result;
	GError * _inner_error_;
	_inner_error_ = NULL;
	if (rygel_thumbnailer_first_time) {
		{
			RygelThumbnailer* _tmp0_;
			RygelThumbnailer* _tmp1_;
			_tmp0_ = rygel_thumbnailer_new (&_inner_error_);
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == THUMBNAILER_ERROR) {
					goto __catch29_thumbnailer_error;
				}
				goto __finally29;
			}
			rygel_thumbnailer_thumbnailer = (_tmp1_ = _tmp0_, _g_object_unref0 (rygel_thumbnailer_thumbnailer), _tmp1_);
		}
		goto __finally29;
		__catch29_thumbnailer_error:
		{
			GError * err;
			err = _inner_error_;
			_inner_error_ = NULL;
			{
				g_warning ("rygel-thumbnailer.vala:81: No thumbnailer available: %s", err->message);
				_g_error_free0 (err);
			}
		}
		__finally29:
		if (_inner_error_ != NULL) {
			g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		rygel_thumbnailer_first_time = FALSE;
	}
	result = _g_object_ref0 (rygel_thumbnailer_thumbnailer);
	return result;
}


RygelThumbnail* rygel_thumbnailer_get_thumbnail (RygelThumbnailer* self, const char* uri, GError** error) {
	RygelThumbnail* result;
	GError * _inner_error_;
	RygelThumbnail* thumbnail;
	char* _tmp0_;
	char* _tmp1_;
	char* path;
	char* full_path;
	GFile* file;
	GFileInfo* info;
	RygelThumbnail* _tmp2_;
	char* _tmp3_;
	char* _tmp4_;
	char* _tmp5_;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (uri != NULL, NULL);
	_inner_error_ = NULL;
	thumbnail = NULL;
	path = (_tmp1_ = g_strconcat (_tmp0_ = g_compute_checksum_for_string (G_CHECKSUM_MD5, uri, -1), self->priv->extension, NULL), _g_free0 (_tmp0_), _tmp1_);
	full_path = g_build_filename (self->directory, path, NULL);
	file = g_file_new_for_path (full_path);
	info = g_file_query_info (file, G_FILE_ATTRIBUTE_ACCESS_CAN_READ "," G_FILE_ATTRIBUTE_STANDARD_SIZE, G_FILE_QUERY_INFO_NONE, NULL, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_rygel_icon_info_unref0 (thumbnail);
		_g_free0 (path);
		_g_free0 (full_path);
		_g_object_unref0 (file);
		return NULL;
	}
	if (!g_file_info_get_attribute_boolean (info, G_FILE_ATTRIBUTE_ACCESS_CAN_READ)) {
		_inner_error_ = g_error_new_literal (THUMBNAILER_ERROR, THUMBNAILER_ERROR_NO_THUMBNAIL, "No thumbnail available");
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_rygel_icon_info_unref0 (thumbnail);
			_g_free0 (path);
			_g_free0 (full_path);
			_g_object_unref0 (file);
			_g_object_unref0 (info);
			return NULL;
		}
	}
	thumbnail = (_tmp2_ = rygel_thumbnail_new ("image/jpeg", "JPEG_TN"), _rygel_icon_info_unref0 (thumbnail), _tmp2_);
	((RygelIconInfo*) thumbnail)->width = ((RygelIconInfo*) self->priv->template)->width;
	((RygelIconInfo*) thumbnail)->height = ((RygelIconInfo*) self->priv->template)->height;
	((RygelIconInfo*) thumbnail)->depth = ((RygelIconInfo*) self->priv->template)->depth;
	((RygelIconInfo*) thumbnail)->path = (_tmp3_ = g_strdup (path), _g_free0 (((RygelIconInfo*) thumbnail)->path), _tmp3_);
	_tmp4_ = g_filename_to_uri (full_path, NULL, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_rygel_icon_info_unref0 (thumbnail);
		_g_free0 (path);
		_g_free0 (full_path);
		_g_object_unref0 (file);
		_g_object_unref0 (info);
		return NULL;
	}
	thumbnail->uri = (_tmp5_ = _tmp4_, _g_free0 (thumbnail->uri), _tmp5_);
	((RygelIconInfo*) thumbnail)->size = (glong) g_file_info_get_attribute_uint64 (info, G_FILE_ATTRIBUTE_STANDARD_SIZE);
	result = thumbnail;
	_g_free0 (path);
	_g_free0 (full_path);
	_g_object_unref0 (file);
	_g_object_unref0 (info);
	return result;
}


static void rygel_thumbnailer_class_init (RygelThumbnailerClass * klass) {
	rygel_thumbnailer_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelThumbnailerPrivate));
	G_OBJECT_CLASS (klass)->finalize = rygel_thumbnailer_finalize;
}


static void rygel_thumbnailer_instance_init (RygelThumbnailer * self) {
	self->priv = RYGEL_THUMBNAILER_GET_PRIVATE (self);
}


static void rygel_thumbnailer_finalize (GObject* obj) {
	RygelThumbnailer * self;
	self = RYGEL_THUMBNAILER (obj);
	_g_free0 (self->directory);
	_rygel_icon_info_unref0 (self->priv->template);
	_g_free0 (self->priv->extension);
	G_OBJECT_CLASS (rygel_thumbnailer_parent_class)->finalize (obj);
}


GType rygel_thumbnailer_get_type (void) {
	static GType rygel_thumbnailer_type_id = 0;
	if (rygel_thumbnailer_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelThumbnailerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_thumbnailer_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelThumbnailer), 0, (GInstanceInitFunc) rygel_thumbnailer_instance_init, NULL };
		rygel_thumbnailer_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelThumbnailer", &g_define_type_info, 0);
	}
	return rygel_thumbnailer_type_id;
}




