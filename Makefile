
NAME	:= server
CLIENT	:= client
CC		:= gcc
SRCSV	:= server.c
SRCCL	:= client.c
OBJSV	:= ${SRCSV:.c=.o}
OBJCL	:= ${SRCCL:.c=.o}
CFLAGS	:= -Wall -Wextra -Werror
RM		:= rm -rf
LFTDIR  := libft
LIBFT	:= libft.a

all: ${NAME}

${NAME}: ${CLIENT} ${OBJSV}
	${CC} ${CFLAGS} ${OBJSV} ${LFTDIR}/${LIBFT} -o ${NAME}

${CLIENT}: ${LIBFT} ${OBJCL}
	${CC} ${CFLAGS} ${OBJCL} ${LFTDIR}/${LIBFT} -o ${CLIENT}

${LIBFT}:
	cd ${LFTDIR} && make all

clean:
	${RM} ${OBJCL} ${OBJSV} 
	cd ${LFTDIR} &&	make clean

fclean: clean
	${RM} ${NAME} ${CLIENT}
	${RM} ${LIBFT}
	cd ${LFTDIR} && make fclean

re: fclean all