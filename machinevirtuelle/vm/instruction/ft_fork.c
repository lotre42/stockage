/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 16:31:06 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/15 01:27:29 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int	cpstok(t_process *new, t_process *tmp, int nb)
{
	int i;

	i = 0;
	new->live = 0;
	new->nbplayer = tmp->nbplayer;
	new->carry = tmp->carry;
	new->pc = mask_pc(tmp->pc, (nb % IDX_MOD));
	new->nbcycle = 0;
	new->tmp = 0;
	new->registre = init_tab(16);
	while (i < 16)
	{
		new->registre[i] = tmp->registre[i];
		i++;
	}
	new->next = NULL;
	return (1);
}

int			ft_fork(t_process *process, unsigned char *ram)
{
	t_process	*new;
	t_process	*tmp;
	int			nb;

	tmp = process;
	if (!(new = malloc(sizeof(t_process))))
		return (0);
	nb = ((ram[mask_pc(process->pc, 1)] << 8) & 0xff00) |
	((ram[mask_pc(process->pc, 2)]) & 0x00ff);
	cpstok(new, process, nb);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	process->pc = mask_pc(process->pc, 3);
	return (1);
}
