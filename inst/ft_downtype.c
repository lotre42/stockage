/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_downtype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 23:39:26 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/04 05:07:50 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static unsigned int	*ft_numberofparam(int ocp)
{
	unsigned int *tabparam;

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

int			*ft_downtype(t_stock *info, char *ram)
{
	unsigned int *tabparam;
	int i;

	if (ram[info->pc] == 0x01 || ram[info->pc] == 0x09 ||
		   	ram[info->pc] == 0x0c || ram[info->pc] == 0x0f)
	{
		tabparam = ft_inittab(2);
		tabparam[0] = 1;
		tabparam[1] = 2;
	}
	else 
		tabparam = ft_numberofparam(ram[pluspc(info->pc, 1)]);
	i = 1;
	return (tabparam);
}
