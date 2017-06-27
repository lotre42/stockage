/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovery_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:40:38 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/26 12:44:56 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int recovery_info(int argc, char **argv)
{
	unsigned char		*ram;
	unsigned int		i;
	unsigned int		*numberplayer;
	int					nb;
	int					x;
	t_player			*players;
	t_process			*process;

	numberplayer = init_number_player(argc - 1);
	i = 1;
	x = 1;
	players = NULL;
	while ((int)i < argc)
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
