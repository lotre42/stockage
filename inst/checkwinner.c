/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkwinner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 00:53:36 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/04 06:35:25 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	checkwinner(t_player *player, t_live *live)
{
	int x;
	t_player *tmp;
	int i;

	x = 0;
	i = 0;
	tmp = player;
	while (player && x < tmp->stok->quantity)
	{
		if (player->stok->kill == 0)
		{
			i++;
		}
		player = player->next;
		x++;
	}
	x = 0;
	if (i == 1)
	{
		while (tmp && x < tmp->stok->quantity)
		{
			if (tmp->stok->kill == 0)
				ft_putendl(tmp->nameplayer);
			tmp = tmp->next;
			x++;
		}
	}
	else
	{
		//ft_putnbr(live->lastlive);
		while (tmp && (live->lastlive != tmp->stok->nbplayer))
		{
			tmp = tmp->next;
		}
		if (tmp)
			ft_putendl(tmp->nameplayer);
	}
}


