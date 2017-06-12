#include "corewar.h"

#define G_MENU_I GTK_MENU_ITEM(menu_item)

void			menu_response(GtkWidget *menu_item, t_data *data)
{
	// if (ft_strcmp(gtk_menu_item_get_label(G_MENU_I), "open file") == 0)
	// 	ft_open_file(data);
	// if (ft_strcmp(gtk_menu_item_get_label(G_MENU_I), "save") == 0)
	// 	ft_save_file(data);
	// if (ft_strcmp(gtk_menu_item_get_label(G_MENU_I), "save image as") == 0)
	// 	ft_save_img_as(data);
	// if (ft_strcmp(gtk_menu_item_get_label(G_MENU_I), "save image") == 0)
	// 	ft_save_img(data);
	// if (ft_strcmp(gtk_menu_item_get_label(G_MENU_I), "record video") == 0)
	// 	ft_record_video(data);
	if (ft_strcmp(gtk_menu_item_get_label(G_MENU_I), "Exit") == 0)
		gtk_main_quit2(data->gtk.window, data);
	if (ft_strcmp(gtk_menu_item_get_label(G_MENU_I), "About") == 0)
		ft_about(data);
	if (ft_strcmp(gtk_menu_item_get_label(G_MENU_I), "default") == 0)
		ft_theme(0);
	if (ft_strcmp(gtk_menu_item_get_label(G_MENU_I), "default dark") == 0)
		ft_theme(1);
}

static void		ft_bar_menu(GtkWidget *menu_bar,
		GtkWidget *file_menu, GtkWidget *theme, GtkWidget *help_menu)
{
	GtkWidget *menu_item;

	menu_item = gtk_menu_item_new_with_label("File");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), file_menu);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item);
	menu_item = gtk_menu_item_new_with_label("Theme");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), theme);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item);
	menu_item = gtk_menu_item_new_with_label("Help");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), help_menu);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item);
}

static void		ft_theme_menu(GtkWidget *theme)
{
	GtkWidget *menu_item;

	menu_item = gtk_menu_item_new_with_label("default");
	gtk_menu_shell_append(GTK_MENU_SHELL(theme), menu_item);
	g_signal_connect(menu_item, "activate", G_CALLBACK(menu_response), NULL);
	menu_item = gtk_menu_item_new_with_label("default dark");
	gtk_menu_shell_append(GTK_MENU_SHELL(theme), menu_item);
	g_signal_connect(menu_item, "activate", G_CALLBACK(menu_response), NULL);
}

static void		ft_file_menu(GtkWidget *file_menu, t_data *data)
{
	GtkWidget *menu_item;

	menu_item = gtk_menu_item_new_with_label("open file");
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), menu_item);
	g_signal_connect(menu_item, "activate", G_CALLBACK(menu_response), data);
	menu_item = gtk_menu_item_new_with_label("save");
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), menu_item);
	g_signal_connect(menu_item, "activate", G_CALLBACK(menu_response), data);
	menu_item = gtk_menu_item_new_with_label("save image");
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), menu_item);
	g_signal_connect(menu_item, "activate", G_CALLBACK(menu_response), data);
	menu_item = gtk_menu_item_new_with_label("save image as");
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), menu_item);
	g_signal_connect(menu_item, "activate", G_CALLBACK(menu_response), data);
	menu_item = gtk_menu_item_new_with_label("record video");
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), menu_item);
	g_signal_connect(menu_item, "activate", G_CALLBACK(menu_response), data);
	menu_item = gtk_menu_item_new_with_label("Exit");
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), menu_item);
	g_signal_connect(menu_item, "activate", G_CALLBACK(menu_response), NULL);
}

GtkWidget		*tool_bar(t_data *data)
{
	GtkWidget *menu_bar;
	GtkWidget *file_menu;
	GtkWidget *help_menu;
	GtkWidget *theme;

	menu_bar = gtk_menu_bar_new();
	file_menu = gtk_menu_new();
	help_menu = gtk_menu_new();
	theme = gtk_menu_new();
	// vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);
	ft_bar_menu(menu_bar, file_menu, theme, help_menu);
	ft_theme_menu(theme);
	ft_file_menu(file_menu, data);
	ft_help_menu(help_menu, data);
	gtk_widget_hide(menu_bar);
	gtk_grid_attach(GTK_GRID(data->gtk.grid), menu_bar, 0, 0, 1, 1);
	return (menu_bar);
}