/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manatt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 22:16:18 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/22 17:55:22 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_manatt0(char *put, t_flag *f)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strdup(put);
	if (ft_strchr(f->att, '-'))
		return (str);
	while (str[i] == ' ')
	{
		str[i] = '0';
		i++;
	}
	return (str);
}

char		*ft_modifchar(char *put)
{
	int		i;
	char	*ret;

	i = 0;
	ret = ft_strdup(put);
	while (ret[i] != '\0')
	{
		if (ret[i] >= 'a' && ret[i] <= 'z')
			ret[i] = ret[i] - 32;
		i++;
	}
	return (ret);
}

static char	*ft_manatt3(char *put, t_flag *f)
{
	char	*tmp;
	char	*ret;

	tmp = ft_strdup(put);
	if (f->conv == 'X')
	{
		ret = ft_modifchar(put);
		ft_strdel(&tmp);
		tmp = ft_strdup(ret);
		ft_strdel(&ret);
	}
	return (tmp);
}

static char	*ft_manatt2(char *put, t_flag *f)
{
	char	*ret;
	char	*tmp;

	tmp = ft_manatt3(put, f);
	if (ft_strchr(f->att, '0') && f->point == 0 && !ft_strchr(f->att, '-'))
	{
		ret = ft_manatt0(tmp, f);
		ft_strdel(&tmp);
		tmp = ft_strdup(ret);
		ft_strdel(&ret);
	}
	if (ft_strchr(f->att, '#'))
	{
		ret = ft_manatttag(tmp, f);
		ft_strdel(&tmp);
		tmp = ft_strdup(ret);
		ft_strdel(&ret);
	}
	return (tmp);
}

char		*ft_manatt(char *put, t_flag *f, char *str, int n)
{
	char	*ret;
	char	*tmp;

	tmp = ft_manatt2(put, f);
	if (ft_strchr(f->att, '+') && n >= 0)
	{
		ret = ft_manattplus(tmp, f, str);
		ft_strdel(&tmp);
		return (ret);
	}
	if (ft_strchr(f->att, ' ') && !ft_strchr(f->att, '+'))
	{
		ret = ft_manattspace(tmp, f, str);
		ft_strdel(&tmp);
		return (ret);
	}
	if (ft_strchr(f->att, '-'))
	{
		ret = ft_manattti(tmp);
		ft_strdel(&tmp);
		return (ret);
	}
	return (tmp);
}
