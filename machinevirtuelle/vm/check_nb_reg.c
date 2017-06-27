/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nb_reg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 18:45:33 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/15 02:38:53 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int				check_nb_reg(unsigned int nb)
{
	if (((nb - 1) < 16))
		return (1);
	else
		return (0);
}

void			cpyint(unsigned char *ram, unsigned char *src, int pc)
{
	ram[pc] = src[0];
	ram[mask_pc(pc, 1)] = src[1];
	ram[mask_pc(pc, 2)] = src[2];
	ram[mask_pc(pc, 3)] = src[3];
}

int				free_process(t_process **process)
{
	t_process *cp;

	cp = (*process);
	while (cp)
	{
		cp = (*process)->next;
		free(*process);
		*process = cp;
	}
	return (0);
}

unsigned int	*init_number_player(int nb, t_path *path)
{
	unsigned int	*ret;
	int				x;

	x = 1;
	ret = init_tab(nb + 1);
	ret[0] = nb;
	while (path)
	{
		ret[x] = path->nb;
		x++;
		path = path->next;
	}
	return (ret);
}

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
