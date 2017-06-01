/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 22:23:16 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/30 09:02:53 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
# include "../libft/includes/libft.h"

typedef struct			s_stock
{
	char				*ram;
	int 				carry;
	unsigned int		*registre;
	int					pc;
	int                 cycle;
}						t_stock;

typedef struct			s_player
{
	char				*totalplayer;
	char 				*magicplayer;
	char				*nameplayer;
	char				*comentplayer;
	char				*instplayer;
	int					sizeplayer;
	int					sizetotal;
	int                 c;
	struct s_player		*next;
	struct s_stock		*stok;
}						t_player;

int						pluspc(int pc, int i);
void					ld(t_stock *info);
void					lld(t_stock *info);
void					ldi(t_stock *info);
void					lldi(t_stock *info);
void					add(t_stock *info);
void					add(t_stock *info);
void					ft_and(t_stock *info);
int						*ft_downtype(t_stock *info);
int						*ft_downvalue(t_stock *info, int *tabtype, int x);
int						*ft_inittab(int x);
void					or(t_stock *info);
void					st(t_stock *info);
void					sti(t_stock *info);
void					sub(t_stock *info);
void					xor(t_stock *info);
void					zjump(t_stock *info);
void					opencor(char *argv, t_player *player);
int						infoplayer(t_player *player);
int						addlist(char *argv, t_player **add);
char					*createram(t_player *player, int nb);
void					diplayplayer(char *str, int i);
void					ft_initplayer(t_player *player, char *ram);
int						ft_core(t_player *player, char *ram);
void					live(t_stock *info, int *liv);
t_player				*ft_initplay(t_player *player);
int						nbplayer(t_player *player);
void					nbofcycle(t_player *player);


#endif
