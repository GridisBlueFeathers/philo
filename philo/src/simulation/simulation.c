/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:08:18 by svereten          #+#    #+#             */
/*   Updated: 2025/03/31 14:39:34 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	simulation(t_data *data)
{
	state_set_start(data->state, FALSE);
	if (!create_threads(data))
	{
		state_set_finish(data->state, TRUE);
		state_set_start(data->state, TRUE);
		putstr_fd("Thread creation failed\n", STDERR_FILENO);
		return ;
	}
	start_set_timestamp(data->start_ts, get_timestamp_epoch_ms());
	state_set_start(data->state, TRUE);
	track_finish(data);
}
