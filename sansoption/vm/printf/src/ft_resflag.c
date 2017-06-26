/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 18:08:15 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/15 15:14:36 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flag		ft_resflag(void)
{
	t_flag flag;

	flag.att = NULL;
	flag.wid = 0;
	flag.prec = 0;
	flag.mod = NULL;
	flag.conv = 0;
	flag.ret = 0;
	flag.point = 0;
	flag.compt = 0;
	return (flag);
}
