/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 05:24:15 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/03 01:38:27 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static int		searchfunction(t_player *player, t_live *liv)
{
	if (player->stok->ram[player->stok->pc] == 0x01)
	{
		liv->nblive++;
		live(player->stok, liv);
	}
	else if (player->stok->ram[player->stok->pc] == 0x02)
		ld(player->stok);
	else if (player->stok->ram[player->stok->pc] == 0x03)
		st(player->stok);
	else if (player->stok->ram[player->stok->pc] == 0x04)
		add(player->stok);
	else if (player->stok->ram[player->stok->pc] == 0x05)
		sub(player->stok);
	else if (player->stok->ram[player->stok->pc] == 0x06)
		ft_and(player->stok);
	else if (player->stok->ram[player->stok->pc] == 0x07)
		or(player->stok);
	else if (player->stok->ram[player->stok->pc] == 0x08)
		xor(player->stok);
	else if (player->stok->ram[player->stok->pc] == 0x09)
		zjump(player->stok);
	else if (player->stok->ram[player->stok->pc] == 0x0a)
		ldi(player->stok);
	else if (player->stok->ram[player->stok->pc] == 0x0b)
		sti(player->stok);
	else if (player->stok->ram[player->stok->pc] == 0x0c)
		ft_fork(player);
	else if (player->stok->ram[player->stok->pc] == 0x0d)
		lld(player->stok);
	else if (player->stok->ram[player->stok->pc] == 0x0e)
		lldi(player->stok);
	else
	{
		player->stok->cycle++;
		player->stok->pc = pluspc(player->stok->pc, 1);
	}
}

static int	ft_addplayerinlive(int nbplayer, t_live **live)
{
	t_live *new;
	t_live *tmp;
	int		i;

	i = 0;
	if (!(new = malloc(sizeof(t_live))))
			return (0);
	new->nbplayer = nbplayer;
	new->nblive = 0;
	new->nbliveplayer = 0;
	new->dead = 0;
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

int			ft_core(t_player *player, char *ram)
{
	t_player *tmp;
	int cycle;
	int cycletodie;
	int cycledelta;
	t_live *live;
	int x;
	
	live = NULL;
	x = 0;
	cycletodie = 1536;
	cycledelta = 50;
	tmp = player;
	ft_initregistre(player);
	while (player)
	{
		player->stok->nbplayer = player->stok->registre[1];
		ft_addplayerinlive(player->stok->registre[1], &live);
//		ft_putendl(player->nameplayer);
		player = player->next;
	}
	player = tmp;
	cycle = 0;
	while (cycle < cycletodie)
	{
		if (player->c == 0)
		{
			nbofcycle(player);
			player->c = 1;
		}
		if (player->stok->cycle <= 0 && !player->stok->kill)
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
			if (cycle >= cycletodie)
			{
				if (checkdelta(live) || x >= 10)
				{
					cycletodie = cycletodie - cycledelta;
					x = 0;
				}
				else
					x++;
				if (checkdead(live))
					killplayer(player, live);
				if (checkkill(player))
				{
					break ;
				}
				initcycle(live);
				cycle = 0;
			}
		}
	}
	x = 0;
	player = tmp;
	while (x < 2)
	{
		x++;
		if (player->stok->kill == 0)
			ft_putendl(player->nameplayer);
		player = player->next;
	}
	return(0);
}
