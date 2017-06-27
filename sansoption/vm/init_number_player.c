/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_number_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 17:44:09 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/27 19:59:41 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

unsigned int	*init_number_player(int nb, t_path *path)
{
	unsigned int	*ret;
	int				x;

	x = 1;
	ret = init_tab(nb + 1);
	ret[0] = nb;
	while (path)
	{
		ret[x] = path->nb;
		x++;
		path = path->next;
	}
	return (ret);
}
