/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 23:43:45 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/15 01:56:17 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static void	cup3(t_process *process, unsigned char *ram, unsigned int *tabvalue)
{
	int s;

	if (check_nb_reg(tabvalue[2]))
	{
		s = process->registre[tabvalue[1] - 1] + tabvalue[0];
		process->registre[tabvalue[2] - 1] =
		loadint(ram, process->pc + (s % IDX_MOD));
	}
	process->pc = mask_pc(process->pc, 5);
}

static void	cup2(t_process *process, unsigned char *ram, unsigned int *tabvalue)
{
	int s;

	if (check_nb_reg(tabvalue[2]))
	{
		s = process->registre[tabvalue[0] - 1] + tabvalue[1];
		process->registre[tabvalue[2] - 1] =
		loadint(ram, process->pc + (s % IDX_MOD));
	}
	process->pc = mask_pc(process->pc, 5);
}

static void	cup(t_process *process, unsigned char *ram, unsigned int *tabvalue)
{
	int s;

	if (check_nb_reg(tabvalue[2]))
	{
		s = tabvalue[0] + tabvalue[1];
		process->registre[tabvalue[2] - 1] =
		loadint(ram, process->pc + (s % IDX_MOD));
	}
	process->pc = mask_pc(process->pc, 6);
}

void		ldi(t_process *process, unsigned char *ram)
{
	unsigned int	*tabtype;
	unsigned int	*tabvalue;

	tabtype = ft_downtype(process, ram);
	tabvalue = ft_downvalue(process, tabtype, 1, ram);
	if ((tabtype[1] == 3 && tabtype[2] == 2) ||
	(tabtype[1] == 3 && tabtype[2] == 3) ||
	(tabtype[1] == 1 && tabtype[2] == 3))
		cup(process, ram, tabvalue);
	else if (tabtype[1] == 1 && (tabtype[2] == 3 || tabtype[2] == 2))
		cup2(process, ram, tabvalue);
	else if (tabtype[1] == 2 && tabtype[2] == 1)
		cup3(process, ram, tabvalue);
	else
		process->pc = mask_pc(process->pc, 1);
	if (process->carry == 0)
		process->carry = 1;
	else
		process->carry = 0;
}
