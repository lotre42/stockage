/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:00:44 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/14 12:59:21 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_complete(int i, char c)
{
	char	*str;
	int		j;

	j = 0;
	str = (char*)malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	while (j < i)
	{
		str[j] = c;
		j++;
	}
	str[j] = '\0';
	return (str);
}
