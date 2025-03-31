/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:19:19 by svereten          #+#    #+#             */
/*   Updated: 2025/03/28 16:21:34 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

uint64_t	timer_get_timestamp(t_timer *timer)
{
	uint64_t	res;

	pthread_mutex_lock(timer->lock);
	res = timer->timestamp;
	pthread_mutex_unlock(timer->lock);
	return (res);
}

void	timer_set_timestamp(t_timer *timer, uint64_t timestamp)
{
	pthread_mutex_lock(timer->lock);
	timer->timestamp = timestamp;
	pthread_mutex_unlock(timer->lock);
}
