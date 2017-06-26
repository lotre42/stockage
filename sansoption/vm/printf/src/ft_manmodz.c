/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manmodz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 16:01:49 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/20 19:12:42 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_manmodj(va_list vl, t_flag *f)
{
	intmax_t	n;
	intmax_t	sign;
	char		*str;
	int			plus;

	n = va_arg(vl, intmax_t);
	if (n < 0)
	{
		sign = n * -1;
		plus = -1;
	}
	else
	{
		sign = n;
		plus = 1;
	}
	str = ft_itoa_base(sign, 10);
	ft_manconvd(plus, f, str);
	if (str)
		ft_strdel(&str);
}

void	ft_manmodju(va_list vl, t_flag *f)
{
	uintmax_t	n;
	char		*str;

	n = va_arg(vl, size_t);
	if (f->conv == 'x' || f->conv == 'X')
		str = ft_itoa_base(n, 16);
	if (f->conv == 'o')
		str = ft_itoa_base(n, 8);
	if (f->conv == 'u')
		str = ft_itoa_base(n, 10);
	ft_manconvd(1, f, str);
	if (str)
		ft_strdel(&str);
}

void	ft_manmodz(va_list vl, t_flag *f)
{
	size_t	n;
	char	*str;

	n = va_arg(vl, size_t);
	if (f->conv == 'u' || f->conv == 'd' || f->conv == 'i' || f->conv == 'D'
			|| f->conv == 'U')
		str = ft_itoa_base(n, 10);
	if (f->conv == 'x' || f->conv == 'X')
		str = ft_itoa_base(n, 16);
	if (f->conv == 'o' || f->conv == 'O')
		str = ft_itoa_base(n, 8);
	ft_manconvd(1, f, str);
	if (str)
		ft_strdel(&str);
}
