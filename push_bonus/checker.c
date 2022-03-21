/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:12:04 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/03 12:08:31 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_error(void)
{
	write(1, ERR, ft_strlen(ERR));
}

void	ft_exit_c(t_node **stack, char *buf)
{
	ft_lstclear(stack);
	free((*stack));
	free(buf);
}

int	main(int ac, char **av)
{
	t_node		*stack_a;
	t_node		*stack_b;
	char		*buffer;

	buffer = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2 && ft_mega_check_m(av, ac))
		ft_exit_c(&stack_a, buffer);
	else if (ac >= 2 && ft_mega_check_m(av, ac))
	{
		ft_fill_stack(&stack_a, av, ac);
		ft_read_moves(&stack_a, &stack_b, &buffer);
		ft_exit_c(&stack_a, buffer);
		if (stack_b)
			ft_exit_c(&stack_b, NULL);
	}
	else
		ft_error();
}
