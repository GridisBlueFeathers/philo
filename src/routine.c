/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:57:03 by svereten          #+#    #+#             */
/*   Updated: 2025/03/28 16:04:22 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static void	wait_for_start(t_philo_node *philo)
{
	while(!state_get_start(philo->state))
		usleep(1);
}

static void	take_fork(t_philo_node *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	print_log(FORK, philo->idx, philo->start_ts, philo->state);
}

static void	eat(t_philo_node *philo)
{
	take_fork(philo, philo->one);
	take_fork(philo, philo->two);
	print_log(EATING, philo->idx, philo->start_ts, philo->state);
	if (state_get_finish(philo->state))
	{
		pthread_mutex_unlock(philo->one);
		pthread_mutex_unlock(philo->two);
		return ;
	}
	usleep(philo->tte * 1000);
	pthread_mutex_unlock(philo->one);
	pthread_mutex_unlock(philo->two);
}

void	*routine(void *arg)
{
	t_philo_node	*philo;

	philo = (t_philo_node *)arg;
	dprintf(STDERR_FILENO, BLUE"Philo %d is alive\n"RESET, philo->idx + 1);
	wait_for_start(philo);
	dprintf(STDERR_FILENO, BLUE"%lu Philo %d has started\n"RESET, start_get_timestamp(philo->start_ts), philo->idx + 1);
	while (!state_get_finish(philo->state))
	{
		eat(philo);
		usleep(1);
	}
	return (NULL);
}
