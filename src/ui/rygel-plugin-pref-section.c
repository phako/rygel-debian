/* rygel-plugin-pref-section.c generated by valac, the Vala compiler
 * generated from rygel-plugin-pref-section.vala, do not modify */

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
#include <gee.h>
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
	GeeArrayList* widgets;
};

struct _RygelPluginPrefSectionClass {
	RygelPreferencesSectionClass parent_class;
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
#define RYGEL_PLUGIN_PREF_SECTION_TITLE_LABEL "-title-label"
#define RYGEL_PLUGIN_PREF_SECTION_TITLE_ENTRY "-title-entry"
RygelPreferencesSection* rygel_preferences_section_construct (GType object_type, RygelUserConfig* config, const char* name);
static void rygel_plugin_pref_section_on_enabled_check_toggled (RygelPluginPrefSection* self, GtkCheckButton* enabled_check);
static void _rygel_plugin_pref_section_on_enabled_check_toggled_gtk_toggle_button_toggled (GtkCheckButton* _sender, gpointer self);
RygelPluginPrefSection* rygel_plugin_pref_section_new (GtkBuilder* builder, RygelUserConfig* config, const char* name);
RygelPluginPrefSection* rygel_plugin_pref_section_construct (GType object_type, GtkBuilder* builder, RygelUserConfig* config, const char* name);
static void rygel_plugin_pref_section_real_save (RygelPreferencesSection* base);
void rygel_plugin_pref_section_reset_widgets_sensitivity (RygelPluginPrefSection* self);
static void rygel_plugin_pref_section_finalize (GObject* obj);



static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


#line 1027 "glib-2.0.vapi"
static char* string_replace (const char* self, const char* old, const char* replacement) {
#line 120 "rygel-plugin-pref-section.c"
	char* result;
	GError * _inner_error_;
#line 1027 "glib-2.0.vapi"
	g_return_val_if_fail (self != NULL, NULL);
#line 1027 "glib-2.0.vapi"
	g_return_val_if_fail (old != NULL, NULL);
#line 1027 "glib-2.0.vapi"
	g_return_val_if_fail (replacement != NULL, NULL);
#line 129 "rygel-plugin-pref-section.c"
	_inner_error_ = NULL;
	{
		char* _tmp0_;
		GRegex* _tmp1_;
		GRegex* regex;
		char* _tmp2_;
#line 1029 "glib-2.0.vapi"
		regex = (_tmp1_ = g_regex_new (_tmp0_ = g_regex_escape_string (old, -1), 0, 0, &_inner_error_), _g_free0 (_tmp0_), _tmp1_);
#line 138 "rygel-plugin-pref-section.c"
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch10_g_regex_error;
			}
			goto __finally10;
		}
#line 1030 "glib-2.0.vapi"
		_tmp2_ = g_regex_replace_literal (regex, self, (gssize) (-1), 0, replacement, 0, &_inner_error_);
#line 147 "rygel-plugin-pref-section.c"
		if (_inner_error_ != NULL) {
			_g_regex_unref0 (regex);
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch10_g_regex_error;
			}
			goto __finally10;
		}
		result = _tmp2_;
		_g_regex_unref0 (regex);
#line 1030 "glib-2.0.vapi"
		return result;
#line 159 "rygel-plugin-pref-section.c"
	}
	goto __finally10;
	__catch10_g_regex_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
#line 1032 "glib-2.0.vapi"
			g_assert_not_reached ();
#line 170 "rygel-plugin-pref-section.c"
			_g_error_free0 (e);
		}
	}
	__finally10:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
}


#line 94 "rygel-plugin-pref-section.vala"
static void _rygel_plugin_pref_section_on_enabled_check_toggled_gtk_toggle_button_toggled (GtkCheckButton* _sender, gpointer self) {
#line 185 "rygel-plugin-pref-section.c"
	rygel_plugin_pref_section_on_enabled_check_toggled (self, _sender);
}


#line 36 "rygel-plugin-pref-section.vala"
RygelPluginPrefSection* rygel_plugin_pref_section_construct (GType object_type, GtkBuilder* builder, RygelUserConfig* config, const char* name) {
#line 192 "rygel-plugin-pref-section.c"
	GError * _inner_error_;
	RygelPluginPrefSection * self;
	GeeArrayList* _tmp0_;
	GtkCheckButton* _tmp3_;
	char* _tmp2_;
	char* _tmp1_;
	GtkEntry* _tmp6_;
	char* _tmp5_;
	char* _tmp4_;
	char* _tmp8_;
	char* _tmp7_;
	GtkLabel* _tmp9_;
	GtkLabel* title_label;
	char* title;
	char* _tmp14_;
	char* _tmp15_;
	char* _tmp16_;
#line 36 "rygel-plugin-pref-section.vala"
	g_return_val_if_fail (builder != NULL, NULL);
#line 36 "rygel-plugin-pref-section.vala"
	g_return_val_if_fail (config != NULL, NULL);
#line 36 "rygel-plugin-pref-section.vala"
	g_return_val_if_fail (name != NULL, NULL);
#line 216 "rygel-plugin-pref-section.c"
	_inner_error_ = NULL;
#line 39 "rygel-plugin-pref-section.vala"
	self = (RygelPluginPrefSection*) rygel_preferences_section_construct (object_type, config, name);
#line 41 "rygel-plugin-pref-section.vala"
	self->widgets = (_tmp0_ = gee_array_list_new (GTK_TYPE_WIDGET, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL), _g_object_unref0 (self->widgets), _tmp0_);
#line 43 "rygel-plugin-pref-section.vala"
	self->priv->enabled_check = (_tmp3_ = _g_object_ref0 (GTK_CHECK_BUTTON (gtk_builder_get_object (builder, _tmp2_ = g_strconcat (_tmp1_ = g_utf8_strdown (name, -1), RYGEL_PLUGIN_PREF_SECTION_ENABLED_CHECK, NULL)))), _g_object_unref0 (self->priv->enabled_check), _tmp3_);
#line 224 "rygel-plugin-pref-section.c"
	_g_free0 (_tmp2_);
	_g_free0 (_tmp1_);
#line 45 "rygel-plugin-pref-section.vala"
	g_assert (self->priv->enabled_check != NULL);
#line 46 "rygel-plugin-pref-section.vala"
	self->priv->title_entry = (_tmp6_ = _g_object_ref0 (GTK_ENTRY (gtk_builder_get_object (builder, _tmp5_ = g_strconcat (_tmp4_ = g_utf8_strdown (name, -1), RYGEL_PLUGIN_PREF_SECTION_TITLE_ENTRY, NULL)))), _g_object_unref0 (self->priv->title_entry), _tmp6_);
#line 231 "rygel-plugin-pref-section.c"
	_g_free0 (_tmp5_);
	_g_free0 (_tmp4_);
#line 48 "rygel-plugin-pref-section.vala"
	g_assert (self->priv->title_entry != NULL);
#line 49 "rygel-plugin-pref-section.vala"
	title_label = (_tmp9_ = _g_object_ref0 (GTK_LABEL (gtk_builder_get_object (builder, _tmp8_ = g_strconcat (_tmp7_ = g_utf8_strdown (name, -1), RYGEL_PLUGIN_PREF_SECTION_TITLE_LABEL, NULL)))), _g_free0 (_tmp8_), _g_free0 (_tmp7_), _tmp9_);
#line 51 "rygel-plugin-pref-section.vala"
	g_assert (title_label != NULL);
#line 52 "rygel-plugin-pref-section.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) self->widgets, (GtkWidget*) title_label);
#line 242 "rygel-plugin-pref-section.c"
	{
		gboolean _tmp10_;
#line 55 "rygel-plugin-pref-section.vala"
		_tmp10_ = rygel_configuration_get_enabled ((RygelConfiguration*) config, name, &_inner_error_);
#line 247 "rygel-plugin-pref-section.c"
		if (_inner_error_ != NULL) {
			goto __catch8_g_error;
			goto __finally8;
		}
#line 55 "rygel-plugin-pref-section.vala"
		gtk_toggle_button_set_active ((GtkToggleButton*) self->priv->enabled_check, _tmp10_);
#line 254 "rygel-plugin-pref-section.c"
	}
	goto __finally8;
	__catch8_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
#line 57 "rygel-plugin-pref-section.vala"
			gtk_toggle_button_set_active ((GtkToggleButton*) self->priv->enabled_check, FALSE);
#line 265 "rygel-plugin-pref-section.c"
			_g_error_free0 (err);
		}
	}
	__finally8:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (title_label);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	title = NULL;
	{
		char* _tmp11_;
		char* _tmp12_;
#line 62 "rygel-plugin-pref-section.vala"
		_tmp11_ = rygel_configuration_get_title ((RygelConfiguration*) config, name, &_inner_error_);
#line 282 "rygel-plugin-pref-section.c"
		if (_inner_error_ != NULL) {
			goto __catch9_g_error;
			goto __finally9;
		}
#line 62 "rygel-plugin-pref-section.vala"
		title = (_tmp12_ = _tmp11_, _g_free0 (title), _tmp12_);
#line 289 "rygel-plugin-pref-section.c"
	}
	goto __finally9;
	__catch9_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp13_;
#line 64 "rygel-plugin-pref-section.vala"
			title = (_tmp13_ = g_strdup (name), _g_free0 (title), _tmp13_);
#line 301 "rygel-plugin-pref-section.c"
			_g_error_free0 (err);
		}
	}
	__finally9:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (title_label);
		_g_free0 (title);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
#line 67 "rygel-plugin-pref-section.vala"
	title = (_tmp14_ = string_replace (title, "@REALNAME@", "%n"), _g_free0 (title), _tmp14_);
#line 68 "rygel-plugin-pref-section.vala"
	title = (_tmp15_ = string_replace (title, "@USERNAME@", "%u"), _g_free0 (title), _tmp15_);
#line 69 "rygel-plugin-pref-section.vala"
	title = (_tmp16_ = string_replace (title, "@HOSTNAME@", "%h"), _g_free0 (title), _tmp16_);
#line 70 "rygel-plugin-pref-section.vala"
	gtk_entry_set_text (self->priv->title_entry, title);
#line 72 "rygel-plugin-pref-section.vala"
	g_signal_connect_object ((GtkToggleButton*) self->priv->enabled_check, "toggled", (GCallback) _rygel_plugin_pref_section_on_enabled_check_toggled_gtk_toggle_button_toggled, self, 0);
#line 323 "rygel-plugin-pref-section.c"
	_g_object_unref0 (title_label);
	_g_free0 (title);
	return self;
}


#line 36 "rygel-plugin-pref-section.vala"
RygelPluginPrefSection* rygel_plugin_pref_section_new (GtkBuilder* builder, RygelUserConfig* config, const char* name) {
#line 36 "rygel-plugin-pref-section.vala"
	return rygel_plugin_pref_section_construct (RYGEL_TYPE_PLUGIN_PREF_SECTION, builder, config, name);
#line 334 "rygel-plugin-pref-section.c"
}


#line 75 "rygel-plugin-pref-section.vala"
static void rygel_plugin_pref_section_real_save (RygelPreferencesSection* base) {
#line 340 "rygel-plugin-pref-section.c"
	RygelPluginPrefSection * self;
	char* title;
	char* _tmp0_;
	char* _tmp1_;
	self = (RygelPluginPrefSection*) base;
#line 76 "rygel-plugin-pref-section.vala"
	rygel_user_config_set_bool (((RygelPreferencesSection*) self)->config, ((RygelPreferencesSection*) self)->name, RYGEL_USER_CONFIG_ENABLED_KEY, gtk_toggle_button_get_active ((GtkToggleButton*) self->priv->enabled_check));
#line 80 "rygel-plugin-pref-section.vala"
	title = string_replace (gtk_entry_get_text (self->priv->title_entry), "%n", "@REALNAME@");
#line 81 "rygel-plugin-pref-section.vala"
	title = (_tmp0_ = string_replace (title, "%u", "@USERNAME@"), _g_free0 (title), _tmp0_);
#line 82 "rygel-plugin-pref-section.vala"
	title = (_tmp1_ = string_replace (title, "%h", "@HOSTNAME@"), _g_free0 (title), _tmp1_);
#line 83 "rygel-plugin-pref-section.vala"
	rygel_user_config_set_string (((RygelPreferencesSection*) self)->config, ((RygelPreferencesSection*) self)->name, RYGEL_USER_CONFIG_TITLE_KEY, title);
#line 356 "rygel-plugin-pref-section.c"
	_g_free0 (title);
}


#line 86 "rygel-plugin-pref-section.vala"
void rygel_plugin_pref_section_reset_widgets_sensitivity (RygelPluginPrefSection* self) {
#line 86 "rygel-plugin-pref-section.vala"
	g_return_if_fail (self != NULL);
#line 87 "rygel-plugin-pref-section.vala"
	gtk_widget_set_sensitive ((GtkWidget*) self->priv->title_entry, gtk_toggle_button_get_active ((GtkToggleButton*) self->priv->enabled_check));
#line 367 "rygel-plugin-pref-section.c"
	{
		GeeIterator* _widget_it;
		_widget_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->widgets);
#line 89 "rygel-plugin-pref-section.vala"
		while (TRUE) {
#line 373 "rygel-plugin-pref-section.c"
			GtkWidget* widget;
#line 89 "rygel-plugin-pref-section.vala"
			if (!gee_iterator_next (_widget_it)) {
#line 89 "rygel-plugin-pref-section.vala"
				break;
#line 379 "rygel-plugin-pref-section.c"
			}
#line 89 "rygel-plugin-pref-section.vala"
			widget = (GtkWidget*) gee_iterator_get (_widget_it);
#line 90 "rygel-plugin-pref-section.vala"
			gtk_widget_set_sensitive (widget, gtk_toggle_button_get_active ((GtkToggleButton*) self->priv->enabled_check));
#line 385 "rygel-plugin-pref-section.c"
			_g_object_unref0 (widget);
		}
		_g_object_unref0 (_widget_it);
	}
}


#line 94 "rygel-plugin-pref-section.vala"
static void rygel_plugin_pref_section_on_enabled_check_toggled (RygelPluginPrefSection* self, GtkCheckButton* enabled_check) {
#line 94 "rygel-plugin-pref-section.vala"
	g_return_if_fail (self != NULL);
#line 94 "rygel-plugin-pref-section.vala"
	g_return_if_fail (enabled_check != NULL);
#line 95 "rygel-plugin-pref-section.vala"
	rygel_plugin_pref_section_reset_widgets_sensitivity (self);
#line 401 "rygel-plugin-pref-section.c"
}


static void rygel_plugin_pref_section_class_init (RygelPluginPrefSectionClass * klass) {
	rygel_plugin_pref_section_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelPluginPrefSectionPrivate));
	RYGEL_PREFERENCES_SECTION_CLASS (klass)->save = rygel_plugin_pref_section_real_save;
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
	_g_object_unref0 (self->widgets);
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




