/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:35:06 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/04 04:57:24 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void orid(t_stock *info, int *tabtype, int *tabvalue, char *ram)
{
	if (tabtype[1] == 3 && tabtype[2] == 3)
	{
		if (ram[pluspc(info->pc, (tabvalue[0] % 512))] || ram[pluspc(info->pc, (tabvalue[1] % 512))])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
		info->pc = pluspc(info->pc, 7);
	}
	else if (tabtype[1] == 3 && tabtype[2] == 1)
	{
		if (ram[pluspc(info->pc, (tabvalue[0] % 512))] || info->registre[tabvalue[1]])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
		info->pc = pluspc(info->pc, 6);
	}
	else if (tabtype[1] == 3 && tabtype[2] == 2)
	{
		if (tabvalue[1] || ram[pluspc(info->pc, (tabvalue[0] % 512))])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
		info->pc = pluspc(info->pc, 9);
	}
	else
		info->pc = pluspc(info->pc, 1);
}

static void orr(t_stock *info, int *tabtype, int *tabvalue, char *ram)
{
	if (tabtype[1] == 1 && tabtype[2] == 1)
	{
		if (info->registre[tabvalue[0]] || info->registre[tabvalue[1]])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
		info->pc = pluspc(info->pc, 5);
	}	
	else if (tabtype[1] == 1 && tabtype[2] == 2)
	{
		if (info->registre[tabvalue[0]] || tabvalue[1])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
		info->pc = pluspc(info->pc, 6);
	}	
	else if (tabtype[1] == 1 && tabtype[2] == 3)
	{
		if (info->registre[tabvalue[0]] || ram[pluspc(info->pc, (tabvalue[1] % 512))])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
		info->pc = pluspc(info->pc, 8);
	}
	else
		orid(info, tabtype, tabvalue, ram);	
}

static void ordi(t_stock *info, int *tabtype, int *tabvalue, char *ram)
{	
	if (tabtype[1] == 2 && tabtype[2] == 2)
	{
		if (tabvalue[0] || tabvalue[1])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
		info->pc = pluspc(info->pc, 11);
	}	
	else if (tabtype[1] == 2 && tabtype[2] == 1)
	{
		if (tabvalue[0] || info->registre[tabvalue[1]])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
		info->pc = pluspc(info->pc, 6);
	}	
	else if (tabtype[1] == 2 && tabtype[2] == 3)
	{
		if (tabvalue[0] || ram[pluspc(info->pc, (tabvalue[1] % 512))])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
		info->pc = pluspc(info->pc, 9);
	}
	else
		orr(info, tabtype, tabvalue, ram);	
}

void	or(t_stock *info, char *ram)
{
	int *tabtype;
	int *tabvalue;

	tabtype = ft_downtype(info, ram);
	tabvalue = ft_downvalue(info, tabtype, 0, ram);
	ordi(info, tabtype, tabvalue, ram);
	if (info->carry == 0)
		info->carry = 1;
	else
		info->carry = 0;
}
