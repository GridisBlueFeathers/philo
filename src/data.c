/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:35:31 by svereten          #+#    #+#             */
/*   Updated: 2025/03/05 14:33:10 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

__attribute__ ((destructor))
void	data_deinit(void)
{
	data(FREE);
}

t_data	*data_alloc(void)
{
	t_data	*res;

	res = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!res)
		return (NULL);
	return (res);
}

t_data	*data_free(t_data *data)
{
	uint32_t		i;
	t_philo_node	*cur;
	t_philo_node	*tmp;

	cur = data->head;
	i = 0;
	while (i < data->num)
	{
		tmp = cur->next;
		free(cur->right);
		free(cur);
		cur = tmp;
		i++;
	}
	if (data->timers)
		free(data->timers);
	free(data);
	return (NULL);
}

t_data	*data(t_option op)
{
	static t_data	*ptr;

	if (op == GET && !ptr)
		ptr = data_alloc();
	if (op == FREE)
		ptr = data_free(ptr);
	return (ptr);
}
