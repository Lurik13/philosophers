/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:41:48 by lribette          #+#    #+#             */
/*   Updated: 2024/01/24 14:58:19 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_routine(t_struct *m)
{
	int	i;

	i = 0;
	m->died = 0;
	while (i < m->nb_of_philos)
	{
		pthread_mutex_init(&m->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&m->ate, NULL);
	pthread_mutex_init(&m->sleeping, NULL);
	pthread_mutex_init(&m->thinking, NULL);
	pthread_mutex_init(&m->dying, NULL);
	i = 0;
	while (i < m->nb_of_philos)
	{
		pthread_create(&m->p[i].thread, NULL, routine, &(m->p[i]));
		i++;
	}
	pthread_create(&m->reaper, NULL, reaper_init, m);
}

void	destroy_routine(t_struct *m)
{
	int	i;

	pthread_join(m->reaper, NULL);
	i = 0;
	while (i < m->nb_of_philos)
	{
		pthread_join(m->p[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < m->nb_of_philos)
	{
		pthread_mutex_destroy(&m->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&m->ate);
	pthread_mutex_destroy(&m->sleeping);
	pthread_mutex_destroy(&m->thinking);
	pthread_mutex_destroy(&m->dying);
}

void	manage_routine(t_struct *m)
{
	init_routine(m);
	destroy_routine(m);
	printf("C'est la fin\n");
}

// mutex pour died && data race pour le thread de reaper
// prendre en compte pour un philo
// prendre en compte le nombre de fois qu'ils mangent