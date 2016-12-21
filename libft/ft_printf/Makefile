# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nweizman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/25 15:38:22 by nweizman          #+#    #+#              #
#    Updated: 2016/10/25 15:38:23 by nweizman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

CFLAGS =	-Wall -Werror -Wextra

SRCS =		build_object.c						\
			ft_printf.c							\
			help_functions.c					\
			syntax_printf.c						\
			count_digit.c						\
			build/build_object_c.c				\
			build/build_object_o.c				\
			build/build_object_u.c				\
			build/build_object_d.c				\
			build/build_object_s.c				\
			build/build_object_x.c				\
			build/build_object_special.c		\
			ft_func/pft_putstr.c				\
			ft_printf_free.c					\
			ft_func/pft_itoa_base.c

OBJS =		build_object.o				\
			ft_printf.o					\
			help_functions.o			\
			syntax_printf.o				\
			count_digit.o				\
			build_object_c.o			\
			build_object_o.o			\
			build_object_u.o			\
			build_object_d.o			\
			build_object_s.o			\
			build_object_x.o			\
			build_object_special.o		\
			pft_putstr.o				\
			ft_printf_free.o			\
			pft_itoa_base.o

CC =		gcc

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRCS)
	ar -rc $(NAME) $(OBJS)

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
