/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherin <hherin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:24:58 by hherin            #+#    #+#             */
/*   Updated: 2019/12/30 12:40:54 by hherin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static t_flag	get_flag(char **str)
{
	t_flag	i;

	i.minus = 0;
	i.zero = 0;
	i.diese = 0;
	while (**str && (**str == '0' || **str == '-' || **str == '#'))
	{
		if (**str == '0')
		{
			i.zero = 1;
			(*str)++;
		}
		else if (**str == '-')
		{
			i.zero = 0;
			i.minus = 1;
			(*str)++;
		}
		else if (**str == '#')
		{
			i.diese = 1;
			(*str)++;
		}
	}
	return (i);
}

static int		get_width(char **str, va_list ap)
{
	int	ret;

	ret = 0;
	if (ft_isdigit(**str))
	{
		ret = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	else if (**str == '*')
	{
		ret = va_arg(ap, int);
		(*str)++;
	}
	return (ret);
}

static int		get_precision(char **str, va_list ap)
{
	int	ret;

	ret = -1;
	if (**str == '.')
	{
		(*str)++;
		ret = 0;
		if (ft_isdigit(**str))
		{
			ret = ft_atoi(*str);
			while (ft_isdigit(**str))
				(*str)++;
		}
		if (**str == '*')
		{
			ret = va_arg(ap, int);
			(*str)++;
		}
	}
	return (ret);
}

t_option		ft_getopt(va_list ap, char **str)
{
	t_option	opt;

	opt.width = 0;
	opt.precision = 0;
	opt.flag = get_flag(str);
	opt.width = get_width(str, ap);
	opt.precision = get_precision(str, ap);
	return (opt);
}
