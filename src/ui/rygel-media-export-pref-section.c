/* rygel-media-export-pref-section.c generated by valac, the Vala compiler
 * generated from rygel-media-export-pref-section.vala, do not modify */

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
#include <gio/gio.h>


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

#define RYGEL_TYPE_MEDIA_EXPORT_PREF_SECTION (rygel_media_export_pref_section_get_type ())
#define RYGEL_MEDIA_EXPORT_PREF_SECTION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_EXPORT_PREF_SECTION, RygelMediaExportPrefSection))
#define RYGEL_MEDIA_EXPORT_PREF_SECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_EXPORT_PREF_SECTION, RygelMediaExportPrefSectionClass))
#define RYGEL_IS_MEDIA_EXPORT_PREF_SECTION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_EXPORT_PREF_SECTION))
#define RYGEL_IS_MEDIA_EXPORT_PREF_SECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_EXPORT_PREF_SECTION))
#define RYGEL_MEDIA_EXPORT_PREF_SECTION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_EXPORT_PREF_SECTION, RygelMediaExportPrefSectionClass))

typedef struct _RygelMediaExportPrefSection RygelMediaExportPrefSection;
typedef struct _RygelMediaExportPrefSectionClass RygelMediaExportPrefSectionClass;
typedef struct _RygelMediaExportPrefSectionPrivate RygelMediaExportPrefSectionPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define __g_slist_free_g_object_unref0(var) ((var == NULL) ? NULL : (var = (_g_slist_free_g_object_unref (var), NULL)))
#define _gtk_tree_row_reference_free0(var) ((var == NULL) ? NULL : (var = (gtk_tree_row_reference_free (var), NULL)))
#define _gtk_tree_path_free0(var) ((var == NULL) ? NULL : (var = (gtk_tree_path_free (var), NULL)))
#define __g_list_free_gtk_tree_path_free0(var) ((var == NULL) ? NULL : (var = (_g_list_free_gtk_tree_path_free (var), NULL)))

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

struct _RygelMediaExportPrefSection {
	RygelPluginPrefSection parent_instance;
	RygelMediaExportPrefSectionPrivate * priv;
};

struct _RygelMediaExportPrefSectionClass {
	RygelPluginPrefSectionClass parent_class;
};

struct _RygelMediaExportPrefSectionPrivate {
	GtkTreeView* treeview;
	GtkListStore* liststore;
	GtkFileChooserDialog* dialog;
};


static gpointer rygel_media_export_pref_section_parent_class = NULL;

GType rygel_preferences_section_get_type (void) G_GNUC_CONST;
GType rygel_plugin_pref_section_get_type (void) G_GNUC_CONST;
GType rygel_media_export_pref_section_get_type (void) G_GNUC_CONST;
#define RYGEL_MEDIA_EXPORT_PREF_SECTION_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_MEDIA_EXPORT_PREF_SECTION, RygelMediaExportPrefSectionPrivate))
enum  {
	RYGEL_MEDIA_EXPORT_PREF_SECTION_DUMMY_PROPERTY
};
#define RYGEL_MEDIA_EXPORT_PREF_SECTION_NAME "MediaExport"
#define RYGEL_MEDIA_EXPORT_PREF_SECTION_URIS_KEY "uris"
#define RYGEL_MEDIA_EXPORT_PREF_SECTION_URIS_LABEL RYGEL_MEDIA_EXPORT_PREF_SECTION_URIS_KEY "-label"
#define RYGEL_MEDIA_EXPORT_PREF_SECTION_URIS_TEXTVIEW RYGEL_MEDIA_EXPORT_PREF_SECTION_URIS_KEY "-treeview"
#define RYGEL_MEDIA_EXPORT_PREF_SECTION_URIS_LISTSTORE RYGEL_MEDIA_EXPORT_PREF_SECTION_URIS_KEY "-liststore"
#define RYGEL_MEDIA_EXPORT_PREF_SECTION_URIS_DIALOG RYGEL_MEDIA_EXPORT_PREF_SECTION_URIS_KEY "-dialog"
#define RYGEL_MEDIA_EXPORT_PREF_SECTION_ADD_BUTTON "add-button"
#define RYGEL_MEDIA_EXPORT_PREF_SECTION_REMOVE_BUTTON "remove-button"
#define RYGEL_MEDIA_EXPORT_PREF_SECTION_CLEAR_BUTTON "clear-button"
RygelPluginPrefSection* rygel_plugin_pref_section_new (GtkBuilder* builder, RygelUserConfig* config, const char* name);
RygelPluginPrefSection* rygel_plugin_pref_section_construct (GType object_type, GtkBuilder* builder, RygelUserConfig* config, const char* name);
static void rygel_media_export_pref_section_on_add_button_clicked (RygelMediaExportPrefSection* self, GtkButton* button);
static void _rygel_media_export_pref_section_on_add_button_clicked_gtk_button_clicked (GtkButton* _sender, gpointer self);
static void rygel_media_export_pref_section_on_remove_button_clicked (RygelMediaExportPrefSection* self, GtkButton* button);
static void _rygel_media_export_pref_section_on_remove_button_clicked_gtk_button_clicked (GtkButton* _sender, gpointer self);
static void rygel_media_export_pref_section_on_clear_button_clicked (RygelMediaExportPrefSection* self, GtkButton* button);
static void _rygel_media_export_pref_section_on_clear_button_clicked_gtk_button_clicked (GtkButton* _sender, gpointer self);
void rygel_plugin_pref_section_reset_widgets_sensitivity (RygelPluginPrefSection* self);
RygelMediaExportPrefSection* rygel_media_export_pref_section_new (GtkBuilder* builder, RygelUserConfig* config);
RygelMediaExportPrefSection* rygel_media_export_pref_section_construct (GType object_type, GtkBuilder* builder, RygelUserConfig* config);
void rygel_preferences_section_save (RygelPreferencesSection* self);
static void rygel_media_export_pref_section_real_save (RygelPreferencesSection* base);
static void _g_slist_free_g_object_unref (GSList* self);
static void _g_list_free_gtk_tree_path_free (GList* self);
static void rygel_media_export_pref_section_finalize (GObject* obj);



static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


#line 111 "rygel-media-export-pref-section.vala"
static void _rygel_media_export_pref_section_on_add_button_clicked_gtk_button_clicked (GtkButton* _sender, gpointer self) {
#line 160 "rygel-media-export-pref-section.c"
	rygel_media_export_pref_section_on_add_button_clicked (self, _sender);
}


#line 132 "rygel-media-export-pref-section.vala"
static void _rygel_media_export_pref_section_on_remove_button_clicked_gtk_button_clicked (GtkButton* _sender, gpointer self) {
#line 167 "rygel-media-export-pref-section.c"
	rygel_media_export_pref_section_on_remove_button_clicked (self, _sender);
}


#line 153 "rygel-media-export-pref-section.vala"
static void _rygel_media_export_pref_section_on_clear_button_clicked_gtk_button_clicked (GtkButton* _sender, gpointer self) {
#line 174 "rygel-media-export-pref-section.c"
	rygel_media_export_pref_section_on_clear_button_clicked (self, _sender);
}


#line 41 "rygel-media-export-pref-section.vala"
RygelMediaExportPrefSection* rygel_media_export_pref_section_construct (GType object_type, GtkBuilder* builder, RygelUserConfig* config) {
#line 181 "rygel-media-export-pref-section.c"
	GError * _inner_error_;
	RygelMediaExportPrefSection * self;
	GtkTreeView* _tmp0_;
	GtkListStore* _tmp1_;
	GtkFileChooserDialog* _tmp2_;
	GtkCellRendererText* _tmp3_;
	GtkButton* button;
	GtkButton* _tmp4_;
	GtkButton* _tmp5_;
	GtkLabel* label;
#line 41 "rygel-media-export-pref-section.vala"
	g_return_val_if_fail (builder != NULL, NULL);
#line 41 "rygel-media-export-pref-section.vala"
	g_return_val_if_fail (config != NULL, NULL);
#line 196 "rygel-media-export-pref-section.c"
	_inner_error_ = NULL;
#line 43 "rygel-media-export-pref-section.vala"
	self = (RygelMediaExportPrefSection*) rygel_plugin_pref_section_construct (object_type, builder, config, RYGEL_MEDIA_EXPORT_PREF_SECTION_NAME);
#line 45 "rygel-media-export-pref-section.vala"
	self->priv->treeview = (_tmp0_ = _g_object_ref0 (GTK_TREE_VIEW (gtk_builder_get_object (builder, RYGEL_MEDIA_EXPORT_PREF_SECTION_URIS_TEXTVIEW))), _g_object_unref0 (self->priv->treeview), _tmp0_);
#line 46 "rygel-media-export-pref-section.vala"
	g_assert (self->priv->treeview != NULL);
#line 47 "rygel-media-export-pref-section.vala"
	self->priv->liststore = (_tmp1_ = _g_object_ref0 (GTK_LIST_STORE (gtk_builder_get_object (builder, RYGEL_MEDIA_EXPORT_PREF_SECTION_URIS_LISTSTORE))), _g_object_unref0 (self->priv->liststore), _tmp1_);
#line 48 "rygel-media-export-pref-section.vala"
	g_assert (self->priv->liststore != NULL);
#line 49 "rygel-media-export-pref-section.vala"
	self->priv->dialog = (_tmp2_ = _g_object_ref0 (GTK_FILE_CHOOSER_DIALOG (gtk_builder_get_object (builder, RYGEL_MEDIA_EXPORT_PREF_SECTION_URIS_DIALOG))), _g_object_unref0 (self->priv->dialog), _tmp2_);
#line 50 "rygel-media-export-pref-section.vala"
	g_assert (self->priv->dialog != NULL);
#line 52 "rygel-media-export-pref-section.vala"
	gtk_tree_view_insert_column_with_attributes (self->priv->treeview, -1, "paths", (GtkCellRenderer*) (_tmp3_ = g_object_ref_sink ((GtkCellRendererText*) gtk_cell_renderer_text_new ())), "text", 0, NULL, NULL);
#line 214 "rygel-media-export-pref-section.c"
	_g_object_unref0 (_tmp3_);
#line 58 "rygel-media-export-pref-section.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) ((RygelPluginPrefSection*) self)->widgets, (GtkWidget*) self->priv->treeview);
#line 218 "rygel-media-export-pref-section.c"
	{
		GeeArrayList* uris;
#line 61 "rygel-media-export-pref-section.vala"
		uris = rygel_configuration_get_string_list ((RygelConfiguration*) config, ((RygelPreferencesSection*) self)->name, RYGEL_MEDIA_EXPORT_PREF_SECTION_URIS_KEY, &_inner_error_);
#line 223 "rygel-media-export-pref-section.c"
		if (_inner_error_ != NULL) {
			goto __catch11_g_error;
		}
		{
			GeeIterator* _uri_it;
#line 62 "rygel-media-export-pref-section.vala"
			_uri_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) uris);
#line 62 "rygel-media-export-pref-section.vala"
			while (TRUE) {
#line 233 "rygel-media-export-pref-section.c"
				char* uri;
				GtkTreeIter iter = {0};
#line 62 "rygel-media-export-pref-section.vala"
				if (!gee_iterator_next (_uri_it)) {
#line 62 "rygel-media-export-pref-section.vala"
					break;
#line 240 "rygel-media-export-pref-section.c"
				}
#line 62 "rygel-media-export-pref-section.vala"
				uri = (char*) gee_iterator_get (_uri_it);
#line 65 "rygel-media-export-pref-section.vala"
				gtk_list_store_append (self->priv->liststore, &iter);
#line 66 "rygel-media-export-pref-section.vala"
				gtk_list_store_set (self->priv->liststore, &iter, 0, uri, -1, -1);
#line 248 "rygel-media-export-pref-section.c"
				_g_free0 (uri);
			}
			_g_object_unref0 (_uri_it);
		}
		_g_object_unref0 (uris);
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
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
#line 70 "rygel-media-export-pref-section.vala"
	gtk_file_chooser_set_current_folder ((GtkFileChooser*) self->priv->dialog, g_get_home_dir ());
#line 71 "rygel-media-export-pref-section.vala"
	gtk_file_chooser_set_show_hidden ((GtkFileChooser*) self->priv->dialog, FALSE);
#line 73 "rygel-media-export-pref-section.vala"
	button = _g_object_ref0 (GTK_BUTTON (gtk_builder_get_object (builder, RYGEL_MEDIA_EXPORT_PREF_SECTION_ADD_BUTTON)));
#line 74 "rygel-media-export-pref-section.vala"
	g_signal_connect_object (button, "clicked", (GCallback) _rygel_media_export_pref_section_on_add_button_clicked_gtk_button_clicked, self, 0);
#line 75 "rygel-media-export-pref-section.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) ((RygelPluginPrefSection*) self)->widgets, (GtkWidget*) button);
#line 77 "rygel-media-export-pref-section.vala"
	button = (_tmp4_ = _g_object_ref0 (GTK_BUTTON (gtk_builder_get_object (builder, RYGEL_MEDIA_EXPORT_PREF_SECTION_REMOVE_BUTTON))), _g_object_unref0 (button), _tmp4_);
#line 78 "rygel-media-export-pref-section.vala"
	g_signal_connect_object (button, "clicked", (GCallback) _rygel_media_export_pref_section_on_remove_button_clicked_gtk_button_clicked, self, 0);
#line 79 "rygel-media-export-pref-section.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) ((RygelPluginPrefSection*) self)->widgets, (GtkWidget*) button);
#line 81 "rygel-media-export-pref-section.vala"
	button = (_tmp5_ = _g_object_ref0 (GTK_BUTTON (gtk_builder_get_object (builder, RYGEL_MEDIA_EXPORT_PREF_SECTION_CLEAR_BUTTON))), _g_object_unref0 (button), _tmp5_);
#line 82 "rygel-media-export-pref-section.vala"
	g_signal_connect_object (button, "clicked", (GCallback) _rygel_media_export_pref_section_on_clear_button_clicked_gtk_button_clicked, self, 0);
#line 83 "rygel-media-export-pref-section.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) ((RygelPluginPrefSection*) self)->widgets, (GtkWidget*) button);
#line 85 "rygel-media-export-pref-section.vala"
	label = _g_object_ref0 (GTK_LABEL (gtk_builder_get_object (builder, RYGEL_MEDIA_EXPORT_PREF_SECTION_URIS_LABEL)));
#line 86 "rygel-media-export-pref-section.vala"
	g_assert (label != NULL);
#line 87 "rygel-media-export-pref-section.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) ((RygelPluginPrefSection*) self)->widgets, (GtkWidget*) label);
#line 90 "rygel-media-export-pref-section.vala"
	rygel_plugin_pref_section_reset_widgets_sensitivity ((RygelPluginPrefSection*) self);
#line 301 "rygel-media-export-pref-section.c"
	_g_object_unref0 (label);
	_g_object_unref0 (button);
	return self;
}


#line 41 "rygel-media-export-pref-section.vala"
RygelMediaExportPrefSection* rygel_media_export_pref_section_new (GtkBuilder* builder, RygelUserConfig* config) {
#line 41 "rygel-media-export-pref-section.vala"
	return rygel_media_export_pref_section_construct (RYGEL_TYPE_MEDIA_EXPORT_PREF_SECTION, builder, config);
#line 312 "rygel-media-export-pref-section.c"
}


#line 93 "rygel-media-export-pref-section.vala"
static void rygel_media_export_pref_section_real_save (RygelPreferencesSection* base) {
#line 318 "rygel-media-export-pref-section.c"
	RygelMediaExportPrefSection * self;
	GtkTreeIter iter = {0};
	GeeArrayList* uri_list;
	self = (RygelMediaExportPrefSection*) base;
#line 94 "rygel-media-export-pref-section.vala"
	RYGEL_PREFERENCES_SECTION_CLASS (rygel_media_export_pref_section_parent_class)->save ((RygelPreferencesSection*) RYGEL_PLUGIN_PREF_SECTION (self));
#line 97 "rygel-media-export-pref-section.vala"
	uri_list = gee_array_list_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, NULL);
#line 99 "rygel-media-export-pref-section.vala"
	if (gtk_tree_model_get_iter_first ((GtkTreeModel*) self->priv->liststore, &iter)) {
#line 329 "rygel-media-export-pref-section.c"
		{
			gboolean _tmp0_;
#line 100 "rygel-media-export-pref-section.vala"
			_tmp0_ = TRUE;
#line 100 "rygel-media-export-pref-section.vala"
			while (TRUE) {
#line 336 "rygel-media-export-pref-section.c"
				char* uri;
#line 100 "rygel-media-export-pref-section.vala"
				if (!_tmp0_) {
#line 105 "rygel-media-export-pref-section.vala"
					if (!gtk_tree_model_iter_next ((GtkTreeModel*) self->priv->liststore, &iter)) {
#line 105 "rygel-media-export-pref-section.vala"
						break;
#line 344 "rygel-media-export-pref-section.c"
					}
				}
#line 100 "rygel-media-export-pref-section.vala"
				_tmp0_ = FALSE;
#line 349 "rygel-media-export-pref-section.c"
				uri = NULL;
#line 103 "rygel-media-export-pref-section.vala"
				gtk_tree_model_get ((GtkTreeModel*) self->priv->liststore, &iter, 0, &uri, -1, -1);
#line 104 "rygel-media-export-pref-section.vala"
				gee_abstract_collection_add ((GeeAbstractCollection*) uri_list, uri);
#line 355 "rygel-media-export-pref-section.c"
				_g_free0 (uri);
			}
		}
	}
#line 108 "rygel-media-export-pref-section.vala"
	rygel_user_config_set_string_list (((RygelPreferencesSection*) self)->config, ((RygelPreferencesSection*) self)->name, RYGEL_MEDIA_EXPORT_PREF_SECTION_URIS_KEY, uri_list);
#line 362 "rygel-media-export-pref-section.c"
	_g_object_unref0 (uri_list);
}


static void _g_slist_free_g_object_unref (GSList* self) {
	g_slist_foreach (self, (GFunc) g_object_unref, NULL);
	g_slist_free (self);
}


#line 111 "rygel-media-export-pref-section.vala"
static void rygel_media_export_pref_section_on_add_button_clicked (RygelMediaExportPrefSection* self, GtkButton* button) {
#line 111 "rygel-media-export-pref-section.vala"
	g_return_if_fail (self != NULL);
#line 111 "rygel-media-export-pref-section.vala"
	g_return_if_fail (button != NULL);
#line 112 "rygel-media-export-pref-section.vala"
	if (gtk_dialog_run ((GtkDialog*) self->priv->dialog) == GTK_RESPONSE_OK) {
#line 381 "rygel-media-export-pref-section.c"
		GtkTreeIter iter = {0};
		GSList* dirs;
#line 115 "rygel-media-export-pref-section.vala"
		dirs = gtk_file_chooser_get_files ((GtkFileChooser*) self->priv->dialog);
#line 386 "rygel-media-export-pref-section.c"
		{
			GSList* dir_collection;
			GSList* dir_it;
#line 117 "rygel-media-export-pref-section.vala"
			dir_collection = dirs;
#line 392 "rygel-media-export-pref-section.c"
			for (dir_it = dir_collection; dir_it != NULL; dir_it = dir_it->next) {
				GFile* dir;
#line 117 "rygel-media-export-pref-section.vala"
				dir = _g_object_ref0 ((GFile*) dir_it->data);
#line 397 "rygel-media-export-pref-section.c"
				{
					char* path;
#line 118 "rygel-media-export-pref-section.vala"
					path = g_file_get_path (dir);
#line 120 "rygel-media-export-pref-section.vala"
					if (path == NULL) {
#line 404 "rygel-media-export-pref-section.c"
						char* _tmp0_;
#line 121 "rygel-media-export-pref-section.vala"
						path = (_tmp0_ = g_file_get_uri (dir), _g_free0 (path), _tmp0_);
#line 408 "rygel-media-export-pref-section.c"
					}
#line 124 "rygel-media-export-pref-section.vala"
					gtk_list_store_append (self->priv->liststore, &iter);
#line 125 "rygel-media-export-pref-section.vala"
					gtk_list_store_set (self->priv->liststore, &iter, 0, path, -1, -1);
#line 414 "rygel-media-export-pref-section.c"
					_g_free0 (path);
					_g_object_unref0 (dir);
				}
			}
		}
		__g_slist_free_g_object_unref0 (dirs);
	}
#line 129 "rygel-media-export-pref-section.vala"
	gtk_widget_hide ((GtkWidget*) self->priv->dialog);
#line 424 "rygel-media-export-pref-section.c"
}


static gpointer _gtk_tree_path_copy0 (gpointer self) {
	return self ? gtk_tree_path_copy (self) : NULL;
}


static void _g_list_free_gtk_tree_path_free (GList* self) {
	g_list_foreach (self, (GFunc) gtk_tree_path_free, NULL);
	g_list_free (self);
}


#line 132 "rygel-media-export-pref-section.vala"
static void rygel_media_export_pref_section_on_remove_button_clicked (RygelMediaExportPrefSection* self, GtkButton* button) {
#line 441 "rygel-media-export-pref-section.c"
	GtkTreeSelection* selection;
	GList* rows;
	GeeArrayList* row_refs;
#line 132 "rygel-media-export-pref-section.vala"
	g_return_if_fail (self != NULL);
#line 132 "rygel-media-export-pref-section.vala"
	g_return_if_fail (button != NULL);
#line 133 "rygel-media-export-pref-section.vala"
	selection = _g_object_ref0 (gtk_tree_view_get_selection (self->priv->treeview));
#line 134 "rygel-media-export-pref-section.vala"
	rows = gtk_tree_selection_get_selected_rows (selection, NULL);
#line 137 "rygel-media-export-pref-section.vala"
	row_refs = gee_array_list_new (GTK_TYPE_TREE_ROW_REFERENCE, (GBoxedCopyFunc) gtk_tree_row_reference_copy, gtk_tree_row_reference_free, NULL);
#line 455 "rygel-media-export-pref-section.c"
	{
		GList* row_collection;
		GList* row_it;
#line 138 "rygel-media-export-pref-section.vala"
		row_collection = rows;
#line 461 "rygel-media-export-pref-section.c"
		for (row_it = row_collection; row_it != NULL; row_it = row_it->next) {
			GtkTreePath* row;
#line 138 "rygel-media-export-pref-section.vala"
			row = _gtk_tree_path_copy0 ((GtkTreePath*) row_it->data);
#line 466 "rygel-media-export-pref-section.c"
			{
				GtkTreeRowReference* _tmp0_;
#line 139 "rygel-media-export-pref-section.vala"
				gee_abstract_collection_add ((GeeAbstractCollection*) row_refs, _tmp0_ = gtk_tree_row_reference_new ((GtkTreeModel*) self->priv->liststore, row));
#line 471 "rygel-media-export-pref-section.c"
				_gtk_tree_row_reference_free0 (_tmp0_);
				_gtk_tree_path_free0 (row);
			}
		}
	}
	{
		GeeIterator* _row_ref_it;
#line 143 "rygel-media-export-pref-section.vala"
		_row_ref_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) row_refs);
#line 143 "rygel-media-export-pref-section.vala"
		while (TRUE) {
#line 483 "rygel-media-export-pref-section.c"
			GtkTreeRowReference* row_ref;
			GtkTreeIter iter = {0};
			GtkTreePath* path;
#line 143 "rygel-media-export-pref-section.vala"
			if (!gee_iterator_next (_row_ref_it)) {
#line 143 "rygel-media-export-pref-section.vala"
				break;
#line 491 "rygel-media-export-pref-section.c"
			}
#line 143 "rygel-media-export-pref-section.vala"
			row_ref = (GtkTreeRowReference*) gee_iterator_get (_row_ref_it);
#line 146 "rygel-media-export-pref-section.vala"
			path = gtk_tree_row_reference_get_path (row_ref);
#line 147 "rygel-media-export-pref-section.vala"
			gtk_tree_model_get_iter ((GtkTreeModel*) self->priv->liststore, &iter, path);
#line 149 "rygel-media-export-pref-section.vala"
			gtk_list_store_remove (self->priv->liststore, &iter);
#line 501 "rygel-media-export-pref-section.c"
			_gtk_tree_path_free0 (path);
			_gtk_tree_row_reference_free0 (row_ref);
		}
		_g_object_unref0 (_row_ref_it);
	}
	_g_object_unref0 (row_refs);
	__g_list_free_gtk_tree_path_free0 (rows);
	_g_object_unref0 (selection);
}


#line 153 "rygel-media-export-pref-section.vala"
static void rygel_media_export_pref_section_on_clear_button_clicked (RygelMediaExportPrefSection* self, GtkButton* button) {
#line 153 "rygel-media-export-pref-section.vala"
	g_return_if_fail (self != NULL);
#line 153 "rygel-media-export-pref-section.vala"
	g_return_if_fail (button != NULL);
#line 154 "rygel-media-export-pref-section.vala"
	gtk_list_store_clear (self->priv->liststore);
#line 521 "rygel-media-export-pref-section.c"
}


static void rygel_media_export_pref_section_class_init (RygelMediaExportPrefSectionClass * klass) {
	rygel_media_export_pref_section_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelMediaExportPrefSectionPrivate));
	RYGEL_PREFERENCES_SECTION_CLASS (klass)->save = rygel_media_export_pref_section_real_save;
	G_OBJECT_CLASS (klass)->finalize = rygel_media_export_pref_section_finalize;
}


static void rygel_media_export_pref_section_instance_init (RygelMediaExportPrefSection * self) {
	self->priv = RYGEL_MEDIA_EXPORT_PREF_SECTION_GET_PRIVATE (self);
}


static void rygel_media_export_pref_section_finalize (GObject* obj) {
	RygelMediaExportPrefSection * self;
	self = RYGEL_MEDIA_EXPORT_PREF_SECTION (obj);
	_g_object_unref0 (self->priv->treeview);
	_g_object_unref0 (self->priv->liststore);
	_g_object_unref0 (self->priv->dialog);
	G_OBJECT_CLASS (rygel_media_export_pref_section_parent_class)->finalize (obj);
}


GType rygel_media_export_pref_section_get_type (void) {
	static volatile gsize rygel_media_export_pref_section_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_media_export_pref_section_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediaExportPrefSectionClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_media_export_pref_section_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediaExportPrefSection), 0, (GInstanceInitFunc) rygel_media_export_pref_section_instance_init, NULL };
		GType rygel_media_export_pref_section_type_id;
		rygel_media_export_pref_section_type_id = g_type_register_static (RYGEL_TYPE_PLUGIN_PREF_SECTION, "RygelMediaExportPrefSection", &g_define_type_info, 0);
		g_once_init_leave (&rygel_media_export_pref_section_type_id__volatile, rygel_media_export_pref_section_type_id);
	}
	return rygel_media_export_pref_section_type_id__volatile;
}




