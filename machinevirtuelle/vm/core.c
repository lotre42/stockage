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
			ft_putstr(") a gagne\n");
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

int				core(t_data *data)
{
	int			cycle;
	t_process	*tmp;
	t_live		*live;

	live = ft_memalloc(sizeof(t_live));
	cycle = 0;
	tmp = data->process;
	while (cycle < data->cycletodie)
	{
		if (data->cycle == data->dump)
			return (print_ram(data->ram));
		check_cycle(data->ram, data->process, live, data->numberplayer);
		cycle++;
		data->cycle++;
		data->process = tmp;
		if (cycle == data->cycletodie &&
		nb_checks(&data->cycletodie, live, &data->nbchecks))
		{
			if (!check_live_dead(&data->process))
				break ;
			cycle = 0;
		}
	}
	check_winner(data->process, live, data->players);
	free(live);
	return (1);
}
