NAME_PUSH	= push_swap
NAME_CHECKER = checker

CC 		= gcc
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address

PUSH_SRCS =	push_swap.c			\
			parsing_checking.c	\
			libft_utils.c		\
			ft_split.c			\
			algorithm.c			\
			algorithm_utils.c	\
			a_command.c			\
			b_command.c			\
			ab_commands.c		\
			repush_utils1.c		\
			repush_utils2.c		\
			right_spot_utils.c


CHECKER_SRCS =	checker.c			\
				parsing_checking.c	\
				libft_utils.c		\
				ft_split.c			\
				a_command.c			\
				b_command.c			\
				ab_commands.c		\
				right_spot_utils.c


PUSH_OBJS	= ${PUSH_SRCS:.c=.o}

CHECKER_OBJS	= ${CHECKER_SRCS:.c=.o}

%.o: %.c
			$(CC) ${CFLAGS} -g -c $< -o $@ 

all: 		checker push_swap
			@(echo "\033[32m===  PUSH_SWAP AND CHECKER PROJECT COMPILED  ===\033[0m")

push_swap:  ${PUSH_OBJS}
			$(CC) ${CFLAGS} -o ${NAME_PUSH} ${PUSH_OBJS}
			@(echo "\033[32m===  PUSH_SWAP PROJECT COMPILED  ===\033[0m")

checker:  	${CHECKER_OBJS}
			$(CC) ${CFLAGS} ${CHECKER_OBJS} -o ${NAME_CHECKER}
			@(echo "\033[32m===  CHECKER PROJECT COMPILED  ===\033[0m")

clean:
			rm -f *.o

fclean: clean
			rm -f $(NAME_PUSH) $(NAME_CHECKER)
			@echo "\033[33m=== PROJECT CLEANED ===\033[0m"

re: fclean all

.PHONY: all clean fclean re push_swap checker libft