# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 22:40:40 by pgeeser           #+#    #+#              #
#    Updated: 2022/08/09 23:49:57 by pgeeser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Werror -Wextra
CC = gcc

SRCS = src/stack/operations_both.c src/stack/operations.c src/stack/stack_helpers.c src/stack/stack.c src/pushswap.c src/stack/additional_stack_helpers.c src/stack/additional_stack_helpers_2.c src/stack/validate.c src/small_stack.c src/big_stack.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	$(MAKE) bonus -C ./ft_printf
	mv ./libft/libft.a .
	mv ./ft_printf/libftprintf.a .
	$(CC) $(CFLAGS) -L. -lft -lftprintf $(OBJS) -o $(NAME)
	
all: $(NAME)

debug:
	$(MAKE) CFLAGS='-g' re

clean:
	rm -rf $(OBJS) $(BONUS_OBJS)
	make clean -C ./libft
	make clean -C ./ft_printf

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft
	make fclean -C ./ft_printf
	rm -rf libft.a
	rm -rf libftprintf.a

re: fclean
	$(MAKE) all

norm:
	norminette $(SRCS) $(BONUS_SRCS) *.h
	make norm -C libft
	make norm -C ./ft_printf

.PHONY:	all bonus clean fclean re norm