/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:49:55 by svereten          #+#    #+#             */
/*   Updated: 2025/03/20 15:58:59 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static void	node_connect(t_data *data, t_philo_node *node)
{
	data->nodes_num++;
	if (data->tail)
	{
		node->next = data->head;
		node->prev = data->tail;
		data->tail->next = node;
		data->head->prev = node;
		data->tail = node;
		return ;
	}
	data->head = node;
	data->tail = node;
}

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
	node->data = data;
	node->state = data->state;
	node_connect(data, node);
	return (TRUE);
}

void	nodes_free(t_data *data)
{
	t_philo_node	*node;
	t_philo_node	*tmp;

	node = data->head;
	while (data->nodes_num > 0)
	{
		tmp = node->next;
		free(node);
		node = tmp;
		data->nodes_num--;
	}
}

t_bool	nodes_init(t_data *data)
{
	uint32_t		i;

	i = 0;
	while (i < data->num)
	{
		if (!node_create(data, i))
			return (FALSE);
		i++;
	}
	i = 0;
	if (data->num > 1)
		forks_assign(data);
	else
		
	return (TRUE);
}
