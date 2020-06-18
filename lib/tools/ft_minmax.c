/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherin <hherin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 12:05:05 by hherin            #+#    #+#             */
/*   Updated: 2020/02/06 14:23:43 by hherin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tools.h"

int		ft_min(int nb1, int nb2)
{
	if (nb1 > nb2)
		return (nb2);
	else
		return (nb1);
}

int		ft_max(int nb1, int nb2)
{
	if (nb1 > nb2)
		return (nb1);
	else
		return (nb2);
}
