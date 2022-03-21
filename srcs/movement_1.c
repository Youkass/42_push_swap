/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:38:26 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/02 17:10:41 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_b(t_node **stack_a, t_node **stack_b, char **buffer)
{
	t_node	*tmp;

	if ((*stack_a))
	{
		tmp = (*stack_a);
		(*stack_a) = tmp->next;
		tmp->next = (*stack_b);
		(*stack_b) = tmp;
		ft_give_index(stack_a);
		ft_give_index(stack_b);
		(*buffer) = ft_strjoin_pimp((*buffer), "pb\n");
	}
}

void	ft_push_a(t_node **stack_a, t_node **stack_b, char **buffer)
{
	t_node	*tmp;

	if ((*stack_b))
	{
		tmp = (*stack_b);
		if (tmp->next)
			(*stack_b) = tmp->next;
		else
			(*stack_b) = NULL;
		tmp->next = (*stack_a);
		(*stack_a) = tmp;
		if ((*stack_a))
			ft_give_index(stack_a);
		if ((*stack_b))
			ft_give_index(stack_b);
		(*buffer) = ft_strjoin_pimp((*buffer), "pa\n");
	}
}

void	ft_rotate_b(t_node **stack, char **buffer)
{
	t_node	*tmp;
	t_node	*iter;

	if ((*stack) && (*stack)->next)
	{
		tmp = (*stack);
		(*stack) = (*stack)->next;
		iter = (*stack);
		while (iter->next != NULL)
			iter = iter->next;
		iter->next = tmp;
		tmp->next = NULL;
		ft_give_index(stack);
		(*buffer) = ft_strjoin_pimp((*buffer), "rb\n");
	}
}

void	ft_rev_rotate_b(t_node **stack, char **buffer)
{
	t_node	*tmp;
	t_node	*iter;

	if ((*stack) && (*stack)->next)
	{
		iter = (*stack);
		while (iter->next->next != NULL)
			iter = iter->next;
		tmp = iter->next;
		iter->next = NULL;
		tmp->next = (*stack);
		(*stack) = tmp;
		ft_give_index(stack);
		(*buffer) = ft_strjoin_pimp((*buffer), "rrb\n");
	}
}
