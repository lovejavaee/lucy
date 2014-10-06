/* lcapplicationrow.c generated by valac 0.22.1, the Vala compiler
 * generated from lcapplicationrow.vala, do not modify */

#include <gtk/gtk.h>
#include "lcapplicationrow.h"
#include "lccommander.h"
#include "lcutil.h"

#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define ICON_SIZE       (48)
#define NAME_LABEL_WIDTH (180)
#define VERSION_LABEL_WIDTH (200)
#define TYPE_LABEL_WIDTH (120)
#define UNINSTALL_BUTTON_WIDTH  (100)

struct _LcApplicationRowPrivate {
    GtkGrid *grid;
    GtkImage *icon_image;
    GtkLabel *name_label;
    GtkLabel *version_label;
    GtkLabel *type_label;
    GtkButton *uninstall_button;

    gpointer user_data;
    GDestroyNotify destroy;
};

#define LC_APPLICATION_ROW_ICON_SIZE	(48)

#define lc_application_row_get_priv(self) ((self)->priv)
#define lc_application_row_get_icon_image(self)	((self)->priv->icon_image)
#define lc_application_row_get_name_label(self)	((self)->priv->name_label)
#define lc_application_row_get_version_label(self) \
	((self)->priv->version_label)
#define lc_application_row_get_uninstallbutton(self) \
        lc_application_row_get_priv(self)->uninstall_button
#define lc_application_row_get_type_label(self) \
        lc_application_row_get_priv(self)->type_label
#define lc_application_row_get_user_data(self) \
        lc_application_row_get_priv(self)->user_data
#define lc_application_row_set_user_data(self,data) \
        lc_application_row_get_user_data(self)=(data)
#define lc_application_row_get_destroy(self) \
        lc_application_row_get_priv(self)->destroy
#define lc_application_row_set_destroy(self,d) \
        lc_application_row_get_destroy(self)= d
#define lc_application_row_get_grid(self) \
        lc_application_row_get_priv(self)->grid


static gpointer lc_application_row_parent_class = NULL;

#define LC_APPLICATION_ROW_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_LC_APPLICATION_ROW, LcApplicationRowPrivate))
enum {
    LC_APPLICATION_ROW_DUMMY_PROPERTY
};
static void lc_application_row_finalize(GObject * obj);


LcApplicationRow *lc_application_row_construct(GType object_type)
{
    LcApplicationRow *self = NULL;
    self = (LcApplicationRow *) g_object_new(object_type, NULL);
    gtk_widget_show_all(GTK_WIDGET(self));
    return self;
}


LcApplicationRow *lc_application_row_new(void)
{
    return lc_application_row_construct(TYPE_LC_APPLICATION_ROW);
}


static void lc_application_row_class_init(LcApplicationRowClass * klass)
{
    lc_application_row_parent_class = g_type_class_peek_parent(klass);
    g_type_class_add_private(klass, sizeof(LcApplicationRowPrivate));
    G_OBJECT_CLASS(klass)->finalize = lc_application_row_finalize;
}


static void lc_application_row_instance_init(LcApplicationRow * self)
{
    self->priv = LC_APPLICATION_ROW_GET_PRIVATE(self);

    LcApplicationRowPrivate *priv = self->priv;

    priv->grid = (GtkGrid *) gtk_grid_new();
    gtk_grid_set_column_spacing(priv->grid, 8);
    gtk_container_set_border_width(GTK_CONTAINER(priv->grid), 1);
    g_object_ref_sink(priv->grid);
    /* ICON */
    priv->icon_image = (GtkImage *) gtk_image_new();
    g_object_ref_sink(priv->icon_image);
    /* NAME */
    priv->name_label = (GtkLabel *) gtk_label_new("");
    gtk_misc_set_alignment(GTK_MISC(priv->name_label), 0.0, 0.5);
    gtk_widget_set_margin_left(GTK_WIDGET(priv->name_label), 10);
    gtk_label_set_max_width_chars(priv->name_label, 20);
    gtk_widget_set_size_request(GTK_WIDGET(priv->name_label),
                                NAME_LABEL_WIDTH, -1);
    gtk_label_set_ellipsize(priv->name_label, PANGO_ELLIPSIZE_END);
    g_object_ref_sink(priv->name_label);
    /* VERSION */
    priv->version_label = (GtkLabel *) gtk_label_new("");
    gtk_misc_set_alignment(GTK_MISC(priv->version_label), 0.0, 0.5);
    gtk_label_set_max_width_chars(priv->version_label, 20);
    gtk_label_set_ellipsize(priv->version_label, PANGO_ELLIPSIZE_END);
    gtk_widget_set_margin_left(GTK_WIDGET(priv->version_label), 20);
    gtk_widget_set_size_request(GTK_WIDGET(priv->version_label),
                                VERSION_LABEL_WIDTH, -1);
    g_object_ref_sink(priv->version_label);
    /* TYPE */
    priv->type_label = (GtkLabel *) gtk_label_new("");
    gtk_widget_set_size_request(GTK_WIDGET(priv->type_label),
                                TYPE_LABEL_WIDTH, -1);
    gtk_widget_set_margin_left(GTK_WIDGET(priv->type_label), 15);
    g_object_ref_sink(priv->type_label);
    /* UNINSTALL */
    priv->uninstall_button =
        (GtkButton *) gtk_button_new_with_label("uninstall");
    gtk_widget_set_size_request(GTK_WIDGET(priv->uninstall_button),
                                UNINSTALL_BUTTON_WIDTH, -1);
    gtk_widget_set_margin_left(GTK_WIDGET(priv->uninstall_button), 10);
    g_object_ref_sink(priv->uninstall_button);

    gtk_container_add(GTK_CONTAINER(self), GTK_WIDGET(priv->grid));

    gtk_grid_attach(priv->grid, GTK_WIDGET(priv->icon_image), 0, 0, 1, 1);
    gtk_grid_attach(priv->grid, GTK_WIDGET(priv->name_label), 1, 0, 1, 1);
    gtk_grid_attach(priv->grid, GTK_WIDGET(priv->version_label),
                    2, 0, 1, 1);
    gtk_grid_attach(priv->grid, GTK_WIDGET(priv->type_label), 3, 0, 1, 1);
    gtk_grid_attach(priv->grid, GTK_WIDGET(priv->uninstall_button), 4, 0,
                    1, 1);

    priv->user_data = NULL;
    priv->destroy = NULL;
}


static void lc_application_row_finalize(GObject * obj)
{
    LcApplicationRow *self;
    self =
        G_TYPE_CHECK_INSTANCE_CAST(obj, TYPE_LC_APPLICATION_ROW,
                                   LcApplicationRow);
    _g_object_unref0(self->priv->grid);
    _g_object_unref0(self->priv->icon_image);
    _g_object_unref0(self->priv->name_label);
    _g_object_unref0(self->priv->version_label);
    _g_object_unref0(self->priv->type_label);
    _g_object_unref0(self->priv->uninstall_button);
    if (self->priv->user_data && self->priv->destroy) {
        self->priv->destroy(self->priv->user_data);
    }
    G_OBJECT_CLASS(lc_application_row_parent_class)->finalize(obj);
}


GType lc_application_row_get_type(void)
{
    static volatile gsize lc_application_row_type_id__volatile = 0;
    if (g_once_init_enter(&lc_application_row_type_id__volatile)) {
        static const GTypeInfo g_define_type_info =
            { sizeof(LcApplicationRowClass), (GBaseInitFunc) NULL,
            (GBaseFinalizeFunc) NULL,
            (GClassInitFunc) lc_application_row_class_init,
            (GClassFinalizeFunc) NULL, NULL, sizeof(LcApplicationRow), 0,
            (GInstanceInitFunc) lc_application_row_instance_init, NULL
        };
        GType lc_application_row_type_id;
        lc_application_row_type_id =
            g_type_register_static(GTK_TYPE_EVENT_BOX, "LcApplicationRow",
                                   &g_define_type_info, 0);
        g_once_init_leave(&lc_application_row_type_id__volatile,
                          lc_application_row_type_id);
    }
    return lc_application_row_type_id__volatile;
}

static void
lc_appliation_row_update_uninstall_button_visible(LcApplicationRow * self,
                                                  const gchar * type)
{
    GtkButton *uninstall_button =
        lc_application_row_get_uninstallbutton(self);
    if (g_strcmp0(type, "system") == 0) {
        gtk_widget_set_visible(GTK_WIDGET(uninstall_button), FALSE);
    } else {
        gtk_widget_set_visible(GTK_WIDGET(uninstall_button), TRUE);
    }
}

LcApplicationRow *lc_application_row_new_full(GdkPixbuf * icon,
                                              const gchar * name,
                                              const gchar * version,
                                              const gchar * type)
{
    LcApplicationRow *self = lc_application_row_new();
    GtkImage *icon_image = lc_application_row_get_icon_image(self);
    GtkLabel *name_label = lc_application_row_get_name_label(self);
    GtkLabel *version_label = lc_application_row_get_version_label(self);
    GtkLabel *type_label = lc_application_row_get_type_label(self);

    gtk_image_set_from_pixbuf(icon_image, icon);
    gtk_label_set_text(name_label, name);
    gtk_widget_set_tooltip_text(GTK_WIDGET(name_label), name);
    gtk_label_set_text(version_label, version);
    gtk_widget_set_tooltip_text(GTK_WIDGET(version_label), version);
    gtk_label_set_text(type_label, type);

    lc_appliation_row_update_uninstall_button_visible(self, type);

    return self;
}

#define SAVE_DATA_KEY "save-data"
static void on_icon_saved(GObject * file, GAsyncResult * result,
                          gpointer user_data)
{
    LcApplicationRow *self = (LcApplicationRow *) user_data;
    LcProtocolApplication *info = lc_application_row_get_user_data(self);
    gchar *data = g_object_get_data(file, SAVE_DATA_KEY);
    g_free(data);
    if (g_file_replace_contents_finish(G_FILE(file), result, NULL, NULL)) {
        GdkPixbuf *pixbuf =
            lc_util_load_pixbuf_from_cache_with_size(info->package_name,
                                                     ICON_SIZE, ICON_SIZE);
        lc_application_row_set_icon(self, pixbuf);
        g_object_unref(pixbuf);
    } else {
        g_warning("Failed to save %s", info->package_name);
    }
}

static void on_command_icon(const gchar * cmd, GByteArray * array,
                            gpointer user_data)
{
    LcApplicationRow *self = (LcApplicationRow *) user_data;
    GBytes *bytes = lc_util_get_bytes_from_byte_array(array);
    if (bytes == NULL) {
        g_warning("%s failed! Connection Problem!", cmd);
        return;
    }
    if (lc_protocol_get_result_from_bytes(bytes) !=
        LC_PROTOCOL_RESULT_OKAY) {
        g_warning("%s failed! Protocol Problem!", cmd);
        g_bytes_unref(bytes);
        return;
    }
    LcProtocolApplication *info = lc_application_row_get_user_data(self);
    const gchar *path =
        lc_util_get_image_cache_path_by_name(info->package_name);
    GFile *file = g_file_new_for_path(path);
    gsize size;
    gchar *data = g_bytes_unref_to_data(bytes, &size);
    g_file_replace_contents_async(file, data + LC_PROTOCOL_HDR_LEN,
                                  size - LC_PROTOCOL_HDR_LEN, NULL, FALSE,
                                  G_FILE_CREATE_NONE, NULL, on_icon_saved,
                                  self);
    g_object_set_data(G_OBJECT(file), SAVE_DATA_KEY, data);

    g_object_unref(file);
}

LcApplicationRow *lc_application_row_new_with_data(const
                                                   LcProtocolApplication *
                                                   info)
{
    GdkPixbuf *pixbuf =
        lc_util_load_pixbuf_from_cache_with_size(info->package_name,
                                                 ICON_SIZE, ICON_SIZE);
    gboolean icon = FALSE;
    if (pixbuf == NULL) {
        icon = TRUE;
        pixbuf =
            lc_util_load_pixbuf_from_resource_with_size(DEFAULT_ICON,
                                                        ICON_SIZE,
                                                        ICON_SIZE);
    }
    LcApplicationRow *self =
        lc_application_row_new_full(pixbuf, info->app_name, info->version,
                                    info->type);
    lc_application_row_set_data(self, lc_protocol_application_copy(info),
                                (GDestroyNotify)
                                lc_protocol_application_free);
    g_object_unref(pixbuf);
    if (icon) {
        lc_commander_send_command_async(lc_protocol_icon_command
                                        (info->package_name),
                                        on_command_icon, self);
    }
    return self;
}

void lc_application_row_update_data(LcApplicationRow * self,
                                    const LcProtocolApplication * info)
{
    lc_application_row_set_data(self, lc_protocol_application_copy(info),
                                (GDestroyNotify)
                                lc_protocol_application_free);
    GtkLabel *name_label = lc_application_row_get_name_label(self);
    GtkLabel *version_label = lc_application_row_get_version_label(self);
    GtkLabel *type_label = lc_application_row_get_type_label(self);
    gtk_label_set_label(name_label, info->app_name);
    gtk_widget_set_tooltip_text(GTK_WIDGET(name_label), info->app_name);
    gtk_label_set_label(version_label, info->version);
    gtk_widget_set_tooltip_text(GTK_WIDGET(version_label), info->version);
    gtk_label_set_label(type_label, info->type);

    lc_appliation_row_update_uninstall_button_visible(self, info->type);
}

void lc_application_row_set_data(LcApplicationRow * self, gpointer data,
                                 GDestroyNotify notify)
{
    GDestroyNotify destroy = lc_application_row_get_destroy(self);
    gpointer pdata = lc_application_row_get_user_data(self);
    if (destroy && pdata) {
        destroy(pdata);
    }
    lc_application_row_set_user_data(self, data);
    lc_application_row_set_destroy(self, notify);
}

gpointer lc_application_row_get_data(LcApplicationRow * self)
{
    return lc_application_row_get_user_data(self);
}

void lc_application_row_set_icon(LcApplicationRow * self,
                                 GdkPixbuf * pixbuf)
{
    GtkImage *image = lc_application_row_get_icon_image(self);
    gtk_image_set_from_pixbuf(image, pixbuf);
}

static GtkCssProvider *highlight_provider = NULL;
void lc_application_row_highlight(LcApplicationRow * self)
{
    if (highlight_provider == NULL) {
        highlight_provider = gtk_css_provider_new();
        gtk_css_provider_load_from_data(highlight_provider,
                                        "GtkGrid{background-color:lightblue;}",
                                        -1, NULL);
    }
    GtkStyleContext *style =
        gtk_widget_get_style_context(GTK_WIDGET
                                     (lc_application_row_get_grid(self)));
    gtk_style_context_add_provider(style,
                                   GTK_STYLE_PROVIDER(highlight_provider),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);
}

void lc_application_row_unhighlight(LcApplicationRow * self)
{
    GtkStyleContext *style =
        gtk_widget_get_style_context(GTK_WIDGET
                                     (lc_application_row_get_grid(self)));
    gtk_style_context_remove_provider(style,
                                      GTK_STYLE_PROVIDER
                                      (highlight_provider));
}

GtkButton *lc_application_row_get_uninstall_button(LcApplicationRow * self)
{
    return lc_application_row_get_uninstallbutton(self);
}
