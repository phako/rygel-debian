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
#include <gio/gio.h>
#include <gee.h>
#include <stdlib.h>
#include <string.h>
#include <gst/gst.h>
#include <gobject/gvaluecollector.h>


#define RYGEL_TYPE_NULL_CONTAINER (rygel_null_container_get_type ())
#define RYGEL_NULL_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_NULL_CONTAINER, RygelNullContainer))
#define RYGEL_NULL_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_NULL_CONTAINER, RygelNullContainerClass))
#define RYGEL_IS_NULL_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_NULL_CONTAINER))
#define RYGEL_IS_NULL_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_NULL_CONTAINER))
#define RYGEL_NULL_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_NULL_CONTAINER, RygelNullContainerClass))

typedef struct _RygelNullContainer RygelNullContainer;
typedef struct _RygelNullContainerClass RygelNullContainerClass;
typedef struct _RygelNullContainerPrivate RygelNullContainerPrivate;

#define RYGEL_TYPE_DUMMY_CONTAINER (rygel_dummy_container_get_type ())
#define RYGEL_DUMMY_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_DUMMY_CONTAINER, RygelDummyContainer))
#define RYGEL_DUMMY_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_DUMMY_CONTAINER, RygelDummyContainerClass))
#define RYGEL_IS_DUMMY_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_DUMMY_CONTAINER))
#define RYGEL_IS_DUMMY_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_DUMMY_CONTAINER))
#define RYGEL_DUMMY_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_DUMMY_CONTAINER, RygelDummyContainerClass))

typedef struct _RygelDummyContainer RygelDummyContainer;
typedef struct _RygelDummyContainerClass RygelDummyContainerClass;
typedef struct _RygelDummyContainerPrivate RygelDummyContainerPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

#define RYGEL_TYPE_FILE_QUEUE_ENTRY (rygel_file_queue_entry_get_type ())
#define RYGEL_FILE_QUEUE_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_FILE_QUEUE_ENTRY, RygelFileQueueEntry))
#define RYGEL_FILE_QUEUE_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_FILE_QUEUE_ENTRY, RygelFileQueueEntryClass))
#define RYGEL_IS_FILE_QUEUE_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_FILE_QUEUE_ENTRY))
#define RYGEL_IS_FILE_QUEUE_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_FILE_QUEUE_ENTRY))
#define RYGEL_FILE_QUEUE_ENTRY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_FILE_QUEUE_ENTRY, RygelFileQueueEntryClass))

typedef struct _RygelFileQueueEntry RygelFileQueueEntry;
typedef struct _RygelFileQueueEntryClass RygelFileQueueEntryClass;
typedef struct _RygelFileQueueEntryPrivate RygelFileQueueEntryPrivate;
typedef struct _RygelParamSpecFileQueueEntry RygelParamSpecFileQueueEntry;

#define RYGEL_TYPE_MEDIA_EXPORT_HARVESTER (rygel_media_export_harvester_get_type ())
#define RYGEL_MEDIA_EXPORT_HARVESTER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_EXPORT_HARVESTER, RygelMediaExportHarvester))
#define RYGEL_MEDIA_EXPORT_HARVESTER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_EXPORT_HARVESTER, RygelMediaExportHarvesterClass))
#define RYGEL_IS_MEDIA_EXPORT_HARVESTER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_EXPORT_HARVESTER))
#define RYGEL_IS_MEDIA_EXPORT_HARVESTER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_EXPORT_HARVESTER))
#define RYGEL_MEDIA_EXPORT_HARVESTER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_EXPORT_HARVESTER, RygelMediaExportHarvesterClass))

typedef struct _RygelMediaExportHarvester RygelMediaExportHarvester;
typedef struct _RygelMediaExportHarvesterClass RygelMediaExportHarvesterClass;
typedef struct _RygelMediaExportHarvesterPrivate RygelMediaExportHarvesterPrivate;

#define RYGEL_TYPE_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR (rygel_media_export_recursive_file_monitor_get_type ())
#define RYGEL_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR, RygelMediaExportRecursiveFileMonitor))
#define RYGEL_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR, RygelMediaExportRecursiveFileMonitorClass))
#define RYGEL_IS_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR))
#define RYGEL_IS_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR))
#define RYGEL_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR, RygelMediaExportRecursiveFileMonitorClass))

typedef struct _RygelMediaExportRecursiveFileMonitor RygelMediaExportRecursiveFileMonitor;
typedef struct _RygelMediaExportRecursiveFileMonitorClass RygelMediaExportRecursiveFileMonitorClass;
#define _g_queue_free0(var) ((var == NULL) ? NULL : (var = (g_queue_free (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define __g_list_free_g_object_unref0(var) ((var == NULL) ? NULL : (var = (_g_list_free_g_object_unref (var), NULL)))
#define _rygel_file_queue_entry_unref0(var) ((var == NULL) ? NULL : (var = (rygel_file_queue_entry_unref (var), NULL)))

struct _RygelNullContainer {
	RygelMediaContainer parent_instance;
	RygelNullContainerPrivate * priv;
};

struct _RygelNullContainerClass {
	RygelMediaContainerClass parent_class;
};

struct _RygelDummyContainer {
	RygelNullContainer parent_instance;
	RygelDummyContainerPrivate * priv;
	GFile* file;
	GeeArrayList* seen_children;
};

struct _RygelDummyContainerClass {
	RygelNullContainerClass parent_class;
};

struct _RygelFileQueueEntry {
	GTypeInstance parent_instance;
	volatile int ref_count;
	RygelFileQueueEntryPrivate * priv;
	GFile* file;
	gboolean update;
};

struct _RygelFileQueueEntryClass {
	GTypeClass parent_class;
	void (*finalize) (RygelFileQueueEntry *self);
};

struct _RygelParamSpecFileQueueEntry {
	GParamSpec parent_instance;
};

struct _RygelMediaExportHarvester {
	GObject parent_instance;
	RygelMediaExportHarvesterPrivate * priv;
};

struct _RygelMediaExportHarvesterClass {
	GObjectClass parent_class;
};

struct _RygelMediaExportHarvesterPrivate {
	RygelMetadataExtractor* extractor;
	RygelMediaDB* media_db;
	GQueue* containers;
	GQueue* files;
	GFile* origin;
	RygelMediaContainer* parent;
	RygelMediaExportRecursiveFileMonitor* monitor;
};


static gpointer rygel_dummy_container_parent_class = NULL;
static gpointer rygel_file_queue_entry_parent_class = NULL;
static gpointer rygel_media_export_harvester_parent_class = NULL;

GType rygel_null_container_get_type (void);
GType rygel_dummy_container_get_type (void);
enum  {
	RYGEL_DUMMY_CONTAINER_DUMMY_PROPERTY
};
RygelNullContainer* rygel_null_container_new (void);
RygelNullContainer* rygel_null_container_construct (GType object_type);
RygelDummyContainer* rygel_dummy_container_new (GFile* file, RygelMediaContainer* parent);
RygelDummyContainer* rygel_dummy_container_construct (GType object_type, GFile* file, RygelMediaContainer* parent);
void rygel_dummy_container_seen (RygelDummyContainer* self, const char* id);
static void rygel_dummy_container_finalize (GObject* obj);
gpointer rygel_file_queue_entry_ref (gpointer instance);
void rygel_file_queue_entry_unref (gpointer instance);
GParamSpec* rygel_param_spec_file_queue_entry (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_file_queue_entry (GValue* value, gpointer v_object);
gpointer rygel_value_get_file_queue_entry (const GValue* value);
GType rygel_file_queue_entry_get_type (void);
enum  {
	RYGEL_FILE_QUEUE_ENTRY_DUMMY_PROPERTY
};
RygelFileQueueEntry* rygel_file_queue_entry_new (GFile* file, gboolean update);
RygelFileQueueEntry* rygel_file_queue_entry_construct (GType object_type, GFile* file, gboolean update);
static void rygel_file_queue_entry_finalize (RygelFileQueueEntry* obj);
GType rygel_media_export_harvester_get_type (void);
GType rygel_media_export_recursive_file_monitor_get_type (void);
#define RYGEL_MEDIA_EXPORT_HARVESTER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_MEDIA_EXPORT_HARVESTER, RygelMediaExportHarvesterPrivate))
enum  {
	RYGEL_MEDIA_EXPORT_HARVESTER_DUMMY_PROPERTY
};
static void rygel_media_export_harvester_on_extracted_cb (RygelMediaExportHarvester* self, GFile* file, GstTagList* tag_list);
static void _rygel_media_export_harvester_on_extracted_cb_rygel_metadata_extractor_extraction_done (RygelMetadataExtractor* _sender, GFile* file, GstTagList* tag_list, gpointer self);
static void rygel_media_export_harvester_on_extractor_error_cb (RygelMediaExportHarvester* self, GFile* file, GError* _error_);
static void _rygel_media_export_harvester_on_extractor_error_cb_rygel_metadata_extractor_error (RygelMetadataExtractor* _sender, GFile* file, GError* err, gpointer self);
RygelMediaExportHarvester* rygel_media_export_harvester_new (RygelMediaContainer* parent, RygelMediaDB* media_db, RygelMetadataExtractor* extractor, RygelMediaExportRecursiveFileMonitor* monitor);
RygelMediaExportHarvester* rygel_media_export_harvester_construct (GType object_type, RygelMediaContainer* parent, RygelMediaDB* media_db, RygelMetadataExtractor* extractor, RygelMediaExportRecursiveFileMonitor* monitor);
static void rygel_media_export_harvester_do_update (RygelMediaExportHarvester* self);
static gboolean rygel_media_export_harvester_on_idle (RygelMediaExportHarvester* self);
static gboolean _rygel_media_export_harvester_on_idle_gsource_func (gpointer self);
static void rygel_media_export_harvester_on_close_async (RygelMediaExportHarvester* self, GObject* obj, GAsyncResult* res);
static gboolean rygel_media_export_harvester_push_if_changed_or_unknown (RygelMediaExportHarvester* self, GFile* file, GFileInfo* info, char** id);
void rygel_media_export_recursive_file_monitor_monitor (RygelMediaExportRecursiveFileMonitor* self, GFile* file);
static void _g_list_free_g_object_unref (GList* self);
static void rygel_media_export_harvester_on_next_files_ready (RygelMediaExportHarvester* self, GObject* obj, GAsyncResult* res);
static void _rygel_media_export_harvester_on_next_files_ready_gasync_ready_callback (GObject* source_object, GAsyncResult* res, gpointer self);
static void _rygel_media_export_harvester_on_close_async_gasync_ready_callback (GObject* source_object, GAsyncResult* res, gpointer self);
static void rygel_media_export_harvester_on_enumerate_ready (RygelMediaExportHarvester* self, GObject* obj, GAsyncResult* res);
static void _rygel_media_export_harvester_on_enumerate_ready_gasync_ready_callback (GObject* source_object, GAsyncResult* res, gpointer self);
static void rygel_media_export_harvester_on_initial_info_ready (RygelMediaExportHarvester* self, GObject* source, GAsyncResult* _result_);
static void _rygel_media_export_harvester_on_initial_info_ready_gasync_ready_callback (GObject* source_object, GAsyncResult* res, gpointer self);
void rygel_media_export_harvester_harvest (RygelMediaExportHarvester* self, GFile* file);
RygelMediaItem* rygel_media_export_item_create_from_taglist (RygelMediaContainer* parent, GFile* file, GstTagList* tag_list);
static void rygel_media_export_harvester_finalize (GObject* obj);



static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


RygelDummyContainer* rygel_dummy_container_construct (GType object_type, GFile* file, RygelMediaContainer* parent) {
	RygelDummyContainer * self;
	char* _tmp0_;
	char* _tmp1_;
	char* id;
	char* _tmp2_;
	char* _tmp3_;
	RygelMediaContainer* _tmp4_;
	GFile* _tmp5_;
	char* _tmp6_;
	GeeArrayList* _tmp7_;
	g_return_val_if_fail (file != NULL, NULL);
	g_return_val_if_fail (parent != NULL, NULL);
	self = (RygelDummyContainer*) rygel_null_container_construct (object_type);
	id = (_tmp1_ = g_compute_checksum_for_string (G_CHECKSUM_MD5, _tmp0_ = g_file_get_uri (file), -1), _g_free0 (_tmp0_), _tmp1_);
	((RygelMediaObject*) self)->id = (_tmp2_ = g_strdup (id), _g_free0 (((RygelMediaObject*) self)->id), _tmp2_);
	((RygelMediaObject*) self)->parent = parent;
	((RygelMediaObject*) self)->title = (_tmp3_ = g_file_get_basename (file), _g_free0 (((RygelMediaObject*) self)->title), _tmp3_);
	((RygelMediaContainer*) self)->child_count = (guint) 0;
	((RygelMediaObject*) self)->parent_ref = (_tmp4_ = _g_object_ref0 (parent), _g_object_unref0 (((RygelMediaObject*) self)->parent_ref), _tmp4_);
	self->file = (_tmp5_ = _g_object_ref0 (file), _g_object_unref0 (self->file), _tmp5_);
	gee_abstract_collection_add ((GeeAbstractCollection*) ((RygelMediaObject*) self)->uris, _tmp6_ = g_file_get_uri (file));
	_g_free0 (_tmp6_);
	self->seen_children = (_tmp7_ = gee_array_list_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, g_str_equal), _g_object_unref0 (self->seen_children), _tmp7_);
	_g_free0 (id);
	return self;
}


RygelDummyContainer* rygel_dummy_container_new (GFile* file, RygelMediaContainer* parent) {
	return rygel_dummy_container_construct (RYGEL_TYPE_DUMMY_CONTAINER, file, parent);
}


void rygel_dummy_container_seen (RygelDummyContainer* self, const char* id) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (id != NULL);
	gee_abstract_collection_add ((GeeAbstractCollection*) self->seen_children, id);
}


static void rygel_dummy_container_class_init (RygelDummyContainerClass * klass) {
	rygel_dummy_container_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = rygel_dummy_container_finalize;
}


static void rygel_dummy_container_instance_init (RygelDummyContainer * self) {
}


static void rygel_dummy_container_finalize (GObject* obj) {
	RygelDummyContainer * self;
	self = RYGEL_DUMMY_CONTAINER (obj);
	_g_object_unref0 (self->file);
	_g_object_unref0 (self->seen_children);
	G_OBJECT_CLASS (rygel_dummy_container_parent_class)->finalize (obj);
}


GType rygel_dummy_container_get_type (void) {
	static GType rygel_dummy_container_type_id = 0;
	if (rygel_dummy_container_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelDummyContainerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_dummy_container_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelDummyContainer), 0, (GInstanceInitFunc) rygel_dummy_container_instance_init, NULL };
		rygel_dummy_container_type_id = g_type_register_static (RYGEL_TYPE_NULL_CONTAINER, "RygelDummyContainer", &g_define_type_info, 0);
	}
	return rygel_dummy_container_type_id;
}


RygelFileQueueEntry* rygel_file_queue_entry_construct (GType object_type, GFile* file, gboolean update) {
	RygelFileQueueEntry* self;
	GFile* _tmp0_;
	g_return_val_if_fail (file != NULL, NULL);
	self = (RygelFileQueueEntry*) g_type_create_instance (object_type);
	self->file = (_tmp0_ = _g_object_ref0 (file), _g_object_unref0 (self->file), _tmp0_);
	self->update = update;
	return self;
}


RygelFileQueueEntry* rygel_file_queue_entry_new (GFile* file, gboolean update) {
	return rygel_file_queue_entry_construct (RYGEL_TYPE_FILE_QUEUE_ENTRY, file, update);
}


static void rygel_value_file_queue_entry_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void rygel_value_file_queue_entry_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		rygel_file_queue_entry_unref (value->data[0].v_pointer);
	}
}


static void rygel_value_file_queue_entry_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = rygel_file_queue_entry_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer rygel_value_file_queue_entry_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* rygel_value_file_queue_entry_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		RygelFileQueueEntry* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = rygel_file_queue_entry_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* rygel_value_file_queue_entry_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	RygelFileQueueEntry** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags && G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = rygel_file_queue_entry_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* rygel_param_spec_file_queue_entry (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	RygelParamSpecFileQueueEntry* spec;
	g_return_val_if_fail (g_type_is_a (object_type, RYGEL_TYPE_FILE_QUEUE_ENTRY), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer rygel_value_get_file_queue_entry (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_TYPE_FILE_QUEUE_ENTRY), NULL);
	return value->data[0].v_pointer;
}


void rygel_value_set_file_queue_entry (GValue* value, gpointer v_object) {
	RygelFileQueueEntry* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_TYPE_FILE_QUEUE_ENTRY));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, RYGEL_TYPE_FILE_QUEUE_ENTRY));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		rygel_file_queue_entry_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		rygel_file_queue_entry_unref (old);
	}
}


static void rygel_file_queue_entry_class_init (RygelFileQueueEntryClass * klass) {
	rygel_file_queue_entry_parent_class = g_type_class_peek_parent (klass);
	RYGEL_FILE_QUEUE_ENTRY_CLASS (klass)->finalize = rygel_file_queue_entry_finalize;
}


static void rygel_file_queue_entry_instance_init (RygelFileQueueEntry * self) {
	self->ref_count = 1;
}


static void rygel_file_queue_entry_finalize (RygelFileQueueEntry* obj) {
	RygelFileQueueEntry * self;
	self = RYGEL_FILE_QUEUE_ENTRY (obj);
	_g_object_unref0 (self->file);
}


GType rygel_file_queue_entry_get_type (void) {
	static GType rygel_file_queue_entry_type_id = 0;
	if (rygel_file_queue_entry_type_id == 0) {
		static const GTypeValueTable g_define_type_value_table = { rygel_value_file_queue_entry_init, rygel_value_file_queue_entry_free_value, rygel_value_file_queue_entry_copy_value, rygel_value_file_queue_entry_peek_pointer, "p", rygel_value_file_queue_entry_collect_value, "p", rygel_value_file_queue_entry_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (RygelFileQueueEntryClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_file_queue_entry_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelFileQueueEntry), 0, (GInstanceInitFunc) rygel_file_queue_entry_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		rygel_file_queue_entry_type_id = g_type_register_fundamental (g_type_fundamental_next (), "RygelFileQueueEntry", &g_define_type_info, &g_define_type_fundamental_info, 0);
	}
	return rygel_file_queue_entry_type_id;
}


gpointer rygel_file_queue_entry_ref (gpointer instance) {
	RygelFileQueueEntry* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void rygel_file_queue_entry_unref (gpointer instance) {
	RygelFileQueueEntry* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		RYGEL_FILE_QUEUE_ENTRY_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}


static void _rygel_media_export_harvester_on_extracted_cb_rygel_metadata_extractor_extraction_done (RygelMetadataExtractor* _sender, GFile* file, GstTagList* tag_list, gpointer self) {
	rygel_media_export_harvester_on_extracted_cb (self, file, tag_list);
}


static void _rygel_media_export_harvester_on_extractor_error_cb_rygel_metadata_extractor_error (RygelMetadataExtractor* _sender, GFile* file, GError* err, gpointer self) {
	rygel_media_export_harvester_on_extractor_error_cb (self, file, err);
}


RygelMediaExportHarvester* rygel_media_export_harvester_construct (GType object_type, RygelMediaContainer* parent, RygelMediaDB* media_db, RygelMetadataExtractor* extractor, RygelMediaExportRecursiveFileMonitor* monitor) {
	RygelMediaExportHarvester * self;
	RygelMediaContainer* _tmp0_;
	RygelMetadataExtractor* _tmp1_;
	RygelMediaDB* _tmp2_;
	GQueue* _tmp3_;
	GQueue* _tmp4_;
	GFile* _tmp5_;
	RygelMediaExportRecursiveFileMonitor* _tmp6_;
	g_return_val_if_fail (parent != NULL, NULL);
	g_return_val_if_fail (media_db != NULL, NULL);
	g_return_val_if_fail (extractor != NULL, NULL);
	g_return_val_if_fail (monitor != NULL, NULL);
	self = (RygelMediaExportHarvester*) g_object_new (object_type, NULL);
	self->priv->parent = (_tmp0_ = _g_object_ref0 (parent), _g_object_unref0 (self->priv->parent), _tmp0_);
	self->priv->extractor = (_tmp1_ = _g_object_ref0 (extractor), _g_object_unref0 (self->priv->extractor), _tmp1_);
	self->priv->media_db = (_tmp2_ = _g_object_ref0 (media_db), _g_object_unref0 (self->priv->media_db), _tmp2_);
	g_signal_connect_object (self->priv->extractor, "extraction-done", (GCallback) _rygel_media_export_harvester_on_extracted_cb_rygel_metadata_extractor_extraction_done, self, 0);
	g_signal_connect_object (self->priv->extractor, "error", (GCallback) _rygel_media_export_harvester_on_extractor_error_cb_rygel_metadata_extractor_error, self, 0);
	self->priv->files = (_tmp3_ = g_queue_new (), _g_queue_free0 (self->priv->files), _tmp3_);
	self->priv->containers = (_tmp4_ = g_queue_new (), _g_queue_free0 (self->priv->containers), _tmp4_);
	self->priv->origin = (_tmp5_ = NULL, _g_object_unref0 (self->priv->origin), _tmp5_);
	self->priv->monitor = (_tmp6_ = _g_object_ref0 (monitor), _g_object_unref0 (self->priv->monitor), _tmp6_);
	return self;
}


RygelMediaExportHarvester* rygel_media_export_harvester_new (RygelMediaContainer* parent, RygelMediaDB* media_db, RygelMetadataExtractor* extractor, RygelMediaExportRecursiveFileMonitor* monitor) {
	return rygel_media_export_harvester_construct (RYGEL_TYPE_MEDIA_EXPORT_HARVESTER, parent, media_db, extractor, monitor);
}


static gboolean _rygel_media_export_harvester_on_idle_gsource_func (gpointer self) {
	return rygel_media_export_harvester_on_idle (self);
}


static void rygel_media_export_harvester_on_close_async (RygelMediaExportHarvester* self, GObject* obj, GAsyncResult* res) {
	GError * _inner_error_;
	GFileEnumerator* enumerator;
	RygelDummyContainer* container;
	g_return_if_fail (self != NULL);
	g_return_if_fail (res != NULL);
	_inner_error_ = NULL;
	enumerator = _g_object_ref0 (G_FILE_ENUMERATOR (obj));
	{
		g_file_enumerator_close_finish (enumerator, res, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch8_g_error;
			goto __finally8;
		}
	}
	goto __finally8;
	__catch8_g_error:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
			_g_error_free0 (_error_);
		}
	}
	__finally8:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (enumerator);
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return;
	}
	container = _g_object_ref0 (RYGEL_DUMMY_CONTAINER ((RygelMediaContainer*) g_queue_peek_head (self->priv->containers)));
	{
		GeeArrayList* children;
		children = rygel_media_db_get_child_ids (self->priv->media_db, ((RygelMediaObject*) container)->id, &_inner_error_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
				goto __catch9_rygel_media_db_error;
			}
			goto __finally9;
		}
		{
			GeeIterator* _seen_id_it;
			_seen_id_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) container->seen_children);
			while (TRUE) {
				char* seen_id;
				if (!gee_iterator_next (_seen_id_it)) {
					break;
				}
				seen_id = (char*) gee_iterator_get (_seen_id_it);
				gee_abstract_collection_remove ((GeeAbstractCollection*) children, seen_id);
				_g_free0 (seen_id);
			}
			_g_object_unref0 (_seen_id_it);
		}
		{
			GeeIterator* _child_it;
			_child_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) children);
			while (TRUE) {
				char* child;
				if (!gee_iterator_next (_child_it)) {
					break;
				}
				child = (char*) gee_iterator_get (_child_it);
				rygel_media_db_remove_by_id (self->priv->media_db, child, &_inner_error_);
				if (_inner_error_ != NULL) {
					_g_free0 (child);
					_g_object_unref0 (_child_it);
					_g_object_unref0 (children);
					if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
						goto __catch9_rygel_media_db_error;
					}
					goto __finally9;
				}
				_g_free0 (child);
			}
			_g_object_unref0 (_child_it);
		}
		rygel_media_export_harvester_do_update (self);
		_g_object_unref0 (children);
	}
	goto __finally9;
	__catch9_rygel_media_db_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			g_warning ("rygel-media-export-harvester.vala:103: Failed to get children of container %s: %s", ((RygelMediaObject*) container)->id, err->message);
			_g_error_free0 (err);
		}
	}
	__finally9:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (enumerator);
		_g_object_unref0 (container);
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return;
	}
	g_idle_add_full (G_PRIORITY_DEFAULT_IDLE, _rygel_media_export_harvester_on_idle_gsource_func, g_object_ref (self), g_object_unref);
	_g_object_unref0 (enumerator);
	_g_object_unref0 (container);
}


static gboolean rygel_media_export_harvester_push_if_changed_or_unknown (RygelMediaExportHarvester* self, GFile* file, GFileInfo* info, char** id) {
	gboolean result;
	GError * _inner_error_;
	char* _tmp1_;
	char* _tmp0_;
	gint64 timestamp;
	gboolean _tmp2_;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (file != NULL, FALSE);
	g_return_val_if_fail (info != NULL, FALSE);
	if (id != NULL) {
		*id = NULL;
	}
	_inner_error_ = NULL;
	*id = (_tmp1_ = g_compute_checksum_for_string (G_CHECKSUM_MD5, _tmp0_ = g_file_get_uri (file), -1), _g_free0 (*id), _tmp1_);
	_g_free0 (_tmp0_);
	timestamp = 0LL;
	_tmp2_ = rygel_media_db_exists (self->priv->media_db, *id, &timestamp, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return FALSE;
	}
	if (_tmp2_) {
		gint64 mtime;
		mtime = (gint64) g_file_info_get_attribute_uint64 (info, G_FILE_ATTRIBUTE_TIME_MODIFIED);
		if (mtime > timestamp) {
			g_queue_push_tail (self->priv->files, rygel_file_queue_entry_new (file, TRUE));
			result = TRUE;
			return result;
		}
	} else {
		g_queue_push_tail (self->priv->files, rygel_file_queue_entry_new (file, FALSE));
		result = TRUE;
		return result;
	}
	result = FALSE;
	return result;
}


static void _g_list_free_g_object_unref (GList* self) {
	g_list_foreach (self, (GFunc) g_object_unref, NULL);
	g_list_free (self);
}


static void _rygel_media_export_harvester_on_next_files_ready_gasync_ready_callback (GObject* source_object, GAsyncResult* res, gpointer self) {
	rygel_media_export_harvester_on_next_files_ready (self, source_object, res);
}


static void _rygel_media_export_harvester_on_close_async_gasync_ready_callback (GObject* source_object, GAsyncResult* res, gpointer self) {
	rygel_media_export_harvester_on_close_async (self, source_object, res);
}


static void rygel_media_export_harvester_on_next_files_ready (RygelMediaExportHarvester* self, GObject* obj, GAsyncResult* res) {
	GError * _inner_error_;
	GFileEnumerator* enumerator;
	g_return_if_fail (self != NULL);
	g_return_if_fail (res != NULL);
	_inner_error_ = NULL;
	enumerator = _g_object_ref0 (G_FILE_ENUMERATOR (obj));
	{
		GList* list;
		list = g_file_enumerator_next_files_finish (enumerator, res, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch10_g_error;
			goto __finally10;
		}
		if (list != NULL) {
			{
				GList* info_collection;
				GList* info_it;
				info_collection = list;
				for (info_it = info_collection; info_it != NULL; info_it = info_it->next) {
					GFileInfo* info;
					info = _g_object_ref0 ((GFileInfo*) info_it->data);
					{
						RygelDummyContainer* parent_container;
						GFile* dir;
						GFile* file;
						if (g_utf8_get_char (g_utf8_offset_to_pointer (g_file_info_get_name (info), 0)) == '.') {
							_g_object_unref0 (info);
							continue;
						}
						parent_container = _g_object_ref0 (RYGEL_DUMMY_CONTAINER ((RygelMediaContainer*) g_queue_peek_head (self->priv->containers)));
						dir = _g_object_ref0 (parent_container->file);
						file = g_file_get_child (dir, g_file_info_get_name (info));
						if (g_file_info_get_file_type (info) == G_FILE_TYPE_DIRECTORY) {
							RygelDummyContainer* container;
							gint64 timestamp;
							gboolean _tmp0_;
							rygel_media_export_recursive_file_monitor_monitor (self->priv->monitor, file);
							container = rygel_dummy_container_new (file, (RygelMediaContainer*) parent_container);
							g_queue_push_tail (self->priv->containers, _g_object_ref0 ((RygelMediaContainer*) container));
							rygel_dummy_container_seen (parent_container, ((RygelMediaObject*) container)->id);
							timestamp = 0LL;
							_tmp0_ = rygel_media_db_exists (self->priv->media_db, ((RygelMediaObject*) container)->id, &timestamp, &_inner_error_);
							if (_inner_error_ != NULL) {
								_g_object_unref0 (container);
								_g_object_unref0 (info);
								_g_object_unref0 (parent_container);
								_g_object_unref0 (dir);
								_g_object_unref0 (file);
								__g_list_free_g_object_unref0 (list);
								goto __catch10_g_error;
								goto __finally10;
							}
							if (!_tmp0_) {
								rygel_media_db_save_object (self->priv->media_db, (RygelMediaObject*) container, &_inner_error_);
								if (_inner_error_ != NULL) {
									_g_object_unref0 (container);
									_g_object_unref0 (info);
									_g_object_unref0 (parent_container);
									_g_object_unref0 (dir);
									_g_object_unref0 (file);
									__g_list_free_g_object_unref0 (list);
									goto __catch10_g_error;
									goto __finally10;
								}
							}
							_g_object_unref0 (container);
						} else {
							char* id;
							char* _tmp3_;
							gboolean _tmp2_;
							char* _tmp1_;
							id = NULL;
							_tmp1_ = NULL;
							_tmp2_ = rygel_media_export_harvester_push_if_changed_or_unknown (self, file, info, &_tmp1_);
							id = (_tmp3_ = _tmp1_, _g_free0 (id), _tmp3_);
							_tmp2_;
							rygel_dummy_container_seen (parent_container, id);
							_g_free0 (id);
						}
						_g_object_unref0 (info);
						_g_object_unref0 (parent_container);
						_g_object_unref0 (dir);
						_g_object_unref0 (file);
					}
				}
			}
			g_file_enumerator_next_files_async (enumerator, 10, G_PRIORITY_DEFAULT, NULL, _rygel_media_export_harvester_on_next_files_ready_gasync_ready_callback, self);
		} else {
			g_file_enumerator_close_async (enumerator, G_PRIORITY_DEFAULT, NULL, _rygel_media_export_harvester_on_close_async_gasync_ready_callback, self);
		}
		__g_list_free_g_object_unref0 (list);
	}
	goto __finally10;
	__catch10_g_error:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
			_g_error_free0 (_error_);
		}
	}
	__finally10:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (enumerator);
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return;
	}
	_g_object_unref0 (enumerator);
}


static void rygel_media_export_harvester_on_enumerate_ready (RygelMediaExportHarvester* self, GObject* obj, GAsyncResult* res) {
	GError * _inner_error_;
	GFile* file;
	g_return_if_fail (self != NULL);
	g_return_if_fail (res != NULL);
	_inner_error_ = NULL;
	file = _g_object_ref0 (G_FILE (obj));
	{
		GFileEnumerator* enumerator;
		enumerator = g_file_enumerate_children_finish (file, res, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch11_g_error;
			goto __finally11;
		}
		g_file_enumerator_next_files_async (enumerator, 10, G_PRIORITY_DEFAULT, NULL, _rygel_media_export_harvester_on_next_files_ready_gasync_ready_callback, self);
		_g_object_unref0 (enumerator);
	}
	goto __finally11;
	__catch11_g_error:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
			_g_error_free0 (_error_);
		}
	}
	__finally11:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (file);
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return;
	}
	_g_object_unref0 (file);
}


static void _rygel_media_export_harvester_on_enumerate_ready_gasync_ready_callback (GObject* source_object, GAsyncResult* res, gpointer self) {
	rygel_media_export_harvester_on_enumerate_ready (self, source_object, res);
}


static gboolean rygel_media_export_harvester_on_idle (RygelMediaExportHarvester* self) {
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	if (g_queue_get_length (self->priv->files) > 0) {
		GFile* candidate;
		candidate = _g_object_ref0 (((RygelFileQueueEntry*) g_queue_peek_head (self->priv->files))->file);
		rygel_metadata_extractor_extract (self->priv->extractor, candidate);
		_g_object_unref0 (candidate);
	} else {
		if (g_queue_get_length (self->priv->containers) > 0) {
			GFile* directory;
			directory = _g_object_ref0 (RYGEL_DUMMY_CONTAINER ((RygelMediaContainer*) g_queue_peek_head (self->priv->containers))->file);
			g_file_enumerate_children_async (directory, G_FILE_ATTRIBUTE_STANDARD_TYPE "," G_FILE_ATTRIBUTE_STANDARD_NAME "," G_FILE_ATTRIBUTE_TIME_MODIFIED, G_FILE_QUERY_INFO_NONE, G_PRIORITY_DEFAULT, NULL, _rygel_media_export_harvester_on_enumerate_ready_gasync_ready_callback, self);
			_g_object_unref0 (directory);
		} else {
			g_signal_emit_by_name (self, "harvested", self->priv->origin);
		}
	}
	result = FALSE;
	return result;
}


static void rygel_media_export_harvester_on_initial_info_ready (RygelMediaExportHarvester* self, GObject* source, GAsyncResult* _result_) {
	GError * _inner_error_;
	GFile* file;
	g_return_if_fail (self != NULL);
	g_return_if_fail (_result_ != NULL);
	_inner_error_ = NULL;
	file = _g_object_ref0 (G_FILE (source));
	{
		GFileInfo* info;
		info = g_file_query_info_finish (file, _result_, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch12_g_error;
			goto __finally12;
		}
		if (g_file_info_get_file_type (info) == G_FILE_TYPE_DIRECTORY) {
			GFile* _tmp0_;
			RygelDummyContainer* container;
			gint64 timestamp;
			gboolean _tmp1_;
			self->priv->origin = (_tmp0_ = _g_object_ref0 (file), _g_object_unref0 (self->priv->origin), _tmp0_);
			rygel_media_export_recursive_file_monitor_monitor (self->priv->monitor, file);
			container = rygel_dummy_container_new (file, self->priv->parent);
			g_queue_push_tail (self->priv->containers, _g_object_ref0 ((RygelMediaContainer*) container));
			timestamp = 0LL;
			_tmp1_ = rygel_media_db_exists (self->priv->media_db, ((RygelMediaObject*) container)->id, &timestamp, &_inner_error_);
			if (_inner_error_ != NULL) {
				_g_object_unref0 (container);
				_g_object_unref0 (info);
				goto __catch12_g_error;
				goto __finally12;
			}
			if (!_tmp1_) {
				rygel_media_db_save_object (self->priv->media_db, (RygelMediaObject*) container, &_inner_error_);
				if (_inner_error_ != NULL) {
					_g_object_unref0 (container);
					_g_object_unref0 (info);
					goto __catch12_g_error;
					goto __finally12;
				}
			}
			g_idle_add_full (G_PRIORITY_DEFAULT_IDLE, _rygel_media_export_harvester_on_idle_gsource_func, g_object_ref (self), g_object_unref);
			_g_object_unref0 (container);
		} else {
			char* id;
			char* _tmp4_;
			gboolean _tmp3_;
			char* _tmp2_;
			id = NULL;
			_tmp2_ = NULL;
			if ((_tmp3_ = rygel_media_export_harvester_push_if_changed_or_unknown (self, file, info, &_tmp2_), id = (_tmp4_ = _tmp2_, _g_free0 (id), _tmp4_), _tmp3_)) {
				GFile* _tmp5_;
				g_idle_add_full (G_PRIORITY_DEFAULT_IDLE, _rygel_media_export_harvester_on_idle_gsource_func, g_object_ref (self), g_object_unref);
				self->priv->origin = (_tmp5_ = _g_object_ref0 (file), _g_object_unref0 (self->priv->origin), _tmp5_);
				g_queue_push_tail (self->priv->containers, _g_object_ref0 (self->priv->parent));
			}
			_g_free0 (id);
		}
		_g_object_unref0 (info);
	}
	goto __finally12;
	__catch12_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp6_;
			g_warning ("rygel-media-export-harvester.vala:240: Failed to harvest file %s: %s", _tmp6_ = g_file_get_uri (file), err->message);
			_g_free0 (_tmp6_);
			g_signal_emit_by_name (self, "harvested", file);
			_g_error_free0 (err);
		}
	}
	__finally12:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (file);
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return;
	}
	_g_object_unref0 (file);
}


static void _rygel_media_export_harvester_on_initial_info_ready_gasync_ready_callback (GObject* source_object, GAsyncResult* res, gpointer self) {
	rygel_media_export_harvester_on_initial_info_ready (self, source_object, res);
}


void rygel_media_export_harvester_harvest (RygelMediaExportHarvester* self, GFile* file) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (file != NULL);
	g_file_query_info_async (file, G_FILE_ATTRIBUTE_STANDARD_NAME "," G_FILE_ATTRIBUTE_STANDARD_TYPE "," G_FILE_ATTRIBUTE_TIME_MODIFIED, G_FILE_QUERY_INFO_NONE, G_PRIORITY_DEFAULT, NULL, _rygel_media_export_harvester_on_initial_info_ready_gasync_ready_callback, self);
}


static gpointer _rygel_file_queue_entry_ref0 (gpointer self) {
	return self ? rygel_file_queue_entry_ref (self) : NULL;
}


static void rygel_media_export_harvester_on_extracted_cb (RygelMediaExportHarvester* self, GFile* file, GstTagList* tag_list) {
	GError * _inner_error_;
	RygelFileQueueEntry* entry;
	g_return_if_fail (self != NULL);
	g_return_if_fail (file != NULL);
	g_return_if_fail (tag_list != NULL);
	_inner_error_ = NULL;
	entry = _rygel_file_queue_entry_ref0 ((RygelFileQueueEntry*) g_queue_peek_head (self->priv->files));
	if (entry == NULL) {
		_rygel_file_queue_entry_unref0 (entry);
		return;
	}
	if (file == entry->file) {
		RygelMediaItem* item;
		RygelFileQueueEntry* _tmp1_;
		item = rygel_media_export_item_create_from_taglist ((RygelMediaContainer*) g_queue_peek_head (self->priv->containers), file, tag_list);
		if (item != NULL) {
			RygelMediaContainer* _tmp0_;
			((RygelMediaObject*) item)->parent_ref = (_tmp0_ = _g_object_ref0 ((RygelMediaContainer*) g_queue_peek_head (self->priv->containers)), _g_object_unref0 (((RygelMediaObject*) item)->parent_ref), _tmp0_);
			{
				if (entry->update) {
					rygel_media_db_update_object (self->priv->media_db, (RygelMediaObject*) item, &_inner_error_);
					if (_inner_error_ != NULL) {
						goto __catch13_g_error;
						goto __finally13;
					}
				} else {
					rygel_media_db_save_object (self->priv->media_db, (RygelMediaObject*) item, &_inner_error_);
					if (_inner_error_ != NULL) {
						goto __catch13_g_error;
						goto __finally13;
					}
				}
			}
			goto __finally13;
			__catch13_g_error:
			{
				GError * _error_;
				_error_ = _inner_error_;
				_inner_error_ = NULL;
				{
					_g_error_free0 (_error_);
				}
			}
			__finally13:
			if (_inner_error_ != NULL) {
				_g_object_unref0 (item);
				_rygel_file_queue_entry_unref0 (entry);
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return;
			}
		}
		_tmp1_ = (RygelFileQueueEntry*) g_queue_pop_head (self->priv->files);
		_rygel_file_queue_entry_unref0 (_tmp1_);
		rygel_media_export_harvester_do_update (self);
		g_idle_add_full (G_PRIORITY_DEFAULT_IDLE, _rygel_media_export_harvester_on_idle_gsource_func, g_object_ref (self), g_object_unref);
		_g_object_unref0 (item);
	}
	_rygel_file_queue_entry_unref0 (entry);
}


static void rygel_media_export_harvester_on_extractor_error_cb (RygelMediaExportHarvester* self, GFile* file, GError* _error_) {
	RygelFileQueueEntry* entry;
	g_return_if_fail (self != NULL);
	g_return_if_fail (file != NULL);
	entry = _rygel_file_queue_entry_ref0 ((RygelFileQueueEntry*) g_queue_peek_head (self->priv->files));
	if (entry == NULL) {
		_rygel_file_queue_entry_unref0 (entry);
		return;
	}
	if (file == entry->file) {
		RygelFileQueueEntry* _tmp0_;
		_tmp0_ = (RygelFileQueueEntry*) g_queue_pop_head (self->priv->files);
		_rygel_file_queue_entry_unref0 (_tmp0_);
		rygel_media_export_harvester_do_update (self);
		g_idle_add_full (G_PRIORITY_DEFAULT_IDLE, _rygel_media_export_harvester_on_idle_gsource_func, g_object_ref (self), g_object_unref);
	}
	_rygel_file_queue_entry_unref0 (entry);
}


static void rygel_media_export_harvester_do_update (RygelMediaExportHarvester* self) {
	gboolean _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = FALSE;
	if (g_queue_get_length (self->priv->files) == 0) {
		_tmp0_ = g_queue_get_length (self->priv->containers) != 0;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		RygelMediaContainer* _tmp1_;
		rygel_media_container_updated ((RygelMediaContainer*) g_queue_peek_head (self->priv->containers));
		_tmp1_ = (RygelMediaContainer*) g_queue_pop_head (self->priv->containers);
		_g_object_unref0 (_tmp1_);
	}
}


static void rygel_media_export_harvester_class_init (RygelMediaExportHarvesterClass * klass) {
	rygel_media_export_harvester_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelMediaExportHarvesterPrivate));
	G_OBJECT_CLASS (klass)->finalize = rygel_media_export_harvester_finalize;
	g_signal_new ("harvested", RYGEL_TYPE_MEDIA_EXPORT_HARVESTER, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__OBJECT, G_TYPE_NONE, 1, G_TYPE_FILE);
}


static void rygel_media_export_harvester_instance_init (RygelMediaExportHarvester * self) {
	self->priv = RYGEL_MEDIA_EXPORT_HARVESTER_GET_PRIVATE (self);
}


static void rygel_media_export_harvester_finalize (GObject* obj) {
	RygelMediaExportHarvester * self;
	self = RYGEL_MEDIA_EXPORT_HARVESTER (obj);
	_g_object_unref0 (self->priv->extractor);
	_g_object_unref0 (self->priv->media_db);
	_g_queue_free0 (self->priv->containers);
	_g_queue_free0 (self->priv->files);
	_g_object_unref0 (self->priv->origin);
	_g_object_unref0 (self->priv->parent);
	_g_object_unref0 (self->priv->monitor);
	G_OBJECT_CLASS (rygel_media_export_harvester_parent_class)->finalize (obj);
}


GType rygel_media_export_harvester_get_type (void) {
	static GType rygel_media_export_harvester_type_id = 0;
	if (rygel_media_export_harvester_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediaExportHarvesterClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_media_export_harvester_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediaExportHarvester), 0, (GInstanceInitFunc) rygel_media_export_harvester_instance_init, NULL };
		rygel_media_export_harvester_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelMediaExportHarvester", &g_define_type_info, 0);
	}
	return rygel_media_export_harvester_type_id;
}




