/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:32:26 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/30 02:52:35 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void addid(t_stock *info, int *tabtype, int *tabvalue)
{
	if (tabtype[1] == 3 && tabtype[2] == 3)
	{
		if (info->ram[info->pc + (tabvalue[0] % 512)] && info->ram[info->pc + (tabvalue[1] % 512)])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
	}
	else if (tabtype[1] == 3 && tabtype[2] == 1)
	{
		if (info->ram[info->pc + (tabvalue[0] % 512)] && info->registre[tabvalue[1]])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
	}
	else if (tabtype[1] == 3 && tabtype[2] == 2)
	{
		if (tabvalue[1] && info->ram[info->pc + (tabvalue[0] % 512)])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
	}
}

static void addr(t_stock *info, int *tabtype, int *tabvalue)
{
	if (tabtype[1] == 1 && tabtype[2] == 1)
	{
		if (info->registre[tabvalue[0]] && info->registre[tabvalue[1]])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
	}	
	else if (tabtype[1] == 1 && tabtype[2] == 2)
	{
		if (info->registre[tabvalue[0]] && tabvalue[1])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
	}	
	else if (tabtype[1] == 1 && tabtype[2] == 3)
	{
		if (info->registre[tabvalue[0]] && info->ram[info->pc + (tabvalue[1] % 512)])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
	}
	else
		addid(info, tabtype, tabvalue);	
}

static void adddi(t_stock *info, int *tabtype, int *tabvalue)
{	
	if (tabtype[1] == 2 && tabtype[2] == 2)
	{
		if (tabvalue[0] && tabvalue[1])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
	}	
	else if (tabtype[1] == 2 && tabtype[2] == 1)
	{
		if (tabvalue[0] && info->registre[tabvalue[1]])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
	}	
	else if (tabtype[1] == 2 && tabtype[2] == 3)
	{
		if (tabvalue[0] && info->ram[info->pc + (tabvalue[1] % 512)])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
	}
	else
		addr(info, tabtype, tabvalue);	
}
void	ft_and(t_stock *info)
{
	int *tabtype;
	int *tabvalue;

	tabtype = ft_downtype(info);
	tabvalue = ft_downvalue(info, tabtype, 0);
	adddi(info, tabtype, tabvalue);
	if (info->registre[tabvalue[2]] == 0)
		info->carry = 1;
	else
		info->carry = 0;
}
