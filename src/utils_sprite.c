/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 09:35:00 by heleneherin       #+#    #+#             */
/*   Updated: 2020/04/10 10:36:51 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3.h"

void	scaling_sprite(t_sprite_obj *obj, t_txt txt)
{
	obj->div = 2;
	obj->vmove = (float)(txt.hei);
	obj->move_sc = (int)(obj->vmove / obj->transfo.y);
}

void	sprite_distance(t_sprite **spr, int size, t_player pl)
{
	int	i;

	i = 0;
	while (i < size)
	{
		(*spr)[i].dist = (pow(pl.pos.x - (*spr)[i].coord.x, 2) * \
			pow(pl.pos.y - (*spr)[i].coord.y, 2));
		i++;
	}
}
