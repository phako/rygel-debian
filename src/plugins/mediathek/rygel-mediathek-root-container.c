/*
 * Copyright (C) 2009 Jens Georg
 *
 * Author: Jens Georg <mail@jensge.org>
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
#include <libsoup/soup.h>
#include <gee.h>


#define RYGEL_TYPE_MEDIATHEK_ROOT_CONTAINER (rygel_mediathek_root_container_get_type ())
#define RYGEL_MEDIATHEK_ROOT_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIATHEK_ROOT_CONTAINER, RygelMediathekRootContainer))
#define RYGEL_MEDIATHEK_ROOT_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIATHEK_ROOT_CONTAINER, RygelMediathekRootContainerClass))
#define RYGEL_IS_MEDIATHEK_ROOT_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIATHEK_ROOT_CONTAINER))
#define RYGEL_IS_MEDIATHEK_ROOT_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIATHEK_ROOT_CONTAINER))
#define RYGEL_MEDIATHEK_ROOT_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIATHEK_ROOT_CONTAINER, RygelMediathekRootContainerClass))

typedef struct _RygelMediathekRootContainer RygelMediathekRootContainer;
typedef struct _RygelMediathekRootContainerClass RygelMediathekRootContainerClass;
typedef struct _RygelMediathekRootContainerPrivate RygelMediathekRootContainerPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define RYGEL_TYPE_MEDIATHEK_RSS_CONTAINER (rygel_mediathek_rss_container_get_type ())
#define RYGEL_MEDIATHEK_RSS_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIATHEK_RSS_CONTAINER, RygelMediathekRssContainer))
#define RYGEL_MEDIATHEK_RSS_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIATHEK_RSS_CONTAINER, RygelMediathekRssContainerClass))
#define RYGEL_IS_MEDIATHEK_RSS_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIATHEK_RSS_CONTAINER))
#define RYGEL_IS_MEDIATHEK_RSS_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIATHEK_RSS_CONTAINER))
#define RYGEL_MEDIATHEK_RSS_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIATHEK_RSS_CONTAINER, RygelMediathekRssContainerClass))

typedef struct _RygelMediathekRssContainer RygelMediathekRssContainer;
typedef struct _RygelMediathekRssContainerClass RygelMediathekRssContainerClass;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _RygelMediathekRootContainer {
	RygelSimpleContainer parent_instance;
	RygelMediathekRootContainerPrivate * priv;
	SoupSessionAsync* session;
};

struct _RygelMediathekRootContainerClass {
	RygelSimpleContainerClass parent_class;
};


static RygelMediathekRootContainer* rygel_mediathek_root_container_instance;
static RygelMediathekRootContainer* rygel_mediathek_root_container_instance = NULL;
static gpointer rygel_mediathek_root_container_parent_class = NULL;

GType rygel_mediathek_root_container_get_type (void);
enum  {
	RYGEL_MEDIATHEK_ROOT_CONTAINER_DUMMY_PROPERTY
};
GType rygel_mediathek_rss_container_get_type (void);
void rygel_mediathek_rss_container_update (RygelMediathekRssContainer* self);
static gboolean rygel_mediathek_root_container_on_schedule_update (RygelMediathekRootContainer* self);
static RygelMediathekRootContainer* rygel_mediathek_root_container_new (void);
static RygelMediathekRootContainer* rygel_mediathek_root_container_construct (GType object_type);
RygelMediathekRootContainer* rygel_mediathek_root_container_get_instance (void);
RygelMediathekRssContainer* rygel_mediathek_rss_container_new (RygelMediaContainer* parent, guint id);
RygelMediathekRssContainer* rygel_mediathek_rss_container_construct (GType object_type, RygelMediaContainer* parent, guint id);
static gboolean _rygel_mediathek_root_container_on_schedule_update_gsource_func (gpointer self);
static void rygel_mediathek_root_container_finalize (GObject* obj);



static gboolean rygel_mediathek_root_container_on_schedule_update (RygelMediathekRootContainer* self) {
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	g_message ("rygel-mediathek-root-container.vala:31: Scheduling update for all feeds....");
	{
		GeeIterator* _container_it;
		_container_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) ((RygelSimpleContainer*) self)->children);
		while (TRUE) {
			RygelMediaObject* container;
			if (!gee_iterator_next (_container_it)) {
				break;
			}
			container = (RygelMediaObject*) gee_iterator_get (_container_it);
			rygel_mediathek_rss_container_update (RYGEL_MEDIATHEK_RSS_CONTAINER (container));
			_g_object_unref0 (container);
		}
		_g_object_unref0 (_container_it);
	}
	result = TRUE;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


RygelMediathekRootContainer* rygel_mediathek_root_container_get_instance (void) {
	RygelMediathekRootContainer* result;
	if (rygel_mediathek_root_container_instance == NULL) {
		RygelMediathekRootContainer* _tmp0_;
		rygel_mediathek_root_container_instance = (_tmp0_ = rygel_mediathek_root_container_new (), _g_object_unref0 (rygel_mediathek_root_container_instance), _tmp0_);
	}
	result = _g_object_ref0 (rygel_mediathek_root_container_instance);
	return result;
}


static gboolean _rygel_mediathek_root_container_on_schedule_update_gsource_func (gpointer self) {
	return rygel_mediathek_root_container_on_schedule_update (self);
}


static RygelMediathekRootContainer* rygel_mediathek_root_container_construct (GType object_type) {
	GError * _inner_error_;
	RygelMediathekRootContainer * self;
	SoupSessionAsync* _tmp0_;
	GeeArrayList* feeds;
	RygelMetaConfig* config;
	_inner_error_ = NULL;
	self = (RygelMediathekRootContainer*) rygel_simple_container_construct_root (object_type, "ZDF Mediathek");
	self->session = (_tmp0_ = (SoupSessionAsync*) soup_session_async_new (), _g_object_unref0 (self->session), _tmp0_);
	feeds = NULL;
	config = rygel_meta_config_get_default ();
	{
		GeeArrayList* _tmp1_;
		GeeArrayList* _tmp2_;
		_tmp1_ = rygel_configuration_get_int_list ((RygelConfiguration*) config, "ZDFMediathek", "rss", &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch2_g_error;
			goto __finally2;
		}
		feeds = (_tmp2_ = _tmp1_, _g_object_unref0 (feeds), _tmp2_);
	}
	goto __finally2;
	__catch2_g_error:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
			GeeArrayList* _tmp3_;
			feeds = (_tmp3_ = gee_array_list_new (G_TYPE_INT, NULL, NULL, g_direct_equal), _g_object_unref0 (feeds), _tmp3_);
			_g_error_free0 (_error_);
		}
	}
	__finally2:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (feeds);
		_g_object_unref0 (config);
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	if (gee_collection_get_size ((GeeCollection*) feeds) == 0) {
		g_message ("rygel-mediathek-root-container.vala:60: Could not get RSS items from GConf, using defaults");
		gee_abstract_collection_add ((GeeAbstractCollection*) feeds, GINT_TO_POINTER (508));
	}
	{
		GeeIterator* _id_it;
		_id_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) feeds);
		while (TRUE) {
			gint id;
			RygelMediathekRssContainer* _tmp4_;
			if (!gee_iterator_next (_id_it)) {
				break;
			}
			id = GPOINTER_TO_INT (gee_iterator_get (_id_it));
			rygel_simple_container_add_child ((RygelSimpleContainer*) self, (RygelMediaObject*) (_tmp4_ = rygel_mediathek_rss_container_new ((RygelMediaContainer*) self, (guint) id)));
			_g_object_unref0 (_tmp4_);
		}
		_g_object_unref0 (_id_it);
	}
	g_timeout_add_seconds ((guint) 1800, _rygel_mediathek_root_container_on_schedule_update_gsource_func, self);
	_g_object_unref0 (feeds);
	_g_object_unref0 (config);
	return self;
}


static RygelMediathekRootContainer* rygel_mediathek_root_container_new (void) {
	return rygel_mediathek_root_container_construct (RYGEL_TYPE_MEDIATHEK_ROOT_CONTAINER);
}


static void rygel_mediathek_root_container_class_init (RygelMediathekRootContainerClass * klass) {
	rygel_mediathek_root_container_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = rygel_mediathek_root_container_finalize;
}


static void rygel_mediathek_root_container_instance_init (RygelMediathekRootContainer * self) {
}


static void rygel_mediathek_root_container_finalize (GObject* obj) {
	RygelMediathekRootContainer * self;
	self = RYGEL_MEDIATHEK_ROOT_CONTAINER (obj);
	_g_object_unref0 (self->session);
	G_OBJECT_CLASS (rygel_mediathek_root_container_parent_class)->finalize (obj);
}


GType rygel_mediathek_root_container_get_type (void) {
	static GType rygel_mediathek_root_container_type_id = 0;
	if (rygel_mediathek_root_container_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediathekRootContainerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_mediathek_root_container_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediathekRootContainer), 0, (GInstanceInitFunc) rygel_mediathek_root_container_instance_init, NULL };
		rygel_mediathek_root_container_type_id = g_type_register_static (RYGEL_TYPE_SIMPLE_CONTAINER, "RygelMediathekRootContainer", &g_define_type_info, 0);
	}
	return rygel_mediathek_root_container_type_id;
}




