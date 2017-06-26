/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:55:04 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/26 13:04:23 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void		check_winner(t_process *process, t_live *live, t_player *player)
{
	t_process	*tmp;

	tmp = process;
	while (player)
	{
		if (player->nbplayer == live->lastlive)
		{
			ft_putstr("le joueur ");
			ft_putnbr(player->nbplayer);
			ft_putstr("(");
			ft_putstr(player->header->prog_name);
			ft_putstr(") a gagne");
			break ;
		}
		player = player->next;
	}
}

static void		check_cycle(unsigned char *ram, t_process *process,
t_live *live, unsigned int *numberplayer)
{
	while (process)
	{
		if (process->tmp == 0)
			nb_of_cycle(process, ram);
		if (process->nbcycle == 0)
			call_fonction(ram, process, live, numberplayer);
		else
			process->nbcycle--;
		process = process->next;
	}
}

static int		nb_checks(int *cycletodie, t_live *live, int *nbchecks)
{
	if (live->nblive >= NBR_LIVE || *nbchecks == MAX_CHECKS)
	{
		*nbchecks = 0;
		live->nblive = 0;
		*cycletodie = *cycletodie - CYCLE_DELTA;
	}
	else
		*nbchecks = *nbchecks + 1;
	return (1);
}

int				core(unsigned char *ram, t_process *process,
unsigned int *numberplayer, t_player *player)
{
	int			cycletodie;
	int			cycle;
	t_process	*tmp;
	t_live		*live;
	int			nbchecks;

	nbchecks = 0;
	live = ft_memalloc(sizeof(t_live));
	cycletodie = CYCLE_TO_DIE;
	cycle = 0;
	tmp = process;
	while (cycle < cycletodie)
	{
		check_cycle(ram, process, live, numberplayer);
		cycle++;
		process = tmp;
		if (cycle == cycletodie && nb_checks(&cycletodie, live, &nbchecks))
		{
			if (!check_live_dead(&process))
				break ;
			cycle = 0;
		}
	}
	check_winner(process, live, player);
	return (1);
}
