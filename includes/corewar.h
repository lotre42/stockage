/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 22:23:16 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/04 07:01:02 by kahantar         ###   ########.fr       */
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

#define CYCLE_TO_DIE			1536
#define CYCLE_DELTA				50
#define NBR_LIVE				21
#define MAX_CHECKS				10
#define MAX_ARGS_NUMBER			4
#define MAX_PLAYERS				4
#define MEM_SIZE				(4*1024)
#define IDX_MOD					(MEM_SIZE / 8)
#define CHAMP_MAX_SIZE			(MEM_SIZE / 6)
# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3
#define REG_NUMBER				16

typedef struct			s_stock
{
	int 				carry;
	unsigned int		*registre;
	int					pc;
	int                 cycle;
	int					kill;
	int					nbplayer;
	int					quantity;
}						t_stock;

typedef struct			s_live
{
	int					nbplayer;
	int					nblive;
	int 				nbliveplayer;
	int 				dead;
	int					lastlive;
	struct s_live		*next;
}						t_live;

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
void					checkwinner(t_player *player, t_live *live);
int						searchfunction(t_player *player, t_live *live, char *ram);
t_live 					*ft_addlive(t_player *player);
void					ft_initregistre(t_player *player);
void					ld(t_stock *info, char *ram);
void					lld(t_stock *info, char *ram);
void					ldi(t_stock *info, char *ram);
void					lldi(t_stock *info, char *ram);
void					add(t_stock *info, char *ram);
void					add(t_stock *info, char *ram);
void					ft_and(t_stock *info, char *ram);
int						*ft_downtype(t_stock *info, char *ram);
unsigned int			*ft_inittab(int x);
void					or(t_stock *info, char *ram);
void					st(t_stock *info, char *ram);
void					sti(t_stock *info, char *ram);
void					sub(t_stock *info, char *ram);
void					xor(t_stock *info, char *ram);
void					zjump(t_stock *info, char *ram);
void					opencor(char *argv, t_player *player);
int						infoplayer(t_player *player);
int						addlist(char *argv, t_player **add);
char					*createram(t_player *player, int nb);
void					diplayplayer(char *str, int i);
void					ft_initplayer(t_player *player, char *ram);
int						ft_core(t_player *player, char *ram);
void					ft_live(t_stock *info, t_live *live, char *ram);
t_player				*ft_initplay(t_player *player);
int						nbplayer(t_player *player);
void					nbofcycle(t_player *player, char *ram);
char					*reverseint(unsigned nb);
void					initcycle(t_live *live);
int						checkdead(t_live *live);
int						checkdelta(t_live *live);
int						ft_fork(t_player *player, char *ram);
int						checkkill(t_player *player);
void					cpyint(char *ram, char *src, int pc);
void					killplayer(t_player *player, t_live *live);
int  					gestion(t_player *player, char *ram);
int						*ft_downvalue(t_stock *info, int *tabtype, int x, char *ram);

#endif
