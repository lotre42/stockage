#include "corewar.h"

void	menu_right(t_data *data)
{
	GtkWidget *box_right;

	box_right = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);
	gtk_box_pack_start(GTK_BOX(box_right), params_player(data), 2, 1, 1);
	gtk_box_pack_start(GTK_BOX(box_right), params_game(data), 1, 1, 1);
	gtk_widget_set_hexpand(box_right, FALSE);
	gtk_grid_attach(GTK_GRID(data->gtk.grid), box_right, 1, 1, 1, 1);
}