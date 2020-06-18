/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherin <hherin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:40:25 by hherin            #+#    #+#             */
/*   Updated: 2019/11/15 14:51:27 by hherin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *element;

	if (!(element = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	element->content = (void*)content;
	element->next = NULL;
	return (element);
}
