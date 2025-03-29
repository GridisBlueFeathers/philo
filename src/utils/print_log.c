/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:28:20 by svereten          #+#    #+#             */
/*   Updated: 2025/03/29 15:11:00 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	print_log(t_print op, t_philo_node *philo)
{
	if (state_get_finish(philo->state))
		return ;
	pthread_mutex_lock(philo->state->print_lock);
	if (op == FORK)
		printf(FORK_LOG, start_get_timestamp(philo->start), philo->idx + 1);
	if (op == EATING)
		printf(EATING_LOG, start_get_timestamp(philo->start), philo->idx + 1);
	if (op == SLEEPING)
		printf(SLEEPNG_LOG, start_get_timestamp(philo->start), philo->idx + 1);
	if (op == THINKING)
		printf(THINKING_LOG, start_get_timestamp(philo->start), philo->idx + 1);
	pthread_mutex_unlock(philo->state->print_lock);
}
