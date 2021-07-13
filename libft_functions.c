/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 10:11:50 by mlachheb          #+#    #+#             */
/*   Updated: 2021/07/12 20:44:21 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
 * ft_strlen: to calculate size of string
 */

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*
 * ft_atoi: transfer a string to number
 * number: helper function for ft_atoi
 */

long long	number(const char *str, int neg)
{
	int			i;
	long long	res;

	i = 0;
	res = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - 48;
		if (res > 4294967295)
		{
			if (neg < 0)
				return (0);
			else
				return (-1);
		}
		i++;
	}
	return (res * neg);
}

long long	ft_atoi(const char *str)
{
	int				i;
	int				neg;
	long long		res;

	i = 0;
	neg = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	res = number(str + i, neg);
	return (res);
}

/*
 * ft_putnbr: to print a number
 */

void	ft_putnbr(long long nbs)
{
	int		m;
	char	c;

	m = 0;
	if (nbs < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		nbs *= -1;
	}
	if (nbs >= 0 && nbs <= 9)
	{
		c = nbs + 48;
		write(STDOUT_FILENO, &c, 1);
	}
	else
	{
		m = nbs % 10;
		nbs /= 10;
		ft_putnbr(nbs);
		c = m + 48;
		write(STDOUT_FILENO, &c, 1);
	}
}

void	ft_putstr(const char *str)
{
	if (str != NULL)
	{
		write(STDOUT_FILENO, str, ft_strlen(str));
	}
}
