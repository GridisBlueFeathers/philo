/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:49:55 by svereten          #+#    #+#             */
/*   Updated: 2025/03/19 15:26:32 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static t_bool	node_create(t_data *data, uint32_t idx)
{
	t_philo_node	*node;

	node = (t_philo_node *)ft_calloc(1, sizeof(t_philo_node));
	if (!node)
		return (FALSE);
	node->idx = idx;
	node->tte = data->tte;
	node->tts = data->tts;
	node->times_to_eat = data->times_to_eat;
	node->state = data->state;
	if (data->tail)
	{
		node->next = data->head;
		node->prev = data->tail;
		data->tail->next = node;
		data->head->prev = node;
		data->tail = node;
		return (TRUE);
	}
	data->head = node;
	data->tail = node;
	return (TRUE);
}

static t_bool	node_add_mutex(t_philo_node *node)
{
	if (node->idx % 2)
	{
		node->one = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
		if (!node->one)
			return (FALSE);
		if (pthread_mutex_init(node->one, NULL) < 0)
			return (FALSE);

	}
	node->timer.ts_lock
		= (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
	if (!node->timer.ts_lock)
		return (FALSE);
	if (pthread_mutex_init(node->timer.ts_lock, NULL) < 0)
		return (FALSE);
	if (node->prev)
		node->prev->left = node->right;
	node->start = &data(GET)->start;
	return (TRUE);
}

t_bool	create_nodes(t_data *data)
{
	uint32_t		i;
	t_philo_node	*cur;

	i = 0;
	while (i < data->num)
	{
		if (!node_create(data, i))
			return (FALSE);
		i++;
	}
	i = 0;
	cur = data->head;
	while (i < data->num)
	{
		if (!node_add_mutex(cur))
			return (FALSE);
		i++;
		cur = cur->next;
	}
	return (TRUE);
}
