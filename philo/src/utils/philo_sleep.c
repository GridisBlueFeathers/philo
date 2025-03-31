/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:03:57 by svereten          #+#    #+#             */
/*   Updated: 2025/03/31 14:48:06 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	philo_sleep(t_state *state, uint64_t usec)
{
	struct timeval	tv;
	uint64_t		end;

	gettimeofday(&tv, NULL);
	end = tv.tv_sec * 1000000 + tv.tv_usec + usec;
	while (get_timestamp_epoch_us() < end && !state_get_finish(state))
		usleep(100);
}
