/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:44:09 by yobougre          #+#    #+#             */
/*   Updated: 2022/01/31 15:41:21 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_move_small(t_node **stack_a, t_node **stack_b, char **buf)
{
	if (ft_index_small(stack_a) > ft_give_index(stack_a) / 2)
	{
		while ((*stack_a)->value != ft_is_smallest(stack_a))
			ft_rev_rotate_a(stack_a, buf);
	}
	else if (ft_index_small(stack_a) <= ft_give_index(stack_a) / 2)
	{
		while ((*stack_a)->value != ft_is_smallest(stack_a))
			ft_rotate_a(stack_a, buf);
	}
	ft_push_b(stack_a, stack_b, buf);
}

void	ft_sort4(t_node **stack_a, t_node **stack_b, char **buf)
{
	ft_move_small(stack_a, stack_b, buf);
	ft_sort3(stack_a, buf);
	ft_push_a(stack_a, stack_b, buf);
}

void	ft_sort5(t_node **stack_a, t_node **stack_b, char **buf)
{
	ft_move_small(stack_a, stack_b, buf);
	ft_move_small(stack_a, stack_b, buf);
	ft_sort3(stack_a, buf);
	ft_push_a(stack_a, stack_b, buf);
	ft_push_a(stack_a, stack_b, buf);
}
