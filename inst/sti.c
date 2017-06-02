/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 23:55:08 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/02 16:23:38 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	sti(t_stock *info)
{
	int *tabtype;
	int *tabvalue;
	int pc;

	tabtype = ft_downtype(info);
	tabvalue = ft_downvalue(info, tabtype, 1);
	if (tabtype[2] == 1 && tabtype[3] == 1)
	{
		pc = pluspc(info->pc, info->registre[tabvalue[1]] + info->registre[tabvalue[2]]);
		cpyint(info->ram, reverseint(info->registre[tabvalue[0]]), pc);
	//	*(unsigned int*)((void *)((info->ram + info->registre[tabvalue[1]] + info->registre[tabvalue[2]]))) 
	//			= info->registre[tabvalue[0]]; 
		info->pc = pluspc(info->pc, 4);
	}
	else if (tabtype[2] == 1 && (tabtype[3] == 2 || tabtype[3] == 3))
	{
		pc = pluspc(info->pc, info->registre[tabvalue[1]] + tabvalue[2]);
		cpyint(info->ram, reverseint(info->registre[tabvalue[0]]), pc);
//		*(unsigned int*)((void *)((info->ram + info->registre[tabvalue[1] + tabvalue[2]]))) 
//		= info->registre[tabvalue[0]]; 
		info->pc = pluspc(info->pc, 5);
	}
	else if (tabtype[3] == 1 && (tabtype[2] == 2 || tabtype[2] == 3))
	{
		pc = pluspc(info->pc, info->registre[tabvalue[2]] + tabvalue[1]);
		cpyint(info->ram, reverseint(info->registre[tabvalue[0]]), pc);
//		*(unsigned int*)((void *)((info->ram + info->registre[tabvalue[2]] + tabvalue[1])))
//		   	= info->registre[tabvalue[0]]; 
		info->pc = pluspc(info->pc, 5);
	}
	else
	{
		pc = pluspc(info->pc, tabvalue[1] + tabvalue[2]);
		cpyint(info->ram, reverseint(info->registre[tabvalue[0]]), pc);
	//	*(unsigned int*)((void *)((info->ram + tabvalue[1] + tabvalue[2]))) = info->registre[tabvalue[0]]; 
	//	info->pc = pluspc(info->pc, 6);
		info->pc = pluspc(info->pc, 7);
	}
}
