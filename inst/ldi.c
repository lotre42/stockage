/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 23:43:45 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/30 08:17:00 by kahantar         ###   ########.fr       */
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
		S = (info->ram[info->pc + (tabvalue[0] % 512)] << 8) |
		   	((info->ram[info->pc + 1 + (tabvalue[0] % 512)] & 0x00ff)) + tabvalue[1];
		info->registre[tabvalue[2]] = ((info->ram[info->pc + (S % 512)] << 24) |
		   	((info->ram[info->pc + 1 + (S % 512)] << 16) & 0x00ffffff) |
		   	((info->ram[info->pc + 2 + (S % 512)] << 8) & 0x0000ffff) |
		   	((info->ram[info->pc + 3 + (S % 512)]) & 0x000000ff));
	}
	else if (tabtype[1] == 3 && tabtype[2] == 3)
	{
		S = (info->ram[info->pc + (tabvalue[0] % 512)] << 8) |
		   	(info->ram[info->pc + 1 + (tabvalue[0] % 512)]) + info->ram[info->pc + (tabvalue[1] % 512)];
		info->registre[tabvalue[2]] = ((info->ram[info->pc + (S % 512)] << 24) |
		   	((info->ram[info->pc + 1 + (S % 512)] << 16) & 0x00ffffff) |
		   	((info->ram[info->pc + 2 + (S % 512)] << 8) & 0x0000ffff) |
		   	((info->ram[info->pc + 3 + (S % 512)]) & 0x000000ff));
	}
	else if (tabtype[1] == 1 && tabtype[2] == 3)
	{
		S = info->registre[tabvalue[0]] + info->ram[info->pc + (tabvalue[1] % 512)];
		info->registre[tabvalue[2]] = ((info->ram[info->pc + (S % 512)] << 24) |
		   	((info->ram[info->pc + 1 + (S % 512)] << 16) & 0x00ffffff) |
		   	((info->ram[info->pc + 2 + (S % 512)] << 8) & 0x0000ffff) |
		   	((info->ram[info->pc + 3 + (S % 512)]) & 0x000000ff));
	}
	else if (tabtype[1] == 1 && tabtype[2] == 2)
	{
		S = info->registre[tabvalue[0]] + tabvalue[1];
		info->registre[tabvalue[2]] = ((info->ram[info->pc + (S % 512)] << 24) |
		   	((info->ram[info->pc + 1 + (S % 512)] << 16) & 0x00ffffff) |
		   	((info->ram[info->pc + 2 + (S % 512)] << 8) & 0x0000ffff) |
		   	((info->ram[info->pc + 3 + (S % 512)]) & 0x000000ff));
	}
	else if (tabtype[1] == 2 && tabtype[2] == 1)
	{
		S = info->registre[tabvalue[1]] + tabvalue[0];
		info->registre[tabvalue[2]] = ((info->ram[info->pc + (S % 512)] << 24) |
		   	((info->ram[info->pc + 1 + (S % 512)] << 16) & 0x00ffffff) |
		   	((info->ram[info->pc + 2 + (S % 512)] << 8) & 0x0000ffff) |
		   	((info->ram[info->pc + 3 + (S % 512)]) & 0x000000ff));
	}
	else if (tabtype[1] == 1 && tabtype[2] == 3)
	{
		S = tabvalue[0] + info->ram[info->pc + (tabvalue[1] % 512)];
		info->registre[tabvalue[2]] = ((info->ram[info->pc + (S % 512)] << 24) |
		   	((info->ram[info->pc + 1 + (S % 512)] << 16) & 0x00ffffff) |
		   	((info->ram[info->pc + 2 + (S % 512)] << 8) & 0x0000ffff) |
		   	((info->ram[info->pc + 3 + (S % 512)]) & 0x000000ff));
	}
	if (info->registre[tabvalue[2]] == 0)
		info->carry = 1;
	else
		info->carry = 0;
}
