# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 12:57:13 by pgeeser           #+#    #+#              #
#    Updated: 2022/05/13 13:29:21 by pgeeser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Werror -Wextra


SRC = fractol.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C minilibx
	mv minilibx/libmlx.a .
	gcc -Wall -g -Werror -Wextra -c $(SRC)
	$(CC) $(CFLAGS) -L. -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

.PHONY: all