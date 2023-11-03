# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 14:37:20 by chonorat          #+#    #+#              #
#    Updated: 2023/03/15 15:15:36 by chonorat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLOR
_GREEN = \033[92m

#POLICE
_END = \033[0m
_BOLD = \033[1m

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
RM = @rm -f
AR = @ar -rcs
CC = @cc -c
HEADER = ./libft.h
PRINT = @echo
FILES = ft_isalpha\
		ft_isdigit\
		ft_isalnum\
		ft_isascii\
		ft_isprint\
		ft_strlen\
		ft_memset\
		ft_bzero\
		ft_memcpy\
		ft_memmove\
		ft_strlcpy\
		ft_strlcat\
		ft_toupper\
		ft_tolower\
		ft_strchr\
		ft_strrchr\
		ft_strncmp\
		ft_memchr\
		ft_memcmp\
		ft_strnstr\
		ft_atoi\
		ft_calloc\
		ft_strdup\
		ft_substr\
		ft_strjoin\
		ft_strtrim\
		ft_split\
		ft_itoa\
		ft_strmapi\
		ft_striteri\
		ft_putchar_fd\
		ft_putstr_fd\
		ft_putendl_fd\
		ft_putnbr_fd\
		ft_lstnew\
		ft_lstadd_front\
		ft_lstsize\
		ft_lstlast\
		ft_lstadd_back\
		ft_lstdelone\
		ft_lstclear\
		ft_lstiter\
		ft_lstmap
SRCS = $(addsuffix .c, $(FILES))
OBJ_FILES = $(addsuffix .o, $(FILES))

$(NAME): $(OBJ_FILES)
	$(PRINT) "\nMaking ${_BOLD}libft.a${_END}..."
	$(AR) $(NAME) $(OBJ_FILES)
	$(PRINT) "${_BOLD}${_GREEN}libft.a done.${_END}"

%.o: %.c Makefile $(HEADER)
	$(PRINT) "Compiling ${_BOLD}$<$(_END)..."
	$(CC) $(CFLAGS) $< -o $@

all: $(NAME)

clean:
	$(PRINT) "${_BOLD}Cleaning libft...${_END}"
	$(RM) $(OBJ_FILES)
	$(PRINT) "${_BOLD}${_GREEN}libft cleaned.${_END}"

fclean: clean
	$(RM) $(NAME)
	$(PRINT) "${_BOLD}${_GREEN}libft.a deleted.${_END}"

re: fclean all

.PHONY: all clean fclean re
