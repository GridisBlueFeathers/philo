/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:45:34 by svereten          #+#    #+#             */
/*   Updated: 2025/03/27 15:00:56 by svereten         ###   ########.fr       */
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

# define START_TS_FAIL "start timestamp allocation failed\n"

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

typedef struct s_state
{
	pthread_mutex_t	*state_lock;
	t_bool			start;
	t_bool			finish;
	uint32_t		philos_full;
	uint32_t		philos_num;
}	t_state;

void		state_set_start(t_state *state, t_bool val);
t_bool		state_get_start(t_state *state);
void		state_set_finish(t_state *state, t_bool val);
t_bool		state_get_finish(t_state *state);
t_bool		state_incr_full(t_state *state);
t_state		*state_constructor(void);
void		state_free(t_state *state);

typedef struct s_timer
{
	struct timeval	start_tv;
	/* Timestamp of start or last eating start */
	uint64_t		timestamp;
	pthread_mutex_t	*ts_lock;
}	t_timer;

typedef struct s_fork
{
	pthread_mutex_t	*fork;
	t_bool			mutex_init;
}	t_fork;

typedef struct s_start_ts
{
	uint64_t		timestamp;
	pthread_mutex_t	*lock;
}	t_start_ts;

uint64_t	start_get_timestamp(t_start_ts *start);
void		start_set_timestamp(t_start_ts *start, uint64_t ts);
t_start_ts	*start_ts_constructor(void);

typedef struct s_philo_node
{
	t_timer				timer;
	struct s_philo_node	*next;
	struct s_philo_node	*prev;
	struct s_data		*data;
	t_state				*state;
	t_start_ts			*start_ts;
	pthread_mutex_t		*one;
	pthread_mutex_t		*two;
	pthread_t			thread;
	uint32_t			idx;
	uint32_t			tte;
	uint32_t			tts;
	uint32_t			times_to_eat;
	uint32_t			times_eaten;
}	t_philo_node;

typedef struct s_data
{
	t_philo_node	*head;
	t_philo_node	*tail;
	t_timer			**timers;
	t_fork			**forks;
	t_state			*state;
	t_start_ts		*start_ts;
	pthread_mutex_t	*data_lock;
	uint32_t		ttd;
	uint32_t		num;
	uint32_t		nodes_num;
	uint32_t		tts;
	uint32_t		tte;
	uint32_t		times_to_eat;
}	t_data;

// data related functions
//
t_bool		data_init(t_data *data, int32_t argc, char **argv);
void		data_free(t_data *data);

t_bool		forks_init(t_data *data);
void		forks_assign(t_data *data);
void		forks_free(t_fork **forks);

t_bool		nodes_init(t_data *data);
void		nodes_free(t_data *data);

t_bool		input_processing(int32_t argc, char **argv, t_data *data);

t_bool		create_nodes(t_data *data);

/**
 * Amount of miliseconds since the start of the universe (epoch)
 */
uint64_t	get_timestamp_epoch(void);

t_bool		create_threads(t_data *data);
void		*routine(void *arg);
t_bool		join_threads(t_data *data);

void		simulation_init(t_data *data);

void		track_finish(t_data *data);

// Utils
//
int32_t		putstr_fd(char *str, int fd);
void		*ft_calloc(size_t nmemb, size_t size);
uint32_t	ft_strlen(char *str);
uint8_t		ft_strcmp(char *s1, char *s2);
t_bool		ft_isdigit(char c);
t_bool		str_is_number(char *str);
t_bool		philo_atoi(char *str, uint32_t *num);
uint64_t	get_timestamp_ms(void);
void		print_log(t_print op, uint32_t idx, struct timeval start);

#endif
