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

using GUPnP;
using Gee;
using Gst;

private errordomain Rygel.MediaItemError {
    BAD_URI
}

/**
 * Represents a media (Music, Video and Image) item.
 */
public class Rygel.MediaItem : MediaObject {
    public static const string IMAGE_CLASS = "object.item.imageItem";
    public static const string PHOTO_CLASS = "object.item.imageItem.photo";
    public static const string VIDEO_CLASS = "object.item.videoItem";
    public static const string AUDIO_CLASS = "object.item.audioItem";
    public static const string MUSIC_CLASS = "object.item.audioItem.musicTrack";

    public string author;
    public string album;
    public string date;

    // Resource info
    public string mime_type;
    public string dlna_profile;

    public long size = -1;       // Size in bytes
    public long duration = -1;   // Duration in seconds
    public int bitrate = -1;     // Bytes/second

    // Audio/Music
    public int sample_freq = -1;
    public int bits_per_sample = -1;
    public int n_audio_channels = -1;
    public int track_number = -1;

    // Image/Video
    public int width = -1;
    public int height = -1;
    public int pixel_width = -1;
    public int pixel_height = -1;
    public int color_depth = -1;

    public ArrayList<Thumbnail> thumbnails;
    public ArrayList<Subtitle> subtitles;

    internal bool place_holder = false;

    public MediaItem (string         id,
                      MediaContainer parent,
                      string         title,
                      string         upnp_class) {
        this.id = id;
        this.parent = parent;
        this.title = title;
        this.upnp_class = upnp_class;

        this.thumbnails = new ArrayList<Thumbnail> ();
        this.subtitles = new ArrayList<Subtitle> ();
    }

    // Live media items need to provide a nice working implementation of this
    // method if they can/do not provide a valid URI
    public virtual Element? create_stream_source () {
        dynamic Element src = null;

        if (this.uris.size != 0) {
            src = Element.make_from_uri (URIType.SRC, this.uris.get (0), null);
        }

        if (src != null) {
            if (src.get_class ().find_property ("blocksize") != null) {
                // The default is usually 4KiB which is not really big enough
                // for most cases so we set this to 65KiB.
                src.blocksize = (long) 65536;
            }

            if (src.get_class ().find_property ("tcp-timeout") != null) {
                // For rtspsrc since some RTSP sources takes a while to start
                // transmitting
                src.tcp_timeout = (int64) 60000000;
            }
        }

        return src;
    }

    // Return true if item should be streamed as a live response with
    // time based seeking, or false to serve directly with byte range
    // seeking.
    public virtual bool should_stream () {
        // Simple heuristic: if we know the size, serve directly.
        return this.size <= 0;
    }

    // Adds URI to MediaItem. You can either provide the associated thumbnail or
    // ask Rygel to try to fetch it for you by passing null as @thumbnail.
    public void add_uri (string uri, Thumbnail? thumbnail) {
        this.uris.add (uri);

        if (thumbnail != null) {
            this.thumbnails.add (thumbnail);
        } else if (this.upnp_class.has_prefix (MediaItem.IMAGE_CLASS) ||
                   this.upnp_class.has_prefix (MediaItem.VIDEO_CLASS)) {
            // Lets see if we can provide the thumbnails
            var thumbnailer = Thumbnailer.get_default ();

            if (thumbnailer == null) {
                return;
            }

            try {
                var thumb = thumbnailer.get_thumbnail (uri);
                this.thumbnails.add (thumb);
            } catch (Error err) {}
        }

        if (this.upnp_class.has_prefix (MediaItem.VIDEO_CLASS)) {
            var subtitle_manager = SubtitleManager.get_default ();

            if (subtitle_manager == null) {
                return;
            }

            try {
                var subtitle = subtitle_manager.get_subtitle (uri);
                this.subtitles.add (subtitle);
            } catch (Error err) {}
        }
    }

    public void lookup_album_art () {
        assert (this.upnp_class.has_prefix (MediaItem.AUDIO_CLASS) &&
                this.thumbnails.size == 0);

        var media_art_store = MediaArtStore.get_default ();
        if (media_art_store == null) {
            return;
        }

        try {
            var thumb = media_art_store.find_media_art_any (this);
            if (thumb != null) {
                this.thumbnails.insert (0, thumb);
            }
        } catch (Error err) {};
    }

    internal int compare_transcoders (void *a, void *b) {
        var transcoder1 = (Transcoder) a;
        var transcoder2 = (Transcoder) b;

        return (int) transcoder1.get_distance (this) -
               (int) transcoder2.get_distance (this);
    }

    internal void add_resources (DIDLLiteItem didl_item,
                                 bool         allow_internal)
                                 throws Error {
        foreach (var subtitle in this.subtitles) {
            var protocol = this.get_protocol_for_uri (subtitle.uri);

            if (allow_internal || protocol != "internal") {
                subtitle.add_didl_node (didl_item);
            }
        }

        foreach (var uri in this.uris) {
            var protocol = this.get_protocol_for_uri (uri);

            if (allow_internal || protocol != "internal") {
                this.add_resource (didl_item, uri, protocol);
            }
        }

        foreach (var thumbnail in this.thumbnails) {
            var protocol = this.get_protocol_for_uri (thumbnail.uri);

            if (allow_internal || protocol != "internal") {
                thumbnail.add_resource (didl_item, protocol);
            }
        }
    }

    internal DIDLLiteResource add_resource (DIDLLiteItem didl_item,
                                            string?      uri,
                                            string       protocol,
                                            string?      import_uri = null)
                                            throws Error {
        var res = didl_item.add_resource ();

        if (uri != null) {
            res.uri = uri;
        }

        if (import_uri != null) {
            res.import_uri = import_uri;
        }

        res.size = this.size;
        res.duration = this.duration;
        res.bitrate = this.bitrate;

        res.sample_freq = this.sample_freq;
        res.bits_per_sample = this.bits_per_sample;
        res.audio_channels = this.n_audio_channels;

        res.width = this.width;
        res.height = this.height;
        res.color_depth = this.color_depth;

        /* Protocol info */
        res.protocol_info = this.get_protocol_info (uri, protocol);

        return res;
    }

    internal override int compare_by_property (MediaObject media_object,
                                               string      property) {
        var item = media_object as MediaItem;

        switch (property) {
        case "dc:creator":
        case "dc:artist":
        case "dc:author":
            return this.compare_string_props (this.author, item.author);
        case "upnp:album":
            return this.compare_string_props (this.album, item.album);
        case "dc:date":
            return this.compare_by_date (item);
        default:
            return base.compare_by_property (item, property);
        }
    }

    private ProtocolInfo get_protocol_info (string? uri,
                                            string  protocol) {
        var protocol_info = new ProtocolInfo ();

        protocol_info.mime_type = this.mime_type;
        protocol_info.dlna_profile = this.dlna_profile;
        protocol_info.protocol = protocol;
        protocol_info.dlna_flags = DLNAFlags.DLNA_V15;

        if (this.upnp_class.has_prefix (MediaItem.IMAGE_CLASS)) {
            protocol_info.dlna_flags |= DLNAFlags.INTERACTIVE_TRANSFER_MODE;
        } else {
            protocol_info.dlna_flags |= DLNAFlags.STREAMING_TRANSFER_MODE;
        }

        if (!this.should_stream ()) {
            protocol_info.dlna_operation = DLNAOperation.RANGE;
            protocol_info.dlna_flags |= DLNAFlags.BACKGROUND_TRANSFER_MODE |
                                        DLNAFlags.CONNECTION_STALL;
        } else {
            protocol_info.dlna_flags |= DLNAFlags.SENDER_PACED;
        }

        return protocol_info;
    }

    private string get_protocol_for_uri (string uri) throws Error {
        var scheme = Uri.parse_scheme (uri);
        if (scheme == null) {
            throw new MediaItemError.BAD_URI (_("Bad URI: %s"), uri);
        }

        if (scheme == "http") {
            return "http-get";
        } else if (scheme == "file") {
            return "internal";
        } else if (scheme == "rtsp") {
            // FIXME: Assuming that RTSP is always accompanied with RTP over UDP
            return "rtsp-rtp-udp";
        } else {
            // Assume the protocol to be the scheme of the URI
            warning (_("Failed to probe protocol for URI %s. Assuming '%s'"),
                     uri,
                     scheme);

            return scheme;
        }
    }

    private int compare_by_date (MediaItem item) {
        if (this.date == null) {
            return -1;
        } else if (item.date == null) {
            return 1;
        } else {
            var tv1 = TimeVal ();
            assert (tv1.from_iso8601 (this.date));

            var tv2 = TimeVal ();
            assert (tv2.from_iso8601 (item.date));

            var ret = this.compare_long (tv1.tv_sec, tv2.tv_sec);
            if (ret == 0) {
                ret = this.compare_long (tv1.tv_usec, tv2.tv_usec);
            }

            return ret;
        }
    }

    private int compare_long (long a, long b) {
        if (a < b) {
            return -1;
        } else if (a > b) {
            return 1;
        } else {
            return 0;
        }
    }
}
