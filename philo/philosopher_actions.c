/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:49:59 by mlachheb          #+#    #+#             */
/*   Updated: 2021/07/16 12:17:04 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat_helper(t_philosopher *philosopher, int which)
{
	if (which == 1)
	{
		pthread_mutex_lock(philosopher->next->fork_mutex);
		philosopher->last_meal_time = get_day_time_ms();
		print_philosopher_action(philosopher, get_day_time_ms(), TK_FORK);
		philosopher->number_meals += 1;
		philosopher->status = EATS;
		print_philosopher_action(philosopher, get_day_time_ms(), EATING);
		ft_usleep(philosopher->data.time_to_eat * 1000);
		pthread_mutex_unlock(philosopher->next->fork_mutex);
	}
	else if (which == 2)
	{
		pthread_mutex_lock(philosopher->head->fork_mutex);
		print_philosopher_action(philosopher, get_day_time_ms(), TK_FORK);
		philosopher->last_meal_time = get_day_time_ms();
		philosopher->number_meals += 1;
		philosopher->status = EATS;
		print_philosopher_action(philosopher, get_day_time_ms(), EATING);
		ft_usleep(philosopher->data.time_to_eat * 1000);
		pthread_mutex_unlock(philosopher->head->fork_mutex);
	}
}

void	philosopher_eats(t_philosopher *philosopher)
{	
	if (philosopher != NULL && philosopher->next != NULL)
	{
		pthread_mutex_lock(philosopher->fork_mutex);
		print_philosopher_action(philosopher, get_day_time_ms(), TK_FORK);
		if (philosopher->next != NULL)
			eat_helper(philosopher, 1);
		else
			ft_usleep(philosopher->data.time_to_die * 1000 + 5000);
		pthread_mutex_unlock(philosopher->fork_mutex);
	}
	else if (philosopher != NULL)
	{
		pthread_mutex_lock(philosopher->fork_mutex);
		print_philosopher_action(philosopher, get_day_time_ms(), TK_FORK);
		if (philosopher->head != NULL)
			eat_helper(philosopher, 2);
		else
			ft_usleep(philosopher->data.time_to_die * 1000 + 5000);
		pthread_mutex_unlock(philosopher->fork_mutex);
	}
}

void	philosopher_sleeps(t_philosopher *philosopher)
{	
	if (philosopher != NULL)
	{
		print_philosopher_action(philosopher, get_day_time_ms(), SLEEPING);
		philosopher->status = SLEEPS;
		ft_usleep(philosopher->data.time_to_sleep * 1000);
	}
}

void	philosopher_thinks(t_philosopher *philosopher)
{	
	if (philosopher != NULL)
	{
		philosopher->status = THINKS;
		print_philosopher_action(philosopher, get_day_time_ms(), THINKING);
	}
}
