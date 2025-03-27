/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:46:57 by svereten          #+#    #+#             */
/*   Updated: 2025/03/25 13:31:12 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <string.h>

#if DEBUG

int32_t	main(int argc, char **argv)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	if (!data_init(&data, argc, argv))
		return (data_free(&data), 1);
	dprintf(STDERR_FILENO, BLUE"Philos num: %u\n"RESET, data.num);
	dprintf(STDERR_FILENO, BLUE"Philos ttd: %u\n"RESET, data.ttd);
	dprintf(STDERR_FILENO, BLUE"Philos tte: %u\n"RESET, data.tte);
	dprintf(STDERR_FILENO, BLUE"Philos tts: %u\n"RESET, data.tts);
	dprintf(STDERR_FILENO, BLUE"Times to eat: %u\n"RESET, data.times_to_eat);
	simulation_init(&data);
	join_threads(&data);
	return (data_free(&data), 0);
	track_finish(&data);
}
#else

int32_t	main(int argc, char **argv)
{
	if (!data(GET))
	{
		putstr_fd("data initialization failed\n", STDERR_FILENO);
		return (1);
	}
	if (!input_processing(argc, argv))
		return (1);
}
#endif
