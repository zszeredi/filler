# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/03 15:14:43 by zszeredi          #+#    #+#              #
#    Updated: 2020/10/04 13:42:59 by zszeredi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zszeredi.filler
CFLAGS = -Wall -Wextra -Werror
SRC := $(shell find src -type f -regex ".*\.c")
LIB = libft/libft.a
INC = get_next_line/get_next_line.c
SANATIZE = -fsanitize=address

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) libs
	gcc $(CFLAGS) $(SRC)$(INC) $(LIB) -o $(NAME)
libs:
	@make -C libft/
	@printf "Libs compiled\n"
clean:
	@make clean -C libft/
	@printf "Libft objects are removed correctly.\n"
fclean: clean
	@make fclean -C libft/
	@/bin/rm -f $(NAME)
	@/bin/rm -f filler.h.gch
	@printf "$(NAME), .gch,  and $(LIB) are removed correctly.\n"
re: fclean all
.PHONY: all clean fclean re
