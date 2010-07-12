/*
 * Copyright (C) 2009 Zeeshan Ali (Khattak) <zeeshanak@gnome.org>.
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

using FreeDesktop;

public class Rygel.External.Plugin : Rygel.Plugin {
    public string service_name;
    public string root_object;

    // Root container properties
    public uint child_count;
    public bool searchable;

    public Plugin (string    service_name,
                   string    title,
                   uint      child_count,
                   bool      searchable,
                   string    root_object,
                   IconInfo? icon) {
        base.MediaServer (service_name,
                          title,
                          typeof (ContentDir),
                          "Rygel External " + title);

        this.service_name = service_name;
        this.child_count = child_count;
        this.searchable = searchable;
        this.root_object = root_object;
        if (icon != null) {
            this.add_icon (icon);
        }
    }
}
