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
#include <libgupnp/gupnp.h>
#include <float.h>
#include <math.h>
#include <libgssdp/gssdp.h>


#define RYGEL_TYPE_PREFERENCES_SECTION (rygel_preferences_section_get_type ())
#define RYGEL_PREFERENCES_SECTION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_PREFERENCES_SECTION, RygelPreferencesSection))
#define RYGEL_PREFERENCES_SECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_PREFERENCES_SECTION, RygelPreferencesSectionClass))
#define RYGEL_IS_PREFERENCES_SECTION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_PREFERENCES_SECTION))
#define RYGEL_IS_PREFERENCES_SECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_PREFERENCES_SECTION))
#define RYGEL_PREFERENCES_SECTION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_PREFERENCES_SECTION, RygelPreferencesSectionClass))

typedef struct _RygelPreferencesSection RygelPreferencesSection;
typedef struct _RygelPreferencesSectionClass RygelPreferencesSectionClass;
typedef struct _RygelPreferencesSectionPrivate RygelPreferencesSectionPrivate;

#define RYGEL_TYPE_GENERAL_PREF_SECTION (rygel_general_pref_section_get_type ())
#define RYGEL_GENERAL_PREF_SECTION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_GENERAL_PREF_SECTION, RygelGeneralPrefSection))
#define RYGEL_GENERAL_PREF_SECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_GENERAL_PREF_SECTION, RygelGeneralPrefSectionClass))
#define RYGEL_IS_GENERAL_PREF_SECTION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_GENERAL_PREF_SECTION))
#define RYGEL_IS_GENERAL_PREF_SECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_GENERAL_PREF_SECTION))
#define RYGEL_GENERAL_PREF_SECTION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_GENERAL_PREF_SECTION, RygelGeneralPrefSectionClass))

typedef struct _RygelGeneralPrefSection RygelGeneralPrefSection;
typedef struct _RygelGeneralPrefSectionClass RygelGeneralPrefSectionClass;
typedef struct _RygelGeneralPrefSectionPrivate RygelGeneralPrefSectionPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
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

struct _RygelGeneralPrefSection {
	RygelPreferencesSection parent_instance;
	RygelGeneralPrefSectionPrivate * priv;
};

struct _RygelGeneralPrefSectionClass {
	RygelPreferencesSectionClass parent_class;
};

struct _RygelGeneralPrefSectionPrivate {
	GtkComboBoxEntry* iface_entry;
	GtkSpinButton* port_spin;
	GtkCheckButton* upnp_check;
	GtkCheckButton* trans_check;
	GtkCheckButton* mp3_check;
	GtkCheckButton* mp2ts_check;
	GtkCheckButton* lpcm_check;
	GUPnPContextManager* context_manager;
};


static gpointer rygel_general_pref_section_parent_class = NULL;

GType rygel_preferences_section_get_type (void);
GType rygel_general_pref_section_get_type (void);
#define RYGEL_GENERAL_PREF_SECTION_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_GENERAL_PREF_SECTION, RygelGeneralPrefSectionPrivate))
enum  {
	RYGEL_GENERAL_PREF_SECTION_DUMMY_PROPERTY
};
#define RYGEL_GENERAL_PREF_SECTION_UPNP_CHECKBUTTON "upnp-checkbutton"
#define RYGEL_GENERAL_PREF_SECTION_IFACE_ENTRY "iface-entry"
#define RYGEL_GENERAL_PREF_SECTION_PORT_SPINBUTTON "port-spinbutton"
#define RYGEL_GENERAL_PREF_SECTION_TRANS_CHECKBUTTON "transcoding-checkbutton"
#define RYGEL_GENERAL_PREF_SECTION_MP3_CHECKBUTTON "mp3-checkbutton"
#define RYGEL_GENERAL_PREF_SECTION_MP2TS_CHECKBUTTON "mp2ts-checkbutton"
#define RYGEL_GENERAL_PREF_SECTION_LPCM_CHECKBUTTON "lpcm-checkbutton"
RygelPreferencesSection* rygel_preferences_section_construct (GType object_type, RygelUserConfig* config, const char* name);
static void rygel_general_pref_section_on_trans_check_toggled (RygelGeneralPrefSection* self, GtkCheckButton* trans_check);
static void _rygel_general_pref_section_on_trans_check_toggled_gtk_toggle_button_toggled (GtkCheckButton* _sender, gpointer self);
static void rygel_general_pref_section_on_context_available (RygelGeneralPrefSection* self, GUPnPContextManager* manager, GUPnPContext* context);
static void _rygel_general_pref_section_on_context_available_gupnp_context_manager_context_available (GUPnPContextManager* _sender, GUPnPContext* p0, gpointer self);
static void rygel_general_pref_section_on_context_unavailable (RygelGeneralPrefSection* self, GUPnPContextManager* manager, GUPnPContext* context);
static void _rygel_general_pref_section_on_context_unavailable_gupnp_context_manager_context_unavailable (GUPnPContextManager* _sender, GUPnPContext* p0, gpointer self);
RygelGeneralPrefSection* rygel_general_pref_section_new (GtkBuilder* builder, RygelUserConfig* config, GError** error);
RygelGeneralPrefSection* rygel_general_pref_section_construct (GType object_type, GtkBuilder* builder, RygelUserConfig* config, GError** error);
static void rygel_general_pref_section_real_save (RygelPreferencesSection* base);
static gboolean rygel_general_pref_section_find_interface (RygelGeneralPrefSection* self, const char* iface, GtkTreeIter* iter);
static void rygel_general_pref_section_finalize (GObject* obj);
static int _vala_strcmp0 (const char * str1, const char * str2);



static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _rygel_general_pref_section_on_trans_check_toggled_gtk_toggle_button_toggled (GtkCheckButton* _sender, gpointer self) {
	rygel_general_pref_section_on_trans_check_toggled (self, _sender);
}


static void _rygel_general_pref_section_on_context_available_gupnp_context_manager_context_available (GUPnPContextManager* _sender, GUPnPContext* p0, gpointer self) {
	rygel_general_pref_section_on_context_available (self, _sender, p0);
}


static void _rygel_general_pref_section_on_context_unavailable_gupnp_context_manager_context_unavailable (GUPnPContextManager* _sender, GUPnPContext* p0, gpointer self) {
	rygel_general_pref_section_on_context_unavailable (self, _sender, p0);
}


RygelGeneralPrefSection* rygel_general_pref_section_construct (GType object_type, GtkBuilder* builder, RygelUserConfig* config, GError** error) {
	GError * _inner_error_;
	RygelGeneralPrefSection * self;
	GtkCheckButton* _tmp0_;
	GtkComboBoxEntry* _tmp1_;
	GtkSpinButton* _tmp2_;
	GtkCheckButton* _tmp3_;
	GtkCheckButton* _tmp4_;
	GtkCheckButton* _tmp5_;
	GtkCheckButton* _tmp6_;
	GUPnPContextManager* _tmp7_;
	g_return_val_if_fail (builder != NULL, NULL);
	g_return_val_if_fail (config != NULL, NULL);
	_inner_error_ = NULL;
	self = (RygelGeneralPrefSection*) rygel_preferences_section_construct (object_type, config, "general");
	self->priv->upnp_check = (_tmp0_ = _g_object_ref0 (GTK_CHECK_BUTTON (gtk_builder_get_object (builder, RYGEL_GENERAL_PREF_SECTION_UPNP_CHECKBUTTON))), _g_object_unref0 (self->priv->upnp_check), _tmp0_);
	g_assert (self->priv->upnp_check != NULL);
	self->priv->iface_entry = (_tmp1_ = _g_object_ref0 (GTK_COMBO_BOX_ENTRY (gtk_builder_get_object (builder, RYGEL_GENERAL_PREF_SECTION_IFACE_ENTRY))), _g_object_unref0 (self->priv->iface_entry), _tmp1_);
	g_assert (self->priv->iface_entry != NULL);
	self->priv->port_spin = (_tmp2_ = _g_object_ref0 (GTK_SPIN_BUTTON (gtk_builder_get_object (builder, RYGEL_GENERAL_PREF_SECTION_PORT_SPINBUTTON))), _g_object_unref0 (self->priv->port_spin), _tmp2_);
	g_assert (self->priv->port_spin != NULL);
	self->priv->trans_check = (_tmp3_ = _g_object_ref0 (GTK_CHECK_BUTTON (gtk_builder_get_object (builder, RYGEL_GENERAL_PREF_SECTION_TRANS_CHECKBUTTON))), _g_object_unref0 (self->priv->trans_check), _tmp3_);
	g_assert (self->priv->trans_check != NULL);
	self->priv->mp3_check = (_tmp4_ = _g_object_ref0 (GTK_CHECK_BUTTON (gtk_builder_get_object (builder, RYGEL_GENERAL_PREF_SECTION_MP3_CHECKBUTTON))), _g_object_unref0 (self->priv->mp3_check), _tmp4_);
	g_assert (self->priv->mp3_check != NULL);
	self->priv->mp2ts_check = (_tmp5_ = _g_object_ref0 (GTK_CHECK_BUTTON (gtk_builder_get_object (builder, RYGEL_GENERAL_PREF_SECTION_MP2TS_CHECKBUTTON))), _g_object_unref0 (self->priv->mp2ts_check), _tmp5_);
	g_assert (self->priv->mp2ts_check != NULL);
	self->priv->lpcm_check = (_tmp6_ = _g_object_ref0 (GTK_CHECK_BUTTON (gtk_builder_get_object (builder, RYGEL_GENERAL_PREF_SECTION_LPCM_CHECKBUTTON))), _g_object_unref0 (self->priv->lpcm_check), _tmp6_);
	g_assert (self->priv->lpcm_check != NULL);
	self->priv->context_manager = (_tmp7_ = gupnp_context_manager_new (NULL, (guint) 0), _g_object_unref0 (self->priv->context_manager), _tmp7_);
	gtk_combo_box_entry_set_text_column (self->priv->iface_entry, 0);
	{
		char* _tmp8_;
		char* _tmp9_;
		_tmp8_ = rygel_configuration_get_interface ((RygelConfiguration*) config, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch1_g_error;
			goto __finally1;
		}
		gtk_combo_box_append_text ((GtkComboBox*) self->priv->iface_entry, _tmp9_ = _tmp8_);
		_g_free0 (_tmp9_);
		gtk_combo_box_set_active ((GtkComboBox*) self->priv->iface_entry, 0);
	}
	goto __finally1;
	__catch1_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			_g_error_free0 (err);
		}
	}
	__finally1:
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return;
	}
	{
		gint _tmp10_;
		_tmp10_ = rygel_configuration_get_port ((RygelConfiguration*) config, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch2_g_error;
			goto __finally2;
		}
		gtk_spin_button_set_value (self->priv->port_spin, (double) _tmp10_);
	}
	goto __finally2;
	__catch2_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			_g_error_free0 (err);
		}
	}
	__finally2:
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return;
	}
	{
		gboolean _tmp11_;
		_tmp11_ = rygel_configuration_get_upnp_enabled ((RygelConfiguration*) ((RygelPreferencesSection*) self)->config, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch3_g_error;
			goto __finally3;
		}
		gtk_toggle_button_set_active ((GtkToggleButton*) self->priv->upnp_check, _tmp11_);
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
		return;
	}
	{
		gboolean _tmp12_;
		_tmp12_ = rygel_configuration_get_transcoding ((RygelConfiguration*) ((RygelPreferencesSection*) self)->config, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch4_g_error;
			goto __finally4;
		}
		gtk_toggle_button_set_active ((GtkToggleButton*) self->priv->trans_check, _tmp12_);
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
		return;
	}
	{
		gboolean _tmp13_;
		_tmp13_ = rygel_configuration_get_mp3_transcoder ((RygelConfiguration*) ((RygelPreferencesSection*) self)->config, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch5_g_error;
			goto __finally5;
		}
		gtk_toggle_button_set_active ((GtkToggleButton*) self->priv->mp3_check, _tmp13_);
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
		return;
	}
	{
		gboolean _tmp14_;
		_tmp14_ = rygel_configuration_get_mp2ts_transcoder ((RygelConfiguration*) ((RygelPreferencesSection*) self)->config, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch6_g_error;
			goto __finally6;
		}
		gtk_toggle_button_set_active ((GtkToggleButton*) self->priv->mp2ts_check, _tmp14_);
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
		return;
	}
	{
		gboolean _tmp15_;
		_tmp15_ = rygel_configuration_get_lpcm_transcoder ((RygelConfiguration*) ((RygelPreferencesSection*) self)->config, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch7_g_error;
			goto __finally7;
		}
		gtk_toggle_button_set_active ((GtkToggleButton*) self->priv->lpcm_check, _tmp15_);
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
		return;
	}
	g_signal_connect_object ((GtkToggleButton*) self->priv->trans_check, "toggled", (GCallback) _rygel_general_pref_section_on_trans_check_toggled_gtk_toggle_button_toggled, self, 0);
	g_signal_connect_object (self->priv->context_manager, "context-available", (GCallback) _rygel_general_pref_section_on_context_available_gupnp_context_manager_context_available, self, 0);
	g_signal_connect_object (self->priv->context_manager, "context-unavailable", (GCallback) _rygel_general_pref_section_on_context_unavailable_gupnp_context_manager_context_unavailable, self, 0);
	return self;
}


RygelGeneralPrefSection* rygel_general_pref_section_new (GtkBuilder* builder, RygelUserConfig* config, GError** error) {
	return rygel_general_pref_section_construct (RYGEL_TYPE_GENERAL_PREF_SECTION, builder, config, error);
}


static void rygel_general_pref_section_real_save (RygelPreferencesSection* base) {
	RygelGeneralPrefSection * self;
	self = (RygelGeneralPrefSection*) base;
	rygel_user_config_set_interface (((RygelPreferencesSection*) self)->config, gtk_combo_box_get_active_text ((GtkComboBox*) self->priv->iface_entry));
	rygel_user_config_set_port (((RygelPreferencesSection*) self)->config, (gint) gtk_spin_button_get_value (self->priv->port_spin));
	rygel_user_config_set_upnp_enabled (((RygelPreferencesSection*) self)->config, gtk_toggle_button_get_active ((GtkToggleButton*) self->priv->upnp_check));
	rygel_user_config_set_transcoding (((RygelPreferencesSection*) self)->config, gtk_toggle_button_get_active ((GtkToggleButton*) self->priv->trans_check));
	rygel_user_config_set_mp3_transcoder (((RygelPreferencesSection*) self)->config, gtk_toggle_button_get_active ((GtkToggleButton*) self->priv->mp3_check));
	rygel_user_config_set_mp2ts_transcoder (((RygelPreferencesSection*) self)->config, gtk_toggle_button_get_active ((GtkToggleButton*) self->priv->mp2ts_check));
	rygel_user_config_set_lpcm_transcoder (((RygelPreferencesSection*) self)->config, gtk_toggle_button_get_active ((GtkToggleButton*) self->priv->lpcm_check));
}


static void rygel_general_pref_section_on_trans_check_toggled (RygelGeneralPrefSection* self, GtkCheckButton* trans_check) {
	gboolean _tmp0_;
	gboolean _tmp1_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (trans_check != NULL);
	g_object_set ((GtkWidget*) self->priv->mp3_check, "sensitive", (g_object_set ((GtkWidget*) self->priv->mp2ts_check, "sensitive", (g_object_set ((GtkWidget*) self->priv->lpcm_check, "sensitive", gtk_toggle_button_get_active ((GtkToggleButton*) trans_check), NULL), (g_object_get ((GtkWidget*) self->priv->lpcm_check, "sensitive", &_tmp0_, NULL), _tmp0_)), NULL), (g_object_get ((GtkWidget*) self->priv->mp2ts_check, "sensitive", &_tmp1_, NULL), _tmp1_)), NULL);
}


static void rygel_general_pref_section_on_context_available (RygelGeneralPrefSection* self, GUPnPContextManager* manager, GUPnPContext* context) {
	GtkTreeIter iter = {0};
	g_return_if_fail (self != NULL);
	g_return_if_fail (manager != NULL);
	g_return_if_fail (context != NULL);
	if (!rygel_general_pref_section_find_interface (self, gssdp_client_get_interface ((GSSDPClient*) context), &iter)) {
		gtk_combo_box_append_text ((GtkComboBox*) self->priv->iface_entry, gssdp_client_get_interface ((GSSDPClient*) context));
	}
}


static void rygel_general_pref_section_on_context_unavailable (RygelGeneralPrefSection* self, GUPnPContextManager* manager, GUPnPContext* context) {
	GtkTreeIter iter = {0};
	g_return_if_fail (self != NULL);
	g_return_if_fail (manager != NULL);
	g_return_if_fail (context != NULL);
	if (rygel_general_pref_section_find_interface (self, gssdp_client_get_interface ((GSSDPClient*) context), &iter)) {
		GtkTreeModel* _tmp0_;
		GtkListStore* list_store;
		list_store = _g_object_ref0 ((_tmp0_ = gtk_combo_box_get_model ((GtkComboBox*) self->priv->iface_entry), GTK_IS_LIST_STORE (_tmp0_) ? ((GtkListStore*) _tmp0_) : NULL));
		gtk_list_store_remove (list_store, &iter);
		_g_object_unref0 (list_store);
	}
}


static gboolean rygel_general_pref_section_find_interface (RygelGeneralPrefSection* self, const char* iface, GtkTreeIter* iter) {
	gboolean result;
	GtkTreeModel* model;
	gboolean more;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (iface != NULL, FALSE);
	model = _g_object_ref0 (gtk_combo_box_get_model ((GtkComboBox*) self->priv->iface_entry));
	more = gtk_tree_model_get_iter_first (model, &(*iter));
	while (TRUE) {
		if (!more) {
			break;
		}
		gtk_tree_model_get (model, &(*iter), 0, &((RygelPreferencesSection*) self)->name, -1, -1);
		if (_vala_strcmp0 (((RygelPreferencesSection*) self)->name, iface) == 0) {
			break;
		}
		more = gtk_tree_model_iter_next (model, &(*iter));
	}
	result = more;
	_g_object_unref0 (model);
	return result;
}


static void rygel_general_pref_section_class_init (RygelGeneralPrefSectionClass * klass) {
	rygel_general_pref_section_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelGeneralPrefSectionPrivate));
	RYGEL_PREFERENCES_SECTION_CLASS (klass)->save = rygel_general_pref_section_real_save;
	G_OBJECT_CLASS (klass)->finalize = rygel_general_pref_section_finalize;
}


static void rygel_general_pref_section_instance_init (RygelGeneralPrefSection * self) {
	self->priv = RYGEL_GENERAL_PREF_SECTION_GET_PRIVATE (self);
}


static void rygel_general_pref_section_finalize (GObject* obj) {
	RygelGeneralPrefSection * self;
	self = RYGEL_GENERAL_PREF_SECTION (obj);
	_g_object_unref0 (self->priv->iface_entry);
	_g_object_unref0 (self->priv->port_spin);
	_g_object_unref0 (self->priv->upnp_check);
	_g_object_unref0 (self->priv->trans_check);
	_g_object_unref0 (self->priv->mp3_check);
	_g_object_unref0 (self->priv->mp2ts_check);
	_g_object_unref0 (self->priv->lpcm_check);
	_g_object_unref0 (self->priv->context_manager);
	G_OBJECT_CLASS (rygel_general_pref_section_parent_class)->finalize (obj);
}


GType rygel_general_pref_section_get_type (void) {
	static GType rygel_general_pref_section_type_id = 0;
	if (rygel_general_pref_section_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelGeneralPrefSectionClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_general_pref_section_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelGeneralPrefSection), 0, (GInstanceInitFunc) rygel_general_pref_section_instance_init, NULL };
		rygel_general_pref_section_type_id = g_type_register_static (RYGEL_TYPE_PREFERENCES_SECTION, "RygelGeneralPrefSection", &g_define_type_info, 0);
	}
	return rygel_general_pref_section_type_id;
}


static int _vala_strcmp0 (const char * str1, const char * str2) {
	if (str1 == NULL) {
		return -(str1 != str2);
	}
	if (str2 == NULL) {
		return str1 != str2;
	}
	return strcmp (str1, str2);
}




