/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:37:51 by yuro4ka           #+#    #+#             */
/*   Updated: 2022/02/02 15:13:56 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	ft_comp(char *send, char *move)
{
	int	i;

	i = 0;
	if (!send)
		return (0);
	while ((send[i] && move[i]) && (send[i] == move[i]))
		++i;
	return (send[i] - move[i]);
}

static void	ft_dbl_rev_rot(t_node **stack_a, t_node **stack_b, char **buffer)
{
	ft_rev_rotate_a(stack_a, buffer);
	ft_rev_rotate_b(stack_b, buffer);
}

static void	ft_dbl_rot(t_node **stack_a, t_node **stack_b, char **buffer)
{
	ft_rotate_a(stack_a, buffer);
	ft_rotate_b(stack_b, buffer);
}

int	ft_parser(char *send, t_node **stack_a, t_node **stack_b, char **buf)
{
	if (ft_comp(send, RA) == 0)
		return (ft_rotate_a(stack_a, buf), 1);
	else if (ft_comp(send, RB) == 0)
		return (ft_rotate_b(stack_b, buf), 1);
	else if (ft_comp(send, RRA) == 0)
		return (ft_rev_rotate_a(stack_a, buf), 1);
	else if (ft_comp(send, RRB) == 0)
		return (ft_rev_rotate_b(stack_b, buf), 1);
	else if (ft_comp(send, RRR) == 0)
		return (ft_dbl_rev_rot(stack_a, stack_b, buf), 1);
	else if (ft_comp(send, RR) == 0)
		return (ft_dbl_rot(stack_a, stack_b, buf), 1);
	else if (ft_comp(send, SA) == 0)
		return (ft_swap_a(stack_a, buf), 1);
	else if (ft_comp(send, SB) == 0)
		return (ft_swap_b(stack_b, buf), 1);
	else if (ft_comp(send, PB) == 0)
		return (ft_push_b(stack_a, stack_b, buf), 1);
	else if (ft_comp(send, PA) == 0)
		return (ft_push_a(stack_a, stack_b, buf), 1);
	else if (ft_comp(send, SS) == 0)
		return (ft_double_swap(stack_a, stack_b, buf), 1);
	else
		return (-1);
}

int	ft_read_moves(t_node **stack_a, t_node **stack_b, char **buf)
{
	char	*send;
	int		i;

	i = 1;
	while (i)
	{
		send = get_next_line(0);
		if (!send)
			i = 0;
		else if (ft_parser(send, stack_a, stack_b, buf) == -1)
			return (free(send), ft_error(), 0);
		free(send);
	}
	if (ft_issort(stack_a) && ft_give_index(stack_b) < 1)
		return (ft_print(OK), 1);
	else
		return (ft_print(KO), 0);
}
