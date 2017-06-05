/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_downvalue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 01:30:18 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/30 08:12:58 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		*ft_downvalue(t_stock *info, int *tabtype, int x, char *ram)
{
	unsigned int *tabvalue;
	int index;
	int i;

	index = pluspc(info->pc, 2);
	i = 1;
	tabvalue = ft_inittab(tabtype[0]);
	//printf("%d\n", index);
	while (i - 1 < tabtype[0])
	{
		if (tabtype[i] == 1)
		{
			tabvalue[i - 1] = ram[index];
			index = pluspc(index, 1);
		}
		else if (tabtype[i] == 2 && x == 0)
		{
			tabvalue[i - 1] = ram[index] << 24 | ram[pluspc(index, 1)] << 16 |
			   	ram[pluspc(index, 2)] << 8 | ram[pluspc(index, 3)];
			index = pluspc(index, 4);
		}
		else if (tabtype[i] == 3 || (tabtype[i] == 2 && x == 1))
		{
			tabvalue[i - 1] = ((ram[index] << 8) & 0xff00) | (ram[pluspc(index, 1)] & 0x00ff);
			index = pluspc(index, 2);
		}
		i++;
	}
	return (tabvalue);
}
