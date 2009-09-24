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
#include <rygel.h>
#include <stdlib.h>
#include <string.h>
#include <gst/gst.h>


#define RYGEL_TYPE_TEST_ITEM (rygel_test_item_get_type ())
#define RYGEL_TEST_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TEST_ITEM, RygelTestItem))
#define RYGEL_TEST_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TEST_ITEM, RygelTestItemClass))
#define RYGEL_IS_TEST_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TEST_ITEM))
#define RYGEL_IS_TEST_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TEST_ITEM))
#define RYGEL_TEST_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TEST_ITEM, RygelTestItemClass))

typedef struct _RygelTestItem RygelTestItem;
typedef struct _RygelTestItemClass RygelTestItemClass;
typedef struct _RygelTestItemPrivate RygelTestItemPrivate;

#define RYGEL_TYPE_TEST_AUDIO_ITEM (rygel_test_audio_item_get_type ())
#define RYGEL_TEST_AUDIO_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TEST_AUDIO_ITEM, RygelTestAudioItem))
#define RYGEL_TEST_AUDIO_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TEST_AUDIO_ITEM, RygelTestAudioItemClass))
#define RYGEL_IS_TEST_AUDIO_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TEST_AUDIO_ITEM))
#define RYGEL_IS_TEST_AUDIO_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TEST_AUDIO_ITEM))
#define RYGEL_TEST_AUDIO_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TEST_AUDIO_ITEM, RygelTestAudioItemClass))

typedef struct _RygelTestAudioItem RygelTestAudioItem;
typedef struct _RygelTestAudioItemClass RygelTestAudioItemClass;
typedef struct _RygelTestAudioItemPrivate RygelTestAudioItemPrivate;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _RygelTestItem {
	RygelMediaItem parent_instance;
	RygelTestItemPrivate * priv;
};

struct _RygelTestItemClass {
	RygelMediaItemClass parent_class;
};

struct _RygelTestAudioItem {
	RygelTestItem parent_instance;
	RygelTestAudioItemPrivate * priv;
};

struct _RygelTestAudioItemClass {
	RygelTestItemClass parent_class;
};


static gpointer rygel_test_audio_item_parent_class = NULL;

GType rygel_test_item_get_type (void);
GType rygel_test_audio_item_get_type (void);
enum  {
	RYGEL_TEST_AUDIO_ITEM_DUMMY_PROPERTY
};
#define RYGEL_TEST_AUDIO_ITEM_TEST_MIMETYPE "audio/x-wav"
RygelTestItem* rygel_test_item_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title, const char* mime, const char* upnp_class);
RygelTestAudioItem* rygel_test_audio_item_new (const char* id, RygelMediaContainer* parent, const char* title);
RygelTestAudioItem* rygel_test_audio_item_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title);
static GstElement* rygel_test_audio_item_real_create_stream_source (RygelMediaItem* base);



RygelTestAudioItem* rygel_test_audio_item_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title) {
	RygelTestAudioItem * self;
	g_return_val_if_fail (id != NULL, NULL);
	g_return_val_if_fail (parent != NULL, NULL);
	g_return_val_if_fail (title != NULL, NULL);
	self = (RygelTestAudioItem*) rygel_test_item_construct (object_type, id, parent, title, RYGEL_TEST_AUDIO_ITEM_TEST_MIMETYPE, RYGEL_MEDIA_ITEM_AUDIO_CLASS);
	return self;
}


RygelTestAudioItem* rygel_test_audio_item_new (const char* id, RygelMediaContainer* parent, const char* title) {
	return rygel_test_audio_item_construct (RYGEL_TYPE_TEST_AUDIO_ITEM, id, parent, title);
}


static GstElement* rygel_test_audio_item_real_create_stream_source (RygelMediaItem* base) {
	RygelTestAudioItem * self;
	GstElement* result;
	GError * _inner_error_;
	self = (RygelTestAudioItem*) base;
	_inner_error_ = NULL;
	{
		GstElement* _tmp0_;
		_tmp0_ = gst_parse_bin_from_description ("audiotestsrc is-live=1 ! wavenc", TRUE, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch0_g_error;
			goto __finally0;
		}
		result = _tmp0_;
		return result;
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			g_warning ("rygel-test-audio-item.vala:49: Required plugin missing (%s)", err->message);
			result = NULL;
			_g_error_free0 (err);
			return result;
		}
	}
	__finally0:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
}


static void rygel_test_audio_item_class_init (RygelTestAudioItemClass * klass) {
	rygel_test_audio_item_parent_class = g_type_class_peek_parent (klass);
	RYGEL_MEDIA_ITEM_CLASS (klass)->create_stream_source = rygel_test_audio_item_real_create_stream_source;
}


static void rygel_test_audio_item_instance_init (RygelTestAudioItem * self) {
}


GType rygel_test_audio_item_get_type (void) {
	static GType rygel_test_audio_item_type_id = 0;
	if (rygel_test_audio_item_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelTestAudioItemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_test_audio_item_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelTestAudioItem), 0, (GInstanceInitFunc) rygel_test_audio_item_instance_init, NULL };
		rygel_test_audio_item_type_id = g_type_register_static (RYGEL_TYPE_TEST_ITEM, "RygelTestAudioItem", &g_define_type_info, 0);
	}
	return rygel_test_audio_item_type_id;
}




