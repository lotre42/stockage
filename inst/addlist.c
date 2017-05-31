/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 06:35:04 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/31 20:16:06 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		addlist(char *argv, t_player **add)
{
	t_player *new;
	t_player *tmp;
	int i;

	i = 0;
	new = ft_initplay(new);
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
