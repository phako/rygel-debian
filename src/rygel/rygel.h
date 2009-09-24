
#ifndef __RYGEL_H__
#define __RYGEL_H__

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gee.h>
#include <libgupnp/gupnp.h>
#include <gio/gio.h>
#include <gst/gst.h>

G_BEGIN_DECLS


#define RYGEL_TYPE_CONFIGURATION (rygel_configuration_get_type ())
#define RYGEL_CONFIGURATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_CONFIGURATION, RygelConfiguration))
#define RYGEL_IS_CONFIGURATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_CONFIGURATION))
#define RYGEL_CONFIGURATION_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), RYGEL_TYPE_CONFIGURATION, RygelConfigurationIface))

typedef struct _RygelConfiguration RygelConfiguration;
typedef struct _RygelConfigurationIface RygelConfigurationIface;

#define RYGEL_TYPE_USER_CONFIG (rygel_user_config_get_type ())
#define RYGEL_USER_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_USER_CONFIG, RygelUserConfig))
#define RYGEL_USER_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_USER_CONFIG, RygelUserConfigClass))
#define RYGEL_IS_USER_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_USER_CONFIG))
#define RYGEL_IS_USER_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_USER_CONFIG))
#define RYGEL_USER_CONFIG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_USER_CONFIG, RygelUserConfigClass))

typedef struct _RygelUserConfig RygelUserConfig;
typedef struct _RygelUserConfigClass RygelUserConfigClass;
typedef struct _RygelUserConfigPrivate RygelUserConfigPrivate;

#define RYGEL_TYPE_META_CONFIG (rygel_meta_config_get_type ())
#define RYGEL_META_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_META_CONFIG, RygelMetaConfig))
#define RYGEL_META_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_META_CONFIG, RygelMetaConfigClass))
#define RYGEL_IS_META_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_META_CONFIG))
#define RYGEL_IS_META_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_META_CONFIG))
#define RYGEL_META_CONFIG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_META_CONFIG, RygelMetaConfigClass))

typedef struct _RygelMetaConfig RygelMetaConfig;
typedef struct _RygelMetaConfigClass RygelMetaConfigClass;
typedef struct _RygelMetaConfigPrivate RygelMetaConfigPrivate;

#define RYGEL_TYPE_CMDLINE_CONFIG (rygel_cmdline_config_get_type ())
#define RYGEL_CMDLINE_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_CMDLINE_CONFIG, RygelCmdlineConfig))
#define RYGEL_CMDLINE_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_CMDLINE_CONFIG, RygelCmdlineConfigClass))
#define RYGEL_IS_CMDLINE_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_CMDLINE_CONFIG))
#define RYGEL_IS_CMDLINE_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_CMDLINE_CONFIG))
#define RYGEL_CMDLINE_CONFIG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_CMDLINE_CONFIG, RygelCmdlineConfigClass))

typedef struct _RygelCmdlineConfig RygelCmdlineConfig;
typedef struct _RygelCmdlineConfigClass RygelCmdlineConfigClass;
typedef struct _RygelCmdlineConfigPrivate RygelCmdlineConfigPrivate;

#define RYGEL_TYPE_CONTENT_DIRECTORY (rygel_content_directory_get_type ())
#define RYGEL_CONTENT_DIRECTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_CONTENT_DIRECTORY, RygelContentDirectory))
#define RYGEL_CONTENT_DIRECTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_CONTENT_DIRECTORY, RygelContentDirectoryClass))
#define RYGEL_IS_CONTENT_DIRECTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_CONTENT_DIRECTORY))
#define RYGEL_IS_CONTENT_DIRECTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_CONTENT_DIRECTORY))
#define RYGEL_CONTENT_DIRECTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_CONTENT_DIRECTORY, RygelContentDirectoryClass))

typedef struct _RygelContentDirectory RygelContentDirectory;
typedef struct _RygelContentDirectoryClass RygelContentDirectoryClass;
typedef struct _RygelContentDirectoryPrivate RygelContentDirectoryPrivate;

#define RYGEL_TYPE_MEDIA_OBJECT (rygel_media_object_get_type ())
#define RYGEL_MEDIA_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObject))
#define RYGEL_MEDIA_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObjectClass))
#define RYGEL_IS_MEDIA_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_OBJECT))
#define RYGEL_IS_MEDIA_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_OBJECT))
#define RYGEL_MEDIA_OBJECT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObjectClass))

typedef struct _RygelMediaObject RygelMediaObject;
typedef struct _RygelMediaObjectClass RygelMediaObjectClass;

#define RYGEL_TYPE_MEDIA_CONTAINER (rygel_media_container_get_type ())
#define RYGEL_MEDIA_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainer))
#define RYGEL_MEDIA_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainerClass))
#define RYGEL_IS_MEDIA_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_CONTAINER))
#define RYGEL_IS_MEDIA_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_CONTAINER))
#define RYGEL_MEDIA_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainerClass))

typedef struct _RygelMediaContainer RygelMediaContainer;
typedef struct _RygelMediaContainerClass RygelMediaContainerClass;

#define RYGEL_TYPE_TRANSCODE_MANAGER (rygel_transcode_manager_get_type ())
#define RYGEL_TRANSCODE_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRANSCODE_MANAGER, RygelTranscodeManager))
#define RYGEL_TRANSCODE_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRANSCODE_MANAGER, RygelTranscodeManagerClass))
#define RYGEL_IS_TRANSCODE_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRANSCODE_MANAGER))
#define RYGEL_IS_TRANSCODE_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRANSCODE_MANAGER))
#define RYGEL_TRANSCODE_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRANSCODE_MANAGER, RygelTranscodeManagerClass))

typedef struct _RygelTranscodeManager RygelTranscodeManager;
typedef struct _RygelTranscodeManagerClass RygelTranscodeManagerClass;

#define RYGEL_TYPE_HTTP_SERVER (rygel_http_server_get_type ())
#define RYGEL_HTTP_SERVER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_SERVER, RygelHTTPServer))
#define RYGEL_HTTP_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_SERVER, RygelHTTPServerClass))
#define RYGEL_IS_HTTP_SERVER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_SERVER))
#define RYGEL_IS_HTTP_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_SERVER))
#define RYGEL_HTTP_SERVER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_SERVER, RygelHTTPServerClass))

typedef struct _RygelHTTPServer RygelHTTPServer;
typedef struct _RygelHTTPServerClass RygelHTTPServerClass;

#define RYGEL_TYPE_CONNECTION_MANAGER (rygel_connection_manager_get_type ())
#define RYGEL_CONNECTION_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_CONNECTION_MANAGER, RygelConnectionManager))
#define RYGEL_CONNECTION_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_CONNECTION_MANAGER, RygelConnectionManagerClass))
#define RYGEL_IS_CONNECTION_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_CONNECTION_MANAGER))
#define RYGEL_IS_CONNECTION_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_CONNECTION_MANAGER))
#define RYGEL_CONNECTION_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_CONNECTION_MANAGER, RygelConnectionManagerClass))

typedef struct _RygelConnectionManager RygelConnectionManager;
typedef struct _RygelConnectionManagerClass RygelConnectionManagerClass;
typedef struct _RygelConnectionManagerPrivate RygelConnectionManagerPrivate;

#define RYGEL_TYPE_STATE_MACHINE (rygel_state_machine_get_type ())
#define RYGEL_STATE_MACHINE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_STATE_MACHINE, RygelStateMachine))
#define RYGEL_IS_STATE_MACHINE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_STATE_MACHINE))
#define RYGEL_STATE_MACHINE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), RYGEL_TYPE_STATE_MACHINE, RygelStateMachineIface))

typedef struct _RygelStateMachine RygelStateMachine;
typedef struct _RygelStateMachineIface RygelStateMachineIface;

#define RYGEL_TYPE_RESOURCE_INFO (rygel_resource_info_get_type ())
#define RYGEL_RESOURCE_INFO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_RESOURCE_INFO, RygelResourceInfo))
#define RYGEL_RESOURCE_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_RESOURCE_INFO, RygelResourceInfoClass))
#define RYGEL_IS_RESOURCE_INFO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_RESOURCE_INFO))
#define RYGEL_IS_RESOURCE_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_RESOURCE_INFO))
#define RYGEL_RESOURCE_INFO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_RESOURCE_INFO, RygelResourceInfoClass))

typedef struct _RygelResourceInfo RygelResourceInfo;
typedef struct _RygelResourceInfoClass RygelResourceInfoClass;
typedef struct _RygelResourceInfoPrivate RygelResourceInfoPrivate;

#define RYGEL_TYPE_ICON_INFO (rygel_icon_info_get_type ())
#define RYGEL_ICON_INFO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_ICON_INFO, RygelIconInfo))
#define RYGEL_ICON_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_ICON_INFO, RygelIconInfoClass))
#define RYGEL_IS_ICON_INFO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_ICON_INFO))
#define RYGEL_IS_ICON_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_ICON_INFO))
#define RYGEL_ICON_INFO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_ICON_INFO, RygelIconInfoClass))

typedef struct _RygelIconInfo RygelIconInfo;
typedef struct _RygelIconInfoClass RygelIconInfoClass;
typedef struct _RygelIconInfoPrivate RygelIconInfoPrivate;

#define RYGEL_TYPE_PLUGIN (rygel_plugin_get_type ())
#define RYGEL_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_PLUGIN, RygelPlugin))
#define RYGEL_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_PLUGIN, RygelPluginClass))
#define RYGEL_IS_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_PLUGIN))
#define RYGEL_IS_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_PLUGIN))
#define RYGEL_PLUGIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_PLUGIN, RygelPluginClass))

typedef struct _RygelPlugin RygelPlugin;
typedef struct _RygelPluginClass RygelPluginClass;
typedef struct _RygelPluginPrivate RygelPluginPrivate;

#define RYGEL_TYPE_PLUGIN_LOADER (rygel_plugin_loader_get_type ())
#define RYGEL_PLUGIN_LOADER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_PLUGIN_LOADER, RygelPluginLoader))
#define RYGEL_PLUGIN_LOADER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_PLUGIN_LOADER, RygelPluginLoaderClass))
#define RYGEL_IS_PLUGIN_LOADER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_PLUGIN_LOADER))
#define RYGEL_IS_PLUGIN_LOADER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_PLUGIN_LOADER))
#define RYGEL_PLUGIN_LOADER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_PLUGIN_LOADER, RygelPluginLoaderClass))

typedef struct _RygelPluginLoader RygelPluginLoader;
typedef struct _RygelPluginLoaderClass RygelPluginLoaderClass;
typedef struct _RygelPluginLoaderPrivate RygelPluginLoaderPrivate;
typedef struct _RygelMediaObjectPrivate RygelMediaObjectPrivate;
typedef struct _RygelMediaContainerPrivate RygelMediaContainerPrivate;

#define RYGEL_TYPE_SIMPLE_CONTAINER (rygel_simple_container_get_type ())
#define RYGEL_SIMPLE_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_SIMPLE_CONTAINER, RygelSimpleContainer))
#define RYGEL_SIMPLE_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_SIMPLE_CONTAINER, RygelSimpleContainerClass))
#define RYGEL_IS_SIMPLE_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_SIMPLE_CONTAINER))
#define RYGEL_IS_SIMPLE_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_SIMPLE_CONTAINER))
#define RYGEL_SIMPLE_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_SIMPLE_CONTAINER, RygelSimpleContainerClass))

typedef struct _RygelSimpleContainer RygelSimpleContainer;
typedef struct _RygelSimpleContainerClass RygelSimpleContainerClass;
typedef struct _RygelSimpleContainerPrivate RygelSimpleContainerPrivate;

#define RYGEL_TYPE_SIMPLE_ASYNC_RESULT (rygel_simple_async_result_get_type ())
#define RYGEL_SIMPLE_ASYNC_RESULT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_SIMPLE_ASYNC_RESULT, RygelSimpleAsyncResult))
#define RYGEL_SIMPLE_ASYNC_RESULT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_SIMPLE_ASYNC_RESULT, RygelSimpleAsyncResultClass))
#define RYGEL_IS_SIMPLE_ASYNC_RESULT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_SIMPLE_ASYNC_RESULT))
#define RYGEL_IS_SIMPLE_ASYNC_RESULT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_SIMPLE_ASYNC_RESULT))
#define RYGEL_SIMPLE_ASYNC_RESULT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_SIMPLE_ASYNC_RESULT, RygelSimpleAsyncResultClass))

typedef struct _RygelSimpleAsyncResult RygelSimpleAsyncResult;
typedef struct _RygelSimpleAsyncResultClass RygelSimpleAsyncResultClass;
typedef struct _RygelSimpleAsyncResultPrivate RygelSimpleAsyncResultPrivate;

#define RYGEL_TYPE_MEDIA_ITEM (rygel_media_item_get_type ())
#define RYGEL_MEDIA_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_ITEM, RygelMediaItem))
#define RYGEL_MEDIA_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_ITEM, RygelMediaItemClass))
#define RYGEL_IS_MEDIA_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_ITEM))
#define RYGEL_IS_MEDIA_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_ITEM))
#define RYGEL_MEDIA_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_ITEM, RygelMediaItemClass))

typedef struct _RygelMediaItem RygelMediaItem;
typedef struct _RygelMediaItemClass RygelMediaItemClass;
typedef struct _RygelMediaItemPrivate RygelMediaItemPrivate;

#define RYGEL_TYPE_THUMBNAIL (rygel_thumbnail_get_type ())
#define RYGEL_THUMBNAIL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_THUMBNAIL, RygelThumbnail))
#define RYGEL_THUMBNAIL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_THUMBNAIL, RygelThumbnailClass))
#define RYGEL_IS_THUMBNAIL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_THUMBNAIL))
#define RYGEL_IS_THUMBNAIL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_THUMBNAIL))
#define RYGEL_THUMBNAIL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_THUMBNAIL, RygelThumbnailClass))

typedef struct _RygelThumbnail RygelThumbnail;
typedef struct _RygelThumbnailClass RygelThumbnailClass;
typedef struct _RygelThumbnailPrivate RygelThumbnailPrivate;

#define RYGEL_TYPE_MEDIA_DB_OBJECT_TYPE (rygel_media_db_object_type_get_type ())

#define RYGEL_TYPE_MEDIA_DB (rygel_media_db_get_type ())
#define RYGEL_MEDIA_DB(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_DB, RygelMediaDB))
#define RYGEL_MEDIA_DB_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_DB, RygelMediaDBClass))
#define RYGEL_IS_MEDIA_DB(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_DB))
#define RYGEL_IS_MEDIA_DB_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_DB))
#define RYGEL_MEDIA_DB_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_DB, RygelMediaDBClass))

typedef struct _RygelMediaDB RygelMediaDB;
typedef struct _RygelMediaDBClass RygelMediaDBClass;
typedef struct _RygelMediaDBPrivate RygelMediaDBPrivate;

#define RYGEL_TYPE_MEDIA_DB_OBJECT_FACTORY (rygel_media_db_object_factory_get_type ())
#define RYGEL_MEDIA_DB_OBJECT_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_DB_OBJECT_FACTORY, RygelMediaDBObjectFactory))
#define RYGEL_MEDIA_DB_OBJECT_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_DB_OBJECT_FACTORY, RygelMediaDBObjectFactoryClass))
#define RYGEL_IS_MEDIA_DB_OBJECT_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_DB_OBJECT_FACTORY))
#define RYGEL_IS_MEDIA_DB_OBJECT_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_DB_OBJECT_FACTORY))
#define RYGEL_MEDIA_DB_OBJECT_FACTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_DB_OBJECT_FACTORY, RygelMediaDBObjectFactoryClass))

typedef struct _RygelMediaDBObjectFactory RygelMediaDBObjectFactory;
typedef struct _RygelMediaDBObjectFactoryClass RygelMediaDBObjectFactoryClass;

#define RYGEL_TYPE_METADATA_EXTRACTOR (rygel_metadata_extractor_get_type ())
#define RYGEL_METADATA_EXTRACTOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_METADATA_EXTRACTOR, RygelMetadataExtractor))
#define RYGEL_METADATA_EXTRACTOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_METADATA_EXTRACTOR, RygelMetadataExtractorClass))
#define RYGEL_IS_METADATA_EXTRACTOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_METADATA_EXTRACTOR))
#define RYGEL_IS_METADATA_EXTRACTOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_METADATA_EXTRACTOR))
#define RYGEL_METADATA_EXTRACTOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_METADATA_EXTRACTOR, RygelMetadataExtractorClass))

typedef struct _RygelMetadataExtractor RygelMetadataExtractor;
typedef struct _RygelMetadataExtractorClass RygelMetadataExtractorClass;
typedef struct _RygelMetadataExtractorPrivate RygelMetadataExtractorPrivate;

#define RYGEL_TYPE_MEDIA_DB_CONTAINER (rygel_media_db_container_get_type ())
#define RYGEL_MEDIA_DB_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_DB_CONTAINER, RygelMediaDBContainer))
#define RYGEL_MEDIA_DB_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_DB_CONTAINER, RygelMediaDBContainerClass))
#define RYGEL_IS_MEDIA_DB_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_DB_CONTAINER))
#define RYGEL_IS_MEDIA_DB_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_DB_CONTAINER))
#define RYGEL_MEDIA_DB_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_DB_CONTAINER, RygelMediaDBContainerClass))

typedef struct _RygelMediaDBContainer RygelMediaDBContainer;
typedef struct _RygelMediaDBContainerClass RygelMediaDBContainerClass;
typedef struct _RygelMediaDBContainerPrivate RygelMediaDBContainerPrivate;
typedef struct _RygelMediaDBObjectFactoryPrivate RygelMediaDBObjectFactoryPrivate;

#define RYGEL_TYPE_DBUS_SERVICE (rygel_dbus_service_get_type ())
#define RYGEL_DBUS_SERVICE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_DBUS_SERVICE, RygelDBusService))
#define RYGEL_DBUS_SERVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_DBUS_SERVICE, RygelDBusServiceClass))
#define RYGEL_IS_DBUS_SERVICE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_DBUS_SERVICE))
#define RYGEL_IS_DBUS_SERVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_DBUS_SERVICE))
#define RYGEL_DBUS_SERVICE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_DBUS_SERVICE, RygelDBusServiceClass))

typedef struct _RygelDBusService RygelDBusService;
typedef struct _RygelDBusServiceClass RygelDBusServiceClass;
typedef struct _RygelDBusServicePrivate RygelDBusServicePrivate;

#define RYGEL_TYPE_MAIN (rygel_main_get_type ())
#define RYGEL_MAIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MAIN, RygelMain))
#define RYGEL_MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MAIN, RygelMainClass))
#define RYGEL_IS_MAIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MAIN))
#define RYGEL_IS_MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MAIN))
#define RYGEL_MAIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MAIN, RygelMainClass))

typedef struct _RygelMain RygelMain;
typedef struct _RygelMainClass RygelMainClass;

#define RYGEL_TYPE_ROOT_DEVICE (rygel_root_device_get_type ())
#define RYGEL_ROOT_DEVICE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_ROOT_DEVICE, RygelRootDevice))
#define RYGEL_ROOT_DEVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_ROOT_DEVICE, RygelRootDeviceClass))
#define RYGEL_IS_ROOT_DEVICE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_ROOT_DEVICE))
#define RYGEL_IS_ROOT_DEVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_ROOT_DEVICE))
#define RYGEL_ROOT_DEVICE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_ROOT_DEVICE, RygelRootDeviceClass))

typedef struct _RygelRootDevice RygelRootDevice;
typedef struct _RygelRootDeviceClass RygelRootDeviceClass;
typedef struct _RygelRootDevicePrivate RygelRootDevicePrivate;

#define RYGEL_TYPE_ROOT_DEVICE_FACTORY (rygel_root_device_factory_get_type ())
#define RYGEL_ROOT_DEVICE_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_ROOT_DEVICE_FACTORY, RygelRootDeviceFactory))
#define RYGEL_ROOT_DEVICE_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_ROOT_DEVICE_FACTORY, RygelRootDeviceFactoryClass))
#define RYGEL_IS_ROOT_DEVICE_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_ROOT_DEVICE_FACTORY))
#define RYGEL_IS_ROOT_DEVICE_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_ROOT_DEVICE_FACTORY))
#define RYGEL_ROOT_DEVICE_FACTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_ROOT_DEVICE_FACTORY, RygelRootDeviceFactoryClass))

typedef struct _RygelRootDeviceFactory RygelRootDeviceFactory;
typedef struct _RygelRootDeviceFactoryClass RygelRootDeviceFactoryClass;
typedef struct _RygelRootDeviceFactoryPrivate RygelRootDeviceFactoryPrivate;
typedef struct _RygelMainPrivate RygelMainPrivate;

typedef enum  {
	RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET,
	RYGEL_CONFIGURATION_ERROR_VALUE_OUT_OF_RANGE
} RygelConfigurationError;
#define RYGEL_CONFIGURATION_ERROR rygel_configuration_error_quark ()
struct _RygelConfigurationIface {
	GTypeInterface parent_iface;
	gboolean (*get_upnp_enabled) (RygelConfiguration* self, GError** error);
	char* (*get_interface) (RygelConfiguration* self, GError** error);
	gint (*get_port) (RygelConfiguration* self, GError** error);
	gboolean (*get_transcoding) (RygelConfiguration* self, GError** error);
	gboolean (*get_mp3_transcoder) (RygelConfiguration* self, GError** error);
	gboolean (*get_mp2ts_transcoder) (RygelConfiguration* self, GError** error);
	gboolean (*get_lpcm_transcoder) (RygelConfiguration* self, GError** error);
	gboolean (*get_enabled) (RygelConfiguration* self, const char* section, GError** error);
	char* (*get_title) (RygelConfiguration* self, const char* section, GError** error);
	char* (*get_string) (RygelConfiguration* self, const char* section, const char* key, GError** error);
	GeeArrayList* (*get_string_list) (RygelConfiguration* self, const char* section, const char* key, GError** error);
	gint (*get_int) (RygelConfiguration* self, const char* section, const char* key, gint min, gint max, GError** error);
	GeeArrayList* (*get_int_list) (RygelConfiguration* self, const char* section, const char* key, GError** error);
	gboolean (*get_bool) (RygelConfiguration* self, const char* section, const char* key, GError** error);
};

struct _RygelUserConfig {
	GObject parent_instance;
	RygelUserConfigPrivate * priv;
	GKeyFile* key_file;
};

struct _RygelUserConfigClass {
	GObjectClass parent_class;
};

struct _RygelMetaConfig {
	GObject parent_instance;
	RygelMetaConfigPrivate * priv;
};

struct _RygelMetaConfigClass {
	GObjectClass parent_class;
};

typedef enum  {
	RYGEL_CMDLINE_CONFIG_ERROR_VERSION_ONLY
} RygelCmdlineConfigError;
#define RYGEL_CMDLINE_CONFIG_ERROR rygel_cmdline_config_error_quark ()
struct _RygelCmdlineConfig {
	GObject parent_instance;
	RygelCmdlineConfigPrivate * priv;
};

struct _RygelCmdlineConfigClass {
	GObjectClass parent_class;
};

typedef enum  {
	RYGEL_CONTENT_DIRECTORY_ERROR_NO_SUCH_OBJECT = 701,
	RYGEL_CONTENT_DIRECTORY_ERROR_INVALID_ARGS = 402
} RygelContentDirectoryError;
#define RYGEL_CONTENT_DIRECTORY_ERROR rygel_content_directory_error_quark ()
struct _RygelContentDirectory {
	GUPnPService parent_instance;
	RygelContentDirectoryPrivate * priv;
	char* feature_list;
	char* search_caps;
	char* sort_caps;
	RygelHTTPServer* http_server;
	RygelMediaContainer* root_container;
	GCancellable* cancellable;
	guint32 system_update_id;
};

struct _RygelContentDirectoryClass {
	GUPnPServiceClass parent_class;
	RygelMediaContainer* (*create_root_container) (RygelContentDirectory* self);
	void (*browse_cb) (RygelContentDirectory* self, RygelContentDirectory* content_dir, GUPnPServiceAction* action);
};

struct _RygelConnectionManager {
	GUPnPService parent_instance;
	RygelConnectionManagerPrivate * priv;
	char* sink_protocol_info;
	char* connection_ids;
};

struct _RygelConnectionManagerClass {
	GUPnPServiceClass parent_class;
};

struct _RygelStateMachineIface {
	GTypeInterface parent_iface;
	void (*run) (RygelStateMachine* self);
	GCancellable* (*get_cancellable) (RygelStateMachine* self);
	void (*set_cancellable) (RygelStateMachine* self, GCancellable* value);
};

struct _RygelResourceInfo {
	GTypeInstance parent_instance;
	volatile int ref_count;
	RygelResourceInfoPrivate * priv;
	char* upnp_type;
	char* upnp_id;
	char* description_path;
	GType type;
};

struct _RygelResourceInfoClass {
	GTypeClass parent_class;
	void (*finalize) (RygelResourceInfo *self);
};

struct _RygelIconInfo {
	GTypeInstance parent_instance;
	volatile int ref_count;
	RygelIconInfoPrivate * priv;
	char* mime_type;
	char* path;
	glong size;
	gint width;
	gint height;
	gint depth;
};

struct _RygelIconInfoClass {
	GTypeClass parent_class;
	void (*finalize) (RygelIconInfo *self);
};

struct _RygelPlugin {
	GUPnPResourceFactory parent_instance;
	RygelPluginPrivate * priv;
	char* name;
	char* title;
	char* desc_path;
	GeeArrayList* resource_infos;
	GeeArrayList* icon_infos;
};

struct _RygelPluginClass {
	GUPnPResourceFactoryClass parent_class;
};

struct _RygelPluginLoader {
	GObject parent_instance;
	RygelPluginLoaderPrivate * priv;
};

struct _RygelPluginLoaderClass {
	GObjectClass parent_class;
};

struct _RygelMediaObject {
	GObject parent_instance;
	RygelMediaObjectPrivate * priv;
	char* id;
	char* title;
	guint64 modified;
	GeeArrayList* uris;
	RygelMediaContainer* parent;
	RygelMediaContainer* parent_ref;
};

struct _RygelMediaObjectClass {
	GObjectClass parent_class;
};

struct _RygelMediaContainer {
	RygelMediaObject parent_instance;
	RygelMediaContainerPrivate * priv;
	guint child_count;
	guint32 update_id;
};

struct _RygelMediaContainerClass {
	RygelMediaObjectClass parent_class;
	void (*get_children) (RygelMediaContainer* self, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target);
	GeeList* (*get_children_finish) (RygelMediaContainer* self, GAsyncResult* res, GError** error);
	void (*find_object) (RygelMediaContainer* self, const char* id, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target);
	RygelMediaObject* (*find_object_finish) (RygelMediaContainer* self, GAsyncResult* res, GError** error);
};

struct _RygelSimpleContainer {
	RygelMediaContainer parent_instance;
	RygelSimpleContainerPrivate * priv;
	GeeArrayList* children;
};

struct _RygelSimpleContainerClass {
	RygelMediaContainerClass parent_class;
};

struct _RygelSimpleAsyncResult {
	GObject parent_instance;
	RygelSimpleAsyncResultPrivate * priv;
	GObject* source_object;
	GAsyncReadyCallback callback;
	gpointer callback_target;
	GDestroyNotify callback_target_destroy_notify;
	gpointer data;
	GError* error;
};

struct _RygelSimpleAsyncResultClass {
	GObjectClass parent_class;
};

struct _RygelMediaItem {
	RygelMediaObject parent_instance;
	RygelMediaItemPrivate * priv;
	char* author;
	char* album;
	char* date;
	char* upnp_class;
	char* mime_type;
	char* dlna_profile;
	glong size;
	glong duration;
	gint bitrate;
	gint sample_freq;
	gint bits_per_sample;
	gint n_audio_channels;
	gint track_number;
	gint width;
	gint height;
	gint pixel_width;
	gint pixel_height;
	gint color_depth;
	GeeArrayList* thumbnails;
};

struct _RygelMediaItemClass {
	RygelMediaObjectClass parent_class;
	GstElement* (*create_stream_source) (RygelMediaItem* self);
	gboolean (*should_stream) (RygelMediaItem* self);
};

struct _RygelThumbnail {
	RygelIconInfo parent_instance;
	RygelThumbnailPrivate * priv;
	char* uri;
	char* dlna_profile;
};

struct _RygelThumbnailClass {
	RygelIconInfoClass parent_class;
};

typedef enum  {
	RYGEL_MEDIA_DB_ERROR_SQLITE_ERROR,
	RYGEL_MEDIA_DB_ERROR_GENERAL_ERROR,
	RYGEL_MEDIA_DB_ERROR_INVALID_TYPE
} RygelMediaDBError;
#define RYGEL_MEDIA_DB_ERROR rygel_media_db_error_quark ()
typedef enum  {
	RYGEL_MEDIA_DB_OBJECT_TYPE_CONTAINER,
	RYGEL_MEDIA_DB_OBJECT_TYPE_ITEM
} RygelMediaDBObjectType;

struct _RygelMediaDB {
	GObject parent_instance;
	RygelMediaDBPrivate * priv;
};

struct _RygelMediaDBClass {
	GObjectClass parent_class;
};

struct _RygelMetadataExtractor {
	GObject parent_instance;
	RygelMetadataExtractorPrivate * priv;
};

struct _RygelMetadataExtractorClass {
	GObjectClass parent_class;
};

struct _RygelMediaDBContainer {
	RygelMediaContainer parent_instance;
	RygelMediaDBContainerPrivate * priv;
	RygelMediaDB* media_db;
};

struct _RygelMediaDBContainerClass {
	RygelMediaContainerClass parent_class;
};

struct _RygelMediaDBObjectFactory {
	GObject parent_instance;
	RygelMediaDBObjectFactoryPrivate * priv;
};

struct _RygelMediaDBObjectFactoryClass {
	GObjectClass parent_class;
	RygelMediaContainer* (*get_container) (RygelMediaDBObjectFactory* self, RygelMediaDB* media_db, const char* id, const char* title, guint child_count);
	RygelMediaItem* (*get_item) (RygelMediaDBObjectFactory* self, RygelMediaDB* media_db, RygelMediaContainer* parent, const char* id, const char* title, const char* upnp_class);
};

struct _RygelDBusService {
	GObject parent_instance;
	RygelDBusServicePrivate * priv;
};

struct _RygelDBusServiceClass {
	GObjectClass parent_class;
};

struct _RygelRootDevice {
	GUPnPRootDevice parent_instance;
	RygelRootDevicePrivate * priv;
	GeeArrayList* services;
};

struct _RygelRootDeviceClass {
	GUPnPRootDeviceClass parent_class;
};

typedef enum  {
	ROOT_DEVICE_FACTORY_ERROR_XML_PARSE,
	ROOT_DEVICE_FACTORY_ERROR_PLUGIN_DISABLED
} RootDeviceFactoryError;
#define ROOT_DEVICE_FACTORY_ERROR root_device_factory_error_quark ()
struct _RygelRootDeviceFactory {
	GTypeInstance parent_instance;
	volatile int ref_count;
	RygelRootDeviceFactoryPrivate * priv;
	GUPnPContext* context;
};

struct _RygelRootDeviceFactoryClass {
	GTypeClass parent_class;
	void (*finalize) (RygelRootDeviceFactory *self);
};

struct _RygelMain {
	GObject parent_instance;
	RygelMainPrivate * priv;
};

struct _RygelMainClass {
	GObjectClass parent_class;
};


GQuark rygel_configuration_error_quark (void);
GType rygel_configuration_get_type (void);
gboolean rygel_configuration_get_upnp_enabled (RygelConfiguration* self, GError** error);
char* rygel_configuration_get_interface (RygelConfiguration* self, GError** error);
gint rygel_configuration_get_port (RygelConfiguration* self, GError** error);
gboolean rygel_configuration_get_transcoding (RygelConfiguration* self, GError** error);
gboolean rygel_configuration_get_mp3_transcoder (RygelConfiguration* self, GError** error);
gboolean rygel_configuration_get_mp2ts_transcoder (RygelConfiguration* self, GError** error);
gboolean rygel_configuration_get_lpcm_transcoder (RygelConfiguration* self, GError** error);
gboolean rygel_configuration_get_enabled (RygelConfiguration* self, const char* section, GError** error);
char* rygel_configuration_get_title (RygelConfiguration* self, const char* section, GError** error);
char* rygel_configuration_get_string (RygelConfiguration* self, const char* section, const char* key, GError** error);
GeeArrayList* rygel_configuration_get_string_list (RygelConfiguration* self, const char* section, const char* key, GError** error);
gint rygel_configuration_get_int (RygelConfiguration* self, const char* section, const char* key, gint min, gint max, GError** error);
GeeArrayList* rygel_configuration_get_int_list (RygelConfiguration* self, const char* section, const char* key, GError** error);
gboolean rygel_configuration_get_bool (RygelConfiguration* self, const char* section, const char* key, GError** error);
GType rygel_user_config_get_type (void);
#define RYGEL_USER_CONFIG_CONFIG_FILE "rygel.conf"
#define RYGEL_USER_CONFIG_IFACE_KEY "interface"
#define RYGEL_USER_CONFIG_PORT_KEY "port"
#define RYGEL_USER_CONFIG_ENABLED_KEY "enabled"
#define RYGEL_USER_CONFIG_TITLE_KEY "title"
#define RYGEL_USER_CONFIG_TRANSCODING_KEY "enable-transcoding"
#define RYGEL_USER_CONFIG_MP3_TRANSCODER_KEY "enable-mp3-transcoder"
#define RYGEL_USER_CONFIG_MP2TS_TRANSCODER_KEY "enable-mp2ts-transcoder"
#define RYGEL_USER_CONFIG_LPCM_TRANSCODER_KEY "enable-lpcm-transcoder"
void rygel_user_config_set_upnp_enabled (RygelUserConfig* self, gboolean value);
void rygel_user_config_set_interface (RygelUserConfig* self, const char* value);
void rygel_user_config_set_port (RygelUserConfig* self, gint value);
void rygel_user_config_set_transcoding (RygelUserConfig* self, gboolean value);
void rygel_user_config_set_mp3_transcoder (RygelUserConfig* self, gboolean value);
void rygel_user_config_set_mp2ts_transcoder (RygelUserConfig* self, gboolean value);
void rygel_user_config_set_lpcm_transcoder (RygelUserConfig* self, gboolean value);
RygelUserConfig* rygel_user_config_get_default (GError** error);
RygelUserConfig* rygel_user_config_new (gboolean read_only, GError** error);
RygelUserConfig* rygel_user_config_construct (GType object_type, gboolean read_only, GError** error);
void rygel_user_config_save (RygelUserConfig* self);
void rygel_user_config_set_string (RygelUserConfig* self, const char* section, const char* key, const char* value);
void rygel_user_config_set_string_list (RygelUserConfig* self, const char* section, const char* key, GeeArrayList* str_list);
void rygel_user_config_set_int (RygelUserConfig* self, const char* section, const char* key, gint value);
void rygel_user_config_set_bool (RygelUserConfig* self, const char* section, const char* key, gboolean value);
GType rygel_meta_config_get_type (void);
RygelMetaConfig* rygel_meta_config_get_default (void);
RygelMetaConfig* rygel_meta_config_new (void);
RygelMetaConfig* rygel_meta_config_construct (GType object_type);
GQuark rygel_cmdline_config_error_quark (void);
GType rygel_cmdline_config_get_type (void);
RygelCmdlineConfig* rygel_cmdline_config_get_default (void);
void rygel_cmdline_config_parse_args (char*** args, int* args_length1, GError** error);
RygelCmdlineConfig* rygel_cmdline_config_new (void);
RygelCmdlineConfig* rygel_cmdline_config_construct (GType object_type);
GQuark rygel_content_directory_error_quark (void);
GType rygel_content_directory_get_type (void);
GType rygel_media_object_get_type (void);
GType rygel_media_container_get_type (void);
GType rygel_transcode_manager_get_type (void);
GType rygel_http_server_get_type (void);
#define RYGEL_CONTENT_DIRECTORY_UPNP_ID "urn:upnp-org:serviceId:ContentDirectory"
#define RYGEL_CONTENT_DIRECTORY_UPNP_TYPE "urn:schemas-upnp-org:service:ContentDirectory:2"
#define RYGEL_CONTENT_DIRECTORY_DESCRIPTION_PATH "xml/ContentDirectory.xml"
RygelMediaContainer* rygel_content_directory_create_root_container (RygelContentDirectory* self);
RygelContentDirectory* rygel_content_directory_new (void);
RygelContentDirectory* rygel_content_directory_construct (GType object_type);
GType rygel_connection_manager_get_type (void);
#define RYGEL_CONNECTION_MANAGER_UPNP_ID "urn:upnp-org:serviceId:ConnectionManager"
#define RYGEL_CONNECTION_MANAGER_UPNP_TYPE "urn:schemas-upnp-org:service:ConnectionManager:2"
#define RYGEL_CONNECTION_MANAGER_DESCRIPTION_PATH "xml/ConnectionManager.xml"
RygelConnectionManager* rygel_connection_manager_new (void);
RygelConnectionManager* rygel_connection_manager_construct (GType object_type);
char* rygel_connection_manager_get_source_protocol_info (RygelConnectionManager* self);
GType rygel_state_machine_get_type (void);
void rygel_state_machine_run (RygelStateMachine* self);
GCancellable* rygel_state_machine_get_cancellable (RygelStateMachine* self);
void rygel_state_machine_set_cancellable (RygelStateMachine* self, GCancellable* value);
gpointer rygel_resource_info_ref (gpointer instance);
void rygel_resource_info_unref (gpointer instance);
GParamSpec* rygel_param_spec_resource_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_resource_info (GValue* value, gpointer v_object);
gpointer rygel_value_get_resource_info (const GValue* value);
GType rygel_resource_info_get_type (void);
RygelResourceInfo* rygel_resource_info_new (const char* upnp_id, const char* upnp_type, const char* description_path, GType type);
RygelResourceInfo* rygel_resource_info_construct (GType object_type, const char* upnp_id, const char* upnp_type, const char* description_path, GType type);
gpointer rygel_icon_info_ref (gpointer instance);
void rygel_icon_info_unref (gpointer instance);
GParamSpec* rygel_param_spec_icon_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_icon_info (GValue* value, gpointer v_object);
gpointer rygel_value_get_icon_info (const GValue* value);
GType rygel_icon_info_get_type (void);
RygelIconInfo* rygel_icon_info_new (const char* mime_type);
RygelIconInfo* rygel_icon_info_construct (GType object_type, const char* mime_type);
GType rygel_plugin_get_type (void);
RygelPlugin* rygel_plugin_new (const char* desc_path, const char* name, const char* title);
RygelPlugin* rygel_plugin_construct (GType object_type, const char* desc_path, const char* name, const char* title);
RygelPlugin* rygel_plugin_new_MediaServer (const char* name, const char* title);
RygelPlugin* rygel_plugin_construct_MediaServer (GType object_type, const char* name, const char* title);
void rygel_plugin_add_resource (RygelPlugin* self, RygelResourceInfo* resource_info);
void rygel_plugin_add_icon (RygelPlugin* self, RygelIconInfo* icon_info);
gboolean rygel_plugin_get_available (RygelPlugin* self);
void rygel_plugin_set_available (RygelPlugin* self, gboolean value);
GType rygel_plugin_loader_get_type (void);
RygelPluginLoader* rygel_plugin_loader_new (void);
RygelPluginLoader* rygel_plugin_loader_construct (GType object_type);
void rygel_plugin_loader_load_plugins (RygelPluginLoader* self);
void rygel_plugin_loader_add_plugin (RygelPluginLoader* self, RygelPlugin* plugin);
RygelPlugin* rygel_plugin_loader_get_plugin_by_name (RygelPluginLoader* self, const char* name);
GeeCollection* rygel_plugin_loader_list_plugins (RygelPluginLoader* self);
RygelMediaObject* rygel_media_object_construct (GType object_type);
RygelMediaContainer* rygel_media_container_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title, guint child_count);
RygelMediaContainer* rygel_media_container_construct_root (GType object_type, const char* title, guint child_count);
void rygel_media_container_get_children (RygelMediaContainer* self, guint offset, guint max_count, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target);
GeeList* rygel_media_container_get_children_finish (RygelMediaContainer* self, GAsyncResult* res, GError** error);
void rygel_media_container_find_object (RygelMediaContainer* self, const char* id, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target);
RygelMediaObject* rygel_media_container_find_object_finish (RygelMediaContainer* self, GAsyncResult* res, GError** error);
void rygel_media_container_updated (RygelMediaContainer* self);
GType rygel_simple_container_get_type (void);
RygelSimpleContainer* rygel_simple_container_new (const char* id, RygelMediaContainer* parent, const char* title);
RygelSimpleContainer* rygel_simple_container_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title);
RygelSimpleContainer* rygel_simple_container_new_root (const char* title);
RygelSimpleContainer* rygel_simple_container_construct_root (GType object_type, const char* title);
void rygel_simple_container_add_child (RygelSimpleContainer* self, RygelMediaObject* child);
void rygel_simple_container_remove_child (RygelSimpleContainer* self, RygelMediaObject* child);
GType rygel_simple_async_result_get_type (void);
RygelSimpleAsyncResult* rygel_simple_async_result_new (GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, GObject* source_object, GAsyncReadyCallback callback, void* callback_target);
RygelSimpleAsyncResult* rygel_simple_async_result_construct (GType object_type, GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, GObject* source_object, GAsyncReadyCallback callback, void* callback_target);
void rygel_simple_async_result_complete (RygelSimpleAsyncResult* self);
void rygel_simple_async_result_complete_in_idle (RygelSimpleAsyncResult* self);
GType rygel_media_item_get_type (void);
GType rygel_thumbnail_get_type (void);
#define RYGEL_MEDIA_ITEM_IMAGE_CLASS "object.item.imageItem"
#define RYGEL_MEDIA_ITEM_VIDEO_CLASS "object.item.videoItem"
#define RYGEL_MEDIA_ITEM_AUDIO_CLASS "object.item.audioItem"
#define RYGEL_MEDIA_ITEM_MUSIC_CLASS "object.item.audioItem.musicTrack"
RygelMediaItem* rygel_media_item_new (const char* id, RygelMediaContainer* parent, const char* title, const char* upnp_class);
RygelMediaItem* rygel_media_item_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title, const char* upnp_class);
GstElement* rygel_media_item_create_stream_source (RygelMediaItem* self);
gboolean rygel_media_item_should_stream (RygelMediaItem* self);
void rygel_media_item_add_uri (RygelMediaItem* self, const char* uri, RygelThumbnail* thumbnail);
RygelThumbnail* rygel_thumbnail_new (const char* mime_type, const char* dlna_profile);
RygelThumbnail* rygel_thumbnail_construct (GType object_type, const char* mime_type, const char* dlna_profile);
GQuark rygel_media_db_error_quark (void);
GType rygel_media_db_object_type_get_type (void);
GType rygel_media_db_get_type (void);
RygelMediaDB* rygel_media_db_create (const char* name, GError** error);
GType rygel_media_db_object_factory_get_type (void);
RygelMediaDB* rygel_media_db_create_with_factory (const char* name, RygelMediaDBObjectFactory* factory, GError** error);
void rygel_media_db_remove_by_id (RygelMediaDB* self, const char* id, GError** error);
void rygel_media_db_remove_object (RygelMediaDB* self, RygelMediaObject* obj, GError** error);
void rygel_media_db_save_object (RygelMediaDB* self, RygelMediaObject* obj, GError** error);
void rygel_media_db_save_container (RygelMediaDB* self, RygelMediaContainer* container, GError** error);
void rygel_media_db_save_item (RygelMediaDB* self, RygelMediaItem* item, GError** error);
void rygel_media_db_update_object (RygelMediaDB* self, RygelMediaObject* obj, GError** error);
RygelMediaObject* rygel_media_db_get_object (RygelMediaDB* self, const char* object_id, GError** error);
RygelMediaItem* rygel_media_db_get_item (RygelMediaDB* self, const char* item_id, GError** error);
RygelMediaContainer* rygel_media_db_get_container (RygelMediaDB* self, const char* container_id, GError** error);
GeeArrayList* rygel_media_db_get_child_ids (RygelMediaDB* self, const char* container_id, GError** error);
gint rygel_media_db_get_child_count (RygelMediaDB* self, const char* container_id, GError** error);
gboolean rygel_media_db_exists (RygelMediaDB* self, const char* object_id, gint64* timestamp, GError** error);
GeeArrayList* rygel_media_db_get_children (RygelMediaDB* self, const char* container_id, glong offset, glong max_count);
GType rygel_metadata_extractor_get_type (void);
#define RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_SIZE "rygel-size"
#define RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_DURATION "rygel-duration"
#define RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_MIME "rygel-mime"
#define RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_CHANNELS "rygel-channels"
#define RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_RATE "rygel-rate"
#define RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_WIDTH "rygel-width"
#define RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_HEIGHT "rygel-height"
#define RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_DEPTH "rygel-depth"
#define RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_MTIME "rygel-mtime"
RygelMetadataExtractor* rygel_metadata_extractor_new (void);
RygelMetadataExtractor* rygel_metadata_extractor_construct (GType object_type);
void rygel_metadata_extractor_extract (RygelMetadataExtractor* self, GFile* file);
GType rygel_media_db_container_get_type (void);
RygelMediaDBContainer* rygel_media_db_container_new (RygelMediaDB* media_db, const char* id, const char* title);
RygelMediaDBContainer* rygel_media_db_container_construct (GType object_type, RygelMediaDB* media_db, const char* id, const char* title);
RygelMediaContainer* rygel_media_db_object_factory_get_container (RygelMediaDBObjectFactory* self, RygelMediaDB* media_db, const char* id, const char* title, guint child_count);
RygelMediaItem* rygel_media_db_object_factory_get_item (RygelMediaDBObjectFactory* self, RygelMediaDB* media_db, RygelMediaContainer* parent, const char* id, const char* title, const char* upnp_class);
RygelMediaDBObjectFactory* rygel_media_db_object_factory_new (void);
RygelMediaDBObjectFactory* rygel_media_db_object_factory_construct (GType object_type);
GType rygel_dbus_service_get_type (void);
GType rygel_main_get_type (void);
RygelDBusService* rygel_dbus_service_new (RygelMain* main, GError** error);
RygelDBusService* rygel_dbus_service_construct (GType object_type, RygelMain* main, GError** error);
void rygel_dbus_service_Shutdown (RygelDBusService* self);
GType rygel_root_device_get_type (void);
RygelRootDevice* rygel_root_device_new (GUPnPContext* context, RygelPlugin* plugin, GUPnPXMLDoc* description_doc, const char* description_path, const char* description_dir);
RygelRootDevice* rygel_root_device_construct (GType object_type, GUPnPContext* context, RygelPlugin* plugin, GUPnPXMLDoc* description_doc, const char* description_path, const char* description_dir);
GQuark root_device_factory_error_quark (void);
gpointer rygel_root_device_factory_ref (gpointer instance);
void rygel_root_device_factory_unref (gpointer instance);
GParamSpec* rygel_param_spec_root_device_factory (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void rygel_value_set_root_device_factory (GValue* value, gpointer v_object);
gpointer rygel_value_get_root_device_factory (const GValue* value);
GType rygel_root_device_factory_get_type (void);
RygelRootDeviceFactory* rygel_root_device_factory_new (GUPnPContext* context, GError** error);
RygelRootDeviceFactory* rygel_root_device_factory_construct (GType object_type, GUPnPContext* context, GError** error);
RygelRootDevice* rygel_root_device_factory_create (RygelRootDeviceFactory* self, RygelPlugin* plugin, GError** error);
void rygel_main_exit (RygelMain* self, gint exit_code);


G_END_DECLS

#endif
