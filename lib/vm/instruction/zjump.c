/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:37:32 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/04 04:58:00 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

void	zjump(t_process *process, unsigned char *ram)
{
	short i;
	
	i = ((ram[mask_pc(process->pc, 1)] << 8) & 0xff00) | (ram[mask_pc(process->pc, 2)] & 0x00ff);
	if (process->carry == 1 && i != 0)
		process->pc = mask_pc(process->pc, (i % 512));
	else
		process->pc = mask_pc(process->pc, 3);
}

