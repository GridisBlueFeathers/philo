/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:49:55 by svereten          #+#    #+#             */
/*   Updated: 2025/03/13 11:18:21 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static t_bool	node_create(uint32_t idx)
{
	t_philo_node	*node;

	node = (t_philo_node *)ft_calloc(1, sizeof(t_philo_node));
	if (!node)
		return (FALSE);
	node->idx = idx;
	node->tte = data(GET)->tte;
	node->tts = data(GET)->tts;
	node->times_to_eat = data(GET)->times_to_eat;
	if (data(GET)->tail)
	{
		node->next = data(GET)->head;
		node->prev = data(GET)->tail;
		data(GET)->tail->next = node;
		data(GET)->head->prev = node;
		data(GET)->tail = node;
		return (TRUE);
	}
	data(GET)->head = node;
	data(GET)->tail = node;
	return (TRUE);
}

static t_bool	node_add_mutex(t_philo_node *node)
{
	node->right = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
	if (!node->right)
		return (FALSE);
	if (pthread_mutex_init(node->right, NULL) < 0)
		return (FALSE);
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

t_bool	create_nodes(void)
{
	uint32_t		i;
	t_philo_node	*cur;

	i = 0;
	while (i < data(GET)->num)
	{
		if (!node_create(i))
			return (FALSE);
		i++;
	}
	i = 0;
	cur = data(GET)->head;
	while (i < data(GET)->num)
	{
		if (!node_add_mutex(cur))
			return (FALSE);
		i++;
		cur = cur->next;
	}
	return (TRUE);
}
