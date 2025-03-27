/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:13:02 by svereten          #+#    #+#             */
/*   Updated: 2025/03/27 16:11:35 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static t_bool	check_timer(t_data *data, uint32_t i)
{
	uint64_t	now_ts;

	pthread_mutex_lock(data->timers[i]->ts_lock);
	now_ts = start_get_timestamp(data->start_ts);
	if (now_ts - data->timers[i]->timestamp >= data->ttd)
	{
		printf(DIED_LOG, now_ts, i + 1);
		state_set_finish(data->state, TRUE);
		pthread_mutex_unlock(data->timers[i]->ts_lock);
		return (FALSE);
	}
	pthread_mutex_unlock(data->timers[i]->ts_lock);
	return (TRUE);
}

void	track_finish(t_data *data)
{
	uint32_t i;

	while (1)
	{
		i = 0;
		while (i < data->num)
		{
			if (!check_timer(data, i))
				return ;
			i++;
		}
		usleep(1);
	}
}
