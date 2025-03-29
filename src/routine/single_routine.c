/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 14:08:26 by svereten          #+#    #+#             */
/*   Updated: 2025/03/29 14:34:44 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	*single_routine(void *arg)
{
	t_philo_node	*philo;

	philo = (t_philo_node *)arg;
	wait_for_start(philo);
	take_fork(philo, philo->one);
	while (!state_get_finish(philo->state))
		usleep(100);
	pthread_mutex_unlock(philo->one->fork);
	return (NULL);
}
