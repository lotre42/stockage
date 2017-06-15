/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpyint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 00:42:25 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/15 02:39:49 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	cpyint(unsigned char *ram, unsigned char *src, int pc)
{
	ram[pc] = src[0];
	ram[mask_pc(pc, 1)] = src[1];
	ram[mask_pc(pc, 2)] = src[2];
	ram[mask_pc(pc, 3)] = src[3];
}
