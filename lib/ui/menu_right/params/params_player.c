#include "corewar.h"

static GtkWidget	*label_name(int i)
{
	GtkWidget		*label;

	if (i == 0)
		label = gtk_label_new("player 1 ");
	else if (i == 1)
		label = gtk_label_new("player 2 ");
	else if (i == 2)
		label = gtk_label_new("player 3 ");
	else if (i == 3)
		label = gtk_label_new("player 4 ");
	else
		label = gtk_label_new("player ? ");
	return(label);
}

GtkWidget	*params_player(t_data *data)
{
	GtkWidget		*grid;
	GtkWidget		*label;
	int				i;


	grid = gtk_grid_new();
	data->gtk.filter_core = gtk_file_filter_new();
	gtk_file_filter_add_pattern(data->gtk.filter_core, "*.cor");

	data->player[0].color.red = 255; 
	data->player[0].color.alpha = 255; 
	data->player[1].color.green = 255;
	data->player[1].color.alpha = 255; 
	data->player[2].color.blue = 255;
	data->player[2].color.alpha = 255;
	data->player[3].color.red = 100;
	data->player[3].color.alpha = 255;

	i = 0;
	while(i < MAX_PLAYERS)
	{
		label = label_name(i);
		gtk_grid_attach(GTK_GRID(grid), label, 0, i, 1, 1);
		data->player[i].b_select =  gtk_file_chooser_button_new (("Select a file"), GTK_FILE_CHOOSER_ACTION_OPEN);
		gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(data->player[i].b_select), data->gtk.filter_core);
		gtk_grid_attach(GTK_GRID(grid), data->player[i].b_select, 1, i, 1, 1);
		g_signal_connect(data->player[i].b_select, "file-set", G_CALLBACK(set_file), &(data->player[i]));
		data->player[i].b_color = gtk_color_button_new_with_rgba (&(data->player[i].color));
		g_signal_connect(data->player[i].b_color, "color-set", G_CALLBACK(set_color), &data->player[i]);
		gtk_grid_attach(GTK_GRID(grid), data->player[i].b_color, 2, i, 1, 1);
		i++;
	}
	return (grid);
}