/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 14:28:57 by heleneherin       #+#    #+#             */
/*   Updated: 2020/04/09 18:32:42 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3.h"

static void	free_tab(char ***tab, t_scene sc)
{
	int		i;

	i = -1;
	while (++i < sc.map_line)
		free((*tab)[i]);
	free(*tab);
}

void		free_win(t_scene *sc)
{
	if (sc->win.img_ptr)
		mlx_destroy_image(sc->win.mlx_ptr, sc->win.img_ptr);
	if (sc->b_sp.img_ptr)
		mlx_destroy_image(sc->win.mlx_ptr, sc->b_sp.img_ptr);
	if (sc->c_sp.img_ptr)
		mlx_destroy_image(sc->win.mlx_ptr, sc->c_sp.img_ptr);
	if (sc->win.win_ptr)
		mlx_destroy_window(sc->win.mlx_ptr, sc->win.win_ptr);
}

void		quit_prog(t_scene *sc, char *str)
{
	if (sc->w_map)
		free_tab(&sc->w_map, *sc);
	ft_printf("Error\n%s\n", str);
	free_win(sc);
	exit(EXIT_FAILURE);
}

void		quit_parc(char *str)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

int			quit_window(t_scene *sc)
{
	if (sc->w_map)
		free_tab(&sc->w_map, *sc);
	free_win(sc);
	exit(0);
	return (0);
}
