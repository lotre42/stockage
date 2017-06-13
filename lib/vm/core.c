/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:55:04 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/09 16:55:06 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static void		delete_process(t_process *process, int i)
{
	t_process	*tmp;

	
	if (process == NULL)
	 	return;
	while (--i)
		process = process->next;
	tmp = process->next;
	process->next = tmp->next;
	ft_memdel((void**)&tmp);
}

static void		check_dead(t_process *process)
{
	int i;
	t_process *tmp2;
	t_process *tmp;

	i = 0;
	tmp = process;
	while (tmp)
	{
		tmp2 = NULL;
		if (tmp->live == 0 && i > 1 && process)
			delete_process(process, i);
		else if (tmp->live == 0 && i == 1 && process)
		{
			tmp2 = process->next;
		if (tmp2 != NULL)
			process = (process->next)->next;
		else
			process->next = NULL;
		}
		else if(tmp->live == 0 && i == 0 && process)
		{
			tmp2 = process;
			process = process->next;
			//free(tmp2);
		}
		tmp = tmp->next;
		i++;
	}
}

static void 		zero_process(t_process *process, t_live *live)
{
	int i;

	i = 0;
	if (!process)
		return ;
	while (process)
	{
		// ft_putnbr(process->live);
		 process->live = 0;
		// ft_putchar(' ');
		 if (process->next == NULL)
		 	break;
		process = process->next;
		i++;
	}
	if (i < 2)
		ft_putendl("bonjour");
	// ft_putchar('\n');
	// if (i == 0)
		// printf("%x", live->lastlive);

}

static void			check_live_dead(t_process *process, int *cycletodie,
 t_live *live, int *nbchecks)
{
	if (live->nblive >= NBR_LIVE || *nbchecks == MAX_CHECKS)
	{
		*nbchecks = 0;
		live->nblive = 0;
		*cycletodie = *cycletodie - CYCLE_DELTA;
	}
	else
		*nbchecks = *nbchecks + 1;
	// check_dead(process);
	// zero_process(process, live);
}

static void		check_winner(t_process *process, t_live *live)
{
	t_process *tmp;
	int i;

	i = 0;
	tmp = process;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	if (i != 1)
		printf("%d", live->lastlive);
	else
		printf("%d", process->nbplayer);

}

int		core(unsigned char *ram, t_process *process, unsigned int *numberplayer)
{
	int	cycletodie;
	
	int	cycle;
	t_process		*tmp;
	t_live			*live;
	int				nbchecks;

	nbchecks = 0;
	live = ft_memalloc(sizeof(t_live));
	cycletodie = CYCLE_TO_DIE;
	cycle = 0;
	tmp = process;
	while (cycle < cycletodie)
	{
		while (process)
		{
			if (process->tmp == 0)
				nb_of_cycle(process, ram);
			if (process->nbcycle == 0 && process->tmp == 1)
				call_fonction(ram, process, live, numberplayer);
			else
				process->nbcycle--;
			process = process->next;
		}
		cycle++;
		process = tmp;
		if (cycle == cycletodie)
		{
			ft_putnbr(cycletodie);
			check_live_dead(process, &cycletodie, live, &nbchecks);
			cycle = 0;
		}
	}
	// check_winner(process, live);
	return (1);
}