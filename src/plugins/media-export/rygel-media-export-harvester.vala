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

using GLib;
using Gee;

public class Rygel.MediaExport.Harvester : GLib.Object {
    private MetadataExtractor extractor;
    private MediaCache media_db;
    private GLib.Queue<MediaContainer> containers;
    private Gee.Queue<File> files;
    private File origin;
    private MediaContainer parent;
    private RecursiveFileMonitor monitor;
    private Regex file_filter;
    public Cancellable cancellable;
    private string flag;
    private const string HARVESTER_ATTRIBUTES =
                                        FILE_ATTRIBUTE_STANDARD_NAME + "," +
                                        FILE_ATTRIBUTE_STANDARD_TYPE + "," +
                                        FILE_ATTRIBUTE_TIME_MODIFIED + "," +
                                        FILE_ATTRIBUTE_STANDARD_SIZE;


    public Harvester (MediaContainer       parent,
                      MediaCache           media_db,
                      MetadataExtractor    extractor,
                      RecursiveFileMonitor monitor,
                      string?              flag = null) {
        this.parent = parent;
        this.extractor = extractor;
        this.media_db = media_db;
        this.extractor.extraction_done.connect (on_extracted_cb);
        this.extractor.error.connect (on_extractor_error_cb);
        this.files = new LinkedList<File> ();
        this.containers = new GLib.Queue<MediaContainer> ();
        this.origin = null;
        this.monitor = monitor;
        this.cancellable = new Cancellable ();
        this.flag = flag;
        var config = MetaConfig.get_default ();

        try {
            var extensions = config.get_string_list ("MediaExport",
                                                     "include-filter");

            // never trust user input
            string[] escaped_extensions = new string[0];
            foreach (var extension in extensions) {
                escaped_extensions += Regex.escape_string (extension);
            }

            var list = string.joinv ("|", escaped_extensions);
            file_filter = new Regex ("(%s)$".printf (list),
                                     RegexCompileFlags.CASELESS |
                                     RegexCompileFlags.OPTIMIZE);
        } catch (Error error) {
            file_filter = null;
        }
    }

    private bool push_if_changed_or_unknown (File       file,
                                             FileInfo   info,
                                             out string id) {
        id = Checksum.compute_for_string (ChecksumType.MD5, file.get_uri ());
        int64 timestamp;
        try {
            if (this.media_db.exists (id, out timestamp)) {
                int64 mtime = (int64) info.get_attribute_uint64 (
                                        FILE_ATTRIBUTE_TIME_MODIFIED);

                if (mtime > timestamp) {
                    this.files.offer (file);

                    return true;
                } else {
                    // check size
                    var size = info.get_size ();
                    var item = media_db.get_item (id);
                    if (item.size != size) {
                        this.files.offer (file);

                        return true;
                    }
                }
            } else {
                this.files.offer (file);

                return true;
            }
        } catch (Error error) {
            warning (_("Failed to query database: %s"), error.message);
        }

        return false;
    }

    private bool process_children (GLib.List<FileInfo>? list) {
        if (list == null || this.cancellable.is_cancelled ()) {
            return false;
        }

        foreach (var info in list) {
            if (info.get_name ()[0] == '.') {
                continue;
            }
            var parent_container =
                (DummyContainer) this.containers.peek_head ();

            var dir = parent_container.file;
            var file = dir.get_child (info.get_name ());
            if (info.get_file_type () == FileType.DIRECTORY) {
                monitor.monitor (file);
                var container = new DummyContainer (file,
                                                    parent_container);
                this.containers.push_tail (container);
                parent_container.seen (container.id);
                try {
                    int64 timestamp;
                    if (!this.media_db.exists (container.id,
                                               out timestamp)) {
                        this.media_db.save_container (container);
                    }
                } catch (Error err) {
                    warning (_("Failed to update database: %s"), err.message);
                }
            } else {
                string id;

                // Let's see if the file is wanted
                if (file_filter != null &&
                    !file_filter.match (file.get_uri ())) {
                    continue;
                }

                push_if_changed_or_unknown (file, info, out id);
                parent_container.seen (id);
            }
        }

        return true;
    }

    private async void enumerate_directory (File directory) {
        try {
            var enumerator = yield directory.enumerate_children_async (
                                        HARVESTER_ATTRIBUTES,
                                        FileQueryInfoFlags.NONE,
                                        Priority.DEFAULT,
                                        this.cancellable);

            GLib.List<FileInfo> list = null;
            do {
                list = yield enumerator.next_files_async (256,
                                                          Priority.DEFAULT,
                                                          this.cancellable);
            } while (process_children (list));

            yield enumerator.close_async (Priority.DEFAULT, this.cancellable);
        } catch (Error err) {
            warning (_("failed to enumerate folder: %s"), err.message);
        }

        cleanup_database (this.containers.peek_head () as DummyContainer);
        this.do_update ();
    }

    void cleanup_database (DummyContainer container) {
        // delete all children which are not in filesystem anymore
        container = (DummyContainer) this.containers.peek_head ();
        try {
            var children = this.media_db.get_child_ids (container.id);

            foreach (var seen_id in container.seen_children) {
                children.remove (seen_id);
            }

            foreach (var child in children) {
                this.media_db.remove_by_id (child);
            }
        } catch (DatabaseError err) {
            warning (_("Failed to get children of container %s: %s"),
                     container.id,
                     err.message);
        }

    }

    private bool on_idle () {
        if (this.cancellable.is_cancelled ()) {
            return false;
        }

        if (this.files.size > 0) {
            var candidate = this.files.peek ();
            this.extractor.extract (candidate);
        } else if (this.containers.get_length () > 0) {
            var container = this.containers.peek_head () as DummyContainer;
            var directory = container.file;
            enumerate_directory (directory);
        } else {
            // nothing to do
            if (this.flag != null) {
                try {
                    this.media_db.flag_object (Item.get_id (this.origin),
                                               this.flag);
                } catch (Error error) {};
            }
            harvested (this.origin);
        }

        return false;
    }

    /**
     * Fired for every file passed to harvest.
     */
    public signal void harvested (File file);

    /**
     * Extract all metainformation from a given file.
     *
     * What action will be taken depends on the arguments
     * * file is a simple file. Then only information of this
     *   file will be extracted
     * * file is a directory and recursive is false. The children
     *   of the directory (if not directories themselves) will be
     *   enqueued for extraction
     * * file is a directory and recursive is true. ++ All ++ children
     *   of the directory will be enqueued for extraction, even directories
     *
     * No matter how many children are contained within file's hierarchy,
     * only one event is sent when all the children are done.
     */
    public async void harvest (File file) {
        try {
            this.cancellable.reset ();
            var info = yield file.query_info_async (
                                        HARVESTER_ATTRIBUTES,
                                        FileQueryInfoFlags.NONE,
                                        Priority.DEFAULT,
                                        this.cancellable);

            if (info.get_file_type () == FileType.DIRECTORY) {
                this.origin = file;
                monitor.monitor (file);
                var container = new DummyContainer (file, this.parent);
                this.containers.push_tail (container);

                int64 timestamp;
                if (!this.media_db.exists (container.id, out timestamp)) {
                    this.media_db.save_container (container);
                }

                Idle.add (this.on_idle);
            } else {
                string id;
                if (push_if_changed_or_unknown (file, info, out id)) {
                    Idle.add (this.on_idle);
                    this.origin = file;
                    this.containers.push_tail (this.parent);
                } else {
                    // 'Harvesting' here means extraction of metadata (title,
                    // codec, bitrate etc) from media files.
                    debug (_("File %s does not need harvesting"),
                           file.get_uri ());
                    harvested (file);
                }
            }

        } catch (Error err) {
            warning (_("Failed to harvest file %s: %s"),
                     file.get_uri (),
                     err.message);
            harvested (file);
        }
    }

    private void on_extracted_cb (File                   file,
                                  GUPnP.DLNAInformation? dlna,
                                  string                 mime,
                                  uint64                 size,
                                  uint64                 mtime) {
        if (this.cancellable.is_cancelled ()) {
            harvested (this.origin);
        }

        var entry = this.files.peek ();
        if (entry == null) {
            // this event may be triggered by another instance
            // just ignore it
           return;
        }
        if (file == entry) {
            MediaItem item;
            if (dlna == null) {
                item = new Item.simple (this.containers.peek_head (),
                                        file,
                                        mime,
                                        size,
                                        mtime);
            } else {
                item = Item.create_from_info (this.containers.peek_head (),
                                              file,
                                              dlna,
                                              mime,
                                              size,
                                              mtime);
            }

            if (item != null) {
                item.parent_ref = this.containers.peek_head ();
                try {
                    this.media_db.save_item (item);
                } catch (Error error) {
                    // Ignore it for now
                }
            }

            this.files.poll ();
            this.do_update ();
        }
    }

    private void on_extractor_error_cb (File file, Error error) {
        var entry = this.files.peek ();
        if (entry == null) {
            // this event may be triggered by another instance
            // just ignore it
            return;
        }

        if (file == entry) {
            this.files.poll ();
            this.do_update ();
        }
    }

    /**
     * If all files of a container were processed, notify the container
     * about this and set the updating signal.
     * Reschedule the iteration and extraction
     */
    private void do_update () {
        if (this.files.size == 0 &&
            this.containers.get_length () != 0) {
            this.containers.peek_head ().updated ();
            this.containers.pop_head ();
        }

        Idle.add (this.on_idle);
    }
}
