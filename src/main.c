/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:46:57 by svereten          #+#    #+#             */
/*   Updated: 2025/03/13 11:24:31 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

#if DEBUG

int32_t	main(int argc, char **argv)
{
	if (!data(GET))
	{
		putstr_fd("philo: data initialization failed\n", STDERR_FILENO);
		return (1);
	}
	if (!input_processing(argc, argv))
		return (1);
	dprintf(STDERR_FILENO, BLUE"Philos num: %d\n"RESET, data(GET)->num);
	dprintf(STDERR_FILENO, BLUE"Philos ttd: %ld\n"RESET, data(GET)->ttd);
	dprintf(STDERR_FILENO, BLUE"Philos tte: %d\n"RESET, data(GET)->tte);
	dprintf(STDERR_FILENO, BLUE"Philos tts: %d\n"RESET, data(GET)->tts);
	dprintf(STDERR_FILENO, BLUE"Times to eat: %d\n"RESET, data(GET)->times_to_eat);
	if (!create_nodes())
		return (1);
	simulation_init();
	track_finish();
	join_threads();
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
