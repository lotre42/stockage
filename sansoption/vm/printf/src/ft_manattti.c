/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manatt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:56:54 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/22 18:04:42 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_manattti(char *put)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = ft_complete(ft_strlen(put), 'x');
	while (put[i] == ' ')
		i++;
	while (put[i] != '\0')
	{
		str[j] = put[i];
		j++;
		i++;
	}
	while (str[j] != '\0')
	{
		str[j] = ' ';
		j++;
	}
	return (str);
}
