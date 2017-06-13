/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:36:27 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/11 01:21:00 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

static void xorid(t_process *process, unsigned int *tabtype, unsigned int *tabvalue, unsigned char *ram)
{
	if (tabtype[1] == 3 && tabtype[2] == 3)
	{
		if ((ram[mask_pc(process->pc, (tabvalue[0] % 512))] && !ram[mask_pc(process->pc, (tabvalue[1] % 512))])
		|| (ram[mask_pc(process->pc, (tabvalue[1] % 512))] && !ram[mask_pc(process->pc, (tabvalue[0] % 512))]))
			process->registre[tabvalue[2] - 1] = 1;
		else
			process->registre[tabvalue[2] - 1] = 0;
		process->pc = mask_pc(process->pc, 7);
	}
	else if (tabtype[1] == 3 && tabtype[2] == 1)
	{
		if ((ram[mask_pc(process->pc, (tabvalue[0] % 512))] && !process->registre[tabvalue[1] - 1]) ||
		 (!ram[mask_pc(process->pc, (tabvalue[0] % 512))] && process->registre[tabvalue[1] - 1]))
			process->registre[tabvalue[2] - 1] = 1;
		else
			process->registre[tabvalue[2] - 1] = 0;
		process->pc = mask_pc(process->pc, 6);
	}
	else if (tabtype[1] == 3 && tabtype[2] == 2)
	{
		if ((tabvalue[1] && !ram[mask_pc(process->pc, (tabvalue[0] % 512))]) ||
		 (!tabvalue[1] || ram[mask_pc(process->pc, (tabvalue[0] % 512))]))
			process->registre[tabvalue[2] - 1] = 1;
		else
			process->registre[tabvalue[2] - 1] = 0;
		process->pc = mask_pc(process->pc, 9);
	}
	else
		process->pc = mask_pc(process->pc, 1);
}

static void xorr(t_process *process,  unsigned int *tabtype, unsigned int *tabvalue, unsigned char *ram)
{
	if (tabtype[1] == 1 && tabtype[2] == 1)
	{
		if ((process->registre[tabvalue[0] - 1] && !process->registre[tabvalue[1] - 1]) ||
		(!process->registre[tabvalue[0] - 1] && process->registre[tabvalue[1] - 1]))
			process->registre[tabvalue[2] - 1] = 1;
		else
			process->registre[tabvalue[2] - 1] = 0;
		process->pc = mask_pc(process->pc, 5);
	}	
	else if (tabtype[1] == 1 && tabtype[2] == 2)
	{
		if ((process->registre[tabvalue[0] - 1] && !tabvalue[1]) ||
		(!process->registre[tabvalue[0] - 1] && tabvalue[1]))
			process->registre[tabvalue[2] - 1] = 1;
		else
			process->registre[tabvalue[2] - 1] = 0;
		process->pc = mask_pc(process->pc, 8);
	}	
	else if (tabtype[1] == 1 && tabtype[2] == 3)
	{
		if ((process->registre[tabvalue[0] - 1] && !ram[mask_pc(process->pc, (tabvalue[1] % 512))]) ||
		(!process->registre[tabvalue[0] - 1] && ram[mask_pc(process->pc, (tabvalue[1] % 512))]))
			process->registre[tabvalue[2] - 1] = 1;
		else
			process->registre[tabvalue[2] - 1] = 0;
		process->pc = mask_pc(process->pc, 6);
	}
	else
		xorid(process, tabtype, tabvalue, ram);	
}

static void xordi(t_process *process, unsigned int *tabtype, unsigned int *tabvalue, unsigned char *ram)
{	
	if (tabtype[1] == 2 && tabtype[2] == 2)
	{
		if ((tabvalue[0] && !tabvalue[1]) || (!tabvalue[0] && tabvalue[1]))
			process->registre[tabvalue[2] - 1] = 1;
		else
			process->registre[tabvalue[2] - 1] = 0;
		process->pc = mask_pc(process->pc, 11);
	}	
	else if (tabtype[1] == 2 && tabtype[2] == 1)
	{
		if ((tabvalue[0] && !process->registre[tabvalue[1] - 1]) ||
		(!tabvalue[0] && process->registre[tabvalue[1] - 1]))
			process->registre[tabvalue[2] - 1] = 1;
		else
			process->registre[tabvalue[2] - 1] = 0;
		process->pc = mask_pc(process->pc, 8);
	}	
	else if (tabtype[1] == 2 && tabtype[2] == 3)
	{
		if ((tabvalue[0] && !ram[mask_pc(process->pc, (tabvalue[1] % 512))]) ||
		(!tabvalue[0] && ram[mask_pc(process->pc, (tabvalue[1] % 512))]))
			process->registre[tabvalue[2] - 1] = 1;
		else
			process->registre[tabvalue[2] - 1] = 0;
		process->pc = mask_pc(process->pc, 9);
	}
	else
		xorr(process, tabtype, tabvalue, ram);	
}

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


void	xor(t_process *process, unsigned char *ram)
{
	unsigned int *tabtype;
	unsigned int *tabvalue;
	
	if (!check_nb_reg(tabvalue[2]))
	{
		pluspc(tabtype, process);
		return ;
	}
	tabtype = ft_downtype(process, ram);
	tabvalue = ft_downvalue(process, tabtype, 0, ram);
	xordi(process, tabtype, tabvalue, ram);
	if (process->registre[tabvalue[2] - 1] == 0)
		process->carry = 1;
	else
		process->carry = 0;
}
