/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:46:57 by svereten          #+#    #+#             */
/*   Updated: 2025/03/03 11:02:25 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

#if DEBUG

int32_t	main(int argc, char **argv)
{
	if (!data(GET))
	{
		putstr_fd("data initialization failed\n", STDERR_FILENO);
		return (1);
	}
	if (!input_processing(argc, argv))
		return (1);
	dprintf(STDERR_FILENO, "\x1b[34m""Philos num: %d\n""\x1b[0m", data(GET)->num);
	dprintf(STDERR_FILENO, "\x1b[34m""Philos ttd: %d\n""\x1b[0m", data(GET)->ttd);
	dprintf(STDERR_FILENO, "\x1b[34m""Philos tte: %d\n""\x1b[0m", data(GET)->tte);
	dprintf(STDERR_FILENO, "\x1b[34m""Philos tts: %d\n""\x1b[0m", data(GET)->tts);
	dprintf(STDERR_FILENO, "\x1b[34m""Times to eat: %d\n""\x1b[0m", data(GET)->times_to_eat);
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
