/* amlmainwindow.c generated by valac 0.20.1, the Vala compiler
 * generated from amlmainwindow.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include "amlmainwindow.h"
#include "amlapplicationview.h"
#include "amlaboutdialog.h"

#define MAINWINDOW_TITLE "Android Manager"

#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define AML_MAIN_WINDOW_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_AML_MAIN_WINDOW, AmlMainWindowPrivate))

static gpointer aml_main_window_parent_class = NULL;

static void aml_main_window_finalize(GObject * obj);

/* 创建菜单栏 */
static GtkWidget *aml_main_window_menu_bar(AmlMainWindow * self);
/* 创建主界面上的GtkStack */
static GtkWidget *aml_main_window_stack_with_switcher(AmlMainWindow *
                                                      self);
static void onAboutMenuItemActivate(GtkMenuItem * item, gpointer data);

enum {
    AML_MAIN_WINDOW_DUMMY_PROPERTY
};

struct _AmlMainWindowPrivate {
    AmlApplicationView *appView;
    GtkStack *rootStack;        /* 根容器，包括正常显示的界面以及，出错界面 */
    GtkStack *contentStack;     /* 正常显示的界面容器 */
};


AmlMainWindow *aml_main_window_construct(GType object_type)
{
    AmlMainWindow *self = NULL;
    self = (AmlMainWindow *) g_object_new(object_type, NULL);
    return self;
}


AmlMainWindow *aml_main_window_new(void)
{
    return aml_main_window_construct(TYPE_AML_MAIN_WINDOW);
}


static void aml_main_window_class_init(AmlMainWindowClass * klass)
{
    aml_main_window_parent_class = g_type_class_peek_parent(klass);
    g_type_class_add_private(klass, sizeof(AmlMainWindowPrivate));
    G_OBJECT_CLASS(klass)->finalize = aml_main_window_finalize;
}


static void aml_main_window_instance_init(AmlMainWindow * self)
{
    self->priv = AML_MAIN_WINDOW_GET_PRIVATE(self);

    gtk_window_set_default_size(GTK_WINDOW(self), 960, 640);
    gtk_window_set_position(GTK_WINDOW(self), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(self), MAINWINDOW_TITLE);
    g_signal_connect(G_OBJECT(self), "destroy",
                     G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *rootBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(self), rootBox);

    gtk_box_pack_start(GTK_BOX(rootBox), aml_main_window_menu_bar(self),
                       FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(rootBox),
                       aml_main_window_stack_with_switcher(self), TRUE,
                       TRUE, 0);
}

static void aml_main_window_finalize(GObject * obj)
{
    AmlMainWindow *self =
        G_TYPE_CHECK_INSTANCE_CAST(obj, TYPE_AML_MAIN_WINDOW,
                                   AmlMainWindow);
    _g_object_unref0(self->priv->appView);
    _g_object_unref0(self->priv->rootStack);
    _g_object_unref0(self->priv->contentStack);
    G_OBJECT_CLASS(aml_main_window_parent_class)->finalize(obj);
}


GType aml_main_window_get_type(void)
{
    static volatile gsize aml_main_window_type_id__volatile = 0;
    if (g_once_init_enter(&aml_main_window_type_id__volatile)) {
        static const GTypeInfo g_define_type_info =
            { sizeof(AmlMainWindowClass), (GBaseInitFunc) NULL,
            (GBaseFinalizeFunc) NULL,
                (GClassInitFunc) aml_main_window_class_init,
                (GClassFinalizeFunc) NULL,
            NULL, sizeof(AmlMainWindow), 0,
                (GInstanceInitFunc) aml_main_window_instance_init, NULL
        };
        GType aml_main_window_type_id;
        aml_main_window_type_id =
            g_type_register_static(GTK_TYPE_WINDOW, "AmlMainWindow",
                                   &g_define_type_info, 0);
        g_once_init_leave(&aml_main_window_type_id__volatile,
                          aml_main_window_type_id);
    }
    return aml_main_window_type_id__volatile;
}

/*创建菜单栏*/
static GtkWidget *aml_main_window_menu_bar(AmlMainWindow * self)
{
    GtkWidget *menuBar = gtk_menu_bar_new();
    GtkWidget *aboutItem = gtk_menu_item_new_with_mnemonic("_About");
    gtk_menu_shell_append(GTK_MENU_SHELL(menuBar), aboutItem);

    GtkWidget *aboutMenu = gtk_menu_new();
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(aboutItem), aboutMenu);

    GtkWidget *_aboutItem = gtk_menu_item_new_with_mnemonic("_About");
    gtk_menu_shell_append(GTK_MENU_SHELL(aboutMenu), _aboutItem);
    g_signal_connect(G_OBJECT(_aboutItem), "activate",
                     G_CALLBACK(onAboutMenuItemActivate), NULL);

    return menuBar;
}

/*About菜单项激活后的回调函数*/
static void onAboutMenuItemActivate(GtkMenuItem * item, gpointer data)
{
    AmlAboutDialog *dialog = aml_about_dialog_new();
    aml_about_dialog_run(dialog);
    aml_about_dialog_destroy(dialog);
}

static GtkWidget *aml_main_window_stack_with_switcher(AmlMainWindow * self)
{
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    GtkWidget *stack = gtk_stack_new();
    GtkWidget *switcher = gtk_stack_switcher_new();
    gtk_stack_switcher_set_stack(GTK_STACK_SWITCHER(switcher),
                                 GTK_STACK(stack));

    gtk_container_set_border_width(GTK_CONTAINER(box), 10);
    gtk_box_pack_start(GTK_BOX(box), switcher, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), stack, TRUE, TRUE, 0);

    gtk_stack_set_transition_duration(GTK_STACK(stack), 500);
    gtk_stack_set_transition_type(GTK_STACK(stack),
                                  GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT_RIGHT);
    /* TODO */
    AmlApplicationView *app = aml_application_view_new();
    gtk_stack_add_titled(GTK_STACK(stack), GTK_WIDGET(app), "app",
                         "Applications");
    GtkWidget *sms = gtk_label_new("SMS");
    gtk_stack_add_titled(GTK_STACK(stack), sms, "sms", "SMS");

    GtkWidget *rootStack = gtk_stack_new();
    gtk_stack_add_named(GTK_STACK(rootStack), box, "connected");
    GtkWidget *dc = gtk_label_new("Disconnected");
    gtk_stack_add_named(GTK_STACK(rootStack), dc, "disconnected");

    gtk_widget_show_all(box);
    gtk_widget_show_all(dc);

    self->priv->appView = app;
    self->priv->rootStack = GTK_STACK(rootStack);
    self->priv->contentStack = GTK_STACK(stack);
    g_object_ref_sink(self->priv->rootStack);
    g_object_ref_sink(self->priv->contentStack);
    g_object_ref_sink(self->priv->appView);

    return rootStack;
}

void aml_main_window_show(AmlMainWindow * window)
{
    gtk_widget_show_all(GTK_WIDGET(window));
    gtk_main();
}
