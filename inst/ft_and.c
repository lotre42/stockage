/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:32:26 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/04 04:57:03 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void addid(t_stock *info, int *tabtype, int *tabvalue, char *ram)
{
	if (tabtype[1] == 3 && tabtype[2] == 3)
	{
		if (ram[(info->pc + (tabvalue[0] % 512))] && ram[(info->pc + (tabvalue[1] % 512))])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
		info->pc = (info->pc + 7);
	}
	else if (tabtype[1] == 3 && tabtype[2] == 1)
	{
		if (ram[(info->pc + (tabvalue[0] % 512))] && info->registre[tabvalue[1]])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
		info->pc = (info->pc + 6);
	}
	else if (tabtype[1] == 3 && tabtype[2] == 2)
	{
		if (tabvalue[1] && ram[(info->pc + (tabvalue[0] % 512))])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
		info->pc = (info->pc + 9);
	}
	else
		info->pc = (info->pc + 1);
}

static void addr(t_stock *info, int *tabtype, int *tabvalue, char *ram)
{
	if (tabtype[1] == 1 && tabtype[2] == 1)
	{
		if (info->registre[tabvalue[0]] && info->registre[tabvalue[1]])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
		info->pc = (info->pc + 5);
	}	
	else if (tabtype[1] == 1 && tabtype[2] == 2)
	{
		if (info->registre[tabvalue[0]] && tabvalue[1])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
		info->pc = (info->pc + 8);
	}	
	else if (tabtype[1] == 1 && tabtype[2] == 3)
	{
		if (info->registre[tabvalue[0]] && ram[(info->pc + (tabvalue[1] % 512))])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
		info->pc = (info->pc + 6);
	}
	else
		addid(info, tabtype, tabvalue, ram);	
}

static void adddi(t_stock *info, int *tabtype, int *tabvalue, char *ram)
{	
	if (tabtype[1] == 2 && tabtype[2] == 2)
	{
		if (tabvalue[0] && tabvalue[1])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
		info->pc = (info->pc + 11);
	}	
	else if (tabtype[1] == 2 && tabtype[2] == 1)
	{
		if (tabvalue[0] && info->registre[tabvalue[1]])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
		info->pc = (info->pc + 8);
	}	
	else if (tabtype[1] == 2 && tabtype[2] == 3)
	{
		if (tabvalue[0] && ram[(info->pc + (tabvalue[1] % 512))])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
		info->pc = (info->pc + 9);
	}
	else
		addr(info, tabtype, tabvalue, ram);	
}
void	ft_and(t_stock *info, char *ram)
{
	int *tabtype;
	int *tabvalue;

	tabtype = ft_downtype(info, ram);
	tabvalue = ft_downvalue(info, tabtype, 0, ram);
	adddi(info, tabtype, tabvalue, ram);
	if (info->carry == 0)
		info->carry = 1;
	else
		info->carry = 0;
}
