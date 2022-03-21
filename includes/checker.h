/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:10:27 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/03 17:35:21 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "push_swap.h"
# define OK "OK\n"
# define KO "KO\n"
# define BUFFER_SIZE 4

void	ft_print(char *s);
void	ft_exit_c(t_node **stack, char *buf);
char	*ft_strdup_pimp(char *s);
int		ft_issort(t_node **stack);
void	ft_error(void);
int		ft_read_moves(t_node **stack_a, t_node **stack_b, char **buf);
int		ft_parser(char *send, t_node **stack_a, t_node **stack_b, char **buf);
int		ft_strchr_pimp(char *s, char c);
char	*get_next_line(int fd);
char	*ft_next_line(char *line);
#endif
