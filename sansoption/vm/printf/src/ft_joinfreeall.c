/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:52:30 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/16 18:35:42 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_joinfreeall(char **s, char **s2, int n)
{
	char	*str;

	str = ft_strjoin(*s, *s2);
	if (n == 0)
	{
		ft_strdel(s);
		ft_strdel(s2);
	}
	if (n == 1)
		ft_strdel(s);
	if (n == 2)
		ft_strdel(s2);
	return (str);
}
