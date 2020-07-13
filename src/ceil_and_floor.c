/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceil_and_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 20:43:36 by hherin            #+#    #+#             */
/*   Updated: 2020/04/09 17:31:47 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3.h"

static void	i_comp(t_scene sc, t_floor *fl, int y)
{
	fl->raydir_0.x = sc.pl.dir.x - sc.pl.plane.x;
	fl->raydir_0.y = sc.pl.dir.y - sc.pl.plane.y;
	fl->raydir_1.x = sc.pl.dir.x + sc.pl.plane.x;
	fl->raydir_1.y = sc.pl.dir.y + sc.pl.plane.y;
	fl->p = y - sc.r.y / 2;
	fl->row_dist = (!fl->p) ? INT_MAX : (0.5 * sc.r.y) / fl->p;
	fl->step.x = fl->row_dist * (fl->raydir_1.x - fl->raydir_0.x) / sc.r.x;
	fl->step.y = fl->row_dist * (fl->raydir_1.y - fl->raydir_0.y) / sc.r.x;
	fl->floor.x = sc.pl.pos.x + fl->row_dist * fl->raydir_0.x;
	fl->floor.y = sc.pl.pos.y + fl->row_dist * fl->raydir_0.y;
}

static void	text_comp(t_floor *fl, t_ceil *ce)
{
	fl->floor.x -= floor(fl->floor.x);
	fl->floor.y -= floor(fl->floor.y);
	if (fl->clr == -1)
	{
		fl->t.x = (fl->txt.wid * fl->floor.x);
		(fl->txt.wid * fl->floor.x > fl->txt.wid - 1) ? \
		fl->t.x = fl->txt.wid - 1 : 0;
		fl->t.y = (fl->txt.hei * fl->floor.y);
		(fl->t.y > fl->txt.hei - 1) ? fl->t.y = fl->txt.hei - 1 : 0;
	}
	if (ce->clr == -1)
	{
		ce->t.x = (ce->txt.wid * fl->floor.x);
		(ce->t.x > ce->txt.wid - 1) ? ce->t.x = ce->txt.wid - 1 : 0;
		ce->t.y = (ce->txt.hei * fl->floor.y);
		(ce->t.y > ce->txt.hei - 1) ? ce->t.y = ce->txt.hei - 1 : 0;
	}
	fl->floor.x += fl->step.x;
	fl->floor.y += fl->step.y;
}

void		ceil_and_floor(t_scene *sc, t_floor fl, t_ceil ce)
{
	int		x;
	int		y;

	y = -1;
	if (sc->key.f_disp)
	{
		while (++y < sc->r.y)
		{
			(fl.clr < 0 || ce.clr < 0) ? i_comp(*sc, &fl, y) : 0;
			x = -1;
			while (++x < sc->r.x)
			{
				(fl.clr < 0 || ce.clr < 0) ? text_comp(&fl, &ce) : 0;
				sc->color = (fl.clr == -1) ? \
				((int*)fl.txt.addr_ar)[fl.txt.wid * fl.t.y + fl.t.x] : fl.clr;
				ft_put_pixel(&sc->win.addr_ar, -x, y, *sc);
				sc->color = (ce.clr == -1) ? \
				((int*)ce.txt.addr_ar)[ce.txt.wid * ce.t.y + ce.t.x] : ce.clr;
				ft_put_pixel(&sc->win.addr_ar, -x, sc->r.y - y - 1, *sc);
			}
		}
	}
}
