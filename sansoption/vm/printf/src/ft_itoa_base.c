/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:53:05 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/23 13:15:43 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	char	*ft_base(size_t n, int base, int i)
{
	char *str;

	str = ft_strnew(i);
	if (base <= 10)
	{
		while (--i >= 0)
		{
			str[i] = (n % base) + 48;
			n = n / base;
		}
	}
	if (base > 10)
	{
		while (--i >= 0)
		{
			if (n % base > 9)
				str[i] = 'a' - 10 + (n % base);
			else
				str[i] = (n % base) + 48;
			n = n / base;
		}
	}
	return (str);
}

char			*ft_itoa_base(size_t n, int base)
{
	size_t		x;
	int			i;

	i = 1;
	x = n;
	while (x >= (size_t)base)
	{
		x = x / base;
		i++;
	}
	return (ft_base(n, base, i));
}
