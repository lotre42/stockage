/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manforcent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:07:04 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/20 16:31:12 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_manforcent2(t_flag *f)
{
	char *ret;
	char *str;
	char *str2;

	if (!ft_strchr(f->att, '-'))
	{
		str = ft_complete(f->wid - 1, ' ');
		ret = ft_joinfree1(&str, "%", 1);
	}
	else
	{
		str = ft_complete(f->wid - 1, ' ');
		str2 = ft_joinfree1(&str, "%", 1);
		ret = ft_manattti(str2);
		ft_strdel(&str2);
	}
	ft_putstr(ret);
	f->compt = f->compt + ft_strlen(ret);
	ft_strdel(&ret);
}

void	ft_manforcent(t_flag *f)
{
	if (f->wid > 1)
		ft_manforcent2(f);
	else
	{
		ft_putchar('%');
		f->compt = f->compt + 1;
	}
}
