# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nweizman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 12:28:33 by nweizman          #+#    #+#              #
#    Updated: 2016/12/07 12:28:35 by nweizman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	"ft_ls"

C_FILES		=	src/main.c				\
				src/notes.c				\
				src/step_one.c			\
				src/support.c			\
				src/step_two.c			\
				src/step_two2.c			\
				src/sorting.c			\
				src/printing.c			\
				src/printing2.c			\
				src/files_list.c		\
				src/time.c				\
				src/file_mode.c			\
				src/bonus.c				\
				src/flags.c				\
				src/file_name.c			\
				src/do_print_l.c		\
				src/file_pwgw.c			\
				src/sorting_t.c			\
				src/sorting_c.c			\
				src/sorting_u.c			\
				src/sorting_uu.c		\
				src/sorting_ss.c		\
				src/print_if_file.c		\
				src/file_size.c			\
				src/print_col.c

O_FILES		=	src/main.o				\
				src/notes.o				\
				src/step_one.o			\
				src/support.o			\
				src/step_two.o			\
				src/step_two2.o			\
				src/printing.o			\
				src/printing2.o			\
				src/files_list.o		\
				src/sorting.o			\
				src/time.o				\
				src/file_mode.o			\
				src/bonus.o				\
				src/flags.o				\
				src/file_name.o			\
				src/do_print_l.o		\
				src/file_pwgw.o			\
				src/sorting_t.o			\
				src/sorting_c.o			\
				src/sorting_u.o			\
				src/sorting_uu.o		\
				src/sorting_ss.o		\
				src/print_if_file.o		\
				src/file_size.o			\
				src/print_col.o

CC			=	gcc -Wall -Werror -Wextra

LIBFT		=	-L libft -lft -L libft/ft_printf -lftprintf

all: $(NAME)

$(NAME): $(O_FILES)
	@make -C libft
	@$(CC) -o $(NAME) $(C_FILES) $(LIBFT)

clean:
	@make clean -C libft
	@/bin/rm -f $(O_FILES)

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
