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
#include <stdio.h>
void	quit_prog(t_scene *sc, char *str)
{
	if (sc->w_map)
		free_tab(&sc->w_map, *sc);
	ft_printf("Error\n%s\n", str);
	printf("1\n");
	free_win(sc);
	printf("2\n");
	free_path(sc);
	printf("3\n");
	exit(EXIT_FAILURE);
}

void	quit_parc(char *str)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

int		quit_window(t_scene *sc)
{
	if (sc->w_map)
		free_tab(&sc->w_map, *sc);
	free_win(sc);
	exit(0);
	return (0);
}

void	quit_parc_after_sc(char *str, t_scene *sc, char *line)
{
	free_path(sc);
	free(line);
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}
