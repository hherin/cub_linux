/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherin <hherin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 11:23:18 by hherin            #+#    #+#             */
/*   Updated: 2019/12/30 12:29:27 by hherin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static t_print	ft_filetab(char c, t_fct funct)
{
	t_print		tab;

	tab.c = c;
	tab.function = funct;
	return (tab);
}

t_print			*ft_struct_printf(void)
{
	t_print		*dispatch;

	dispatch = (t_print*)malloc(sizeof(t_print) * NB_STRUCT);
	dispatch[0] = ft_filetab('d', &ft_type_d);
	dispatch[1] = ft_filetab('i', &ft_type_d);
	dispatch[2] = ft_filetab('s', &ft_type_s);
	dispatch[3] = ft_filetab('c', &ft_type_c);
	dispatch[4] = ft_filetab('x', &ft_type_x);
	dispatch[5] = ft_filetab('X', &ft_type_xmaj);
	dispatch[6] = ft_filetab('p', &ft_type_p);
	dispatch[7] = ft_filetab('u', &ft_type_u);
	dispatch[8] = ft_filetab('%', &ft_type_pourcent);
	return (dispatch);
}
