/*
 * Copyright (C) 2008 Nokia Corporation.
 * Copyright (C) 2008 Zeeshan Ali (Khattak) <zeeshanak@gnome.org>.
 *
 * Author: Zeeshan Ali (Khattak) <zeeshanak@gnome.org>
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
using Soup;

/**
 * Search action implementation.
 */
internal class Rygel.Search:  Rygel.MediaQueryAction {
    // In arguments
    public string search_criteria;

    public Search (ContentDirectory    content_dir,
                   owned ServiceAction action) {
        base (content_dir, action);

        this.object_id_arg = "ContainerID";
    }

    protected override void parse_args () throws Error {
        base.parse_args ();

        this.action.get ("SearchCriteria",
                            typeof (string),
                            out this.search_criteria);

        if (this.search_criteria == null) {
            throw new ContentDirectoryError.INVALID_ARGS (
                                        "No search criteria given");
        }

        debug (_("Executing search request: %s"), this.search_criteria);
    }

    protected override async MediaObjects fetch_results (
                                        MediaObject media_object) throws Error {
        var container = media_object as MediaContainer;

        var parser = new Rygel.SearchCriteriaParser (this.search_criteria);
        yield parser.run ();

        if (parser.err != null) {
            throw parser.err;
        }

        var results = yield container.search (parser.expression,
                                              this.index,
                                              this.requested_count,
                                              out this.total_matches,
                                              this.cancellable);
        if (results.size == 0) {
            var message = _("No object satisfies given search criteria.");

            throw new ContentDirectoryError.CANT_PROCESS (message);
        }

        return results;
    }

    protected override void handle_error (Error error) {
        warning (_("Failed to search in '%s': %s"),
                 this.object_id,
                 error.message);

        base.handle_error (error);
    }
}

