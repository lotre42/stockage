/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:05:41 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/15 04:48:44 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

unsigned int	*load_value(t_process *process, unsigned char *ram,
unsigned int *type, unsigned int *val)
{
	unsigned int	*ret;
	int				i;

	i = 0;
	ret = init_tab(2);
	while (i < 2)
	{
		if (type[i + 1] == 1)
		{
			if (check_nb_reg(val[i]))
				ret[i] = process->registre[val[i]];
			else
				return (NULL);
		}
		else if (type[i + 1] == 2)
			ret[i] = val[i];
		else if (type[i + 1] == 3)
			ret[i] = ram[mask_pc(process->pc, val[i])];
		i++;
	}
	return (ret);
}

unsigned int	loadint(unsigned char *ram, int pc)
{
	unsigned int ret;

	ret = (ram[pc] << 24)
		| ((ram[pc + 1] << 16) & 0x00ffffff)
		| ((ram[pc + 2] << 8) & 0x0000ffff)
		| (ram[pc + 3] & 0x000000ff);
	return (ret);
}

int				mask_pc(int nb, int i)
{
	int ret;

	ret = (nb + i) % (MEM_SIZE - 1);
	return (ret);
}

int				print_ram(unsigned char *ram)
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

unsigned char	*reverseint(unsigned int nb)
{
	unsigned char *ret;

	ret = (unsigned char *)ft_strnew(4);
	ret[0] = (nb & 0xff000000) >> 24;
	ret[1] = (nb & 0x00ff0000) >> 16;
	ret[2] = (nb & 0x0000ff00) >> 8;
	ret[3] = (nb & 0x000000ff);
	return (ret);
}
