/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:26:03 by svereten          #+#    #+#             */
/*   Updated: 2025/03/13 00:26:46 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

uint64_t	get_timestamp_ms(struct timeval start)
{
	uint64_t		res;
	struct timeval	now;

	res = 0;
	gettimeofday(&now, NULL);
	res = (now.tv_sec - start.tv_sec) * 1000
		+ (now.tv_usec - start.tv_usec) / 1000;
	return (res);
}
