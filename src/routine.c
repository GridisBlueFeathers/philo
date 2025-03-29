/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:57:03 by svereten          #+#    #+#             */
/*   Updated: 2025/03/29 13:53:33 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <stdio.h>

static void	wait_for_start(t_philo_node *philo)
{
	while(!state_get_start(philo->state))
		usleep(100);
}

static void	take_fork(t_philo_node *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	print_log(FORK, philo->idx, philo->start_ts, philo->state);
}

static void	routine_eat(t_philo_node *philo)
{
	take_fork(philo, philo->one);
	take_fork(philo, philo->two);
	timer_set_timestamp(&philo->timer, start_get_timestamp(philo->start_ts));
	print_log(EATING, philo->idx, philo->start_ts, philo->state);
	philo->times_eaten++;
	if ((philo->times_to_eat
		&& philo->times_eaten == philo->times_to_eat
		&& state_incr_full(philo->state))
		|| state_get_finish(philo->state))
	{
		pthread_mutex_unlock(philo->one);
		pthread_mutex_unlock(philo->two);
		return ;
	}
	usleep(philo->tte * 1000);
	pthread_mutex_unlock(philo->one);
	pthread_mutex_unlock(philo->two);
}

static void	routine_sleep(t_philo_node *philo)
{
	if (state_get_finish(philo->state))
		return ;
	print_log(SLEEPING, philo->idx, philo->start_ts, philo->state);
	usleep(philo->tts * 1000);
}

static void	routine_think(t_philo_node *philo)
{
	if (state_get_finish(philo->state))
		return ;
	print_log(THINKING, philo->idx, philo->start_ts, philo->state);
	usleep(1);
}

#if DEBUG
void	*routine(void *arg)
{
	t_philo_node	*philo;

	philo = (t_philo_node *)arg;
	dprintf(STDERR_FILENO, BLUE"Philo %d is alive\n"RESET, philo->idx + 1);
	wait_for_start(philo);
	dprintf(STDERR_FILENO, BLUE"%lu Philo %d has started\n"RESET, start_get_timestamp(philo->start_ts), philo->idx + 1);
	while (!state_get_finish(philo->state))
	{
		routine_eat(philo);
		routine_sleep(philo);
		routine_think(philo);
		usleep(100);
	}
	return (NULL);
}
#else
void	*routine(void *arg)
{
	t_philo_node	*philo;

	philo = (t_philo_node *)arg;
	wait_for_start(philo);
	while (!state_get_finish(philo->state))
	{
		routine_eat(philo);
		routine_sleep(philo);
		routine_think(philo);
		usleep(100);
	}
	return (NULL);
}
#endif
