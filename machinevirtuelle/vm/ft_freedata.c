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

static void		free_play(t_player **players)
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
	free(tmp->numberplayer);
	free(tmp->ram);
	free_play(&tmp->players);
	// free_process(&tmp->process);
	free(tmp->process);
	free(tmp);
}
