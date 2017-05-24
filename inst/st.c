/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:23:53 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/24 03:45:40 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/corewar.h"

void	st(t_stock *info, int pc)
{
	int	*tabtype;
	int *tabvalue;

	tabtype = ft_downtype(info, pc);
	tabvalue = ft_downvalue(info, tabtype, pc);
	if (tabtype[2] == 3)
	{
		pc = info->pc + (tabvalue[1] % 512);
		info->ram[pc] = info->registre[tabvalue[0]];
	}
	else
		info->registre[tabvalue[1]] = info->registre[tabvalue[0]];
}

