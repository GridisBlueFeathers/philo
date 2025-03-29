/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 14:10:26 by svereten          #+#    #+#             */
/*   Updated: 2025/03/29 14:51:45 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <stdio.h>

void	wait_for_start(t_philo_node *philo)
{
	while (!state_get_start(philo->state))
		usleep(100);
}

#if DEBUG
void	take_fork(t_philo_node *philo, t_fork *fork)
{
	pthread_mutex_lock(fork->fork);
	print_log(FORK, philo->idx, philo->start_ts, philo->state);
	dprintf(STDERR_FILENO, BLUE"Fork %u\n"RESET, fork->idx);
}
#else
void	take_fork(t_philo_node *philo, t_fork *fork)
{
	pthread_mutex_lock(fork->fork);
	print_log(FORK, philo->idx, philo->start_ts, philo->state);
}
#endif

void	routine_eat(t_philo_node *philo)
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
		pthread_mutex_unlock(philo->one->fork);
		pthread_mutex_unlock(philo->two->fork);
		return ;
	}
	usleep(philo->tte * 1000);
	pthread_mutex_unlock(philo->one->fork);
	pthread_mutex_unlock(philo->two->fork);
}

void	routine_sleep(t_philo_node *philo)
{
	if (state_get_finish(philo->state))
		return ;
	print_log(SLEEPING, philo->idx, philo->start_ts, philo->state);
	usleep(philo->tts * 1000);
}

void	routine_think(t_philo_node *philo)
{
	if (state_get_finish(philo->state))
		return ;
	print_log(THINKING, philo->idx, philo->start_ts, philo->state);
	usleep(1);
}
