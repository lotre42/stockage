/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createram.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 08:54:26 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/29 09:36:07 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		cpyinram(char *ram, t_player *player, int i)
{
	int x;

	x = 0;
	while (x < player->sizeplayer)
	{
		ram[i] = player->instplayer[x];
		x++;
		i++;
	}
}

char		*createram(t_player *player, int nb)
{
	char *ram;
	int  x;
	int i;

	i = 1;
	x = 4096 / nb;
	ram = ft_strnew(4096);
	cpyinram(ram, player, 0);
	nb--;
	while (nb > 0)
	{
		cpyinram(ram, player, x * i);
		i++;
		nb--;
		player = player->next;
	}
	while (i < 4096)
	{
		printf("%hhx", ram[i]);
		i++;
	}
	return (ram);
}
