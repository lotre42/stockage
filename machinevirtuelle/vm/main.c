/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 18:58:45 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/27 20:06:30 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int		is_number(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 58)
			return (0);
		i++;
	}
	return (1);
}

static int		check_flag(char **argv, int *i, t_data *data)
{
	data->dump = -1;
	data->cycletodie = CYCLE_TO_DIE;
	if (ft_strequ(argv[*i], "-dump"))
	{
		data->dump = ft_atoi(argv[*i + 1]);
		*i = *i + 2;
	}
	return (0);
}

int				main(int argc, char **argv)
{
	int			i;
	t_data		*data;
	t_path		*path;

	i = 1;
	path = NULL;
	if (!(data = ft_memalloc(sizeof(t_data))))
		return (0);
	check_flag(argv, &i, data);
	while (i < argc)
	{
		if (ft_strequ(argv[i], "-n"))
		{
			i++;
			if (is_number(argv[i]))
				ft_add(ft_atoi(argv[i]), argv[i + 1], &path);
			else
				return (ft_putendlreturn("Erreur numero joueur"));
			i++;
		}
		else
			ft_add(i * -1, argv[i], &path);
		i++;
	}
	recovery_info(path, data);
	ft_freepath(&path);
	ft_freedata(&data);
	return (0);
}
