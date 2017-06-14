/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:35:06 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/11 01:20:09 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

static void	pluspc(unsigned int *tabtype, t_process *process)
{
	if ((tabtype[1] == 2 && tabtype[2] == 3) || (tabtype[1] == 3 && tabtype[2] == 2))
		process->pc = mask_pc(process->pc, 9);
	else if ((tabtype[1] == 2 && tabtype[2] == 1) && (tabtype[1] == 1 && tabtype[2] == 2))
		process->pc = mask_pc(process->pc, 8);
	else if ((tabtype[1] == 2 && tabtype[2] == 2))
		process->pc = mask_pc(process->pc, 11);
	else if ((tabtype[1] == 3 && tabtype[2] == 1) && (tabtype[1] == 1 && tabtype[2] == 3))
		process->pc = mask_pc(process->pc, 6);
	else if (tabtype[1] == 1 && tabtype[2] == 1)
		process->pc = mask_pc(process->pc, 5);
	else if (tabtype[1] == 3 && tabtype[2] == 3)
		process->pc = mask_pc(process->pc, 5);
	else
		process->pc = mask_pc(process->pc, 1);
}

void	or(t_process *process, unsigned char *ram)
{
	unsigned int *tabtype;
	unsigned int *tabvalue;
	unsigned int *val;

	tabtype = ft_downtype(process, ram);
	tabvalue = ft_downvalue(process, tabtype, 0, ram);
	if (!check_nb_reg(tabvalue[2]))
	{
		pluspc(tabtype, process);
		return ;
	}
	val = load_value(process, ram, tabtype, tabvalue);
	if (val[0] || val[1])
		process->registre[tabvalue[2] - 1] = 1;
	else
		process->registre[tabvalue[2] - 1] = 0;
	if (process->registre[tabvalue[2] - 1] == 0)
		process->carry = 1;
	else
		process->carry = 0;
}
