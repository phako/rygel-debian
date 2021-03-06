/* rygel-mediathek-rss-container.c generated by valac, the Vala compiler
 * generated from rygel-mediathek-rss-container.vala, do not modify */

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


#define RYGEL_MEDIATHEK_TYPE_RSS_CONTAINER (rygel_mediathek_rss_container_get_type ())
#define RYGEL_MEDIATHEK_RSS_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_MEDIATHEK_TYPE_RSS_CONTAINER, RygelMediathekRssContainer))
#define RYGEL_MEDIATHEK_RSS_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_MEDIATHEK_TYPE_RSS_CONTAINER, RygelMediathekRssContainerClass))
#define RYGEL_MEDIATHEK_IS_RSS_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_MEDIATHEK_TYPE_RSS_CONTAINER))
#define RYGEL_MEDIATHEK_IS_RSS_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_MEDIATHEK_TYPE_RSS_CONTAINER))
#define RYGEL_MEDIATHEK_RSS_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_MEDIATHEK_TYPE_RSS_CONTAINER, RygelMediathekRssContainerClass))

typedef struct _RygelMediathekRssContainer RygelMediathekRssContainer;
typedef struct _RygelMediathekRssContainerClass RygelMediathekRssContainerClass;
typedef struct _RygelMediathekRssContainerPrivate RygelMediathekRssContainerPrivate;
#define _soup_date_free0(var) ((var == NULL) ? NULL : (var = (soup_date_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

#define RYGEL_MEDIATHEK_TYPE_VIDEO_ITEM (rygel_mediathek_video_item_get_type ())
#define RYGEL_MEDIATHEK_VIDEO_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_MEDIATHEK_TYPE_VIDEO_ITEM, RygelMediathekVideoItem))
#define RYGEL_MEDIATHEK_VIDEO_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_MEDIATHEK_TYPE_VIDEO_ITEM, RygelMediathekVideoItemClass))
#define RYGEL_MEDIATHEK_IS_VIDEO_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_MEDIATHEK_TYPE_VIDEO_ITEM))
#define RYGEL_MEDIATHEK_IS_VIDEO_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_MEDIATHEK_TYPE_VIDEO_ITEM))
#define RYGEL_MEDIATHEK_VIDEO_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_MEDIATHEK_TYPE_VIDEO_ITEM, RygelMediathekVideoItemClass))

typedef struct _RygelMediathekVideoItem RygelMediathekVideoItem;
typedef struct _RygelMediathekVideoItemClass RygelMediathekVideoItemClass;
#define _xmlXPathFreeContext0(var) ((var == NULL) ? NULL : (var = (xmlXPathFreeContext (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

#define RYGEL_MEDIATHEK_TYPE_ROOT_CONTAINER (rygel_mediathek_root_container_get_type ())
#define RYGEL_MEDIATHEK_ROOT_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_MEDIATHEK_TYPE_ROOT_CONTAINER, RygelMediathekRootContainer))
#define RYGEL_MEDIATHEK_ROOT_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_MEDIATHEK_TYPE_ROOT_CONTAINER, RygelMediathekRootContainerClass))
#define RYGEL_MEDIATHEK_IS_ROOT_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_MEDIATHEK_TYPE_ROOT_CONTAINER))
#define RYGEL_MEDIATHEK_IS_ROOT_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_MEDIATHEK_TYPE_ROOT_CONTAINER))
#define RYGEL_MEDIATHEK_ROOT_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_MEDIATHEK_TYPE_ROOT_CONTAINER, RygelMediathekRootContainerClass))

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

GType rygel_mediathek_rss_container_get_type (void) G_GNUC_CONST;
#define RYGEL_MEDIATHEK_RSS_CONTAINER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_MEDIATHEK_TYPE_RSS_CONTAINER, RygelMediathekRssContainerPrivate))
enum  {
	RYGEL_MEDIATHEK_RSS_CONTAINER_DUMMY_PROPERTY
};
static gboolean rygel_mediathek_rss_container_parse_response (RygelMediathekRssContainer* self, const char* data, gsize length);
static void rygel_mediathek_rss_container_on_feed_got (RygelMediathekRssContainer* self, SoupSession* session, SoupMessage* msg);
GType rygel_mediathek_video_item_get_type (void) G_GNUC_CONST;
GQuark rygel_mediathek_video_item_error_quark (void);
RygelMediathekVideoItem* rygel_mediathek_video_item_create_from_xml (RygelMediaContainer* parent, xmlNode* item, GError** error);
GType rygel_mediathek_root_container_get_type (void) G_GNUC_CONST;
static void _rygel_mediathek_rss_container_on_feed_got_soup_session_callback (SoupSession* session, SoupMessage* msg, gpointer self);
void rygel_mediathek_rss_container_update (RygelMediathekRssContainer* self);
RygelMediathekRssContainer* rygel_mediathek_rss_container_new (RygelMediaContainer* parent, guint id);
RygelMediathekRssContainer* rygel_mediathek_rss_container_construct (GType object_type, RygelMediaContainer* parent, guint id);
static void rygel_mediathek_rss_container_finalize (GObject* obj);



#line 31 "rygel-mediathek-rss-container.vala"
static void rygel_mediathek_rss_container_on_feed_got (RygelMediathekRssContainer* self, SoupSession* session, SoupMessage* msg) {
#line 128 "rygel-mediathek-rss-container.c"
	guint _tmp0_;
#line 31 "rygel-mediathek-rss-container.vala"
	g_return_if_fail (self != NULL);
#line 31 "rygel-mediathek-rss-container.vala"
	g_return_if_fail (session != NULL);
#line 31 "rygel-mediathek-rss-container.vala"
	g_return_if_fail (msg != NULL);
#line 32 "rygel-mediathek-rss-container.vala"
	switch ((g_object_get (msg, "status-code", &_tmp0_, NULL), _tmp0_)) {
#line 138 "rygel-mediathek-rss-container.c"
		case 304:
		{
#line 34 "rygel-mediathek-rss-container.vala"
			g_message ("rygel-mediathek-rss-container.vala:34: Feed has not changed, nothing t" \
"o do");
#line 35 "rygel-mediathek-rss-container.vala"
			break;
#line 145 "rygel-mediathek-rss-container.c"
		}
		case 200:
		{
#line 37 "rygel-mediathek-rss-container.vala"
			if (rygel_mediathek_rss_container_parse_response (self, (const char*) msg->response_body->data, (gsize) msg->response_body->length)) {
#line 151 "rygel-mediathek-rss-container.c"
				SoupDate* _tmp1_;
#line 39 "rygel-mediathek-rss-container.vala"
				self->priv->last_modified = (_tmp1_ = soup_date_new_from_string (soup_message_headers_get (msg->response_headers, "Date")), _soup_date_free0 (self->priv->last_modified), _tmp1_);
#line 155 "rygel-mediathek-rss-container.c"
			}
#line 42 "rygel-mediathek-rss-container.vala"
			break;
#line 159 "rygel-mediathek-rss-container.c"
		}
		default:
		{
			guint _tmp2_;
			guint _tmp3_;
#line 45 "rygel-mediathek-rss-container.vala"
			g_warning ("rygel-mediathek-rss-container.vala:45: Got unexpected response %u (%s)", (g_object_get (msg, "status-code", &_tmp2_, NULL), _tmp2_), soup_status_get_phrase ((g_object_get (msg, "status-code", &_tmp3_, NULL), _tmp3_)));
#line 48 "rygel-mediathek-rss-container.vala"
			break;
#line 169 "rygel-mediathek-rss-container.c"
		}
	}
}


#line 52 "rygel-mediathek-rss-container.vala"
static gboolean rygel_mediathek_rss_container_parse_response (RygelMediathekRssContainer* self, const char* data, gsize length) {
#line 177 "rygel-mediathek-rss-container.c"
	gboolean result = FALSE;
	GError * _inner_error_;
	gboolean ret;
	xmlDoc* doc;
#line 52 "rygel-mediathek-rss-container.vala"
	g_return_val_if_fail (self != NULL, FALSE);
#line 52 "rygel-mediathek-rss-container.vala"
	g_return_val_if_fail (data != NULL, FALSE);
#line 186 "rygel-mediathek-rss-container.c"
	_inner_error_ = NULL;
#line 53 "rygel-mediathek-rss-container.vala"
	ret = FALSE;
#line 54 "rygel-mediathek-rss-container.vala"
	doc = xmlParseMemory (data, (gint) length);
#line 55 "rygel-mediathek-rss-container.vala"
	if (doc != NULL) {
#line 194 "rygel-mediathek-rss-container.c"
		xmlXPathContext* ctx;
		xmlXPathObject* xpo;
		gboolean _tmp0_ = FALSE;
#line 56 "rygel-mediathek-rss-container.vala"
		gee_abstract_collection_clear ((GeeAbstractCollection*) ((RygelSimpleContainer*) self)->children);
#line 57 "rygel-mediathek-rss-container.vala"
		((RygelMediaContainer*) self)->child_count = 0;
#line 59 "rygel-mediathek-rss-container.vala"
		ctx = xmlXPathNewContext (doc);
#line 60 "rygel-mediathek-rss-container.vala"
		xpo = xmlXPathEval ("/rss/channel/title", ctx);
#line 61 "rygel-mediathek-rss-container.vala"
		if (xpo->type == XPATH_NODESET) {
#line 62 "rygel-mediathek-rss-container.vala"
			_tmp0_ = xmlXPathNodeSetGetLength (xpo->nodesetval) > 0;
#line 210 "rygel-mediathek-rss-container.c"
		} else {
#line 61 "rygel-mediathek-rss-container.vala"
			_tmp0_ = FALSE;
#line 214 "rygel-mediathek-rss-container.c"
		}
#line 61 "rygel-mediathek-rss-container.vala"
		if (_tmp0_) {
#line 218 "rygel-mediathek-rss-container.c"
			char* _tmp1_;
#line 64 "rygel-mediathek-rss-container.vala"
			rygel_media_object_set_title ((RygelMediaObject*) self, _tmp1_ = xmlNodeGetContent (xmlXPathNodeSetItem (xpo->nodesetval, 0)));
#line 222 "rygel-mediathek-rss-container.c"
			_g_free0 (_tmp1_);
		}
#line 67 "rygel-mediathek-rss-container.vala"
		xpo = xmlXPathEval ("/rss/channel/item", ctx);
#line 68 "rygel-mediathek-rss-container.vala"
		if (xpo->type == XPATH_NODESET) {
#line 229 "rygel-mediathek-rss-container.c"
			{
				gint i;
#line 69 "rygel-mediathek-rss-container.vala"
				i = 0;
#line 234 "rygel-mediathek-rss-container.c"
				{
					gboolean _tmp2_;
#line 69 "rygel-mediathek-rss-container.vala"
					_tmp2_ = TRUE;
#line 69 "rygel-mediathek-rss-container.vala"
					while (TRUE) {
#line 241 "rygel-mediathek-rss-container.c"
						xmlNode* node;
#line 69 "rygel-mediathek-rss-container.vala"
						if (!_tmp2_) {
#line 69 "rygel-mediathek-rss-container.vala"
							i++;
#line 247 "rygel-mediathek-rss-container.c"
						}
#line 69 "rygel-mediathek-rss-container.vala"
						_tmp2_ = FALSE;
#line 69 "rygel-mediathek-rss-container.vala"
						if (!(i < xmlXPathNodeSetGetLength (xpo->nodesetval))) {
#line 69 "rygel-mediathek-rss-container.vala"
							break;
#line 255 "rygel-mediathek-rss-container.c"
						}
#line 70 "rygel-mediathek-rss-container.vala"
						node = xmlXPathNodeSetItem (xpo->nodesetval, i);
#line 259 "rygel-mediathek-rss-container.c"
						{
							RygelMediathekVideoItem* item;
#line 72 "rygel-mediathek-rss-container.vala"
							item = rygel_mediathek_video_item_create_from_xml ((RygelMediaContainer*) self, node, &_inner_error_);
#line 264 "rygel-mediathek-rss-container.c"
							if (_inner_error_ != NULL) {
								if (_inner_error_->domain == RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR) {
									goto __catch3_rygel_mediathek_video_item_error;
								}
								_xmlXPathFreeContext0 (ctx);
								g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
								g_clear_error (&_inner_error_);
								return FALSE;
							}
#line 73 "rygel-mediathek-rss-container.vala"
							rygel_simple_container_add_child ((RygelSimpleContainer*) self, (RygelMediaObject*) item);
#line 74 "rygel-mediathek-rss-container.vala"
							ret = TRUE;
#line 278 "rygel-mediathek-rss-container.c"
							_g_object_unref0 (item);
						}
						goto __finally3;
						__catch3_rygel_mediathek_video_item_error:
						{
							GError * _error_;
							_error_ = _inner_error_;
							_inner_error_ = NULL;
							{
#line 77 "rygel-mediathek-rss-container.vala"
								g_warning ("rygel-mediathek-rss-container.vala:77: Error creating video item: %s", _error_->message);
#line 290 "rygel-mediathek-rss-container.c"
								_g_error_free0 (_error_);
							}
						}
						__finally3:
						if (_inner_error_ != NULL) {
							_xmlXPathFreeContext0 (ctx);
							g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
							g_clear_error (&_inner_error_);
							return FALSE;
						}
					}
				}
			}
		} else {
#line 83 "rygel-mediathek-rss-container.vala"
			g_warning ("rygel-mediathek-rss-container.vala:83: XPath query failed");
#line 307 "rygel-mediathek-rss-container.c"
		}
#line 86 "rygel-mediathek-rss-container.vala"
		xmlFreeDoc (doc);
#line 87 "rygel-mediathek-rss-container.vala"
		rygel_media_container_updated ((RygelMediaContainer*) self);
#line 313 "rygel-mediathek-rss-container.c"
		_xmlXPathFreeContext0 (ctx);
	} else {
#line 90 "rygel-mediathek-rss-container.vala"
		g_warning ("rygel-mediathek-rss-container.vala:90: Failed to parse doc");
#line 318 "rygel-mediathek-rss-container.c"
	}
	result = ret;
#line 93 "rygel-mediathek-rss-container.vala"
	return result;
#line 323 "rygel-mediathek-rss-container.c"
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


#line 31 "rygel-mediathek-rss-container.vala"
static void _rygel_mediathek_rss_container_on_feed_got_soup_session_callback (SoupSession* session, SoupMessage* msg, gpointer self) {
#line 334 "rygel-mediathek-rss-container.c"
	rygel_mediathek_rss_container_on_feed_got (self, session, msg);
}


#line 96 "rygel-mediathek-rss-container.vala"
void rygel_mediathek_rss_container_update (RygelMediathekRssContainer* self) {
#line 341 "rygel-mediathek-rss-container.c"
	char* _tmp0_;
	SoupMessage* _tmp1_;
	SoupMessage* message;
#line 96 "rygel-mediathek-rss-container.vala"
	g_return_if_fail (self != NULL);
#line 97 "rygel-mediathek-rss-container.vala"
	message = (_tmp1_ = soup_message_new ("GET", _tmp0_ = g_strdup_printf ("http://www.zdf.de/ZDFmediathek/content/%u?view=rss", self->priv->zdf_content_id)), _g_free0 (_tmp0_), _tmp1_);
#line 100 "rygel-mediathek-rss-container.vala"
	if (self->priv->last_modified != NULL) {
#line 101 "rygel-mediathek-rss-container.vala"
		g_debug ("rygel-mediathek-rss-container.vala:101: Requesting change since %s", soup_date_to_string (self->priv->last_modified, SOUP_DATE_HTTP));
#line 103 "rygel-mediathek-rss-container.vala"
		soup_message_headers_append (message->request_headers, "If-Modified-Since", soup_date_to_string (self->priv->last_modified, SOUP_DATE_HTTP));
#line 355 "rygel-mediathek-rss-container.c"
	}
#line 107 "rygel-mediathek-rss-container.vala"
	soup_session_queue_message ((SoupSession*) RYGEL_MEDIATHEK_ROOT_CONTAINER (((RygelMediaObject*) self)->parent)->session, _g_object_ref0 (message), _rygel_mediathek_rss_container_on_feed_got_soup_session_callback, self);
#line 359 "rygel-mediathek-rss-container.c"
	_g_object_unref0 (message);
}


#line 111 "rygel-mediathek-rss-container.vala"
RygelMediathekRssContainer* rygel_mediathek_rss_container_construct (GType object_type, RygelMediaContainer* parent, guint id) {
#line 366 "rygel-mediathek-rss-container.c"
	RygelMediathekRssContainer * self;
	char* _tmp1_;
	char* _tmp0_;
#line 111 "rygel-mediathek-rss-container.vala"
	g_return_val_if_fail (parent != NULL, NULL);
#line 112 "rygel-mediathek-rss-container.vala"
	self = (RygelMediathekRssContainer*) rygel_simple_container_construct (object_type, _tmp0_ = g_strdup_printf ("GroupId:%u", id), parent, _tmp1_ = g_strdup_printf ("ZDF Mediathek RSS feed %u", id));
#line 374 "rygel-mediathek-rss-container.c"
	_g_free0 (_tmp1_);
	_g_free0 (_tmp0_);
#line 116 "rygel-mediathek-rss-container.vala"
	self->priv->zdf_content_id = id;
#line 117 "rygel-mediathek-rss-container.vala"
	rygel_mediathek_rss_container_update (self);
#line 381 "rygel-mediathek-rss-container.c"
	return self;
}


#line 111 "rygel-mediathek-rss-container.vala"
RygelMediathekRssContainer* rygel_mediathek_rss_container_new (RygelMediaContainer* parent, guint id) {
#line 111 "rygel-mediathek-rss-container.vala"
	return rygel_mediathek_rss_container_construct (RYGEL_MEDIATHEK_TYPE_RSS_CONTAINER, parent, id);
#line 390 "rygel-mediathek-rss-container.c"
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
	static volatile gsize rygel_mediathek_rss_container_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_mediathek_rss_container_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediathekRssContainerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_mediathek_rss_container_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediathekRssContainer), 0, (GInstanceInitFunc) rygel_mediathek_rss_container_instance_init, NULL };
		GType rygel_mediathek_rss_container_type_id;
		rygel_mediathek_rss_container_type_id = g_type_register_static (RYGEL_TYPE_SIMPLE_CONTAINER, "RygelMediathekRssContainer", &g_define_type_info, 0);
		g_once_init_leave (&rygel_mediathek_rss_container_type_id__volatile, rygel_mediathek_rss_container_type_id);
	}
	return rygel_mediathek_rss_container_type_id__volatile;
}




