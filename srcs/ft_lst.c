/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:22:10 by yobougre          #+#    #+#             */
/*   Updated: 2022/01/31 11:58:42 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_lstnew(int value)
{
	t_node	*sortie;

	sortie = malloc(sizeof(t_node) * 1);
	if (!sortie)
		return (NULL);
	sortie->value = value;
	sortie->next = NULL;
	return (sortie);
}

void	ft_lstadd_back(t_node **alst, t_node *new)
{
	t_node	*tmp;

	tmp = *alst;
	if (!(*alst))
	{
		*alst = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}

void	ft_lstadd_front(t_node **alst, t_node *new)
{
	new->next = *alst;
	*alst = new;
}

void	ft_lstclear(t_node **lst)
{
	t_node	*tmp_00;
	t_node	*tmp_01;

	if (!lst)
		return ;
	tmp_00 = *lst;
	while (tmp_00)
	{
		tmp_01 = tmp_00->next;
		free(tmp_00);
		tmp_00 = tmp_01;
	}
	*lst = NULL;
}
