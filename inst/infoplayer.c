/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infoplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 17:33:21 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/31 18:52:07 by kahantar         ###   ########.fr       */
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

	if (player->sizetotal < (COMMENT_LENGTH + PROG_NAME_LENGTH + 16))
	{
		ft_putendl("La taille du joueur n'est pas adequate pour participer à la partie");
		return (0);
	}
	player->magicplayer = ft_strnew(4);
	player->magicplayer = ft_memcpy(player->magicplayer, player->totalplayer, 4);
	i = 4;
	player->nameplayer = createbuf(player->totalplayer, i , PROG_NAME_LENGTH);
	i = i + PROG_NAME_LENGTH;
	if (!verifnull(player->totalplayer, i))
		return (0);
	i = i + 4;
	player->sizeplayer = ((player->totalplayer[i] << 24) & 0xff000000) |
	   	((player->totalplayer[i + 1] << 16) & 0x00ff0000)
	   	| ((player->totalplayer[i + 2] << 8) & 0x0000ff00) | (player->totalplayer[i + 3] & 0x000000ff);
	if (player->sizeplayer > CHAMP_MAX_SIZE)
	{
		ft_putendl("La taille du joueur n'est pas adequate pour participer à la partie");
		return (0);
	}
	i = i + 4;
	player->comentplayer = createbuf(player->totalplayer, i, COMMENT_LENGTH);
	i = i + COMMENT_LENGTH;
	if (!verifnull(player->totalplayer, i))
		return (0);
	i = i + 4;
	if (player->sizetotal < i + player->sizeplayer)
		return (0);
	player->instplayer = createbuf(player->totalplayer, i, player->sizeplayer);
	return (1);
}
