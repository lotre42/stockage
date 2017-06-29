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

int		ft_add(unsigned int nb, char *str, t_path **add)
{
	t_path *new;

	if (!(new = malloc(sizeof(t_path))))
		exit(0);
	new->str = ft_strdup(str);
	new->nb = nb;
	new->next = *add;
	*add = new;
	return (0);
}

int		ft_addend(unsigned int nb, char *str, t_path **add)
{
	t_path *new;
	t_path *tmp;

	if (!(new = malloc(sizeof(t_path))))
		exit(0);
	new->str = ft_strdup(str);
	new->nb = nb;
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
