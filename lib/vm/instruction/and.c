/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:17:28 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/13 17:17:30 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../../includes/vm.h"

void	ft_and(t_process *process, unsigned char *ram)
{
	unsigned int *tabtype;
	unsigned int *tabvalue;
	unsigned int *val;

	if (!check_nb_reg(tabvalue[2]))
	{
		pluspc(tabtype, process);
		return ;
	}
	tabtype = ft_downtype(process, ram);
	tabvalue = ft_downvalue(process, tabtype, 0, ram);
	val = 
	if (process->registre[tabvalue[2] - 1] == 0)
		process->carry = 1;
	else
		process->carry = 0;
}
