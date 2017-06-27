/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ram.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 16:31:40 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/08 16:31:49 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int	print_ram(unsigned char *ram)
{
	int i;
	int x;

	i = 0;
	while (i < MEM_SIZE)
	{
		x = 0;
		while (x < 32)
		{
			if (ram[i] < 16)
				ft_printf("0%hhx ", ram[i]);
			else
				ft_printf("%hhx ", ram[i]);
			x++;
			i++;
		}
		ft_printf("\n");
	}
	return (1);
}
