/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:14:29 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/19 18:47:26 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_initflag(t_flag *f)
{
	if (f->att)
		ft_strdel(&f->att);
	if (f->mod)
		ft_strdel(&f->mod);
	f->att = NULL;
	f->wid = 0;
	f->prec = 0;
	f->mod = NULL;
	f->conv = 0;
	f->ret = 0;
	f->point = 0;
}
