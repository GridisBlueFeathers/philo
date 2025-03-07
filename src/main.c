/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:46:57 by svereten          #+#    #+#             */
/*   Updated: 2025/03/05 15:30:03 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <stdio.h>
#include <sys/time.h>

void	print_log(t_print op, uint32_t idx)
{
	struct timeval tv;

	pthread_mutex_lock(&data(GET)->finish_lock);
	gettimeofday(&tv, NULL);
	if (op == FORK && !data(GET)->finish)
		printf(FORK_LOG, (tv.tv_usec - data(GET)->start_time) / 1000, idx);
	if (op == EATING && !data(GET)->finish)
		printf(EATING_LOG, (tv.tv_usec - data(GET)->start_time) / 1000, idx);
	if (op == SLEEPING && !data(GET)->finish)
		printf(SLEEPNG_LOG, (tv.tv_usec - data(GET)->start_time) / 1000, idx);
	if (op == THINKING && !data(GET)->finish)
		printf(THINKING_LOG, (tv.tv_usec - data(GET)->start_time) / 1000, idx);
	pthread_mutex_unlock(&data(GET)->finish_lock);
}

void	track_finish(void)
{
	uint32_t		i;
	struct timeval	tv;
	t_data			*data_ptr;

	data_ptr = data(GET);
	while (1)
	{
		i = 0;
		while (i < data(GET)->num)
		{
			pthread_mutex_lock(&data_ptr->timer_lock);
			gettimeofday(&tv, NULL);
			if (tv.tv_usec - data_ptr->timers[i] >= data_ptr->ttd * 1000)
			{
				printf(DIED_LOG, (tv.tv_usec - data(GET)->start_time) / 1000, i + 1);
				pthread_mutex_lock(&data_ptr->finish_lock);
				data_ptr->finish = 1;
				pthread_mutex_unlock(&data_ptr->finish_lock);
				pthread_mutex_unlock(&data_ptr->timer_lock);
				return ;
			}
			pthread_mutex_unlock(&data_ptr->timer_lock);
			i++;
		}
	}
}

void	start_time_tracking(void)
{
	struct timeval	tv;
	t_data			*data_ptr;
	uint32_t		 i;

	gettimeofday(&tv, NULL);
	data_ptr = data(GET);
	data_ptr->start_time = tv.tv_usec;
	i = 0;
	while (i < data_ptr->num)
	{
		data_ptr->timers[i] = data_ptr->start_time;
		i++;
	}
	dprintf(STDERR_FILENO, BLUE"Start time: %ld\n"RESET, data_ptr->start_time);
}

#if DEBUG

int32_t	main(int argc, char **argv)
{
	if (!data(GET))
	{
		putstr_fd("data initialization failed\n", STDERR_FILENO);
		return (1);
	}
	if (!input_processing(argc, argv))
		return (1);
	dprintf(STDERR_FILENO, BLUE"Philos num: %d\n"RESET, data(GET)->num);
	dprintf(STDERR_FILENO, BLUE"Philos ttd: %ld\n"RESET, data(GET)->ttd);
	dprintf(STDERR_FILENO, BLUE"Philos tte: %d\n"RESET, data(GET)->tte);
	dprintf(STDERR_FILENO, BLUE"Philos tts: %d\n"RESET, data(GET)->tts);
	dprintf(STDERR_FILENO, BLUE"Times to eat: %d\n"RESET, data(GET)->times_to_eat);
	if (!create_nodes())
		return (1);
	pthread_mutex_lock(&data(GET)->start);
	create_threads();
	start_time_tracking();
	dprintf(STDERR_FILENO, "Hello?\n");
	pthread_mutex_unlock(&data(GET)->start);
	track_finish();
	join_threads();
}
#else

int32_t	main(int argc, char **argv)
{
	if (!data(GET))
	{
		putstr_fd("data initialization failed\n", STDERR_FILENO);
		return (1);
	}
	if (!input_processing(argc, argv))
		return (1);
}
#endif
