/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:33:44 by hherin            #+#    #+#             */
/*   Updated: 2020/07/13 11:29:36 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3.h"

int	check_jclosed_map(int i, int j, char ***m)
{
	while (j < (int)ft_strlen((*m)[i]) && (*m)[i][j] != '1')
	{
		(j > 0 && (*m)[i][j - 1] == '.') ? quit_parc("map not closed") : 0;
		((*m)[i - 1][j] == '.' || (*m)[i + 1][j] == '.') ? \
			quit_parc("map not closed") : 0;
		((*m)[i][j] == '0') ? (*m)[i][j] = 'x' : 0;
		((*m)[i][j] == '.') ? quit_parc("map not closed") : 0;
		j++;
	}
	return (1);
}

int	check_iclosed_map(int i, int j, char ***m, int map_l)
{
	while (i < map_l + 3 && (*m)[i][j] != '1')
	{
		((*m)[i][j] == '.') ? quit_parc("map not closed") : 0;
		((*m)[i][j - 1] == '.' || (*m)[i][j + 1] == '.') ? \
			quit_parc("map not closed") : 0;
		(i > 0 && (*m)[i - 1][j] == '.') ? quit_parc("map not closed") : 0;
		((*m)[i][j] == '0') ? (*m)[i][j] = 'x' : 0;
		i++;
	}
	return (1);
}
