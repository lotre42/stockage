/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 22:23:16 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/27 20:17:54 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "op.h"
# include "libft.h"
# include "ft_printf.h"

typedef struct			s_process
{
	int					carry;
	int					live;
	unsigned int		*registre;
	unsigned int		nbplayer;
	int					pc;
	int					nbcycle;
	int					tmp;
	int					last;
	struct s_process	*next;
}						t_process;

typedef struct			s_live
{
	int					nblive;
	unsigned int		lastlive;
}						t_live;

typedef struct			s_player
{
	unsigned char		*instruction;
	struct s_header		*header;
	char				*data_file;
	unsigned int		nbplayer;
	struct s_player		*next;
}						t_player;

typedef struct			s_data
{
	unsigned char		*ram;
	t_process			*process;
	unsigned int		*numberplayer;
	t_player			*players;
	int					dump;
	int					cycle;
	int					nbchecks;
	int					cycletodie;
}						t_data;

typedef struct			s_path
{
	char				*str;
	unsigned int		nb;
	struct s_path		*next;
}						t_path;

void					free_tab(unsigned int *tabtype, unsigned int *tabvalue);
int						ft_startandfree(t_path **path, t_data **data);
void					ft_freedata(t_data **data);
void					ft_freepath(t_path **path);
int						ft_add(unsigned int nb, char *str, t_path **add);
int						ft_addend(unsigned int nb, char *str, t_path **add);
int						recovery_info(t_path *path, t_data *data);
int						open_path(char *pathplayer, t_player *player,
						unsigned int x);
int						add_player_in_list(char *pathplayer,
						t_player **players, int x);
unsigned char			*create_ram(t_player *players, int nb,
						t_process *process);
int						print_ram(unsigned char *ram);
unsigned int			*init_tab(int x);
int						init_process(t_process **process, unsigned int nb);
t_process				*create_list_process(t_player *players);
unsigned int			*init_number_player(int nb, t_path *path);
int						core(t_data *data);
void					nb_of_cycle(t_process *process, unsigned char *ram);
int						mask_pc(int nb, int i);
int						call_fonction(unsigned char *ram, t_process *process,
						t_live *live, unsigned int *nbplayer);
void					ft_live(t_process *process, t_live *live,
						unsigned char *ram, unsigned int *numberplayer);
void					sti(t_process *process, unsigned char *ram);
void					and(t_process *process, unsigned char *ram);
unsigned int			*ft_downtype(t_process *process, unsigned char *ram);
unsigned int			*ft_downvalue(t_process *process, unsigned int *tabtype,
						int x, unsigned char *ram);
void					zjump(t_process *process, unsigned char *ram);
void					cpyint(unsigned char *ram, unsigned char *src, int pc);
unsigned char			*reverseint(unsigned int nb);
unsigned int			loadint(unsigned char *ram, int pc);
void					ldi(t_process *process, unsigned char *ram);
void					lld(t_process *process, unsigned char *ram);
void					lldi(t_process *process, unsigned char *ram);
void					ld(t_process *process, unsigned char *ram);
void					or(t_process *process, unsigned char *ram);
void					xor(t_process *process, unsigned char *ram);
int						ft_fork(t_process *process, unsigned char *ram);
void					sub(t_process *process, unsigned char *ram);
void					add(t_process *process, unsigned char *ram);
void					st(t_process *process, unsigned char *ram);
int						check_nb_reg(unsigned int nb);
int						lfork(t_process *process, unsigned char *ram);
void					aff(t_process *process, unsigned char *ram);
int						free_process(t_process **process);
unsigned int			*load_value(t_process *process, unsigned char *ram,
						unsigned int *type, unsigned int *val);
void					and(t_process *process, unsigned char *ram);
int						check_live_dead(t_process **process);

#endif
