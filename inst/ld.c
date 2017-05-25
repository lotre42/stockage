/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 13:57:52 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/25 08:35:03 by kahantar         ###   ########.fr       */
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
		info->registre[tabvalue[1]] = *(unsigned int*)((void *)((info->ram + pc + (tabvalue[0] % 512))));
		printf("%x", info->registre[3]);
	}
	else if (tabtype[1] == 2)
		info->registre[tabvalue[1]] = tabvalue[0];	
	if (info->carry == 0)
		info->carry = 1;
	else
		info->carry = 0;
}
