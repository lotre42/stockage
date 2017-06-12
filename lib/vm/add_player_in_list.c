/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addplayerinlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:08:12 by srabah            #+#    #+#             */
/*   Updated: 2017/06/06 16:08:16 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int		add_player_in_list(char *pathplayer, t_player **players, int x)
{
	t_player *new;
	t_player *tmp;
	int i;

	i = 0;
	if ((new = malloc(sizeof(t_player))) == NULL)
		return (0);
	new->instruction = NULL;
	new->header = NULL;
	new->data_file = NULL;
	new->nbplayer = x;
	new->next = NULL;
	if (!open_path(pathplayer, new, x))
		return (0);
	tmp = *players;
	if (!tmp)
		*players = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}