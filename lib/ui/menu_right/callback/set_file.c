#include "corewar.h"

void			set_file(GtkButton *widget, t_gtk_player *player)
{
	player->path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(widget));
}