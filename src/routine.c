/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:57:03 by svereten          #+#    #+#             */
/*   Updated: 2025/03/04 17:01:33 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static void	wait_for_start(t_philo_node *philo)
{
	pthread_mutex_lock(philo->start);
	pthread_mutex_unlock(philo->start);
}

void	*routine(void *arg)
{
	t_philo_node	*philo;

	philo = (t_philo_node *)arg;
	dprintf(STDERR_FILENO, BLUE"Philo %d is alive\n"RESET, philo->idx + 1);
	wait_for_start(philo);
	dprintf(STDERR_FILENO, BLUE"Philo %d has started\n"RESET, philo->idx + 1);
	return (NULL);
}
