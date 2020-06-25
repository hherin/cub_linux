/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 20:31:39 by hherin            #+#    #+#             */
/*   Updated: 2020/04/08 13:51:21 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3.h"

static void	final_check(char *line, int boole)
{
	int		err_bool;

	err_bool = 1;
	if (*line == 'R' || *line == 'F' || *line == 'C' || *line == 'T')
	{
		err_bool = boole;
		if (!ft_isspace(*(line + 1)))
			err_bool = 0;
	}
	else if (*line == 'S')
	{
		err_bool = boole;
		line++;
		if (*line != 'O' && !ft_isspace(*line))
			err_bool = 0;
	}
	else if ((*line == 'N' && *(line + 1) == 'O') || (*line == 'W' && \
		*(line + 1) == 'E') || (*line == 'E' && *(line + 1) == 'A'))
		err_bool = boole;
	else if (ft_isdigit(*line))
		err_bool = 1;
	else
		err_bool = 0;
	if (!err_bool)
		quit_parc("configuration elements");
}

void		pre_check(char *line)
{
	if (ft_isspace(*line))
	{
		while (ft_isspace(*line))
			line++;
		final_check(line, 0);
	}
	if (!ft_isspace(*line))
		final_check(line, 1);
}
