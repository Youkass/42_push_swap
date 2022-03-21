/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:11:45 by yobougre          #+#    #+#             */
/*   Updated: 2022/01/31 11:59:19 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	*ft_strdup_pimp(char *s)
{
	char	*output;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	output = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!output)
		return (NULL);
	while (s[i])
	{
		output[i] = s[i];
		++i;
	}
	output[i] = 0;
	return (output);
}

char	*ft_strjoin_pimp(char *s1, char *s2)
{
	char	*output;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = ft_strdup_pimp("\0");
	if (!s2)
		return (NULL);
	output = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!output)
		return (free(s1), free(s2), NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		output[i] = s1[i];
		++i;
	}
	while (s2[j])
	{
		output[i + j] = s2[j];
		++j;
	}
	output[i + j] = 0;
	return (free(s1), output);
}

static int	ft_verif(char **buffer, char *action_1, char *action_2, int *index)
{
	int	i;
	int	j;

	j = *index;
	i = 0;
	while (action_1[i] != '\n')
	{
		if (action_1[i] != buffer[j][i])
			return (0);
		++i;
	}
	++j;
	i = 0;
	if (j == ft_tablen(buffer))
		return (0);
	while (action_2[i] != '\n')
	{
		if (action_2[i] != buffer[j][i])
			return (0);
		++i;
	}
	*index = j;
	return (1);
}

int	ft_check_rr(char **buffer, int *index)
{
	if (ft_verif(buffer, RA, RB, index))
		return (1);
	else if (ft_verif(buffer, RB, RA, index))
		return (1);
	else
		return (0);
}

int	ft_check_rrr(char **buffer, int *index)
{
	if (ft_verif(buffer, RRA, RRB, index))
		return (1);
	else if (ft_verif(buffer, RRB, RRA, index))
		return (1);
	else
		return (0);
}
