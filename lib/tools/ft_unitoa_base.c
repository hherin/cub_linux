/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherin <hherin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 12:05:28 by hherin            #+#    #+#             */
/*   Updated: 2020/02/06 14:22:33 by hherin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tools.h"

static	unsigned int	length_n_unsigned(unsigned int n, char *base)
{
	unsigned int		length;

	length = (n == 0) ? 1 : 0;
	while (n > 0)
	{
		n = n / ft_strlen(base);
		length++;
	}
	return (length);
}

char					*ft_unitoa_base(unsigned int n, char *base)
{
	char				*p;
	int					size;
	unsigned int		length;

	length = length_n_unsigned(n, base);
	size = ft_strlen(base);
	if (!(p = malloc(sizeof(char) * (length + 1))))
		return (0);
	p[length] = '\0';
	while (length)
	{
		p[--length] = base[n % size];
		n = n / size;
	}
	return (p);
}
