/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:52:34 by svereten          #+#    #+#             */
/*   Updated: 2025/03/19 13:14:36 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	set_start(struct s_state *self, t_bool val)
{
	pthread_mutex_lock(self->state_lock);
	self->start = val;
	pthread_mutex_unlock(self->state_lock);
}

t_bool	get_start(struct s_state *self)
{
	t_bool	res;

	pthread_mutex_lock(self->state_lock);
	res = self->start;
	pthread_mutex_unlock(self->state_lock);
	return (res);
}

void	set_finish(struct s_state *self, t_bool val)
{
	pthread_mutex_lock(self->state_lock);
	self->finish = val;
	pthread_mutex_unlock(self->state_lock);
}

t_bool	get_finish(struct s_state *self)
{
	t_bool	res;

	pthread_mutex_lock(self->state_lock);
	res = self->finish;
	pthread_mutex_unlock(self->state_lock);
	return (res);
}

t_bool	incr_full(struct s_state *self)
{
	pthread_mutex_lock(self->state_lock);
	self->philos_full++;
	if (self->philos_full == self->philos_num)
	{
		self->finish = TRUE;
		pthread_mutex_unlock(self->state_lock);
		return (TRUE);
	}
	pthread_mutex_unlock(self->state_lock);
	return (FALSE);
}
