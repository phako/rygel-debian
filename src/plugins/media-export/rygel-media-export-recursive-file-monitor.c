/* rygel-media-export-recursive-file-monitor.c generated by valac, the Vala compiler
 * generated from rygel-media-export-recursive-file-monitor.vala, do not modify */

/*
 * Copyright (C) 2009 Jens Georg <mail@jensge.org>.
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
#include <gio/gio.h>
#include <gee.h>
#include <glib/gi18n-lib.h>


#define RYGEL_MEDIA_EXPORT_TYPE_RECURSIVE_FILE_MONITOR (rygel_media_export_recursive_file_monitor_get_type ())
#define RYGEL_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_MEDIA_EXPORT_TYPE_RECURSIVE_FILE_MONITOR, RygelMediaExportRecursiveFileMonitor))
#define RYGEL_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_MEDIA_EXPORT_TYPE_RECURSIVE_FILE_MONITOR, RygelMediaExportRecursiveFileMonitorClass))
#define RYGEL_MEDIA_EXPORT_IS_RECURSIVE_FILE_MONITOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_MEDIA_EXPORT_TYPE_RECURSIVE_FILE_MONITOR))
#define RYGEL_MEDIA_EXPORT_IS_RECURSIVE_FILE_MONITOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_MEDIA_EXPORT_TYPE_RECURSIVE_FILE_MONITOR))
#define RYGEL_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_MEDIA_EXPORT_TYPE_RECURSIVE_FILE_MONITOR, RygelMediaExportRecursiveFileMonitorClass))

typedef struct _RygelMediaExportRecursiveFileMonitor RygelMediaExportRecursiveFileMonitor;
typedef struct _RygelMediaExportRecursiveFileMonitorClass RygelMediaExportRecursiveFileMonitorClass;
typedef struct _RygelMediaExportRecursiveFileMonitorPrivate RygelMediaExportRecursiveFileMonitorPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _RygelMediaExportRecursiveFileMonitorMonitorData RygelMediaExportRecursiveFileMonitorMonitorData;

struct _RygelMediaExportRecursiveFileMonitor {
	GObject parent_instance;
	RygelMediaExportRecursiveFileMonitorPrivate * priv;
};

struct _RygelMediaExportRecursiveFileMonitorClass {
	GObjectClass parent_class;
};

struct _RygelMediaExportRecursiveFileMonitorPrivate {
	GCancellable* cancellable;
	GeeHashMap* monitors;
};

struct _RygelMediaExportRecursiveFileMonitorMonitorData {
	int _state_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	RygelMediaExportRecursiveFileMonitor* self;
	GFile* file;
	GFileInfo* info;
	GFileMonitor* file_monitor;
	char* _tmp0_;
	GError * err;
	GError * _inner_error_;
};


static gpointer rygel_media_export_recursive_file_monitor_parent_class = NULL;

GType rygel_media_export_recursive_file_monitor_get_type (void) G_GNUC_CONST;
#define RYGEL_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_MEDIA_EXPORT_TYPE_RECURSIVE_FILE_MONITOR, RygelMediaExportRecursiveFileMonitorPrivate))
enum  {
	RYGEL_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR_DUMMY_PROPERTY
};
RygelMediaExportRecursiveFileMonitor* rygel_media_export_recursive_file_monitor_new (GCancellable* cancellable);
RygelMediaExportRecursiveFileMonitor* rygel_media_export_recursive_file_monitor_construct (GType object_type, GCancellable* cancellable);
void rygel_media_export_recursive_file_monitor_monitor (RygelMediaExportRecursiveFileMonitor* self, GFile* file, GAsyncReadyCallback _callback_, gpointer _user_data_);
void rygel_media_export_recursive_file_monitor_monitor_finish (RygelMediaExportRecursiveFileMonitor* self, GAsyncResult* _res_);
void rygel_media_export_recursive_file_monitor_on_monitor_changed (RygelMediaExportRecursiveFileMonitor* self, GFile* file, GFile* other_file, GFileMonitorEvent event_type);
static void _rygel_media_export_recursive_file_monitor_on_monitor_changed_g_file_monitor_changed (GFileMonitor* _sender, GFile* file, GFile* other_file, GFileMonitorEvent event_type, gpointer self);
static void rygel_media_export_recursive_file_monitor_monitor_data_free (gpointer _data);
static void rygel_media_export_recursive_file_monitor_monitor_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static gboolean rygel_media_export_recursive_file_monitor_monitor_co (RygelMediaExportRecursiveFileMonitorMonitorData* data);
void rygel_media_export_recursive_file_monitor_cancel (RygelMediaExportRecursiveFileMonitor* self);
static void rygel_media_export_recursive_file_monitor_finalize (GObject* obj);


static void g_cclosure_user_marshal_VOID__OBJECT_OBJECT_ENUM (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);

static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


#line 29 "rygel-media-export-recursive-file-monitor.vala"
RygelMediaExportRecursiveFileMonitor* rygel_media_export_recursive_file_monitor_construct (GType object_type, GCancellable* cancellable) {
#line 104 "rygel-media-export-recursive-file-monitor.c"
	RygelMediaExportRecursiveFileMonitor * self;
	GCancellable* _tmp0_;
	GeeHashMap* _tmp1_;
#line 29 "rygel-media-export-recursive-file-monitor.vala"
	self = (RygelMediaExportRecursiveFileMonitor*) g_object_new (object_type, NULL);
#line 30 "rygel-media-export-recursive-file-monitor.vala"
	self->priv->cancellable = (_tmp0_ = _g_object_ref0 (cancellable), _g_object_unref0 (self->priv->cancellable), _tmp0_);
#line 31 "rygel-media-export-recursive-file-monitor.vala"
	self->priv->monitors = (_tmp1_ = gee_hash_map_new (G_TYPE_FILE, (GBoxedCopyFunc) g_object_ref, g_object_unref, G_TYPE_FILE_MONITOR, (GBoxedCopyFunc) g_object_ref, g_object_unref, g_file_hash, g_file_equal, NULL), _g_object_unref0 (self->priv->monitors), _tmp1_);
#line 114 "rygel-media-export-recursive-file-monitor.c"
	return self;
}


#line 29 "rygel-media-export-recursive-file-monitor.vala"
RygelMediaExportRecursiveFileMonitor* rygel_media_export_recursive_file_monitor_new (GCancellable* cancellable) {
#line 29 "rygel-media-export-recursive-file-monitor.vala"
	return rygel_media_export_recursive_file_monitor_construct (RYGEL_MEDIA_EXPORT_TYPE_RECURSIVE_FILE_MONITOR, cancellable);
#line 123 "rygel-media-export-recursive-file-monitor.c"
}


#line 35 "rygel-media-export-recursive-file-monitor.vala"
static void _rygel_media_export_recursive_file_monitor_on_monitor_changed_g_file_monitor_changed (GFileMonitor* _sender, GFile* file, GFile* other_file, GFileMonitorEvent event_type, gpointer self) {
#line 129 "rygel-media-export-recursive-file-monitor.c"
	rygel_media_export_recursive_file_monitor_on_monitor_changed (self, file, other_file, event_type);
}


#line 35 "rygel-media-export-recursive-file-monitor.vala"
void rygel_media_export_recursive_file_monitor_on_monitor_changed (RygelMediaExportRecursiveFileMonitor* self, GFile* file, GFile* other_file, GFileMonitorEvent event_type) {
#line 35 "rygel-media-export-recursive-file-monitor.vala"
	g_return_if_fail (self != NULL);
#line 35 "rygel-media-export-recursive-file-monitor.vala"
	g_return_if_fail (file != NULL);
#line 38 "rygel-media-export-recursive-file-monitor.vala"
	g_signal_emit_by_name (self, "changed", file, other_file, event_type);
#line 40 "rygel-media-export-recursive-file-monitor.vala"
	switch (event_type) {
#line 144 "rygel-media-export-recursive-file-monitor.c"
		case G_FILE_MONITOR_EVENT_CREATED:
		{
#line 42 "rygel-media-export-recursive-file-monitor.vala"
			rygel_media_export_recursive_file_monitor_monitor (self, file, NULL, NULL);
#line 43 "rygel-media-export-recursive-file-monitor.vala"
			break;
#line 151 "rygel-media-export-recursive-file-monitor.c"
		}
		case G_FILE_MONITOR_EVENT_DELETED:
		{
			GFileMonitor* file_monitor;
#line 45 "rygel-media-export-recursive-file-monitor.vala"
			file_monitor = (GFileMonitor*) gee_abstract_map_get ((GeeAbstractMap*) self->priv->monitors, file);
#line 46 "rygel-media-export-recursive-file-monitor.vala"
			if (file_monitor != NULL) {
#line 160 "rygel-media-export-recursive-file-monitor.c"
				char* _tmp0_;
				guint _tmp1_;
#line 47 "rygel-media-export-recursive-file-monitor.vala"
				g_debug (_ ("Directory %s gone, removing watch"), _tmp0_ = g_file_get_uri (file));
#line 165 "rygel-media-export-recursive-file-monitor.c"
				_g_free0 (_tmp0_);
#line 49 "rygel-media-export-recursive-file-monitor.vala"
				gee_map_remove ((GeeMap*) self->priv->monitors, file, NULL);
#line 50 "rygel-media-export-recursive-file-monitor.vala"
				g_file_monitor_cancel (file_monitor);
#line 51 "rygel-media-export-recursive-file-monitor.vala"
				g_signal_parse_name ("changed", G_TYPE_FILE_MONITOR, &_tmp1_, NULL, FALSE);
#line 51 "rygel-media-export-recursive-file-monitor.vala"
				g_signal_handlers_disconnect_matched (file_monitor, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, _tmp1_, 0, NULL, (GCallback) _rygel_media_export_recursive_file_monitor_on_monitor_changed_g_file_monitor_changed, self);
#line 175 "rygel-media-export-recursive-file-monitor.c"
			}
			_g_object_unref0 (file_monitor);
#line 53 "rygel-media-export-recursive-file-monitor.vala"
			break;
#line 180 "rygel-media-export-recursive-file-monitor.c"
		}
		default:
		{
#line 56 "rygel-media-export-recursive-file-monitor.vala"
			break;
#line 186 "rygel-media-export-recursive-file-monitor.c"
		}
	}
}


static void rygel_media_export_recursive_file_monitor_monitor_data_free (gpointer _data) {
	RygelMediaExportRecursiveFileMonitorMonitorData* data;
	data = _data;
	_g_object_unref0 (data->file);
	g_object_unref (data->self);
	g_slice_free (RygelMediaExportRecursiveFileMonitorMonitorData, data);
}


void rygel_media_export_recursive_file_monitor_monitor (RygelMediaExportRecursiveFileMonitor* self, GFile* file, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	RygelMediaExportRecursiveFileMonitorMonitorData* _data_;
	_data_ = g_slice_new0 (RygelMediaExportRecursiveFileMonitorMonitorData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, rygel_media_export_recursive_file_monitor_monitor);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, rygel_media_export_recursive_file_monitor_monitor_data_free);
	_data_->self = g_object_ref (self);
	_data_->file = _g_object_ref0 (file);
	rygel_media_export_recursive_file_monitor_monitor_co (_data_);
}


void rygel_media_export_recursive_file_monitor_monitor_finish (RygelMediaExportRecursiveFileMonitor* self, GAsyncResult* _res_) {
	RygelMediaExportRecursiveFileMonitorMonitorData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void rygel_media_export_recursive_file_monitor_monitor_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	RygelMediaExportRecursiveFileMonitorMonitorData* data;
	data = _user_data_;
	data->_res_ = _res_;
	rygel_media_export_recursive_file_monitor_monitor_co (data);
}


static gboolean rygel_media_export_recursive_file_monitor_monitor_co (RygelMediaExportRecursiveFileMonitorMonitorData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		case 6:
		goto _state_6;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	{
		{
			data->_state_ = 6;
			g_file_query_info_async (data->file, G_FILE_ATTRIBUTE_STANDARD_TYPE, G_FILE_QUERY_INFO_NONE, G_PRIORITY_DEFAULT, NULL, rygel_media_export_recursive_file_monitor_monitor_ready, data);
			return FALSE;
			_state_6:
			data->info = g_file_query_info_finish (data->file, data->_res_, &data->_inner_error_);
			if (data->_inner_error_ != NULL) {
				goto __catch37_g_error;
			}
#line 67 "rygel-media-export-recursive-file-monitor.vala"
			if (g_file_info_get_file_type (data->info) == G_FILE_TYPE_DIRECTORY) {
#line 248 "rygel-media-export-recursive-file-monitor.c"
				data->file_monitor = g_file_monitor_directory (data->file, G_FILE_MONITOR_NONE, data->self->priv->cancellable, &data->_inner_error_);
				if (data->_inner_error_ != NULL) {
					_g_object_unref0 (data->info);
					goto __catch37_g_error;
				}
#line 71 "rygel-media-export-recursive-file-monitor.vala"
				gee_abstract_map_set ((GeeAbstractMap*) data->self->priv->monitors, data->file, data->file_monitor);
#line 72 "rygel-media-export-recursive-file-monitor.vala"
				g_signal_connect_object (data->file_monitor, "changed", (GCallback) _rygel_media_export_recursive_file_monitor_on_monitor_changed_g_file_monitor_changed, data->self, 0);
#line 258 "rygel-media-export-recursive-file-monitor.c"
				_g_object_unref0 (data->file_monitor);
			}
			_g_object_unref0 (data->info);
		}
		goto __finally37;
		__catch37_g_error:
		{
			data->err = data->_inner_error_;
			data->_inner_error_ = NULL;
			{
#line 75 "rygel-media-export-recursive-file-monitor.vala"
				g_warning (_ ("Failed to get file info for %s"), data->_tmp0_ = g_file_get_uri (data->file));
#line 271 "rygel-media-export-recursive-file-monitor.c"
				_g_free0 (data->_tmp0_);
				_g_error_free0 (data->err);
			}
		}
		__finally37:
		if (data->_inner_error_ != NULL) {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, data->_inner_error_->message, g_quark_to_string (data->_inner_error_->domain), data->_inner_error_->code);
			g_clear_error (&data->_inner_error_);
			return FALSE;
		}
	}
	{
		if (data->_state_ == 0) {
			g_simple_async_result_complete_in_idle (data->_async_result);
		} else {
			g_simple_async_result_complete (data->_async_result);
		}
		g_object_unref (data->_async_result);
		return FALSE;
	}
}


#line 79 "rygel-media-export-recursive-file-monitor.vala"
void rygel_media_export_recursive_file_monitor_cancel (RygelMediaExportRecursiveFileMonitor* self) {
#line 79 "rygel-media-export-recursive-file-monitor.vala"
	g_return_if_fail (self != NULL);
#line 80 "rygel-media-export-recursive-file-monitor.vala"
	if (self->priv->cancellable != NULL) {
#line 81 "rygel-media-export-recursive-file-monitor.vala"
		g_cancellable_cancel (self->priv->cancellable);
#line 303 "rygel-media-export-recursive-file-monitor.c"
	} else {
		{
			GeeCollection* _tmp0_;
			GeeIterator* _tmp1_;
			GeeIterator* _monitor_it;
#line 83 "rygel-media-export-recursive-file-monitor.vala"
			_monitor_it = (_tmp1_ = gee_iterable_iterator ((GeeIterable*) (_tmp0_ = gee_map_get_values ((GeeMap*) self->priv->monitors))), _g_object_unref0 (_tmp0_), _tmp1_);
#line 83 "rygel-media-export-recursive-file-monitor.vala"
			while (TRUE) {
#line 313 "rygel-media-export-recursive-file-monitor.c"
				GFileMonitor* monitor;
#line 83 "rygel-media-export-recursive-file-monitor.vala"
				if (!gee_iterator_next (_monitor_it)) {
#line 83 "rygel-media-export-recursive-file-monitor.vala"
					break;
#line 319 "rygel-media-export-recursive-file-monitor.c"
				}
#line 83 "rygel-media-export-recursive-file-monitor.vala"
				monitor = (GFileMonitor*) gee_iterator_get (_monitor_it);
#line 84 "rygel-media-export-recursive-file-monitor.vala"
				g_file_monitor_cancel (monitor);
#line 325 "rygel-media-export-recursive-file-monitor.c"
				_g_object_unref0 (monitor);
			}
			_g_object_unref0 (_monitor_it);
		}
	}
}


static void rygel_media_export_recursive_file_monitor_class_init (RygelMediaExportRecursiveFileMonitorClass * klass) {
	rygel_media_export_recursive_file_monitor_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelMediaExportRecursiveFileMonitorPrivate));
	G_OBJECT_CLASS (klass)->finalize = rygel_media_export_recursive_file_monitor_finalize;
	g_signal_new ("changed", RYGEL_MEDIA_EXPORT_TYPE_RECURSIVE_FILE_MONITOR, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__OBJECT_OBJECT_ENUM, G_TYPE_NONE, 3, G_TYPE_FILE, G_TYPE_FILE, G_TYPE_FILE_MONITOR_EVENT);
}


static void rygel_media_export_recursive_file_monitor_instance_init (RygelMediaExportRecursiveFileMonitor * self) {
	self->priv = RYGEL_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR_GET_PRIVATE (self);
}


static void rygel_media_export_recursive_file_monitor_finalize (GObject* obj) {
	RygelMediaExportRecursiveFileMonitor * self;
	self = RYGEL_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR (obj);
	_g_object_unref0 (self->priv->cancellable);
	_g_object_unref0 (self->priv->monitors);
	G_OBJECT_CLASS (rygel_media_export_recursive_file_monitor_parent_class)->finalize (obj);
}


GType rygel_media_export_recursive_file_monitor_get_type (void) {
	static volatile gsize rygel_media_export_recursive_file_monitor_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_media_export_recursive_file_monitor_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediaExportRecursiveFileMonitorClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_media_export_recursive_file_monitor_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediaExportRecursiveFileMonitor), 0, (GInstanceInitFunc) rygel_media_export_recursive_file_monitor_instance_init, NULL };
		GType rygel_media_export_recursive_file_monitor_type_id;
		rygel_media_export_recursive_file_monitor_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelMediaExportRecursiveFileMonitor", &g_define_type_info, 0);
		g_once_init_leave (&rygel_media_export_recursive_file_monitor_type_id__volatile, rygel_media_export_recursive_file_monitor_type_id);
	}
	return rygel_media_export_recursive_file_monitor_type_id__volatile;
}



static void g_cclosure_user_marshal_VOID__OBJECT_OBJECT_ENUM (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data) {
	typedef void (*GMarshalFunc_VOID__OBJECT_OBJECT_ENUM) (gpointer data1, gpointer arg_1, gpointer arg_2, gint arg_3, gpointer data2);
	register GMarshalFunc_VOID__OBJECT_OBJECT_ENUM callback;
	register GCClosure * cc;
	register gpointer data1, data2;
	cc = (GCClosure *) closure;
	g_return_if_fail (n_param_values == 4);
	if (G_CCLOSURE_SWAP_DATA (closure)) {
		data1 = closure->data;
		data2 = param_values->data[0].v_pointer;
	} else {
		data1 = param_values->data[0].v_pointer;
		data2 = closure->data;
	}
	callback = (GMarshalFunc_VOID__OBJECT_OBJECT_ENUM) (marshal_data ? marshal_data : cc->callback);
	callback (data1, g_value_get_object (param_values + 1), g_value_get_object (param_values + 2), g_value_get_enum (param_values + 3), data2);
}



