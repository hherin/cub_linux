/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoahexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherin <hherin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 12:04:47 by hherin            #+#    #+#             */
/*   Updated: 2020/02/06 14:23:53 by hherin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tools.h"

static	unsigned int	length_nhexa(long n)
{
	unsigned int length;

	length = (n == 0) ? 1 : 0;
	while (n > 0)
	{
		n = n / 16;
		length++;
	}
	return (length);
}

char					*ft_itoahexa(long n)
{
	char				*p;
	unsigned int		length;
	char				*base;

	length = length_nhexa(n) + 2;
	base = "0123456789abcdef";
	if (!(p = malloc(sizeof(char) * (length + 1))))
		return (0);
	p[length] = '\0';
	while (length > 1)
	{
		p[--length] = base[n % 16];
		n = n / 16;
	}
	p[1] = 'x';
	p[0] = '0';
	return (p);
}
