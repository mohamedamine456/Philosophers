/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:26:34 by mlachheb          #+#    #+#             */
/*   Updated: 2021/07/13 17:02:34 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philosopher	*philos;
	t_common_data	data;
	int				number_philos;

	if (argc < 5 || argc > 6)
		fatal_arguments();
	else if (!check_argv(argv + 1))
	{
		data = read_data(argv + 1, &number_philos);
		if (!check_value(data, number_philos))
		{
			philos = init_philosophers(data, number_philos);
			create_threads(philos, number_philos);
		}
	}
	return (0);
}
