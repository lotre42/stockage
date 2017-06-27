/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovery_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:40:38 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/27 20:01:40 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		list_len(t_path *path)
{
	int i;

	i = 0;
	while (path)
	{
		path = path->next;
		i++;
	}
	return (i);
}

int		recovery_info(t_path *path, t_data *data)
{
	t_path		*tmp;
	t_player	*players;
	int			x;

	data->numberplayer = init_number_player(list_len(path), path);
	tmp = path;
	x = 1;
	while (tmp)
	{
		if (!add_player_in_list(tmp->str, &players, data->numberplayer[x]))
			return (0);
		x++;
		tmp = tmp->next;
	}
	data->players = players;
	data->process = create_list_process(data->players);
	if (!(data->ram = create_ram(data->players, list_len(path), data->process)))
		return (0);
	core(data);
	return (0);
}
