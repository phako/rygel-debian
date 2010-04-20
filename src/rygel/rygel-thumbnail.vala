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

/**
 * Represents a picture or video thumbnail.
 */
public class Rygel.Thumbnail : Rygel.IconInfo {
    public string dlna_profile;

    public Thumbnail (string mime_type = "image/jpeg",
                      string dlna_profile = "JPEG_TN") {
        base (mime_type);

        this.dlna_profile = dlna_profile;
    }

    internal DIDLLiteResource add_resource (DIDLLiteItem didl_item,
                                            string       protocol) {
        var res = didl_item.add_resource ();

        res.uri = this.uri;
        res.size = this.size;

        res.width = this.width;
        res.height = this.height;
        res.color_depth = this.depth;

        /* Protocol info */
        res.protocol_info = this.get_protocol_info (protocol);

        return res;
    }

    private ProtocolInfo get_protocol_info (string protocol) {
        var protocol_info = new ProtocolInfo ();

        protocol_info.mime_type = this.mime_type;
        protocol_info.dlna_profile = this.dlna_profile;
        protocol_info.protocol = protocol;
        protocol_info.dlna_flags |= DLNAFlags.INTERACTIVE_TRANSFER_MODE |
                                    DLNAFlags.BACKGROUND_TRANSFER_MODE |
                                    DLNAFlags.CONNECTION_STALL |
                                    DLNAFlags.DLNA_V15;

        return protocol_info;
    }
}
