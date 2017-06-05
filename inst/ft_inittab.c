/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inittab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 23:21:34 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/31 16:29:29 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

unsigned int *ft_inittab(int x)
{
	unsigned int *tab;
	int i;

	i = 0;
	if (!(tab = (unsigned int*)malloc(sizeof(int) * x)))
		return (0);
	while (i < x)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
