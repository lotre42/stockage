/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:54:12 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/15 04:47:20 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

unsigned int	*init_tab(int x)
{
	unsigned int	*tab;
	int				i;

	i = 0;
	if (!(tab = (unsigned int*)malloc(sizeof(unsigned int) * x)))
		return (0);
	while (i < x)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
