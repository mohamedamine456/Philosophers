/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:30:46 by mlachheb          #+#    #+#             */
/*   Updated: 2021/07/16 12:15:27 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*supervisor_life(void *supervisor)
{
	t_supervisor	superv;

	superv = *((t_supervisor *)supervisor);
	while (TRUE)
	{
		if (!check_death_time(superv.philosophers))
		{
			return (NULL);
		}
		else if (!check_must_eat_number(superv.philosophers))
		{
			pthread_mutex_lock(superv.write_mutex);
			return (NULL);
		}
		usleep(100);
	}
}

int	check_death_time(t_philosopher *philosophers)
{
	t_philosopher	*tmp;
	long long		actual_time;

	tmp = philosophers;
	actual_time = get_day_time_ms();
	while (tmp != NULL)
	{
		if (tmp->last_meal_time != 0 && tmp->status != EATS
			&& actual_time - tmp->last_meal_time > tmp->data.time_to_die)
		{
			philo_died(tmp->write_mutex, tmp->id, actual_time);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int	check_must_eat_number(t_philosopher *philosophers)
{
	t_philosopher	*tmp;

	tmp = philosophers;
	while (tmp != NULL)
	{
		if (tmp->data.must_eat_number == -1)
			return (1);
		else if (tmp->number_meals < tmp->data.must_eat_number)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
