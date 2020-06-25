/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherin <hherin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:40:01 by hherin            #+#    #+#             */
/*   Updated: 2019/11/15 14:51:02 by hherin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *last;

	last = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		last = *alst;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}
