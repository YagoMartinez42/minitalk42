
NAME	:= server
CLIENT	:= client
SVBN	:= server_bonus
CLBN	:= client_bonus
CC		:= gcc
SRCSV	:= server.c
SRCCL	:= client.c
SRCSVBN	:= server_bonus.c
SRCCLBN := client_bonus.c
CFLAGS	:= -Wall -Wextra -Werror
RM		:= rm -rf
LFTDIR  := libft
LIBFT	:= libft.a

all: ${NAME}

bonus: ${SVBN} ${CLBN}

${NAME}: ${CLIENT}
	${CC} ${CFLAGS} ${SRCSV} ${LFTDIR}/${LIBFT} -o ${NAME}

${CLIENT}: ${LIBFT}
	${CC} ${CFLAGS} ${SRCCL} ${LFTDIR}/${LIBFT} -o ${CLIENT}

${SVBN}: ${CLBN}
	${CC} ${CFLAGS} ${SRCSVBN} ${LFTDIR}/${LIBFT} -o ${SVBN}

${CLBN}: ${LIBFT}
	${CC} ${CFLAGS} ${SRCCLBN} ${LFTDIR}/${LIBFT} -o ${CLBN}

${LIBFT}:
	cd ${LFTDIR} && make all

clean:
	cd ${LFTDIR} &&	make clean

fclean: clean
	${RM} ${NAME} ${CLIENT}
	${RM} ${LIBFT}
	cd ${LFTDIR} && make fclean

re: fclean all