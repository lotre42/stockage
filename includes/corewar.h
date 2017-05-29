/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 22:23:16 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/29 09:34:38 by kahantar         ###   ########.fr       */
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
	struct s_player		*next;
}						t_player;

void					ld(t_stock *info, int pc);
void					ldi(t_stock *info, int pc);
void					add(t_stock *info, int pc);
void					add(t_stock *info, int pc);
void					ft_and(t_stock *info, int pc);
int						*ft_downtype(t_stock *info, int pc);
int						*ft_downvalue(t_stock *info, int *tabtype, int pc, int x);
int						*ft_inittab(int x);
void					or(t_stock *info, int pc);
void					st(t_stock *info, int pc);
void					sti(t_stock *info, int pc);
void					sub(t_stock *info, int pc);
void					xor(t_stock *info, int pc);
void					zjump(t_stock *info, int pc);
void					opencor(char *argv, t_player *player);
int						infoplayer(t_player *player);
int						addlist(char *argv, t_player **add);
char					*createram(t_player *player, int nb);

#endif
