/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherin <hherin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:24:11 by hherin            #+#    #+#             */
/*   Updated: 2020/01/03 11:47:01 by hherin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static int	ft_checkerror(t_option opt)
{
	if (opt.flag.zero)
		return (1);
	return (0);
}

static char	*ft_optchoose(char *s, t_option opt)
{
	size_t	len;
	int		len_prec;
	int		start;
	size_t	i;
	char	*str;

	i = 0;
	str = NULL;
	len_prec = (opt.precision < 0) ? (int)ft_strlen(s) :
		ft_min((int)ft_strlen(s), opt.precision);
	len = ft_max(ft_abso(opt.width), len_prec);
	if (!(str = ft_memaset(str, len)))
		return (NULL);
	if (opt.precision == 0)
	{
		len = ft_abso(opt.width);
		len_prec = 0;
	}
	opt.precision = 0;
	start = (opt.flag.minus || opt.width < 0) ? 0 :
		len - ft_min(len_prec, (int)ft_strlen(s));
	while ((int)i < len_prec)
		str[start++] = s[i++];
	return (str);
}

int			ft_type_s(va_list ap, t_option opt)
{
	char	*s;
	int		lenght;

	if (ft_checkerror(opt))
		return (0);
	s = va_arg(ap, char*);
	if (!s)
		s = ft_substr("(null)", 0, 6);
	if (!(s = ft_optchoose(s, opt)))
		return (-1);
	lenght = ft_strlen(s);
	ft_putstr(s);
	free(s);
	return (lenght);
}
