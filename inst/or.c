/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:35:06 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/24 05:38:13 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar"

static void orid(t_stock *info, int pc, int *tabtype, int *tabvalue)
{
	if (tabtype[1] == 3 && tabtype[2] == 3)
	{
		if (info->ram[pc + (tabvalue[0] % 512)] || info->ram[pc + (tabvalue[1] % 512)])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
	}
	else if (tabtype[1] == 3 && tabtype[2] == 1)
	{
		if (info->ram[pc + (tabvalue[0] % 512)] || info->registre[tabvalue[1]])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
	}
	else if (tabtype[1] == 3 && tabtype[2] == 2)
	{
		if (tabvalue[1] || info->ram[pc + (tabvalue[0] % 512)])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
	}
}

static void orr(t_stock *info, int pc, int *tabtype, int *tabvalue)
{
	if (tabtype[1] == 1 && tabtype[2] == 1)
	{
		if (info->registre[tabvalue[0]] || info->registre[tabvalue[1]])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
	}	
	else if (tabtype[1] == 1 && tabtype[2] == 2)
	{
		if (info->registre[tabvalue[0]] || tabvalue[1])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
	}	
	else if (tabtype[1] == 1 && tabtype[2] == 3)
	{
		if (info->registre[tabvalue[0]] || info->ram[pc + (tabvalue[1] % 512)])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
	}
	else
		orid(info, pc, tabtype, tabvalue);	
}

static void ordi(t_stock *info, int pc, int *tabtype, int *tabvalue)
{	
	if (tabtype[1] == 2 && tabtype[2] == 2)
	{
		if (tabvalue[0] || tabvalue[1])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
	}	
	else if (tabtype[1] == 2 && tabtype[2] == 1)
	{
		if (tabvalue[0] || info->registre[tabvalue[1]])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
	}	
	else if (tabtype[1] == 2 && tabtype[2] == 3)
	{
		if (tabvalue[0] || info->ram[pc + (tabvalue[1] % 512)])
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
	}
	else
		orr(info, pc, tabtype, tabvalue);	
}

void	or(t_stock *info, int pc)
{
	int *tabtype;
	int *tabvalue;

	tabtype = ft_downtype(info, pc);
	tabvalue = ft_downvalue(info, tabtype, pc);
	ordi(info, pc, tabtype, tabvalue);
	if (info->registre[tabvalue[2]] == 0)
		info->carry = 1;
	else
		info->carry = 0;
}
