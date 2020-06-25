/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:08:14 by hherin            #+#    #+#             */
/*   Updated: 2020/04/09 17:27:53 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3.h"

void	m_forward(t_scene *sc)
{
	if (sc->w_map[(int)sc->pl.pos.y]\
		[(int)(sc->pl.pos.x + sc->pl.dir.x * sc->pl.walk_spd)] < '1')
		sc->pl.pos.x += sc->pl.dir.x * sc->pl.walk_spd;
	if (sc->w_map[(int)(sc->pl.pos.y + sc->pl.dir.y * sc->pl.walk_spd)]\
		[(int)(sc->pl.pos.x)] < '1')
		sc->pl.pos.y += sc->pl.dir.y * sc->pl.walk_spd;
}

void	m_back(t_scene *sc)
{
	if (sc->w_map[(int)sc->pl.pos.y]\
		[(int)(sc->pl.pos.x - sc->pl.dir.x * sc->pl.walk_spd)] < '1')
		sc->pl.pos.x -= sc->pl.dir.x * sc->pl.walk_spd;
	if (sc->w_map[(int)(sc->pl.pos.y - sc->pl.dir.y * sc->pl.walk_spd)]\
		[(int)(sc->pl.pos.x)] < '1')
		sc->pl.pos.y -= sc->pl.dir.y * sc->pl.walk_spd;
}

void	m_right(t_scene *sc)
{
	if (sc->w_map[(int)sc->pl.pos.y]\
		[(int)(sc->pl.pos.x + sc->pl.plane.x * sc->pl.walk_spd)] < '1')
		sc->pl.pos.x += sc->pl.plane.x * sc->pl.walk_spd;
	if (sc->w_map[(int)(sc->pl.pos.y + sc->pl.plane.y * sc->pl.walk_spd)]\
		[(int)(sc->pl.pos.x)] < '1')
		sc->pl.pos.y += sc->pl.plane.y * sc->pl.walk_spd;
}

void	m_left(t_scene *sc)
{
	if (sc->w_map[(int)sc->pl.pos.y]\
		[(int)(sc->pl.pos.x - sc->pl.plane.x * sc->pl.walk_spd)] < '1')
		sc->pl.pos.x -= sc->pl.plane.x * sc->pl.walk_spd;
	if (sc->w_map[(int)(sc->pl.pos.y - sc->pl.plane.y * sc->pl.walk_spd)]\
		[(int)(sc->pl.pos.x)] < '1')
		sc->pl.pos.y -= sc->pl.plane.y * sc->pl.walk_spd;
}

void	m_rotation(t_scene *sc)
{
	float tmp_dir_x;
	float tmp_plane_x;

	tmp_dir_x = sc->pl.dir.x;
	sc->pl.dir.x = sc->pl.dir.x * cos(-sc->key.rot_speed) - \
		sc->pl.dir.y * sin(-sc->key.rot_speed);
	sc->pl.dir.y = tmp_dir_x * sin(-sc->key.rot_speed) + sc->pl.dir.y * \
		cos(-sc->key.rot_speed);
	tmp_plane_x = sc->pl.plane.x;
	sc->pl.plane.x = \
		sc->pl.plane.x * cos(-sc->key.rot_speed) - sc->pl.plane.y * \
			sin(-sc->key.rot_speed);
	sc->pl.plane.y = tmp_plane_x * sin(-sc->key.rot_speed) + sc->pl.plane.y * \
		cos(-sc->key.rot_speed);
}
