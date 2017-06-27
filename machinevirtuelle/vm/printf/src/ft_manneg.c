/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manneg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:38:24 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/23 21:17:15 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_mannegwid(char *put)
{
	char	*ret;
	int		c;

	ret = ft_manattti(put);
	c = ft_strlen(ret) - 1;
	while (c > 1)
	{
		ret[c] = ret[c - 1];
		c--;
	}
	ret[1] = ret[0];
	ret[0] = '-';
	return (ret);
}

static char	*ft_manneg1(char *put)
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_strdup(put);
	while (ret[i] == ' ')
		i++;
	i--;
	ret[i] = '-';
	return (ret);
}

static char	*ft_manneg0(char *put)
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_manattti(put);
	while (ft_isdigit(ret[i]))
		i++;
	while (i > 0)
	{
		ret[i] = ret[i - 1];
		i--;
	}
	ret[i] = '-';
	return (ret);
}

char		*ft_manneg(char *put, t_flag *f, char *str)
{
	char	*ret;

	ret = NULL;
	if (f->wid > f->prec && (size_t)f->wid > ft_strlen(str) &&
			ft_strchr(f->att, '0') && f->point == 0 && !ft_strchr(f->att, '-'))
	{
		ret = ft_strdup(put);
		ret[0] = '-';
		return (ret);
	}
	if (f->wid > f->prec && (size_t)f->wid > ft_strlen(str) &&
			f->point == 0 && ft_strchr(f->att, '-'))
		return (ft_manneg0(put));
	if (f->wid > f->prec && (size_t)f->wid > ft_strlen(str) &&
			(ft_strchr(f->att, '0') || f->point == 1) &&
			ft_strchr(f->att, '-'))
		return (ft_mannegwid(put));
	if (f->wid > f->prec && (size_t)f->wid > ft_strlen(str) &&
			(!ft_strchr(f->att, '0') || f->point == 1) &&
			!ft_strchr(f->att, '-'))
		return (ft_manneg1(put));
	ret = ft_strjoin("-", str);
	return (ret);
}
