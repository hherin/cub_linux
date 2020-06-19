/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:30:01 by hherin            #+#    #+#             */
/*   Updated: 2020/04/08 14:52:28 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3.h"

static char	*ft_getpath(char *line)
{
	char	*str;

	line += (*line == 'S' && *(line + 1) != 'O') ? 1 : 2;
	if (!(str = ft_strtrim(line, " 	")))
		quit_parc("Something when wrong with path traitment");
	return (str);
}

static int	ft_getclr(char *line)
{
	int		nb;
	int		interm;

	(ft_isdigit(*line)) ? 0 : quit_parc("Wrong input color");
	if ((interm = ft_atoi_trim(&line)) < 0 || interm > 255)
		quit_parc("Wrong red color");
	(*line == ',' && ft_isdigit(*(line + 1))) ? line++ :
					quit_parc("Wrong color separator");
	nb = interm;
	if ((interm = ft_atoi_trim(&line)) < 0 || interm > 255)
		quit_parc("green color");
	(*line == ',' && ft_isdigit(*(line + 1))) ? line++ :
					quit_parc("Wrong color separator");
	nb = nb * pow(10, nb_size(interm)) + interm;
	if ((interm = ft_atoi_trim(&line)) < 0 || interm > 255)
		quit_parc("Wrong blue color");
	nb = nb * pow(10, nb_size(interm)) + interm;
	while (ft_isspace(*line))
		line++;
	if (*line)
		quit_parc("Too many arguments in color");
	return (nb);
}

static void	ft_get_resol(t_scene *scene, char *line)
{
	scene->r.x = -1;
	scene->r.y = -1;
	while (*line == 'R' || *line == ' ' || *line == '\t')
		line++;
	(ft_isdigit(*line)) ? 0 : quit_parc("Wrong first input in resolution");
	scene->r.x = ft_atoi_trim(&line);
	while (*line > 0 && *line < 33)
		line++;
	(ft_isdigit(*line)) ? 0 : quit_parc("Wrong second input in resolution");
	scene->r.y = ft_atoi_trim(&line);
	if (scene->r.x > 2560 && scene->r.y > 1440)
	{
		scene->r.x = 2560;
		scene->r.y = 1440;
	}
	while (ft_isspace(*line))
		line++;
	if (*line)
		quit_parc("Too many arguments in resolution");
}

static void	ft_parc_clr(t_scene *sc, char *line)
{
	int		cpt;

	cpt = 0;
	if (*line == 'F')
		cpt = 1;
	if (*line == 'C')
		cpt = 2;
	line++;
	while (*line > 0 && *line < 33)
		line += 1;
	if (cpt == 1)
	{
		if (*line == '.')
			sc->floor.txt.path = ft_getpath(line);
		else
			sc->floor.clr = ft_getclr(line);
	}
	else
	{
		if (*line == '.')
			sc->ceil.txt.path = ft_getpath(line);
		else
			sc->ceil.clr = ft_getclr(line);
	}
}

void		ft_filestruct(t_scene *sc, char *line)
{
	char *tmp;

	tmp = line;
	if (*line == 'R')
		ft_get_resol(sc, line);
	else if (*line == 'F')
		ft_parc_clr(sc, line);
	else if (*line == 'C')
		ft_parc_clr(sc, line);
	else if (*line == 'N' && *(line + 1) == 'O')
		sc->wall_n.txt.path = ft_getpath(line);
	else if (*line == 'S' && *(line + 1) == 'O')
		sc->wall_s.txt.path = ft_getpath(line);
	else if (*line == 'W' && *(line + 1) == 'E')
		sc->wall_w.txt.path = ft_getpath(line);
	else if (*line == 'E' && *(line + 1) == 'A')
		sc->wall_e.txt.path = ft_getpath(line);
	else if (*line == 'S' && ft_isspace(*(line + 1)))
		sc->c_sp.path = ft_getpath(line);
	else if (*line == 'T' && ft_isspace(*(line + 1)))
		sc->b_sp.path = ft_getpath(line);
	else
		quit_parc("wrong configuration (file struct)");
	line = tmp;
}
