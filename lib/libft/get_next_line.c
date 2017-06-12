/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 04:53:11 by srabah            #+#    #+#             */
/*   Updated: 2017/05/24 04:53:15 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char		*impro_realloc(char **line, int *i)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(*line) + *i + 1));
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, *line);
	free(*line);
	return (str);
}

static int		need_place(char **ste, char *sti)
{
	if (*ste == NULL)
		return (0);
	**ste = '\0';
	*ste += 1;
	ft_strcpy(sti, *ste);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char	sti[BUFF_SIZE];
	char		str[BUFF_SIZE + 1];
	char		*ste;
	int			i;

	if (!line || fd == -1)
		return (-1);
	if (!(*line = (char *)malloc(sizeof(char *) *
					(BUFF_SIZE + ft_strlen(sti) + 1))))
		return (-1);
	ft_strcpy(*line, sti);
	while (!((ste = ft_strchr(*line, '\n'))) &&
			((i = read(fd, str, BUFF_SIZE)) > 0))
	{
		str[i] = '\0';
		if (!(*line = impro_realloc(line, &i)))
			return (-1);
		ft_strcat(*line, str);
	}
	if (need_place(&ste, sti))
		return (1);
	if (i == 0)
		return (0);
	else
		return (-1);
}
