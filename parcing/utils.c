/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:10:37 by hherin            #+#    #+#             */
/*   Updated: 2020/07/01 17:21:01 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3.h"

int		is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int		check_inputs(t_scene sc)
{
	if (sc.r.x < 0 || sc.r.y < 0)
		return (0);
	if (sc.floor.clr < 0 && !sc.floor.txt.path)
		return (0);
	if (sc.ceil.clr < 0 && !sc.ceil.txt.path)
		return (0);
	if (!sc.c_sp.path)
		return (0);
	if (!sc.wall_e.txt.path)
		return (0);
	if (!sc.wall_w.txt.path)
		return (0);
	if (!sc.wall_n.txt.path)
		return (0);
	if (!sc.wall_s.txt.path)
		return (0);
	if (!sc.b_sp.path)
		return (0);
	return (1);
}

void	switch_maps(char ***tab, int i, char *line, t_scene *sc)
{
	char	**tmp;
	int		j;

	j = 0;
	while (ft_isspace(*line))
		line++;
	tmp = tab_parcing(line, *tab, sc);
	while (j < i)
		free((*tab)[j++]);
	free(*tab);
	*tab = tmp;
}
