# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 13:53:42 by fmaurer           #+#    #+#              #
#    Updated: 2025/04/22 11:10:05 by fmaurer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# This is my LibFT Makefile. By now it also includes my ft_printf, which is
# certainly not production ready code. Also in libft i would like to do some
# more improvements towards clean code.

NAME = libft.a

SRCS_LIBFT =  ft_isalpha.c \
							ft_isdigit.c \
							ft_isalnum.c \
							ft_isascii.c \
							ft_isprint.c \
							ft_strlen.c \
							ft_memset.c \
							ft_bzero.c \
							ft_memcpy.c \
							ft_memmove.c \
							ft_strlcpy.c \
							ft_strcpy.c \
							ft_strlcat.c \
							ft_toupper.c \
							ft_tolower.c \
							ft_strchr.c \
							ft_strrchr.c \
							ft_strncmp.c \
							ft_strcmp.c \
							ft_memchr.c \
							ft_memcmp.c \
							ft_strnstr.c \
							ft_atoi.c \
							ft_calloc.c \
							ft_strdup.c \
							ft_substr.c \
							ft_strjoin.c \
							ft_strtrim.c \
							ft_split.c \
							_ft_multisplit.c \
							ft_multisplit.c \
							ft_freesplit.c \
							ft_itoa.c \
							ft_strmapi.c \
							ft_striteri.c \
							ft_putchar_fd.c \
							ft_putstr_fd.c \
							ft_putendl_fd.c \
							ft_putnbr_fd.c \
							ft_lstnew.c \
							ft_lstadd_front.c \
							ft_lstsize.c \
							ft_lstlast.c \
							ft_lstadd_back.c \
							ft_lstclear.c \
							ft_lstdelone.c \
							ft_lstiter.c \
							ft_lstmap.c \
							ft_strndup.c \
							ft_isspace.c

SRCS_FTPR	=	ft_printf/ft_printf.c \
						ft_printf/smpl_utils.c \
						ft_printf/smpl_utoa.c \
						ft_printf/smpl_convert_cdsi.c \
						ft_printf/smpl_convert_p.c \
						ft_printf/smpl_convert_x.c \
						ft_printf/smpl_convert.c \
						ft_printf/compl_convert_bonus.c \
						ft_printf/compl_utils_bonus.c \
						ft_printf/compl_is_conv_bonus.c \
						ft_printf/compl_flag_utils_bonus.c \
						ft_printf/compl_do_conv_bonus.c \
						ft_printf/compl_convert_d_bonus.c \
						ft_printf/compl_convert_u_bonus.c \
						ft_printf/compl_convert_c_bonus.c \
						ft_printf/compl_convert_s_bonus.c \
						ft_printf/compl_convert_p_bonus.c \
						ft_printf/compl_convert_x_bonus.c

SRCS_FTDPR	=	ft_dprintf/ft_dprintf.c \
							ft_dprintf/smpl_utils.c \
							ft_dprintf/smpl_utoa.c \
							ft_dprintf/smpl_convert_cdsi.c \
							ft_dprintf/smpl_convert_p.c \
							ft_dprintf/smpl_convert_x.c \
							ft_dprintf/smpl_convert.c \
							ft_dprintf/compl_convert_bonus.c \
							ft_dprintf/compl_utils_bonus.c \
							ft_dprintf/compl_is_conv_bonus.c \
							ft_dprintf/compl_flag_utils_bonus.c \
							ft_dprintf/compl_do_conv_bonus.c \
							ft_dprintf/compl_convert_d_bonus.c \
							ft_dprintf/compl_convert_u_bonus.c \
							ft_dprintf/compl_convert_c_bonus.c \
							ft_dprintf/compl_convert_s_bonus.c \
							ft_dprintf/compl_convert_p_bonus.c \
							ft_dprintf/compl_convert_x_bonus.c

SRCS_GNL	=	get_next_line/get_next_line.c

OBJS_DIR = obj

OBJS	= $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRCS_LIBFT)) 
OBJS += $(patsubst ft_printf/%.c,$(OBJS_DIR)/%.o,$(SRCS_FTPR))
OBJS += $(patsubst ft_dprintf/%.c,$(OBJS_DIR)/ftdprntf-%.o,$(SRCS_FTDPR))
OBJS += $(patsubst get_next_line/%.c,$(OBJS_DIR)/%.o,$(SRCS_GNL))

CC = cc
CC_FLAGS = -Wall -Wextra -Werror

# we are building a library which might even end up being a shared lib. so
# generating "Position Independent Code" seems like a good idea.
# additionally printf-unit-test needs this. some literature:
# https://stackoverflow.com/questions/5311515/gcc-fpic-option
PIC	=	-fPIC


# debugging flags for more verbosity on memory corruption issues and debugging
# in general.
DEBUG_FLAGS = -fsanitize=address -fno-omit-frame-pointer -g
DEBUG_OBJS = $(OBJS:.o=.debug.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo -e "\nArchiving:\n($^) --> libft.a\n"
	@ar -rcs $(NAME) $(OBJS)

$(OBJS_DIR)/%.o : %.c libft.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@$(CC) $(CC_FLAGS) $(PIC) -c $< -o $@

$(OBJS_DIR)/%.o : ft_printf/%.c libft.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@$(CC) $(CC_FLAGS) $(PIC) -c $< -o $@

$(OBJS_DIR)/ftdprntf-%.o : ft_dprintf/%.c libft.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@$(CC) $(CC_FLAGS) $(PIC) -c $< -o $@

$(OBJS_DIR)/%.o : get_next_line/%.c libft.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@$(CC) $(CC_FLAGS) $(PIC) -c $< -o $@

# debugging targets:
debug: CC_FLAGS += $(DEBUG_FLAGS)
debug: $(DEBUG_OBJS)
	@echo -e "\nArchiving debug version:\n($^) --> libft.a\n"
	@ar -rcs $(NAME) $(DEBUG_OBJS)

$(OBJS_DIR)/%.debug.o : %.c libft.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling debug: $<"
	@$(CC) $(CC_FLAGS) $(PIC) -c $< -o $@

$(OBJS_DIR)/%.debug.o : ft_printf/%.c libft.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling debug: $<"
	@$(CC) $(CC_FLAGS) $(PIC) -c $< -o $@

$(OBJS_DIR)/ftdprntf-%.debug.o : ft_dprintf/%.c libft.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling debug: $<"
	@$(CC) $(CC_FLAGS) $(PIC) -c $< -o $@

$(OBJS_DIR)/%.debug.o : get_next_line/%.c libft.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling debug: $<"
	@$(CC) $(CC_FLAGS) $(PIC) -c $< -o $@

clean:
	@echo "Removing objs..."
	rm -rf $(OBJS_DIR)

fclean: clean
	@echo "Removing $(NAME)..."
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all debug
