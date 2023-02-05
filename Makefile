SRCS	= check_arguments.c \
		ft_split.c \
		instructions.c \
		list_utils.c \
		list.c \
		main.c \
		push_swap_utils.c \
		push_swap_utils2.c \
		push_swap_utils3.c \
		radix_utils.c \
		radix.c \

OBJS	= ${SRCS:.c=.o}

CC		= gcc

FLAGS	= -Wall -Werror -Wextra

HEADER	= push_swap/

NAME	= push_swap

RM		= rm -f

all:	${NAME} Makefile

%.o:	%.c ${HEADER} Makefile
		${CC} ${FLAGS} -I${HEADER} -c $< -o $@

${NAME}:	${OBJS}
			${CC} ${OBJS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:            fclean all

.PHONY: all clean fclean re

