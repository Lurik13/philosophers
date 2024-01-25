/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:22:50 by lribette          #+#    #+#             */
/*   Updated: 2024/01/25 19:16:43 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_satiety(t_struct *m)
{
	int	i;
	int	nb_of_philos_satiated;

	i = 0;
	nb_of_philos_satiated = 0;
	while (i < m->nb_of_philos)
	{
		pthread_mutex_lock(&m->nb_of_times_eaten);
		if (m->nb_of_times_eating
			&& m->p[i].nb_of_times_eaten_p >= m->nb_of_times_eating)
			nb_of_philos_satiated++;
		pthread_mutex_unlock(&m->nb_of_times_eaten);
		i++;
	}
	return (nb_of_philos_satiated >= m->nb_of_philos);
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

	while (1)
	{
		i = 0;
		while (i < m->nb_of_philos)
		{
			if (is_too_long(m, i))
				return (1);
			i++;
		}
		if (m->nb_of_times_eating > 0 && check_satiety(m))
		{
			pthread_mutex_lock(&m->dying);
			m->died = 1;
			pthread_mutex_unlock(&m->dying);
			return (0);
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
