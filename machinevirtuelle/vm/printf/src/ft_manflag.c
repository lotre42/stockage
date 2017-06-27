/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 19:25:31 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/23 21:16:55 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_manflagstring(va_list vl, t_flag *f)
{
	int		c;

	if (f->conv == 's' && ft_strcmp(f->mod, "l"))
		ft_manconvs(vl, f);
	else if (f->conv == 'p')
		ft_manadress(vl, f);
	else if (f->conv == 'c' && ft_strcmp(f->mod, "l"))
		ft_manconvc(vl, f);
	else if ((!ft_strcmp(f->mod, "l") && f->conv == 's') || f->conv == 'S')
		ft_manconvls(vl, f);
	else if ((!ft_strcmp(f->mod, "l") && f->conv == 'c') || f->conv == 'C')
	{
		c = va_arg(vl, int);
		ft_manconvlc(c, f);
	}
}

static void		ft_manflagbase(va_list vl, t_flag *f)
{
	if (f->mod == NULL && (f->conv == 'u' || f->conv == 'o' || f->conv == 'x'
				|| f->conv == 'X'))
		ft_modbase(vl, f);
	else if (!ft_strcmp(f->mod, "hh") && (f->conv == 'u' || f->conv == 'o' ||
				f->conv == 'x' || f->conv == 'X'))
		ft_modhhbase(vl, f);
	else if (!ft_strcmp(f->mod, "h") && (f->conv == 'u' || f->conv == 'o' ||
				f->conv == 'x' || f->conv == 'X'))
		ft_modhbase(vl, f);
	else if ((!ft_strcmp(f->mod, "l") && (f->conv == 'u' || f->conv == 'o' ||
					f->conv == 'x' || f->conv == 'X')) || f->conv == 'U'
			|| f->conv == 'O')
		ft_modlbase(vl, f);
	else if (!ft_strcmp(f->mod, "ll") && (f->conv == 'u' || f->conv == 'o' ||
				f->conv == 'x' || f->conv == 'X'))
		ft_modllbase(vl, f);
	else
		ft_manflagstring(vl, f);
}

void			ft_manflag(va_list vl, t_flag *f)
{
	if (f->mod == NULL && (f->conv == 'd' || f->conv == 'i'))
		ft_manmodd(vl, f);
	else if (!ft_strcmp(f->mod, "j") && (f->conv == 'd' || f->conv == 'i'))
		ft_manmodj(vl, f);
	else if (!ft_strcmp(f->mod, "j") && (f->conv == 'x' || f->conv == 'X'
				|| f->conv == 'u' || f->conv == 'o'))
		ft_manmodju(vl, f);
	else if (!ft_strcmp(f->mod, "z"))
		ft_manmodz(vl, f);
	else if ((!ft_strcmp(f->mod, "l") && (f->conv == 'd' || f->conv == 'i'))
			|| f->conv == 'D')
		ft_manmodld(vl, f);
	else if (!ft_strcmp(f->mod, "ll") && (f->conv == 'd' || f->conv == 'i'))
		ft_manmodlld(vl, f);
	else if (!ft_strcmp(f->mod, "h") && (f->conv == 'd' || f->conv == 'i'))
		ft_manmodhd(vl, f);
	else if (!ft_strcmp(f->mod, "hh") && (f->conv == 'd' || f->conv == 'i'))
		ft_manmodhhd(vl, f);
	else
		ft_manflagbase(vl, f);
}
