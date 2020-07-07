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
	//write(1, "1\n", 2);
	ceil_and_floor(sc, sc->floor, sc->ceil);
	//write(1, "2\n", 2);
	raycasting(sc);
	//write(1, "3\n", 2);
	print_minimap(sc);
	//write(1, "4\n", 2);
	mlx_put_image_to_window(sc->win.mlx_ptr, sc->win.win_ptr, \
							sc->win.img_ptr, 0, 0);
	//write(1, "5\n", 2);
	mlx_do_sync(sc->win.mlx_ptr);
	//write(1, "6\n", 2);
	return (1);
}
