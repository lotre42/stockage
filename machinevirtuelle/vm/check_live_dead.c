/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_live_dead.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:55:55 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/30 04:00:50 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static t_process	*check_dead(t_process *l)
{
	t_process *first;
	t_process *tmp;

	while (l->live == 0)
		l = l->next;
	if (l)
		first = l;
	else
		return (NULL);
	tmp = l->next;
	while (tmp)
	{
		if (tmp->live == 0)
		{
			l->next = l->next->next;
			free(tmp);
			tmp = l->next;
			continue ;
		}
		tmp = tmp->next;
		l = l->next;
	}
	return (first);
}

static int			zero_process(t_process *process)
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

int					check_live_dead(t_process **process)
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
	*process = check_dead(*process);
	tmp = *process;
	while (tmp)
	{
		j++;
		tmp = tmp->next;
	}
	return (zero_process(*process));
}
