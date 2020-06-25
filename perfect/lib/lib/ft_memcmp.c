/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherin <hherin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:40:47 by hherin            #+#    #+#             */
/*   Updated: 2019/11/15 14:51:43 by hherin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char		*str1;
	char		*str2;
	size_t		i;

	str1 = (char*)s1;
	str2 = (char*)s2;
	i = 0;
	while (i < n)
	{
		if (ft_strncmp(&str1[i], &str2[i], 1) != 0)
			return (ft_strncmp(&str1[i], &str2[i], 1));
		i++;
	}
	return (0);
}
