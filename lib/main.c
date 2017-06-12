#include "corewar.h"

void		gtk_main_quit2(GtkWidget *window, t_data *data)
{
	(void)data; // add fonction free
	(void)window;
	gtk_main_quit();
}

void		ft_init_grid(t_data *data)
{
	data->gtk.grid = gtk_grid_new();
	data->gtk.menu_bar = tool_bar(data);
	image_corewar(data);
	menu_right(data);
	gtk_container_add(GTK_CONTAINER(data->gtk.window), data->gtk.grid);
}


static void	macos_custom(GtkosxApplication *the_app, GtkWidget *menu_bar)
{
	gtk_widget_hide(menu_bar);
	gtkosx_application_set_menu_bar(the_app, GTK_MENU_SHELL(menu_bar));
	gtkosx_application_set_use_quartz_accelerators(the_app, TRUE);
	gtkosx_application_ready(the_app);
	gtkosx_application_sync_menubar(the_app);
}

static t_data	*initialization()
{
	t_data		*data;

	if ((data = (t_data *)ft_memalloc(sizeof(t_data))) == NULL)
	{
		printf("Out of memory\n");
		exit(-1);
	}
	data->gtk.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GWIN, "COREWAR");
	gtk_window_set_position(GWIN, GTK_WIN_POS_CENTER);
	return(data);
}
static gboolean szalloccallback (GtkWidget *w, GtkAllocation *a, t_data *data)
{
	(void)w;
	if (data->win_size_width != a->width || data->win_size_height != a->height)
	{
		printf ( " szalloc (x,y)=(%d,%d) (w,h)=(%d,%d)\n" , a->x, a->y, a->width , a->height);
		image_update_size(data);
		data->win_size_width = a->width;
		data->win_size_height = a->height;
		image_update(data);
		
	}
	return (0);
}

int			main(int argc, char *argv[])
{
	GError				**err;
	GtkosxApplication	*the_app;
	t_data				*data;
	GtkWidget			*icon;
	GdkPixbuf			*pixbuf;

	err = NULL;
	gtk_init(&argc, &argv);
	the_app = (GtkosxApplication *)g_object_new(GTKOSX_TYPE_APPLICATION, NULL);
	gtk_window_set_default_icon_from_file("./resources/corewar.png", err);
	icon = gtk_image_new_from_file("./resources/corewar.png");
	pixbuf = gtk_image_get_pixbuf(GTK_IMAGE(icon));
	gtkosx_application_set_dock_icon_pixbuf(the_app, pixbuf);
	gtk_init(&argc, &argv);
	g_object_set(gtk_settings_get_default(), DARK_THEME, TRUE, NULL);
	data = initialization();
	g_signal_connect(WIN, "destroy", G_CALLBACK(gtk_main_quit2), data);
	g_signal_connect(WIN, "size-allocate", G_CALLBACK(szalloccallback), data);
	ft_init_grid(data);
	gtk_window_set_keep_above(GWIN, TRUE);
	gtk_widget_show_all(data->gtk.window);
	macos_custom(the_app, data->gtk.menu_bar);
	image_update(data);
	gtk_main();
	return (1);
}
