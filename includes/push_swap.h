/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 21:36:49 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/02 13:23:30 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MI -2147483648
# define INT_MA 2147483647
# define ERR "Error\n"
# define RA "ra\n"
# define RB "rb\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"
# define RR "rr\n"
# define PA "pa\n"
# define PB "pb\n"
# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	struct s_node	*next;
	int				index;
	int				value;
	int				cost;
	int				senpai;
}	t_node;

int		ft_arg_len(char *arg);
int		ft_check(char c);
int		ft_space(char c);
void	ft_move_small(t_node **stack_a, t_node **stack_b, char **buf);
void	ft_sort_small(t_node **stack_a, t_node **stack_b, char **buf);
void	ft_sort4(t_node **stack_a, t_node **stack_b, char **buf);
void	ft_sort5(t_node **stack_a, t_node **stack_b, char **buf);
int		ft_index_small(t_node **stack);
int		ft_is_smallest(t_node **stack);
int		ft_issort(t_node **stack);
void	ft_exit(t_node **stack);
void	ft_sort3(t_node **stack, char **buf);
void	ft_freetab(char **tab);
int		ft_tablen(char **buffer);
void	ft_move_cheap(t_node **stack_a, t_node **stack_b, char **buffer);
int		ft_check_rrr(char **buffer, int *index);
int		ft_check_rr(char **buffer, int *index);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
int		ft_strlen(char *buffer);
void	ft_print_action(char *buffer);
char	*ft_strjoin_pimp(char *s1, char *s2);
void	ft_give_cost(t_node **stack_a, t_node **stack_b);
int		ft_find_cost(int index_a, int index_b, int sz_a, int sz_b);
int		ft_same_down(int index_a, int index_b, int size_a, int size_b);
int		ft_same_up(t_node **stack_a, t_node **stack_b);
int		ft_down_senpai(t_node **stack_a, t_node **stack_b);
int		ft_down_little(t_node **stack_a, t_node **stack_b);
int		ft_right_index(t_node **stack_a, int value);
int		ft_index(t_node **stack_a, t_node **stack_b);
int		ft_is_highest(t_node **stack_a);
int		ft_dist(int size, int index);
void	ft_global_phase_1(t_node **stack_a, t_node **stack_b, char **buffer);
void	ft_double_swap(t_node **stack_a, t_node **stack_b, char **buffer);
int		ft_still_in(t_node **stack, int median);
void	ft_phase_2(t_node **stack_a, t_node **stack_b, int median, char **buf);
void	ft_phase_1(t_node **stack_a, t_node **stack_b, char **buffer);
int		ft_is_sort(t_node **begin, int size, int *is_sort);
int		ft_find_cheap(t_node **stack);
int		*array_sort(int size, int *ret, int *is_sort);
void	ft_swap_a(t_node **stack, char **buffer);
void	ft_swap_b(t_node **stack, char **buffer);
void	ft_rev_rotate_b(t_node **stack, char **buffer);
void	ft_rotate_b(t_node **stack, char **buffer);
void	ft_rev_rotate_a(t_node **stack, char **buffer);
void	ft_rotate_a(t_node **stack, char **buffer);
void	ft_push_b(t_node **stack_a, t_node **stack_b, char **buffer);
void	ft_push_a(t_node **stack_a, t_node **stack_b, char **buffer);
int		ft_find_median(t_node **begin, int size);
int		ft_give_index(t_node **begin);
int		ft_mega_check_s(char **av, int ac);
int		ft_mega_check_m(char **av, int ac);
int		ft_check_dbl(char **av, int size);
int		ft_count(char const *str, char c);
int		ft_fill_stack_2(t_node **begin, char **av);
void	ft_free_lst(t_node **begin);
int		ft_check_mult_args(char **av, int ac);
void	ft_lstclear(t_node **lst);
void	ft_mult_args(char **av, int size);
int		ft_fill_stack(t_node **begin, char **av, int size);
void	ft_lstadd_back(t_node **alst, t_node *new);
void	ft_lstadd_front(t_node **alst, t_node *new);
t_node	*ft_lstnew(int value);
char	**ft_split(char const *s, char c);
long	ft_atol(const char *nbr);
int		ft_check_args(char *av);
#endif 
