/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbplayer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 00:12:53 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/01 00:24:42 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		nbplayer(t_player *player)
{
	int i;

	i = 0;
	while (player)
	{
		i++;
		player = player->next;
	}
	return (i);
}
