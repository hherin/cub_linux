/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:03:30 by hherin            #+#    #+#             */
/*   Updated: 2020/04/09 18:38:22 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_strdel(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
}

int				ft_resume(char **line, char *buf, int *index, int i)
{
	char		*str;
	char		*tmp;

	if (!(str = ft_substr(buf, i, *index - i)))
	{
		ft_strdel(&str);
		return (0);
	}
	tmp = *line;
	if (!(*line = ft_sjoin(tmp, str)))
	{
		ft_strdel(&str);
		return (0);
	}
	ft_strdel(&str);
	ft_strdel(&tmp);
	(*index)++;
	return (1);
}

int				ft_resume2(char *buf, char **line, int *index, int i)
{
	char		*tmp;
	int			j;

	j = 0;
	tmp = *line;
	if (!(*line = ft_sjoin(tmp, buf + i)))
		return (0);
	ft_strdel(&tmp);
	while (buf[j])
		buf[j++] = 0;
	*index = 0;
	return (1);
}

int				ft_filetheline(int fd, char **line, char *buf, int *index)
{
	int				i;
	int				nread;

	nread = 1;
	while (nread > 0)
	{
		i = *index;
		if (*index == 0)
			if (!(nread = read(fd, buf, BUFFER_SIZE)))
				return (0);
		if (nread == -1)
			return (-1);
		while (buf[*index] != '\n' && buf[*index] != '\0')
			(*index)++;
		if (buf[*index] == '\n')
			return ((ft_resume(line, buf, index, i) == 0)) ? -1 : 1;
		else
		{
			if (!(ft_resume2(buf, line, index, i)))
				return (-1);
		}
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	int				ret;
	static t_get	elem;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	*line = (char*)ft_calloc(1, 1);
	ret = ft_filetheline(fd, line, elem.buffer, &(elem.index));
	return (ret);
}
