/*
 * Copyright (C) 2008 Nokia Corporation.
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
using GUPnP;

/**
 * Represents a Rygel plugin. Plugins are supposed to provide an object of this
 * class or a subclass.
 */
public class Rygel.Plugin : GUPnP.ResourceFactory {
    private static const string ICON_BIG = "file://" +
                                           BuildConfig.BIG_ICON_DIR +
                                           "/rygel.png";
    private static const string ICON_SMALL = "file://" +
                                             BuildConfig.SMALL_ICON_DIR +
                                             "/rygel.png";
    private static const string ICON_MIME = "image/png";
    private static const int ICON_DEPTH = 32;
    private static const int ICON_BIG_WIDTH = 256;
    private static const int ICON_BIG_HEIGHT = 256;
    private static const int ICON_SMALL_WIDTH = 32;
    private static const int ICON_SMALL_HEIGHT = 32;

    public string name;
    public string title;
    public string description;

    // Path to description document
    public string desc_path;

    public bool available { get; set; }

    public ArrayList<ResourceInfo> resource_infos;
    public ArrayList<IconInfo> icon_infos;

    public ArrayList<IconInfo> default_icons;

    public Plugin (string  desc_path,
                   string  name,
                   string? title,
                   string? description = null) {
        this.desc_path = desc_path;
        this.name = name;
        this.title = title;
        this.description = description;

        this.available = true;

        if (title == null) {
            this.title = name;
        }

        this.resource_infos = new ArrayList<ResourceInfo> ();
        this.icon_infos = new ArrayList<IconInfo> ();
        this.default_icons = new ArrayList<IconInfo> ();

        var icon = new IconInfo (ICON_MIME);
        icon.uri = ICON_BIG;
        icon.width = ICON_BIG_WIDTH;
        icon.height = ICON_BIG_HEIGHT;
        icon.depth = ICON_DEPTH;
        this.default_icons.add (icon);

        icon = new IconInfo (ICON_MIME);
        icon.uri = ICON_SMALL;
        icon.width = ICON_SMALL_WIDTH;
        icon.height = ICON_SMALL_HEIGHT;
        icon.depth = ICON_DEPTH;
        this.default_icons.add (icon);
    }

    public void add_resource (ResourceInfo resource_info) {
        this.resource_infos.add (resource_info);
        this.register_resource_type (resource_info.upnp_type,
                                     resource_info.type);
    }

    public void add_icon (IconInfo icon_info) {
        this.icon_infos.add (icon_info);
    }
}

