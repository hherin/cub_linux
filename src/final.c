/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherin <hherin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:01:32 by hherin            #+#    #+#             */
/*   Updated: 2020/06/10 14:11:30 by hherin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3.h"

int	final_print(t_scene *sc)
{
	ceil_and_floor(sc, sc->floor, sc->ceil);
	raycasting(sc);
	print_minimap(sc);
	mlx_put_image_to_window(sc->win.mlx_ptr, sc->win.win_ptr, \
							sc->win.img_ptr, 0, 0);
	mlx_string_put(sc->win.mlx_ptr, sc->win.win_ptr, sc->r.x / 2, \
					sc->r.y / 2, 20991844, "X");
	return (1);
}
