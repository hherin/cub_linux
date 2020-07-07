/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 13:44:17 by heleneherin       #+#    #+#             */
/*   Updated: 2020/04/09 18:33:00 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3.h"

static void	nb_sprite(t_scene sc, t_sprite_obj **obj, char **tab)
{
	int		j;
	int		i;

	j = -1;
	(*obj)->nb_sp = 0;
	while (++j < sc.map_line)
	{
		i = -1;
		while (++i < (int)ft_strlen(sc.w_map[j]))
		{
			if (tab[j][i] == '2' || tab[j][i] == '3')
				(*obj)->nb_sp++;
		}
	}
}

static void	is_sprite(t_sprite_obj *obj, char **tab, t_scene *sc)
{
	int		compt;
	int		j;
	int		i;

	nb_sprite(*sc, &obj, tab);
	if (!(obj->s = malloc(sizeof(t_sprite) * obj->nb_sp)))
		quit_parc("error malloc of sprites.");
	compt = 0;
	j = -1;
	while (++j < sc->map_line)
	{
		i = -1;
		while (++i < (int)ft_strlen(sc->w_map[j]))
		{
			if (tab[j][i] == '2' || tab[j][i] == '3')
			{
				(obj->s)[compt].coord.y = j;
				(obj->s)[compt].coord.x = i;
				(obj->s)[compt++].c = tab[j][i];
			}
		}
	}
}

void		final_set_map(int line, int *map_line, t_scene *sc)
{
	int		i;

	i = -1;
	*map_line = line;
	is_sprite(&sc->s_obj, sc->w_map, sc);
	error_map(sc->w_map, *map_line);
}
