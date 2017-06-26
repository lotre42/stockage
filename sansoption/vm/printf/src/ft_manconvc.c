/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manconvc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:35:44 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/20 18:34:40 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_manconvc3(t_flag *f, char *str)
{
	if (ft_strchr(f->att, '-'))
	{
		ft_putstr(ft_manattti(str));
		f->compt = f->compt + ft_strlen(ft_manattti(str));
	}
	else
	{
		ft_putstr(str);
		f->compt = f->compt + ft_strlen(str);
	}
}

static void	ft_manconvc2(char c, t_flag *f, char *buf)
{
	char	*str;
	char	*tmp;

	if (f->wid > 1)
	{
		tmp = ft_complete(f->wid - 1, ' ');
		str = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
		ft_manconvc3(f, str);
		ft_strdel(&str);
		if (c == 0)
			f->compt = f->compt + 1;
	}
	else
	{
		ft_putchar(c);
		f->compt = f->compt + 1;
	}
}

void		ft_manconvc(va_list vl, t_flag *f)
{
	char	*buf;
	char	c;

	c = va_arg(vl, int);
	buf = ft_strnew(2);
	buf[0] = c;
	buf[1] = '\0';
	ft_manconvc2(c, f, buf);
}
