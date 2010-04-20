/*
 * Copyright (C) 2009 Jens Georg <mail@jensge.org>.
 *
 * Author: Jens Georg <mail@jensge.org>
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


using Gee;
using GUPnP;
using Sqlite;

public errordomain Rygel.MediaDBError {
    SQLITE_ERROR,
    GENERAL_ERROR,
    INVALID_TYPE,
    UNSUPPORTED
}

public enum Rygel.MediaDBObjectType {
    CONTAINER,
    ITEM
}

/**
 * Persistent storage of media objects
 *
 * MediaDB is a sqlite3 backed persistent storage of media objects
 */
public class Rygel.MediaDB : Object {
    private Rygel.Database db;
    private MediaDBObjectFactory factory;
    private const string schema_version = "5";
    private const string CREATE_META_DATA_TABLE_STRING =
    "CREATE TABLE meta_data (size INTEGER NOT NULL, " +
                            "mime_type TEXT NOT NULL, " +
                            "duration INTEGER, " +
                            "width INTEGER, " +
                            "height INTEGER, " +
                            "class TEXT NOT NULL, " +
                            "author TEXT, " +
                            "album TEXT, " +
                            "date TEXT, " +
                            "bitrate INTEGER, " +
                            "sample_freq INTEGER, " +
                            "bits_per_sample INTEGER, " +
                            "channels INTEGER, " +
                            "track INTEGER, " +
                            "color_depth INTEGER, " +
                            "object_fk TEXT UNIQUE CONSTRAINT " +
                                "object_fk_id REFERENCES Object(upnp_id) " +
                                    "ON DELETE CASCADE);";

    private const string SCHEMA_STRING =
    "CREATE TABLE schema_info (version TEXT NOT NULL); " +
    "CREATE TABLE object_type (id INTEGER PRIMARY KEY, " +
                              "desc TEXT NOT NULL);" +
    CREATE_META_DATA_TABLE_STRING +
    "CREATE TABLE object (parent TEXT CONSTRAINT parent_fk_id " +
                                "REFERENCES Object(upnp_id), " +
                          "upnp_id TEXT PRIMARY KEY, " +
                          "type_fk INTEGER CONSTRAINT type_fk_id " +
                                "REFERENCES Object_Type(id), " +
                          "title TEXT NOT NULL, " +
                          "timestamp INTEGER NOT NULL);" +
    "CREATE TABLE uri (object_fk TEXT " +
                        "CONSTRAINT object_fk_id REFERENCES Object(upnp_id) "+
                            "ON DELETE CASCADE, " +
                      "uri TEXT NOT NULL);" +
    "INSERT INTO object_type (id, desc) VALUES (0, 'Container'); " +
    "INSERT INTO object_type (id, desc) VALUES (1, 'Item'); " +
    "INSERT INTO schema_info (version) VALUES ('" + MediaDB.schema_version +
                                                "'); ";

    private const string CREATE_CLOSURE_TABLE =
    "CREATE TABLE closure (ancestor TEXT, descendant TEXT, depth INTEGER)";

    private const string CREATE_CLOSURE_TRIGGER_STRING =
    "CREATE TRIGGER trgr_update_closure " +
    "AFTER INSERT ON Object " +
    "FOR EACH ROW BEGIN " +
        "INSERT INTO Closure (ancestor, descendant, depth) " +
            "VALUES (NEW.upnp_id, NEW.upnp_id, 0); " +
        "INSERT INTO Closure (ancestor, descendant, depth) " +
            "SELECT ancestor, NEW.upnp_id, depth + 1 FROM Closure " +
                "WHERE descendant = NEW.parent;" +
    "END;" +

    "CREATE TRIGGER trgr_delete_closure " +
    "AFTER DELETE ON Object " +
    "FOR EACH ROW BEGIN " +
        "DELETE FROM Closure WHERE descendant = OLD.upnp_id;" +
    "END;";

    // these triggers emulate ON DELETE CASCADE
    private const string CREATE_TRIGGER_STRING =
    "CREATE TRIGGER trgr_delete_metadata " +
    "BEFORE DELETE ON Object " +
    "FOR EACH ROW BEGIN " +
        "DELETE FROM meta_data WHERE meta_data.object_fk = OLD.upnp_id; "+
    "END;" +

    "CREATE TRIGGER trgr_delete_uris " +
    "BEFORE DELETE ON Object " +
    "FOR EACH ROW BEGIN " +
        "DELETE FROM Uri WHERE Uri.object_fk = OLD.upnp_id;" +
    "END;";

    private const string CREATE_INDICES_STRING =
    "CREATE INDEX idx_parent on Object(parent);" +
    "CREATE INDEX idx_uri_fk on Uri(object_fk);" +
    "CREATE INDEX idx_meta_data_fk on meta_data(object_fk);" +
    "CREATE INDEX idx_closure on Closure(descendant,depth);";

    private const string SAVE_META_DATA_STRING =
    "INSERT OR REPLACE INTO meta_data " +
        "(size, mime_type, width, height, class, " +
         "author, album, date, bitrate, " +
         "sample_freq, bits_per_sample, channels, " +
         "track, color_depth, duration, object_fk) VALUES " +
         "(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";

    private const string INSERT_OBJECT_STRING =
    "INSERT INTO Object (upnp_id, title, type_fk, parent, timestamp) " +
        "VALUES (?,?,?,?,?)";

    private const string UPDATE_OBJECT_STRING =
    "UPDATE Object SET title = ?, timestamp = ? WHERE upnp_id = ?";

    private const string INSERT_URI_STRING =
    "INSERT INTO Uri (object_fk, uri) VALUES (?,?)";

    private const string DELETE_URI_STRING =
    "DELETE FROM Uri WHERE object_fk = ?";

    private const string DELETE_BY_ID_STRING =
    "DELETE FROM Object WHERE upnp_id IN " +
        "(SELECT descendant FROM closure WHERE ancestor = ?)";

    private const string GET_OBJECT_WITH_PATH =
    "SELECT o.type_fk, o.title, m.size, m.mime_type, m.width, m.height, " +
            "m.class, m.author, m.album, m.date, m.bitrate, m.sample_freq, " +
            "m.bits_per_sample, m.channels, m.track, m.color_depth, " +
            "m.duration, o.parent, o.upnp_id " +
    "FROM Object o " +
        "JOIN Closure c ON (o.upnp_id = c.ancestor) " +
        "LEFT OUTER JOIN meta_data m ON (o.upnp_id = m.object_fk) " +
            "WHERE c.descendant = ? ORDER BY c.depth DESC";

    /**
     * This is the database query used to retrieve the children for a
     * given object.
     *
     * Sorting is as follows:
     *   - by type: containers first, then items if both are present
     *   - by upnp_class: items are sorted according to their class
     *   - by track: sorted by track
     *   - and after that alphabetically
     */
    private const string GET_CHILDREN_STRING =
    "SELECT o.type_fk, o.title, m.size, m.mime_type, " +
            "m.width, m.height, m.class, m.author, m.album, " +
            "m.date, m.bitrate, m.sample_freq, m.bits_per_sample, " +
            "m.channels, m.track, m.color_depth, m.duration, " +
            "o.upnp_id, o.parent, o.timestamp " +
    "FROM Object o LEFT OUTER JOIN meta_data m " +
        "ON o.upnp_id = m.object_fk " +
    "WHERE o.parent = ? " +
        "ORDER BY o.type_fk ASC, " +
                 "m.class ASC, " +
                 "m.track ASC, " +
                 "o.title ASC " +
    "LIMIT ?,?";

    // The uris are joined in to be able to filter by "ref"
    private const string GET_OBJECTS_BY_FILTER_STRING =
    "SELECT DISTINCT o.type_fk, o.title, m.size, m.mime_type, " +
            "m.width, m.height, m.class, m.author, m.album, " +
            "m.date, m.bitrate, m.sample_freq, m.bits_per_sample, " +
            "m.channels, m.track, m.color_depth, m.duration, " +
            "o.upnp_id, o.parent, o.timestamp " +
    "FROM Object o " +
        "JOIN Closure c ON o.upnp_id = c.descendant AND c.ancestor = ? " +
        "LEFT OUTER JOIN meta_data m " +
            "ON o.upnp_id = m.object_fk " +
        "LEFT OUTER JOIN Uri u ON u.object_fk = o.upnp_id " +
    "WHERE %s " +
        "ORDER BY o.type_fk ASC, " +
                 "m.class ASC, " +
                 "m.track ASC, " +
                 "o.title ASC " +
    "LIMIT ?,?";


    private const string URI_GET_STRING =
    "SELECT uri FROM Uri WHERE Uri.object_fk = ?";

    private const string CHILDREN_COUNT_STRING =
    "SELECT COUNT(upnp_id) FROM Object WHERE Object.parent = ?";

    private const string OBJECT_EXISTS_STRING =
    "SELECT COUNT(upnp_id), timestamp FROM Object WHERE Object.upnp_id = ?";

    private const string GET_CHILD_ID_STRING =
    "SELECT upnp_id FROM OBJECT WHERE parent = ?";

    private const string UPDATE_V3_V4_STRING_2 =
    "UPDATE meta_data SET object_fk = " +
        "(SELECT upnp_id FROM Object WHERE metadata_fk = meta_data.id)";

    private const string UPDATE_V3_V4_STRING_3 =
    "ALTER TABLE Object ADD timestamp INTEGER";

    private const string UPDATE_V3_V4_STRING_4 =
    "UPDATE Object SET timestamp = 0";

    private const string GET_META_DATA_COLUMN_STRING =
    "SELECT DISTINCT %s FROM meta_data AS m %s " +
        "ORDER BY %s LIMIT ?,?";

    public signal void object_added (string object_id);
    public signal void object_removed (string object_id);
    public signal void object_updated (string object_id);

    public signal void item_removed (string item_id);
    public signal void item_added (string item_id);
    public signal void item_updated (string item_id);

    public signal void container_added (string container_id);
    public signal void container_removed (string container_id);
    public signal void container_updated (string container_id);

    public void remove_by_id (string id) throws DatabaseError {
        GLib.Value[] values = { id };
        this.db.exec (DELETE_BY_ID_STRING, values);
        object_removed (id);
    }

    public void remove_object (MediaObject object) throws DatabaseError,
                                                          MediaDBError {
        this.remove_by_id (object.id);

        if (object is MediaItem) {
            item_removed (object.id);
        } else if (object is MediaContainer) {
            container_removed (object.id);
        } else {
            throw new MediaDBError.INVALID_TYPE ("Invalid object type");
        }
    }

    public void save_container (MediaContainer container) throws Error {
        try {
            db.begin ();
            create_object (container);
            save_uris (container);
            db.commit ();
            object_added (container.id);
            container_added (container.id);
        } catch (DatabaseError error) {
            db.rollback ();

            throw error;
        }
    }

    public void save_item (MediaItem item) throws Error {
        try {
            db.begin ();
            save_metadata (item);
            create_object (item);
            save_uris (item);
            db.commit ();
            object_added (item.id);
            item_added (item.id);
        } catch (DatabaseError error) {
            warning ("Failed to add item with id %s: %s",
                     item.id,
                     error.message);
            db.rollback ();

            throw error;
        }
    }

    public void update_object (MediaObject object) throws Error {
        try {
            db.begin ();
            remove_uris (object);
            if (object is MediaItem) {
                save_metadata (object as MediaItem);
            }
            update_object_internal (object);
            save_uris (object);
            db.commit ();
            object_updated (object.id);
            if (object is MediaItem) {
                item_updated (object.id);
            } else if (object is MediaContainer) {
                container_updated (object.id);
            }
        } catch (Error error) {
            warning ("Failed to add item with id %s: %s",
                     object.id,
                     error.message);
            db.rollback ();

            throw error;
        }
    }

    public MediaObject? get_object (string object_id) throws DatabaseError {
        GLib.Value[] values = { object_id };
        MediaObject parent = null;

        Rygel.Database.RowCallback cb = (statement) => {
            var parent_container = parent as MediaContainer;
            var object = get_object_from_statement (parent_container,
                                                    statement.column_text (18),
                                                    statement);
            object.parent_ref = parent_container;
            parent = object;

            return true;
        };

        this.db.exec (GET_OBJECT_WITH_PATH, values, cb);

        return parent;
    }

    public MediaItem? get_item (string item_id)
                                throws DatabaseError, MediaDBError {
        var object = get_object (item_id);
        if (object != null && !(object is MediaItem)) {
            throw new MediaDBError.INVALID_TYPE ("Object with id %s is not a" +
                                                 "MediaItem",
                                                 item_id);
        }

        return object as MediaItem;
    }

    public MediaContainer? get_container (string container_id)
                                          throws DatabaseError, MediaDBError {
        var object = get_object (container_id);
        if (object != null && !(object is MediaContainer)) {
            throw new MediaDBError.INVALID_TYPE ("Object with id %s is not a" +
                                                 "MediaContainer",
                                                 container_id);
        }

        return object as MediaContainer;
    }

    public int get_child_count (string container_id) throws DatabaseError {
        int count = 0;
        GLib.Value[] values = { container_id };

        this.db.exec (CHILDREN_COUNT_STRING,
                      values,
                      (statement) => {
                          count = statement.column_int (0);

                          return false;
                      });

        return count;
    }

    public bool exists (string    object_id,
                        out int64 timestamp) throws DatabaseError {
        bool exists = false;
        GLib.Value[] values = { object_id };
        int64 tmp_timestamp = 0;

        this.db.exec (OBJECT_EXISTS_STRING,
                      values,
                      (statement) => {
                          exists = statement.column_int (0) == 1;
                          tmp_timestamp = statement.column_int64 (1);

                          return false;
                      });

        // out parameters are not allowed to be captured
        timestamp = tmp_timestamp;

        return exists;
    }

    public Gee.ArrayList<MediaObject> get_children (string container_id,
                                                    long   offset,
                                                    long   max_count)
                                                    throws Error {
        ArrayList<MediaObject> children = new ArrayList<MediaObject> ();
        var parent = get_object (container_id) as MediaContainer;

        GLib.Value[] values = { container_id,
                                (int64) offset,
                                (int64) max_count };
        Rygel.Database.RowCallback callback = (statement) => {
            var child_id = statement.column_text (17);
            children.add (get_object_from_statement (parent,
                                                     child_id,
                                                     statement));
            children.last() .parent_ref = parent;

            return true;
        };

        this.db.exec (GET_CHILDREN_STRING, values, callback);

        return children;
    }

    private uint modify_limit (uint max_count) {
        if (max_count == 0) {
            return -1;
        } else {
            return max_count;
        }
    }

    public Gee.List<MediaObject> get_objects_by_search_expression (
                                        SearchExpression? expression,
                                        string            container_id,
                                        uint              offset,
                                        uint              max_count)
                                        throws Error {
        var args = new GLib.ValueArray (0);
        var filter = this.search_expression_to_sql (expression, args);

        if (filter == null) {
            return new Gee.ArrayList<MediaObject> ();
        }

        debug ("Orignal search: %s", expression.to_string ());
        debug ("Parsed search expression: %s", filter);

        for (int i = 0; i < args.n_values; i++) {
            debug ("Arg %d: %s", i, args.get_nth (i).get_string ());
        }

        var max_objects = modify_limit (max_count);

        return this.get_objects_by_filter (filter,
                                           args,
                                           container_id,
                                           offset,
                                           max_objects);
    }

    public Gee.ArrayList<MediaObject> get_objects_by_filter (
                                        string          filter,
                                        GLib.ValueArray args,
                                        string          container_id,
                                        long            offset,
                                        long            max_count)
                                        throws Error {
        ArrayList<MediaObject> children = new ArrayList<MediaObject> ();
        GLib.Value v = container_id;
        args.prepend (v);
        v = offset;
        args.append (v);
        v = max_count;
        args.append (v);

        debug ("Parameters to bind: %u", args.n_values);

        Rygel.Database.RowCallback callback = (statement) => {
            var child_id = statement.column_text (17);
            var parent_id = statement.column_text (18);
            try {
                var parent = get_object (parent_id) as MediaContainer;
                if (parent != null) {
                    children.add (get_object_from_statement (parent,
                                                             child_id,
                                                             statement));
                    children.last ().parent_ref = parent;
                } else {
                    warning ("Inconsistent database: item %s " +
                             "has no parent %s",
                             child_id,
                             parent_id);
                }

                return true;
            } catch (DatabaseError error) {
                warning ("Failed to get parent item: %s", error.message);

                return false;
            }
        };

        this.db.exec (GET_OBJECTS_BY_FILTER_STRING.printf (filter),
                      args.values,
                      callback);

        return children;
    }

    public MediaDB (string name) throws Error {
        this.open_db (name);
        this.factory = new MediaDBObjectFactory ();
    }

    public MediaDB.with_factory (string               name,
                                 MediaDBObjectFactory factory) throws Error {
        this.open_db (name);
        this.factory = factory;
    }

    private void open_db (string name) throws Error {
        this.db = new Rygel.Database (name);
        int old_version = -1;

        try {
            this.db.exec ("SELECT version FROM schema_info",
                          null,
                          (statement) => {
                              old_version = statement.column_int (0);

                              return false;
                          });
            int current_version = schema_version.to_int ();
            if (old_version == current_version) {
                bool schema_ok = true;

                debug ("Media DB schema has current version");
                debug ("Checking for consistent schema...");
                db.exec ("SELECT count(*) FROM sqlite_master WHERE sql " +
                         "LIKE 'CREATE TABLE Meta_Data%object_fk TEXT " +
                         "UNIQUE%'",
                         null,
                         (statement) => {
                             schema_ok = statement.column_int (0) == 1;

                             return false;
                         });
                if (!schema_ok) {
                    try {
                        message ("Found faulty schema, forcing full reindex");
                        db.begin ();
                        db.exec ("DELETE FROM Object WHERE upnp_id IN (" +
                                 "SELECT DISTINCT object_fk FROM meta_data)");
                        db.exec ("DROP TABLE Meta_Data");
                        db.exec (CREATE_META_DATA_TABLE_STRING);
                        db.commit ();
                    } catch (Error error) {
                        db.rollback ();
                        warning ("Failed to force reindex to fix database: " +
                                 error.message);
                    }
                }
            } else {
                if (old_version < current_version) {
                    debug ("Older schema detected. Upgrading...");
                    switch (old_version) {
                        case 3:
                            update_v3_v4 ();
                            if (this.db != null) {
                                update_v4_v5 ();
                            }
                            break;
                        case 4:
                            update_v4_v5 ();
                            break;
                        default:
                            warning ("Cannot upgrade");
                            db = null;
                            break;
                    }
                } else {
                    warning ("The version \"%d\" of the detected database" +
                             " is newer than our supported version \"%d\"",
                             old_version,
                             current_version);
                    this.db = null;

                    throw new MediaDBError.GENERAL_ERROR ("Database format" +
                                                          " not supported");
                }
            }
        } catch (DatabaseError error) {
            debug ("Could not find schema version;" +
                   " checking for empty database...");
            try {
                int rows = -1;
                this.db.exec ("SELECT count(type) FROM sqlite_master " +
                              "WHERE rowid=1",
                              null,
                              (statement) => {
                                  rows = statement.column_int (0);

                                  return false;
                              });
                if (rows == 0) {
                    debug ("Empty database, creating new schema version %s",
                            schema_version);
                    if (!create_schema ()) {
                        this.db = null;

                        return;
                    }
                } else {
                    warning ("Incompatible schema... cannot proceed");
                    this.db = null;

                    return;
                }
            } catch (DatabaseError error) {
                warning ("Something weird going on: %s", error.message);
                this.db = null;

                throw new MediaDBError.GENERAL_ERROR ("Invalid database");
            }
        }
    }

    private void update_v3_v4 () {
        try {
            db.begin ();
            db.exec ("ALTER TABLE Meta_Data RENAME TO _Meta_Data");
            db.exec (CREATE_META_DATA_TABLE_STRING);
            db.exec ("INSERT INTO meta_data (size, mime_type, duration, " +
                     "width, height, class, author, album, date, " +
                     "bitrate, sample_freq, bits_per_sample, channels, " +
                     "track, color_depth, object_fk) SELECT size, " +
                     "mime_type, duration, width, height, class, author, " +
                     "album, date, bitrate, sample_freq, bits_per_sample, " +
                     "channels, track, color_depth, o.upnp_id FROM " +
                     "_Meta_Data JOIN object o ON id = o.metadata_fk");
            db.exec ("DROP TABLE _Meta_Data");
            db.exec (UPDATE_V3_V4_STRING_3);
            db.exec (UPDATE_V3_V4_STRING_4);
            db.exec (CREATE_TRIGGER_STRING);
            db.exec ("UPDATE schema_info SET version = '4'");
            db.commit ();
        } catch (DatabaseError error) {
            db.rollback ();
            warning ("Database upgrade failed: %s", error.message);
            db = null;
        }
    }

    private void update_v4_v5 () {
        Gee.Queue<string> queue = new LinkedList<string> ();
        try {
            db.begin ();
            db.exec ("DROP TRIGGER IF EXISTS trgr_delete_children");
            db.exec (CREATE_CLOSURE_TABLE);
            // this is to have the database generate the closure table
            db.exec ("ALTER TABLE Object RENAME TO _Object");
            db.exec ("CREATE TABLE Object AS SELECT * FROM _Object");
            db.exec ("DELETE FROM Object");
            db.exec (CREATE_CLOSURE_TRIGGER_STRING);
            db.exec ("INSERT INTO _Object (upnp_id, type_fk, title, " +
                     "timestamp) VALUES ('0', 0, 'Root', 0)");
            db.exec ("INSERT INTO Object (upnp_id, type_fk, title, " +
                     "timestamp) VALUES ('0', 0, 'Root', 0)");

            queue.offer ("0");
            while (!queue.is_empty) {
                GLib.Value[] args = { queue.poll () };
                db.exec ("SELECT upnp_id FROM _Object WHERE parent = ?",
                         args,
                         (statement) => {
                            queue.offer (statement.column_text (0));

                            return true;
                         });

                db.exec ("INSERT INTO Object SELECT * FROM _OBJECT " +
                         "WHERE parent = ?",
                         args);
            }
            db.exec ("DROP TABLE Object");
            db.exec ("ALTER TABLE _Object RENAME TO Object");
            // the triggers created above have been dropped automatically
            // so we need to recreate them
            db.exec (CREATE_CLOSURE_TRIGGER_STRING);
            db.exec (CREATE_INDICES_STRING);
            db.exec ("UPDATE schema_info SET version = '5'");
            db.commit ();
            db.exec ("VACUUM");
            db.analyze ();
        } catch (DatabaseError err) {
            db.rollback ();
            warning ("Database upgrade failed: %s", err.message);
            db = null;
        }
    }

    private void update_object_internal (MediaObject object) throws Error {
        GLib.Value[] values = { object.title,
                                (int64) object.modified,
                                object.id };
        this.db.exec (UPDATE_OBJECT_STRING, values);
    }

    private void remove_uris (MediaObject object) throws Error {
        GLib.Value[] values = { object.id };
        this.db.exec (DELETE_URI_STRING, values);
    }

    private void save_metadata (MediaItem item) throws Error {
        GLib.Value[] values = { item.size,
                                item.mime_type,
                                item.width,
                                item.height,
                                item.upnp_class,
                                item.author,
                                item.album,
                                item.date,
                                item.bitrate,
                                item.sample_freq,
                                item.bits_per_sample,
                                item.n_audio_channels,
                                item.track_number,
                                item.color_depth,
                                item.duration,
                                item.id };
        this.db.exec (SAVE_META_DATA_STRING, values);
    }

    private void create_object (MediaObject item) throws Error {
        int type = MediaDBObjectType.CONTAINER;
        GLib.Value parent;

        if (item is MediaItem) {
            type = MediaDBObjectType.ITEM;
        }

        if (item.parent == null) {
            parent = Database.@null ();
        } else {
            parent = item.parent.id;
        }

        GLib.Value[] values = { item.id,
                                item.title,
                                type,
                                parent,
                                (int64) item.modified };
        this.db.exec (INSERT_OBJECT_STRING, values);
    }

    private void save_uris (MediaObject object) throws Error {
        foreach (var uri in object.uris) {
            GLib.Value[] values = { object.id, uri };
            this.db.exec (INSERT_URI_STRING, values);
        }
    }

    /**
     * Create the current schema.
     *
     * If schema creation fails, schema will be rolled back
     * completely.
     *
     * @returns: true on success, false on failure
     */
    private bool create_schema () {
        try {
            db.begin ();
            db.exec (SCHEMA_STRING);
            db.exec (CREATE_TRIGGER_STRING);
            db.exec (CREATE_CLOSURE_TABLE);
            db.exec (CREATE_INDICES_STRING);
            db.exec (CREATE_CLOSURE_TRIGGER_STRING);
            db.commit ();
            db.analyze ();

            return true;
        } catch (Error err) {
            warning ("Failed to create schema: %s", err.message);
            db.rollback ();
        }

        return false;
   }

    private void add_uris (MediaObject object) throws DatabaseError {
        GLib.Value[] values = { object.id };
        this.db.exec (URI_GET_STRING,
                      values,
                      (statement) => {
                          if (object is MediaItem) {
                              var item = object as MediaItem;
                              item.add_uri (statement.column_text (0), null);
                          } else {
                              object.uris.add (statement.column_text (0));
                          }

                          return true;
                      });
    }

    private MediaObject? get_object_from_statement (MediaContainer? parent,
                                                    string          object_id,
                                                    Statement       statement) {
        MediaObject object = null;
        switch (statement.column_int (0)) {
            case 0:
                // this is a container
                object = factory.get_container (this,
                                                object_id,
                                                statement.column_text (1),
                                                0);
                break;
            case 1:
                // this is an item
                object = factory.get_item (this,
                                           parent,
                                           object_id,
                                           statement.column_text (1),
                                           statement.column_text (6));
                fill_item (statement, object as MediaItem);
                break;
            default:
                assert_not_reached ();
        }

        try {
            if (object != null) {
                object.modified = statement.column_int64 (18);
                add_uris (object);
            }
        } catch (DatabaseError error) {
            warning ("Failed to load uris from database: %s", error.message);
            object = null;
        }
        return object;
    }

    private void fill_item (Statement statement, MediaItem item) {
        item.author = statement.column_text (7);
        item.album = statement.column_text (8);
        item.date = statement.column_text (9);
        item.mime_type = statement.column_text (3);
        item.duration = (long) statement.column_int64 (16);

        item.size = (long) statement.column_int64 (2);
        item.bitrate = statement.column_int (10);

        item.sample_freq = statement.column_int (11);
        item.bits_per_sample = statement.column_int (12);
        item.n_audio_channels = statement.column_int (13);
        item.track_number = statement.column_int (14);

        item.width = statement.column_int (4);
        item.height = statement.column_int (5);
        item.color_depth = statement.column_int (15);
    }

    public ArrayList<string> get_child_ids (string container_id)
                                            throws DatabaseError {
        ArrayList<string> children = new ArrayList<string> (str_equal);
        GLib.Value[] values = { container_id  };

        this.db.exec (GET_CHILD_ID_STRING,
                      values,
                      (statement) => {
                          children.add (statement.column_text (0));

                          return true;
                      });

        return children;
    }

    private string? search_expression_to_sql (SearchExpression? expression,
                                             GLib.ValueArray   args)
                                             throws Error {
        if (expression == null) {
            return null;
        }

        if (expression is LogicalExpression) {
            return logical_expression_to_sql (expression as LogicalExpression,
                                              args);
        } else {
            return relational_expression_to_sql (
                                        expression as RelationalExpression,
                                        args);
        }
    }

    private string? logical_expression_to_sql (LogicalExpression? expression,
                                               GLib.ValueArray    args)
                                               throws Error {
        string left_sql_string = search_expression_to_sql (expression.operand1,
                                                           args);
        string right_sql_string = search_expression_to_sql (expression.operand2,
                                                            args);
        string operator_sql_string = "OR";

        if (expression.op == LogicalOperator.AND) {
            operator_sql_string = "AND";
        }

        return "(%s %s %s)".printf (left_sql_string,
                                    operator_sql_string,
                                    right_sql_string);
    }

    private string? map_operand_to_column (string operand) throws Error {
        string column = null;

        switch (operand) {
            case "res":
                column = "u.uri";
                break;
            case "@id":
                column = "o.upnp_id";
                break;
            case "@parentID":
                column = "o.parent";
                break;
            case "upnp:class":
                column = "m.class";
                break;
            case "dc:title":
                column = "o.title";
                break;
            case "upnp:artist":
            case "dc:creator":
                column = "m.author";
                break;
            case "dc:date":
                column = "m.date";
                break;
            case "upnp:album":
                column = "m.album";
                break;
            default:
                var message = "Unsupported column %s".printf (operand);

                throw new MediaDBError.UNSUPPORTED (message);
        }

        return column;
    }

    private string? relational_expression_to_sql (RelationalExpression? exp,
                                                  GLib.ValueArray       args)
                                                  throws Error {
        string sql_function = null;
        GLib.Value? v = null;

        string column = map_operand_to_column (exp.operand1);

        switch (exp.op) {
            case SearchCriteriaOp.EXISTS:
                if (exp.operand2 == "true") {
                    sql_function = "IS NOT NULL AND %s != ''";
                } else {
                    sql_function = "IS NULL OR %s = ''";
                }
                break;
            case SearchCriteriaOp.EQ:
                sql_function = "=";
                v = exp.operand2;
                break;
            case SearchCriteriaOp.NEQ:
                sql_function = "!=";
                v = exp.operand2;
                break;
            case SearchCriteriaOp.LESS:
                sql_function = "<";
                v = exp.operand2;
                break;
            case SearchCriteriaOp.LEQ:
                sql_function = "<=";
                v = exp.operand2;
                break;
            case SearchCriteriaOp.GREATER:
                sql_function = ">";
                v = exp.operand2;
                break;
            case SearchCriteriaOp.GEQ:
                sql_function = ">=";
                v = exp.operand2;
                break;
            case SearchCriteriaOp.CONTAINS:
                sql_function = "LIKE";
                v = "%%%s%%".printf (exp.operand2);
                break;
            case SearchCriteriaOp.DOES_NOT_CONTAIN:
                sql_function = "NOT LIKE";
                v = "%%%s%%".printf (exp.operand2);
                break;
            case SearchCriteriaOp.DERIVED_FROM:
                sql_function = "LIKE";
                v = "%s%%".printf (exp.operand2);
                break;
            default:
                warning ("Unsupported op %d", exp.op);
                break;
        }

        if (v != null) {
            args.append (v);
        }

        return "%s %s ?".printf (column, sql_function);
    }

    public Gee.List<string> get_meta_data_column_by_filter (
                                        string          column,
                                        string          filter,
                                        GLib.ValueArray args,
                                        long            offset,
                                        long            max_count)
                                        throws Error {
        GLib.Value v = offset;
        args.append (v);
        v = max_count;
        args.append (v);

        var data = new ArrayList<string> ();
        Rygel.Database.RowCallback callback = (statement) => {
            data.add (statement.column_text (0));

            return true;
        };

        var sql = GET_META_DATA_COLUMN_STRING.printf (column, filter, column);
        this.db.exec (sql, args.values, callback);

        return data;
    }

    public Gee.List<string> get_object_attribute_by_search_expression (
                                        string            attribute,
                                        SearchExpression? expression,
                                        long              offset,
                                        long              max_count)
                                        throws Error {
        var args = new ValueArray (0);
        var filter = this.search_expression_to_sql (expression, args);
        if (filter != null) {
            filter = " WHERE %s ".printf (filter);
        } else {
            filter = "";
        }

        debug ("Parsed filter: %s", filter);

        var column = this.map_operand_to_column (attribute);

        return this.get_meta_data_column_by_filter (column,
                                                    filter,
                                                    args,
                                                    offset,
                                                    max_count);
    }
}
