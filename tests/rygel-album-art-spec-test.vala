/*
 * Copyright (C) 2010 Jens Georg.
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


public class Rygel.MediaItem : GLib.Object {
    public string title;
    public string author;
    public string album;
}

private class Rygel.AlbumArtSpecTest : GLib.Object {
    public static int main (string[] args) {
        var test = new AlbumArtSpecTest ();

        test.run ();

        return 0;
    }

    public void run() {
        this.test_full_spec ();
        //this.test_simple_spec ();
    }

    public void test_full_spec () {
        var store = MediaArtStore.get_default ();
        var item = new MediaItem ();
        item.author = "metallica";
        item.album = "and justice for all";
        item.title = "Enter Sandman";
        var file = store.get_media_art_file ("album", item);
        assert (file != null);
        assert (file.get_uri ().has_suffix
                ("album-3c2234a7ce973bc1700e0c743d6a819c-3d422ba022ae0daa8f5454ba7dfa0f9a.jpeg"));

        file = store.get_media_art_file ("artist", item);
        assert (file != null);
        assert (file.get_uri ().has_suffix
                ("artist-3c2234a7ce973bc1700e0c743d6a819c-3d422ba022ae0daa8f5454ba7dfa0f9a.jpeg"));

        item = new MediaItem ();
        item.title = "radio ga ga";
        file = store.get_media_art_file ("radio", item);
        assert (file != null);
        assert (file.get_uri ().has_suffix
                ("radio-b924ce08955675c6a30c745d18286d21-7215ee9c7d9dc229d2921a40e899ec5f.jpeg"));

        item = new MediaItem ();
        item.author = "met[xXx]allica";
        item.album = "and justice f[{]}or all";
        item.title = "Enter Sandman";
        file = store.get_media_art_file ("album", item);
        assert (file != null);
        assert (file.get_uri ().has_suffix
                ("album-3c2234a7ce973bc1700e0c743d6a819c-3d422ba022ae0daa8f5454ba7dfa0f9a.jpeg"));

        // check block removal algorithm - normalizes to "metallica" and not
        // "metca"
        item = new MediaItem ();
        item.author = "met[xX[x]alli]ca";
        item.album = "and justice for all";
        item.title = "Enter Sandman";
        file = store.get_media_art_file ("album", item);
        assert (file != null);
        assert (file.get_uri ().has_suffix
                ("album-3c2234a7ce973bc1700e0c743d6a819c-3d422ba022ae0daa8f5454ba7dfa0f9a.jpeg"));

        /* Fails due to unclear spec
        item = new MediaItem ();
        item.author = "World Soccer";
        item.title = "Daily Podcast";
        file = store.get_media_art_file ("podcast", item);
        assert (file != null);
        assert (file.get_uri ().has_suffix
                ("podcast-d717b10ec8fb35b11644995deb04b721-08d299536e562915eb133e2676396d3f.jpeg"));
                */

        // test banshee spec
        item = new MediaItem ();
        item.author = "Peter Fox";
        item.album = "Stadtaffe";
        item.title = "Schwarz zu Blau";
        file = store.get_media_art_file ("album", item, true);
        assert (file != null);
        debug (file.get_uri());
        assert (file.get_uri ().has_suffix
                ("album-15f9f69ee3d841df6b1e2f56439f11a2.jpg"));
    }
}
