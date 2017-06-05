/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 06:35:04 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/04 02:54:37 by kahantar         ###   ########.fr       */
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
	if (!infoplayer(new))
		return (0);
	tmp = *add;
	if (!tmp)
		*add = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}
