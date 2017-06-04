/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initplay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 19:07:55 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/04 06:47:35 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

t_player	*ft_initplay(t_player *player)
{
	player = (t_player *)malloc(sizeof(t_player));
	player->totalplayer = NULL;
	player->magicplayer = NULL;
	player->nameplayer = NULL;
	player->comentplayer = NULL;
	player->instplayer = NULL;
	player->sizeplayer = 0;
	player->c = 0;
	player->sizetotal = 0;
	player->next = NULL;
	player->stok = NULL;
	return (player);
}

