# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yobougre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 17:53:40 by yobougre          #+#    #+#              #
#    Updated: 2022/03/21 15:40:08 by yuro4ka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=  srcs/algo_1.c\
	   srcs/algo_2.c\
	   srcs/algo_3.c\
	   srcs/algo_4.c\
	   srcs/algo_5.c\
	   srcs/check_args.c\
	   srcs/check_args_2.c\
	   srcs/find_median_2.c\
	   srcs/ft_atoi.c\
	   srcs/ft_lst.c\
	   srcs/ft_split.c\
	   srcs/movement_1.c\
	   srcs/movement_2.c\
	   srcs/parsing.c\
	   srcs/parsing_2.c\
	   srcs/push_swap.c\
	   srcs/direction.c\
	   srcs/ft_strjoin.c\
	   srcs/ft_print_action.c\
	   srcs/algo_6.c\
	   srcs/calloc.c

SRCS_BONUS= push_bonus/checker.c\
			push_bonus/utils_bonus.c\
			push_bonus/get_next_line.c\
			push_bonus/get_next_line_utils.c\
			srcs/direction.c\
			srcs/ft_strjoin.c\
			srcs/ft_print_action.c\
			srcs/calloc.c\
			srcs/algo_1.c\
			srcs/algo_2.c\
			srcs/algo_3.c\
			srcs/algo_4.c\
			srcs/algo_5.c\
			srcs/algo_6.c\
			srcs/check_args.c\
			srcs/check_args_2.c\
			srcs/find_median_2.c\
			srcs/ft_atoi.c\
			srcs/ft_lst.c\
			srcs/ft_split.c\
			srcs/movement_1.c\
			srcs/movement_2.c\
			srcs/parsing.c\
			srcs/parsing_2.c\
			push_bonus/utils_bonus_2.c 

INCL=	includes/checker.h\
		includes/push_swap.h

CC= gcc

CFLAGS= -Wall -Werror -Wextra

RM=	rm -f

NAME=	push_swap

BONUS_NAME=	checker

OBJ=	$(SRCS:.c=.o)

OBJ_BONUS=	$(SRCS_BONUS:.c=.o)

all:	$(NAME) 

bonus:  $(BONUS_NAME)

$(NAME):	$(OBJ) includes/push_swap.h 
			$(CC) $(CFLAGS) $(OBJ) $(INCL) -o $(NAME) 

$(BONUS_NAME):		$(OBJ_BONUS) $(INCL) 
					$(CC) $(CFLAGS) $(OBJ_BONUS) $(INCL) -o $(BONUS_NAME) 				
clean:	
		$(RM) $(OBJ) $(OBJ_BONUS)

fclean:	clean
		$(RM) $(NAME) $(BONUS_NAME) $(OBJ_BONUS)

re:	fclean all

.PHONY: clean fclean re bonus all

