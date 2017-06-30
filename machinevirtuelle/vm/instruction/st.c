/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:23:53 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/15 02:11:33 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		st_rev(unsigned int *tabvalue,
t_process *process, unsigned char *ram)
{
	unsigned char *rev;

	rev = reverseint(process->registre[tabvalue[0] - 1]);
	cpyint(ram, rev,
	mask_pc(process->pc, (tabvalue[1] % IDX_MOD)));
	free(rev);
}

void		st(t_process *process, unsigned char *ram)
{
	unsigned int	*tabtype;
	unsigned int	*tabvalue;

	tabtype = ft_downtype(process, ram);
	tabvalue = ft_downvalue(process, tabtype, 0, ram);
	if (tabtype[2] == 3)
	{
		if (check_nb_reg(tabvalue[0]))
			st_rev(tabvalue, process, ram);
		process->pc = mask_pc(process->pc, 5);
	}
	else if (tabtype[2] == 1)
	{
		if (check_nb_reg(tabvalue[1]) && check_nb_reg(tabvalue[0]))
		{
			process->registre[tabvalue[1] - 1] =
			process->registre[tabvalue[0] - 1];
		}
		process->pc = mask_pc(process->pc, 4);
	}
	else
		process->pc = mask_pc(process->pc, 1);
	free_tab(tabtype, tabvalue);
}
