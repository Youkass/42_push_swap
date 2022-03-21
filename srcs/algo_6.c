/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:13:35 by yobougre          #+#    #+#             */
/*   Updated: 2022/01/31 15:41:24 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort3(t_node **stack, char **buf)
{
	if (ft_issort(stack))
		return ;
	if (ft_index_small(stack) == 2)
	{
		if (((*stack)->value > (*stack)->next->value))
			ft_swap_a(stack, buf);
		ft_rev_rotate_a(stack, buf);
	}
	else if (ft_index_small(stack) == 0)
	{
		ft_swap_a(stack, buf);
		ft_rotate_a(stack, buf);
	}
	else if (ft_index_small(stack) == 1)
	{
		if ((*stack)->value > (*stack)->next->next->value)
			ft_rotate_a(stack, buf);
		else
			ft_swap_a(stack, buf);
	}
}

void	ft_freetab(char **tab)
{
	int	i;

	i = ft_tablen(tab);
	while (i)
	{
		free(tab[i]);
		--i;
	}
	free(tab[i]);
	free(tab);
}

int	ft_issort(t_node **stack)
{
	t_node	*tmp_1;
	t_node	*tmp_2;

	tmp_1 = (*stack);
	while (tmp_1 != NULL)
	{
		tmp_2 = tmp_1->next;
		while (tmp_2 != NULL)
		{
			if (tmp_1->value > tmp_2->value)
				return (0);
			tmp_2 = tmp_2->next;
		}
		tmp_1 = tmp_1->next;
	}
	return (1);
}

void	ft_exit(t_node **stack)
{
	ft_lstclear(stack);
	free((*stack));
}

void	ft_sort_small(t_node **stack_a, t_node **stack_b, char **buf)
{
	if (ft_give_index(stack_a) == 3)
		ft_sort3(stack_a, buf);
	else if (ft_give_index(stack_a) == 4)
		ft_sort4(stack_a, stack_b, buf);
	else if (ft_give_index(stack_a) == 5)
		ft_sort5(stack_a, stack_b, buf);
	ft_exit(stack_a);
	ft_print_action(*buf);
}
