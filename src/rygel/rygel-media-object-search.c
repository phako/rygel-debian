/*
 * Copyright (C) 2009 Zeeshan Ali (Khattak) <zeeshanak@gnome.org>.
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
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>
#include <gee.h>


#define RYGEL_TYPE_STATE_MACHINE (rygel_state_machine_get_type ())
#define RYGEL_STATE_MACHINE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_STATE_MACHINE, RygelStateMachine))
#define RYGEL_IS_STATE_MACHINE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_STATE_MACHINE))
#define RYGEL_STATE_MACHINE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), RYGEL_TYPE_STATE_MACHINE, RygelStateMachineIface))

typedef struct _RygelStateMachine RygelStateMachine;
typedef struct _RygelStateMachineIface RygelStateMachineIface;

#define RYGEL_TYPE_MEDIA_OBJECT_SEARCH (rygel_media_object_search_get_type ())
#define RYGEL_MEDIA_OBJECT_SEARCH(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_OBJECT_SEARCH, RygelMediaObjectSearch))
#define RYGEL_MEDIA_OBJECT_SEARCH_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_OBJECT_SEARCH, RygelMediaObjectSearchClass))
#define RYGEL_IS_MEDIA_OBJECT_SEARCH(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_OBJECT_SEARCH))
#define RYGEL_IS_MEDIA_OBJECT_SEARCH_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_OBJECT_SEARCH))
#define RYGEL_MEDIA_OBJECT_SEARCH_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_OBJECT_SEARCH, RygelMediaObjectSearchClass))

typedef struct _RygelMediaObjectSearch RygelMediaObjectSearch;
typedef struct _RygelMediaObjectSearchClass RygelMediaObjectSearchClass;
typedef struct _RygelMediaObjectSearchPrivate RygelMediaObjectSearchPrivate;

#define RYGEL_TYPE_MEDIA_OBJECT (rygel_media_object_get_type ())
#define RYGEL_MEDIA_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObject))
#define RYGEL_MEDIA_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObjectClass))
#define RYGEL_IS_MEDIA_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_OBJECT))
#define RYGEL_IS_MEDIA_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_OBJECT))
#define RYGEL_MEDIA_OBJECT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObjectClass))

typedef struct _RygelMediaObject RygelMediaObject;
typedef struct _RygelMediaObjectClass RygelMediaObjectClass;

#define RYGEL_TYPE_MEDIA_CONTAINER (rygel_media_container_get_type ())
#define RYGEL_MEDIA_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainer))
#define RYGEL_MEDIA_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainerClass))
#define RYGEL_IS_MEDIA_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_CONTAINER))
#define RYGEL_IS_MEDIA_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_CONTAINER))
#define RYGEL_MEDIA_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainerClass))

typedef struct _RygelMediaContainer RygelMediaContainer;
typedef struct _RygelMediaContainerClass RygelMediaContainerClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_destroy_func0(var) (((var == NULL) || (g_destroy_func == NULL)) ? NULL : (var = (g_destroy_func (var), NULL)))

struct _RygelStateMachineIface {
	GTypeInterface parent_iface;
	void (*run) (RygelStateMachine* self);
	GCancellable* (*get_cancellable) (RygelStateMachine* self);
	void (*set_cancellable) (RygelStateMachine* self, GCancellable* value);
};

struct _RygelMediaObjectSearch {
	GObject parent_instance;
	RygelMediaObjectSearchPrivate * priv;
	char* id;
	gpointer data;
	RygelMediaObject* media_object;
	GError* error;
};

struct _RygelMediaObjectSearchClass {
	GObjectClass parent_class;
};

struct _RygelMediaObjectSearchPrivate {
	GType g_type;
	GBoxedCopyFunc g_dup_func;
	GDestroyNotify g_destroy_func;
	GeeArrayList* containers;
	GCancellable* _cancellable;
};


static gpointer rygel_media_object_search_parent_class = NULL;
static RygelStateMachineIface* rygel_media_object_search_rygel_state_machine_parent_iface = NULL;

GType rygel_state_machine_get_type (void);
GType rygel_media_object_search_get_type (void);
GType rygel_media_object_get_type (void);
GType rygel_media_container_get_type (void);
#define RYGEL_MEDIA_OBJECT_SEARCH_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_MEDIA_OBJECT_SEARCH, RygelMediaObjectSearchPrivate))
enum  {
	RYGEL_MEDIA_OBJECT_SEARCH_DUMMY_PROPERTY,
	RYGEL_MEDIA_OBJECT_SEARCH_CANCELLABLE,
	RYGEL_MEDIA_OBJECT_SEARCH_G_TYPE,
	RYGEL_MEDIA_OBJECT_SEARCH_G_DUP_FUNC,
	RYGEL_MEDIA_OBJECT_SEARCH_G_DESTROY_FUNC
};
void rygel_state_machine_set_cancellable (RygelStateMachine* self, GCancellable* value);
RygelMediaObjectSearch* rygel_media_object_search_new (GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, const char* id, GeeArrayList* containers, gconstpointer data, GCancellable* cancellable);
RygelMediaObjectSearch* rygel_media_object_search_construct (GType object_type, GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, const char* id, GeeArrayList* containers, gconstpointer data, GCancellable* cancellable);
void rygel_media_container_find_object (RygelMediaContainer* self, const char* id, GCancellable* cancellable, GAsyncReadyCallback callback, void* callback_target);
GCancellable* rygel_state_machine_get_cancellable (RygelStateMachine* self);
static void rygel_media_object_search_on_object_found (RygelMediaObjectSearch* self, GObject* source_object, GAsyncResult* res);
static void _rygel_media_object_search_on_object_found_gasync_ready_callback (GObject* source_object, GAsyncResult* res, gpointer self);
static void rygel_media_object_search_real_run (RygelStateMachine* base);
RygelMediaObject* rygel_media_container_find_object_finish (RygelMediaContainer* self, GAsyncResult* res, GError** error);
void rygel_state_machine_run (RygelStateMachine* self);
static void rygel_media_object_search_finalize (GObject* obj);
static void rygel_media_object_search_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void rygel_media_object_search_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


RygelMediaObjectSearch* rygel_media_object_search_construct (GType object_type, GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, const char* id, GeeArrayList* containers, gconstpointer data, GCancellable* cancellable) {
	RygelMediaObjectSearch * self;
	char* _tmp0_;
	GeeArrayList* _tmp1_;
	gpointer _tmp3_;
	gconstpointer _tmp2_;
	g_return_val_if_fail (id != NULL, NULL);
	g_return_val_if_fail (containers != NULL, NULL);
	self = (RygelMediaObjectSearch*) g_object_new (object_type, NULL);
	self->priv->g_type = g_type;
	self->priv->g_dup_func = g_dup_func;
	self->priv->g_destroy_func = g_destroy_func;
	self->id = (_tmp0_ = g_strdup (id), _g_free0 (self->id), _tmp0_);
	self->priv->containers = (_tmp1_ = _g_object_ref0 (containers), _g_object_unref0 (self->priv->containers), _tmp1_);
	self->data = (_tmp3_ = (_tmp2_ = data, ((_tmp2_ == NULL) || (g_dup_func == NULL)) ? ((gpointer) _tmp2_) : g_dup_func ((gpointer) _tmp2_)), _g_destroy_func0 (self->data), _tmp3_);
	rygel_state_machine_set_cancellable ((RygelStateMachine*) self, cancellable);
	return self;
}


RygelMediaObjectSearch* rygel_media_object_search_new (GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, const char* id, GeeArrayList* containers, gconstpointer data, GCancellable* cancellable) {
	return rygel_media_object_search_construct (RYGEL_TYPE_MEDIA_OBJECT_SEARCH, g_type, g_dup_func, g_destroy_func, id, containers, data, cancellable);
}


static void _rygel_media_object_search_on_object_found_gasync_ready_callback (GObject* source_object, GAsyncResult* res, gpointer self) {
	rygel_media_object_search_on_object_found (self, source_object, res);
}


static void rygel_media_object_search_real_run (RygelStateMachine* base) {
	RygelMediaObjectSearch * self;
	self = (RygelMediaObjectSearch*) base;
	if (gee_collection_get_size ((GeeCollection*) self->priv->containers) > 0) {
		RygelMediaContainer* container;
		container = (RygelMediaContainer*) gee_abstract_list_get ((GeeAbstractList*) self->priv->containers, 0);
		rygel_media_container_find_object (container, self->id, rygel_state_machine_get_cancellable ((RygelStateMachine*) self), _rygel_media_object_search_on_object_found_gasync_ready_callback, self);
		_g_object_unref0 (container);
	} else {
		g_signal_emit_by_name ((RygelStateMachine*) self, "completed");
	}
}


static gpointer _g_error_copy0 (gpointer self) {
	return self ? g_error_copy (self) : NULL;
}


static void rygel_media_object_search_on_object_found (RygelMediaObjectSearch* self, GObject* source_object, GAsyncResult* res) {
	GError * _inner_error_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (res != NULL);
	_inner_error_ = NULL;
	{
		GObject* _tmp0_;
		RygelMediaContainer* container;
		RygelMediaObject* _tmp1_;
		RygelMediaObject* _tmp2_;
		container = _g_object_ref0 ((_tmp0_ = source_object, RYGEL_IS_MEDIA_CONTAINER (_tmp0_) ? ((RygelMediaContainer*) _tmp0_) : NULL));
		_tmp1_ = rygel_media_container_find_object_finish (container, res, &_inner_error_);
		if (_inner_error_ != NULL) {
			_g_object_unref0 (container);
			goto __catch29_g_error;
			goto __finally29;
		}
		self->media_object = (_tmp2_ = _tmp1_, _g_object_unref0 (self->media_object), _tmp2_);
		if (self->media_object == NULL) {
			gee_abstract_list_remove_at ((GeeAbstractList*) self->priv->containers, 0);
			rygel_state_machine_run ((RygelStateMachine*) self);
		} else {
			g_signal_emit_by_name ((RygelStateMachine*) self, "completed");
		}
		_g_object_unref0 (container);
	}
	goto __finally29;
	__catch29_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			GError* _tmp3_;
			self->error = (_tmp3_ = _g_error_copy0 (err), _g_error_free0 (self->error), _tmp3_);
			g_signal_emit_by_name ((RygelStateMachine*) self, "completed");
			_g_error_free0 (err);
		}
	}
	__finally29:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return;
	}
}


static GCancellable* rygel_media_object_search_real_get_cancellable (RygelStateMachine* base) {
	GCancellable* result;
	RygelMediaObjectSearch* self;
	self = (RygelMediaObjectSearch*) base;
	result = self->priv->_cancellable;
	return result;
}


static void rygel_media_object_search_real_set_cancellable (RygelStateMachine* base, GCancellable* value) {
	RygelMediaObjectSearch* self;
	GCancellable* _tmp0_;
	self = (RygelMediaObjectSearch*) base;
	self->priv->_cancellable = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_cancellable), _tmp0_);
	g_object_notify ((GObject *) self, "cancellable");
}


static void rygel_media_object_search_class_init (RygelMediaObjectSearchClass * klass) {
	rygel_media_object_search_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelMediaObjectSearchPrivate));
	G_OBJECT_CLASS (klass)->get_property = rygel_media_object_search_get_property;
	G_OBJECT_CLASS (klass)->set_property = rygel_media_object_search_set_property;
	G_OBJECT_CLASS (klass)->finalize = rygel_media_object_search_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), RYGEL_MEDIA_OBJECT_SEARCH_G_TYPE, g_param_spec_gtype ("g-type", "type", "type", G_TYPE_NONE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), RYGEL_MEDIA_OBJECT_SEARCH_G_DUP_FUNC, g_param_spec_pointer ("g-dup-func", "dup func", "dup func", G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), RYGEL_MEDIA_OBJECT_SEARCH_G_DESTROY_FUNC, g_param_spec_pointer ("g-destroy-func", "destroy func", "destroy func", G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_override_property (G_OBJECT_CLASS (klass), RYGEL_MEDIA_OBJECT_SEARCH_CANCELLABLE, "cancellable");
}


static void rygel_media_object_search_rygel_state_machine_interface_init (RygelStateMachineIface * iface) {
	rygel_media_object_search_rygel_state_machine_parent_iface = g_type_interface_peek_parent (iface);
	iface->run = rygel_media_object_search_real_run;
	iface->get_cancellable = rygel_media_object_search_real_get_cancellable;
	iface->set_cancellable = rygel_media_object_search_real_set_cancellable;
}


static void rygel_media_object_search_instance_init (RygelMediaObjectSearch * self) {
	self->priv = RYGEL_MEDIA_OBJECT_SEARCH_GET_PRIVATE (self);
}


static void rygel_media_object_search_finalize (GObject* obj) {
	RygelMediaObjectSearch * self;
	self = RYGEL_MEDIA_OBJECT_SEARCH (obj);
	_g_free0 (self->id);
	_g_object_unref0 (self->priv->containers);
	((self->data == NULL) || (self->priv->g_destroy_func == NULL)) ? NULL : (self->data = (self->priv->g_destroy_func (self->data), NULL));
	_g_object_unref0 (self->priv->_cancellable);
	_g_object_unref0 (self->media_object);
	_g_error_free0 (self->error);
	G_OBJECT_CLASS (rygel_media_object_search_parent_class)->finalize (obj);
}


GType rygel_media_object_search_get_type (void) {
	static GType rygel_media_object_search_type_id = 0;
	if (rygel_media_object_search_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediaObjectSearchClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_media_object_search_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediaObjectSearch), 0, (GInstanceInitFunc) rygel_media_object_search_instance_init, NULL };
		static const GInterfaceInfo rygel_state_machine_info = { (GInterfaceInitFunc) rygel_media_object_search_rygel_state_machine_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		rygel_media_object_search_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelMediaObjectSearch", &g_define_type_info, 0);
		g_type_add_interface_static (rygel_media_object_search_type_id, RYGEL_TYPE_STATE_MACHINE, &rygel_state_machine_info);
	}
	return rygel_media_object_search_type_id;
}


static void rygel_media_object_search_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	RygelMediaObjectSearch * self;
	self = RYGEL_MEDIA_OBJECT_SEARCH (object);
	switch (property_id) {
		case RYGEL_MEDIA_OBJECT_SEARCH_CANCELLABLE:
		g_value_set_object (value, rygel_state_machine_get_cancellable ((RygelStateMachine*) self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void rygel_media_object_search_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	RygelMediaObjectSearch * self;
	self = RYGEL_MEDIA_OBJECT_SEARCH (object);
	switch (property_id) {
		case RYGEL_MEDIA_OBJECT_SEARCH_CANCELLABLE:
		rygel_state_machine_set_cancellable ((RygelStateMachine*) self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
		case RYGEL_MEDIA_OBJECT_SEARCH_G_TYPE:
		self->priv->g_type = g_value_get_gtype (value);
		break;
		case RYGEL_MEDIA_OBJECT_SEARCH_G_DUP_FUNC:
		self->priv->g_dup_func = g_value_get_pointer (value);
		break;
		case RYGEL_MEDIA_OBJECT_SEARCH_G_DESTROY_FUNC:
		self->priv->g_destroy_func = g_value_get_pointer (value);
		break;
	}
}




