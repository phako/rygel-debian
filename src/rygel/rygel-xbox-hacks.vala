/*
 * Copyright (C) 2010 Nokia Corporation.
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

using Soup;
using GUPnP;
using CStuff;

internal errordomain Rygel.XBoxHacksError {
    NA
}

internal class Rygel.XBoxHacks : GLib.Object {
    private static string AGENT = ".*Xbox.*";
    private static string DMS = "urn:schemas-upnp-org:device:MediaServer";
    private static string DMS_V1 = DMS + ":1";
    private static string FRIENDLY_NAME_POSTFIX =
                                        ": 1 : Windows Media Connect";
    private static string MODEL_NAME = "Windows Media Connect";

    public XBoxHacks.for_action (ServiceAction action) throws XBoxHacksError {
        var agent = action.get_message ().request_headers.get ("User-Agent");
        if (!agent.contains ("Xbox")) {
            throw new XBoxHacksError.NA (_("Not Applicable"));
        }
    }

    public void apply_on_device (RootDevice device,
                                 string     template_path) throws Error {
        if (!device.get_device_type ().has_prefix (DMS)) {
            return;
        }

        var doc = new XMLDoc.from_path (template_path);
        this.modify_dms_desc (doc.doc);

        var desc_path = template_path.replace (".xml", "-xbox.xml");
        this.save_modified_desc (doc, desc_path);

        var regex = new Regex (AGENT, RegexCompileFlags.CASELESS, 0);
        var server_path = "/" + device.get_relative_location ();
        device.context.host_path_for_agent (desc_path, server_path, regex);
    }

    public void translate_container_id (ref string container_id) {
        if (container_id == "1" ||
            container_id == "4" ||
            container_id == "5" ||
            container_id == "6" ||
            container_id == "7") {
            container_id = "0";
        }
    }

    public void apply (MediaItem item) {
        if (item.mime_type == "video/x-msvideo") {
            item.mime_type = "video/avi";
        } else if (item.mime_type == "video/mpeg") {
            // Force transcoding for MPEG files
            item.mime_type = "invalid/content";
        }
    }

    private void modify_dms_desc (Xml.Doc doc) {
        var element = Utils.get_xml_element ((Xml.Node *) doc,
                                             "root",
                                             "device",
                                             "deviceType");
        assert (element != null);
        element->set_content (DMS_V1);

        element = Utils.get_xml_element ((Xml.Node *) doc,
                                         "root",
                                         "device",
                                         "modelName");
        assert (element != null);
        element->set_content (MODEL_NAME);

        element = Utils.get_xml_element ((Xml.Node *) doc,
                                         "root",
                                         "device",
                                         "friendlyName");
        assert (element != null);
        element->add_content (FRIENDLY_NAME_POSTFIX);

        element = this.find_cds_type_node (doc);
        assert (element != null);
        element->set_content (ContentDirectory.UPNP_TYPE_V1);
    }

    private Xml.Node * find_cds_type_node (Xml.Node *doc_node) {
        var element = Utils.get_xml_element (doc_node,
                                             "root",
                                             "device",
                                             "serviceList");
        assert (element != null && element->children != null);

        Xml.Node *cds_type_node = null;

        for (var service_node = element->children;
             service_node != null;
             service_node = service_node->next) {
            for (var type_node = service_node->children;
                 type_node != null;
                 type_node = type_node->next) {
                if (type_node->name == "serviceType" &&
                    type_node->get_content () == ContentDirectory.UPNP_TYPE) {
                    cds_type_node = type_node;
                }
            }

            if (cds_type_node != null) {
                break;
            }
        }

        return cds_type_node;
    }

    private void save_modified_desc (XMLDoc doc,
                                     string desc_path) throws GLib.Error {
        FileStream f = FileStream.open (desc_path, "w+");
        int res = -1;

        if (f != null)
            res = doc.doc.dump (f);

        if (f == null || res == -1) {
            var message = _("Failed to write modified description to %s.");

            throw new IOError.FAILED (message, desc_path);
        }
    }
}
