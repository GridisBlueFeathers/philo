/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:57:03 by svereten          #+#    #+#             */
/*   Updated: 2025/03/19 13:33:24 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static void	wait_for_start(t_philo_node *philo)
{
	while(!philo->state->get_start(philo->state))
		;
}

void	*routine(void *arg)
{
	t_philo_node	*philo;

	philo = (t_philo_node *)arg;
	dprintf(STDERR_FILENO, BLUE"Philo %d is alive\n"RESET, philo->idx + 1);
	wait_for_start(philo);
	dprintf(STDERR_FILENO, BLUE"Philo %d has started\n"RESET, philo->idx + 1);
	while (!philo->state->get_finish(philo->state))
	{
		usleep(1);
	}
	return (NULL);
}
