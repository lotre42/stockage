/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:23:53 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/04 05:02:30 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	st(t_stock *info, char *ram)
{
	int	*tabtype;
	int *tabvalue;
	int pc;

	tabtype = ft_downtype(info, ram);
	tabvalue = ft_downvalue(info, tabtype, 0, ram);
	if (tabtype[2] == 3)
	{
		pc = (info->pc + (tabvalue[1] % 512));
		cpyint(ram, reverseint(info->registre[tabvalue[0]]), pc);
		//*(unsigned int*)((void*)((ram + pc))) = info->registre[tabvalue[0]];
		info->pc = (info->pc + 5);
	}
	else
	{
		info->registre[tabvalue[1]] = info->registre[tabvalue[0]];
		info->pc = (info->pc + 4);
	}
}

