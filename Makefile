# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 17:05:22 by chonorat          #+#    #+#              #
#    Updated: 2023/07/07 15:56:00 by chonorat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLOR
_GREEN = \033[92m
_YELLOW = \033[33m
_RED = \033[31m

#POLICE
_END = \033[0m
_BOLD = \033[1m

NAME = push_swap
CC = @cc
RM = @rm -rf
PRINT = @echo
HEADER = Includes/push_swap.h
CFLAGS = -Wall -Wextra -Werror
MAKE_LIBFT = @make -C libft
LIBFT = libft/libft.a
CLEAN_LIBFT = @make clean -C libft
FCLEAN_LIBFT = @make fclean -C libft
DIR = @mkdir -p
FILES = push_swap\
		arg_checker\
		convert_stack\
		lst_utilitary\
		utilitaries\
		do_swap\
		do_push\
		do_rotate\
		do_rev_rotate\
		is_sorted\
		small_sort\
		radix_sort
SRCS = $(addsuffix .c, $(addprefix Sources/, $(FILES)))
OBJS = $(addsuffix .o, $(addprefix Objects/, $(FILES)))


$(NAME): $(OBJS)
		$(PRINT) "\n${_YELLOW}Checking Libft...${_END}"
		$(MAKE_LIBFT)
		$(PRINT) "\n${_YELLOW}Making push_swap...${_END}"
		$(CC) -o $(NAME) $(OBJS) $(LIBFT)
		$(PRINT) "${_BOLD}${_GREEN}push_swap done.${_END}"

Objects/%.o: Sources/%.c Makefile $(HEADER)
	$(DIR) Objects
	$(PRINT) "Compiling ${_BOLD}$<$(_END)..."
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME) 

clean:
	$(CLEAN_LIBFT)
	$(PRINT) "\n${_BOLD}Cleaning Objects...${_END}"
	$(RM) $(OBJS)
	$(PRINT) "${_BOLD}${_GREEN}Objects cleaned.${_END}"

fclean:
	$(FCLEAN_LIBFT)
	$(PRINT) "\n${_BOLD}Cleaning Objects...${_END}"
	$(RM) $(OBJS)
	$(PRINT) "${_RED}Deleting push_swap...${_END}"
	$(RM) $(NAME)
	$(PRINT) "${_RED}Deleting Objects directory...${_END}"
	$(RM) Objects
	$(PRINT) "${_BOLD}${_GREEN}Objects cleaned.${_END}"
	$(PRINT) "${_BOLD}${_GREEN}Push_swap deleted.${_END}"
	$(PRINT) "${_BOLD}${_GREEN}Objects directory deleted.\n${_END}"

re:	fclean all

.PHONY: all clean fclean re