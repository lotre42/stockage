/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 13:57:52 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/24 03:52:10 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ld(t_stock *info, int pc)
{
	int *tabtype;
	int	*tabvalue;
	
	tabtype = ft_downtype(info, pc);
	tabvalue = ft_downvalue(info, tabtype, pc);
	if (tabtype[1] == 3)
	{
		info->registre[tabvalue[1]] = (info->ram[pc + (tabvalue[0] % 512)] << 24) |
	   		(info->ram[pc + (tabvalue[0] % 512) + 1] << 16) |
	   		(info->ram[pc + (tabvalue[0] % 512) + 2] << 8) |
	   		(info->ram[pc + (tabvalue[0] % 512) + 3]);
	}
	else if (tabtype[1] == 2)
		info->registre[tabvalue[1]] = tabvalue[0];	
	if (info->carry == 0)
		info->carry = 1;
	else
		info->carry = 0;
}
