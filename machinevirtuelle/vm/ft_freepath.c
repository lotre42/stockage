/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freepath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 23:55:13 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/28 23:55:14 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	ft_freepath(t_path **path)
{
	t_path *tmp;

	tmp = (*path);
	while (tmp)
	{
		if ((*path)->str)
			free((*path)->str);
		tmp = (*path)->next;
		free(*path);
		*path = tmp;
	}
}

int		ft_startandfree(t_path **path, t_data **data)
{
	recovery_info(*path, *data);
	ft_freepath(path);
	ft_freedata(data);
	return (0);
}
