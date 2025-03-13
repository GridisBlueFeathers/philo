/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:28:20 by svereten          #+#    #+#             */
/*   Updated: 2025/03/13 00:28:31 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	print_log(t_print op, uint32_t idx, struct timeval start)
{
	pthread_mutex_lock(&data(GET)->finish_lock);
	if (op == FORK && !data(GET)->finish)
		printf(FORK_LOG, get_timestamp_ms(start), idx);
	if (op == EATING && !data(GET)->finish)
		printf(EATING_LOG, get_timestamp_ms(start), idx);
	if (op == SLEEPING && !data(GET)->finish)
		printf(SLEEPNG_LOG, get_timestamp_ms(start), idx);
	if (op == THINKING && !data(GET)->finish)
		printf(THINKING_LOG, get_timestamp_ms(start), idx);
	pthread_mutex_unlock(&data(GET)->finish_lock);
}
