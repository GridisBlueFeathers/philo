/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:08:18 by svereten          #+#    #+#             */
/*   Updated: 2025/03/13 11:18:42 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static void	start_time_tracking(void)
{
	t_data		*data_ptr;
	uint32_t	i;

	data_ptr = data(GET);
	gettimeofday(&data_ptr->start_tv, NULL);
	i = 0;
	while (i < data_ptr->num)
	{
		data_ptr->timers[i]->start_tv.tv_sec = data_ptr->start_tv.tv_sec;
		data_ptr->timers[i]->start_tv.tv_usec = data_ptr->start_tv.tv_usec;
		i++;
	}
}

void	simulation_init(void)
{
	create_threads();
	pthread_mutex_lock(&data(GET)->start);
	start_time_tracking();
	pthread_mutex_unlock(&data(GET)->start);
}
