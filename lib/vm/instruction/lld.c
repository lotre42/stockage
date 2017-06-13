/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 15:36:54 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/11 01:15:38 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

void	lld(t_process *process, unsigned char *ram)
{
	unsigned int *tabtype;
	unsigned int *tabvalue;

	tabtype = ft_downtype(process, ram);
	tabvalue = ft_downvalue(process, tabtype, 0, ram);
	if (tabtype[1] == 3)
	{
		if (check_nb_reg(tabvalue[1]))
			process->registre[tabvalue[1] - 1] = loadint(ram, process->pc + tabvalue[0]);
		process->pc = mask_pc(process->pc, 5);
	}
	else if (tabtype[1] == 2)
	{
		if (check_nb_reg(tabvalue[1]))
			process->registre[tabvalue[1] - 1] = tabvalue[0];
		process->pc = mask_pc(process->pc, 7);
	}
	else
		process->pc = mask_pc(process->pc, 1);
	process->carry = 1;
}
