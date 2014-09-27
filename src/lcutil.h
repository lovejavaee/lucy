/*
 * lcutil.h
 *
 * Copyright (C) 2014 - Wiky L
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
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __LC_UTIL_H__
#define __LC_UTIL_H__

#include <gtk/gtk.h>
#include "lcprotocol.h"

void lc_init(int argc, char *argv[]);

/*
 * get the string data from GByteArray.
 * '\0' is appended to the last of GByteArray to terminal the string
 *
 * return NULL if array is NULL.
 * And if non-NULL is returned, it must be freed by g_free()
 */
gchar *lc_util_get_string_from_byte_array(GByteArray * array,
                                          gsize * size);

/*
 * apply specified CSS resource file to widget.
 */
void lc_util_load_css(GtkWidget * widget, const gchar * name);

/*
 * return the absolute path of resource file .
 * if not found, NULL is returned.
 * the return string is in static memory and should not be freed.
 */
const gchar *lc_util_get_resource_by_name(const gchar * name);


typedef gboolean(*GListElementNotify) (gconstpointer data,
                                       gpointer user_data);
/*
 * remove all elements in a list that meet specified condition.
 * judge is used to decide if an element should be removed or not.
 * if judge(element,user_data) returns TRUE then it is removed.
 */
GList *lc_util_clean_list_by(GList * list, GListElementNotify judge,
                             gpointer user_data, GDestroyNotify destroy);

#endif