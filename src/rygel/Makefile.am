if UNINSTALLED
shareddir = $(abs_top_builddir)/data
desktopdir = $(shareddir)
plugindir = $(abs_top_builddir)/src/plugins
smallicondir = $(shareddir)/icons/32x32
bigicondir = $(shareddir)/icons/256x256
else
shareddir = $(datadir)/rygel
desktopdir = $(datadir)/applications
plugindir = $(libdir)/rygel-1.0
smallicondir = $(datadir)/icons/hicolor/32x32/apps
bigicondir = $(datadir)/icons/hicolor/256x256/apps
endif

AM_CFLAGS = $(LIBGUPNP_CFLAGS) \
	    $(LIBGUPNP_AV_CFLAGS) \
	    $(LIBGSTREAMER_CFLAGS) \
	    $(GIO_CFLAGS) \
	    $(GEE_CFLAGS) \
	    $(UUID_CFLAGS) \
	    $(LIBSOUP_CFLAGS) \
	    $(LIBDBUS_GLIB_CFLAGS) \
	    -I$(top_srcdir) \
	    -DDATA_DIR='"$(shareddir)"' -DSYS_CONFIG_DIR='"$(sysconfdir)"'\
	    -DPLUGIN_DIR='"$(plugindir)"' -DDESKTOP_DIR='"$(desktopdir)"'\
	    -DSMALL_ICON_DIR='"$(smallicondir)"' \
	    -DBIG_ICON_DIR='"$(bigicondir)"' -include config.h

librygelincdir = $(includedir)/rygel-1.0

librygelinc_HEADERS = rygel.h

bin_PROGRAMS = rygel

BUILT_SOURCES = rygel-1.0.vapi \
		rygel.h

rygel_SOURCES = $(VAPI_SOURCE_FILES) \
		rygel-http-item-uri.vala \
		rygel-dbus-service.vala \
		rygel-root-device.vala \
		rygel-root-device-factory.vala \
		rygel-xml-utils.vala \
		rygel-signal-handler.vala \
		rygel-main.vala

VAPI_SOURCE_FILES = rygel-configuration.vala \
		    rygel-user-config.vala \
		    rygel-meta-config.vala \
		    rygel-cmdline-config.vala \
		    rygel-environment-config.vala \
		    rygel-content-directory.vala \
		    rygel-connection-manager.vala \
		    rygel-source-connection-manager.vala \
		    rygel-sink-connection-manager.vala \
		    rygel-av-transport.vala \
		    rygel-rendering-control.vala \
		    rygel-transcode-manager.vala \
		    rygel-http-server.vala \
		    rygel-state-machine.vala \
		    rygel-http-request.vala \
		    rygel-http-get-handler.vala \
		    rygel-http-get.vala \
		    rygel-http-post.vala \
		    rygel-http-identity-handler.vala \
		    rygel-http-transcode-handler.vala \
		    rygel-http-seek.vala \
		    rygel-http-byte-seek.vala \
		    rygel-http-time-seek.vala \
		    rygel-http-response.vala \
		    rygel-live-response.vala \
		    rygel-seekable-response.vala \
		    rygel-resource-info.vala \
		    rygel-icon-info.vala \
		    rygel-plugin.vala \
		    rygel-media-server-plugin.vala \
		    rygel-media-renderer-plugin.vala \
		    rygel-plugin-loader.vala \
		    rygel-media-object.vala \
		    rygel-media-objects.vala \
		    rygel-media-container.vala \
		    rygel-simple-container.vala \
		    rygel-media-item.vala \
		    rygel-thumbnail.vala \
		    rygel-thumbnailer.vala \
		    rygel-album-art.vala \
		    rygel-media-art-store.vala \
		    rygel-subtitle.vala \
		    rygel-subtitle-manager.vala \
		    rygel-media-query-action.vala \
		    rygel-browse.vala \
		    rygel-search.vala \
		    rygel-xbox-hacks.vala \
		    rygel-import-resource.vala \
		    rygel-item-creator.vala \
		    rygel-search-expression.vala \
		    rygel-relational-expression.vala \
		    rygel-logical-expression.vala \
		    rygel-search-criteria-parser.vala \
		    rygel-didl-lite-writer.vala \
		    rygel-transcoder.vala \
		    rygel-mp2ts-transcoder.vala \
		    rygel-mp3-transcoder.vala \
		    rygel-l16-transcoder.vala \
		    rygel-mp2ts-transcoder-bin.vala \
		    rygel-mp3-transcoder-bin.vala \
		    rygel-l16-transcoder-bin.vala \
		    rygel-wma-transcoder.vala \
		    rygel-wma-transcoder-bin.vala \
		    rygel-wmv-transcoder.vala \
		    rygel-wmv-transcoder-bin.vala \
		    rygel-gst-utils.vala \
		    rygel-media-receiver-registrar.vala \
		    rygel-log-handler.vala \
		    rygel-media-player.vala \
		    rygel-changelog.vala \
		    rygel-volume.vala

rygel_VALAFLAGS = \
	-H rygel.h -C --library=rygel-1.0 --vapidir=$(srcdir) --thread \
	--pkg rygel-build-config --pkg rygel-misc --pkg gupnp-1.0 \
	--pkg gupnp-av-1.0 --pkg dbus-glib-1 --pkg gstreamer-0.10 \
	--pkg gio-2.0 --pkg gee-1.0 --pkg posix -g
# Note:  `-- the -g needs to be at the end of VALAFLAGS to not break make dist

rygel_LDADD = librygel-configuration.a \
	      $(LIBGUPNP_LIBS) \
	      $(LIBGUPNP_AV_LIBS) \
	      $(LIBGSTREAMER_LIBS) \
	      $(GIO_LIBS) \
	      $(GEE_LIBS) \
	      $(UUID_LIBS) \
	      $(LIBSOUP_LIBS) \
	      $(LIBDBUS_GLIB_LIBS)

rygel_LDFLAGS = -export-dynamic

VAPI_FILES = rygel-1.0.vapi
DEPS_FILES = rygel-1.0.deps

vapidir = $(VAPIDIR)
vapi_DATA = $(VAPI_FILES) $(DEPS_FILES)
rygel-1.0.vapi rygel.h: $(VAPI_SOURCE_FILES)

noinst_LIBRARIES = librygel-configuration.a

librygel_configuration_a_SOURCES = rygel-configuration.c \
				   rygel-user-config.c \
				   rygel-meta-config.c \
				   rygel-cmdline-config.c \
				   rygel-environment-config.c

MAINTAINERCLEANFILES = Makefile.in $(BUILT_SOURCES)
EXTRA_DIST = rygel-build-config.vapi \
             rygel-misc.vapi \
             $(VAPI_FILES) \
             $(DEPS_FILES) \
             $(BUILT_SOURCES)
