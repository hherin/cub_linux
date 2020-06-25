/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parcing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:56:09 by hherin            #+#    #+#             */
/*   Updated: 2020/04/08 15:13:07 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3.h"

static void	init_path(t_scene *sc)
{
	sc->ceil.txt.path = NULL;
	sc->floor.txt.path = NULL;
	sc->wall_e.txt.path = NULL;
	sc->wall_s.txt.path = NULL;
	sc->wall_n.txt.path = NULL;
	sc->wall_w.txt.path = NULL;
	sc->c_sp.path = NULL;
	sc->b_sp.path = NULL;
}

static void	init_data(t_scene *sc)
{
	sc->r.x = -1;
	sc->r.y = -1;
	sc->ceil.clr = -1;
	sc->floor.clr = -1;
	sc->pl.pos.x = -1.0;
	sc->pl.pos.y = -1.0;
	sc->ray.cam_x = 0;
	sc->nb_sprite = 0;
	sc->see = 0;
}

void		init_parcing(t_scene *sc)
{
	sc->w_map = NULL;
	if (!(sc->wall = malloc(sizeof(t_wall))))
		quit_parc("Wrong allocation in malloc");
	sc->pl.walk_spd = 0.157;
	init_path(sc);
	init_data(sc);
}
