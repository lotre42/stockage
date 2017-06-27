/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:24:19 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/19 19:05:48 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_modif2(const char *str, int *i, t_flag *f)
{
	if (str[*i] == 'l' && str[*i - 1] == 'l')
	{
		f->mod = ft_strdup("ll");
		*i = *i + 1;
		return (0);
	}
	if (str[*i] == 'h' && str[*i - 1] == 'h')
	{
		f->mod = ft_strdup("hh");
		*i = *i + 1;
	}
	return (0);
}

void	ft_modif(const char *str, int *i, t_flag *f)
{
	if (str[*i] == 'z' || str[*i] == 'j' || str[*i] == 'h' || str[*i] == 'l')
	{
		if (str[*i] == 'z')
			f->mod = ft_strdup("z");
		if (str[*i] == 'j')
			f->mod = ft_strdup("j");
		if (str[*i] == 'l' && str[*i + 1] != 'l')
			f->mod = ft_strdup("l");
		if (str[*i] == 'h' && str[*i + 1] != 'h')
			f->mod = ft_strdup("h");
		*i = *i + 1;
	}
	ft_modif2(str, i, f);
}
