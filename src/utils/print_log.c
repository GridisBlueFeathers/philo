/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:28:20 by svereten          #+#    #+#             */
/*   Updated: 2025/03/29 12:32:04 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	print_log(t_print op, uint32_t idx, t_start_ts *start, t_state *state)
{
	if (state_get_finish(state))
		return ;
	if (op == FORK)
		printf(FORK_LOG, start_get_timestamp(start), idx + 1);
	if (op == EATING)
		printf(EATING_LOG, start_get_timestamp(start), idx + 1);
	if (op == SLEEPING)
		printf(SLEEPNG_LOG, start_get_timestamp(start), idx + 1);
	if (op == THINKING)
		printf(THINKING_LOG, start_get_timestamp(start), idx + 1);
}
