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
#include <stdlib.h>
#include <string.h>
#include <libxml/tree.h>
#include <gee.h>


#define RYGEL_TYPE_MEDIATHEK_VIDEO_ITEM (rygel_mediathek_video_item_get_type ())
#define RYGEL_MEDIATHEK_VIDEO_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIATHEK_VIDEO_ITEM, RygelMediathekVideoItem))
#define RYGEL_MEDIATHEK_VIDEO_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIATHEK_VIDEO_ITEM, RygelMediathekVideoItemClass))
#define RYGEL_IS_MEDIATHEK_VIDEO_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIATHEK_VIDEO_ITEM))
#define RYGEL_IS_MEDIATHEK_VIDEO_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIATHEK_VIDEO_ITEM))
#define RYGEL_MEDIATHEK_VIDEO_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIATHEK_VIDEO_ITEM, RygelMediathekVideoItemClass))

typedef struct _RygelMediathekVideoItem RygelMediathekVideoItem;
typedef struct _RygelMediathekVideoItemClass RygelMediathekVideoItemClass;
typedef struct _RygelMediathekVideoItemPrivate RygelMediathekVideoItemPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))

#define RYGEL_TYPE_MEDIATHEK_ASX_PLAYLIST (rygel_mediathek_asx_playlist_get_type ())
#define RYGEL_MEDIATHEK_ASX_PLAYLIST(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIATHEK_ASX_PLAYLIST, RygelMediathekAsxPlaylist))
#define RYGEL_MEDIATHEK_ASX_PLAYLIST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIATHEK_ASX_PLAYLIST, RygelMediathekAsxPlaylistClass))
#define RYGEL_IS_MEDIATHEK_ASX_PLAYLIST(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIATHEK_ASX_PLAYLIST))
#define RYGEL_IS_MEDIATHEK_ASX_PLAYLIST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIATHEK_ASX_PLAYLIST))
#define RYGEL_MEDIATHEK_ASX_PLAYLIST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIATHEK_ASX_PLAYLIST, RygelMediathekAsxPlaylistClass))

typedef struct _RygelMediathekAsxPlaylist RygelMediathekAsxPlaylist;
typedef struct _RygelMediathekAsxPlaylistClass RygelMediathekAsxPlaylistClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _RygelMediathekAsxPlaylistPrivate RygelMediathekAsxPlaylistPrivate;

typedef enum  {
	RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR_XML_PARSE_ERROR
} RygelMediathekVideoItemError;
#define RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR rygel_mediathek_video_item_error_quark ()
struct _RygelMediathekVideoItem {
	RygelMediaItem parent_instance;
	RygelMediathekVideoItemPrivate * priv;
};

struct _RygelMediathekVideoItemClass {
	RygelMediaItemClass parent_class;
};

typedef enum  {
	RYGEL_MEDIATHEK_ASX_PLAYLIST_ERROR_XML_ERROR,
	RYGEL_MEDIATHEK_ASX_PLAYLIST_ERROR_NETWORK_ERROR
} RygelMediathekAsxPlaylistError;
#define RYGEL_MEDIATHEK_ASX_PLAYLIST_ERROR rygel_mediathek_asx_playlist_error_quark ()
struct _RygelMediathekAsxPlaylist {
	GObject parent_instance;
	RygelMediathekAsxPlaylistPrivate * priv;
	GeeArrayList* uris;
};

struct _RygelMediathekAsxPlaylistClass {
	GObjectClass parent_class;
};


static gpointer rygel_mediathek_video_item_parent_class = NULL;

GQuark rygel_mediathek_video_item_error_quark (void);
GType rygel_mediathek_video_item_get_type (void);
enum  {
	RYGEL_MEDIATHEK_VIDEO_ITEM_DUMMY_PROPERTY
};
static RygelMediathekVideoItem* rygel_mediathek_video_item_new (RygelMediaContainer* parent, const char* title);
static RygelMediathekVideoItem* rygel_mediathek_video_item_construct (GType object_type, RygelMediaContainer* parent, const char* title);
static gboolean rygel_mediathek_video_item_namespace_ok (xmlNode* node);
GType rygel_mediathek_asx_playlist_get_type (void);
RygelMediathekAsxPlaylist* rygel_mediathek_asx_playlist_new (const char* uri);
RygelMediathekAsxPlaylist* rygel_mediathek_asx_playlist_construct (GType object_type, const char* uri);
GQuark rygel_mediathek_asx_playlist_error_quark (void);
void rygel_mediathek_asx_playlist_parse (RygelMediathekAsxPlaylist* self, GError** error);
RygelMediathekAsxPlaylist* rygel_mediathek_video_item_handle_content (xmlNode* group, GError** error);
RygelMediathekVideoItem* rygel_mediathek_video_item_create_from_xml (RygelMediaContainer* parent, xmlNode* item, GError** error);
static int _vala_strcmp0 (const char * str1, const char * str2);



GQuark rygel_mediathek_video_item_error_quark (void) {
	return g_quark_from_static_string ("rygel_mediathek_video_item_error-quark");
}


static RygelMediathekVideoItem* rygel_mediathek_video_item_construct (GType object_type, RygelMediaContainer* parent, const char* title) {
	RygelMediathekVideoItem * self;
	char* _tmp0_;
	char* _tmp1_;
	char* _tmp2_;
	g_return_val_if_fail (parent != NULL, NULL);
	g_return_val_if_fail (title != NULL, NULL);
	self = (RygelMediathekVideoItem*) rygel_media_item_construct (object_type, _tmp0_ = g_compute_checksum_for_string (G_CHECKSUM_MD5, title, -1), parent, title, RYGEL_MEDIA_ITEM_VIDEO_CLASS);
	_g_free0 (_tmp0_);
	((RygelMediaItem*) self)->mime_type = (_tmp1_ = g_strdup ("video/x-ms-asf"), _g_free0 (((RygelMediaItem*) self)->mime_type), _tmp1_);
	((RygelMediaItem*) self)->author = (_tmp2_ = g_strdup ("ZDF - Zweites Deutsches Fernsehen"), _g_free0 (((RygelMediaItem*) self)->author), _tmp2_);
	return self;
}


static RygelMediathekVideoItem* rygel_mediathek_video_item_new (RygelMediaContainer* parent, const char* title) {
	return rygel_mediathek_video_item_construct (RYGEL_TYPE_MEDIATHEK_VIDEO_ITEM, parent, title);
}


static gboolean rygel_mediathek_video_item_namespace_ok (xmlNode* node) {
	gboolean result;
	gboolean _tmp0_;
	_tmp0_ = FALSE;
	if (node->ns != NULL) {
		_tmp0_ = _vala_strcmp0 (node->ns->prefix, "media") == 0;
	} else {
		_tmp0_ = FALSE;
	}
	result = _tmp0_;
	return result;
}


RygelMediathekAsxPlaylist* rygel_mediathek_video_item_handle_content (xmlNode* group, GError** error) {
	RygelMediathekAsxPlaylist* result;
	GError * _inner_error_;
	RygelMediathekAsxPlaylist* asx;
	_inner_error_ = NULL;
	asx = NULL;
	if (rygel_mediathek_video_item_namespace_ok (group)) {
		xmlAttr* attr;
		attr = xmlHasProp (group, "url");
		if (attr != NULL) {
			char* url;
			url = g_strdup (attr->children->content);
			if (g_str_has_suffix (url, ".asx")) {
				{
					RygelMediathekAsxPlaylist* _tmp0_;
					asx = (_tmp0_ = rygel_mediathek_asx_playlist_new (url), _g_object_unref0 (asx), _tmp0_);
					rygel_mediathek_asx_playlist_parse (asx, &_inner_error_);
					if (_inner_error_ != NULL) {
						if (_inner_error_->domain == RYGEL_MEDIATHEK_ASX_PLAYLIST_ERROR) {
							goto __catch1_rygel_mediathek_asx_playlist_error;
						}
						goto __finally1;
					}
				}
				goto __finally1;
				__catch1_rygel_mediathek_asx_playlist_error:
				{
					GError * _error_;
					_error_ = _inner_error_;
					_inner_error_ = NULL;
					{
						RygelMediathekAsxPlaylist* _tmp1_;
						asx = (_tmp1_ = NULL, _g_object_unref0 (asx), _tmp1_);
						_g_error_free0 (_error_);
					}
				}
				__finally1:
				if (_inner_error_ != NULL) {
					if (_inner_error_->domain == RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR) {
						g_propagate_error (error, _inner_error_);
						_g_free0 (url);
						_g_object_unref0 (asx);
						return NULL;
					} else {
						_g_free0 (url);
						_g_object_unref0 (asx);
						g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
						g_clear_error (&_inner_error_);
						return NULL;
					}
				}
			}
			_g_free0 (url);
		} else {
			_inner_error_ = g_error_new_literal (RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR, RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR_XML_PARSE_ERROR, "group node has url property");
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR) {
					g_propagate_error (error, _inner_error_);
					_g_object_unref0 (asx);
					return NULL;
				} else {
					_g_object_unref0 (asx);
					g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
					g_clear_error (&_inner_error_);
					return NULL;
				}
			}
		}
	} else {
		_inner_error_ = g_error_new_literal (RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR, RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR_XML_PARSE_ERROR, "invalid or no namespace");
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR) {
				g_propagate_error (error, _inner_error_);
				_g_object_unref0 (asx);
				return NULL;
			} else {
				_g_object_unref0 (asx);
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return NULL;
			}
		}
	}
	result = asx;
	return result;
}


RygelMediathekVideoItem* rygel_mediathek_video_item_create_from_xml (RygelMediaContainer* parent, xmlNode* item, GError** error) {
	RygelMediathekVideoItem* result;
	GError * _inner_error_;
	char* title;
	RygelMediathekVideoItem* video_item;
	RygelMediathekAsxPlaylist* asx;
	RygelMediathekVideoItem* _tmp7_;
	g_return_val_if_fail (parent != NULL, NULL);
	_inner_error_ = NULL;
	title = NULL;
	video_item = NULL;
	asx = NULL;
	{
		xmlNode* item_child;
		item_child = item->children;
		{
			gboolean _tmp0_;
			_tmp0_ = TRUE;
			while (TRUE) {
				GQuark _tmp6_;
				const char* _tmp5_;
				static GQuark _tmp6__label0 = 0;
				static GQuark _tmp6__label1 = 0;
				if (!_tmp0_) {
					item_child = item_child->next;
				}
				_tmp0_ = FALSE;
				if (!(item_child != NULL)) {
					break;
				}
				_tmp5_ = item_child->name;
				_tmp6_ = (NULL == _tmp5_) ? 0 : g_quark_from_string (_tmp5_);
				if (_tmp6_ == ((0 != _tmp6__label0) ? _tmp6__label0 : (_tmp6__label0 = g_quark_from_static_string ("title"))))
				do {
					char* _tmp1_;
					title = (_tmp1_ = xmlNodeGetContent (item_child), _g_free0 (title), _tmp1_);
					break;
				} while (0); else if (_tmp6_ == ((0 != _tmp6__label1) ? _tmp6__label1 : (_tmp6__label1 = g_quark_from_static_string ("group"))))
				do {
					if (rygel_mediathek_video_item_namespace_ok (item_child)) {
						{
							xmlNode* group;
							group = item_child->children;
							{
								gboolean _tmp2_;
								_tmp2_ = TRUE;
								while (TRUE) {
									if (!_tmp2_) {
										group = group->next;
									}
									_tmp2_ = FALSE;
									if (!(group != NULL)) {
										break;
									}
									if (_vala_strcmp0 (group->name, "content") == 0) {
										RygelMediathekAsxPlaylist* _tmp3_;
										RygelMediathekAsxPlaylist* _tmp4_;
										_tmp3_ = rygel_mediathek_video_item_handle_content (group, &_inner_error_);
										if (_inner_error_ != NULL) {
											if (_inner_error_->domain == RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR) {
												g_propagate_error (error, _inner_error_);
												_g_free0 (title);
												_g_object_unref0 (video_item);
												_g_object_unref0 (asx);
												return NULL;
											} else {
												_g_free0 (title);
												_g_object_unref0 (video_item);
												_g_object_unref0 (asx);
												g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
												g_clear_error (&_inner_error_);
												return NULL;
											}
										}
										asx = (_tmp4_ = _tmp3_, _g_object_unref0 (asx), _tmp4_);
									}
								}
							}
						}
					} else {
						_inner_error_ = g_error_new_literal (RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR, RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR_XML_PARSE_ERROR, "invalid or no namespace on group node");
						if (_inner_error_ != NULL) {
							if (_inner_error_->domain == RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR) {
								g_propagate_error (error, _inner_error_);
								_g_free0 (title);
								_g_object_unref0 (video_item);
								_g_object_unref0 (asx);
								return NULL;
							} else {
								_g_free0 (title);
								_g_object_unref0 (video_item);
								_g_object_unref0 (asx);
								g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
								g_clear_error (&_inner_error_);
								return NULL;
							}
						}
					}
					break;
				} while (0); else
				do {
					break;
				} while (0);
			}
		}
	}
	if (title == NULL) {
		_inner_error_ = g_error_new_literal (RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR, RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR_XML_PARSE_ERROR, "Could not find title");
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR) {
				g_propagate_error (error, _inner_error_);
				_g_free0 (title);
				_g_object_unref0 (video_item);
				_g_object_unref0 (asx);
				return NULL;
			} else {
				_g_free0 (title);
				_g_object_unref0 (video_item);
				_g_object_unref0 (asx);
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return NULL;
			}
		}
	}
	if (asx == NULL) {
		_inner_error_ = g_error_new_literal (RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR, RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR_XML_PARSE_ERROR, "Could not find uris");
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR) {
				g_propagate_error (error, _inner_error_);
				_g_free0 (title);
				_g_object_unref0 (video_item);
				_g_object_unref0 (asx);
				return NULL;
			} else {
				_g_free0 (title);
				_g_object_unref0 (video_item);
				_g_object_unref0 (asx);
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return NULL;
			}
		}
	}
	video_item = (_tmp7_ = rygel_mediathek_video_item_new (parent, title), _g_object_unref0 (video_item), _tmp7_);
	{
		GeeIterator* _uri_it;
		_uri_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) asx->uris);
		while (TRUE) {
			char* uri;
			if (!gee_iterator_next (_uri_it)) {
				break;
			}
			uri = (char*) gee_iterator_get (_uri_it);
			rygel_media_item_add_uri ((RygelMediaItem*) video_item, uri, NULL);
			_g_free0 (uri);
		}
		_g_object_unref0 (_uri_it);
	}
	result = video_item;
	_g_free0 (title);
	_g_object_unref0 (asx);
	return result;
}


static void rygel_mediathek_video_item_class_init (RygelMediathekVideoItemClass * klass) {
	rygel_mediathek_video_item_parent_class = g_type_class_peek_parent (klass);
}


static void rygel_mediathek_video_item_instance_init (RygelMediathekVideoItem * self) {
}


GType rygel_mediathek_video_item_get_type (void) {
	static GType rygel_mediathek_video_item_type_id = 0;
	if (rygel_mediathek_video_item_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediathekVideoItemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_mediathek_video_item_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediathekVideoItem), 0, (GInstanceInitFunc) rygel_mediathek_video_item_instance_init, NULL };
		rygel_mediathek_video_item_type_id = g_type_register_static (RYGEL_TYPE_MEDIA_ITEM, "RygelMediathekVideoItem", &g_define_type_info, 0);
	}
	return rygel_mediathek_video_item_type_id;
}


static int _vala_strcmp0 (const char * str1, const char * str2) {
	if (str1 == NULL) {
		return -(str1 != str2);
	}
	if (str2 == NULL) {
		return str1 != str2;
	}
	return strcmp (str1, str2);
}




