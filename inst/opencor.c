/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 16:43:25 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/04 02:47:49 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../includes/corewar.h"

void	opencor(char *argv, t_player *player)
{
	int fd;
	int res;
	int i;
	int y;
	char buf[1025];

	i = 0;
	y = 0;
	close(fd);
	fd = open(argv, O_RDONLY);
	while ((res = read(fd, buf, 1024)))
		i = i + res;
	player->totalplayer = (char*)malloc(sizeof(char) * i);
	fd = open(argv, O_RDONLY);
	res = read(fd, player->totalplayer, i);
	player->sizetotal = i;
	close(fd);
}
