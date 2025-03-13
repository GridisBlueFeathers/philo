# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 15:06:44 by svereten          #+#    #+#              #
#    Updated: 2025/03/13 11:25:29 by svereten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
################################################################################
#
# Project variables
#
################################################################################
NAME = philo

CC = cc

CFLAGS = -Wall -Werror -Wextra

INCLUDE = -I./include

LDLIBS = -lpthread

SRC_DIR = src
OBJ_DIR = obj

FILES = main \
		data \
		input \
		node \
		thread \
		routine \
		finish \
		simulation/init \
		utils/putstr_fd \
		utils/ft_strlen \
		utils/ft_isdigit \
		utils/ft_calloc \
		utils/str_is_number \
		utils/philo_atoi \
		utils/get_timestamp \

SRCS = ${FILES:%=${SRC_DIR}/%.c}
OBJS = ${FILES:%=${OBJ_DIR}/%.o}

OBJ_DIRS = ${sort ${dir ${OBJS}}}

RM = rm -rf

################################################################################
#
# Dev variables
#
################################################################################

INCLUDE_FILES = ${wildcard include/*.h}

CFLAGS := ${CFLAGS} -g -D DEBUG=1

################################################################################
#
# Project targets
#
################################################################################

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${INCLUDE} ${OBJS} -o $@ ${LDFLAGS} ${LDLIBS} 

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c | ${OBJ_DIRS}
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

${OBJ_DIRS}:
	mkdir -p $@

clean:
	${RM} ${OBJ_DIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

################################################################################
#
# Dev targets
#
################################################################################

helgrind: re
	valgrind --tool=helgrind ./${NAME} ${ARGS}

valgrind: re
	valgrind --show-leak-kinds=all --leak-check=full ./${NAME} ${ARGS}

norm:
	norminette ${SRCS} ${INCLUDE_FILES}

run: re
	@./${NAME} ${ARGS}

.PHONY: all clean fclean re
