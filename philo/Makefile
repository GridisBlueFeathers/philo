# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 15:06:44 by svereten          #+#    #+#              #
#    Updated: 2025/03/31 14:55:13 by svereten         ###   ########.fr        #
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
		finish \
		thread \
		timer \
		data/forks \
		data/data \
		data/input \
		data/node \
		data/start_ts \
		state/methods \
		state/constructor \
		simulation/simulation \
		simulation/thinking_time \
		routine/utils \
		routine/single_routine \
		routine/routine \
		utils/putstr_fd \
		utils/ft_strlen \
		utils/ft_strcmp \
		utils/ft_isdigit \
		utils/ft_calloc \
		utils/str_is_number \
		utils/philo_atoi \
		utils/philo_sleep \
		utils/get_timestamp \
		utils/print_log \

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

.PHONY: all clean fclean re
