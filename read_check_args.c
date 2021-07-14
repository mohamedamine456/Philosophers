/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 10:43:58 by mlachheb          #+#    #+#             */
/*   Updated: 2021/07/14 15:34:43 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_common_data	read_data(char **argv, int *number_philos)
{
	t_common_data	data;

	*number_philos = ft_atoi(argv[0]);
	data.time_to_die = ft_atoi(argv[1]);
	data.time_to_eat = ft_atoi(argv[2]);
	data.time_to_sleep = ft_atoi(argv[3]);
	data.must_eat_number = -1;
	if (argv[4] != NULL)
	{
		data.must_eat_number = ft_atoi(argv[4]);
		if (data.must_eat_number == 0)
			fatal(BAD_ARG);
	}
	return (data);
}

int	check_argv(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args != NULL && args[i] != NULL)
	{
		j = 0;
		while (args[i][j] != '\0')
		{
			if (args[i][j] > '9' || args[i][j] < '0')
				fatal(BAD_ARG);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_value(t_common_data data, int number_philos)
{
	if (number_philos <= 0)
		fatal(BAD_ARG);
	else if (data.time_to_die <= 0 || data.time_to_eat <= 0
		|| data.time_to_sleep <= 0)
		fatal(BAD_ARG);
	return (0);
}

void	print_data(t_common_data data)
{
	ft_putstr("TIME TO DIE: ");
	ft_putnbr(data.time_to_die);
	ft_putstr("\n");
	ft_putstr("TIME TO EAT: ");
	ft_putnbr(data.time_to_eat);
	ft_putstr("\n");
	ft_putstr("TIME TO SLEEP: ");
	ft_putnbr(data.time_to_sleep);
	ft_putstr("\n");
	if (data.must_eat_number > LONG_MAX)
	{
		ft_putstr("Number of Times each Philosopher must Eat: ");
		ft_putnbr(data.must_eat_number);
		ft_putstr("\n");
	}
}

void	print_philosophers(t_philosopher *philos)
{
	t_philosopher	*tmp;

	tmp = philos;
	while (tmp != NULL)
	{
		ft_putstr("PHILOSPHER ID: ");
		ft_putnbr(tmp->id);
		ft_putstr("\n");
		print_data(philos->data);
		ft_putstr("----------------------------------------\n");
		tmp = tmp->next;
	}
}
