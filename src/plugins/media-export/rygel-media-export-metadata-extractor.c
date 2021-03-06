/* rygel-media-export-metadata-extractor.c generated by valac, the Vala compiler
 * generated from rygel-media-export-metadata-extractor.vala, do not modify */

/*
 * Copyright (C) 2008 Zeeshan Ali (Khattak) <zeeshanak@gnome.org>.
 * Copyright (C) 2009 Jens Georg <mail@jensge.org>.
 *
 * Author: Zeeshan Ali (Khattak) <zeeshanak@gnome.org>
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
#include <libgupnp-dlna/gupnp-dlna-discoverer.h>
#include <gee.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>
#include <rygel.h>
#include <gst/gst.h>
#include <libgupnp-dlna/gupnp-dlna-information.h>
#include <gst/discoverer/gstdiscoverer.h>
#include <glib/gi18n-lib.h>


#define RYGEL_MEDIA_EXPORT_TYPE_METADATA_EXTRACTOR (rygel_media_export_metadata_extractor_get_type ())
#define RYGEL_MEDIA_EXPORT_METADATA_EXTRACTOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_MEDIA_EXPORT_TYPE_METADATA_EXTRACTOR, RygelMediaExportMetadataExtractor))
#define RYGEL_MEDIA_EXPORT_METADATA_EXTRACTOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_MEDIA_EXPORT_TYPE_METADATA_EXTRACTOR, RygelMediaExportMetadataExtractorClass))
#define RYGEL_MEDIA_EXPORT_IS_METADATA_EXTRACTOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_MEDIA_EXPORT_TYPE_METADATA_EXTRACTOR))
#define RYGEL_MEDIA_EXPORT_IS_METADATA_EXTRACTOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_MEDIA_EXPORT_TYPE_METADATA_EXTRACTOR))
#define RYGEL_MEDIA_EXPORT_METADATA_EXTRACTOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_MEDIA_EXPORT_TYPE_METADATA_EXTRACTOR, RygelMediaExportMetadataExtractorClass))

typedef struct _RygelMediaExportMetadataExtractor RygelMediaExportMetadataExtractor;
typedef struct _RygelMediaExportMetadataExtractorClass RygelMediaExportMetadataExtractorClass;
typedef struct _RygelMediaExportMetadataExtractorPrivate RygelMediaExportMetadataExtractorPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _RygelMediaExportMetadataExtractor {
	GObject parent_instance;
	RygelMediaExportMetadataExtractorPrivate * priv;
};

struct _RygelMediaExportMetadataExtractorClass {
	GObjectClass parent_class;
};

struct _RygelMediaExportMetadataExtractorPrivate {
	GUPnPDLNADiscoverer* discoverer;
	GeeHashMap* file_hash;
	guint64 timeout;
	gboolean extract_metadata;
};


static gpointer rygel_media_export_metadata_extractor_parent_class = NULL;

GType rygel_media_export_metadata_extractor_get_type (void) G_GNUC_CONST;
#define RYGEL_MEDIA_EXPORT_METADATA_EXTRACTOR_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_MEDIA_EXPORT_TYPE_METADATA_EXTRACTOR, RygelMediaExportMetadataExtractorPrivate))
enum  {
	RYGEL_MEDIA_EXPORT_METADATA_EXTRACTOR_DUMMY_PROPERTY
};
static void rygel_media_export_metadata_extractor_on_done (RygelMediaExportMetadataExtractor* self, GUPnPDLNAInformation* dlna, GError* err);
static void _rygel_media_export_metadata_extractor_on_done_gupnp_dlna_discoverer_done (GUPnPDLNADiscoverer* _sender, GUPnPDLNAInformation* dlna, GError* err, gpointer self);
RygelMediaExportMetadataExtractor* rygel_media_export_metadata_extractor_new (void);
RygelMediaExportMetadataExtractor* rygel_media_export_metadata_extractor_construct (GType object_type);
static void rygel_media_export_metadata_extractor_extract_file_info (RygelMediaExportMetadataExtractor* self, GFile* file, char** mime, guint64* size, guint64* mtime, GError** error);
void rygel_media_export_metadata_extractor_extract (RygelMediaExportMetadataExtractor* self, GFile* file);
static void rygel_media_export_metadata_extractor_finalize (GObject* obj);


static void g_cclosure_user_marshal_VOID__OBJECT_OBJECT_STRING_UINT64_UINT64 (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);
static void g_cclosure_user_marshal_VOID__OBJECT_POINTER (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);

#line 84 "rygel-media-export-metadata-extractor.vala"
static void _rygel_media_export_metadata_extractor_on_done_gupnp_dlna_discoverer_done (GUPnPDLNADiscoverer* _sender, GUPnPDLNAInformation* dlna, GError* err, gpointer self) {
#line 95 "rygel-media-export-metadata-extractor.c"
	rygel_media_export_metadata_extractor_on_done (self, dlna, err);
}


#line 59 "rygel-media-export-metadata-extractor.vala"
RygelMediaExportMetadataExtractor* rygel_media_export_metadata_extractor_construct (GType object_type) {
#line 102 "rygel-media-export-metadata-extractor.c"
	GError * _inner_error_;
	RygelMediaExportMetadataExtractor * self;
	GeeHashMap* _tmp0_;
	RygelMetaConfig* config;
	_inner_error_ = NULL;
#line 59 "rygel-media-export-metadata-extractor.vala"
	self = (RygelMediaExportMetadataExtractor*) g_object_new (object_type, NULL);
#line 60 "rygel-media-export-metadata-extractor.vala"
	self->priv->file_hash = (_tmp0_ = gee_hash_map_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, G_TYPE_FILE, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL, NULL, NULL), _g_object_unref0 (self->priv->file_hash), _tmp0_);
#line 62 "rygel-media-export-metadata-extractor.vala"
	config = rygel_meta_config_get_default ();
#line 114 "rygel-media-export-metadata-extractor.c"
	{
		gboolean _tmp1_;
#line 64 "rygel-media-export-metadata-extractor.vala"
		_tmp1_ = rygel_configuration_get_bool ((RygelConfiguration*) config, "MediaExport", "extract-metadata", &_inner_error_);
#line 119 "rygel-media-export-metadata-extractor.c"
		if (_inner_error_ != NULL) {
			goto __catch15_g_error;
		}
#line 64 "rygel-media-export-metadata-extractor.vala"
		self->priv->extract_metadata = _tmp1_;
#line 125 "rygel-media-export-metadata-extractor.c"
	}
	goto __finally15;
	__catch15_g_error:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
#line 67 "rygel-media-export-metadata-extractor.vala"
			self->priv->extract_metadata = TRUE;
#line 136 "rygel-media-export-metadata-extractor.c"
			_g_error_free0 (_error_);
		}
	}
	__finally15:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (config);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
#line 70 "rygel-media-export-metadata-extractor.vala"
	if (self->priv->extract_metadata) {
#line 149 "rygel-media-export-metadata-extractor.c"
		GstClockTime gst_timeout;
		GUPnPDLNADiscoverer* _tmp2_;
#line 71 "rygel-media-export-metadata-extractor.vala"
		gst_timeout = (GstClockTime) (self->priv->timeout * GST_SECOND);
#line 72 "rygel-media-export-metadata-extractor.vala"
		self->priv->discoverer = (_tmp2_ = gupnp_dlna_discoverer_new (gst_timeout), _g_object_unref0 (self->priv->discoverer), _tmp2_);
#line 73 "rygel-media-export-metadata-extractor.vala"
		g_signal_connect_object (self->priv->discoverer, "done", (GCallback) _rygel_media_export_metadata_extractor_on_done_gupnp_dlna_discoverer_done, self, 0);
#line 74 "rygel-media-export-metadata-extractor.vala"
		gupnp_dlna_discoverer_start (self->priv->discoverer);
#line 160 "rygel-media-export-metadata-extractor.c"
	}
	_g_object_unref0 (config);
	return self;
}


#line 59 "rygel-media-export-metadata-extractor.vala"
RygelMediaExportMetadataExtractor* rygel_media_export_metadata_extractor_new (void) {
#line 59 "rygel-media-export-metadata-extractor.vala"
	return rygel_media_export_metadata_extractor_construct (RYGEL_MEDIA_EXPORT_TYPE_METADATA_EXTRACTOR);
#line 171 "rygel-media-export-metadata-extractor.c"
}


#line 84 "rygel-media-export-metadata-extractor.vala"
static void rygel_media_export_metadata_extractor_on_done (RygelMediaExportMetadataExtractor* self, GUPnPDLNAInformation* dlna, GError* err) {
#line 177 "rygel-media-export-metadata-extractor.c"
	GError * _inner_error_;
	GFile* file;
#line 84 "rygel-media-export-metadata-extractor.vala"
	g_return_if_fail (self != NULL);
#line 84 "rygel-media-export-metadata-extractor.vala"
	g_return_if_fail (dlna != NULL);
#line 184 "rygel-media-export-metadata-extractor.c"
	_inner_error_ = NULL;
#line 86 "rygel-media-export-metadata-extractor.vala"
	g_assert (gee_abstract_map_has_key ((GeeAbstractMap*) self->priv->file_hash, gupnp_dlna_information_get_info (dlna)->uri));
#line 88 "rygel-media-export-metadata-extractor.vala"
	file = (GFile*) gee_abstract_map_get ((GeeAbstractMap*) self->priv->file_hash, gupnp_dlna_information_get_info (dlna)->uri);
#line 90 "rygel-media-export-metadata-extractor.vala"
	gee_abstract_map_unset ((GeeAbstractMap*) self->priv->file_hash, gupnp_dlna_information_get_info (dlna)->uri, NULL);
#line 92 "rygel-media-export-metadata-extractor.vala"
	if ((gupnp_dlna_information_get_info (dlna)->result & GST_DISCOVERER_TIMEOUT) != 0) {
#line 194 "rygel-media-export-metadata-extractor.c"
		GError* _tmp0_;
#line 93 "rygel-media-export-metadata-extractor.vala"
		g_signal_emit_by_name (self, "error", file, _tmp0_ = g_error_new_literal (G_IO_CHANNEL_ERROR, G_IO_CHANNEL_ERROR_FAILED, "Pipeline stuck while" "reading file info"));
#line 198 "rygel-media-export-metadata-extractor.c"
		_g_error_free0 (_tmp0_);
		_g_object_unref0 (file);
#line 96 "rygel-media-export-metadata-extractor.vala"
		return;
#line 203 "rygel-media-export-metadata-extractor.c"
	} else {
#line 97 "rygel-media-export-metadata-extractor.vala"
		if ((gupnp_dlna_information_get_info (dlna)->result & GST_DISCOVERER_ERROR) != 0) {
#line 98 "rygel-media-export-metadata-extractor.vala"
			g_signal_emit_by_name (self, "error", file, err);
#line 209 "rygel-media-export-metadata-extractor.c"
			_g_object_unref0 (file);
#line 99 "rygel-media-export-metadata-extractor.vala"
			return;
#line 213 "rygel-media-export-metadata-extractor.c"
		}
	}
	{
		guint64 size = 0ULL;
		guint64 mtime = 0ULL;
		char* mime;
		char* _tmp2_;
		char* _tmp1_ = NULL;
		mime = NULL;
#line 106 "rygel-media-export-metadata-extractor.vala"
		rygel_media_export_metadata_extractor_extract_file_info (self, file, &_tmp1_, &size, &mtime, &_inner_error_);
#line 106 "rygel-media-export-metadata-extractor.vala"
		mime = (_tmp2_ = _tmp1_, _g_free0 (mime), _tmp2_);
#line 227 "rygel-media-export-metadata-extractor.c"
		if (_inner_error_ != NULL) {
			_g_free0 (mime);
			goto __catch16_g_error;
		}
#line 107 "rygel-media-export-metadata-extractor.vala"
		g_signal_emit_by_name (self, "extraction-done", file, dlna, mime, size, mtime);
#line 234 "rygel-media-export-metadata-extractor.c"
		_g_free0 (mime);
	}
	goto __finally16;
	__catch16_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
#line 109 "rygel-media-export-metadata-extractor.vala"
			g_debug (_ ("Failed to extract metadata from %s: %s"), gupnp_dlna_information_get_info (dlna)->uri, e->message);
#line 246 "rygel-media-export-metadata-extractor.c"
			_g_error_free0 (e);
		}
	}
	__finally16:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (file);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_g_object_unref0 (file);
}


#line 115 "rygel-media-export-metadata-extractor.vala"
void rygel_media_export_metadata_extractor_extract (RygelMediaExportMetadataExtractor* self, GFile* file) {
#line 263 "rygel-media-export-metadata-extractor.c"
	GError * _inner_error_;
#line 115 "rygel-media-export-metadata-extractor.vala"
	g_return_if_fail (self != NULL);
#line 115 "rygel-media-export-metadata-extractor.vala"
	g_return_if_fail (file != NULL);
#line 269 "rygel-media-export-metadata-extractor.c"
	_inner_error_ = NULL;
#line 116 "rygel-media-export-metadata-extractor.vala"
	if (self->priv->extract_metadata) {
#line 273 "rygel-media-export-metadata-extractor.c"
		char* uri;
#line 117 "rygel-media-export-metadata-extractor.vala"
		uri = g_file_get_uri (file);
#line 118 "rygel-media-export-metadata-extractor.vala"
		gee_abstract_map_set ((GeeAbstractMap*) self->priv->file_hash, uri, file);
#line 119 "rygel-media-export-metadata-extractor.vala"
		gupnp_dlna_discoverer_discover_uri (self->priv->discoverer, uri);
#line 281 "rygel-media-export-metadata-extractor.c"
		_g_free0 (uri);
	} else {
		{
			char* mime;
			guint64 size = 0ULL;
			guint64 mtime = 0ULL;
			char* _tmp1_;
			char* _tmp0_ = NULL;
			mime = NULL;
#line 126 "rygel-media-export-metadata-extractor.vala"
			rygel_media_export_metadata_extractor_extract_file_info (self, file, &_tmp0_, &size, &mtime, &_inner_error_);
#line 126 "rygel-media-export-metadata-extractor.vala"
			mime = (_tmp1_ = _tmp0_, _g_free0 (mime), _tmp1_);
#line 295 "rygel-media-export-metadata-extractor.c"
			if (_inner_error_ != NULL) {
				_g_free0 (mime);
				goto __catch17_g_error;
			}
#line 131 "rygel-media-export-metadata-extractor.vala"
			g_signal_emit_by_name (self, "extraction-done", file, NULL, mime, size, mtime);
#line 302 "rygel-media-export-metadata-extractor.c"
			_g_free0 (mime);
		}
		goto __finally17;
		__catch17_g_error:
		{
			GError * _error_;
			_error_ = _inner_error_;
			_inner_error_ = NULL;
			{
#line 137 "rygel-media-export-metadata-extractor.vala"
				g_signal_emit_by_name (self, "error", file, _error_);
#line 314 "rygel-media-export-metadata-extractor.c"
				_g_error_free0 (_error_);
			}
		}
		__finally17:
		if (_inner_error_ != NULL) {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
}


static gpointer _g_error_copy0 (gpointer self) {
	return self ? g_error_copy (self) : NULL;
}


#line 142 "rygel-media-export-metadata-extractor.vala"
static void rygel_media_export_metadata_extractor_extract_file_info (RygelMediaExportMetadataExtractor* self, GFile* file, char** mime, guint64* size, guint64* mtime, GError** error) {
#line 335 "rygel-media-export-metadata-extractor.c"
	GError * _inner_error_;
	GFileInfo* file_info;
	char* content_type;
	char* _tmp3_;
#line 142 "rygel-media-export-metadata-extractor.vala"
	g_return_if_fail (self != NULL);
#line 142 "rygel-media-export-metadata-extractor.vala"
	g_return_if_fail (file != NULL);
#line 344 "rygel-media-export-metadata-extractor.c"
	if (mime != NULL) {
		*mime = NULL;
	}
	_inner_error_ = NULL;
	file_info = NULL;
	{
		GFileInfo* _tmp0_;
		GFileInfo* _tmp1_;
#line 149 "rygel-media-export-metadata-extractor.vala"
		_tmp0_ = g_file_query_info (file, G_FILE_ATTRIBUTE_STANDARD_CONTENT_TYPE "," G_FILE_ATTRIBUTE_STANDARD_SIZE "," G_FILE_ATTRIBUTE_TIME_MODIFIED, G_FILE_QUERY_INFO_NONE, NULL, &_inner_error_);
#line 355 "rygel-media-export-metadata-extractor.c"
		if (_inner_error_ != NULL) {
			goto __catch18_g_error;
		}
#line 149 "rygel-media-export-metadata-extractor.vala"
		file_info = (_tmp1_ = _tmp0_, _g_object_unref0 (file_info), _tmp1_);
#line 361 "rygel-media-export-metadata-extractor.c"
	}
	goto __finally18;
	__catch18_g_error:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp2_;
#line 156 "rygel-media-export-metadata-extractor.vala"
			g_warning (_ ("Failed to query content type for '%s'"), _tmp2_ = g_file_get_uri (file));
#line 373 "rygel-media-export-metadata-extractor.c"
			_g_free0 (_tmp2_);
#line 160 "rygel-media-export-metadata-extractor.vala"
			g_signal_emit_by_name (self, "error", file, _error_);
#line 377 "rygel-media-export-metadata-extractor.c"
			_inner_error_ = _g_error_copy0 (_error_);
			{
				_g_error_free0 (_error_);
				_g_object_unref0 (file_info);
				goto __finally18;
			}
			_g_error_free0 (_error_);
		}
	}
	__finally18:
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_g_object_unref0 (file_info);
		return;
	}
#line 165 "rygel-media-export-metadata-extractor.vala"
	content_type = g_strdup (g_file_info_get_content_type (file_info));
#line 166 "rygel-media-export-metadata-extractor.vala"
	*mime = (_tmp3_ = g_content_type_get_mime_type (content_type), _g_free0 (*mime), _tmp3_);
#line 167 "rygel-media-export-metadata-extractor.vala"
	*size = (guint64) g_file_info_get_size (file_info);
#line 168 "rygel-media-export-metadata-extractor.vala"
	*mtime = g_file_info_get_attribute_uint64 (file_info, G_FILE_ATTRIBUTE_TIME_MODIFIED);
#line 401 "rygel-media-export-metadata-extractor.c"
	_g_free0 (content_type);
	_g_object_unref0 (file_info);
}


static void rygel_media_export_metadata_extractor_class_init (RygelMediaExportMetadataExtractorClass * klass) {
	rygel_media_export_metadata_extractor_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelMediaExportMetadataExtractorPrivate));
	G_OBJECT_CLASS (klass)->finalize = rygel_media_export_metadata_extractor_finalize;
	g_signal_new ("extraction_done", RYGEL_MEDIA_EXPORT_TYPE_METADATA_EXTRACTOR, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__OBJECT_OBJECT_STRING_UINT64_UINT64, G_TYPE_NONE, 5, G_TYPE_FILE, GUPNP_TYPE_DLNA_INFORMATION, G_TYPE_STRING, G_TYPE_UINT64, G_TYPE_UINT64);
	g_signal_new ("error", RYGEL_MEDIA_EXPORT_TYPE_METADATA_EXTRACTOR, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__OBJECT_POINTER, G_TYPE_NONE, 2, G_TYPE_FILE, G_TYPE_POINTER);
}


static void rygel_media_export_metadata_extractor_instance_init (RygelMediaExportMetadataExtractor * self) {
	self->priv = RYGEL_MEDIA_EXPORT_METADATA_EXTRACTOR_GET_PRIVATE (self);
	self->priv->timeout = (guint64) 10;
}


static void rygel_media_export_metadata_extractor_finalize (GObject* obj) {
	RygelMediaExportMetadataExtractor * self;
	self = RYGEL_MEDIA_EXPORT_METADATA_EXTRACTOR (obj);
	{
#line 79 "rygel-media-export-metadata-extractor.vala"
		if (self->priv->extract_metadata) {
#line 80 "rygel-media-export-metadata-extractor.vala"
			gupnp_dlna_discoverer_stop (self->priv->discoverer);
#line 430 "rygel-media-export-metadata-extractor.c"
		}
	}
	_g_object_unref0 (self->priv->discoverer);
	_g_object_unref0 (self->priv->file_hash);
	G_OBJECT_CLASS (rygel_media_export_metadata_extractor_parent_class)->finalize (obj);
}


GType rygel_media_export_metadata_extractor_get_type (void) {
	static volatile gsize rygel_media_export_metadata_extractor_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_media_export_metadata_extractor_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediaExportMetadataExtractorClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_media_export_metadata_extractor_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediaExportMetadataExtractor), 0, (GInstanceInitFunc) rygel_media_export_metadata_extractor_instance_init, NULL };
		GType rygel_media_export_metadata_extractor_type_id;
		rygel_media_export_metadata_extractor_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelMediaExportMetadataExtractor", &g_define_type_info, 0);
		g_once_init_leave (&rygel_media_export_metadata_extractor_type_id__volatile, rygel_media_export_metadata_extractor_type_id);
	}
	return rygel_media_export_metadata_extractor_type_id__volatile;
}



static void g_cclosure_user_marshal_VOID__OBJECT_OBJECT_STRING_UINT64_UINT64 (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data) {
	typedef void (*GMarshalFunc_VOID__OBJECT_OBJECT_STRING_UINT64_UINT64) (gpointer data1, gpointer arg_1, gpointer arg_2, const char* arg_3, guint64 arg_4, guint64 arg_5, gpointer data2);
	register GMarshalFunc_VOID__OBJECT_OBJECT_STRING_UINT64_UINT64 callback;
	register GCClosure * cc;
	register gpointer data1, data2;
	cc = (GCClosure *) closure;
	g_return_if_fail (n_param_values == 6);
	if (G_CCLOSURE_SWAP_DATA (closure)) {
		data1 = closure->data;
		data2 = param_values->data[0].v_pointer;
	} else {
		data1 = param_values->data[0].v_pointer;
		data2 = closure->data;
	}
	callback = (GMarshalFunc_VOID__OBJECT_OBJECT_STRING_UINT64_UINT64) (marshal_data ? marshal_data : cc->callback);
	callback (data1, g_value_get_object (param_values + 1), g_value_get_object (param_values + 2), g_value_get_string (param_values + 3), g_value_get_uint64 (param_values + 4), g_value_get_uint64 (param_values + 5), data2);
}


static void g_cclosure_user_marshal_VOID__OBJECT_POINTER (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data) {
	typedef void (*GMarshalFunc_VOID__OBJECT_POINTER) (gpointer data1, gpointer arg_1, gpointer arg_2, gpointer data2);
	register GMarshalFunc_VOID__OBJECT_POINTER callback;
	register GCClosure * cc;
	register gpointer data1, data2;
	cc = (GCClosure *) closure;
	g_return_if_fail (n_param_values == 3);
	if (G_CCLOSURE_SWAP_DATA (closure)) {
		data1 = closure->data;
		data2 = param_values->data[0].v_pointer;
	} else {
		data1 = param_values->data[0].v_pointer;
		data2 = closure->data;
	}
	callback = (GMarshalFunc_VOID__OBJECT_POINTER) (marshal_data ? marshal_data : cc->callback);
	callback (data1, g_value_get_object (param_values + 1), g_value_get_pointer (param_values + 2), data2);
}



