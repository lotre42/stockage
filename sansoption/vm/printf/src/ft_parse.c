/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 10:22:30 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/22 16:57:07 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_width(const char *str, int *i, t_flag *f)
{
	int n;

	if (ft_atoi(&str[*i]))
	{
		n = ft_atoi(&str[*i]);
		*i = *i + 1;
		f->wid = n;
		while ((n = n / 10) >= 1)
			*i = *i + 1;
	}
}

void	ft_precision(const char *str, int *i, t_flag *f)
{
	int n;

	if (ft_atoi(&str[*i]))
	{
		n = ft_atoi(&str[*i]);
		f->prec = n;
	}
	while (ft_isdigit(str[*i]))
		*i = *i + 1;
}

void	ft_convert(const char *str, int *i, t_flag *f)
{
	if (str[*i] == 's' || str[*i] == 'S' || str[*i] == 'p' || str[*i] == 'd'
			|| str[*i] == 'x' || str[*i] == 'X' || str[*i] == 'D' ||
			str[*i] == 'i' || str[*i] == 'o' || str[*i] == 'O' || str[*i] == 'u'
			|| str[*i] == 'U' || str[*i] == 'c' || str[*i] == 'C')
	{
		f->conv = str[*i];
		*i = *i + 1;
	}
}

void	ft_attribute(const char *str, int *i, t_flag *f)
{
	char	*att;
	int		n;

	att = NULL;
	n = *i;
	while (str[n] == ' ' || str[n] == '+' || str[n] == '-' || str[n] == '#'
			|| str[n] == '0')
		n++;
	n = n - *i;
	att = ft_strnew(n);
	n = 0;
	while ((str[*i] == ' ' || str[*i] == '+' || str[*i] == '-' || str[*i] == '#'
			|| str[*i] == '0') && n != 2)
	{
		att[n] = str[*i];
		n++;
		*i = *i + 1;
	}
	while (str[*i] == ' ' || str[*i] == '+' || str[*i] == '-' || str[*i] == '#'
			|| str[*i] == '0')
		*i = *i + 1;
	f->att = ft_strdup(att);
	if (att)
		ft_strdel(&att);
}

void	ft_parse(va_list vl, const char *str, int *i, t_flag *f)
{
	ft_attribute(str, i, f);
	ft_width(str, i, f);
	if (str[*i] == '.')
	{
		*i = *i + 1;
		f->point = 1;
	}
	ft_precision(str, i, f);
	ft_modif(str, i, f);
	ft_convert(str, i, f);
	ft_manflag(vl, f);
}
