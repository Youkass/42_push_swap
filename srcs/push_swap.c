/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 09:44:15 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/02 13:39:33 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_error(void)
{
	write(1, ERR, ft_strlen(ERR));
}

int	main(int ac, char **av)
{
	t_node		*stack_a;
	t_node		*stack_b;
	char		*buffer;

	if (ac < 2)
		return (0);
	else if (ac == 2 && ft_mega_check_m(av, ac))
		return (0);
	else if (ac > 2 && ft_mega_check_m(av, ac))
	{
		buffer = NULL;
		stack_b = NULL;
		ft_fill_stack(&stack_a, av, ac);
		if (ft_issort(&stack_a))
			return (ft_exit(&stack_a), 0);
		if (ac >= 4 && ac <= 6)
			return (ft_sort_small(&stack_a, &stack_b, &buffer), 0);
		ft_global_phase_1(&stack_a, &stack_b, &buffer);
		ft_print_action(buffer);
		ft_exit(&stack_a);
	}
	else
		ft_error();
}
