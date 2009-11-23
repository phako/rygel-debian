/* rygel-database.c generated by valac, the Vala compiler
 * generated from rygel-database.vala, do not modify */

/*
 * Copyright (C) 2009 Jens Georg <mail@jensge.org>.
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
#include <sqlite3.h>
#include <stdlib.h>
#include <string.h>


#define RYGEL_TYPE_DATABASE (rygel_database_get_type ())
#define RYGEL_DATABASE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_DATABASE, RygelDatabase))
#define RYGEL_DATABASE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_DATABASE, RygelDatabaseClass))
#define RYGEL_IS_DATABASE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_DATABASE))
#define RYGEL_IS_DATABASE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_DATABASE))
#define RYGEL_DATABASE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_DATABASE, RygelDatabaseClass))

typedef struct _RygelDatabase RygelDatabase;
typedef struct _RygelDatabaseClass RygelDatabaseClass;
typedef struct _RygelDatabasePrivate RygelDatabasePrivate;
#define _sqlite3_close0(var) ((var == NULL) ? NULL : (var = (sqlite3_close (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _sqlite3_finalize0(var) ((var == NULL) ? NULL : (var = (sqlite3_finalize (var), NULL)))

typedef enum  {
	RYGEL_DATABASE_ERROR_SQLITE_ERROR
} RygelDatabaseError;
#define RYGEL_DATABASE_ERROR rygel_database_error_quark ()
struct _RygelDatabase {
	GObject parent_instance;
	RygelDatabasePrivate * priv;
};

struct _RygelDatabaseClass {
	GObjectClass parent_class;
};

struct _RygelDatabasePrivate {
	sqlite3* db;
};

typedef gboolean (*RygelDatabaseRowCallback) (sqlite3_stmt* stmt, void* user_data);

static gpointer rygel_database_parent_class = NULL;

GQuark rygel_database_error_quark (void);
GType rygel_database_get_type (void);
#define RYGEL_DATABASE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RYGEL_TYPE_DATABASE, RygelDatabasePrivate))
enum  {
	RYGEL_DATABASE_DUMMY_PROPERTY
};
RygelDatabase* rygel_database_new (const char* name);
RygelDatabase* rygel_database_construct (GType object_type, const char* name);
static sqlite3_stmt* rygel_database_prepare_statement (RygelDatabase* self, const char* sql, GValue* values, int values_length1, GError** error);
gint rygel_database_exec (RygelDatabase* self, const char* sql, GValue* values, int values_length1, RygelDatabaseRowCallback callback, void* callback_target, GError** error);
void rygel_database_analyze (RygelDatabase* self);
void rygel_database_null (GValue* result);
void rygel_database_begin (RygelDatabase* self, GError** error);
void rygel_database_commit (RygelDatabase* self, GError** error);
void rygel_database_rollback (RygelDatabase* self);
static void rygel_database_finalize (GObject* obj);



GQuark rygel_database_error_quark (void) {
	return g_quark_from_static_string ("rygel_database_error-quark");
}


RygelDatabase* rygel_database_construct (GType object_type, const char* name) {
	RygelDatabase * self;
	char* dirname;
	char* _tmp0_;
	char* _tmp1_;
	char* db_file;
	sqlite3* _tmp4_;
	gint _tmp3_;
	sqlite3* _tmp2_ = NULL;
	gint rc;
	g_return_val_if_fail (name != NULL, NULL);
	self = (RygelDatabase*) g_object_new (object_type, NULL);
	dirname = g_build_filename (g_get_user_cache_dir (), "rygel", NULL);
	g_mkdir_with_parents (dirname, 0750);
	db_file = (_tmp1_ = g_build_filename (dirname, _tmp0_ = g_strdup_printf ("%s.db", name), NULL), _g_free0 (_tmp0_), _tmp1_);
	g_debug ("rygel-database.vala:39: Using database file %s", db_file);
	rc = (_tmp3_ = sqlite3_open (db_file, &_tmp2_), self->priv->db = (_tmp4_ = _tmp2_, _sqlite3_close0 (self->priv->db), _tmp4_), _tmp3_);
	if (rc != SQLITE_OK) {
		g_warning ("rygel-database.vala:42: Failed to open database: %d, %s", rc, sqlite3_errmsg (self->priv->db));
		_g_free0 (dirname);
		_g_free0 (db_file);
		return self;
	}
	sqlite3_exec (self->priv->db, "PRAGMA cache_size = 32768", NULL, NULL, NULL);
	sqlite3_exec (self->priv->db, "PRAGMA synchronous = OFF", NULL, NULL, NULL);
	sqlite3_exec (self->priv->db, "PRAGMA temp_store = MEMORY", NULL, NULL, NULL);
	sqlite3_exec (self->priv->db, "PRAGMA count_changes = OFF", NULL, NULL, NULL);
	_g_free0 (dirname);
	_g_free0 (db_file);
	return self;
}


RygelDatabase* rygel_database_new (const char* name) {
	return rygel_database_construct (RYGEL_TYPE_DATABASE, name);
}


gint rygel_database_exec (RygelDatabase* self, const char* sql, GValue* values, int values_length1, RygelDatabaseRowCallback callback, void* callback_target, GError** error) {
	gint result;
	GError * _inner_error_;
	gint rc = 0;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	g_return_val_if_fail (self != NULL, 0);
	g_return_val_if_fail (sql != NULL, 0);
	_inner_error_ = NULL;
	if (values == NULL) {
		_tmp0_ = callback == NULL;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		rc = sqlite3_exec (self->priv->db, sql, NULL, NULL, NULL);
	} else {
		sqlite3_stmt* statement;
		statement = rygel_database_prepare_statement (self, sql, values, values_length1, &_inner_error_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == RYGEL_DATABASE_ERROR) {
				g_propagate_error (error, _inner_error_);
				return 0;
			} else {
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return 0;
			}
		}
		while (TRUE) {
			if (!((rc = sqlite3_step (statement)) == SQLITE_ROW)) {
				break;
			}
			if (callback != NULL) {
				if (!callback (statement, callback_target)) {
					rc = SQLITE_DONE;
					break;
				}
			}
		}
		_sqlite3_finalize0 (statement);
	}
	if (rc != SQLITE_DONE) {
		_tmp1_ = rc != SQLITE_OK;
	} else {
		_tmp1_ = FALSE;
	}
	if (_tmp1_) {
		_inner_error_ = g_error_new_literal (RYGEL_DATABASE_ERROR, RYGEL_DATABASE_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == RYGEL_DATABASE_ERROR) {
				g_propagate_error (error, _inner_error_);
				return 0;
			} else {
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return 0;
			}
		}
	}
	result = rc;
	return result;
}


static sqlite3_stmt* rygel_database_prepare_statement (RygelDatabase* self, const char* sql, GValue* values, int values_length1, GError** error) {
	sqlite3_stmt* result;
	GError * _inner_error_;
	sqlite3_stmt* statement;
	sqlite3_stmt* _tmp2_;
	gint _tmp1_;
	sqlite3_stmt* _tmp0_ = NULL;
	gint rc;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (sql != NULL, NULL);
	_inner_error_ = NULL;
	statement = NULL;
	rc = (_tmp1_ = sqlite3_prepare_v2 (self->priv->db, sql, -1, &_tmp0_, NULL), statement = (_tmp2_ = _tmp0_, _sqlite3_finalize0 (statement), _tmp2_), _tmp1_);
	if (rc != SQLITE_OK) {
		_inner_error_ = g_error_new_literal (RYGEL_DATABASE_ERROR, RYGEL_DATABASE_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == RYGEL_DATABASE_ERROR) {
				g_propagate_error (error, _inner_error_);
				_sqlite3_finalize0 (statement);
				return NULL;
			} else {
				_sqlite3_finalize0 (statement);
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return NULL;
			}
		}
	}
	if (values != NULL) {
		{
			gint i;
			i = 0;
			{
				gboolean _tmp3_;
				_tmp3_ = TRUE;
				while (TRUE) {
					GValue _tmp4_;
					if (!_tmp3_) {
						i++;
					}
					_tmp3_ = FALSE;
					if (!(i < values_length1)) {
						break;
					}
					if (G_VALUE_HOLDS ((_tmp4_ = values[i], &_tmp4_), G_TYPE_INT)) {
						GValue _tmp5_;
						rc = sqlite3_bind_int (statement, i + 1, g_value_get_int ((_tmp5_ = values[i], &_tmp5_)));
					} else {
						GValue _tmp6_;
						if (G_VALUE_HOLDS ((_tmp6_ = values[i], &_tmp6_), G_TYPE_INT64)) {
							GValue _tmp7_;
							rc = sqlite3_bind_int64 (statement, i + 1, g_value_get_int64 ((_tmp7_ = values[i], &_tmp7_)));
						} else {
							GValue _tmp8_;
							if (G_VALUE_HOLDS ((_tmp8_ = values[i], &_tmp8_), G_TYPE_LONG)) {
								GValue _tmp9_;
								rc = sqlite3_bind_int64 (statement, i + 1, (gint64) g_value_get_long ((_tmp9_ = values[i], &_tmp9_)));
							} else {
								GValue _tmp10_;
								if (G_VALUE_HOLDS ((_tmp10_ = values[i], &_tmp10_), G_TYPE_STRING)) {
									GValue _tmp11_;
									rc = sqlite3_bind_text (statement, i + 1, g_strdup (g_value_get_string ((_tmp11_ = values[i], &_tmp11_))), -1, g_free);
								} else {
									GValue _tmp12_;
									if (G_VALUE_HOLDS ((_tmp12_ = values[i], &_tmp12_), G_TYPE_POINTER)) {
										GValue _tmp13_;
										if (g_value_peek_pointer ((_tmp13_ = values[i], &_tmp13_)) == NULL) {
											rc = sqlite3_bind_null (statement, i + 1);
										} else {
											g_assert_not_reached ();
										}
									} else {
										GValue _tmp14_;
										GType t;
										t = G_VALUE_TYPE ((_tmp14_ = values[i], &_tmp14_));
										g_warning ("rygel-database.vala:110: Unsupported type %s", g_type_name (t));
										g_assert_not_reached ();
									}
								}
							}
						}
					}
					if (rc != SQLITE_OK) {
						_inner_error_ = g_error_new_literal (RYGEL_DATABASE_ERROR, RYGEL_DATABASE_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
						if (_inner_error_ != NULL) {
							if (_inner_error_->domain == RYGEL_DATABASE_ERROR) {
								g_propagate_error (error, _inner_error_);
								_sqlite3_finalize0 (statement);
								return NULL;
							} else {
								_sqlite3_finalize0 (statement);
								g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
								g_clear_error (&_inner_error_);
								return NULL;
							}
						}
					}
				}
			}
		}
	}
	result = statement;
	return result;
}


void rygel_database_analyze (RygelDatabase* self) {
	g_return_if_fail (self != NULL);
	sqlite3_exec (self->priv->db, "ANALYZE", NULL, NULL, NULL);
}


void rygel_database_null (GValue* result) {
	GValue _tmp0_ = {0};
	GValue v;
	v = (g_value_init (&_tmp0_, G_TYPE_POINTER), _tmp0_);
	g_value_set_pointer (&v, NULL);
	*result = v;
	return;
}


void rygel_database_begin (RygelDatabase* self, GError** error) {
	GError * _inner_error_;
	g_return_if_fail (self != NULL);
	_inner_error_ = NULL;
	if (sqlite3_exec (self->priv->db, "BEGIN", NULL, NULL, NULL) != SQLITE_OK) {
		_inner_error_ = g_error_new_literal (RYGEL_DATABASE_ERROR, RYGEL_DATABASE_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == RYGEL_DATABASE_ERROR) {
				g_propagate_error (error, _inner_error_);
				return;
			} else {
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return;
			}
		}
	}
}


void rygel_database_commit (RygelDatabase* self, GError** error) {
	GError * _inner_error_;
	g_return_if_fail (self != NULL);
	_inner_error_ = NULL;
	if (sqlite3_exec (self->priv->db, "COMMIT", NULL, NULL, NULL) != SQLITE_OK) {
		_inner_error_ = g_error_new_literal (RYGEL_DATABASE_ERROR, RYGEL_DATABASE_ERROR_SQLITE_ERROR, sqlite3_errmsg (self->priv->db));
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == RYGEL_DATABASE_ERROR) {
				g_propagate_error (error, _inner_error_);
				return;
			} else {
				g_critical ("file %s: line %d: uncaught error: %s", __FILE__, __LINE__, _inner_error_->message);
				g_clear_error (&_inner_error_);
				return;
			}
		}
	}
}


void rygel_database_rollback (RygelDatabase* self) {
	g_return_if_fail (self != NULL);
	if (sqlite3_exec (self->priv->db, "ROLLBACK", NULL, NULL, NULL) != SQLITE_OK) {
		g_critical ("rygel-database.vala:146: Failed to rollback transaction: %s", sqlite3_errmsg (self->priv->db));
	}
}


static void rygel_database_class_init (RygelDatabaseClass * klass) {
	rygel_database_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RygelDatabasePrivate));
	G_OBJECT_CLASS (klass)->finalize = rygel_database_finalize;
}


static void rygel_database_instance_init (RygelDatabase * self) {
	self->priv = RYGEL_DATABASE_GET_PRIVATE (self);
}


static void rygel_database_finalize (GObject* obj) {
	RygelDatabase * self;
	self = RYGEL_DATABASE (obj);
	_sqlite3_close0 (self->priv->db);
	G_OBJECT_CLASS (rygel_database_parent_class)->finalize (obj);
}


GType rygel_database_get_type (void) {
	static GType rygel_database_type_id = 0;
	if (rygel_database_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelDatabaseClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_database_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelDatabase), 0, (GInstanceInitFunc) rygel_database_instance_init, NULL };
		rygel_database_type_id = g_type_register_static (G_TYPE_OBJECT, "RygelDatabase", &g_define_type_info, 0);
	}
	return rygel_database_type_id;
}



