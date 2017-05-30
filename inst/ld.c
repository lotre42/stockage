/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 13:57:52 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/30 02:53:57 by kahantar         ###   ########.fr       */
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
		info->registre[tabvalue[1]] = ((info->ram[info->pc + (tabvalue[0] % 512)]) << 24)
		   	| (((info->ram[info->pc + 1 + (tabvalue[0] % 512)]) << 16) & 0x00ffffff)
		   	| (((info->ram[info->pc + 2 + (tabvalue[0] % 512)]) << 8) & 0x0000ffff)
		    | ((info->ram[info->pc + 3 + (tabvalue[0] % 512)]) & 0x000000ff);
	}
	else if (tabtype[1] == 2)
		info->registre[tabvalue[1]] = tabvalue[0];	
	if (info->carry == 0)
		info->carry = 1;
	else
		info->carry = 0;
}
