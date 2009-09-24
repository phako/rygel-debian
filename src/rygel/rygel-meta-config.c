/*
 * Copyright (C) 2008,2009 Nokia Corporation.
 * Copyright (C) 2008,2009 Zeeshan Ali (Khattak) <zeeshanak@gnome.org>.
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


#define RYGEL_TYPE_CONFIGURATION (rygel_configuration_get_type ())
#define RYGEL_CONFIGURATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_CONFIGURATION, RygelConfiguration))
#define RYGEL_IS_CONFIGURATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_CONFIGURATION))
#define RYGEL_CONFIGURATION_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), RYGEL_TYPE_CONFIGURATION, RygelConfigurationIface))

typedef struct _RygelConfiguration RygelConfiguration;
typedef struct _RygelConfigurationIface RygelConfigurationIface;

#define RYGEL_TYPE_META_CONFIG (rygel_meta_config_get_type ())
#define RYGEL_META_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_META_CONFIG, RygelMetaConfig))
#define RYGEL_META_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_META_CONFIG, RygelMetaConfigClass))
#define RYGEL_IS_META_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_META_CONFIG))
#define RYGEL_IS_META_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_META_CONFIG))
#define RYGEL_META_CONFIG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_META_CONFIG, RygelMetaConfigClass))

typedef struct _RygelMetaConfig RygelMetaConfig;
typedef struct _RygelMetaConfigClass RygelMetaConfigClass;
typedef struct _RygelMetaConfigPrivate RygelMetaConfigPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define RYGEL_TYPE_CMDLINE_CONFIG (rygel_cmdline_config_get_type ())
#define RYGEL_CMDLINE_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_CMDLINE_CONFIG, RygelCmdlineConfig))
#define RYGEL_CMDLINE_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_CMDLINE_CONFIG, RygelCmdlineConfigClass))
#define RYGEL_IS_CMDLINE_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_CMDLINE_CONFIG))
#define RYGEL_IS_CMDLINE_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_CMDLINE_CONFIG))
#define RYGEL_CMDLINE_CONFIG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_CMDLINE_CONFIG, RygelCmdlineConfigClass))

typedef struct _RygelCmdlineConfig RygelCmdlineConfig;
typedef struct _RygelCmdlineConfigClass RygelCmdlineConfigClass;

#define RYGEL_TYPE_USER_CONFIG (rygel_user_config_get_type ())
#define RYGEL_USER_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_USER_CONFIG, RygelUserConfig))
#define RYGEL_USER_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_USER_CONFIG, RygelUserConfigClass))
#define RYGEL_IS_USER_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_USER_CONFIG))
#define RYGEL_IS_USER_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_USER_CONFIG))
#define RYGEL_USER_CONFIG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_USER_CONFIG, RygelUserConfigClass))

typedef struct _RygelUserConfig RygelUserConfig;
typedef struct _RygelUserConfigClass RygelUserConfigClass;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

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

struct _RygelMetaConfig {
	GObject parent_instance;
	RygelMetaConfigPrivate * priv;
};

struct _RygelMetaConfigClass {
	GObjectClass parent_class;
};

struct _RygelMetaConfigPrivate {
	GeeArrayList* configs;
};

typedef enum  {
	RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET,
	RYGEL_CONFIGURATION_ERROR_VALUE_OUT_OF_RANGE
} RygelConfigurationError;
#define RYGEL_CONFIGURATION_ERROR rygel_configuration_error_quark ()

static RygelMetaConfig* rygel_meta_config_meta_config;
static RygelMetaConfig* rygel_meta_config_meta_config = NULL;
static gpointer rygel_meta_config_parent_class = NULL;
static RygelConfigurationIface* rygel_meta_config_rygel_configuration_parent_iface = NULL;

GType rygel_configuration_get_type (void);
GType rygel_meta_config_get_type (void);
#define RYGEL_META_CONFIG_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_META_CONFIG, RygelMetaConfigPrivate))
enum  {
	RYGEL_META_CONFIG_DUMMY_PROPERTY
};
RygelMetaConfig* rygel_meta_config_new (void);
RygelMetaConfig* rygel_meta_config_construct (GType object_type);
RygelMetaConfig* rygel_meta_config_get_default (void);
GType rygel_cmdline_config_get_type (void);
RygelCmdlineConfig* rygel_cmdline_config_get_default (void);
GType rygel_user_config_get_type (void);
RygelUserConfig* rygel_user_config_get_default (GError** error);
gboolean rygel_configuration_get_upnp_enabled (RygelConfiguration* self, GError** error);
GQuark rygel_configuration_error_quark (void);
static gboolean rygel_meta_config_real_get_upnp_enabled (RygelConfiguration* base, GError** error);
char* rygel_configuration_get_interface (RygelConfiguration* self, GError** error);
static char* rygel_meta_config_real_get_interface (RygelConfiguration* base, GError** error);
gint rygel_configuration_get_port (RygelConfiguration* self, GError** error);
static gint rygel_meta_config_real_get_port (RygelConfiguration* base, GError** error);
gboolean rygel_configuration_get_transcoding (RygelConfiguration* self, GError** error);
static gboolean rygel_meta_config_real_get_transcoding (RygelConfiguration* base, GError** error);
gboolean rygel_configuration_get_mp3_transcoder (RygelConfiguration* self, GError** error);
static gboolean rygel_meta_config_real_get_mp3_transcoder (RygelConfiguration* base, GError** error);
gboolean rygel_configuration_get_mp2ts_transcoder (RygelConfiguration* self, GError** error);
static gboolean rygel_meta_config_real_get_mp2ts_transcoder (RygelConfiguration* base, GError** error);
gboolean rygel_configuration_get_lpcm_transcoder (RygelConfiguration* self, GError** error);
static gboolean rygel_meta_config_real_get_lpcm_transcoder (RygelConfiguration* base, GError** error);
gboolean rygel_configuration_get_enabled (RygelConfiguration* self, const char* section, GError** error);
static gboolean rygel_meta_config_real_get_enabled (RygelConfiguration* base, const char* section, GError** error);
char* rygel_configuration_get_title (RygelConfiguration* self, const char* section, GError** error);
static char* rygel_meta_config_real_get_title (RygelConfiguration* base, const char* section, GError** error);
char* rygel_configuration_get_string (RygelConfiguration* self, const char* section, const char* key, GError** error);
static char* rygel_meta_config_real_get_string (RygelConfiguration* base, const char* section, const char* key, GError** error);
GeeArrayList* rygel_configuration_get_string_list (RygelConfiguration* self, const char* section, const char* key, GError** error);
static GeeArrayList* rygel_meta_config_real_get_string_list (RygelConfiguration* base, const char* section, const char* key, GError** error);
gint rygel_configuration_get_int (RygelConfiguration* self, const char* section, const char* key, gint min, gint max, GError** error);
static gint rygel_meta_config_real_get_int (RygelConfiguration* base, const char* section, const char* key, gint min, gint max, GError** error);
GeeArrayList* rygel_configuration_get_int_list (RygelConfiguration* self, const char* section, const char* key, GError** error);
static GeeArrayList* rygel_meta_config_real_get_int_list (RygelConfiguration* base, const char* section, const char* key, GError** error);
gboolean rygel_configuration_get_bool (RygelConfiguration* self, const char* section, const char* key, GError** error);
static gboolean rygel_meta_config_real_get_bool (RygelConfiguration* base, const char* section, const char* key, GError** error);
static void rygel_meta_config_finalize (GObject* obj);



static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


RygelMetaConfig* rygel_meta_config_get_default (void) {
	RygelMetaConfig* result;
	if (rygel_meta_config_meta_config == NULL) {
		RygelMetaConfig* _tmp0_;
		rygel_meta_config_meta_config = (_tmp0_ = rygel_meta_config_new (), _g_object_unref0 (rygel_meta_config_meta_config), _tmp0_);
	}
	result = _g_object_ref0 (rygel_meta_config_meta_config);
	return result;
}


RygelMetaConfig* rygel_meta_config_construct (GType object_type) {
	GError * _inner_error_;
	RygelMetaConfig * self;
	GeeArrayList* _tmp0_;
	RygelCmdlineConfig* _tmp1_;
	_inner_error_ = NULL;
	self = (RygelMetaConfig*) g_object_new (object_type, NULL);
	self->priv->configs = (_tmp0_ = gee_array_list_new (RYGEL_TYPE_CONFIGURATION, (GBoxedCopyFunc) g_object_ref, g_object_unref, g_direct_equal), _g_object_unref0 (self->priv->configs), _tmp0_);
	gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->configs, (RygelConfiguration*) (_tmp1_ = rygel_cmdline_config_get_default ()));
	_g_object_unref0 (_tmp1_);
	{
		RygelUserConfig* user_config;
		user_config = rygel_user_config_get_default (&_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch2_g_error;
			goto __finally2;
		}
		gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->configs, (RygelConfiguration*) user_config);
		_g_object_unref0 (user_config);
	}
	goto __finally2;
	__catch2_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			g_warning ("rygel-meta-config.vala:57: Failed to load user configuration: %s", err->message);
			_g_error_free0 (err);
		}
	}
	__finally2:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	return self;
}


RygelMetaConfig* rygel_meta_config_new (void) {
	return rygel_meta_config_construct (RYGEL_TYPE_META_CONFIG);
}


static gboolean rygel_meta_config_real_get_upnp_enabled (RygelConfiguration* base, GError** error) {
	RygelMetaConfig * self;
	gboolean result;
	GError * _inner_error_;
	gboolean val;
	gboolean unavailable;
	self = (RygelMetaConfig*) base;
	_inner_error_ = NULL;
	val = TRUE;
	unavailable = TRUE;
	{
		GeeIterator* _config_it;
		_config_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->configs);
		while (TRUE) {
			RygelConfiguration* config;
			if (!gee_iterator_next (_config_it)) {
				break;
			}
			config = (RygelConfiguration*) gee_iterator_get (_config_it);
			{
				gboolean _tmp0_;
				_tmp0_ = rygel_configuration_get_upnp_enabled (config, &_inner_error_);
				if (_inner_error_ != NULL) {
					goto __catch3_g_error;
					goto __finally3;
				}
				val = _tmp0_;
				unavailable = FALSE;
				_g_object_unref0 (config);
				break;
			}
			goto __finally3;
			__catch3_g_error:
			{
				GError * err;
				err = _inner_error_;
				_inner_error_ = NULL;
				{
					_g_error_free0 (err);
				}
			}
			__finally3:
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_g_object_unref0 (config);
				_g_object_unref0 (_config_it);
				return FALSE;
			}
			_g_object_unref0 (config);
		}
		_g_object_unref0 (_config_it);
	}
	if (unavailable) {
		_inner_error_ = g_error_new_literal (RYGEL_CONFIGURATION_ERROR, RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET, "No value available");
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			return FALSE;
		}
	}
	result = val;
	return result;
}


static char* rygel_meta_config_real_get_interface (RygelConfiguration* base, GError** error) {
	RygelMetaConfig * self;
	char* result;
	GError * _inner_error_;
	char* val;
	gboolean unavailable;
	self = (RygelMetaConfig*) base;
	_inner_error_ = NULL;
	val = NULL;
	unavailable = TRUE;
	{
		GeeIterator* _config_it;
		_config_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->configs);
		while (TRUE) {
			RygelConfiguration* config;
			if (!gee_iterator_next (_config_it)) {
				break;
			}
			config = (RygelConfiguration*) gee_iterator_get (_config_it);
			{
				char* _tmp0_;
				char* _tmp1_;
				_tmp0_ = rygel_configuration_get_interface (config, &_inner_error_);
				if (_inner_error_ != NULL) {
					goto __catch4_g_error;
					goto __finally4;
				}
				val = (_tmp1_ = _tmp0_, _g_free0 (val), _tmp1_);
				unavailable = FALSE;
				_g_object_unref0 (config);
				break;
			}
			goto __finally4;
			__catch4_g_error:
			{
				GError * err;
				err = _inner_error_;
				_inner_error_ = NULL;
				{
					_g_error_free0 (err);
				}
			}
			__finally4:
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_g_object_unref0 (config);
				_g_object_unref0 (_config_it);
				_g_free0 (val);
				return NULL;
			}
			_g_object_unref0 (config);
		}
		_g_object_unref0 (_config_it);
	}
	if (unavailable) {
		_inner_error_ = g_error_new_literal (RYGEL_CONFIGURATION_ERROR, RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET, "No value available");
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_g_free0 (val);
			return NULL;
		}
	}
	result = val;
	return result;
}


static gint rygel_meta_config_real_get_port (RygelConfiguration* base, GError** error) {
	RygelMetaConfig * self;
	gint result;
	GError * _inner_error_;
	gint val;
	gboolean unavailable;
	self = (RygelMetaConfig*) base;
	_inner_error_ = NULL;
	val = 0;
	unavailable = TRUE;
	{
		GeeIterator* _config_it;
		_config_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->configs);
		while (TRUE) {
			RygelConfiguration* config;
			if (!gee_iterator_next (_config_it)) {
				break;
			}
			config = (RygelConfiguration*) gee_iterator_get (_config_it);
			{
				gint _tmp0_;
				_tmp0_ = rygel_configuration_get_port (config, &_inner_error_);
				if (_inner_error_ != NULL) {
					goto __catch5_g_error;
					goto __finally5;
				}
				val = _tmp0_;
				unavailable = FALSE;
				_g_object_unref0 (config);
				break;
			}
			goto __finally5;
			__catch5_g_error:
			{
				GError * err;
				err = _inner_error_;
				_inner_error_ = NULL;
				{
					_g_error_free0 (err);
				}
			}
			__finally5:
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_g_object_unref0 (config);
				_g_object_unref0 (_config_it);
				return 0;
			}
			_g_object_unref0 (config);
		}
		_g_object_unref0 (_config_it);
	}
	if (unavailable) {
		_inner_error_ = g_error_new_literal (RYGEL_CONFIGURATION_ERROR, RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET, "No value available");
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			return 0;
		}
	}
	result = val;
	return result;
}


static gboolean rygel_meta_config_real_get_transcoding (RygelConfiguration* base, GError** error) {
	RygelMetaConfig * self;
	gboolean result;
	GError * _inner_error_;
	gboolean val;
	gboolean unavailable;
	self = (RygelMetaConfig*) base;
	_inner_error_ = NULL;
	val = TRUE;
	unavailable = TRUE;
	{
		GeeIterator* _config_it;
		_config_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->configs);
		while (TRUE) {
			RygelConfiguration* config;
			if (!gee_iterator_next (_config_it)) {
				break;
			}
			config = (RygelConfiguration*) gee_iterator_get (_config_it);
			{
				gboolean _tmp0_;
				_tmp0_ = rygel_configuration_get_transcoding (config, &_inner_error_);
				if (_inner_error_ != NULL) {
					goto __catch6_g_error;
					goto __finally6;
				}
				val = _tmp0_;
				unavailable = FALSE;
				_g_object_unref0 (config);
				break;
			}
			goto __finally6;
			__catch6_g_error:
			{
				GError * err;
				err = _inner_error_;
				_inner_error_ = NULL;
				{
					_g_error_free0 (err);
				}
			}
			__finally6:
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_g_object_unref0 (config);
				_g_object_unref0 (_config_it);
				return FALSE;
			}
			_g_object_unref0 (config);
		}
		_g_object_unref0 (_config_it);
	}
	if (unavailable) {
		_inner_error_ = g_error_new_literal (RYGEL_CONFIGURATION_ERROR, RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET, "No value available");
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			return FALSE;
		}
	}
	result = val;
	return result;
}


static gboolean rygel_meta_config_real_get_mp3_transcoder (RygelConfiguration* base, GError** error) {
	RygelMetaConfig * self;
	gboolean result;
	GError * _inner_error_;
	gboolean val;
	gboolean unavailable;
	self = (RygelMetaConfig*) base;
	_inner_error_ = NULL;
	val = TRUE;
	unavailable = TRUE;
	{
		GeeIterator* _config_it;
		_config_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->configs);
		while (TRUE) {
			RygelConfiguration* config;
			if (!gee_iterator_next (_config_it)) {
				break;
			}
			config = (RygelConfiguration*) gee_iterator_get (_config_it);
			{
				gboolean _tmp0_;
				_tmp0_ = rygel_configuration_get_mp3_transcoder (config, &_inner_error_);
				if (_inner_error_ != NULL) {
					goto __catch7_g_error;
					goto __finally7;
				}
				val = _tmp0_;
				unavailable = FALSE;
				_g_object_unref0 (config);
				break;
			}
			goto __finally7;
			__catch7_g_error:
			{
				GError * err;
				err = _inner_error_;
				_inner_error_ = NULL;
				{
					_g_error_free0 (err);
				}
			}
			__finally7:
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_g_object_unref0 (config);
				_g_object_unref0 (_config_it);
				return FALSE;
			}
			_g_object_unref0 (config);
		}
		_g_object_unref0 (_config_it);
	}
	if (unavailable) {
		_inner_error_ = g_error_new_literal (RYGEL_CONFIGURATION_ERROR, RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET, "No value available");
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			return FALSE;
		}
	}
	result = val;
	return result;
}


static gboolean rygel_meta_config_real_get_mp2ts_transcoder (RygelConfiguration* base, GError** error) {
	RygelMetaConfig * self;
	gboolean result;
	GError * _inner_error_;
	gboolean val;
	gboolean unavailable;
	self = (RygelMetaConfig*) base;
	_inner_error_ = NULL;
	val = TRUE;
	unavailable = TRUE;
	{
		GeeIterator* _config_it;
		_config_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->configs);
		while (TRUE) {
			RygelConfiguration* config;
			if (!gee_iterator_next (_config_it)) {
				break;
			}
			config = (RygelConfiguration*) gee_iterator_get (_config_it);
			{
				gboolean _tmp0_;
				_tmp0_ = rygel_configuration_get_mp2ts_transcoder (config, &_inner_error_);
				if (_inner_error_ != NULL) {
					goto __catch8_g_error;
					goto __finally8;
				}
				val = _tmp0_;
				unavailable = FALSE;
				_g_object_unref0 (config);
				break;
			}
			goto __finally8;
			__catch8_g_error:
			{
				GError * err;
				err = _inner_error_;
				_inner_error_ = NULL;
				{
					_g_error_free0 (err);
				}
			}
			__finally8:
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_g_object_unref0 (config);
				_g_object_unref0 (_config_it);
				return FALSE;
			}
			_g_object_unref0 (config);
		}
		_g_object_unref0 (_config_it);
	}
	if (unavailable) {
		_inner_error_ = g_error_new_literal (RYGEL_CONFIGURATION_ERROR, RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET, "No value available");
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			return FALSE;
		}
	}
	result = val;
	return result;
}


static gboolean rygel_meta_config_real_get_lpcm_transcoder (RygelConfiguration* base, GError** error) {
	RygelMetaConfig * self;
	gboolean result;
	GError * _inner_error_;
	gboolean val;
	gboolean unavailable;
	self = (RygelMetaConfig*) base;
	_inner_error_ = NULL;
	val = TRUE;
	unavailable = TRUE;
	{
		GeeIterator* _config_it;
		_config_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->configs);
		while (TRUE) {
			RygelConfiguration* config;
			if (!gee_iterator_next (_config_it)) {
				break;
			}
			config = (RygelConfiguration*) gee_iterator_get (_config_it);
			{
				gboolean _tmp0_;
				_tmp0_ = rygel_configuration_get_lpcm_transcoder (config, &_inner_error_);
				if (_inner_error_ != NULL) {
					goto __catch9_g_error;
					goto __finally9;
				}
				val = _tmp0_;
				unavailable = FALSE;
				_g_object_unref0 (config);
				break;
			}
			goto __finally9;
			__catch9_g_error:
			{
				GError * err;
				err = _inner_error_;
				_inner_error_ = NULL;
				{
					_g_error_free0 (err);
				}
			}
			__finally9:
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_g_object_unref0 (config);
				_g_object_unref0 (_config_it);
				return FALSE;
			}
			_g_object_unref0 (config);
		}
		_g_object_unref0 (_config_it);
	}
	if (unavailable) {
		_inner_error_ = g_error_new_literal (RYGEL_CONFIGURATION_ERROR, RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET, "No value available");
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			return FALSE;
		}
	}
	result = val;
	return result;
}


static gboolean rygel_meta_config_real_get_enabled (RygelConfiguration* base, const char* section, GError** error) {
	RygelMetaConfig * self;
	gboolean result;
	GError * _inner_error_;
	gboolean val;
	gboolean unavailable;
	self = (RygelMetaConfig*) base;
	g_return_val_if_fail (section != NULL, FALSE);
	_inner_error_ = NULL;
	val = TRUE;
	unavailable = TRUE;
	{
		GeeIterator* _config_it;
		_config_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->configs);
		while (TRUE) {
			RygelConfiguration* config;
			if (!gee_iterator_next (_config_it)) {
				break;
			}
			config = (RygelConfiguration*) gee_iterator_get (_config_it);
			{
				gboolean _tmp0_;
				_tmp0_ = rygel_configuration_get_enabled (config, section, &_inner_error_);
				if (_inner_error_ != NULL) {
					goto __catch10_g_error;
					goto __finally10;
				}
				val = _tmp0_;
				unavailable = FALSE;
				_g_object_unref0 (config);
				break;
			}
			goto __finally10;
			__catch10_g_error:
			{
				GError * err;
				err = _inner_error_;
				_inner_error_ = NULL;
				{
					_g_error_free0 (err);
				}
			}
			__finally10:
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_g_object_unref0 (config);
				_g_object_unref0 (_config_it);
				return FALSE;
			}
			_g_object_unref0 (config);
		}
		_g_object_unref0 (_config_it);
	}
	if (unavailable) {
		_inner_error_ = g_error_new (RYGEL_CONFIGURATION_ERROR, RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET, "No value available for '%s/enabled'", section);
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			return FALSE;
		}
	}
	result = val;
	return result;
}


static char* rygel_meta_config_real_get_title (RygelConfiguration* base, const char* section, GError** error) {
	RygelMetaConfig * self;
	char* result;
	GError * _inner_error_;
	char* val;
	self = (RygelMetaConfig*) base;
	g_return_val_if_fail (section != NULL, NULL);
	_inner_error_ = NULL;
	val = NULL;
	{
		GeeIterator* _config_it;
		_config_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->configs);
		while (TRUE) {
			RygelConfiguration* config;
			if (!gee_iterator_next (_config_it)) {
				break;
			}
			config = (RygelConfiguration*) gee_iterator_get (_config_it);
			{
				char* _tmp0_;
				char* _tmp1_;
				_tmp0_ = rygel_configuration_get_title (config, section, &_inner_error_);
				if (_inner_error_ != NULL) {
					goto __catch11_g_error;
					goto __finally11;
				}
				val = (_tmp1_ = _tmp0_, _g_free0 (val), _tmp1_);
				_g_object_unref0 (config);
				break;
			}
			goto __finally11;
			__catch11_g_error:
			{
				GError * err;
				err = _inner_error_;
				_inner_error_ = NULL;
				{
					_g_error_free0 (err);
				}
			}
			__finally11:
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_g_object_unref0 (config);
				_g_object_unref0 (_config_it);
				_g_free0 (val);
				return NULL;
			}
			_g_object_unref0 (config);
		}
		_g_object_unref0 (_config_it);
	}
	if (val == NULL) {
		_inner_error_ = g_error_new (RYGEL_CONFIGURATION_ERROR, RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET, "No value available for '%s/enabled'", section);
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_g_free0 (val);
			return NULL;
		}
	}
	result = val;
	return result;
}


static char* rygel_meta_config_real_get_string (RygelConfiguration* base, const char* section, const char* key, GError** error) {
	RygelMetaConfig * self;
	char* result;
	GError * _inner_error_;
	char* val;
	self = (RygelMetaConfig*) base;
	g_return_val_if_fail (section != NULL, NULL);
	g_return_val_if_fail (key != NULL, NULL);
	_inner_error_ = NULL;
	val = NULL;
	{
		GeeIterator* _config_it;
		_config_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->configs);
		while (TRUE) {
			RygelConfiguration* config;
			if (!gee_iterator_next (_config_it)) {
				break;
			}
			config = (RygelConfiguration*) gee_iterator_get (_config_it);
			{
				char* _tmp0_;
				char* _tmp1_;
				_tmp0_ = rygel_configuration_get_string (config, section, key, &_inner_error_);
				if (_inner_error_ != NULL) {
					goto __catch12_g_error;
					goto __finally12;
				}
				val = (_tmp1_ = _tmp0_, _g_free0 (val), _tmp1_);
				_g_object_unref0 (config);
				break;
			}
			goto __finally12;
			__catch12_g_error:
			{
				GError * err;
				err = _inner_error_;
				_inner_error_ = NULL;
				{
					_g_error_free0 (err);
				}
			}
			__finally12:
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_g_object_unref0 (config);
				_g_object_unref0 (_config_it);
				_g_free0 (val);
				return NULL;
			}
			_g_object_unref0 (config);
		}
		_g_object_unref0 (_config_it);
	}
	if (val == NULL) {
		_inner_error_ = g_error_new (RYGEL_CONFIGURATION_ERROR, RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET, "No value available for '%s/%s'", section, key);
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_g_free0 (val);
			return NULL;
		}
	}
	result = val;
	return result;
}


static GeeArrayList* rygel_meta_config_real_get_string_list (RygelConfiguration* base, const char* section, const char* key, GError** error) {
	RygelMetaConfig * self;
	GeeArrayList* result;
	GError * _inner_error_;
	GeeArrayList* val;
	self = (RygelMetaConfig*) base;
	g_return_val_if_fail (section != NULL, NULL);
	g_return_val_if_fail (key != NULL, NULL);
	_inner_error_ = NULL;
	val = NULL;
	{
		GeeIterator* _config_it;
		_config_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->configs);
		while (TRUE) {
			RygelConfiguration* config;
			if (!gee_iterator_next (_config_it)) {
				break;
			}
			config = (RygelConfiguration*) gee_iterator_get (_config_it);
			{
				GeeArrayList* _tmp0_;
				GeeArrayList* _tmp1_;
				_tmp0_ = rygel_configuration_get_string_list (config, section, key, &_inner_error_);
				if (_inner_error_ != NULL) {
					goto __catch13_g_error;
					goto __finally13;
				}
				val = (_tmp1_ = _tmp0_, _g_object_unref0 (val), _tmp1_);
				_g_object_unref0 (config);
				break;
			}
			goto __finally13;
			__catch13_g_error:
			{
				GError * err;
				err = _inner_error_;
				_inner_error_ = NULL;
				{
					_g_error_free0 (err);
				}
			}
			__finally13:
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_g_object_unref0 (config);
				_g_object_unref0 (_config_it);
				_g_object_unref0 (val);
				return NULL;
			}
			_g_object_unref0 (config);
		}
		_g_object_unref0 (_config_it);
	}
	if (val == NULL) {
		_inner_error_ = g_error_new (RYGEL_CONFIGURATION_ERROR, RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET, "No value available for '%s/%s'", section, key);
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_g_object_unref0 (val);
			return NULL;
		}
	}
	result = val;
	return result;
}


static gint rygel_meta_config_real_get_int (RygelConfiguration* base, const char* section, const char* key, gint min, gint max, GError** error) {
	RygelMetaConfig * self;
	gint result;
	GError * _inner_error_;
	gint val;
	gboolean unavailable;
	self = (RygelMetaConfig*) base;
	g_return_val_if_fail (section != NULL, 0);
	g_return_val_if_fail (key != NULL, 0);
	_inner_error_ = NULL;
	val = 0;
	unavailable = TRUE;
	{
		GeeIterator* _config_it;
		_config_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->configs);
		while (TRUE) {
			RygelConfiguration* config;
			if (!gee_iterator_next (_config_it)) {
				break;
			}
			config = (RygelConfiguration*) gee_iterator_get (_config_it);
			{
				gint _tmp0_;
				_tmp0_ = rygel_configuration_get_int (config, section, key, min, max, &_inner_error_);
				if (_inner_error_ != NULL) {
					goto __catch14_g_error;
					goto __finally14;
				}
				val = _tmp0_;
				unavailable = FALSE;
				_g_object_unref0 (config);
				break;
			}
			goto __finally14;
			__catch14_g_error:
			{
				GError * err;
				err = _inner_error_;
				_inner_error_ = NULL;
				{
					_g_error_free0 (err);
				}
			}
			__finally14:
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_g_object_unref0 (config);
				_g_object_unref0 (_config_it);
				return 0;
			}
			_g_object_unref0 (config);
		}
		_g_object_unref0 (_config_it);
	}
	if (unavailable) {
		_inner_error_ = g_error_new (RYGEL_CONFIGURATION_ERROR, RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET, "No value available for '%s/%s'", section, key);
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			return 0;
		}
	}
	result = val;
	return result;
}


static GeeArrayList* rygel_meta_config_real_get_int_list (RygelConfiguration* base, const char* section, const char* key, GError** error) {
	RygelMetaConfig * self;
	GeeArrayList* result;
	GError * _inner_error_;
	GeeArrayList* val;
	self = (RygelMetaConfig*) base;
	g_return_val_if_fail (section != NULL, NULL);
	g_return_val_if_fail (key != NULL, NULL);
	_inner_error_ = NULL;
	val = NULL;
	{
		GeeIterator* _config_it;
		_config_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->configs);
		while (TRUE) {
			RygelConfiguration* config;
			if (!gee_iterator_next (_config_it)) {
				break;
			}
			config = (RygelConfiguration*) gee_iterator_get (_config_it);
			{
				GeeArrayList* _tmp0_;
				GeeArrayList* _tmp1_;
				_tmp0_ = rygel_configuration_get_int_list (config, section, key, &_inner_error_);
				if (_inner_error_ != NULL) {
					goto __catch15_g_error;
					goto __finally15;
				}
				val = (_tmp1_ = _tmp0_, _g_object_unref0 (val), _tmp1_);
				_g_object_unref0 (config);
				break;
			}
			goto __finally15;
			__catch15_g_error:
			{
				GError * err;
				err = _inner_error_;
				_inner_error_ = NULL;
				{
					_g_error_free0 (err);
				}
			}
			__finally15:
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_g_object_unref0 (config);
				_g_object_unref0 (_config_it);
				_g_object_unref0 (val);
				return NULL;
			}
			_g_object_unref0 (config);
		}
		_g_object_unref0 (_config_it);
	}
	if (val == NULL) {
		_inner_error_ = g_error_new (RYGEL_CONFIGURATION_ERROR, RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET, "No value available for '%s/%s'", section, key);
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_g_object_unref0 (val);
			return NULL;
		}
	}
	result = val;
	return result;
}


static gboolean rygel_meta_config_real_get_bool (RygelConfiguration* base, const char* section, const char* key, GError** error) {
	RygelMetaConfig * self;
	gboolean result;
	GError * _inner_error_;
	gboolean val;
	gboolean unavailable;
	self = (RygelMetaConfig*) base;
	g_return_val_if_fail (section != NULL, FALSE);
	g_return_val_if_fail (key != NULL, FALSE);
	_inner_error_ = NULL;
	val = FALSE;
	unavailable = TRUE;
	{
		GeeIterator* _config_it;
		_config_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->configs);
		while (TRUE) {
			RygelConfiguration* config;
			if (!gee_iterator_next (_config_it)) {
				break;
			}
			config = (RygelConfiguration*) gee_iterator_get (_config_it);
			{
				gboolean _tmp0_;
				_tmp0_ = rygel_configuration_get_bool (config, section, key, &_inner_error_);
				if (_inner_error_ != NULL) {
					goto __catch16_g_error;
					goto __finally16;
				}
				val = _tmp0_;
				unavailable = FALSE;
				_g_object_unref0 (config);
				break;
			}
			goto __finally16;
			__catch16_g_error:
			{
				GError * err;
				err = _inner_error_;
				_inner_error_ = NULL;
				{
					_g_error_free0 (err);
				}
			}
			__finally16:
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_g_object_unref0 (config);
				_g_object_unref0 (_config_it);
				return FALSE;
			}
			_g_object_unref0 (config);
		}
		_g_object_unref0 (_config_it);
	}
	if (unavailable) {
		_inner_error_ = g_error_new (RYGEL_CONFIGURATION_ERROR, RYGEL_CONFIGURATION_ERROR_NO_VALUE_SET, "No value available for '%s/%s'", section, key);
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			return FALSE;
		}
	}
	result = val;
	return result;
}


static void rygel_meta_config_class_init (RygelMetaConfigClass * klass) {
	rygel_meta_config_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelMetaConfigPrivate));
	G_OBJECT_CLASS (klass)->finalize = rygel_meta_config_finalize;
}


static void rygel_meta_config_rygel_configuration_interface_init (RygelConfigurationIface * iface) {
	rygel_meta_config_rygel_configuration_parent_iface = g_type_interface_peek_parent (iface);
	iface->get_upnp_enabled = rygel_meta_config_real_get_upnp_enabled;
	iface->get_interface = rygel_meta_config_real_get_interface;
	iface->get_port = rygel_meta_config_real_get_port;
	iface->get_transcoding = rygel_meta_config_real_get_transcoding;
	iface->get_mp3_transcoder = rygel_meta_config_real_get_mp3_transcoder;
	iface->get_mp2ts_transcoder = rygel_meta_config_real_get_mp2ts_transcoder;
	iface->get_lpcm_transcoder = rygel_meta_config_real_get_lpcm_transcoder;
	iface->get_enabled = rygel_meta_config_real_get_enabled;
	iface->get_title = rygel_meta_config_real_get_title;
	iface->get_string = rygel_meta_config_real_get_string;
	iface->get_string_list = rygel_meta_config_real_get_string_list;
	iface->get_int = rygel_meta_config_real_get_int;
	iface->get_int_list = rygel_meta_config_real_get_int_list;
	iface->get_bool = rygel_meta_config_real_get_bool;
}


static void rygel_meta_config_instance_init (RygelMetaConfig * self) {
	self->priv = RYGEL_META_CONFIG_GET_PRIVATE (self);
}


static void rygel_meta_config_finalize (GObject* obj) {
	RygelMetaConfig * self;
	self = RYGEL_META_CONFIG (obj);
	_g_object_unref0 (self->priv->configs);
	G_OBJECT_CLASS (rygel_meta_config_parent_class)->finalize (obj);
}


GType rygel_meta_config_get_type (void) {
	static GType rygel_meta_config_type_id = 0;
	if (rygel_meta_config_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMetaConfigClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_meta_config_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMetaConfig), 0, (GInstanceInitFunc) rygel_meta_config_instance_init, NULL };
		static const GInterfaceInfo rygel_configuration_info = { (GInterfaceInitFunc) rygel_meta_config_rygel_configuration_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		rygel_meta_config_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelMetaConfig", &g_define_type_info, 0);
		g_type_add_interface_static (rygel_meta_config_type_id, RYGEL_TYPE_CONFIGURATION, &rygel_configuration_info);
	}
	return rygel_meta_config_type_id;
}




