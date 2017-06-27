/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_of_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 04:50:22 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/15 04:55:16 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void	nb2(t_process *process, unsigned char *ram)
{
	if (ram[process->pc] == 11)
		process->nbcycle = 25;
	else if (ram[process->pc] == 12)
		process->nbcycle = 800;
	else if (ram[process->pc] == 13)
		process->nbcycle = 10;
	else if (ram[process->pc] == 14)
		process->nbcycle = 50;
	else if (ram[process->pc] == 15)
		process->nbcycle = 1000;
	else
		process->nbcycle = 0;
}

void		nb_of_cycle(t_process *process, unsigned char *ram)
{
	if (ram[process->pc] == 1)
		process->nbcycle = 10;
	else if (ram[process->pc] == 2)
		process->nbcycle = 5;
	else if (ram[process->pc] == 3)
		process->nbcycle = 5;
	else if (ram[process->pc] == 4)
		process->nbcycle = 10;
	else if (ram[process->pc] == 5)
		process->nbcycle = 10;
	else if (ram[process->pc] == 6)
		process->nbcycle = 6;
	else if (ram[process->pc] == 7)
		process->nbcycle = 6;
	else if (ram[process->pc] == 8)
		process->nbcycle = 6;
	else if (ram[process->pc] == 9)
		process->nbcycle = 20;
	else if (ram[process->pc] == 10)
		process->nbcycle = 25;
	else
		nb2(process, ram);
	process->tmp = 1;
}
