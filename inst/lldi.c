/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 15:38:57 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/04 05:00:36 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/corewar.h"

void	lldi(t_stock *info, char *ram)
{
	int S;
	int *tabtype;
	int *tabvalue;

	tabtype = ft_downtype(info, ram);
	tabvalue = ft_downvalue(info, tabtype, 1, ram);
	if (tabtype[1] == 3 && tabtype[2] == 2)
	{
		S = tabvalue[0] + tabvalue[1];
		info->registre[tabvalue[2]] = (((ram[(info->pc + (S))] << 24) & 0xff000000)|
		   	((ram[(info->pc + 1 + (S))] << 16) & 0x00ff0000) |
		   	((ram[(info->pc + 2 + (S))] << 8) & 0x0000ff00) |
		   	((ram[(info->pc + 3 + (S))]) & 0x000000ff));
		info->pc = (info->pc + 6);
	}
	else if (tabtype[1] == 3 && tabtype[2] == 3)
	{
		S = tabvalue[0] + tabvalue[1];
		info->registre[tabvalue[2]] = ((ram[(info->pc + (S))] << 24) |
		   	((ram[(info->pc + 1 + (S))] << 16) & 0x00ffffff) |
		   	((ram[(info->pc + 2 + (S))] << 8) & 0x0000ffff) |
		   	((ram[(info->pc + 3 + (S))]) & 0x000000ff));
		info->pc = (info->pc + 6);
	}
	else if (tabtype[1] == 1 && tabtype[2] == 3)
	{
		S = info->registre[tabvalue[0]] + tabvalue[1];
		info->registre[tabvalue[2]] = (((ram[(info->pc + (S))] << 24) & 0xff000000)|
		   	((ram[(info->pc + 1 + (S))] << 16) & 0x00ff0000) |
		   	((ram[(info->pc + 2 + (S))] << 8) & 0x0000ff00) |
		   	((ram[(info->pc + 3 + (S))]) & 0x000000ff));
		info->pc = (info->pc + 5);
	}
	else if (tabtype[1] == 1 && tabtype[2] == 2)
	{
		S = info->registre[tabvalue[0]] + tabvalue[1];
		info->registre[tabvalue[2]] = (((ram[(info->pc + (S))] << 24) & 0xff000000) |
		   	((ram[(info->pc + 1 + (S))] << 16) & 0x00ff0000) |
		   	((ram[(info->pc + 2 + (S))] << 8) & 0x0000ff00) |
		   	((ram[(info->pc + 3 + (S))]) & 0x000000ff));
		info->pc = (info->pc + 5);
	}
	else if (tabtype[1] == 2 && tabtype[2] == 1)
	{
		S = info->registre[tabvalue[1]] + tabvalue[0];
		info->registre[tabvalue[2]] = (((ram[(info->pc + (S))] << 24) & 0xff000000) |
		   	((ram[(info->pc + 1 + (S))] << 16) & 0x00ff0000) |
		   	((ram[(info->pc + 2 + (S))] << 8) & 0x0000ff00) |
		   	((ram[(info->pc + 3 + (S))]) & 0x000000ff));
		info->pc = (info->pc + 5);
	}
	else if (tabtype[1] == 1 && tabtype[2] == 3)
	{
		S = tabvalue[0] + tabvalue[1];
		info->registre[tabvalue[2]] = (((ram[(info->pc + (S))] << 24) & 0xff000000) |
		   	((ram[(info->pc + 1 + (S))] << 16) & 0x00ff0000) |
		   	((ram[(info->pc + 2 + (S))] << 8) & 0x0000ff00) |
		   	((ram[(info->pc + 3 + (S))]) & 0x000000ff));
		info->pc = (info->pc + 5);
	}
	else
		info->pc = (info->pc + 1);
	if (info->carry == 0)
		info->carry = 1;
	else
		info->carry = 0;
}
