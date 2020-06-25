/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherin <hherin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:23:56 by hherin            #+#    #+#             */
/*   Updated: 2020/01/02 18:01:08 by hherin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static int	ft_checkerror(t_option opt)
{
	if (opt.flag.zero || opt.precision >= 0)
		return (1);
	return (0);
}

void		ft_spaceprint(int lenght)
{
	while (lenght > 0)
	{
		write(1, " ", 1);
		lenght--;
	}
}

int			ft_type_c(va_list ap, t_option opt)
{
	char	c;
	int		abso_wid;

	if (ft_checkerror(opt))
		return (0);
	abso_wid = ft_abso(opt.width);
	if (ft_checkerror(opt))
		return (0);
	c = va_arg(ap, int);
	if (!opt.flag.minus && opt.width > 1)
		ft_spaceprint(abso_wid - 1);
	ft_putchar(c);
	if (opt.flag.minus || opt.width < -1)
		ft_spaceprint(abso_wid - 1);
	return ((abso_wid > 1) ? abso_wid : 1);
}
