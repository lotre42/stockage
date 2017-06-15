/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 23:55:08 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/15 02:29:00 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

static void	cup4(t_process *process, unsigned char *ram, unsigned int *tabtype,
unsigned int *tabvalue)
{
	int pc;

	if (check_nb_reg(tabvalue[0]))
	{
		pc = mask_pc(process->pc, tabvalue[1] + tabvalue[2]);
		cpyint(ram, reverseint(process->registre[tabvalue[0] - 1]), pc);
	}
	process->pc = mask_pc(process->pc, 7);
}

static void	cup3(t_process *process, unsigned char *ram, unsigned int *tabtype,
unsigned int *tabvalue)
{
	int pc;

	if (check_nb_reg(tabvalue[0]))
	{
		pc = mask_pc(process->pc, process->registre[tabvalue[2] - 1] +
		tabvalue[1]);
		cpyint(ram, reverseint(process->registre[tabvalue[0] - 1]), pc);
	}
	process->pc = mask_pc(process->pc, 6);
}

static void	cup2(t_process *process, unsigned char *ram, unsigned int *tabtype,
unsigned int *tabvalue)
{
	int pc;

	if (check_nb_reg(tabvalue[0]))
	{
		pc = mask_pc(process->pc, process->registre[tabvalue[1] - 1] +
		tabvalue[2]);
		cpyint(ram, reverseint(process->registre[tabvalue[0] - 1]), pc);
	}
	process->pc = mask_pc(process->pc, 6);
}

static void	cup(t_process *process, unsigned char *ram, unsigned int *tabtype,
unsigned int *tabvalue)
{
	int pc;

	if (check_nb_reg(tabvalue[0]))
	{
		pc = mask_pc(process->pc, process->registre[tabvalue[1] - 1]
		+ process->registre[tabvalue[2] - 1]);
		cpyint(ram, reverseint(process->registre[tabvalue[0] - 1]), pc);
	}
	process->pc = mask_pc(process->pc, 5);
}

void		sti(t_process *process, unsigned char *ram)
{
	unsigned int	*tabtype;
	unsigned int	*tabvalue;
	int				pc;

	tabtype = ft_downtype(process, ram);
	tabvalue = ft_downvalue(process, tabtype, 1, ram);
	if (tabtype[2] == 1 && tabtype[3] == 1)
		cup(process, ram, tabtype, tabvalue);
	else if (tabtype[2] == 1 && (tabtype[3] == 2 || tabtype[3] == 3))
		cup2(process, ram, tabtype, tabvalue);
	else if (tabtype[3] == 1 && (tabtype[2] == 2 || tabtype[2] == 3))
		cup3(process, ram, tabtype, tabvalue);
	else if ((tabtype[2] == 2 && tabtype[3] == 2) ||
	(tabtype[2] == 3 && tabtype[3] == 3)
	|| (tabtype[2] == 3 && tabtype[3] == 3) ||
	(tabtype[2] == 3 && tabtype[3] == 2))
		cup4(process, ram, tabtype, tabvalue);
	else
		process->pc = mask_pc(process->pc, 1);
}
