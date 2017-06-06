/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 23:46:24 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/04 06:23:45 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		ft_live(t_stock *info, t_live *live, char *ram)
{
	unsigned int i;
 
	i = loadint(ram, info->pc + 1);
	info->pc = (info->pc + 5);
	while (live)
	{
		if (live->nbplayer == i)
		{
			live->nbliveplayer = live->nbliveplayer + 1;
			live->lastlive = i;
		}
		live = live->next;
	}
}
