/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 10:32:03 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/26 13:48:03 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <locale.h>
# include "libft.h"

typedef struct	s_flags
{
	char		*att;
	int			wid;
	int			prec;
	char		*mod;
	char		conv;
	int			ret;
	int			point;
	int			compt;
}				t_flag;

int				ft_printf(char const *str, ...);
t_flag			ft_resflag(void);
void			ft_parse(va_list vl, const char *str, int *i, t_flag *f);
void			ft_modif(const char *str, int *i, t_flag *f);
void			ft_manflag(va_list vl, t_flag *f);
int				ft_manconvd(int n, t_flag *f, char *str);
char			*ft_complete(int i, char c);
char			*ft_manattti(char *put);
char			*ft_manatt(char *put, t_flag *f, char *str, int n);
char			*ft_manattplus(char *put, t_flag *f, char *str);
char			*ft_manattspace(char *put, t_flag *f, char *str);
char			*ft_manneg(char *put, t_flag *f, char *str);
char			*ft_nbnosign(int nb);
char			*ft_manatttag(char *str, t_flag *f);
int				ft_manconvs(va_list vl, t_flag *f);
void			ft_manmodd(va_list vl, t_flag *f);
void			ft_manmodld(va_list vl, t_flag *f);
void			ft_manmodlld(va_list vl, t_flag *f);
void			ft_manmodhd(va_list vl, t_flag *f);
void			ft_manmodhhd(va_list vl, t_flag *f);
void			ft_modbase(va_list vl, t_flag *f);
void			ft_modhhbase(va_list vl, t_flag *f);
void			ft_modhbase(va_list vl, t_flag *f);
void			ft_modlbase(va_list vl, t_flag *f);
void			ft_modllbase(va_list vl, t_flag *f);
char			*ft_itoa_base(size_t n, int base);
void			ft_manadress(va_list vl, t_flag *f);
void			ft_manmodz(va_list vl, t_flag *f);
void			ft_manmodj(va_list vl, t_flag *f);
void			ft_manmodju(va_list vl, t_flag *f);
void			ft_manforcent(t_flag *f);
void			ft_manconvc(va_list vl, t_flag *f);
void			ft_initflag(t_flag *f);
char			*ft_modifchar(char *put);
void			ft_strdel(char **as);
char			*ft_joinfreeall(char **s, char **s2, int n);
char			*ft_joinfree1(char **s, char *s2, int n);
char			*ft_joinfree2(char *s, char **s2, int n);
char			*ft_addtago(char *add, char *ret);
void			ft_manmodd2(t_flag *f);
int				ft_manconvls(va_list vl, t_flag *f);
int				ft_manconvlc(int c, t_flag *f);
void			ft_manwid(int x, t_flag *f);
int				ft_comptbits(int c);
int				ft_mask(int x);
int				ft_display(int arg, int x, int m);
void			ft_manwid(int x, t_flag *f);

#endif
