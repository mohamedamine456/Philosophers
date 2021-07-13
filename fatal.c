/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 09:28:21 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/21 10:25:09 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	fatal(const char *error)
{
	write(STDOUT_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
	write(STDOUT_FILENO, error, ft_strlen(error));
	write(STDOUT_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

void	fatal_arguments(void)
{
	write(STDOUT_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
	write(STDOUT_FILENO, ERROR_ARGS_MSG1, ft_strlen(ERROR_ARGS_MSG1));
	write(STDOUT_FILENO, ERROR_ARGS_MSG2, ft_strlen(ERROR_ARGS_MSG2));
	write(STDOUT_FILENO, ERROR_ARGS_MSG3, ft_strlen(ERROR_ARGS_MSG3));
	write(STDOUT_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}
