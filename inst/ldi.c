/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 23:43:45 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/23 09:38:04 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/corewar.h"

void	ldi(int i, int x, int *r, t_stock *info)
{
	int S;

	S = (info->ram[info->pc + (i % 512)] << 8) |
	   	(info->ram[info->pc + 1 + (i % 512)]) + x;
	*r = ((info->ram[info->pc + (S % 512)] << 24) |
	   	(info->ram[info->pc + 1 + (S % 512)] << 16) |
	   	(info->ram[info->pc + 2 + (S % 512)] << 8) |
	   	(info->ram[info->pc + 3 + (S % 512)]));
}
