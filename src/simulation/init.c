/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:08:18 by svereten          #+#    #+#             */
/*   Updated: 2025/03/27 14:00:19 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static void	start_time_tracking(t_data *data)
{
	uint32_t	i;

	(void)data;
	(void)i;
	/*gettimeofday(&data->start_tv, NULL);
	i = 0;
	while (i < data->num)
	{
		data->timers[i]->start_tv.tv_sec = data->start_tv.tv_sec;
		data->timers[i]->start_tv.tv_usec = data->start_tv.tv_usec;
		i++;
	}*/
}

void	simulation_init(t_data *data)
{
	data->state->set_start(data->state, FALSE);
	create_threads(data);
	start_time_tracking(data);
	data->state->set_start(data->state, TRUE);
}
