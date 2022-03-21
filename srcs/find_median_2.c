/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:33:00 by yobougre          #+#    #+#             */
/*   Updated: 2022/01/31 11:58:13 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_fill_tab(int *tab, t_node **begin, int size)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = (*begin);
	while (i < size)
	{
		tab[i] = tmp->value;
		tmp = tmp->next;
		++i;
	}
}

int	*array_sort(int size, int *ret, int *is_sort)
{
	int	count;
	int	tmp;
	int	i;

	count = 0;
	while (count < size)
	{
		i = 0;
		while (i < (size - 1))
		{
			if (ret[i] > ret[i + 1])
			{
				*is_sort = 1;
				tmp = ret[i];
				ret[i] = ret[i + 1];
				ret[i + 1] = tmp;
			}
			i++;
		}
		count++;
	}
	return (ret);
}

int	ft_find_median(t_node **begin, int size)
{
	int		median;
	int		*ret;
	int		is_sort;

	ret = malloc(sizeof(int) * size);
	if (!ret)
		return (0);
	ft_fill_tab(ret, begin, size);
	ret = array_sort(size, ret, &is_sort);
	if (size % 2 == 0)
		median = ret[size / 2 - 1];
	else
		median = ret[size / 2];
	return (free(ret), median);
}

int	ft_is_sort(t_node **begin, int size, int *is_sort)
{
	int		median;
	int		*ret;

	ret = malloc(sizeof(int) * size);
	if (!ret)
		return (0);
	ft_fill_tab(ret, begin, size);
	ret = array_sort(size, ret, is_sort);
	if (size % 2 == 0)
		median = ret[size / 2 - 1];
	else
		median = ret[size / 2];
	return (free(ret), median);
}
