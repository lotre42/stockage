/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlive.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 06:35:38 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/04 06:58:23 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void		ft_nbofplayer(t_player *player, int nb)
{
	player->stok->quantity = nb;
}

static int	ft_addplayerinlive(int nb, t_live **live)
{
	t_live *new;
	t_live *tmp;
	int		i;

	i = 0;
	if (!(new = malloc(sizeof(t_live))))
		return (0);
	new->nbplayer = nb;
	new->nblive = 0;
	new->nbliveplayer = 0;
	new->dead = 0;
	new->lastlive = 0;
	new->next = NULL;
	tmp = *live;
	if (!tmp)
		*live = new;
	else
	{
		while (tmp->next)
			tmp =tmp->next;
		tmp->next = new;
	}	
	return (1);
}

t_live *ft_addlive(t_player *player)
{
	t_live *live;
	t_player *tmp;
	int		nb;

	nb = 0;
	live = NULL;
	tmp = player;
	while (player)
	{
		player->stok->nbplayer = player->stok->registre[1];
		ft_addplayerinlive(player->stok->nbplayer, &live);
		player = player->next;
		nb++;
	}
	ft_nbofplayer(tmp, nb);
	return (live);
}
