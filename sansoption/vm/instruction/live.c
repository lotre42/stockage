/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 23:46:24 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/15 02:00:18 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		ft_live(t_process *process, t_live *live, unsigned char *ram,
unsigned int *numberplayer)
{
	unsigned int	i;
	unsigned int	x;

	x = 1;
	i = loadint(ram, process->pc + 1);
	process->pc = mask_pc(process->pc, 5);
	process->live++;
	live->nblive++;
	while (x < numberplayer[0] + 1)
	{
		if (numberplayer[x] == i)
		{
			live->lastlive = i;
			break ;
		}
		x++;
	}
}
