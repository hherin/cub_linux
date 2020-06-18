/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 11:22:06 by heleneherin       #+#    #+#             */
/*   Updated: 2020/04/09 17:36:09 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3.h"

static void			print_bmp(int nb, int size, int fd)
{
	int				i;
	int				shift;

	i = 0;
	while (i < size)
	{
		shift = i * 8;
		ft_putchar_fd((nb & (0xff << shift)) >> (shift), fd);
		i++;
	}
}

static void			file_type_data(t_scene sc, int fd)
{
	unsigned int	size;

	size = 54 + sc.r.x * sc.win.bit_pixel * sc.r.y;
	print_bmp(66, 1, fd);
	print_bmp(77, 1, fd);
	print_bmp(size, 4, fd);
	print_bmp(0, 2, fd);
	print_bmp(0, 2, fd);
	print_bmp(54, 4, fd);
}

static void			image_data(t_scene sc, int fd)
{
	print_bmp(40, 4, fd);
	print_bmp(sc.r.x, 4, fd);
	print_bmp(sc.r.y, 4, fd);
	print_bmp(1, 2, fd);
	print_bmp(sc.win.bit_pixel, 2, fd);
	print_bmp(0, 4, fd);
	print_bmp(0, 4, fd);
	print_bmp(0, 4, fd);
	print_bmp(0, 4, fd);
	print_bmp(0, 4, fd);
	print_bmp(0, 4, fd);
}

static void			print_body(t_scene sc, int fd)
{
	int				x;
	int				y;

	y = sc.r.y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < sc.r.x)
		{
			print_bmp(((int*)sc.win.addr_ar)[y * sc.r.x + x], 4, fd);
			x++;
		}
		y--;
	}
}

void				save_bmp(t_scene *sc)
{
	int				fd;

	ceil_and_floor(sc, sc->floor, sc->ceil);
	raycasting(sc);
	print_minimap(sc);
	if ((fd = open("./image.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0666)) < 0)
		quit_prog(sc, "file to save not opened");
	file_type_data(*sc, fd);
	image_data(*sc, fd);
	print_body(*sc, fd);
	close(fd);
	exit(0);
}
