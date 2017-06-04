/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 16:31:06 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/04 04:59:51 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static int	cpstok(t_stock *new, t_stock *tmp, int nb)
{
	int i;

	i = 0;
	new->nbplayer = tmp->nbplayer;
	// new->ram = tmp->ram;
	new->carry = tmp->carry;
	new->pc = pluspc(tmp->pc, nb);
	new->cycle = 0;
	new->kill = 0;
	new->registre = ft_inittab(16);
	while (i < 16)
	{
		new->registre[i] = tmp->registre[i];
		i++;
	}
	return (1);
}

static int	cpplayer(t_player *new, t_player *tmp)
{
	new->totalplayer = NULL;
	new->magicplayer = NULL;
	new->nameplayer = ft_strdup(tmp->nameplayer);
	new->comentplayer = NULL;
	new->instplayer = NULL;
	new->sizeplayer = tmp->sizeplayer;
	new->sizetotal = tmp->sizetotal;
	new->c = 0;
	if (!(new->stok = malloc(sizeof(t_stock))))
		return (0);
	return (1);
}

int			ft_fork(t_player *player)
{
	t_player *new;
	t_player *tmp;
	int 	nb;

	tmp = player;
	if (!(new = malloc(sizeof(t_player))))
	  return (0);	
	cpplayer(new, tmp);
	nb = ((tmp->stok->ram[pluspc(tmp->stok->pc, 1)] << 8) & 0xff00) |
	((tmp->stok->ram[pluspc(tmp->stok->pc, 2)]) & 0x00ff);
	cpstok(new->stok, tmp->stok, nb);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	player->stok->pc = pluspc(player->stok->pc, 3);
}
