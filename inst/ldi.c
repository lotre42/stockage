/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 23:43:45 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/25 02:49:26 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/corewar.h"

void	ldi(t_stock *info, int pc)
{
	int S;
	int *tabtype;
	int *tabvalue;

	tabtype = ft_downtype(info, pc);
	tabvalue = ft_downvalue(info, tabtype, pc, 1);
	if (tabtype[1] == 3 && tabtype[2] == 2)
	{
		S = (info->ram[pc + (tabvalue[0] % 512)] << 8) |
		   	(info->ram[pc + 1 + (tabvalue[0] % 512)]) + tabvalue[1];
		info->registre[tabvalue[2]] = ((info->ram[pc + (S % 512)] << 24) |
		   	(info->ram[pc + 1 + (S % 512)] << 16) |
		   	(info->ram[pc + 2 + (S % 512)] << 8) |
		   	(info->ram[pc + 3 + (S % 512)]));
	}
	else if (tabtype[1] == 3 && tabtype[2] == 3)
	{
		S = (info->ram[pc + (tabvalue[0] % 512)] << 8) |
		   	(info->ram[pc + 1 + (tabvalue[0] % 512)]) + info->ram[pc + (tabvalue[1] % 512)];
		info->registre[tabvalue[2]] = ((info->ram[pc + (S % 512)] << 24) |
		   	(info->ram[pc + 1 + (S % 512)] << 16) |
		   	(info->ram[pc + 2 + (S % 512)] << 8) |
		   	(info->ram[pc + 3 + (S % 512)]));
	}
	else if (tabtype[1] == 1 && tabtype[2] == 3)
	{
		S = info->registre[tabvalue[0]] + info->ram[pc + (tabvalue[1] % 512)];
		info->registre[tabvalue[2]] = ((info->ram[pc + (S % 512)] << 24) |
		   	(info->ram[pc + 1 + (S % 512)] << 16) |
		   	(info->ram[pc + 2 + (S % 512)] << 8) |
		   	(info->ram[pc + 3 + (S % 512)]));
	}
	else if (tabtype[1] == 1 && tabtype[2] == 2)
	{
		S = info->registre[tabvalue[0]] + tabvalue[1];
		info->registre[tabvalue[2]] = ((info->ram[pc + (S % 512)] << 24) |
		   	(info->ram[pc + 1 + (S % 512)] << 16) |
		   	(info->ram[pc + 2 + (S % 512)] << 8) |
		   	(info->ram[pc + 3 + (S % 512)]));
	}
	else if (tabtype[1] == 2 && tabtype[2] == 1)
	{
		S = info->registre[tabvalue[1]] + tabvalue[0];
		info->registre[tabvalue[2]] = ((info->ram[pc + (S % 512)] << 24) |
		   	(info->ram[pc + 1 + (S % 512)] << 16) |
		   	(info->ram[pc + 2 + (S % 512)] << 8) |
		   	(info->ram[pc + 3 + (S % 512)]));
	}
	else if (tabtype[1] == 1 && tabtype[2] == 3)
	{
		S = tabvalue[0] + info->ram[pc + (tabvalue[1] % 512)];
		info->registre[tabvalue[2]] = ((info->ram[pc + (S % 512)] << 24) |
		   	(info->ram[pc + 1 + (S % 512)] << 16) |
		   	(info->ram[pc + 2 + (S % 512)] << 8) |
		   	(info->ram[pc + 3 + (S % 512)]));
	}
}
