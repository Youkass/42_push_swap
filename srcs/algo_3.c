/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:40:21 by yobougre          #+#    #+#             */
/*   Updated: 2022/01/31 14:37:51 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_invert(t_node **stack)
{
	if ((*stack) && (*stack)->next)
	{
		if ((*stack)->value < (*stack)->next->value)
			return (1);
		else
			return (0);
	}
	else
		return (-1);
}

int	ft_is_smallest(t_node **stack)
{
	t_node	*tmp;
	int		small;

	tmp = (*stack);
	small = tmp->value;
	while (tmp != NULL)
	{
		if (small > tmp->value)
			small = tmp->value;
		tmp = tmp->next;
	}
	return (small);
}

int	ft_index_small(t_node **stack)
{
	t_node	*tmp;

	tmp = (*stack);
	while (ft_is_smallest(stack) != tmp->value)
		tmp = tmp->next;
	return (tmp->index);
}

void	ft_global_phase_1(t_node **stack_a, t_node **stack_b, char **buffer)
{
	while (ft_give_index(stack_a) > 2)
		ft_phase_1(stack_a, stack_b, buffer);
	if (ft_invert(stack_a) == 0 && ft_invert(stack_b) == 1)
		ft_double_swap(stack_a, stack_b, buffer);
	else if (ft_invert(stack_a) == 0)
		ft_swap_a(stack_a, buffer);
	else if (ft_invert(stack_b) == 1)
		ft_swap_b(stack_b, buffer);
	while (ft_give_index(stack_b))
	{
		ft_give_cost(stack_a, stack_b);
		ft_move_cheap(stack_a, stack_b, buffer);
	}
	if (ft_index_small(stack_a) > ft_give_index(stack_a) / 2)
	{
		while ((*stack_a)->value != ft_is_smallest(stack_a))
			ft_rev_rotate_a(stack_a, buffer);
	}
	else if (ft_index_small(stack_a) <= ft_give_index(stack_a) / 2)
	{
		while ((*stack_a)->value != ft_is_smallest(stack_a))
			ft_rotate_a(stack_a, buffer);
	}
}
