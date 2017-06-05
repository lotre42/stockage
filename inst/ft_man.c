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

static int	ft_dead(t_player *player, t_live *live, int *cycle, int *cycletodie, int *x)
{
	if (*cycle >= *cycletodie)
			{
				if (checkdelta(live) || *x >= 10)
				{
					*cycletodie = *cycletodie - CYCLE_DELTA;
					*x = 0;
				}
				else
					*x = *x + 1;
				if (checkdead(live))
				{
					killplayer(player, live);
					if (checkkill(player))
					{
						return (0);
					}
				}
				initcycle(live);
				*cycle = 0;
			}
			return (1);
}

static void gestioncycle(t_player *player, t_live *live, char *ram)
{
	int cycle;
	int cycletodie;
	t_player *tmp;
	int x;

	tmp = player;
	cycle = 0;
	cycletodie = CYCLE_TO_DIE;

	x = 0;
	while (cycle < cycletodie)
	{
		if (player->c == 0)
		{
			nbofcycle(player, ram);
			player->c = 1;
		}
		if (player->stok->cycle == 0 && !player->stok->kill)
		{
			searchfunction(player, live, ram);
			player->c = 0;
		}
		else
			player->stok->cycle--;
		player = player->next;
		if (!player)
		{
			player = tmp;
			cycle++;
			if (!ft_dead(player, live, &cycle, &cycletodie, &x))
				break ;
		}
	}
}

int  gestion(t_player *player, char *ram)
{
	t_live *live;

	ft_initregistre(player);
	live = ft_addlive(player);
	gestioncycle(player, live, ram);
	checkwinner(player, live);
	displayplayer(ram, 4096);
	return (1);
}
