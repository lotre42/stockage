#include "corewar.h"

void		ft_help_menu(GtkWidget *help_menu, t_data *data)
{
	GtkWidget *menu_item;

	menu_item = gtk_menu_item_new_with_label("About");
	gtk_menu_shell_append(GTK_MENU_SHELL(help_menu), menu_item);
	g_signal_connect(menu_item, "activate", G_CALLBACK(menu_response), data);
}
