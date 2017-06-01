#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/06 11:18:22 by dbezsinn          #+#    #+#              #
#    Updated: 2016/12/06 11:18:27 by dbezsinn         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC_LIB = 	src/

SRC_FILES = ft_putchar.c \
			ft_putstr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_isprint.c \
			ft_isascii.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_atoi.c \
			ft_atoimax.c \
			ft_putnbr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_putendl.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_itoa.c \
			ft_nbrlen.c \
			ft_strsplit.c \
			ft_countwords.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_strsplit_lst.c \
			ft_lstadd_back.c \
			ft_lstfold.c \
			ft_lst_concat.c \
			ft_lstrev.c \
			ft_lstcount.c \
			ft_swap_int.c \
			get_next_line.c

SRC = $(addprefix $(SRC_LIB), $(SRC_FILES))
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc -c $(FLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
