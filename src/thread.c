/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:53:04 by svereten          #+#    #+#             */
/*   Updated: 2025/03/13 00:02:20 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

t_bool	create_threads(void)
{
	uint32_t		i;
	t_philo_node	*cur;

	i = 0;
	cur = data(GET)->head;
	while (i < data(GET)->num)
	{
		if (pthread_create(&cur->thread, NULL, routine, cur) < 0)
			return (FALSE);
		data(GET)->timers[i] = &cur->timer;
		i++;
		cur = cur->next;
	}
	return (TRUE);
}

t_bool	join_threads(void)
{
	uint32_t		i;
	t_philo_node	*cur;

	i = 0;
	cur = data(GET)->head;
	while (i < data(GET)->num)
	{
		if (pthread_join(cur->thread, NULL) < 0)
			return (FALSE);
		i++;
		cur = cur->next;
	}
	return (TRUE);
}
