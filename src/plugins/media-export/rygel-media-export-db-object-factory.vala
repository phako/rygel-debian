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


/**
 * Class used by MediaDB to create containers and items on demand
 *
 * If a specific kind of Item or Container is needed instead of
 * the default ones, inherit from this class and override the
 * corresponding methods.
 *
 * The class does not hold a reference to the MediaDB as the
 * MediaDB is holding a reference to the factory; this is done to
 * prevent circular references
 */
public class Rygel.MediaExportDBObjectFactory : Object {
    /**
     * Return a new instance of DatabaseBackedMediaContainer
     *
     * @param media_db instance of MediaDB
     * @param title title of the container
     * @param child_count number of children in the container
     */
    public virtual MediaContainer get_container (
                                        MediaExportMediaCache media_db,
                                        string                id,
                                        string                title,
                                        uint                  child_count) {
        return new MediaExportDBContainer (media_db, id, title);
    }

    /**
     * Return a new instance of MediaItem
     *
     * @param media_db instance of MediaDB
     * @param id id of the item
     * @param title title of the item
     * @param upnp_class upnp_class of the item
     */
    public virtual MediaItem get_item (MediaExportMediaCache media_db,
                                       MediaContainer        parent,
                                       string                id,
                                       string                title,
                                       string                upnp_class) {
        return new MediaItem (id, parent, title, upnp_class);
    }
}
