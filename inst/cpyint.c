/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpyint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 00:42:25 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/04 04:39:24 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	cpyint(char *ram, char *src, int pc)
{
	ram[pc] = src[0];
	ram[pluspc(pc, 1)] = src[1];
	ram[pluspc(pc, 2)] = src[2];
	ram[pluspc(pc, 3)] = src[3];
}

