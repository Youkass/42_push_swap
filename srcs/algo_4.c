/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:21:11 by yobougre          #+#    #+#             */
/*   Updated: 2022/01/31 11:56:35 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_highest(t_node **stack_a)
{
	t_node	*tmp;
	int		high;

	tmp = (*stack_a);
	high = tmp->value;
	while (tmp != NULL)
	{
		if (tmp->value > high)
			high = tmp->value;
		tmp = tmp->next;
	}
	return (high);
}

int	ft_index(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	int		right_value;

	right_value = ft_is_highest(stack_a);
	tmp = (*stack_a);
	while (tmp != NULL)
	{
		if (tmp->value < right_value && tmp->value > (*stack_b)->value)
			right_value = tmp->value;
		tmp = tmp->next;
	}
	return (right_value);
}

int	ft_right_index(t_node **stack_a, int value)
{
	t_node	*tmp;
	int		index;

	index = (*stack_a)->index;
	tmp = (*stack_a);
	while (tmp != NULL)
	{
		if (tmp->value == value)
			index = tmp->index;
		tmp = tmp->next;
	}
	return (index);
}

void	ft_assign_senpai(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	tmp = (*stack_b);
	while (tmp != NULL)
	{
		tmp->senpai = ft_index(stack_a, &tmp);
		tmp = tmp->next;
	}
}

void	ft_give_cost(t_node **stack_a, t_node **stack_b)
{
	t_node	*a;
	t_node	*b;
	int		sz_b;
	int		sz_a;

	sz_a = ft_give_index(stack_a);
	sz_b = ft_give_index(stack_b);
	ft_assign_senpai(stack_a, stack_b);
	b = (*stack_b);
	ft_give_index(&b);
	while (b != NULL)
	{
		a = (*stack_a);
		while (a != NULL)
		{
			if (a->value == b->senpai)
				b->cost = ft_find_cost(a->index, b->index, sz_a, sz_b);
			a = a->next;
		}
		b = b->next;
	}
}
