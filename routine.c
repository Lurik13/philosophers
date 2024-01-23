/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:57:14 by lribette          #+#    #+#             */
/*   Updated: 2024/01/23 14:33:11 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data)
{
	t_philos	*philo;

	philo = (t_philos *) data;
	/*if (!philo->structure)
		printf("%sJe n'ai pas acces a structure%s\n", RED, RESET);*/
	printf("ca marche ? %d\n", philo->structure->nb_of_philos);
	printf("%sJe suis le philo %d%s\n", GREEN, philo->num, RESET);
	/*pthread_mutex_lock(m->forks[philo->num - 1]);
	printf("Ma fourchette : %d\n", philo->num);
	pthread_mutex_unlock(m->forks[philo->num - 1]);*/
	return (NULL);
}

void	launch_routine(t_struct *m)
{
	int	i;
	//pthread_mutex_t	*forks;

	i = 0;
	//forks = malloc(m->nb_of_philos * sizeof(pthread_mutex_t));
	/*if (!forks)
		printf(RED_ERROR);*/
	/*if (!m->p[0].structure)
		printf("%sJe n'ai pas acces a structure%s\n", RED, RESET);*/
	pthread_mutex_init(m->forks, NULL);
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
	pthread_mutex_destroy(m->forks);
}
