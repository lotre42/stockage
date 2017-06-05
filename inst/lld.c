/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 15:36:54 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/04 05:00:17 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	lld(t_stock *info, char *ram)
{
	int *tabtype;
	int	*tabvalue;

	tabtype = ft_downtype(info, ram);
	tabvalue = ft_downvalue(info, tabtype, 0, ram);
	if (tabtype[1] == 3)
	{
		info->registre[tabvalue[1]] = (ram[(info->pc + (tabvalue[0]))] << 24)
		   	| ((ram[(info->pc + 1 + (tabvalue[0]))] << 16) & 0x00ffffff)
		   	| ((ram[(info->pc + 2 + (tabvalue[0]))] << 8) & 0x0000ffff)
		    | (ram[(info->pc + 3 + (tabvalue[0]))] & 0x000000ff);
		info->pc = (info->pc + 5);
	}
	else if (tabtype[1] == 2)
	{
		info->registre[tabvalue[1]] = tabvalue[0];
		info->pc = (info->pc + 7);
	}
	else
		info->pc = (info->pc + 1);
	if (info->carry == 0)
		info->carry = 1;
	else
		info->carry = 0;
}
