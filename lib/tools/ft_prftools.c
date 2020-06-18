/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prftools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherin <hherin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 12:05:11 by hherin            #+#    #+#             */
/*   Updated: 2020/02/06 14:23:37 by hherin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tools.h"

char	*ft_memaset(char *tmp, size_t size)
{
	if (!(tmp = malloc(sizeof(char) * size + 1)))
		return (NULL);
	tmp[size] = '\0';
	tmp = ft_memset(tmp, ' ', size);
	return (tmp);
}

char	*ft_finalcopy(char *tmp, char *s, size_t start, size_t zero)
{
	size_t	i;

	i = 0;
	while (i++ < zero)
		tmp[start++] = '0';
	i = 0;
	while (i < ft_strlen(s))
		tmp[start++] = s[i++];
	return (tmp);
}

int		ft_abso(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}

int		ft_istype(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X'
		|| c == 'p' || c == 's' || c == '%' || c == 'c')
		return (1);
	return (0);
}
