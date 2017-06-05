/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 13:57:52 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/04 04:55:34 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ld(t_stock *info, char *ram)
{
	int *tabtype;
	int	*tabvalue;

	tabtype = ft_downtype(info, ram);
	tabvalue = ft_downvalue(info, tabtype, 0, ram);
	if (tabtype[1] == 3)
	{
		info->registre[tabvalue[1]] = ((ram[(info->pc + (tabvalue[0] % 512))] << 24) & 0xff000000)
		   	| ((ram[info->pc + 1 + (tabvalue[0] % 512)] << 16) & 0x00ff0000)
		   	| ((ram[info->pc + 2 + (tabvalue[0] % 512)] << 8) & 0x0000ff00)
		    | (ram[info->pc + 3 + (tabvalue[0] % 512)] & 0x000000ff);
		info->pc = info->pc + 5;
	}
	else if (tabtype[1] == 2)
	{
		info->registre[tabvalue[1]] = tabvalue[0];
		info->pc = info->pc + 7;
	}
	else
		info->pc = (info->pc + 1);
	if (info->carry == 0)
		info->carry = 1;
	else
		info->carry = 0;
}
