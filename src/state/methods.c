/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:52:34 by svereten          #+#    #+#             */
/*   Updated: 2025/03/27 15:05:06 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	state_set_start(t_state *state, t_bool val)
{
	pthread_mutex_lock(state->state_lock);
	state->start = val;
	pthread_mutex_unlock(state->state_lock);
}

t_bool	state_get_start(t_state *state)
{
	t_bool	res;

	pthread_mutex_lock(state->state_lock);
	res = state->start;
	pthread_mutex_unlock(state->state_lock);
	return (res);
}

void	state_set_finish(t_state *state, t_bool val)
{
	pthread_mutex_lock(state->state_lock);
	state->finish = val;
	pthread_mutex_unlock(state->state_lock);
}

t_bool	state_get_finish(t_state *state)
{
	t_bool	res;

	pthread_mutex_lock(state->state_lock);
	res = state->finish;
	pthread_mutex_unlock(state->state_lock);
	return (res);
}

t_bool	state_incr_full(t_state *state)
{
	pthread_mutex_lock(state->state_lock);
	state->philos_full++;
	if (state->philos_full == state->philos_num)
	{
		state->finish = TRUE;
		pthread_mutex_unlock(state->state_lock);
		return (TRUE);
	}
	pthread_mutex_unlock(state->state_lock);
	return (FALSE);
}
