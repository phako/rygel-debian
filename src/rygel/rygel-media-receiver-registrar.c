/* rygel-media-receiver-registrar.c generated by valac, the Vala compiler
 * generated from rygel-media-receiver-registrar.vala, do not modify */

/*
 * Copyright (C) 2008 Zeeshan Ali <zeenix@gmail.com>.
 *
 * Author: Zeeshan Ali <zeenix@gmail.com>
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
#include <libgupnp/gupnp.h>
#include <stdlib.h>
#include <string.h>


#define RYGEL_TYPE_MEDIA_RECEIVER_REGISTRAR (rygel_media_receiver_registrar_get_type ())
#define RYGEL_MEDIA_RECEIVER_REGISTRAR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_RECEIVER_REGISTRAR, RygelMediaReceiverRegistrar))
#define RYGEL_MEDIA_RECEIVER_REGISTRAR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_RECEIVER_REGISTRAR, RygelMediaReceiverRegistrarClass))
#define RYGEL_IS_MEDIA_RECEIVER_REGISTRAR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_RECEIVER_REGISTRAR))
#define RYGEL_IS_MEDIA_RECEIVER_REGISTRAR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_RECEIVER_REGISTRAR))
#define RYGEL_MEDIA_RECEIVER_REGISTRAR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_RECEIVER_REGISTRAR, RygelMediaReceiverRegistrarClass))

typedef struct _RygelMediaReceiverRegistrar RygelMediaReceiverRegistrar;
typedef struct _RygelMediaReceiverRegistrarClass RygelMediaReceiverRegistrarClass;
typedef struct _RygelMediaReceiverRegistrarPrivate RygelMediaReceiverRegistrarPrivate;

struct _RygelMediaReceiverRegistrar {
	GUPnPService parent_instance;
	RygelMediaReceiverRegistrarPrivate * priv;
};

struct _RygelMediaReceiverRegistrarClass {
	GUPnPServiceClass parent_class;
};


static gpointer rygel_media_receiver_registrar_parent_class = NULL;

GType rygel_media_receiver_registrar_get_type (void) G_GNUC_CONST;
enum  {
	RYGEL_MEDIA_RECEIVER_REGISTRAR_DUMMY_PROPERTY
};
#define RYGEL_MEDIA_RECEIVER_REGISTRAR_UPNP_ID "urn:microsoft.com:serviceId:X_MS_MediaReceiverRegistrar"
#define RYGEL_MEDIA_RECEIVER_REGISTRAR_UPNP_TYPE "urn:microsoft.com:service:X_MS_MediaReceiverRegistrar:1"
#define RYGEL_MEDIA_RECEIVER_REGISTRAR_DESCRIPTION_PATH "xml/X_MS_MediaReceiverRegistrar1.xml"
static void rygel_media_receiver_registrar_is_authorized_cb (RygelMediaReceiverRegistrar* self, GUPnPService* registrar, GUPnPServiceAction* action);
static void _rygel_media_receiver_registrar_is_authorized_cb_gupnp_service_action_invoked (GUPnPService* _sender, GUPnPServiceAction* action, gpointer self);
static void rygel_media_receiver_registrar_register_device_cb (RygelMediaReceiverRegistrar* self, GUPnPService* registrar, GUPnPServiceAction* action);
static void _rygel_media_receiver_registrar_register_device_cb_gupnp_service_action_invoked (GUPnPService* _sender, GUPnPServiceAction* action, gpointer self);
static void rygel_media_receiver_registrar_real_constructed (GObject* base);
RygelMediaReceiverRegistrar* rygel_media_receiver_registrar_new (void);
RygelMediaReceiverRegistrar* rygel_media_receiver_registrar_construct (GType object_type);



#line 43 "rygel-media-receiver-registrar.vala"
static void _rygel_media_receiver_registrar_is_authorized_cb_gupnp_service_action_invoked (GUPnPService* _sender, GUPnPServiceAction* action, gpointer self) {
#line 76 "rygel-media-receiver-registrar.c"
	rygel_media_receiver_registrar_is_authorized_cb (self, _sender, action);
}


#line 50 "rygel-media-receiver-registrar.vala"
static void _rygel_media_receiver_registrar_register_device_cb_gupnp_service_action_invoked (GUPnPService* _sender, GUPnPServiceAction* action, gpointer self) {
#line 83 "rygel-media-receiver-registrar.c"
	rygel_media_receiver_registrar_register_device_cb (self, _sender, action);
}


#line 36 "rygel-media-receiver-registrar.vala"
static void rygel_media_receiver_registrar_real_constructed (GObject* base) {
#line 90 "rygel-media-receiver-registrar.c"
	RygelMediaReceiverRegistrar * self;
	self = (RygelMediaReceiverRegistrar*) base;
#line 37 "rygel-media-receiver-registrar.vala"
	g_signal_connect_object ((GUPnPService*) self, "action-invoked::IsAuthorized", (GCallback) _rygel_media_receiver_registrar_is_authorized_cb_gupnp_service_action_invoked, self, 0);
#line 38 "rygel-media-receiver-registrar.vala"
	g_signal_connect_object ((GUPnPService*) self, "action-invoked::IsValidated", (GCallback) _rygel_media_receiver_registrar_is_authorized_cb_gupnp_service_action_invoked, self, 0);
#line 39 "rygel-media-receiver-registrar.vala"
	g_signal_connect_object ((GUPnPService*) self, "action-invoked::RegisterDevice", (GCallback) _rygel_media_receiver_registrar_register_device_cb_gupnp_service_action_invoked, self, 0);
#line 99 "rygel-media-receiver-registrar.c"
}


#line 43 "rygel-media-receiver-registrar.vala"
static void rygel_media_receiver_registrar_is_authorized_cb (RygelMediaReceiverRegistrar* self, GUPnPService* registrar, GUPnPServiceAction* action) {
#line 43 "rygel-media-receiver-registrar.vala"
	g_return_if_fail (self != NULL);
#line 43 "rygel-media-receiver-registrar.vala"
	g_return_if_fail (registrar != NULL);
#line 43 "rygel-media-receiver-registrar.vala"
	g_return_if_fail (action != NULL);
#line 45 "rygel-media-receiver-registrar.vala"
	gupnp_service_action_set (action, "Result", G_TYPE_INT, 1, NULL);
#line 47 "rygel-media-receiver-registrar.vala"
	gupnp_service_action_return (action);
#line 115 "rygel-media-receiver-registrar.c"
}


#line 50 "rygel-media-receiver-registrar.vala"
static void rygel_media_receiver_registrar_register_device_cb (RygelMediaReceiverRegistrar* self, GUPnPService* registrar, GUPnPServiceAction* action) {
#line 50 "rygel-media-receiver-registrar.vala"
	g_return_if_fail (self != NULL);
#line 50 "rygel-media-receiver-registrar.vala"
	g_return_if_fail (registrar != NULL);
#line 50 "rygel-media-receiver-registrar.vala"
	g_return_if_fail (action != NULL);
#line 52 "rygel-media-receiver-registrar.vala"
	gupnp_service_action_set (action, "RegistrationRespMsg", G_TYPE_STRING, "WhatisSupposedToBeHere", NULL);
#line 56 "rygel-media-receiver-registrar.vala"
	gupnp_service_action_return (action);
#line 131 "rygel-media-receiver-registrar.c"
}


#line 28 "rygel-media-receiver-registrar.vala"
RygelMediaReceiverRegistrar* rygel_media_receiver_registrar_construct (GType object_type) {
#line 137 "rygel-media-receiver-registrar.c"
	RygelMediaReceiverRegistrar * self;
	self = g_object_newv (object_type, 0, NULL);
	return self;
}


#line 28 "rygel-media-receiver-registrar.vala"
RygelMediaReceiverRegistrar* rygel_media_receiver_registrar_new (void) {
#line 28 "rygel-media-receiver-registrar.vala"
	return rygel_media_receiver_registrar_construct (RYGEL_TYPE_MEDIA_RECEIVER_REGISTRAR);
#line 148 "rygel-media-receiver-registrar.c"
}


static void rygel_media_receiver_registrar_class_init (RygelMediaReceiverRegistrarClass * klass) {
	rygel_media_receiver_registrar_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->constructed = rygel_media_receiver_registrar_real_constructed;
}


static void rygel_media_receiver_registrar_instance_init (RygelMediaReceiverRegistrar * self) {
}


GType rygel_media_receiver_registrar_get_type (void) {
	static volatile gsize rygel_media_receiver_registrar_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_media_receiver_registrar_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediaReceiverRegistrarClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_media_receiver_registrar_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediaReceiverRegistrar), 0, (GInstanceInitFunc) rygel_media_receiver_registrar_instance_init, NULL };
		GType rygel_media_receiver_registrar_type_id;
		rygel_media_receiver_registrar_type_id = g_type_register_static (GUPNP_TYPE_SERVICE, "RygelMediaReceiverRegistrar", &g_define_type_info, 0);
		g_once_init_leave (&rygel_media_receiver_registrar_type_id__volatile, rygel_media_receiver_registrar_type_id);
	}
	return rygel_media_receiver_registrar_type_id__volatile;
}




