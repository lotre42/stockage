#include "corewar.h"
#define G_AD GTK_ABOUT_DIALOG(ad)

void		ft_about(t_data *data)
{
	GtkWidget		*ad;
	static gchar	*authors[3] = {"Sofine Rabah, " "BITCOIM, "
	"KM, " "PAT" };
	static gchar	*git[3] = {"z1nz, " "BITCOIN, " "KM, ""PAT"};

	ad = gtk_about_dialog_new();
	gtk_window_set_transient_for(GTK_WINDOW(ad), GWIN);
	gtk_about_dialog_set_logo_icon_name(G_AD, NULL);
	gtk_about_dialog_set_version(G_AD, "1.0");
	gtk_about_dialog_set_comments(G_AD, "C’est quoi, le Corewar ? Le Corewar e\
	st un jeu très particulier. Il consiste à rassembler autour d’une \"ma- chi\
	ne virtuelle\" des \"joueurs\", lesquels vont y charger des \"champions\" qui v\
	ont se battre à l’aide de \"processus\", dans le but, entre autres, de faire\
	 en sorte qu’on dise d’eux qu’ils sont \"en vie\". Les processus s’exécutent\
	  séquentiellement au sein de la même machine virtuelle, et du même espace\
	 mémoire. Ils peuvent donc, entre autre chose, s’écrire les uns sur les au\
	 tres afin de se corrompre mutuellement, de forcer les autres à exécuter d\
	 es instructions qui leur font du mal, de tenter de recréer à la volée l’é\
	 quivalent logiciel d’un Côtes du Rhône 1982, etc ... Le jeu se termine qu\
	 and plus aucun processus n’est en vie. À ce moment là, le gagnant est le \
	 dernier joueur à avoir été rapporté comme étant \"en vie\".");
	gtk_about_dialog_set_website(G_AD, "http://www.42.fr");
	gtk_about_dialog_set_program_name(G_AD, "Corewar");
	gtk_about_dialog_set_copyright(G_AD, "copyright 2017-2017 no_name_team");
	gtk_about_dialog_set_license_type(G_AD, GTK_LICENSE_GPL_3_0);
	gtk_about_dialog_set_authors(G_AD, (const char**)authors);
	gtk_about_dialog_add_credit_section(G_AD, "Github", (const char**)git);
	gtk_dialog_run(GTK_DIALOG(ad));
	gtk_widget_destroy(ad);
}
