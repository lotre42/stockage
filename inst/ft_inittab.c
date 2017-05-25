/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inittab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 23:21:34 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/25 05:20:25 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int *ft_inittab(int x)
{
	int *tab;
	int i;

	i = 0;
	if (!(tab = (int*)malloc(sizeof(int) * x)))
		return (0);
	while (i < x)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
