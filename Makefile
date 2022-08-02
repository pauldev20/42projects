# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 22:40:40 by pgeeser           #+#    #+#              #
#    Updated: 2022/08/02 22:44:25 by pgeeser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Werror -Wextra
CC = cc

SRCS = pushswap.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	$(MAKE) bonus -C ./ft_printf
	mv ./libft/libft.a .
	mv ./ft_printf/libftprintf.a .
	$(CC) $(CFLAGS) -L. -lft -lftprintf $(OBJS) -o $(NAME)
	
all: $(NAME)

clean:
	rm -rf $(OBJS) $(BONUS_OBJS)
	make clean -C ./libft
	make clean -C ./ft_printf

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft
	make fclean -C ./ft_printf

re: fclean
	$(MAKE) all

norm:
	norminette $(SRCS) $(BONUS_SRCS) *.h
	make norm -C libft
	make norm -C ./ft_printf

.PHONY:	all bonus clean fclean re norm