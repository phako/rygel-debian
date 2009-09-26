/*
 * Copyright (C) 2008 Zeeshan Ali (Khattak) <zeeshanak@gnome.org>.
 * Copyright (C) 2008 Nokia Corporation.
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
#include <gio/gio.h>
#include <libsoup/soup.h>
#include <gst/gst.h>
#include <stdlib.h>
#include <string.h>


#define RYGEL_TYPE_STATE_MACHINE (rygel_state_machine_get_type ())
#define RYGEL_STATE_MACHINE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_STATE_MACHINE, RygelStateMachine))
#define RYGEL_IS_STATE_MACHINE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_STATE_MACHINE))
#define RYGEL_STATE_MACHINE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), RYGEL_TYPE_STATE_MACHINE, RygelStateMachineIface))

typedef struct _RygelStateMachine RygelStateMachine;
typedef struct _RygelStateMachineIface RygelStateMachineIface;

#define RYGEL_TYPE_HTTP_RESPONSE (rygel_http_response_get_type ())
#define RYGEL_HTTP_RESPONSE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_RESPONSE, RygelHTTPResponse))
#define RYGEL_HTTP_RESPONSE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_RESPONSE, RygelHTTPResponseClass))
#define RYGEL_IS_HTTP_RESPONSE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_RESPONSE))
#define RYGEL_IS_HTTP_RESPONSE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_RESPONSE))
#define RYGEL_HTTP_RESPONSE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_RESPONSE, RygelHTTPResponseClass))

typedef struct _RygelHTTPResponse RygelHTTPResponse;
typedef struct _RygelHTTPResponseClass RygelHTTPResponseClass;
typedef struct _RygelHTTPResponsePrivate RygelHTTPResponsePrivate;

#define RYGEL_TYPE_LIVE_RESPONSE (rygel_live_response_get_type ())
#define RYGEL_LIVE_RESPONSE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_LIVE_RESPONSE, RygelLiveResponse))
#define RYGEL_LIVE_RESPONSE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_LIVE_RESPONSE, RygelLiveResponseClass))
#define RYGEL_IS_LIVE_RESPONSE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_LIVE_RESPONSE))
#define RYGEL_IS_LIVE_RESPONSE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_LIVE_RESPONSE))
#define RYGEL_LIVE_RESPONSE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_LIVE_RESPONSE, RygelLiveResponseClass))

typedef struct _RygelLiveResponse RygelLiveResponse;
typedef struct _RygelLiveResponseClass RygelLiveResponseClass;
typedef struct _RygelLiveResponsePrivate RygelLiveResponsePrivate;

#define RYGEL_TYPE_HTTP_SEEK (rygel_http_seek_get_type ())
#define RYGEL_HTTP_SEEK(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_SEEK, RygelHTTPSeek))
#define RYGEL_HTTP_SEEK_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_SEEK, RygelHTTPSeekClass))
#define RYGEL_IS_HTTP_SEEK(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_SEEK))
#define RYGEL_IS_HTTP_SEEK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_SEEK))
#define RYGEL_HTTP_SEEK_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_SEEK, RygelHTTPSeekClass))

typedef struct _RygelHTTPSeek RygelHTTPSeek;
typedef struct _RygelHTTPSeekClass RygelHTTPSeekClass;
#define _gst_object_unref0(var) ((var == NULL) ? NULL : (var = (gst_object_unref (var), NULL)))
#define _g_async_queue_unref0(var) ((var == NULL) ? NULL : (var = (g_async_queue_unref (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _gst_buffer_unref0(var) ((var == NULL) ? NULL : (var = (gst_buffer_unref (var), NULL)))
#define _gst_caps_unref0(var) ((var == NULL) ? NULL : (var = (gst_caps_unref (var), NULL)))
#define _gst_structure_free0(var) ((var == NULL) ? NULL : (var = (gst_structure_free (var), NULL)))
#define __g_list_free_gst_object_unref0(var) ((var == NULL) ? NULL : (var = (_g_list_free_gst_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

typedef enum  {
	RYGEL_LIVE_RESPONSE_ERROR_MISSING_PLUGIN,
	RYGEL_LIVE_RESPONSE_ERROR_LINK
} RygelLiveResponseError;
#define RYGEL_LIVE_RESPONSE_ERROR rygel_live_response_error_quark ()
struct _RygelStateMachineIface {
	GTypeInterface parent_iface;
	void (*run) (RygelStateMachine* self);
	GCancellable* (*get_cancellable) (RygelStateMachine* self);
	void (*set_cancellable) (RygelStateMachine* self, GCancellable* value);
};

struct _RygelHTTPResponse {
	GObject parent_instance;
	RygelHTTPResponsePrivate * priv;
	SoupMessage* msg;
};

struct _RygelHTTPResponseClass {
	GObjectClass parent_class;
	void (*run) (RygelHTTPResponse* self);
	void (*end) (RygelHTTPResponse* self, gboolean aborted, guint status);
};

struct _RygelLiveResponse {
	RygelHTTPResponse parent_instance;
	RygelLiveResponsePrivate * priv;
};

struct _RygelLiveResponseClass {
	RygelHTTPResponseClass parent_class;
};

struct _RygelLiveResponsePrivate {
	GstPipeline* pipeline;
	GAsyncQueue* buffers;
	RygelHTTPSeek* time_range;
};


static gpointer rygel_live_response_parent_class = NULL;

GQuark rygel_live_response_error_quark (void);
GType rygel_state_machine_get_type (void);
GType rygel_http_response_get_type (void);
GType rygel_live_response_get_type (void);
GType rygel_http_seek_get_type (void);
#define RYGEL_LIVE_RESPONSE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_LIVE_RESPONSE, RygelLiveResponsePrivate))
enum  {
	RYGEL_LIVE_RESPONSE_DUMMY_PROPERTY
};
#define RYGEL_LIVE_RESPONSE_SINK_NAME "fakesink"
RygelHTTPResponse* rygel_http_response_construct (GType object_type, SoupServer* server, SoupMessage* msg, gboolean partial, GCancellable* cancellable);
static void rygel_live_response_prepare_pipeline (RygelLiveResponse* self, const char* name, GstElement* src, GError** error);
RygelLiveResponse* rygel_live_response_new (SoupServer* server, SoupMessage* msg, const char* name, GstElement* src, RygelHTTPSeek* time_range, GCancellable* cancellable, GError** error);
RygelLiveResponse* rygel_live_response_construct (GType object_type, SoupServer* server, SoupMessage* msg, const char* name, GstElement* src, RygelHTTPSeek* time_range, GCancellable* cancellable, GError** error);
void rygel_http_response_run (RygelHTTPResponse* self);
gint64 rygel_http_seek_get_start (RygelHTTPSeek* self);
static void rygel_live_response_real_run (RygelHTTPResponse* base);
void rygel_http_response_end (RygelHTTPResponse* self, gboolean aborted, guint status);
static void rygel_live_response_real_end (RygelHTTPResponse* base, gboolean aborted, guint status);
static inline void _dynamic_set_signal_handoffs0 (GstElement* obj, gboolean value);
static void rygel_live_response_on_new_buffer (RygelLiveResponse* self, GstElement* sink, GstBuffer* buffer, GstPad* pad);
static void _rygel_live_response_on_new_buffer_dynamic_handoff0_ (GstElement* _sender, GstBuffer* buffer, GstPad* pad, gpointer self);
void _dynamic_handoff1_connect (gpointer obj, const char * signal_name, GCallback handler, gpointer data);
static void rygel_live_response_src_pad_added (RygelLiveResponse* self, GstElement* src, GstPad* src_pad);
static void _rygel_live_response_src_pad_added_gst_element_pad_added (GstElement* _sender, GstPad* pad, gpointer self);
static gboolean rygel_live_response_bus_handler (RygelLiveResponse* self, GstBus* bus, GstMessage* message);
static gboolean _rygel_live_response_bus_handler_gst_bus_func (GstBus* bus, GstMessage* message, gpointer self);
static GstElement* rygel_live_response_get_rtp_depayloader (RygelLiveResponse* self, GstCaps* caps);
static gboolean rygel_live_response_need_rtp_depayloader (RygelLiveResponse* self, GstCaps* caps);
static gboolean rygel_live_response_rtp_depay_filter (RygelLiveResponse* self, GstPluginFeature* feature);
static gboolean _rygel_live_response_rtp_depay_filter_gst_plugin_feature_filter (GstPluginFeature* feature, gpointer self);
static GstElement* rygel_live_response_get_best_depay (RygelLiveResponse* self, GList* features, GstCaps* caps);
static void _g_list_free_gst_object_unref (GList* self);
static gint rygel_live_response_compare_factories (void* a, void* b);
static gint _rygel_live_response_compare_factories_gcompare_func (void* a, void* b);
static gboolean rygel_live_response_idle_handler (RygelLiveResponse* self);
static gboolean _rygel_live_response_idle_handler_gsource_func (gpointer self);
void rygel_http_response_push_data (RygelHTTPResponse* self, void* data, gsize length);
static gboolean rygel_live_response_seek (RygelLiveResponse* self);
gint64 rygel_http_seek_get_stop (RygelHTTPSeek* self);
static void rygel_live_response_finalize (GObject* obj);
static int _vala_strcmp0 (const char * str1, const char * str2);


static void g_cclosure_user_marshal_VOID__POINTER_OBJECT (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);

GQuark rygel_live_response_error_quark (void) {
	return g_quark_from_static_string ("rygel_live_response_error-quark");
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


RygelLiveResponse* rygel_live_response_construct (GType object_type, SoupServer* server, SoupMessage* msg, const char* name, GstElement* src, RygelHTTPSeek* time_range, GCancellable* cancellable, GError** error) {
	GError * _inner_error_;
	RygelLiveResponse * self;
	GAsyncQueue* _tmp0_;
	RygelHTTPSeek* _tmp1_;
	g_return_val_if_fail (server != NULL, NULL);
	g_return_val_if_fail (msg != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (src != NULL, NULL);
	_inner_error_ = NULL;
	self = (RygelLiveResponse*) rygel_http_response_construct (object_type, server, msg, FALSE, cancellable);
	soup_message_headers_set_encoding (((RygelHTTPResponse*) self)->msg->response_headers, SOUP_ENCODING_EOF);
	self->priv->buffers = (_tmp0_ = g_async_queue_new (), _g_async_queue_unref0 (self->priv->buffers), _tmp0_);
	rygel_live_response_prepare_pipeline (self, name, src, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return;
	}
	self->priv->time_range = (_tmp1_ = _g_object_ref0 (time_range), _g_object_unref0 (self->priv->time_range), _tmp1_);
	return self;
}


RygelLiveResponse* rygel_live_response_new (SoupServer* server, SoupMessage* msg, const char* name, GstElement* src, RygelHTTPSeek* time_range, GCancellable* cancellable, GError** error) {
	return rygel_live_response_construct (RYGEL_TYPE_LIVE_RESPONSE, server, msg, name, src, time_range, cancellable, error);
}


static void rygel_live_response_real_run (RygelHTTPResponse* base) {
	RygelLiveResponse * self;
	gboolean _tmp0_;
	self = (RygelLiveResponse*) base;
	RYGEL_HTTP_RESPONSE_CLASS (rygel_live_response_parent_class)->run (RYGEL_HTTP_RESPONSE (self));
	_tmp0_ = FALSE;
	if (self->priv->time_range != NULL) {
		_tmp0_ = rygel_http_seek_get_start (self->priv->time_range) > 0;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		gst_element_set_state ((GstElement*) self->priv->pipeline, GST_STATE_PAUSED);
	} else {
		gst_element_set_state ((GstElement*) self->priv->pipeline, GST_STATE_PLAYING);
	}
}


static void rygel_live_response_real_end (RygelHTTPResponse* base, gboolean aborted, guint status) {
	RygelLiveResponse * self;
	GstBuffer* buffer;
	self = (RygelLiveResponse*) base;
	gst_element_set_state ((GstElement*) self->priv->pipeline, GST_STATE_NULL);
	buffer = NULL;
	{
		gboolean _tmp0_;
		_tmp0_ = TRUE;
		while (TRUE) {
			GstBuffer* _tmp1_;
			if (!_tmp0_) {
				if (!(buffer != NULL)) {
					break;
				}
			}
			_tmp0_ = FALSE;
			buffer = (_tmp1_ = (GstBuffer*) g_async_queue_try_pop (self->priv->buffers), _gst_buffer_unref0 (buffer), _tmp1_);
		}
	}
	if (!aborted) {
		soup_message_body_complete (((RygelHTTPResponse*) self)->msg->response_body);
	}
	RYGEL_HTTP_RESPONSE_CLASS (rygel_live_response_parent_class)->end (RYGEL_HTTP_RESPONSE (self), aborted, status);
	_gst_buffer_unref0 (buffer);
}


static inline void _dynamic_set_signal_handoffs0 (GstElement* obj, gboolean value) {
	g_object_set (obj, "signal-handoffs", value, NULL);
}


static void _rygel_live_response_on_new_buffer_dynamic_handoff0_ (GstElement* _sender, GstBuffer* buffer, GstPad* pad, gpointer self) {
	rygel_live_response_on_new_buffer (self, _sender, buffer, pad);
}


void _dynamic_handoff1_connect (gpointer obj, const char * signal_name, GCallback handler, gpointer data) {
	g_signal_connect_object (obj, signal_name, handler, data, 0);
}


static gpointer _gst_object_ref0 (gpointer self) {
	return self ? gst_object_ref (self) : NULL;
}


static void _rygel_live_response_src_pad_added_gst_element_pad_added (GstElement* _sender, GstPad* pad, gpointer self) {
	rygel_live_response_src_pad_added (self, _sender, pad);
}


static gboolean _rygel_live_response_bus_handler_gst_bus_func (GstBus* bus, GstMessage* message, gpointer self) {
	return rygel_live_response_bus_handler (self, bus, message);
}


static void rygel_live_response_prepare_pipeline (RygelLiveResponse* self, const char* name, GstElement* src, GError** error) {
	GError * _inner_error_;
	GstElement* sink;
	GstPipeline* _tmp0_;
	GstBus* bus;
	g_return_if_fail (self != NULL);
	g_return_if_fail (name != NULL);
	g_return_if_fail (src != NULL);
	_inner_error_ = NULL;
	sink = gst_element_factory_make ("fakesink", RYGEL_LIVE_RESPONSE_SINK_NAME);
	if (sink == NULL) {
		_inner_error_ = g_error_new_literal (RYGEL_LIVE_RESPONSE_ERROR, RYGEL_LIVE_RESPONSE_ERROR_MISSING_PLUGIN, "Required plugin 'fakesink' missing");
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_gst_object_unref0 (sink);
			return;
		}
	}
	_dynamic_set_signal_handoffs0 (sink, TRUE);
	_dynamic_handoff1_connect (sink, "handoff", (GCallback) _rygel_live_response_on_new_buffer_dynamic_handoff0_, self);
	self->priv->pipeline = (_tmp0_ = (GstPipeline*) gst_pipeline_new (name), _gst_object_unref0 (self->priv->pipeline), _tmp0_);
	g_assert (self->priv->pipeline != NULL);
	gst_bin_add_many ((GstBin*) self->priv->pipeline, _gst_object_ref0 (src), _gst_object_ref0 (sink), NULL);
	if (src->numpads == 0) {
		g_signal_connect_object (src, "pad-added", (GCallback) _rygel_live_response_src_pad_added_gst_element_pad_added, self, 0);
	} else {
		if (!gst_element_link (src, sink)) {
			_inner_error_ = g_error_new (RYGEL_LIVE_RESPONSE_ERROR, RYGEL_LIVE_RESPONSE_ERROR_LINK, "Failed to link %s to %s", gst_object_get_name ((GstObject*) src), gst_object_get_name ((GstObject*) sink));
			if (_inner_error_ != NULL) {
				g_propagate_error (error, _inner_error_);
				_gst_object_unref0 (sink);
				return;
			}
		}
	}
	bus = gst_pipeline_get_bus (self->priv->pipeline);
	gst_bus_add_watch (bus, _rygel_live_response_bus_handler_gst_bus_func, self);
	_gst_object_unref0 (sink);
	_gst_object_unref0 (bus);
}


static void rygel_live_response_src_pad_added (RygelLiveResponse* self, GstElement* src, GstPad* src_pad) {
	GstCaps* caps;
	GstElement* sink;
	GstPad* sink_pad;
	GstElement* depay;
	g_return_if_fail (self != NULL);
	g_return_if_fail (src != NULL);
	g_return_if_fail (src_pad != NULL);
	caps = gst_pad_get_caps (src_pad);
	sink = gst_bin_get_by_name ((GstBin*) self->priv->pipeline, RYGEL_LIVE_RESPONSE_SINK_NAME);
	sink_pad = NULL;
	depay = rygel_live_response_get_rtp_depayloader (self, caps);
	if (depay != NULL) {
		GstPad* _tmp0_;
		gst_bin_add ((GstBin*) self->priv->pipeline, _gst_object_ref0 (depay));
		if (!gst_element_link (depay, sink)) {
			g_critical ("rygel-live-response.vala:130: Failed to link %s to %s", gst_object_get_name ((GstObject*) depay), gst_object_get_name ((GstObject*) sink));
			rygel_http_response_end ((RygelHTTPResponse*) self, FALSE, (guint) SOUP_STATUS_NONE);
			_gst_caps_unref0 (caps);
			_gst_object_unref0 (sink);
			_gst_object_unref0 (sink_pad);
			_gst_object_unref0 (depay);
			return;
		}
		sink_pad = (_tmp0_ = _gst_object_ref0 (gst_element_get_compatible_pad (depay, src_pad, caps)), _gst_object_unref0 (sink_pad), _tmp0_);
	} else {
		GstPad* _tmp1_;
		sink_pad = (_tmp1_ = _gst_object_ref0 (gst_element_get_compatible_pad (sink, src_pad, caps)), _gst_object_unref0 (sink_pad), _tmp1_);
	}
	if (gst_pad_link (src_pad, sink_pad) != GST_PAD_LINK_OK) {
		g_critical ("rygel-live-response.vala:143: Failed to link pad %s to %s", gst_object_get_name ((GstObject*) src_pad), gst_object_get_name ((GstObject*) sink_pad));
		rygel_http_response_end ((RygelHTTPResponse*) self, FALSE, (guint) SOUP_STATUS_NONE);
		_gst_caps_unref0 (caps);
		_gst_object_unref0 (sink);
		_gst_object_unref0 (sink_pad);
		_gst_object_unref0 (depay);
		return;
	}
	if (depay != NULL) {
		gst_element_sync_state_with_parent (depay);
	}
	_gst_caps_unref0 (caps);
	_gst_object_unref0 (sink);
	_gst_object_unref0 (sink_pad);
	_gst_object_unref0 (depay);
}


static gpointer _gst_structure_copy0 (gpointer self) {
	return self ? gst_structure_copy (self) : NULL;
}


static gboolean rygel_live_response_need_rtp_depayloader (RygelLiveResponse* self, GstCaps* caps) {
	gboolean result;
	GstStructure* structure;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (caps != NULL, FALSE);
	structure = _gst_structure_copy0 (gst_caps_get_structure (caps, (guint) 0));
	result = _vala_strcmp0 (gst_structure_get_name (structure), "application/x-rtp") == 0;
	_gst_structure_free0 (structure);
	return result;
}


static gboolean _rygel_live_response_rtp_depay_filter_gst_plugin_feature_filter (GstPluginFeature* feature, gpointer self) {
	return rygel_live_response_rtp_depay_filter (self, feature);
}


static void _g_list_free_gst_object_unref (GList* self) {
	g_list_foreach (self, (GFunc) gst_object_unref, NULL);
	g_list_free (self);
}


static GstElement* rygel_live_response_get_rtp_depayloader (RygelLiveResponse* self, GstCaps* caps) {
	GstElement* result;
	GstRegistry* registry;
	GList* features;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (caps != NULL, NULL);
	if (!rygel_live_response_need_rtp_depayloader (self, caps)) {
		result = NULL;
		return result;
	}
	registry = gst_registry_get_default ();
	features = gst_registry_feature_filter (registry, _rygel_live_response_rtp_depay_filter_gst_plugin_feature_filter, FALSE, self);
	result = rygel_live_response_get_best_depay (self, features, caps);
	__g_list_free_gst_object_unref0 (features);
	return result;
}


static gint _rygel_live_response_compare_factories_gcompare_func (void* a, void* b) {
	return rygel_live_response_compare_factories (a, b);
}


static GstElement* rygel_live_response_get_best_depay (RygelLiveResponse* self, GList* features, GstCaps* caps) {
	GstElement* result;
	GList* relevant_factories;
	GstElementFactory* factory;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (caps != NULL, NULL);
	relevant_factories = NULL;
	{
		GList* feature_collection;
		GList* feature_it;
		feature_collection = features;
		for (feature_it = feature_collection; feature_it != NULL; feature_it = feature_it->next) {
			GstPluginFeature* feature;
			feature = _gst_object_ref0 ((GstPluginFeature*) feature_it->data);
			{
				GstElementFactory* factory;
				factory = _gst_object_ref0 (GST_ELEMENT_FACTORY (feature));
				if (gst_element_factory_can_sink_caps (factory, caps)) {
					relevant_factories = g_list_append (relevant_factories, _gst_object_ref0 (factory));
				}
				_gst_object_unref0 (feature);
				_gst_object_unref0 (factory);
			}
		}
	}
	if (g_list_length (relevant_factories) == 0) {
		result = NULL;
		__g_list_free_gst_object_unref0 (relevant_factories);
		return result;
	}
	relevant_factories = g_list_sort (relevant_factories, _rygel_live_response_compare_factories_gcompare_func);
	factory = _gst_object_ref0 ((GstElementFactory*) relevant_factories->data);
	result = gst_element_factory_make (gst_plugin_feature_get_name ((GstPluginFeature*) factory), NULL);
	__g_list_free_gst_object_unref0 (relevant_factories);
	_gst_object_unref0 (factory);
	return result;
}


static gboolean string_contains (const char* self, const char* needle) {
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (needle != NULL, FALSE);
	result = strstr (self, needle) != NULL;
	return result;
}


static gboolean rygel_live_response_rtp_depay_filter (RygelLiveResponse* self, GstPluginFeature* feature) {
	gboolean result;
	GstElementFactory* factory;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (feature != NULL, FALSE);
	if (!g_type_is_a (G_TYPE_FROM_INSTANCE ((GObject*) feature), GST_TYPE_ELEMENT_FACTORY)) {
		result = FALSE;
		return result;
	}
	factory = _gst_object_ref0 (GST_ELEMENT_FACTORY (feature));
	result = string_contains (gst_element_factory_get_klass (factory), "Depayloader");
	_gst_object_unref0 (factory);
	return result;
}


static gint rygel_live_response_compare_factories (void* a, void* b) {
	gint result;
	GstElementFactory* factory_a;
	GstElementFactory* factory_b;
	factory_a = _gst_object_ref0 (GST_ELEMENT_FACTORY (a));
	factory_b = _gst_object_ref0 (GST_ELEMENT_FACTORY (b));
	result = (gint) (gst_plugin_feature_get_rank ((GstPluginFeature*) factory_b) - gst_plugin_feature_get_rank ((GstPluginFeature*) factory_a));
	_gst_object_unref0 (factory_a);
	_gst_object_unref0 (factory_b);
	return result;
}


static gpointer _gst_buffer_ref0 (gpointer self) {
	return self ? gst_buffer_ref (self) : NULL;
}


static gboolean _rygel_live_response_idle_handler_gsource_func (gpointer self) {
	return rygel_live_response_idle_handler (self);
}


static void rygel_live_response_on_new_buffer (RygelLiveResponse* self, GstElement* sink, GstBuffer* buffer, GstPad* pad) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (sink != NULL);
	g_return_if_fail (buffer != NULL);
	g_return_if_fail (pad != NULL);
	g_async_queue_push (self->priv->buffers, _gst_buffer_ref0 (buffer));
	g_idle_add_full (G_PRIORITY_HIGH_IDLE, _rygel_live_response_idle_handler_gsource_func, g_object_ref (self), g_object_unref);
}


static gboolean rygel_live_response_idle_handler (RygelLiveResponse* self) {
	gboolean result;
	GstBuffer* buffer;
	g_return_val_if_fail (self != NULL, FALSE);
	buffer = (GstBuffer*) g_async_queue_try_pop (self->priv->buffers);
	if (buffer != NULL) {
		rygel_http_response_push_data ((RygelHTTPResponse*) self, buffer->data, (gsize) buffer->size);
	}
	result = FALSE;
	_gst_buffer_unref0 (buffer);
	return result;
}


static gboolean rygel_live_response_bus_handler (RygelLiveResponse* self, GstBus* bus, GstMessage* message) {
	gboolean result;
	gboolean ret;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (bus != NULL, FALSE);
	g_return_val_if_fail (message != NULL, FALSE);
	ret = TRUE;
	if (message->type == GST_MESSAGE_EOS) {
		ret = FALSE;
	} else {
		if (message->type == GST_MESSAGE_STATE_CHANGED) {
			gboolean _tmp0_;
			if (message->src != GST_OBJECT (self->priv->pipeline)) {
				result = TRUE;
				return result;
			}
			_tmp0_ = FALSE;
			if (self->priv->time_range != NULL) {
				_tmp0_ = rygel_http_seek_get_start (self->priv->time_range) > 0;
			} else {
				_tmp0_ = FALSE;
			}
			if (_tmp0_) {
				GstState old_state;
				GstState new_state;
				gboolean _tmp1_;
				old_state = 0;
				new_state = 0;
				gst_message_parse_state_changed (message, &old_state, &new_state, NULL);
				_tmp1_ = FALSE;
				if (old_state == GST_STATE_READY) {
					_tmp1_ = new_state == GST_STATE_PAUSED;
				} else {
					_tmp1_ = FALSE;
				}
				if (_tmp1_) {
					if (rygel_live_response_seek (self)) {
						gst_element_set_state ((GstElement*) self->priv->pipeline, GST_STATE_PLAYING);
					}
				}
			}
		} else {
			GError* err;
			char* err_msg;
			err = NULL;
			err_msg = NULL;
			if (message->type == GST_MESSAGE_ERROR) {
				char* _tmp5_;
				char* _tmp4_;
				GError* _tmp3_;
				GError* _tmp2_;
				_tmp4_ = NULL;
				_tmp2_ = NULL;
				(gst_message_parse_error (message, &_tmp2_, &_tmp4_), err = (_tmp3_ = _tmp2_, _g_error_free0 (err), _tmp3_));
				err_msg = (_tmp5_ = _tmp4_, _g_free0 (err_msg), _tmp5_);
				g_critical ("rygel-live-response.vala:262: Error from pipeline %s:%s", gst_object_get_name ((GstObject*) self->priv->pipeline), err_msg);
				ret = FALSE;
			} else {
				if (message->type == GST_MESSAGE_WARNING) {
					char* _tmp9_;
					char* _tmp8_;
					GError* _tmp7_;
					GError* _tmp6_;
					_tmp8_ = NULL;
					_tmp6_ = NULL;
					(gst_message_parse_warning (message, &_tmp6_, &_tmp8_), err = (_tmp7_ = _tmp6_, _g_error_free0 (err), _tmp7_));
					err_msg = (_tmp9_ = _tmp8_, _g_free0 (err_msg), _tmp9_);
					g_warning ("rygel-live-response.vala:269: Warning from pipeline %s:%s", gst_object_get_name ((GstObject*) self->priv->pipeline), err_msg);
				}
			}
			_g_error_free0 (err);
			_g_free0 (err_msg);
		}
	}
	if (!ret) {
		rygel_http_response_end ((RygelHTTPResponse*) self, FALSE, (guint) SOUP_STATUS_NONE);
	}
	result = ret;
	return result;
}


static gboolean rygel_live_response_seek (RygelLiveResponse* self) {
	gboolean result;
	GstSeekType stop_type;
	g_return_val_if_fail (self != NULL, FALSE);
	stop_type = 0;
	if (rygel_http_seek_get_stop (self->priv->time_range) > 0) {
		stop_type = GST_SEEK_TYPE_SET;
	} else {
		stop_type = GST_SEEK_TYPE_NONE;
	}
	if (!gst_element_seek ((GstElement*) self->priv->pipeline, 1.0, GST_FORMAT_TIME, GST_SEEK_FLAG_FLUSH, GST_SEEK_TYPE_SET, rygel_http_seek_get_start (self->priv->time_range), stop_type, rygel_http_seek_get_stop (self->priv->time_range))) {
		g_warning ("rygel-live-response.vala:298: Failed to seek to offset %lld", rygel_http_seek_get_start (self->priv->time_range));
		rygel_http_response_end ((RygelHTTPResponse*) self, FALSE, (guint) SOUP_STATUS_REQUESTED_RANGE_NOT_SATISFIABLE);
		result = FALSE;
		return result;
	}
	result = TRUE;
	return result;
}


static void rygel_live_response_class_init (RygelLiveResponseClass * klass) {
	rygel_live_response_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelLiveResponsePrivate));
	RYGEL_HTTP_RESPONSE_CLASS (klass)->run = rygel_live_response_real_run;
	RYGEL_HTTP_RESPONSE_CLASS (klass)->end = rygel_live_response_real_end;
	G_OBJECT_CLASS (klass)->finalize = rygel_live_response_finalize;
}


static void rygel_live_response_instance_init (RygelLiveResponse * self) {
	self->priv = RYGEL_LIVE_RESPONSE_GET_PRIVATE (self);
}


static void rygel_live_response_finalize (GObject* obj) {
	RygelLiveResponse * self;
	self = RYGEL_LIVE_RESPONSE (obj);
	_gst_object_unref0 (self->priv->pipeline);
	_g_async_queue_unref0 (self->priv->buffers);
	_g_object_unref0 (self->priv->time_range);
	G_OBJECT_CLASS (rygel_live_response_parent_class)->finalize (obj);
}


GType rygel_live_response_get_type (void) {
	static GType rygel_live_response_type_id = 0;
	if (rygel_live_response_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelLiveResponseClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_live_response_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelLiveResponse), 0, (GInstanceInitFunc) rygel_live_response_instance_init, NULL };
		rygel_live_response_type_id = g_type_register_static (RYGEL_TYPE_HTTP_RESPONSE, "RygelLiveResponse", &g_define_type_info, 0);
	}
	return rygel_live_response_type_id;
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



static void g_cclosure_user_marshal_VOID__POINTER_OBJECT (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data) {
	typedef void (*GMarshalFunc_VOID__POINTER_OBJECT) (gpointer data1, gpointer arg_1, gpointer arg_2, gpointer data2);
	register GMarshalFunc_VOID__POINTER_OBJECT callback;
	register GCClosure * cc;
	register gpointer data1, data2;
	cc = (GCClosure *) closure;
	g_return_if_fail (n_param_values == 3);
	if (G_CCLOSURE_SWAP_DATA (closure)) {
		data1 = closure->data;
		data2 = param_values->data[0].v_pointer;
	} else {
		data1 = param_values->data[0].v_pointer;
		data2 = closure->data;
	}
	callback = (GMarshalFunc_VOID__POINTER_OBJECT) (marshal_data ? marshal_data : cc->callback);
	callback (data1, gst_value_get_mini_object (param_values + 1), g_value_get_object (param_values + 2), data2);
}



