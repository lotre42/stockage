/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addtago.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 16:33:40 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/20 16:34:51 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_addtago(char *add, char *ret)
{
	int		i;
	char	*str;
	char	*s;

	i = 0;
	str = ft_strdup(ret);
	if (str[0] == '0')
		return (str);
	if (str[0] != ' ')
	{
		s = ft_strjoin(add, str);
		ft_strdel(&str);
		return (s);
	}
	while (str[i] == ' ')
		i++;
	str[i - 1] = '0';
	return (str);
}
