/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:47:01 by hherin            #+#    #+#             */
/*   Updated: 2020/06/18 21:37:33 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3.h"

static void	apload_txt(t_scene *sc, t_txt *smt)
{
	if (!(smt->img_ptr = mlx_xpm_file_to_image(sc->win.mlx_ptr, \
			smt->path, &smt->wid, &smt->hei)))
		quit_prog(sc, "wrong path of texture");
	if (!(smt->addr_ar = mlx_get_data_addr(smt->img_ptr, \
			&smt->bit_pixel, &smt->size_line, \
			&smt->endian)))
		quit_prog(sc, "No data addr in texture");
	free(smt->path);
}

void		init_texture(t_scene *sc)
{
	apload_txt(sc, &sc->wall_e.txt);
	apload_txt(sc, &sc->wall_w.txt);
	apload_txt(sc, &sc->wall_n.txt);
	apload_txt(sc, &sc->wall_s.txt);
	(sc->ceil.clr == -1) ? apload_txt(sc, &sc->ceil.txt) : 0;
	(sc->floor.clr == -1) ? apload_txt(sc, &sc->floor.txt) : 0;
	(sc->b_sp.path) ? apload_txt(sc, &sc->b_sp) : 0;
	(sc->c_sp.path) ? apload_txt(sc, &sc->c_sp) : 0;
}
