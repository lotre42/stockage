/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 04:53:24 by srabah            #+#    #+#             */
/*   Updated: 2017/05/24 04:53:30 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				k;
	unsigned char	*news1;
	unsigned char	*news2;

	news1 = (unsigned char *)s1;
	news2 = (unsigned char *)s2;
	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (-1);
	while (n-- && (news1[k] || news2[k]))
	{
		i = news1[k] - news2[k];
		if (news1[k] != news2[k])
			return (i);
		k++;
	}
	return (i);
}
