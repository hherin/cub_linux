/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 15:42:22 by heleneherin       #+#    #+#             */
/*   Updated: 2020/07/13 13:40:19 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3.h"

static void	pl_init(t_mini *mini, t_scene sc, int boole, t_float_tup pos)
{
	mini->fl.x = (int)((pos.x - (int)pos.x) * sc.pxl.x);
	mini->fl.y = (int)((pos.y - (int)pos.y) * sc.pxl.y);
	mini->cur.x = ((int)pos.x * sc.pxl.x) + mini->fl.x - sc.pl_sq.x / 2;
	(boole) ? \
	mini->cur.y = ((int)pos.y * sc.pxl.y) + mini->fl.y - sc.pl_sq.y / 2 : 0;
	mini->max.x = mini->cur.x + sc.pl_sq.x;
	(boole) ? \
	mini->max.y = mini->cur.y + sc.pl_sq.y : 0;
}

static void	mini_pl(int color, t_scene *sc)
{
	t_mini	mini;

	sc->pl_sq.x = PL * sc->pxl.x;
	sc->pl_sq.y = PL * sc->pxl.y;
	pl_init(&mini, *sc, 1, sc->pl.pos);
	while (mini.cur.y < mini.max.y)
	{
		pl_init(&mini, *sc, 0, sc->pl.pos);
		while (mini.cur.x < mini.max.x)
		{
			sc->color = color;
			ft_put_pixel(&sc->win.addr_ar, mini.cur.x, mini.cur.y, *sc);
			mini.cur.x++;
		}
		mini.cur.y++;
	}
}

void		print_minimap(t_scene *sc)
{
	int		x;
	int		y;

	sc->pxl.x = PXL * sc->r.x;
	sc->pxl.y = PXL * sc->r.y;
	if ((y = -1) == -1 && sc->key.f_disp)
	{
		sc->key.f_disp = 0;
		while (++y < sc->map_line * sc->pxl.y)
		{
			x = -1;
			while (++x < (int)ft_strlen(sc->w_map[y / sc->pxl.y]) * sc->pxl.x)
			{
				if (sc->w_map[y / sc->pxl.y][x / sc->pxl.x] == '0')
					sc->color = 12632256;
				else if (sc->w_map[y / sc->pxl.y][x / sc->pxl.x] == '1')
					sc->color = 0;
				else
					sc->color = 8421504;
				(x % sc->pxl.x && y % sc->pxl.y) ? \
					ft_put_pixel(&sc->win.addr_ar, -x, y, *sc) : 0;
			}
		}
		(y) ? mini_pl(16711680, sc) : 0;
	}
}
