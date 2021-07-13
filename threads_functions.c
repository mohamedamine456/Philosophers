/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:55:43 by mlachheb          #+#    #+#             */
/*   Updated: 2021/07/12 20:46:42 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	create_threads(t_philosopher *philos, int number_philos)
{
	int				i;
	t_philosopher	*tmp;
	t_supervisor	supervisor;

	i = 0;
	tmp = philos;
	supervisor.philosophers = philos;
	supervisor.write_mutex = philos->write_mutex;
	if (pthread_create(&(supervisor.superv_thread), NULL,
			supervisor_life, &supervisor) != 0)
		fatal("create supervisor thread failed!");
	while (i < number_philos)
	{
		usleep(50);
		if (pthread_create(&(tmp->philo_thread), NULL,
				philosopher_life, tmp) != 0)
			fatal("create philosophers thread failed!");
		i++;
		tmp = tmp->next;
	}	
	if (pthread_join(supervisor.superv_thread, NULL) != 0)
		fatal("join supervisor thread failed!");
	detach_philosophers(philos);
	clear_philosophers(&philos);
}

void	*philosopher_life(void *philos)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)philos;
	philosopher->last_meal_time = get_day_time_ms();
	while (TRUE)
	{
		philosopher_eats(philosopher);
		philosopher_sleeps(philosopher);
		philosopher_thinks(philosopher);
	}
	return (NULL);
}

void	detach_philosophers(t_philosopher *philos)
{
	t_philosopher	*tmp;

	tmp = philos;
	while (tmp != NULL)
	{
		pthread_mutex_destroy(tmp->write_mutex);
		pthread_detach(tmp->philo_thread);
		tmp = tmp->next;
	}
}