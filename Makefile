# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/26 13:08:18 by jnivala           #+#    #+#              #
#    Updated: 2020/07/15 17:43:10 by jnivala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./ft_strlen.c ./ft_strdup.c ./ft_strcmp.c \
./ft_strncmp.c ./ft_atoi.c ./ft_strcpy.c ./ft_strncpy.c ./ft_strcat.c \
./ft_strncat.c ./ft_strlcat.c ./ft_strchr.c ./ft_strrchr.c ./ft_strstr.c \
./ft_strnstr.c ./ft_isalpha.c ./ft_isdigit.c ./ft_isalnum.c ./ft_isascii.c \
./ft_isprint.c ./ft_toupper.c ./ft_tolower.c ./ft_memset.c ./ft_memcpy.c \
./ft_memccpy.c ./ft_memchr.c ./ft_bzero.c ./ft_memmove.c ./ft_memcmp.c \
./ft_memalloc.c ./ft_memdel.c ./ft_strnew.c ./ft_strdel.c ./ft_strclr.c \
./ft_putchar_fd.c ./ft_putstr_fd.c ./ft_putendl_fd.c ./ft_striter.c \
./ft_striteri.c ./ft_strmap.c ./ft_strmapi.c ./ft_strequ.c ./ft_strnequ.c \
./ft_strsub.c ./ft_strtrim.c ./ft_strjoin.c ./ft_strsplit.c ./ft_itoa.c \
./ft_putchar.c ./ft_putstr.c ./ft_putendl.c ./ft_putnbr.c ./ft_putnbr_fd.c \
./ft_lstadd.c ./ft_lstiter.c ./ft_lstmap.c ./ft_lstnew.c ./ft_lstdelone.c \
./ft_lstdel.c ./ft_lstlen.c ./ft_lst_addback.c ./ft_isspace.c \
./ft_strarrnew.c ./ft_strarrdel.c ./ft_strndup.c ./ft_itoa_base.c


INC = ./libft.h

OBJ  = $(SRC:.c=.o) ./libft.h.gch

.PHONY: clean fclean all

all: $(NAME)

$(NAME): $(SRC) $(INC)
	@gcc -Wall -Werror -Wextra -c $(SRC) $(INC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@rm -f ./libft.h.gch

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
