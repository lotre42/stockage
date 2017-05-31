/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 15:38:57 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/01 01:12:30 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/corewar.h"

void	lldi(t_stock *info)
{
	int S;
	int *tabtype;
	int *tabvalue;

	tabtype = ft_downtype(info);
	tabvalue = ft_downvalue(info, tabtype, 1);
	if (tabtype[1] == 3 && tabtype[2] == 2)
	{
		S = (info->ram[info->pc + (tabvalue[0])] << 8) |
		   	((info->ram[info->pc + 1 + (tabvalue[0])] & 0x00ff)) + tabvalue[1];
		info->registre[tabvalue[2]] = ((info->ram[info->pc + (S)] << 24) |
		   	((info->ram[info->pc + 1 + (S)] << 16) & 0x00ffffff) |
		   	((info->ram[info->pc + 2 + (S)] << 8) & 0x0000ffff) |
		   	((info->ram[info->pc + 3 + (S)]) & 0x000000ff));
		info->pc = pluspc(info->pc, 6);
	}
	else if (tabtype[1] == 3 && tabtype[2] == 3)
	{
		S = (info->ram[info->pc + (tabvalue[0])] << 8) |
		   	(info->ram[info->pc + 1 + (tabvalue[0])]) + info->ram[info->pc + (tabvalue[1] % 512)];
		info->registre[tabvalue[2]] = ((info->ram[info->pc + (S)] << 24) |
		   	((info->ram[info->pc + 1 + (S)] << 16) & 0x00ffffff) |
		   	((info->ram[info->pc + 2 + (S)] << 8) & 0x0000ffff) |
		   	((info->ram[info->pc + 3 + (S)]) & 0x000000ff));
		info->pc = pluspc(info->pc, 6);
	}
	else if (tabtype[1] == 1 && tabtype[2] == 3)
	{
		S = info->registre[tabvalue[0]] + info->ram[info->pc + (tabvalue[1])];
		info->registre[tabvalue[2]] = ((info->ram[info->pc + (S)] << 24) |
		   	((info->ram[info->pc + 1 + (S)] << 16) & 0x00ffffff) |
		   	((info->ram[info->pc + 2 + (S)] << 8) & 0x0000ffff) |
		   	((info->ram[info->pc + 3 + (S)]) & 0x000000ff));
		info->pc = pluspc(info->pc, 5);
	}
	else if (tabtype[1] == 1 && tabtype[2] == 2)
	{
		S = info->registre[tabvalue[0]] + tabvalue[1];
		info->registre[tabvalue[2]] = ((info->ram[info->pc + (S % 512)] << 24) |
		   	((info->ram[info->pc + 1 + (S)] << 16) & 0x00ffffff) |
		   	((info->ram[info->pc + 2 + (S)] << 8) & 0x0000ffff) |
		   	((info->ram[info->pc + 3 + (S)]) & 0x000000ff));
		info->pc = pluspc(info->pc, 5);
	}
	else if (tabtype[1] == 2 && tabtype[2] == 1)
	{
		S = info->registre[tabvalue[1]] + tabvalue[0];
		info->registre[tabvalue[2]] = ((info->ram[info->pc + (S)] << 24) |
		   	((info->ram[info->pc + 1 + (S)] << 16) & 0x00ffffff) |
		   	((info->ram[info->pc + 2 + (S)] << 8) & 0x0000ffff) |
		   	((info->ram[info->pc + 3 + (S % 512)]) & 0x000000ff));
		info->pc = pluspc(info->pc, 5);
	}
	if (info->registre[tabvalue[2]] == 0)
		info->carry = 1;
	else
		info->carry = 0;
}
