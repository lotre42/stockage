# include <gtk/gtk.h>
# include <gdk/gdk.h>
# include <gio/gio.h>
# include <gdk/gdkkeysyms.h>
# include <gdk-pixbuf/gdk-pixbuf.h>
# include <gtkosxapplication.h>
# include <stdlib.h>
# include <fcntl.h>
# include "op.h"
# include "vm.h"
# define BUFF_SIZE 1
# define DARK_THEME "gtk-application-prefer-dark-theme"
# define WIN		data->gtk.window
# define GWIN		GTK_WINDOW(data->gtk.window)

typedef struct			s_gtk
{
	GtkWidget			*window;
	GtkWidget			*grid;
	GtkWidget			*menu_bar;
	GtkWidget			*play;
	GtkWidget			*pause;
	GtkFileFilter 		*filter_core;
}						t_gtk;

typedef struct			s_gtk_player
{
	GtkWidget			*b_select;
	GtkWidget			*b_color;
	GdkRGBA				color;
	char				*path;
}						t_gtk_player;

typedef struct			s_img
{
	GtkWidget			*image;
	GtkWidget			*box_img;
	GdkPixbuf			*pix;
	int					width;
	int					height;
	int					rowstride;
	int					n_channels;
	int					cell_width;
	int					cell_height;
}						t_img;

typedef struct			s_maps
{
	unsigned char		maps_color[MEM_SIZE];
	unsigned char		maps_hexa[MEM_SIZE];
}						t_maps;

typedef struct			s_data
{
	t_gtk				gtk;
	
	t_gtk_player		player[MAX_PLAYERS];
	t_img				img;
	t_maps				maps;
	int					win_size_width;
	int					win_size_height;
}						t_data;



/*
** main fonction
*/
void		gtk_main_quit2(GtkWidget *window, t_data *data);

/*
** libft
*/

void	ft_bzero(void *s, int n);
char	*ft_itoa(int n);
void	*ft_memalloc(size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
void	ft_memdel(void **ap);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnew(size_t size);
int		get_next_line(int const fd, char **line);

/*
** ui / tool bar
*/

void		ft_about(t_data *data);
void		ft_theme(int i);
void		ft_help_menu(GtkWidget *help_menu, t_data *data);
GtkWidget	*tool_bar(t_data *data);
void		menu_response(GtkWidget *menu_item, t_data *data);

/*
** ui / menu right
*/

void		menu_right(t_data *data);
GtkWidget	*params_game(t_data *data);
GtkWidget	*params_player(t_data *data);

/*
** ui / menu right callback
*/
void		call_back_play(GtkButton *widget, t_data *data);
void		set_color(GtkButton *widget,  t_gtk_player *player);
void		set_file(GtkButton *widget, t_gtk_player *player);

/*
** ui / image corewar
*/
void		image_update(t_data *data);
void		image_corewar(t_data *data);
void		image_update_size(t_data *data);
void		put_cell(int i, GdkRGBA color, t_data *data);
void 		put_pixel(t_data *data, int x, int y, GdkRGBA color);

/*
**
*/
int 		recovery_info(t_data *data);
int			open_path(char *pathplayer, t_player *player);
int			add_player_in_list(char *pathplayer, t_player **players);
char		*create_ram(t_player *players, int nb);



