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

// static void		delete_process(t_process *process, int i)
// {
// 	t_process	*tmp;

// 	if (process == NULL)
// 	 	return;
// 	while (--i)
// 		process = process->next;
// 	tmp = process->next;
// 	process->next = tmp->next;
// 	ft_memdel((void**)&tmp);
// }

static void				cpy_process(t_process **cpy, t_process *process)
{
	t_process *tmp;
	t_process *new;
	int			i;

	i = 0;
	if (!(new = ft_memalloc(sizeof(t_process))))
		return ;
	new->carry = process->carry;
	new->nbplayer = process->nbplayer;
	new->pc = process->pc;
	new->next = NULL;
	new->registre = init_tab(16);
	new->last = process->last;
	while (i < 16)
	{
		new->registre[i] = process->registre[i];
		i++;
	}
	tmp = *cpy;
	if (!tmp)
		*cpy = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

static void			check_dead(t_process **process)
{	
	t_process *cpy;
	t_process *tmp;

	cpy = NULL;
	tmp = *process;
	while (tmp)
	{
		if (tmp->live != 0)
			cpy_process(&cpy, tmp);
		tmp = tmp->next;
	}
	// if ((*process))
		// free_process(process);
	*process = cpy;	
}



static int 		zero_process(t_process *process, t_live *live)
{
	int i;
	t_process *tmp;

	i = 0;
	tmp = process;
	if (!process)
		return (0);
	while (process)
	{
			i++;
		process = process->next;
	}
	process = tmp;
	if (i == 0)
		return (0);
	else
		return (1);
}

static int			check_live_dead(t_process **process, int *cycletodie,
 t_live *live, int *nbchecks)
{
	int i;
	int j;
	t_process *tmp;

	tmp = *process;
	i = 0;
	j = 0;
	if (live->nblive >= NBR_LIVE || *nbchecks == MAX_CHECKS)
	{
		*nbchecks = 0;
		live->nblive = 0;
		*cycletodie = *cycletodie - CYCLE_DELTA;
	}
	else
		*nbchecks = *nbchecks + 1;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	check_dead(process);
	tmp = *process;
		while (tmp)
	{
		j++;
		tmp = tmp->next;
	}
	// printf("avant---->%d\napres------>%d\n", i, j);
	return (zero_process(*process, live));
}

static void		check_winner(t_process *process, t_live *live, t_player *player)
{
	t_process *tmp;
	int 		win;
	int i;

	i = 0;
	win = 0;
	tmp = process;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	tmp = process;
	// ft_putstr("le joueur");
	// ft_putnbr(live->lastlive);
	// ft_putstr("(");
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
	// ft_putstr(") a gagne");
}

int		core(unsigned char *ram, t_process *process, unsigned int *numberplayer, t_player *player)
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
			if (process->nbcycle == 0)
				call_fonction(ram, process, live, numberplayer);
			else
				process->nbcycle--;
			process = process->next;
		}
		cycle++;
		process = tmp;
		if (cycle == cycletodie)
		{
			if (!check_live_dead(&process, &cycletodie, live, &nbchecks))
				break ;
			cycle = 0;
		}
	}
	check_winner(process, live, player);
	return (1);
}