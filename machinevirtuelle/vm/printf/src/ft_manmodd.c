/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manmod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:27:42 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/20 19:12:59 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_manmodd(va_list vl, t_flag *f)
{
	int				n;
	int long		sign;
	char			*str;
	int				plus;

	n = va_arg(vl, int);
	if (n < 0)
	{
		sign = (int long)n * -1;
		plus = -1;
	}
	else
	{
		sign = n;
		plus = 1;
	}
	str = ft_itoa_base(sign, 10);
	if (n != 0 || f->prec != 0 || f->point == 0)
		ft_manconvd(plus, f, str);
	else
		ft_manmodd2(f);
	if (str)
		ft_strdel(&str);
}

void	ft_manmodld(va_list vl, t_flag *f)
{
	long int	n;
	long int	sign;
	char		*str;
	int			plus;

	n = va_arg(vl, long int);
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

void	ft_manmodlld(va_list vl, t_flag *f)
{
	long long int	n;
	long long int	sign;
	char			*str;
	int				plus;

	n = va_arg(vl, long long int);
	if (n < 0)
	{
		plus = -1;
		sign = n * -1;
	}
	else
	{
		plus = 1;
		sign = n;
	}
	str = ft_itoa_base(sign, 10);
	ft_manconvd(plus, f, str);
	if (str)
		ft_strdel(&str);
}

void	ft_manmodhd(va_list vl, t_flag *f)
{
	short int	n;
	int			sign;
	char		*str;
	int			plus;

	n = va_arg(vl, int);
	if (n < 0)
	{
		plus = -1;
		sign = (int)n * -1;
	}
	else
	{
		plus = 1;
		sign = n;
	}
	str = ft_itoa_base(sign, 10);
	ft_manconvd(plus, f, str);
	if (str)
		ft_strdel(&str);
}

void	ft_manmodhhd(va_list vl, t_flag *f)
{
	signed char		n;
	int				sign;
	char			*str;
	int				plus;

	n = va_arg(vl, signed);
	if (n < 0)
	{
		plus = -1;
		sign = (int)n * -1;
	}
	else
	{
		plus = 1;
		sign = n;
	}
	str = ft_itoa_base(sign, 10);
	ft_manconvd(plus, f, str);
	if (str)
		ft_strdel(&str);
}
