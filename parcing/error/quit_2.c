/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 14:28:57 by heleneherin       #+#    #+#             */
/*   Updated: 2020/04/09 18:32:42 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3.h"

void	free_path(t_scene *sc)
{
	(sc->ceil.txt.path) ? free(sc->ceil.txt.path) : 0;
	(sc->floor.txt.path) ? free(sc->floor.txt.path) : 0;
	(sc->wall_e.txt.path) ? free(sc->wall_e.txt.path) : 0;
	(sc->wall_s.txt.path) ? free(sc->wall_s.txt.path) : 0;
	(sc->wall_w.txt.path) ? free(sc->wall_w.txt.path) : 0;
	(sc->c_sp.path) ? free(sc->c_sp.path) : 0;
	(sc->b_sp.path) ? free(sc->b_sp.path) : 0;
}

void	free_win(t_scene *sc)
{
	if (sc->win.img_ptr)
		mlx_destroy_image(sc->win.mlx_ptr, sc->win.img_ptr);
	if (sc->b_sp.img_ptr)
		mlx_destroy_image(sc->win.mlx_ptr, sc->b_sp.img_ptr);
	if (sc->c_sp.img_ptr)
		mlx_destroy_image(sc->win.mlx_ptr, sc->c_sp.img_ptr);
	if (sc->win.boole_quit)
		mlx_destroy_window(sc->win.mlx_ptr, sc->win.win_ptr);
}

void	free_tab(char ***tab, t_scene sc)
{
	int		i;

	i = -1;
	while (++i < sc.map_line)
		free((*tab)[i]);
	free(*tab);
}
