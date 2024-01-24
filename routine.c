/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:57:14 by lribette          #+#    #+#             */
/*   Updated: 2024/01/24 09:11:50 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philos *p)
{
	long	current;

	pthread_mutex_lock(&p->m->forks[p->num - 1]);
	pthread_mutex_lock(&p->m->forks[p->num % p->m->nb_of_philos]);
	current = get_time(p->m);
	printf("%ld %d %s", current, p->num, FORK);
	printf("%ld %d %s", current, p->num, EATING);
	usleep(p->m->time_to_eat * 1000);
	pthread_mutex_unlock(&p->m->forks[p->num - 1]);
	pthread_mutex_unlock(&p->m->forks[p->num % p->m->nb_of_philos]);
	//printf("%d", p->m->time_to_eat);
	p->last_meal = get_time(p->m);
	/*printf("Gauche : %d\n", p->num);
	if ((p->num + 1) % (p->m->nb_of_philos + 1) == 0)
		printf("Droite : 1\n");
	else
		printf("Droite : %d\n", (p->num + 1) % (p->m->nb_of_philos + 1));*/
}

void	is_sleeping(t_philos *p)
{
	long	current;

	pthread_mutex_lock(&p->m->sleeping);
	current = get_time(p->m);
	printf("%ld %d %s", current, p->num, SLEEPING);
	pthread_mutex_unlock(&p->m->sleeping);
	usleep(p->m->time_to_sleep * 1000);
	current = get_time(p->m);
	if (current - p->last_meal > p->m->time_to_die)
		printf("%sALERTE%s", RED_ERROR, RESET);
}

void	is_thinking(t_philos *p)
{
	long	current;

	pthread_mutex_lock(&p->m->thinking);
	current = get_time(p->m);
	printf("%ld %d %s", current, p->num, THINKING);
	pthread_mutex_unlock(&p->m->thinking);
	usleep(0);
}

void	*routine(void *data)
{
	t_philos	*p;

	p = (t_philos *) data;
	if (p->num % 2 == 0)
	{
		//printf("%d\n", p->num);
		usleep(p->m->time_to_eat);
	}
	while (1)
	{
		eating(p);
		is_sleeping(p);
		is_thinking(p);
	}
	//printf("[%ld]", get_time(p->m));
	return (NULL);
}

void	launch_routine(t_struct *m)
{
	int	i;

	i = 0;
	while (i < m->nb_of_philos)
	{
		pthread_mutex_init(&m->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&m->sleeping, NULL);
	pthread_mutex_init(&m->thinking, NULL);
	i = 0;
	while (i < m->nb_of_philos)
	{
		pthread_create(&m->p[i].thread, NULL, routine, &(m->p[i]));
		i++;
	}
	i = 0;
	while (i < m->nb_of_philos)
	{
		pthread_join(m->p[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < m->nb_of_philos)
	{
		pthread_mutex_destroy(m->forks);
		i++;
	}
	pthread_mutex_destroy(&m->sleeping);
	pthread_mutex_destroy(&m->thinking);
	printf("C'est la fin\n");
}
