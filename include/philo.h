/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:45:34 by svereten          #+#    #+#             */
/*   Updated: 2025/03/13 12:51:46 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# ifndef DEBUG
#  define DEBUG 1
# endif

# define BLUE "\x1b[34m"
# define RESET "\x1b[0m"

# define DIED_LOG "%li %d died\n"
# define FORK_LOG "%li %d has taken a fork\n"
# define EATING_LOG "%li %d is eating\n"
# define SLEEPNG_LOG "%li %d is sleeping\n"
# define THINKING_LOG "%li %d is thinking\n"

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

typedef enum e_print
{
	DIED,
	FORK,
	EATING,
	SLEEPING,
	THINKING
}	t_print;

typedef struct s_timer
{
	struct timeval	start_tv;
	/* Timestamp of start or last eating start */
	uint64_t		timestamp;
	pthread_mutex_t	*ts_lock;
}	t_timer;

typedef struct s_philo_node
{
	t_timer				timer;
	struct s_philo_node	*next;
	struct s_philo_node	*prev;
	pthread_mutex_t		*right;
	pthread_mutex_t		*left;
	pthread_mutex_t		*start;
	pthread_t			thread;
	uint32_t			idx;
	uint32_t			tts;
	uint32_t			tte;
	uint32_t			times_to_eat;
}	t_philo_node;

typedef struct s_data
{
	t_philo_node	*head;
	t_philo_node	*tail;
	t_timer			**timers;
	struct timeval	start_tv;
	pthread_mutex_t	start;
	pthread_mutex_t	finish_lock;
	uint32_t		ttd;
	uint32_t		num;
	uint32_t		tts;
	uint32_t		tte;
	uint32_t		times_to_eat;
	t_bool			finish;
}	t_data;

// data related functions
//
t_data		*data(t_option op);

t_bool		input_processing(int32_t argc, char **argv);
t_bool		create_nodes(void);

t_bool		create_threads(void);
void		*routine(void *arg);
t_bool		join_threads(void);

void		simulation_init(void);

void		track_finish(void);

// Utils
//
int32_t		putstr_fd(char *str, int fd);
void		*ft_calloc(size_t nmemb, size_t size);
uint32_t	ft_strlen(char *str);
uint8_t		ft_strcmp(char *s1, char *s2);
t_bool		ft_isdigit(char c);
t_bool		str_is_number(char *str);
t_bool		philo_atoi(char *str, uint32_t *num);
uint64_t	get_timestamp_ms(struct timeval start);
void		print_log(t_print op, uint32_t idx, struct timeval start);

#endif
