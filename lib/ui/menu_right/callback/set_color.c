#include "corewar.h"

void			set_color(GtkButton *widget, t_gtk_player *player)
{
	gtk_color_chooser_get_rgba(GTK_COLOR_CHOOSER(widget), &player->color);
}