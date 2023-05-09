# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 15:30:42 by pgeeser           #+#    #+#              #
#    Updated: 2023/05/09 18:43:45 by pgeeser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Create folders for volumes and start docker-compose
all:
	@mkdir -p /home/pgeeser/data/wordpress;
	@mkdir -p /home/pgeeser/data/mariadb;
	@docker	compose -f ./srcs/docker-compose.yml up

# Stop docker-compose
down:
	@docker compose -f ./srcs/docker-compose.yml down

# Stop docker-compose, delete all containers, images, volumes and networks and start docker-compose
re: fclean
	@docker compose -f ./srcs/docker-compose.yml up --build

# Stop all containers, delete all containers, images, volumes and networks
clean: down
	docker rmi -f $$(docker images -q)
	docker volume rm $$(docker volume ls -q)
	docker network rm $$(docker network ls -q)

# Stop all containers, delete all containers, images, volumes
fclean: clean
	@rm -rf /home/pgeeser/data

.PHONY: all down re clean fclean
