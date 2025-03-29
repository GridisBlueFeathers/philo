/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:57:03 by svereten          #+#    #+#             */
/*   Updated: 2025/03/29 14:14:26 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <stdio.h>



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
