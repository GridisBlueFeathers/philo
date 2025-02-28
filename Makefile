# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svereten <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 15:06:44 by svereten          #+#    #+#              #
#    Updated: 2025/02/28 16:02:59 by svereten         ###   ########.fr        #
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
LDFLAGS = 

SRC_DIR = src
OBJ_DIR = obj

FILES = main \
		utils/putstr_fd \
		utils/ft_strlen \
		utils/ft_isdigit \
		utils/str_is_number \

SRCS = ${FILES:%=${SRC_DIR}/%.c}
OBJS = ${FILES:%=${OBJ_DIR}/%.o}

OBJ_DIRS = ${sort ${dir ${OBJS}}}

RM = rm -rf

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

norm:
	norminette ${SRCS}

run: ${NAME}
	@./${NAME} ${ARGS}

.PHONY: all clean fclean re
