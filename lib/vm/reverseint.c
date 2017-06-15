/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 00:21:14 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/15 05:07:32 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

unsigned char	*reverseint(unsigned int nb)
{
	unsigned char *ret;

	ret = (unsigned char *)ft_strnew(4);
	ret[0] = (nb & 0xff000000) >> 24;
	ret[1] = (nb & 0x00ff0000) >> 16;
	ret[2] = (nb & 0x0000ff00) >> 8;
	ret[3] = (nb & 0x000000ff);
	return (ret);
}
