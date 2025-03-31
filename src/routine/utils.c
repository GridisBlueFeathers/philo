/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 14:10:26 by svereten          #+#    #+#             */
/*   Updated: 2025/03/31 12:08:41 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <stdio.h>

void	wait_for_start(t_philo_node *philo)
{
	while (!state_get_start(philo->state))
		philo_sleep(philo->state, 100);
}

#if DEBUG

void	take_fork(t_philo_node *philo, t_fork *fork)
{
	pthread_mutex_lock(fork->fork);
	print_log(FORK, philo);
	dprintf(STDERR_FILENO, BLUE"Fork %u\n"RESET, fork->idx);
}
#else

void	take_fork(t_philo_node *philo, t_fork *fork)
{
	pthread_mutex_lock(fork->fork);
	print_log(FORK, philo);
}
#endif

void	routine_eat(t_philo_node *philo)
{
	take_fork(philo, philo->one);
	take_fork(philo, philo->two);
	timer_set_timestamp(&philo->timer, start_get_timestamp(philo->start));
	print_log(EATING, philo);
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
	philo_sleep(philo->state, philo->tte * 1000);
	pthread_mutex_unlock(philo->one->fork);
	pthread_mutex_unlock(philo->two->fork);
}

void	routine_sleep(t_philo_node *philo)
{
	if (state_get_finish(philo->state))
		return ;
	print_log(SLEEPING, philo);
	philo_sleep(philo->state, philo->tts * 1000);
}

void	routine_think(t_philo_node *philo)
{
	if (state_get_finish(philo->state))
		return ;
	print_log(THINKING, philo);
	philo_sleep(philo->state, philo->ttt * 1000);
}
