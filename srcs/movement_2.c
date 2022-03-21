/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 05:43:02 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/02 17:08:17 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap_a(t_node **stack, char **buffer)
{
	int	tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = (*stack)->next->value;
	(*stack)->next->value = (*stack)->value;
	(*stack)->value = tmp;
	(*buffer) = ft_strjoin_pimp((*buffer), "sa\n");
}

void	ft_swap_b(t_node **stack, char **buffer)
{
	int	tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = (*stack)->next->value;
	(*stack)->next->value = (*stack)->value;
	(*stack)->value = tmp;
	(*buffer) = ft_strjoin_pimp((*buffer), "sb\n");
}

void	ft_rotate_a(t_node **stack, char **buffer)
{
	t_node	*tmp;
	t_node	*iter;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	iter = (*stack);
	while (iter->next != NULL)
		iter = iter->next;
	iter->next = tmp;
	tmp->next = NULL;
	ft_give_index(stack);
	(*buffer) = ft_strjoin_pimp((*buffer), "ra\n");
}

void	ft_rev_rotate_a(t_node **stack, char **buffer)
{
	t_node	*tmp;
	t_node	*iter;

	if (!(*stack) || !(*stack)->next)
		return ;
	iter = (*stack);
	while (iter->next->next != NULL)
		iter = iter->next;
	tmp = iter->next;
	iter->next = NULL;
	tmp->next = (*stack);
	(*stack) = tmp;
	ft_give_index(stack);
	(*buffer) = ft_strjoin_pimp((*buffer), "rra\n");
}

void	ft_double_swap(t_node **stack_a, t_node **stack_b, char **buffer)
{
	int	tmp;

	if (!(*stack_a) || !(*stack_b) || !(*stack_a)->next || !(*stack_b)->next)
		return ;
	tmp = (*stack_a)->next->value;
	(*stack_a)->next->value = (*stack_a)->value;
	(*stack_a)->value = tmp;
	tmp = (*stack_b)->next->value;
	(*stack_b)->next->value = (*stack_b)->value;
	(*stack_b)->value = tmp;
	(*buffer) = ft_strjoin_pimp((*buffer), "ss\n");
}
