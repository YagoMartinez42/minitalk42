# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samartin <samartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 12:34:51 by samartin          #+#    #+#              #
#    Updated: 2022/12/15 12:44:39 by samartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= server
CLIENT	:= client
CC		:= gcc
AR		:= ar -crs
SRCSV	:= server.c
SRCCL	:= client.c
CFLAGS	:= -Wall -Wextra -Werror
RM		:= rm -rf
LFTDIR  := libft
LIBFT	:= libft.a

all: ${NAME}

${NAME}: ${CLIENT}
	${CC} ${SRCSV} ${LIBFT} -o ${NAME}

${CLIENT}: ${LIBFT}
	${CC} ${SRCCL} ${LIBFT} -o ${CLIENT}

${LIBFT}:
	cd ${LFTDIR} ; make all

clean:
	cd ${LFTDIR} ; make clean
	${RM} ${OBJS}

fclean: clean
	cd ${LFTDIR} ; make fclean
	${RM} ${NAME}

re: fclean all