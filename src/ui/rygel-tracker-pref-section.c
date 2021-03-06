/* rygel-tracker-pref-section.c generated by valac, the Vala compiler
 * generated from rygel-tracker-pref-section.vala, do not modify */

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
	GeeArrayList* widgets;
};

struct _RygelPluginPrefSectionClass {
	RygelPreferencesSectionClass parent_class;
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

GType rygel_preferences_section_get_type (void) G_GNUC_CONST;
GType rygel_plugin_pref_section_get_type (void) G_GNUC_CONST;
GType rygel_tracker_pref_section_get_type (void) G_GNUC_CONST;
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
void rygel_plugin_pref_section_reset_widgets_sensitivity (RygelPluginPrefSection* self);
RygelTrackerPrefSection* rygel_tracker_pref_section_new (GtkBuilder* builder, RygelUserConfig* config);
RygelTrackerPrefSection* rygel_tracker_pref_section_construct (GType object_type, GtkBuilder* builder, RygelUserConfig* config);
void rygel_preferences_section_save (RygelPreferencesSection* self);
static void rygel_tracker_pref_section_real_save (RygelPreferencesSection* base);
static void rygel_tracker_pref_section_finalize (GObject* obj);



static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


#line 40 "rygel-tracker-pref-section.vala"
RygelTrackerPrefSection* rygel_tracker_pref_section_construct (GType object_type, GtkBuilder* builder, RygelUserConfig* config) {
#line 145 "rygel-tracker-pref-section.c"
	GError * _inner_error_;
	RygelTrackerPrefSection * self;
	GtkCheckButton* _tmp0_;
	GtkCheckButton* _tmp1_;
	GtkCheckButton* _tmp2_;
#line 40 "rygel-tracker-pref-section.vala"
	g_return_val_if_fail (builder != NULL, NULL);
#line 40 "rygel-tracker-pref-section.vala"
	g_return_val_if_fail (config != NULL, NULL);
#line 155 "rygel-tracker-pref-section.c"
	_inner_error_ = NULL;
#line 41 "rygel-tracker-pref-section.vala"
	self = (RygelTrackerPrefSection*) rygel_plugin_pref_section_construct (object_type, builder, config, RYGEL_TRACKER_PREF_SECTION_NAME);
#line 43 "rygel-tracker-pref-section.vala"
	self->priv->videos_check = (_tmp0_ = _g_object_ref0 (GTK_CHECK_BUTTON (gtk_builder_get_object (builder, RYGEL_TRACKER_PREF_SECTION_VIDEOS_CHECK))), _g_object_unref0 (self->priv->videos_check), _tmp0_);
#line 44 "rygel-tracker-pref-section.vala"
	g_assert (self->priv->videos_check != NULL);
#line 45 "rygel-tracker-pref-section.vala"
	self->priv->music_check = (_tmp1_ = _g_object_ref0 (GTK_CHECK_BUTTON (gtk_builder_get_object (builder, RYGEL_TRACKER_PREF_SECTION_MUSIC_CHECK))), _g_object_unref0 (self->priv->music_check), _tmp1_);
#line 46 "rygel-tracker-pref-section.vala"
	g_assert (self->priv->music_check != NULL);
#line 47 "rygel-tracker-pref-section.vala"
	self->priv->pictures_check = (_tmp2_ = _g_object_ref0 (GTK_CHECK_BUTTON (gtk_builder_get_object (builder, RYGEL_TRACKER_PREF_SECTION_PICTURES_CHECK))), _g_object_unref0 (self->priv->pictures_check), _tmp2_);
#line 48 "rygel-tracker-pref-section.vala"
	g_assert (self->priv->pictures_check != NULL);
#line 50 "rygel-tracker-pref-section.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) ((RygelPluginPrefSection*) self)->widgets, (GtkWidget*) self->priv->videos_check);
#line 51 "rygel-tracker-pref-section.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) ((RygelPluginPrefSection*) self)->widgets, (GtkWidget*) self->priv->music_check);
#line 52 "rygel-tracker-pref-section.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) ((RygelPluginPrefSection*) self)->widgets, (GtkWidget*) self->priv->pictures_check);
#line 54 "rygel-tracker-pref-section.vala"
	gtk_toggle_button_set_active ((GtkToggleButton*) self->priv->videos_check, TRUE);
#line 55 "rygel-tracker-pref-section.vala"
	gtk_toggle_button_set_active ((GtkToggleButton*) self->priv->music_check, TRUE);
#line 56 "rygel-tracker-pref-section.vala"
	gtk_toggle_button_set_active ((GtkToggleButton*) self->priv->pictures_check, TRUE);
#line 183 "rygel-tracker-pref-section.c"
	{
		gboolean _tmp3_;
		gboolean _tmp4_;
		gboolean _tmp5_;
#line 59 "rygel-tracker-pref-section.vala"
		_tmp3_ = rygel_configuration_get_bool ((RygelConfiguration*) config, ((RygelPreferencesSection*) self)->name, RYGEL_TRACKER_PREF_SECTION_VIDEOS_KEY, &_inner_error_);
#line 190 "rygel-tracker-pref-section.c"
		if (_inner_error_ != NULL) {
			goto __catch12_g_error;
		}
#line 59 "rygel-tracker-pref-section.vala"
		gtk_toggle_button_set_active ((GtkToggleButton*) self->priv->videos_check, _tmp3_);
#line 60 "rygel-tracker-pref-section.vala"
		_tmp4_ = rygel_configuration_get_bool ((RygelConfiguration*) config, ((RygelPreferencesSection*) self)->name, RYGEL_TRACKER_PREF_SECTION_MUSIC_KEY, &_inner_error_);
#line 198 "rygel-tracker-pref-section.c"
		if (_inner_error_ != NULL) {
			goto __catch12_g_error;
		}
#line 60 "rygel-tracker-pref-section.vala"
		gtk_toggle_button_set_active ((GtkToggleButton*) self->priv->music_check, _tmp4_);
#line 61 "rygel-tracker-pref-section.vala"
		_tmp5_ = rygel_configuration_get_bool ((RygelConfiguration*) config, ((RygelPreferencesSection*) self)->name, RYGEL_TRACKER_PREF_SECTION_PICTURES_KEY, &_inner_error_);
#line 206 "rygel-tracker-pref-section.c"
		if (_inner_error_ != NULL) {
			goto __catch12_g_error;
		}
#line 61 "rygel-tracker-pref-section.vala"
		gtk_toggle_button_set_active ((GtkToggleButton*) self->priv->pictures_check, _tmp5_);
#line 212 "rygel-tracker-pref-section.c"
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
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
#line 66 "rygel-tracker-pref-section.vala"
	rygel_plugin_pref_section_reset_widgets_sensitivity ((RygelPluginPrefSection*) self);
#line 232 "rygel-tracker-pref-section.c"
	return self;
}


#line 40 "rygel-tracker-pref-section.vala"
RygelTrackerPrefSection* rygel_tracker_pref_section_new (GtkBuilder* builder, RygelUserConfig* config) {
#line 40 "rygel-tracker-pref-section.vala"
	return rygel_tracker_pref_section_construct (RYGEL_TYPE_TRACKER_PREF_SECTION, builder, config);
#line 241 "rygel-tracker-pref-section.c"
}


#line 69 "rygel-tracker-pref-section.vala"
static void rygel_tracker_pref_section_real_save (RygelPreferencesSection* base) {
#line 247 "rygel-tracker-pref-section.c"
	RygelTrackerPrefSection * self;
	self = (RygelTrackerPrefSection*) base;
#line 70 "rygel-tracker-pref-section.vala"
	RYGEL_PREFERENCES_SECTION_CLASS (rygel_tracker_pref_section_parent_class)->save ((RygelPreferencesSection*) RYGEL_PLUGIN_PREF_SECTION (self));
#line 72 "rygel-tracker-pref-section.vala"
	rygel_user_config_set_bool (((RygelPreferencesSection*) self)->config, ((RygelPreferencesSection*) self)->name, RYGEL_TRACKER_PREF_SECTION_VIDEOS_KEY, gtk_toggle_button_get_active ((GtkToggleButton*) self->priv->videos_check));
#line 73 "rygel-tracker-pref-section.vala"
	rygel_user_config_set_bool (((RygelPreferencesSection*) self)->config, ((RygelPreferencesSection*) self)->name, RYGEL_TRACKER_PREF_SECTION_MUSIC_KEY, gtk_toggle_button_get_active ((GtkToggleButton*) self->priv->music_check));
#line 74 "rygel-tracker-pref-section.vala"
	rygel_user_config_set_bool (((RygelPreferencesSection*) self)->config, ((RygelPreferencesSection*) self)->name, RYGEL_TRACKER_PREF_SECTION_PICTURES_KEY, gtk_toggle_button_get_active ((GtkToggleButton*) self->priv->pictures_check));
#line 258 "rygel-tracker-pref-section.c"
}


static void rygel_tracker_pref_section_class_init (RygelTrackerPrefSectionClass * klass) {
	rygel_tracker_pref_section_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelTrackerPrefSectionPrivate));
	RYGEL_PREFERENCES_SECTION_CLASS (klass)->save = rygel_tracker_pref_section_real_save;
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
	static volatile gsize rygel_tracker_pref_section_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_tracker_pref_section_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelTrackerPrefSectionClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_tracker_pref_section_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelTrackerPrefSection), 0, (GInstanceInitFunc) rygel_tracker_pref_section_instance_init, NULL };
		GType rygel_tracker_pref_section_type_id;
		rygel_tracker_pref_section_type_id = g_type_register_static (RYGEL_TYPE_PLUGIN_PREF_SECTION, "RygelTrackerPrefSection", &g_define_type_info, 0);
		g_once_init_leave (&rygel_tracker_pref_section_type_id__volatile, rygel_tracker_pref_section_type_id);
	}
	return rygel_tracker_pref_section_type_id__volatile;
}




