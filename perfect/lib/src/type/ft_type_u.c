/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherin <hherin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:24:22 by hherin            #+#    #+#             */
/*   Updated: 2020/01/03 11:46:55 by hherin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static char	*ft_zeropad(char *s, char *tmp, t_option opt, size_t size)
{
	size_t	start;
	size_t	zero;

	if (opt.precision >= 0)
	{
		zero = (opt.precision >= (int)ft_strlen(s)) ?
			opt.precision - ft_strlen(s) : 0;
		start = (opt.flag.minus || opt.width < 0) ? 0 :
			size - ft_max(opt.precision, (int)ft_strlen(s));
		tmp = ft_finalcopy(tmp, s, start, zero);
	}
	else
	{
		zero = (opt.flag.zero && opt.width > 0) ? opt.width - ft_strlen(s) : 0;
		start = (opt.flag.minus || opt.width < 0) ? 0 :
			size - ft_max(ft_strlen(s), zero + ft_strlen(s));
		tmp = ft_finalcopy(tmp, s, start, zero);
	}
	return (tmp);
}

static char	*ft_optschoose(t_option opt, char *s)
{
	char	*tmp;
	size_t	size;

	tmp = NULL;
	size = ft_max(opt.precision, ft_abso(opt.width));
	if ((ft_strlen(s) == 1) && *s == '0' && !opt.precision)
	{
		free(s);
		s = ft_calloc(1, 1);
	}
	if (size < ft_strlen(s))
		return (s);
	if (!(tmp = ft_memaset(tmp, size)))
		return (NULL);
	tmp = ft_zeropad(s, tmp, opt, size);
	free(s);
	return (tmp);
}

int			ft_type_u(va_list ap, t_option opt)
{
	char	*str;
	int		lenght;

	str = ft_unitoa_base(va_arg(ap, unsigned int), "0123456789");
	if (!(str = ft_optschoose(opt, str)))
		return (-1);
	lenght = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (lenght);
}
