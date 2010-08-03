/* rygel-mediathek-video-item.c generated by valac, the Vala compiler
 * generated from rygel-mediathek-video-item.vala, do not modify */

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


#define RYGEL_MEDIATHEK_TYPE_VIDEO_ITEM (rygel_mediathek_video_item_get_type ())
#define RYGEL_MEDIATHEK_VIDEO_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_MEDIATHEK_TYPE_VIDEO_ITEM, RygelMediathekVideoItem))
#define RYGEL_MEDIATHEK_VIDEO_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_MEDIATHEK_TYPE_VIDEO_ITEM, RygelMediathekVideoItemClass))
#define RYGEL_MEDIATHEK_IS_VIDEO_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_MEDIATHEK_TYPE_VIDEO_ITEM))
#define RYGEL_MEDIATHEK_IS_VIDEO_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_MEDIATHEK_TYPE_VIDEO_ITEM))
#define RYGEL_MEDIATHEK_VIDEO_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_MEDIATHEK_TYPE_VIDEO_ITEM, RygelMediathekVideoItemClass))

typedef struct _RygelMediathekVideoItem RygelMediathekVideoItem;
typedef struct _RygelMediathekVideoItemClass RygelMediathekVideoItemClass;
typedef struct _RygelMediathekVideoItemPrivate RygelMediathekVideoItemPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))

#define RYGEL_MEDIATHEK_TYPE_ASX_PLAYLIST (rygel_mediathek_asx_playlist_get_type ())
#define RYGEL_MEDIATHEK_ASX_PLAYLIST(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_MEDIATHEK_TYPE_ASX_PLAYLIST, RygelMediathekAsxPlaylist))
#define RYGEL_MEDIATHEK_ASX_PLAYLIST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_MEDIATHEK_TYPE_ASX_PLAYLIST, RygelMediathekAsxPlaylistClass))
#define RYGEL_MEDIATHEK_IS_ASX_PLAYLIST(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_MEDIATHEK_TYPE_ASX_PLAYLIST))
#define RYGEL_MEDIATHEK_IS_ASX_PLAYLIST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_MEDIATHEK_TYPE_ASX_PLAYLIST))
#define RYGEL_MEDIATHEK_ASX_PLAYLIST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_MEDIATHEK_TYPE_ASX_PLAYLIST, RygelMediathekAsxPlaylistClass))

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
GType rygel_mediathek_video_item_get_type (void) G_GNUC_CONST;
enum  {
	RYGEL_MEDIATHEK_VIDEO_ITEM_DUMMY_PROPERTY
};
static RygelMediathekVideoItem* rygel_mediathek_video_item_new (RygelMediaContainer* parent, const char* title);
static RygelMediathekVideoItem* rygel_mediathek_video_item_construct (GType object_type, RygelMediaContainer* parent, const char* title);
static gboolean rygel_mediathek_video_item_namespace_ok (xmlNode* node);
GType rygel_mediathek_asx_playlist_get_type (void) G_GNUC_CONST;
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


#line 31 "rygel-mediathek-video-item.vala"
static RygelMediathekVideoItem* rygel_mediathek_video_item_construct (GType object_type, RygelMediaContainer* parent, const char* title) {
#line 118 "rygel-mediathek-video-item.c"
	RygelMediathekVideoItem * self;
	char* _tmp0_;
	char* _tmp1_;
	char* _tmp2_;
#line 31 "rygel-mediathek-video-item.vala"
	g_return_val_if_fail (parent != NULL, NULL);
#line 31 "rygel-mediathek-video-item.vala"
	g_return_val_if_fail (title != NULL, NULL);
#line 32 "rygel-mediathek-video-item.vala"
	self = (RygelMediathekVideoItem*) rygel_media_item_construct (object_type, _tmp0_ = g_compute_checksum_for_string (G_CHECKSUM_MD5, title, -1), parent, title, RYGEL_MEDIA_ITEM_VIDEO_CLASS);
#line 129 "rygel-mediathek-video-item.c"
	_g_free0 (_tmp0_);
#line 37 "rygel-mediathek-video-item.vala"
	((RygelMediaItem*) self)->mime_type = (_tmp1_ = g_strdup ("video/x-ms-wmv"), _g_free0 (((RygelMediaItem*) self)->mime_type), _tmp1_);
#line 38 "rygel-mediathek-video-item.vala"
	((RygelMediaItem*) self)->author = (_tmp2_ = g_strdup ("ZDF - Second German TV Channel Streams"), _g_free0 (((RygelMediaItem*) self)->author), _tmp2_);
#line 135 "rygel-mediathek-video-item.c"
	return self;
}


#line 31 "rygel-mediathek-video-item.vala"
static RygelMediathekVideoItem* rygel_mediathek_video_item_new (RygelMediaContainer* parent, const char* title) {
#line 31 "rygel-mediathek-video-item.vala"
	return rygel_mediathek_video_item_construct (RYGEL_MEDIATHEK_TYPE_VIDEO_ITEM, parent, title);
#line 144 "rygel-mediathek-video-item.c"
}


#line 41 "rygel-mediathek-video-item.vala"
static gboolean rygel_mediathek_video_item_namespace_ok (xmlNode* node) {
#line 150 "rygel-mediathek-video-item.c"
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
#line 42 "rygel-mediathek-video-item.vala"
	if (node->ns != NULL) {
#line 42 "rygel-mediathek-video-item.vala"
		_tmp0_ = _vala_strcmp0 (node->ns->prefix, "media") == 0;
#line 157 "rygel-mediathek-video-item.c"
	} else {
#line 42 "rygel-mediathek-video-item.vala"
		_tmp0_ = FALSE;
#line 161 "rygel-mediathek-video-item.c"
	}
	result = _tmp0_;
#line 42 "rygel-mediathek-video-item.vala"
	return result;
#line 166 "rygel-mediathek-video-item.c"
}


#line 45 "rygel-mediathek-video-item.vala"
RygelMediathekAsxPlaylist* rygel_mediathek_video_item_handle_content (xmlNode* group, GError** error) {
#line 172 "rygel-mediathek-video-item.c"
	RygelMediathekAsxPlaylist* result = NULL;
	GError * _inner_error_;
	RygelMediathekAsxPlaylist* asx;
	_inner_error_ = NULL;
#line 47 "rygel-mediathek-video-item.vala"
	asx = NULL;
#line 48 "rygel-mediathek-video-item.vala"
	if (rygel_mediathek_video_item_namespace_ok (group)) {
#line 181 "rygel-mediathek-video-item.c"
		xmlAttr* attr;
#line 49 "rygel-mediathek-video-item.vala"
		attr = xmlHasProp (group, "url");
#line 50 "rygel-mediathek-video-item.vala"
		if (attr != NULL) {
#line 187 "rygel-mediathek-video-item.c"
			char* url;
#line 51 "rygel-mediathek-video-item.vala"
			url = g_strdup (attr->children->content);
#line 52 "rygel-mediathek-video-item.vala"
			if (g_str_has_suffix (url, ".asx")) {
#line 193 "rygel-mediathek-video-item.c"
				{
					RygelMediathekAsxPlaylist* _tmp0_;
#line 54 "rygel-mediathek-video-item.vala"
					asx = (_tmp0_ = rygel_mediathek_asx_playlist_new (url), _g_object_unref0 (asx), _tmp0_);
#line 55 "rygel-mediathek-video-item.vala"
					rygel_mediathek_asx_playlist_parse (asx, &_inner_error_);
#line 200 "rygel-mediathek-video-item.c"
					if (_inner_error_ != NULL) {
						if (_inner_error_->domain == RYGEL_MEDIATHEK_ASX_PLAYLIST_ERROR) {
							goto __catch1_rygel_mediathek_asx_playlist_error;
						}
						_g_free0 (url);
						_g_object_unref0 (asx);
						g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
						g_clear_error (&_inner_error_);
						return NULL;
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
#line 57 "rygel-mediathek-video-item.vala"
						asx = (_tmp1_ = NULL, _g_object_unref0 (asx), _tmp1_);
#line 222 "rygel-mediathek-video-item.c"
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
						g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
						g_clear_error (&_inner_error_);
						return NULL;
					}
				}
			}
			_g_free0 (url);
		} else {
			_inner_error_ = g_error_new_literal (RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR, RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR_XML_PARSE_ERROR, "group node has no 'url' property");
			{
				if (_inner_error_->domain == RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR) {
					g_propagate_error (error, _inner_error_);
					_g_object_unref0 (asx);
					return NULL;
				} else {
					_g_object_unref0 (asx);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
					g_clear_error (&_inner_error_);
					return NULL;
				}
			}
		}
	} else {
		_inner_error_ = g_error_new_literal (RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR, RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR_XML_PARSE_ERROR, "invalid or no namespace");
		{
			if (_inner_error_->domain == RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR) {
				g_propagate_error (error, _inner_error_);
				_g_object_unref0 (asx);
				return NULL;
			} else {
				_g_object_unref0 (asx);
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return NULL;
			}
		}
	}
	result = asx;
#line 71 "rygel-mediathek-video-item.vala"
	return result;
#line 276 "rygel-mediathek-video-item.c"
}


#line 74 "rygel-mediathek-video-item.vala"
RygelMediathekVideoItem* rygel_mediathek_video_item_create_from_xml (RygelMediaContainer* parent, xmlNode* item, GError** error) {
#line 282 "rygel-mediathek-video-item.c"
	RygelMediathekVideoItem* result = NULL;
	GError * _inner_error_;
	char* title;
	RygelMediathekVideoItem* video_item;
	RygelMediathekAsxPlaylist* asx;
	RygelMediathekVideoItem* _tmp7_;
#line 74 "rygel-mediathek-video-item.vala"
	g_return_val_if_fail (parent != NULL, NULL);
#line 291 "rygel-mediathek-video-item.c"
	_inner_error_ = NULL;
#line 77 "rygel-mediathek-video-item.vala"
	title = NULL;
#line 78 "rygel-mediathek-video-item.vala"
	video_item = NULL;
#line 79 "rygel-mediathek-video-item.vala"
	asx = NULL;
#line 299 "rygel-mediathek-video-item.c"
	{
		xmlNode* item_child;
#line 81 "rygel-mediathek-video-item.vala"
		item_child = item->children;
#line 304 "rygel-mediathek-video-item.c"
		{
			gboolean _tmp0_;
#line 81 "rygel-mediathek-video-item.vala"
			_tmp0_ = TRUE;
#line 81 "rygel-mediathek-video-item.vala"
			while (TRUE) {
#line 311 "rygel-mediathek-video-item.c"
				GQuark _tmp6_;
				const char* _tmp5_;
				static GQuark _tmp6__label0 = 0;
				static GQuark _tmp6__label1 = 0;
#line 81 "rygel-mediathek-video-item.vala"
				if (!_tmp0_) {
#line 83 "rygel-mediathek-video-item.vala"
					item_child = item_child->next;
#line 320 "rygel-mediathek-video-item.c"
				}
#line 81 "rygel-mediathek-video-item.vala"
				_tmp0_ = FALSE;
#line 82 "rygel-mediathek-video-item.vala"
				if (!(item_child != NULL)) {
#line 82 "rygel-mediathek-video-item.vala"
					break;
#line 328 "rygel-mediathek-video-item.c"
				}
				_tmp5_ = item_child->name;
				_tmp6_ = (NULL == _tmp5_) ? 0 : g_quark_from_string (_tmp5_);
				if (_tmp6_ == ((0 != _tmp6__label0) ? _tmp6__label0 : (_tmp6__label0 = g_quark_from_static_string ("title"))))
				switch (0) {
					default:
					{
						char* _tmp1_;
#line 87 "rygel-mediathek-video-item.vala"
						title = (_tmp1_ = xmlNodeGetContent (item_child), _g_free0 (title), _tmp1_);
#line 88 "rygel-mediathek-video-item.vala"
						break;
#line 341 "rygel-mediathek-video-item.c"
					}
				} else if (_tmp6_ == ((0 != _tmp6__label1) ? _tmp6__label1 : (_tmp6__label1 = g_quark_from_static_string ("group"))))
				switch (0) {
					default:
					{
#line 90 "rygel-mediathek-video-item.vala"
						if (rygel_mediathek_video_item_namespace_ok (item_child)) {
#line 349 "rygel-mediathek-video-item.c"
							{
								xmlNode* group;
#line 91 "rygel-mediathek-video-item.vala"
								group = item_child->children;
#line 354 "rygel-mediathek-video-item.c"
								{
									gboolean _tmp2_;
#line 91 "rygel-mediathek-video-item.vala"
									_tmp2_ = TRUE;
#line 91 "rygel-mediathek-video-item.vala"
									while (TRUE) {
#line 91 "rygel-mediathek-video-item.vala"
										if (!_tmp2_) {
#line 93 "rygel-mediathek-video-item.vala"
											group = group->next;
#line 365 "rygel-mediathek-video-item.c"
										}
#line 91 "rygel-mediathek-video-item.vala"
										_tmp2_ = FALSE;
#line 92 "rygel-mediathek-video-item.vala"
										if (!(group != NULL)) {
#line 92 "rygel-mediathek-video-item.vala"
											break;
#line 373 "rygel-mediathek-video-item.c"
										}
#line 94 "rygel-mediathek-video-item.vala"
										if (_vala_strcmp0 (group->name, "content") == 0) {
#line 377 "rygel-mediathek-video-item.c"
											RygelMediathekAsxPlaylist* _tmp3_;
											RygelMediathekAsxPlaylist* _tmp4_;
#line 95 "rygel-mediathek-video-item.vala"
											_tmp3_ = rygel_mediathek_video_item_handle_content (group, &_inner_error_);
#line 382 "rygel-mediathek-video-item.c"
											if (_inner_error_ != NULL) {
												if (_inner_error_->domain == RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR) {
													g_propagate_error (error, _inner_error_);
													_g_object_unref0 (asx);
													_g_object_unref0 (video_item);
													_g_free0 (title);
													return NULL;
												} else {
													_g_object_unref0 (asx);
													_g_object_unref0 (video_item);
													_g_free0 (title);
													g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
													g_clear_error (&_inner_error_);
													return NULL;
												}
											}
#line 95 "rygel-mediathek-video-item.vala"
											asx = (_tmp4_ = _tmp3_, _g_object_unref0 (asx), _tmp4_);
#line 401 "rygel-mediathek-video-item.c"
										}
									}
								}
							}
						} else {
							char* msg;
#line 100 "rygel-mediathek-video-item.vala"
							msg = g_strdup ("Invalid or no namespace on group node");
#line 410 "rygel-mediathek-video-item.c"
							_inner_error_ = g_error_new_literal (RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR, RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR_XML_PARSE_ERROR, msg);
							{
								if (_inner_error_->domain == RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR) {
									g_propagate_error (error, _inner_error_);
									_g_free0 (msg);
									_g_object_unref0 (asx);
									_g_object_unref0 (video_item);
									_g_free0 (title);
									return NULL;
								} else {
									_g_free0 (msg);
									_g_object_unref0 (asx);
									_g_object_unref0 (video_item);
									_g_free0 (title);
									g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
									g_clear_error (&_inner_error_);
									return NULL;
								}
							}
							_g_free0 (msg);
						}
#line 104 "rygel-mediathek-video-item.vala"
						break;
#line 434 "rygel-mediathek-video-item.c"
					}
				} else
				switch (0) {
					default:
					{
#line 106 "rygel-mediathek-video-item.vala"
						break;
#line 442 "rygel-mediathek-video-item.c"
					}
				}
			}
		}
	}
#line 110 "rygel-mediathek-video-item.vala"
	if (title == NULL) {
#line 450 "rygel-mediathek-video-item.c"
		_inner_error_ = g_error_new_literal (RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR, RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR_XML_PARSE_ERROR, "Could not find title");
		{
			if (_inner_error_->domain == RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR) {
				g_propagate_error (error, _inner_error_);
				_g_object_unref0 (asx);
				_g_object_unref0 (video_item);
				_g_free0 (title);
				return NULL;
			} else {
				_g_object_unref0 (asx);
				_g_object_unref0 (video_item);
				_g_free0 (title);
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return NULL;
			}
		}
	}
#line 116 "rygel-mediathek-video-item.vala"
	if (asx == NULL) {
#line 471 "rygel-mediathek-video-item.c"
		_inner_error_ = g_error_new_literal (RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR, RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR_XML_PARSE_ERROR, "Could not find URIs");
		{
			if (_inner_error_->domain == RYGEL_MEDIATHEK_VIDEO_ITEM_ERROR) {
				g_propagate_error (error, _inner_error_);
				_g_object_unref0 (asx);
				_g_object_unref0 (video_item);
				_g_free0 (title);
				return NULL;
			} else {
				_g_object_unref0 (asx);
				_g_object_unref0 (video_item);
				_g_free0 (title);
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return NULL;
			}
		}
	}
#line 121 "rygel-mediathek-video-item.vala"
	video_item = (_tmp7_ = rygel_mediathek_video_item_new (parent, title), _g_object_unref0 (video_item), _tmp7_);
#line 492 "rygel-mediathek-video-item.c"
	{
		GeeIterator* _uri_it;
#line 122 "rygel-mediathek-video-item.vala"
		_uri_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) asx->uris);
#line 122 "rygel-mediathek-video-item.vala"
		while (TRUE) {
#line 499 "rygel-mediathek-video-item.c"
			char* uri;
#line 122 "rygel-mediathek-video-item.vala"
			if (!gee_iterator_next (_uri_it)) {
#line 122 "rygel-mediathek-video-item.vala"
				break;
#line 505 "rygel-mediathek-video-item.c"
			}
#line 122 "rygel-mediathek-video-item.vala"
			uri = (char*) gee_iterator_get (_uri_it);
#line 123 "rygel-mediathek-video-item.vala"
			rygel_media_item_add_uri ((RygelMediaItem*) video_item, uri, NULL);
#line 511 "rygel-mediathek-video-item.c"
			_g_free0 (uri);
		}
		_g_object_unref0 (_uri_it);
	}
	result = video_item;
	_g_object_unref0 (asx);
	_g_free0 (title);
#line 126 "rygel-mediathek-video-item.vala"
	return result;
#line 521 "rygel-mediathek-video-item.c"
}


static void rygel_mediathek_video_item_class_init (RygelMediathekVideoItemClass * klass) {
	rygel_mediathek_video_item_parent_class = g_type_class_peek_parent (klass);
}


static void rygel_mediathek_video_item_instance_init (RygelMediathekVideoItem * self) {
}


GType rygel_mediathek_video_item_get_type (void) {
	static volatile gsize rygel_mediathek_video_item_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_mediathek_video_item_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediathekVideoItemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_mediathek_video_item_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediathekVideoItem), 0, (GInstanceInitFunc) rygel_mediathek_video_item_instance_init, NULL };
		GType rygel_mediathek_video_item_type_id;
		rygel_mediathek_video_item_type_id = g_type_register_static (RYGEL_TYPE_MEDIA_ITEM, "RygelMediathekVideoItem", &g_define_type_info, 0);
		g_once_init_leave (&rygel_mediathek_video_item_type_id__volatile, rygel_mediathek_video_item_type_id);
	}
	return rygel_mediathek_video_item_type_id__volatile;
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




