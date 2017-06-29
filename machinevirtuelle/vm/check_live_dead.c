/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_live_dead.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:55:55 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/26 13:24:06 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void		cpy_process(t_process *process, t_process *new)
{
	new->carry = process->carry;
	new->nbplayer = process->nbplayer;
	new->pc = process->pc;
	new->next = NULL;
	new->registre = init_tab(16);
	new->last = process->last;
}

static void		create_process(t_process **cpy, t_process *process)
{
	t_process	*tmp;
	t_process	*new;
	int			i;

	i = 0;
	if (!(new = ft_memalloc(sizeof(t_process))))
		return ;
	cpy_process(process, new);
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

static void		check_dead(t_process **process)
{
	t_process *cpy;
	t_process *tmp;

	cpy = NULL;
	tmp = *process;
	while (tmp)
	{
		if (tmp->live != 0)
			create_process(&cpy, tmp);
		tmp = tmp->next;
	}
	free_process(process);
	tmp = cpy;
}

static int		zero_process(t_process *process)
{
	int			i;
	t_process	*tmp;

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

int				check_live_dead(t_process **process)
{
	int			i;
	int			j;
	t_process	*tmp;

	tmp = *process;
	i = 0;
	j = 0;
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
	return (zero_process(*process));
}
