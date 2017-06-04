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

void	ldi(t_stock *info)
{
	int S;
	int *tabtype;
	int *tabvalue;

	tabtype = ft_downtype(info);
	tabvalue = ft_downvalue(info, tabtype, 1);
	if (tabtype[1] == 3 && tabtype[2] == 2)
	{
		S = ((info->ram[pluspc(info->pc, (tabvalue[0] % 512))] << 8) & 0xff00)|
		   	((info->ram[pluspc(info->pc, 1 + (tabvalue[0] % 512))] & 0x00ff)) + tabvalue[1];
		info->registre[tabvalue[2]] = (((info->ram[pluspc(info->pc, (S % 512))] << 24) & 0xff000000)|
		   	((info->ram[pluspc(info->pc, 1 + (S % 512))] << 16) & 0x00ff0000) |
		   	((info->ram[pluspc(info->pc, 2 + (S % 512))] << 8) & 0x0000ff00) |
		   	((info->ram[pluspc(info->pc, 3 + (S % 512))]) & 0x000000ff));
		info->pc = pluspc(info->pc, 6);
	}
	else if (tabtype[1] == 3 && tabtype[2] == 3)
	{
		S = ((info->ram[pluspc(info->pc, (tabvalue[0] % 512))] << 8) & 0xff00) |
		   	((info->ram[pluspc(info->pc, 1 + (tabvalue[0] % 512))] & 0x00ff)) + info->ram[pluspc(info->pc, (tabvalue[1] % 512))];
		info->registre[tabvalue[2]] = ((info->ram[pluspc(info->pc, (S % 512))] << 24) |
		   	((info->ram[pluspc(info->pc, 1 + (S % 512))] << 16) & 0x00ffffff) |
		   	((info->ram[pluspc(info->pc, 2 + (S % 512))] << 8) & 0x0000ffff) |
		   	((info->ram[pluspc(info->pc, 3 + (S % 512))]) & 0x000000ff));
		info->pc = pluspc(info->pc, 6);
	}
	else if (tabtype[1] == 1 && tabtype[2] == 3)
	{
		S = info->registre[tabvalue[0]] + info->ram[pluspc(info->pc, (tabvalue[1] % 512))];
		info->registre[tabvalue[2]] = (((info->ram[pluspc(info->pc, (S % 512))] << 24) & 0xff000000)|
		   	((info->ram[pluspc(info->pc, 1 + (S % 512))] << 16) & 0x00ff0000) |
		   	((info->ram[pluspc(info->pc, 2 + (S % 512))] << 8) & 0x0000ff00) |
		   	((info->ram[pluspc(info->pc, 3 + (S % 512))]) & 0x000000ff));
		info->pc = pluspc(info->pc, 5);
	}
	else if (tabtype[1] == 1 && tabtype[2] == 2)
	{
		S = info->registre[tabvalue[0]] + tabvalue[1];
		info->registre[tabvalue[2]] = (((info->ram[pluspc(info->pc, (S % 512))] << 24) & 0xff000000) |
		   	((info->ram[pluspc(info->pc, 1 + (S % 512))] << 16) & 0x00ff0000) |
		   	((info->ram[pluspc(info->pc, 2 + (S % 512))] << 8) & 0x0000ff00) |
		   	((info->ram[pluspc(info->pc, 3 + (S % 512))]) & 0x000000ff));
		info->pc = pluspc(info->pc, 5);
	}
	else if (tabtype[1] == 2 && tabtype[2] == 1)
	{
		S = info->registre[tabvalue[1]] + tabvalue[0];
		info->registre[tabvalue[2]] = (((info->ram[pluspc(info->pc, (S % 512))] << 24) & 0xff000000) |
		   	((info->ram[pluspc(info->pc, 1 + (S % 512))] << 16) & 0x00ff0000) |
		   	((info->ram[pluspc(info->pc, 2 + (S % 512))] << 8) & 0x0000ff00) |
		   	((info->ram[pluspc(info->pc, 3 + (S % 512))]) & 0x000000ff));
		info->pc = pluspc(info->pc, 5);
	}
	else if (tabtype[1] == 1 && tabtype[2] == 3)
	{
		S = tabvalue[0] + info->ram[pluspc(info->pc, (tabvalue[1] % 512))];
		info->registre[tabvalue[2]] = (((info->ram[pluspc(info->pc, (S % 512))] << 24) & 0xff000000) |
		   	((info->ram[pluspc(info->pc, 1 + (S % 512))] << 16) & 0x00ff0000) |
		   	((info->ram[pluspc(info->pc, 2 + (S % 512))] << 8) & 0x0000ff00) |
		   	((info->ram[pluspc(info->pc, 3 + (S % 512))]) & 0x000000ff));
		info->pc = pluspc(info->pc, 5);
	}
	else
		info->pc = pluspc(info->pc, 1);
	//printf("%x", info->registre[1]);
}
