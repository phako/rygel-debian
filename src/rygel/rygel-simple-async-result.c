/*
 * Copyright (C) 2009 Zeeshan Ali <zeenix@gmail.com>.
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
#include <gio/gio.h>


#define RYGEL_TYPE_SIMPLE_ASYNC_RESULT (rygel_simple_async_result_get_type ())
#define RYGEL_SIMPLE_ASYNC_RESULT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_SIMPLE_ASYNC_RESULT, RygelSimpleAsyncResult))
#define RYGEL_SIMPLE_ASYNC_RESULT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_SIMPLE_ASYNC_RESULT, RygelSimpleAsyncResultClass))
#define RYGEL_IS_SIMPLE_ASYNC_RESULT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_SIMPLE_ASYNC_RESULT))
#define RYGEL_IS_SIMPLE_ASYNC_RESULT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_SIMPLE_ASYNC_RESULT))
#define RYGEL_SIMPLE_ASYNC_RESULT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_SIMPLE_ASYNC_RESULT, RygelSimpleAsyncResultClass))

typedef struct _RygelSimpleAsyncResult RygelSimpleAsyncResult;
typedef struct _RygelSimpleAsyncResultClass RygelSimpleAsyncResultClass;
typedef struct _RygelSimpleAsyncResultPrivate RygelSimpleAsyncResultPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _RygelSimpleAsyncResult {
	GObject parent_instance;
	RygelSimpleAsyncResultPrivate * priv;
	GObject* source_object;
	GAsyncReadyCallback callback;
	gpointer callback_target;
	GDestroyNotify callback_target_destroy_notify;
	gpointer data;
	GError* error;
};

struct _RygelSimpleAsyncResultClass {
	GObjectClass parent_class;
};

struct _RygelSimpleAsyncResultPrivate {
	GType g_type;
	GBoxedCopyFunc g_dup_func;
	GDestroyNotify g_destroy_func;
};


static gpointer rygel_simple_async_result_parent_class = NULL;
static GAsyncResultIface* rygel_simple_async_result_g_async_result_parent_iface = NULL;

GType rygel_simple_async_result_get_type (void);
#define RYGEL_SIMPLE_ASYNC_RESULT_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_SIMPLE_ASYNC_RESULT, RygelSimpleAsyncResultPrivate))
enum  {
	RYGEL_SIMPLE_ASYNC_RESULT_DUMMY_PROPERTY,
	RYGEL_SIMPLE_ASYNC_RESULT_G_TYPE,
	RYGEL_SIMPLE_ASYNC_RESULT_G_DUP_FUNC,
	RYGEL_SIMPLE_ASYNC_RESULT_G_DESTROY_FUNC
};
RygelSimpleAsyncResult* rygel_simple_async_result_new (GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, GObject* source_object, GAsyncReadyCallback callback, void* callback_target);
RygelSimpleAsyncResult* rygel_simple_async_result_construct (GType object_type, GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, GObject* source_object, GAsyncReadyCallback callback, void* callback_target);
static GObject* rygel_simple_async_result_real_get_source_object (GAsyncResult* base);
static void* rygel_simple_async_result_real_get_user_data (GAsyncResult* base);
void rygel_simple_async_result_complete (RygelSimpleAsyncResult* self);
static gboolean rygel_simple_async_result_idle_func (RygelSimpleAsyncResult* self);
static gboolean _rygel_simple_async_result_idle_func_gsource_func (gpointer self);
void rygel_simple_async_result_complete_in_idle (RygelSimpleAsyncResult* self);
static void rygel_simple_async_result_finalize (GObject* obj);
static void rygel_simple_async_result_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void rygel_simple_async_result_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


RygelSimpleAsyncResult* rygel_simple_async_result_construct (GType object_type, GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, GObject* source_object, GAsyncReadyCallback callback, void* callback_target) {
	RygelSimpleAsyncResult * self;
	GObject* _tmp0_;
	GAsyncReadyCallback _tmp1_;
	g_return_val_if_fail (source_object != NULL, NULL);
	self = (RygelSimpleAsyncResult*) g_object_new (object_type, NULL);
	self->priv->g_type = g_type;
	self->priv->g_dup_func = g_dup_func;
	self->priv->g_destroy_func = g_destroy_func;
	self->source_object = (_tmp0_ = _g_object_ref0 (source_object), _g_object_unref0 (self->source_object), _tmp0_);
	self->callback = (_tmp1_ = callback, ((self->callback_target_destroy_notify == NULL) ? NULL : self->callback_target_destroy_notify (self->callback_target), self->callback = NULL, self->callback_target = NULL, self->callback_target_destroy_notify = NULL), self->callback_target = callback_target, self->callback_target_destroy_notify = NULL, _tmp1_);
	return self;
}


RygelSimpleAsyncResult* rygel_simple_async_result_new (GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, GObject* source_object, GAsyncReadyCallback callback, void* callback_target) {
	return rygel_simple_async_result_construct (RYGEL_TYPE_SIMPLE_ASYNC_RESULT, g_type, g_dup_func, g_destroy_func, source_object, callback, callback_target);
}


static GObject* rygel_simple_async_result_real_get_source_object (GAsyncResult* base) {
	RygelSimpleAsyncResult * self;
	GObject* result;
	self = (RygelSimpleAsyncResult*) base;
	result = self->source_object;
	return result;
}


static void* rygel_simple_async_result_real_get_user_data (GAsyncResult* base) {
	RygelSimpleAsyncResult * self;
	void* result;
	self = (RygelSimpleAsyncResult*) base;
	result = NULL;
	return result;
}


void rygel_simple_async_result_complete (RygelSimpleAsyncResult* self) {
	g_return_if_fail (self != NULL);
	self->callback (self->source_object, (GAsyncResult*) self, self->callback_target);
}


static gboolean _rygel_simple_async_result_idle_func_gsource_func (gpointer self) {
	return rygel_simple_async_result_idle_func (self);
}


void rygel_simple_async_result_complete_in_idle (RygelSimpleAsyncResult* self) {
	g_return_if_fail (self != NULL);
	g_idle_add_full (G_PRIORITY_DEFAULT, _rygel_simple_async_result_idle_func_gsource_func, g_object_ref (self), g_object_unref);
}


static gboolean rygel_simple_async_result_idle_func (RygelSimpleAsyncResult* self) {
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	rygel_simple_async_result_complete (self);
	result = FALSE;
	return result;
}


static void rygel_simple_async_result_class_init (RygelSimpleAsyncResultClass * klass) {
	rygel_simple_async_result_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelSimpleAsyncResultPrivate));
	G_OBJECT_CLASS (klass)->get_property = rygel_simple_async_result_get_property;
	G_OBJECT_CLASS (klass)->set_property = rygel_simple_async_result_set_property;
	G_OBJECT_CLASS (klass)->finalize = rygel_simple_async_result_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), RYGEL_SIMPLE_ASYNC_RESULT_G_TYPE, g_param_spec_gtype ("g-type", "type", "type", G_TYPE_NONE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), RYGEL_SIMPLE_ASYNC_RESULT_G_DUP_FUNC, g_param_spec_pointer ("g-dup-func", "dup func", "dup func", G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), RYGEL_SIMPLE_ASYNC_RESULT_G_DESTROY_FUNC, g_param_spec_pointer ("g-destroy-func", "destroy func", "destroy func", G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
}


static void rygel_simple_async_result_g_async_result_interface_init (GAsyncResultIface * iface) {
	rygel_simple_async_result_g_async_result_parent_iface = g_type_interface_peek_parent (iface);
	iface->get_source_object = rygel_simple_async_result_real_get_source_object;
	iface->get_user_data = rygel_simple_async_result_real_get_user_data;
}


static void rygel_simple_async_result_instance_init (RygelSimpleAsyncResult * self) {
	self->priv = RYGEL_SIMPLE_ASYNC_RESULT_GET_PRIVATE (self);
}


static void rygel_simple_async_result_finalize (GObject* obj) {
	RygelSimpleAsyncResult * self;
	self = RYGEL_SIMPLE_ASYNC_RESULT (obj);
	_g_object_unref0 (self->source_object);
	(self->callback_target_destroy_notify == NULL) ? NULL : self->callback_target_destroy_notify (self->callback_target);
	self->callback = NULL;
	self->callback_target = NULL;
	self->callback_target_destroy_notify = NULL;
	((self->data == NULL) || (self->priv->g_destroy_func == NULL)) ? NULL : (self->data = (self->priv->g_destroy_func (self->data), NULL));
	_g_error_free0 (self->error);
	G_OBJECT_CLASS (rygel_simple_async_result_parent_class)->finalize (obj);
}


GType rygel_simple_async_result_get_type (void) {
	static GType rygel_simple_async_result_type_id = 0;
	if (rygel_simple_async_result_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelSimpleAsyncResultClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_simple_async_result_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelSimpleAsyncResult), 0, (GInstanceInitFunc) rygel_simple_async_result_instance_init, NULL };
		static const GInterfaceInfo g_async_result_info = { (GInterfaceInitFunc) rygel_simple_async_result_g_async_result_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		rygel_simple_async_result_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelSimpleAsyncResult", &g_define_type_info, 0);
		g_type_add_interface_static (rygel_simple_async_result_type_id, G_TYPE_ASYNC_RESULT, &g_async_result_info);
	}
	return rygel_simple_async_result_type_id;
}


static void rygel_simple_async_result_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	RygelSimpleAsyncResult * self;
	self = RYGEL_SIMPLE_ASYNC_RESULT (object);
	switch (property_id) {
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void rygel_simple_async_result_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	RygelSimpleAsyncResult * self;
	self = RYGEL_SIMPLE_ASYNC_RESULT (object);
	switch (property_id) {
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
		case RYGEL_SIMPLE_ASYNC_RESULT_G_TYPE:
		self->priv->g_type = g_value_get_gtype (value);
		break;
		case RYGEL_SIMPLE_ASYNC_RESULT_G_DUP_FUNC:
		self->priv->g_dup_func = g_value_get_pointer (value);
		break;
		case RYGEL_SIMPLE_ASYNC_RESULT_G_DESTROY_FUNC:
		self->priv->g_destroy_func = g_value_get_pointer (value);
		break;
	}
}




