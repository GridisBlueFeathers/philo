/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_ts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:27:22 by svereten          #+#    #+#             */
/*   Updated: 2025/03/31 12:11:27 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

uint64_t	start_get_timestamp(t_start_ts *start)
{
	uint64_t		res;

	pthread_mutex_lock(start->lock);
	res = get_timestamp_epoch_ms() - start->timestamp;
	pthread_mutex_unlock(start->lock);
	return (res);
}

void	start_set_timestamp(t_start_ts *start, uint64_t ts)
{
	pthread_mutex_lock(start->lock);
	start->timestamp = ts;
	pthread_mutex_unlock(start->lock);
}

t_start_ts	*start_ts_constructor(void)
{
	t_start_ts	*res;

	res = (t_start_ts *)ft_calloc(1, sizeof(t_start_ts));
	if (!res)
		return (putstr_fd(START_TS_FAIL, STDERR_FILENO), NULL);
	res->lock = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
	if (!res->lock || pthread_mutex_init(res->lock, NULL))
		return (putstr_fd(START_TS_FAIL, 2), free(res), NULL);
	return (res);
}
