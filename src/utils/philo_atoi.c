/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:58:03 by svereten          #+#    #+#             */
/*   Updated: 2025/03/31 14:40:19 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static uint32_t	numlen(uint32_t num)
{
	uint32_t	res;

	res = 1;
	while (num > 9)
	{
		res++;
		num /= 10;
	}
	return (res);
}

static void	itoa_worker(char *res, uint32_t num)
{
	uint32_t	i;

	if (num < 10)
	{
		i = 0;
		while (res[i])
			i++;
		res[i] = num + '0';
		return ;
	}
	itoa_worker(res, num / 10);
	itoa_worker(res, num % 10);
}

static char	*philo_itoa(uint32_t num)
{
	char		*res;

	res = (char *)ft_calloc(numlen(num) + 1, sizeof(char));
	if (!res)
		return (NULL);
	itoa_worker(res, num);
	return (res);
}

t_bool	philo_atoi(char *str, uint32_t *num)
{
	char		*itoa_res;
	uint8_t		i;

	if (!num)
		return (FALSE);
	*num = 0;
	i = 0;
	while (str[i])
	{
		*num = *num * 10 + (str[i] - '0');
		i++;
	}
	itoa_res = philo_itoa(*num);
	if (!itoa_res)
		return (FALSE);
	if (ft_strcmp(str, itoa_res) != 0)
		return (free(itoa_res), FALSE);
	return (free(itoa_res), TRUE);
}
