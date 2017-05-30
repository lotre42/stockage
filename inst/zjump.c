/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:37:32 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/30 08:40:32 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	zjump(t_stock *info)
{
	int i;

	i = info->ram[info->pc + 2] << 8 | info->ram[info->pc + 3];
	if (info->carry == 1)
		info->pc = info->pc + info->ram[(i % 512)];
}

