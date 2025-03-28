/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:08:18 by svereten          #+#    #+#             */
/*   Updated: 2025/03/28 14:23:32 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <unistd.h>

void	simulation(t_data *data)
{
	state_set_start(data->state, FALSE);
	create_threads(data);
	start_set_timestamp(data->start_ts, get_timestamp_epoch());
	state_set_start(data->state, TRUE);
	track_finish(data);
}
