/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:37:55 by lribette          #+#    #+#             */
/*   Updated: 2024/01/23 14:35:45 by lribette         ###   ########.fr       */
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
		m->p[i].structure = m;
		printf("[%ld] ", get_time(m));
		if (i % 6 == 0)
			printf("%s", RED);
		if (i % 6 == 1)
			printf("%s", ORANGE);
		if (i % 6 == 2)
			printf("%s", YELLOW);
		if (i % 6 == 3)
			printf("%s", GREEN);
		if (i % 6 == 4)
			printf("%s", BLUE);
		if (i % 6 == 5)
			printf("%s", PURPLE);
		printf("%d%s", m->p[i].num, RESET);
		if (i % 3 == 0)
			printf("%s", EATING);
		if (i % 3 == 1)
			printf("%s", SLEEPING);
		if (i % 3 == 2)
			printf("%s", THINKING);
		usleep(100);
		//printf("i = %d, [%d][%d]\n", i, m->p[i].num, m->forks[i]);
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
	else if (argc == 6 && !m->nb_of_time_eating)
		printf("%sWrong number of times eating%s\n", RED_ERROR, RESET);
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
		m->nb_of_time_eating = ft_atoi(argv[5]);
	gettimeofday(&m->start, NULL);
	//printf("time = %ld", m->start.tv_sec * 1000 + m->start.tv_usec / 1000);
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
			launch_routine(&m);
			ft_free(&m);
		}
	}
}
