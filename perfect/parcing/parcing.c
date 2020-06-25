/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:35:48 by hherin            #+#    #+#             */
/*   Updated: 2020/04/09 18:03:38 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3.h"

static void		set_struct(t_scene *sc, char *line, int *i)
{
	int			j;

	j = 0;
	(*line) ? pre_check(line) : 0;
	(ft_isalpha(*line)) ? ft_filestruct(sc, line) : 0;
	while (ft_isspace(line[j]))
		j++;
	if (ft_isdigit(*(line + j)) || sc->w_map)
	{
		if (!check_inputs(*sc))
			quit_parc_after_sc("Miss config info before map", sc, line);
		switch_maps(&sc->w_map, *i, line + j, sc);
		*i += 1;
	}
	free(line);
}

t_scene			rc_parcing(char *av)
{
	int			fd;
	char		*line;
	int			i;
	t_scene		sc;
	int			ret;

	i = 0;
	if ((fd = open(av, O_RDONLY)) < 0)
		quit_parc("Can't open the file");
	init_parcing(&sc);
	while ((ret = get_next_line(fd, &line)) >= 0)
	{
		set_struct(&sc, line, &i);
		if (ret == 0)
			break ;
	}
	(sc.pl.pos.x != -1) ? 0 : quit_parc_after_sc("no player", &sc, line);
	final_set_map(i, &sc.map_line, &sc);
	if (!sc.wall_e.txt.path || !sc.wall_w.txt.path || !sc.wall_n.txt.path \
	|| !sc.wall_s.txt.path || !sc.b_sp.path || !sc.c_sp.path)
		quit_parc("Missing path in configuration file");
	close(fd);
	return (sc);
}
