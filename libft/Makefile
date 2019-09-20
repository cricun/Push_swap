# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djon-con <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 17:26:14 by djon-con          #+#    #+#              #
#    Updated: 2019/06/12 20:49:07 by djon-con         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror -g
NAME = libft.a
SRC = $(addprefix srcs/basics/,	ft_abs.c \
	ft_atoi.c \
	ft_atol.c \
	ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isnumber.c \
	ft_isprint.c \
	ft_isspace.c \
	ft_itoa.c \
	ft_push_back.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_realloc.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_wordcount.c \
	get_next_line.c) \
	$(addprefix srcs/lists/, ft_lstadd.c \
	ft_lstaddrev.c \
	ft_lstcount.c \
	ft_lstdel.c \
	ft_lstdelone.c \
	ft_lstfree.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstpop.c \
	ft_lstrm.c) \
	$(addprefix srcs/memory/, ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c) \
	$(addprefix srcs/strings/, ft_putstr.c \
	ft_putstr_fd.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c) \
	$(addprefix srcs/ft_printf/, atoi_move.c \
	clean_and_enlarge_vec.c \
	extract_float_values.c \
	fill_helper.c \
	float.c \
	ft_init.c \
	ft_parse.c \
	ft_parse_part_two.c \
	ft_printf.c \
	get_va_arg.c \
	get_va_digit_values.c \
	get_wp.c \
	itoa_base_printf.c \
	long_arithmetic.c \
	print_arg.c \
	print_buf.c \
	print_char.c \
	print_float.c \
	print_long.c \
	print_something.c \
	print_string.c \
	set_precision.c \
	string_helper.c \
	vector_operations.c) \
	srcs/ft_vec_init.c
HEADERS = $(addprefix includes/, libft.h get_next_line.h ft_printf.h float.h)
OBJ = $(SRC:.c=.o)

.PHONY: $(NAME) all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $@ $(OBJ)

%.o: %.c $(HEADERS)
	@gcc $(FLAGS) -Iincludes -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
