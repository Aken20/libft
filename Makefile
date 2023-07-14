NAME = strlen
CFLAGS =  -Wall -Wextra -Werror
all =
libft.a: ft_$(Name).c main.c libft.h
	gcc $(CFLAGS) -c ft_strlen.c main.c libft.h

clean :
fclean :
re :
