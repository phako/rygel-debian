/*
 * Copyright (C) 2009 Jens Georg <mail@jensge.org>.
 *
 * Author: Jens Georg <mail@jensge.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 */

#include <glib.h>
#include <glib-object.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <string.h>
#include <gee.h>
#include <gst/gst.h>


#define RYGEL_TYPE_MEDIA_DB_OBJECT_TYPE (rygel_media_db_object_type_get_type ())

#define RYGEL_TYPE_MEDIA_DB (rygel_media_db_get_type ())
#define RYGEL_MEDIA_DB(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_DB, RygelMediaDB))
#define RYGEL_MEDIA_DB_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_DB, RygelMediaDBClass))
#define RYGEL_IS_MEDIA_DB(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_DB))
#define RYGEL_IS_MEDIA_DB_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_DB))
#define RYGEL_MEDIA_DB_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_DB, RygelMediaDBClass))

typedef struct _RygelMediaDB RygelMediaDB;
typedef struct _RygelMediaDBClass RygelMediaDBClass;
typedef struct _RygelMediaDBPrivate RygelMediaDBPrivate;

#define RYGEL_TYPE_MEDIA_DB_OBJECT_FACTORY (rygel_media_db_object_factory_get_type ())
#define RYGEL_MEDIA_DB_OBJECT_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_DB_OBJECT_FACTORY, RygelMediaDBObjectFactory))
#define RYGEL_MEDIA_DB_OBJECT_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_DB_OBJECT_FACTORY, RygelMediaDBObjectFactoryClass))
#define RYGEL_IS_MEDIA_DB_OBJECT_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_DB_OBJECT_FACTORY))
#define RYGEL_IS_MEDIA_DB_OBJECT_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_DB_OBJECT_FACTORY))
#define RYGEL_MEDIA_DB_OBJECT_FACTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_DB_OBJECT_FACTORY, RygelMediaDBObjectFactoryClass))

typedef struct _RygelMediaDBObjectFactory RygelMediaDBObjectFactory;
typedef struct _RygelMediaDBObjectFactoryClass RygelMediaDBObjectFactoryClass;
#define _sqlite3_close0(var) ((var == NULL) ? NULL : (var = (sqlite3_close (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _sqlite3_finalize0(var) ((var == NULL) ? NULL : (var = (sqlite3_finalize (var), NULL)))

#define RYGEL_TYPE_MEDIA_OBJECT (rygel_media_object_get_type ())
#define RYGEL_MEDIA_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObject))
#define RYGEL_MEDIA_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObjectClass))
#define RYGEL_IS_MEDIA_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_OBJECT))
#define RYGEL_IS_MEDIA_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_OBJECT))
#define RYGEL_MEDIA_OBJECT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObjectClass))

typedef struct _RygelMediaObject RygelMediaObject;
typedef struct _RygelMediaObjectClass RygelMediaObjectClass;
typedef struct _RygelMediaObjectPrivate RygelMediaObjectPrivate;

#define RYGEL_TYPE_MEDIA_CONTAINER (rygel_media_container_get_type ())
#define RYGEL_MEDIA_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainer))
#define RYGEL_MEDIA_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainerClass))
#define RYGEL_IS_MEDIA_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_CONTAINER))
#define RYGEL_IS_MEDIA_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_CONTAINER))
#define RYGEL_MEDIA_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainerClass))

typedef struct _RygelMediaContainer RygelMediaContainer;
typedef struct _RygelMediaContainerClass RygelMediaContainerClass;

#define RYGEL_TYPE_MEDIA_ITEM (rygel_media_item_get_type ())
#define RYGEL_MEDIA_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_ITEM, RygelMediaItem))
#define RYGEL_MEDIA_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_ITEM, RygelMediaItemClass))
#define RYGEL_IS_MEDIA_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_ITEM))
#define RYGEL_IS_MEDIA_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_ITEM))
#define RYGEL_MEDIA_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_ITEM, RygelMediaItemClass))

typedef struct _RygelMediaItem RygelMediaItem;
typedef struct _RygelMediaItemClass RygelMediaItemClass;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _RygelMediaItemPrivate RygelMediaItemPrivate;

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

typedef enum  {
	RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR,
	RYGEL_MEDIA_DB_ERROR_GENERAL_ERROR,
	RYGEL_MEDIA_DB_ERROR_INVALID_TYPE
} RygelMediaDBError;
#define RYGEL_MEDIA_DB_ERROR rygel_media_db_error_quark ()
typedef enum  {
	RYGEL_MEDIA_DB_OBJECT_TYPE_CONTAINER,
	RYGEL_MEDIA_DB_OBJECT_TYPE_ITEM
} RygelMediaDBObjectType;

struct _RygelMediaDB {
	GObject parent_instance;
	RygelMediaDBPrivate * priv;
};

struct _RygelMediaDBClass {
	GObjectClass parent_class;
};

struct _RygelMediaDBPrivate {
	sqlite3* db;
	RygelMediaDBObjectFactory* factory;
};

struct _RygelMediaObject {
	GObject parent_instance;
	RygelMediaObjectPrivate * priv;
	char* id;
	char* title;
	guint64 modified;
	GeeArrayList* uris;
	RygelMediaContainer* parent;
	RygelMediaContainer* parent_ref;
};

struct _RygelMediaObjectClass {
	GObjectClass parent_class;
};

struct _RygelMediaItem {
	RygelMediaObject parent_instance;
	RygelMediaItemPrivate * priv;
	char* author;
	char* album;
	char* date;
	char* upnp_class;
	char* mime_type;
	char* dlna_profile;
	glong size;
	glong duration;
	gint bitrate;
	gint sample_freq;
	gint bits_per_sample;
	gint n_audio_channels;
	gint track_number;
	gint width;
	gint height;
	gint pixel_width;
	gint pixel_height;
	gint color_depth;
	GeeArrayList* thumbnails;
};

struct _RygelMediaItemClass {
	RygelMediaObjectClass parent_class;
	GstElement* (*create_stream_source) (RygelMediaItem* self);
	gboolean (*should_stream) (RygelMediaItem* self);
};


static gpointer rygel_media_db_parent_class = NULL;

GQuark rygel_media_db_error_quark (void);
GType rygel_media_db_object_type_get_type (void);
GType rygel_media_db_get_type (void);
GType rygel_media_db_object_factory_get_type (void);
#define RYGEL_MEDIA_DB_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_MEDIA_DB, RygelMediaDBPrivate))
enum  {
	RYGEL_MEDIA_DB_DUMMY_PROPERTY
};
#define RYGEL_MEDIA_DB_schema_version "4"
#define RYGEL_MEDIA_DB_SCHEMA_STRING "CREATE TABLE Schema_Info (version TEXT NOT NULL); " "CREATE TABLE Object_Type (id INTEGER PRIMARY KEY, " "desc TEXT NOT NULL);" "CREATE TABLE Meta_Data (id INTEGER PRIMARY KEY AUTOINCREMENT, " "size INTEGER NOT NULL, " "mime_type TEXT NOT NULL, " "duration INTEGER, " "width INTEGER, " "height INTEGER, " "class TEXT NOT NULL, " "author TEXT, " "album TEXT, " "date TEXT, " "bitrate INTEGER, " "sample_freq INTEGER, " "bits_per_sample INTEGER, " "channels INTEGER, " "track INTEGER, " "color_depth INTEGER, " "object_fk TEXT UNIQUE CONSTRAINT " "object_fk_id REFERENCES Object(upnp_id) " "ON DELETE CASCADE);" "CREATE TABLE Object (parent TEXT CONSTRAINT parent_fk_id " "REFERENCES Object(upnp_id), " "upnp_id TEXT PRIMARY KEY, " "type_fk INTEGER CONSTRAINT type_fk_id " "REFERENCES Object_Type(id), " "title TEXT NOT NULL, " "timestamp INTEGER NOT NULL);" "CREATE TABLE Uri (object_fk TEXT " "CONSTRAINT object_fk_id REFERENCES Object(upnp_id) " "ON DELETE CASCADE, " "uri TEXT NOT NULL);" "INSERT INTO Object_Type (id, desc) VALUES (0, 'Container'); " "INSERT INTO Object_Type (id, desc) VALUES (1, 'Item'); " "INSERT INTO Schema_Info (version) VALUES ('" RYGEL_MEDIA_DB_schema_version "'); "
#define RYGEL_MEDIA_DB_CREATE_TRIGGER_STRING "CREATE TRIGGER trgr_delete_children " "BEFORE DELETE ON Object " "FOR EACH ROW BEGIN " "UPDATE Object SET parent = NULL " "WHERE Object.parent = OLD.upnp_id;" "END;" "CREATE TRIGGER trgr_delete_metadata " "BEFORE DELETE ON Object " "FOR EACH ROW BEGIN " "DELETE FROM Meta_Data WHERE Meta_Data.object_fk = OLD.upnp_id; " "END;" "CREATE TRIGGER trgr_delete_uris " "BEFORE DELETE ON Object " "FOR EACH ROW BEGIN " "DELETE FROM Uri WHERE Uri.object_fk = OLD.upnp_id;" "END;"
#define RYGEL_MEDIA_DB_INSERT_META_DATA_STRING "INSERT INTO Meta_Data " "(size, mime_type, width, height, class, " "author, album, date, bitrate, " "sample_freq, bits_per_sample, channels, " "track, color_depth, duration, object_fk) VALUES " "(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)"
#define RYGEL_MEDIA_DB_UPDATE_META_DATA_STRING "UPDATE Meta_Data SET " "size = ?, mime_type = ?, width = ?, height = ?, class = ?, " "author = ?, album = ?, date = ?, bitrate = ?, " "sample_freq = ?, bits_per_sample = ?, channels = ?, " "track = ?, color_depth = ?, duration = ? " "WHERE object_fk = ?"
#define RYGEL_MEDIA_DB_INSERT_OBJECT_STRING "INSERT INTO Object (upnp_id, title, type_fk, parent, timestamp) " "VALUES (?,?,?,?,?)"
#define RYGEL_MEDIA_DB_UPDATE_OBJECT_STRING "UPDATE Object SET title = ?, timestamp = ? WHERE upnp_id = ?"
#define RYGEL_MEDIA_DB_INSERT_URI_STRING "INSERT INTO Uri (object_fk, uri) VALUES (?,?)"
#define RYGEL_MEDIA_DB_DELETE_URI_STRING "DELETE FROM Uri WHERE object_fk = ?"
#define RYGEL_MEDIA_DB_GET_OBJECT_STRING "SELECT type_fk, title, Meta_Data.size, Meta_Data.mime_type, " "Meta_Data.width, Meta_Data.height, " "Meta_Data.class, Meta_Data.author, Meta_Data.album, " "Meta_Data.date, Meta_Data.bitrate, Meta_Data.sample_freq, " "Meta_Data.bits_per_sample, Meta_Data.channels, " "Meta_Data.track, Meta_Data.color_depth, Meta_Data.duration, " "Object.parent " "FROM Object LEFT OUTER JOIN Meta_Data " "ON Object.upnp_id = Meta_Data.object_fk WHERE Object.upnp_id = ?"
#define RYGEL_MEDIA_DB_GET_CHILDREN_STRING "SELECT type_fk, title, Meta_Data.size, Meta_Data.mime_type, " "Meta_Data.width, Meta_Data.height, " "Meta_Data.class, Meta_Data.author, Meta_Data.album, " "Meta_Data.date, Meta_Data.bitrate, Meta_Data.sample_freq, " "Meta_Data.bits_per_sample, Meta_Data.channels, " "Meta_Data.track, Meta_Data.color_depth, Meta_Data.duration, " "upnp_id, Object.parent, Object.timestamp " "FROM Object LEFT OUTER JOIN Meta_Data " "ON Object.upnp_id = Meta_Data.object_fk " "WHERE Object.parent = ? " "ORDER BY type_fk ASC, " "Meta_Data.class ASC, " "Meta_Data.track ASC, " "title ASC " "LIMIT ?,?"
#define RYGEL_MEDIA_DB_URI_GET_STRING "SELECT uri FROM Uri WHERE Uri.object_fk = ?"
#define RYGEL_MEDIA_DB_CHILDREN_COUNT_STRING "SELECT COUNT(upnp_id) FROM Object WHERE Object.parent = ?"
#define RYGEL_MEDIA_DB_OBJECT_EXISTS_STRING "SELECT COUNT(upnp_id), timestamp FROM Object WHERE Object.upnp_id = ?"
#define RYGEL_MEDIA_DB_OBJECT_DELETE_STRING "DELETE FROM Object WHERE Object.upnp_id = ?"
#define RYGEL_MEDIA_DB_SWEEPER_STRING "DELETE FROM Object WHERE parent IS NULL AND Object.upnp_id != '0'"
#define RYGEL_MEDIA_DB_GET_CHILD_ID_STRING "SELECT upnp_id FROM OBJECT WHERE parent = ?"
#define RYGEL_MEDIA_DB_UPDATE_V3_V4_STRING_1 "ALTER TABLE Meta_Data ADD object_fk TEXT"
#define RYGEL_MEDIA_DB_UPDATE_V3_V4_STRING_2 "UPDATE Meta_Data SET object_fk = " "(SELECT upnp_id FROM Object WHERE metadata_fk = Meta_Data.id)"
#define RYGEL_MEDIA_DB_UPDATE_V3_V4_STRING_3 "ALTER TABLE Object ADD timestamp INTEGER"
#define RYGEL_MEDIA_DB_UPDATE_V3_V4_STRING_4 "UPDATE Object SET timestamp = 0"
static void rygel_media_db_update_v3_v4 (RygelMediaDB* self);
static gboolean rygel_media_db_create_schema (RygelMediaDB* self);
static void rygel_media_db_open_db (RygelMediaDB* self, const char* name);
static RygelMediaDB* rygel_media_db_new (const char* name, RygelMediaDBObjectFactory* factory);
static RygelMediaDB* rygel_media_db_construct (GType object_type, const char* name, RygelMediaDBObjectFactory* factory);
RygelMediaDBObjectFactory* rygel_media_db_object_factory_new (void);
RygelMediaDBObjectFactory* rygel_media_db_object_factory_construct (GType object_type);
RygelMediaDB* rygel_media_db_create (const char* name, GError** error);
RygelMediaDB* rygel_media_db_create_with_factory (const char* name, RygelMediaDBObjectFactory* factory, GError** error);
static gboolean rygel_media_db_sweeper (RygelMediaDB* self);
static gboolean _rygel_media_db_sweeper_gsource_func (gpointer self);
void rygel_media_db_remove_by_id (RygelMediaDB* self, const char* id, GError** error);
GType rygel_media_object_get_type (void);
GType rygel_media_container_get_type (void);
GType rygel_media_item_get_type (void);
void rygel_media_db_remove_object (RygelMediaDB* self, RygelMediaObject* obj, GError** error);
void rygel_media_db_save_item (RygelMediaDB* self, RygelMediaItem* item, GError** error);
void rygel_media_db_save_container (RygelMediaDB* self, RygelMediaContainer* container, GError** error);
void rygel_media_db_save_object (RygelMediaDB* self, RygelMediaObject* obj, GError** error);
static void rygel_media_db_create_object (RygelMediaDB* self, RygelMediaObject* item, GError** error);
static void rygel_media_db_save_uris (RygelMediaDB* self, RygelMediaObject* obj, GError** error);
static void rygel_media_db_save_metadata (RygelMediaDB* self, RygelMediaItem* item, const char* sql, GError** error);
static void rygel_media_db_remove_uris (RygelMediaDB* self, RygelMediaObject* obj, GError** error);
static void rygel_media_db_update_object_internal (RygelMediaDB* self, RygelMediaObject* obj, GError** error);
void rygel_media_db_update_object (RygelMediaDB* self, RygelMediaObject* obj, GError** error);
gpointer rygel_icon_info_ref (gpointer instance);
void rygel_icon_info_unref (gpointer instance);
GParamSpec* rygel_param_spec_icon_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_icon_info (GValue* value, gpointer v_object);
gpointer rygel_value_get_icon_info (const GValue* value);
GType rygel_icon_info_get_type (void);
GType rygel_thumbnail_get_type (void);
void rygel_media_item_add_uri (RygelMediaItem* self, const char* uri, RygelThumbnail* thumbnail);
static void rygel_media_db_add_uris (RygelMediaDB* self, RygelMediaObject* obj, GError** error);
RygelMediaContainer* rygel_media_db_object_factory_get_container (RygelMediaDBObjectFactory* self, RygelMediaDB* media_db, const char* id, const char* title, guint child_count);
RygelMediaItem* rygel_media_db_object_factory_get_item (RygelMediaDBObjectFactory* self, RygelMediaDB* media_db, RygelMediaContainer* parent, const char* id, const char* title, const char* upnp_class);
static void rygel_media_db_fill_item (RygelMediaDB* self, sqlite3_stmt* statement, RygelMediaItem* item);
static RygelMediaObject* rygel_media_db_get_object_from_statement (RygelMediaDB* self, RygelMediaContainer* parent, const char* object_id, sqlite3_stmt* statement);
RygelMediaObject* rygel_media_db_get_object (RygelMediaDB* self, const char* object_id, GError** error);
RygelMediaItem* rygel_media_db_get_item (RygelMediaDB* self, const char* item_id, GError** error);
RygelMediaContainer* rygel_media_db_get_container (RygelMediaDB* self, const char* container_id, GError** error);
GeeArrayList* rygel_media_db_get_child_ids (RygelMediaDB* self, const char* container_id, GError** error);
gint rygel_media_db_get_child_count (RygelMediaDB* self, const char* container_id, GError** error);
gboolean rygel_media_db_exists (RygelMediaDB* self, const char* object_id, gint64* timestamp, GError** error);
GeeArrayList* rygel_media_db_get_children (RygelMediaDB* self, const char* container_id, glong offset, glong max_count);
static void rygel_media_db_finalize (GObject* obj);
static int _vala_strcmp0 (const char * str1, const char * str2);



GQuark rygel_media_db_error_quark (void) {
	return g_quark_from_static_string ("rygel_media_db_error-quark");
}



GType rygel_media_db_object_type_get_type (void) {
	static GType rygel_media_db_object_type_type_id = 0;
	if (G_UNLIKELY (rygel_media_db_object_type_type_id == 0)) {
		static const GEnumValue values[] = {{RYGEL_MEDIA_DB_OBJECT_TYPE_CONTAINER, "RYGEL_MEDIA_DB_OBJECT_TYPE_CONTAINER", "container"}, {RYGEL_MEDIA_DB_OBJECT_TYPE_ITEM, "RYGEL_MEDIA_DB_OBJECT_TYPE_ITEM", "item"}, {0, NULL, NULL}};
		rygel_media_db_object_type_type_id = g_enum_register_static ("RygelMediaDBObjectType", values);
	}
	return rygel_media_db_object_type_type_id;
}


static void rygel_media_db_update_v3_v4 (RygelMediaDB* self) {
	gboolean _tmp0_;
	gboolean _tmp1_;
	gboolean _tmp2_;
	gboolean _tmp3_;
	gboolean _tmp4_;
	gboolean _tmp5_;
	g_return_if_fail (self != NULL);
	_tmp0_ = FALSE;
	_tmp1_ = FALSE;
	_tmp2_ = FALSE;
	_tmp3_ = FALSE;
	_tmp4_ = FALSE;
	_tmp5_ = FALSE;
	if (sqlite3_exec (self->priv->db, "BEGIN", NULL, NULL, NULL) == SQLITE_OK) {
		_tmp5_ = sqlite3_exec (self->priv->db, RYGEL_MEDIA_DB_UPDATE_V3_V4_STRING_1, NULL, NULL, NULL) == SQLITE_OK;
	} else {
		_tmp5_ = FALSE;
	}
	if (_tmp5_) {
		_tmp4_ = sqlite3_exec (self->priv->db, RYGEL_MEDIA_DB_UPDATE_V3_V4_STRING_2, NULL, NULL, NULL) == SQLITE_OK;
	} else {
		_tmp4_ = FALSE;
	}
	if (_tmp4_) {
		_tmp3_ = sqlite3_exec (self->priv->db, RYGEL_MEDIA_DB_UPDATE_V3_V4_STRING_3, NULL, NULL, NULL) == SQLITE_OK;
	} else {
		_tmp3_ = FALSE;
	}
	if (_tmp3_) {
		_tmp2_ = sqlite3_exec (self->priv->db, RYGEL_MEDIA_DB_UPDATE_V3_V4_STRING_4, NULL, NULL, NULL) == SQLITE_OK;
	} else {
		_tmp2_ = FALSE;
	}
	if (_tmp2_) {
		_tmp1_ = sqlite3_exec (self->priv->db, RYGEL_MEDIA_DB_CREATE_TRIGGER_STRING, NULL, NULL, NULL) == SQLITE_OK;
	} else {
		_tmp1_ = FALSE;
	}
	if (_tmp1_) {
		_tmp0_ = sqlite3_exec (self->priv->db, "UPDATE Schema_Info SET version = " RYGEL_MEDIA_DB_schema_version, NULL, NULL, NULL) == SQLITE_OK;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		sqlite3_exec (self->priv->db, "COMMIT", NULL, NULL, NULL);
	} else {
		sqlite3* _tmp6_;
		sqlite3_exec (self->priv->db, "ROLLBACK", NULL, NULL, NULL);
		g_warning ("rygel-media-db.vala:218: Database upgrade failed: %s", sqlite3_errmsg (self->priv->db));
		self->priv->db = (_tmp6_ = NULL, _sqlite3_close0 (self->priv->db), _tmp6_);
	}
}


static void rygel_media_db_open_db (RygelMediaDB* self, const char* name) {
	char* dirname;
	char* _tmp0_;
	char* _tmp1_;
	char* db_file;
	sqlite3* _tmp4_;
	gint _tmp3_;
	sqlite3* _tmp2_;
	gint rc;
	gint schema_info_size;
	gint schema_info_length1;
	char** schema_info;
	gint nrows;
	gint ncolumns;
	g_return_if_fail (self != NULL);
	g_return_if_fail (name != NULL);
	dirname = g_build_filename (g_get_user_cache_dir (), "rygel", NULL);
	g_mkdir_with_parents (dirname, 0750);
	db_file = (_tmp1_ = g_build_filename (dirname, _tmp0_ = g_strdup_printf ("%s.db", name), NULL), _g_free0 (_tmp0_), _tmp1_);
	g_debug ("rygel-media-db.vala:228: Using database file %s", db_file);
	_tmp2_ = NULL;
	rc = (_tmp3_ = sqlite3_open (db_file, &_tmp2_), self->priv->db = (_tmp4_ = _tmp2_, _sqlite3_close0 (self->priv->db), _tmp4_), _tmp3_);
	if (rc != SQLITE_OK) {
		g_warning ("rygel-media-db.vala:231: Failed to open database: %d, %s", rc, sqlite3_errmsg (self->priv->db));
		_g_free0 (dirname);
		_g_free0 (db_file);
		return;
	}
	schema_info = (schema_info_length1 = 0, NULL);
	nrows = 0;
	ncolumns = 0;
	rc = sqlite3_get_table (self->priv->db, "SELECT version FROM Schema_Info;", &schema_info, &nrows, &ncolumns, NULL);
	if (rc == SQLITE_OK) {
		gboolean _tmp5_;
		_tmp5_ = FALSE;
		if (nrows == 1) {
			_tmp5_ = ncolumns == 1;
		} else {
			_tmp5_ = FALSE;
		}
		if (_tmp5_) {
			if (_vala_strcmp0 (schema_info[1], RYGEL_MEDIA_DB_schema_version) == 0) {
				g_debug ("rygel-media-db.vala:250: Media DB schema has current version");
			} else {
				gint old_version;
				gint current_version;
				old_version = atoi (schema_info[1]);
				current_version = atoi (RYGEL_MEDIA_DB_schema_version);
				if (old_version < current_version) {
					g_debug ("rygel-media-db.vala:255: Older schema detected. Upgrading...");
					switch (old_version) {
						case 3:
						{
							rygel_media_db_update_v3_v4 (self);
							break;
						}
						default:
						{
							sqlite3* _tmp6_;
							g_warning ("rygel-media-db.vala:261: Cannot upgrade");
							self->priv->db = (_tmp6_ = NULL, _sqlite3_close0 (self->priv->db), _tmp6_);
							break;
						}
					}
				} else {
					sqlite3* _tmp7_;
					g_warning ("The version \"%d\" of the detected database" " is newer than our supported version \"%d\"", old_version, current_version);
					self->priv->db = (_tmp7_ = NULL, _sqlite3_close0 (self->priv->db), _tmp7_);
				}
			}
		} else {
			sqlite3* _tmp8_;
			g_warning ("rygel-media-db.vala:273: Incompatible schema... cannot proceed");
			self->priv->db = (_tmp8_ = NULL, _sqlite3_close0 (self->priv->db), _tmp8_);
			_g_free0 (dirname);
			_g_free0 (db_file);
			return;
		}
	} else {
		g_debug ("rygel-media-db.vala:278: Could not find schema version; checking for empty database...");
		rc = sqlite3_get_table (self->priv->db, "SELECT * FROM sqlite_master", &schema_info, &nrows, &ncolumns, NULL);
		if (rc != SQLITE_OK) {
			sqlite3* _tmp9_;
			g_warning ("rygel-media-db.vala:285: Something weird going on: %s", sqlite3_errmsg (self->priv->db));
			self->priv->db = (_tmp9_ = NULL, _sqlite3_close0 (self->priv->db), _tmp9_);
			_g_free0 (dirname);
			_g_free0 (db_file);
			return;
		}
		if (nrows == 0) {
			g_debug ("rygel-media-db.vala:292: Empty database, creating new schema version %s", RYGEL_MEDIA_DB_schema_version);
			if (!rygel_media_db_create_schema (self)) {
				sqlite3* _tmp10_;
				self->priv->db = (_tmp10_ = NULL, _sqlite3_close0 (self->priv->db), _tmp10_);
				_g_free0 (dirname);
				_g_free0 (db_file);
				return;
			}
		} else {
			sqlite3* _tmp11_;
			g_warning ("rygel-media-db.vala:299: Incompatible schema... cannot proceed");
			self->priv->db = (_tmp11_ = NULL, _sqlite3_close0 (self->priv->db), _tmp11_);
			_g_free0 (dirname);
			_g_free0 (db_file);
			return;
		}
	}
	_g_free0 (dirname);
	_g_free0 (db_file);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static RygelMediaDB* rygel_media_db_construct (GType object_type, const char* name, RygelMediaDBObjectFactory* factory) {
	RygelMediaDB * self;
	RygelMediaDBObjectFactory* _tmp0_;
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (factory != NULL, NULL);
	self = (RygelMediaDB*) g_object_new (object_type, NULL);
	rygel_media_db_open_db (self, name);
	self->priv->factory = (_tmp0_ = _g_object_ref0 (factory), _g_object_unref0 (self->priv->factory), _tmp0_);
	return self;
}


static RygelMediaDB* rygel_media_db_new (const char* name, RygelMediaDBObjectFactory* factory) {
	return rygel_media_db_construct (RYGEL_TYPE_MEDIA_DB, name, factory);
}


RygelMediaDB* rygel_media_db_create (const char* name, GError** error) {
	RygelMediaDB* result;
	GError * _inner_error_;
	RygelMediaDBObjectFactory* _tmp0_;
	RygelMediaDB* _tmp1_;
	RygelMediaDB* instance;
	g_return_val_if_fail (name != NULL, NULL);
	_inner_error_ = NULL;
	instance = (_tmp1_ = rygel_media_db_new (name, _tmp0_ = rygel_media_db_object_factory_new ()), _g_object_unref0 (_tmp0_), _tmp1_);
	if (instance->priv->db != NULL) {
		result = instance;
		return result;
	}
	_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_GENERAL_ERROR, "Invalid database");
	if (_inner_error_ != NULL) {
		if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
			g_propagate_error (error, _inner_error_);
			_g_object_unref0 (instance);
			return NULL;
		} else {
			_g_object_unref0 (instance);
			g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
	_g_object_unref0 (instance);
}


RygelMediaDB* rygel_media_db_create_with_factory (const char* name, RygelMediaDBObjectFactory* factory, GError** error) {
	RygelMediaDB* result;
	GError * _inner_error_;
	RygelMediaDB* instance;
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (factory != NULL, NULL);
	_inner_error_ = NULL;
	instance = rygel_media_db_new (name, factory);
	if (instance->priv->db != NULL) {
		result = instance;
		return result;
	}
	_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_GENERAL_ERROR, "Invalid database");
	if (_inner_error_ != NULL) {
		if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
			g_propagate_error (error, _inner_error_);
			_g_object_unref0 (instance);
			return NULL;
		} else {
			_g_object_unref0 (instance);
			g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
	_g_object_unref0 (instance);
}


static gboolean rygel_media_db_sweeper (RygelMediaDB* self) {
	gboolean result;
	gint rc;
	g_return_val_if_fail (self != NULL, FALSE);
	g_debug ("rygel-media-db.vala:332: Running sweeper");
	rc = sqlite3_exec (self->priv->db, RYGEL_MEDIA_DB_SWEEPER_STRING, NULL, NULL, NULL);
	if (rc != SQLITE_OK) {
		g_warning ("rygel-media-db.vala:335: Failed to sweep database");
		result = FALSE;
		return result;
	} else {
		gint changes;
		changes = sqlite3_changes (self->priv->db);
		g_debug ("rygel-media-db.vala:342: Changes in sweeper: %d", changes);
		result = changes != 0;
		return result;
	}
}


static gboolean _rygel_media_db_sweeper_gsource_func (gpointer self) {
	return rygel_media_db_sweeper (self);
}


void rygel_media_db_remove_by_id (RygelMediaDB* self, const char* id, GError** error) {
	GError * _inner_error_;
	sqlite3_stmt* statement;
	sqlite3_stmt* _tmp2_;
	gint _tmp1_;
	sqlite3_stmt* _tmp0_;
	gint rc;
	g_return_if_fail (self != NULL);
	g_return_if_fail (id != NULL);
	_inner_error_ = NULL;
	statement = NULL;
	_tmp0_ = NULL;
	rc = (_tmp1_ = sqlite3_prepare_v2 (self->priv->db, "DELETE FROM Object WHERE upnp_id = ?", -1, &_tmp0_, NULL), statement = (_tmp2_ = _tmp0_, _sqlite3_finalize0 (statement), _tmp2_), _tmp1_);
	if (rc == SQLITE_OK) {
		gboolean _tmp3_;
		if (sqlite3_bind_text (statement, 1, g_strdup (id), -1, g_free) != SQLITE_OK) {
			_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
					g_propagate_error (error, _inner_error_);
					_sqlite3_finalize0 (statement);
					return;
				} else {
					_sqlite3_finalize0 (statement);
					g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
					g_clear_error (&_inner_error_);
					return;
				}
			}
		}
		rc = sqlite3_step (statement);
		_tmp3_ = FALSE;
		if (rc == SQLITE_DONE) {
			_tmp3_ = TRUE;
		} else {
			_tmp3_ = rc == SQLITE_OK;
		}
		if (_tmp3_) {
			g_signal_emit_by_name (self, "object-removed", id);
			g_idle_add_full (G_PRIORITY_DEFAULT_IDLE, _rygel_media_db_sweeper_gsource_func, g_object_ref (self), g_object_unref);
		}
	} else {
		g_warning ("rygel-media-db.vala:376: Failed to prepare delete of object %s: %s", id, sqlite3_errmsg (self->priv->db));
		_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
				g_propagate_error (error, _inner_error_);
				_sqlite3_finalize0 (statement);
				return;
			} else {
				_sqlite3_finalize0 (statement);
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return;
			}
		}
	}
	_sqlite3_finalize0 (statement);
}


void rygel_media_db_remove_object (RygelMediaDB* self, RygelMediaObject* obj, GError** error) {
	GError * _inner_error_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (obj != NULL);
	_inner_error_ = NULL;
	rygel_media_db_remove_by_id (self, obj->id, &_inner_error_);
	if (_inner_error_ != NULL) {
		if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
			g_propagate_error (error, _inner_error_);
			return;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	if (RYGEL_IS_MEDIA_ITEM (obj)) {
		g_signal_emit_by_name (self, "item-removed", obj->id);
	} else {
		if (RYGEL_IS_MEDIA_CONTAINER (obj)) {
			g_signal_emit_by_name (self, "container-removed", obj->id);
		} else {
			_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_INVALID_TYPE, "Invalid object type");
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
					g_propagate_error (error, _inner_error_);
					return;
				} else {
					g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
					g_clear_error (&_inner_error_);
					return;
				}
			}
		}
	}
}


void rygel_media_db_save_object (RygelMediaDB* self, RygelMediaObject* obj, GError** error) {
	GError * _inner_error_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (obj != NULL);
	_inner_error_ = NULL;
	if (RYGEL_IS_MEDIA_ITEM (obj)) {
		rygel_media_db_save_item (self, RYGEL_MEDIA_ITEM (obj), &_inner_error_);
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			return;
		}
	} else {
		if (RYGEL_IS_MEDIA_CONTAINER (obj)) {
			rygel_media_db_save_container (self, RYGEL_MEDIA_CONTAINER (obj), &_inner_error_);
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				return;
			}
		} else {
			_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_INVALID_TYPE, "Invalid object type");
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				return;
			}
		}
	}
}


static gpointer _g_error_copy0 (gpointer self) {
	return self ? g_error_copy (self) : NULL;
}


void rygel_media_db_save_container (RygelMediaDB* self, RygelMediaContainer* container, GError** error) {
	GError * _inner_error_;
	gint rc;
	g_return_if_fail (self != NULL);
	g_return_if_fail (container != NULL);
	_inner_error_ = NULL;
	rc = sqlite3_exec (self->priv->db, "BEGIN", NULL, NULL, NULL);
	{
		rygel_media_db_create_object (self, (RygelMediaObject*) container, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch34_g_error;
			goto __finally34;
		}
		rygel_media_db_save_uris (self, (RygelMediaObject*) container, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch34_g_error;
			goto __finally34;
		}
		rc = sqlite3_exec (self->priv->db, "COMMIT", NULL, NULL, NULL);
		if (rc == SQLITE_OK) {
			g_signal_emit_by_name (self, "object-added", ((RygelMediaObject*) container)->id);
			g_signal_emit_by_name (self, "container-added", ((RygelMediaObject*) container)->id);
		}
	}
	goto __finally34;
	__catch34_g_error:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
			rc = sqlite3_exec (self->priv->db, "ROLLBACK", NULL, NULL, NULL);
			_inner_error_ = _g_error_copy0 (_error_);
			if (_inner_error_ != NULL) {
				_g_error_free0 (_error_);
				goto __finally34;
			}
			_g_error_free0 (_error_);
		}
	}
	__finally34:
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return;
	}
}


void rygel_media_db_save_item (RygelMediaDB* self, RygelMediaItem* item, GError** error) {
	GError * _inner_error_;
	gint rc;
	g_return_if_fail (self != NULL);
	g_return_if_fail (item != NULL);
	_inner_error_ = NULL;
	rc = sqlite3_exec (self->priv->db, "BEGIN;", NULL, NULL, NULL);
	{
		rygel_media_db_save_metadata (self, item, RYGEL_MEDIA_DB_INSERT_META_DATA_STRING, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch35_g_error;
			goto __finally35;
		}
		rygel_media_db_create_object (self, (RygelMediaObject*) item, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch35_g_error;
			goto __finally35;
		}
		rygel_media_db_save_uris (self, (RygelMediaObject*) item, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch35_g_error;
			goto __finally35;
		}
		rc = sqlite3_exec (self->priv->db, "COMMIT;", NULL, NULL, NULL);
		if (rc == SQLITE_OK) {
			g_signal_emit_by_name (self, "object-added", ((RygelMediaObject*) item)->id);
			g_signal_emit_by_name (self, "item-added", ((RygelMediaObject*) item)->id);
		}
	}
	goto __finally35;
	__catch35_g_error:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
			g_warning ("rygel-media-db.vala:432: Failed to add item with id %s: %s", ((RygelMediaObject*) item)->id, _error_->message);
			rc = sqlite3_exec (self->priv->db, "ROLLBACK;", NULL, NULL, NULL);
			_inner_error_ = _g_error_copy0 (_error_);
			if (_inner_error_ != NULL) {
				_g_error_free0 (_error_);
				goto __finally35;
			}
			_g_error_free0 (_error_);
		}
	}
	__finally35:
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return;
	}
}


void rygel_media_db_update_object (RygelMediaDB* self, RygelMediaObject* obj, GError** error) {
	GError * _inner_error_;
	gint rc;
	g_return_if_fail (self != NULL);
	g_return_if_fail (obj != NULL);
	_inner_error_ = NULL;
	rc = sqlite3_exec (self->priv->db, "BEGIN", NULL, NULL, NULL);
	{
		rygel_media_db_remove_uris (self, obj, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch36_g_error;
			goto __finally36;
		}
		if (RYGEL_IS_MEDIA_ITEM (obj)) {
			rygel_media_db_save_metadata (self, RYGEL_MEDIA_ITEM (obj), RYGEL_MEDIA_DB_UPDATE_META_DATA_STRING, &_inner_error_);
			if (_inner_error_ != NULL) {
				goto __catch36_g_error;
				goto __finally36;
			}
		}
		rygel_media_db_update_object_internal (self, obj, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch36_g_error;
			goto __finally36;
		}
		rygel_media_db_save_uris (self, obj, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch36_g_error;
			goto __finally36;
		}
		rc = sqlite3_exec (self->priv->db, "COMMIT", NULL, NULL, NULL);
		if (rc == SQLITE_OK) {
			g_signal_emit_by_name (self, "object-updated", obj->id);
			if (RYGEL_IS_MEDIA_ITEM (obj)) {
				g_signal_emit_by_name (self, "item-updated", obj->id);
			} else {
				if (RYGEL_IS_MEDIA_CONTAINER (obj)) {
					g_signal_emit_by_name (self, "container-updated", obj->id);
				}
			}
		}
	}
	goto __finally36;
	__catch36_g_error:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
			g_warning ("rygel-media-db.vala:459: Failed to add item with id %s: %s", obj->id, _error_->message);
			rc = sqlite3_exec (self->priv->db, "ROLLBACK", NULL, NULL, NULL);
			_inner_error_ = _g_error_copy0 (_error_);
			if (_inner_error_ != NULL) {
				_g_error_free0 (_error_);
				goto __finally36;
			}
			_g_error_free0 (_error_);
		}
	}
	__finally36:
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return;
	}
}


static void rygel_media_db_update_object_internal (RygelMediaDB* self, RygelMediaObject* obj, GError** error) {
	GError * _inner_error_;
	sqlite3_stmt* statement;
	sqlite3_stmt* _tmp2_;
	gint _tmp1_;
	sqlite3_stmt* _tmp0_;
	gint rc;
	g_return_if_fail (self != NULL);
	g_return_if_fail (obj != NULL);
	_inner_error_ = NULL;
	statement = NULL;
	_tmp0_ = NULL;
	rc = (_tmp1_ = sqlite3_prepare_v2 (self->priv->db, RYGEL_MEDIA_DB_UPDATE_OBJECT_STRING, -1, &_tmp0_, NULL), statement = (_tmp2_ = _tmp0_, _sqlite3_finalize0 (statement), _tmp2_), _tmp1_);
	if (rc == SQLITE_OK) {
		gboolean _tmp3_;
		gboolean _tmp4_;
		gboolean _tmp5_;
		_tmp3_ = FALSE;
		_tmp4_ = FALSE;
		if (sqlite3_bind_text (statement, 1, g_strdup (obj->title), -1, g_free) != SQLITE_OK) {
			_tmp4_ = TRUE;
		} else {
			_tmp4_ = sqlite3_bind_int64 (statement, 2, (gint64) obj->modified) != SQLITE_OK;
		}
		if (_tmp4_) {
			_tmp3_ = TRUE;
		} else {
			_tmp3_ = sqlite3_bind_text (statement, 3, g_strdup (obj->id), -1, g_free) != SQLITE_OK;
		}
		if (_tmp3_) {
			_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_sqlite3_finalize0 (statement);
				return;
			}
		}
		rc = sqlite3_step (statement);
		_tmp5_ = FALSE;
		if (rc != SQLITE_DONE) {
			_tmp5_ = rc != SQLITE_OK;
		} else {
			_tmp5_ = FALSE;
		}
		if (_tmp5_) {
			_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_sqlite3_finalize0 (statement);
				return;
			}
		}
	} else {
		_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_sqlite3_finalize0 (statement);
			return;
		}
	}
	_sqlite3_finalize0 (statement);
}


static void rygel_media_db_remove_uris (RygelMediaDB* self, RygelMediaObject* obj, GError** error) {
	GError * _inner_error_;
	sqlite3_stmt* statement;
	sqlite3_stmt* _tmp2_;
	gint _tmp1_;
	sqlite3_stmt* _tmp0_;
	gint rc;
	g_return_if_fail (self != NULL);
	g_return_if_fail (obj != NULL);
	_inner_error_ = NULL;
	statement = NULL;
	_tmp0_ = NULL;
	rc = (_tmp1_ = sqlite3_prepare_v2 (self->priv->db, RYGEL_MEDIA_DB_DELETE_URI_STRING, -1, &_tmp0_, NULL), statement = (_tmp2_ = _tmp0_, _sqlite3_finalize0 (statement), _tmp2_), _tmp1_);
	if (rc == SQLITE_OK) {
		gboolean _tmp3_;
		if (sqlite3_bind_text (statement, 1, g_strdup (obj->id), -1, g_free) != SQLITE_OK) {
			_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_sqlite3_finalize0 (statement);
				return;
			}
		}
		rc = sqlite3_step (statement);
		_tmp3_ = FALSE;
		if (rc != SQLITE_DONE) {
			_tmp3_ = rc != SQLITE_OK;
		} else {
			_tmp3_ = FALSE;
		}
		if (_tmp3_) {
			_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_sqlite3_finalize0 (statement);
				return;
			}
		}
	} else {
		_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_sqlite3_finalize0 (statement);
			return;
		}
	}
	_sqlite3_finalize0 (statement);
}


static void rygel_media_db_save_metadata (RygelMediaDB* self, RygelMediaItem* item, const char* sql, GError** error) {
	GError * _inner_error_;
	sqlite3_stmt* statement;
	sqlite3_stmt* _tmp2_;
	gint _tmp1_;
	sqlite3_stmt* _tmp0_;
	gint rc;
	g_return_if_fail (self != NULL);
	g_return_if_fail (item != NULL);
	g_return_if_fail (sql != NULL);
	_inner_error_ = NULL;
	statement = NULL;
	_tmp0_ = NULL;
	rc = (_tmp1_ = sqlite3_prepare_v2 (self->priv->db, sql, -1, &_tmp0_, NULL), statement = (_tmp2_ = _tmp0_, _sqlite3_finalize0 (statement), _tmp2_), _tmp1_);
	if (rc == SQLITE_OK) {
		gboolean _tmp3_;
		gboolean _tmp4_;
		gboolean _tmp5_;
		gboolean _tmp6_;
		gboolean _tmp7_;
		gboolean _tmp8_;
		gboolean _tmp9_;
		gboolean _tmp10_;
		gboolean _tmp11_;
		gboolean _tmp12_;
		gboolean _tmp13_;
		gboolean _tmp14_;
		gboolean _tmp15_;
		gboolean _tmp16_;
		gboolean _tmp17_;
		gboolean _tmp18_;
		_tmp3_ = FALSE;
		_tmp4_ = FALSE;
		_tmp5_ = FALSE;
		_tmp6_ = FALSE;
		_tmp7_ = FALSE;
		_tmp8_ = FALSE;
		_tmp9_ = FALSE;
		_tmp10_ = FALSE;
		_tmp11_ = FALSE;
		_tmp12_ = FALSE;
		_tmp13_ = FALSE;
		_tmp14_ = FALSE;
		_tmp15_ = FALSE;
		_tmp16_ = FALSE;
		_tmp17_ = FALSE;
		if (sqlite3_bind_int64 (statement, 1, (gint64) item->size) != SQLITE_OK) {
			_tmp17_ = TRUE;
		} else {
			_tmp17_ = sqlite3_bind_text (statement, 2, g_strdup (item->mime_type), -1, g_free) != SQLITE_OK;
		}
		if (_tmp17_) {
			_tmp16_ = TRUE;
		} else {
			_tmp16_ = sqlite3_bind_int (statement, 3, item->width) != SQLITE_OK;
		}
		if (_tmp16_) {
			_tmp15_ = TRUE;
		} else {
			_tmp15_ = sqlite3_bind_int (statement, 4, item->height) != SQLITE_OK;
		}
		if (_tmp15_) {
			_tmp14_ = TRUE;
		} else {
			_tmp14_ = sqlite3_bind_text (statement, 5, g_strdup (item->upnp_class), -1, g_free) != SQLITE_OK;
		}
		if (_tmp14_) {
			_tmp13_ = TRUE;
		} else {
			_tmp13_ = sqlite3_bind_text (statement, 6, g_strdup (item->author), -1, g_free) != SQLITE_OK;
		}
		if (_tmp13_) {
			_tmp12_ = TRUE;
		} else {
			_tmp12_ = sqlite3_bind_text (statement, 7, g_strdup (item->album), -1, g_free) != SQLITE_OK;
		}
		if (_tmp12_) {
			_tmp11_ = TRUE;
		} else {
			_tmp11_ = sqlite3_bind_text (statement, 8, g_strdup (item->date), -1, g_free) != SQLITE_OK;
		}
		if (_tmp11_) {
			_tmp10_ = TRUE;
		} else {
			_tmp10_ = sqlite3_bind_int (statement, 9, item->bitrate) != SQLITE_OK;
		}
		if (_tmp10_) {
			_tmp9_ = TRUE;
		} else {
			_tmp9_ = sqlite3_bind_int (statement, 10, item->sample_freq) != SQLITE_OK;
		}
		if (_tmp9_) {
			_tmp8_ = TRUE;
		} else {
			_tmp8_ = sqlite3_bind_int (statement, 11, item->bits_per_sample) != SQLITE_OK;
		}
		if (_tmp8_) {
			_tmp7_ = TRUE;
		} else {
			_tmp7_ = sqlite3_bind_int (statement, 12, item->n_audio_channels) != SQLITE_OK;
		}
		if (_tmp7_) {
			_tmp6_ = TRUE;
		} else {
			_tmp6_ = sqlite3_bind_int (statement, 13, item->track_number) != SQLITE_OK;
		}
		if (_tmp6_) {
			_tmp5_ = TRUE;
		} else {
			_tmp5_ = sqlite3_bind_int (statement, 14, item->color_depth) != SQLITE_OK;
		}
		if (_tmp5_) {
			_tmp4_ = TRUE;
		} else {
			_tmp4_ = sqlite3_bind_int64 (statement, 15, (gint64) item->duration) != SQLITE_OK;
		}
		if (_tmp4_) {
			_tmp3_ = TRUE;
		} else {
			_tmp3_ = sqlite3_bind_text (statement, 16, g_strdup (((RygelMediaObject*) item)->id), -1, g_free) != SQLITE_OK;
		}
		if (_tmp3_) {
			_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_sqlite3_finalize0 (statement);
				return;
			}
		}
		rc = sqlite3_step (statement);
		_tmp18_ = FALSE;
		if (rc != SQLITE_DONE) {
			_tmp18_ = rc != SQLITE_OK;
		} else {
			_tmp18_ = FALSE;
		}
		if (_tmp18_) {
			_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_sqlite3_finalize0 (statement);
				return;
			}
		}
	} else {
		_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_sqlite3_finalize0 (statement);
			return;
		}
	}
	_sqlite3_finalize0 (statement);
}


static void rygel_media_db_create_object (RygelMediaDB* self, RygelMediaObject* item, GError** error) {
	GError * _inner_error_;
	sqlite3_stmt* statement;
	sqlite3_stmt* _tmp2_;
	gint _tmp1_;
	sqlite3_stmt* _tmp0_;
	gint rc;
	g_return_if_fail (self != NULL);
	g_return_if_fail (item != NULL);
	_inner_error_ = NULL;
	statement = NULL;
	_tmp0_ = NULL;
	rc = (_tmp1_ = sqlite3_prepare_v2 (self->priv->db, RYGEL_MEDIA_DB_INSERT_OBJECT_STRING, -1, &_tmp0_, NULL), statement = (_tmp2_ = _tmp0_, _sqlite3_finalize0 (statement), _tmp2_), _tmp1_);
	if (rc == SQLITE_OK) {
		gboolean _tmp3_;
		gboolean _tmp4_;
		gboolean _tmp5_;
		_tmp3_ = FALSE;
		_tmp4_ = FALSE;
		if (sqlite3_bind_text (statement, 1, g_strdup (item->id), -1, g_free) != SQLITE_OK) {
			_tmp4_ = TRUE;
		} else {
			_tmp4_ = sqlite3_bind_int64 (statement, 5, (gint64) item->modified) != SQLITE_OK;
		}
		if (_tmp4_) {
			_tmp3_ = TRUE;
		} else {
			_tmp3_ = sqlite3_bind_text (statement, 2, g_strdup (item->title), -1, g_free) != SQLITE_OK;
		}
		if (_tmp3_) {
			_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_sqlite3_finalize0 (statement);
				return;
			}
		}
		if (RYGEL_IS_MEDIA_ITEM (item)) {
			rc = sqlite3_bind_int (statement, 3, (gint) RYGEL_MEDIA_DB_OBJECT_TYPE_ITEM);
		} else {
			if (RYGEL_IS_MEDIA_OBJECT (item)) {
				rc = sqlite3_bind_int (statement, 3, (gint) RYGEL_MEDIA_DB_OBJECT_TYPE_CONTAINER);
			} else {
				_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_INVALID_TYPE, "Invalid object type");
				if (_inner_error_ != NULL) {
					g_propagate_error (error, _inner_error_);
					_sqlite3_finalize0 (statement);
					return;
				}
			}
		}
		if (rc != SQLITE_OK) {
			_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_sqlite3_finalize0 (statement);
				return;
			}
		}
		if (item->parent == NULL) {
			rc = sqlite3_bind_null (statement, 4);
		} else {
			rc = sqlite3_bind_text (statement, 4, g_strdup (((RygelMediaObject*) item->parent)->id), -1, g_free);
		}
		if (rc != SQLITE_OK) {
			_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_sqlite3_finalize0 (statement);
				return;
			}
		}
		rc = sqlite3_step (statement);
		_tmp5_ = FALSE;
		if (rc != SQLITE_OK) {
			_tmp5_ = rc != SQLITE_DONE;
		} else {
			_tmp5_ = FALSE;
		}
		if (_tmp5_) {
			_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_sqlite3_finalize0 (statement);
				return;
			}
		}
	} else {
		_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_sqlite3_finalize0 (statement);
			return;
		}
	}
	_sqlite3_finalize0 (statement);
}


static void rygel_media_db_save_uris (RygelMediaDB* self, RygelMediaObject* obj, GError** error) {
	GError * _inner_error_;
	sqlite3_stmt* statement;
	sqlite3_stmt* _tmp2_;
	gint _tmp1_;
	sqlite3_stmt* _tmp0_;
	gint rc;
	g_return_if_fail (self != NULL);
	g_return_if_fail (obj != NULL);
	_inner_error_ = NULL;
	statement = NULL;
	_tmp0_ = NULL;
	rc = (_tmp1_ = sqlite3_prepare_v2 (self->priv->db, RYGEL_MEDIA_DB_INSERT_URI_STRING, -1, &_tmp0_, NULL), statement = (_tmp2_ = _tmp0_, _sqlite3_finalize0 (statement), _tmp2_), _tmp1_);
	if (rc == SQLITE_OK) {
		{
			GeeIterator* _uri_it;
			_uri_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) obj->uris);
			while (TRUE) {
				char* uri;
				gboolean _tmp3_;
				gboolean _tmp4_;
				if (!gee_iterator_next (_uri_it)) {
					break;
				}
				uri = (char*) gee_iterator_get (_uri_it);
				_tmp3_ = FALSE;
				if (sqlite3_bind_text (statement, 1, g_strdup (obj->id), -1, g_free) != SQLITE_OK) {
					_tmp3_ = TRUE;
				} else {
					_tmp3_ = sqlite3_bind_text (statement, 2, g_strdup (uri), -1, g_free) != SQLITE_OK;
				}
				if (_tmp3_) {
					_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
					if (_inner_error_ != NULL) {
						g_propagate_error (error, _inner_error_);
						_g_free0 (uri);
						_g_object_unref0 (_uri_it);
						_sqlite3_finalize0 (statement);
						return;
					}
				}
				rc = sqlite3_step (statement);
				_tmp4_ = FALSE;
				if (rc != SQLITE_OK) {
					_tmp4_ = rc != SQLITE_DONE;
				} else {
					_tmp4_ = FALSE;
				}
				if (_tmp4_) {
					_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
					if (_inner_error_ != NULL) {
						g_propagate_error (error, _inner_error_);
						_g_free0 (uri);
						_g_object_unref0 (_uri_it);
						_sqlite3_finalize0 (statement);
						return;
					}
				}
				sqlite3_reset (statement);
				sqlite3_clear_bindings (statement);
				_g_free0 (uri);
			}
			_g_object_unref0 (_uri_it);
		}
	} else {
		_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_sqlite3_finalize0 (statement);
			return;
		}
	}
	_sqlite3_finalize0 (statement);
}


static gboolean rygel_media_db_create_schema (RygelMediaDB* self) {
	gboolean result;
	gint rc;
	g_return_val_if_fail (self != NULL, FALSE);
	rc = sqlite3_exec (self->priv->db, "BEGIN", NULL, NULL, NULL);
	if (rc == SQLITE_OK) {
		rc = sqlite3_exec (self->priv->db, RYGEL_MEDIA_DB_SCHEMA_STRING, NULL, NULL, NULL);
		if (rc == SQLITE_OK) {
			g_debug ("rygel-media-db.vala:626: succeeded in schema creation");
			rc = sqlite3_exec (self->priv->db, RYGEL_MEDIA_DB_CREATE_TRIGGER_STRING, NULL, NULL, NULL);
			if (rc == SQLITE_OK) {
				g_debug ("rygel-media-db.vala:629: succeeded in trigger creation");
				rc = sqlite3_exec (self->priv->db, "COMMIT", NULL, NULL, NULL);
				if (rc == SQLITE_OK) {
					result = TRUE;
					return result;
				} else {
					g_warning ("rygel-media-db.vala:634: Failed to commit schema: %d %s", rc, sqlite3_errmsg (self->priv->db));
				}
			} else {
				g_warning ("rygel-media-db.vala:639: Failed to create triggers: %d %s", rc, sqlite3_errmsg (self->priv->db));
			}
		} else {
			g_warning ("rygel-media-db.vala:644: Failed to create tables: %d %s", rc, sqlite3_errmsg (self->priv->db));
		}
	} else {
		g_warning ("rygel-media-db.vala:649: Failed to start transaction: %d %s", rc, sqlite3_errmsg (self->priv->db));
	}
	sqlite3_exec (self->priv->db, "ROLLBACK", NULL, NULL, NULL);
	result = FALSE;
	return result;
}


static void rygel_media_db_add_uris (RygelMediaDB* self, RygelMediaObject* obj, GError** error) {
	GError * _inner_error_;
	sqlite3_stmt* statement;
	sqlite3_stmt* _tmp2_;
	gint _tmp1_;
	sqlite3_stmt* _tmp0_;
	gint rc;
	g_return_if_fail (self != NULL);
	g_return_if_fail (obj != NULL);
	_inner_error_ = NULL;
	statement = NULL;
	_tmp0_ = NULL;
	rc = (_tmp1_ = sqlite3_prepare_v2 (self->priv->db, RYGEL_MEDIA_DB_URI_GET_STRING, -1, &_tmp0_, NULL), statement = (_tmp2_ = _tmp0_, _sqlite3_finalize0 (statement), _tmp2_), _tmp1_);
	if (rc == SQLITE_OK) {
		if (sqlite3_bind_text (statement, 1, g_strdup (obj->id), -1, g_free) != SQLITE_OK) {
			_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
					g_propagate_error (error, _inner_error_);
					_sqlite3_finalize0 (statement);
					return;
				} else {
					_sqlite3_finalize0 (statement);
					g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
					g_clear_error (&_inner_error_);
					return;
				}
			}
		}
		while (TRUE) {
			if (!((rc = sqlite3_step (statement)) == SQLITE_ROW)) {
				break;
			}
			if (RYGEL_IS_MEDIA_ITEM (obj)) {
				rygel_media_item_add_uri (RYGEL_MEDIA_ITEM (obj), sqlite3_column_text (statement, 0), NULL);
			} else {
				gee_abstract_collection_add ((GeeAbstractCollection*) obj->uris, sqlite3_column_text (statement, 0));
			}
		}
	} else {
		g_warning ("rygel-media-db.vala:678: Failed to get uris for obj %s: %s", obj->id, sqlite3_errmsg (self->priv->db));
		_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
				g_propagate_error (error, _inner_error_);
				_sqlite3_finalize0 (statement);
				return;
			} else {
				_sqlite3_finalize0 (statement);
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return;
			}
		}
	}
	_sqlite3_finalize0 (statement);
}


static RygelMediaObject* rygel_media_db_get_object_from_statement (RygelMediaDB* self, RygelMediaContainer* parent, const char* object_id, sqlite3_stmt* statement) {
	RygelMediaObject* result;
	GError * _inner_error_;
	RygelMediaObject* obj;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (object_id != NULL, NULL);
	g_return_val_if_fail (statement != NULL, NULL);
	_inner_error_ = NULL;
	obj = NULL;
	switch (sqlite3_column_int (statement, 0)) {
		case 0:
		{
			RygelMediaObject* _tmp0_;
			obj = (_tmp0_ = (RygelMediaObject*) rygel_media_db_object_factory_get_container (self->priv->factory, self, object_id, sqlite3_column_text (statement, 1), (guint) 0), _g_object_unref0 (obj), _tmp0_);
			break;
		}
		case 1:
		{
			RygelMediaObject* _tmp1_;
			obj = (_tmp1_ = (RygelMediaObject*) rygel_media_db_object_factory_get_item (self->priv->factory, self, parent, object_id, sqlite3_column_text (statement, 1), sqlite3_column_text (statement, 6)), _g_object_unref0 (obj), _tmp1_);
			rygel_media_db_fill_item (self, statement, RYGEL_MEDIA_ITEM (obj));
			break;
		}
		default:
		{
			g_assert_not_reached ();
		}
	}
	{
		if (obj != NULL) {
			obj->modified = (guint64) sqlite3_column_int64 (statement, 18);
			rygel_media_db_add_uris (self, obj, &_inner_error_);
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
					goto __catch37_rygel_media_db_error;
				}
				goto __finally37;
			}
		}
	}
	goto __finally37;
	__catch37_rygel_media_db_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			RygelMediaObject* _tmp2_;
			g_warning ("rygel-media-db.vala:716: Failed to load uris from database: %s", err->message);
			obj = (_tmp2_ = NULL, _g_object_unref0 (obj), _tmp2_);
			_g_error_free0 (err);
		}
	}
	__finally37:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (obj);
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	result = obj;
	return result;
}


RygelMediaObject* rygel_media_db_get_object (RygelMediaDB* self, const char* object_id, GError** error) {
	RygelMediaObject* result;
	GError * _inner_error_;
	RygelMediaObject* obj;
	sqlite3_stmt* statement;
	sqlite3_stmt* _tmp2_;
	gint _tmp1_;
	sqlite3_stmt* _tmp0_;
	gint rc;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (object_id != NULL, NULL);
	_inner_error_ = NULL;
	obj = NULL;
	statement = NULL;
	_tmp0_ = NULL;
	rc = (_tmp1_ = sqlite3_prepare_v2 (self->priv->db, RYGEL_MEDIA_DB_GET_OBJECT_STRING, -1, &_tmp0_, NULL), statement = (_tmp2_ = _tmp0_, _sqlite3_finalize0 (statement), _tmp2_), _tmp1_);
	if (rc == SQLITE_OK) {
		if (sqlite3_bind_text (statement, 1, g_strdup (object_id), -1, g_free) != SQLITE_OK) {
			_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
					g_propagate_error (error, _inner_error_);
					_g_object_unref0 (obj);
					_sqlite3_finalize0 (statement);
					return NULL;
				} else {
					_g_object_unref0 (obj);
					_sqlite3_finalize0 (statement);
					g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
					g_clear_error (&_inner_error_);
					return NULL;
				}
			}
		}
		while (TRUE) {
			RygelMediaContainer* parent;
			char* parent_id;
			RygelMediaObject* _tmp5_;
			RygelMediaContainer* _tmp6_;
			if (!((rc = sqlite3_step (statement)) == SQLITE_ROW)) {
				break;
			}
			parent = NULL;
			parent_id = g_strdup (sqlite3_column_text (statement, 17));
			if (parent_id != NULL) {
				RygelMediaObject* _tmp3_;
				RygelMediaContainer* _tmp4_;
				_tmp3_ = rygel_media_db_get_object (self, sqlite3_column_text (statement, 17), &_inner_error_);
				if (_inner_error_ != NULL) {
					if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
						g_propagate_error (error, _inner_error_);
						_g_object_unref0 (parent);
						_g_free0 (parent_id);
						_g_object_unref0 (obj);
						_sqlite3_finalize0 (statement);
						return NULL;
					} else {
						_g_object_unref0 (parent);
						_g_free0 (parent_id);
						_g_object_unref0 (obj);
						_sqlite3_finalize0 (statement);
						g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
						g_clear_error (&_inner_error_);
						return NULL;
					}
				}
				parent = (_tmp4_ = RYGEL_MEDIA_CONTAINER (_tmp3_), _g_object_unref0 (parent), _tmp4_);
			} else {
				if (_vala_strcmp0 (sqlite3_column_text (statement, 0), "0") != 0) {
					g_warning ("Inconsitent database; non-root element " "without parent found. Id is %s", sqlite3_column_text (statement, 0));
				}
			}
			obj = (_tmp5_ = rygel_media_db_get_object_from_statement (self, RYGEL_MEDIA_CONTAINER (parent), object_id, statement), _g_object_unref0 (obj), _tmp5_);
			obj->parent_ref = (_tmp6_ = _g_object_ref0 (RYGEL_MEDIA_CONTAINER (parent)), _g_object_unref0 (obj->parent_ref), _tmp6_);
			obj->parent = obj->parent_ref;
			_g_object_unref0 (parent);
			_g_free0 (parent_id);
			break;
		}
	} else {
		_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
				g_propagate_error (error, _inner_error_);
				_g_object_unref0 (obj);
				_sqlite3_finalize0 (statement);
				return NULL;
			} else {
				_g_object_unref0 (obj);
				_sqlite3_finalize0 (statement);
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return NULL;
			}
		}
	}
	result = obj;
	_sqlite3_finalize0 (statement);
	return result;
}


RygelMediaItem* rygel_media_db_get_item (RygelMediaDB* self, const char* item_id, GError** error) {
	RygelMediaItem* result;
	GError * _inner_error_;
	RygelMediaObject* obj;
	gboolean _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (item_id != NULL, NULL);
	_inner_error_ = NULL;
	obj = rygel_media_db_get_object (self, item_id, &_inner_error_);
	if (_inner_error_ != NULL) {
		if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
			g_propagate_error (error, _inner_error_);
			return NULL;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
	_tmp0_ = FALSE;
	if (obj != NULL) {
		_tmp0_ = !RYGEL_IS_MEDIA_ITEM (obj);
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		_inner_error_ = g_error_new (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_INVALID_TYPE, "Object with id %s is not a" "MediaItem", item_id);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
				g_propagate_error (error, _inner_error_);
				_g_object_unref0 (obj);
				return NULL;
			} else {
				_g_object_unref0 (obj);
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return NULL;
			}
		}
	}
	result = _g_object_ref0 (RYGEL_MEDIA_ITEM (obj));
	_g_object_unref0 (obj);
	return result;
}


RygelMediaContainer* rygel_media_db_get_container (RygelMediaDB* self, const char* container_id, GError** error) {
	RygelMediaContainer* result;
	GError * _inner_error_;
	RygelMediaObject* obj;
	gboolean _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (container_id != NULL, NULL);
	_inner_error_ = NULL;
	obj = rygel_media_db_get_object (self, container_id, &_inner_error_);
	if (_inner_error_ != NULL) {
		if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
			g_propagate_error (error, _inner_error_);
			return NULL;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
	_tmp0_ = FALSE;
	if (obj != NULL) {
		_tmp0_ = !RYGEL_IS_MEDIA_CONTAINER (obj);
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		_inner_error_ = g_error_new (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_INVALID_TYPE, "Object with id %s is not a" "MediaContainer", container_id);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
				g_propagate_error (error, _inner_error_);
				_g_object_unref0 (obj);
				return NULL;
			} else {
				_g_object_unref0 (obj);
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return NULL;
			}
		}
	}
	result = _g_object_ref0 (RYGEL_MEDIA_CONTAINER (obj));
	_g_object_unref0 (obj);
	return result;
}


static void rygel_media_db_fill_item (RygelMediaDB* self, sqlite3_stmt* statement, RygelMediaItem* item) {
	char* _tmp0_;
	char* _tmp1_;
	char* _tmp2_;
	char* _tmp3_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (statement != NULL);
	g_return_if_fail (item != NULL);
	item->author = (_tmp0_ = g_strdup (sqlite3_column_text (statement, 7)), _g_free0 (item->author), _tmp0_);
	item->album = (_tmp1_ = g_strdup (sqlite3_column_text (statement, 8)), _g_free0 (item->album), _tmp1_);
	item->date = (_tmp2_ = g_strdup (sqlite3_column_text (statement, 9)), _g_free0 (item->date), _tmp2_);
	item->mime_type = (_tmp3_ = g_strdup (sqlite3_column_text (statement, 3)), _g_free0 (item->mime_type), _tmp3_);
	item->duration = (glong) sqlite3_column_int64 (statement, 16);
	item->size = (glong) sqlite3_column_int64 (statement, 2);
	item->bitrate = sqlite3_column_int (statement, 10);
	item->sample_freq = sqlite3_column_int (statement, 11);
	item->bits_per_sample = sqlite3_column_int (statement, 12);
	item->n_audio_channels = sqlite3_column_int (statement, 13);
	item->track_number = sqlite3_column_int (statement, 14);
	item->width = sqlite3_column_int (statement, 4);
	item->height = sqlite3_column_int (statement, 5);
	item->color_depth = sqlite3_column_int (statement, 15);
}


GeeArrayList* rygel_media_db_get_child_ids (RygelMediaDB* self, const char* container_id, GError** error) {
	GeeArrayList* result;
	GError * _inner_error_;
	GeeArrayList* children;
	sqlite3_stmt* statement;
	sqlite3_stmt* _tmp2_;
	gint _tmp1_;
	sqlite3_stmt* _tmp0_;
	gint rc;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (container_id != NULL, NULL);
	_inner_error_ = NULL;
	children = gee_array_list_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, g_str_equal);
	statement = NULL;
	_tmp0_ = NULL;
	rc = (_tmp1_ = sqlite3_prepare_v2 (self->priv->db, RYGEL_MEDIA_DB_GET_CHILD_ID_STRING, -1, &_tmp0_, NULL), statement = (_tmp2_ = _tmp0_, _sqlite3_finalize0 (statement), _tmp2_), _tmp1_);
	if (rc == SQLITE_OK) {
		if (sqlite3_bind_text (statement, 1, g_strdup (container_id), -1, g_free) != SQLITE_OK) {
			_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
					g_propagate_error (error, _inner_error_);
					_g_object_unref0 (children);
					_sqlite3_finalize0 (statement);
					return NULL;
				} else {
					_g_object_unref0 (children);
					_sqlite3_finalize0 (statement);
					g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
					g_clear_error (&_inner_error_);
					return NULL;
				}
			}
		}
		while (TRUE) {
			if (!((rc = sqlite3_step (statement)) == SQLITE_ROW)) {
				break;
			}
			gee_abstract_collection_add ((GeeAbstractCollection*) children, sqlite3_column_text (statement, 0));
		}
	} else {
		g_warning ("rygel-media-db.vala:819: Failed to get children for obj %s: %s", container_id, sqlite3_errmsg (self->priv->db));
		_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
				g_propagate_error (error, _inner_error_);
				_g_object_unref0 (children);
				_sqlite3_finalize0 (statement);
				return NULL;
			} else {
				_g_object_unref0 (children);
				_sqlite3_finalize0 (statement);
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return NULL;
			}
		}
	}
	result = children;
	_sqlite3_finalize0 (statement);
	return result;
}


gint rygel_media_db_get_child_count (RygelMediaDB* self, const char* container_id, GError** error) {
	gint result;
	GError * _inner_error_;
	sqlite3_stmt* statement;
	gint count;
	sqlite3_stmt* _tmp2_;
	gint _tmp1_;
	sqlite3_stmt* _tmp0_;
	gint rc;
	g_return_val_if_fail (self != NULL, 0);
	g_return_val_if_fail (container_id != NULL, 0);
	_inner_error_ = NULL;
	statement = NULL;
	count = 0;
	_tmp0_ = NULL;
	rc = (_tmp1_ = sqlite3_prepare_v2 (self->priv->db, RYGEL_MEDIA_DB_CHILDREN_COUNT_STRING, -1, &_tmp0_, NULL), statement = (_tmp2_ = _tmp0_, _sqlite3_finalize0 (statement), _tmp2_), _tmp1_);
	if (rc == SQLITE_OK) {
		if (sqlite3_bind_text (statement, 1, g_strdup (container_id), -1, g_free) != SQLITE_OK) {
			_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
					g_propagate_error (error, _inner_error_);
					_sqlite3_finalize0 (statement);
					return 0;
				} else {
					_sqlite3_finalize0 (statement);
					g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
					g_clear_error (&_inner_error_);
					return 0;
				}
			}
		}
		while (TRUE) {
			if (!((rc = sqlite3_step (statement)) == SQLITE_ROW)) {
				break;
			}
			count = sqlite3_column_int (statement, 0);
			break;
		}
	} else {
		g_warning ("rygel-media-db.vala:844: Could not get child count for object %s: %s", container_id, sqlite3_errmsg (self->priv->db));
		_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
				g_propagate_error (error, _inner_error_);
				_sqlite3_finalize0 (statement);
				return 0;
			} else {
				_sqlite3_finalize0 (statement);
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return 0;
			}
		}
	}
	result = count;
	_sqlite3_finalize0 (statement);
	return result;
}


gboolean rygel_media_db_exists (RygelMediaDB* self, const char* object_id, gint64* timestamp, GError** error) {
	gboolean result;
	GError * _inner_error_;
	sqlite3_stmt* statement;
	gboolean exists;
	sqlite3_stmt* _tmp2_;
	gint _tmp1_;
	sqlite3_stmt* _tmp0_;
	gint rc;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (object_id != NULL, FALSE);
	_inner_error_ = NULL;
	statement = NULL;
	exists = FALSE;
	_tmp0_ = NULL;
	rc = (_tmp1_ = sqlite3_prepare_v2 (self->priv->db, RYGEL_MEDIA_DB_OBJECT_EXISTS_STRING, -1, &_tmp0_, NULL), statement = (_tmp2_ = _tmp0_, _sqlite3_finalize0 (statement), _tmp2_), _tmp1_);
	if (rc == SQLITE_OK) {
		if (sqlite3_bind_text (statement, 1, g_strdup (object_id), -1, g_free) != SQLITE_OK) {
			_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
					g_propagate_error (error, _inner_error_);
					_sqlite3_finalize0 (statement);
					return FALSE;
				} else {
					_sqlite3_finalize0 (statement);
					g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
					g_clear_error (&_inner_error_);
					return FALSE;
				}
			}
		}
		while (TRUE) {
			if (!((rc = sqlite3_step (statement)) == SQLITE_ROW)) {
				break;
			}
			exists = sqlite3_column_int (statement, 0) == 1;
			(*timestamp) = sqlite3_column_int64 (statement, 1);
			break;
		}
	} else {
		g_warning ("rygel-media-db.vala:872: Could not get child count for object %s: %s", object_id, sqlite3_errmsg (self->priv->db));
		_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
				g_propagate_error (error, _inner_error_);
				_sqlite3_finalize0 (statement);
				return FALSE;
			} else {
				_sqlite3_finalize0 (statement);
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return FALSE;
			}
		}
	}
	result = exists;
	_sqlite3_finalize0 (statement);
	return result;
}


GeeArrayList* rygel_media_db_get_children (RygelMediaDB* self, const char* container_id, glong offset, glong max_count) {
	GeeArrayList* result;
	GError * _inner_error_;
	sqlite3_stmt* statement;
	GeeArrayList* children;
	sqlite3_stmt* _tmp2_;
	gint _tmp1_;
	sqlite3_stmt* _tmp0_;
	gint rc;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (container_id != NULL, NULL);
	_inner_error_ = NULL;
	statement = NULL;
	children = gee_array_list_new (RYGEL_TYPE_MEDIA_OBJECT, (GBoxedCopyFunc) g_object_ref, g_object_unref, g_direct_equal);
	_tmp0_ = NULL;
	rc = (_tmp1_ = sqlite3_prepare_v2 (self->priv->db, RYGEL_MEDIA_DB_GET_CHILDREN_STRING, -1, &_tmp0_, NULL), statement = (_tmp2_ = _tmp0_, _sqlite3_finalize0 (statement), _tmp2_), _tmp1_);
	if (rc == SQLITE_OK) {
		gboolean _tmp3_;
		gboolean _tmp4_;
		_tmp3_ = FALSE;
		_tmp4_ = FALSE;
		if (sqlite3_bind_text (statement, 1, g_strdup (container_id), -1, g_free) != SQLITE_OK) {
			_tmp4_ = TRUE;
		} else {
			_tmp4_ = sqlite3_bind_int64 (statement, 2, (gint64) offset) != SQLITE_OK;
		}
		if (_tmp4_) {
			_tmp3_ = TRUE;
		} else {
			_tmp3_ = sqlite3_bind_int64 (statement, 3, (gint64) max_count) != SQLITE_OK;
		}
		if (_tmp3_) {
			_inner_error_ = g_error_new_literal (RYGEL_MEDIA_DB_ERROR, RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
			if (_inner_error_ != NULL) {
				_sqlite3_finalize0 (statement);
				_g_object_unref0 (children);
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return NULL;
			}
		}
		while (TRUE) {
			char* child_id;
			if (!((rc = sqlite3_step (statement)) == SQLITE_ROW)) {
				break;
			}
			child_id = g_strdup (sqlite3_column_text (statement, 17));
			{
				RygelMediaObject* parent;
				RygelMediaObject* _tmp5_;
				RygelMediaObject* _tmp6_;
				RygelMediaContainer* _tmp9_;
				RygelMediaContainer* *_tmp8_;
				RygelMediaObject* _tmp7_;
				parent = rygel_media_db_get_object (self, sqlite3_column_text (statement, 18), &_inner_error_);
				if (_inner_error_ != NULL) {
					if (_inner_error_->domain == RYGEL_MEDIA_DB_ERROR) {
						goto __catch38_rygel_media_db_error;
					}
					goto __finally38;
				}
				gee_abstract_collection_add ((GeeAbstractCollection*) children, _tmp5_ = rygel_media_db_get_object_from_statement (self, RYGEL_MEDIA_CONTAINER (parent), child_id, statement));
				_g_object_unref0 (_tmp5_);
				(_tmp6_ = (RygelMediaObject*) gee_abstract_list_get ((GeeAbstractList*) children, gee_collection_get_size ((GeeCollection*) children) - 1))->parent = RYGEL_MEDIA_CONTAINER (parent);
				_g_object_unref0 (_tmp6_);
				_tmp8_ = &(_tmp7_ = (RygelMediaObject*) gee_abstract_list_get ((GeeAbstractList*) children, gee_collection_get_size ((GeeCollection*) children) - 1))->parent_ref;
				(*_tmp8_) = (_tmp9_ = _g_object_ref0 (RYGEL_MEDIA_CONTAINER (parent)), _g_object_unref0 ((*_tmp8_)), _tmp9_);
				_g_object_unref0 (_tmp7_);
				_g_object_unref0 (parent);
			}
			goto __finally38;
			__catch38_rygel_media_db_error:
			{
				GError * err;
				err = _inner_error_;
				_inner_error_ = NULL;
				{
					g_warning ("rygel-media-db.vala:907: Could not get parent object: %s", err->message);
					_g_error_free0 (err);
				}
			}
			__finally38:
			if (_inner_error_ != NULL) {
				_g_free0 (child_id);
				_sqlite3_finalize0 (statement);
				_g_object_unref0 (children);
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return NULL;
			}
			_g_free0 (child_id);
		}
	}
	result = children;
	_sqlite3_finalize0 (statement);
	return result;
}


static void rygel_media_db_class_init (RygelMediaDBClass * klass) {
	rygel_media_db_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelMediaDBPrivate));
	G_OBJECT_CLASS (klass)->finalize = rygel_media_db_finalize;
	g_signal_new ("object_added", RYGEL_TYPE_MEDIA_DB, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__STRING, G_TYPE_NONE, 1, G_TYPE_STRING);
	g_signal_new ("object_removed", RYGEL_TYPE_MEDIA_DB, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__STRING, G_TYPE_NONE, 1, G_TYPE_STRING);
	g_signal_new ("object_updated", RYGEL_TYPE_MEDIA_DB, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__STRING, G_TYPE_NONE, 1, G_TYPE_STRING);
	g_signal_new ("item_removed", RYGEL_TYPE_MEDIA_DB, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__STRING, G_TYPE_NONE, 1, G_TYPE_STRING);
	g_signal_new ("item_added", RYGEL_TYPE_MEDIA_DB, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__STRING, G_TYPE_NONE, 1, G_TYPE_STRING);
	g_signal_new ("item_updated", RYGEL_TYPE_MEDIA_DB, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__STRING, G_TYPE_NONE, 1, G_TYPE_STRING);
	g_signal_new ("container_added", RYGEL_TYPE_MEDIA_DB, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__STRING, G_TYPE_NONE, 1, G_TYPE_STRING);
	g_signal_new ("container_removed", RYGEL_TYPE_MEDIA_DB, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__STRING, G_TYPE_NONE, 1, G_TYPE_STRING);
	g_signal_new ("container_updated", RYGEL_TYPE_MEDIA_DB, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__STRING, G_TYPE_NONE, 1, G_TYPE_STRING);
}


static void rygel_media_db_instance_init (RygelMediaDB * self) {
	self->priv = RYGEL_MEDIA_DB_GET_PRIVATE (self);
}


static void rygel_media_db_finalize (GObject* obj) {
	RygelMediaDB * self;
	self = RYGEL_MEDIA_DB (obj);
	_sqlite3_close0 (self->priv->db);
	_g_object_unref0 (self->priv->factory);
	G_OBJECT_CLASS (rygel_media_db_parent_class)->finalize (obj);
}


GType rygel_media_db_get_type (void) {
	static GType rygel_media_db_type_id = 0;
	if (rygel_media_db_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediaDBClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_media_db_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediaDB), 0, (GInstanceInitFunc) rygel_media_db_instance_init, NULL };
		rygel_media_db_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelMediaDB", &g_define_type_info, 0);
	}
	return rygel_media_db_type_id;
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



