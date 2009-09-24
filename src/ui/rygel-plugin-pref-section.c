/*
 * Copyright (C) 2009 Nokia Corporation.
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
#include <rygel.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>


#define RYGEL_TYPE_PREFERENCES_SECTION (rygel_preferences_section_get_type ())
#define RYGEL_PREFERENCES_SECTION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_PREFERENCES_SECTION, RygelPreferencesSection))
#define RYGEL_PREFERENCES_SECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_PREFERENCES_SECTION, RygelPreferencesSectionClass))
#define RYGEL_IS_PREFERENCES_SECTION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_PREFERENCES_SECTION))
#define RYGEL_IS_PREFERENCES_SECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_PREFERENCES_SECTION))
#define RYGEL_PREFERENCES_SECTION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_PREFERENCES_SECTION, RygelPreferencesSectionClass))

typedef struct _RygelPreferencesSection RygelPreferencesSection;
typedef struct _RygelPreferencesSectionClass RygelPreferencesSectionClass;
typedef struct _RygelPreferencesSectionPrivate RygelPreferencesSectionPrivate;

#define RYGEL_TYPE_PLUGIN_PREF_SECTION (rygel_plugin_pref_section_get_type ())
#define RYGEL_PLUGIN_PREF_SECTION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_PLUGIN_PREF_SECTION, RygelPluginPrefSection))
#define RYGEL_PLUGIN_PREF_SECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_PLUGIN_PREF_SECTION, RygelPluginPrefSectionClass))
#define RYGEL_IS_PLUGIN_PREF_SECTION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_PLUGIN_PREF_SECTION))
#define RYGEL_IS_PLUGIN_PREF_SECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_PLUGIN_PREF_SECTION))
#define RYGEL_PLUGIN_PREF_SECTION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_PLUGIN_PREF_SECTION, RygelPluginPrefSectionClass))

typedef struct _RygelPluginPrefSection RygelPluginPrefSection;
typedef struct _RygelPluginPrefSectionClass RygelPluginPrefSectionClass;
typedef struct _RygelPluginPrefSectionPrivate RygelPluginPrefSectionPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_regex_unref0(var) ((var == NULL) ? NULL : (var = (g_regex_unref (var), NULL)))

struct _RygelPreferencesSection {
	GObject parent_instance;
	RygelPreferencesSectionPrivate * priv;
	RygelUserConfig* config;
	char* name;
};

struct _RygelPreferencesSectionClass {
	GObjectClass parent_class;
	void (*save) (RygelPreferencesSection* self);
};

struct _RygelPluginPrefSection {
	RygelPreferencesSection parent_instance;
	RygelPluginPrefSectionPrivate * priv;
};

struct _RygelPluginPrefSectionClass {
	RygelPreferencesSectionClass parent_class;
	void (*on_enabled_check_toggled) (RygelPluginPrefSection* self, GtkCheckButton* enabled_check);
};

struct _RygelPluginPrefSectionPrivate {
	GtkCheckButton* enabled_check;
	GtkEntry* title_entry;
};


static gpointer rygel_plugin_pref_section_parent_class = NULL;

GType rygel_preferences_section_get_type (void);
GType rygel_plugin_pref_section_get_type (void);
#define RYGEL_PLUGIN_PREF_SECTION_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_PLUGIN_PREF_SECTION, RygelPluginPrefSectionPrivate))
enum  {
	RYGEL_PLUGIN_PREF_SECTION_DUMMY_PROPERTY
};
#define RYGEL_PLUGIN_PREF_SECTION_ENABLED_CHECK "-enabled-checkbutton"
#define RYGEL_PLUGIN_PREF_SECTION_TITLE_ENTRY "-title-entry"
RygelPreferencesSection* rygel_preferences_section_construct (GType object_type, RygelUserConfig* config, const char* name);
void rygel_plugin_pref_section_on_enabled_check_toggled (RygelPluginPrefSection* self, GtkCheckButton* enabled_check);
static void _rygel_plugin_pref_section_on_enabled_check_toggled_gtk_toggle_button_toggled (GtkCheckButton* _sender, gpointer self);
RygelPluginPrefSection* rygel_plugin_pref_section_new (GtkBuilder* builder, RygelUserConfig* config, const char* name);
RygelPluginPrefSection* rygel_plugin_pref_section_construct (GType object_type, GtkBuilder* builder, RygelUserConfig* config, const char* name);
static void rygel_plugin_pref_section_real_save (RygelPreferencesSection* base);
static void rygel_plugin_pref_section_real_on_enabled_check_toggled (RygelPluginPrefSection* self, GtkCheckButton* enabled_check);
static void rygel_plugin_pref_section_finalize (GObject* obj);



static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static char* string_replace (const char* self, const char* old, const char* replacement) {
	char* result;
	GError * _inner_error_;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (old != NULL, NULL);
	g_return_val_if_fail (replacement != NULL, NULL);
	_inner_error_ = NULL;
	{
		char* _tmp0_;
		GRegex* _tmp1_;
		GRegex* regex;
		char* _tmp2_;
		regex = (_tmp1_ = g_regex_new (_tmp0_ = g_regex_escape_string (old, -1), 0, 0, &_inner_error_), _g_free0 (_tmp0_), _tmp1_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch9_g_regex_error;
			}
			goto __finally9;
		}
		_tmp2_ = g_regex_replace_literal (regex, self, (glong) (-1), 0, replacement, 0, &_inner_error_);
		if (_inner_error_ != NULL) {
			_g_regex_unref0 (regex);
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch9_g_regex_error;
			}
			goto __finally9;
		}
		result = _tmp2_;
		_g_regex_unref0 (regex);
		return result;
	}
	goto __finally9;
	__catch9_g_regex_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			g_assert_not_reached ();
			_g_error_free0 (e);
		}
	}
	__finally9:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
}


static void _rygel_plugin_pref_section_on_enabled_check_toggled_gtk_toggle_button_toggled (GtkCheckButton* _sender, gpointer self) {
	rygel_plugin_pref_section_on_enabled_check_toggled (self, _sender);
}


RygelPluginPrefSection* rygel_plugin_pref_section_construct (GType object_type, GtkBuilder* builder, RygelUserConfig* config, const char* name) {
	GError * _inner_error_;
	RygelPluginPrefSection * self;
	GtkCheckButton* _tmp2_;
	char* _tmp1_;
	char* _tmp0_;
	GtkEntry* _tmp5_;
	char* _tmp4_;
	char* _tmp3_;
	gboolean _tmp6_;
	char* title;
	char* _tmp10_;
	char* _tmp11_;
	char* _tmp12_;
	g_return_val_if_fail (builder != NULL, NULL);
	g_return_val_if_fail (config != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	_inner_error_ = NULL;
	self = (RygelPluginPrefSection*) rygel_preferences_section_construct (object_type, config, name);
	self->priv->enabled_check = (_tmp2_ = _g_object_ref0 (GTK_CHECK_BUTTON (gtk_builder_get_object (builder, _tmp1_ = g_strconcat (_tmp0_ = g_utf8_strdown (name, -1), RYGEL_PLUGIN_PREF_SECTION_ENABLED_CHECK, NULL)))), _g_object_unref0 (self->priv->enabled_check), _tmp2_);
	_g_free0 (_tmp1_);
	_g_free0 (_tmp0_);
	g_assert (self->priv->enabled_check != NULL);
	self->priv->title_entry = (_tmp5_ = _g_object_ref0 (GTK_ENTRY (gtk_builder_get_object (builder, _tmp4_ = g_strconcat (_tmp3_ = g_utf8_strdown (name, -1), RYGEL_PLUGIN_PREF_SECTION_TITLE_ENTRY, NULL)))), _g_object_unref0 (self->priv->title_entry), _tmp5_);
	_g_free0 (_tmp4_);
	_g_free0 (_tmp3_);
	g_assert (self->priv->title_entry != NULL);
	_tmp6_ = rygel_configuration_get_enabled ((RygelConfiguration*) config, name, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	gtk_toggle_button_set_active ((GtkToggleButton*) self->priv->enabled_check, _tmp6_);
	title = NULL;
	{
		char* _tmp7_;
		char* _tmp8_;
		_tmp7_ = rygel_configuration_get_title ((RygelConfiguration*) config, name, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch8_g_error;
			goto __finally8;
		}
		title = (_tmp8_ = _tmp7_, _g_free0 (title), _tmp8_);
	}
	goto __finally8;
	__catch8_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp9_;
			title = (_tmp9_ = g_strdup (name), _g_free0 (title), _tmp9_);
			_g_error_free0 (err);
		}
	}
	__finally8:
	if (_inner_error_ != NULL) {
		_g_free0 (title);
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	title = (_tmp10_ = string_replace (title, "@REALNAME@", "%n"), _g_free0 (title), _tmp10_);
	title = (_tmp11_ = string_replace (title, "@USERNAME@", "%u"), _g_free0 (title), _tmp11_);
	title = (_tmp12_ = string_replace (title, "@HOSTNAME@", "%h"), _g_free0 (title), _tmp12_);
	gtk_entry_set_text (self->priv->title_entry, title);
	g_signal_connect_object ((GtkToggleButton*) self->priv->enabled_check, "toggled", (GCallback) _rygel_plugin_pref_section_on_enabled_check_toggled_gtk_toggle_button_toggled, self, 0);
	_g_free0 (title);
	return self;
}


RygelPluginPrefSection* rygel_plugin_pref_section_new (GtkBuilder* builder, RygelUserConfig* config, const char* name) {
	return rygel_plugin_pref_section_construct (RYGEL_TYPE_PLUGIN_PREF_SECTION, builder, config, name);
}


static void rygel_plugin_pref_section_real_save (RygelPreferencesSection* base) {
	RygelPluginPrefSection * self;
	char* title;
	char* _tmp0_;
	char* _tmp1_;
	self = (RygelPluginPrefSection*) base;
	rygel_user_config_set_bool (((RygelPreferencesSection*) self)->config, ((RygelPreferencesSection*) self)->name, RYGEL_USER_CONFIG_ENABLED_KEY, gtk_toggle_button_get_active ((GtkToggleButton*) self->priv->enabled_check));
	title = string_replace (gtk_entry_get_text (self->priv->title_entry), "%n", "@REALNAME@");
	title = (_tmp0_ = string_replace (title, "%u", "@USERNAME@"), _g_free0 (title), _tmp0_);
	title = (_tmp1_ = string_replace (title, "%h", "@HOSTNAME@"), _g_free0 (title), _tmp1_);
	rygel_user_config_set_string (((RygelPreferencesSection*) self)->config, ((RygelPreferencesSection*) self)->name, RYGEL_USER_CONFIG_TITLE_KEY, title);
	_g_free0 (title);
}


static void rygel_plugin_pref_section_real_on_enabled_check_toggled (RygelPluginPrefSection* self, GtkCheckButton* enabled_check) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (enabled_check != NULL);
	g_object_set ((GtkWidget*) self->priv->title_entry, "sensitive", gtk_toggle_button_get_active ((GtkToggleButton*) enabled_check), NULL);
}


void rygel_plugin_pref_section_on_enabled_check_toggled (RygelPluginPrefSection* self, GtkCheckButton* enabled_check) {
	RYGEL_PLUGIN_PREF_SECTION_GET_CLASS (self)->on_enabled_check_toggled (self, enabled_check);
}


static void rygel_plugin_pref_section_class_init (RygelPluginPrefSectionClass * klass) {
	rygel_plugin_pref_section_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelPluginPrefSectionPrivate));
	RYGEL_PREFERENCES_SECTION_CLASS (klass)->save = rygel_plugin_pref_section_real_save;
	RYGEL_PLUGIN_PREF_SECTION_CLASS (klass)->on_enabled_check_toggled = rygel_plugin_pref_section_real_on_enabled_check_toggled;
	G_OBJECT_CLASS (klass)->finalize = rygel_plugin_pref_section_finalize;
}


static void rygel_plugin_pref_section_instance_init (RygelPluginPrefSection * self) {
	self->priv = RYGEL_PLUGIN_PREF_SECTION_GET_PRIVATE (self);
}


static void rygel_plugin_pref_section_finalize (GObject* obj) {
	RygelPluginPrefSection * self;
	self = RYGEL_PLUGIN_PREF_SECTION (obj);
	_g_object_unref0 (self->priv->enabled_check);
	_g_object_unref0 (self->priv->title_entry);
	G_OBJECT_CLASS (rygel_plugin_pref_section_parent_class)->finalize (obj);
}


GType rygel_plugin_pref_section_get_type (void) {
	static GType rygel_plugin_pref_section_type_id = 0;
	if (rygel_plugin_pref_section_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelPluginPrefSectionClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_plugin_pref_section_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelPluginPrefSection), 0, (GInstanceInitFunc) rygel_plugin_pref_section_instance_init, NULL };
		rygel_plugin_pref_section_type_id = g_type_register_static (RYGEL_TYPE_PREFERENCES_SECTION, "RygelPluginPrefSection", &g_define_type_info, 0);
	}
	return rygel_plugin_pref_section_type_id;
}




