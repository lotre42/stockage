/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:23:53 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/30 05:04:40 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	st(t_stock *info)
{
	int	*tabtype;
	int *tabvalue;

	tabtype = ft_downtype(info);
	tabvalue = ft_downvalue(info, tabtype, 0);
	if (tabtype[2] == 3)
	{
		info->pc = info->pc + (tabvalue[1] % 512);
		*(unsigned int*)((void*)((info->ram + info->pc))) = info->registre[tabvalue[0]];
	}
	else
		info->registre[tabvalue[1]] = info->registre[tabvalue[0]];
}

