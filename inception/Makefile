# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 15:30:42 by pgeeser           #+#    #+#              #
#    Updated: 2023/05/10 14:24:35 by pgeeser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Create folders for volumes and start docker-compose
all:
	mkdir -p ~/data/wordpress;
	mkdir -p ~/data/mariadb;
	docker	compose -f ./srcs/docker-compose.yml up

# Stop docker-compose
down:
	docker compose -f ./srcs/docker-compose.yml down

# Stop docker-compose, delete all containers, images, volumes and networks and start docker-compose
re: fclean
	docker compose -f ./srcs/docker-compose.yml up --build

# Stop all containers, delete all containers, images, volumes and networks
clean: down
	docker container prune -f
	docker rmi $$(docker images -q) 2> /dev/null || true

# Stop all containers, delete all containers, images, volumes
fclean: clean
	docker compose -f ./srcs/docker-compose.yml down --volumes --rmi all
	sudo rm -rf ~/data

.PHONY: all down re clean fclean
