# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 23:33:46 by jnivala           #+#    #+#              #
#    Updated: 2020/06/11 11:59:49 by jnivala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./ft_strlen.c ./ft_strdup.c ./ft_strcmp.c \
./ft_strncmp.c ./ft_atoi.c ./ft_strcpy.c ./ft_strncpy.c ./ft_strcat.c \
./ft_strncat.c ./ft_strlcat.c ./ft_strchr.c ./ft_strrchr.c ./ft_strstr.c \
./ft_strnstr.c ./ft_isalpha.c ./ft_isdigit.c ./ft_isalnum.c ./ft_isascii.c \
./ft_isprint.c ./ft_toupper.c ./ft_tolower.c ./ft_memset.c ./ft_memcpy.c \
./ft_memccpy.c ./ft_memchr.c ./ft_bzero.c ./ft_memmove.c ./ft_memcmp.c \
./ft_memalloc.c

INC = ./libft.h

OBJ  = ft_strlen.o ft_strdup.o ft_strcmp.o ft_strncmp.o ft_atoi.o \
ft_strcpy.o ft_strncpy.o ft_strcat.o ./ft_strncat.o ./ft_strlcat.o \
./ft_strchr.o ./ft_strrchr.o ./ft_strstr.o ./ft_strnstr.o ft_isalpha.o \
./ft_isdigit.o ./ft_isalnum.o ./ft_isascii.o ./ft_isprint.o ./ft_toupper.o \
./ft_tolower.o ./ft_memset.o ./ft_memcpy.o ./ft_bzero.o ./ft_memccpy.o \
./ft_memchr.o ./ft_memmove.o ./ft_memcmp.o ./ft_memalloc.o ./libft.h.gch

all: $(NAME)

$(NAME):
	@gcc -Wall -Werror -Wextra -c $(SRC) -I. $(INC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

test:
	@gcc -Wall -Werror -Wextra test_main.c -L. -lft -lbsd -o t

retest:
	@rm -f test
	@gcc -Wall -Werror -Wextra test_main.c -L. -lft -lbsd -o t

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
