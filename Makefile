# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 12:57:13 by pgeeser           #+#    #+#              #
#    Updated: 2022/07/29 15:06:25 by pgeeser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Werror -Wextra


SRCS = src/fractol.c src/arguments.c src/fractals.c src/mlx_helpers.c src/hooks.c src/display.c src/complex.c src/helpers.c
SRCS_BONUS = src_bonus/fractol_bonus.c src_bonus/arguments_bonus.c src_bonus/fractals_bonus.c src_bonus/mlx_helpers_bonus.c src_bonus/hooks_bonus.c src_bonus/display_bonus.c src_bonus/helpers_bonus.c src_bonus/complex_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

$(NAME): $(OBJS)
	make -C minilibx
	make bonus -C libft
	make bonus -C ft_printf
	mv minilibx/libmlx.a .
	mv libft/libft.a .
	mv ft_printf/libftprintf.a .
	$(CC) $(CFLAGS) -lm -L. -lmlx -lft -lftprintf -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

all: $(NAME)

bonus: $(OBJS_BONUS)
	make -C minilibx
	make bonus -C libft
	make bonus -C ft_printf
	mv minilibx/libmlx.a .
	mv libft/libft.a .
	mv ft_printf/libftprintf.a .
	$(CC) $(CFLAGS) -lm -L. -lmlx -lft -lftprintf -framework OpenGL -framework AppKit $(OBJS_BONUS) -o $(NAME)


clean:
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)
	make clean -C minilibx
	make clean -C libft
	make clean -C ft_printf

fclean: clean
	rm -rf $(NAME)
	rm -rf libmlx.a
	rm -rf libft.a
	rm -rf libftprintf.a
	make fclean -C libft
	make fclean -C ft_printf

re: fclean all

norm:
	norminette $(SRCS) $(SRCS_BONUS)

.PHONY: all clean fclean re norm
