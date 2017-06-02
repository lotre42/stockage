/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 13:57:52 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/03 01:28:06 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ld(t_stock *info)
{
	int *tabtype;
	int	*tabvalue;

	tabtype = ft_downtype(info);
	tabvalue = ft_downvalue(info, tabtype, 0);
	if (tabtype[1] == 3)
	{
		info->registre[tabvalue[1]] = ((info->ram[pluspc(info->pc, (tabvalue[0] % 512))] << 24) & 0xff000000)
		   	| ((info->ram[pluspc(info->pc, 1 + (tabvalue[0] % 512))] << 16) & 0x00ff0000)
		   	| ((info->ram[pluspc(info->pc, 2 + (tabvalue[0] % 512))] << 8) & 0x0000ff00)
		    | (info->ram[pluspc(info->pc, 3 + (tabvalue[0] % 512))] & 0x000000ff);
		info->pc = pluspc(info->pc, 5);
	}
	else if (tabtype[1] == 2)
	{
		info->registre[tabvalue[1]] = tabvalue[0];
		info->pc = pluspc(info->pc, 7);
	}
	if (info->carry == 0)
		info->carry = 1;
	else
		info->carry = 0;
}
