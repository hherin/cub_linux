/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherin <hherin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:41:41 by hherin            #+#    #+#             */
/*   Updated: 2020/01/20 13:35:24 by hherin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	lenght;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return ((char*)s2);
	if (s2 == NULL)
		return ((char*)s1);
	lenght = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(char) * lenght + 1)))
		return (NULL);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
