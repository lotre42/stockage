/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 05:24:15 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/01 00:58:32 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static int		searchfunction(t_player *player, int *liv)
{
	if (player->stok->ram[player->stok->pc] == 0x01)
	{
		live(player->stok, liv);
		ft_putendl("live");
		player->stok->cycle = 5;
	}
	else if (player->stok->ram[player->stok->pc] == 0x02)
	{
		ld(player->stok);
		ft_putendl("ld");
		player->stok->cycle = 5;
	}
	else if (player->stok->ram[player->stok->pc] == 0x03)
	{
		st(player->stok);
		ft_putendl("st");
		player->stok->cycle = 5;
	}
	else if (player->stok->ram[player->stok->pc] == 0x04)
	{
		add(player->stok);
		ft_putendl("add");
		player->stok->cycle = 10;
	}
	else if (player->stok->ram[player->stok->pc] == 0x05)
	{
		sub(player->stok);
		ft_putendl("sub");
		player->stok->cycle = 10;
	}
	else if (player->stok->ram[player->stok->pc] == 0x06)
	{
		ft_and(player->stok);
		ft_putendl("ft_and");
		player->stok->cycle = 6;
	}
	else if (player->stok->ram[player->stok->pc] == 0x07)
	{
		or(player->stok);
		ft_putendl("or");
		player->stok->cycle = 6;
	}
	else if (player->stok->ram[player->stok->pc] == 0x08)
	{
		xor(player->stok);
		ft_putendl("xor");
		player->stok->cycle = 6;
	}
	else if (player->stok->ram[player->stok->pc] == 0x09)
	{
		zjump(player->stok);
		ft_putendl("zjump");
		player->stok->cycle = 20;
	}
	else if (player->stok->ram[player->stok->pc] == 0x0a)
	{
		ldi(player->stok);
		ft_putendl("ldi");
		player->stok->cycle = 25;
	}
	else if (player->stok->ram[player->stok->pc] == 0x0b)
	{
		sti(player->stok);
		ft_putendl("sti");
		player->stok->cycle = 25;
	}
	else if (player->stok->ram[player->stok->pc] == 0x0d)
	{
		lld(player->stok);
		ft_putendl("lld");
		player->stok->cycle = 10;
	}
	else if (player->stok->ram[player->stok->pc] == 0x0e)
	{
		lldi(player->stok);
		ft_putendl("lldi");
		player->stok->cycle = 50;
	}
	else
	{
		player->stok->cycle++;
		player->stok->pc = pluspc(player->stok->pc, 1);
	}
}

int			ft_core(t_player *player, char *ram)
{
	t_player *tmp;
	tmp = player;
	int cycle;
	int *live;

	live = ft_inittab(nbplayer(player));	
	cycle = 0;
	while (cycle < 100)
	{
		//printf("%d\n", player->stok->cycle);
		if (player->c == 0)
		{
			nbofcycle(player);
			player->c = 1;
		}
		if (player->stok->cycle <= 0)
		{
			searchfunction(player, live);
			player->c = 0;
		}
		else
			player->stok->cycle--;
		cycle++;
		player = player->next;
		if (!player)
			player = tmp;
	}
//yy	printf("%d", live[0]);
//	displayplayer(tmp->stok->ram, 4096);
	return(0);
}
