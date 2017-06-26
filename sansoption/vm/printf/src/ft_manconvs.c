/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manconvs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:48:52 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/23 21:21:14 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_manconvs2(t_flag *f, char *str)
{
	char	*put;
	char	*ret;
	int		n;

	n = 0;
	put = ft_strnew(f->prec + 1);
	while (n < f->prec && str[n] != '\0')
	{
		put[n] = str[n];
		n++;
	}
	if (f->wid > f->prec)
		ret = ft_strjoin(ft_complete(f->wid - f->prec, ' '), put);
	else
		ret = ft_strdup(put);
	ft_strdel(&put);
	return (ret);
}

static void		ft_manconvs1(char *ret, t_flag *f, char *str)
{
	char	*str2;
	char	*inv;
	char	*comp;

	if (!ft_strcmp(f->att, "-"))
	{
		if ((size_t)f->wid > ft_strlen(str) && (f->point == 0 ||
				(size_t)f->prec >= ft_strlen(str)) && str[0] == ' ')
		{
			inv = ft_manattti(str);
			comp = ft_complete(f->wid - ft_strlen(str), ' ');
			str2 = ft_joinfree2(str, &comp, 1);
			ft_strdel(&inv);
		}
		else
			str2 = ft_manattti(ret);
		ft_putstr(str2);
		f->compt = f->compt + ft_strlen(str2);
		ft_strdel(&str2);
	}
	else
	{
		ft_putstr(ret);
		f->compt = f->compt + ft_strlen(ret);
	}
}

static void		ft_strnull(t_flag *f)
{
	int		i;
	int		x;

	i = 0;
	x = f->wid - 6;
	while (i < x && x > 0)
		ft_putchar(' ');
	ft_putstr("(null)");
	if (x > 0)
		f->compt = f->compt + 6 + x;
	else
		f->compt = f->compt + 6;
}

int				ft_manconvs(va_list vl, t_flag *f)
{
	char *str;
	char *ret;

	if (!(str = va_arg(vl, char*)))
	{
		ft_strnull(f);
		return (0);
	}
	ret = NULL;
	if ((size_t)f->prec < ft_strlen(str) && f->point == 1)
		ret = ft_manconvs2(f, str);
	if ((size_t)f->wid > ft_strlen(str) && (f->point == 0 ||
				(size_t)f->prec >= ft_strlen(str)))
	{
		f->mod = ft_complete(f->wid - ft_strlen(str), ' ');
		ret = ft_joinfree1(&f->mod, str, 1);
	}
	else if (!ret)
		ret = ft_strdup(str);
	ft_manconvs1(ret, f, str);
	if (ret)
		ft_strdel(&ret);
	return (0);
}
