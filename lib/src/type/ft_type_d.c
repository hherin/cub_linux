/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:24:48 by hherin            #+#    #+#             */
/*   Updated: 2020/04/09 18:40:44 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static char	*ft_nbnegative(char *s, char *tmp, t_option opt, size_t size)
{
	size_t	start;
	size_t	zero;
	int		abso;

	if (opt.precision >= 0)
	{
		zero = (opt.precision >= (int)ft_strlen(s)) ?
			opt.precision - ft_strlen(s) + 1 : 0;
		start = (opt.flag.minus || opt.width < 0) ? 0 :
			size - ft_max(opt.precision + 1, (int)ft_strlen(s));
		tmp[start++] = '-';
		tmp = ft_finalcopy(tmp, s + 1, start, zero);
	}
	else
	{
		abso = (opt.width < 0) ? (int)ft_strlen(s) : opt.width;
		zero = (opt.flag.zero && opt.width > 0) ? abso - ft_strlen(s) : 0;
		start = (opt.flag.minus || opt.width < 0) ? 0 :
			size - (zero + ft_strlen(s));
		tmp[start++] = '-';
		tmp = ft_finalcopy(tmp, s + 1, start, zero);
	}
	return (tmp);
}

static char	*ft_zeropad(char *s, char *tmp, t_option opt, size_t size)
{
	size_t	start;
	size_t	zero;
	int		abso;

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
		abso = (opt.width < 0) ? (int)ft_strlen(s) : opt.width;
		zero = (opt.flag.zero && opt.width > 0) ? abso - ft_strlen(s) : 0;
		start = (opt.flag.minus || opt.width < 0) ? 0 :
			size - ft_max(ft_strlen(s), zero + ft_strlen(s));
		tmp = ft_finalcopy(tmp, s, start, zero);
	}
	return (tmp);
}

static char	*ft_optschoose(t_option opt, char *s, int nb)
{
	char	*tmp;
	size_t	size;
	int		abso;

	tmp = NULL;
	abso = (opt.width < 0) ? -opt.width : opt.width;
	size = (nb < 0) ? ft_max(opt.precision + 1, abso) :
		ft_max(opt.precision, abso);
	if ((ft_strlen(s) == 1) && *s == '0' && !opt.precision)
	{
		free(s);
		s = ft_calloc(1, 1);
	}
	if (size < ft_strlen(s))
		return (s);
	if (!(tmp = ft_memaset(tmp, size)))
		return (NULL);
	if (nb < 0)
		tmp = ft_nbnegative(s, tmp, opt, size);
	else
		tmp = ft_zeropad(s, tmp, opt, size);
	free(s);
	return (tmp);
}

int			ft_type_d(va_list ap, t_option opt)
{
	char	*s;
	char	*str;
	int		nb;
	int		lenght;

	nb = va_arg(ap, int);
	if (!(s = ft_itoa(nb)))
		return (0);
	if (!(str = ft_optschoose(opt, s, nb)))
		return (-1);
	lenght = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (lenght);
}
