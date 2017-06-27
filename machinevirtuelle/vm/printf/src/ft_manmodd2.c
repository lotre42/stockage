/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manmodd2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 16:46:51 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/20 16:53:17 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_manmodd2(t_flag *f)
{
	char *str2;

	if (f->wid)
	{
		str2 = ft_complete(f->wid, ' ');
		ft_putstr(str2);
		f->compt = f->compt + f->wid;
		ft_strdel(&str2);
	}
}
