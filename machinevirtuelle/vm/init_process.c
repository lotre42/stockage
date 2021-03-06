/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:39:05 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/15 04:46:26 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			init_process(t_process **process, unsigned int nb)
{
	t_process	*new;
	t_process	*tmp;
	int			i;

	i = 0;
	new = NULL;
	if (!(new = ft_memalloc(sizeof(t_process))))
		exit(0);
	new->registre = init_tab(16);
	new->registre[0] = nb;
	new->nbplayer = nb;
	tmp = *process;
	if (!tmp)
		*process = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

t_process	*create_list_process(t_player *players)
{
	t_process	*process;
	int			i;

	process = NULL;
	i = -1;
	while (players)
	{
		if (!init_process(&process, players->nbplayer))
			return (0);
		players = players->next;
	}
	return (process);
}
