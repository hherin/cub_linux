/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:58:50 by hherin            #+#    #+#             */
/*   Updated: 2020/04/09 17:25:36 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3.h"

static void	player_move(t_scene *sc)
{
	sc->pl.walk_spd = (sc->key.tab) ? 0.4 : 0.157;
	(sc->key.forw == 1) ? m_forward(sc) : 0;
	(sc->key.back == 1) ? m_back(sc) : 0;
	(sc->key.rot == 1) ? m_rotation(sc) : 0;
	(sc->key.right == 1) ? m_right(sc) : 0;
	(sc->key.left == 1) ? m_left(sc) : 0;
	sc->see = (sc->key.up == 1) ? 1 : 0;
}

static void	deal_key(int keyhook, t_key *key, int var, t_scene *sc)
{
	(keyhook == ESC_KEY) ? quit_window(sc) : 0;
	(keyhook == W_KEY) ? key->forw = var : 0;
	(keyhook == A_KEY) ? key->left = var : 0;
	(keyhook == S_KEY) ? key->back = var : 0;
	(keyhook == D_KEY) ? key->right = var : 0;
	(keyhook == UP_KEY) ? key->up = var : 0;
	(keyhook == DOWN_KEY) ? key->down = var : 0;
	(keyhook == F_KEY) ? key->sound = var : 0;
	(keyhook == TAB_KEY) ? key->tab = var : 0;
	(key->forw != 0 && key->forw != 1) ? key->forw = 0 : 0;
	(key->left != 0 && key->left != 1) ? key->left = 0 : 0;
	(key->back != 0 && key->back != 1) ? key->back = 0 : 0;
	(key->right != 0 && key->right != 1) ? key->right = 0 : 0;
	if (keyhook == RIGHT_KEY || keyhook == LEFT_KEY)
	{
		key->rot = var;
		key->rot_speed = (keyhook == RIGHT_KEY) ? 0.08 : -0.08;
	}
	(key->forw || key->left || key->right || key->back || \
		key->right || key->rot || key->up || key->down) ? \
			key->f_disp = 1 : 0;
	(key->sound) ? ft_printf("\a") : 0;
}

int			key_press(int keyhook, t_scene *sc)
{
	deal_key(keyhook, &sc->key, 1, sc);
	player_move(sc);
	return (1);
}

int			key_release(int keyhook, t_scene *sc)
{
	deal_key(keyhook, &sc->key, 0, sc);
	player_move(sc);
	return (1);
}
