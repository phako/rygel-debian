/*
 * Copyright (C) 2010 Jens Georg <mail@jensge.org>.
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

internal errordomain MediaArtStoreError {
    NO_DIR,
    NO_MEDIA_ART
}

public class Rygel.MediaArtStore : GLib.Object {
    private const string PLACEHOLDER_HASH = "7215ee9c7d9dc229d2921a40e899ec5f";
    private const string invalid_chars = "()[]<>{}_!@#$^&*+=|\\/\"'?~";
    private const string convert_chars = "\t";
    private const string block_pattern = "%s[^%s]*%s";
    private const string[] blocks = { "()", "{}", "[]", "<>" };
    private static MediaArtStore media_art_store;
    private static bool first_time = true;
    private Regex char_remove_regex;
    private Regex char_convert_regex;
    private Regex space_compress_regex;
    private Regex[] block_regexes;

    private string directory;

    public static MediaArtStore? get_default () {
        if (first_time) {
            try {
                media_art_store = new MediaArtStore ();
            } catch (MediaArtStoreError error) {
                warning ("No media art available: %s", error.message);
            }
        }

        first_time = false;

        return media_art_store;
    }

    public Thumbnail? find_media_art (MediaItem item,
                                      bool simple = false) throws Error {
        string[] types = { "track", "album", "artist", "podcast", "radio" };
        File file = null;

        foreach (var type in types) {
            file = this.get_media_art_file (type, item, simple);
            if (file.query_exists (null)) {
                break;
            } else {
                file = null;
            }
        }

        if (file == null) {
            return null;
        }

        var info = file.query_info (FILE_ATTRIBUTE_ACCESS_CAN_READ + "," +
                                    FILE_ATTRIBUTE_STANDARD_SIZE,
                                    FileQueryInfoFlags.NONE,
                                    null);
        if (!info.get_attribute_boolean (FILE_ATTRIBUTE_ACCESS_CAN_READ)) {
            return null;
        }

        var thumb = new AlbumArt ();
        thumb.uri = file.get_uri ();
        thumb.size = (long) info.get_size ();

        return thumb;
    }

    public Thumbnail? find_media_art_any (MediaItem item) throws Error {
        var thumb = this.find_media_art (item);
        if (thumb == null) {
            thumb = this.find_media_art (item, true);
        }

        return thumb;
    }

    public File get_media_art_file (string    type,
                                    MediaItem item,
                                    bool      simple = false) {
        string hash;
        string suffix;

        if (simple) {
            hash = this.get_simple_hash (type, item);
            suffix = "jpg";
        } else {
            hash = this.get_hash (type, item);
            suffix = "jpeg";
        }
        var file_path = "%s-%s.%s".printf (type, hash, suffix);

        var path = Path.build_filename (this.directory, file_path);

        return File.new_for_path (path);
    }

    private MediaArtStore () throws MediaArtStoreError {
        var dir = Path.build_filename (Environment.get_user_cache_dir (),
                                       "media-art");
        var file = File.new_for_path (dir);

        if (!file.query_exists (null)) {
            var message = "Failed to find media-art directory";

            throw new MediaArtStoreError.NO_DIR (message);
        }

        this.directory = dir;
        try {
            var regex_string = Regex.escape_string (invalid_chars);
            char_remove_regex = new Regex ("[%s]".printf (regex_string));
            regex_string = Regex.escape_string (convert_chars);
            char_convert_regex = new Regex ("[%s]".printf (regex_string));
            space_compress_regex = new Regex ("\\s+");
            block_regexes = new Regex[0];

            foreach (var block in blocks) {
                var block_re = block_pattern.printf (
                                  Regex.escape_string ("%C".printf (block[0])),
                                  Regex.escape_string ("%C".printf (block[1])),
                                  Regex.escape_string ("%C".printf (block[1])));
                block_regexes += new Regex (block_re);
            }
        } catch (RegexError error) {
            assert_not_reached ();
        }
    }

    private string get_simple_hash (string type, MediaItem item) {
        string hash;
        switch (type) {
            case "artist":
                case "radio":
                hash = this.normalize_and_hash (item.author);
                break;
            case "podcast":
                hash = this.normalize_and_hash (item.title);
                break;
            case "album":
                hash = this.normalize_and_hash (item.author + "\t" +
                                                item.album);
                break;
            case "track":
                hash = this.normalize_and_hash (item.author + "\t" +
                                                item.album + "\t" +
                                                item.title);
                break;
            default:
                assert_not_reached ();
        }

        return hash;
    }

    private string get_hash (string type, MediaItem item) {
        string b = null, c = null;
        switch (type) {
            case "track":
                b = this.normalize_and_hash (item.author, false) + "-" +
                    this.normalize_and_hash (item.album, false);
                c = this.normalize_and_hash (item.title, false);
                break;
            case "album":
            case "artist":
                b = this.normalize_and_hash (item.author, false);
                c = this.normalize_and_hash (item.album, false);
                break;
            case "radio":
            case "podcast":
                b = this.normalize_and_hash (item.title, false);
                c = PLACEHOLDER_HASH;
                break;
        }

        return "%s-%s".printf (b, c);
    }

    private string normalize_and_hash (string? input, bool utf8_only = true) {
        string normalized = " ";
        if (input != null && input != "") {
            if (utf8_only) {
                normalized = input;
            } else {
                normalized = this.strip_invalid_entities (input);
                normalized = normalized.down ();
            }
            normalized = normalized.normalize (-1, NormalizeMode.ALL);
        }

        return Checksum.compute_for_string (ChecksumType.MD5, normalized);
    }

    string strip_invalid_entities (string original) {
        string p;

        p = original;

        try {
            foreach (var re in block_regexes) {
                p = re.replace_literal (p, -1, 0, "");
            }

            p = char_remove_regex.replace (p, -1, 0, "");
            p = char_convert_regex.replace (p, -1, 0, " ");
            p = space_compress_regex.replace (p, -1, 0, " ");

            return p;
        } catch (RegexError error) {
            assert_not_reached ();
        }
    }
}
