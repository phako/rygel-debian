/* rygel-http-item-uri.c generated by valac, the Vala compiler
 * generated from rygel-http-item-uri.vala, do not modify */

/*
 * Copyright (C) 2009 Jens Georg <mail@jensge.org>.
 * Copyright (C) 2010 Nokia Corporation.
 *
 * Authors: Jens Georg <mail@jensge.org>
 *          Zeeshan Ali (Khattak) <zeeshan.ali@nokia.com>
 *                                <zeeshanak@gnome.org>
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
#include <glib/gi18n-lib.h>
#include <libsoup/soup.h>
#include <libgupnp/gupnp.h>
#include <libgssdp/gssdp.h>


#define RYGEL_TYPE_HTTP_ITEM_URI (rygel_http_item_uri_get_type ())
#define RYGEL_HTTP_ITEM_URI(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_ITEM_URI, RygelHTTPItemURI))
#define RYGEL_HTTP_ITEM_URI_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_ITEM_URI, RygelHTTPItemURIClass))
#define RYGEL_IS_HTTP_ITEM_URI(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_ITEM_URI))
#define RYGEL_IS_HTTP_ITEM_URI_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_ITEM_URI))
#define RYGEL_HTTP_ITEM_URI_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_ITEM_URI, RygelHTTPItemURIClass))

typedef struct _RygelHTTPItemURI RygelHTTPItemURI;
typedef struct _RygelHTTPItemURIClass RygelHTTPItemURIClass;
typedef struct _RygelHTTPItemURIPrivate RygelHTTPItemURIPrivate;

#define RYGEL_TYPE_HTTP_SERVER (rygel_http_server_get_type ())
#define RYGEL_HTTP_SERVER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_SERVER, RygelHTTPServer))
#define RYGEL_HTTP_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_SERVER, RygelHTTPServerClass))
#define RYGEL_IS_HTTP_SERVER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_SERVER))
#define RYGEL_IS_HTTP_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_SERVER))
#define RYGEL_HTTP_SERVER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_SERVER, RygelHTTPServerClass))

typedef struct _RygelHTTPServer RygelHTTPServer;
typedef struct _RygelHTTPServerClass RygelHTTPServerClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_regex_unref0(var) ((var == NULL) ? NULL : (var = (g_regex_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_string_free0(var) ((var == NULL) ? NULL : (var = (g_string_free (var, TRUE), NULL)))
typedef struct _RygelHTTPServerPrivate RygelHTTPServerPrivate;

struct _RygelHTTPItemURI {
	GObject parent_instance;
	RygelHTTPItemURIPrivate * priv;
	char* item_id;
	gint thumbnail_index;
	gint subtitle_index;
	char* transcode_target;
	RygelHTTPServer* http_server;
};

struct _RygelHTTPItemURIClass {
	GObjectClass parent_class;
};

typedef enum  {
	RYGEL_HTTP_REQUEST_ERROR_UNACCEPTABLE = SOUP_STATUS_NOT_ACCEPTABLE,
	RYGEL_HTTP_REQUEST_ERROR_BAD_REQUEST = SOUP_STATUS_BAD_REQUEST,
	RYGEL_HTTP_REQUEST_ERROR_NOT_FOUND = SOUP_STATUS_NOT_FOUND
} RygelHTTPRequestError;
#define RYGEL_HTTP_REQUEST_ERROR rygel_http_request_error_quark ()
struct _RygelHTTPServer {
	GObject parent_instance;
	RygelHTTPServerPrivate * priv;
	GUPnPContext* context;
};

struct _RygelHTTPServerClass {
	GObjectClass parent_class;
};


static gpointer rygel_http_item_uri_parent_class = NULL;

GType rygel_http_item_uri_get_type (void) G_GNUC_CONST;
GType rygel_http_server_get_type (void) G_GNUC_CONST;
enum  {
	RYGEL_HTTP_ITEM_URI_DUMMY_PROPERTY
};
RygelHTTPItemURI* rygel_http_item_uri_new (const char* item_id, RygelHTTPServer* http_server, gint thumbnail_index, gint subtitle_index, const char* transcode_target);
RygelHTTPItemURI* rygel_http_item_uri_construct (GType object_type, const char* item_id, RygelHTTPServer* http_server, gint thumbnail_index, gint subtitle_index, const char* transcode_target);
const char* rygel_http_server_get_path_root (RygelHTTPServer* self);
GQuark rygel_http_request_error_quark (void);
RygelHTTPItemURI* rygel_http_item_uri_new_from_string (const char* uri, RygelHTTPServer* http_server, GError** error);
RygelHTTPItemURI* rygel_http_item_uri_construct_from_string (GType object_type, const char* uri, RygelHTTPServer* http_server, GError** error);
static char* rygel_http_item_uri_create_uri_for_path (RygelHTTPItemURI* self, const char* path);
char* rygel_http_item_uri_to_string (RygelHTTPItemURI* self);
static void rygel_http_item_uri_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);



static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


#line 33 "rygel-http-item-uri.vala"
RygelHTTPItemURI* rygel_http_item_uri_construct (GType object_type, const char* item_id, RygelHTTPServer* http_server, gint thumbnail_index, gint subtitle_index, const char* transcode_target) {
#line 127 "rygel-http-item-uri.c"
	RygelHTTPItemURI * self;
	char* _tmp0_;
	char* _tmp1_;
	RygelHTTPServer* _tmp2_;
#line 33 "rygel-http-item-uri.vala"
	g_return_val_if_fail (item_id != NULL, NULL);
#line 33 "rygel-http-item-uri.vala"
	g_return_val_if_fail (http_server != NULL, NULL);
#line 33 "rygel-http-item-uri.vala"
	self = (RygelHTTPItemURI*) g_object_new (object_type, NULL);
#line 38 "rygel-http-item-uri.vala"
	self->item_id = (_tmp0_ = g_strdup (item_id), _g_free0 (self->item_id), _tmp0_);
#line 39 "rygel-http-item-uri.vala"
	self->thumbnail_index = thumbnail_index;
#line 40 "rygel-http-item-uri.vala"
	self->subtitle_index = subtitle_index;
#line 41 "rygel-http-item-uri.vala"
	self->transcode_target = (_tmp1_ = g_strdup (transcode_target), _g_free0 (self->transcode_target), _tmp1_);
#line 42 "rygel-http-item-uri.vala"
	self->http_server = (_tmp2_ = _g_object_ref0 (http_server), _g_object_unref0 (self->http_server), _tmp2_);
#line 148 "rygel-http-item-uri.c"
	return self;
}


#line 33 "rygel-http-item-uri.vala"
RygelHTTPItemURI* rygel_http_item_uri_new (const char* item_id, RygelHTTPServer* http_server, gint thumbnail_index, gint subtitle_index, const char* transcode_target) {
#line 33 "rygel-http-item-uri.vala"
	return rygel_http_item_uri_construct (RYGEL_TYPE_HTTP_ITEM_URI, item_id, http_server, thumbnail_index, subtitle_index, transcode_target);
#line 157 "rygel-http-item-uri.c"
}


#line 1156 "glib-2.0.vapi"
static char* string_replace (const char* self, const char* old, const char* replacement) {
#line 163 "rygel-http-item-uri.c"
	char* result = NULL;
	GError * _inner_error_;
#line 1156 "glib-2.0.vapi"
	g_return_val_if_fail (self != NULL, NULL);
#line 1156 "glib-2.0.vapi"
	g_return_val_if_fail (old != NULL, NULL);
#line 1156 "glib-2.0.vapi"
	g_return_val_if_fail (replacement != NULL, NULL);
#line 172 "rygel-http-item-uri.c"
	_inner_error_ = NULL;
	{
		char* _tmp0_;
		GRegex* _tmp1_;
		GRegex* regex;
		char* _tmp2_;
#line 1158 "glib-2.0.vapi"
		regex = (_tmp1_ = g_regex_new (_tmp0_ = g_regex_escape_string (old, -1), 0, 0, &_inner_error_), _g_free0 (_tmp0_), _tmp1_);
#line 181 "rygel-http-item-uri.c"
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch2_g_regex_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
#line 1159 "glib-2.0.vapi"
		_tmp2_ = g_regex_replace_literal (regex, self, (gssize) (-1), 0, replacement, 0, &_inner_error_);
#line 192 "rygel-http-item-uri.c"
		if (_inner_error_ != NULL) {
			_g_regex_unref0 (regex);
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch2_g_regex_error;
			}
			_g_regex_unref0 (regex);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		result = _tmp2_;
		_g_regex_unref0 (regex);
#line 1159 "glib-2.0.vapi"
		return result;
#line 207 "rygel-http-item-uri.c"
	}
	goto __finally2;
	__catch2_g_regex_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
#line 1161 "glib-2.0.vapi"
			g_assert_not_reached ();
#line 218 "rygel-http-item-uri.c"
			_g_error_free0 (e);
		}
	}
	__finally2:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
}


#line 45 "rygel-http-item-uri.vala"
RygelHTTPItemURI* rygel_http_item_uri_construct_from_string (GType object_type, const char* uri, RygelHTTPServer* http_server, GError** error) {
#line 233 "rygel-http-item-uri.c"
	GError * _inner_error_;
	RygelHTTPItemURI * self;
	char* _tmp0_;
	RygelHTTPServer* _tmp1_;
	char* request_uri;
	char** _tmp3_;
	gint _parts_size_;
	gint parts_length1;
	char** _tmp2_;
	char** parts;
	gboolean _tmp4_ = FALSE;
#line 45 "rygel-http-item-uri.vala"
	g_return_val_if_fail (uri != NULL, NULL);
#line 45 "rygel-http-item-uri.vala"
	g_return_val_if_fail (http_server != NULL, NULL);
#line 249 "rygel-http-item-uri.c"
	_inner_error_ = NULL;
#line 45 "rygel-http-item-uri.vala"
	self = (RygelHTTPItemURI*) g_object_new (object_type, NULL);
#line 49 "rygel-http-item-uri.vala"
	self->thumbnail_index = -1;
#line 50 "rygel-http-item-uri.vala"
	self->subtitle_index = -1;
#line 51 "rygel-http-item-uri.vala"
	self->transcode_target = (_tmp0_ = NULL, _g_free0 (self->transcode_target), _tmp0_);
#line 52 "rygel-http-item-uri.vala"
	self->http_server = (_tmp1_ = _g_object_ref0 (http_server), _g_object_unref0 (self->http_server), _tmp1_);
#line 54 "rygel-http-item-uri.vala"
	request_uri = string_replace (uri, rygel_http_server_get_path_root (http_server), "");
#line 263 "rygel-http-item-uri.c"
	parts = (_tmp3_ = _tmp2_ = g_strsplit (request_uri, "/", 0), parts_length1 = _vala_array_length (_tmp2_), _parts_size_ = parts_length1, _tmp3_);
#line 57 "rygel-http-item-uri.vala"
	if (parts_length1 < 2) {
#line 57 "rygel-http-item-uri.vala"
		_tmp4_ = TRUE;
#line 269 "rygel-http-item-uri.c"
	} else {
#line 57 "rygel-http-item-uri.vala"
		_tmp4_ = (parts_length1 % 2) == 0;
#line 273 "rygel-http-item-uri.c"
	}
#line 57 "rygel-http-item-uri.vala"
	if (_tmp4_) {
#line 277 "rygel-http-item-uri.c"
		_inner_error_ = g_error_new (RYGEL_HTTP_REQUEST_ERROR, RYGEL_HTTP_REQUEST_ERROR_BAD_REQUEST, _ ("Invalid URI '%s'"), request_uri);
		{
			if (_inner_error_->domain == RYGEL_HTTP_REQUEST_ERROR) {
				g_propagate_error (error, _inner_error_);
				parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
				_g_free0 (request_uri);
				_g_object_unref0 (self);
				return NULL;
			} else {
				parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
				_g_free0 (request_uri);
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return NULL;
			}
		}
	}
	{
		gint i;
#line 62 "rygel-http-item-uri.vala"
		i = 1;
#line 299 "rygel-http-item-uri.c"
		{
			gboolean _tmp5_;
#line 62 "rygel-http-item-uri.vala"
			_tmp5_ = TRUE;
#line 62 "rygel-http-item-uri.vala"
			while (TRUE) {
#line 306 "rygel-http-item-uri.c"
				GQuark _tmp13_;
				const char* _tmp12_;
				static GQuark _tmp13__label0 = 0;
				static GQuark _tmp13__label1 = 0;
				static GQuark _tmp13__label2 = 0;
				static GQuark _tmp13__label3 = 0;
#line 62 "rygel-http-item-uri.vala"
				if (!_tmp5_) {
#line 62 "rygel-http-item-uri.vala"
					i = i + 2;
#line 317 "rygel-http-item-uri.c"
				}
#line 62 "rygel-http-item-uri.vala"
				_tmp5_ = FALSE;
#line 62 "rygel-http-item-uri.vala"
				if (!(i < (parts_length1 - 1))) {
#line 62 "rygel-http-item-uri.vala"
					break;
#line 325 "rygel-http-item-uri.c"
				}
				_tmp12_ = parts[i];
				_tmp13_ = (NULL == _tmp12_) ? 0 : g_quark_from_string (_tmp12_);
				if (_tmp13_ == ((0 != _tmp13__label0) ? _tmp13__label0 : (_tmp13__label0 = g_quark_from_static_string ("item"))))
				switch (0) {
					default:
					{
						guchar* _tmp9_;
						gint _data_size_;
						gint data_length1;
						size_t _tmp7_;
						char* _tmp6_;
						guchar* _tmp8_;
						guchar* data;
						GString* builder;
						char* _tmp10_;
						data = (_tmp9_ = (_tmp8_ = g_base64_decode (_tmp6_ = soup_uri_decode (parts[i + 1]), &_tmp7_), _g_free0 (_tmp6_), _tmp8_), data_length1 = _tmp7_, _data_size_ = data_length1, _tmp9_);
#line 66 "rygel-http-item-uri.vala"
						builder = g_string_new ("");
#line 67 "rygel-http-item-uri.vala"
						g_string_append (builder, (const char*) data);
#line 68 "rygel-http-item-uri.vala"
						self->item_id = (_tmp10_ = g_strdup (builder->str), _g_free0 (self->item_id), _tmp10_);
#line 349 "rygel-http-item-uri.c"
						_g_string_free0 (builder);
						data = (g_free (data), NULL);
#line 70 "rygel-http-item-uri.vala"
						break;
#line 354 "rygel-http-item-uri.c"
					}
				} else if (_tmp13_ == ((0 != _tmp13__label1) ? _tmp13__label1 : (_tmp13__label1 = g_quark_from_static_string ("transcoded"))))
				switch (0) {
					default:
					{
						char* _tmp11_;
#line 72 "rygel-http-item-uri.vala"
						self->transcode_target = (_tmp11_ = soup_uri_decode (parts[i + 1]), _g_free0 (self->transcode_target), _tmp11_);
#line 74 "rygel-http-item-uri.vala"
						break;
#line 365 "rygel-http-item-uri.c"
					}
				} else if (_tmp13_ == ((0 != _tmp13__label2) ? _tmp13__label2 : (_tmp13__label2 = g_quark_from_static_string ("thumbnail"))))
				switch (0) {
					default:
					{
#line 76 "rygel-http-item-uri.vala"
						self->thumbnail_index = atoi (parts[i + 1]);
#line 78 "rygel-http-item-uri.vala"
						break;
#line 375 "rygel-http-item-uri.c"
					}
				} else if (_tmp13_ == ((0 != _tmp13__label3) ? _tmp13__label3 : (_tmp13__label3 = g_quark_from_static_string ("subtitle"))))
				switch (0) {
					default:
					{
#line 80 "rygel-http-item-uri.vala"
						self->subtitle_index = atoi (parts[i + 1]);
#line 82 "rygel-http-item-uri.vala"
						break;
#line 385 "rygel-http-item-uri.c"
					}
				} else
				switch (0) {
					default:
					{
#line 84 "rygel-http-item-uri.vala"
						break;
#line 393 "rygel-http-item-uri.c"
					}
				}
			}
		}
	}
#line 88 "rygel-http-item-uri.vala"
	if (self->item_id == NULL) {
#line 401 "rygel-http-item-uri.c"
		_inner_error_ = g_error_new_literal (RYGEL_HTTP_REQUEST_ERROR, RYGEL_HTTP_REQUEST_ERROR_NOT_FOUND, _ ("Not Found"));
		{
			if (_inner_error_->domain == RYGEL_HTTP_REQUEST_ERROR) {
				g_propagate_error (error, _inner_error_);
				parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
				_g_free0 (request_uri);
				_g_object_unref0 (self);
				return NULL;
			} else {
				parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
				_g_free0 (request_uri);
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return NULL;
			}
		}
	}
	parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
	_g_free0 (request_uri);
	return self;
}


#line 45 "rygel-http-item-uri.vala"
RygelHTTPItemURI* rygel_http_item_uri_new_from_string (const char* uri, RygelHTTPServer* http_server, GError** error) {
#line 45 "rygel-http-item-uri.vala"
	return rygel_http_item_uri_construct_from_string (RYGEL_TYPE_HTTP_ITEM_URI, uri, http_server, error);
#line 429 "rygel-http-item-uri.c"
}


#line 1169 "glib-2.0.vapi"
static gchar* string_to_utf8 (const char* self, int* result_length1) {
#line 435 "rygel-http-item-uri.c"
	gchar* result = NULL;
	gchar* _tmp1_;
	gint __result__size_;
	gint _result__length1;
	gint _tmp0_;
	gchar* _result_;
	gchar* _tmp2_;
#line 1169 "glib-2.0.vapi"
	g_return_val_if_fail (self != NULL, NULL);
#line 445 "rygel-http-item-uri.c"
	_result_ = (_tmp1_ = g_new0 (gchar, _tmp0_ = strlen (self) + 1), _result__length1 = _tmp0_, __result__size_ = _result__length1, _tmp1_);
#line 1171 "glib-2.0.vapi"
	_result__length1--;
#line 1172 "glib-2.0.vapi"
	memcpy (_result_, self, strlen (self));
#line 451 "rygel-http-item-uri.c"
	result = (_tmp2_ = _result_, *result_length1 = _result__length1, _tmp2_);
#line 1173 "glib-2.0.vapi"
	return result;
#line 455 "rygel-http-item-uri.c"
	_result_ = (g_free (_result_), NULL);
}


#line 93 "rygel-http-item-uri.vala"
char* rygel_http_item_uri_to_string (RygelHTTPItemURI* self) {
#line 462 "rygel-http-item-uri.c"
	char* result = NULL;
	gchar* _tmp1_;
	gint _data_size_;
	gint data_length1;
	gint _tmp0_;
	gchar* data;
	char* _tmp2_;
	char* _tmp3_;
	char* escaped;
	char* path;
#line 93 "rygel-http-item-uri.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 475 "rygel-http-item-uri.c"
	data = (_tmp1_ = string_to_utf8 (self->item_id, &_tmp0_), data_length1 = _tmp0_, _data_size_ = data_length1, _tmp1_);
#line 98 "rygel-http-item-uri.vala"
	escaped = (_tmp3_ = g_uri_escape_string (_tmp2_ = g_base64_encode ((guchar*) data, data_length1), "", TRUE), _g_free0 (_tmp2_), _tmp3_);
#line 101 "rygel-http-item-uri.vala"
	path = g_strconcat ("/item/", escaped, NULL);
#line 103 "rygel-http-item-uri.vala"
	if (self->transcode_target != NULL) {
#line 483 "rygel-http-item-uri.c"
		char* _tmp4_;
		char* _tmp6_;
		char* _tmp5_;
#line 104 "rygel-http-item-uri.vala"
		escaped = (_tmp4_ = g_uri_escape_string (self->transcode_target, "", TRUE), _g_free0 (escaped), _tmp4_);
#line 105 "rygel-http-item-uri.vala"
		path = (_tmp6_ = g_strconcat (path, _tmp5_ = g_strconcat ("/transcoded/", escaped, NULL), NULL), _g_free0 (path), _tmp6_);
#line 491 "rygel-http-item-uri.c"
		_g_free0 (_tmp5_);
	} else {
#line 106 "rygel-http-item-uri.vala"
		if (self->thumbnail_index >= 0) {
#line 496 "rygel-http-item-uri.c"
			char* _tmp9_;
			char* _tmp8_;
			char* _tmp7_;
#line 107 "rygel-http-item-uri.vala"
			path = (_tmp9_ = g_strconcat (path, _tmp8_ = g_strconcat ("/thumbnail/", _tmp7_ = g_strdup_printf ("%i", self->thumbnail_index), NULL), NULL), _g_free0 (path), _tmp9_);
#line 502 "rygel-http-item-uri.c"
			_g_free0 (_tmp8_);
			_g_free0 (_tmp7_);
		} else {
#line 108 "rygel-http-item-uri.vala"
			if (self->subtitle_index >= 0) {
#line 508 "rygel-http-item-uri.c"
				char* _tmp12_;
				char* _tmp11_;
				char* _tmp10_;
#line 109 "rygel-http-item-uri.vala"
				path = (_tmp12_ = g_strconcat (path, _tmp11_ = g_strconcat ("/subtitle/", _tmp10_ = g_strdup_printf ("%i", self->subtitle_index), NULL), NULL), _g_free0 (path), _tmp12_);
#line 514 "rygel-http-item-uri.c"
				_g_free0 (_tmp11_);
				_g_free0 (_tmp10_);
			}
		}
	}
	result = rygel_http_item_uri_create_uri_for_path (self, path);
	_g_free0 (path);
	_g_free0 (escaped);
	data = (g_free (data), NULL);
#line 112 "rygel-http-item-uri.vala"
	return result;
#line 526 "rygel-http-item-uri.c"
}


#line 115 "rygel-http-item-uri.vala"
static char* rygel_http_item_uri_create_uri_for_path (RygelHTTPItemURI* self, const char* path) {
#line 532 "rygel-http-item-uri.c"
	char* result = NULL;
#line 115 "rygel-http-item-uri.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 115 "rygel-http-item-uri.vala"
	g_return_val_if_fail (path != NULL, NULL);
#line 538 "rygel-http-item-uri.c"
	result = g_strdup_printf ("http://%s:%u%s%s", gssdp_client_get_host_ip ((GSSDPClient*) self->http_server->context), gupnp_context_get_port (self->http_server->context), rygel_http_server_get_path_root (self->http_server), path);
#line 116 "rygel-http-item-uri.vala"
	return result;
#line 542 "rygel-http-item-uri.c"
}


static void rygel_http_item_uri_class_init (RygelHTTPItemURIClass * klass) {
	rygel_http_item_uri_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = rygel_http_item_uri_finalize;
}


static void rygel_http_item_uri_instance_init (RygelHTTPItemURI * self) {
}


static void rygel_http_item_uri_finalize (GObject* obj) {
	RygelHTTPItemURI * self;
	self = RYGEL_HTTP_ITEM_URI (obj);
	_g_free0 (self->item_id);
	_g_free0 (self->transcode_target);
	_g_object_unref0 (self->http_server);
	G_OBJECT_CLASS (rygel_http_item_uri_parent_class)->finalize (obj);
}


GType rygel_http_item_uri_get_type (void) {
	static volatile gsize rygel_http_item_uri_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_http_item_uri_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelHTTPItemURIClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_http_item_uri_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelHTTPItemURI), 0, (GInstanceInitFunc) rygel_http_item_uri_instance_init, NULL };
		GType rygel_http_item_uri_type_id;
		rygel_http_item_uri_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelHTTPItemURI", &g_define_type_info, 0);
		g_once_init_leave (&rygel_http_item_uri_type_id__volatile, rygel_http_item_uri_type_id);
	}
	return rygel_http_item_uri_type_id__volatile;
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




