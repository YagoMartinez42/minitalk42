
NAME	:= server
CLIENT	:= client
CC		:= gcc
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
	cd ${LFTDIR} && make all && cp ${LIBFT} ..

clean:
	cd ${LFTDIR} &&	make clean

fclean: clean
	${RM} ${NAME} ${CLIENT}
	${RM} ${LIBFT}
	cd ${LFTDIR} && make fclean

re: fclean all