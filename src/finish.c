/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:13:02 by svereten          #+#    #+#             */
/*   Updated: 2025/03/13 11:13:22 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static t_bool	check_timer(t_data *data_ptr, uint32_t i)
{
	uint64_t	now_ts;

	pthread_mutex_lock(data_ptr->timers[i]->ts_lock);
	now_ts = get_timestamp_ms(data_ptr->start_tv);
	if (now_ts - data_ptr->timers[i]->timestamp >= data_ptr->ttd)
	{
		pthread_mutex_lock(&data_ptr->finish_lock);
		printf(DIED_LOG, get_timestamp_ms(data_ptr->start_tv), i + 1);
		data_ptr->finish = 1;
		pthread_mutex_unlock(&data_ptr->finish_lock);
		pthread_mutex_unlock(data_ptr->timers[i]->ts_lock);
		return (FALSE);
	}
	pthread_mutex_unlock(data_ptr->timers[i]->ts_lock);
	return (TRUE);
}

void	track_finish(void)
{
	uint32_t		i;
	t_data			*data_ptr;

	data_ptr = data(GET);
	while (1)
	{
		i = 0;
		while (i < data(GET)->num)
		{
			if (!check_timer(data_ptr, i))
				return ;
			i++;
		}
	}
}
