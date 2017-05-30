/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:31:17 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/30 05:07:10 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	sub(t_stock *info)
{
	int *tabtype;
	int *tabvalue;

	tabtype = ft_downtype(info);
	tabvalue = ft_downvalue(info, tabtype, 0);
	info->registre[tabvalue[2]] = info->registre[tabvalue[0]] -
	   	info->registre[tabvalue[1]];
	if (info->registre[tabvalue[2]] == 0)
		info->carry = 1;
	else
		info->carry = 0;
}
