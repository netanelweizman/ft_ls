# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nweizman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/31 13:11:22 by nweizman          #+#    #+#              #
#    Updated: 2016/10/20 17:51:34 by nweizman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a

CFLAGS +=	-Wall -Werror -Wextra

SRCS =		ft_memalloc.c				\
			ft_putendl.c				\
			ft_strdup.c					\
			ft_strncat.c				\
			ft_strtrim.c				\
			ft_atoi.c					\
			ft_memccpy.c				\
			ft_putnbr.c					\
			ft_strequ.c					\
			ft_strncmp.c				\
			ft_tolower.c				\
			ft_bzero.c					\
			ft_memchr.c					\
			ft_putstr.c					\
			ft_striter.c				\
			ft_strncpy.c				\
			ft_toupper.c				\
			ft_isalnum.c				\
			ft_memcmp.c					\
			ft_strcat.c					\
			ft_striteri.c				\
			ft_strnequ.c				\
			ft_isalpha.c				\
			ft_memcpy.c					\
			ft_strchr.c					\
			ft_strjoin.c				\
			ft_strnew.c					\
			ft_isascii.c				\
			ft_memdel.c					\
			ft_strclr.c					\
			ft_strlcat.c				\
			ft_strrchr.c				\
			ft_isdigit.c				\
			ft_memmove.c				\
			ft_strcmp.c					\
			ft_strlen.c					\
			ft_strsplit.c				\
			ft_isprint.c				\
			ft_memset.c					\
			ft_strcpy.c					\
			ft_strmap.c					\
			ft_strstr.c					\
			ft_itoa.c					\
			ft_putchar.c				\
			ft_strdel.c					\
			ft_strmapi.c				\
			ft_strsub.c					\
			ft_strnstr.c				\
			ft_putchar_fd.c				\
			ft_putstr_fd.c				\
			ft_putendl_fd.c				\
			ft_putnbr_fd.c				\
			ft_lstnew.c					\
			ft_lstdelone.c				\
			ft_lstdel.c					\
			ft_lstadd.c					\
			ft_lstiter.c				\
			ft_lstmap.c					\
			ft_list_size.c				\
			ft_list_push_back.c			\
			ft_list_last.c				\
			ft_any.c					\
			ft_print_words_tables.c		\
			ft_is_prime.c				\
			ft_flip_str.c				\
			ft_add_char_to_str.c		\
			ft_add_char_to_str_back.c	\
			ft_itoa_base.c				\
			ft_free_node.c				\
			ft_list_push_front.c		\
			ft_init_dynamic_arr.c		\
			ft_insert_dynamic_arr.c		\
			ft_free_dynamic_arr.c		\
			ft_str_is_number.c			\
			ft_free_strsplit.c			\
			ft_str_to_lower.c			\
			ft_add_char_at_index.c

OBJS =		$(SRCS:.c=.o)

CC =		gcc

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRCS)
	ar -rc $(NAME) $(OBJS)
	@make -C ft_printf

clean:
	@/bin/rm -f $(OBJS)
	@make clean -C ft_printf

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C ft_printf

re: fclean all
