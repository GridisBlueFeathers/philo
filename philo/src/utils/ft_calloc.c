/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:41:12 by svereten          #+#    #+#             */
/*   Updated: 2025/03/04 14:11:05 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <string.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	res_size;

	res_size = nmemb * size;
	if (!nmemb || !size || res_size / nmemb != size)
		return (NULL);
	res = malloc(res_size);
	if (!res)
		return (NULL);
	memset(res, 0, res_size);
	return (res);
}
