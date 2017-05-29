/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 22:40:55 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/29 07:05:53 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int main(int argc, char **argv)
{
	t_stock info;
	int r;
	int pc;
	int i;
	i = 1;
	t_player *player;
	player = NULL;
/*	pc = 0;
	r = 0;
	info.registre = (unsigned int*)ft_inittab(16);
	info.registre[0] = -1;
	info.registre[1] = -1;
	info.registre[2] = 0;
	info.ram = malloc(sizeof(char) * 27);
	info.ram[0] = 0x06;
	info.ram[1] = 0x64;
	info.ram[2] = 0x02;
	info.ram[3] = 0x00;
	info.ram[4] = 0x00;
	info.ram[5] = 0x00;
	info.ram[6] = 0x03;
	info.ram[7] = 0x03;
	info.ram[8] = 0x00;
	info.ram[9] = 0x00;
	info.ram[10] = 0x00;
	info.ram[11] = 0x00;
	info.ram[12] = 0x00;
	info.ram[13] = 0x00;
	info.ram[14] = 0x00;
	info.ram[15] = 0x00;
	info.ram[16] = 0x00;
	info.ram[17] = 0x00;
	info.ram[19] = 0x00;
	info.ram[20] = 0x00;
	info.ram[21] = 0x00;
	info.ram[22] = 0x00;
	info.ram[23] = 0x00;
	info.ram[24] = 0x00;
	info.ram[25] = 0x00;
	info.ram[26] = 0x00;
	info.carry = 0;
	*/
	while (i < argc)
	{
	addlist(argv[i], &player);
		i++;
	}
	//printf("%d", info.registre[3]);
//	while (r < 26)
//	{
//		printf("%hhx\n", info.ram[r]);
//		r++;
//	}
	return (0);
}


