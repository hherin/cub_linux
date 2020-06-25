/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherin <hherin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:50:39 by hherin            #+#    #+#             */
/*   Updated: 2019/11/15 14:53:36 by hherin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isset(char s, const char *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strsize(const char **s, const char *set)
{
	size_t i;

	while (ft_isset(**s, set) && **s)
		(*s)++;
	if (**s == '\0')
		return (1);
	i = ft_strlen(*s) - 1;
	while (ft_isset(*(*s + i), set))
		i--;
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len;

	if (s1 == NULL)
		return (NULL);
	len = ft_strsize(&s1, set);
	str = ft_substr(s1, 0, len);
	return (str);
}
