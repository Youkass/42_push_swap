/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:54:42 by yobougre          #+#    #+#             */
/*   Updated: 2022/01/31 12:03:52 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	ft_strchr_pimp(char *s, char c)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strdup_pimp(char *s)
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
		if (output[i - 1] == '\n')
			break ;
	}
	output[i] = 0;
	return (output);
}
