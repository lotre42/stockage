/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 10:04:14 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/20 19:12:23 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_modbase(va_list vl, t_flag *f)
{
	unsigned int	n;
	char			*str;

	n = va_arg(vl, unsigned int);
	if (f->conv == 'u')
		str = ft_itoa_base(n, 10);
	if (f->conv == 'o')
		str = ft_itoa_base(n, 8);
	if (f->conv == 'x' || f->conv == 'X')
		str = ft_itoa_base(n, 16);
	if (n != 0 || f->prec != 0 || f->point == 0)
		ft_manconvd(1, f, str);
	else
	{
		if (f->wid)
			ft_manmodd2(f);
		else if (f->conv == 'o' && ft_strchr(f->att, '#'))
		{
			ft_putchar('0');
			f->compt = f->compt + 1;
		}
	}
	if (str)
		ft_strdel(&str);
}

void	ft_modhhbase(va_list vl, t_flag *f)
{
	unsigned char	n;
	char			*str;

	n = va_arg(vl, unsigned);
	if (f->conv == 'u')
		str = ft_itoa_base(n, 10);
	if (f->conv == 'o')
		str = ft_itoa_base(n, 8);
	if (f->conv == 'x' || f->conv == 'X')
		str = ft_itoa_base(n, 16);
	ft_manconvd(1, f, str);
	if (str)
		ft_strdel(&str);
}

void	ft_modhbase(va_list vl, t_flag *f)
{
	unsigned short int	n;
	char				*str;

	n = va_arg(vl, unsigned int);
	if (f->conv == 'u')
		str = ft_itoa_base(n, 10);
	if (f->conv == 'o')
		str = ft_itoa_base(n, 8);
	if (f->conv == 'x' || f->conv == 'X')
		str = ft_itoa_base(n, 16);
	ft_manconvd(1, f, str);
	if (str)
		ft_strdel(&str);
}

void	ft_modlbase(va_list vl, t_flag *f)
{
	unsigned long int	n;
	char				*str;

	n = va_arg(vl, unsigned long int);
	if (f->conv == 'u' || f->conv == 'U')
		str = ft_itoa_base(n, 10);
	if (f->conv == 'o' || f->conv == 'O')
		str = ft_itoa_base(n, 8);
	if (f->conv == 'x' || f->conv == 'X')
		str = ft_itoa_base(n, 16);
	if (n != 0 || f->prec != 0 || f->point == 0)
		ft_manconvd(1, f, str);
	else
	{
		if (f->wid)
			ft_manmodd2(f);
		else if (f->conv == 'O' && ft_strchr(f->att, '#'))
		{
			ft_putchar('0');
			f->compt = f->compt + 1;
		}
	}
	if (str)
		ft_strdel(&str);
}

void	ft_modllbase(va_list vl, t_flag *f)
{
	unsigned long long int	n;
	char					*str;

	n = va_arg(vl, unsigned long long int);
	if (f->conv == 'u')
		str = ft_itoa_base(n, 10);
	if (f->conv == 'o')
		str = ft_itoa_base(n, 8);
	if (f->conv == 'x' || f->conv == 'X')
		str = ft_itoa_base(n, 16);
	ft_manconvd(1, f, str);
	if (str)
		ft_strdel(&str);
}
