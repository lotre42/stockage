/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 18:40:13 by kahantar          #+#    #+#             */
/*   Updated: 2017/06/15 02:41:08 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			free_process(t_process **process)
{
	t_process *cp;

	cp = (*process);
	while (cp)
	{
		cp = (*process)->next;
		// free(*(process)->registre);
		free(*process);
		*process = cp;
	}
	return (0);
}
