/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:09:04 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/20 14:54:16 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_mana0dress(char *ret, t_flag *f)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_manattti(ret);
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	while (str[i] != '\0')
	{
		str[i] = '0';
		i++;
	}
	ft_putstr(str);
	f->compt = f->compt + ft_strlen(str);
	ft_strdel(&str);
}

static void	ft_manadress1(t_flag *f, char *ret)
{
	char	*str;

	if (!ft_strcmp(f->att, "-"))
	{
		str = ft_manattti(ret);
		ft_putstr(str);
		f->compt = f->compt + ft_strlen(str);
		ft_strdel(&str);
	}
	else
	{
		if (ft_strchr(f->att, '0'))
			ft_mana0dress(ret, f);
		else
		{
			ft_putstr(ret);
			f->compt = f->compt + ft_strlen(ret);
		}
	}
}

static char	*ft_manadress2(t_flag *f, char *put)
{
	char	*str;
	char	*ret;

	if ((size_t)f->wid > ft_strlen(put))
	{
		str = ft_complete(f->wid - ft_strlen(put), ' ');
		ret = ft_strjoin(str, put);
		ft_strdel(&str);
	}
	else
		ret = ft_strdup(put);
	return (ret);
}

void		ft_manadress(va_list vl, t_flag *f)
{
	long int	i;
	char		*ret;
	char		*put;
	char		*str;

	i = va_arg(vl, long int);
	if (f->prec == 0 && f->point == 1)
		put = ft_strdup("0x");
	else
	{
		str = ft_itoa_base(i, 16);
		put = ft_strjoin("0x", str);
		ft_strdel(&str);
	}
	ret = ft_manadress2(f, put);
	ft_manadress1(f, ret);
	if (put)
		ft_strdel(&put);
	if (ret)
		ft_strdel(&ret);
}
