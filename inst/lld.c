/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 15:36:54 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/27 15:38:41 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	lld(t_stock *info, int pc)
{
	int *tabtype;
	int	*tabvalue;
	
	tabtype = ft_downtype(info, pc);
	tabvalue = ft_downvalue(info, tabtype, pc, 0);
	if (tabtype[1] == 3)
	{
		info->registre[tabvalue[1]] = ((info->ram[pc + (tabvalue[0])]) << 24)
		   	| (((info->ram[pc + 1 + (tabvalue[0])]) << 16) & 0x00ffffff)
		   	| (((info->ram[pc + 2 + (tabvalue[0])]) << 8) & 0x0000ffff)
		    | ((info->ram[pc + 3 + (tabvalue[0])]) & 0x000000ff);
	}
	else if (tabtype[1] == 2)
		info->registre[tabvalue[1]] = tabvalue[0];	
	if (info->carry == 0)
		info->carry = 1;
	else
		info->carry = 0;
}
