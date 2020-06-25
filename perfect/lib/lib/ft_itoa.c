/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherin <hherin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:36:29 by hherin            #+#    #+#             */
/*   Updated: 2019/11/15 14:50:48 by hherin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nblen(unsigned int nb)
{
	int len;

	len = 0;
	if (nb < 10)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int				len;
	char			*str;
	unsigned int	nb;

	len = (n < 0) ? ft_nblen(-n) + 1 : ft_nblen(n);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	nb = n;
	if (n < 0)
	{
		*str = '-';
		nb = -n;
	}
	*(str + len--) = '\0';
	while (len > (*str == '-' ? 0 : -1))
	{
		if (nb > 9)
		{
			str[len--] = (nb % 10) + '0';
			nb /= 10;
		}
		else
			str[len--] = nb + '0';
	}
	return (str);
}
