/* rygel-http-response_seekable-response.c generated by valac, the Vala compiler
 * generated from rygel-http-response_seekable-response.vala, do not modify */

/*
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
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _RygelStateMachineIface {
	GTypeInterface parent_iface;
	void (*run) (RygelStateMachine* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
	void (*run_finish) (RygelStateMachine* self, GAsyncResult* _res_);
	GCancellable* (*get_cancellable) (RygelStateMachine* self);
	void (*set_cancellable) (RygelStateMachine* self, GCancellable* value);
};

struct _RygelHTTPResponse {
	GObject parent_instance;
	RygelHTTPResponsePrivate * priv;
	SoupMessage* msg;
	GSourceFunc run_continue;
	gpointer run_continue_target;
	GDestroyNotify run_continue_target_destroy_notify;
};

struct _RygelHTTPResponseClass {
	GObjectClass parent_class;
	void (*run) (RygelHTTPResponse* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
	void (*run_finish) (RygelHTTPResponse* self, GAsyncResult* _res_);
	void (*end) (RygelHTTPResponse* self, gboolean aborted, guint status);
};

struct _RygelHTTPResponsePrivate {
	SoupServer* _server;
	GCancellable* _cancellable;
};


static gpointer rygel_http_response_parent_class = NULL;
static RygelStateMachineIface* rygel_http_response_rygel_state_machine_parent_iface = NULL;

GType rygel_state_machine_get_type (void) G_GNUC_CONST;
GType rygel_http_response_get_type (void) G_GNUC_CONST;
#define RYGEL_HTTP_RESPONSE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_HTTP_RESPONSE, RygelHTTPResponsePrivate))
enum  {
	RYGEL_HTTP_RESPONSE_DUMMY_PROPERTY,
	RYGEL_HTTP_RESPONSE_SERVER,
	RYGEL_HTTP_RESPONSE_CANCELLABLE
};
static void rygel_http_response_set_server (RygelHTTPResponse* self, SoupServer* value);
void rygel_state_machine_set_cancellable (RygelStateMachine* self, GCancellable* value);
GCancellable* rygel_state_machine_get_cancellable (RygelStateMachine* self);
static void rygel_http_response_on_cancelled (RygelHTTPResponse* self, GCancellable* cancellable);
static void _rygel_http_response_on_cancelled_g_cancellable_cancelled (GCancellable* _sender, gpointer self);
RygelHTTPResponse* rygel_http_response_construct (GType object_type, SoupServer* server, SoupMessage* msg, gboolean partial, GCancellable* cancellable);
void rygel_http_response_run (RygelHTTPResponse* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
void rygel_http_response_run_finish (RygelHTTPResponse* self, GAsyncResult* _res_);
void rygel_http_response_end (RygelHTTPResponse* self, gboolean aborted, guint status);
SoupServer* rygel_http_response_get_server (RygelHTTPResponse* self);
void rygel_http_response_push_data (RygelHTTPResponse* self, void* data, gsize length);
static void rygel_http_response_real_end (RygelHTTPResponse* self, gboolean aborted, guint status);
static void rygel_http_response_finalize (GObject* obj);
static void rygel_http_response_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void rygel_http_response_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


#line 57 "rygel-http-response_seekable-response.vala"
static void _rygel_http_response_on_cancelled_g_cancellable_cancelled (GCancellable* _sender, gpointer self) {
#line 120 "rygel-http-response_seekable-response.c"
	rygel_http_response_on_cancelled (self, _sender);
}


#line 34 "rygel-http-response_seekable-response.vala"
RygelHTTPResponse* rygel_http_response_construct (GType object_type, SoupServer* server, SoupMessage* msg, gboolean partial, GCancellable* cancellable) {
#line 127 "rygel-http-response_seekable-response.c"
	RygelHTTPResponse * self;
	SoupMessage* _tmp0_;
#line 34 "rygel-http-response_seekable-response.vala"
	g_return_val_if_fail (server != NULL, NULL);
#line 34 "rygel-http-response_seekable-response.vala"
	g_return_val_if_fail (msg != NULL, NULL);
#line 34 "rygel-http-response_seekable-response.vala"
	self = (RygelHTTPResponse*) g_object_new (object_type, NULL);
#line 38 "rygel-http-response_seekable-response.vala"
	rygel_http_response_set_server (self, server);
#line 39 "rygel-http-response_seekable-response.vala"
	self->msg = (_tmp0_ = _g_object_ref0 (msg), _g_object_unref0 (self->msg), _tmp0_);
#line 40 "rygel-http-response_seekable-response.vala"
	rygel_state_machine_set_cancellable ((RygelStateMachine*) self, cancellable);
#line 42 "rygel-http-response_seekable-response.vala"
	if (partial) {
#line 43 "rygel-http-response_seekable-response.vala"
		soup_message_set_status (self->msg, (guint) SOUP_STATUS_PARTIAL_CONTENT);
#line 146 "rygel-http-response_seekable-response.c"
	} else {
#line 45 "rygel-http-response_seekable-response.vala"
		soup_message_set_status (self->msg, (guint) SOUP_STATUS_OK);
#line 150 "rygel-http-response_seekable-response.c"
	}
#line 48 "rygel-http-response_seekable-response.vala"
	soup_message_body_set_accumulate (self->msg->response_body, FALSE);
#line 50 "rygel-http-response_seekable-response.vala"
	if (rygel_state_machine_get_cancellable ((RygelStateMachine*) self) != NULL) {
#line 51 "rygel-http-response_seekable-response.vala"
		g_signal_connect_object (rygel_state_machine_get_cancellable ((RygelStateMachine*) self), "cancelled", (GCallback) _rygel_http_response_on_cancelled_g_cancellable_cancelled, self, 0);
#line 158 "rygel-http-response_seekable-response.c"
	}
	return self;
}


#line 34 "rygel-http-response_seekable-response.vala"
void rygel_http_response_run (RygelHTTPResponse* self, GAsyncReadyCallback _callback_, gpointer _user_data_) {
#line 34 "rygel-http-response_seekable-response.vala"
	RYGEL_HTTP_RESPONSE_GET_CLASS (self)->run (self, _callback_, _user_data_);
#line 168 "rygel-http-response_seekable-response.c"
}


#line 34 "rygel-http-response_seekable-response.vala"
void rygel_http_response_run_finish (RygelHTTPResponse* self, GAsyncResult* _res_) {
#line 34 "rygel-http-response_seekable-response.vala"
	RYGEL_HTTP_RESPONSE_GET_CLASS (self)->run_finish (self, _res_);
#line 176 "rygel-http-response_seekable-response.c"
}


#line 57 "rygel-http-response_seekable-response.vala"
static void rygel_http_response_on_cancelled (RygelHTTPResponse* self, GCancellable* cancellable) {
#line 57 "rygel-http-response_seekable-response.vala"
	g_return_if_fail (self != NULL);
#line 57 "rygel-http-response_seekable-response.vala"
	g_return_if_fail (cancellable != NULL);
#line 58 "rygel-http-response_seekable-response.vala"
	rygel_http_response_end (self, TRUE, (guint) SOUP_STATUS_CANCELLED);
#line 188 "rygel-http-response_seekable-response.c"
}


#line 61 "rygel-http-response_seekable-response.vala"
void rygel_http_response_push_data (RygelHTTPResponse* self, void* data, gsize length) {
#line 61 "rygel-http-response_seekable-response.vala"
	g_return_if_fail (self != NULL);
#line 62 "rygel-http-response_seekable-response.vala"
	soup_message_body_append (self->msg->response_body, SOUP_MEMORY_COPY, data, length);
#line 66 "rygel-http-response_seekable-response.vala"
	soup_server_unpause_message (self->priv->_server, self->msg);
#line 200 "rygel-http-response_seekable-response.c"
}


#line 69 "rygel-http-response_seekable-response.vala"
static void rygel_http_response_real_end (RygelHTTPResponse* self, gboolean aborted, guint status) {
#line 69 "rygel-http-response_seekable-response.vala"
	g_return_if_fail (self != NULL);
#line 70 "rygel-http-response_seekable-response.vala"
	if (self->run_continue != NULL) {
#line 71 "rygel-http-response_seekable-response.vala"
		self->run_continue (self->run_continue_target);
#line 212 "rygel-http-response_seekable-response.c"
	}
#line 74 "rygel-http-response_seekable-response.vala"
	if (status != SOUP_STATUS_NONE) {
#line 75 "rygel-http-response_seekable-response.vala"
		soup_message_set_status (self->msg, status);
#line 218 "rygel-http-response_seekable-response.c"
	}
#line 78 "rygel-http-response_seekable-response.vala"
	g_signal_emit_by_name ((RygelStateMachine*) self, "completed");
#line 222 "rygel-http-response_seekable-response.c"
}


#line 69 "rygel-http-response_seekable-response.vala"
void rygel_http_response_end (RygelHTTPResponse* self, gboolean aborted, guint status) {
#line 69 "rygel-http-response_seekable-response.vala"
	RYGEL_HTTP_RESPONSE_GET_CLASS (self)->end (self, aborted, status);
#line 230 "rygel-http-response_seekable-response.c"
}


SoupServer* rygel_http_response_get_server (RygelHTTPResponse* self) {
	SoupServer* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_server;
#line 27 "rygel-http-response_seekable-response.vala"
	return result;
#line 240 "rygel-http-response_seekable-response.c"
}


static void rygel_http_response_set_server (RygelHTTPResponse* self, SoupServer* value) {
	SoupServer* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_server = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_server), _tmp0_);
	g_object_notify ((GObject *) self, "server");
}


static GCancellable* rygel_http_response_real_get_cancellable (RygelStateMachine* base) {
	GCancellable* result;
	RygelHTTPResponse* self;
	self = (RygelHTTPResponse*) base;
	result = self->priv->_cancellable;
#line 30 "rygel-http-response_seekable-response.vala"
	return result;
#line 259 "rygel-http-response_seekable-response.c"
}


static void rygel_http_response_real_set_cancellable (RygelStateMachine* base, GCancellable* value) {
	RygelHTTPResponse* self;
	GCancellable* _tmp0_;
	self = (RygelHTTPResponse*) base;
	self->priv->_cancellable = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_cancellable), _tmp0_);
	g_object_notify ((GObject *) self, "cancellable");
}


static void rygel_http_response_class_init (RygelHTTPResponseClass * klass) {
	rygel_http_response_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelHTTPResponsePrivate));
	RYGEL_HTTP_RESPONSE_CLASS (klass)->end = rygel_http_response_real_end;
	G_OBJECT_CLASS (klass)->get_property = rygel_http_response_get_property;
	G_OBJECT_CLASS (klass)->set_property = rygel_http_response_set_property;
	G_OBJECT_CLASS (klass)->finalize = rygel_http_response_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), RYGEL_HTTP_RESPONSE_SERVER, g_param_spec_object ("server", "server", "server", SOUP_TYPE_SERVER, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	g_object_class_override_property (G_OBJECT_CLASS (klass), RYGEL_HTTP_RESPONSE_CANCELLABLE, "cancellable");
}


static void rygel_http_response_rygel_state_machine_interface_init (RygelStateMachineIface * iface) {
	rygel_http_response_rygel_state_machine_parent_iface = g_type_interface_peek_parent (iface);
	iface->run = (void (*)(RygelStateMachine*)) rygel_http_response_run;
	iface->run_finish = rygel_http_response_run_finish;
	iface->get_cancellable = rygel_http_response_real_get_cancellable;
	iface->set_cancellable = rygel_http_response_real_set_cancellable;
}


static void rygel_http_response_instance_init (RygelHTTPResponse * self) {
	self->priv = RYGEL_HTTP_RESPONSE_GET_PRIVATE (self);
}


static void rygel_http_response_finalize (GObject* obj) {
	RygelHTTPResponse * self;
	self = RYGEL_HTTP_RESPONSE (obj);
	_g_object_unref0 (self->priv->_server);
	_g_object_unref0 (self->msg);
	_g_object_unref0 (self->priv->_cancellable);
	(self->run_continue_target_destroy_notify == NULL) ? NULL : (self->run_continue_target_destroy_notify (self->run_continue_target), NULL);
	self->run_continue = NULL;
	self->run_continue_target = NULL;
	self->run_continue_target_destroy_notify = NULL;
	G_OBJECT_CLASS (rygel_http_response_parent_class)->finalize (obj);
}


GType rygel_http_response_get_type (void) {
	static volatile gsize rygel_http_response_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_http_response_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelHTTPResponseClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_http_response_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelHTTPResponse), 0, (GInstanceInitFunc) rygel_http_response_instance_init, NULL };
		static const GInterfaceInfo rygel_state_machine_info = { (GInterfaceInitFunc) rygel_http_response_rygel_state_machine_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType rygel_http_response_type_id;
		rygel_http_response_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelHTTPResponse", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_type_add_interface_static (rygel_http_response_type_id, RYGEL_TYPE_STATE_MACHINE, &rygel_state_machine_info);
		g_once_init_leave (&rygel_http_response_type_id__volatile, rygel_http_response_type_id);
	}
	return rygel_http_response_type_id__volatile;
}


static void rygel_http_response_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	RygelHTTPResponse * self;
	self = RYGEL_HTTP_RESPONSE (object);
	switch (property_id) {
		case RYGEL_HTTP_RESPONSE_SERVER:
		g_value_set_object (value, rygel_http_response_get_server (self));
		break;
		case RYGEL_HTTP_RESPONSE_CANCELLABLE:
		g_value_set_object (value, rygel_state_machine_get_cancellable ((RygelStateMachine*) self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void rygel_http_response_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	RygelHTTPResponse * self;
	self = RYGEL_HTTP_RESPONSE (object);
	switch (property_id) {
		case RYGEL_HTTP_RESPONSE_SERVER:
		rygel_http_response_set_server (self, g_value_get_object (value));
		break;
		case RYGEL_HTTP_RESPONSE_CANCELLABLE:
		rygel_state_machine_set_cancellable ((RygelStateMachine*) self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




