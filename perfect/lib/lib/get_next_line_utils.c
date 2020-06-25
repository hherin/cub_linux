/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:03:24 by hherin            #+#    #+#             */
/*   Updated: 2020/04/09 18:38:28 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_sjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	lenght;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL)
		lenght = ft_strlen(s2);
	else if (s2 == NULL)
		lenght = ft_strlen(s1);
	else
		lenght = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(char) * lenght + 1)))
		return (NULL);
	while (s1 && s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j] && s2)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
