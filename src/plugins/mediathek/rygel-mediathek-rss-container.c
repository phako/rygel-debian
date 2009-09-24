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
#include <stdlib.h>
#include <string.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <gee.h>
#include <libxml/xpath.h>


#define RYGEL_TYPE_MEDIATHEK_RSS_CONTAINER (rygel_mediathek_rss_container_get_type ())
#define RYGEL_MEDIATHEK_RSS_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIATHEK_RSS_CONTAINER, RygelMediathekRssContainer))
#define RYGEL_MEDIATHEK_RSS_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIATHEK_RSS_CONTAINER, RygelMediathekRssContainerClass))
#define RYGEL_IS_MEDIATHEK_RSS_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIATHEK_RSS_CONTAINER))
#define RYGEL_IS_MEDIATHEK_RSS_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIATHEK_RSS_CONTAINER))
#define RYGEL_MEDIATHEK_RSS_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIATHEK_RSS_CONTAINER, RygelMediathekRssContainerClass))

typedef struct _RygelMediathekRssContainer RygelMediathekRssContainer;
typedef struct _RygelMediathekRssContainerClass RygelMediathekRssContainerClass;
typedef struct _RygelMediathekRssContainerPrivate RygelMediathekRssContainerPrivate;
#define _soup_date_free0(var) ((var == NULL) ? NULL : (var = (soup_date_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

#define RYGEL_TYPE_MEDIATHEK_VIDEO_ITEM (rygel_mediathek_video_item_get_type ())
#define RYGEL_MEDIATHEK_VIDEO_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIATHEK_VIDEO_ITEM, RygelMediathekVideoItem))
#define RYGEL_MEDIATHEK_VIDEO_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIATHEK_VIDEO_ITEM, RygelMediathekVideoItemClass))
#define RYGEL_IS_MEDIATHEK_VIDEO_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIATHEK_VIDEO_ITEM))
#define RYGEL_IS_MEDIATHEK_VIDEO_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIATHEK_VIDEO_ITEM))
#define RYGEL_MEDIATHEK_VIDEO_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIATHEK_VIDEO_ITEM, RygelMediathekVideoItemClass))

typedef struct _RygelMediathekVideoItem RygelMediathekVideoItem;
typedef struct _RygelMediathekVideoItemClass RygelMediathekVideoItemClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _xmlXPathFreeContext0(var) ((var == NULL) ? NULL : (var = (xmlXPathFreeContext (var), NULL)))

#define RYGEL_TYPE_MEDIATHEK_ROOT_CONTAINER (rygel_mediathek_root_container_get_type ())
#define RYGEL_MEDIATHEK_ROOT_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIATHEK_ROOT_CONTAINER, RygelMediathekRootContainer))
#define RYGEL_MEDIATHEK_ROOT_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIATHEK_ROOT_CONTAINER, RygelMediathekRootContainerClass))
#define RYGEL_IS_MEDIATHEK_ROOT_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIATHEK_ROOT_CONTAINER))
#define RYGEL_IS_MEDIATHEK_ROOT_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIATHEK_ROOT_CONTAINER))
#define RYGEL_MEDIATHEK_ROOT_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIATHEK_ROOT_CONTAINER, RygelMediathekRootContainerClass))

typedef struct _RygelMediathekRootContainer RygelMediathekRootContainer;
typedef struct _RygelMediathekRootContainerClass RygelMediathekRootContainerClass;
typedef struct _RygelMediathekRootContainerPrivate RygelMediathekRootContainerPrivate;

struct _RygelMediathekRssContainer {
	RygelSimpleContainer parent_instance;
	RygelMediathekRssContainerPrivate * priv;
};

struct _RygelMediathekRssContainerClass {
	RygelSimpleContainerClass parent_class;
};

struct _RygelMediathekRssContainerPrivate {
	guint zdf_content_id;
	SoupDate* last_modified;
};

typedef enum  {
	RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR_XML_PARSE_ERROR
} RygelMediathekVideoItemError;
#define RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR rygel_mediathek_video_item_error_quark ()
struct _RygelMediathekRootContainer {
	RygelSimpleContainer parent_instance;
	RygelMediathekRootContainerPrivate * priv;
	SoupSessionAsync* session;
};

struct _RygelMediathekRootContainerClass {
	RygelSimpleContainerClass parent_class;
};


static gpointer rygel_mediathek_rss_container_parent_class = NULL;

GType rygel_mediathek_rss_container_get_type (void);
#define RYGEL_MEDIATHEK_RSS_CONTAINER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_MEDIATHEK_RSS_CONTAINER, RygelMediathekRssContainerPrivate))
enum  {
	RYGEL_MEDIATHEK_RSS_CONTAINER_DUMMY_PROPERTY
};
static gboolean rygel_mediathek_rss_container_parse_response (RygelMediathekRssContainer* self, const char* data, gsize length);
static void rygel_mediathek_rss_container_on_feed_got (RygelMediathekRssContainer* self, SoupSession* session, SoupMessage* msg);
GType rygel_mediathek_video_item_get_type (void);
GQuark rygel_mediathek_video_item_error_quark (void);
RygelMediathekVideoItem* rygel_mediathek_video_item_create_from_xml (RygelMediaContainer* parent, xmlNode* item, GError** error);
GType rygel_mediathek_root_container_get_type (void);
static void _rygel_mediathek_rss_container_on_feed_got_soup_session_callback (SoupSession* session, SoupMessage* msg, gpointer self);
void rygel_mediathek_rss_container_update (RygelMediathekRssContainer* self);
RygelMediathekRssContainer* rygel_mediathek_rss_container_new (RygelMediaContainer* parent, guint id);
RygelMediathekRssContainer* rygel_mediathek_rss_container_construct (GType object_type, RygelMediaContainer* parent, guint id);
static void rygel_mediathek_rss_container_finalize (GObject* obj);



static void rygel_mediathek_rss_container_on_feed_got (RygelMediathekRssContainer* self, SoupSession* session, SoupMessage* msg) {
	guint _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (session != NULL);
	g_return_if_fail (msg != NULL);
	switch ((g_object_get (msg, "status-code", &_tmp0_, NULL), _tmp0_)) {
		case 304:
		{
			g_message ("rygel-mediathek-rss-container.vala:34: Feed has not changed, nothing to do");
			break;
		}
		case 200:
		{
			if (rygel_mediathek_rss_container_parse_response (self, msg->response_body->data, (gsize) msg->response_body->length)) {
				SoupDate* _tmp1_;
				self->priv->last_modified = (_tmp1_ = soup_date_new_from_string (soup_message_headers_get (msg->response_headers, "Date")), _soup_date_free0 (self->priv->last_modified), _tmp1_);
			}
			break;
		}
		default:
		{
			guint _tmp2_;
			guint _tmp3_;
			g_warning ("rygel-mediathek-rss-container.vala:45: Got unexpected response %u (%s)", (g_object_get (msg, "status-code", &_tmp2_, NULL), _tmp2_), soup_status_get_phrase ((g_object_get (msg, "status-code", &_tmp3_, NULL), _tmp3_)));
			break;
		}
	}
}


static gboolean rygel_mediathek_rss_container_parse_response (RygelMediathekRssContainer* self, const char* data, gsize length) {
	gboolean result;
	GError * _inner_error_;
	gboolean ret;
	xmlDoc* doc;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (data != NULL, FALSE);
	_inner_error_ = NULL;
	ret = FALSE;
	doc = xmlParseMemory (data, (gint) length);
	if (doc != NULL) {
		xmlXPathContext* ctx;
		xmlXPathObject* xpo;
		gboolean _tmp0_;
		gee_abstract_collection_clear ((GeeAbstractCollection*) ((RygelSimpleContainer*) self)->children);
		((RygelMediaContainer*) self)->child_count = (guint) 0;
		ctx = xmlXPathNewContext (doc);
		xpo = xmlXPathEval ("/rss/channel/title", ctx);
		_tmp0_ = FALSE;
		if (xpo->type == XPATH_NODESET) {
			_tmp0_ = xmlXPathNodeSetGetLength (xpo->nodesetval) > 0;
		} else {
			_tmp0_ = FALSE;
		}
		if (_tmp0_) {
			char* _tmp1_;
			((RygelMediaObject*) self)->title = (_tmp1_ = xmlNodeGetContent (xmlXPathNodeSetItem (xpo->nodesetval, 0)), _g_free0 (((RygelMediaObject*) self)->title), _tmp1_);
		}
		xpo = xmlXPathEval ("/rss/channel/item", ctx);
		if (xpo->type == XPATH_NODESET) {
			{
				gint i;
				i = 0;
				{
					gboolean _tmp2_;
					_tmp2_ = TRUE;
					while (TRUE) {
						xmlNode* node;
						if (!_tmp2_) {
							i++;
						}
						_tmp2_ = FALSE;
						if (!(i < xmlXPathNodeSetGetLength (xpo->nodesetval))) {
							break;
						}
						node = xmlXPathNodeSetItem (xpo->nodesetval, i);
						{
							RygelMediathekVideoItem* item;
							item = rygel_mediathek_video_item_create_from_xml ((RygelMediaContainer*) self, node, &_inner_error_);
							if (_inner_error_ != NULL) {
								if (_inner_error_->domain == RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR) {
									goto __catch3_rygel_mediathek_video_item_error;
								}
								goto __finally3;
							}
							rygel_simple_container_add_child ((RygelSimpleContainer*) self, (RygelMediaObject*) item);
							ret = TRUE;
							_g_object_unref0 (item);
						}
						goto __finally3;
						__catch3_rygel_mediathek_video_item_error:
						{
							GError * _error_;
							_error_ = _inner_error_;
							_inner_error_ = NULL;
							{
								g_warning ("rygel-mediathek-rss-container.vala:79: Error creating video item: %s", _error_->message);
								_g_error_free0 (_error_);
							}
						}
						__finally3:
						if (_inner_error_ != NULL) {
							_xmlXPathFreeContext0 (ctx);
							g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
							g_clear_error (&_inner_error_);
							return FALSE;
						}
					}
				}
			}
		} else {
			g_warning ("rygel-mediathek-rss-container.vala:85: XPath query failed");
		}
		xmlFreeDoc (doc);
		rygel_media_container_updated ((RygelMediaContainer*) self);
		_xmlXPathFreeContext0 (ctx);
	} else {
		g_warning ("rygel-mediathek-rss-container.vala:92: Failed to parse doc");
	}
	result = ret;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _rygel_mediathek_rss_container_on_feed_got_soup_session_callback (SoupSession* session, SoupMessage* msg, gpointer self) {
	rygel_mediathek_rss_container_on_feed_got (self, session, msg);
}


void rygel_mediathek_rss_container_update (RygelMediathekRssContainer* self) {
	char* _tmp0_;
	SoupMessage* _tmp1_;
	SoupMessage* message;
	g_return_if_fail (self != NULL);
	message = (_tmp1_ = soup_message_new ("GET", _tmp0_ = g_strdup_printf ("http://www.zdf.de/ZDFmediathek/content/%u?view=rss", self->priv->zdf_content_id)), _g_free0 (_tmp0_), _tmp1_);
	if (self->priv->last_modified != NULL) {
		g_debug ("rygel-mediathek-rss-container.vala:103: Requesting change since %s", soup_date_to_string (self->priv->last_modified, SOUP_DATE_HTTP));
		soup_message_headers_append (message->request_headers, "If-Modified-Since", soup_date_to_string (self->priv->last_modified, SOUP_DATE_HTTP));
	}
	soup_session_queue_message ((SoupSession*) RYGEL_MEDIATHEK_ROOT_CONTAINER (((RygelMediaObject*) self)->parent)->session, _g_object_ref0 (message), _rygel_mediathek_rss_container_on_feed_got_soup_session_callback, self);
	_g_object_unref0 (message);
}


RygelMediathekRssContainer* rygel_mediathek_rss_container_construct (GType object_type, RygelMediaContainer* parent, guint id) {
	RygelMediathekRssContainer * self;
	char* _tmp1_;
	char* _tmp0_;
	g_return_val_if_fail (parent != NULL, NULL);
	self = (RygelMediathekRssContainer*) rygel_simple_container_construct (object_type, _tmp0_ = g_strdup_printf ("GroupId:%u", id), parent, _tmp1_ = g_strdup_printf ("ZDF Mediathek RSS feed %u", id));
	_g_free0 (_tmp1_);
	_g_free0 (_tmp0_);
	self->priv->zdf_content_id = id;
	rygel_mediathek_rss_container_update (self);
	return self;
}


RygelMediathekRssContainer* rygel_mediathek_rss_container_new (RygelMediaContainer* parent, guint id) {
	return rygel_mediathek_rss_container_construct (RYGEL_TYPE_MEDIATHEK_RSS_CONTAINER, parent, id);
}


static void rygel_mediathek_rss_container_class_init (RygelMediathekRssContainerClass * klass) {
	rygel_mediathek_rss_container_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelMediathekRssContainerPrivate));
	G_OBJECT_CLASS (klass)->finalize = rygel_mediathek_rss_container_finalize;
}


static void rygel_mediathek_rss_container_instance_init (RygelMediathekRssContainer * self) {
	self->priv = RYGEL_MEDIATHEK_RSS_CONTAINER_GET_PRIVATE (self);
	self->priv->last_modified = NULL;
}


static void rygel_mediathek_rss_container_finalize (GObject* obj) {
	RygelMediathekRssContainer * self;
	self = RYGEL_MEDIATHEK_RSS_CONTAINER (obj);
	_soup_date_free0 (self->priv->last_modified);
	G_OBJECT_CLASS (rygel_mediathek_rss_container_parent_class)->finalize (obj);
}


GType rygel_mediathek_rss_container_get_type (void) {
	static GType rygel_mediathek_rss_container_type_id = 0;
	if (rygel_mediathek_rss_container_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediathekRssContainerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_mediathek_rss_container_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediathekRssContainer), 0, (GInstanceInitFunc) rygel_mediathek_rss_container_instance_init, NULL };
		rygel_mediathek_rss_container_type_id = g_type_register_static (RYGEL_TYPE_SIMPLE_CONTAINER, "RygelMediathekRssContainer", &g_define_type_info, 0);
	}
	return rygel_mediathek_rss_container_type_id;
}




