/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:23:53 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/04 05:02:30 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

void	st(t_process *process, unsigned char *ram)
{
	unsigned int *tabtype;
	unsigned int *tabvalue;
	int pc;

	if (ram[process->pc + 1] != 80 && ram[process->pc + 1] != 112)
	{
		process->pc = mask_pc(process->pc, 1);
		return ;
	}
	tabtype = ft_downtype(process, ram);
	tabvalue = ft_downvalue(process, tabtype, 0, ram);
	if (tabtype[2] == 3)
	{
		if (check_nb_reg(tabvalue[0]))
		{
			pc = mask_pc(process->pc, (tabvalue[1] % 512));
			cpyint(ram, reverseint(process->registre[tabvalue[0] - 1]), pc);
		}
		process->pc = mask_pc(process->pc, 5);
	}
	else if (tabtype[2] == 1)
	{
		if (check_nb_reg(tabvalue[1]) && check_nb_reg(tabvalue[0]))
			process->registre[tabvalue[1] - 1] = process->registre[tabvalue[0] - 1];
		process->pc = mask_pc(process->pc, 4);
	}
	else
		process->pc = mask_pc(process->pc, 1);
}


