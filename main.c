/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:37:55 by lribette          #+#    #+#             */
/*   Updated: 2024/01/25 11:16:52 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		m->p[i].active = 1;
		m->p[i].m = m;
		i++;
	}
	return (1);
}

int	ft_error(t_struct *m, int argc)
{
	if (!m->nb_of_philos || m->nb_of_philos > 200)
		printf("%sWrong number of philosophers%s\n", RED_ERROR, RESET);
	else if (!m->time_to_die)
		printf("%sWrong time to die%s\n", RED_ERROR, RESET);
	else if (!m->time_to_eat)
		printf("%sWrong time to eat%s\n", RED_ERROR, RESET);
	else if (!m->time_to_sleep)
		printf("%sWrong time to sleep%s\n", RED_ERROR, RESET);
	else if (argc == 6 && m->nb_of_times_eating < 0)
		printf("%sWrong number of times eating%s\n", RED_ERROR, RESET);
	/*else if (argc == 5)
		m->nb_of_times_eating = 0;*/
	else
		return (0);
	return (1);
}

void	ft_free(t_struct *m)
{
	free(m->p);
	free(m->forks);
}

void	init_params(t_struct *m, char **argv)
{
	m->nb_of_philos = ft_atoi(argv[1]);
	m->time_to_die = ft_atoi(argv[2]);
	m->time_to_eat = ft_atoi(argv[3]);
	m->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		m->nb_of_times_eating = ft_atoi(argv[5]);
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
		init_params(&m, argv);
		if (!ft_error(&m, argc))
		{
			ft_start(&m);
			manage_routine(&m);
			ft_free(&m);
		}
	}
}
