/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinfree2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:05:45 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/20 14:27:38 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_joinfree2(char *s, char **s2, int n)
{
	char	*str;

	str = ft_strjoin(s, *s2);
	if (n == 1)
		ft_strdel(s2);
	return (str);
}
