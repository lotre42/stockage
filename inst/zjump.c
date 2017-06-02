/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:37:32 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/03 01:28:38 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	zjump(t_stock *info)
{
	short i;
	
	i = ((info->ram[pluspc(info->pc, 1)] << 8) &0xff00) | (info->ram[pluspc(info->pc, 2)] & 0x00ff);
	if (info->carry == 1)
		info->pc = pluspc(info->pc, (i % 512));
	else
		info->pc = pluspc(info->pc, 6);
}

