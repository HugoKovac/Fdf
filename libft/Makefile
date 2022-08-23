# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/22 11:55:14 by hkovac            #+#    #+#              #
#    Updated: 2022/01/17 23:39:47 by hkovac           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror -Iincludes -g3
CC = gcc
HEADER = includes/libft.h includes/get_next_line.h
SRC_LIBFT = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_striteri.c\
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
		ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_strstr.c ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c \
		ft_lstsize.c ft_lstlast.c ft_lstdelone.c ft_lstclear.c \
		ft_lstiter.c ft_lstmap.c free_tab.c count_tab.c
SRC_GNL = get_next_line.c get_next_line_utils.c
SRC_PF = ft_char.c ft_dec.c ft_dispatch.c ft_hex.c ft_printf.c \
		ft_ptr.c ft_str.c ft_uns.c utils.c
SRCS_LIBFT = $(addprefix libft/,$(SRC_LIBFT))
SRCS_GNL = $(addprefix get_next_line/,$(SRC_GNL))
SRCS_PF = $(addprefix ft_printf/,$(SRC_PF))
OBJS_LIBFT = $(SRC_LIBFT:.c=.o)
OBJS_GNL = $(SRC_GNL:.c=.o)
OBJS_PF = $(SRC_PF:.c=.o)

all: $(NAME)
	
$(NAME): $(OBJS_LIBFT)
	@ar rsc $(NAME) $(OBJS_LIBFT) $(OBJS_GNL) $(OBJS_PF)

$(OBJS_LIBFT): $(SRCS_LIBFT) $(HEADER)
	@gcc $(CFLAGS) -c $(SRCS_LIBFT)
	@gcc $(CFLAGS) -c $(SRCS_GNL)
	@gcc $(CFLAGS) -c $(SRCS_PF)

clean:
	@rm -f $(OBJS_LIBFT) $(OBJS_GNL) $(OBJS_PF)

fclean: clean
	@rm -f $(NAME)

re: fclean all

lib: $(NAME) clean
	@echo Done

.PHONY: all clean fclean re lib
