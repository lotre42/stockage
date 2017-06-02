/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 00:21:14 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/02 00:42:18 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

char *reverseint(unsigned int nb)
{
	char *ret;

	ret = ft_strnew(4);
	ret[0] = (nb & 0xff000000) >> 24;
	ret[1] = (nb & 0x00ff0000) >> 16;
	ret[2] = (nb & 0x0000ff00) >> 8;
	ret[3] = (nb & 0x000000ff);
	return (ret);
}
