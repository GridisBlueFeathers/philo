/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:48:20 by svereten          #+#    #+#             */
/*   Updated: 2025/03/19 15:55:05 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

t_data	*data_free(t_data *data)
{
	uint32_t		i;
	t_philo_node	*cur;
	t_philo_node	*tmp;

	if (!data)
		return (NULL);
	cur = data->head;
	i = 0;
	while (cur && i < data->num)
	{
		tmp = cur->next;
		free(cur->right);
		free(cur->timer.ts_lock);
		free(cur);
		cur = tmp;
		i++;
	}
	if (data->timers)
		free(data->timers);
	if (data->forks)
		forks_free(data->forks);
	free(data);
	return (NULL);
}

t_bool	data_init(t_data *data)
{
	data->timers = (t_timer **)ft_calloc(data->num, sizeof(t_timer *));
	if (!data->timers)
		return (putstr_fd("Timers allocation failed\n", STDERR_FILENO), FALSE);
	data->state = state_constructor();
	if (!data->state)
		return (putstr_fd("State allocation failed\n", STDERR_FILENO), FALSE);
	data->state->philos_num = data->num;
	if (!forks_init(data))
		return (putstr_fd("Forks allocation failed\n", STDERR_FILENO), FALSE);
	return (TRUE);
}
