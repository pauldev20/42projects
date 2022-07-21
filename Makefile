# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 12:57:13 by pgeeser           #+#    #+#              #
#    Updated: 2022/07/21 17:34:42 by pgeeser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Werror -Wextra


SRC = fractol.c arguments.c fractals.c mlx_helpers.c hooks.c display.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C minilibx
	make -C libft
	make bonus -C ft_printf
	mv minilibx/libmlx.a .
	mv libft/libft.a .
	mv ft_printf/libftprintf.a .
	gcc -Wall -g -Werror -Wextra -c $(SRC)
	$(CC) $(CFLAGS) -L. -lmlx -lft -lftprintf -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

fclean:
	rm -rf $(NAME)
	rm -rf $(OBJ)
	rm -rf libmlx.a
	rm -rf libft.a
	rm -rf libftprintf.a


.PHONY: all
