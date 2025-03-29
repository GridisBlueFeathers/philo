/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:48:51 by svereten          #+#    #+#             */
/*   Updated: 2025/03/29 16:08:20 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

/**
 * Philos number and index are not the same
 * idx % 2 == 0 means philo number is odd
 * idx % 2 != 0 means philo number is even
 */
uint32_t	calculate_initial_ttt(t_data *data, uint32_t idx)
{
	uint32_t	res;

	if (idx % 2 == 0)
		res = 1;
	else
		res = data->tte;
	if (data->num % 2 != 0 && idx + 1 == data->num)
		res = data->tte * 2;
	return (res);
}

uint32_t	calculate_ttt(t_data *data)
{
	uint32_t	res;

	if (data->num % 2 == 0 && (data->tte > data->tts))
		res = data->tte - data->tts;
	else if (data->num % 2 != 0 && ((data->tte * 2) > data->tts))
		res = (data->tte * 2) - data->tts;
	else
		res = 0;
	return (res);
}
