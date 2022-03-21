/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:45:26 by yobougre          #+#    #+#             */
/*   Updated: 2022/01/31 11:55:44 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_phase_1(t_node **stack_a, t_node **stack_b, char **buffer)
{
	int		size;
	int		median;

	size = ft_give_index(stack_a);
	median = ft_find_median(stack_a, size);
	ft_phase_2(stack_a, stack_b, median, buffer);
}

void	ft_phase_2(t_node **stack_a, t_node **stack_b, int median, char **buf)
{
	while (ft_still_in(stack_a, median))
	{
		if ((*stack_a)->value < median)
			ft_push_b(stack_a, stack_b, buf);
		else
			ft_rotate_a(stack_a, buf);
	}
}
