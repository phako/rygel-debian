/*
 * Copyright (C) 2008 Zeeshan Ali <zeenix@gmail.com>.
 *
 * Author: Zeeshan Ali <zeenix@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 */

#include <glib.h>
#include <glib-object.h>
#include <gst/gst.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>


#define GST_TYPE_STREAM_TYPE (gst_stream_type_get_type ())

#define RYGEL_TYPE_METADATA_EXTRACTOR (rygel_metadata_extractor_get_type ())
#define RYGEL_METADATA_EXTRACTOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_METADATA_EXTRACTOR, RygelMetadataExtractor))
#define RYGEL_METADATA_EXTRACTOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_METADATA_EXTRACTOR, RygelMetadataExtractorClass))
#define RYGEL_IS_METADATA_EXTRACTOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_METADATA_EXTRACTOR))
#define RYGEL_IS_METADATA_EXTRACTOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_METADATA_EXTRACTOR))
#define RYGEL_METADATA_EXTRACTOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_METADATA_EXTRACTOR, RygelMetadataExtractorClass))

typedef struct _RygelMetadataExtractor RygelMetadataExtractor;
typedef struct _RygelMetadataExtractorClass RygelMetadataExtractorClass;
typedef struct _RygelMetadataExtractorPrivate RygelMetadataExtractorPrivate;
#define _gst_object_unref0(var) ((var == NULL) ? NULL : (var = (gst_object_unref (var), NULL)))
#define _gst_tag_list_free0(var) ((var == NULL) ? NULL : (var = (gst_tag_list_free (var), NULL)))
#define _g_queue_free0(var) ((var == NULL) ? NULL : (var = (g_queue_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _gst_caps_unref0(var) ((var == NULL) ? NULL : (var = (gst_caps_unref (var), NULL)))

typedef enum  {
	GST_STREAM_TYPE_UNKNOWN = 0,
	GST_STREAM_TYPE_AUDIO = 1,
	GST_STREAM_TYPE_VIDEO = 2,
	GST_STREAM_TYPE_TEXT = 3,
	GST_STREAM_TYPE_SUBPICTURE = 4,
	GST_STREAM_TYPE_ELEMENT = 5
} GstStreamType;

struct _RygelMetadataExtractor {
	GObject parent_instance;
	RygelMetadataExtractorPrivate * priv;
};

struct _RygelMetadataExtractorClass {
	GObjectClass parent_class;
};

struct _RygelMetadataExtractorPrivate {
	GstElement* playbin;
	GstTagList* tag_list;
	GQueue* file_queue;
	guint timeout_id;
};


static gpointer rygel_metadata_extractor_parent_class = NULL;

GType gst_stream_type_get_type (void);
GType rygel_metadata_extractor_get_type (void);
#define RYGEL_METADATA_EXTRACTOR_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_METADATA_EXTRACTOR, RygelMetadataExtractorPrivate))
enum  {
	RYGEL_METADATA_EXTRACTOR_DUMMY_PROPERTY
};
#define RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_SIZE "rygel-size"
#define RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_DURATION "rygel-duration"
#define RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_MIME "rygel-mime"
#define RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_CHANNELS "rygel-channels"
#define RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_RATE "rygel-rate"
#define RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_WIDTH "rygel-width"
#define RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_HEIGHT "rygel-height"
#define RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_DEPTH "rygel-depth"
#define RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_MTIME "rygel-mtime"
static void _gst_tag_merge_use_first_gst_tag_merge_func (const GValue* dest, const GValue* src);
static void rygel_metadata_extractor_register_custom_tag (const char* tag, GType type);
static inline void _dynamic_set_video_sink6 (GstElement* obj, GstElement* value);
static inline void _dynamic_set_audio_sink7 (GstElement* obj, GstElement* value);
static void rygel_metadata_extractor_tag_cb (RygelMetadataExtractor* self, GstBus* bus, GstMessage* message);
static void _rygel_metadata_extractor_tag_cb_gst_bus_message (GstBus* _sender, GstMessage* message, gpointer self);
static void rygel_metadata_extractor_state_changed_cb (RygelMetadataExtractor* self, GstBus* bus, GstMessage* message);
static void _rygel_metadata_extractor_state_changed_cb_gst_bus_message (GstBus* _sender, GstMessage* message, gpointer self);
static void rygel_metadata_extractor_error_cb (RygelMetadataExtractor* self, GstBus* bus, GstMessage* message);
static void _rygel_metadata_extractor_error_cb_gst_bus_message (GstBus* _sender, GstMessage* message, gpointer self);
static void rygel_metadata_extractor_renew_playbin (RygelMetadataExtractor* self);
RygelMetadataExtractor* rygel_metadata_extractor_new (void);
RygelMetadataExtractor* rygel_metadata_extractor_construct (GType object_type);
static void rygel_metadata_extractor_extract_next (RygelMetadataExtractor* self);
void rygel_metadata_extractor_extract (RygelMetadataExtractor* self, GFile* file);
static gboolean rygel_metadata_extractor_on_harvesting_timeout (RygelMetadataExtractor* self);
static void rygel_metadata_extractor_extract_mime_and_size (RygelMetadataExtractor* self, GError** error);
static inline void _dynamic_set_uri8 (GstElement* obj, char* value);
static gboolean _rygel_metadata_extractor_on_harvesting_timeout_gsource_func (gpointer self);
static void rygel_metadata_extractor_extract_duration (RygelMetadataExtractor* self);
static void rygel_metadata_extractor_extract_stream_info (RygelMetadataExtractor* self);
static void rygel_metadata_extractor_extract_av_info (RygelMetadataExtractor* self, GstPad* pad, GstStreamType type);
static inline GstElement* _dynamic_get_video_sink9 (GstElement* obj);
static inline GstElement* _dynamic_get_audio_sink10 (GstElement* obj);
static void rygel_metadata_extractor_extract_audio_info (RygelMetadataExtractor* self, const GstStructure* structure);
static void rygel_metadata_extractor_extract_video_info (RygelMetadataExtractor* self, const GstStructure* structure);
static void rygel_metadata_extractor_extract_int_value (RygelMetadataExtractor* self, const GstStructure* structure, const char* key, const char* tag);
static void rygel_metadata_extractor_finalize (GObject* obj);


static void g_cclosure_user_marshal_VOID__OBJECT_POINTER (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);


GType gst_stream_type_get_type (void) {
	static GType gst_stream_type_type_id = 0;
	if (G_UNLIKELY (gst_stream_type_type_id == 0)) {
		static const GEnumValue values[] = {{GST_STREAM_TYPE_UNKNOWN, "GST_STREAM_TYPE_UNKNOWN", "unknown"}, {GST_STREAM_TYPE_AUDIO, "GST_STREAM_TYPE_AUDIO", "audio"}, {GST_STREAM_TYPE_VIDEO, "GST_STREAM_TYPE_VIDEO", "video"}, {GST_STREAM_TYPE_TEXT, "GST_STREAM_TYPE_TEXT", "text"}, {GST_STREAM_TYPE_SUBPICTURE, "GST_STREAM_TYPE_SUBPICTURE", "subpicture"}, {GST_STREAM_TYPE_ELEMENT, "GST_STREAM_TYPE_ELEMENT", "element"}, {0, NULL, NULL}};
		gst_stream_type_type_id = g_enum_register_static ("GstStreamType", values);
	}
	return gst_stream_type_type_id;
}


static void _gst_tag_merge_use_first_gst_tag_merge_func (const GValue* dest, const GValue* src) {
	gst_tag_merge_use_first (dest, src);
}


static void rygel_metadata_extractor_register_custom_tag (const char* tag, GType type) {
	g_return_if_fail (tag != NULL);
	gst_tag_register (tag, GST_TAG_FLAG_META, type, tag, "", _gst_tag_merge_use_first_gst_tag_merge_func);
}


static inline void _dynamic_set_video_sink6 (GstElement* obj, GstElement* value) {
	g_object_set (obj, "video-sink", value, NULL);
}


static inline void _dynamic_set_audio_sink7 (GstElement* obj, GstElement* value) {
	g_object_set (obj, "audio-sink", value, NULL);
}


static void _rygel_metadata_extractor_tag_cb_gst_bus_message (GstBus* _sender, GstMessage* message, gpointer self) {
	rygel_metadata_extractor_tag_cb (self, _sender, message);
}


static void _rygel_metadata_extractor_state_changed_cb_gst_bus_message (GstBus* _sender, GstMessage* message, gpointer self) {
	rygel_metadata_extractor_state_changed_cb (self, _sender, message);
}


static void _rygel_metadata_extractor_error_cb_gst_bus_message (GstBus* _sender, GstMessage* message, gpointer self) {
	rygel_metadata_extractor_error_cb (self, _sender, message);
}


static void rygel_metadata_extractor_renew_playbin (RygelMetadataExtractor* self) {
	GstElement* _tmp0_;
	GstElement* sink;
	GstElement* _tmp2_;
	GstBus* bus;
	g_return_if_fail (self != NULL);
	self->priv->playbin = (_tmp0_ = gst_element_factory_make ("playbin2", NULL), _gst_object_unref0 (self->priv->playbin), _tmp0_);
	if (self->priv->playbin == NULL) {
		GstElement* _tmp1_;
		self->priv->playbin = (_tmp1_ = gst_element_factory_make ("playbin", NULL), _gst_object_unref0 (self->priv->playbin), _tmp1_);
	}
	sink = gst_element_factory_make ("fakesink", NULL);
	gst_object_ref ((GstObject*) sink);
	_dynamic_set_video_sink6 (self->priv->playbin, sink);
	sink = (_tmp2_ = gst_element_factory_make ("fakesink", NULL), _gst_object_unref0 (sink), _tmp2_);
	gst_object_ref ((GstObject*) sink);
	_dynamic_set_audio_sink7 (self->priv->playbin, sink);
	bus = gst_element_get_bus (self->priv->playbin);
	gst_bus_add_signal_watch (bus);
	g_signal_connect_object (bus, "message::tag", (GCallback) _rygel_metadata_extractor_tag_cb_gst_bus_message, self, 0);
	g_signal_connect_object (bus, "message::state-changed", (GCallback) _rygel_metadata_extractor_state_changed_cb_gst_bus_message, self, 0);
	g_signal_connect_object (bus, "message::error", (GCallback) _rygel_metadata_extractor_error_cb_gst_bus_message, self, 0);
	_gst_object_unref0 (sink);
	_gst_object_unref0 (bus);
}


RygelMetadataExtractor* rygel_metadata_extractor_construct (GType object_type) {
	RygelMetadataExtractor * self;
	GQueue* _tmp0_;
	GstTagList* _tmp1_;
	self = (RygelMetadataExtractor*) g_object_new (object_type, NULL);
	rygel_metadata_extractor_register_custom_tag (RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_SIZE, G_TYPE_INT64);
	rygel_metadata_extractor_register_custom_tag (RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_DURATION, G_TYPE_INT64);
	rygel_metadata_extractor_register_custom_tag (RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_MIME, G_TYPE_STRING);
	rygel_metadata_extractor_register_custom_tag (RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_CHANNELS, G_TYPE_INT);
	rygel_metadata_extractor_register_custom_tag (RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_RATE, G_TYPE_INT);
	rygel_metadata_extractor_register_custom_tag (RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_WIDTH, G_TYPE_INT);
	rygel_metadata_extractor_register_custom_tag (RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_HEIGHT, G_TYPE_INT);
	rygel_metadata_extractor_register_custom_tag (RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_DEPTH, G_TYPE_INT);
	rygel_metadata_extractor_register_custom_tag (RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_MTIME, G_TYPE_UINT64);
	self->priv->file_queue = (_tmp0_ = g_queue_new (), _g_queue_free0 (self->priv->file_queue), _tmp0_);
	self->priv->tag_list = (_tmp1_ = gst_tag_list_new (), _gst_tag_list_free0 (self->priv->tag_list), _tmp1_);
	return self;
}


RygelMetadataExtractor* rygel_metadata_extractor_new (void) {
	return rygel_metadata_extractor_construct (RYGEL_TYPE_METADATA_EXTRACTOR);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void rygel_metadata_extractor_extract (RygelMetadataExtractor* self, GFile* file) {
	gboolean trigger_run;
	g_return_if_fail (self != NULL);
	g_return_if_fail (file != NULL);
	trigger_run = g_queue_get_length (self->priv->file_queue) == 0;
	g_queue_push_tail (self->priv->file_queue, _g_object_ref0 (file));
	if (trigger_run) {
		rygel_metadata_extractor_extract_next (self);
	}
}


static gboolean rygel_metadata_extractor_on_harvesting_timeout (RygelMetadataExtractor* self) {
	gboolean result;
	char* _tmp0_;
	GError* _tmp1_;
	GFile* _tmp2_;
	g_return_val_if_fail (self != NULL, FALSE);
	g_warning ("rygel-metadata-extractor.vala:127: Metadata extractor timed out on %s, restarting", _tmp0_ = g_file_get_uri ((GFile*) g_queue_peek_head (self->priv->file_queue)));
	_g_free0 (_tmp0_);
	gst_element_set_state (self->priv->playbin, GST_STATE_NULL);
	g_signal_emit_by_name (self, "error", (GFile*) g_queue_peek_head (self->priv->file_queue), _tmp1_ = g_error_new_literal (G_IO_CHANNEL_ERROR, G_IO_CHANNEL_ERROR_FAILED, "Pipeline stuck while reading file info"));
	_g_error_free0 (_tmp1_);
	_tmp2_ = (GFile*) g_queue_pop_head (self->priv->file_queue);
	_g_object_unref0 (_tmp2_);
	rygel_metadata_extractor_extract_next (self);
	result = FALSE;
	return result;
}


static inline void _dynamic_set_uri8 (GstElement* obj, char* value) {
	g_object_set (obj, "uri", value, NULL);
}


static gboolean _rygel_metadata_extractor_on_harvesting_timeout_gsource_func (gpointer self) {
	return rygel_metadata_extractor_on_harvesting_timeout (self);
}


static void rygel_metadata_extractor_extract_next (RygelMetadataExtractor* self) {
	GError * _inner_error_;
	g_return_if_fail (self != NULL);
	_inner_error_ = NULL;
	if (self->priv->timeout_id != 0) {
		g_source_remove (self->priv->timeout_id);
	}
	if (g_queue_get_length (self->priv->file_queue) > 0) {
		{
			GFile* item;
			char* _tmp0_;
			char* _tmp1_;
			item = _g_object_ref0 ((GFile*) g_queue_peek_head (self->priv->file_queue));
			g_debug ("rygel-metadata-extractor.vala:145: Scheduling file %s for metadata extraction", _tmp0_ = g_file_get_uri (item));
			_g_free0 (_tmp0_);
			rygel_metadata_extractor_extract_mime_and_size (self, &_inner_error_);
			if (_inner_error_ != NULL) {
				_g_object_unref0 (item);
				goto __catch39_g_error;
				goto __finally39;
			}
			rygel_metadata_extractor_renew_playbin (self);
			_dynamic_set_uri8 (self->priv->playbin, _tmp1_ = g_file_get_uri (item));
			_g_free0 (_tmp1_);
			self->priv->timeout_id = g_timeout_add_seconds_full (G_PRIORITY_DEFAULT, (guint) 5, _rygel_metadata_extractor_on_harvesting_timeout_gsource_func, g_object_ref (self), g_object_unref);
			gst_element_set_state (self->priv->playbin, GST_STATE_PAUSED);
			_g_object_unref0 (item);
		}
		goto __finally39;
		__catch39_g_error:
		{
			GError * _error_;
			_error_ = _inner_error_;
			_inner_error_ = NULL;
			{
				rygel_metadata_extractor_extract_next (self);
				_g_error_free0 (_error_);
			}
		}
		__finally39:
		if (_inner_error_ != NULL) {
			g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
			g_clear_error (&_inner_error_);
			return;
		}
	}
}


static void rygel_metadata_extractor_tag_cb (RygelMetadataExtractor* self, GstBus* bus, GstMessage* message) {
	GstTagList* new_tag_list;
	GstTagList* _tmp1_;
	GstTagList* _tmp0_;
	GstTagList* _tmp2_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (bus != NULL);
	g_return_if_fail (message != NULL);
	new_tag_list = NULL;
	_tmp0_ = NULL;
	gst_message_parse_tag (message, &_tmp0_);
	new_tag_list = (_tmp1_ = _tmp0_, _gst_tag_list_free0 (new_tag_list), _tmp1_);
	self->priv->tag_list = (_tmp2_ = gst_tag_list_merge (new_tag_list, self->priv->tag_list, GST_TAG_MERGE_REPLACE), _gst_tag_list_free0 (self->priv->tag_list), _tmp2_);
	_gst_tag_list_free0 (new_tag_list);
}


static void rygel_metadata_extractor_state_changed_cb (RygelMetadataExtractor* self, GstBus* bus, GstMessage* message) {
	GstState new_state;
	GstState old_state;
	gboolean _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (bus != NULL);
	g_return_if_fail (message != NULL);
	if (message->src != GST_OBJECT (self->priv->playbin)) {
		return;
	}
	new_state = 0;
	old_state = 0;
	gst_message_parse_state_changed (message, &old_state, &new_state, NULL);
	_tmp0_ = FALSE;
	if (new_state == GST_STATE_PAUSED) {
		_tmp0_ = old_state == GST_STATE_READY;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		GstTagList* _tmp1_;
		GFile* _tmp2_;
		rygel_metadata_extractor_extract_duration (self);
		rygel_metadata_extractor_extract_stream_info (self);
		g_signal_emit_by_name (self, "extraction-done", (GFile*) g_queue_peek_head (self->priv->file_queue), self->priv->tag_list);
		gst_element_set_state (self->priv->playbin, GST_STATE_NULL);
		self->priv->tag_list = (_tmp1_ = gst_tag_list_new (), _gst_tag_list_free0 (self->priv->tag_list), _tmp1_);
		_tmp2_ = (GFile*) g_queue_pop_head (self->priv->file_queue);
		_g_object_unref0 (_tmp2_);
		rygel_metadata_extractor_extract_next (self);
	}
}


static void rygel_metadata_extractor_error_cb (RygelMetadataExtractor* self, GstBus* bus, GstMessage* message) {
	GError* _error_;
	char* debug;
	char* _tmp3_;
	char* _tmp2_;
	GError* _tmp1_;
	GError* _tmp0_;
	GstTagList* _tmp5_;
	GFile* _tmp6_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (bus != NULL);
	g_return_if_fail (message != NULL);
	g_return_if_fail (g_queue_get_length (self->priv->file_queue) != 0);
	_error_ = NULL;
	debug = NULL;
	_tmp2_ = NULL;
	_tmp0_ = NULL;
	(gst_message_parse_error (message, &_tmp0_, &_tmp2_), _error_ = (_tmp1_ = _tmp0_, _g_error_free0 (_error_), _tmp1_));
	debug = (_tmp3_ = _tmp2_, _g_free0 (debug), _tmp3_);
	if (_error_ != NULL) {
		char* _tmp4_;
		debug = (_tmp4_ = g_strdup (_error_->message), _g_free0 (debug), _tmp4_);
	}
	g_signal_emit_by_name (self, "error", (GFile*) g_queue_peek_head (self->priv->file_queue), _error_);
	gst_element_set_state (self->priv->playbin, GST_STATE_NULL);
	self->priv->tag_list = (_tmp5_ = gst_tag_list_new (), _gst_tag_list_free0 (self->priv->tag_list), _tmp5_);
	_tmp6_ = (GFile*) g_queue_pop_head (self->priv->file_queue);
	_g_object_unref0 (_tmp6_);
	rygel_metadata_extractor_extract_next (self);
	_g_error_free0 (_error_);
	_g_free0 (debug);
}


static gpointer _g_error_copy0 (gpointer self) {
	return self ? g_error_copy (self) : NULL;
}


static void rygel_metadata_extractor_extract_mime_and_size (RygelMetadataExtractor* self, GError** error) {
	GError * _inner_error_;
	GFile* file;
	GFileInfo* file_info;
	const char* content_type;
	const char* mime;
	gint64 size;
	guint64 mtime;
	g_return_if_fail (self != NULL);
	_inner_error_ = NULL;
	file = _g_object_ref0 ((GFile*) g_queue_peek_head (self->priv->file_queue));
	file_info = NULL;
	{
		GFileInfo* _tmp0_;
		GFileInfo* _tmp1_;
		_tmp0_ = g_file_query_info (file, G_FILE_ATTRIBUTE_STANDARD_CONTENT_TYPE "," G_FILE_ATTRIBUTE_STANDARD_SIZE "," G_FILE_ATTRIBUTE_TIME_MODIFIED, G_FILE_QUERY_INFO_NONE, NULL, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch40_g_error;
			goto __finally40;
		}
		file_info = (_tmp1_ = _tmp0_, _g_object_unref0 (file_info), _tmp1_);
	}
	goto __finally40;
	__catch40_g_error:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp2_;
			g_warning ("rygel-metadata-extractor.vala:231: Failed to query content type for '%s'\n", _tmp2_ = g_file_get_uri (file));
			_g_free0 (_tmp2_);
			g_signal_emit_by_name (self, "error", file, _error_);
			_inner_error_ = _g_error_copy0 (_error_);
			if (_inner_error_ != NULL) {
				_g_error_free0 (_error_);
				_g_object_unref0 (file);
				_g_object_unref0 (file_info);
				goto __finally40;
			}
			_g_error_free0 (_error_);
		}
	}
	__finally40:
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_g_object_unref0 (file);
		_g_object_unref0 (file_info);
		return;
	}
	content_type = g_file_info_get_content_type (file_info);
	mime = g_content_type_get_mime_type (content_type);
	if (mime != NULL) {
		gst_tag_list_add (self->priv->tag_list, GST_TAG_MERGE_REPLACE, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_MIME, mime, NULL);
	}
	size = g_file_info_get_size (file_info);
	gst_tag_list_add (self->priv->tag_list, GST_TAG_MERGE_REPLACE, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_SIZE, size, NULL);
	mtime = g_file_info_get_attribute_uint64 (file_info, G_FILE_ATTRIBUTE_TIME_MODIFIED);
	gst_tag_list_add (self->priv->tag_list, GST_TAG_MERGE_REPLACE, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_MTIME, mtime, NULL);
	_g_object_unref0 (file);
	_g_object_unref0 (file_info);
}


static void rygel_metadata_extractor_extract_duration (RygelMetadataExtractor* self) {
	gint64 duration;
	GstFormat format;
	g_return_if_fail (self != NULL);
	duration = 0LL;
	format = GST_FORMAT_TIME;
	if (gst_element_query_duration (self->priv->playbin, &format, &duration)) {
		gst_tag_list_add (self->priv->tag_list, GST_TAG_MERGE_REPLACE, RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_DURATION, duration, NULL);
	}
}


static inline GstElement* _dynamic_get_video_sink9 (GstElement* obj) {
	GstElement* result;
	g_object_get (obj, "video-sink", &result, NULL);
	return result;
}


static inline GstElement* _dynamic_get_audio_sink10 (GstElement* obj) {
	GstElement* result;
	g_object_get (obj, "audio-sink", &result, NULL);
	return result;
}


static void rygel_metadata_extractor_extract_stream_info (RygelMetadataExtractor* self) {
	g_return_if_fail (self != NULL);
	rygel_metadata_extractor_extract_av_info (self, gst_element_get_pad (_dynamic_get_video_sink9 (self->priv->playbin), "sink"), GST_STREAM_TYPE_VIDEO);
	rygel_metadata_extractor_extract_av_info (self, gst_element_get_pad (_dynamic_get_audio_sink10 (self->priv->playbin), "sink"), GST_STREAM_TYPE_AUDIO);
}


static void rygel_metadata_extractor_extract_av_info (RygelMetadataExtractor* self, GstPad* pad, GstStreamType type) {
	GstCaps* caps;
	const GstStructure* structure;
	g_return_if_fail (self != NULL);
	g_return_if_fail (pad != NULL);
	if (pad == NULL) {
		return;
	}
	caps = gst_pad_get_negotiated_caps (pad);
	if (caps == NULL) {
		_gst_caps_unref0 (caps);
		return;
	}
	structure = gst_caps_get_structure (caps, (guint) 0);
	if (structure == NULL) {
		_gst_caps_unref0 (caps);
		return;
	}
	if (type == GST_STREAM_TYPE_AUDIO) {
		rygel_metadata_extractor_extract_audio_info (self, structure);
	} else {
		if (type == GST_STREAM_TYPE_VIDEO) {
			rygel_metadata_extractor_extract_video_info (self, structure);
		}
	}
	_gst_caps_unref0 (caps);
}


static void rygel_metadata_extractor_extract_audio_info (RygelMetadataExtractor* self, const GstStructure* structure) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (structure != NULL);
	rygel_metadata_extractor_extract_int_value (self, structure, "channels", RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_CHANNELS);
	rygel_metadata_extractor_extract_int_value (self, structure, "rate", RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_RATE);
}


static void rygel_metadata_extractor_extract_video_info (RygelMetadataExtractor* self, const GstStructure* structure) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (structure != NULL);
	rygel_metadata_extractor_extract_int_value (self, structure, "width", RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_WIDTH);
	rygel_metadata_extractor_extract_int_value (self, structure, "height", RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_HEIGHT);
	rygel_metadata_extractor_extract_int_value (self, structure, "depth", RYGEL_METADATA_EXTRACTOR_TAG_RYGEL_DEPTH);
}


static void rygel_metadata_extractor_extract_int_value (RygelMetadataExtractor* self, const GstStructure* structure, const char* key, const char* tag) {
	gint val;
	g_return_if_fail (self != NULL);
	g_return_if_fail (structure != NULL);
	g_return_if_fail (key != NULL);
	g_return_if_fail (tag != NULL);
	val = 0;
	if (gst_structure_get_int (structure, key, &val)) {
		gst_tag_list_add (self->priv->tag_list, GST_TAG_MERGE_REPLACE, tag, val, NULL);
	}
}


static void rygel_metadata_extractor_class_init (RygelMetadataExtractorClass * klass) {
	rygel_metadata_extractor_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelMetadataExtractorPrivate));
	G_OBJECT_CLASS (klass)->finalize = rygel_metadata_extractor_finalize;
	g_signal_new ("extraction_done", RYGEL_TYPE_METADATA_EXTRACTOR, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__OBJECT_POINTER, G_TYPE_NONE, 2, G_TYPE_FILE, G_TYPE_POINTER);
	g_signal_new ("error", RYGEL_TYPE_METADATA_EXTRACTOR, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__OBJECT_POINTER, G_TYPE_NONE, 2, G_TYPE_FILE, G_TYPE_POINTER);
}


static void rygel_metadata_extractor_instance_init (RygelMetadataExtractor * self) {
	self->priv = RYGEL_METADATA_EXTRACTOR_GET_PRIVATE (self);
}


static void rygel_metadata_extractor_finalize (GObject* obj) {
	RygelMetadataExtractor * self;
	self = RYGEL_METADATA_EXTRACTOR (obj);
	_gst_object_unref0 (self->priv->playbin);
	_gst_tag_list_free0 (self->priv->tag_list);
	_g_queue_free0 (self->priv->file_queue);
	G_OBJECT_CLASS (rygel_metadata_extractor_parent_class)->finalize (obj);
}


GType rygel_metadata_extractor_get_type (void) {
	static GType rygel_metadata_extractor_type_id = 0;
	if (rygel_metadata_extractor_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMetadataExtractorClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_metadata_extractor_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMetadataExtractor), 0, (GInstanceInitFunc) rygel_metadata_extractor_instance_init, NULL };
		rygel_metadata_extractor_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelMetadataExtractor", &g_define_type_info, 0);
	}
	return rygel_metadata_extractor_type_id;
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



