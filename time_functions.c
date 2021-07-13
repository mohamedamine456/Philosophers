/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:05:38 by mlachheb          #+#    #+#             */
/*   Updated: 2021/07/12 14:46:33 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_day_time_ms(void)
{
	struct timeval	day_time;
	long long		time_ms;

	gettimeofday(&day_time, NULL);
	time_ms = day_time.tv_sec * 1000 + day_time.tv_usec / 1000;
	return (time_ms);
}

long long	get_day_time_us(void)
{
	struct timeval	day_time;
	long long		time_us;

	gettimeofday(&day_time, NULL);
	time_us = day_time.tv_sec * 1000000 + day_time.tv_usec;
	return (time_us);
}

void	ft_usleep(long long time_to_sleep)
{
	long long	begin;
	long long	end;

	begin = get_day_time_us();
	while (TRUE)
	{
		end = get_day_time_us();
		if (end - begin >= time_to_sleep)
			break ;
		if (end - begin > 10)
			usleep(8);
	}
}
