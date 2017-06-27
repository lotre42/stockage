/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manconvd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 19:30:32 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/22 16:44:39 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_manconvd31(t_flag *f, char *str)
{
	char	*put;
	char	*s;
	char	*s2;
	char	*s3;

	if ((size_t)f->prec > ft_strlen(str))
	{
		s = ft_complete((f->wid - f->prec), ' ');
		s2 = ft_complete((f->prec - ft_strlen(str)), '0');
		s3 = ft_strjoin(s, s2);
		put = ft_strjoin(s3, str);
		ft_strdel(&s);
		ft_strdel(&s2);
		ft_strdel(&s3);
	}
	else
	{
		s = ft_complete((f->wid - ft_strlen(str)), ' ');
		put = ft_strjoin(s, str);
		ft_strdel(&s);
	}
	return (put);
}

static char	*ft_manconvd3(t_flag *f, char *str, int n)
{
	char	*ret;
	char	*put;

	put = NULL;
	if ((size_t)f->wid > ft_strlen(str) && f->wid > f->prec)
		put = ft_manconvd31(f, str);
	if (ft_strlen(str) >= (size_t)f->prec && ft_strlen(str) >= (size_t)f->wid)
		put = ft_strdup(str);
	if (!put)
		return (NULL);
	ret = ft_manatt(put, f, str, n);
	if (put)
		ft_strdel(&put);
	return (ret);
}

static int	ft_manconvd2(t_flag *f, char *str, int n)
{
	char	*put;
	char	*str2;

	put = ft_manconvd3(f, str, n);
	if (!put)
		return (0);
	if (n < 0)
	{
		str2 = ft_manneg(put, f, str);
		ft_putstr(str2);
		f->compt = f->compt + ft_strlen(str2);
		ft_strdel(&str2);
	}
	else
	{
		ft_putstr(put);
		f->compt = f->compt + ft_strlen(put);
	}
	ft_strdel(&put);
	return (0);
}

static char	*ft_manconvd1(char *str, t_flag *f, int n)
{
	int		x;
	char	*tmp;
	char	*put;
	char	*ret;

	x = f->prec - ft_strlen(str);
	tmp = ft_complete(x, '0');
	put = ft_strjoin(tmp, str);
	ft_strdel(&tmp);
	ret = ft_manatt(put, f, str, n);
	ft_strdel(&put);
	return (ret);
}

int			ft_manconvd(int n, t_flag *f, char *str)
{
	char	*ret;
	char	*tmp;

	if ((size_t)f->prec > ft_strlen(str) && f->prec >= f->wid)
	{
		ret = ft_manconvd1(str, f, n);
		if (n < 0)
		{
			tmp = ft_strjoin("-", ret);
			ft_putstr(tmp);
			ft_strdel(&tmp);
			f->compt = f->compt + ft_strlen(ret) + 1;
		}
		else
		{
			ft_putstr(ret);
			f->compt = f->compt + ft_strlen(ret);
		}
		ft_strdel(&ret);
		return (0);
	}
	return (ft_manconvd2(f, str, n));
}
