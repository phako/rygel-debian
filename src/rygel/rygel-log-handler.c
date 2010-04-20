/* rygel-log-handler.c generated by valac, the Vala compiler
 * generated from rygel-log-handler.vala, do not modify */

/*
 * Copyright (C) 2008 Nokia Corporation.
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

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gee.h>


#define RYGEL_TYPE_LOG_LEVEL (rygel_log_level_get_type ())

#define RYGEL_TYPE_LOG_HANDLER (rygel_log_handler_get_type ())
#define RYGEL_LOG_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_LOG_HANDLER, RygelLogHandler))
#define RYGEL_LOG_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_LOG_HANDLER, RygelLogHandlerClass))
#define RYGEL_IS_LOG_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_LOG_HANDLER))
#define RYGEL_IS_LOG_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_LOG_HANDLER))
#define RYGEL_LOG_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_LOG_HANDLER, RygelLogHandlerClass))

typedef struct _RygelLogHandler RygelLogHandler;
typedef struct _RygelLogHandlerClass RygelLogHandlerClass;
typedef struct _RygelLogHandlerPrivate RygelLogHandlerPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define RYGEL_TYPE_META_CONFIG (rygel_meta_config_get_type ())
#define RYGEL_META_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_META_CONFIG, RygelMetaConfig))
#define RYGEL_META_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_META_CONFIG, RygelMetaConfigClass))
#define RYGEL_IS_META_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_META_CONFIG))
#define RYGEL_IS_META_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_META_CONFIG))
#define RYGEL_META_CONFIG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_META_CONFIG, RygelMetaConfigClass))

typedef struct _RygelMetaConfig RygelMetaConfig;
typedef struct _RygelMetaConfigClass RygelMetaConfigClass;

#define RYGEL_TYPE_CONFIGURATION (rygel_configuration_get_type ())
#define RYGEL_CONFIGURATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_CONFIGURATION, RygelConfiguration))
#define RYGEL_IS_CONFIGURATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_CONFIGURATION))
#define RYGEL_CONFIGURATION_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), RYGEL_TYPE_CONFIGURATION, RygelConfigurationIface))

typedef struct _RygelConfiguration RygelConfiguration;
typedef struct _RygelConfigurationIface RygelConfigurationIface;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

typedef enum  {
	RYGEL_LOG_LEVEL_INVALID = 0,
	RYGEL_LOG_LEVEL_CRITICAL = 1,
	RYGEL_LOG_LEVEL_ERROR = 2,
	RYGEL_LOG_LEVEL_WARNING = 3,
	RYGEL_LOG_LEVEL_INFO = 4,
	RYGEL_LOG_LEVEL_DEFAULT = 4,
	RYGEL_LOG_LEVEL_DEBUG = 5
} RygelLogLevel;

struct _RygelLogHandler {
	GObject parent_instance;
	RygelLogHandlerPrivate * priv;
	GLogLevelFlags levels;
};

struct _RygelLogHandlerClass {
	GObjectClass parent_class;
};

struct _RygelConfigurationIface {
	GTypeInterface parent_iface;
	gboolean (*get_upnp_enabled) (RygelConfiguration* self, GError** error);
	char* (*get_interface) (RygelConfiguration* self, GError** error);
	gint (*get_port) (RygelConfiguration* self, GError** error);
	gboolean (*get_transcoding) (RygelConfiguration* self, GError** error);
	gboolean (*get_mp3_transcoder) (RygelConfiguration* self, GError** error);
	gboolean (*get_mp2ts_transcoder) (RygelConfiguration* self, GError** error);
	gboolean (*get_lpcm_transcoder) (RygelConfiguration* self, GError** error);
	gboolean (*get_wmv_transcoder) (RygelConfiguration* self, GError** error);
	RygelLogLevel (*get_log_level) (RygelConfiguration* self, GError** error);
	gboolean (*get_enabled) (RygelConfiguration* self, const char* section, GError** error);
	char* (*get_title) (RygelConfiguration* self, const char* section, GError** error);
	char* (*get_string) (RygelConfiguration* self, const char* section, const char* key, GError** error);
	GeeArrayList* (*get_string_list) (RygelConfiguration* self, const char* section, const char* key, GError** error);
	gint (*get_int) (RygelConfiguration* self, const char* section, const char* key, gint min, gint max, GError** error);
	GeeArrayList* (*get_int_list) (RygelConfiguration* self, const char* section, const char* key, GError** error);
	gboolean (*get_bool) (RygelConfiguration* self, const char* section, const char* key, GError** error);
};


static RygelLogHandler* rygel_log_handler_log_handler;
static RygelLogHandler* rygel_log_handler_log_handler = NULL;
static gpointer rygel_log_handler_parent_class = NULL;

GType rygel_log_level_get_type (void);
GType rygel_log_handler_get_type (void);
enum  {
	RYGEL_LOG_HANDLER_DUMMY_PROPERTY
};
#define RYGEL_LOG_HANDLER_DEFAULT_LEVELS ((((G_LOG_LEVEL_WARNING | G_LOG_LEVEL_CRITICAL) | G_LOG_LEVEL_ERROR) | G_LOG_LEVEL_MESSAGE) | G_LOG_LEVEL_INFO)
static RygelLogHandler* rygel_log_handler_new (void);
static RygelLogHandler* rygel_log_handler_construct (GType object_type);
RygelLogHandler* rygel_log_handler_get_default (void);
GType rygel_meta_config_get_type (void);
RygelMetaConfig* rygel_meta_config_get_default (void);
GType rygel_configuration_get_type (void);
RygelLogLevel rygel_configuration_get_log_level (RygelConfiguration* self, GError** error);
static GLogLevelFlags rygel_log_handler_log_level_to_flags (RygelLogHandler* self, RygelLogLevel level);
static void rygel_log_handler_log_func (RygelLogHandler* self, const char* log_domain, GLogLevelFlags log_levels, const char* message);
static void _rygel_log_handler_log_func_glog_func (const char* log_domain, GLogLevelFlags log_levels, const char* message, gpointer self);
static void rygel_log_handler_finalize (GObject* obj);



GType rygel_log_level_get_type (void) {
	static volatile gsize rygel_log_level_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_log_level_type_id__volatile)) {
		static const GEnumValue values[] = {{RYGEL_LOG_LEVEL_INVALID, "RYGEL_LOG_LEVEL_INVALID", "invalid"}, {RYGEL_LOG_LEVEL_CRITICAL, "RYGEL_LOG_LEVEL_CRITICAL", "critical"}, {RYGEL_LOG_LEVEL_ERROR, "RYGEL_LOG_LEVEL_ERROR", "error"}, {RYGEL_LOG_LEVEL_WARNING, "RYGEL_LOG_LEVEL_WARNING", "warning"}, {RYGEL_LOG_LEVEL_INFO, "RYGEL_LOG_LEVEL_INFO", "info"}, {RYGEL_LOG_LEVEL_DEFAULT, "RYGEL_LOG_LEVEL_DEFAULT", "default"}, {RYGEL_LOG_LEVEL_DEBUG, "RYGEL_LOG_LEVEL_DEBUG", "debug"}, {0, NULL, NULL}};
		GType rygel_log_level_type_id;
		rygel_log_level_type_id = g_enum_register_static ("RygelLogLevel", values);
		g_once_init_leave (&rygel_log_level_type_id__volatile, rygel_log_level_type_id);
	}
	return rygel_log_level_type_id__volatile;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


#line 45 "rygel-log-handler.vala"
RygelLogHandler* rygel_log_handler_get_default (void) {
#line 152 "rygel-log-handler.c"
	RygelLogHandler* result = NULL;
#line 46 "rygel-log-handler.vala"
	if (rygel_log_handler_log_handler == NULL) {
#line 156 "rygel-log-handler.c"
		RygelLogHandler* _tmp0_;
#line 47 "rygel-log-handler.vala"
		rygel_log_handler_log_handler = (_tmp0_ = rygel_log_handler_new (), _g_object_unref0 (rygel_log_handler_log_handler), _tmp0_);
#line 160 "rygel-log-handler.c"
	}
	result = _g_object_ref0 (rygel_log_handler_log_handler);
#line 50 "rygel-log-handler.vala"
	return result;
#line 165 "rygel-log-handler.c"
}


#line 69 "rygel-log-handler.vala"
static void _rygel_log_handler_log_func_glog_func (const char* log_domain, GLogLevelFlags log_levels, const char* message, gpointer self) {
#line 171 "rygel-log-handler.c"
	rygel_log_handler_log_func (self, log_domain, log_levels, message);
}


#line 53 "rygel-log-handler.vala"
static RygelLogHandler* rygel_log_handler_construct (GType object_type) {
#line 178 "rygel-log-handler.c"
	GError * _inner_error_;
	RygelLogHandler * self;
	RygelMetaConfig* config;
	_inner_error_ = NULL;
#line 53 "rygel-log-handler.vala"
	self = (RygelLogHandler*) g_object_new (object_type, NULL);
#line 55 "rygel-log-handler.vala"
	config = rygel_meta_config_get_default ();
#line 187 "rygel-log-handler.c"
	{
		RygelLogLevel _tmp0_;
#line 58 "rygel-log-handler.vala"
		_tmp0_ = rygel_configuration_get_log_level ((RygelConfiguration*) config, &_inner_error_);
#line 192 "rygel-log-handler.c"
		if (_inner_error_ != NULL) {
			goto __catch69_g_error;
		}
#line 58 "rygel-log-handler.vala"
		self->levels = rygel_log_handler_log_level_to_flags (self, _tmp0_);
#line 198 "rygel-log-handler.c"
	}
	goto __finally69;
	__catch69_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
#line 60 "rygel-log-handler.vala"
			self->levels = RYGEL_LOG_HANDLER_DEFAULT_LEVELS;
#line 62 "rygel-log-handler.vala"
			g_warning ("rygel-log-handler.vala:62: Failed to get log level from configuration " \
"sources: %s", err->message);
#line 211 "rygel-log-handler.c"
			_g_error_free0 (err);
		}
	}
	__finally69:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (config);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
#line 66 "rygel-log-handler.vala"
	g_log_set_default_handler (_rygel_log_handler_log_func_glog_func, self);
#line 224 "rygel-log-handler.c"
	_g_object_unref0 (config);
	return self;
}


#line 53 "rygel-log-handler.vala"
static RygelLogHandler* rygel_log_handler_new (void) {
#line 53 "rygel-log-handler.vala"
	return rygel_log_handler_construct (RYGEL_TYPE_LOG_HANDLER);
#line 234 "rygel-log-handler.c"
}


#line 69 "rygel-log-handler.vala"
static void rygel_log_handler_log_func (RygelLogHandler* self, const char* log_domain, GLogLevelFlags log_levels, const char* message) {
#line 69 "rygel-log-handler.vala"
	g_return_if_fail (self != NULL);
#line 69 "rygel-log-handler.vala"
	g_return_if_fail (message != NULL);
#line 72 "rygel-log-handler.vala"
	if ((self->levels & log_levels) == log_levels) {
#line 74 "rygel-log-handler.vala"
		g_log_default_handler (log_domain, log_levels, message, NULL);
#line 248 "rygel-log-handler.c"
	}
}


#line 78 "rygel-log-handler.vala"
static GLogLevelFlags rygel_log_handler_log_level_to_flags (RygelLogHandler* self, RygelLogLevel level) {
#line 255 "rygel-log-handler.c"
	GLogLevelFlags result = 0;
	GLogLevelFlags flags;
#line 78 "rygel-log-handler.vala"
	g_return_val_if_fail (self != NULL, 0);
#line 79 "rygel-log-handler.vala"
	flags = RYGEL_LOG_HANDLER_DEFAULT_LEVELS;
#line 81 "rygel-log-handler.vala"
	switch (level) {
#line 264 "rygel-log-handler.c"
		case RYGEL_LOG_LEVEL_CRITICAL:
		{
#line 83 "rygel-log-handler.vala"
			flags = G_LOG_LEVEL_CRITICAL;
#line 84 "rygel-log-handler.vala"
			break;
#line 271 "rygel-log-handler.c"
		}
		case RYGEL_LOG_LEVEL_ERROR:
		{
#line 86 "rygel-log-handler.vala"
			flags = G_LOG_LEVEL_CRITICAL | G_LOG_LEVEL_ERROR;
#line 88 "rygel-log-handler.vala"
			break;
#line 279 "rygel-log-handler.c"
		}
		case RYGEL_LOG_LEVEL_WARNING:
		{
#line 90 "rygel-log-handler.vala"
			flags = (G_LOG_LEVEL_WARNING | G_LOG_LEVEL_CRITICAL) | G_LOG_LEVEL_ERROR;
#line 93 "rygel-log-handler.vala"
			break;
#line 287 "rygel-log-handler.c"
		}
		case RYGEL_LOG_LEVEL_INFO:
		{
#line 95 "rygel-log-handler.vala"
			flags = (((G_LOG_LEVEL_WARNING | G_LOG_LEVEL_CRITICAL) | G_LOG_LEVEL_ERROR) | G_LOG_LEVEL_MESSAGE) | G_LOG_LEVEL_INFO;
#line 100 "rygel-log-handler.vala"
			break;
#line 295 "rygel-log-handler.c"
		}
		case RYGEL_LOG_LEVEL_DEBUG:
		{
#line 102 "rygel-log-handler.vala"
			flags = ((((G_LOG_LEVEL_WARNING | G_LOG_LEVEL_CRITICAL) | G_LOG_LEVEL_ERROR) | G_LOG_LEVEL_MESSAGE) | G_LOG_LEVEL_INFO) | G_LOG_LEVEL_DEBUG;
#line 108 "rygel-log-handler.vala"
			break;
#line 303 "rygel-log-handler.c"
		}
		default:
		{
#line 110 "rygel-log-handler.vala"
			flags = RYGEL_LOG_HANDLER_DEFAULT_LEVELS;
#line 111 "rygel-log-handler.vala"
			break;
#line 311 "rygel-log-handler.c"
		}
	}
	result = flags;
#line 114 "rygel-log-handler.vala"
	return result;
#line 317 "rygel-log-handler.c"
}


static void rygel_log_handler_class_init (RygelLogHandlerClass * klass) {
	rygel_log_handler_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = rygel_log_handler_finalize;
}


static void rygel_log_handler_instance_init (RygelLogHandler * self) {
}


static void rygel_log_handler_finalize (GObject* obj) {
	RygelLogHandler * self;
	self = RYGEL_LOG_HANDLER (obj);
	G_OBJECT_CLASS (rygel_log_handler_parent_class)->finalize (obj);
}


GType rygel_log_handler_get_type (void) {
	static volatile gsize rygel_log_handler_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_log_handler_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelLogHandlerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_log_handler_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelLogHandler), 0, (GInstanceInitFunc) rygel_log_handler_instance_init, NULL };
		GType rygel_log_handler_type_id;
		rygel_log_handler_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelLogHandler", &g_define_type_info, 0);
		g_once_init_leave (&rygel_log_handler_type_id__volatile, rygel_log_handler_type_id);
	}
	return rygel_log_handler_type_id__volatile;
}




