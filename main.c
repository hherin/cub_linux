/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherin <hherin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:07:44 by hherin            #+#    #+#             */
/*   Updated: 2020/06/10 14:44:42 by hherin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3.h"

static t_key	init_key(int bole)
{
	t_key		key;

	key.forw = 0;
	key.back = 0;
	key.left = 0;
	key.right = 0;
	key.rot = 0;
	key.rot_speed = 0;
	key.up = 0;
	key.down = 0;
	key.sound = 0;
	key.tab = 0;
	key.f_disp = bole;
	return (key);
}

int				main(int ac, char **av)
{
	t_scene		sc;

	if (ac < 2 || ac > 3)
		quit_parc("No file or too many files");
	sc = rc_parcing(av[1]);
	sc.key = init_key(1);
	init_cub(&sc, &sc.win, sc.r);
	if (ac == 3)
	{
		if (!ft_strncmp(av[2], "--save", 10))
			save_bmp(&sc);
		else
			quit_prog(&sc, "Wrong 2nd argument");
	}
	loop_cub(&sc.win, sc.r, &sc);
	mlx_loop(sc.win.mlx_ptr);
	return (1);
}