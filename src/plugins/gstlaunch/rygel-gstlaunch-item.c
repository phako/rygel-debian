/*
 * Copyright (C) 2009 Thijs Vermeir <thijsvermeir@gmail.com>
 *
 * Author: Thijs Vermeir <thijsvermeir@gmail.com>
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
#include <gst/gst.h>


#define RYGEL_TYPE_GST_LAUNCH_ITEM (rygel_gst_launch_item_get_type ())
#define RYGEL_GST_LAUNCH_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_GST_LAUNCH_ITEM, RygelGstLaunchItem))
#define RYGEL_GST_LAUNCH_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_GST_LAUNCH_ITEM, RygelGstLaunchItemClass))
#define RYGEL_IS_GST_LAUNCH_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_GST_LAUNCH_ITEM))
#define RYGEL_IS_GST_LAUNCH_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_GST_LAUNCH_ITEM))
#define RYGEL_GST_LAUNCH_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_GST_LAUNCH_ITEM, RygelGstLaunchItemClass))

typedef struct _RygelGstLaunchItem RygelGstLaunchItem;
typedef struct _RygelGstLaunchItemClass RygelGstLaunchItemClass;
typedef struct _RygelGstLaunchItemPrivate RygelGstLaunchItemPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _RygelGstLaunchItem {
	RygelMediaItem parent_instance;
	RygelGstLaunchItemPrivate * priv;
};

struct _RygelGstLaunchItemClass {
	RygelMediaItemClass parent_class;
};

struct _RygelGstLaunchItemPrivate {
	char* launch_line;
};


static gpointer rygel_gst_launch_item_parent_class = NULL;

GType rygel_gst_launch_item_get_type (void);
#define RYGEL_GST_LAUNCH_ITEM_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_GST_LAUNCH_ITEM, RygelGstLaunchItemPrivate))
enum  {
	RYGEL_GST_LAUNCH_ITEM_DUMMY_PROPERTY
};
RygelGstLaunchItem* rygel_gst_launch_item_new (const char* id, RygelMediaContainer* parent, const char* title, const char* mime_type, const char* launch_line);
RygelGstLaunchItem* rygel_gst_launch_item_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title, const char* mime_type, const char* launch_line);
static GstElement* rygel_gst_launch_item_real_create_stream_source (RygelMediaItem* base);
static void rygel_gst_launch_item_finalize (GObject* obj);



RygelGstLaunchItem* rygel_gst_launch_item_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title, const char* mime_type, const char* launch_line) {
	RygelGstLaunchItem * self;
	const char* _tmp0_;
	char* _tmp1_;
	char* _tmp2_;
	g_return_val_if_fail (id != NULL, NULL);
	g_return_val_if_fail (parent != NULL, NULL);
	g_return_val_if_fail (title != NULL, NULL);
	g_return_val_if_fail (mime_type != NULL, NULL);
	g_return_val_if_fail (launch_line != NULL, NULL);
	_tmp0_ = NULL;
	if (g_str_has_prefix (mime_type, "audio")) {
		_tmp0_ = RYGEL_MEDIA_ITEM_AUDIO_CLASS;
	} else {
		_tmp0_ = RYGEL_MEDIA_ITEM_VIDEO_CLASS;
	}
	self = (RygelGstLaunchItem*) rygel_media_item_construct (object_type, id, parent, title, _tmp0_);
	((RygelMediaItem*) self)->mime_type = (_tmp1_ = g_strdup (mime_type), _g_free0 (((RygelMediaItem*) self)->mime_type), _tmp1_);
	self->priv->launch_line = (_tmp2_ = g_strdup (launch_line), _g_free0 (self->priv->launch_line), _tmp2_);
	return self;
}


RygelGstLaunchItem* rygel_gst_launch_item_new (const char* id, RygelMediaContainer* parent, const char* title, const char* mime_type, const char* launch_line) {
	return rygel_gst_launch_item_construct (RYGEL_TYPE_GST_LAUNCH_ITEM, id, parent, title, mime_type, launch_line);
}


static GstElement* rygel_gst_launch_item_real_create_stream_source (RygelMediaItem* base) {
	RygelGstLaunchItem * self;
	GstElement* result;
	GError * _inner_error_;
	self = (RygelGstLaunchItem*) base;
	_inner_error_ = NULL;
	{
		GstElement* _tmp0_;
		_tmp0_ = gst_parse_bin_from_description (self->priv->launch_line, TRUE, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch2_g_error;
			goto __finally2;
		}
		result = _tmp0_;
		return result;
	}
	goto __finally2;
	__catch2_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			g_warning ("rygel-gstlaunch-item.vala:51: parse launchline failed: %s", err->message);
			result = NULL;
			_g_error_free0 (err);
			return result;
		}
	}
	__finally2:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
}


static void rygel_gst_launch_item_class_init (RygelGstLaunchItemClass * klass) {
	rygel_gst_launch_item_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelGstLaunchItemPrivate));
	RYGEL_MEDIA_ITEM_CLASS (klass)->create_stream_source = rygel_gst_launch_item_real_create_stream_source;
	G_OBJECT_CLASS (klass)->finalize = rygel_gst_launch_item_finalize;
}


static void rygel_gst_launch_item_instance_init (RygelGstLaunchItem * self) {
	self->priv = RYGEL_GST_LAUNCH_ITEM_GET_PRIVATE (self);
}


static void rygel_gst_launch_item_finalize (GObject* obj) {
	RygelGstLaunchItem * self;
	self = RYGEL_GST_LAUNCH_ITEM (obj);
	_g_free0 (self->priv->launch_line);
	G_OBJECT_CLASS (rygel_gst_launch_item_parent_class)->finalize (obj);
}


GType rygel_gst_launch_item_get_type (void) {
	static GType rygel_gst_launch_item_type_id = 0;
	if (rygel_gst_launch_item_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelGstLaunchItemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_gst_launch_item_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelGstLaunchItem), 0, (GInstanceInitFunc) rygel_gst_launch_item_instance_init, NULL };
		rygel_gst_launch_item_type_id = g_type_register_static (RYGEL_TYPE_MEDIA_ITEM, "RygelGstLaunchItem", &g_define_type_info, 0);
	}
	return rygel_gst_launch_item_type_id;
}




