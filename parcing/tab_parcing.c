/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_parcing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:52:15 by hherin            #+#    #+#             */
/*   Updated: 2020/07/13 11:07:39 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3.h"

static void	init_player(t_player *p1, int i, char *line, int index)
{
	(p1->pos.x < 0) ? 0 : quit_parc("There is too many players");
	p1->pos.x = i + 0.5;
	p1->pos.y = index - 1 + 0.5;
	get_dir(p1, line[i]);
}

static char	*new_element(char *line, char *new_tab)
{
	int	i;

	i = -1;
	if (!(new_tab = ft_strdup(line)))
		quit_parc("Wrong allocation in the map");
	i = -1;
	while (++i < (int)ft_strlen(new_tab))
	{
		if (new_tab[i] != '0' && new_tab[i] != '1' && new_tab[i] != '2'
		&& new_tab[i] != 'N' && new_tab[i] != 'E' && new_tab[i] != 'W'
		&& new_tab[i] != 'S' && new_tab[i] != '3' && !ft_isspace(new_tab[i]))
			quit_parc("Wrong input in map");
	}
	return (new_tab);
}

char		**tab_parcing(char *line, char **tab, t_scene *sc)
{
	static int	index = 0;
	int			i;
	char		**new_tab;

	i = -1;
	if (!(new_tab = (char**)malloc(sizeof(char*) * (index + 1))))
		quit_parc_after_sc("Wrong allocation in the map", sc, line);
	while (++i < index)
		if (!(new_tab[i] = ft_strdup(tab[i])))
			quit_parc_after_sc("Wrong allocation in the map", sc, line);
	index = i + 1;
	new_tab[i] = new_element(line, new_tab[i]);
	((int)ft_strlen(new_tab[i]) > sc->max_map) ? \
		sc->max_map = ft_strlen(new_tab[i]) : 0;
	i = -1;
	while (++i < (int)ft_strlen(line))
	{
		if (is_player(line[i]))
		{
			init_player(&sc->pl, i, line, index);
			new_tab[index - 1][i] = '0';
		}
	}
	return (new_tab);
}
