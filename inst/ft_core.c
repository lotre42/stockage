/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 05:24:15 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/04 07:49:53 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		searchfunction(t_player *player, t_live *liv)
{
	ft_putstr("\n------------>");
	//printf("[%hhx]", (player->stok->ram[player->stok->pc]));
	//displayplayer(player->stok->ram, 2059);
if (player->stok->ram[player->stok->pc])
	ft_putstr("JE SUIS VIVANT");

	if (player->stok->ram[player->stok->pc] && player->stok->ram[player->stok->pc] == 0x01)
	{
			ft_putstr("3\n");

		liv->nblive++;
		live(player->stok, liv);
	}
	else if (player->stok->ram[player->stok->pc] == 0x02)
	{
		ft_putstr("1\n");
		ld(player->stok);
	}
	else if (player->stok->ram[player->stok->pc] == 0x03)
		{
			ft_putstr("2\n");
			st(player->stok);
		}
	else if (player->stok->ram[player->stok->pc] == 0x04)
		{
			ft_putstr("3\n");
			add(player->stok);}
	else if (player->stok->ram[player->stok->pc] == 0x05)
			{
			ft_putstr("4\n");
			sub(player->stok);}
	else if (player->stok->ram[player->stok->pc] == 0x06)
			{
			ft_putstr("5\n");
			ft_and(player->stok);
		}
	else if (player->stok->ram[player->stok->pc] == 0x07)
		{
			ft_putstr("3\n");
			or(player->stok);
		}
	else if (player->stok->ram[player->stok->pc] == 0x08)
		{
			ft_putstr("3\n");
		xor(player->stok);
		}
	else if (player->stok->ram[player->stok->pc] == 0x09)
		{
			ft_putstr("3\n");

		zjump(player->stok);
		}
	else if (player->stok->ram[player->stok->pc] == 0x0a)
		{
			ft_putstr("3\n");
		ldi(player->stok);
		}
	else if (player->stok->ram[player->stok->pc] == 0x0b)
		{
			ft_putstr("3\n");

		sti(player->stok);
		}
	else if (player->stok->ram[player->stok->pc] == 0x0c)
		{
			ft_putstr("3\n");

		ft_fork(player);
		}
	else if (player->stok->ram[player->stok->pc] == 0x0d)
		{
			ft_putstr("3\n");

		lld(player->stok);
		}
	else if (player->stok->ram[player->stok->pc] == 0x0e)
		{
			ft_putstr("3\n");

		lldi(player->stok);
		}
	else
	{
			ft_putstr("3\n");

		player->stok->cycle++;
		player->stok->pc = pluspc(player->stok->pc, 1);
	}
	ft_putstr("<------------\n");
	return(0);
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
		x++;
		player->stok->nbplayer = player->stok->registre[1];
		ft_addplayerinlive(player->stok->registre[1], &live);
		//		ft_putendl(player->nameplayer);
		player = player->next;
	}
	player = tmp;
	player->stok->quantity = x;
	x = 0;
	cycle = 0;
	while (cycle < cycletodie)
	{
		ft_putnbr(cycle);
		if (player->c == 0)
		{
			nbofcycle(player);
			player->c = 1;
		}
		if (player->stok->cycle <= 0 /*&& !player->stok->kill*/)
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
				{
					killplayer(player, live);
					if (checkkill(player))
					{
						break ;
					}
				}
				initcycle(live);
				cycle = 0;
			}
		}
	}
	player = tmp;
	checkwinner(player, live);
//		displayplayer(ram, 4096);
	return(0);
}
