/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:54:04 by mlachheb          #+#    #+#             */
/*   Updated: 2021/07/13 16:59:33 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define ERROR_MSG "ERROR:\n"
# define ERROR_ARGS_MSG1 "./philosophers number_of_philosophers"
# define ERROR_ARGS_MSG2 " time_to_die time_to_eat time_to_sleep"
# define ERROR_ARGS_MSG3 " [number_of_times_each_philosopher_must_eat]"
# define BAD_ARG "All arguments must be positif integers.(no positif sign)!"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define THINKING "is thinking"
# define TK_FORK "has taken a fork"
# define TRUE 1
# define FALSE 0

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_common_data
{
	long long			time_to_die;
	long long			time_to_eat;
	long long			time_to_sleep;
	long				must_eat_number;
}				t_common_data;

typedef struct s_philosopher
{
	int						id;
	t_common_data			data;
	long long				last_meal_time;
	long long				number_meals;
	pthread_mutex_t			*fork_mutex;
	pthread_t				philo_thread;
	pthread_mutex_t			*write_mutex;
	struct s_philosopher	*next;
	struct s_philosopher	*head;
}							t_philosopher;

typedef struct s_supervisor
{
	pthread_t		superv_thread;
	t_philosopher	*philosophers;
	pthread_mutex_t	*write_mutex;
}							t_supervisor;

/*
 * libft_functions.c prototypes
 */

int							ft_strlen(const char *str);
long long					ft_atoi(const char *str);
void						ft_putnbr(long long n);
void						ft_putstr(const char *str);

/*
 * fatal.c prototypes
 */

void						fatal(const char *error);
void						fatal_arguments(void);

/*
 * read_check_args.c prototypes
 */

t_common_data				read_data(char **argv, int *number_philos);
int							check_argv(char **args);
int							check_value(t_common_data data, int number_philos);
void						print_data(t_common_data data);
void						print_philosophers(t_philosopher *philos);

/*
 * philosophers_functions.c prototypes
 */

t_philosopher				*init_philosophers(t_common_data data,
								int number_philos);
t_philosopher				*new_philosopher(t_common_data data);
void						add_back_philosopher(t_philosopher **philos,
								t_philosopher *new);
void						clear_philosophers(t_philosopher **philos);
t_philosopher				*last_philosopher(t_philosopher *philos);

/*
 * philosopher_prints.c prototypes
 */

void						print_philosopher_action(t_philosopher *philo,
								long long real_time, char *action);
void						all_ate(pthread_mutex_t *write_mutex,
								long long must_eat_number);
void						philo_died(pthread_mutex_t *write_mutex, int id,
								long long real_time);

/*
 * time_functions.c prototypes
 */

long long					get_day_time_ms(void);
long long					get_day_time_us(void);
void						ft_usleep(long long time_to_sleep);

/*
 * threads_functions.c prototypes
 */

void						create_threads(t_philosopher *philos,
								int number_philos);
void						*philosopher_life(void *life_data);
void						detach_philosophers(t_philosopher *philos);

/*
 * philosopher_actions.c prototypes
 */

void						philosopher_eats(t_philosopher *philosopher);
void						philosopher_sleeps(t_philosopher *philosopher);
void						philosopher_thinks(t_philosopher *philosopher);

/*
 * supervisor.c prototypes
 */

void						*supervisor_life(void *supervisor);
int							check_must_eat_number(t_philosopher *philosophers);

#endif
