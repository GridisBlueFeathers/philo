# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svereten <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 15:06:44 by svereten          #+#    #+#              #
#    Updated: 2024/09/26 18:20:22 by svereten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = philo

CC = cc

CFLAGS = -Wall -Werror -Wextra

INCLUDE = -I./include -I./libft/include

LDLIBS = -lft
LDFLAGS = -L./libft/

LIBFT_DIR = libft
SRC_DIR = src
OBJ_DIR = obj

FILES = main

OBJS = ${FILES:%=${OBJ_DIR}/%.o}

OBJ_DIRS = ${sort ${dir ${OBJS}}}

LIBFT = ./${LIBFT_DIR}/libft.a

RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${INCLUDE} ${OBJS} -o $@ ${LDFLAGS} ${LDLIBS} 

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c | ${OBJ_DIRS}
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

${OBJ_DIRS}:
	mkdir -p $@

${LIBFT}:
	${MAKE} -C ${LIBFT_DIR}

clean:
	${RM} ${OBJ_DIR}
	${MAKE} clean -C ${LIBFT_DIR}

fclean: clean
	${RM} ${NAME}
	${MAKE} fclean -C ${LIBFT_DIR}

re: fclean all

.PHONY: all clean fclean re
