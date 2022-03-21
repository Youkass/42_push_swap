/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:59:09 by yobougre          #+#    #+#             */
/*   Updated: 2022/01/31 15:18:50 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_same_down(int index_a, int index_b, int size_a, int size_b)
{
	if (index_a > size_a / 2 && index_b > size_b / 2)
		return (1);
	else if (index_a <= size_a / 2 && index_b <= size_b / 2)
		return (1);
	else
		return (0);
}

int	ft_down_senpai(t_node **stack_a, t_node **stack_b)
{	
	int	size_b;
	int	size_a;

	size_a = ft_give_index(stack_a);
	size_b = ft_give_index(stack_b);
	if ((*stack_a)->index > size_a / 2 && (*stack_b)->index <= size_b / 2)
		return (1);
	else
		return (0);
}

int	ft_down_little(t_node **stack_a, t_node **stack_b)
{	
	int	size_b;
	int	size_a;

	size_a = ft_give_index(stack_a);
	size_b = ft_give_index(stack_b);
	if ((*stack_a)->index <= size_a / 2 && (*stack_b)->index > size_b / 2)
		return (1);
	else
		return (0);
}
