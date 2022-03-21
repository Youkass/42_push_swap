/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:53:43 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/03 17:35:21 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_fill_tab(char **tab, long *ret, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < size)
	{
		ret[i] = ft_atol(tab[j]);
		++i;
		++j;
	}
}

int	ft_arg_len(char *arg)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	if (*arg == '0' && ft_strlen(arg) == 1)
		return (1);
	while (ft_space(arg[i]))
		++i;
	if (arg[i] == '-' || arg[i] == '+')
	{
		if (arg[i] == '-')
			++size;
		++i;
	}
	while (arg[i] == '0')
		++i;
	if (!arg[i])
		return (size + 1);
	while (ft_check(arg[i]))
	{
		++i;
		++size;
	}
	return (size);
}

int	ft_check_dbl(char **av, int size)
{
	int		i;
	int		j;
	long	*tab;

	tab = malloc(sizeof(long) * size - 1);
	if (!tab)
		return (0);
	ft_fill_tab(av, tab, size);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size - 1)
		{
			if (tab[i] == tab[j])
				return (free(tab), 0);
			++j;
		}
		++i;
	}
	return (free(tab), 1);
}

int	ft_mega_check_s(char **av, int ac)
{
	if (ft_check_args(av[1]) && ft_check_dbl(ft_split(av[1], ' '), ac))
		return (1);
	else
		return (0);
}

int	ft_mega_check_m(char **av, int ac)
{
	if (ft_check_mult_args(av, ac) && ft_check_dbl(av, ac))
		return (1);
	else
		return (0);
}
