/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_downtype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 23:39:26 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/24 03:34:51 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static int	*ft_numberofparam(int ocp)
{
	int *tabparam;

	if ((ocp & 0b00001111))
	{
		tabparam = ft_inittab(4);
		tabparam[0] = 3;
		tabparam[1] = (ocp & 0b11000000) >> 6;
		tabparam[2] = (ocp & 0b00110000) >> 4;
		tabparam[3] = (ocp & 0b00001100) >> 2;
	}
	else
	{
		tabparam = ft_inittab(3);
		tabparam[0] = 2;
		tabparam[1] = (ocp & 0b11000000) >> 6;
		tabparam[2] = (ocp & 0b00110000) >> 4;
	}
	return (tabparam);
}

int			*ft_downtype(t_stock *info, int pc)
{
	int *tabparam;
	int i;

	if (info->ram[pc] == 0x01 || info->ram[pc] == 0x09 ||
		   	info->ram[pc] == 0x0c || info->ram[pc] == 0x0f)
	{
		tabparam = ft_inittab(2);
		tabparam[0] = 1;
		tabparam[1] = 2;
	}
	else
		tabparam = ft_numberofparam(info->ram[pc + 1]);
	i = 1;
	return (tabparam);
}
