/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:57:14 by lribette          #+#    #+#             */
/*   Updated: 2024/01/22 20:36:30 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data)
{
	int			i;
	t_struct	*m;

	i = 0;
	m = (t_struct *) data;
	int	j = 0;
	pthread_mutex_lock(&m->mutex);
	while (m->forks[i])
	{
		
		printf("Ma fourchette : %d\n", m->forks[i]);
		i++;
		j++;
	}
	printf("j = %d\n", j);
	pthread_mutex_unlock(&m->mutex);
	return (NULL);
}

void	launch_routine(t_struct *m)
{
	int	i;

	i = 0;
	pthread_mutex_init(&m->mutex, NULL);
	while (i < m->nb_of_philos)
	{
		pthread_create(&m->philos[i].thread, NULL, routine, (void *)m);
		i++;
	}
	i = 0;
	while (i < m->nb_of_philos)
	{
		pthread_join(m->philos[i].thread, NULL);
		i++;
	}
	pthread_mutex_destroy(&m->mutex);
}
