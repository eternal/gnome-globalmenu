#ifndef __APPLICATION_H_
#define __APPLICATION_H_
#include "menuserver.h"

G_BEGIN_DECLS

typedef struct _Application Application;
typedef struct _ApplicationClass ApplicationClass;

#define TYPE_APPLICATION	(application_get_type())
#define APPLICATION(obj)	(G_TYPE_CHECK_INSTANCE_CAST((obj), TYPE_APPLICATION, Application))
#define APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), TYPE_APPLICATION, ApplicationClass))
#define IS_APPLICATION(obj)	(G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_APPLICATION))
#define IS_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_APPLICATION))
#define APPLICATION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), TYPE_APPLICATION, ApplicationClass))


struct _Application
{
	GObject parent;
	GtkContainer * window;
	GtkFixed * menu_bar_area;
	GtkWidget * title;
	GtkWidget * icon;
	MenuServer * server;
	GtkPixmap * bgpixmap;
	GdkColor * bgcolor;
	gboolean show_title;
	gboolean show_icon;
};

struct _ApplicationClass {
	GObjectClass parent_class;
	void (*update_ui)(Application *app);
	void (*load_conf)(Application *app);
	void (*save_conf)(Application *app);
	void (*conf_changed)(Application *app); /*emited if configure is changed. not implemented yet*/
};

GType application_get_type(void);

void application_set_background(Application * app, GdkColor * color, GdkPixmap * pixmap);
void application_update_ui(Application *app);
void application_load_conf(Application *app);
void application_save_conf(Application *app);

G_END_DECLS
#endif
/*
vim:ts=4:sw=4
*/