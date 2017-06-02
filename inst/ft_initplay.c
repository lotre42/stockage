/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initplay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 19:07:55 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/03 00:13:59 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*static void ft_init(t_player *player)
{
	player->totalplayer = NULL;
	player->magicplayer = NULL;
	player->nameplayer = NULL;
	player->comentplayer = NULL;
	player->instplayer = NULL;
	player->sizeplayer = 0;
	player->sizetotal = 0;
	player->next = NULL;
	player->stok = NULL;
}
*/
t_player	*ft_initplay(t_player *player)
{
	player = (t_player *)malloc(sizeof(t_player));
	player->totalplayer = NULL;
	player->magicplayer = NULL;
	player->nameplayer = NULL;
	player->comentplayer = NULL;
	player->instplayer = NULL;
	player->sizeplayer = 0;
	player->sizetotal = 0;
	player->next = NULL;
	player->stok = NULL;
	return (player);
}

/*t_player	ft_initplay(void)
{
	t_player player;

	player.totalplayer = NULL;
	player.magicplayer = NULL;
	player.nameplayer = NULL;
	player.comentplayer = NULL;
	player.instplayer = NULL;
	player.sizeplayer = 0;
	player.sizetotal = 0;
	player.next = NULL;
	player.stok = NULL;
	ft_init(&player);
	return (&player);
}*/
