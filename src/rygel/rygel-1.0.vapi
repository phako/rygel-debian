/* rygel-1.0.vapi generated by valac, do not modify. */

[CCode (cprefix = "Rygel", lower_case_cprefix = "rygel_")]
namespace Rygel {
	[CCode (cheader_filename = "rygel.h")]
	public class Configuration : GLib.Object {
		protected GConf.Client gconf;
		protected const string ENABLED_KEY;
		protected const string IP_KEY;
		protected const string LPCM_TRANSCODER_KEY;
		protected const string MP2TS_TRANSCODER_KEY;
		protected const string MP3_TRANSCODER_KEY;
		protected const string PORT_KEY;
		protected const string ROOT_GCONF_PATH;
		protected const string TITLE_KEY;
		protected const string TRANSCODING_KEY;
		public bool get_bool (string section, string key, bool default_value);
		public static Rygel.Configuration get_default ();
		public bool get_enabled (string section);
		public int get_int (string section, string key, int min, int max, int default_value);
		public Gee.ArrayList<int> get_int_list (string section, string key);
		public string? get_string (string section, string key, string? default_value);
		public Gee.ArrayList<string> get_string_list (string section, string key);
		public string get_title (string section, string default_title);
		public Configuration ();
		public void set_bool (string section, string key, bool value);
		public void set_int (string section, string key, int value);
		public void set_string (string section, string key, string value);
		public void set_string_list (string section, string key, Gee.ArrayList<string> str_list);
		public string host_ip { get; set; }
		public bool lpcm_transcoder { get; set; }
		public bool mp2ts_transcoder { get; set; }
		public bool mp3_transcoder { get; set; }
		public int port { get; set; }
		public bool transcoding { get; set; }
	}
	[CCode (cheader_filename = "rygel.h")]
	public class ConnectionManager : GUPnP.Service {
		protected string connection_ids;
		protected string sink_protocol_info;
		protected string source_protocol_info;
		public const string DESCRIPTION_PATH;
		public const string UPNP_ID;
		public const string UPNP_TYPE;
		public override void constructed ();
		public ConnectionManager ();
	}
	[CCode (cheader_filename = "rygel.h")]
	public class ContentDirectory : GUPnP.Service {
		protected string feature_list;
		public Rygel.MediaContainer root_container;
		protected string search_caps;
		protected string sort_caps;
		public uint32 system_update_id;
		public const string DESCRIPTION_PATH;
		public const string UPNP_ID;
		public const string UPNP_TYPE;
		public override void constructed ();
		public virtual Rygel.MediaContainer? create_root_container ();
		public ContentDirectory ();
	}
	[CCode (ref_function = "rygel_icon_info_ref", unref_function = "rygel_icon_info_unref", param_spec_function = "rygel_param_spec_icon_info", cheader_filename = "rygel.h")]
	public class IconInfo {
		public uint depth;
		public uint height;
		public string mimetype;
		public string path;
		public uint width;
		public IconInfo (string mimetype, uint width, uint height, uint depth, string path);
	}
	[CCode (cheader_filename = "rygel.h")]
	public abstract class MediaContainer : Rygel.MediaObject {
		public uint child_count;
		public uint32 update_id;
		public abstract void find_object (string id, GLib.Cancellable? cancellable, GLib.AsyncReadyCallback callback);
		public abstract Rygel.MediaObject? find_object_finish (GLib.AsyncResult res) throws GLib.Error;
		public abstract void get_children (uint offset, uint max_count, GLib.Cancellable? cancellable, GLib.AsyncReadyCallback callback);
		public abstract Gee.List<Rygel.MediaObject>? get_children_finish (GLib.AsyncResult res) throws GLib.Error;
		public MediaContainer (string id, Rygel.MediaContainer? parent, string title, uint child_count);
		public MediaContainer.root (string title, uint child_count);
		public void updated ();
		public signal void container_updated (Rygel.MediaContainer container);
	}
	[CCode (cheader_filename = "rygel.h")]
	public class MediaItem : Rygel.MediaObject {
		public string album;
		public string author;
		public int bitrate;
		public int bits_per_sample;
		public int color_depth;
		public string date;
		public long duration;
		public int height;
		public string mime_type;
		public int n_audio_channels;
		public int sample_freq;
		public long size;
		public int track_number;
		public string upnp_class;
		public Gee.ArrayList<string> uris;
		public int width;
		public const string AUDIO_CLASS;
		public const string IMAGE_CLASS;
		public const string MUSIC_CLASS;
		public const string VIDEO_CLASS;
		public virtual Gst.Element? create_stream_source ();
		public MediaItem (string id, Rygel.MediaContainer parent, string title, string upnp_class);
	}
	[CCode (cheader_filename = "rygel.h")]
	public abstract class MediaObject : GLib.Object {
		public string id;
		public weak Rygel.MediaContainer parent;
		public string title;
	}
	[CCode (cheader_filename = "rygel.h")]
	public class Plugin : GUPnP.ResourceFactory {
		public Gee.ArrayList<Rygel.IconInfo> icon_infos;
		public string name;
		public Gee.ArrayList<Rygel.ResourceInfo> resource_infos;
		public string title;
		public void add_icon (Rygel.IconInfo icon_info);
		public void add_resource (Rygel.ResourceInfo resource_info);
		public Plugin (string name, string? title);
		public bool available { get; set; }
	}
	[CCode (cheader_filename = "rygel.h")]
	public class PluginLoader : GLib.Object {
		public void add_plugin (Rygel.Plugin plugin);
		public Rygel.Plugin? get_plugin_by_name (string name);
		public Gee.Collection<Rygel.Plugin> list_plugins ();
		public void load_plugins ();
		public PluginLoader ();
		public signal void plugin_available (Rygel.Plugin plugin);
	}
	[CCode (ref_function = "rygel_resource_info_ref", unref_function = "rygel_resource_info_unref", param_spec_function = "rygel_param_spec_resource_info", cheader_filename = "rygel.h")]
	public class ResourceInfo {
		public string description_path;
		public GLib.Type type;
		public string upnp_id;
		public string upnp_type;
		public ResourceInfo (string upnp_id, string upnp_type, string description_path, GLib.Type type);
	}
	[CCode (cheader_filename = "rygel.h")]
	public class SimpleAsyncResult<G> : GLib.Object, GLib.AsyncResult {
		protected GLib.AsyncReadyCallback callback;
		public G data;
		public GLib.Error error;
		protected GLib.Object source_object;
		public void complete ();
		public void complete_in_idle ();
		public SimpleAsyncResult (GLib.Object source_object, GLib.AsyncReadyCallback callback);
	}
	[CCode (cheader_filename = "rygel.h")]
	public interface StateMachine : GLib.Object {
		public abstract void run (GLib.Cancellable? cancellable);
		public signal void completed ();
	}
	[CCode (cprefix = "RYGEL_CONTENT_DIRECTORY_ERROR_", cheader_filename = "rygel.h")]
	public errordomain ContentDirectoryError {
		NO_SUCH_OBJECT,
		INVALID_ARGS,
	}
}
