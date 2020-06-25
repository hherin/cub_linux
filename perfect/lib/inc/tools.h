/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherin <hherin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:26:04 by hherin            #+#    #+#             */
/*   Updated: 2020/02/06 14:23:06 by hherin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

char	*ft_unitoa_base(unsigned int n, char *base);
char	*ft_itoahexa(long n);
char	*ft_memaset(char *tmp, size_t size);
char	*ft_finalcopy(char *tmp, char *s, size_t start, size_t zero);
int		ft_abso(int nb);
int		ft_min(int nb1, int nb2);
int		ft_max(int nb1, int nb2);
int		ft_istype(char c);
#endif
