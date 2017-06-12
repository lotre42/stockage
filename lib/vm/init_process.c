/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:39:05 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/09 15:39:07 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int		init_process(t_player *players, t_process **process, unsigned int nb)
{
	t_process *new;
	t_process *tmp;
	int i;

	i = 0;
	new = NULL;
	if (!(new = ft_memalloc(sizeof(t_process))))
		return (0);
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

t_process 	*create_list_process(t_player *players)
{
	t_process *process;
	int 		i;

	process = NULL;
	//i = 0;
	i = -1;
	while (players)
	{
		if (!init_process(players, &process, i))/*nbplayer[i]*/
			return (0);
		players = players->next;
		//i++;
		i--;
	}
	return (process);
}