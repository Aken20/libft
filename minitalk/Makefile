# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 04:39:30 by ahibrahi          #+#    #+#              #
#    Updated: 2023/12/25 13:40:35 by ahibrahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = Minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f


all: $(Name)

$(Name): client server

re: fclean all

client:
	$(CC) $(CFLAGS) ft_client.c utilitys.c -o client 

server:
	$(CC) $(CFLAGS) ft_server.c utilitys.c -o server

fclean:
	$(RM) client server

.PHONY: all fclean client server