/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherin <hherin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:42:03 by hherin            #+#    #+#             */
/*   Updated: 2019/11/15 14:53:17 by hherin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *to_find, size_t len)
{
	size_t i;

	i = 0;
	if (len == 0 && *to_find != '\0')
		return (NULL);
	if ((*src == '\0' && *to_find == '\0') || len == 0)
		return ((char*)src);
	if (len == 0)
		return (NULL);
	while (*src && len)
	{
		i = 0;
		while (src[i] == to_find[i] && i < len && src[i])
			i++;
		if (to_find[i] == '\0')
			return ((char*)src);
		src++;
		len--;
	}
	return (NULL);
}
