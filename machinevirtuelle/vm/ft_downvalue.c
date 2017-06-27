/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_downvalue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 01:30:18 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/15 02:57:06 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void			downcup(unsigned int *tabvalue, unsigned char *ram,
int i, int *index)
{
	tabvalue[i - 1] = ((ram[*index] << 8) & 0xff00) |
	(ram[mask_pc(*index, 1)] & 0x00ff);
	*index = mask_pc(*index, 2);
}

unsigned int		*ft_downvalue(t_process *process, unsigned int *tabtype,
int x, unsigned char *ram)
{
	unsigned int	*tabvalue;
	int				index;
	unsigned int	i;

	index = mask_pc(process->pc, 2);
	i = 1;
	tabvalue = init_tab(tabtype[0]);
	while (i - 1 < tabtype[0])
	{
		if (tabtype[i] == 1)
		{
			tabvalue[i - 1] = ram[index];
			index = mask_pc(index, 1);
		}
		else if (tabtype[i] == 2 && x == 0)
		{
			tabvalue[i - 1] = ram[index] << 24 | ram[mask_pc(index, 1)] << 16 |
			ram[mask_pc(index, 2)] << 8 | ram[mask_pc(index, 3)];
			index = mask_pc(index, 4);
		}
		else if (tabtype[i] == 3 || (tabtype[i] == 2 && x == 1))
			downcup(tabvalue, ram, i, &index);
		i++;
	}
	return (tabvalue);
}
