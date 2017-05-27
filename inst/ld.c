/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 13:57:52 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/25 09:44:17 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ld(t_stock *info, int pc)
{
	int *tabtype;
	int	*tabvalue;
	
	tabtype = ft_downtype(info, pc);
	tabvalue = ft_downvalue(info, tabtype, pc, 0);
	if (tabtype[1] == 3)
	{
		info->registre[tabvalue[1]] = ((info->ram[pc + (tabvalue[0] % 512)]) << 24)
		   	| (((info->ram[pc + 1 + (tabvalue[0] % 512)]) << 16) & 0x00ffffff)
		   	| (((info->ram[pc + 2 + (tabvalue[0] % 512)]) << 8) & 0x0000ffff)
		    | ((info->ram[pc + 3 + (tabvalue[0] % 512)]) & 0x000000ff);
		printf("%x", (int)info->registre[tabvalue[1]]);
	}
	else if (tabtype[1] == 2)
		info->registre[tabvalue[1]] = tabvalue[0];	
	if (info->carry == 0)
		info->carry = 1;
	else
		info->carry = 0;
}
