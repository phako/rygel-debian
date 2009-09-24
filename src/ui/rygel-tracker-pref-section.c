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

#define RYGEL_TYPE_TRACKER_PREF_SECTION (rygel_tracker_pref_section_get_type ())
#define RYGEL_TRACKER_PREF_SECTION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_PREF_SECTION, RygelTrackerPrefSection))
#define RYGEL_TRACKER_PREF_SECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_PREF_SECTION, RygelTrackerPrefSectionClass))
#define RYGEL_IS_TRACKER_PREF_SECTION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_PREF_SECTION))
#define RYGEL_IS_TRACKER_PREF_SECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_PREF_SECTION))
#define RYGEL_TRACKER_PREF_SECTION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_PREF_SECTION, RygelTrackerPrefSectionClass))

typedef struct _RygelTrackerPrefSection RygelTrackerPrefSection;
typedef struct _RygelTrackerPrefSectionClass RygelTrackerPrefSectionClass;
typedef struct _RygelTrackerPrefSectionPrivate RygelTrackerPrefSectionPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

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

struct _RygelTrackerPrefSection {
	RygelPluginPrefSection parent_instance;
	RygelTrackerPrefSectionPrivate * priv;
};

struct _RygelTrackerPrefSectionClass {
	RygelPluginPrefSectionClass parent_class;
};

struct _RygelTrackerPrefSectionPrivate {
	GtkCheckButton* videos_check;
	GtkCheckButton* music_check;
	GtkCheckButton* pictures_check;
};


static gpointer rygel_tracker_pref_section_parent_class = NULL;

GType rygel_preferences_section_get_type (void);
GType rygel_plugin_pref_section_get_type (void);
GType rygel_tracker_pref_section_get_type (void);
#define RYGEL_TRACKER_PREF_SECTION_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_TRACKER_PREF_SECTION, RygelTrackerPrefSectionPrivate))
enum  {
	RYGEL_TRACKER_PREF_SECTION_DUMMY_PROPERTY
};
#define RYGEL_TRACKER_PREF_SECTION_NAME "Tracker"
#define RYGEL_TRACKER_PREF_SECTION_VIDEOS_KEY "share-videos"
#define RYGEL_TRACKER_PREF_SECTION_MUSIC_KEY "share-music"
#define RYGEL_TRACKER_PREF_SECTION_PICTURES_KEY "share-pictures"
#define RYGEL_TRACKER_PREF_SECTION_TAG_KEY "share-tagged"
#define RYGEL_TRACKER_PREF_SECTION_VIDEOS_CHECK RYGEL_TRACKER_PREF_SECTION_VIDEOS_KEY "-checkbutton"
#define RYGEL_TRACKER_PREF_SECTION_MUSIC_CHECK RYGEL_TRACKER_PREF_SECTION_MUSIC_KEY "-checkbutton"
#define RYGEL_TRACKER_PREF_SECTION_PICTURES_CHECK RYGEL_TRACKER_PREF_SECTION_PICTURES_KEY "-checkbutton"
RygelPluginPrefSection* rygel_plugin_pref_section_new (GtkBuilder* builder, RygelUserConfig* config, const char* name);
RygelPluginPrefSection* rygel_plugin_pref_section_construct (GType object_type, GtkBuilder* builder, RygelUserConfig* config, const char* name);
RygelTrackerPrefSection* rygel_tracker_pref_section_new (GtkBuilder* builder, RygelUserConfig* config);
RygelTrackerPrefSection* rygel_tracker_pref_section_construct (GType object_type, GtkBuilder* builder, RygelUserConfig* config);
void rygel_preferences_section_save (RygelPreferencesSection* self);
static void rygel_tracker_pref_section_real_save (RygelPreferencesSection* base);
void rygel_plugin_pref_section_on_enabled_check_toggled (RygelPluginPrefSection* self, GtkCheckButton* enabled_check);
static void rygel_tracker_pref_section_real_on_enabled_check_toggled (RygelPluginPrefSection* base, GtkCheckButton* enabled_check);
static void rygel_tracker_pref_section_finalize (GObject* obj);



static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


RygelTrackerPrefSection* rygel_tracker_pref_section_construct (GType object_type, GtkBuilder* builder, RygelUserConfig* config) {
	GError * _inner_error_;
	RygelTrackerPrefSection * self;
	GtkCheckButton* _tmp0_;
	GtkCheckButton* _tmp1_;
	GtkCheckButton* _tmp2_;
	g_return_val_if_fail (builder != NULL, NULL);
	g_return_val_if_fail (config != NULL, NULL);
	_inner_error_ = NULL;
	self = (RygelTrackerPrefSection*) rygel_plugin_pref_section_construct (object_type, builder, config, RYGEL_TRACKER_PREF_SECTION_NAME);
	self->priv->videos_check = (_tmp0_ = _g_object_ref0 (GTK_CHECK_BUTTON (gtk_builder_get_object (builder, RYGEL_TRACKER_PREF_SECTION_VIDEOS_CHECK))), _g_object_unref0 (self->priv->videos_check), _tmp0_);
	g_assert (self->priv->videos_check != NULL);
	self->priv->music_check = (_tmp1_ = _g_object_ref0 (GTK_CHECK_BUTTON (gtk_builder_get_object (builder, RYGEL_TRACKER_PREF_SECTION_MUSIC_CHECK))), _g_object_unref0 (self->priv->music_check), _tmp1_);
	g_assert (self->priv->music_check != NULL);
	self->priv->pictures_check = (_tmp2_ = _g_object_ref0 (GTK_CHECK_BUTTON (gtk_builder_get_object (builder, RYGEL_TRACKER_PREF_SECTION_PICTURES_CHECK))), _g_object_unref0 (self->priv->pictures_check), _tmp2_);
	g_assert (self->priv->pictures_check != NULL);
	gtk_toggle_button_set_active ((GtkToggleButton*) self->priv->videos_check, TRUE);
	gtk_toggle_button_set_active ((GtkToggleButton*) self->priv->music_check, TRUE);
	gtk_toggle_button_set_active ((GtkToggleButton*) self->priv->pictures_check, TRUE);
	{
		gboolean _tmp3_;
		gboolean _tmp4_;
		gboolean _tmp5_;
		_tmp3_ = rygel_configuration_get_bool ((RygelConfiguration*) config, ((RygelPreferencesSection*) self)->name, RYGEL_TRACKER_PREF_SECTION_VIDEOS_KEY, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch11_g_error;
			goto __finally11;
		}
		gtk_toggle_button_set_active ((GtkToggleButton*) self->priv->videos_check, _tmp3_);
		_tmp4_ = rygel_configuration_get_bool ((RygelConfiguration*) config, ((RygelPreferencesSection*) self)->name, RYGEL_TRACKER_PREF_SECTION_MUSIC_KEY, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch11_g_error;
			goto __finally11;
		}
		gtk_toggle_button_set_active ((GtkToggleButton*) self->priv->music_check, _tmp4_);
		_tmp5_ = rygel_configuration_get_bool ((RygelConfiguration*) config, ((RygelPreferencesSection*) self)->name, RYGEL_TRACKER_PREF_SECTION_PICTURES_KEY, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch11_g_error;
			goto __finally11;
		}
		gtk_toggle_button_set_active ((GtkToggleButton*) self->priv->pictures_check, _tmp5_);
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
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	return self;
}


RygelTrackerPrefSection* rygel_tracker_pref_section_new (GtkBuilder* builder, RygelUserConfig* config) {
	return rygel_tracker_pref_section_construct (RYGEL_TYPE_TRACKER_PREF_SECTION, builder, config);
}


static void rygel_tracker_pref_section_real_save (RygelPreferencesSection* base) {
	RygelTrackerPrefSection * self;
	self = (RygelTrackerPrefSection*) base;
	RYGEL_PREFERENCES_SECTION_CLASS (rygel_tracker_pref_section_parent_class)->save ((RygelPreferencesSection*) RYGEL_PLUGIN_PREF_SECTION (self));
	rygel_user_config_set_bool (((RygelPreferencesSection*) self)->config, ((RygelPreferencesSection*) self)->name, RYGEL_TRACKER_PREF_SECTION_VIDEOS_KEY, gtk_toggle_button_get_active ((GtkToggleButton*) self->priv->videos_check));
	rygel_user_config_set_bool (((RygelPreferencesSection*) self)->config, ((RygelPreferencesSection*) self)->name, RYGEL_TRACKER_PREF_SECTION_MUSIC_KEY, gtk_toggle_button_get_active ((GtkToggleButton*) self->priv->music_check));
	rygel_user_config_set_bool (((RygelPreferencesSection*) self)->config, ((RygelPreferencesSection*) self)->name, RYGEL_TRACKER_PREF_SECTION_PICTURES_KEY, gtk_toggle_button_get_active ((GtkToggleButton*) self->priv->pictures_check));
}


static void rygel_tracker_pref_section_real_on_enabled_check_toggled (RygelPluginPrefSection* base, GtkCheckButton* enabled_check) {
	RygelTrackerPrefSection * self;
	self = (RygelTrackerPrefSection*) base;
	g_return_if_fail (enabled_check != NULL);
	RYGEL_PLUGIN_PREF_SECTION_CLASS (rygel_tracker_pref_section_parent_class)->on_enabled_check_toggled (RYGEL_PLUGIN_PREF_SECTION (self), enabled_check);
	g_object_set ((GtkWidget*) self->priv->videos_check, "sensitive", gtk_toggle_button_get_active ((GtkToggleButton*) enabled_check), NULL);
	g_object_set ((GtkWidget*) self->priv->music_check, "sensitive", gtk_toggle_button_get_active ((GtkToggleButton*) enabled_check), NULL);
	g_object_set ((GtkWidget*) self->priv->pictures_check, "sensitive", gtk_toggle_button_get_active ((GtkToggleButton*) enabled_check), NULL);
}


static void rygel_tracker_pref_section_class_init (RygelTrackerPrefSectionClass * klass) {
	rygel_tracker_pref_section_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelTrackerPrefSectionPrivate));
	RYGEL_PREFERENCES_SECTION_CLASS (klass)->save = rygel_tracker_pref_section_real_save;
	RYGEL_PLUGIN_PREF_SECTION_CLASS (klass)->on_enabled_check_toggled = rygel_tracker_pref_section_real_on_enabled_check_toggled;
	G_OBJECT_CLASS (klass)->finalize = rygel_tracker_pref_section_finalize;
}


static void rygel_tracker_pref_section_instance_init (RygelTrackerPrefSection * self) {
	self->priv = RYGEL_TRACKER_PREF_SECTION_GET_PRIVATE (self);
}


static void rygel_tracker_pref_section_finalize (GObject* obj) {
	RygelTrackerPrefSection * self;
	self = RYGEL_TRACKER_PREF_SECTION (obj);
	_g_object_unref0 (self->priv->videos_check);
	_g_object_unref0 (self->priv->music_check);
	_g_object_unref0 (self->priv->pictures_check);
	G_OBJECT_CLASS (rygel_tracker_pref_section_parent_class)->finalize (obj);
}


GType rygel_tracker_pref_section_get_type (void) {
	static GType rygel_tracker_pref_section_type_id = 0;
	if (rygel_tracker_pref_section_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelTrackerPrefSectionClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_tracker_pref_section_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelTrackerPrefSection), 0, (GInstanceInitFunc) rygel_tracker_pref_section_instance_init, NULL };
		rygel_tracker_pref_section_type_id = g_type_register_static (RYGEL_TYPE_PLUGIN_PREF_SECTION, "RygelTrackerPrefSection", &g_define_type_info, 0);
	}
	return rygel_tracker_pref_section_type_id;
}



