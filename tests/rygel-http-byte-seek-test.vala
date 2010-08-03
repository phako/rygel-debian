/*
 * Copyright (C) 2010 Nokia Corporation.
 *
 * Author: Zeeshan Ali (Khattak) <zeeshan.ali@nokia.com>
 *                               <zeeshanak@gnome.org>
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

private errordomain Rygel.TestError {
    SKIP
}

private class Rygel.HTTPIdentityHandler : GLib.Object {}

private class Rygel.MediaItem : GLib.Object {
    public int64 size = 2048;
}

private class Rygel.Thumbnail : GLib.Object {
    public int64 size = 1024;
}

private class Rygel.Subtitle : GLib.Object {
    public int64 size = 512;
}

private class Rygel.HTTPGet : GLib.Object {
    public const string ITEM_URI = "http://DoesntMatterWhatThisIs";

    public Soup.Message msg;
    public MediaItem item;
    public Thumbnail thumbnail;
    public Subtitle subtitle;

    public HTTPIdentityHandler handler;

    public HTTPGet (Thumbnail? thumbnail, Subtitle? subtitle) {
        this.msg = new Soup.Message ("HTTP", ITEM_URI);
        this.item = new MediaItem ();
        this.handler = new HTTPIdentityHandler ();
        this.thumbnail = thumbnail;
        this.subtitle = subtitle;
    }

    public HTTPGet.seek_start (int64      start,
                               Thumbnail? thumbnail,
                               Subtitle?  subtitle) {
        this (thumbnail, subtitle);

        this.add_headers (start, -1);
    }

    public HTTPGet.seek_stop (int64      stop,
                              Thumbnail? thumbnail,
                              Subtitle?  subtitle) {
        this (thumbnail, subtitle);

        this.add_headers (0, stop);
    }

    public HTTPGet.seek_start_stop (int64      start,
                                    int64      stop,
                                    Thumbnail? thumbnail,
                                    Subtitle?  subtitle) {
        this (thumbnail, subtitle);

        this.add_headers (start, stop);
    }

    private void add_headers (int64 start, int64 stop) {
        this.msg.request_headers.set_range (start, stop);
    }
}

private class Rygel.HTTPByteSeekTest : GLib.Object {
    private Regex range_regex;

    public static int main (string[] args) {
        try {
            var test = new HTTPByteSeekTest ();

            test.run ();
        } catch (TestError.SKIP error) {
            return 77;
        } catch (Error error) {
            critical ("%s", error.message);

            return -1;
        }

        return 0;
    }

    public void run () throws HTTPSeekError {
        var thumbnails = new Thumbnail[] { null, new Thumbnail () };
        var subtitles = new Subtitle[] { null, new Subtitle () };

        foreach (var thumbnail in thumbnails) {
            foreach (var subtitle in subtitles) {
                this.test_no_seek (thumbnail, subtitle);
                this.test_start_only_seek (thumbnail, subtitle);
                this.test_stop_only_seek (thumbnail, subtitle);
                this.test_start_stop_seek (thumbnail, subtitle);
            }
        }
    }

    private HTTPByteSeekTest () {
        this.range_regex = new Regex ("bytes +[0-9]+-[0-9]+/[0-9]+",
                                      RegexCompileFlags.CASELESS);
    }

    private void test_no_seek (Thumbnail? thumbnail,
                               Subtitle?  subtitle) throws HTTPSeekError {
        var request = new HTTPGet (thumbnail, subtitle);

        int64 size;
        if (request.thumbnail != null) {
            size = request.thumbnail.size;
        } else if (request.subtitle != null) {
            size = request.subtitle.size;
        } else {
            size = request.item.size;
        }

        this.test_seek (request, 0, size - 1);
    }

    private void test_start_only_seek (Thumbnail? thumbnail,
                                       Subtitle?  subtitle)
                                       throws HTTPSeekError {
        var request = new HTTPGet.seek_start (128, thumbnail, subtitle);

        int64 size;
        if (request.thumbnail != null) {
            size = request.thumbnail.size;
        } else if (request.subtitle != null) {
            size = request.subtitle.size;
        } else {
            size = request.item.size;
        }

        this.test_seek (request, 128, size - 1);
    }

    private void test_stop_only_seek (Thumbnail? thumbnail,
                                      Subtitle?  subtitle)
                                      throws HTTPSeekError {
        var request = new HTTPGet.seek_stop (128, thumbnail, subtitle);

        this.test_seek (request, 0, 128);
    }

    private void test_start_stop_seek (Thumbnail? thumbnail,
                                       Subtitle?  subtitle)
                                       throws HTTPSeekError {
        var request = new HTTPGet.seek_start_stop (128,
                                                   256,
                                                   thumbnail,
                                                   subtitle);

        this.test_seek (request, 128, 256);
    }

    private void test_seek (HTTPGet request,
                            int64   start,
                            int64   stop) throws HTTPSeekError {
        assert (HTTPByteSeek.needed (request));

        var seek = new HTTPByteSeek (request);
        seek.add_response_headers ();

        assert (seek != null);
        assert (seek.start == start);
        assert (seek.stop == stop);

        if (request.thumbnail != null) {
            assert (seek.total_length == request.thumbnail.size);
        } else if (request.subtitle != null) {
            assert (seek.total_length == request.subtitle.size);
        } else {
            assert (seek.total_length == request.item.size);
        }

        var header = request.msg.response_headers.get ("Accept-Ranges");
        assert (header == "bytes");
        header = request.msg.response_headers.get ("Content-Range");
        assert (header != null);
        assert (this.range_regex.match (header));

        assert (request.msg.response_headers.get_content_length () ==
                seek.length);
    }
}
