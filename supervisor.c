/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:30:46 by mlachheb          #+#    #+#             */
/*   Updated: 2021/07/12 17:07:28 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*supervisor_life(void *supervisor)
{
	t_supervisor	superv;
	t_philosopher	*tmp_philos;
	long long		act_time;

	superv = *((t_supervisor *)supervisor);
	while (TRUE)
	{
		tmp_philos = superv.philosophers;
		act_time = get_day_time_ms();
		while (tmp_philos != NULL)
		{
			if (tmp_philos->last_meal_time != 0 && act_time
				- tmp_philos->last_meal_time > tmp_philos->data.time_to_die)
			{
				philo_died(tmp_philos->write_mutex, tmp_philos->id, act_time);
				return (NULL);
			}
			else if (!check_must_eat_number(superv.philosophers))
			{
				all_ate(superv.write_mutex, tmp_philos->data.must_eat_number);
				return (NULL);
			}
			tmp_philos = tmp_philos->next;
		}
	}
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
