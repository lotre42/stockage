/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:29:20 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/24 03:55:45 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/corewar.h"

void	add(t_stock *info, int pc)
{
	int *tabtype;
	int *tabvalue;

	tabtype = ft_downtype(info, pc);
	tabvalue = ft_downvalue(info, tabtype, pc);
	info->registre[tabvalue[2]] = info->registre[tabvalue[0]] +
	   	info->registre[tabvalue[1]];
	if (info->registre[tabvalue[2]] == 0)
		info->carry = 1;
	else
		info->carry = 0;
}
