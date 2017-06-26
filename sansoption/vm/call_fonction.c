/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_fonction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 21:07:34 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/09 21:07:35 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void	next_fonction(t_process *process, unsigned char *ram)
{
	if (ram[process->pc] == 0x0a)
		ldi(process, ram);
	else if (ram[process->pc] == 0x0b)
		sti(process, ram);
	else if (ram[process->pc] == 0x0c)
		ft_fork(process, ram);
	else if (ram[process->pc] == 0x0d)
		lld(process, ram);
	else if (ram[process->pc] == 0x0e)
		lldi(process, ram);
	else if (ram[process->pc] == 0x0f)
		lfork(process, ram);
	else
		process->pc = mask_pc(process->pc, 1);
}

int			call_fonction(unsigned char *ram, t_process *process, t_live *live,
unsigned int *nbplayer)
{
	if (ram[process->pc] == 0x01)
	{
		live->nblive++;
		ft_live(process, live, ram, nbplayer);
	}
	else if (ram[process->pc] == 0x02)
		ld(process, ram);
	else if (ram[process->pc] == 0x03)
		st(process, ram);
	else if (ram[process->pc] == 0x04)
		add(process, ram);
	else if (ram[process->pc] == 0x05)
		sub(process, ram);
	else if (ram[process->pc] == 0x06)
		and(process, ram);
	else if (ram[process->pc] == 0x07)
		or(process, ram);
	else if (ram[process->pc] == 0x08)
		xor(process, ram);
	else if (ram[process->pc] == 0x09)
		zjump(process, ram);
	else
		next_fonction(process, ram);
	process->tmp = 0;
	return (1);
}
