/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:38:18 by svereten          #+#    #+#             */
/*   Updated: 2025/03/19 15:46:14 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	forks_free(t_fork **forks)
{
	uint32_t	i;

	i = 0;
	while (forks[i])
	{
		if (forks[i]->fork)
		{
			pthread_mutex_destroy(forks[i]->fork);
			free(forks[i]->fork);
		}
		free(forks[i]);
		i++;
	}
	free(forks);
}

t_bool	forks_init(t_data *data)
{
	uint32_t	i;

	data->forks = (t_fork **)ft_calloc(data->num + 1, sizeof(t_fork *));
	if (!data->forks)
		return (FALSE);
	i = 0;
	while (i < data->num)
	{
		data->forks[i] = (t_fork *)ft_calloc(1, sizeof(t_fork));
		if (!data->forks[i])
			return (FALSE);
		data->forks[i]->fork
			= (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
		if (!data->forks[i]->fork)
			return (FALSE);
	}
	return (TRUE);
}
