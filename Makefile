#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/14 14:47:43 by dbezsinn          #+#    #+#              #
#    Updated: 2017/05/14 14:47:44 by dbezsinn         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CHECKER_NAME =		checker
PUSH_SWAP_NAME = 	push_swap

PUSH_SWAP_SRC_DIR = push_swap_src/

CHECKER_FILES =		checker.c
PUSH_SWAP_FILES = 	push_swap.c \
					ps_list_to_arr_sort.c \
					stack_split_main.c \
					small_stack_sort.c \
					plist_functions.c \
					sort_three.c \
					process_perm_cases.c \
					process_perm_cases1.c \
					stack_split_addon.c \
					backpush_a_b.c
COMMON_FILES = 		stack_commands.c \
					common_functions.c \
					common_functions1.c \
					common_functions2.c \
					common_functions3.c
FILES = 			$(CHECKER_FILES) $(PUSH_SWAP_FILES) $(COMMON_FILES)

CHECKER_SRC = 		$(addprefix $(PUSH_SWAP_SRC_DIR), $(CHECKER_FILES))
PUSH_SWAP_SRC = 	$(addprefix $(PUSH_SWAP_SRC_DIR), $(PUSH_SWAP_FILES))
COMMON_SRC = 		$(addprefix $(PUSH_SWAP_SRC_DIR), $(COMMON_FILES))
SRC = 				$(CHECKER_SRC) $(PUSH_SWAP_SRC) $(COMMON_SRC)

CHECKER_OBJ =		$(CHECKER_SRC:.c=.o) $(COMMON_SRC:.c=.o)
PUSH_SWAP_OBJ =		$(PUSH_SWAP_SRC:.c=.o) $(COMMON_SRC:.c=.o)

OBJ = 				$(CHECKER_OBJ) $(PUSH_SWAP_OBJ)
FLAGS = 			-Wall -Werror -Wextra

all: $(CHECKER_NAME) $(PUSH_SWAP_NAME)

$(CHECKER_NAME): $(CHECKER_OBJ)
	gcc -o $(CHECKER_NAME) $(CHECKER_OBJ) -L ./ -lft

$(PUSH_SWAP_NAME): $(PUSH_SWAP_OBJ)
	gcc -o $(PUSH_SWAP_NAME) $(PUSH_SWAP_OBJ) -L ./ -lft

%.o: %.c
	gcc -c $(FLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJ)

fclean: clean
	rm -f $(CHECKER_NAME)
	rm -f $(PUSH_SWAP_NAME)

re: fclean all


	# clang -o push_swap checker.o -L ./ -lft