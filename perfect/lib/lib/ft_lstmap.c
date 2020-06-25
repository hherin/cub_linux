/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherin <hherin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:40:20 by hherin            #+#    #+#             */
/*   Updated: 2019/11/15 14:51:24 by hherin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list *temp;
	t_list *start;

	if (!lst || !*del)
		return (NULL);
	if (!(temp = ft_lstnew((*f)(lst->content))))
		return (NULL);
	start = temp;
	while (lst)
	{
		if (!(temp = ft_lstnew((*f)(lst->content))))
			ft_lstclear(&temp, del);
		lst = lst->next;
		ft_lstadd_back(&start, temp);
	}
	start = start->next;
	return (start);
}
