/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:07:52 by hherin            #+#    #+#             */
/*   Updated: 2020/07/01 17:25:27 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3.h"

void	init_cub(t_scene *sc, t_win *win, t_int_tup r)
{
	sc->win.boole_quit = 0;
	if (!(win->img_ptr = mlx_new_image(win->mlx_ptr, r.x, r.y)))
		quit_prog(sc, "No image of window created");
	if (!(win->addr_ar = mlx_get_data_addr(win->img_ptr, &win->bit_pixel, \
		&win->size_line, &win->endian)))
		quit_prog(sc, "No data address of window created");
	init_texture(sc);
}

void	loop_cub(t_win *win, t_int_tup r, t_scene *sc)
{
	sc->win.boole_quit = 1;
	win->win_ptr = mlx_new_window(win->mlx_ptr, r.x, r.y, "GO BACK TO WORK");
	if (win->win_ptr == NULL)
		quit_prog(sc, "Window creation failed");
	final_print(sc);
	mlx_hook(win->win_ptr, KEYPRESS, (1L << 0), &key_press, sc);
	mlx_hook(win->win_ptr, KEYRELEASE, (1L << 1), &key_release, sc);
	mlx_hook(win->win_ptr, 33, (1L << 17), &quit_window, sc);
	mlx_loop_hook(win->mlx_ptr, &final_print, sc);
}

void	ft_put_pixel(char **ret_get_data_addr, int x, int y, t_scene sc)
{
	int *pix_array;

	pix_array = (int*)(*ret_get_data_addr);
	pix_array[x + sc.r.x * y] = sc.color;
}

int		ft_get_color(char *ret_get_data_addr, int start)
{
	int ret;
	int *cast_ret;

	cast_ret = (int*)ret_get_data_addr;
	ret = cast_ret[start];
	return (ret);
}
