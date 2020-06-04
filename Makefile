# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 23:33:46 by jnivala           #+#    #+#              #
#    Updated: 2020/06/04 14:48:03 by jnivala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./srcs/ft_strlen.c ./srcs/ft_strdup.c ./srcs/ft_strcmp.c \
./srcs/ft_strncmp.c ./srcs/ft_atoi.c

INC = ./inc/libft.h

OBJ  = ft_strlen.o ft_strdup.o ft_strcmp.o ft_strncmp.o ft_atoi.o \
./inc/libft.h.gch

all: $(NAME)

$(NAME):
	@gcc -Wall -Werror -Wextra -c $(SRC) -I. $(INC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

test:
	@gcc -Wall -Werror -Wextra test_main.c -L. -lft -o t

retest:
	@rm -f test
	@gcc -Wall -Werror -Wextra test_main.c -L. -lft -o t

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
