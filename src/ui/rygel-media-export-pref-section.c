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
#include <gee.h>
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
};

struct _RygelPluginPrefSectionClass {
	RygelPreferencesSectionClass parent_class;
	void (*on_enabled_check_toggled) (RygelPluginPrefSection* self, GtkCheckButton* enabled_check);
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

GType rygel_preferences_section_get_type (void);
GType rygel_plugin_pref_section_get_type (void);
GType rygel_media_export_pref_section_get_type (void);
#define RYGEL_MEDIA_EXPORT_PREF_SECTION_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_MEDIA_EXPORT_PREF_SECTION, RygelMediaExportPrefSectionPrivate))
enum  {
	RYGEL_MEDIA_EXPORT_PREF_SECTION_DUMMY_PROPERTY
};
#define RYGEL_MEDIA_EXPORT_PREF_SECTION_NAME "MediaExport"
#define RYGEL_MEDIA_EXPORT_PREF_SECTION_URIS_KEY "uris"
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
RygelMediaExportPrefSection* rygel_media_export_pref_section_new (GtkBuilder* builder, RygelUserConfig* config);
RygelMediaExportPrefSection* rygel_media_export_pref_section_construct (GType object_type, GtkBuilder* builder, RygelUserConfig* config);
void rygel_preferences_section_save (RygelPreferencesSection* self);
static void rygel_media_export_pref_section_real_save (RygelPreferencesSection* base);
void rygel_plugin_pref_section_on_enabled_check_toggled (RygelPluginPrefSection* self, GtkCheckButton* enabled_check);
static void rygel_media_export_pref_section_real_on_enabled_check_toggled (RygelPluginPrefSection* base, GtkCheckButton* enabled_check);
static void _g_slist_free_g_object_unref (GSList* self);
static void _g_list_free_gtk_tree_path_free (GList* self);
static void rygel_media_export_pref_section_finalize (GObject* obj);



static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _rygel_media_export_pref_section_on_add_button_clicked_gtk_button_clicked (GtkButton* _sender, gpointer self) {
	rygel_media_export_pref_section_on_add_button_clicked (self, _sender);
}


static void _rygel_media_export_pref_section_on_remove_button_clicked_gtk_button_clicked (GtkButton* _sender, gpointer self) {
	rygel_media_export_pref_section_on_remove_button_clicked (self, _sender);
}


static void _rygel_media_export_pref_section_on_clear_button_clicked_gtk_button_clicked (GtkButton* _sender, gpointer self) {
	rygel_media_export_pref_section_on_clear_button_clicked (self, _sender);
}


RygelMediaExportPrefSection* rygel_media_export_pref_section_construct (GType object_type, GtkBuilder* builder, RygelUserConfig* config) {
	GError * _inner_error_;
	RygelMediaExportPrefSection * self;
	GtkTreeView* _tmp0_;
	GtkListStore* _tmp1_;
	GtkFileChooserDialog* _tmp2_;
	GtkCellRendererText* _tmp3_;
	GtkButton* button;
	GtkButton* _tmp4_;
	GtkButton* _tmp5_;
	g_return_val_if_fail (builder != NULL, NULL);
	g_return_val_if_fail (config != NULL, NULL);
	_inner_error_ = NULL;
	self = (RygelMediaExportPrefSection*) rygel_plugin_pref_section_construct (object_type, builder, config, RYGEL_MEDIA_EXPORT_PREF_SECTION_NAME);
	self->priv->treeview = (_tmp0_ = _g_object_ref0 (GTK_TREE_VIEW (gtk_builder_get_object (builder, RYGEL_MEDIA_EXPORT_PREF_SECTION_URIS_TEXTVIEW))), _g_object_unref0 (self->priv->treeview), _tmp0_);
	g_assert (self->priv->treeview != NULL);
	self->priv->liststore = (_tmp1_ = _g_object_ref0 (GTK_LIST_STORE (gtk_builder_get_object (builder, RYGEL_MEDIA_EXPORT_PREF_SECTION_URIS_LISTSTORE))), _g_object_unref0 (self->priv->liststore), _tmp1_);
	g_assert (self->priv->liststore != NULL);
	self->priv->dialog = (_tmp2_ = _g_object_ref0 (GTK_FILE_CHOOSER_DIALOG (gtk_builder_get_object (builder, RYGEL_MEDIA_EXPORT_PREF_SECTION_URIS_DIALOG))), _g_object_unref0 (self->priv->dialog), _tmp2_);
	g_assert (self->priv->dialog != NULL);
	gtk_tree_view_insert_column_with_attributes (self->priv->treeview, -1, "paths", (GtkCellRenderer*) (_tmp3_ = g_object_ref_sink ((GtkCellRendererText*) gtk_cell_renderer_text_new ())), "text", 0, NULL, NULL);
	_g_object_unref0 (_tmp3_);
	{
		GeeArrayList* uris;
		uris = rygel_configuration_get_string_list ((RygelConfiguration*) config, ((RygelPreferencesSection*) self)->name, RYGEL_MEDIA_EXPORT_PREF_SECTION_URIS_KEY, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch10_g_error;
			goto __finally10;
		}
		{
			GeeIterator* _uri_it;
			_uri_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) uris);
			while (TRUE) {
				char* uri;
				GtkTreeIter iter = {0};
				if (!gee_iterator_next (_uri_it)) {
					break;
				}
				uri = (char*) gee_iterator_get (_uri_it);
				gtk_list_store_append (self->priv->liststore, &iter);
				gtk_list_store_set (self->priv->liststore, &iter, 0, uri, -1, -1);
				_g_free0 (uri);
			}
			_g_object_unref0 (_uri_it);
		}
		_g_object_unref0 (uris);
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
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	gtk_file_chooser_set_current_folder ((GtkFileChooser*) self->priv->dialog, g_get_home_dir ());
	gtk_file_chooser_set_show_hidden ((GtkFileChooser*) self->priv->dialog, FALSE);
	button = _g_object_ref0 (GTK_BUTTON (gtk_builder_get_object (builder, RYGEL_MEDIA_EXPORT_PREF_SECTION_ADD_BUTTON)));
	g_signal_connect_object (button, "clicked", (GCallback) _rygel_media_export_pref_section_on_add_button_clicked_gtk_button_clicked, self, 0);
	button = (_tmp4_ = _g_object_ref0 (GTK_BUTTON (gtk_builder_get_object (builder, RYGEL_MEDIA_EXPORT_PREF_SECTION_REMOVE_BUTTON))), _g_object_unref0 (button), _tmp4_);
	g_signal_connect_object (button, "clicked", (GCallback) _rygel_media_export_pref_section_on_remove_button_clicked_gtk_button_clicked, self, 0);
	button = (_tmp5_ = _g_object_ref0 (GTK_BUTTON (gtk_builder_get_object (builder, RYGEL_MEDIA_EXPORT_PREF_SECTION_CLEAR_BUTTON))), _g_object_unref0 (button), _tmp5_);
	g_signal_connect_object (button, "clicked", (GCallback) _rygel_media_export_pref_section_on_clear_button_clicked_gtk_button_clicked, self, 0);
	_g_object_unref0 (button);
	return self;
}


RygelMediaExportPrefSection* rygel_media_export_pref_section_new (GtkBuilder* builder, RygelUserConfig* config) {
	return rygel_media_export_pref_section_construct (RYGEL_TYPE_MEDIA_EXPORT_PREF_SECTION, builder, config);
}


static void rygel_media_export_pref_section_real_save (RygelPreferencesSection* base) {
	RygelMediaExportPrefSection * self;
	GtkTreeIter iter = {0};
	GeeArrayList* uri_list;
	self = (RygelMediaExportPrefSection*) base;
	RYGEL_PREFERENCES_SECTION_CLASS (rygel_media_export_pref_section_parent_class)->save ((RygelPreferencesSection*) RYGEL_PLUGIN_PREF_SECTION (self));
	uri_list = gee_array_list_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, g_direct_equal);
	if (gtk_tree_model_get_iter_first ((GtkTreeModel*) self->priv->liststore, &iter)) {
		{
			gboolean _tmp0_;
			_tmp0_ = TRUE;
			while (TRUE) {
				char* uri;
				if (!_tmp0_) {
					if (!gtk_tree_model_iter_next ((GtkTreeModel*) self->priv->liststore, &iter)) {
						break;
					}
				}
				_tmp0_ = FALSE;
				uri = NULL;
				gtk_tree_model_get ((GtkTreeModel*) self->priv->liststore, &iter, 0, &uri, -1, -1);
				gee_abstract_collection_add ((GeeAbstractCollection*) uri_list, uri);
				_g_free0 (uri);
			}
		}
	}
	rygel_user_config_set_string_list (((RygelPreferencesSection*) self)->config, ((RygelPreferencesSection*) self)->name, RYGEL_MEDIA_EXPORT_PREF_SECTION_URIS_KEY, uri_list);
	_g_object_unref0 (uri_list);
}


static void rygel_media_export_pref_section_real_on_enabled_check_toggled (RygelPluginPrefSection* base, GtkCheckButton* enabled_check) {
	RygelMediaExportPrefSection * self;
	self = (RygelMediaExportPrefSection*) base;
	g_return_if_fail (enabled_check != NULL);
	RYGEL_PLUGIN_PREF_SECTION_CLASS (rygel_media_export_pref_section_parent_class)->on_enabled_check_toggled (RYGEL_PLUGIN_PREF_SECTION (self), enabled_check);
	g_object_set ((GtkWidget*) self->priv->treeview, "sensitive", gtk_toggle_button_get_active ((GtkToggleButton*) enabled_check), NULL);
}


static void _g_slist_free_g_object_unref (GSList* self) {
	g_slist_foreach (self, (GFunc) g_object_unref, NULL);
	g_slist_free (self);
}


static void rygel_media_export_pref_section_on_add_button_clicked (RygelMediaExportPrefSection* self, GtkButton* button) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (button != NULL);
	if (gtk_dialog_run ((GtkDialog*) self->priv->dialog) == GTK_RESPONSE_OK) {
		GtkTreeIter iter = {0};
		GSList* dirs;
		dirs = gtk_file_chooser_get_files ((GtkFileChooser*) self->priv->dialog);
		{
			GSList* dir_collection;
			GSList* dir_it;
			dir_collection = dirs;
			for (dir_it = dir_collection; dir_it != NULL; dir_it = dir_it->next) {
				GFile* dir;
				dir = _g_object_ref0 ((GFile*) dir_it->data);
				{
					char* path;
					path = g_file_get_path (dir);
					if (path == NULL) {
						char* _tmp0_;
						path = (_tmp0_ = g_file_get_uri (dir), _g_free0 (path), _tmp0_);
					}
					gtk_list_store_append (self->priv->liststore, &iter);
					gtk_list_store_set (self->priv->liststore, &iter, 0, path, -1, -1);
					_g_object_unref0 (dir);
					_g_free0 (path);
				}
			}
		}
		__g_slist_free_g_object_unref0 (dirs);
	}
	gtk_widget_hide ((GtkWidget*) self->priv->dialog);
}


static gpointer _gtk_tree_path_copy0 (gpointer self) {
	return self ? gtk_tree_path_copy (self) : NULL;
}


static void _g_list_free_gtk_tree_path_free (GList* self) {
	g_list_foreach (self, (GFunc) gtk_tree_path_free, NULL);
	g_list_free (self);
}


static void rygel_media_export_pref_section_on_remove_button_clicked (RygelMediaExportPrefSection* self, GtkButton* button) {
	GtkTreeSelection* selection;
	GList* rows;
	GeeArrayList* row_refs;
	g_return_if_fail (self != NULL);
	g_return_if_fail (button != NULL);
	selection = _g_object_ref0 (gtk_tree_view_get_selection (self->priv->treeview));
	rows = gtk_tree_selection_get_selected_rows (selection, NULL);
	row_refs = gee_array_list_new (GTK_TYPE_TREE_ROW_REFERENCE, (GBoxedCopyFunc) gtk_tree_row_reference_copy, gtk_tree_row_reference_free, g_direct_equal);
	{
		GList* row_collection;
		GList* row_it;
		row_collection = rows;
		for (row_it = row_collection; row_it != NULL; row_it = row_it->next) {
			GtkTreePath* row;
			row = _gtk_tree_path_copy0 ((const GtkTreePath*) row_it->data);
			{
				GtkTreeRowReference* _tmp0_;
				gee_abstract_collection_add ((GeeAbstractCollection*) row_refs, _tmp0_ = gtk_tree_row_reference_new ((GtkTreeModel*) self->priv->liststore, row));
				_gtk_tree_row_reference_free0 (_tmp0_);
				_gtk_tree_path_free0 (row);
			}
		}
	}
	{
		GeeIterator* _row_ref_it;
		_row_ref_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) row_refs);
		while (TRUE) {
			GtkTreeRowReference* row_ref;
			GtkTreeIter iter = {0};
			GtkTreePath* path;
			if (!gee_iterator_next (_row_ref_it)) {
				break;
			}
			row_ref = (GtkTreeRowReference*) gee_iterator_get (_row_ref_it);
			path = gtk_tree_row_reference_get_path (row_ref);
			gtk_tree_model_get_iter ((GtkTreeModel*) self->priv->liststore, &iter, path);
			gtk_list_store_remove (self->priv->liststore, &iter);
			_gtk_tree_row_reference_free0 (row_ref);
			_gtk_tree_path_free0 (path);
		}
		_g_object_unref0 (_row_ref_it);
	}
	_g_object_unref0 (selection);
	__g_list_free_gtk_tree_path_free0 (rows);
	_g_object_unref0 (row_refs);
}


static void rygel_media_export_pref_section_on_clear_button_clicked (RygelMediaExportPrefSection* self, GtkButton* button) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (button != NULL);
	gtk_list_store_clear (self->priv->liststore);
}


static void rygel_media_export_pref_section_class_init (RygelMediaExportPrefSectionClass * klass) {
	rygel_media_export_pref_section_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelMediaExportPrefSectionPrivate));
	RYGEL_PREFERENCES_SECTION_CLASS (klass)->save = rygel_media_export_pref_section_real_save;
	RYGEL_PLUGIN_PREF_SECTION_CLASS (klass)->on_enabled_check_toggled = rygel_media_export_pref_section_real_on_enabled_check_toggled;
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
	static GType rygel_media_export_pref_section_type_id = 0;
	if (rygel_media_export_pref_section_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediaExportPrefSectionClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_media_export_pref_section_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediaExportPrefSection), 0, (GInstanceInitFunc) rygel_media_export_pref_section_instance_init, NULL };
		rygel_media_export_pref_section_type_id = g_type_register_static (RYGEL_TYPE_PLUGIN_PREF_SECTION, "RygelMediaExportPrefSection", &g_define_type_info, 0);
	}
	return rygel_media_export_pref_section_type_id;
}




