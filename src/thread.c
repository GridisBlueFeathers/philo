/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:53:04 by svereten          #+#    #+#             */
/*   Updated: 2025/03/31 13:45:18 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <stdio.h>

t_bool	create_threads(t_data *data)
{
	uint32_t		i;
	t_philo_node	*cur;

	i = 0;
	cur = data->head;
	if (data->num == 1)
	{
		if (pthread_create(&cur->thread, NULL, single_routine, cur) < 0)
			return (FALSE);
		return (TRUE);
	}
	while (i < data->num)
	{
		if (pthread_create(&cur->thread, NULL, routine, cur) < 0)
			return (FALSE);
		i++;
		cur = cur->next;
	}
	return (TRUE);
}

t_bool	join_threads(t_data *data)
{
	uint32_t		i;
	t_philo_node	*cur;

	i = 0;
	cur = data->head;
	while (i < data->num)
	{
		if (pthread_join(cur->thread, NULL) < 0)
			return (FALSE);
		i++;
		cur = cur->next;
	}
	return (TRUE);
}
