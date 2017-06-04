/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_man.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 06:32:35 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/04 07:19:34 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void gestioncycle(t_player *player, t_live *live)
{
	int cycle;
	int cycletodie;
	int cycledelta;
	t_player *tmp;

	tmp = player;
	cycledelta = 50;
	cycletodie = 1536;
	cycle = 0;
	while (cycle < 75)
	{
		ft_putnbr(cycle);
		ft_putendl("");
		if (player->c == 0)
		{
			nbofcycle(player);
			player->c = 1;
		}
		if (player->stok->cycle == 0)
		{
			searchfunction(player, live);
			player->c = 0;
		}
		else
			player->stok->cycle--;
		player = player->next;
		if (!player)
		{
			player = tmp;
			cycle++;
		}
	}
}

int  gestion(t_player *player)
{
	t_live *live;

	ft_initregistre(player);
	live = ft_addlive(player);
	gestioncycle(player, live);
	return (1);
}
