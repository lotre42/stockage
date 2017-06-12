#include "corewar.h"

void		ft_theme(int i)
{
	if (i == 0)
		g_object_set(gtk_settings_get_default(),
			"gtk-application-prefer-dark-theme", FALSE, NULL);
	else if (i == 1)
		g_object_set(gtk_settings_get_default(),
			"gtk-application-prefer-dark-theme", TRUE, NULL);
}