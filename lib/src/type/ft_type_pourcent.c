/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_pourcent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherin <hherin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:26:44 by hherin            #+#    #+#             */
/*   Updated: 2020/01/03 11:51:42 by hherin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static char	*ft_optchoose(t_option opt, char *s)
{
	char	*tmp;
	size_t	size;
	int		zero;
	int		start;

	tmp = NULL;
	size = ft_abso(opt.width);
	zero = (opt.flag.minus || !opt.flag.zero || opt.width < 0) ? 0 :
		opt.width - 1;
	if (size < ft_strlen(s))
		return (s);
	tmp = ft_memaset(tmp, size);
	start = (opt.flag.minus || opt.width < 0) ? 0 :
		size - ft_max((int)ft_strlen(s), zero + 1);
	tmp = ft_finalcopy(tmp, s, start, zero);
	free(s);
	return (tmp);
}

int			ft_type_pourcent(va_list ap, t_option opt)
{
	char	*str;
	int		lenght;

	str = malloc(sizeof(char) * 2);
	str[0] = '%';
	str[1] = '\0';
	str = ft_optchoose(opt, str);
	(void)ap;
	lenght = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (lenght);
}
