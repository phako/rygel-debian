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


#define RYGEL_TYPE_TEST_ROOT_CONTAINER (rygel_test_root_container_get_type ())
#define RYGEL_TEST_ROOT_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TEST_ROOT_CONTAINER, RygelTestRootContainer))
#define RYGEL_TEST_ROOT_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TEST_ROOT_CONTAINER, RygelTestRootContainerClass))
#define RYGEL_IS_TEST_ROOT_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TEST_ROOT_CONTAINER))
#define RYGEL_IS_TEST_ROOT_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TEST_ROOT_CONTAINER))
#define RYGEL_TEST_ROOT_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TEST_ROOT_CONTAINER, RygelTestRootContainerClass))

typedef struct _RygelTestRootContainer RygelTestRootContainer;
typedef struct _RygelTestRootContainerClass RygelTestRootContainerClass;
typedef struct _RygelTestRootContainerPrivate RygelTestRootContainerPrivate;

#define RYGEL_TYPE_TEST_ITEM (rygel_test_item_get_type ())
#define RYGEL_TEST_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TEST_ITEM, RygelTestItem))
#define RYGEL_TEST_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TEST_ITEM, RygelTestItemClass))
#define RYGEL_IS_TEST_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TEST_ITEM))
#define RYGEL_IS_TEST_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TEST_ITEM))
#define RYGEL_TEST_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TEST_ITEM, RygelTestItemClass))

typedef struct _RygelTestItem RygelTestItem;
typedef struct _RygelTestItemClass RygelTestItemClass;

#define RYGEL_TYPE_TEST_AUDIO_ITEM (rygel_test_audio_item_get_type ())
#define RYGEL_TEST_AUDIO_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TEST_AUDIO_ITEM, RygelTestAudioItem))
#define RYGEL_TEST_AUDIO_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TEST_AUDIO_ITEM, RygelTestAudioItemClass))
#define RYGEL_IS_TEST_AUDIO_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TEST_AUDIO_ITEM))
#define RYGEL_IS_TEST_AUDIO_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TEST_AUDIO_ITEM))
#define RYGEL_TEST_AUDIO_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TEST_AUDIO_ITEM, RygelTestAudioItemClass))

typedef struct _RygelTestAudioItem RygelTestAudioItem;
typedef struct _RygelTestAudioItemClass RygelTestAudioItemClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define RYGEL_TYPE_TEST_VIDEO_ITEM (rygel_test_video_item_get_type ())
#define RYGEL_TEST_VIDEO_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TEST_VIDEO_ITEM, RygelTestVideoItem))
#define RYGEL_TEST_VIDEO_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TEST_VIDEO_ITEM, RygelTestVideoItemClass))
#define RYGEL_IS_TEST_VIDEO_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TEST_VIDEO_ITEM))
#define RYGEL_IS_TEST_VIDEO_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TEST_VIDEO_ITEM))
#define RYGEL_TEST_VIDEO_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TEST_VIDEO_ITEM, RygelTestVideoItemClass))

typedef struct _RygelTestVideoItem RygelTestVideoItem;
typedef struct _RygelTestVideoItemClass RygelTestVideoItemClass;

struct _RygelTestRootContainer {
	RygelSimpleContainer parent_instance;
	RygelTestRootContainerPrivate * priv;
};

struct _RygelTestRootContainerClass {
	RygelSimpleContainerClass parent_class;
};


static gpointer rygel_test_root_container_parent_class = NULL;

GType rygel_test_root_container_get_type (void);
enum  {
	RYGEL_TEST_ROOT_CONTAINER_DUMMY_PROPERTY
};
RygelTestAudioItem* rygel_test_audio_item_new (const char* id, RygelMediaContainer* parent, const char* title);
RygelTestAudioItem* rygel_test_audio_item_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title);
GType rygel_test_item_get_type (void);
GType rygel_test_audio_item_get_type (void);
RygelTestVideoItem* rygel_test_video_item_new (const char* id, RygelMediaContainer* parent, const char* title);
RygelTestVideoItem* rygel_test_video_item_construct (GType object_type, const char* id, RygelMediaContainer* parent, const char* title);
GType rygel_test_video_item_get_type (void);
RygelTestRootContainer* rygel_test_root_container_new (const char* title);
RygelTestRootContainer* rygel_test_root_container_construct (GType object_type, const char* title);



RygelTestRootContainer* rygel_test_root_container_construct (GType object_type, const char* title) {
	RygelTestRootContainer * self;
	RygelTestAudioItem* _tmp0_;
	RygelTestVideoItem* _tmp1_;
	g_return_val_if_fail (title != NULL, NULL);
	self = (RygelTestRootContainer*) rygel_simple_container_construct_root (object_type, title);
	rygel_simple_container_add_child ((RygelSimpleContainer*) self, (RygelMediaObject*) (_tmp0_ = rygel_test_audio_item_new ("sinewave", (RygelMediaContainer*) self, "Sine Wave")));
	_g_object_unref0 (_tmp0_);
	rygel_simple_container_add_child ((RygelSimpleContainer*) self, (RygelMediaObject*) (_tmp1_ = rygel_test_video_item_new ("smtpe", (RygelMediaContainer*) self, "SMTPE")));
	_g_object_unref0 (_tmp1_);
	return self;
}


RygelTestRootContainer* rygel_test_root_container_new (const char* title) {
	return rygel_test_root_container_construct (RYGEL_TYPE_TEST_ROOT_CONTAINER, title);
}


static void rygel_test_root_container_class_init (RygelTestRootContainerClass * klass) {
	rygel_test_root_container_parent_class = g_type_class_peek_parent (klass);
}


static void rygel_test_root_container_instance_init (RygelTestRootContainer * self) {
}


GType rygel_test_root_container_get_type (void) {
	static GType rygel_test_root_container_type_id = 0;
	if (rygel_test_root_container_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelTestRootContainerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_test_root_container_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelTestRootContainer), 0, (GInstanceInitFunc) rygel_test_root_container_instance_init, NULL };
		rygel_test_root_container_type_id = g_type_register_static (RYGEL_TYPE_SIMPLE_CONTAINER, "RygelTestRootContainer", &g_define_type_info, 0);
	}
	return rygel_test_root_container_type_id;
}




