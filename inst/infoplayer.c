/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infoplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 17:33:21 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/27 20:30:41 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	infoplayer(t_player *player)
{
	char *info;
	int i;
	int x;

	i = 0;
	x = 0;
	player->infoplayer = ft_strnew(2191);
	player->infoplayer = ft_memcpy(player->infoplayer, player->totalplayer, 2191);
	player->instplayer = ft_strnew(player->sizeplayer - 2191);
	i = 2191;
	while (i < player->sizeplayer)
	{
		ft_putendl("coucou");
		player->instplayer[x] = player->totalplayer[i];
		x++;
		i++;
	}
}
