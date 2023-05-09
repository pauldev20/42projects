# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 15:30:42 by pgeeser           #+#    #+#              #
#    Updated: 2023/05/08 23:05:26 by pgeeser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@mkdir -p /home/paulgeeser/data/wordpress;
	@mkdir -p /home/paulgeeser/data/mariadb;
	@docker-compose -f ./srcs/docker-compose.yml up

down:
	@docker-compose -f ./srcs/docker-compose.yml down

re:
	@docker-compose -f srcs/docker-compose.yml up --build

clean:
	@rm -rf /home/paulgeeser/data
	@docker stop $$(docker ps -qa);\
	docker rm $$(docker ps -qa);\
	docker rmi -f $$(docker images -qa);\
	docker volume rm $$(docker volume ls -q);\
	docker network rm $$(docker network ls -q);\

fclean:

.PHONY: all down re clean fclean
