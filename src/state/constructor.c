/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:03:48 by svereten          #+#    #+#             */
/*   Updated: 2025/03/20 15:20:21 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	state_free(t_state *state)
{
	pthread_mutex_destroy(state->state_lock);
	free(state->state_lock);
	free(state);
}

t_state	*state_constructor(void)
{
	t_state	*res;

	res = (t_state *)ft_calloc(1, sizeof(t_state));
	if (!res)
		return (NULL);
	res->state_lock = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
	if (!res->state_lock)
		return (free(res), NULL);
	if (pthread_mutex_init(res->state_lock, NULL) != 0)
		return (free(res->state_lock), free(res), NULL);
	res->set_start = set_start;
	res->get_start = get_start;
	res->set_finish = set_finish;
	res->get_finish = get_finish;
	res->incr_full = incr_full;
	return (res);
}
