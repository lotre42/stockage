/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manconvls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 19:01:26 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/23 21:27:00 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_manconvls1(wchar_t *str, int c, t_flag *f)
{
	int		x;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 127)
		{
			x = ft_comptbits(str[i]);
			ft_display(str[i], x, ft_mask(x));
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	if (ft_strchr(f->att, '-'))
		ft_manwid(c, f);
}

int			ft_manconvls(va_list vl, t_flag *f)
{
	wchar_t	*str;
	int		i;
	int		c;

	i = 0;
	c = 0;
	if (!(str = va_arg(vl, wchar_t *)))
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] > 127)
			c = c + ft_comptbits(str[i]);
		else
			c = c + 1;
		i++;
	}
	if (!ft_strchr(f->att, '-'))
		ft_manwid(c, f);
	ft_manconvls1(str, c, f);
	return (0);
}
