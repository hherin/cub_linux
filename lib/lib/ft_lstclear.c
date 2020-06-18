/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherin <hherin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:57:30 by hherin            #+#    #+#             */
/*   Updated: 2019/11/15 14:51:10 by hherin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *tmp;

	if (*lst == NULL)
		return ;
	while (*lst)
	{
		tmp = *lst;
		(*del)((*lst)->content);
		*lst = (*lst)->next;
		free(tmp);
		tmp = NULL;
	}
}
