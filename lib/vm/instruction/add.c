/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:29:20 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/15 01:24:52 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

void	add(t_process *process, unsigned char *ram)
{
	unsigned int *tabtype;
	unsigned int *tabvalue;

	tabtype = ft_downtype(process, ram);
	tabvalue = ft_downvalue(process, tabtype, 0, ram);
	if (check_nb_reg(tabvalue[2]) && check_nb_reg(tabvalue[1]) &&
	check_nb_reg(tabvalue[0]))
		process->registre[tabvalue[2] - 1] = process->registre[tabvalue[0] - 1]
		+ process->registre[tabvalue[1] - 1];
	process->pc = mask_pc(process->pc, 5);
	if (check_nb_reg(tabvalue[2]))
	{
		if (process->registre[tabvalue[2] - 1] == 0)
			process->carry = 1;
		else
			process->carry = 0;
	}
}
