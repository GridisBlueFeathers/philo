/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:03:48 by svereten          #+#    #+#             */
/*   Updated: 2025/03/29 14:52:27 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	state_free(t_state *state)
{
	pthread_mutex_destroy(state->state_lock);
	free(state->state_lock);
	pthread_mutex_destroy(state->print_lock);
	free(state->print_lock);
	free(state);
}

t_state	*state_constructor(void)
{
	t_state	*res;

	res = (t_state *)ft_calloc(1, sizeof(t_state));
	if (!res)
		return (NULL);
	res->state_lock = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
	if (!res->state_lock || pthread_mutex_init(res->state_lock, NULL))
		return (free(res->state_lock), free(res), NULL);
	res->print_lock = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
	if (!res->print_lock || pthread_mutex_init(res->print_lock, NULL))
	{
		pthread_mutex_destroy(res->state_lock);
		return (free(res->print_lock), free(res->state_lock), free(res), NULL);
	}
	return (res);
}
