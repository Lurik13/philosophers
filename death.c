/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:22:50 by lribette          #+#    #+#             */
/*   Updated: 2024/01/25 10:36:45 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_activity(t_struct *m)
{
	int	i;
	int	nb_of_inactives;

	i = 0;
	nb_of_inactives = 0;
	while (i < m->nb_of_philos)
	{
		pthread_mutex_lock(&m->activity);
		if (!m->p[i].active)
			nb_of_inactives++;
		pthread_mutex_unlock(&m->activity);
		i++;
	}
	return (nb_of_inactives == m->nb_of_philos);
}

int	is_too_long(t_struct *m, int i)
{
	long	current;

	current = get_time(m);
	pthread_mutex_lock(&m->dying);
	pthread_mutex_lock(&m->ate);
	if (current - m->p[i].last_meal > m->time_to_die)
	{
		pthread_mutex_unlock(&m->ate);
		usleep(1);
		printf("%ld %d %s%s", current, m->p[i].num, DYING, RESET);
		m->died = 1;
		pthread_mutex_unlock(&m->dying);
		return (1);
	}
	pthread_mutex_unlock(&m->ate);
	pthread_mutex_unlock(&m->dying);
	return (0);
}

int	check_death(t_struct *m)
{
	int		i;

	while (!check_activity(m))
	{
		i = 0;
		while (i < m->nb_of_philos)
		{
			pthread_mutex_lock(&m->activity);
			if (m->p[i].active)
			{
				pthread_mutex_unlock(&m->activity);
				if (is_too_long(m, i))
					return (1);
			}
			else
				pthread_mutex_unlock(&m->activity);
			i++;
		}
	}
	return (0);
}

void	*reaper_init(void *data)
{
	t_struct	*m;

	m = (t_struct *) data;
	check_death(m);
	return (NULL);
}
