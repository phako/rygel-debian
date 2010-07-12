/* rygel-gst-renderer-rendering-control.c generated by valac, the Vala compiler
 * generated from rygel-gst-renderer-rendering-control.vala, do not modify */

/*
 * Copyright (C) 2008 OpenedHand Ltd.
 * Copyright (C) 2009 Nokia Corporation.
 *
 * Author: Jorn Baayen <jorn@openedhand.com>
 *         Zeeshan Ali (Khattak) <zeeshanak@gnome.org>
 *                               <zeeshan.ali@nokia.com>
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
#include <libgupnp/gupnp.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <glib/gi18n-lib.h>


#define RYGEL_GST_RENDERER_TYPE_RENDERING_CONTROL (rygel_gst_renderer_rendering_control_get_type ())
#define RYGEL_GST_RENDERER_RENDERING_CONTROL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_GST_RENDERER_TYPE_RENDERING_CONTROL, RygelGstRendererRenderingControl))
#define RYGEL_GST_RENDERER_RENDERING_CONTROL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_GST_RENDERER_TYPE_RENDERING_CONTROL, RygelGstRendererRenderingControlClass))
#define RYGEL_GST_RENDERER_IS_RENDERING_CONTROL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_GST_RENDERER_TYPE_RENDERING_CONTROL))
#define RYGEL_GST_RENDERER_IS_RENDERING_CONTROL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_GST_RENDERER_TYPE_RENDERING_CONTROL))
#define RYGEL_GST_RENDERER_RENDERING_CONTROL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_GST_RENDERER_TYPE_RENDERING_CONTROL, RygelGstRendererRenderingControlClass))

typedef struct _RygelGstRendererRenderingControl RygelGstRendererRenderingControl;
typedef struct _RygelGstRendererRenderingControlClass RygelGstRendererRenderingControlClass;
typedef struct _RygelGstRendererRenderingControlPrivate RygelGstRendererRenderingControlPrivate;

#define RYGEL_GST_RENDERER_TYPE_CHANGE_LOG (rygel_gst_renderer_change_log_get_type ())
#define RYGEL_GST_RENDERER_CHANGE_LOG(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_GST_RENDERER_TYPE_CHANGE_LOG, RygelGstRendererChangeLog))
#define RYGEL_GST_RENDERER_CHANGE_LOG_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_GST_RENDERER_TYPE_CHANGE_LOG, RygelGstRendererChangeLogClass))
#define RYGEL_GST_RENDERER_IS_CHANGE_LOG(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_GST_RENDERER_TYPE_CHANGE_LOG))
#define RYGEL_GST_RENDERER_IS_CHANGE_LOG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_GST_RENDERER_TYPE_CHANGE_LOG))
#define RYGEL_GST_RENDERER_CHANGE_LOG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_GST_RENDERER_TYPE_CHANGE_LOG, RygelGstRendererChangeLogClass))

typedef struct _RygelGstRendererChangeLog RygelGstRendererChangeLog;
typedef struct _RygelGstRendererChangeLogClass RygelGstRendererChangeLogClass;

#define RYGEL_GST_RENDERER_TYPE_PLAYER (rygel_gst_renderer_player_get_type ())
#define RYGEL_GST_RENDERER_PLAYER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_GST_RENDERER_TYPE_PLAYER, RygelGstRendererPlayer))
#define RYGEL_GST_RENDERER_PLAYER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_GST_RENDERER_TYPE_PLAYER, RygelGstRendererPlayerClass))
#define RYGEL_GST_RENDERER_IS_PLAYER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_GST_RENDERER_TYPE_PLAYER))
#define RYGEL_GST_RENDERER_IS_PLAYER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_GST_RENDERER_TYPE_PLAYER))
#define RYGEL_GST_RENDERER_PLAYER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_GST_RENDERER_TYPE_PLAYER, RygelGstRendererPlayerClass))

typedef struct _RygelGstRendererPlayer RygelGstRendererPlayer;
typedef struct _RygelGstRendererPlayerClass RygelGstRendererPlayerClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _RygelGstRendererRenderingControl {
	GUPnPService parent_instance;
	RygelGstRendererRenderingControlPrivate * priv;
};

struct _RygelGstRendererRenderingControlClass {
	GUPnPServiceClass parent_class;
};

struct _RygelGstRendererRenderingControlPrivate {
	gboolean _mute;
	guint _volume;
	char* preset_name_list;
	RygelGstRendererChangeLog* changelog;
	RygelGstRendererPlayer* player;
};


static gpointer rygel_gst_renderer_rendering_control_parent_class = NULL;

GType rygel_gst_renderer_rendering_control_get_type (void);
GType rygel_gst_renderer_change_log_get_type (void);
GType rygel_gst_renderer_player_get_type (void);
#define RYGEL_GST_RENDERER_RENDERING_CONTROL_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_GST_RENDERER_TYPE_RENDERING_CONTROL, RygelGstRendererRenderingControlPrivate))
enum  {
	RYGEL_GST_RENDERER_RENDERING_CONTROL_DUMMY_PROPERTY,
	RYGEL_GST_RENDERER_RENDERING_CONTROL_MUTE,
	RYGEL_GST_RENDERER_RENDERING_CONTROL_VOLUME
};
#define RYGEL_GST_RENDERER_RENDERING_CONTROL_UPNP_ID "urn:upnp-org:serviceId:RenderingControl"
#define RYGEL_GST_RENDERER_RENDERING_CONTROL_UPNP_TYPE "urn:schemas-upnp-org:service:RenderingControl:2"
#define RYGEL_GST_RENDERER_RENDERING_CONTROL_DESCRIPTION_PATH "xml/RenderingControl2.xml"
#define RYGEL_GST_RENDERER_RENDERING_CONTROL_LAST_CHANGE_NS "urn:schemas-upnp-org:metadata-1-0/RCS/"
RygelGstRendererChangeLog* rygel_gst_renderer_change_log_new (GUPnPService* service, const char* service_ns);
RygelGstRendererChangeLog* rygel_gst_renderer_change_log_construct (GType object_type, GUPnPService* service, const char* service_ns);
RygelGstRendererPlayer* rygel_gst_renderer_player_get_default (void);
static void rygel_gst_renderer_rendering_control_query_last_change_cb (RygelGstRendererRenderingControl* self, GUPnPService* service, const char* variable, GValue* value);
static void _rygel_gst_renderer_rendering_control_query_last_change_cb_gupnp_service_query_variable (GUPnPService* _sender, const char* variable, GValue* value, gpointer self);
static void rygel_gst_renderer_rendering_control_list_presets_cb (RygelGstRendererRenderingControl* self, GUPnPService* service, GUPnPServiceAction* action);
static void _rygel_gst_renderer_rendering_control_list_presets_cb_gupnp_service_action_invoked (GUPnPService* _sender, GUPnPServiceAction* action, gpointer self);
static void rygel_gst_renderer_rendering_control_select_preset_cb (RygelGstRendererRenderingControl* self, GUPnPService* service, GUPnPServiceAction* action);
static void _rygel_gst_renderer_rendering_control_select_preset_cb_gupnp_service_action_invoked (GUPnPService* _sender, GUPnPServiceAction* action, gpointer self);
static void rygel_gst_renderer_rendering_control_get_mute_cb (RygelGstRendererRenderingControl* self, GUPnPService* service, GUPnPServiceAction* action);
static void _rygel_gst_renderer_rendering_control_get_mute_cb_gupnp_service_action_invoked (GUPnPService* _sender, GUPnPServiceAction* action, gpointer self);
static void rygel_gst_renderer_rendering_control_set_mute_cb (RygelGstRendererRenderingControl* self, GUPnPService* service, GUPnPServiceAction* action);
static void _rygel_gst_renderer_rendering_control_set_mute_cb_gupnp_service_action_invoked (GUPnPService* _sender, GUPnPServiceAction* action, gpointer self);
static void rygel_gst_renderer_rendering_control_get_volume_cb (RygelGstRendererRenderingControl* self, GUPnPService* service, GUPnPServiceAction* action);
static void _rygel_gst_renderer_rendering_control_get_volume_cb_gupnp_service_action_invoked (GUPnPService* _sender, GUPnPServiceAction* action, gpointer self);
static void rygel_gst_renderer_rendering_control_set_volume_cb (RygelGstRendererRenderingControl* self, GUPnPService* service, GUPnPServiceAction* action);
static void _rygel_gst_renderer_rendering_control_set_volume_cb_gupnp_service_action_invoked (GUPnPService* _sender, GUPnPServiceAction* action, gpointer self);
guint rygel_gst_renderer_volume_to_percentage (double volume);
double rygel_gst_renderer_player_get_volume (RygelGstRendererPlayer* self);
static void rygel_gst_renderer_rendering_control_real_constructed (GObject* base);
gboolean rygel_gst_renderer_rendering_control_get_mute (RygelGstRendererRenderingControl* self);
void rygel_gst_renderer_change_log_log_with_channel (RygelGstRendererChangeLog* self, const char* variable, const char* value, const char* channel);
guint rygel_gst_renderer_rendering_control_get_volume (RygelGstRendererRenderingControl* self);
char* rygel_gst_renderer_change_log_finish (RygelGstRendererChangeLog* self);
static gboolean rygel_gst_renderer_rendering_control_check_instance_id (RygelGstRendererRenderingControl* self, GUPnPServiceAction* action);
static gboolean rygel_gst_renderer_rendering_control_check_channel (RygelGstRendererRenderingControl* self, GUPnPServiceAction* action);
void rygel_gst_renderer_rendering_control_set_mute (RygelGstRendererRenderingControl* self, gboolean value);
void rygel_gst_renderer_rendering_control_set_volume (RygelGstRendererRenderingControl* self, guint value);
RygelGstRendererRenderingControl* rygel_gst_renderer_rendering_control_new (void);
RygelGstRendererRenderingControl* rygel_gst_renderer_rendering_control_construct (GType object_type);
void rygel_gst_renderer_player_set_volume (RygelGstRendererPlayer* self, double value);
double rygel_gst_renderer_volume_from_percentage (guint percentage);
static void rygel_gst_renderer_rendering_control_finalize (GObject* obj);
static void rygel_gst_renderer_rendering_control_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void rygel_gst_renderer_rendering_control_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static int _vala_strcmp0 (const char * str1, const char * str2);



#line 96 "rygel-gst-renderer-rendering-control.vala"
static void _rygel_gst_renderer_rendering_control_query_last_change_cb_gupnp_service_query_variable (GUPnPService* _sender, const char* variable, GValue* value, gpointer self) {
#line 145 "rygel-gst-renderer-rendering-control.c"
	rygel_gst_renderer_rendering_control_query_last_change_cb (self, _sender, variable, value);
}


#line 123 "rygel-gst-renderer-rendering-control.vala"
static void _rygel_gst_renderer_rendering_control_list_presets_cb_gupnp_service_action_invoked (GUPnPService* _sender, GUPnPServiceAction* action, gpointer self) {
#line 152 "rygel-gst-renderer-rendering-control.c"
	rygel_gst_renderer_rendering_control_list_presets_cb (self, _sender, action);
}


#line 136 "rygel-gst-renderer-rendering-control.vala"
static void _rygel_gst_renderer_rendering_control_select_preset_cb_gupnp_service_action_invoked (GUPnPService* _sender, GUPnPServiceAction* action, gpointer self) {
#line 159 "rygel-gst-renderer-rendering-control.c"
	rygel_gst_renderer_rendering_control_select_preset_cb (self, _sender, action);
}


#line 168 "rygel-gst-renderer-rendering-control.vala"
static void _rygel_gst_renderer_rendering_control_get_mute_cb_gupnp_service_action_invoked (GUPnPService* _sender, GUPnPServiceAction* action, gpointer self) {
#line 166 "rygel-gst-renderer-rendering-control.c"
	rygel_gst_renderer_rendering_control_get_mute_cb (self, _sender, action);
}


#line 183 "rygel-gst-renderer-rendering-control.vala"
static void _rygel_gst_renderer_rendering_control_set_mute_cb_gupnp_service_action_invoked (GUPnPService* _sender, GUPnPServiceAction* action, gpointer self) {
#line 173 "rygel-gst-renderer-rendering-control.c"
	rygel_gst_renderer_rendering_control_set_mute_cb (self, _sender, action);
}


#line 202 "rygel-gst-renderer-rendering-control.vala"
static void _rygel_gst_renderer_rendering_control_get_volume_cb_gupnp_service_action_invoked (GUPnPService* _sender, GUPnPServiceAction* action, gpointer self) {
#line 180 "rygel-gst-renderer-rendering-control.c"
	rygel_gst_renderer_rendering_control_get_volume_cb (self, _sender, action);
}


#line 217 "rygel-gst-renderer-rendering-control.vala"
static void _rygel_gst_renderer_rendering_control_set_volume_cb_gupnp_service_action_invoked (GUPnPService* _sender, GUPnPServiceAction* action, gpointer self) {
#line 187 "rygel-gst-renderer-rendering-control.c"
	rygel_gst_renderer_rendering_control_set_volume_cb (self, _sender, action);
}


#line 80 "rygel-gst-renderer-rendering-control.vala"
static void rygel_gst_renderer_rendering_control_real_constructed (GObject* base) {
#line 194 "rygel-gst-renderer-rendering-control.c"
	RygelGstRendererRenderingControl * self;
	RygelGstRendererChangeLog* _tmp0_;
	RygelGstRendererPlayer* _tmp1_;
	self = (RygelGstRendererRenderingControl*) base;
#line 81 "rygel-gst-renderer-rendering-control.vala"
	self->priv->changelog = (_tmp0_ = rygel_gst_renderer_change_log_new ((GUPnPService*) self, RYGEL_GST_RENDERER_RENDERING_CONTROL_LAST_CHANGE_NS), _g_object_unref0 (self->priv->changelog), _tmp0_);
#line 82 "rygel-gst-renderer-rendering-control.vala"
	self->priv->player = (_tmp1_ = rygel_gst_renderer_player_get_default (), _g_object_unref0 (self->priv->player), _tmp1_);
#line 84 "rygel-gst-renderer-rendering-control.vala"
	g_signal_connect_object ((GUPnPService*) self, "query-variable::LastChange", (GCallback) _rygel_gst_renderer_rendering_control_query_last_change_cb_gupnp_service_query_variable, self, 0);
#line 86 "rygel-gst-renderer-rendering-control.vala"
	g_signal_connect_object ((GUPnPService*) self, "action-invoked::ListPresets", (GCallback) _rygel_gst_renderer_rendering_control_list_presets_cb_gupnp_service_action_invoked, self, 0);
#line 87 "rygel-gst-renderer-rendering-control.vala"
	g_signal_connect_object ((GUPnPService*) self, "action-invoked::SelectPreset", (GCallback) _rygel_gst_renderer_rendering_control_select_preset_cb_gupnp_service_action_invoked, self, 0);
#line 88 "rygel-gst-renderer-rendering-control.vala"
	g_signal_connect_object ((GUPnPService*) self, "action-invoked::GetMute", (GCallback) _rygel_gst_renderer_rendering_control_get_mute_cb_gupnp_service_action_invoked, self, 0);
#line 89 "rygel-gst-renderer-rendering-control.vala"
	g_signal_connect_object ((GUPnPService*) self, "action-invoked::SetMute", (GCallback) _rygel_gst_renderer_rendering_control_set_mute_cb_gupnp_service_action_invoked, self, 0);
#line 90 "rygel-gst-renderer-rendering-control.vala"
	g_signal_connect_object ((GUPnPService*) self, "action-invoked::GetVolume", (GCallback) _rygel_gst_renderer_rendering_control_get_volume_cb_gupnp_service_action_invoked, self, 0);
#line 91 "rygel-gst-renderer-rendering-control.vala"
	g_signal_connect_object ((GUPnPService*) self, "action-invoked::SetVolume", (GCallback) _rygel_gst_renderer_rendering_control_set_volume_cb_gupnp_service_action_invoked, self, 0);
#line 93 "rygel-gst-renderer-rendering-control.vala"
	self->priv->_volume = rygel_gst_renderer_volume_to_percentage (rygel_gst_renderer_player_get_volume (self->priv->player));
#line 219 "rygel-gst-renderer-rendering-control.c"
}


#line 96 "rygel-gst-renderer-rendering-control.vala"
static void rygel_gst_renderer_rendering_control_query_last_change_cb (RygelGstRendererRenderingControl* self, GUPnPService* service, const char* variable, GValue* value) {
#line 225 "rygel-gst-renderer-rendering-control.c"
	RygelGstRendererChangeLog* log;
	const char* _tmp0_;
	char* _tmp1_;
	char* _tmp2_;
#line 96 "rygel-gst-renderer-rendering-control.vala"
	g_return_if_fail (self != NULL);
#line 96 "rygel-gst-renderer-rendering-control.vala"
	g_return_if_fail (service != NULL);
#line 96 "rygel-gst-renderer-rendering-control.vala"
	g_return_if_fail (variable != NULL);
#line 100 "rygel-gst-renderer-rendering-control.vala"
	log = rygel_gst_renderer_change_log_new (NULL, RYGEL_GST_RENDERER_RENDERING_CONTROL_LAST_CHANGE_NS);
#line 238 "rygel-gst-renderer-rendering-control.c"
	_tmp0_ = NULL;
#line 102 "rygel-gst-renderer-rendering-control.vala"
	if (rygel_gst_renderer_rendering_control_get_mute (self)) {
#line 102 "rygel-gst-renderer-rendering-control.vala"
		_tmp0_ = "1";
#line 244 "rygel-gst-renderer-rendering-control.c"
	} else {
#line 102 "rygel-gst-renderer-rendering-control.vala"
		_tmp0_ = "0";
#line 248 "rygel-gst-renderer-rendering-control.c"
	}
#line 102 "rygel-gst-renderer-rendering-control.vala"
	rygel_gst_renderer_change_log_log_with_channel (log, "Mute", _tmp0_, "Master");
#line 103 "rygel-gst-renderer-rendering-control.vala"
	rygel_gst_renderer_change_log_log_with_channel (log, "Volume", _tmp1_ = g_strdup_printf ("%u", rygel_gst_renderer_rendering_control_get_volume (self)), "Master");
#line 254 "rygel-gst-renderer-rendering-control.c"
	_g_free0 (_tmp1_);
#line 105 "rygel-gst-renderer-rendering-control.vala"
	g_value_init (value, G_TYPE_STRING);
#line 106 "rygel-gst-renderer-rendering-control.vala"
	g_value_set_string (value, _tmp2_ = rygel_gst_renderer_change_log_finish (log));
#line 260 "rygel-gst-renderer-rendering-control.c"
	_g_free0 (_tmp2_);
	_g_object_unref0 (log);
}


#line 110 "rygel-gst-renderer-rendering-control.vala"
static gboolean rygel_gst_renderer_rendering_control_check_instance_id (RygelGstRendererRenderingControl* self, GUPnPServiceAction* action) {
#line 268 "rygel-gst-renderer-rendering-control.c"
	gboolean result = FALSE;
	guint instance_id = 0U;
#line 110 "rygel-gst-renderer-rendering-control.vala"
	g_return_val_if_fail (self != NULL, FALSE);
#line 110 "rygel-gst-renderer-rendering-control.vala"
	g_return_val_if_fail (action != NULL, FALSE);
#line 113 "rygel-gst-renderer-rendering-control.vala"
	gupnp_service_action_get (action, "InstanceID", G_TYPE_UINT, &instance_id, NULL);
#line 114 "rygel-gst-renderer-rendering-control.vala"
	if (instance_id != 0) {
#line 115 "rygel-gst-renderer-rendering-control.vala"
		gupnp_service_action_return_error (action, (guint) 702, _ ("Invalid InstanceID"));
#line 281 "rygel-gst-renderer-rendering-control.c"
		result = FALSE;
#line 117 "rygel-gst-renderer-rendering-control.vala"
		return result;
#line 285 "rygel-gst-renderer-rendering-control.c"
	}
	result = TRUE;
#line 120 "rygel-gst-renderer-rendering-control.vala"
	return result;
#line 290 "rygel-gst-renderer-rendering-control.c"
}


#line 123 "rygel-gst-renderer-rendering-control.vala"
static void rygel_gst_renderer_rendering_control_list_presets_cb (RygelGstRendererRenderingControl* self, GUPnPService* service, GUPnPServiceAction* action) {
#line 123 "rygel-gst-renderer-rendering-control.vala"
	g_return_if_fail (self != NULL);
#line 123 "rygel-gst-renderer-rendering-control.vala"
	g_return_if_fail (service != NULL);
#line 123 "rygel-gst-renderer-rendering-control.vala"
	g_return_if_fail (action != NULL);
#line 125 "rygel-gst-renderer-rendering-control.vala"
	if (!rygel_gst_renderer_rendering_control_check_instance_id (self, action)) {
#line 126 "rygel-gst-renderer-rendering-control.vala"
		return;
#line 306 "rygel-gst-renderer-rendering-control.c"
	}
#line 129 "rygel-gst-renderer-rendering-control.vala"
	gupnp_service_action_set (action, "CurrentPresetNameList", G_TYPE_STRING, self->priv->preset_name_list, NULL);
#line 133 "rygel-gst-renderer-rendering-control.vala"
	gupnp_service_action_return (action);
#line 312 "rygel-gst-renderer-rendering-control.c"
}


#line 136 "rygel-gst-renderer-rendering-control.vala"
static void rygel_gst_renderer_rendering_control_select_preset_cb (RygelGstRendererRenderingControl* self, GUPnPService* service, GUPnPServiceAction* action) {
#line 318 "rygel-gst-renderer-rendering-control.c"
	char* preset_name;
#line 136 "rygel-gst-renderer-rendering-control.vala"
	g_return_if_fail (self != NULL);
#line 136 "rygel-gst-renderer-rendering-control.vala"
	g_return_if_fail (service != NULL);
#line 136 "rygel-gst-renderer-rendering-control.vala"
	g_return_if_fail (action != NULL);
#line 138 "rygel-gst-renderer-rendering-control.vala"
	if (!rygel_gst_renderer_rendering_control_check_instance_id (self, action)) {
#line 139 "rygel-gst-renderer-rendering-control.vala"
		return;
#line 330 "rygel-gst-renderer-rendering-control.c"
	}
	preset_name = NULL;
#line 144 "rygel-gst-renderer-rendering-control.vala"
	gupnp_service_action_get (action, "PresetName", G_TYPE_STRING, &preset_name, NULL);
#line 145 "rygel-gst-renderer-rendering-control.vala"
	if (_vala_strcmp0 (preset_name, "") != 0) {
#line 146 "rygel-gst-renderer-rendering-control.vala"
		gupnp_service_action_return_error (action, (guint) 701, _ ("Invalid Name"));
#line 339 "rygel-gst-renderer-rendering-control.c"
		_g_free0 (preset_name);
#line 148 "rygel-gst-renderer-rendering-control.vala"
		return;
#line 343 "rygel-gst-renderer-rendering-control.c"
	}
#line 151 "rygel-gst-renderer-rendering-control.vala"
	gupnp_service_action_return (action);
#line 347 "rygel-gst-renderer-rendering-control.c"
	_g_free0 (preset_name);
}


#line 155 "rygel-gst-renderer-rendering-control.vala"
static gboolean rygel_gst_renderer_rendering_control_check_channel (RygelGstRendererRenderingControl* self, GUPnPServiceAction* action) {
#line 354 "rygel-gst-renderer-rendering-control.c"
	gboolean result = FALSE;
	char* channel;
#line 155 "rygel-gst-renderer-rendering-control.vala"
	g_return_val_if_fail (self != NULL, FALSE);
#line 155 "rygel-gst-renderer-rendering-control.vala"
	g_return_val_if_fail (action != NULL, FALSE);
#line 361 "rygel-gst-renderer-rendering-control.c"
	channel = NULL;
#line 158 "rygel-gst-renderer-rendering-control.vala"
	gupnp_service_action_get (action, "Channel", G_TYPE_STRING, &channel, NULL);
#line 159 "rygel-gst-renderer-rendering-control.vala"
	if (_vala_strcmp0 (channel, "Master") != 0) {
#line 160 "rygel-gst-renderer-rendering-control.vala"
		gupnp_service_action_return_error (action, (guint) 501, _ ("Action Failed"));
#line 369 "rygel-gst-renderer-rendering-control.c"
		result = FALSE;
		_g_free0 (channel);
#line 162 "rygel-gst-renderer-rendering-control.vala"
		return result;
#line 374 "rygel-gst-renderer-rendering-control.c"
	}
	result = TRUE;
	_g_free0 (channel);
#line 165 "rygel-gst-renderer-rendering-control.vala"
	return result;
#line 380 "rygel-gst-renderer-rendering-control.c"
}


#line 168 "rygel-gst-renderer-rendering-control.vala"
static void rygel_gst_renderer_rendering_control_get_mute_cb (RygelGstRendererRenderingControl* self, GUPnPService* service, GUPnPServiceAction* action) {
#line 168 "rygel-gst-renderer-rendering-control.vala"
	g_return_if_fail (self != NULL);
#line 168 "rygel-gst-renderer-rendering-control.vala"
	g_return_if_fail (service != NULL);
#line 168 "rygel-gst-renderer-rendering-control.vala"
	g_return_if_fail (action != NULL);
#line 170 "rygel-gst-renderer-rendering-control.vala"
	if (!rygel_gst_renderer_rendering_control_check_instance_id (self, action)) {
#line 171 "rygel-gst-renderer-rendering-control.vala"
		return;
#line 396 "rygel-gst-renderer-rendering-control.c"
	}
#line 174 "rygel-gst-renderer-rendering-control.vala"
	if (!rygel_gst_renderer_rendering_control_check_channel (self, action)) {
#line 175 "rygel-gst-renderer-rendering-control.vala"
		return;
#line 402 "rygel-gst-renderer-rendering-control.c"
	}
#line 178 "rygel-gst-renderer-rendering-control.vala"
	gupnp_service_action_set (action, "CurrentMute", G_TYPE_BOOLEAN, rygel_gst_renderer_rendering_control_get_mute (self), NULL);
#line 180 "rygel-gst-renderer-rendering-control.vala"
	gupnp_service_action_return (action);
#line 408 "rygel-gst-renderer-rendering-control.c"
}


#line 183 "rygel-gst-renderer-rendering-control.vala"
static void rygel_gst_renderer_rendering_control_set_mute_cb (RygelGstRendererRenderingControl* self, GUPnPService* service, GUPnPServiceAction* action) {
#line 414 "rygel-gst-renderer-rendering-control.c"
	gboolean mute = FALSE;
#line 183 "rygel-gst-renderer-rendering-control.vala"
	g_return_if_fail (self != NULL);
#line 183 "rygel-gst-renderer-rendering-control.vala"
	g_return_if_fail (service != NULL);
#line 183 "rygel-gst-renderer-rendering-control.vala"
	g_return_if_fail (action != NULL);
#line 185 "rygel-gst-renderer-rendering-control.vala"
	if (!rygel_gst_renderer_rendering_control_check_instance_id (self, action)) {
#line 186 "rygel-gst-renderer-rendering-control.vala"
		return;
#line 426 "rygel-gst-renderer-rendering-control.c"
	}
#line 189 "rygel-gst-renderer-rendering-control.vala"
	if (!rygel_gst_renderer_rendering_control_check_channel (self, action)) {
#line 190 "rygel-gst-renderer-rendering-control.vala"
		return;
#line 432 "rygel-gst-renderer-rendering-control.c"
	}
#line 195 "rygel-gst-renderer-rendering-control.vala"
	gupnp_service_action_get (action, "DesiredMute", G_TYPE_BOOLEAN, &mute, NULL);
#line 197 "rygel-gst-renderer-rendering-control.vala"
	rygel_gst_renderer_rendering_control_set_mute (self, mute);
#line 199 "rygel-gst-renderer-rendering-control.vala"
	gupnp_service_action_return (action);
#line 440 "rygel-gst-renderer-rendering-control.c"
}


#line 202 "rygel-gst-renderer-rendering-control.vala"
static void rygel_gst_renderer_rendering_control_get_volume_cb (RygelGstRendererRenderingControl* self, GUPnPService* service, GUPnPServiceAction* action) {
#line 202 "rygel-gst-renderer-rendering-control.vala"
	g_return_if_fail (self != NULL);
#line 202 "rygel-gst-renderer-rendering-control.vala"
	g_return_if_fail (service != NULL);
#line 202 "rygel-gst-renderer-rendering-control.vala"
	g_return_if_fail (action != NULL);
#line 204 "rygel-gst-renderer-rendering-control.vala"
	if (!rygel_gst_renderer_rendering_control_check_instance_id (self, action)) {
#line 205 "rygel-gst-renderer-rendering-control.vala"
		return;
#line 456 "rygel-gst-renderer-rendering-control.c"
	}
#line 208 "rygel-gst-renderer-rendering-control.vala"
	if (!rygel_gst_renderer_rendering_control_check_channel (self, action)) {
#line 209 "rygel-gst-renderer-rendering-control.vala"
		return;
#line 462 "rygel-gst-renderer-rendering-control.c"
	}
#line 212 "rygel-gst-renderer-rendering-control.vala"
	gupnp_service_action_set (action, "CurrentVolume", G_TYPE_UINT, rygel_gst_renderer_rendering_control_get_volume (self), NULL);
#line 214 "rygel-gst-renderer-rendering-control.vala"
	gupnp_service_action_return (action);
#line 468 "rygel-gst-renderer-rendering-control.c"
}


#line 217 "rygel-gst-renderer-rendering-control.vala"
static void rygel_gst_renderer_rendering_control_set_volume_cb (RygelGstRendererRenderingControl* self, GUPnPService* service, GUPnPServiceAction* action) {
#line 474 "rygel-gst-renderer-rendering-control.c"
	guint volume = 0U;
#line 217 "rygel-gst-renderer-rendering-control.vala"
	g_return_if_fail (self != NULL);
#line 217 "rygel-gst-renderer-rendering-control.vala"
	g_return_if_fail (service != NULL);
#line 217 "rygel-gst-renderer-rendering-control.vala"
	g_return_if_fail (action != NULL);
#line 219 "rygel-gst-renderer-rendering-control.vala"
	if (!rygel_gst_renderer_rendering_control_check_instance_id (self, action)) {
#line 220 "rygel-gst-renderer-rendering-control.vala"
		return;
#line 486 "rygel-gst-renderer-rendering-control.c"
	}
#line 223 "rygel-gst-renderer-rendering-control.vala"
	if (!rygel_gst_renderer_rendering_control_check_channel (self, action)) {
#line 224 "rygel-gst-renderer-rendering-control.vala"
		return;
#line 492 "rygel-gst-renderer-rendering-control.c"
	}
#line 229 "rygel-gst-renderer-rendering-control.vala"
	gupnp_service_action_get (action, "DesiredVolume", G_TYPE_UINT, &volume, NULL);
#line 230 "rygel-gst-renderer-rendering-control.vala"
	if (volume > 100) {
#line 231 "rygel-gst-renderer-rendering-control.vala"
		gupnp_service_action_return_error (action, (guint) 501, _ ("Action Failed"));
#line 233 "rygel-gst-renderer-rendering-control.vala"
		return;
#line 502 "rygel-gst-renderer-rendering-control.c"
	}
#line 236 "rygel-gst-renderer-rendering-control.vala"
	rygel_gst_renderer_rendering_control_set_volume (self, volume);
#line 238 "rygel-gst-renderer-rendering-control.vala"
	gupnp_service_action_return (action);
#line 508 "rygel-gst-renderer-rendering-control.c"
}


#line 27 "rygel-gst-renderer-rendering-control.vala"
RygelGstRendererRenderingControl* rygel_gst_renderer_rendering_control_construct (GType object_type) {
#line 514 "rygel-gst-renderer-rendering-control.c"
	RygelGstRendererRenderingControl * self;
	self = g_object_newv (object_type, 0, NULL);
	return self;
}


#line 27 "rygel-gst-renderer-rendering-control.vala"
RygelGstRendererRenderingControl* rygel_gst_renderer_rendering_control_new (void) {
#line 27 "rygel-gst-renderer-rendering-control.vala"
	return rygel_gst_renderer_rendering_control_construct (RYGEL_GST_RENDERER_TYPE_RENDERING_CONTROL);
#line 525 "rygel-gst-renderer-rendering-control.c"
}


gboolean rygel_gst_renderer_rendering_control_get_mute (RygelGstRendererRenderingControl* self) {
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_mute;
#line 38 "rygel-gst-renderer-rendering-control.vala"
	return result;
#line 535 "rygel-gst-renderer-rendering-control.c"
}


void rygel_gst_renderer_rendering_control_set_mute (RygelGstRendererRenderingControl* self, gboolean value) {
	const char* _tmp0_;
	g_return_if_fail (self != NULL);
#line 42 "rygel-gst-renderer-rendering-control.vala"
	self->priv->_mute = value;
#line 44 "rygel-gst-renderer-rendering-control.vala"
	if (self->priv->_mute) {
#line 45 "rygel-gst-renderer-rendering-control.vala"
		rygel_gst_renderer_player_set_volume (self->priv->player, (double) 0);
#line 548 "rygel-gst-renderer-rendering-control.c"
	} else {
#line 47 "rygel-gst-renderer-rendering-control.vala"
		rygel_gst_renderer_player_set_volume (self->priv->player, rygel_gst_renderer_volume_from_percentage (rygel_gst_renderer_rendering_control_get_volume (self)));
#line 552 "rygel-gst-renderer-rendering-control.c"
	}
	_tmp0_ = NULL;
#line 51 "rygel-gst-renderer-rendering-control.vala"
	if (rygel_gst_renderer_rendering_control_get_mute (self)) {
#line 51 "rygel-gst-renderer-rendering-control.vala"
		_tmp0_ = "1";
#line 559 "rygel-gst-renderer-rendering-control.c"
	} else {
#line 51 "rygel-gst-renderer-rendering-control.vala"
		_tmp0_ = "0";
#line 563 "rygel-gst-renderer-rendering-control.c"
	}
#line 50 "rygel-gst-renderer-rendering-control.vala"
	rygel_gst_renderer_change_log_log_with_channel (self->priv->changelog, "Mute", _tmp0_, "Master");
#line 567 "rygel-gst-renderer-rendering-control.c"
	g_object_notify ((GObject *) self, "mute");
}


guint rygel_gst_renderer_rendering_control_get_volume (RygelGstRendererRenderingControl* self) {
	guint result;
	g_return_val_if_fail (self != NULL, 0U);
	result = self->priv->_volume;
#line 59 "rygel-gst-renderer-rendering-control.vala"
	return result;
#line 578 "rygel-gst-renderer-rendering-control.c"
}


void rygel_gst_renderer_rendering_control_set_volume (RygelGstRendererRenderingControl* self, guint value) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
#line 63 "rygel-gst-renderer-rendering-control.vala"
	self->priv->_volume = value;
#line 65 "rygel-gst-renderer-rendering-control.vala"
	if (!rygel_gst_renderer_rendering_control_get_mute (self)) {
#line 66 "rygel-gst-renderer-rendering-control.vala"
		rygel_gst_renderer_player_set_volume (self->priv->player, rygel_gst_renderer_volume_from_percentage (rygel_gst_renderer_rendering_control_get_volume (self)));
#line 591 "rygel-gst-renderer-rendering-control.c"
	}
#line 69 "rygel-gst-renderer-rendering-control.vala"
	rygel_gst_renderer_change_log_log_with_channel (self->priv->changelog, "Volume", _tmp0_ = g_strdup_printf ("%u", rygel_gst_renderer_rendering_control_get_volume (self)), "Master");
#line 595 "rygel-gst-renderer-rendering-control.c"
	_g_free0 (_tmp0_);
	g_object_notify ((GObject *) self, "volume");
}


static void rygel_gst_renderer_rendering_control_class_init (RygelGstRendererRenderingControlClass * klass) {
	rygel_gst_renderer_rendering_control_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelGstRendererRenderingControlPrivate));
	G_OBJECT_CLASS (klass)->constructed = rygel_gst_renderer_rendering_control_real_constructed;
	G_OBJECT_CLASS (klass)->get_property = rygel_gst_renderer_rendering_control_get_property;
	G_OBJECT_CLASS (klass)->set_property = rygel_gst_renderer_rendering_control_set_property;
	G_OBJECT_CLASS (klass)->finalize = rygel_gst_renderer_rendering_control_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), RYGEL_GST_RENDERER_RENDERING_CONTROL_MUTE, g_param_spec_boolean ("mute", "mute", "mute", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), RYGEL_GST_RENDERER_RENDERING_CONTROL_VOLUME, g_param_spec_uint ("volume", "volume", "volume", 0, G_MAXUINT, 0U, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void rygel_gst_renderer_rendering_control_instance_init (RygelGstRendererRenderingControl * self) {
	self->priv = RYGEL_GST_RENDERER_RENDERING_CONTROL_GET_PRIVATE (self);
	self->priv->_mute = FALSE;
	self->priv->_volume = (guint) 0;
	self->priv->preset_name_list = g_strdup ("");
}


static void rygel_gst_renderer_rendering_control_finalize (GObject* obj) {
	RygelGstRendererRenderingControl * self;
	self = RYGEL_GST_RENDERER_RENDERING_CONTROL (obj);
	_g_free0 (self->priv->preset_name_list);
	_g_object_unref0 (self->priv->changelog);
	_g_object_unref0 (self->priv->player);
	G_OBJECT_CLASS (rygel_gst_renderer_rendering_control_parent_class)->finalize (obj);
}


GType rygel_gst_renderer_rendering_control_get_type (void) {
	static volatile gsize rygel_gst_renderer_rendering_control_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_gst_renderer_rendering_control_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelGstRendererRenderingControlClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_gst_renderer_rendering_control_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelGstRendererRenderingControl), 0, (GInstanceInitFunc) rygel_gst_renderer_rendering_control_instance_init, NULL };
		GType rygel_gst_renderer_rendering_control_type_id;
		rygel_gst_renderer_rendering_control_type_id = g_type_register_static (GUPNP_TYPE_SERVICE, "RygelGstRendererRenderingControl", &g_define_type_info, 0);
		g_once_init_leave (&rygel_gst_renderer_rendering_control_type_id__volatile, rygel_gst_renderer_rendering_control_type_id);
	}
	return rygel_gst_renderer_rendering_control_type_id__volatile;
}


static void rygel_gst_renderer_rendering_control_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	RygelGstRendererRenderingControl * self;
	self = RYGEL_GST_RENDERER_RENDERING_CONTROL (object);
	switch (property_id) {
		case RYGEL_GST_RENDERER_RENDERING_CONTROL_MUTE:
		g_value_set_boolean (value, rygel_gst_renderer_rendering_control_get_mute (self));
		break;
		case RYGEL_GST_RENDERER_RENDERING_CONTROL_VOLUME:
		g_value_set_uint (value, rygel_gst_renderer_rendering_control_get_volume (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void rygel_gst_renderer_rendering_control_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	RygelGstRendererRenderingControl * self;
	self = RYGEL_GST_RENDERER_RENDERING_CONTROL (object);
	switch (property_id) {
		case RYGEL_GST_RENDERER_RENDERING_CONTROL_MUTE:
		rygel_gst_renderer_rendering_control_set_mute (self, g_value_get_boolean (value));
		break;
		case RYGEL_GST_RENDERER_RENDERING_CONTROL_VOLUME:
		rygel_gst_renderer_rendering_control_set_volume (self, g_value_get_uint (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
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




