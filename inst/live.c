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
	int i;
 
	i = ((ram[pluspc(info->pc, 1)] << 24) & 0xff000000)
		   	| ((ram[pluspc(info->pc, 2)] << 16) & 0x00ff0000)
		   	| ((ram[pluspc(info->pc, 3)] << 8) & 0x0000ff00)
		    | (ram[pluspc(info->pc, 4)] & 0x000000ff);
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
