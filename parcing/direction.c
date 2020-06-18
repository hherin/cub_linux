/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 15:16:04 by heleneherin       #+#    #+#             */
/*   Updated: 2020/04/08 13:32:48 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3.h"

static void	ns_dir(t_player *pl, int signe)
{
	pl->d_mi = (signe < 0) ? N : S;
	pl->dir.x = 0;
	pl->dir.y = 1 * signe;
	pl->plane.x = 0.66 * signe;
	pl->plane.y = 0;
}

static void	we_dir(t_player *pl, int signe)
{
	pl->d_mi = (signe < 0) ? W : E;
	pl->dir.x = 1 * signe;
	pl->dir.y = 0;
	pl->plane.x = 0;
	pl->plane.y = -0.66 * signe;
}

void		get_dir(t_player *pl, char c)
{
	(c == 'N') ? ns_dir(pl, -1) : 0;
	(c == 'S') ? ns_dir(pl, 1) : 0;
	(c == 'E') ? we_dir(pl, 1) : 0;
	(c == 'W') ? we_dir(pl, -1) : 0;
}
