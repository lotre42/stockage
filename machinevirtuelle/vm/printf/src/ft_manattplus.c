/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manattplus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:46:24 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/20 15:01:28 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_manattplus2(char *put)
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
	ret[0] = '+';
	return (ret);
}

static char	*ft_manattplus1(char *put, t_flag *f, char *str)
{
	char	*ret;
	int		i;

	i = 0;
	if (f->wid > f->prec && (size_t)f->wid > ft_strlen(str) &&
			(!ft_strchr(f->att, '0') || f->point) && !ft_strchr(f->att, '-'))
	{
		ret = ft_strdup(put);
		while (ret[i] == ' ')
			i++;
		i--;
		ret[i] = '+';
		return (ret);
	}
	else
	{
		ret = ft_strjoin("+", put);
		return (ret);
	}
}

char		*ft_manattplus(char *put, t_flag *f, char *str)
{
	char	*ret;

	ret = NULL;
	if (f->wid > f->prec && (size_t)f->wid > ft_strlen(str) &&
			ft_strchr(f->att, '0') && f->point == 0)
	{
		ret = ft_strdup(put);
		ret[0] = '+';
		return (ret);
	}
	if (f->wid > f->prec && (size_t)f->wid > ft_strlen(str) &&
			(!ft_strchr(f->att, '0') || f->point) && ft_strchr(f->att, '-'))
		return (ft_manattplus2(put));
	return (ft_manattplus1(put, f, str));
}
