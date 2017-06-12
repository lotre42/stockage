#include "corewar.h"

void			call_back_play(GtkButton *widget, t_data *data)
{
	(void)widget;
	data->player[0].path = "/Users/mac/Documents/ressourceadam/Ressources/champs/examples/bigzork.cor";
	data->player[1].path = "/Users/mac/Documents/ressourceadam/Ressources/champs/examples/bigzork.cor";

	ft_putstr("start\n");
	recovery_info(data);
	ft_putstr("fini\n");
}