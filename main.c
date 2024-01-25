/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:37:55 by lribette          #+#    #+#             */
/*   Updated: 2024/01/25 19:19:44 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int			i;
	long long	number;

	i = 0;
	number = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		number = number * 10 + str[i] - 48;
		if (number > 2147483647 || number < -2147483648)
			return (-1);
		i++;
	}
	return ((int)number);
}

int	ft_start(t_struct *m)
{
	int	i;

	i = 0;
	m->p = malloc(m->nb_of_philos * sizeof(t_philos));
	m->forks = malloc(m->nb_of_philos * sizeof(pthread_mutex_t));
	if (!m->p || !m->forks)
		return (0);
	while (i < m->nb_of_philos)
	{
		m->p[i].num = i + 1;
		m->p[i].last_meal = 0;
		m->p[i].nb_of_times_eaten_p = 0;
		m->p[i].m = m;
		i++;
	}
	return (1);
}

int	ft_error(t_struct *m, int argc)
{
	printf("");
	if (m->nb_of_philos <= 0 || m->nb_of_philos > 200)
		printf("%sWrong number of philosophers%s\n", RED_ERROR, RESET);
	else if (m->time_to_die <= 0)
		printf("%sWrong time to die%s\n", RED_ERROR, RESET);
	else if (m->time_to_eat <= 0)
		printf("%sWrong time to eat%s\n", RED_ERROR, RESET);
	else if (m->time_to_sleep <= 0)
		printf("%sWrong time to sleep%s\n", RED_ERROR, RESET);
	else if (argc == 6 && m->nb_of_times_eating <= 0)
		printf("%sWrong number of times eating%s\n", RED_ERROR, RESET);
	else
		return (0);
	return (1);
}

void	init_params(t_struct *m, int argc, char **argv)
{
	m->nb_of_philos = ft_atoi(argv[1]);
	m->time_to_die = ft_atoi(argv[2]);
	m->time_to_eat = ft_atoi(argv[3]);
	m->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		m->nb_of_times_eating = ft_atoi(argv[5]);
	else
		m->nb_of_times_eating = -1;
	gettimeofday(&m->start, NULL);
}

int	main(int argc, char **argv)
{
	t_struct	m;
	int			i;

	i = 0;
	if (!(argc == 5 || argc == 6))
		printf("Wrong number of arguments\n");
	else
	{
		init_params(&m, argc, argv);
		if (!ft_error(&m, argc))
		{
			ft_start(&m);
			manage_routine(&m);
			free(m.p);
			free(m.forks);
		}
	}
}
