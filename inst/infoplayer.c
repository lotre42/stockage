/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infoplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 17:33:21 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/29 07:17:02 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static char	*createbuf(char *str, int i, int size)
{
	char *ret;
	int j;
	int x;

	x = 0;
	j = i;
	ret = ft_strnew(size);
	while (i < j + size)
	{
		ret[x] = str[i];
		i++;
		x++;
	}
	return (ret);
}

static int	verifnull(char *str, int i)
{
	if (str[i] || str[i + 1] | str[i + 2] | str[i + 3])
	{
		ft_putendl("ERROR");
		return (0);
	}
	return (1);
}

int			infoplayer(t_player *player)
{
	char *info;
	int i;

	if (player->sizetotal < 2191)
		return (0);
	//player->magicplayer = ft_strnew(4);
	//player->magicplayer = ft_memcpy(player->magicplayer, player->totalplayer, 4);
	i = 4;
//	//player->nameplayer = createbuf(player->totalplayer, i , 128);
	i = i + 128;
//	if (!verifnull(player->totalplayer, i))
//		return (0);
	i = i + 4;
	player->sizeplayer = player->totalplayer[i] << 24 |
	   	player->totalplayer[i + 1] << 16
	   	| player->totalplayer[i + 2] << 8 | player->totalplayer[i + 3];
//	i = i + 4;
//	player->comentplayer = createbuf(player->totalplayer, i, 2048);
//	i = i + 2048;
//	if (!verifnull(player->totalplayer, i))
//		return (0);
//	i = i + 4;
//	if (player->sizetotal < i + player->sizeplayer)
//		return (0);
//	player->instplayer = createbuf(player->totalplayer, i, player->sizeplayer);
	return (1);
}
