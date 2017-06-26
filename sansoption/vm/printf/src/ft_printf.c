/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 18:17:37 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/23 20:44:13 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_printf2(const char *str, t_flag *f, va_list vl)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_initflag(f);
		while (str[i] != '%' && str[i] != '\0')
		{
			f->compt = f->compt + 1;
			ft_putchar(str[i++]);
		}
		if (str[i] == '\0')
			break ;
		i++;
		ft_parse(vl, str, &i, f);
		if (str[i] == '%' && (str[i - 1] == '%' || ft_isdigit(str[i - 1]) ||
					str[i - 1] == ' '))
		{
			ft_manforcent(f);
			i++;
		}
	}
}

int			ft_printf(const char *str, ...)
{
	int		i;
	va_list	vl;
	t_flag	f;

	i = 0;
	f = ft_resflag();
	va_start(vl, str);
	if (!str)
		return (0);
	ft_printf2(str, &f, vl);
	va_end(vl);
	ft_strdel(&f.att);
	ft_strdel(&f.mod);
	return (f.compt);
}
