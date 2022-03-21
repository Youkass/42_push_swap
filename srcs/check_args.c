/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:27:14 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/21 15:15:50 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_check_num(long nb, int *size)
{
	if (nb < 0)
	{
		*size += 1;
		nb *= -1;
	}
	if (nb < 10 && nb >= 0)
		*size += 1;
	else
	{
		ft_check_num(nb / 10, size);
		ft_check_num(nb % 10, size);
	}
}

static void	ft_free_tab(char **tab, int i)
{
	while (i)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

static int	ft_check_ascii(char *arg)
{
	int	i;

	i = 0;
	if (ft_strlen(arg) == 1 && arg[i] == '-')
		return (0);
	if (!ft_strlen(arg))
			return (0);
	while (arg[i])
	{
		if (!(arg[i] >= '0' && arg[i] <= '9') && arg[i] != '-' && arg[i] != '+')
			return (0);
		++i;
	}
	return (1);
}

int	ft_check_mult_args(char **av, int ac)
{
	int	i;
	int	size;

	i = 1;
	while (i < ac)
	{
		size = 0;
		ft_check_num(ft_atol(av[i]), &size);
		if (!ft_check_ascii(av[i]))
			return (0);
		if (size != ft_arg_len(av[i]))
			return (0);
		if (ft_atol(av[i]) > INT_MA || ft_atol(av[i]) < INT_MI)
			return (0);
		++i;
	}
	return (1);
}

int	ft_check_args(char *av)
{
	char	**args_lst;
	int		i;
	int		size;

	args_lst = ft_split(av, ' ');
	if (!args_lst)
		return (0);
	i = 0;
	while (args_lst[i])
	{
		size = 0;
		ft_check_num(ft_atol(args_lst[i]), &size);
		if (size != ft_arg_len(args_lst[i]))
			return (0);
		if (ft_atol(args_lst[i]) > INT_MA || ft_atol(args_lst[i]) < INT_MI)
			return (0);
		i++;
	}
	return (ft_free_tab(args_lst, i), 1);
}
