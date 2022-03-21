/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:06:56 by yobougre          #+#    #+#             */
/*   Updated: 2022/01/31 12:01:41 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	*ft_copy(char *output, char *buffer)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(buffer, '\n');
	while (tab[i])
	{
		if (ft_check_rr(tab, &i))
			output = ft_strjoin_pimp(output, RR);
		else if (ft_check_rrr(tab, &i))
			output = ft_strjoin_pimp(output, RRR);
		else
		{
			output = ft_strjoin_pimp(output, tab[i]);
			output = ft_strjoin_pimp(output, "\n");
		}
		++i;
	}
	return (ft_freetab(tab), output);
}

int	ft_tablen(char **buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
		++i;
	return (i);
}

static char	*ft_final_buffer(char *buffer)
{
	char	*output;

	output = ft_calloc(sizeof(char), ft_strlen(buffer) + 1);
	output = ft_copy(output, buffer);
	return (free(buffer), output);
}

void	ft_print_action(char *buffer)
{
	buffer = ft_final_buffer(buffer);
	write(1, buffer, ft_strlen(buffer));
	free(buffer);
}
