/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:33:44 by hherin            #+#    #+#             */
/*   Updated: 2020/07/01 17:25:50 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3.h"

static char			**init_map(int map_l, int max_map)
{
	char			**nw_map;
	int				i;

	i = 0;
	if (!(nw_map = malloc(sizeof(char*) * (map_l + 2))))
		quit_parc("error malloc check map.");
	while (i < map_l + 2)
	{
		nw_map[i] = malloc(sizeof(char) * max_map);
		nw_map[i][max_map - 1] = '\0';
		nw_map[i] = ft_memset(nw_map[i], '.', max_map - 1);
		i++;
	}
	return (nw_map);
}

static void			map_copy(char **w_map, char ***dest, int map_l)
{
	t_int_tup		src;
	t_int_tup		dst;
	char			c;
	int				size;

	src.x = -1;
	dst.x = 1;
	while (++src.x < map_l)
	{
		src.y = -1;
		dst.y = 1;
		size = (int)ft_strlen(w_map[src.x]);
		while (++src.y < size)
		{
			c = w_map[src.x][src.y];
			(*dest)[dst.x][dst.y] = (is_player(c)) ? '0' : c;
			(*dest)[dst.x][dst.y] = (ft_isspace(c)) ? '.' : c;
			dst.y++;
		}
		dst.x++;
	}
}

static t_int_tup	check_map(char **m, int map_l)
{
	int				i;
	int				j;
	int				size;
	t_int_tup		pos;

	i = 0;
	pos.x = -1;
	pos.y = -1;
	while (++i < map_l + 2)
	{
		size = (int)ft_strlen(m[i]);
		j = 0;
		while (++j < size)
		{
			if (m[i][j] == '0')
			{
				pos.x = j;
				pos.y = i;
				return (pos);
			}
		}
	}
	return (pos);
}

int					rec_check(char ***m, t_int_tup pos, int map_l)
{
	int				i;
	int				j;

	i = pos.y;
	j = pos.x;
	while (j > 0 && (*m)[i][j - 1] == '0')
		j--;
	while (j < (int)ft_strlen((*m)[i]) && (*m)[i][j] != '1')
	{
		((*m)[i][j] == '0') ? (*m)[i][j] = 'x' : 0;
		((*m)[i][j] == '.') ? quit_parc("map not closed") : 0;
		j++;
	}
	j = pos.x;
	while (i > 0 && ((*m)[i -1][j] == '0'))
		i--;
	while (i < map_l + 3 && (*m)[i][j] != '1')
	{
		((*m)[i][j] == '0') ? (*m)[i][j] = 'x' : 0;
		((*m)[i][j] == '.') ? quit_parc("map not closed") : 0;
		i++;
	}
	pos = check_map(*m, map_l);
	if (pos.x != -1)
		rec_check(m, pos, map_l);
	return (1);
}

void				error_map(char **w_map, int map_l, int max_map)
{
	char			**new_map;
	t_int_tup		pl;
	int				ret;
	int				i;

	i = 0;
	new_map = init_map(map_l, max_map + 3);
	map_copy(w_map, &new_map, map_l);
	pl = check_map(new_map, map_l);
	ret = rec_check(&new_map, pl, map_l);
	while (i < map_l + 2)
	{
		free(new_map[i]);
		i++;
	}
	free(new_map);
	if (!ret)
		quit_parc("map not closed");
}
