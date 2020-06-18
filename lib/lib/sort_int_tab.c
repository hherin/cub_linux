/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:42:13 by hherin            #+#    #+#             */
/*   Updated: 2020/04/09 18:39:01 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *tab, int *tab1)
{
	int tmp;

	tmp = *tab;
	*tab = *tab1;
	*tab1 = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j++;
			i++;
		}
		size--;
		i = 0;
	}
}

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int tmp;

	i = 0;
	tmp = 0;
	size--;
	while (i < size)
	{
		tmp = tab[size];
		tab[size] = tab[i];
		tab[i] = tmp;
		i++;
		size--;
	}
}
