/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:57:14 by lribette          #+#    #+#             */
/*   Updated: 2024/01/25 11:14:17 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating(t_philos *p)
{
	long	current;

	pthread_mutex_lock(&p->m->forks[p->num - 1]);
	pthread_mutex_lock(&p->m->forks[p->num % p->m->nb_of_philos]);
	pthread_mutex_lock(&p->m->dying);
	if (p->m->died)
	{
		pthread_mutex_unlock(&p->m->dying);
		pthread_mutex_unlock(&p->m->forks[p->num - 1]);
		pthread_mutex_unlock(&p->m->forks[p->num % p->m->nb_of_philos]);
		return (1);
	}
	pthread_mutex_unlock(&p->m->dying);
	current = get_time(p->m);
	printf("%ld %d %s", current, p->num, FORK);
	printf("%ld %d %s", current, p->num, EATING);
	pthread_mutex_lock(&p->m->ate);
	p->last_meal = get_time(p->m);
	pthread_mutex_unlock(&p->m->ate);
	usleep(p->m->time_to_eat * 1000);
	pthread_mutex_unlock(&p->m->forks[p->num - 1]);
	pthread_mutex_unlock(&p->m->forks[p->num % p->m->nb_of_philos]);
	return (0);
}

int	is_sleeping(t_philos *p)
{
	long	current;

	pthread_mutex_lock(&p->m->dying);
	if (!p->m->died)
	{
		pthread_mutex_unlock(&p->m->dying);
		current = get_time(p->m);
		pthread_mutex_lock(&p->m->sleeping);
		pthread_mutex_lock(&p->m->dying);
		if (p->m->died)
		{
			pthread_mutex_unlock(&p->m->dying);
			pthread_mutex_unlock(&p->m->sleeping);
			return (1);
		}
		pthread_mutex_unlock(&p->m->dying);
		printf("%ld %d %s", current, p->num, SLEEPING);
		pthread_mutex_unlock(&p->m->sleeping);
		usleep(p->m->time_to_sleep * 1000);
		current = get_time(p->m);
	}
	else
		pthread_mutex_unlock(&p->m->dying);
	return (0);
}

int	is_thinking(t_philos *p)
{
	long	current;

	pthread_mutex_lock(&p->m->dying);
	if (!p->m->died)
	{
		pthread_mutex_unlock(&p->m->dying);
		current = get_time(p->m);
		pthread_mutex_lock(&p->m->thinking);
		pthread_mutex_lock(&p->m->dying);
		if (p->m->died)
		{
			pthread_mutex_unlock(&p->m->dying);
			pthread_mutex_unlock(&p->m->thinking);
			return (1);
		}
		pthread_mutex_unlock(&p->m->dying);
		printf("%ld %d %s", current, p->num, THINKING);
		pthread_mutex_unlock(&p->m->thinking);
		usleep(0);
	}
	else
		pthread_mutex_unlock(&p->m->dying);
	return (0);
}

void	*routine(void *data)
{
	t_philos	*p;
	int			i;

	p = (t_philos *) data;
	i = 0;
	if (p->num % 2 == 0)
		usleep(1);
	while (1)
	{
		/*if (p->m->nb_of_times_eating && i == p->m->nb_of_times_eating)
		{
			//pthread_mutex_lock(&p->m->activity);
			p->active = 0;
			//pthread_mutex_unlock(&p->m->activity);
			break ;
		}*/
		i++;
		if (eating(p))
			break ;
		if (is_sleeping(p))
			break ;
		if (is_thinking(p))
			break ;
	}
	return (NULL);
}

// prendre en compte pour un philo