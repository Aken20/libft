# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 23:37:36 by ahibrahi          #+#    #+#              #
#    Updated: 2023/07/24 13:06:50 by ahibrahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =  isalpha.c /
		isdigit.c /
		isalnum.c /
		isascii.c /
		isprint.c /
		strlen.c /
		memset.c /
		bzero.c /
		memcpy.c /
		memmove.c /
		strlcpy.c /
		strlcat.c /
		toupper.c /
		tolower.c /
		strchr.c /
		strrchr.c /
		strncmp.c /
		memchr.c /
		memcmp.c /
		strnstr.c 

OBJECTS =	isalpha.o /
			isdigit.o /
			isalnum.o /
			isascii.o /
			isprint.o /
			strlen.o /
			memset.o /
			bzero.o /
			memcpy.o /
			memmove.o /
			strlcpy.o /
			strlcat.o /
			toupper.o /
			tolower.o /
			strchr.o /
			strrchr.o /
			strncmp.o /
			memchr.o /
			memcmp.o /
			strnstr.o 

INCLUDES = ./

all: $(NAME)

$(NAME): $(SRCS) libft.h
	@gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all