/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 10:48:35 by heleneherin       #+#    #+#             */
/*   Updated: 2020/04/10 10:39:47 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3.h"

static void		sort_sprite(t_sprite **spr, int size, t_player pl)
{
	int			i;
	int			j;
	t_sprite	tmp;

	sprite_distance(spr, size, pl);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if ((*spr)[j].dist < (*spr)[j + 1].dist)
			{
				tmp = (*spr)[j];
				(*spr)[j] = (*spr)[j + 1];
				(*spr)[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void		n_sprite(t_sprite_obj *obj, t_player pl, t_scene sc, int i)
{
	obj->sprt.x = obj->s[i].coord.x - sc.pl.pos.x + 0.5;
	obj->sprt.y = obj->s[i].coord.y - sc.pl.pos.y + 0.5;
	obj->invdet = 1.0 / (sc.pl.plane.x * pl.dir.y - pl.dir.x * pl.plane.y);
	obj->transfo.x = obj->invdet * (pl.dir.y * obj->sprt.x - pl.dir.x * \
	obj->sprt.y);
	obj->transfo.y = obj->invdet * (-pl.plane.y * obj->sprt.x + pl.plane.x * \
	obj->sprt.y);
	obj->sprite_screen_x = (int)((sc.r.x / 2) * (1 + obj->transfo.x / \
	obj->transfo.y));
	scaling_sprite(obj, *obj->txt);
	obj->sprite_height = abs((int)(sc.r.y / (obj->transfo.y))) / obj->div;
	obj->start.y = -obj->sprite_height / 2 + sc.r.y / 2 + obj->move_sc;
	(obj->start.y < 0) ? obj->start.y = 0 : 0;
	obj->end.y = obj->sprite_height / 2 + sc.r.y / 2 + obj->move_sc;
	(obj->end.y >= sc.r.y) ? obj->end.y = sc.r.y - 1 : 0;
	obj->sprite_wid = abs((int)(sc.r.y / obj->transfo.y)) / obj->div;
	obj->start.x = -obj->sprite_wid / 2 + obj->sprite_screen_x;
	(obj->start.x < 0) ? obj->start.x = 0 : 0;
	obj->end.x = obj->sprite_wid / 2 + obj->sprite_screen_x;
	(obj->end.x >= sc.r.x) ? obj->end.x = sc.r.x - 1 : 0;
}

static void		set_sprite(t_scene *sc, t_sprite_obj *obj, int stripe, \
							t_txt *txt)
{
	int			y;

	y = obj->start.y;
	while (y < obj->end.y)
	{
		obj->d = (y - obj->move_sc) * 256 - sc->r.y * 128 + \
					obj->sprite_height * 128;
		obj->tex.y = ((obj->d * txt->hei) / obj->sprite_height) / 256;
		sc->color = ((int*)txt->addr_ar)[txt->wid * obj->tex.y + obj->tex.x];
		((sc->color & 0xFFFFFF) != 0) ? ft_put_pixel(&sc->win.addr_ar, \
														stripe, y, *sc) : 0;
		y++;
	}
}

void			draw_sprite(t_scene *sc, float z_buf[sc->r.x], \
							t_sprite_obj *obj)
{
	int			i;
	int			stripe;

	i = 0;
	sort_sprite(&obj->s, obj->nb_sp, sc->pl);
	while (i < obj->nb_sp)
	{
		obj->txt = (obj->s[i].c == '2') ? &sc->c_sp : &sc->b_sp;
		n_sprite(&sc->s_obj, sc->pl, *sc, i);
		stripe = obj->start.x;
		while (stripe < obj->end.x)
		{
			obj->tex.x = (int)(256 * (stripe - (-obj->sprite_wid / 2 + \
				obj->sprite_screen_x)) * obj->txt->wid / obj->sprite_wid) / 256;
			if (obj->transfo.y > 0 && stripe > 0 && stripe < sc->r.x && \
				obj->transfo.y < z_buf[stripe])
				set_sprite(sc, obj, stripe, obj->txt);
			stripe++;
		}
		i++;
	}
}
