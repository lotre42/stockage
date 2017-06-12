#include "corewar.h"


GtkWidget	*params_game(t_data *data)
{
	GtkWidget		*grid;
	GtkWidget		*label;

	(void)data;
	grid = gtk_grid_new();
	label = gtk_button_new_from_icon_name ("camera-photo", GTK_ICON_SIZE_DND);

	gtk_button_new();
	gtk_container_add(GTK_CONTAINER(grid), label);
	// spin speed
	// cycle int 
	// score des joueur
	// prosses int 
	// add changement entre cellule et text dans la map;
	data->gtk.play = gtk_button_new_with_label ("Play");
	g_signal_connect(data->gtk.play, "clicked", G_CALLBACK(call_back_play), &data);
	data->gtk.pause = gtk_button_new_with_label ("Pause");
	gtk_container_add(GTK_CONTAINER(grid), data->gtk.play);
	gtk_container_add(GTK_CONTAINER(grid), data->gtk.pause );
	return (grid);
}