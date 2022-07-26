# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 12:57:13 by pgeeser           #+#    #+#              #
#    Updated: 2022/07/26 14:32:01 by pgeeser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Werror -Wextra


SRCS = fractol.c arguments.c fractals.c mlx_helpers.c hooks.c display.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make -C minilibx
	make bonus -C libft
	make bonus -C ft_printf
	mv minilibx/libmlx.a .
	mv libft/libft.a .
	mv ft_printf/libftprintf.a .
	$(CC) $(CFLAGS) -L. -lmlx -lft -lftprintf -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf libmlx.a
	rm -rf libft.a
	rm -rf libftprintf.a

re: fclean all

.PHONY: all clean fclean re
