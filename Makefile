# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 11:37:05 by fmaurer           #+#    #+#              #
#    Updated: 2024/08/05 20:08:25 by fmaurer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC			= cc

## for unit test to work:
CFLAGS	= -Wall -Wextra -Werror

# we are building a library which might even end up being a shared lib. so
# generating "Position Independent Code" seems like a good idea.
# additionally printf-unit-test needs this. some literature:
# https://stackoverflow.com/questions/5311515/gcc-fpic-option
PIC	=	-fPIC

LIBFT_PATH	= ./libft
LIBFT				= $(LIBFT_PATH)/libft.a

LIB_FTPRINTF_PATH	= ./ft_printf
LIB_FTPRINTF			= $(LIB_FTPRINTF_PATH)/libftprintf.a

all: $(NAME)

$(NAME):
	make -C $(LIBFT_PATH) all
	make -C $(LIB_FTPRINTF_PATH) all
	mv $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(LIB_FTPRINTF)

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(LIB_FTPRINTF_PATH) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
