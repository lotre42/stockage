/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pluspc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 00:48:25 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/01 01:19:35 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		pluspc(int pc, int i)
{
	int nb;
	int cpypc;

	nb = 0;
	cpypc = pc;
	if (i > 0)
	{
		while (nb < i)
		{
			if (cpypc >= 4095)
				cpypc = 0;
			cpypc++;
			nb++;
		}
	}
	else
	{
		while (nb > i)
		{
			if (cpypc <= 0)
				cpypc = 4095;
			cpypc--;
			nb--;
		}
	}
	return (cpypc);
}
