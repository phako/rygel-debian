/* rygel-mediathek-asx-playlist.c generated by valac, the Vala compiler
 * generated from rygel-mediathek-asx-playlist.vala, do not modify */

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
#include <gee.h>
#include <stdlib.h>
#include <string.h>
#include <libsoup/soup.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xpath.h>


#define RYGEL_TYPE_MEDIATHEK_ASX_PLAYLIST (rygel_mediathek_asx_playlist_get_type ())
#define RYGEL_MEDIATHEK_ASX_PLAYLIST(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIATHEK_ASX_PLAYLIST, RygelMediathekAsxPlaylist))
#define RYGEL_MEDIATHEK_ASX_PLAYLIST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIATHEK_ASX_PLAYLIST, RygelMediathekAsxPlaylistClass))
#define RYGEL_IS_MEDIATHEK_ASX_PLAYLIST(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIATHEK_ASX_PLAYLIST))
#define RYGEL_IS_MEDIATHEK_ASX_PLAYLIST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIATHEK_ASX_PLAYLIST))
#define RYGEL_MEDIATHEK_ASX_PLAYLIST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIATHEK_ASX_PLAYLIST, RygelMediathekAsxPlaylistClass))

typedef struct _RygelMediathekAsxPlaylist RygelMediathekAsxPlaylist;
typedef struct _RygelMediathekAsxPlaylistClass RygelMediathekAsxPlaylistClass;
typedef struct _RygelMediathekAsxPlaylistPrivate RygelMediathekAsxPlaylistPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_regex_unref0(var) ((var == NULL) ? NULL : (var = (g_regex_unref (var), NULL)))
#define _xmlXPathFreeContext0(var) ((var == NULL) ? NULL : (var = (xmlXPathFreeContext (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

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

struct _RygelMediathekAsxPlaylistPrivate {
	char* uri;
};


static gpointer rygel_mediathek_asx_playlist_parent_class = NULL;

GQuark rygel_mediathek_asx_playlist_error_quark (void);
GType rygel_mediathek_asx_playlist_get_type (void);
#define RYGEL_MEDIATHEK_ASX_PLAYLIST_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_MEDIATHEK_ASX_PLAYLIST, RygelMediathekAsxPlaylistPrivate))
enum  {
	RYGEL_MEDIATHEK_ASX_PLAYLIST_DUMMY_PROPERTY
};
RygelMediathekAsxPlaylist* rygel_mediathek_asx_playlist_new (const char* uri);
RygelMediathekAsxPlaylist* rygel_mediathek_asx_playlist_construct (GType object_type, const char* uri);
void rygel_mediathek_asx_playlist_parse (RygelMediathekAsxPlaylist* self, GError** error);
static void rygel_mediathek_asx_playlist_finalize (GObject* obj);



GQuark rygel_mediathek_asx_playlist_error_quark (void) {
	return g_quark_from_static_string ("rygel_mediathek_asx_playlist_error-quark");
}


RygelMediathekAsxPlaylist* rygel_mediathek_asx_playlist_construct (GType object_type, const char* uri) {
	RygelMediathekAsxPlaylist * self;
	GeeArrayList* _tmp0_;
	char* _tmp1_;
	g_return_val_if_fail (uri != NULL, NULL);
	self = (RygelMediathekAsxPlaylist*) g_object_new (object_type, NULL);
	self->uris = (_tmp0_ = gee_array_list_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, NULL), _g_object_unref0 (self->uris), _tmp0_);
	self->priv->uri = (_tmp1_ = g_strdup (uri), _g_free0 (self->priv->uri), _tmp1_);
	return self;
}


RygelMediathekAsxPlaylist* rygel_mediathek_asx_playlist_new (const char* uri) {
	return rygel_mediathek_asx_playlist_construct (RYGEL_TYPE_MEDIATHEK_ASX_PLAYLIST, uri);
}


static glong string_get_length (const char* self) {
	glong result;
	g_return_val_if_fail (self != NULL, 0L);
	result = g_utf8_strlen (self, -1);
	return result;
}


void rygel_mediathek_asx_playlist_parse (RygelMediathekAsxPlaylist* self, GError** error) {
	GError * _inner_error_;
	SoupSessionSync* session;
	SoupMessage* message;
	guint _tmp0_;
	g_return_if_fail (self != NULL);
	_inner_error_ = NULL;
	session = (SoupSessionSync*) soup_session_sync_new ();
	message = soup_message_new ("GET", self->priv->uri);
	soup_session_send_message ((SoupSession*) session, message);
	if ((g_object_get (message, "status-code", &_tmp0_, NULL), _tmp0_) == 200) {
		{
			GRegex* normalizer;
			char* normalized_content;
			xmlDoc* doc;
			normalizer = g_regex_new ("(<[/]?)([a-zA-Z:]+)", 0, 0, &_inner_error_);
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == G_REGEX_ERROR) {
					goto __catch0_g_regex_error;
				}
				goto __finally0;
			}
			normalized_content = g_regex_replace (normalizer, message->response_body->data, (gssize) ((glong) message->response_body->length), 0, "\\1\\L\\2\\E", 0, &_inner_error_);
			if (_inner_error_ != NULL) {
				_g_regex_unref0 (normalizer);
				if (_inner_error_->domain == G_REGEX_ERROR) {
					goto __catch0_g_regex_error;
				}
				goto __finally0;
			}
			doc = xmlParseMemory (normalized_content, (gint) string_get_length (normalized_content));
			if (doc != NULL) {
				xmlXPathContext* ctx;
				xmlXPathObject* xpo;
				ctx = xmlXPathNewContext (doc);
				xpo = xmlXPathEval ("/asx/entry/ref/@href", ctx);
				if (xpo->type == XPATH_NODESET) {
					{
						gint i;
						i = 0;
						{
							gboolean _tmp1_;
							_tmp1_ = TRUE;
							while (TRUE) {
								xmlNode* item;
								if (!_tmp1_) {
									i++;
								}
								_tmp1_ = FALSE;
								if (!(i < xmlXPathNodeSetGetLength (xpo->nodesetval))) {
									break;
								}
								item = xmlXPathNodeSetItem (xpo->nodesetval, i);
								gee_abstract_collection_add ((GeeAbstractCollection*) self->uris, item->children->content);
							}
						}
					}
				}
				_xmlXPathFreeContext0 (ctx);
			} else {
				_inner_error_ = g_error_new_literal (RYGEL_MEDIATHEK_ASX_PLAYLIST_ERROR, RYGEL_MEDIATHEK_ASX_PLAYLIST_ERROR_XML_ERROR, "Could not received XML");
				if (_inner_error_ != NULL) {
					_g_regex_unref0 (normalizer);
					_g_free0 (normalized_content);
					if (_inner_error_->domain == G_REGEX_ERROR) {
						goto __catch0_g_regex_error;
					}
					goto __finally0;
				}
			}
			_g_regex_unref0 (normalizer);
			_g_free0 (normalized_content);
		}
		goto __finally0;
		__catch0_g_regex_error:
		{
			GError * _error_;
			_error_ = _inner_error_;
			_inner_error_ = NULL;
			{
				_g_error_free0 (_error_);
			}
		}
		__finally0:
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == RYGEL_MEDIATHEK_ASX_PLAYLIST_ERROR) {
				g_propagate_error (error, _inner_error_);
				_g_object_unref0 (session);
				_g_object_unref0 (message);
				return;
			} else {
				_g_object_unref0 (session);
				_g_object_unref0 (message);
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return;
			}
		}
	} else {
		char* _tmp4_;
		guint _tmp2_;
		guint _tmp3_;
		GError* _tmp5_;
		_inner_error_ = (_tmp5_ = g_error_new_literal (RYGEL_MEDIATHEK_ASX_PLAYLIST_ERROR, RYGEL_MEDIATHEK_ASX_PLAYLIST_ERROR_NETWORK_ERROR, _tmp4_ = g_strdup_printf ("Could not download playlist, error code was %u (%s)", (g_object_get (message, "status-code", &_tmp2_, NULL), _tmp2_), soup_status_get_phrase ((g_object_get (message, "status-code", &_tmp3_, NULL), _tmp3_)))), _g_free0 (_tmp4_), _tmp5_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == RYGEL_MEDIATHEK_ASX_PLAYLIST_ERROR) {
				g_propagate_error (error, _inner_error_);
				_g_object_unref0 (session);
				_g_object_unref0 (message);
				return;
			} else {
				_g_object_unref0 (session);
				_g_object_unref0 (message);
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return;
			}
		}
	}
	_g_object_unref0 (session);
	_g_object_unref0 (message);
}


static void rygel_mediathek_asx_playlist_class_init (RygelMediathekAsxPlaylistClass * klass) {
	rygel_mediathek_asx_playlist_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelMediathekAsxPlaylistPrivate));
	G_OBJECT_CLASS (klass)->finalize = rygel_mediathek_asx_playlist_finalize;
}


static void rygel_mediathek_asx_playlist_instance_init (RygelMediathekAsxPlaylist * self) {
	self->priv = RYGEL_MEDIATHEK_ASX_PLAYLIST_GET_PRIVATE (self);
}


static void rygel_mediathek_asx_playlist_finalize (GObject* obj) {
	RygelMediathekAsxPlaylist * self;
	self = RYGEL_MEDIATHEK_ASX_PLAYLIST (obj);
	_g_object_unref0 (self->uris);
	_g_free0 (self->priv->uri);
	G_OBJECT_CLASS (rygel_mediathek_asx_playlist_parent_class)->finalize (obj);
}


GType rygel_mediathek_asx_playlist_get_type (void) {
	static GType rygel_mediathek_asx_playlist_type_id = 0;
	if (rygel_mediathek_asx_playlist_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediathekAsxPlaylistClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_mediathek_asx_playlist_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediathekAsxPlaylist), 0, (GInstanceInitFunc) rygel_mediathek_asx_playlist_instance_init, NULL };
		rygel_mediathek_asx_playlist_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelMediathekAsxPlaylist", &g_define_type_info, 0);
	}
	return rygel_mediathek_asx_playlist_type_id;
}




