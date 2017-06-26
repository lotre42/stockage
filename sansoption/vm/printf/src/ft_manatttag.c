/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manatttag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:12:45 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/20 16:33:55 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_add01tag(char *ret, char *add)
{
	char	*s;
	char	*str;
	char	*s2;

	str = ft_strdup(ret);
	s = ft_strsub(str, 1, ft_strlen(str) - 1);
	s2 = ft_strjoin(add, s);
	ft_strdel(&str);
	ft_strdel(&s);
	return (s2);
}

static char	*ft_add0tag(char *add, char *ret)
{
	int		i;
	char	*str;
	char	*s;

	i = 0;
	str = ft_strdup(ret);
	if (str[0] != '0')
	{
		s = ft_strjoin(add, str);
		ft_strdel(&str);
		return (s);
	}
	while (str[i] == '0')
		i++;
	if (i > 1)
	{
		str[0] = add[0];
		str[1] = add[1];
		return (str);
	}
	if (i == 1)
		return (ft_add01tag(ret, add));
	return (str);
}

static char	*ft_addtag1(char *ret, char *add, int i)
{
	char	*str;

	str = ft_strdup(ret);
	while (str[i] == ' ')
		i++;
	str[i - 2] = add[0];
	str[i - 1] = add[1];
	return (str);
}

static char	*ft_addtag(char *add, char *ret)
{
	int		i;
	char	*str;
	char	*s;

	i = 0;
	str = ft_strdup(ret);
	if (ret[0] != ' ')
	{
		s = ft_strjoin(add, str);
		ft_strdel(&str);
		return (s);
	}
	while (str[i] == ' ')
		i++;
	if (i > 1)
		return (ft_addtag1(ret, add, i));
	if (i == 1)
		str[0] = add[1];
	s = ft_strjoin("0", str);
	ft_strdel(&str);
	return (s);
}

char		*ft_manatttag(char *ret, t_flag *f)
{
	char *str;

	if (f->conv == 'X' && ft_strcmp(ret, "0") && ft_strchr(f->att, '0'))
		return (ft_add0tag("0X", ret));
	if (f->conv == 'x' && ft_strcmp(ret, "0") && ft_strchr(f->att, '0'))
		return (ft_add0tag("0x", ret));
	if (f->conv == 'X' && ft_strcmp(ret, "0") && !ft_strchr(f->att, '0'))
		return (ft_addtag("0X", ret));
	if (f->conv == 'x' && ft_strcmp(ret, "0") && !ft_strchr(f->att, '0'))
		return (ft_addtag("0x", ret));
	if (f->conv == 'o')
		return (ft_addtago("0", ret));
	if (f->conv == 'O')
		return (ft_addtago("0", ret));
	str = ft_strdup(ret);
	return (str);
}
