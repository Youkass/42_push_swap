/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 12:50:59 by yobougre          #+#    #+#             */
/*   Updated: 2022/01/31 12:00:23 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_lst(t_node **begin)
{
	ft_lstclear(begin);
	free(begin);
}

static int	ft_split_size(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		++i;
	return (i);
}

int	ft_fill_stack(t_node **begin, char **av, int size)
{
	t_node	*tmp;
	int		i;

	i = 1;
	(*begin) = ft_lstnew(ft_atol(av[i]));
	++i;
	tmp = (*begin);
	while (i < size)
	{
		tmp->next = ft_lstnew(ft_atol(av[i]));
		if (!tmp->next)
			return (ft_free_lst(begin), 0);
		tmp = tmp->next;
		++i;
	}
	return (1);
}

int	ft_fill_stack_2(t_node **begin, char **av)
{	
	t_node	*tmp;
	int		i;

	i = 0;
	if (!(*begin))
	{
		(*begin) = ft_lstnew(ft_atol(av[i]));
		++i;
	}
	tmp = (*begin);
	while (i < ft_split_size(av))
	{
		tmp->next = ft_lstnew(ft_atol(av[i]));
		if (!tmp->next)
			return (ft_free_lst(begin), 0);
		tmp = tmp->next;
		++i;
	}
	return (1);
}

int	ft_give_index(t_node **begin)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = (*begin);
	if (!(*begin))
		return (0);
	while (tmp->next != NULL && tmp != NULL)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
	tmp->index = i;
	return (i + 1);
}
