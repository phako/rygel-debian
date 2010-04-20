/* rygel-http-byte-seek.c generated by valac, the Vala compiler
 * generated from rygel-http-byte-seek.vala, do not modify */

/*
 * Copyright (C) 2009 Nokia Corporation.
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
#include <stdlib.h>
#include <string.h>
#include <libsoup/soup.h>


#define RYGEL_TYPE_HTTP_SEEK (rygel_http_seek_get_type ())
#define RYGEL_HTTP_SEEK(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_SEEK, RygelHTTPSeek))
#define RYGEL_HTTP_SEEK_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_SEEK, RygelHTTPSeekClass))
#define RYGEL_IS_HTTP_SEEK(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_SEEK))
#define RYGEL_IS_HTTP_SEEK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_SEEK))
#define RYGEL_HTTP_SEEK_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_SEEK, RygelHTTPSeekClass))

typedef struct _RygelHTTPSeek RygelHTTPSeek;
typedef struct _RygelHTTPSeekClass RygelHTTPSeekClass;
typedef struct _RygelHTTPSeekPrivate RygelHTTPSeekPrivate;

#define RYGEL_TYPE_HTTP_BYTE_SEEK (rygel_http_byte_seek_get_type ())
#define RYGEL_HTTP_BYTE_SEEK(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_BYTE_SEEK, RygelHTTPByteSeek))
#define RYGEL_HTTP_BYTE_SEEK_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_BYTE_SEEK, RygelHTTPByteSeekClass))
#define RYGEL_IS_HTTP_BYTE_SEEK(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_BYTE_SEEK))
#define RYGEL_IS_HTTP_BYTE_SEEK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_BYTE_SEEK))
#define RYGEL_HTTP_BYTE_SEEK_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_BYTE_SEEK, RygelHTTPByteSeekClass))

typedef struct _RygelHTTPByteSeek RygelHTTPByteSeek;
typedef struct _RygelHTTPByteSeekClass RygelHTTPByteSeekClass;
typedef struct _RygelHTTPByteSeekPrivate RygelHTTPByteSeekPrivate;

#define RYGEL_TYPE_HTTP_GET (rygel_http_get_get_type ())
#define RYGEL_HTTP_GET(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_GET, RygelHTTPGet))
#define RYGEL_HTTP_GET_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_GET, RygelHTTPGetClass))
#define RYGEL_IS_HTTP_GET(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_GET))
#define RYGEL_IS_HTTP_GET_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_GET))
#define RYGEL_HTTP_GET_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_GET, RygelHTTPGetClass))

typedef struct _RygelHTTPGet RygelHTTPGet;
typedef struct _RygelHTTPGetClass RygelHTTPGetClass;
typedef struct _RygelHTTPGetPrivate RygelHTTPGetPrivate;

#define RYGEL_TYPE_MEDIA_ITEM (rygel_media_item_get_type ())
#define RYGEL_MEDIA_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_ITEM, RygelMediaItem))
#define RYGEL_MEDIA_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_ITEM, RygelMediaItemClass))
#define RYGEL_IS_MEDIA_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_ITEM))
#define RYGEL_IS_MEDIA_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_ITEM))
#define RYGEL_MEDIA_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_ITEM, RygelMediaItemClass))

typedef struct _RygelMediaItem RygelMediaItem;
typedef struct _RygelMediaItemClass RygelMediaItemClass;

#define RYGEL_TYPE_THUMBNAIL (rygel_thumbnail_get_type ())
#define RYGEL_THUMBNAIL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_THUMBNAIL, RygelThumbnail))
#define RYGEL_THUMBNAIL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_THUMBNAIL, RygelThumbnailClass))
#define RYGEL_IS_THUMBNAIL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_THUMBNAIL))
#define RYGEL_IS_THUMBNAIL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_THUMBNAIL))
#define RYGEL_THUMBNAIL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_THUMBNAIL, RygelThumbnailClass))

typedef struct _RygelThumbnail RygelThumbnail;
typedef struct _RygelThumbnailClass RygelThumbnailClass;

#define RYGEL_TYPE_SUBTITLE (rygel_subtitle_get_type ())
#define RYGEL_SUBTITLE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_SUBTITLE, RygelSubtitle))
#define RYGEL_SUBTITLE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_SUBTITLE, RygelSubtitleClass))
#define RYGEL_IS_SUBTITLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_SUBTITLE))
#define RYGEL_IS_SUBTITLE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_SUBTITLE))
#define RYGEL_SUBTITLE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_SUBTITLE, RygelSubtitleClass))

typedef struct _RygelSubtitle RygelSubtitle;
typedef struct _RygelSubtitleClass RygelSubtitleClass;

#define RYGEL_TYPE_HTTP_IDENTITY_HANDLER (rygel_http_identity_handler_get_type ())
#define RYGEL_HTTP_IDENTITY_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_IDENTITY_HANDLER, RygelHTTPIdentityHandler))
#define RYGEL_HTTP_IDENTITY_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_IDENTITY_HANDLER, RygelHTTPIdentityHandlerClass))
#define RYGEL_IS_HTTP_IDENTITY_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_IDENTITY_HANDLER))
#define RYGEL_IS_HTTP_IDENTITY_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_IDENTITY_HANDLER))
#define RYGEL_HTTP_IDENTITY_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_IDENTITY_HANDLER, RygelHTTPIdentityHandlerClass))

typedef struct _RygelHTTPIdentityHandler RygelHTTPIdentityHandler;
typedef struct _RygelHTTPIdentityHandlerClass RygelHTTPIdentityHandlerClass;
typedef struct _RygelThumbnailPrivate RygelThumbnailPrivate;
typedef struct _RygelSubtitlePrivate RygelSubtitlePrivate;
typedef struct _RygelMediaItemPrivate RygelMediaItemPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))

struct _RygelHTTPSeek {
	GObject parent_instance;
	RygelHTTPSeekPrivate * priv;
};

struct _RygelHTTPSeekClass {
	GObjectClass parent_class;
	void (*add_response_headers) (RygelHTTPSeek* self);
};

struct _RygelHTTPByteSeek {
	RygelHTTPSeek parent_instance;
	RygelHTTPByteSeekPrivate * priv;
};

struct _RygelHTTPByteSeekClass {
	RygelHTTPSeekClass parent_class;
};

struct _RygelHTTPGet {
	GObject parent_instance;
	RygelHTTPGetPrivate * priv;
	SoupMessage* msg;
	RygelMediaItem* item;
	RygelThumbnail* thumbnail;
	RygelSubtitle* subtitle;
	RygelHTTPIdentityHandler* handler;
};

struct _RygelHTTPGetClass {
	GObjectClass parent_class;
};

struct _RygelThumbnail {
	GObject parent_instance;
	RygelThumbnailPrivate * priv;
	gint64 size;
};

struct _RygelThumbnailClass {
	GObjectClass parent_class;
};

struct _RygelSubtitle {
	GObject parent_instance;
	RygelSubtitlePrivate * priv;
	gint64 size;
};

struct _RygelSubtitleClass {
	GObjectClass parent_class;
};

struct _RygelMediaItem {
	GObject parent_instance;
	RygelMediaItemPrivate * priv;
	gint64 size;
};

struct _RygelMediaItemClass {
	GObjectClass parent_class;
};

typedef enum  {
	RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE = SOUP_STATUS_BAD_REQUEST,
	RYGEL_HTTP_SEEK_ERROR_OUT_OF_RANGE = SOUP_STATUS_REQUESTED_RANGE_NOT_SATISFIABLE
} RygelHTTPSeekError;
#define RYGEL_HTTP_SEEK_ERROR rygel_http_seek_error_quark ()

static gpointer rygel_http_byte_seek_parent_class = NULL;

GType rygel_http_seek_get_type (void);
GType rygel_http_byte_seek_get_type (void);
enum  {
	RYGEL_HTTP_BYTE_SEEK_DUMMY_PROPERTY
};
GType rygel_http_get_get_type (void);
GType rygel_media_item_get_type (void);
GType rygel_thumbnail_get_type (void);
GType rygel_subtitle_get_type (void);
GType rygel_http_identity_handler_get_type (void);
GQuark rygel_http_seek_error_quark (void);
RygelHTTPSeek* rygel_http_seek_construct (GType object_type, SoupMessage* msg, gint64 start, gint64 stop, gint64 length);
RygelHTTPByteSeek* rygel_http_byte_seek_new (RygelHTTPGet* request, GError** error);
RygelHTTPByteSeek* rygel_http_byte_seek_construct (GType object_type, RygelHTTPGet* request, GError** error);
gboolean rygel_http_byte_seek_needed (RygelHTTPGet* request);
SoupMessage* rygel_http_seek_get_msg (RygelHTTPSeek* self);
gint64 rygel_http_seek_get_start (RygelHTTPSeek* self);
gint64 rygel_http_seek_get_stop (RygelHTTPSeek* self);
gint64 rygel_http_seek_get_length (RygelHTTPSeek* self);
static void rygel_http_byte_seek_real_add_response_headers (RygelHTTPSeek* base);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);
static int _vala_strcmp0 (const char * str1, const char * str2);



#line 25 "rygel-http-byte-seek.vala"
RygelHTTPByteSeek* rygel_http_byte_seek_construct (GType object_type, RygelHTTPGet* request, GError** error) {
#line 212 "rygel-http-byte-seek.c"
	GError * _inner_error_;
	RygelHTTPByteSeek * self;
	char* range;
	char* pos;
	gint _range_tokens_size_;
	gint range_tokens_length1;
	char** range_tokens;
	gint64 start;
	gint64 total_length = 0LL;
	gint64 stop;
	char* _tmp0_;
#line 25 "rygel-http-byte-seek.vala"
	g_return_val_if_fail (request != NULL, NULL);
#line 226 "rygel-http-byte-seek.c"
	_inner_error_ = NULL;
	range = NULL;
	pos = NULL;
	range_tokens = (range_tokens_length1 = 0, NULL);
#line 28 "rygel-http-byte-seek.vala"
	start = (gint64) 0;
#line 30 "rygel-http-byte-seek.vala"
	if (request->thumbnail != NULL) {
#line 31 "rygel-http-byte-seek.vala"
		total_length = request->thumbnail->size;
#line 237 "rygel-http-byte-seek.c"
	} else {
#line 32 "rygel-http-byte-seek.vala"
		if (request->subtitle != NULL) {
#line 33 "rygel-http-byte-seek.vala"
			total_length = request->subtitle->size;
#line 243 "rygel-http-byte-seek.c"
		} else {
#line 35 "rygel-http-byte-seek.vala"
			total_length = request->item->size;
#line 247 "rygel-http-byte-seek.c"
		}
	}
#line 37 "rygel-http-byte-seek.vala"
	stop = total_length - 1;
#line 39 "rygel-http-byte-seek.vala"
	range = (_tmp0_ = g_strdup (soup_message_headers_get (request->msg->request_headers, "Range")), _g_free0 (range), _tmp0_);
#line 40 "rygel-http-byte-seek.vala"
	if (range != NULL) {
#line 256 "rygel-http-byte-seek.c"
		char** _tmp2_;
		char** _tmp1_;
		gboolean _tmp3_ = FALSE;
		char* _tmp4_;
		char* _tmp5_;
#line 42 "rygel-http-byte-seek.vala"
		if (!g_str_has_prefix (range, "bytes=")) {
#line 264 "rygel-http-byte-seek.c"
			_inner_error_ = g_error_new (RYGEL_HTTP_SEEK_ERROR, RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE, "Invalid Range '%s'", range);
			{
				if (_inner_error_->domain == RYGEL_HTTP_SEEK_ERROR) {
					g_propagate_error (error, _inner_error_);
					_g_free0 (range);
					_g_free0 (pos);
					range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
					g_object_unref (self);
					return NULL;
				} else {
					_g_free0 (range);
					_g_free0 (pos);
					range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
					g_clear_error (&_inner_error_);
					return NULL;
				}
			}
		}
#line 47 "rygel-http-byte-seek.vala"
		range_tokens = (_tmp2_ = _tmp1_ = g_strsplit (g_utf8_offset_to_pointer (range, (glong) 6), "-", 2), range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL), range_tokens_length1 = _vala_array_length (_tmp1_), _range_tokens_size_ = range_tokens_length1, _tmp2_);
#line 48 "rygel-http-byte-seek.vala"
		if (range_tokens[0] == NULL) {
#line 48 "rygel-http-byte-seek.vala"
			_tmp3_ = TRUE;
#line 290 "rygel-http-byte-seek.c"
		} else {
#line 48 "rygel-http-byte-seek.vala"
			_tmp3_ = range_tokens[1] == NULL;
#line 294 "rygel-http-byte-seek.c"
		}
#line 48 "rygel-http-byte-seek.vala"
		if (_tmp3_) {
#line 298 "rygel-http-byte-seek.c"
			_inner_error_ = g_error_new (RYGEL_HTTP_SEEK_ERROR, RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE, "Invalid Range '%s'", range);
			{
				if (_inner_error_->domain == RYGEL_HTTP_SEEK_ERROR) {
					g_propagate_error (error, _inner_error_);
					_g_free0 (range);
					_g_free0 (pos);
					range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
					g_object_unref (self);
					return NULL;
				} else {
					_g_free0 (range);
					_g_free0 (pos);
					range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
					g_clear_error (&_inner_error_);
					return NULL;
				}
			}
		}
#line 54 "rygel-http-byte-seek.vala"
		pos = (_tmp4_ = g_strdup (range_tokens[0]), _g_free0 (pos), _tmp4_);
#line 55 "rygel-http-byte-seek.vala"
		if (g_unichar_isdigit (g_utf8_get_char (g_utf8_offset_to_pointer (pos, 0)))) {
#line 56 "rygel-http-byte-seek.vala"
			start = g_ascii_strtoll (pos, NULL, 0);
#line 324 "rygel-http-byte-seek.c"
		} else {
#line 57 "rygel-http-byte-seek.vala"
			if (_vala_strcmp0 (pos, "") != 0) {
#line 328 "rygel-http-byte-seek.c"
				_inner_error_ = g_error_new (RYGEL_HTTP_SEEK_ERROR, RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE, "Invalid Range '%s'", range);
				{
					if (_inner_error_->domain == RYGEL_HTTP_SEEK_ERROR) {
						g_propagate_error (error, _inner_error_);
						_g_free0 (range);
						_g_free0 (pos);
						range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
						g_object_unref (self);
						return NULL;
					} else {
						_g_free0 (range);
						_g_free0 (pos);
						range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
						g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
						g_clear_error (&_inner_error_);
						return NULL;
					}
				}
			}
		}
#line 63 "rygel-http-byte-seek.vala"
		pos = (_tmp5_ = g_strdup (range_tokens[1]), _g_free0 (pos), _tmp5_);
#line 64 "rygel-http-byte-seek.vala"
		if (g_unichar_isdigit (g_utf8_get_char (g_utf8_offset_to_pointer (pos, 0)))) {
#line 65 "rygel-http-byte-seek.vala"
			stop = g_ascii_strtoll (pos, NULL, 0);
#line 66 "rygel-http-byte-seek.vala"
			if (stop < start) {
#line 357 "rygel-http-byte-seek.c"
				_inner_error_ = g_error_new (RYGEL_HTTP_SEEK_ERROR, RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE, "Invalid Range '%s'", range);
				{
					if (_inner_error_->domain == RYGEL_HTTP_SEEK_ERROR) {
						g_propagate_error (error, _inner_error_);
						_g_free0 (range);
						_g_free0 (pos);
						range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
						g_object_unref (self);
						return NULL;
					} else {
						_g_free0 (range);
						_g_free0 (pos);
						range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
						g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
						g_clear_error (&_inner_error_);
						return NULL;
					}
				}
			}
		} else {
#line 70 "rygel-http-byte-seek.vala"
			if (_vala_strcmp0 (pos, "") != 0) {
#line 380 "rygel-http-byte-seek.c"
				_inner_error_ = g_error_new (RYGEL_HTTP_SEEK_ERROR, RYGEL_HTTP_SEEK_ERROR_INVALID_RANGE, "Invalid Range '%s'", range);
				{
					if (_inner_error_->domain == RYGEL_HTTP_SEEK_ERROR) {
						g_propagate_error (error, _inner_error_);
						_g_free0 (range);
						_g_free0 (pos);
						range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
						g_object_unref (self);
						return NULL;
					} else {
						_g_free0 (range);
						_g_free0 (pos);
						range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
						g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
						g_clear_error (&_inner_error_);
						return NULL;
					}
				}
			}
		}
	}
#line 76 "rygel-http-byte-seek.vala"
	self = (RygelHTTPByteSeek*) rygel_http_seek_construct (object_type, request->msg, start, stop, total_length);
#line 404 "rygel-http-byte-seek.c"
	_g_free0 (range);
	_g_free0 (pos);
	range_tokens = (_vala_array_free (range_tokens, range_tokens_length1, (GDestroyNotify) g_free), NULL);
	return self;
}


#line 25 "rygel-http-byte-seek.vala"
RygelHTTPByteSeek* rygel_http_byte_seek_new (RygelHTTPGet* request, GError** error) {
#line 25 "rygel-http-byte-seek.vala"
	return rygel_http_byte_seek_construct (RYGEL_TYPE_HTTP_BYTE_SEEK, request, error);
#line 416 "rygel-http-byte-seek.c"
}


#line 82 "rygel-http-byte-seek.vala"
gboolean rygel_http_byte_seek_needed (RygelHTTPGet* request) {
#line 422 "rygel-http-byte-seek.c"
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_ = FALSE;
#line 82 "rygel-http-byte-seek.vala"
	g_return_val_if_fail (request != NULL, FALSE);
#line 83 "rygel-http-byte-seek.vala"
	if (request->item->size > 0) {
#line 84 "rygel-http-byte-seek.vala"
		_tmp2_ = RYGEL_IS_HTTP_IDENTITY_HANDLER (request->handler);
#line 433 "rygel-http-byte-seek.c"
	} else {
#line 83 "rygel-http-byte-seek.vala"
		_tmp2_ = FALSE;
#line 437 "rygel-http-byte-seek.c"
	}
#line 83 "rygel-http-byte-seek.vala"
	if (_tmp2_) {
#line 83 "rygel-http-byte-seek.vala"
		_tmp1_ = TRUE;
#line 443 "rygel-http-byte-seek.c"
	} else {
		gboolean _tmp3_ = FALSE;
#line 85 "rygel-http-byte-seek.vala"
		if (request->thumbnail != NULL) {
#line 85 "rygel-http-byte-seek.vala"
			_tmp3_ = request->thumbnail->size > 0;
#line 450 "rygel-http-byte-seek.c"
		} else {
#line 85 "rygel-http-byte-seek.vala"
			_tmp3_ = FALSE;
#line 454 "rygel-http-byte-seek.c"
		}
#line 85 "rygel-http-byte-seek.vala"
		_tmp1_ = _tmp3_;
#line 458 "rygel-http-byte-seek.c"
	}
#line 83 "rygel-http-byte-seek.vala"
	if (_tmp1_) {
#line 83 "rygel-http-byte-seek.vala"
		_tmp0_ = TRUE;
#line 464 "rygel-http-byte-seek.c"
	} else {
		gboolean _tmp4_ = FALSE;
#line 86 "rygel-http-byte-seek.vala"
		if (request->subtitle != NULL) {
#line 86 "rygel-http-byte-seek.vala"
			_tmp4_ = request->subtitle->size > 0;
#line 471 "rygel-http-byte-seek.c"
		} else {
#line 86 "rygel-http-byte-seek.vala"
			_tmp4_ = FALSE;
#line 475 "rygel-http-byte-seek.c"
		}
#line 86 "rygel-http-byte-seek.vala"
		_tmp0_ = _tmp4_;
#line 479 "rygel-http-byte-seek.c"
	}
	result = _tmp0_;
#line 83 "rygel-http-byte-seek.vala"
	return result;
#line 484 "rygel-http-byte-seek.c"
}


#line 89 "rygel-http-byte-seek.vala"
static void rygel_http_byte_seek_real_add_response_headers (RygelHTTPSeek* base) {
#line 490 "rygel-http-byte-seek.c"
	RygelHTTPByteSeek * self;
	char* range;
	SoupMessageHeaders* headers;
	char* _tmp7_;
	char* _tmp6_;
	char* _tmp5_;
	char* _tmp4_;
	char* _tmp3_;
	char* _tmp2_;
	char* _tmp1_;
	char* _tmp0_;
	self = (RygelHTTPByteSeek*) base;
#line 91 "rygel-http-byte-seek.vala"
	range = g_strdup ("bytes ");
#line 92 "rygel-http-byte-seek.vala"
	headers = rygel_http_seek_get_msg ((RygelHTTPSeek*) self)->response_headers;
#line 94 "rygel-http-byte-seek.vala"
	soup_message_headers_append (headers, "Accept-Ranges", "bytes");
#line 96 "rygel-http-byte-seek.vala"
	range = (_tmp7_ = g_strconcat (range, _tmp6_ = g_strconcat (_tmp4_ = g_strconcat (_tmp3_ = g_strconcat (_tmp1_ = g_strconcat (_tmp0_ = g_strdup_printf ("%lli", rygel_http_seek_get_start ((RygelHTTPSeek*) self)), "-", NULL), _tmp2_ = g_strdup_printf ("%lli", rygel_http_seek_get_stop ((RygelHTTPSeek*) self)), NULL), "/", NULL), _tmp5_ = g_strdup_printf ("%lli", rygel_http_seek_get_length ((RygelHTTPSeek*) self)), NULL), NULL), _g_free0 (range), _tmp7_);
#line 511 "rygel-http-byte-seek.c"
	_g_free0 (_tmp6_);
	_g_free0 (_tmp5_);
	_g_free0 (_tmp4_);
	_g_free0 (_tmp3_);
	_g_free0 (_tmp2_);
	_g_free0 (_tmp1_);
	_g_free0 (_tmp0_);
#line 99 "rygel-http-byte-seek.vala"
	soup_message_headers_append (headers, "Content-Range", range);
#line 101 "rygel-http-byte-seek.vala"
	soup_message_headers_set_content_length (headers, (rygel_http_seek_get_stop ((RygelHTTPSeek*) self) + 1) - rygel_http_seek_get_start ((RygelHTTPSeek*) self));
#line 523 "rygel-http-byte-seek.c"
	_g_free0 (range);
}


static void rygel_http_byte_seek_class_init (RygelHTTPByteSeekClass * klass) {
	rygel_http_byte_seek_parent_class = g_type_class_peek_parent (klass);
	RYGEL_HTTP_SEEK_CLASS (klass)->add_response_headers = rygel_http_byte_seek_real_add_response_headers;
}


static void rygel_http_byte_seek_instance_init (RygelHTTPByteSeek * self) {
}


GType rygel_http_byte_seek_get_type (void) {
	static volatile gsize rygel_http_byte_seek_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_http_byte_seek_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelHTTPByteSeekClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_http_byte_seek_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelHTTPByteSeek), 0, (GInstanceInitFunc) rygel_http_byte_seek_instance_init, NULL };
		GType rygel_http_byte_seek_type_id;
		rygel_http_byte_seek_type_id = g_type_register_static (RYGEL_TYPE_HTTP_SEEK, "RygelHTTPByteSeek", &g_define_type_info, 0);
		g_once_init_leave (&rygel_http_byte_seek_type_id__volatile, rygel_http_byte_seek_type_id);
	}
	return rygel_http_byte_seek_type_id__volatile;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
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



