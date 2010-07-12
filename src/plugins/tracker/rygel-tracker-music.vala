/*
 * Copyright (C) 2009 Nokia Corporation.
 *
 * Author: Zeeshan Ali (Khattak) <zeeshanak@gnome.org>
 *                               <zeeshan.ali@nokia.com>
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

/**
 * Container listing Music content hierarchy.
 */
public class Rygel.Tracker.Music : CategoryContainer {
    public Music (string id, MediaContainer parent, string title) {
        base (id, parent, title, new MusicItemFactory ());

        var key_chain = new string[] { "nmm:performer",
                                       "nmm:artistName",
                                       null };
        this.add_child (new MetadataValues (id + "Artists",
                                            this,
                                            _("Artists"),
                                            this.item_factory,
                                            key_chain));

        key_chain = new string[] { "nmm:musicAlbum", "nmm:albumTitle", null };
        this.add_child (new MetadataValues (id + "Albums",
                                            this,
                                            _("Albums"),
                                            this.item_factory,
                                            key_chain));
        this.add_child (new Tags (this, item_factory));
    }
}

