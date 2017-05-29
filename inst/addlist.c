/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 06:35:04 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/29 08:54:13 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		addlist(char *argv, t_player **add)
{
	t_player *new;
	t_player *tmp;
	int i;

	i = 0;
	if (!(new = malloc(sizeof(t_player))))
		return (0);
	opencor(argv, new);
	infoplayer(new);
	tmp = *add;
	if (!tmp)
		*add = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (0);
}
