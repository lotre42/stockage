/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initlive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 17:45:02 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/04 01:05:52 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		checkkill(t_player *player)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (x < player->stok->quantity)
	{
		if (!player->stok->kill)
		{
			i++;
		}
		player = player->next;
		x++;
	}
	if (i <= 1)
		return (1);
	else
		return (0);
}

void	killplayer(t_player *player, t_live *live)
{
	t_player *tmp;

	tmp = player;
	while (live)
	{
		if (live->dead == 1)
		{
			while (player && (live->nbplayer != player->stok->nbplayer))
			{
				player = player->next;
			}
			if (player)
			{
				player->stok->kill = 1;
			}
		}
		live = live->next;
		player = tmp;
	}
}

int		checkdelta(t_live *live)
{
	if (live->nblive > 21)
	{
		live->nblive = 0;
		return (1);
	}
	return (0);
}

int		checkdead(t_live *live)
{
	int ret;

	ret = 0;
	while (live)
	{
		if (live->nbliveplayer == 0)
		{
			live->dead = 1;
			ret = 1;
		}
		live = live->next;
	}
	if (ret == 1)
		return (1);
	else
		return (0);
}

void	initcycle(t_live *live)
{
	while (live)
	{
		live->nbliveplayer = 0;
		live = live->next;
	}
}
