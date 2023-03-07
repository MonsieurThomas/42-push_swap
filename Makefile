# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 12:49:39 by rthomas           #+#    #+#              #
#    Updated: 2022/05/16 16:19:24 by rthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCES =	utils/ft_lstadd_back.c \
			utils/ft_lstadd_front.c \
			utils/ft_lstadd_front_data.c \
			utils/ft_lstlast.c \
			utils/ft_lstnew.c \
			utils/ft_lstnew_data.c \
			utils/ft_lstsize.c \
			utils/ft_atoi.c \
			utils/ft_split.c \
			src/create_stack.c \
			src/first_sort.c \
			src/create_string.c \
			src/sort_biggest.c \
			src/sort_middle.c \
			src/sort_smallest.c \
			src/mediane.c \
			src/free.c \
			src/main.c \
			src/isgood.c \
			src/push_swap_less_6.c \
			src/push_swap_less_4.c \
			src/sort_swap.c \
			src/sort.c \

OBJECTS = ${SOURCES:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${OBJECTS}
	${CC} ${CFLAGS} ${OBJECTS} -o ${NAME}

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re