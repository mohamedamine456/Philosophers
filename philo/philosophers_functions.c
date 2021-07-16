/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:26:17 by mlachheb          #+#    #+#             */
/*   Updated: 2021/07/15 12:11:53 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philosopher	*init_philosophers(t_common_data data, int number_philos)
{
	t_philosopher	*philos;
	t_philosopher	*tmp;
	int				i;
	pthread_mutex_t	*write_mutex;

	philos = NULL;
	i = 0;
	write_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(write_mutex, NULL);
	while (i < number_philos)
	{
		tmp = new_philosopher(data);
		tmp->id = i + 1;
		tmp->write_mutex = write_mutex;
		add_back_philosopher(&philos, tmp);
		i++;
	}
	return (philos);
}

t_philosopher	*new_philosopher(t_common_data data)
{
	t_philosopher	*new;

	new = (t_philosopher *)malloc(sizeof(t_philosopher));
	new->id = 0;
	new->data.time_to_die = data.time_to_die;
	new->data.time_to_eat = data.time_to_eat;
	new->data.time_to_sleep = data.time_to_sleep;
	new->number_meals = 0;
	new->last_meal_time = 0;
	new->data.must_eat_number = data.must_eat_number;
	new->fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(new->fork_mutex, NULL);
	new->next = NULL;
	new->head = NULL;
	return (new);
}

void	add_back_philosopher(t_philosopher **philos, t_philosopher *new)
{
	t_philosopher	*philo;

	philo = *philos;
	if (philo == NULL)
	{
		*philos = new;
	}
	else
	{
		philo = last_philosopher(*philos);
		philo->next = new;
		new->head = *philos;
	}
}

void	clear_philosophers(t_philosopher **philos)
{
	t_philosopher	*philos1;
	t_philosopher	*philos2;

	philos1 = *philos;
	if (philos1 != NULL)
		free(philos1->write_mutex);
	while (philos1 != NULL)
	{
		philos2 = philos1->next;
		philos1->head = NULL;
		free(philos1->fork_mutex);
		free(philos1);
		philos1 = philos2;
	}
	philos = NULL;
}

t_philosopher	*last_philosopher(t_philosopher *philos)
{
	if (philos != NULL)
	{
		while (philos->next != NULL)
			philos = philos->next;
	}
	return (philos);
}
