/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 22:40:55 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/24 03:30:20 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int main(void)
{
	t_stock info;
	int r;
	int pc;

	pc = 0;
	r = 0;
	info.ram = malloc(sizeof(char) * 8);
	info.ram[0] = 0x02;
	info.ram[1] = 0x68;
	info.ram[2] = 0x01;
	info.ram[3] = 0x00;
	info.ram[4] = 0x0f;
	info.ram[5] = 0x00;
	info.ram[6] = 0x01;
	info.carry = 0;
	ld(&info, pc);
}


