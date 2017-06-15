/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_downtype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 23:39:26 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/15 02:44:23 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static unsigned int	*ft_numberofparam(int ocp)
{
	unsigned int *tabparam;

	if ((ocp & 0b00001111))
	{
		tabparam = init_tab(4);
		tabparam[0] = 3;
		tabparam[1] = (ocp & 0b11000000) >> 6;
		tabparam[2] = (ocp & 0b00110000) >> 4;
		tabparam[3] = (ocp & 0b00001100) >> 2;
	}
	else
	{
		tabparam = init_tab(3);
		tabparam[0] = 2;
		tabparam[1] = (ocp & 0b11000000) >> 6;
		tabparam[2] = (ocp & 0b00110000) >> 4;
	}
	return (tabparam);
}

unsigned int		*ft_downtype(t_process *process, unsigned char *ram)
{
	unsigned int	*tabparam;
	int				i;

	if (ram[process->pc] == 0x01 || ram[process->pc] == 0x09 ||
	ram[process->pc] == 0x0c || ram[process->pc] == 0x0f)
	{
		tabparam = init_tab(2);
		tabparam[0] = 1;
		tabparam[1] = 2;
	}
	else
		tabparam = ft_numberofparam(ram[mask_pc(process->pc, 1)]);
	i = 1;
	return (tabparam);
}
