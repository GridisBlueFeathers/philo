/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:13:02 by svereten          #+#    #+#             */
/*   Updated: 2025/03/20 15:40:44 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static t_bool	check_timer(t_data *data, uint32_t i)
{
	(void)data;
	(void)i;
	/*uint64_t	now_ts;

	pthread_mutex_lock(data->timers[i]->ts_lock);
	now_ts = get_timestamp_ms(data->start_tv);
	if (now_ts - data->timers[i]->timestamp >= data->ttd)
	{
		pthread_mutex_lock(&data->finish_lock);
		printf(DIED_LOG, get_timestamp_ms(data->start_tv), i + 1);
		data->finish = 1;
		pthread_mutex_unlock(&data->finish_lock);
		pthread_mutex_unlock(data->timers[i]->ts_lock);
		return (FALSE);
	}
	pthread_mutex_unlock(data->timers[i]->ts_lock);*/
	return (TRUE);
}

void	track_finish(t_data *data)
{
	uint32_t		i;

	while (1)
	{
		i = 0;
		while (i < data->num)
		{
			if (!check_timer(data, i))
				return ;
			i++;
		}
	}
}
