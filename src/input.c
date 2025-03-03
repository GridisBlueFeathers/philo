/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:01:15 by svereten          #+#    #+#             */
/*   Updated: 2025/03/03 11:01:42 by svereten         ###   ########.fr       */
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
	if (!input_validataion(argc, argv))
	{
		putstr_fd("Invalid arguments\n", STDERR_FILENO);
		return (FALSE);
	}
	data(GET)->num = philo_atoi(argv[1]);
	data(GET)->ttd = philo_atoi(argv[2]);
	data(GET)->tte = philo_atoi(argv[3]);
	data(GET)->tts = philo_atoi(argv[4]);
	if (argv[5])
		data(GET)->times_to_eat = philo_atoi(argv[5]);
	return (TRUE);
}
