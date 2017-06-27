/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 18:58:45 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/26 18:58:47 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int	check_flag(int argc char **argv, int i)
{
	int		dump;

	if (ft_strequ(argv[*i], "-dump"))
		dunp = ft_atoi(argv[*i + 1]);
	else if (ft_strequ(argv[*i], "-n"))

}

int		main(int argc, char **argv)
{
	int			i;
	t_player	*players;

	i = 1;
	players = NULL;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			check_flag(argc, argv, &i);
	}
	return 0;
}
