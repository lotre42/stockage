/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 04:48:55 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/15 04:49:17 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

unsigned int	loadint(unsigned char *ram, int pc)
{
	unsigned int ret;

	ret = (ram[pc] << 24)
		| ((ram[pc + 1] << 16) & 0x00ffffff)
		| ((ram[pc + 2] << 8) & 0x0000ffff)
		| (ram[pc + 3] & 0x000000ff);
	return (ret);
}
