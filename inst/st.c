/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:23:53 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/02 19:15:33 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"



void	st(t_stock *info)
{
	int	*tabtype;
	int *tabvalue;
	int pc;

	tabtype = ft_downtype(info);
	tabvalue = ft_downvalue(info, tabtype, 0);
	if (tabtype[2] == 3)
	{
		pc = pluspc(info->pc, (tabvalue[1] % 512));
		cpyint(info->ram, reverseint(info->registre[tabvalue[0]]), pc);
		//*(unsigned int*)((void*)((info->ram + pc))) = info->registre[tabvalue[0]];
		info->pc = pluspc(info->pc, 5);
	}
	else
	{
		info->registre[tabvalue[1]] = info->registre[tabvalue[0]];
		info->pc = pluspc(info->pc, 4);
	}
	if (info->registre[tabvalue[0]] == 0)
		info->carry = 1;
	else
		info->carry = 0;
}

