/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:48:20 by svereten          #+#    #+#             */
/*   Updated: 2025/03/20 15:55:25 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	data_free(t_data *data)
{
	if (data->timers)
		free(data->timers);
	if (data->forks)
		forks_free(data->forks);
	if (data->state)
		state_free(data->state);
	if (data->head)
		nodes_free(data);
}

t_bool	data_init(t_data *data, int32_t argc, char **argv)
{
	if (!input_processing(argc, argv, data))
		return (FALSE);
	data->timers = (t_timer **)ft_calloc(data->num, sizeof(t_timer *));
	if (!data->timers)
		return (putstr_fd("Timers allocation failed\n", STDERR_FILENO), FALSE);
	data->state = state_constructor();
	if (!data->state)
		return (putstr_fd("State allocation failed\n", STDERR_FILENO), FALSE);
	data->state->philos_num = data->num;
	if (!forks_init(data))
		return (putstr_fd("Forks allocation failed\n", STDERR_FILENO), FALSE);
	if (!nodes_init(data))
		return (putstr_fd("Nodes allocation failed\n", STDERR_FILENO), FALSE);
	return (TRUE);
}
