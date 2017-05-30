/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 23:55:08 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/30 05:06:25 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	sti(t_stock *info)
{
	int *tabtype;
	int *tabvalue;

	tabtype = ft_downtype(info);
	tabvalue = ft_downvalue(info, tabtype, 1);
	if (tabtype[2] == 1 && tabtype[3] == 1)
	{
		*(unsigned int*)((void *)((info->ram + info->registre[tabvalue[1]] + info->registre[tabvalue[2]]))) 
				= info->registre[tabvalue[0]]; 
	}
	else if (tabtype[2] == 1 && (tabtype[3] == 2 || tabtype[3] == 3))
	{
		*(unsigned int*)((void *)((info->ram + info->registre[tabvalue[1] + tabvalue[2]]))) 
		= info->registre[tabvalue[0]]; 
	}
	else if (tabtype[3] == 1 && (tabtype[2] == 2 || tabtype[2] == 3))
	{
		*(unsigned int*)((void *)((info->ram + info->registre[tabvalue[2]] + tabvalue[1])))
		   	= info->registre[tabvalue[0]]; 
	}
	else
	{
		*(unsigned int*)((void *)((info->ram + tabvalue[1] + tabvalue[2]))) = info->registre[tabvalue[0]]; 
	}
}
