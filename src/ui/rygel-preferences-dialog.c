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
#include <gtk/gtk.h>
#include <gee.h>
#include <stdlib.h>
#include <string.h>


#define RYGEL_TYPE_PREFERENCES_DIALOG (rygel_preferences_dialog_get_type ())
#define RYGEL_PREFERENCES_DIALOG(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_PREFERENCES_DIALOG, RygelPreferencesDialog))
#define RYGEL_PREFERENCES_DIALOG_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_PREFERENCES_DIALOG, RygelPreferencesDialogClass))
#define RYGEL_IS_PREFERENCES_DIALOG(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_PREFERENCES_DIALOG))
#define RYGEL_IS_PREFERENCES_DIALOG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_PREFERENCES_DIALOG))
#define RYGEL_PREFERENCES_DIALOG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_PREFERENCES_DIALOG, RygelPreferencesDialogClass))

typedef struct _RygelPreferencesDialog RygelPreferencesDialog;
typedef struct _RygelPreferencesDialogClass RygelPreferencesDialogClass;
typedef struct _RygelPreferencesDialogPrivate RygelPreferencesDialogPrivate;

#define RYGEL_TYPE_PREFERENCES_SECTION (rygel_preferences_section_get_type ())
#define RYGEL_PREFERENCES_SECTION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_PREFERENCES_SECTION, RygelPreferencesSection))
#define RYGEL_PREFERENCES_SECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_PREFERENCES_SECTION, RygelPreferencesSectionClass))
#define RYGEL_IS_PREFERENCES_SECTION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_PREFERENCES_SECTION))
#define RYGEL_IS_PREFERENCES_SECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_PREFERENCES_SECTION))
#define RYGEL_PREFERENCES_SECTION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_PREFERENCES_SECTION, RygelPreferencesSectionClass))

typedef struct _RygelPreferencesSection RygelPreferencesSection;
typedef struct _RygelPreferencesSectionClass RygelPreferencesSectionClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define RYGEL_TYPE_GENERAL_PREF_SECTION (rygel_general_pref_section_get_type ())
#define RYGEL_GENERAL_PREF_SECTION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_GENERAL_PREF_SECTION, RygelGeneralPrefSection))
#define RYGEL_GENERAL_PREF_SECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_GENERAL_PREF_SECTION, RygelGeneralPrefSectionClass))
#define RYGEL_IS_GENERAL_PREF_SECTION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_GENERAL_PREF_SECTION))
#define RYGEL_IS_GENERAL_PREF_SECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_GENERAL_PREF_SECTION))
#define RYGEL_GENERAL_PREF_SECTION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_GENERAL_PREF_SECTION, RygelGeneralPrefSectionClass))

typedef struct _RygelGeneralPrefSection RygelGeneralPrefSection;
typedef struct _RygelGeneralPrefSectionClass RygelGeneralPrefSectionClass;

#define RYGEL_TYPE_PLUGIN_PREF_SECTION (rygel_plugin_pref_section_get_type ())
#define RYGEL_PLUGIN_PREF_SECTION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_PLUGIN_PREF_SECTION, RygelPluginPrefSection))
#define RYGEL_PLUGIN_PREF_SECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_PLUGIN_PREF_SECTION, RygelPluginPrefSectionClass))
#define RYGEL_IS_PLUGIN_PREF_SECTION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_PLUGIN_PREF_SECTION))
#define RYGEL_IS_PLUGIN_PREF_SECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_PLUGIN_PREF_SECTION))
#define RYGEL_PLUGIN_PREF_SECTION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_PLUGIN_PREF_SECTION, RygelPluginPrefSectionClass))

typedef struct _RygelPluginPrefSection RygelPluginPrefSection;
typedef struct _RygelPluginPrefSectionClass RygelPluginPrefSectionClass;

#define RYGEL_TYPE_TRACKER_PREF_SECTION (rygel_tracker_pref_section_get_type ())
#define RYGEL_TRACKER_PREF_SECTION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRACKER_PREF_SECTION, RygelTrackerPrefSection))
#define RYGEL_TRACKER_PREF_SECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRACKER_PREF_SECTION, RygelTrackerPrefSectionClass))
#define RYGEL_IS_TRACKER_PREF_SECTION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRACKER_PREF_SECTION))
#define RYGEL_IS_TRACKER_PREF_SECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRACKER_PREF_SECTION))
#define RYGEL_TRACKER_PREF_SECTION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRACKER_PREF_SECTION, RygelTrackerPrefSectionClass))

typedef struct _RygelTrackerPrefSection RygelTrackerPrefSection;
typedef struct _RygelTrackerPrefSectionClass RygelTrackerPrefSectionClass;

#define RYGEL_TYPE_MEDIA_EXPORT_PREF_SECTION (rygel_media_export_pref_section_get_type ())
#define RYGEL_MEDIA_EXPORT_PREF_SECTION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_EXPORT_PREF_SECTION, RygelMediaExportPrefSection))
#define RYGEL_MEDIA_EXPORT_PREF_SECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_EXPORT_PREF_SECTION, RygelMediaExportPrefSectionClass))
#define RYGEL_IS_MEDIA_EXPORT_PREF_SECTION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_EXPORT_PREF_SECTION))
#define RYGEL_IS_MEDIA_EXPORT_PREF_SECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_EXPORT_PREF_SECTION))
#define RYGEL_MEDIA_EXPORT_PREF_SECTION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_EXPORT_PREF_SECTION, RygelMediaExportPrefSectionClass))

typedef struct _RygelMediaExportPrefSection RygelMediaExportPrefSection;
typedef struct _RygelMediaExportPrefSectionClass RygelMediaExportPrefSectionClass;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _RygelPreferencesDialog {
	GObject parent_instance;
	RygelPreferencesDialogPrivate * priv;
};

struct _RygelPreferencesDialogClass {
	GObjectClass parent_class;
};

struct _RygelPreferencesDialogPrivate {
	RygelUserConfig* config;
	GtkBuilder* builder;
	GtkDialog* dialog;
	GeeArrayList* sections;
};


static gpointer rygel_preferences_dialog_parent_class = NULL;

GType rygel_preferences_dialog_get_type (void);
GType rygel_preferences_section_get_type (void);
#define RYGEL_PREFERENCES_DIALOG_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_PREFERENCES_DIALOG, RygelPreferencesDialogPrivate))
enum  {
	RYGEL_PREFERENCES_DIALOG_DUMMY_PROPERTY
};
#define RYGEL_PREFERENCES_DIALOG_UI_FILE DATA_DIR "/rygel-preferences.ui"
#define RYGEL_PREFERENCES_DIALOG_DIALOG "preferences-dialog"
RygelGeneralPrefSection* rygel_general_pref_section_new (GtkBuilder* builder, RygelUserConfig* config, GError** error);
RygelGeneralPrefSection* rygel_general_pref_section_construct (GType object_type, GtkBuilder* builder, RygelUserConfig* config, GError** error);
GType rygel_general_pref_section_get_type (void);
RygelTrackerPrefSection* rygel_tracker_pref_section_new (GtkBuilder* builder, RygelUserConfig* config);
RygelTrackerPrefSection* rygel_tracker_pref_section_construct (GType object_type, GtkBuilder* builder, RygelUserConfig* config);
GType rygel_plugin_pref_section_get_type (void);
GType rygel_tracker_pref_section_get_type (void);
RygelMediaExportPrefSection* rygel_media_export_pref_section_new (GtkBuilder* builder, RygelUserConfig* config);
RygelMediaExportPrefSection* rygel_media_export_pref_section_construct (GType object_type, GtkBuilder* builder, RygelUserConfig* config);
GType rygel_media_export_pref_section_get_type (void);
RygelPreferencesDialog* rygel_preferences_dialog_new (GError** error);
RygelPreferencesDialog* rygel_preferences_dialog_construct (GType object_type, GError** error);
void rygel_preferences_section_save (RygelPreferencesSection* self);
void rygel_preferences_dialog_run (RygelPreferencesDialog* self);
gint rygel_preferences_dialog_main (char** args, int args_length1);
static void rygel_preferences_dialog_finalize (GObject* obj);



static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


RygelPreferencesDialog* rygel_preferences_dialog_construct (GType object_type, GError** error) {
	GError * _inner_error_;
	RygelPreferencesDialog * self;
	RygelUserConfig* _tmp0_;
	RygelUserConfig* _tmp1_;
	GtkBuilder* _tmp2_;
	GtkDialog* _tmp3_;
	GeeArrayList* _tmp4_;
	RygelGeneralPrefSection* _tmp5_;
	RygelGeneralPrefSection* _tmp6_;
	RygelTrackerPrefSection* _tmp7_;
	RygelMediaExportPrefSection* _tmp8_;
	_inner_error_ = NULL;
	self = (RygelPreferencesDialog*) g_object_new (object_type, NULL);
	_tmp0_ = rygel_user_config_new (FALSE, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return;
	}
	self->priv->config = (_tmp1_ = _tmp0_, _g_object_unref0 (self->priv->config), _tmp1_);
	self->priv->builder = (_tmp2_ = gtk_builder_new (), _g_object_unref0 (self->priv->builder), _tmp2_);
	gtk_builder_add_from_file (self->priv->builder, RYGEL_PREFERENCES_DIALOG_UI_FILE, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return;
	}
	self->priv->dialog = (_tmp3_ = _g_object_ref0 (GTK_DIALOG (gtk_builder_get_object (self->priv->builder, RYGEL_PREFERENCES_DIALOG_DIALOG))), _g_object_unref0 (self->priv->dialog), _tmp3_);
	g_assert (self->priv->dialog != NULL);
	self->priv->sections = (_tmp4_ = gee_array_list_new (RYGEL_TYPE_PREFERENCES_SECTION, (GBoxedCopyFunc) g_object_ref, g_object_unref, g_direct_equal), _g_object_unref0 (self->priv->sections), _tmp4_);
	_tmp5_ = rygel_general_pref_section_new (self->priv->builder, self->priv->config, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return;
	}
	gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->sections, (RygelPreferencesSection*) (_tmp6_ = _tmp5_));
	_g_object_unref0 (_tmp6_);
	gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->sections, (RygelPreferencesSection*) (_tmp7_ = rygel_tracker_pref_section_new (self->priv->builder, self->priv->config)));
	_g_object_unref0 (_tmp7_);
	gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->sections, (RygelPreferencesSection*) (_tmp8_ = rygel_media_export_pref_section_new (self->priv->builder, self->priv->config)));
	_g_object_unref0 (_tmp8_);
	return self;
}


RygelPreferencesDialog* rygel_preferences_dialog_new (GError** error) {
	return rygel_preferences_dialog_construct (RYGEL_TYPE_PREFERENCES_DIALOG, error);
}


void rygel_preferences_dialog_run (RygelPreferencesDialog* self) {
	g_return_if_fail (self != NULL);
	gtk_dialog_run (self->priv->dialog);
	{
		GeeIterator* _section_it;
		_section_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->sections);
		while (TRUE) {
			RygelPreferencesSection* section;
			if (!gee_iterator_next (_section_it)) {
				break;
			}
			section = (RygelPreferencesSection*) gee_iterator_get (_section_it);
			rygel_preferences_section_save (section);
			_g_object_unref0 (section);
		}
		_g_object_unref0 (_section_it);
	}
	rygel_user_config_save (self->priv->config);
}


gint rygel_preferences_dialog_main (char** args, int args_length1) {
	gint result;
	GError * _inner_error_;
	_inner_error_ = NULL;
	gtk_init (&args_length1, &args);
	{
		RygelPreferencesDialog* dialog;
		dialog = rygel_preferences_dialog_new (&_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch0_g_error;
			goto __finally0;
		}
		rygel_preferences_dialog_run (dialog);
		_g_object_unref0 (dialog);
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			g_error ("rygel-preferences-dialog.vala:70: Failed to create preferences dialog: %s\n", err->message);
			_g_error_free0 (err);
		}
	}
	__finally0:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return 0;
	}
	result = 0;
	return result;
}


int main (int argc, char ** argv) {
	g_thread_init (NULL);
	g_type_init ();
	return rygel_preferences_dialog_main (argv, argc);
}


static void rygel_preferences_dialog_class_init (RygelPreferencesDialogClass * klass) {
	rygel_preferences_dialog_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelPreferencesDialogPrivate));
	G_OBJECT_CLASS (klass)->finalize = rygel_preferences_dialog_finalize;
}


static void rygel_preferences_dialog_instance_init (RygelPreferencesDialog * self) {
	self->priv = RYGEL_PREFERENCES_DIALOG_GET_PRIVATE (self);
}


static void rygel_preferences_dialog_finalize (GObject* obj) {
	RygelPreferencesDialog * self;
	self = RYGEL_PREFERENCES_DIALOG (obj);
	_g_object_unref0 (self->priv->config);
	_g_object_unref0 (self->priv->builder);
	_g_object_unref0 (self->priv->dialog);
	_g_object_unref0 (self->priv->sections);
	G_OBJECT_CLASS (rygel_preferences_dialog_parent_class)->finalize (obj);
}


GType rygel_preferences_dialog_get_type (void) {
	static GType rygel_preferences_dialog_type_id = 0;
	if (rygel_preferences_dialog_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelPreferencesDialogClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_preferences_dialog_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelPreferencesDialog), 0, (GInstanceInitFunc) rygel_preferences_dialog_instance_init, NULL };
		rygel_preferences_dialog_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelPreferencesDialog", &g_define_type_info, 0);
	}
	return rygel_preferences_dialog_type_id;
}




