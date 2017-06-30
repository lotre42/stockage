/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freedata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 00:38:32 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/29 00:38:38 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int				free_process(t_process **process)
{
	t_process *tmp;

	tmp = (*process);
	while (tmp)
	{
		if ((*process)->registre)
			free((*process)->registre);
		tmp = (*process)->next;
		free(*process);
		*process = tmp;
	}
	return (1);
}

void		free_play(t_player **players)
{
	t_player *tmp;

	tmp = (*players);
	while (tmp)
	{
		if ((*players)->data_file)
			free((*players)->data_file);
		tmp = (*players)->next;
		free(*players);
		*players = tmp;
	}
}

void			ft_freedata(t_data **data)
{
	t_data *tmp;

	tmp = *data;
	if (tmp->numberplayer)
		free(tmp->numberplayer);
	if (tmp->ram)
		free(tmp->ram);
	if (tmp->players)
		free_play(&tmp->players);
	if (tmp->process)
		free_process(&tmp->process);
	free(tmp->process);
	if (tmp)
		free(tmp);
}
