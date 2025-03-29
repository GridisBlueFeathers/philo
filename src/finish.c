/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:13:02 by svereten          #+#    #+#             */
/*   Updated: 2025/03/29 14:20:25 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static t_bool	check_timer(t_data *data, uint32_t i)
{
	uint64_t	now_ts;

	now_ts = start_get_timestamp(data->start_ts);
	if (now_ts - timer_get_timestamp(data->timers[i]) >= data->ttd)
	{
		printf(DIED_LOG, now_ts, i + 1);
		state_set_finish(data->state, TRUE);
		return (FALSE);
	}
	return (TRUE);
}

void	track_finish(t_data *data)
{
	uint32_t i;

	while (!state_get_finish(data->state))
	{
		i = 0;
		while (i < data->num)
		{
			if (!check_timer(data, i))
				return ;
			i++;
		}
		usleep(100);
	}
}
