/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_number_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 17:44:09 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/15 02:58:56 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

unsigned int	*init_number_player(int nb)
{
	unsigned int *ret;
	unsigned int i;
	unsigned int x;

	x = 1;
	i = -1;
	ret = init_tab(nb + 1);
	ret[0] = nb;
	while (x < nb + 1)
	{
		ret[x] = i;
		x++;
		i--;
	}
	return (ret);
}
