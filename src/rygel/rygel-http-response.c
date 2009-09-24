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

struct _RygelHTTPResponsePrivate {
	SoupServer* _server;
	GCancellable* _cancellable;
};


static gpointer rygel_http_response_parent_class = NULL;
static RygelStateMachineIface* rygel_http_response_rygel_state_machine_parent_iface = NULL;

GType rygel_state_machine_get_type (void);
GType rygel_http_response_get_type (void);
#define RYGEL_HTTP_RESPONSE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_HTTP_RESPONSE, RygelHTTPResponsePrivate))
enum  {
	RYGEL_HTTP_RESPONSE_DUMMY_PROPERTY,
	RYGEL_HTTP_RESPONSE_SERVER,
	RYGEL_HTTP_RESPONSE_CANCELLABLE
};
static void rygel_http_response_set_server (RygelHTTPResponse* self, SoupServer* value);
void rygel_state_machine_set_cancellable (RygelStateMachine* self, GCancellable* value);
static void rygel_http_response_on_request_aborted (RygelHTTPResponse* self, SoupServer* server, SoupMessage* msg, SoupClientContext* client);
static void _rygel_http_response_on_request_aborted_soup_server_request_aborted (SoupServer* _sender, SoupMessage* msg, SoupClientContext* client, gpointer self);
SoupServer* rygel_http_response_get_server (RygelHTTPResponse* self);
RygelHTTPResponse* rygel_http_response_construct (GType object_type, SoupServer* server, SoupMessage* msg, gboolean partial, GCancellable* cancellable);
GCancellable* rygel_state_machine_get_cancellable (RygelStateMachine* self);
static void rygel_http_response_on_cancelled (RygelHTTPResponse* self, GCancellable* cancellable);
static void _rygel_http_response_on_cancelled_g_cancellable_cancelled (GCancellable* _sender, gpointer self);
void rygel_http_response_run (RygelHTTPResponse* self);
static void rygel_http_response_real_run (RygelHTTPResponse* self);
void rygel_http_response_end (RygelHTTPResponse* self, gboolean aborted, guint status);
void rygel_http_response_push_data (RygelHTTPResponse* self, void* data, gsize length);
static void rygel_http_response_real_end (RygelHTTPResponse* self, gboolean aborted, guint status);
static void rygel_http_response_finalize (GObject* obj);
static void rygel_http_response_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void rygel_http_response_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _rygel_http_response_on_request_aborted_soup_server_request_aborted (SoupServer* _sender, SoupMessage* msg, SoupClientContext* client, gpointer self) {
	rygel_http_response_on_request_aborted (self, _sender, msg, client);
}


RygelHTTPResponse* rygel_http_response_construct (GType object_type, SoupServer* server, SoupMessage* msg, gboolean partial, GCancellable* cancellable) {
	RygelHTTPResponse * self;
	SoupMessage* _tmp0_;
	g_return_val_if_fail (server != NULL, NULL);
	g_return_val_if_fail (msg != NULL, NULL);
	self = (RygelHTTPResponse*) g_object_new (object_type, NULL);
	rygel_http_response_set_server (self, server);
	self->msg = (_tmp0_ = _g_object_ref0 (msg), _g_object_unref0 (self->msg), _tmp0_);
	rygel_state_machine_set_cancellable ((RygelStateMachine*) self, cancellable);
	if (partial) {
		soup_message_set_status (self->msg, (guint) SOUP_STATUS_PARTIAL_CONTENT);
	} else {
		soup_message_set_status (self->msg, (guint) SOUP_STATUS_OK);
	}
	soup_message_body_set_accumulate (self->msg->response_body, FALSE);
	g_signal_connect_object (self->priv->_server, "request-aborted", (GCallback) _rygel_http_response_on_request_aborted_soup_server_request_aborted, self, 0);
	return self;
}


static void _rygel_http_response_on_cancelled_g_cancellable_cancelled (GCancellable* _sender, gpointer self) {
	rygel_http_response_on_cancelled (self, _sender);
}


static void rygel_http_response_real_run (RygelHTTPResponse* self) {
	g_return_if_fail (self != NULL);
	if (rygel_state_machine_get_cancellable ((RygelStateMachine*) self) != NULL) {
		g_signal_connect_object (rygel_state_machine_get_cancellable ((RygelStateMachine*) self), "cancelled", (GCallback) _rygel_http_response_on_cancelled_g_cancellable_cancelled, self, 0);
	}
}


void rygel_http_response_run (RygelHTTPResponse* self) {
	RYGEL_HTTP_RESPONSE_GET_CLASS (self)->run (self);
}


static void rygel_http_response_on_cancelled (RygelHTTPResponse* self, GCancellable* cancellable) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (cancellable != NULL);
	rygel_http_response_end (self, TRUE, (guint) SOUP_STATUS_CANCELLED);
}


static void rygel_http_response_on_request_aborted (RygelHTTPResponse* self, SoupServer* server, SoupMessage* msg, SoupClientContext* client) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (server != NULL);
	g_return_if_fail (msg != NULL);
	g_return_if_fail (client != NULL);
	if (msg == self->msg) {
		rygel_http_response_end (self, TRUE, (guint) SOUP_STATUS_NONE);
	}
}


void rygel_http_response_push_data (RygelHTTPResponse* self, void* data, gsize length) {
	g_return_if_fail (self != NULL);
	soup_message_body_append (self->msg->response_body, SOUP_MEMORY_COPY, data, length);
	soup_server_unpause_message (self->priv->_server, self->msg);
}


static void rygel_http_response_real_end (RygelHTTPResponse* self, gboolean aborted, guint status) {
	g_return_if_fail (self != NULL);
	if (status != SOUP_STATUS_NONE) {
		soup_message_set_status (self->msg, status);
	}
	g_signal_emit_by_name ((RygelStateMachine*) self, "completed");
}


void rygel_http_response_end (RygelHTTPResponse* self, gboolean aborted, guint status) {
	RYGEL_HTTP_RESPONSE_GET_CLASS (self)->end (self, aborted, status);
}


SoupServer* rygel_http_response_get_server (RygelHTTPResponse* self) {
	SoupServer* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_server;
	return result;
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
	return result;
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
	RYGEL_HTTP_RESPONSE_CLASS (klass)->run = rygel_http_response_real_run;
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
	G_OBJECT_CLASS (rygel_http_response_parent_class)->finalize (obj);
}


GType rygel_http_response_get_type (void) {
	static GType rygel_http_response_type_id = 0;
	if (rygel_http_response_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelHTTPResponseClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_http_response_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelHTTPResponse), 0, (GInstanceInitFunc) rygel_http_response_instance_init, NULL };
		static const GInterfaceInfo rygel_state_machine_info = { (GInterfaceInitFunc) rygel_http_response_rygel_state_machine_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		rygel_http_response_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelHTTPResponse", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_type_add_interface_static (rygel_http_response_type_id, RYGEL_TYPE_STATE_MACHINE, &rygel_state_machine_info);
	}
	return rygel_http_response_type_id;
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




