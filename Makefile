# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 23:37:36 by ahibrahi          #+#    #+#              #
#    Updated: 2023/09/03 08:46:47 by ahibrahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f

FILES = ft_memset ft_bzero ft_memcpy ft_strtrim ft_strlcat  \
		ft_memmove ft_memchr ft_memcmp ft_strlen ft_strlcpy  \
		ft_strchr ft_strrchr ft_strnstr ft_strncmp ft_isalnum \
		ft_atoi ft_isdigit ft_isalpha ft_isascii ft_isprint    \
		ft_toupper ft_tolower ft_calloc ft_strdup ft_substr     \
		ft_strjoin ft_split ft_itoa ft_strmapi ft_striteri       \
		ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd     \
		
FILES_B = ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back \
          ft_lstdelone \
			 
SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_B = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES_B)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_B = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_B)))


.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: $(OBJS_B)
	$(AR) $(NAME) $^

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re