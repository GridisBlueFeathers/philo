/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:27:33 by svereten          #+#    #+#             */
/*   Updated: 2025/02/28 15:29:45 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdint.h>

uint32_t	ft_strlen(char *str)
{
	uint32_t	res;

	res = 0;
	while (str[res])
		res++;
	return (res);
}
