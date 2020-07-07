/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherin <hherin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:39:03 by hherin            #+#    #+#             */
/*   Updated: 2020/06/10 14:58:27 by hherin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3_H
# define CUB3_H
                                #include <stdio.h>
# include "struct.h"
# include "lgl_define.h"
# include "mlx/mlx.h"
# include "../lib/inc/ft_printf.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>

# define N 0
# define S 1
# define E 2
# define W 3
# define PXL 0.01
# define PL 0.5
# define HEXA "0123456789ABCDEF"
# define DEC "0123456789"

/*
** ================  PARCING  =================
*/
void	rc_parcing(char *av, t_scene *sc);
char	**tab_parcing(char *line, char **tab, t_scene *sc);
void	ft_filestruct(t_scene *sc, char *line);
void	switch_maps(char ***tab, int i, char *line, t_scene *sc);
void	final_set_map(int line, int *map_line, t_scene *sc);
void	get_dir(t_player *pl, char c);
void	init_parcing(t_scene *sc);
int		is_player(char c);
int		check_inputs(t_scene sc);
/*
** ==================  ERROR  ===================
*/
void	free_win(t_scene *sc);
int		check_output(char *cub, char *extension);
void	quit_parc(char *str);
void	quit_parc_after_sc(char *str, t_scene *sc, char *line);
void	error_map(char **w_map, int map_line, int max_map);
void	pre_check(char *line);
void	quit_prog(t_scene *sc, char *str);
void	free_path(t_scene *sc);
void	free_tab(char ***tab, t_scene sc);
/*
** ==================  EXTRA    ==================
*/
void	print_minimap(t_scene *sc);
/*
** ================  RAYCASTING  =================
*/
void	loop_cub(t_win *win, t_int_tup r, t_scene *sc);
void	init_cub(t_scene *sc, t_win *win, t_int_tup r);
void	ft_put_pixel(char **ret_get_data_addr, int x, int y, t_scene sc);
void	ceil_and_floor(t_scene *sc, t_floor fl, t_ceil ce);
void	draw_sprite(t_scene *sc, float z_buf[sc->r.x], t_sprite_obj *obj);
void	sprite_distance(t_sprite **spr, int size, t_player pl);
void	scaling_sprite(t_sprite_obj *obj, t_txt txt);
void	save_bmp(t_scene *sc);
void	init_texture(t_scene *sc);
void	m_forward(t_scene *sc);
void	m_back(t_scene *sc);
void	m_right(t_scene *sc);
void	m_left(t_scene *sc);
void	m_rotation(t_scene *sc);
void	save_bmp(t_scene *sc);
void	init_texture(t_scene *sc);
int		quit_window(t_scene *sc);
int		ft_get_color(char *ret_get_data_addr, int start);
int		key_press(int keyhook, t_scene *sc);
int		key_release(int keyhook, t_scene *sc);
int		raycasting(t_scene *sc);
int		final_print(t_scene *sc);
#endif
