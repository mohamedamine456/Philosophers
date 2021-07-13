/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_prints.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 21:07:06 by mlachheb          #+#    #+#             */
/*   Updated: 2021/07/12 17:06:22 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_philosopher_action(t_philosopher *philosopher,
		long long real_time, char *action)
{
	pthread_mutex_lock(philosopher->write_mutex);
	ft_putnbr(real_time);
	ft_putstr(" ");
	ft_putnbr(philosopher->id);
	ft_putstr(" ");
	ft_putstr(action);
	ft_putstr("\n");
	pthread_mutex_unlock(philosopher->write_mutex);
}

void	all_ate(pthread_mutex_t *write_mutex, long long must_eat_number)
{
	pthread_mutex_lock(write_mutex);
	ft_putstr("All Philosophers ate at least ");
	ft_putnbr(must_eat_number);
	ft_putstr(" times\n");
}

void	philo_died(pthread_mutex_t *write_mutex, int id, long long real_time)
{
	pthread_mutex_lock(write_mutex);
	ft_putnbr(real_time);
	ft_putstr(" ");
	ft_putnbr(id);
	ft_putstr(" died");
	ft_putstr("\n");
}
