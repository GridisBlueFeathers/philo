/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:45:34 by svereten          #+#    #+#             */
/*   Updated: 2025/03/03 11:02:15 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef DEBUG
#  define DEBUG 1
# endif

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef enum e_option
{
	GET,
	FREE,
}	t_option;

typedef struct s_data
{
	int32_t	num;
	int32_t	ttd;
	int32_t	tts;
	int32_t	tte;
	int32_t	times_to_eat;
}	t_data;

// data related functions
//
t_data		*data(t_option op);

t_bool		input_processing(int32_t argc, char **argv);

// Utils
//
int32_t		putstr_fd(char *str, int fd);
void		*ft_calloc(size_t nmemb, size_t size);
uint32_t	ft_strlen(char *str);
t_bool		ft_isdigit(char c);
t_bool		str_is_number(char *str);
uint32_t	philo_atoi(char *str);

#endif
