/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_downvalue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 01:30:18 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/24 04:42:52 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		*ft_downvalue(t_stock *info, int *tabtype, int pc)
{
	int *tabvalue;
	int index;
	int i;

	index = pc + 2;
	i = 1;
	tabvalue = ft_inittab(tabtype[0]);
	while (i - 1 < tabtype[0])
	{
		if (tabtype[i] == 1)
		{
			tabvalue[i - 1] = info->ram[index];
			index++;
		}
		else if (tabtype[i] == 2)
		{
			tabvalue[i - 1] = info->ram[index] << 24 | info->ram[index + 1] << 16 |
			   	info->ram[index + 2] << 8 | info->ram[index + 3];
			index = index + 4;
		}
		else if (tabtype[i] == 3)
		{
			tabvalue[i - 1] = info->ram[index] << 8 | info->ram[index + 1];
			index = index + 2;
		}
		i++;
	}
	i = 0;
	while (i < tabtype[0])
	{
		printf("%x\n", tabvalue[i]);
		i++;
	}
	return (tabvalue);
}
