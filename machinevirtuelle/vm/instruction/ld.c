/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 13:57:52 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/15 01:37:49 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	ld(t_process *process, unsigned char *ram)
{
	unsigned int	*tabtype;
	unsigned int	*tabvalue;

	tabtype = ft_downtype(process, ram);
	tabvalue = ft_downvalue(process, tabtype, 0, ram);
	if (tabtype[1] == 3)
	{
		if (check_nb_reg(tabvalue[1]))
		{
			process->registre[tabvalue[1] - 1] =
			loadint(ram, process->pc + (tabvalue[0] % 512));
		}
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
	if (tabtype)
		free(tabtype);
	if (tabvalue)
		free(tabvalue);
}
