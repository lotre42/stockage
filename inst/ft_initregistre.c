/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initregistre.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 19:27:58 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/01 19:30:10 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_initregistre(t_player *player)
{
	int i;

	i = -1;
	while (player)
	{
		player->stok->registre[1] = i;
		i--;
		player = player->next;
	}
}
