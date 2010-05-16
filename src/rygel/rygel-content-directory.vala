/*
 * Copyright (C) 2008 Zeeshan Ali <zeenix@gmail.com>.
 * Copyright (C) 2007 OpenedHand Ltd.
 *
 * Author: Zeeshan Ali <zeenix@gmail.com>
 *         Jorn Baayen <jorn@openedhand.com>
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

/**
 * Errors used by ContentDirectory and deriving classes.
 */
public errordomain Rygel.ContentDirectoryError {
    NO_SUCH_OBJECT = 701,
    RESTRICTED_PARENT = 713,
    CANT_PROCESS = 720,
    INVALID_ARGS = 402
}

/**
 * Basic implementation of UPnP ContentDirectory service version 2. Most often
 * plugins will provide a child of this class. The inheriting classes should
 * override create_root_container method.
 */
public class Rygel.ContentDirectory: Service {
    public const string UPNP_ID = "urn:upnp-org:serviceId:ContentDirectory";
    public const string UPNP_TYPE =
                    "urn:schemas-upnp-org:service:ContentDirectory:2";
    public const string UPNP_TYPE_V1 =
                    "urn:schemas-upnp-org:service:ContentDirectory:1";
    public const string DESCRIPTION_PATH = "xml/ContentDirectory.xml";
    private const string SEARCH_CAPS = "@id,@parentID,@refID," +
                                       "upnp:class,dc:title,dc:creator," +
                                       "res,res@protocolInfo";

    protected string feature_list;
    protected string sort_caps;

    internal HTTPServer http_server;

    public MediaContainer root_container;
    private ArrayList<MediaContainer> updated_containers;

    private ArrayList<ImportResource> active_imports;

    private bool clear_updated_containers;
    private uint update_notify_id;

    internal Cancellable cancellable;

    public uint32 system_update_id;

    // Public abstract methods derived classes need to implement
    public virtual MediaContainer? create_root_container () {
       return null;
    }

    public override void constructed () {
        this.cancellable = new Cancellable ();

        this.root_container = this.create_root_container ();

        try {
            this.http_server = new HTTPServer (this, this.get_type ().name ());
        } catch (GLib.Error err) {
            critical (_("Failed to create HTTP server for %s: %s"),
                      this.get_type ().name (),
                      err.message);
            return;
        }

        this.updated_containers =  new ArrayList<MediaContainer> ();
        this.active_imports = new ArrayList<ImportResource> ();

        this.root_container.container_updated += on_container_updated;

        this.feature_list =
            "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" +
            "<Features xmlns=\"urn:schemas-upnp-org:av:avs\" " +
            "xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" " +
            "xsi:schemaLocation=\"urn:schemas-upnp-org:av:avs" +
            "http://www.upnp.org/schemas/av/avs-v1-20060531.xsd\">" +
            "</Features>";
        this.sort_caps = "";

        this.action_invoked["Browse"] += this.browse_cb;
        this.action_invoked["Search"] += this.search_cb;
        this.action_invoked["CreateObject"] += this.create_object_cb;
        this.action_invoked["ImportResource"] += this.import_resource_cb;
        this.action_invoked["GetTransferProgress"] +=
                                        this.get_transfer_progress_cb;
        this.action_invoked["StopTransferResource"] +=
                                        this.stop_transfer_resource_cb;

        this.query_variable["TransferIDs"] += this.query_transfer_ids;

        /* Connect SystemUpdateID related signals */
        this.action_invoked["GetSystemUpdateID"] +=
                                                this.get_system_update_id_cb;
        this.query_variable["SystemUpdateID"] += this.query_system_update_id;
        this.query_variable["ContainerUpdateIDs"] +=
                                                this.query_container_update_ids;

        /* Connect SearchCapabilities related signals */
        this.action_invoked["GetSearchCapabilities"] +=
                                                this.get_search_capabilities_cb;
        this.query_variable["SearchCapabilities"] +=
                                                this.query_search_capabilities;

        /* Connect SortCapabilities related signals */
        this.action_invoked["GetSortCapabilities"] +=
                                                this.get_sort_capabilities_cb;
        this.query_variable["SortCapabilities"] +=
                                                this.query_sort_capabilities;

        /* Connect FeatureList related signals */
        this.action_invoked["GetFeatureList"] += this.get_feature_list_cb;
        this.query_variable["FeatureList"] += this.query_feature_list;

        this.http_server.run.begin ();
    }

    ~ContentDirectory () {
        // Cancel all state machines
        this.cancellable.cancel ();
    }

    /* Browse action implementation */
    private void browse_cb (ContentDirectory    content_dir,
                            owned ServiceAction action) {
        Browse browse = new Browse (this, action);

        browse.run.begin ();
    }

    /* Search action implementation */
    private void search_cb (ContentDirectory    content_dir,
                            owned ServiceAction action) {
        var search = new Search (this, action);

        search.run.begin ();
    }

    /* CreateObject action implementation */
    private void create_object_cb (ContentDirectory    content_dir,
                                   owned ServiceAction action) {
        var creator = new ItemCreator (this, action);

        creator.run.begin ();
    }

    /* ImportResource action implementation */
    private void import_resource_cb (ContentDirectory    content_dir,
                                     owned ServiceAction action) {
        var import = new ImportResource (this, action);

        import.completed += this.on_import_completed;
        this.active_imports.add (import);

        import.run.begin ();

        this.notify ("TransferIDs",
                        typeof (string),
                        this.create_transfer_ids ());
    }

    /* Query TransferIDs */
    private void query_transfer_ids (ContentDirectory content_dir,
                                     string           variable,
                                     ref GLib.Value   value) {
        value.init (typeof (string));
        value.set_string (this.create_transfer_ids ());
    }

    /* GetTransferProgress action implementation */
    private void get_transfer_progress_cb (ContentDirectory    content_dir,
                                           owned ServiceAction action) {
        var import = find_import_for_action (action);
        if (import != null) {
            action.set ("TransferStatus",
                            typeof (string),
                            import.status_as_string,
                        "TransferLength",
                            typeof (int64),
                            import.bytes_copied,
                        "TransferTotal",
                            typeof (int64),
                            import.bytes_total);

            action.return ();
        } else {
            action.return_error (717, _("No such file transfer"));
        }
    }

    /* StopTransferResource action implementation */
    private void stop_transfer_resource_cb (ContentDirectory    content_dir,
                                            owned ServiceAction action) {
        var import = find_import_for_action (action);
        if (import != null) {
            import.cancellable.cancel ();

            action.return ();
        } else {
            action.return_error (717, _("No such file transfer"));
        }
    }

    /* GetSystemUpdateID action implementation */
    private void get_system_update_id_cb (ContentDirectory    content_dir,
                                          owned ServiceAction action) {
        /* Set action return arguments */
        action.set ("Id", typeof (uint32), this.system_update_id);

        action.return ();
    }

    /* Query GetSystemUpdateID */
    private void query_system_update_id (ContentDirectory content_dir,
                                         string           variable,
                                         ref GLib.Value   value) {
        /* Set action return arguments */
        value.init (typeof (uint32));
        value.set_uint (this.system_update_id);
    }

    /* Query ContainerUpdateIDs */
    private void query_container_update_ids (ContentDirectory content_dir,
                                             string           variable,
                                             ref GLib.Value   value) {
        var update_ids = this.create_container_update_ids ();

        /* Set action return arguments */
        value.init (typeof (string));
        value.set_string (update_ids);
    }

    /* action GetSearchCapabilities implementation */
    private void get_search_capabilities_cb (ContentDirectory    content_dir,
                                             owned ServiceAction action) {
        /* Set action return arguments */
        action.set ("SearchCaps", typeof (string), SEARCH_CAPS);

        action.return ();
    }

    /* Query SearchCapabilities */
    private void query_search_capabilities (ContentDirectory content_dir,
                                            string           variable,
                                            ref GLib.Value   value) {
        /* Set action return arguments */
        value.init (typeof (string));
        value.set_string (SEARCH_CAPS);
    }

    /* action GetSortCapabilities implementation */
    private void get_sort_capabilities_cb (ContentDirectory    content_dir,
                                           owned ServiceAction action) {
        /* Set action return arguments */
        action.set ("SortCaps", typeof (string), this.sort_caps);

        action.return ();
    }

    /* Query SortCapabilities */
    private void query_sort_capabilities (ContentDirectory content_dir,
                                          string           variable,
                                          ref GLib.Value   value) {
        /* Set action return arguments */
        value.init (typeof (string));
        value.set_string (this.sort_caps);
    }

    /* action GetFeatureList implementation */
    private void get_feature_list_cb (ContentDirectory    content_dir,
                                      owned ServiceAction action) {
        /* Set action return arguments */
        action.set ("FeatureList", typeof (string), this.feature_list);

        action.return ();
    }

    /* Query FeatureList */
    private void query_feature_list (ContentDirectory content_dir,
                                     string           variable,
                                     ref GLib.Value   value) {
        /* Set action return arguments */
        value.init (typeof (string));
        value.set_string (this.feature_list);
    }

    private string create_container_update_ids () {
        var update_ids = "";

        foreach (var container in this.updated_containers) {
            if (update_ids != "") {
                update_ids += ",";
            }

            update_ids += container.id + "," + container.update_id.to_string ();
        }

        return update_ids;
    }

    /**
     * handler for container_updated signal on root_container. We don't
     * immediately send the notification for changes but schedule the
     * notification after 0.2 seconds. Also we don't clear the updated
     * container list immediately after notification but rather in this
     * function. Please refer to ContentDirectory version 2 specs for details
     * on why we do all this the way we do.
     *
     * @param root_container the root_container
     * @param updated_container the container that just got updated
     */
    private void on_container_updated (MediaContainer root_container,
                                       MediaContainer updated_container) {
        this.system_update_id++;

        if (this.clear_updated_containers) {
            this.updated_containers.clear ();
            this.clear_updated_containers = false;
        }

        // UPnP specs dicate we make sure only last update be evented
        this.updated_containers.remove (updated_container);
        this.updated_containers.add (updated_container);

        if (this.update_notify_id == 0) {
            this.update_notify_id = Timeout.add (200, this.update_notify);
        }
    }

    private bool update_notify () {
        var update_ids = this.create_container_update_ids ();

        this.notify ("ContainerUpdateIDs", typeof (string), update_ids);
        this.notify ("SystemUpdateID", typeof (uint32), this.system_update_id);

        this.clear_updated_containers = true;
        this.update_notify_id = 0;

        return false;
    }

    private string create_transfer_ids () {
        var ids = "";

        foreach (var import in this.active_imports) {
            if (import.status != TransferStatus.COMPLETED) {
                if (ids != "") {
                    ids += ",";
                }

                ids += import.transfer_id.to_string ();
            }
        }

        return ids;
    }

    private void on_import_completed (ImportResource import) {
        this.notify ("TransferIDs",
                        typeof (string),
                        this.create_transfer_ids ());

        // According to CDS specs (v3 section 2.4.17), we must not immediately
        // remove the import from out memory
        Timeout.add_seconds (30, () => {
                this.active_imports.remove (import);

                return false;
        });
    }

    private ImportResource? find_import_for_action (ServiceAction action) {
        ImportResource ret = null;
        uint32 transfer_id;

        action.get ("TransferID",
                        typeof (uint32),
                        out transfer_id);

        foreach (var import in this.active_imports) {
            if (import.transfer_id == transfer_id) {
                ret = import;

                break;
            }
        }

        return ret;
    }
}

