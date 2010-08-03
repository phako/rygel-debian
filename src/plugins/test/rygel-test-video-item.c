/* rygel-test-video-item.c generated by valac, the Vala compiler
 * generated from rygel-test-video-item.vala, do not modify */

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


#define RYGEL_TEST_TYPE_ITEM (rygel_test_item_get_type ())
#define RYGEL_TEST_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TEST_TYPE_ITEM, RygelTestItem))
#define RYGEL_TEST_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TEST_TYPE_ITEM, RygelTestItemClass))
#define RYGEL_TEST_IS_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TEST_TYPE_ITEM))
#define RYGEL_TEST_IS_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TEST_TYPE_ITEM))
#define RYGEL_TEST_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TEST_TYPE_ITEM, RygelTestItemClass))

typedef struct _RygelTestItem RygelTestItem;
typedef struct _RygelTestItemClass RygelTestItemClass;
typedef struct _RygelTestItemPrivate RygelTestItemPrivate;

#define RYGEL_TEST_TYPE_VIDEO_ITEM (rygel_test_video_item_get_type ())
#define RYGEL_TEST_VIDEO_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TEST_TYPE_VIDEO_ITEM, RygelTestVideoItem))
#define RYGEL_TEST_VIDEO_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TEST_TYPE_VIDEO_ITEM, RygelTestVideoItemClass))
#define RYGEL_TEST_IS_VIDEO_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TEST_TYPE_VIDEO_ITEM))
#define RYGEL_TEST_IS_VIDEO_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TEST_TYPE_VIDEO_ITEM))
#define RYGEL_TEST_VIDEO_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TEST_TYPE_VIDEO_ITEM, RygelTestVideoItemClass))

typedef struct _RygelTestVideoItem RygelTestVideoItem;
typedef struct _RygelTestVideoItemClass RygelTestVideoItemClass;
typedef struct _RygelTestVideoItemPrivate RygelTestVideoItemPrivate;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _RygelTestItem {
	RygelMediaItem parent_instance;
	RygelTestItemPrivate * priv;
};

struct _RygelTestItemClass {
	RygelMediaItemClass parent_class;
};

struct _RygelTestVideoItem {
	RygelTestItem parent_instance;
	RygelTestVideoItemPrivate * priv;
};

struct _RygelTestVideoItemClass {
	RygelTestItemClass parent_class;
};


static gpointer rygel_test_video_item_parent_class = NULL;

GType rygel_test_item_get_type (void) G_GNUC_CONST;
GType rygel_test_video_item_get_type (void) G_GNUC_CONST;
enum  {
	RYGEL_TEST_VIDEO_ITEM_DUMMY_PROPERTY
};
#define RYGEL_TEST_VIDEO_ITEM_TEST_MIMETYPE "video/mpeg"
#define RYGEL_TEST_VIDEO_ITEM_PIPELINE "videotestsrc is-live=1 ! " "ffenc_mpeg2video ! " "mpegtsmux"
RygelTestItem* rygel_test_item_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title, const char* mime, const char* upnp_class);
RygelTestVideoItem* rygel_test_video_item_new (const char* id, RygelMediaContainer* parent, const char* title);
RygelTestVideoItem* rygel_test_video_item_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title);
static GstElement* rygel_test_video_item_real_create_stream_source (RygelMediaItem* base);



#line 36 "rygel-test-video-item.vala"
RygelTestVideoItem* rygel_test_video_item_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title) {
#line 97 "rygel-test-video-item.c"
	RygelTestVideoItem * self;
#line 36 "rygel-test-video-item.vala"
	g_return_val_if_fail (id != NULL, NULL);
#line 36 "rygel-test-video-item.vala"
	g_return_val_if_fail (parent != NULL, NULL);
#line 36 "rygel-test-video-item.vala"
	g_return_val_if_fail (title != NULL, NULL);
#line 37 "rygel-test-video-item.vala"
	self = (RygelTestVideoItem*) rygel_test_item_construct (object_type, id, parent, title, RYGEL_TEST_VIDEO_ITEM_TEST_MIMETYPE, RYGEL_MEDIA_ITEM_VIDEO_CLASS);
#line 107 "rygel-test-video-item.c"
	return self;
}


#line 36 "rygel-test-video-item.vala"
RygelTestVideoItem* rygel_test_video_item_new (const char* id, RygelMediaContainer* parent, const char* title) {
#line 36 "rygel-test-video-item.vala"
	return rygel_test_video_item_construct (RYGEL_TEST_TYPE_VIDEO_ITEM, id, parent, title);
#line 116 "rygel-test-video-item.c"
}


#line 44 "rygel-test-video-item.vala"
static GstElement* rygel_test_video_item_real_create_stream_source (RygelMediaItem* base) {
#line 122 "rygel-test-video-item.c"
	RygelTestVideoItem * self;
	GstElement* result = NULL;
	GError * _inner_error_;
	self = (RygelTestVideoItem*) base;
	_inner_error_ = NULL;
	{
		GstElement* _tmp0_;
#line 46 "rygel-test-video-item.vala"
		_tmp0_ = gst_parse_bin_from_description (RYGEL_TEST_VIDEO_ITEM_PIPELINE, TRUE, &_inner_error_);
#line 132 "rygel-test-video-item.c"
		if (_inner_error_ != NULL) {
			goto __catch1_g_error;
		}
		result = _tmp0_;
#line 46 "rygel-test-video-item.vala"
		return result;
#line 139 "rygel-test-video-item.c"
	}
	goto __finally1;
	__catch1_g_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
#line 48 "rygel-test-video-item.vala"
			g_warning ("rygel-test-video-item.vala:48: Required plugin missing (%s)", err->message);
#line 150 "rygel-test-video-item.c"
			result = NULL;
			_g_error_free0 (err);
#line 50 "rygel-test-video-item.vala"
			return result;
#line 155 "rygel-test-video-item.c"
		}
	}
	__finally1:
	{
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
}


static void rygel_test_video_item_class_init (RygelTestVideoItemClass * klass) {
	rygel_test_video_item_parent_class = g_type_class_peek_parent (klass);
	RYGEL_MEDIA_ITEM_CLASS (klass)->create_stream_source = rygel_test_video_item_real_create_stream_source;
}


static void rygel_test_video_item_instance_init (RygelTestVideoItem * self) {
}


GType rygel_test_video_item_get_type (void) {
	static volatile gsize rygel_test_video_item_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_test_video_item_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelTestVideoItemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_test_video_item_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelTestVideoItem), 0, (GInstanceInitFunc) rygel_test_video_item_instance_init, NULL };
		GType rygel_test_video_item_type_id;
		rygel_test_video_item_type_id = g_type_register_static (RYGEL_TEST_TYPE_ITEM, "RygelTestVideoItem", &g_define_type_info, 0);
		g_once_init_leave (&rygel_test_video_item_type_id__volatile, rygel_test_video_item_type_id);
	}
	return rygel_test_video_item_type_id__volatile;
}




