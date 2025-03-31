/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:12:08 by svereten          #+#    #+#             */
/*   Updated: 2025/03/31 11:58:31 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <unistd.h>

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

t_bool	input_processing(int32_t argc, char **argv, t_data *data)
{
	if (!input_validataion(argc, argv))
		return (putstr_fd("Invalid arguments\n", STDERR_FILENO), FALSE);
	if (!philo_atoi(argv[1], &data->num)
		|| !philo_atoi(argv[2], &data->ttd)
		|| !philo_atoi(argv[3], &data->tte)
		|| !philo_atoi(argv[4], &data->tts))
		return (putstr_fd("Invalid arguments\n", STDERR_FILENO), FALSE);
	if (argv[5] && !philo_atoi(argv[5], &data->times_to_eat))
		return (putstr_fd("Invalid arguments\n", STDERR_FILENO), FALSE);
	if (!data->num || !data->ttd || !data->tte || !data->tts)
		return (putstr_fd("Invalid arguments\n", STDERR_FILENO), FALSE);
	if (argv[5] && !data->times_to_eat)
		return (putstr_fd("Invalid arguments\n", STDERR_FILENO), FALSE);
	return (TRUE);
}
