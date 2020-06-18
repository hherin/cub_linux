/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:25:03 by hherin            #+#    #+#             */
/*   Updated: 2020/04/09 18:40:59 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int		ft_finalprint(va_list ap, t_print *tab, char *str)
{
	t_option	opt;
	int			index;
	int			tmp;
	int			j;

	index = 0;
	while (*str)
	{
		(*str != '%') ? ft_putchar(*str) : 0;
		(*str != '%') ? index++ : 0;
		if (*str == '%')
		{
			j = -1;
			tmp = 0;
			str++;
			opt = ft_getopt(ap, &str);
			while (++j < NB_STRUCT)
				if (tab[j].c == *str)
					if ((tmp = tab[j].function(ap, opt)) == -1)
						return (-1);
			index += tmp;
		}
		str++;
	}
	return (index);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_print		*tab;
	int			ret;
	char		*str;

	va_start(ap, format);
	str = (char*)format;
	tab = ft_struct_printf();
	ret = ft_finalprint(ap, tab, str);
	free(tab);
	va_end(ap);
	return (ret);
}
