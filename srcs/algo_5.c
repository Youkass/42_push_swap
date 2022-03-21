/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:20:21 by yobougre          #+#    #+#             */
/*   Updated: 2022/01/31 11:56:47 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_find_cheap_value(t_node **stack)
{
	t_node	*tmp;

	tmp = (*stack);
	while (tmp->index != ft_find_cheap(stack))
		tmp = tmp->next;
	return (tmp->value);
}

static int	ft_cheapest_senpai(t_node **stack)
{
	t_node	*tmp;

	tmp = (*stack);
	while (tmp->index != ft_find_cheap(stack))
		tmp = tmp->next;
	return (tmp->senpai);
}

static int	ft_index_senpai(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	tmp = (*stack_a);
	while (tmp->value != ft_cheapest_senpai(stack_b))
		tmp = tmp->next;
	return (tmp->index);
}

static void	ft_move_a(t_node **stack_a, t_node **stack_b, char **buffer)
{
	int	size_a;

	size_a = ft_give_index(stack_a);
	if (ft_index_senpai(stack_a, stack_b) > size_a / 2)
		ft_rev_rotate_a(stack_a, buffer);
	else if (ft_index_senpai(stack_a, stack_b) <= size_a / 2)
		ft_rotate_a(stack_a, buffer);
}

void	ft_move_cheap(t_node **stack_a, t_node **stack_b, char **buffer)
{
	int	cheap_value;
	int	senpai;
	int	index_cheap;

	cheap_value = ft_find_cheap_value(stack_b);
	senpai = ft_cheapest_senpai(stack_b);
	index_cheap = ft_find_cheap(stack_b);
	while ((*stack_b)->value != cheap_value || (*stack_a)->value != senpai)
	{	
		if ((*stack_b)->value != cheap_value)
		{
			if (index_cheap > ft_give_index(stack_b) / 2)
				ft_rev_rotate_b(stack_b, buffer);
			else if (index_cheap <= ft_give_index(stack_b) / 2)
				ft_rotate_b(stack_b, buffer);
		}
		if ((*stack_a)->value != senpai)
			ft_move_a(stack_a, stack_b, buffer);
		if ((*stack_b)->value == cheap_value && (*stack_a)->value == senpai)
			break ;
	}
	ft_push_a(stack_a, stack_b, buffer);
}
