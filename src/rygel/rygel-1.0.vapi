/* rygel-1.0.vapi generated by valac, do not modify. */

[CCode (cprefix = "Rygel", lower_case_cprefix = "rygel_")]
namespace Rygel {
	[CCode (cheader_filename = "rygel.h")]
	public class CmdlineConfig : GLib.Object, Rygel.Configuration {
		public CmdlineConfig ();
		public static Rygel.CmdlineConfig get_default ();
		public static void parse_args (ref unowned string[] args) throws Rygel.CmdlineConfigError, GLib.OptionError;
	}
	[CCode (cheader_filename = "rygel.h")]
	public class ConnectionManager : GUPnP.Service {
		protected string connection_ids;
		protected string sink_protocol_info;
		protected string source_protocol_info;
		public const string DESCRIPTION_PATH;
		public const string UPNP_ID;
		public const string UPNP_TYPE;
		public ConnectionManager ();
		public override void constructed ();
	}
	[CCode (cheader_filename = "rygel.h")]
	public class ContentDirectory : GUPnP.Service {
		protected string feature_list;
		public Rygel.MediaContainer root_container;
		protected string sort_caps;
		public uint32 system_update_id;
		public const string DESCRIPTION_PATH;
		public const string UPNP_ID;
		public const string UPNP_TYPE;
		public const string UPNP_TYPE_V1;
		public ContentDirectory ();
		public override void constructed ();
		public virtual Rygel.MediaContainer? create_root_container ();
	}
	[CCode (cheader_filename = "rygel.h")]
	[DBus (name = "org.gnome.Rygel1")]
	public class DBusService : GLib.Object {
		public DBusService (Rygel.Main main) throws DBus.Error;
		public void Shutdown ();
	}
	[CCode (cheader_filename = "rygel.h")]
	public class EnvironmentConfig : GLib.Object, Rygel.Configuration {
		public EnvironmentConfig ();
		public static Rygel.EnvironmentConfig get_default ();
	}
	[CCode (ref_function = "rygel_icon_info_ref", unref_function = "rygel_icon_info_unref", cheader_filename = "rygel.h")]
	public class IconInfo {
		public int depth;
		public int height;
		public string mime_type;
		public long size;
		public string uri;
		public int width;
		public IconInfo (string mime_type);
	}
	[CCode (cheader_filename = "rygel.h")]
	public class LogHandler : GLib.Object {
		public GLib.LogLevelFlags levels;
		public static Rygel.LogHandler get_default ();
	}
	[CCode (cheader_filename = "rygel.h")]
	public class LogicalExpression : Rygel.SearchExpression<Rygel.LogicalOperator,Rygel.SearchExpression,Rygel.SearchExpression> {
		public LogicalExpression ();
		public override bool satisfied_by (Rygel.MediaObject media_object);
		public override string to_string ();
	}
	[CCode (cheader_filename = "rygel.h")]
	public class Main : GLib.Object {
		public bool need_restart;
		public void exit (int exit_code);
		public void restart ();
	}
	[CCode (cheader_filename = "rygel.h")]
	public abstract class MediaContainer : Rygel.MediaObject {
		public int child_count;
		public Gee.ArrayList<string> create_classes;
		public uint32 update_id;
		public MediaContainer (string id, Rygel.MediaContainer? parent, string title, int child_count);
		public virtual async void add_item (Rygel.MediaItem item, GLib.Cancellable? cancellable) throws GLib.Error;
		public virtual async Rygel.MediaObject? find_object (string id, GLib.Cancellable? cancellable) throws GLib.Error;
		public abstract async Gee.List<Rygel.MediaObject>? get_children (uint offset, uint max_count, GLib.Cancellable? cancellable) throws GLib.Error;
		public MediaContainer.root (string title, int child_count);
		public virtual async Gee.List<Rygel.MediaObject>? search (Rygel.SearchExpression expression, uint offset, uint max_count, out uint total_matches, GLib.Cancellable? cancellable) throws GLib.Error;
		public void set_uri (string uri, Gee.ArrayList<string>? create_classes = null);
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
		public string dlna_profile;
		public long duration;
		public int height;
		public string mime_type;
		public int n_audio_channels;
		public int pixel_height;
		public int pixel_width;
		public int sample_freq;
		public long size;
		public Gee.ArrayList<Rygel.Subtitle> subtitles;
		public Gee.ArrayList<Rygel.Thumbnail> thumbnails;
		public int track_number;
		public int width;
		public const string AUDIO_CLASS;
		public const string IMAGE_CLASS;
		public const string MUSIC_CLASS;
		public const string PHOTO_CLASS;
		public const string VIDEO_CLASS;
		public MediaItem (string id, Rygel.MediaContainer parent, string title, string upnp_class);
		public void add_uri (string uri, Rygel.Thumbnail? thumbnail);
		public virtual Gst.Element? create_stream_source ();
		public virtual bool should_stream ();
	}
	[CCode (cheader_filename = "rygel.h")]
	public abstract class MediaObject : GLib.Object {
		public string id;
		public uint64 modified;
		public weak Rygel.MediaContainer parent;
		public string upnp_class;
		public Gee.ArrayList<string> uris;
		public MediaObject ();
		public async GLib.File? get_writable (GLib.Cancellable? cancellable) throws GLib.Error;
		public Rygel.MediaContainer parent_ref { get; set; }
		public string title { get; set; }
	}
	[CCode (cheader_filename = "rygel.h")]
	public class MediaReceiverRegistrar : GUPnP.Service {
		public const string DESCRIPTION_PATH;
		public const string UPNP_ID;
		public const string UPNP_TYPE;
		public MediaReceiverRegistrar ();
		public override void constructed ();
	}
	[CCode (cheader_filename = "rygel.h")]
	public class MetaConfig : GLib.Object, Rygel.Configuration {
		public MetaConfig ();
		public static Rygel.MetaConfig get_default ();
	}
	[CCode (cheader_filename = "rygel.h")]
	public class Plugin : GUPnP.ResourceFactory {
		public Gee.ArrayList<Rygel.IconInfo> default_icons;
		public string desc_path;
		public string description;
		public Gee.ArrayList<Rygel.IconInfo> icon_infos;
		public string name;
		public Gee.ArrayList<Rygel.ResourceInfo> resource_infos;
		public string title;
		public Plugin (string desc_path, string name, string? title, string? description = null);
		public Plugin.MediaServer (string name, string? title, GLib.Type content_dir_type, string? description = null);
		public void add_icon (Rygel.IconInfo icon_info);
		public void add_resource (Rygel.ResourceInfo resource_info);
		public bool available { get; set; }
	}
	[CCode (cheader_filename = "rygel.h")]
	public class PluginLoader : GLib.Object {
		public PluginLoader ();
		public void add_plugin (Rygel.Plugin plugin);
		public Rygel.Plugin? get_plugin_by_name (string name);
		public Gee.Collection<Rygel.Plugin> list_plugins ();
		public void load_plugins ();
		public signal void plugin_available (Rygel.Plugin plugin);
	}
	[CCode (cheader_filename = "rygel.h")]
	public class RelationalExpression : Rygel.SearchExpression<GUPnP.SearchCriteriaOp,string,string> {
		public RelationalExpression ();
		public bool compare_string (string? str);
		public override bool satisfied_by (Rygel.MediaObject media_object);
		public override string to_string ();
	}
	[CCode (ref_function = "rygel_resource_info_ref", unref_function = "rygel_resource_info_unref", cheader_filename = "rygel.h")]
	public class ResourceInfo {
		public string description_path;
		public GLib.Type type;
		public string upnp_id;
		public string upnp_type;
		public ResourceInfo (string upnp_id, string upnp_type, string description_path, GLib.Type type);
	}
	[CCode (cheader_filename = "rygel.h")]
	public class RootDevice : GUPnP.RootDevice {
		public RootDevice (GUPnP.Context context, Rygel.Plugin plugin, GUPnP.XMLDoc description_doc, string description_path, string description_dir);
	}
	[CCode (ref_function = "rygel_search_expression_ref", unref_function = "rygel_search_expression_unref", cheader_filename = "rygel.h")]
	public abstract class SearchExpression<G,H,I> {
		public G op;
		public H operand1;
		public I operand2;
		public SearchExpression ();
		public abstract bool satisfied_by (Rygel.MediaObject media_object);
		public abstract string to_string ();
	}
	[CCode (cheader_filename = "rygel.h")]
	public class SignalHandler : GLib.Object {
		public SignalHandler ();
		public static void cleanup ();
		public static void setup (Rygel.Main _main);
	}
	[CCode (cheader_filename = "rygel.h")]
	public class SimpleContainer : Rygel.MediaContainer {
		public Gee.ArrayList<Rygel.MediaObject> children;
		public SimpleContainer (string id, Rygel.MediaContainer? parent, string title);
		public void add_child (Rygel.MediaObject child);
		public void clear ();
		public override async Gee.List<Rygel.MediaObject>? get_children (uint offset, uint max_count, GLib.Cancellable? cancellable) throws GLib.Error;
		public void remove_child (Rygel.MediaObject child);
		public SimpleContainer.root (string title);
	}
	[CCode (cheader_filename = "rygel.h")]
	public class SourceConnectionManager : Rygel.ConnectionManager {
		public SourceConnectionManager ();
		public override void constructed ();
	}
	[CCode (ref_function = "rygel_subtitle_ref", unref_function = "rygel_subtitle_unref", cheader_filename = "rygel.h")]
	public class Subtitle {
		public string caption_type;
		public string mime_type;
		public long size;
		public string uri;
		public Subtitle (string mime_type = "text/plain", string caption_type = "srt");
	}
	[CCode (cheader_filename = "rygel.h")]
	public class Thumbnail : Rygel.IconInfo {
		public string dlna_profile;
		public Thumbnail (string mime_type = "image/jpeg", string dlna_profile = "JPEG_TN");
	}
	[CCode (cheader_filename = "rygel.h")]
	public class UserConfig : GLib.Object, Rygel.Configuration {
		protected GLib.KeyFile key_file;
		protected const string CONFIG_FILE;
		protected const string ENABLED_KEY;
		protected const string IFACE_KEY;
		protected const string LOG_LEVEL_KEY;
		protected const string LPCM_TRANSCODER_KEY;
		protected const string MP2TS_TRANSCODER_KEY;
		protected const string MP3_TRANSCODER_KEY;
		protected const string PLUGIN_PATH_KEY;
		protected const string PORT_KEY;
		protected const string TITLE_KEY;
		protected const string TRANSCODING_KEY;
		protected const string WMV_TRANSCODER_KEY;
		public UserConfig (bool read_only = true) throws GLib.Error;
		public static Rygel.UserConfig get_default () throws GLib.Error;
		public void save ();
		public void set_bool (string section, string key, bool value);
		public void set_int (string section, string key, int value);
		public void set_interface (string value);
		public void set_lpcm_transcoder (bool value);
		public void set_mp2ts_transcoder (bool value);
		public void set_mp3_transcoder (bool value);
		public void set_port (int value);
		public void set_string (string section, string key, string value);
		public void set_string_list (string section, string key, Gee.ArrayList<string> str_list);
		public void set_transcoding (bool value);
		public void set_upnp_enabled (bool value);
		public void set_wmv_transcoder (bool value);
	}
	[CCode (ref_function = "rygel_xml_utils_ref", unref_function = "rygel_xml_utils_unref", cheader_filename = "rygel.h")]
	public class XMLUtils {
		public XMLUtils ();
		public static Xml.Node* get_element (Xml.Node* node, ...);
	}
	[CCode (cheader_filename = "rygel.h")]
	public interface Configuration : GLib.Object {
		public abstract bool get_bool (string section, string key) throws GLib.Error;
		public abstract bool get_enabled (string section) throws GLib.Error;
		public abstract int get_int (string section, string key, int min, int max) throws GLib.Error;
		public abstract Gee.ArrayList<int> get_int_list (string section, string key) throws GLib.Error;
		public abstract string get_interface () throws GLib.Error;
		public abstract Rygel.LogLevel get_log_level () throws GLib.Error;
		public abstract bool get_lpcm_transcoder () throws GLib.Error;
		public abstract bool get_mp2ts_transcoder () throws GLib.Error;
		public abstract bool get_mp3_transcoder () throws GLib.Error;
		public abstract string get_plugin_path () throws GLib.Error;
		public abstract int get_port () throws GLib.Error;
		public abstract string get_string (string section, string key) throws GLib.Error;
		public abstract Gee.ArrayList<string> get_string_list (string section, string key) throws GLib.Error;
		public abstract string get_title (string section) throws GLib.Error;
		public abstract bool get_transcoding () throws GLib.Error;
		public abstract bool get_upnp_enabled () throws GLib.Error;
		public abstract bool get_wmv_transcoder () throws GLib.Error;
	}
	[CCode (cheader_filename = "rygel.h")]
	public interface StateMachine : GLib.Object {
		public abstract async void run ();
		public abstract GLib.Cancellable cancellable { get; set; }
		public signal void completed ();
	}
	[CCode (cprefix = "RYGEL_LOG_LEVEL_", cheader_filename = "rygel.h")]
	public enum LogLevel {
		INVALID,
		CRITICAL,
		ERROR,
		WARNING,
		INFO,
		DEFAULT,
		DEBUG
	}
	[CCode (cprefix = "RYGEL_LOGICAL_OPERATOR_", cheader_filename = "rygel.h")]
	public enum LogicalOperator {
		AND,
		OR
	}
	[CCode (cprefix = "RYGEL_CMDLINE_CONFIG_ERROR_", cheader_filename = "rygel.h")]
	public errordomain CmdlineConfigError {
		VERSION_ONLY,
	}
	[CCode (cprefix = "RYGEL_CONFIGURATION_ERROR_", cheader_filename = "rygel.h")]
	public errordomain ConfigurationError {
		NO_VALUE_SET,
		VALUE_OUT_OF_RANGE,
	}
	[CCode (cprefix = "RYGEL_CONTENT_DIRECTORY_ERROR_", cheader_filename = "rygel.h")]
	public errordomain ContentDirectoryError {
		NO_SUCH_OBJECT,
		BAD_METADATA,
		RESTRICTED_PARENT,
		CANT_PROCESS,
		INVALID_ARGS,
	}
}
[CCode (cprefix = "ROOT_DEVICE_FACTORY_ERROR_", cheader_filename = "rygel.h")]
public errordomain RootDeviceFactoryError {
	XML_PARSE,
}
[CCode (cheader_filename = "uuid/uuid.h")]
public static void uuid_generate ([CCode (array_length = false)] uchar[] uuid);
[CCode (cheader_filename = "uuid/uuid.h")]
public static void uuid_unparse ([CCode (array_length = false)] uchar[] uuid, [CCode (array_length = false)] uchar[] output);
