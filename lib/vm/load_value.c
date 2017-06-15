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

#include "../../includes/vm.h"

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
