/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:07:15 by hherin            #+#    #+#             */
/*   Updated: 2020/07/08 19:41:13 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3.h"

static void	init_ray(t_ray *ray, t_player pl, int x, t_int_tup r)
{
	ray->cam_x = (2 * x / (float)r.x) - 1;
	ray->dir.x = pl.dir.x + pl.plane.x * ray->cam_x;
	ray->dir.y = pl.dir.y + pl.plane.y * ray->cam_x;
	ray->ddist.x = fabs(1 / ray->dir.x);
	ray->ddist.y = fabs(1 / ray->dir.y);
	ray->map.x = (int)pl.pos.x;
	ray->map.y = (int)pl.pos.y;
	ray->hit = 0;
	ray->step.x = (ray->dir.x < 0) ? -1 : 1;
	ray->dist.x = (ray->dir.x < 0) ? \
			(pl.pos.x - ray->map.x) * ray->ddist.x : \
			(ray->map.x + 1.0 - pl.pos.x) * ray->ddist.x;
	ray->step.y = (ray->dir.y < 0) ? -1 : 1;
	ray->dist.y = (ray->dir.y < 0) ? \
		(pl.pos.y - ray->map.y) * ray->ddist.y : \
		(ray->map.y + 1.0 - pl.pos.y) * ray->ddist.y;
}

static void	dda_cast(t_ray *ray, t_player pl, char **w_map, t_scene *sc)
{
	while (ray->hit == 0)
	{
		if (ray->dist.x < ray->dist.y)
		{
			ray->map.x += (int)ray->step.x;
			ray->dist.x += ray->ddist.x;
			ray->side = 0;
			sc->wall = (ray->dir.x < 0) ? &sc->wall_w : &sc->wall_e;
		}
		else
		{
			ray->map.y += (int)ray->step.y;
			ray->dist.y += ray->ddist.y;
			ray->side = 1;
			sc->wall = (ray->dir.y < 0) ? &sc->wall_n : &sc->wall_s;
		}
		(w_map[ray->map.y][ray->map.x] == '1') ? ray->hit = 1 : 0;
	}
	ray->perp_wall = (ray->side == 0) ? \
		fabs((ray->map.x - pl.pos.x + (1 - ray->step.x) / 2) / ray->dir.x) : \
		fabs((ray->map.y - pl.pos.y + (1 - ray->step.y) / 2) / ray->dir.y);
}

static void	wall_computation(t_wall *wall, t_scene sc, int line_hei, int start)
{
	wall->wall_x = (sc.ray.side) ? sc.pl.pos.x + (sc.ray.map.y - sc.pl.pos.y + \
					(1 - sc.ray.step.y) / 2) / sc.ray.dir.y * sc.ray.dir.x \
						: sc.pl.pos.y + ((sc.ray.map.x - sc.pl.pos.x + \
						(1 - sc.ray.step.x) / 2) / sc.ray.dir.x) * sc.ray.dir.y;
	wall->wall_x -= floor(wall->wall_x);
	wall->text.x = (int)(wall->wall_x * wall->txt.wid);
	if ((!sc.ray.side && sc.ray.dir.x > 0) || (sc.ray.side && sc.ray.dir.y < 0))
		wall->text.x = wall->txt.wid - wall->text.x - 1;
	wall->step = 1.0 * wall->txt.hei / line_hei;
	wall->posx_txt = (start - sc.r.y / 2 + line_hei / 2) * wall->step;
}

static void	compute_clr(t_ray ray, t_scene *sc, int x, t_wall *wall)
{
	int		y;
	int		line_hei;
	int		start;
	int		end;

	line_hei = abs((int)(sc->r.y / ray.perp_wall));
	start = (int)(-line_hei / 2 + sc->r.y / 2);
	(start < 0) ? start = 0 : 0;
	end = (int)(line_hei / 2 + sc->r.y / 2);
	(end >= sc->r.y) ? end = sc->r.y - 1 : 0;
	y = start;
	wall_computation(wall, *sc, line_hei, start);
	while (y < end)
	{
		sc->wall->text.y = (y * 2 - sc->r.y + line_hei) * \
		(sc->wall->txt.hei / 2) / line_hei;
		sc->wall->posx_txt += sc->wall->step;
		sc->color = (int)ft_get_color(sc->wall->txt.addr_ar, \
		sc->wall->txt.wid * sc->wall->text.y + sc->wall->text.x);
		ft_put_pixel(&sc->win.addr_ar, x, y, *sc);
		y++;
	}
}

int			raycasting(t_scene *sc)
{
	int		x;
	float	z_buf[sc->r.x];

	x = 0;
	if (sc->key.f_disp)
	{
		while (x < sc->r.x)
		{
			init_ray(&sc->ray, sc->pl, x, sc->r);
			dda_cast(&sc->ray, sc->pl, sc->w_map, sc);
			compute_clr(sc->ray, sc, x, sc->wall);
			z_buf[x] = sc->ray.perp_wall;
			x++;
		}
		(sc->b_sp.addr_ar) ? draw_sprite(sc, z_buf, &sc->s_obj) : 0;
	}
	return (1);
}
