/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:36:29 by hherin            #+#    #+#             */
/*   Updated: 2020/04/09 18:35:23 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	nb;
	int		signe;

	nb = 0;
	signe = 1;
	while ((*str < 14 && *str >= 9) || *str == 32)
		str++;
	signe = (*str == '-') ? -1 : 1;
	str = (*str == '-' || *str == '+') ? str + 1 : str;
	while (ft_isdigit(*str))
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (nb * signe);
}

int		ft_atoi_trim(char **str)
{
	long	nb;
	int		signe;

	nb = 0;
	signe = 1;
	while ((**str < 14 && **str >= 9) || **str == 32)
		(*str)++;
	signe = (**str == '-') ? -1 : 1;
	*str = (**str == '-' || **str == '+') ? *str + 1 : *str;
	while (ft_isdigit(**str))
	{
		nb = nb * 10 + **str - '0';
		(*str)++;
	}
	return (nb * signe);
}
