/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recoveryprocess.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 15:56:09 by srabah            #+#    #+#             */
/*   Updated: 2017/06/06 15:56:11 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

// int recovery_process(t_data *data)
// {
// 	 // char		*ram;
// 	 unsigned int 		i;
// 	 int 		nb;
// 	 t_player 	*players;

// 	 i = 0;
// 	 players = NULL;
// 	while (i < 2)
// 	{
// 	 	if (!add_player_in_list(data->player[i].path, &players))
// 	 		return (0);
// 	 	i++;
//  	}
//   	nb = 2;
// 	// if (!(ram = create_ram(players, nb)))
// 	// 	return (0);
// 	// // ft_initplayer(player, ram);
// 	// // ft_initregistre(player);
// 	//  // gestion(player, ram);
// 	return (0);
// }

int main(int argc, char **argv)
{
	 unsigned char		*ram;
	 unsigned int 		i;
	 unsigned int 		*numberplayer;
	 int 		nb;
	 int  		x;
	 t_player 	*players;
	 t_process 	*process;

	numberplayer = init_number_player(argc - 1);
	 i = 1;
	 x = 1;
	 players = NULL;
	while (i < argc)
	{
	 	if (!add_player_in_list(argv[i], &players, numberplayer[x]))
	 		return (0);
	 	i++;
	 	x++;
 	}
  	nb = argc - 1;
	process = create_list_process(players);
	if (!(ram = create_ram(players, nb, process)))
	 	return (0);
	core(ram, process, numberplayer, players);
	// print_ram(ram);
	return (0);
}