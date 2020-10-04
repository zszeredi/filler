NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB_DIR = ../libft
SRCS =		srcs/ft_printf.c \
			srcs/cut_str.c \
			srcs/fs_c.c \
			srcs/fs_di.c \
			srcs/fs_f.c \
			srcs/fs_f_round.c \
			srcs/fs_f_print.c \
			srcs/fs_p.c \
			srcs/fs_s.c \
			srcs/ft_flags.c \
			srcs/ft_length_modifier.c \
			srcs/fs_oux.c \
			srcs/parse_fs.c \
			srcs/uniform_functions.c \
			srcs/ft_wp.c \
			srcs/pdioux_create.c \
			srcs/pdioux_enlarge.c \
			srcs/pdioux_main.c \

RESULT = 	ft_printf.o \
			cut_str.o \
			fs_c.o \
			fs_di.o \
			fs_f.o \
			fs_f_round.o \
			fs_f_print.o \
			fs_p.o \
			fs_s.o \
			ft_flags.o \
			ft_length_modifier.o \
			fs_oux.o \
			parse_fs.o \
			uniform_functions.o \
			ft_wp.o \
			pdioux_create.o \
			pdioux_enlarge.o \
			pdioux_main.o \

INCLUDES = ft_printf.h

all: $(NAME)

$(NAME):
	@make -C $(LIB_DIR)
	@cp $(LIB_DIR)/libft.a $(NAME)
	@$(CC) -c $(CFLAGS) $(SRCS) $(INCLUDES)
	@ar rc $(NAME) $(RESULT)
	@ranlib $(NAME)
	@/bin/rm -f ft_printf.h.gch
	@echo "compilation ok"

clean:
	@/bin/rm -f $(RESULT)
	@/bin/rm -f libft/*.o
	@printf "Objects are removed correctly.\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(LIB_DIR)/libft.a
	@printf "$(NAME) and $(LIB) are removed correctly.\n"

re: fclean all

.PHONY: all clean fclean re
