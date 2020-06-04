# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 23:33:46 by jnivala           #+#    #+#              #
#    Updated: 2020/06/04 17:15:03 by jnivala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./ft_strlen.c ./ft_strdup.c ./ft_strcmp.c \
./ft_strncmp.c ./ft_atoi.c ./ft_strcpy.c ./ft_strncpy.c

INC = ./libft.h

OBJ  = ft_strlen.o ft_strdup.o ft_strcmp.o ft_strncmp.o ft_atoi.o \
ft_strcpy.o ft_strncpy.o ./libft.h.gch

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
