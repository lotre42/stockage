/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initplayer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 05:31:07 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/03 00:14:23 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static int	countplayer(t_player *player)
{
	int i;

	i = 0;
	while (player)
	{
		player = player->next;
		i++;
	}
	return (i);
}

void		ft_initplayer(t_player *player, char *ram)
{
	int i;
	int x;
	int pc;

	i = 0;
	x = countplayer(player);
	pc = 4096 / x;
	while (player)
	{
		player->stok = malloc(sizeof(t_stock));
		player->stok->ram = ram;
		player->stok->carry = 0;
		player->stok->registre = ft_inittab(16);
		player->stok->pc = pc * i;
		player->stok->cycle = 0;
		player->stok->kill = 0;
		player->stok->nbplayer = 0;
		i++;
		player = player->next;
	}
}
