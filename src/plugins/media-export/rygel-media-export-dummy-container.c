/* rygel-media-export-dummy-container.c generated by valac, the Vala compiler
 * generated from rygel-media-export-dummy-container.vala, do not modify */

/*
 * Copyright (C) 2009,2010 Jens Georg <mail@jensge.org>.
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
#include <gio/gio.h>
#include <gee.h>
#include <stdlib.h>
#include <string.h>


#define RYGEL_TYPE_NULL_CONTAINER (rygel_null_container_get_type ())
#define RYGEL_NULL_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_NULL_CONTAINER, RygelNullContainer))
#define RYGEL_NULL_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_NULL_CONTAINER, RygelNullContainerClass))
#define RYGEL_IS_NULL_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_NULL_CONTAINER))
#define RYGEL_IS_NULL_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_NULL_CONTAINER))
#define RYGEL_NULL_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_NULL_CONTAINER, RygelNullContainerClass))

typedef struct _RygelNullContainer RygelNullContainer;
typedef struct _RygelNullContainerClass RygelNullContainerClass;
typedef struct _RygelNullContainerPrivate RygelNullContainerPrivate;

#define RYGEL_MEDIA_EXPORT_TYPE_DUMMY_CONTAINER (rygel_media_export_dummy_container_get_type ())
#define RYGEL_MEDIA_EXPORT_DUMMY_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_MEDIA_EXPORT_TYPE_DUMMY_CONTAINER, RygelMediaExportDummyContainer))
#define RYGEL_MEDIA_EXPORT_DUMMY_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_MEDIA_EXPORT_TYPE_DUMMY_CONTAINER, RygelMediaExportDummyContainerClass))
#define RYGEL_MEDIA_EXPORT_IS_DUMMY_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_MEDIA_EXPORT_TYPE_DUMMY_CONTAINER))
#define RYGEL_MEDIA_EXPORT_IS_DUMMY_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_MEDIA_EXPORT_TYPE_DUMMY_CONTAINER))
#define RYGEL_MEDIA_EXPORT_DUMMY_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_MEDIA_EXPORT_TYPE_DUMMY_CONTAINER, RygelMediaExportDummyContainerClass))

typedef struct _RygelMediaExportDummyContainer RygelMediaExportDummyContainer;
typedef struct _RygelMediaExportDummyContainerClass RygelMediaExportDummyContainerClass;
typedef struct _RygelMediaExportDummyContainerPrivate RygelMediaExportDummyContainerPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _RygelNullContainer {
	RygelMediaContainer parent_instance;
	RygelNullContainerPrivate * priv;
};

struct _RygelNullContainerClass {
	RygelMediaContainerClass parent_class;
};

struct _RygelMediaExportDummyContainer {
	RygelNullContainer parent_instance;
	RygelMediaExportDummyContainerPrivate * priv;
	GFile* file;
	GeeArrayList* seen_children;
};

struct _RygelMediaExportDummyContainerClass {
	RygelNullContainerClass parent_class;
};


static gpointer rygel_media_export_dummy_container_parent_class = NULL;

GType rygel_null_container_get_type (void) G_GNUC_CONST;
GType rygel_media_export_dummy_container_get_type (void) G_GNUC_CONST;
enum  {
	RYGEL_MEDIA_EXPORT_DUMMY_CONTAINER_DUMMY_PROPERTY
};
RygelNullContainer* rygel_null_container_new (void);
RygelNullContainer* rygel_null_container_construct (GType object_type);
RygelMediaExportDummyContainer* rygel_media_export_dummy_container_new (GFile* file, RygelMediaContainer* parent);
RygelMediaExportDummyContainer* rygel_media_export_dummy_container_construct (GType object_type, GFile* file, RygelMediaContainer* parent);
void rygel_media_export_dummy_container_seen (RygelMediaExportDummyContainer* self, const char* id);
static void rygel_media_export_dummy_container_finalize (GObject* obj);



static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


#line 26 "rygel-media-export-dummy-container.vala"
RygelMediaExportDummyContainer* rygel_media_export_dummy_container_construct (GType object_type, GFile* file, RygelMediaContainer* parent) {
#line 102 "rygel-media-export-dummy-container.c"
	RygelMediaExportDummyContainer * self;
	char* _tmp0_;
	char* _tmp1_;
	char* id;
	char* _tmp2_;
	char* _tmp3_;
	GFile* _tmp4_;
	char* _tmp5_;
	GeeArrayList* _tmp6_;
#line 26 "rygel-media-export-dummy-container.vala"
	g_return_val_if_fail (file != NULL, NULL);
#line 26 "rygel-media-export-dummy-container.vala"
	g_return_val_if_fail (parent != NULL, NULL);
#line 26 "rygel-media-export-dummy-container.vala"
	self = (RygelMediaExportDummyContainer*) rygel_null_container_construct (object_type);
#line 27 "rygel-media-export-dummy-container.vala"
	id = (_tmp1_ = g_compute_checksum_for_string (G_CHECKSUM_MD5, _tmp0_ = g_file_get_uri (file), -1), _g_free0 (_tmp0_), _tmp1_);
#line 29 "rygel-media-export-dummy-container.vala"
	((RygelMediaObject*) self)->id = (_tmp2_ = g_strdup (id), _g_free0 (((RygelMediaObject*) self)->id), _tmp2_);
#line 30 "rygel-media-export-dummy-container.vala"
	((RygelMediaObject*) self)->parent = parent;
#line 31 "rygel-media-export-dummy-container.vala"
	rygel_media_object_set_title ((RygelMediaObject*) self, _tmp3_ = g_file_get_basename (file));
#line 126 "rygel-media-export-dummy-container.c"
	_g_free0 (_tmp3_);
#line 32 "rygel-media-export-dummy-container.vala"
	((RygelMediaContainer*) self)->child_count = 0;
#line 33 "rygel-media-export-dummy-container.vala"
	rygel_media_object_set_parent_ref ((RygelMediaObject*) self, parent);
#line 34 "rygel-media-export-dummy-container.vala"
	self->file = (_tmp4_ = _g_object_ref0 (file), _g_object_unref0 (self->file), _tmp4_);
#line 35 "rygel-media-export-dummy-container.vala"
	rygel_media_container_set_uri ((RygelMediaContainer*) self, _tmp5_ = g_file_get_uri (file), NULL);
#line 136 "rygel-media-export-dummy-container.c"
	_g_free0 (_tmp5_);
#line 36 "rygel-media-export-dummy-container.vala"
	self->seen_children = (_tmp6_ = gee_array_list_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, g_str_equal), _g_object_unref0 (self->seen_children), _tmp6_);
#line 140 "rygel-media-export-dummy-container.c"
	_g_free0 (id);
	return self;
}


#line 26 "rygel-media-export-dummy-container.vala"
RygelMediaExportDummyContainer* rygel_media_export_dummy_container_new (GFile* file, RygelMediaContainer* parent) {
#line 26 "rygel-media-export-dummy-container.vala"
	return rygel_media_export_dummy_container_construct (RYGEL_MEDIA_EXPORT_TYPE_DUMMY_CONTAINER, file, parent);
#line 150 "rygel-media-export-dummy-container.c"
}


#line 39 "rygel-media-export-dummy-container.vala"
void rygel_media_export_dummy_container_seen (RygelMediaExportDummyContainer* self, const char* id) {
#line 39 "rygel-media-export-dummy-container.vala"
	g_return_if_fail (self != NULL);
#line 39 "rygel-media-export-dummy-container.vala"
	g_return_if_fail (id != NULL);
#line 40 "rygel-media-export-dummy-container.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) self->seen_children, id);
#line 162 "rygel-media-export-dummy-container.c"
}


static void rygel_media_export_dummy_container_class_init (RygelMediaExportDummyContainerClass * klass) {
	rygel_media_export_dummy_container_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = rygel_media_export_dummy_container_finalize;
}


static void rygel_media_export_dummy_container_instance_init (RygelMediaExportDummyContainer * self) {
}


static void rygel_media_export_dummy_container_finalize (GObject* obj) {
	RygelMediaExportDummyContainer * self;
	self = RYGEL_MEDIA_EXPORT_DUMMY_CONTAINER (obj);
	_g_object_unref0 (self->file);
	_g_object_unref0 (self->seen_children);
	G_OBJECT_CLASS (rygel_media_export_dummy_container_parent_class)->finalize (obj);
}


GType rygel_media_export_dummy_container_get_type (void) {
	static volatile gsize rygel_media_export_dummy_container_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_media_export_dummy_container_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediaExportDummyContainerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_media_export_dummy_container_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediaExportDummyContainer), 0, (GInstanceInitFunc) rygel_media_export_dummy_container_instance_init, NULL };
		GType rygel_media_export_dummy_container_type_id;
		rygel_media_export_dummy_container_type_id = g_type_register_static (RYGEL_TYPE_NULL_CONTAINER, "RygelMediaExportDummyContainer", &g_define_type_info, 0);
		g_once_init_leave (&rygel_media_export_dummy_container_type_id__volatile, rygel_media_export_dummy_container_type_id);
	}
	return rygel_media_export_dummy_container_type_id__volatile;
}




