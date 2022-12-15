# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samartin <samartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 14:33:37 by samartin          #+#    #+#              #
#    Updated: 2022/12/02 13:53:19 by samartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libft.a
CC		:= gcc
AR		:= ar -crs
VPATH	:= lists filem print
SRC		:= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_itoab.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
		ft_split.c ft_strcat.c ft_strchr.c ft_strdup.c ft_striteri.c \
		ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
		ft_strncmp.c ft_strnstr.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
		ft_substr.c ft_tolower.c ft_toupper.c 
SRCLSTS	:= ft_lstadd_front.c ft_lstlast.c ft_lstnew.c ft_lstsize.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
SRCFLM	:= get_next_line_bonus.c get_next_line_utils_bonus.c
SRCPRNT := ft_printf.c ft_printf_alpha_utils.c ft_printf_dec_utils.c \
		ft_printf_hex_utils.c ft_print_memory.c
OBJ		:= ${SRC:.c=.o}
OBJLSTS	:= ${SRCLSTS:.c=.o}
OBJFLM	:= ${SRCFLM:.c=.o}
OBJPRNT	:= ${SRCPRNT:.c=.o}
CFLAGS	:= -Wall -Wextra -Werror
RM		:= rm -rf


all: ${NAME}

${NAME}: ${OBJ} ${OBJLSTS} ${OBJFLM} ${OBJPRNT}
	${AR} ${NAME} $^

clean:
	${RM} ${OBJ} ${OBJLSTS} ${OBJFLM} ${OBJPRNT}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re bonus