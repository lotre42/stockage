/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinfree1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:04:15 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/16 17:06:28 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_joinfree1(char **s, char *s2, int n)
{
	char	*str;

	str = ft_strjoin(*s, s2);
	if (n == 1)
		ft_strdel(s);
	return (str);
}
