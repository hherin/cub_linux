/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:32:57 by hherin            #+#    #+#             */
/*   Updated: 2020/04/10 10:26:52 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_tuple
{
	float			x;
	float			y;
}					t_float_tup;

typedef	struct		s_int_tup
{
	int				x;
	int				y;
}					t_int_tup;

typedef struct		s_color
{
	int				red;
	int				gr;
	int				bl;
}					t_color;

typedef struct		s_ray
{
	float			cam_x;
	t_float_tup		ori;
	t_float_tup		dir;
	t_float_tup		ddist;
	t_float_tup		dist;
	t_float_tup		step;
	int				hit;
	int				side;
	float			perp_wall;
	t_int_tup		map;
}					t_ray;
/*
**----------------------------STRUCTURES DE BASES-----------------------------
*/

/*
** RESOLUTION
*/
typedef struct		s_r
{
	int				x;
	int				y;
}					t_r;

/*
** TEXTURES
*/
typedef struct		s_txt
{
	char			*path;
	void			*img_ptr;
	char			*addr_ar;
	int				bit_pixel;
	int				size_line;
	int				endian;
	int				wid;
	int				hei;
}					t_txt;

/*
** DISPLAY POINTERS
*/
typedef struct		s_win
{
	int				boole_quit;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*addr_ar;
	int				bit_pixel;
	int				size_line;
	int				endian;
	int				wid;
	int				hei;
}					t_win;

/*
** WALLS
*/
typedef struct		s_wall
{
	t_txt			txt;
	char			textnum;
	float			wall_x;
	t_int_tup		text;
	int				posx_txt;
	float			step;
}					t_wall;

/*
** KEY EVENT
*/
typedef struct		s_key
{
	int				forw;
	int				back;
	int				left;
	int				right;
	int				rot;
	float			rot_speed;
	int				up;
	int				down;
	int				f_disp;
	int				sound;
	int				tab;
}					t_key;

/*
** PLAYER/RAY INFO
*/
typedef struct		s_player
{
	int				d_mi;
	t_float_tup		pos;
	t_float_tup		dir;
	t_float_tup		plane;
	float			walk_spd;
}					t_player;

/*
** SPRITE
*/
typedef struct		s_sprite
{
	t_int_tup		coord;
	float			dist;
	int				cpt;
	char			c;
}					t_sprite;

typedef struct		s_sprit_obj
{
	t_sprite		*s;
	int				nb_sp;
	t_float_tup		sprt;
	t_float_tup		transfo;
	int				sprite_screen_x;
	int				sprite_height;
	int				sprite_wid;
	int				invdet;
	int				d;
	int				move_sc;
	float			vmove;
	int				div;
	t_int_tup		start;
	t_int_tup		end;
	t_int_tup		tex;
	t_txt			*txt;
}					t_sprite_obj;
/*
** CEILING AND FLOOR
*/
typedef struct		s_floor
{
	int				clr;
	t_float_tup		raydir_0;
	t_float_tup		raydir_1;
	t_int_tup		cell;
	t_int_tup		t;
	float			p;
	float			row_dist;
	t_float_tup		step;
	t_float_tup		floor;
	t_txt			txt;
}					t_floor;

typedef struct		s_ceil
{
	int				clr;
	t_int_tup		t;
	t_txt			txt;
}					t_ceil;
/*
** RESUME SCENE
*/
typedef struct		s_scene
{
	t_int_tup		r;
	t_int_tup		pxl;
	t_int_tup		pl_sq;
	int				see;
	int				life;
	float			d;
	int				color;
	t_ceil			ceil;
	t_floor			floor;
	t_key			key;
	int				map_line;
	t_sprite_obj	s_obj;
	t_txt			b_sp;
	t_txt			c_sp;
	int				nb_sprite;
	char			**w_map;
	t_player		pl;
	t_ray			ray;
	t_win			win;
	t_wall			*wall;
	t_wall			wall_e;
	t_wall			wall_n;
	t_wall			wall_s;
	t_wall			wall_w;
}					t_scene;

typedef struct		s_mini
{
	t_int_tup		cur;
	t_int_tup		max;
	t_int_tup		fl;
}					t_mini;
#endif
