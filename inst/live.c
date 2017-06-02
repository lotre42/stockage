/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 23:46:24 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/03 01:28:15 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		live(t_stock *info, t_live *live)
{
	int i;
 
	i = ((info->ram[pluspc(info->pc, 1)] << 24) & 0xff000000)
		   	| ((info->ram[pluspc(info->pc, 2)] << 16) & 0x00ff0000)
		   	| ((info->ram[pluspc(info->pc, 3)] << 8) & 0x0000ff00)
		    | (info->ram[pluspc(info->pc, 4)] & 0x000000ff);
	info->pc = pluspc(info->pc, 5);
	while (live)
	{
		if (live->nbplayer == i)
		{
			live->nbliveplayer = live->nbliveplayer + 1;
		}
		live = live->next;
	}
}