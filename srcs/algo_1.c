/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:51:42 by yobougre          #+#    #+#             */
/*   Updated: 2022/01/31 11:50:10 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_dist(int size, int index)
{
	int	distance;

	distance = 1;
	if (size % 2 == 0)
	{
		if (index > size / 2)
			distance = size - index + 1;
		else
			distance = index + 1;
	}
	else
	{
		if (index > size / 2)
			distance = size - index + 1;
		else if (index == size / 2)
			distance = size - index;
		else
			distance = index + 1;
	}
	return (distance);
}

int	ft_still_in(t_node **stack, int median)
{
	t_node	*tmp;

	tmp = (*stack);
	while (tmp != NULL)
	{
		if (tmp->value < median)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_find_cost(int index_a, int index_b, int sz_a, int sz_b)
{
	int	cost;

	if (ft_same_down(index_a, index_b, sz_a, sz_b))
	{
		if (ft_dist(sz_a, index_a) > ft_dist(sz_b, index_b))
			cost = ft_dist(sz_a, index_a);
		else
			cost = ft_dist(sz_b, index_b);
	}
	else
		cost = ft_dist(sz_a, index_a) + ft_dist(sz_b, index_b) - 1;
	return (cost);
}

int	ft_find_cheap(t_node **stack)
{
	t_node	*tmp;
	int		i;
	int		index;

	index = (*stack)->index;
	i = (*stack)->cost;
	tmp = (*stack);
	while (tmp != NULL)
	{
		if (tmp->cost < i)
		{
			index = tmp->index;
			i = tmp->cost;
		}
		tmp = tmp->next;
	}
	return (index);
}
