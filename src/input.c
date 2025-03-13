/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:01:15 by svereten          #+#    #+#             */
/*   Updated: 2025/03/13 11:17:48 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static t_bool	input_validataion(int32_t argc, char **argv)
{
	int8_t	i;

	if (argc < 5 || argc > 6)
		return (FALSE);
	i = 1;
	while (i < argc)
	{
		if (!str_is_number(argv[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	input_processing(int32_t argc, char **argv)
{
	t_data	*ptr;

	if (!input_validataion(argc, argv))
	{
		putstr_fd("Invalid arguments\n", STDERR_FILENO);
		return (FALSE);
	}
	ptr = data(GET);
	ptr->num = philo_atoi(argv[1]);
	ptr->ttd = philo_atoi(argv[2]);
	ptr->tte = philo_atoi(argv[3]);
	ptr->tts = philo_atoi(argv[4]);
	if (argv[5])
		ptr->times_to_eat = philo_atoi(argv[5]);
	ptr->timers = (t_timer **)ft_calloc(data(GET)->num, sizeof(t_timer *));
	if (!ptr->timers)
		return (FALSE);
	return (TRUE);
}
