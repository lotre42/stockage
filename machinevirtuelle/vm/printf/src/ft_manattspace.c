/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manattspace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:12:47 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/22 17:52:38 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_manattspace2(char *put)
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
	ret[0] = ' ';
	return (ret);
}

static char	*ft_manattspace1(char *put)
{
	int		i;
	char	*ret;

	i = 0;
	ret = ft_strdup(put);
	while (ret[i] == ' ')
		i++;
	i--;
	ret[i] = ' ';
	return (ret);
}

char		*ft_manattspace(char *put, t_flag *f, char *str)
{
	char	*ret;
	int		i;

	i = 0;
	ret = NULL;
	if (f->wid > f->prec && (size_t)f->wid > ft_strlen(str) &&
			ft_strchr(f->att, '0') && f->point == 0)
	{
		ret = ft_strdup(put);
		ret[0] = ' ';
		return (ret);
	}
	if (f->wid > f->prec && (size_t)f->wid > ft_strlen(str) &&
			(!ft_strchr(f->att, '0') || f->point) && ft_strchr(f->att, '-'))
	{
		ret = ft_manattspace2(put);
		return (ret);
	}
	if (f->wid > f->prec && (size_t)f->wid > ft_strlen(str) &&
			(!ft_strchr(f->att, '0') || f->point) && !ft_strchr(f->att, '-'))
		return (ft_manattspace1(put));
	ret = ft_strjoin(" ", put);
	return (ret);
}
