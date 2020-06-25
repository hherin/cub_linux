/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherin <hherin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:23:50 by hherin            #+#    #+#             */
/*   Updated: 2020/01/03 16:22:21 by hherin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static char	*ft_optchoose(char *str, t_option opt)
{
	char	*tmp;
	size_t	size;
	size_t	start;
	size_t	i;

	i = 0;
	tmp = NULL;
	size = ft_max((int)ft_strlen(str), opt.width);
	if (!(tmp = ft_memaset(tmp, size)))
		return (NULL);
	start = (opt.flag.minus) ? 0 : size - ft_strlen(str);
	while (i < ft_strlen(str))
		tmp[start++] = str[i++];
	free(str);
	return (tmp);
}

static char	*ft_nulad(char *str)
{
	free(str);
	str = malloc(sizeof(char) * 3);
	str[0] = '0';
	str[1] = 'x';
	str[2] = '\0';
	return (str);
}

int			ft_type_p(va_list ap, t_option opt)
{
	long	nb;
	char	*str;
	int		lenght;

	nb = va_arg(ap, long);
	str = ft_itoahexa(nb);
	(nb == 0 && !opt.precision) ? str = ft_nulad(str) : 0;
	if (!(str = ft_optchoose(str, opt)))
		return (-1);
	lenght = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (lenght);
}
