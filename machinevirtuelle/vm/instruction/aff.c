/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 17:37:27 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/26 17:37:28 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	aff(t_process *process, unsigned char *ram)
{
	if (check_nb_reg(((mask_pc(process->pc, 2)))))
		ft_putchar(process->registre[ram[((mask_pc(process->pc, 2)) - 1) % 256]]);
	process->pc = mask_pc(process->pc, 3);
}
