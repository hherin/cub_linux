/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:30:01 by hherin            #+#    #+#             */
/*   Updated: 2020/07/13 11:37:14 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3.h"

static char	*ft_getpath(char *line)
{
	char	*str;

	line += (*line == 'S' && *(line + 1) != 'O') ? 1 : 2;
	if (!(str = ft_strtrim(line, " 	")))
		quit_parc("Something when wrong with path traitment");
	if (check_output(str, ".xpm"))
		quit_parc("Wrong texture extension");
	return (str);
}

static int	ft_getclr(char *line)
{
	int		nb;
	int		tmp;

	(ft_isdigit(*line)) ? 0 : quit_parc("Wrong red input color");
	if ((tmp = ft_atoi_trim(&line)) < 0 || tmp > 255)
		quit_parc("Wrong red color");
	if (*line == ',')
		line++;
	else
		quit_parc("Wrong color separator1");
	(!ft_isdigit(*line)) ? quit_parc("Wrong green input color") : 0;
	nb = tmp * 65536;
	if ((tmp = ft_atoi_trim(&line)) < 0 || tmp > 255)
		quit_parc("Green color not in good range");
	if (*line == ',')
		line++;
	else
		quit_parc("Wrong color separator2");
	(!ft_isdigit(*line)) ? quit_parc("Wrong blue input color") : 0;
	nb = nb + (tmp * 256);
	if ((tmp = ft_atoi_trim(&line)) < 0 || tmp > 255)
		quit_parc("Blue color not in good range");
	nb = nb + tmp;
	(*line) ? quit_parc("Too many arguments in color") : 0;
	return (nb);
}

static void	ft_get_resol(t_scene *sc, char *line)
{
	mlx_get_screen_size(sc->win.mlx_ptr, &sc->limit.x, &sc->limit.y);
	sc->r.x = -1;
	sc->r.y = -1;
	while (*line == 'R' || *line == ' ' || *line == '\t')
		line++;
	(ft_isdigit(*line)) ? 0 : quit_parc("Wrong first input in resolution");
	if (!(sc->r.x = ft_atoi_trim(&line)))
		quit_parc("X resolution is invalid");
	while (*line > 0 && *line < 33)
		line++;
	(ft_isdigit(*line)) ? 0 : quit_parc("Wrong second input in resolution");
	if (!(sc->r.y = ft_atoi_trim(&line)))
		quit_parc("Y resolution is invalid");
	(sc->r.x > sc->limit.x) ? sc->r.x = sc->limit.x : 0;
	(sc->r.y > sc->limit.y) ? sc->r.y = sc->limit.y : 0;
	(sc->r.x % 2) ? sc->r.x++ : 0;
	(sc->r.y % 2) ? sc->r.y++ : 0;
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
	if (*line == 'R' && sc->r.x == -1)
		ft_get_resol(sc, line);
	else if (*line == 'F' && (!sc->floor.txt.path && sc->floor.clr == -1))
		ft_parc_clr(sc, line);
	else if (*line == 'C' && (!sc->ceil.txt.path && sc->ceil.clr == -1))
		ft_parc_clr(sc, line);
	else if (*line == 'N' && *(line + 1) == 'O' && !sc->wall_n.txt.path)
		sc->wall_n.txt.path = ft_getpath(line);
	else if (*line == 'S' && *(line + 1) == 'O' && !sc->wall_s.txt.path)
		sc->wall_s.txt.path = ft_getpath(line);
	else if (*line == 'W' && *(line + 1) == 'E' && !sc->wall_w.txt.path)
		sc->wall_w.txt.path = ft_getpath(line);
	else if (*line == 'E' && *(line + 1) == 'A' && !sc->wall_e.txt.path)
		sc->wall_e.txt.path = ft_getpath(line);
	else if (*line == 'S' && ft_isspace(*(line + 1)) && !sc->c_sp.path)
		sc->c_sp.path = ft_getpath(line);
	else if (*line == 'T' && ft_isspace(*(line + 1)) && !sc->b_sp.path)
		sc->b_sp.path = ft_getpath(line);
	else
		quit_parc("wrong configuration (file struct)");
	line = tmp;
}
