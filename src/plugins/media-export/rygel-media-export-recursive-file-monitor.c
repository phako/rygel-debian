/*
 * Copyright (C) 2009 Jens Georg <mail@jensge.org>.
 *
 * Author: Jens Georg <mail@jensge.org>
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
#include <gio/gio.h>
#include <gee.h>


#define RYGEL_TYPE_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR (rygel_media_export_recursive_file_monitor_get_type ())
#define RYGEL_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR, RygelMediaExportRecursiveFileMonitor))
#define RYGEL_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR, RygelMediaExportRecursiveFileMonitorClass))
#define RYGEL_IS_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR))
#define RYGEL_IS_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR))
#define RYGEL_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR, RygelMediaExportRecursiveFileMonitorClass))

typedef struct _RygelMediaExportRecursiveFileMonitor RygelMediaExportRecursiveFileMonitor;
typedef struct _RygelMediaExportRecursiveFileMonitorClass RygelMediaExportRecursiveFileMonitorClass;
typedef struct _RygelMediaExportRecursiveFileMonitorPrivate RygelMediaExportRecursiveFileMonitorPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

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


static gpointer rygel_media_export_recursive_file_monitor_parent_class = NULL;

GType rygel_media_export_recursive_file_monitor_get_type (void);
#define RYGEL_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR, RygelMediaExportRecursiveFileMonitorPrivate))
enum  {
	RYGEL_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR_DUMMY_PROPERTY
};
RygelMediaExportRecursiveFileMonitor* rygel_media_export_recursive_file_monitor_new (GCancellable* cancellable);
RygelMediaExportRecursiveFileMonitor* rygel_media_export_recursive_file_monitor_construct (GType object_type, GCancellable* cancellable);
void rygel_media_export_recursive_file_monitor_monitor (RygelMediaExportRecursiveFileMonitor* self, GFile* file);
void rygel_media_export_recursive_file_monitor_on_monitor_changed (RygelMediaExportRecursiveFileMonitor* self, GFile* file, GFile* other_file, GFileMonitorEvent event_type);
static void _rygel_media_export_recursive_file_monitor_on_monitor_changed_g_file_monitor_changed (GFileMonitor* _sender, GFile* file, GFile* other_file, GFileMonitorEvent event_type, gpointer self);
static void rygel_media_export_recursive_file_monitor_on_info_ready (RygelMediaExportRecursiveFileMonitor* self, GObject* source, GAsyncResult* res);
static void _rygel_media_export_recursive_file_monitor_on_info_ready_gasync_ready_callback (GObject* source_object, GAsyncResult* res, gpointer self);
void rygel_media_export_recursive_file_monitor_cancel (RygelMediaExportRecursiveFileMonitor* self);
static void rygel_media_export_recursive_file_monitor_finalize (GObject* obj);


static void g_cclosure_user_marshal_VOID__OBJECT_OBJECT_ENUM (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);

static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


RygelMediaExportRecursiveFileMonitor* rygel_media_export_recursive_file_monitor_construct (GType object_type, GCancellable* cancellable) {
	RygelMediaExportRecursiveFileMonitor * self;
	GCancellable* _tmp0_;
	GeeHashMap* _tmp1_;
	self = (RygelMediaExportRecursiveFileMonitor*) g_object_new (object_type, NULL);
	self->priv->cancellable = (_tmp0_ = _g_object_ref0 (cancellable), _g_object_unref0 (self->priv->cancellable), _tmp0_);
	self->priv->monitors = (_tmp1_ = gee_hash_map_new (G_TYPE_FILE, (GBoxedCopyFunc) g_object_ref, g_object_unref, G_TYPE_FILE_MONITOR, (GBoxedCopyFunc) g_object_ref, g_object_unref, g_file_hash, g_file_equal, g_direct_equal), _g_object_unref0 (self->priv->monitors), _tmp1_);
	return self;
}


RygelMediaExportRecursiveFileMonitor* rygel_media_export_recursive_file_monitor_new (GCancellable* cancellable) {
	return rygel_media_export_recursive_file_monitor_construct (RYGEL_TYPE_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR, cancellable);
}


static void _rygel_media_export_recursive_file_monitor_on_monitor_changed_g_file_monitor_changed (GFileMonitor* _sender, GFile* file, GFile* other_file, GFileMonitorEvent event_type, gpointer self) {
	rygel_media_export_recursive_file_monitor_on_monitor_changed (self, file, other_file, event_type);
}


void rygel_media_export_recursive_file_monitor_on_monitor_changed (RygelMediaExportRecursiveFileMonitor* self, GFile* file, GFile* other_file, GFileMonitorEvent event_type) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (file != NULL);
	g_signal_emit_by_name (self, "changed", file, other_file, event_type);
	switch (event_type) {
		case G_FILE_MONITOR_EVENT_CREATED:
		{
			rygel_media_export_recursive_file_monitor_monitor (self, file);
			break;
		}
		case G_FILE_MONITOR_EVENT_DELETED:
		{
			GFileMonitor* file_monitor;
			file_monitor = (GFileMonitor*) gee_abstract_map_get ((GeeAbstractMap*) self->priv->monitors, file);
			if (file_monitor != NULL) {
				char* _tmp0_;
				guint _tmp1_;
				g_debug ("rygel-media-export-recursive-file-monitor.vala:50: Directory %s gone, removing watch", _tmp0_ = g_file_get_uri (file));
				_g_free0 (_tmp0_);
				gee_abstract_map_remove ((GeeAbstractMap*) self->priv->monitors, file, NULL);
				g_file_monitor_cancel (file_monitor);
				g_signal_handlers_disconnect_matched (file_monitor, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, (g_signal_parse_name ("changed", G_TYPE_FILE_MONITOR, &_tmp1_, NULL, FALSE), _tmp1_), 0, NULL, (GCallback) _rygel_media_export_recursive_file_monitor_on_monitor_changed_g_file_monitor_changed, self);
			}
			_g_object_unref0 (file_monitor);
			break;
		}
		default:
		{
			break;
		}
	}
}


static void rygel_media_export_recursive_file_monitor_on_info_ready (RygelMediaExportRecursiveFileMonitor* self, GObject* source, GAsyncResult* res) {
	GError * _inner_error_;
	GFile* file;
	g_return_if_fail (self != NULL);
	g_return_if_fail (res != NULL);
	_inner_error_ = NULL;
	file = _g_object_ref0 (G_FILE (source));
	{
		GFileInfo* info;
		info = g_file_query_info_finish (file, res, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch7_g_error;
			goto __finally7;
		}
		if (g_file_info_get_file_type (info) == G_FILE_TYPE_DIRECTORY) {
			GFileMonitor* file_monitor;
			file_monitor = g_file_monitor_directory (file, G_FILE_MONITOR_NONE, self->priv->cancellable, &_inner_error_);
			if (_inner_error_ != NULL) {
				_g_object_unref0 (info);
				goto __catch7_g_error;
				goto __finally7;
			}
			gee_abstract_map_set ((GeeAbstractMap*) self->priv->monitors, file, file_monitor);
			g_signal_connect_object (file_monitor, "changed", (GCallback) _rygel_media_export_recursive_file_monitor_on_monitor_changed_g_file_monitor_changed, self, 0);
			_g_object_unref0 (file_monitor);
		}
		_g_object_unref0 (info);
	}
	goto __finally7;
	__catch7_g_error:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp0_;
			g_warning ("rygel-media-export-recursive-file-monitor.vala:76: Failed to get file info for %s", _tmp0_ = g_file_get_uri (file));
			_g_free0 (_tmp0_);
			_g_error_free0 (_error_);
		}
	}
	__finally7:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (file);
		g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
		g_clear_error (&_inner_error_);
		return;
	}
	_g_object_unref0 (file);
}


static void _rygel_media_export_recursive_file_monitor_on_info_ready_gasync_ready_callback (GObject* source_object, GAsyncResult* res, gpointer self) {
	rygel_media_export_recursive_file_monitor_on_info_ready (self, source_object, res);
}


void rygel_media_export_recursive_file_monitor_monitor (RygelMediaExportRecursiveFileMonitor* self, GFile* file) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (file != NULL);
	g_file_query_info_async (file, G_FILE_ATTRIBUTE_STANDARD_TYPE, G_FILE_QUERY_INFO_NONE, G_PRIORITY_DEFAULT, NULL, _rygel_media_export_recursive_file_monitor_on_info_ready_gasync_ready_callback, self);
}


void rygel_media_export_recursive_file_monitor_cancel (RygelMediaExportRecursiveFileMonitor* self) {
	g_return_if_fail (self != NULL);
	if (self->priv->cancellable != NULL) {
		g_cancellable_cancel (self->priv->cancellable);
	} else {
		{
			GeeCollection* _tmp0_;
			GeeIterator* _tmp1_;
			GeeIterator* _monitor_it;
			_monitor_it = (_tmp1_ = gee_iterable_iterator ((GeeIterable*) (_tmp0_ = gee_abstract_map_get_values ((GeeAbstractMap*) self->priv->monitors))), _g_object_unref0 (_tmp0_), _tmp1_);
			while (TRUE) {
				GFileMonitor* monitor;
				if (!gee_iterator_next (_monitor_it)) {
					break;
				}
				monitor = (GFileMonitor*) gee_iterator_get (_monitor_it);
				g_file_monitor_cancel (monitor);
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
	g_signal_new ("changed", RYGEL_TYPE_MEDIA_EXPORT_RECURSIVE_FILE_MONITOR, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__OBJECT_OBJECT_ENUM, G_TYPE_NONE, 3, G_TYPE_FILE, G_TYPE_FILE, G_TYPE_FILE_MONITOR_EVENT);
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
	static GType rygel_media_export_recursive_file_monitor_type_id = 0;
	if (rygel_media_export_recursive_file_monitor_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelMediaExportRecursiveFileMonitorClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_media_export_recursive_file_monitor_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelMediaExportRecursiveFileMonitor), 0, (GInstanceInitFunc) rygel_media_export_recursive_file_monitor_instance_init, NULL };
		rygel_media_export_recursive_file_monitor_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelMediaExportRecursiveFileMonitor", &g_define_type_info, 0);
	}
	return rygel_media_export_recursive_file_monitor_type_id;
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



