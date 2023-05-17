# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarie <mmarie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 12:34:21 by mmarie            #+#    #+#              #
#    Updated: 2023/05/16 00:59:21 by mmarie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

FLAGS = -Wall -Werror -Wextra
CC = gcc

all: Objs/server.o Objs/client.o Objs/mini-function.o
	@${CC} ${FLAGS} Objs/server.o Objs/mini-function.o -o $(SERVER) -I Includes -L Libs -l ftprintf
	@${CC} $(FLAGS) Objs/client.o Objs/mini-function.o  -o $(CLIENT) -I Includes -L Libs -l ftprintf
	@echo "Make Compilations Succesfully !"

Objs/server.o:
	@mkdir -p Objs
	@${CC} ${FLAGS} -c Srcs/server.c -o Objs/server.o 

Objs/client.o:
	@mkdir -p Objs
	@${CC} ${FLAGS} -c Srcs/client.c -o Objs/client.o 
Objs/mini-function.o:
	@mkdir -p Objs
	@${CC} ${FLAGS} -c Srcs/mini-function.c -o Objs/mini-function.o 

clean:
	@rm -rf Objs/*.o
	@echo "Clean Succesfully !\n"

fclean: clean
	@rm -rf $(SERVER) $(CLIENT)

re: fclean all
