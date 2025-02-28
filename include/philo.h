/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:45:34 by svereten          #+#    #+#             */
/*   Updated: 2025/02/28 15:55:05 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

#include <stdint.h>
#include <unistd.h>

typedef	enum	e_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef	struct	s_data
{
	int32_t num;
	int32_t ttd;
	int32_t tts;
	int32_t tte;


}	t_data;

// Utils
//
int32_t		putstr_fd(char *str, int fd);
uint32_t	ft_strlen(char *str);
t_bool		ft_isdigit(char c);
t_bool		str_is_number(char *str);

#endif
