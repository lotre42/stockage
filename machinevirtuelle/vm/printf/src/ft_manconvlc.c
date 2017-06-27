/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manconvlc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:06:18 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/23 21:23:18 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_manwid(int x, t_flag *f)
{
	int i;

	i = f->wid - x;
	if (i > 0)
	{
		f->compt = f->compt + f->wid;
		while (i > 0)
		{
			ft_putchar(' ');
			i--;
		}
	}
	else
		f->compt = f->compt + x;
}

int				ft_display(int arg, int x, int m)
{
	int	i;
	int	a;
	int	b;
	int *tab;

	if (!(tab = malloc(sizeof(int) * 3)))
		return (0);
	tab[0] = 63;
	tab[1] = 4032;
	tab[2] = 258048;
	i = x - 1;
	a = m | (arg >> (i * 6));
	write(1, &a, 1);
	while (x > 1)
	{
		i--;
		b = 128 | ((arg & tab[x - 2]) >> (i * 6));
		x--;
		write(1, &b, 1);
	}
	free(tab);
	return (0);
}

int				ft_mask(int x)
{
	int n;
	int c;

	c = 256;
	n = 0;
	while (x > 0)
	{
		n = n + c / 2;
		c = c / 2;
		x--;
	}
	return (n);
}

int				ft_comptbits(int c)
{
	char	*str;
	int		i;
	int		x;

	x = 1;
	str = ft_itoa_base(c, 2);
	i = ft_strlen(str);
	while (i >= 6)
	{
		i = i - 6;
		x++;
	}
	if ((x + i + 1) > 8)
		x++;
	ft_strdel(&str);
	return (x);
}

int				ft_manconvlc(int c, t_flag *f)
{
	int x;

	x = 0;
	if (c > 127)
	{
		x = ft_comptbits(c);
		if (!ft_strchr(f->att, '-'))
			ft_manwid(x, f);
	}
	else
	{
		if (!ft_strchr(f->att, '-'))
			ft_manwid(1, f);
		write(1, &c, 1);
		if (ft_strchr(f->att, '-'))
			ft_manwid(1, f);
		return (0);
	}
	ft_display(c, x, ft_mask(x));
	if (ft_strchr(f->att, '-') && c > 127)
		ft_manwid(x, f);
	return (0);
}
