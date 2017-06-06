/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 23:43:45 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/04 04:59:21 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ldi(t_stock *info, char *ram)
{
	int S;
	int *tabtype;
	int *tabvalue;

	tabtype = ft_downtype(info, ram);
	tabvalue = ft_downvalue(info, tabtype, 1, ram);
	if ((tabtype[1] == 3 && tabtype[2] == 2) || (tabtype[1] == 3 && tabtype[2] == 3) || (tabtype[1] == 1 && tabtype[2] == 3))
	{
		S = tabvalue[0] + tabvalue[1];
		info->registre[tabvalue[2]] = loadint(ram, info->pc + (S % 512));
		info->pc = (info->pc + 6);
	}
	else if (tabtype[1] == 1 && tabtype[2] == 3)
	{
		S = info->registre[tabvalue[0]] + tabvalue[1];
		info->registre[tabvalue[2]] = loadint(ram, info->pc + (S % 512));
		info->pc = (info->pc + 5);
	}
	else if (tabtype[1] == 1 && tabtype[2] == 2)
	{
		S = info->registre[tabvalue[0]] + tabvalue[1];
		info->registre[tabvalue[2]] = loadint(ram, info->pc + (S % 512));
		info->pc = (info->pc + 5);
	}
	else if (tabtype[1] == 2 && tabtype[2] == 1)
	{
		S = info->registre[tabvalue[1]] + tabvalue[0];
		info->registre[tabvalue[2]] = loadint(ram, info->pc + (S % 512));
		info->pc = (info->pc + 5);
	}
	else
		info->pc = (info->pc + 1);
	//printf("%x", info->registre[1]);
}
