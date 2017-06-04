/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:36:27 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/04 04:57:36 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/corewar.h"

static void xorid(t_stock *info, int *tabtype, int *tabvalue)
{
	if (tabtype[1] == 3 && tabtype[2] == 3)
	{
		if ((info->ram[pluspc(info->pc, (tabvalue[0] % 512))] && !info->ram[pluspc(info->pc, (tabvalue[1] % 512))])
		|| (info->ram[pluspc(info->pc, (tabvalue[1] % 512))] && !info->ram[pluspc(info->pc, (tabvalue[0] % 512))]))
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
		info->pc = pluspc(info->pc, 7);
	}
	else if (tabtype[1] == 3 && tabtype[2] == 1)
	{
		if ((info->ram[pluspc(info->pc, (tabvalue[0] % 512))] && !info->registre[tabvalue[1]]) ||
		 (!info->ram[pluspc(info->pc, (tabvalue[0] % 512))] && info->registre[tabvalue[1]]))
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
		info->pc = pluspc(info->pc, 6);
	}
	else if (tabtype[1] == 3 && tabtype[2] == 2)
	{
		if ((tabvalue[1] && !info->ram[pluspc(info->pc, (tabvalue[0] % 512))]) ||
		 (!tabvalue[1] || info->ram[pluspc(info->pc, (tabvalue[0] % 512))]))
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
		info->pc = pluspc(info->pc, 9);
	}
	else
		info->pc = pluspc(info->pc, 1);
}

static void xorr(t_stock *info,  int *tabtype, int *tabvalue)
{
	if (tabtype[1] == 1 && tabtype[2] == 1)
	{
		if ((info->registre[tabvalue[0]] && !info->registre[tabvalue[1]]) ||
		(!info->registre[tabvalue[0]] && info->registre[tabvalue[1]]))
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
		info->pc = pluspc(info->pc, 5);
	}	
	else if (tabtype[1] == 1 && tabtype[2] == 2)
	{
		if ((info->registre[tabvalue[0]] && !tabvalue[1]) ||
		(!info->registre[tabvalue[0]] && tabvalue[1]))
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
		info->pc = pluspc(info->pc, 8);
	}	
	else if (tabtype[1] == 1 && tabtype[2] == 3)
	{
		if ((info->registre[tabvalue[0]] && !info->ram[pluspc(info->pc, (tabvalue[1] % 512))]) ||
		(!info->registre[tabvalue[0]] && info->ram[pluspc(info->pc, (tabvalue[1] % 512))]))
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
		info->pc = pluspc(info->pc, 6);
	}
	else
		xorid(info, tabtype, tabvalue);	
}

static void xordi(t_stock *info, int *tabtype, int *tabvalue)
{	
	if (tabtype[1] == 2 && tabtype[2] == 2)
	{
		if ((tabvalue[0] && !tabvalue[1]) || (!tabvalue[0] && tabvalue[1]))
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
		info->pc = pluspc(info->pc, 11);
	}	
	else if (tabtype[1] == 2 && tabtype[2] == 1)
	{
		if ((tabvalue[0] && !info->registre[tabvalue[1]]) ||
		(!tabvalue[0] && info->registre[tabvalue[1]]))
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
		info->pc = pluspc(info->pc, 8);
	}	
	else if (tabtype[1] == 2 && tabtype[2] == 3)
	{
		if ((tabvalue[0] && !info->ram[pluspc(info->pc, (tabvalue[1] % 512))]) ||
		(!tabvalue[0] && info->ram[pluspc(info->pc, (tabvalue[1] % 512))]))
			info->registre[tabvalue[2]] = 1;
		else
			info->registre[tabvalue[2]] = 0;
		info->pc = pluspc(info->pc, 9);
	}
	else
		xorr(info, tabtype, tabvalue);	
}

void	xor(t_stock *info)
{
	int *tabtype;
	int *tabvalue;

	tabtype = ft_downtype(info);
	tabvalue = ft_downvalue(info, tabtype, 0);
	xordi(info, tabtype, tabvalue);
	if (info->carry == 0)
		info->carry = 1;
	else
		info->carry = 0;
}
