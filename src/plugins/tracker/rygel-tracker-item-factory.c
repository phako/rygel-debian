/* rygel-tracker-item-factory.c generated by valac, the Vala compiler
 * generated from rygel-tracker-item-factory.vala, do not modify */

/*
 * Copyright (C) 2008 Zeeshan Ali <zeenix@gmail.com>.
 * Copyright (C) 2008 Nokia Corporation.
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
#include <rygel.h>
#include <gee.h>
#include <gobject/gvaluecollector.h>


#define RYGEL_TYPE_TRACKER_ITEM_FACTORY (rygel_tracker_item_factory_get_type ())
#define RYGEL_TRACKER_ITEM_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_ITEM_FACTORY, RygelTrackerItemFactory))
#define RYGEL_TRACKER_ITEM_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_ITEM_FACTORY, RygelTrackerItemFactoryClass))
#define RYGEL_IS_TRACKER_ITEM_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_ITEM_FACTORY))
#define RYGEL_IS_TRACKER_ITEM_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_ITEM_FACTORY))
#define RYGEL_TRACKER_ITEM_FACTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_ITEM_FACTORY, RygelTrackerItemFactoryClass))

typedef struct _RygelTrackerItemFactory RygelTrackerItemFactory;
typedef struct _RygelTrackerItemFactoryClass RygelTrackerItemFactoryClass;
typedef struct _RygelTrackerItemFactoryPrivate RygelTrackerItemFactoryPrivate;

#define RYGEL_TYPE_TRACKER_SEARCH_CONTAINER (rygel_tracker_search_container_get_type ())
#define RYGEL_TRACKER_SEARCH_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainer))
#define RYGEL_TRACKER_SEARCH_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainerClass))
#define RYGEL_IS_TRACKER_SEARCH_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER))
#define RYGEL_IS_TRACKER_SEARCH_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER))
#define RYGEL_TRACKER_SEARCH_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_SEARCH_CONTAINER, RygelTrackerSearchContainerClass))

typedef struct _RygelTrackerSearchContainer RygelTrackerSearchContainer;
typedef struct _RygelTrackerSearchContainerClass RygelTrackerSearchContainerClass;

#define RYGEL_TRACKER_ITEM_FACTORY_TYPE_METADATA (rygel_tracker_item_factory_metadata_get_type ())
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _RygelParamSpecTrackerItemFactory RygelParamSpecTrackerItemFactory;

struct _RygelTrackerItemFactory {
	GTypeInstance parent_instance;
	volatile int ref_count;
	RygelTrackerItemFactoryPrivate * priv;
	char* category;
	char* upnp_class;
	char* resources_class_path;
	char* upload_dir;
	GeeArrayList* key_chains;
};

struct _RygelTrackerItemFactoryClass {
	GTypeClass parent_class;
	void (*finalize) (RygelTrackerItemFactory *self);
	RygelMediaItem* (*create) (RygelTrackerItemFactory* self, const char* id, const char* uri, RygelTrackerSearchContainer* parent, char** metadata, int metadata_length1, GError** error);
};

typedef enum  {
	RYGEL_TRACKER_ITEM_FACTORY_METADATA_FILE_NAME,
	RYGEL_TRACKER_ITEM_FACTORY_METADATA_TITLE,
	RYGEL_TRACKER_ITEM_FACTORY_METADATA_MIME,
	RYGEL_TRACKER_ITEM_FACTORY_METADATA_SIZE,
	RYGEL_TRACKER_ITEM_FACTORY_METADATA_DATE,
	RYGEL_TRACKER_ITEM_FACTORY_METADATA_LAST_KEY
} RygelTrackerItemFactoryMetadata;

struct _RygelParamSpecTrackerItemFactory {
	GParamSpec parent_instance;
};


static gpointer rygel_tracker_item_factory_parent_class = NULL;

gpointer rygel_tracker_item_factory_ref (gpointer instance);
void rygel_tracker_item_factory_unref (gpointer instance);
GParamSpec* rygel_param_spec_tracker_item_factory (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_tracker_item_factory (GValue* value, gpointer v_object);
void rygel_value_take_tracker_item_factory (GValue* value, gpointer v_object);
gpointer rygel_value_get_tracker_item_factory (const GValue* value);
GType rygel_tracker_item_factory_get_type (void);
GType rygel_tracker_search_container_get_type (void);
enum  {
	RYGEL_TRACKER_ITEM_FACTORY_DUMMY_PROPERTY
};
GType rygel_tracker_item_factory_metadata_get_type (void);
RygelTrackerItemFactory* rygel_tracker_item_factory_construct (GType object_type, const char* category, const char* upnp_class, const char* resources_class_path, const char* upload_dir);
RygelMediaItem* rygel_tracker_item_factory_create (RygelTrackerItemFactory* self, const char* id, const char* uri, RygelTrackerSearchContainer* parent, char** metadata, int metadata_length1, GError** error);
static RygelMediaItem* rygel_tracker_item_factory_real_create (RygelTrackerItemFactory* self, const char* id, const char* uri, RygelTrackerSearchContainer* parent, char** metadata, int metadata_length1, GError** error);
static void rygel_tracker_item_factory_finalize (RygelTrackerItemFactory* obj);
static int _vala_strcmp0 (const char * str1, const char * str2);



GType rygel_tracker_item_factory_metadata_get_type (void) {
	static volatile gsize rygel_tracker_item_factory_metadata_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_tracker_item_factory_metadata_type_id__volatile)) {
		static const GEnumValue values[] = {{RYGEL_TRACKER_ITEM_FACTORY_METADATA_FILE_NAME, "RYGEL_TRACKER_ITEM_FACTORY_METADATA_FILE_NAME", "file-name"}, {RYGEL_TRACKER_ITEM_FACTORY_METADATA_TITLE, "RYGEL_TRACKER_ITEM_FACTORY_METADATA_TITLE", "title"}, {RYGEL_TRACKER_ITEM_FACTORY_METADATA_MIME, "RYGEL_TRACKER_ITEM_FACTORY_METADATA_MIME", "mime"}, {RYGEL_TRACKER_ITEM_FACTORY_METADATA_SIZE, "RYGEL_TRACKER_ITEM_FACTORY_METADATA_SIZE", "size"}, {RYGEL_TRACKER_ITEM_FACTORY_METADATA_DATE, "RYGEL_TRACKER_ITEM_FACTORY_METADATA_DATE", "date"}, {RYGEL_TRACKER_ITEM_FACTORY_METADATA_LAST_KEY, "RYGEL_TRACKER_ITEM_FACTORY_METADATA_LAST_KEY", "last-key"}, {0, NULL, NULL}};
		GType rygel_tracker_item_factory_metadata_type_id;
		rygel_tracker_item_factory_metadata_type_id = g_enum_register_static ("RygelTrackerItemFactoryMetadata", values);
		g_once_init_leave (&rygel_tracker_item_factory_metadata_type_id__volatile, rygel_tracker_item_factory_metadata_type_id);
	}
	return rygel_tracker_item_factory_metadata_type_id__volatile;
}


#line 47 "rygel-tracker-item-factory.vala"
RygelTrackerItemFactory* rygel_tracker_item_factory_construct (GType object_type, const char* category, const char* upnp_class, const char* resources_class_path, const char* upload_dir) {
#line 130 "rygel-tracker-item-factory.c"
	RygelTrackerItemFactory* self;
	char* _tmp0_;
	char* _tmp1_;
	char* _tmp2_;
	char* _tmp3_;
	GeeArrayList* _tmp4_;
	GeeArrayList* _tmp7_;
	GeeArrayList* _tmp8_;
	GeeArrayList* _tmp9_;
	GeeArrayList* _tmp10_;
	GeeArrayList* _tmp11_;
#line 47 "rygel-tracker-item-factory.vala"
	g_return_val_if_fail (category != NULL, NULL);
#line 47 "rygel-tracker-item-factory.vala"
	g_return_val_if_fail (upnp_class != NULL, NULL);
#line 47 "rygel-tracker-item-factory.vala"
	g_return_val_if_fail (resources_class_path != NULL, NULL);
#line 148 "rygel-tracker-item-factory.c"
	self = (RygelTrackerItemFactory*) g_type_create_instance (object_type);
#line 51 "rygel-tracker-item-factory.vala"
	self->category = (_tmp0_ = g_strdup (category), _g_free0 (self->category), _tmp0_);
#line 52 "rygel-tracker-item-factory.vala"
	self->upnp_class = (_tmp1_ = g_strdup (upnp_class), _g_free0 (self->upnp_class), _tmp1_);
#line 53 "rygel-tracker-item-factory.vala"
	self->resources_class_path = (_tmp2_ = g_strdup (resources_class_path), _g_free0 (self->resources_class_path), _tmp2_);
#line 54 "rygel-tracker-item-factory.vala"
	self->upload_dir = (_tmp3_ = g_strdup (upload_dir), _g_free0 (self->upload_dir), _tmp3_);
#line 56 "rygel-tracker-item-factory.vala"
	self->key_chains = (_tmp4_ = gee_array_list_new (GEE_TYPE_ARRAY_LIST, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL), _g_object_unref0 (self->key_chains), _tmp4_);
#line 160 "rygel-tracker-item-factory.c"
	{
		gint i;
#line 58 "rygel-tracker-item-factory.vala"
		i = 0;
#line 165 "rygel-tracker-item-factory.c"
		{
			gboolean _tmp5_;
#line 58 "rygel-tracker-item-factory.vala"
			_tmp5_ = TRUE;
#line 58 "rygel-tracker-item-factory.vala"
			while (TRUE) {
#line 172 "rygel-tracker-item-factory.c"
				GeeArrayList* _tmp6_;
#line 58 "rygel-tracker-item-factory.vala"
				if (!_tmp5_) {
#line 58 "rygel-tracker-item-factory.vala"
					i++;
#line 178 "rygel-tracker-item-factory.c"
				}
#line 58 "rygel-tracker-item-factory.vala"
				_tmp5_ = FALSE;
#line 58 "rygel-tracker-item-factory.vala"
				if (!(i < RYGEL_TRACKER_ITEM_FACTORY_METADATA_LAST_KEY)) {
#line 58 "rygel-tracker-item-factory.vala"
					break;
#line 186 "rygel-tracker-item-factory.c"
				}
#line 59 "rygel-tracker-item-factory.vala"
				gee_abstract_collection_add ((GeeAbstractCollection*) self->key_chains, _tmp6_ = gee_array_list_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, NULL));
#line 190 "rygel-tracker-item-factory.c"
				_g_object_unref0 (_tmp6_);
			}
		}
	}
#line 62 "rygel-tracker-item-factory.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) (_tmp7_ = (GeeArrayList*) gee_abstract_list_get ((GeeAbstractList*) self->key_chains, (gint) RYGEL_TRACKER_ITEM_FACTORY_METADATA_FILE_NAME)), "nfo:fileName");
#line 197 "rygel-tracker-item-factory.c"
	_g_object_unref0 (_tmp7_);
#line 63 "rygel-tracker-item-factory.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) (_tmp8_ = (GeeArrayList*) gee_abstract_list_get ((GeeAbstractList*) self->key_chains, (gint) RYGEL_TRACKER_ITEM_FACTORY_METADATA_TITLE)), "nie:title");
#line 201 "rygel-tracker-item-factory.c"
	_g_object_unref0 (_tmp8_);
#line 64 "rygel-tracker-item-factory.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) (_tmp9_ = (GeeArrayList*) gee_abstract_list_get ((GeeAbstractList*) self->key_chains, (gint) RYGEL_TRACKER_ITEM_FACTORY_METADATA_MIME)), "nie:mimeType");
#line 205 "rygel-tracker-item-factory.c"
	_g_object_unref0 (_tmp9_);
#line 65 "rygel-tracker-item-factory.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) (_tmp10_ = (GeeArrayList*) gee_abstract_list_get ((GeeAbstractList*) self->key_chains, (gint) RYGEL_TRACKER_ITEM_FACTORY_METADATA_SIZE)), "nfo:fileSize");
#line 209 "rygel-tracker-item-factory.c"
	_g_object_unref0 (_tmp10_);
#line 66 "rygel-tracker-item-factory.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) (_tmp11_ = (GeeArrayList*) gee_abstract_list_get ((GeeAbstractList*) self->key_chains, (gint) RYGEL_TRACKER_ITEM_FACTORY_METADATA_DATE)), "nie:contentCreated");
#line 213 "rygel-tracker-item-factory.c"
	_g_object_unref0 (_tmp11_);
	return self;
}


#line 69 "rygel-tracker-item-factory.vala"
static RygelMediaItem* rygel_tracker_item_factory_real_create (RygelTrackerItemFactory* self, const char* id, const char* uri, RygelTrackerSearchContainer* parent, char** metadata, int metadata_length1, GError** error) {
#line 221 "rygel-tracker-item-factory.c"
	RygelMediaItem* result = NULL;
	RygelMediaItem* item;
	char* _tmp1_;
#line 69 "rygel-tracker-item-factory.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 69 "rygel-tracker-item-factory.vala"
	g_return_val_if_fail (id != NULL, NULL);
#line 69 "rygel-tracker-item-factory.vala"
	g_return_val_if_fail (uri != NULL, NULL);
#line 69 "rygel-tracker-item-factory.vala"
	g_return_val_if_fail (parent != NULL, NULL);
#line 74 "rygel-tracker-item-factory.vala"
	item = rygel_media_item_new (id, (RygelMediaContainer*) parent, "", self->upnp_class);
#line 76 "rygel-tracker-item-factory.vala"
	if (_vala_strcmp0 (metadata[RYGEL_TRACKER_ITEM_FACTORY_METADATA_TITLE], "") != 0) {
#line 77 "rygel-tracker-item-factory.vala"
		rygel_media_object_set_title ((RygelMediaObject*) item, metadata[RYGEL_TRACKER_ITEM_FACTORY_METADATA_TITLE]);
#line 239 "rygel-tracker-item-factory.c"
	} else {
#line 80 "rygel-tracker-item-factory.vala"
		rygel_media_object_set_title ((RygelMediaObject*) item, metadata[RYGEL_TRACKER_ITEM_FACTORY_METADATA_FILE_NAME]);
#line 243 "rygel-tracker-item-factory.c"
	}
#line 82 "rygel-tracker-item-factory.vala"
	if (_vala_strcmp0 (metadata[RYGEL_TRACKER_ITEM_FACTORY_METADATA_SIZE], "") != 0) {
#line 83 "rygel-tracker-item-factory.vala"
		item->size = (glong) atoi (metadata[RYGEL_TRACKER_ITEM_FACTORY_METADATA_SIZE]);
#line 249 "rygel-tracker-item-factory.c"
	}
#line 85 "rygel-tracker-item-factory.vala"
	if (_vala_strcmp0 (metadata[RYGEL_TRACKER_ITEM_FACTORY_METADATA_DATE], "") != 0) {
#line 253 "rygel-tracker-item-factory.c"
		char* _tmp0_;
#line 86 "rygel-tracker-item-factory.vala"
		item->date = (_tmp0_ = g_strdup (metadata[RYGEL_TRACKER_ITEM_FACTORY_METADATA_DATE]), _g_free0 (item->date), _tmp0_);
#line 257 "rygel-tracker-item-factory.c"
	}
#line 88 "rygel-tracker-item-factory.vala"
	item->mime_type = (_tmp1_ = g_strdup (metadata[RYGEL_TRACKER_ITEM_FACTORY_METADATA_MIME]), _g_free0 (item->mime_type), _tmp1_);
#line 90 "rygel-tracker-item-factory.vala"
	rygel_media_item_add_uri (item, uri, NULL);
#line 263 "rygel-tracker-item-factory.c"
	result = item;
#line 92 "rygel-tracker-item-factory.vala"
	return result;
#line 267 "rygel-tracker-item-factory.c"
}


#line 69 "rygel-tracker-item-factory.vala"
RygelMediaItem* rygel_tracker_item_factory_create (RygelTrackerItemFactory* self, const char* id, const char* uri, RygelTrackerSearchContainer* parent, char** metadata, int metadata_length1, GError** error) {
#line 69 "rygel-tracker-item-factory.vala"
	return RYGEL_TRACKER_ITEM_FACTORY_GET_CLASS (self)->create (self, id, uri, parent, metadata, metadata_length1, error);
#line 275 "rygel-tracker-item-factory.c"
}


static void rygel_value_tracker_item_factory_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void rygel_value_tracker_item_factory_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		rygel_tracker_item_factory_unref (value->data[0].v_pointer);
	}
}


static void rygel_value_tracker_item_factory_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = rygel_tracker_item_factory_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer rygel_value_tracker_item_factory_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* rygel_value_tracker_item_factory_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		RygelTrackerItemFactory* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = rygel_tracker_item_factory_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* rygel_value_tracker_item_factory_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	RygelTrackerItemFactory** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags && G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = rygel_tracker_item_factory_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* rygel_param_spec_tracker_item_factory (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	RygelParamSpecTrackerItemFactory* spec;
	g_return_val_if_fail (g_type_is_a (object_type, RYGEL_TYPE_TRACKER_ITEM_FACTORY), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer rygel_value_get_tracker_item_factory (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_TYPE_TRACKER_ITEM_FACTORY), NULL);
	return value->data[0].v_pointer;
}


void rygel_value_set_tracker_item_factory (GValue* value, gpointer v_object) {
	RygelTrackerItemFactory* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_TYPE_TRACKER_ITEM_FACTORY));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, RYGEL_TYPE_TRACKER_ITEM_FACTORY));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		rygel_tracker_item_factory_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		rygel_tracker_item_factory_unref (old);
	}
}


void rygel_value_take_tracker_item_factory (GValue* value, gpointer v_object) {
	RygelTrackerItemFactory* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, RYGEL_TYPE_TRACKER_ITEM_FACTORY));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, RYGEL_TYPE_TRACKER_ITEM_FACTORY));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		rygel_tracker_item_factory_unref (old);
	}
}


static void rygel_tracker_item_factory_class_init (RygelTrackerItemFactoryClass * klass) {
	rygel_tracker_item_factory_parent_class = g_type_class_peek_parent (klass);
	RYGEL_TRACKER_ITEM_FACTORY_CLASS (klass)->finalize = rygel_tracker_item_factory_finalize;
	RYGEL_TRACKER_ITEM_FACTORY_CLASS (klass)->create = rygel_tracker_item_factory_real_create;
}


static void rygel_tracker_item_factory_instance_init (RygelTrackerItemFactory * self) {
	self->ref_count = 1;
}


static void rygel_tracker_item_factory_finalize (RygelTrackerItemFactory* obj) {
	RygelTrackerItemFactory * self;
	self = RYGEL_TRACKER_ITEM_FACTORY (obj);
	_g_free0 (self->category);
	_g_free0 (self->upnp_class);
	_g_free0 (self->resources_class_path);
	_g_free0 (self->upload_dir);
	_g_object_unref0 (self->key_chains);
}


GType rygel_tracker_item_factory_get_type (void) {
	static volatile gsize rygel_tracker_item_factory_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_tracker_item_factory_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { rygel_value_tracker_item_factory_init, rygel_value_tracker_item_factory_free_value, rygel_value_tracker_item_factory_copy_value, rygel_value_tracker_item_factory_peek_pointer, "p", rygel_value_tracker_item_factory_collect_value, "p", rygel_value_tracker_item_factory_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (RygelTrackerItemFactoryClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_tracker_item_factory_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelTrackerItemFactory), 0, (GInstanceInitFunc) rygel_tracker_item_factory_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType rygel_tracker_item_factory_type_id;
		rygel_tracker_item_factory_type_id = g_type_register_fundamental (g_type_fundamental_next (), "RygelTrackerItemFactory", &g_define_type_info, &g_define_type_fundamental_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&rygel_tracker_item_factory_type_id__volatile, rygel_tracker_item_factory_type_id);
	}
	return rygel_tracker_item_factory_type_id__volatile;
}


gpointer rygel_tracker_item_factory_ref (gpointer instance) {
	RygelTrackerItemFactory* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void rygel_tracker_item_factory_unref (gpointer instance) {
	RygelTrackerItemFactory* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		RYGEL_TRACKER_ITEM_FACTORY_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
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




