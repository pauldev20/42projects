# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 11:32:54 by pgeeser           #+#    #+#              #
#    Updated: 2022/08/02 14:05:21 by pgeeser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CC = cc
CFLAGS = -Wall -Werror -Wextra

CLIENT_NAME = client
SERVER_NAME = server

SRC_CLIENT = src/client.c
SRC_SERVER = src/server.c
OBJS_CLIENT = $(SRC_CLIENT:.c=.o)
OBJS_SERVER = $(SRC_SERVER:.c=.o)

SRC_CLIENT_BONUS = src_bonus/client_bonus.c
SRC_SERVER_BONUS = src_bonus/server_bonus.c
OBJS_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)
OBJS_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)

$(NAME): $(OBJS_CLIENT) $(OBJS_SERVER)
	make bonus -C libft
	make bonus -C ft_printf
	mv libft/libft.a .
	mv ft_printf/libftprintf.a .
	$(CC) $(CFLAGS) -L. -lft -lftprintf $(OBJS_CLIENT) -o $(CLIENT_NAME)
	$(CC) $(CFLAGS) -L. -lft -lftprintf $(OBJS_SERVER) -o $(SERVER_NAME)

all: $(NAME)

bonus: $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)
	make bonus -C libft
	make bonus -C ft_printf
	mv libft/libft.a .
	mv ft_printf/libftprintf.a .
	$(CC) $(CFLAGS) -L. -lft -lftprintf $(OBJS_CLIENT_BONUS) -o $(CLIENT_NAME)
	$(CC) $(CFLAGS) -L. -lft -lftprintf $(OBJS_SERVER_BONUS) -o $(SERVER_NAME)

clean:
	rm -rf $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)
	make clean -C libft
	make clean -C ft_printf

fclean: clean
	rm -rf $(CLIENT_NAME) $(SERVER_NAME)
	rm -rf libft.a
	rm -rf libftprintf.a
	make fclean -C libft
	make fclean -C ft_printf

re: fclean all

norm:
	norminette $(SRC_CLIENT) $(SRC_SERVER) $(SRC_CLIENT_BONUS) $(SRC_SERVER_BONUS) src/*.h src_bonus/*.h
	make norm -C libft
	make norm -C ft_printf

.PHONY: all clean fclean re norm bonus