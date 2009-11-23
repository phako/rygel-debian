/* rygel-media-object.c generated by valac, the Vala compiler
 * generated from rygel-media-object.vala, do not modify */

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
#include <stdlib.h>
#include <string.h>
#include <gee.h>


#define RYGEL_TYPE_MEDIA_OBJECT (rygel_media_object_get_type ())
#define RYGEL_MEDIA_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObject))
#define RYGEL_MEDIA_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObjectClass))
#define RYGEL_IS_MEDIA_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_OBJECT))
#define RYGEL_IS_MEDIA_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_OBJECT))
#define RYGEL_MEDIA_OBJECT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObjectClass))

typedef struct _RygelMediaObject RygelMediaObject;
typedef struct _RygelMediaObjectClass RygelMediaObjectClass;
typedef struct _RygelMediaObjectPrivate RygelMediaObjectPrivate;

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
#define _g_regex_unref0(var) ((var == NULL) ? NULL : (var = (g_regex_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _RygelMediaObject {
	GObject parent_instance;
	RygelMediaObjectPrivate * priv;
	char* id;
	char* upnp_class;
	guint64 modified;
	GeeArrayList* uris;
	RygelMediaContainer* parent;
	RygelMediaContainer* parent_ref;
};

struct _RygelMediaObjectClass {
	GObjectClass parent_class;
};

struct _RygelMediaObjectPrivate {
	char* _title;
};


static gpointer rygel_media_object_parent_class = NULL;

GType rygel_media_object_get_type (void);
GType rygel_media_container_get_type (void);
#define RYGEL_MEDIA_OBJECT_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObjectPrivate))
enum  {
	RYGEL_MEDIA_OBJECT_DUMMY_PROPERTY,
	RYGEL_MEDIA_OBJECT_TITLE
};
RygelMediaObject* rygel_media_object_construct (GType object_type);
const char* rygel_media_object_get_title (RygelMediaObject* self);
void rygel_media_object_set_title (RygelMediaObject* self, const char* value);
static GObject * rygel_media_object_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void rygel_media_object_finalize (GObject* obj);
static void rygel_media_object_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void rygel_media_object_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



RygelMediaObject* rygel_media_object_construct (GType object_type) {
	RygelMediaObject * self;
	self = g_object_newv (object_type, 0, NULL);
	return self;
}


const char* rygel_media_object_get_title (RygelMediaObject* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_title;
	return result;
}


static char* string_replace (const char* self, const char* old, const char* replacement) {
	char* result;
	GError * _inner_error_;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (old != NULL, NULL);
	g_return_val_if_fail (replacement != NULL, NULL);
	_inner_error_ = NULL;
	{
		char* _tmp0_;
		GRegex* _tmp1_;
		GRegex* regex;
		char* _tmp2_;
		regex = (_tmp1_ = g_regex_new (_tmp0_ = g_regex_escape_string (old, -1), 0, 0, &_inner_error_), _g_free0 (_tmp0_), _tmp1_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch37_g_regex_error;
			}
			goto __finally37;
		}
		_tmp2_ = g_regex_replace_literal (regex, self, (gssize) (-1), 0, replacement, 0, &_inner_error_);
		if (_inner_error_ != NULL) {
			_g_regex_unref0 (regex);
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch37_g_regex_error;
			}
			goto __finally37;
		}
		result = _tmp2_;
		_g_regex_unref0 (regex);
		return result;
	}
	goto __finally37;
	__catch37_g_regex_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			g_assert_not_reached ();
			_g_error_free0 (e);
		}
	}
	__finally37:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
}


void rygel_media_object_set_title (RygelMediaObject* self, const char* value) {
	char* _tmp0_;
	char* _tmp1_;
	char* _tmp2_;
	g_return_if_fail (self != NULL);
	self->priv->_title = (_tmp0_ = string_replace (value, "@REALNAME@", g_get_real_name ()), _g_free0 (self->priv->_title), _tmp0_);
	self->priv->_title = (_tmp1_ = string_replace (self->priv->_title, "@USERNAME@", g_get_user_name ()), _g_free0 (self->priv->_title), _tmp1_);
	self->priv->_title = (_tmp2_ = string_replace (self->priv->_title, "@HOSTNAME@", g_get_host_name ()), _g_free0 (self->priv->_title), _tmp2_);
	g_object_notify ((GObject *) self, "title");
}


static GObject * rygel_media_object_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	RygelMediaObject * self;
	parent_class = G_OBJECT_CLASS (rygel_media_object_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = RYGEL_MEDIA_OBJECT (obj);
	{
		GeeArrayList* _tmp0_;
		self->uris = (_tmp0_ = gee_array_list_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, NULL), _g_object_unref0 (self->uris), _tmp0_);
	}
	return obj;
}


static void rygel_media_object_class_init (RygelMediaObjectClass * klass) {
	rygel_media_object_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelMediaObjectPrivate));
	G_OBJECT_CLASS (klass)->get_property = rygel_media_object_get_property;
	G_OBJECT_CLASS (klass)->set_property = rygel_media_object_set_property;
	G_OBJECT_CLASS (klass)->constructor = rygel_media_object_constructor;
	G_OBJECT_CLASS (klass)->finalize = rygel_media_object_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), RYGEL_MEDIA_OBJECT_TITLE, g_param_spec_string ("title", "title", "title", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void rygel_media_object_instance_init (RygelMediaObject * self) {
	self->priv = RYGEL_MEDIA_OBJECT_GET_PRIVATE (self);
}


static void rygel_media_object_finalize (GObject* obj) {
	RygelMediaObject * self;
	self = RYGEL_MEDIA_OBJECT (obj);
	_g_free0 (self->id);
	_g_free0 (self->upnp_class);
	_g_object_unref0 (self->uris);
	_g_object_unref0 (self->parent_ref);
	_g_free0 (self->priv->_title);
	G_OBJECT_CLASS (rygel_media_object_parent_class)->finalize (obj);
}


GType rygel_media_object_get_type (void) {
	static GType rygel_media_object_type_id = 0;
	if (rygel_media_object_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediaObjectClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_media_object_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediaObject), 0, (GInstanceInitFunc) rygel_media_object_instance_init, NULL };
		rygel_media_object_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelMediaObject", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
	}
	return rygel_media_object_type_id;
}


static void rygel_media_object_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	RygelMediaObject * self;
	self = RYGEL_MEDIA_OBJECT (object);
	switch (property_id) {
		case RYGEL_MEDIA_OBJECT_TITLE:
		g_value_set_string (value, rygel_media_object_get_title (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void rygel_media_object_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	RygelMediaObject * self;
	self = RYGEL_MEDIA_OBJECT (object);
	switch (property_id) {
		case RYGEL_MEDIA_OBJECT_TITLE:
		rygel_media_object_set_title (self, g_value_get_string (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




