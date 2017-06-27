/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 15:48:39 by kahantar          #+#    #+#             */
/*   Updated: 2017/04/26 19:32:18 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		ft_add(char *str, t_path **add)
{
	t_path *new;

	if (!(new = malloc(sizeof(t_path))))
		return (0);
	new->str = ft_strdup(str);
	new->next = *add;
	*add = new;
	return (0);
}

int		ft_addend(char *str, t_path **add)
{
	t_path *new;
	t_path *tmp;

	if (!(new = malloc(sizeof(t_path))))
		return (0);
	new->str = ft_strdup;
	new->next = NULL;
	tmp = *add;
	if (*add == NULL)
		*add = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (0);
}
