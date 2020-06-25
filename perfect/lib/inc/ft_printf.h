/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherin <hherin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:26:13 by hherin            #+#    #+#             */
/*   Updated: 2020/02/06 14:25:25 by hherin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "tools.h"
# include "libft.h"
# define NB_STRUCT 9

typedef struct	s_flag
{
	int			minus;
	int			zero;
	int			diese;
}				t_flag;

typedef struct	s_option
{
	t_flag		flag;
	int			width;
	int			precision;
}				t_option;

typedef int	(*t_fct)(va_list ap, t_option opt);

typedef struct	s_printf
{
	char		c;
	t_fct		function;
}				t_print;

int				ft_printf(const char *format, ...);
t_option		ft_getopt(va_list ap, char **str);
t_print			*ft_struct_printf(void);
int				ft_type_d(va_list ap, t_option opt);
int				ft_type_s(va_list ap, t_option opt);
int				ft_type_c(va_list ap, t_option opt);
int				ft_type_x(va_list ap, t_option opt);
int				ft_type_xmaj(va_list ap, t_option opt);
int				ft_type_p(va_list ap, t_option opt);
int				ft_type_u(va_list ap, t_option opt);
int				ft_type_pourcent(va_list ap, t_option opt);
#endif
