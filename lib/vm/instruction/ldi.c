/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 23:43:45 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/11 01:16:38 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

void	ldi(t_process *process, unsigned char *ram)
{
	int S;
	unsigned int *tabtype;
	unsigned int *tabvalue;

	tabtype = ft_downtype(process, ram);
	tabvalue = ft_downvalue(process, tabtype, 1, ram);
	if ((tabtype[1] == 3 && tabtype[2] == 2) || (tabtype[1] == 3 && tabtype[2] == 3) || (tabtype[1] == 1 && tabtype[2] == 3))
	{
		if (check_nb_reg(tabvalue[2]))
		{
			S = tabvalue[0] + tabvalue[1];
			process->registre[tabvalue[2] - 1] = loadint(ram, process->pc + (S % IDX_MOD));
		}
		process->pc = mask_pc(process->pc, 6);
	}
	else if (tabtype[1] == 1 && tabtype[2] == 3)
	{
		if (check_nb_reg(tabvalue[2]))
		{
			S = process->registre[tabvalue[0] - 1] + tabvalue[1];
			process->registre[tabvalue[2] - 1] = loadint(ram, process->pc + (S % IDX_MOD));
		}
		process->pc = mask_pc(process->pc, 5);
	}
	else if (tabtype[1] == 1 && tabtype[2] == 2)
	{
		if (check_nb_reg(tabvalue[2]))
		{
			S = process->registre[tabvalue[0] - 1] + tabvalue[1];
			process->registre[tabvalue[2] - 1] = loadint(ram, process->pc + (S % IDX_MOD));
		}	
		process->pc = mask_pc(process->pc, 5);
	}
	else if (tabtype[1] == 2 && tabtype[2] == 1)
	{
		if (check_nb_reg(tabvalue[2]))
		{
			S = process->registre[tabvalue[1] - 1] + tabvalue[0];
			process->registre[tabvalue[2] - 1] = loadint(ram, process->pc + (S % IDX_MOD));
		}
		process->pc = mask_pc(process->pc, 5);
	}
	else
		process->pc = mask_pc(process->pc, 1);
	if (process->carry == 0)
		process->carry = 1;
	else
		process->carry = 0;
}
