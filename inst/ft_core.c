/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 05:24:15 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/30 09:04:24 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void	searchfunction(t_player *player)
{
	if (player->stok->ram[player->stok->pc] == 0x02)
	{
		ld(player->stok);
		ft_putendl("ld");
	}
	else if (player->stok->ram[player->stok->pc] == 0x03)
	{
		st(player->stok);
		ft_putendl("ld");
	}
	else if (player->stok->ram[player->stok->pc] == 0x04)
	{
		add(player->stok);
		ft_putendl("add");
	}
	else if (player->stok->ram[player->stok->pc] == 0x05)
	{
		sub(player->stok);
		ft_putendl("sub");
	}
	else if (player->stok->ram[player->stok->pc] == 0x06)
	{
		ft_and(player->stok);
		ft_putendl("ft_and");
	}
	else if (player->stok->ram[player->stok->pc] == 0x07)
	{
		or(player->stok);
		ft_putendl("or");
	}
	else if (player->stok->ram[player->stok->pc] == 0x08)
	{
		xor(player->stok);
		ft_putendl("xor");
	}
	else if (player->stok->ram[player->stok->pc] == 0x09)
	{
		zjump(player->stok);
		ft_putendl("zjump");
	}
	else if (player->stok->ram[player->stok->pc] == 0x0a)
	{
		ldi(player->stok);
		ft_putendl("ldi");
	}
	else if (player->stok->ram[player->stok->pc] == 0x0b)
	{
		sti(player->stok);
		ft_putendl("sti");
	}
	else if (player->stok->ram[player->stok->pc] == 0x0d)
	{
		lld(player->stok);
		ft_putendl("lld");
	}
	else if (player->stok->ram[player->stok->pc] == 0x0e)
	{
		lldi(player->stok);
		ft_putendl("lldi");
	}
}

int			ft_core(t_player *player, char *ram)
{
	t_player *tmp;
	tmp = player;
	while (player)
	{
		searchfunction(player);
		player = player->next;
	}
	displayplayer(tmp->stok->ram, 4096);
	return (0);
}
